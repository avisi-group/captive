#include <aarch64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::aarch64;
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_add_vector(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:792 [F] s_b_0_0=sym_3510_3_parameter_inst.SCALAR (const) */
    /* execute.simd:792 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:792 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.simd:792 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:792 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:793 [F] s_b_1_0=sym_3510_3_parameter_inst.rn (const) */
    /* execute.simd:6275 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:794 [F] s_b_1_2=sym_3510_3_parameter_inst.rm (const) */
    /* execute.simd:6275 [D] s_b_1_3 = ReadRegBank 7:s_b_1_2 (u64) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(8));
    }
    /* execute.simd:796 [F] s_b_1_4=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:796 [D] s_b_1_5 = s_b_1_1+s_b_1_3 */
    auto s_b_1_5 = emitter.add(s_b_1_1, s_b_1_3);
    /* execute.simd:6246 [D] s_b_1_6: WriteRegBank 2:s_b_1_4 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_5);
    /* execute.simd:6247 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6247 [F] s_b_1_8: WriteRegBank 3:s_b_1_4 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:798 [F] s_b_3_0=sym_3510_3_parameter_inst.arrangement (const) */
    /* execute.simd:799 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:809 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:817 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:827 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:836 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:846 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:854 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:798 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_11 (const) -> b_11, b_10, b_9, b_8, b_7, b_6, b_5, b_4,  */
    switch (insn.arrangement) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_5;
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
    default:
      goto fixed_block_b_11;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.simd:800 [F] s_b_4_0=sym_3510_3_parameter_inst.rn (const) */
    /* execute.simd:800 [D] s_b_4_1 = ReadRegBank 15:s_b_4_0 (v8u8) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:801 [F] s_b_4_2=sym_3510_3_parameter_inst.rm (const) */
    /* execute.simd:801 [D] s_b_4_3 = ReadRegBank 15:s_b_4_2 (v8u8) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* execute.simd:803 [D] s_b_4_4 = s_b_4_1+s_b_4_3 */
    auto s_b_4_4 = emitter.add(s_b_4_1, s_b_4_3);
    /* execute.simd:804 [F] s_b_4_5=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:804 [D] s_b_4_6: WriteRegBank 15:s_b_4_5 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:805 [F] s_b_4_7=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:805 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:805 [F] s_b_4_9: WriteRegBank 3:s_b_4_7 = s_b_4_8 */
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
    /* execute.simd:810 [F] s_b_5_0=sym_3510_3_parameter_inst.rn (const) */
    /* execute.simd:810 [D] s_b_5_1 = ReadRegBank 16:s_b_5_0 (v16u8) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:811 [F] s_b_5_2=sym_3510_3_parameter_inst.rm (const) */
    /* execute.simd:811 [D] s_b_5_3 = ReadRegBank 16:s_b_5_2 (v16u8) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:813 [D] s_b_5_4 = s_b_5_1+s_b_5_3 */
    auto s_b_5_4 = emitter.add(s_b_5_1, s_b_5_3);
    /* execute.simd:814 [F] s_b_5_5=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:814 [D] s_b_5_6: WriteRegBank 16:s_b_5_5 = s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4);
    /* execute.simd:0 [F] s_b_5_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:818 [F] s_b_6_0=sym_3510_3_parameter_inst.rn (const) */
    /* execute.simd:818 [D] s_b_6_1 = ReadRegBank 17:s_b_6_0 (v4u16) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:819 [F] s_b_6_2=sym_3510_3_parameter_inst.rm (const) */
    /* execute.simd:819 [D] s_b_6_3 = ReadRegBank 17:s_b_6_2 (v4u16) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:821 [D] s_b_6_4 = s_b_6_1+s_b_6_3 */
    auto s_b_6_4 = emitter.add(s_b_6_1, s_b_6_3);
    /* execute.simd:822 [F] s_b_6_5=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:822 [D] s_b_6_6: WriteRegBank 17:s_b_6_5 = s_b_6_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4);
    /* execute.simd:823 [F] s_b_6_7=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:823 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:823 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
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
    /* execute.simd:828 [F] s_b_7_0=sym_3510_3_parameter_inst.rn (const) */
    /* execute.simd:828 [D] s_b_7_1 = ReadRegBank 18:s_b_7_0 (v8u16) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:829 [F] s_b_7_2=sym_3510_3_parameter_inst.rm (const) */
    /* execute.simd:829 [D] s_b_7_3 = ReadRegBank 18:s_b_7_2 (v8u16) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:831 [D] s_b_7_4 = s_b_7_1+s_b_7_3 */
    auto s_b_7_4 = emitter.add(s_b_7_1, s_b_7_3);
    /* execute.simd:832 [F] s_b_7_5=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:832 [D] s_b_7_6: WriteRegBank 18:s_b_7_5 = s_b_7_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4);
    /* execute.simd:0 [F] s_b_7_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.simd:837 [F] s_b_8_0=sym_3510_3_parameter_inst.rn (const) */
    /* execute.simd:837 [D] s_b_8_1 = ReadRegBank 19:s_b_8_0 (v2u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:838 [F] s_b_8_2=sym_3510_3_parameter_inst.rm (const) */
    /* execute.simd:838 [D] s_b_8_3 = ReadRegBank 19:s_b_8_2 (v2u32) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(8));
    }
    /* execute.simd:840 [D] s_b_8_4 = s_b_8_1+s_b_8_3 */
    auto s_b_8_4 = emitter.add(s_b_8_1, s_b_8_3);
    /* execute.simd:841 [F] s_b_8_5=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:841 [D] s_b_8_6: WriteRegBank 19:s_b_8_5 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4);
    /* execute.simd:842 [F] s_b_8_7=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:842 [F] s_b_8_8 = constant u64 0 (const) */
    /* execute.simd:842 [F] s_b_8_9: WriteRegBank 3:s_b_8_7 = s_b_8_8 */
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
    /* execute.simd:847 [F] s_b_9_0=sym_3510_3_parameter_inst.rn (const) */
    /* execute.simd:847 [D] s_b_9_1 = ReadRegBank 20:s_b_9_0 (v4u32) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:848 [F] s_b_9_2=sym_3510_3_parameter_inst.rm (const) */
    /* execute.simd:848 [D] s_b_9_3 = ReadRegBank 20:s_b_9_2 (v4u32) */
    auto s_b_9_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_9_3,emitter.const_u8(16));
    }
    /* execute.simd:850 [D] s_b_9_4 = s_b_9_1+s_b_9_3 */
    auto s_b_9_4 = emitter.add(s_b_9_1, s_b_9_3);
    /* execute.simd:851 [F] s_b_9_5=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:851 [D] s_b_9_6: WriteRegBank 20:s_b_9_5 = s_b_9_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_4);
    /* execute.simd:0 [F] s_b_9_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:855 [F] s_b_10_0=sym_3510_3_parameter_inst.rn (const) */
    /* execute.simd:855 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* execute.simd:856 [F] s_b_10_2=sym_3510_3_parameter_inst.rm (const) */
    /* execute.simd:856 [D] s_b_10_3 = ReadRegBank 21:s_b_10_2 (v2u64) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_3,emitter.const_u8(16));
    }
    /* execute.simd:858 [D] s_b_10_4 = s_b_10_1+s_b_10_3 */
    auto s_b_10_4 = emitter.add(s_b_10_1, s_b_10_3);
    /* execute.simd:859 [F] s_b_10_5=sym_3510_3_parameter_inst.rd (const) */
    /* execute.simd:859 [D] s_b_10_6: WriteRegBank 21:s_b_10_5 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4);
    /* execute.simd:0 [F] s_b_10_7: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_11: 
  {
    /* execute.simd:864 [D] s_b_11_0 = trap */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_andsr(const aarch64_decode_a64_LOGICAL_SR&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_50439_1__R_s_b_20_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_50398_1__R_s_b_19_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50373_1__R_s_b_18_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50348_1__R_s_b_15_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_5944_0_result = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50328_1_tmp_s_b_9_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_50310_1__R_s_b_9_9;
  auto DV_sym_50310_1__R_s_b_9_9 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50505_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50182_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50747_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_50725_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2434 [F] s_b_0_0=sym_5927_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_0_1: If s_b_0_0: Jump b_6 else b_7 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_33,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2441 [F] s_b_1_0=sym_5927_3_parameter_inst.sf (const) */
    /* execute.a64:2441 [F] s_b_1_1: If s_b_1_0: Jump b_3 else b_5 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_33,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2442 [D] s_b_3_0 = sym_5944_0_result uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_5944_0_result, emitter.context().types().u64());
    /* execute.a64:2442 [D] s_b_3_1 = __builtin_update_zn_flags64 */
    emitter.set_zn(s_b_3_0);
    /* execute.a64:2442 [F] s_b_3_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_5,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2447 [F] s_b_4_0 = constant u8 0 (const) */
    /* execute.a64:2447 [F] s_b_4_1: WriteReg 3 = s_b_4_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2448 [F] s_b_4_2 = constant u8 0 (const) */
    /* execute.a64:2448 [F] s_b_4_3: WriteReg 4 = s_b_4_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2441 [F] s_b_4_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2444 [D] s_b_5_0 = sym_5944_0_result uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_5944_0_result, emitter.context().types().u64());
    /* execute.a64:2444 [D] s_b_5_1 = (u32)s_b_5_0 */
    auto s_b_5_1 = emitter.truncate(s_b_5_0, emitter.context().types().u32());
    /* execute.a64:2444 [D] s_b_5_2 = __builtin_update_zn_flags32 */
    emitter.set_zn(s_b_5_1);
    /* execute.a64:2444 [F] s_b_5_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2657 [F] s_b_6_0=sym_5927_3_parameter_inst.rn (const) */
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
    /* execute.a64:2657 [D] s_b_6_7: sym_50182_1__R_s_b_0_4 = s_b_6_6, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_50182_1__R_s_b_0_4, s_b_6_6);
    /* execute.a64:2657 [F] s_b_6_8: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2659 [F] s_b_7_0=sym_5927_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2646 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_7_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_7_5 = ReadRegBank 1:s_b_7_0 (u32) */
    auto s_b_7_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_7_6: Select s_b_7_3 ? s_b_7_4 : s_b_7_5 */
    dbt::el::Value *s_b_7_6;
    s_b_7_6 = (s_b_7_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_7_5);
    /* execute.a64:2659 [D] s_b_7_7 = (u64)s_b_7_6 */
    auto s_b_7_7 = emitter.zx(s_b_7_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_7_8: sym_50182_1__R_s_b_0_4 = s_b_7_7, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_50182_1__R_s_b_0_4, s_b_7_7);
    /* execute.a64:2659 [F] s_b_7_9: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_6, b_7,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2434 [D] s_b_8_0 = sym_50182_1__R_s_b_0_4 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_50182_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2435 [F] s_b_8_1=sym_5927_3_parameter_inst.imm6 (const) */
    /* ???:4294967295 [D] s_b_8_2: sym_50328_1_tmp_s_b_9_0 = s_b_8_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_50328_1_tmp_s_b_9_0, s_b_8_0);
    /* execute.a64:2572 [F] s_b_8_3 = (u32)s_b_8_1 (const) */
    /* execute.a64:2572 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2572 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)insn.imm6) == (uint32_t)0ULL));
    /* execute.a64:2572 [F] s_b_8_6: If s_b_8_5: Jump b_9 else b_10 (const) */
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
    /* execute.a64:2572 [F] s_b_9_0=sym_5927_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_9_1: If s_b_9_0: Jump b_19 else b_20 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2574 [F] s_b_10_0=sym_5927_3_parameter_inst.shift (const) */
    /* execute.a64:2575 [F] s_b_10_1 = constant s32 0 (const) */
    /* execute.a64:2579 [F] s_b_10_2 = constant s32 1 (const) */
    /* execute.a64:2583 [F] s_b_10_3 = constant s32 2 (const) */
    /* execute.a64:2587 [F] s_b_10_4 = constant s32 3 (const) */
    /* execute.a64:2574 [F] s_b_10_5: Switch s_b_10_0: < <todo> > def b_11 (const) -> b_11, b_12, b_14, b_15, b_13,  */
    switch (insn.shift) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_12;
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
    /* execute.a64:2598 [F] s_b_11_2: sym_50310_1__R_s_b_9_9 = s_b_11_1 (const), dominates: s_b_18_1  */
    CV_sym_50310_1__R_s_b_9_9 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_50310_1__R_s_b_9_9, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2598 [F] s_b_11_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_10,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2577 [F] s_b_12_0=sym_5927_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_12_1: If s_b_12_0: Jump b_22 else b_23 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2581 [F] s_b_13_0=sym_5927_3_parameter_inst.sf (const) */
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
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2585 [F] s_b_14_0=sym_5927_3_parameter_inst.sf (const) */
    /* execute.a64:2665 [F] s_b_14_1: If s_b_14_0: Jump b_28 else b_29 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_10,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2589 [F] s_b_15_0=sym_5927_3_parameter_inst.sf (const) */
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
    /* execute.a64:2657 [F] s_b_16_0=sym_5927_3_parameter_inst.rm (const) */
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
    /* execute.a64:2590 [F] s_b_16_7=sym_5927_3_parameter_inst.imm6 (const) */
    /* execute.a64:2590 [F] s_b_16_8 = (u64)s_b_16_7 (const) */
    /* execute.a64:2590 [D] s_b_16_9 = s_b_16_6>>>s_b_16_8 */
    auto s_b_16_9 = emitter.ror(s_b_16_6, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2590 [D] s_b_16_10: sym_50310_1__R_s_b_9_9 = s_b_16_9, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_50310_1__R_s_b_9_9, s_b_16_9);
    /* execute.a64:2590 [F] s_b_16_11: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_15,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2659 [F] s_b_17_0=sym_5927_3_parameter_inst.rm (const) */
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
    /* execute.a64:2592 [F] s_b_17_9=sym_5927_3_parameter_inst.imm6 (const) */
    /* execute.a64:2592 [F] s_b_17_10 = (u32)s_b_17_9 (const) */
    /* execute.a64:2592 [D] s_b_17_11 = s_b_17_8>>>s_b_17_10 */
    auto s_b_17_11 = emitter.ror(s_b_17_8, emitter.const_u32(((uint32_t)insn.imm6)));
    /* execute.a64:2592 [D] s_b_17_12 = (u64)s_b_17_11 */
    auto s_b_17_12 = emitter.zx(s_b_17_11, emitter.context().types().u64());
    /* execute.a64:2592 [D] s_b_17_13: sym_50310_1__R_s_b_9_9 = s_b_17_12, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_50310_1__R_s_b_9_9, s_b_17_12);
    /* execute.a64:2592 [F] s_b_17_14: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_11, b_16, b_17, b_21, b_24, b_27, b_30,  */
  fixed_block_b_18: 
  {
    /* ???:4294967295 [D] s_b_18_0 = sym_50328_1_tmp_s_b_9_0 uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_50328_1_tmp_s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2435 [D] s_b_18_1 = sym_50310_1__R_s_b_9_9 uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_50310_1__R_s_b_9_9, emitter.context().types().u64());
    /* execute.a64:2437 [D] s_b_18_2 = s_b_18_0&s_b_18_1 */
    auto s_b_18_2 = emitter.bitwise_and(s_b_18_0, s_b_18_1);
    /* execute.a64:2437 [D] s_b_18_3: sym_5944_0_result = s_b_18_2, dominates: s_b_3_0 s_b_5_0  */
    emitter.store_local(DV_sym_5944_0_result, s_b_18_2);
    /* execute.a64:2438 [F] s_b_18_4=sym_5927_3_parameter_inst.sf (const) */
    /* execute.a64:2438 [D] s_b_18_5: sym_50505_3_parameter_value = s_b_18_2, dominates: s_b_31_1 s_b_32_1  */
    emitter.store_local(DV_sym_50505_3_parameter_value, s_b_18_2);
    /* execute.a64:2690 [F] s_b_18_6: If s_b_18_4: Jump b_31 else b_32 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_9,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2657 [F] s_b_19_0=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:2651 [F] s_b_19_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_19_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_19_5 = ReadRegBank 0:s_b_19_0 (u64) */
    auto s_b_19_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_19_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_19_6: Select s_b_19_3 ? s_b_19_4 : s_b_19_5 */
    dbt::el::Value *s_b_19_6;
    s_b_19_6 = (s_b_19_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_19_5);
    /* execute.a64:2657 [D] s_b_19_7: sym_50348_1__R_s_b_15_4 = s_b_19_6, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_50348_1__R_s_b_15_4, s_b_19_6);
    /* execute.a64:2657 [F] s_b_19_8: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_9,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2659 [F] s_b_20_0=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
    /* execute.a64:2646 [F] s_b_20_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_20_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_20_5 = ReadRegBank 1:s_b_20_0 (u32) */
    auto s_b_20_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_20_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_20_6: Select s_b_20_3 ? s_b_20_4 : s_b_20_5 */
    dbt::el::Value *s_b_20_6;
    s_b_20_6 = (s_b_20_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_20_5);
    /* execute.a64:2659 [D] s_b_20_7 = (u64)s_b_20_6 */
    auto s_b_20_7 = emitter.zx(s_b_20_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_20_8: sym_50348_1__R_s_b_15_4 = s_b_20_7, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_50348_1__R_s_b_15_4, s_b_20_7);
    /* execute.a64:2659 [F] s_b_20_9: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_19, b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2572 [D] s_b_21_0 = sym_50348_1__R_s_b_15_4 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_50348_1__R_s_b_15_4, emitter.context().types().u64());
    /* execute.a64:2572 [D] s_b_21_1: sym_50310_1__R_s_b_9_9 = s_b_21_0, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_50310_1__R_s_b_9_9, s_b_21_0);
    /* execute.a64:2572 [F] s_b_21_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_12,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2657 [F] s_b_22_0=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
    /* execute.a64:2651 [F] s_b_22_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
    uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_22_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_22_5 = ReadRegBank 0:s_b_22_0 (u64) */
    auto s_b_22_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_22_6: Select s_b_22_3 ? s_b_22_4 : s_b_22_5 */
    dbt::el::Value *s_b_22_6;
    s_b_22_6 = (s_b_22_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_22_5);
    /* execute.a64:2657 [D] s_b_22_7: sym_50373_1__R_s_b_18_4 = s_b_22_6, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_50373_1__R_s_b_18_4, s_b_22_6);
    /* execute.a64:2657 [F] s_b_22_8: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_12,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2659 [F] s_b_23_0=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:2646 [F] s_b_23_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_23_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_23_5 = ReadRegBank 1:s_b_23_0 (u32) */
    auto s_b_23_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_23_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_23_6: Select s_b_23_3 ? s_b_23_4 : s_b_23_5 */
    dbt::el::Value *s_b_23_6;
    s_b_23_6 = (s_b_23_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_23_5);
    /* execute.a64:2659 [D] s_b_23_7 = (u64)s_b_23_6 */
    auto s_b_23_7 = emitter.zx(s_b_23_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_23_8: sym_50373_1__R_s_b_18_4 = s_b_23_7, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_50373_1__R_s_b_18_4, s_b_23_7);
    /* execute.a64:2659 [F] s_b_23_9: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2577 [D] s_b_24_0 = sym_50373_1__R_s_b_18_4 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_50373_1__R_s_b_18_4, emitter.context().types().u64());
    /* execute.a64:2577 [F] s_b_24_1=sym_5927_3_parameter_inst.imm6 (const) */
    /* execute.a64:2577 [F] s_b_24_2 = (u64)s_b_24_1 (const) */
    /* execute.a64:2577 [D] s_b_24_3 = s_b_24_0<<s_b_24_2 */
    auto s_b_24_3 = emitter.shl(s_b_24_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2577 [D] s_b_24_4: sym_50310_1__R_s_b_9_9 = s_b_24_3, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_50310_1__R_s_b_9_9, s_b_24_3);
    /* execute.a64:2577 [F] s_b_24_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_13,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2657 [F] s_b_25_0=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
    /* execute.a64:2651 [F] s_b_25_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_25_3 = s_b_25_1==s_b_25_2 (const) */
    uint8_t s_b_25_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_25_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_25_5 = ReadRegBank 0:s_b_25_0 (u64) */
    auto s_b_25_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_25_6: Select s_b_25_3 ? s_b_25_4 : s_b_25_5 */
    dbt::el::Value *s_b_25_6;
    s_b_25_6 = (s_b_25_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_25_5);
    /* execute.a64:2657 [D] s_b_25_7: sym_50398_1__R_s_b_19_4 = s_b_25_6, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_50398_1__R_s_b_19_4, s_b_25_6);
    /* execute.a64:2657 [F] s_b_25_8: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_13,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2659 [F] s_b_26_0=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
    /* execute.a64:2646 [F] s_b_26_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_26_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_26_5 = ReadRegBank 1:s_b_26_0 (u32) */
    auto s_b_26_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_26_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_26_6: Select s_b_26_3 ? s_b_26_4 : s_b_26_5 */
    dbt::el::Value *s_b_26_6;
    s_b_26_6 = (s_b_26_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_26_5);
    /* execute.a64:2659 [D] s_b_26_7 = (u64)s_b_26_6 */
    auto s_b_26_7 = emitter.zx(s_b_26_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_26_8: sym_50398_1__R_s_b_19_4 = s_b_26_7, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_50398_1__R_s_b_19_4, s_b_26_7);
    /* execute.a64:2659 [F] s_b_26_9: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_25, b_26,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2581 [D] s_b_27_0 = sym_50398_1__R_s_b_19_4 uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_50398_1__R_s_b_19_4, emitter.context().types().u64());
    /* execute.a64:2581 [F] s_b_27_1=sym_5927_3_parameter_inst.imm6 (const) */
    /* execute.a64:2581 [F] s_b_27_2 = (u64)s_b_27_1 (const) */
    /* execute.a64:2581 [D] s_b_27_3 = s_b_27_0>>s_b_27_2 */
    auto s_b_27_3 = emitter.shr(s_b_27_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2581 [D] s_b_27_4: sym_50310_1__R_s_b_9_9 = s_b_27_3, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_50310_1__R_s_b_9_9, s_b_27_3);
    /* execute.a64:2581 [F] s_b_27_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_14,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2666 [F] s_b_28_0=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
    /* execute.a64:2666 [F] s_b_28_2 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_28_4 = constant s64 0 (const) */
    /* execute.a64:2666 [F] s_b_28_5=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [D] s_b_28_6 = ReadRegBank 0:s_b_28_5 (u64) */
    auto s_b_28_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_6,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_28_7 = (s64)s_b_28_6 */
    auto s_b_28_7 = emitter.reinterpret(s_b_28_6, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_28_8: Select s_b_28_3 ? s_b_28_4 : s_b_28_7 */
    dbt::el::Value *s_b_28_8;
    s_b_28_8 = (s_b_28_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_28_7);
    /* execute.a64:2666 [D] s_b_28_9: sym_50439_1__R_s_b_20_4 = s_b_28_8, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_50439_1__R_s_b_20_4, s_b_28_8);
    /* execute.a64:2666 [F] s_b_28_10: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_14,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2668 [F] s_b_29_0=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
    /* execute.a64:2668 [F] s_b_29_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_29_4 = constant s64 0 (const) */
    /* execute.a64:2668 [F] s_b_29_5=sym_5927_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [D] s_b_29_6 = ReadRegBank 1:s_b_29_5 (u32) */
    auto s_b_29_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_29_6,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_29_7 = (s32)s_b_29_6 */
    auto s_b_29_7 = emitter.reinterpret(s_b_29_6, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_29_8 = (s64)s_b_29_7 */
    auto s_b_29_8 = emitter.sx(s_b_29_7, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_29_9: Select s_b_29_3 ? s_b_29_4 : s_b_29_8 */
    dbt::el::Value *s_b_29_9;
    s_b_29_9 = (s_b_29_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_29_8);
    /* execute.a64:2668 [D] s_b_29_10: sym_50439_1__R_s_b_20_4 = s_b_29_9, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_50439_1__R_s_b_20_4, s_b_29_9);
    /* execute.a64:2668 [F] s_b_29_11: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_28, b_29,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2585 [D] s_b_30_0 = sym_50439_1__R_s_b_20_4 int64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_50439_1__R_s_b_20_4, emitter.context().types().s64());
    /* execute.a64:2585 [F] s_b_30_1=sym_5927_3_parameter_inst.imm6 (const) */
    /* execute.a64:2585 [D] s_b_30_2 = (u64)s_b_30_0 */
    auto s_b_30_2 = emitter.reinterpret(s_b_30_0, emitter.context().types().u64());
    /* execute.a64:2585 [F] s_b_30_3 = (u64)s_b_30_1 (const) */
    /* execute.a64:2585 [D] s_b_30_4 = s_b_30_2->>s_b_30_3 */
    auto s_b_30_4 = emitter.sar(s_b_30_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2585 [D] s_b_30_5 = (u64)s_b_30_4 */
    auto s_b_30_5 = (dbt::el::Value *)s_b_30_4;
    /* execute.a64:2585 [D] s_b_30_6: sym_50310_1__R_s_b_9_9 = s_b_30_5, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_50310_1__R_s_b_9_9, s_b_30_5);
    /* execute.a64:2585 [F] s_b_30_7: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_18,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2691 [F] s_b_31_0=sym_5927_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_31_1 = sym_50505_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_50505_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_31_2: sym_50725_3_parameter_value = s_b_31_1, dominates: s_b_34_1  */
    emitter.store_local(DV_sym_50725_3_parameter_value, s_b_31_1);
    /* execute.a64:2682 [F] s_b_31_3 = (u32)s_b_31_0 (const) */
    /* execute.a64:2682 [F] s_b_31_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_31_5 = s_b_31_3==s_b_31_4 (const) */
    uint8_t s_b_31_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_31_6: If s_b_31_5: Jump b_33 else b_34 (const) */
    if (s_b_31_5) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_34;
    }
  }
  /* b_18,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2693 [F] s_b_32_0=sym_5927_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_32_1 = sym_50505_3_parameter_value uint64_t */
    auto s_b_32_1 = emitter.load_local(DV_sym_50505_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_32_2 = (u32)s_b_32_1 */
    auto s_b_32_2 = emitter.truncate(s_b_32_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_32_3 = (u64)s_b_32_2 */
    auto s_b_32_3 = emitter.zx(s_b_32_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_32_4: sym_50747_3_parameter_value = s_b_32_3, dominates: s_b_35_1  */
    emitter.store_local(DV_sym_50747_3_parameter_value, s_b_32_3);
    /* execute.a64:2682 [F] s_b_32_5 = (u32)s_b_32_0 (const) */
    /* execute.a64:2682 [F] s_b_32_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_32_7 = s_b_32_5==s_b_32_6 (const) */
    uint8_t s_b_32_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_32_8: If s_b_32_7: Jump b_33 else b_35 (const) */
    if (s_b_32_7) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_31, b_32, b_34, b_35,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2440 [F] s_b_33_0=sym_5927_3_parameter_inst.opc (const) */
    /* execute.a64:2440 [F] s_b_33_1 = (u32)s_b_33_0 (const) */
    /* execute.a64:2440 [F] s_b_33_2 = constant u32 3 (const) */
    /* execute.a64:2440 [F] s_b_33_3 = s_b_33_1==s_b_33_2 (const) */
    uint8_t s_b_33_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:2440 [F] s_b_33_4: If s_b_33_3: Jump b_1 else b_2 (const) */
    if (s_b_33_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_31,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2684 [F] s_b_34_0=sym_5927_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_34_1 = sym_50725_3_parameter_value uint64_t */
    auto s_b_34_1 = emitter.load_local(DV_sym_50725_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_34_2: WriteRegBank 0:s_b_34_0 = s_b_34_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_34_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_34_1);
    /* execute.a64:0 [F] s_b_34_3: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_32,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2684 [F] s_b_35_0=sym_5927_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_35_1 = sym_50747_3_parameter_value uint64_t */
    auto s_b_35_1 = emitter.load_local(DV_sym_50747_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_35_2: WriteRegBank 0:s_b_35_0 = s_b_35_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_35_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_35_1);
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_bicsr(const aarch64_decode_a64_LOGICAL_SR&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_52263_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52241_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_52021_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_6251_0_result = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51914_1__R_s_b_19_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51864_1__R_s_b_15_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51955_1__R_s_b_20_4 = emitter.alloc_local(emitter.context().types().s64(), false);
  uint64_t CV_sym_51826_1__R_s_b_9_9;
  auto DV_sym_51826_1__R_s_b_9_9 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51698_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51844_1_tmp_s_b_9_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_51889_1__R_s_b_18_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2454 [F] s_b_0_0=sym_6233_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_0_1: If s_b_0_0: Jump b_6 else b_7 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_33,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2461 [F] s_b_1_0=sym_6233_3_parameter_inst.sf (const) */
    /* execute.a64:2461 [F] s_b_1_1: If s_b_1_0: Jump b_3 else b_5 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_3;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_33,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2462 [D] s_b_3_0 = sym_6251_0_result uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_6251_0_result, emitter.context().types().u64());
    /* execute.a64:2462 [D] s_b_3_1 = __builtin_update_zn_flags64 */
    emitter.set_zn(s_b_3_0);
    /* execute.a64:2462 [F] s_b_3_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_3, b_5,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2467 [F] s_b_4_0 = constant u8 0 (const) */
    /* execute.a64:2467 [F] s_b_4_1: WriteReg 3 = s_b_4_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1298), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2468 [F] s_b_4_2 = constant u8 0 (const) */
    /* execute.a64:2468 [F] s_b_4_3: WriteReg 4 = s_b_4_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1299), emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2461 [F] s_b_4_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2464 [D] s_b_5_0 = sym_6251_0_result uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_6251_0_result, emitter.context().types().u64());
    /* execute.a64:2464 [D] s_b_5_1 = (u32)s_b_5_0 */
    auto s_b_5_1 = emitter.truncate(s_b_5_0, emitter.context().types().u32());
    /* execute.a64:2464 [D] s_b_5_2 = __builtin_update_zn_flags32 */
    emitter.set_zn(s_b_5_1);
    /* execute.a64:2464 [F] s_b_5_3: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2657 [F] s_b_6_0=sym_6233_3_parameter_inst.rn (const) */
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
    /* execute.a64:2657 [D] s_b_6_7: sym_51698_1__R_s_b_0_4 = s_b_6_6, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_51698_1__R_s_b_0_4, s_b_6_6);
    /* execute.a64:2657 [F] s_b_6_8: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2659 [F] s_b_7_0=sym_6233_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2646 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_7_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_7_5 = ReadRegBank 1:s_b_7_0 (u32) */
    auto s_b_7_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_7_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_7_6: Select s_b_7_3 ? s_b_7_4 : s_b_7_5 */
    dbt::el::Value *s_b_7_6;
    s_b_7_6 = (s_b_7_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_7_5);
    /* execute.a64:2659 [D] s_b_7_7 = (u64)s_b_7_6 */
    auto s_b_7_7 = emitter.zx(s_b_7_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_7_8: sym_51698_1__R_s_b_0_4 = s_b_7_7, dominates: s_b_8_0  */
    emitter.store_local(DV_sym_51698_1__R_s_b_0_4, s_b_7_7);
    /* execute.a64:2659 [F] s_b_7_9: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_6, b_7,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2454 [D] s_b_8_0 = sym_51698_1__R_s_b_0_4 uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_51698_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2455 [F] s_b_8_1=sym_6233_3_parameter_inst.imm6 (const) */
    /* ???:4294967295 [D] s_b_8_2: sym_51844_1_tmp_s_b_9_0 = s_b_8_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_51844_1_tmp_s_b_9_0, s_b_8_0);
    /* execute.a64:2572 [F] s_b_8_3 = (u32)s_b_8_1 (const) */
    /* execute.a64:2572 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2572 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)insn.imm6) == (uint32_t)0ULL));
    /* execute.a64:2572 [F] s_b_8_6: If s_b_8_5: Jump b_9 else b_10 (const) */
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
    /* execute.a64:2572 [F] s_b_9_0=sym_6233_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_9_1: If s_b_9_0: Jump b_19 else b_20 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_20;
    }
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2574 [F] s_b_10_0=sym_6233_3_parameter_inst.shift (const) */
    /* execute.a64:2575 [F] s_b_10_1 = constant s32 0 (const) */
    /* execute.a64:2579 [F] s_b_10_2 = constant s32 1 (const) */
    /* execute.a64:2583 [F] s_b_10_3 = constant s32 2 (const) */
    /* execute.a64:2587 [F] s_b_10_4 = constant s32 3 (const) */
    /* execute.a64:2574 [F] s_b_10_5: Switch s_b_10_0: < <todo> > def b_11 (const) -> b_11, b_12, b_13, b_14, b_15,  */
    switch (insn.shift) 
    {
    case (int32_t)3ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_13;
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
    /* execute.a64:2598 [F] s_b_11_2: sym_51826_1__R_s_b_9_9 = s_b_11_1 (const), dominates: s_b_18_1  */
    CV_sym_51826_1__R_s_b_9_9 = (uint64_t)0ULL;
    emitter.store_local(DV_sym_51826_1__R_s_b_9_9, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2598 [F] s_b_11_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_10,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2577 [F] s_b_12_0=sym_6233_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_12_1: If s_b_12_0: Jump b_22 else b_23 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_10,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2581 [F] s_b_13_0=sym_6233_3_parameter_inst.sf (const) */
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
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2585 [F] s_b_14_0=sym_6233_3_parameter_inst.sf (const) */
    /* execute.a64:2665 [F] s_b_14_1: If s_b_14_0: Jump b_28 else b_29 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_28;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_10,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2589 [F] s_b_15_0=sym_6233_3_parameter_inst.sf (const) */
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
    /* execute.a64:2657 [F] s_b_16_0=sym_6233_3_parameter_inst.rm (const) */
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
    /* execute.a64:2590 [F] s_b_16_7=sym_6233_3_parameter_inst.imm6 (const) */
    /* execute.a64:2590 [F] s_b_16_8 = (u64)s_b_16_7 (const) */
    /* execute.a64:2590 [D] s_b_16_9 = s_b_16_6>>>s_b_16_8 */
    auto s_b_16_9 = emitter.ror(s_b_16_6, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2590 [D] s_b_16_10: sym_51826_1__R_s_b_9_9 = s_b_16_9, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_51826_1__R_s_b_9_9, s_b_16_9);
    /* execute.a64:2590 [F] s_b_16_11: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_15,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2659 [F] s_b_17_0=sym_6233_3_parameter_inst.rm (const) */
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
    /* execute.a64:2592 [F] s_b_17_9=sym_6233_3_parameter_inst.imm6 (const) */
    /* execute.a64:2592 [F] s_b_17_10 = (u32)s_b_17_9 (const) */
    /* execute.a64:2592 [D] s_b_17_11 = s_b_17_8>>>s_b_17_10 */
    auto s_b_17_11 = emitter.ror(s_b_17_8, emitter.const_u32(((uint32_t)insn.imm6)));
    /* execute.a64:2592 [D] s_b_17_12 = (u64)s_b_17_11 */
    auto s_b_17_12 = emitter.zx(s_b_17_11, emitter.context().types().u64());
    /* execute.a64:2592 [D] s_b_17_13: sym_51826_1__R_s_b_9_9 = s_b_17_12, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_51826_1__R_s_b_9_9, s_b_17_12);
    /* execute.a64:2592 [F] s_b_17_14: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_11, b_16, b_17, b_21, b_24, b_27, b_30,  */
  fixed_block_b_18: 
  {
    /* ???:4294967295 [D] s_b_18_0 = sym_51844_1_tmp_s_b_9_0 uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_51844_1_tmp_s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2455 [D] s_b_18_1 = sym_51826_1__R_s_b_9_9 uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_51826_1__R_s_b_9_9, emitter.context().types().u64());
    /* execute.a64:2457 [D] s_b_18_2 = ~s_b_18_1 */
    auto s_b_18_2 = emitter.bitwise_not(s_b_18_1);
    /* execute.a64:2457 [D] s_b_18_3 = s_b_18_0&s_b_18_2 */
    auto s_b_18_3 = emitter.bitwise_and(s_b_18_0, s_b_18_2);
    /* execute.a64:2457 [D] s_b_18_4: sym_6251_0_result = s_b_18_3, dominates: s_b_3_0 s_b_5_0  */
    emitter.store_local(DV_sym_6251_0_result, s_b_18_3);
    /* execute.a64:2458 [F] s_b_18_5=sym_6233_3_parameter_inst.sf (const) */
    /* execute.a64:2458 [D] s_b_18_6: sym_52021_3_parameter_value = s_b_18_3, dominates: s_b_31_1 s_b_32_1  */
    emitter.store_local(DV_sym_52021_3_parameter_value, s_b_18_3);
    /* execute.a64:2690 [F] s_b_18_7: If s_b_18_5: Jump b_31 else b_32 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_31;
    }
    else 
    {
      goto fixed_block_b_32;
    }
  }
  /* b_9,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2657 [F] s_b_19_0=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
    /* execute.a64:2651 [F] s_b_19_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_19_3 = s_b_19_1==s_b_19_2 (const) */
    uint8_t s_b_19_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_19_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_19_5 = ReadRegBank 0:s_b_19_0 (u64) */
    auto s_b_19_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_19_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_19_6: Select s_b_19_3 ? s_b_19_4 : s_b_19_5 */
    dbt::el::Value *s_b_19_6;
    s_b_19_6 = (s_b_19_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_19_5);
    /* execute.a64:2657 [D] s_b_19_7: sym_51864_1__R_s_b_15_4 = s_b_19_6, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_51864_1__R_s_b_15_4, s_b_19_6);
    /* execute.a64:2657 [F] s_b_19_8: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_9,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2659 [F] s_b_20_0=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
    /* execute.a64:2646 [F] s_b_20_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_20_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_20_5 = ReadRegBank 1:s_b_20_0 (u32) */
    auto s_b_20_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_20_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_20_6: Select s_b_20_3 ? s_b_20_4 : s_b_20_5 */
    dbt::el::Value *s_b_20_6;
    s_b_20_6 = (s_b_20_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_20_5);
    /* execute.a64:2659 [D] s_b_20_7 = (u64)s_b_20_6 */
    auto s_b_20_7 = emitter.zx(s_b_20_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_20_8: sym_51864_1__R_s_b_15_4 = s_b_20_7, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_51864_1__R_s_b_15_4, s_b_20_7);
    /* execute.a64:2659 [F] s_b_20_9: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_19, b_20,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2572 [D] s_b_21_0 = sym_51864_1__R_s_b_15_4 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_51864_1__R_s_b_15_4, emitter.context().types().u64());
    /* execute.a64:2572 [D] s_b_21_1: sym_51826_1__R_s_b_9_9 = s_b_21_0, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_51826_1__R_s_b_9_9, s_b_21_0);
    /* execute.a64:2572 [F] s_b_21_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_12,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2657 [F] s_b_22_0=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
    /* execute.a64:2651 [F] s_b_22_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_22_3 = s_b_22_1==s_b_22_2 (const) */
    uint8_t s_b_22_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_22_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_22_5 = ReadRegBank 0:s_b_22_0 (u64) */
    auto s_b_22_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_22_6: Select s_b_22_3 ? s_b_22_4 : s_b_22_5 */
    dbt::el::Value *s_b_22_6;
    s_b_22_6 = (s_b_22_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_22_5);
    /* execute.a64:2657 [D] s_b_22_7: sym_51889_1__R_s_b_18_4 = s_b_22_6, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_51889_1__R_s_b_18_4, s_b_22_6);
    /* execute.a64:2657 [F] s_b_22_8: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_12,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2659 [F] s_b_23_0=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:2646 [F] s_b_23_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_23_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_23_5 = ReadRegBank 1:s_b_23_0 (u32) */
    auto s_b_23_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_23_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_23_6: Select s_b_23_3 ? s_b_23_4 : s_b_23_5 */
    dbt::el::Value *s_b_23_6;
    s_b_23_6 = (s_b_23_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_23_5);
    /* execute.a64:2659 [D] s_b_23_7 = (u64)s_b_23_6 */
    auto s_b_23_7 = emitter.zx(s_b_23_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_23_8: sym_51889_1__R_s_b_18_4 = s_b_23_7, dominates: s_b_24_0  */
    emitter.store_local(DV_sym_51889_1__R_s_b_18_4, s_b_23_7);
    /* execute.a64:2659 [F] s_b_23_9: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_22, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2577 [D] s_b_24_0 = sym_51889_1__R_s_b_18_4 uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_51889_1__R_s_b_18_4, emitter.context().types().u64());
    /* execute.a64:2577 [F] s_b_24_1=sym_6233_3_parameter_inst.imm6 (const) */
    /* execute.a64:2577 [F] s_b_24_2 = (u64)s_b_24_1 (const) */
    /* execute.a64:2577 [D] s_b_24_3 = s_b_24_0<<s_b_24_2 */
    auto s_b_24_3 = emitter.shl(s_b_24_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2577 [D] s_b_24_4: sym_51826_1__R_s_b_9_9 = s_b_24_3, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_51826_1__R_s_b_9_9, s_b_24_3);
    /* execute.a64:2577 [F] s_b_24_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_13,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2657 [F] s_b_25_0=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
    /* execute.a64:2651 [F] s_b_25_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_25_3 = s_b_25_1==s_b_25_2 (const) */
    uint8_t s_b_25_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_25_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_25_5 = ReadRegBank 0:s_b_25_0 (u64) */
    auto s_b_25_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_25_6: Select s_b_25_3 ? s_b_25_4 : s_b_25_5 */
    dbt::el::Value *s_b_25_6;
    s_b_25_6 = (s_b_25_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_25_5);
    /* execute.a64:2657 [D] s_b_25_7: sym_51914_1__R_s_b_19_4 = s_b_25_6, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_51914_1__R_s_b_19_4, s_b_25_6);
    /* execute.a64:2657 [F] s_b_25_8: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_13,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2659 [F] s_b_26_0=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_26_1 = (u32)s_b_26_0 (const) */
    /* execute.a64:2646 [F] s_b_26_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_26_3 = s_b_26_1==s_b_26_2 (const) */
    uint8_t s_b_26_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_26_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_26_5 = ReadRegBank 1:s_b_26_0 (u32) */
    auto s_b_26_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_26_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_26_6: Select s_b_26_3 ? s_b_26_4 : s_b_26_5 */
    dbt::el::Value *s_b_26_6;
    s_b_26_6 = (s_b_26_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_26_5);
    /* execute.a64:2659 [D] s_b_26_7 = (u64)s_b_26_6 */
    auto s_b_26_7 = emitter.zx(s_b_26_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_26_8: sym_51914_1__R_s_b_19_4 = s_b_26_7, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_51914_1__R_s_b_19_4, s_b_26_7);
    /* execute.a64:2659 [F] s_b_26_9: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_25, b_26,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2581 [D] s_b_27_0 = sym_51914_1__R_s_b_19_4 uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_51914_1__R_s_b_19_4, emitter.context().types().u64());
    /* execute.a64:2581 [F] s_b_27_1=sym_6233_3_parameter_inst.imm6 (const) */
    /* execute.a64:2581 [F] s_b_27_2 = (u64)s_b_27_1 (const) */
    /* execute.a64:2581 [D] s_b_27_3 = s_b_27_0>>s_b_27_2 */
    auto s_b_27_3 = emitter.shr(s_b_27_0, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2581 [D] s_b_27_4: sym_51826_1__R_s_b_9_9 = s_b_27_3, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_51826_1__R_s_b_9_9, s_b_27_3);
    /* execute.a64:2581 [F] s_b_27_5: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_14,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2666 [F] s_b_28_0=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
    /* execute.a64:2666 [F] s_b_28_2 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_28_3 = s_b_28_1==s_b_28_2 (const) */
    uint8_t s_b_28_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_28_4 = constant s64 0 (const) */
    /* execute.a64:2666 [F] s_b_28_5=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [D] s_b_28_6 = ReadRegBank 0:s_b_28_5 (u64) */
    auto s_b_28_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_6,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_28_7 = (s64)s_b_28_6 */
    auto s_b_28_7 = emitter.reinterpret(s_b_28_6, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_28_8: Select s_b_28_3 ? s_b_28_4 : s_b_28_7 */
    dbt::el::Value *s_b_28_8;
    s_b_28_8 = (s_b_28_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_28_7);
    /* execute.a64:2666 [D] s_b_28_9: sym_51955_1__R_s_b_20_4 = s_b_28_8, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_51955_1__R_s_b_20_4, s_b_28_8);
    /* execute.a64:2666 [F] s_b_28_10: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_14,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2668 [F] s_b_29_0=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
    /* execute.a64:2668 [F] s_b_29_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_29_3 = s_b_29_1==s_b_29_2 (const) */
    uint8_t s_b_29_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_29_4 = constant s64 0 (const) */
    /* execute.a64:2668 [F] s_b_29_5=sym_6233_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [D] s_b_29_6 = ReadRegBank 1:s_b_29_5 (u32) */
    auto s_b_29_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_29_6,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_29_7 = (s32)s_b_29_6 */
    auto s_b_29_7 = emitter.reinterpret(s_b_29_6, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_29_8 = (s64)s_b_29_7 */
    auto s_b_29_8 = emitter.sx(s_b_29_7, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_29_9: Select s_b_29_3 ? s_b_29_4 : s_b_29_8 */
    dbt::el::Value *s_b_29_9;
    s_b_29_9 = (s_b_29_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_29_8);
    /* execute.a64:2668 [D] s_b_29_10: sym_51955_1__R_s_b_20_4 = s_b_29_9, dominates: s_b_30_0  */
    emitter.store_local(DV_sym_51955_1__R_s_b_20_4, s_b_29_9);
    /* execute.a64:2668 [F] s_b_29_11: Jump b_30 (const) */
    goto fixed_block_b_30;
  }
  /* b_28, b_29,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2585 [D] s_b_30_0 = sym_51955_1__R_s_b_20_4 int64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_51955_1__R_s_b_20_4, emitter.context().types().s64());
    /* execute.a64:2585 [F] s_b_30_1=sym_6233_3_parameter_inst.imm6 (const) */
    /* execute.a64:2585 [D] s_b_30_2 = (u64)s_b_30_0 */
    auto s_b_30_2 = emitter.reinterpret(s_b_30_0, emitter.context().types().u64());
    /* execute.a64:2585 [F] s_b_30_3 = (u64)s_b_30_1 (const) */
    /* execute.a64:2585 [D] s_b_30_4 = s_b_30_2->>s_b_30_3 */
    auto s_b_30_4 = emitter.sar(s_b_30_2, emitter.const_u64(((uint64_t)insn.imm6)));
    /* execute.a64:2585 [D] s_b_30_5 = (u64)s_b_30_4 */
    auto s_b_30_5 = (dbt::el::Value *)s_b_30_4;
    /* execute.a64:2585 [D] s_b_30_6: sym_51826_1__R_s_b_9_9 = s_b_30_5, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_51826_1__R_s_b_9_9, s_b_30_5);
    /* execute.a64:2585 [F] s_b_30_7: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_18,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2691 [F] s_b_31_0=sym_6233_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_31_1 = sym_52021_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_52021_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_31_2: sym_52241_3_parameter_value = s_b_31_1, dominates: s_b_34_1  */
    emitter.store_local(DV_sym_52241_3_parameter_value, s_b_31_1);
    /* execute.a64:2682 [F] s_b_31_3 = (u32)s_b_31_0 (const) */
    /* execute.a64:2682 [F] s_b_31_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_31_5 = s_b_31_3==s_b_31_4 (const) */
    uint8_t s_b_31_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_31_6: If s_b_31_5: Jump b_33 else b_34 (const) */
    if (s_b_31_5) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_34;
    }
  }
  /* b_18,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2693 [F] s_b_32_0=sym_6233_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_32_1 = sym_52021_3_parameter_value uint64_t */
    auto s_b_32_1 = emitter.load_local(DV_sym_52021_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_32_2 = (u32)s_b_32_1 */
    auto s_b_32_2 = emitter.truncate(s_b_32_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_32_3 = (u64)s_b_32_2 */
    auto s_b_32_3 = emitter.zx(s_b_32_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_32_4: sym_52263_3_parameter_value = s_b_32_3, dominates: s_b_35_1  */
    emitter.store_local(DV_sym_52263_3_parameter_value, s_b_32_3);
    /* execute.a64:2682 [F] s_b_32_5 = (u32)s_b_32_0 (const) */
    /* execute.a64:2682 [F] s_b_32_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_32_7 = s_b_32_5==s_b_32_6 (const) */
    uint8_t s_b_32_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_32_8: If s_b_32_7: Jump b_33 else b_35 (const) */
    if (s_b_32_7) 
    {
      goto fixed_block_b_33;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_31, b_32, b_34, b_35,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2460 [F] s_b_33_0=sym_6233_3_parameter_inst.opc (const) */
    /* execute.a64:2460 [F] s_b_33_1 = (u32)s_b_33_0 (const) */
    /* execute.a64:2460 [F] s_b_33_2 = constant u32 3 (const) */
    /* execute.a64:2460 [F] s_b_33_3 = s_b_33_1==s_b_33_2 (const) */
    uint8_t s_b_33_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:2460 [F] s_b_33_4: If s_b_33_3: Jump b_1 else b_2 (const) */
    if (s_b_33_3) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_31,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2684 [F] s_b_34_0=sym_6233_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_34_1 = sym_52241_3_parameter_value uint64_t */
    auto s_b_34_1 = emitter.load_local(DV_sym_52241_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_34_2: WriteRegBank 0:s_b_34_0 = s_b_34_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_34_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_34_1);
    /* execute.a64:0 [F] s_b_34_3: Jump b_33 (const) */
    goto fixed_block_b_33;
  }
  /* b_32,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2684 [F] s_b_35_0=sym_6233_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_35_1 = sym_52263_3_parameter_value uint64_t */
    auto s_b_35_1 = emitter.load_local(DV_sym_52263_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_35_2: WriteRegBank 0:s_b_35_0 = s_b_35_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_35_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_35_1);
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ccmpi(const aarch64_decode_a64_COND_CMP_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
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
  uint8_t CV_sym_53897_0_state;
  auto DV_sym_53897_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_53985_1__R_s_b_0_2 = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_6753_0_rn = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_54010_1__R_s_b_1_4 = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2020 [F] s_b_0_0=sym_6735_3_parameter_inst.cond (const) */
    /* execute.a64:2791 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2791 [F] s_b_0_2: sym_53897_0_state = s_b_0_1 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_53897_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_53897_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2793 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_6 (const) -> b_10, b_11, b_12, b_13, b_14, b_8, b_6, b_7, b_9,  */
    switch (s_b_0_5) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_8;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_11;
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
    /* execute.a64:2828 [F] s_b_6_0=sym_6735_3_parameter_inst.cond (const) */
    /* execute.a64:2828 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2828 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_6_3 = s_b_6_1&s_b_6_2 (const) */
    uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_6_4 = constant u32 1 (const) */
    /* execute.a64:2828 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(s_b_6_3 == (uint32_t)1ULL));
    /* execute.a64:2828 [F] s_b_6_6=sym_6735_3_parameter_inst.cond (const) */
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
    /* execute.a64:2807 [D] s_b_7_1: sym_53897_0_state = s_b_7_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53897_0_state, s_b_7_0);
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
    /* execute.a64:2803 [D] s_b_8_1: sym_53897_0_state = s_b_8_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53897_0_state, s_b_8_0);
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
    /* execute.a64:2799 [D] s_b_9_1: sym_53897_0_state = s_b_9_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53897_0_state, s_b_9_0);
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
    /* execute.a64:2795 [D] s_b_10_1: sym_53897_0_state = s_b_10_0, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53897_0_state, s_b_10_0);
    /* execute.a64:0 [F] s_b_10_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_0,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2823 [F] s_b_11_0 = constant u8 1 (const) */
    /* execute.a64:2823 [F] s_b_11_1: sym_53897_0_state = s_b_11_0 (const), dominates: s_b_15_0 s_b_16_0  */
    CV_sym_53897_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_53897_0_state, emitter.const_u8((uint8_t)1ULL));
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
    /* execute.a64:2811 [D] s_b_12_4: sym_53897_0_state = s_b_12_3, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53897_0_state, s_b_12_3);
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
    /* execute.a64:2819 [D] s_b_13_6: sym_53897_0_state = s_b_13_5, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53897_0_state, s_b_13_5);
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
    /* execute.a64:2815 [D] s_b_14_3: sym_53897_0_state = s_b_14_2, dominates: s_b_15_0 s_b_16_0  */
    emitter.store_local(DV_sym_53897_0_state, s_b_14_2);
    /* execute.a64:0 [F] s_b_14_4: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2829 [D] s_b_15_0 = sym_53897_0_state uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_53897_0_state, emitter.context().types().u8());
    /* execute.a64:2829 [D] s_b_15_1 = !s_b_15_0 */
    auto s_b_15_1 = emitter.cmp_eq(s_b_15_0, emitter.const_u8(0));
    /* execute.a64:2829 [D] s_b_15_2: sym_53985_1__R_s_b_0_2 = s_b_15_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_53985_1__R_s_b_0_2, s_b_15_1);
    /* execute.a64:2829 [F] s_b_15_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2831 [D] s_b_16_0 = sym_53897_0_state uint8_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_53897_0_state, emitter.context().types().u8());
    /* execute.a64:2831 [D] s_b_16_1: sym_53985_1__R_s_b_0_2 = s_b_16_0, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_53985_1__R_s_b_0_2, s_b_16_0);
    /* execute.a64:2831 [F] s_b_16_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2020 [D] s_b_17_0 = sym_53985_1__R_s_b_0_2 uint8_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_53985_1__R_s_b_0_2, emitter.context().types().u8());
    /* execute.a64:2022 [D] s_b_17_1 = (u32)s_b_17_0 */
    auto s_b_17_1 = emitter.zx(s_b_17_0, emitter.context().types().u32());
    /* execute.a64:2022 [F] s_b_17_2 = constant u32 0 (const) */
    /* execute.a64:2022 [D] s_b_17_3 = s_b_17_1!=s_b_17_2 */
    auto s_b_17_3 = emitter.cmp_ne(s_b_17_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2022 [D] s_b_17_4: If s_b_17_3: Jump b_1 else b_3 */
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
        /* execute.a64:2023 [F] s_b_1_0=sym_6735_3_parameter_inst.sf (const) */
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
        /* execute.a64:2031 [F] s_b_3_0=sym_6735_3_parameter_inst.nzcv (const) */
        /* execute.a64:2031 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
        /* execute.a64:2031 [F] s_b_3_2 = constant u32 8 (const) */
        /* execute.a64:2031 [F] s_b_3_3 = s_b_3_1&s_b_3_2 (const) */
        uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)8ULL));
        /* execute.a64:2031 [F] s_b_3_4 = constant u32 8 (const) */
        /* execute.a64:2031 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
        uint8_t s_b_3_5 = ((uint8_t)(s_b_3_3 == (uint32_t)8ULL));
        /* execute.a64:2031 [F] s_b_3_6: WriteReg 1 = s_b_3_5 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), emitter.const_u8(s_b_3_5), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1296), emitter.const_u8(s_b_3_5));
        /* execute.a64:2032 [F] s_b_3_7=sym_6735_3_parameter_inst.nzcv (const) */
        /* execute.a64:2032 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
        /* execute.a64:2032 [F] s_b_3_9 = constant u32 4 (const) */
        /* execute.a64:2032 [F] s_b_3_10 = s_b_3_8&s_b_3_9 (const) */
        uint32_t s_b_3_10 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)4ULL));
        /* execute.a64:2032 [F] s_b_3_11 = constant u32 4 (const) */
        /* execute.a64:2032 [F] s_b_3_12 = s_b_3_10==s_b_3_11 (const) */
        uint8_t s_b_3_12 = ((uint8_t)(s_b_3_10 == (uint32_t)4ULL));
        /* execute.a64:2032 [F] s_b_3_13: WriteReg 2 = s_b_3_12 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), emitter.const_u8(s_b_3_12), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1297), emitter.const_u8(s_b_3_12));
        /* execute.a64:2033 [F] s_b_3_14=sym_6735_3_parameter_inst.nzcv (const) */
        /* execute.a64:2033 [F] s_b_3_15 = (u32)s_b_3_14 (const) */
        /* execute.a64:2033 [F] s_b_3_16 = constant u32 2 (const) */
        /* execute.a64:2033 [F] s_b_3_17 = s_b_3_15&s_b_3_16 (const) */
        uint32_t s_b_3_17 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)2ULL));
        /* execute.a64:2033 [F] s_b_3_18 = constant u32 2 (const) */
        /* execute.a64:2033 [F] s_b_3_19 = s_b_3_17==s_b_3_18 (const) */
        uint8_t s_b_3_19 = ((uint8_t)(s_b_3_17 == (uint32_t)2ULL));
        /* execute.a64:2033 [F] s_b_3_20: WriteReg 3 = s_b_3_19 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), emitter.const_u8(s_b_3_19), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1298), emitter.const_u8(s_b_3_19));
        /* execute.a64:2034 [F] s_b_3_21=sym_6735_3_parameter_inst.nzcv (const) */
        /* execute.a64:2034 [F] s_b_3_22 = (u32)s_b_3_21 (const) */
        /* execute.a64:2034 [F] s_b_3_23 = constant u32 1 (const) */
        /* execute.a64:2034 [F] s_b_3_24 = s_b_3_22&s_b_3_23 (const) */
        uint32_t s_b_3_24 = ((uint32_t)(((uint32_t)insn.nzcv) & (uint32_t)1ULL));
        /* execute.a64:2034 [F] s_b_3_25 = constant u32 1 (const) */
        /* execute.a64:2034 [F] s_b_3_26 = s_b_3_24==s_b_3_25 (const) */
        uint8_t s_b_3_26 = ((uint8_t)(s_b_3_24 == (uint32_t)1ULL));
        /* execute.a64:2034 [F] s_b_3_27: WriteReg 4 = s_b_3_26 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), emitter.const_u8(s_b_3_26), emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32(1299), emitter.const_u8(s_b_3_26));
        /* execute.a64:2031 [F] s_b_3_28: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_4) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_4);
        /* execute.a64:2026 [D] s_b_4_0 = sym_6753_0_rn uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_6753_0_rn, emitter.context().types().u64());
        /* execute.a64:2026 [D] s_b_4_1 = (u32)s_b_4_0 */
        auto s_b_4_1 = emitter.truncate(s_b_4_0, emitter.context().types().u32());
        /* execute.a64:2026 [F] s_b_4_2=sym_6735_3_parameter_inst.imm5 (const) */
        /* execute.a64:2026 [F] s_b_4_3 = (u32)s_b_4_2 (const) */
        /* execute.a64:2026 [F] s_b_4_4 = ~s_b_4_3 (const) */
        uint32_t s_b_4_4 = ~((uint32_t)insn.imm5);
        /* execute.a64:2026 [F] s_b_4_5 = constant u8 1 (const) */
        /* execute.a64:2026 [D] s_b_4_6 = __builtin_adc32_flags */
        auto s_b_4_6 = emitter.adcf(s_b_4_1, emitter.const_u32(s_b_4_4), emitter.const_u8((uint8_t)1ULL));
        /* execute.a64:2026 [F] s_b_4_7: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:2028 [D] s_b_5_0 = sym_6753_0_rn uint64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_6753_0_rn, emitter.context().types().u64());
        /* execute.a64:2028 [F] s_b_5_1=sym_6735_3_parameter_inst.imm5 (const) */
        /* execute.a64:2028 [F] s_b_5_2 = (u64)s_b_5_1 (const) */
        /* execute.a64:2028 [F] s_b_5_3 = ~s_b_5_2 (const) */
        uint64_t s_b_5_3 = ~((uint64_t)insn.imm5);
        /* execute.a64:2028 [F] s_b_5_4 = constant u8 1 (const) */
        /* execute.a64:2028 [D] s_b_5_5 = __builtin_adc64_flags */
        auto s_b_5_5 = emitter.adcf(s_b_5_0, emitter.const_u64(s_b_5_3), emitter.const_u8((uint8_t)1ULL));
        /* execute.a64:2028 [F] s_b_5_6: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.a64:2657 [F] s_b_18_0=sym_6735_3_parameter_inst.rn (const) */
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
        /* execute.a64:2657 [D] s_b_18_7: sym_54010_1__R_s_b_1_4 = s_b_18_6, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_54010_1__R_s_b_1_4, s_b_18_6);
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
        /* execute.a64:2659 [F] s_b_19_0=sym_6735_3_parameter_inst.rn (const) */
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
        /* execute.a64:2659 [D] s_b_19_8: sym_54010_1__R_s_b_1_4 = s_b_19_7, dominates: s_b_20_0  */
        emitter.store_local(DV_sym_54010_1__R_s_b_1_4, s_b_19_7);
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
        /* execute.a64:2023 [D] s_b_20_0 = sym_54010_1__R_s_b_1_4 uint64_t */
        auto s_b_20_0 = emitter.load_local(DV_sym_54010_1__R_s_b_1_4, emitter.context().types().u64());
        /* execute.a64:2023 [D] s_b_20_1: sym_6753_0_rn = s_b_20_0, dominates: s_b_4_0 s_b_5_0  */
        emitter.store_local(DV_sym_6753_0_rn, s_b_20_0);
        /* execute.a64:2025 [F] s_b_20_2=sym_6735_3_parameter_inst.sf (const) */
        /* execute.a64:2025 [F] s_b_20_3 = (u32)s_b_20_2 (const) */
        /* execute.a64:2025 [F] s_b_20_4 = constant u32 0 (const) */
        /* execute.a64:2025 [F] s_b_20_5 = s_b_20_3==s_b_20_4 (const) */
        uint8_t s_b_20_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
        /* execute.a64:2025 [F] s_b_20_6: If s_b_20_5: Jump b_4 else b_5 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_cmhi_reg(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
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
    /* execute.simd:1581 [F] s_b_0_0=sym_7776_3_parameter_inst.SCALAR (const) */
    /* execute.simd:1581 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1582 [F] s_b_1_0=sym_7776_3_parameter_inst.rn (const) */
    /* execute.simd:6275 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:1583 [F] s_b_1_2=sym_7776_3_parameter_inst.rm (const) */
    /* execute.simd:6275 [D] s_b_1_3 = ReadRegBank 7:s_b_1_2 (u64) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(8));
    }
    /* execute.simd:1585 [D] s_b_1_4 = s_b_1_1>s_b_1_3 */
    auto s_b_1_4 = emitter.cmp_gt(s_b_1_1, s_b_1_3);
    /* execute.simd:1585 [D] s_b_1_5: If s_b_1_4: Jump b_4 else b_5 */
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
      emitter.branch(s_b_1_4, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1591 [F] s_b_3_0=sym_7776_3_parameter_inst.arrangement (const) */
    /* execute.simd:1592 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:1602 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:1611 [F] s_b_3_3 = constant s32 2 (const) */
    /* execute.simd:1621 [F] s_b_3_4 = constant s32 3 (const) */
    /* execute.simd:1630 [F] s_b_3_5 = constant s32 4 (const) */
    /* execute.simd:1640 [F] s_b_3_6 = constant s32 5 (const) */
    /* execute.simd:1649 [F] s_b_3_7 = constant s32 6 (const) */
    /* execute.simd:1591 [F] s_b_3_8: Switch s_b_3_0: < <todo> > def b_13 (const) -> b_13, b_12, b_11, b_10, b_9, b_8, b_7, b_6,  */
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
    /* execute.simd:1593 [F] s_b_6_0=sym_7776_3_parameter_inst.rn (const) */
    /* execute.simd:1593 [D] s_b_6_1 = ReadRegBank 15:s_b_6_0 (v8u8) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:1594 [F] s_b_6_2=sym_7776_3_parameter_inst.rm (const) */
    /* execute.simd:1594 [D] s_b_6_3 = ReadRegBank 15:s_b_6_2 (v8u8) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:1596 [D] s_b_6_4 = s_b_6_1>s_b_6_3 */
    auto s_b_6_4 = emitter.cmp_gt(s_b_6_1, s_b_6_3);
    /* execute.simd:1597 [F] s_b_6_5=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1597 [D] s_b_6_6: WriteRegBank 15:s_b_6_5 = s_b_6_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4);
    /* execute.simd:1598 [F] s_b_6_7=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1598 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:1598 [F] s_b_6_9: WriteRegBank 3:s_b_6_7 = s_b_6_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:1603 [F] s_b_7_0=sym_7776_3_parameter_inst.rn (const) */
    /* execute.simd:1603 [D] s_b_7_1 = ReadRegBank 16:s_b_7_0 (v16u8) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:1604 [F] s_b_7_2=sym_7776_3_parameter_inst.rm (const) */
    /* execute.simd:1604 [D] s_b_7_3 = ReadRegBank 16:s_b_7_2 (v16u8) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:1606 [D] s_b_7_4 = s_b_7_1>s_b_7_3 */
    auto s_b_7_4 = emitter.cmp_gt(s_b_7_1, s_b_7_3);
    /* execute.simd:1607 [F] s_b_7_5=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1607 [D] s_b_7_6: WriteRegBank 16:s_b_7_5 = s_b_7_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4,emitter.const_u8(16));
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
    /* execute.simd:1612 [F] s_b_8_0=sym_7776_3_parameter_inst.rn (const) */
    /* execute.simd:1612 [D] s_b_8_1 = ReadRegBank 17:s_b_8_0 (v4u16) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.simd:1613 [F] s_b_8_2=sym_7776_3_parameter_inst.rm (const) */
    /* execute.simd:1613 [D] s_b_8_3 = ReadRegBank 17:s_b_8_2 (v4u16) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(8));
    }
    /* execute.simd:1615 [D] s_b_8_4 = s_b_8_1>s_b_8_3 */
    auto s_b_8_4 = emitter.cmp_gt(s_b_8_1, s_b_8_3);
    /* execute.simd:1616 [F] s_b_8_5=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1616 [D] s_b_8_6: WriteRegBank 17:s_b_8_5 = s_b_8_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_4);
    /* execute.simd:1617 [F] s_b_8_7=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1617 [F] s_b_8_8 = constant u64 0 (const) */
    /* execute.simd:1617 [F] s_b_8_9: WriteRegBank 3:s_b_8_7 = s_b_8_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:1622 [F] s_b_9_0=sym_7776_3_parameter_inst.rn (const) */
    /* execute.simd:1622 [D] s_b_9_1 = ReadRegBank 18:s_b_9_0 (v8u16) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_9_1,emitter.const_u8(16));
    }
    /* execute.simd:1623 [F] s_b_9_2=sym_7776_3_parameter_inst.rm (const) */
    /* execute.simd:1623 [D] s_b_9_3 = ReadRegBank 18:s_b_9_2 (v8u16) */
    auto s_b_9_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_9_3,emitter.const_u8(16));
    }
    /* execute.simd:1625 [D] s_b_9_4 = s_b_9_1>s_b_9_3 */
    auto s_b_9_4 = emitter.cmp_gt(s_b_9_1, s_b_9_3);
    /* execute.simd:1627 [F] s_b_9_5=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1627 [D] s_b_9_6: WriteRegBank 18:s_b_9_5 = s_b_9_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_9_4,emitter.const_u8(16));
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
    /* execute.simd:1631 [F] s_b_10_0=sym_7776_3_parameter_inst.rn (const) */
    /* execute.simd:1631 [D] s_b_10_1 = ReadRegBank 19:s_b_10_0 (v2u32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.simd:1632 [F] s_b_10_2=sym_7776_3_parameter_inst.rm (const) */
    /* execute.simd:1632 [D] s_b_10_3 = ReadRegBank 19:s_b_10_2 (v2u32) */
    auto s_b_10_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_3,emitter.const_u8(8));
    }
    /* execute.simd:1634 [D] s_b_10_4 = s_b_10_1>s_b_10_3 */
    auto s_b_10_4 = emitter.cmp_gt(s_b_10_1, s_b_10_3);
    /* execute.simd:1635 [F] s_b_10_5=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1635 [D] s_b_10_6: WriteRegBank 19:s_b_10_5 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_4);
    /* execute.simd:1636 [F] s_b_10_7=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1636 [F] s_b_10_8 = constant u64 0 (const) */
    /* execute.simd:1636 [F] s_b_10_9: WriteRegBank 3:s_b_10_7 = s_b_10_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
    /* execute.simd:1641 [F] s_b_11_0=sym_7776_3_parameter_inst.rn (const) */
    /* execute.simd:1641 [D] s_b_11_1 = ReadRegBank 20:s_b_11_0 (v4u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_11_1,emitter.const_u8(16));
    }
    /* execute.simd:1642 [F] s_b_11_2=sym_7776_3_parameter_inst.rm (const) */
    /* execute.simd:1642 [D] s_b_11_3 = ReadRegBank 20:s_b_11_2 (v4u32) */
    auto s_b_11_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_11_3,emitter.const_u8(16));
    }
    /* execute.simd:1644 [D] s_b_11_4 = s_b_11_1>s_b_11_3 */
    auto s_b_11_4 = emitter.cmp_gt(s_b_11_1, s_b_11_3);
    /* execute.simd:1646 [F] s_b_11_5=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1646 [D] s_b_11_6: WriteRegBank 20:s_b_11_5 = s_b_11_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_11_4,emitter.const_u8(16));
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
    /* execute.simd:1650 [F] s_b_12_0=sym_7776_3_parameter_inst.rn (const) */
    /* execute.simd:1650 [D] s_b_12_1 = ReadRegBank 21:s_b_12_0 (v2u64) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(16));
    }
    /* execute.simd:1651 [F] s_b_12_2=sym_7776_3_parameter_inst.rm (const) */
    /* execute.simd:1651 [D] s_b_12_3 = ReadRegBank 21:s_b_12_2 (v2u64) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_12_3,emitter.const_u8(16));
    }
    /* execute.simd:1653 [D] s_b_12_4 = s_b_12_1>s_b_12_3 */
    auto s_b_12_4 = emitter.cmp_gt(s_b_12_1, s_b_12_3);
    /* execute.simd:1655 [F] s_b_12_5=sym_7776_3_parameter_inst.rd (const) */
    /* execute.simd:1655 [D] s_b_12_6: WriteRegBank 21:s_b_12_5 = s_b_12_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_4,emitter.const_u8(16));
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
    /* execute.simd:1659 [D] s_b_13_0 = trap */
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
        /* execute.simd:1586 [F] s_b_4_0=sym_7776_3_parameter_inst.rd (const) */
        /* execute.simd:1586 [F] s_b_4_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6246 [F] s_b_4_2: WriteRegBank 2:s_b_4_0 = s_b_4_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6247 [F] s_b_4_3 = constant u64 0 (const) */
        /* execute.simd:6247 [F] s_b_4_4: WriteRegBank 3:s_b_4_0 = s_b_4_3 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
        /* execute.simd:1588 [F] s_b_5_0=sym_7776_3_parameter_inst.rd (const) */
        /* execute.simd:1588 [F] s_b_5_1 = constant u64 0 (const) */
        /* execute.simd:6246 [F] s_b_5_2: WriteRegBank 2:s_b_5_0 = s_b_5_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6247 [F] s_b_5_3 = constant u64 0 (const) */
        /* execute.simd:6247 [F] s_b_5_4: WriteRegBank 3:s_b_5_0 = s_b_5_3 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_csinv(const aarch64_decode_a64_COND_SEL&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_56528_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56624_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  uint8_t CV_sym_56279_0_state;
  auto DV_sym_56279_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_56558_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56602_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56580_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56322_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_56404_1__R_s_b_3_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56464_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_56373_1__R_s_b_1_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2128 [F] s_b_0_0=sym_9035_3_parameter_inst.cond (const) */
    /* execute.a64:2791 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2791 [F] s_b_0_2: sym_56279_0_state = s_b_0_1 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_56279_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_56279_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2793 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_4 (const) -> b_13, b_4, b_12, b_9, b_10, b_11, b_7, b_8, b_14,  */
    switch (s_b_0_5) 
    {
    case (int32_t)7ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_7;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_10;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_9;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
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
    /* execute.a64:2828 [F] s_b_4_0=sym_9035_3_parameter_inst.cond (const) */
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
    /* execute.a64:2829 [D] s_b_5_0 = sym_56279_0_state uint8_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_56279_0_state, emitter.context().types().u8());
    /* execute.a64:2829 [D] s_b_5_1 = !s_b_5_0 */
    auto s_b_5_1 = emitter.cmp_eq(s_b_5_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_5_2: sym_56322_0_return_symbol = s_b_5_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_56322_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2831 [D] s_b_6_0 = sym_56279_0_state uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_56279_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_6_1: sym_56322_0_return_symbol = s_b_6_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_56322_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2795 [D] s_b_7_1: sym_56279_0_state = s_b_7_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56279_0_state, s_b_7_0);
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
    /* execute.a64:2799 [D] s_b_8_1: sym_56279_0_state = s_b_8_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56279_0_state, s_b_8_0);
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
    /* execute.a64:2803 [D] s_b_9_1: sym_56279_0_state = s_b_9_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56279_0_state, s_b_9_0);
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
    /* execute.a64:2807 [D] s_b_10_1: sym_56279_0_state = s_b_10_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56279_0_state, s_b_10_0);
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
    /* execute.a64:2811 [D] s_b_11_4: sym_56279_0_state = s_b_11_3, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56279_0_state, s_b_11_3);
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
    /* execute.a64:2815 [D] s_b_12_3: sym_56279_0_state = s_b_12_2, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56279_0_state, s_b_12_2);
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
    /* execute.a64:2819 [D] s_b_13_6: sym_56279_0_state = s_b_13_5, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_56279_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2823 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2823 [F] s_b_14_1: sym_56279_0_state = s_b_14_0 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_56279_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_56279_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5, b_6,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_56322_0_return_symbol uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_56322_0_return_symbol, emitter.context().types().u8());
    /* execute.a64:2130 [D] s_b_15_1 = (u32)s_b_15_0 */
    auto s_b_15_1 = emitter.zx(s_b_15_0, emitter.context().types().u32());
    /* execute.a64:2130 [F] s_b_15_2 = constant u32 0 (const) */
    /* execute.a64:2130 [D] s_b_15_3 = s_b_15_1==s_b_15_2 */
    auto s_b_15_3 = emitter.cmp_eq(s_b_15_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2130 [D] s_b_15_4: If s_b_15_3: Jump b_1 else b_3 */
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
        /* execute.a64:2131 [F] s_b_1_0=sym_9035_3_parameter_inst.sf (const) */
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
        /* execute.a64:2133 [F] s_b_3_0=sym_9035_3_parameter_inst.sf (const) */
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
        /* execute.a64:2657 [F] s_b_16_0=sym_9035_3_parameter_inst.rm (const) */
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
        /* execute.a64:2657 [D] s_b_16_7: sym_56373_1__R_s_b_1_6 = s_b_16_6, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_56373_1__R_s_b_1_6, s_b_16_6);
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
        /* execute.a64:2659 [F] s_b_17_0=sym_9035_3_parameter_inst.rm (const) */
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
        /* execute.a64:2659 [D] s_b_17_8: sym_56373_1__R_s_b_1_6 = s_b_17_7, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_56373_1__R_s_b_1_6, s_b_17_7);
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
        /* ???:4294967295 [F] s_b_18_0=sym_9035_3_parameter_inst.sf (const) */
        /* execute.a64:2131 [D] s_b_18_1 = sym_56373_1__R_s_b_1_6 uint64_t */
        auto s_b_18_1 = emitter.load_local(DV_sym_56373_1__R_s_b_1_6, emitter.context().types().u64());
        /* execute.a64:2131 [D] s_b_18_2 = ~s_b_18_1 */
        auto s_b_18_2 = emitter.bitwise_not(s_b_18_1);
        /* execute.a64:2131 [D] s_b_18_3: sym_56464_3_parameter_value = s_b_18_2, dominates: s_b_22_1 s_b_23_1  */
        emitter.store_local(DV_sym_56464_3_parameter_value, s_b_18_2);
        /* execute.a64:2690 [F] s_b_18_4: If s_b_18_0: Jump b_22 else b_23 (const) */
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
        /* execute.a64:2657 [F] s_b_19_0=sym_9035_3_parameter_inst.rn (const) */
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
        /* execute.a64:2657 [D] s_b_19_7: sym_56404_1__R_s_b_3_6 = s_b_19_6, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_56404_1__R_s_b_3_6, s_b_19_6);
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
        /* execute.a64:2659 [F] s_b_20_0=sym_9035_3_parameter_inst.rn (const) */
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
        /* execute.a64:2659 [D] s_b_20_8: sym_56404_1__R_s_b_3_6 = s_b_20_7, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_56404_1__R_s_b_3_6, s_b_20_7);
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
        /* ???:4294967295 [F] s_b_21_0=sym_9035_3_parameter_inst.sf (const) */
        /* execute.a64:2133 [D] s_b_21_1 = sym_56404_1__R_s_b_3_6 uint64_t */
        auto s_b_21_1 = emitter.load_local(DV_sym_56404_1__R_s_b_3_6, emitter.context().types().u64());
        /* execute.a64:2133 [D] s_b_21_2: sym_56528_3_parameter_value = s_b_21_1, dominates: s_b_24_1 s_b_25_1  */
        emitter.store_local(DV_sym_56528_3_parameter_value, s_b_21_1);
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
        /* execute.a64:2691 [F] s_b_22_0=sym_9035_3_parameter_inst.rd (const) */
        /* execute.a64:2691 [D] s_b_22_1 = sym_56464_3_parameter_value uint64_t */
        auto s_b_22_1 = emitter.load_local(DV_sym_56464_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2691 [D] s_b_22_2: sym_56558_3_parameter_value = s_b_22_1, dominates: s_b_26_1  */
        emitter.store_local(DV_sym_56558_3_parameter_value, s_b_22_1);
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
        /* execute.a64:2693 [F] s_b_23_0=sym_9035_3_parameter_inst.rd (const) */
        /* execute.a64:2693 [D] s_b_23_1 = sym_56464_3_parameter_value uint64_t */
        auto s_b_23_1 = emitter.load_local(DV_sym_56464_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_23_2 = (u32)s_b_23_1 */
        auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_23_3 = (u64)s_b_23_2 */
        auto s_b_23_3 = emitter.zx(s_b_23_2, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_23_4: sym_56580_3_parameter_value = s_b_23_3, dominates: s_b_27_1  */
        emitter.store_local(DV_sym_56580_3_parameter_value, s_b_23_3);
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
        /* execute.a64:2691 [F] s_b_24_0=sym_9035_3_parameter_inst.rd (const) */
        /* execute.a64:2691 [D] s_b_24_1 = sym_56528_3_parameter_value uint64_t */
        auto s_b_24_1 = emitter.load_local(DV_sym_56528_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2691 [D] s_b_24_2: sym_56602_3_parameter_value = s_b_24_1, dominates: s_b_28_1  */
        emitter.store_local(DV_sym_56602_3_parameter_value, s_b_24_1);
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
        /* execute.a64:2693 [F] s_b_25_0=sym_9035_3_parameter_inst.rd (const) */
        /* execute.a64:2693 [D] s_b_25_1 = sym_56528_3_parameter_value uint64_t */
        auto s_b_25_1 = emitter.load_local(DV_sym_56528_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_25_2 = (u32)s_b_25_1 */
        auto s_b_25_2 = emitter.truncate(s_b_25_1, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_25_3 = (u64)s_b_25_2 */
        auto s_b_25_3 = emitter.zx(s_b_25_2, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_25_4: sym_56624_3_parameter_value = s_b_25_3, dominates: s_b_29_1  */
        emitter.store_local(DV_sym_56624_3_parameter_value, s_b_25_3);
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
        /* execute.a64:2684 [F] s_b_26_0=sym_9035_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_26_1 = sym_56558_3_parameter_value uint64_t */
        auto s_b_26_1 = emitter.load_local(DV_sym_56558_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2684 [F] s_b_27_0=sym_9035_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_27_1 = sym_56580_3_parameter_value uint64_t */
        auto s_b_27_1 = emitter.load_local(DV_sym_56580_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2684 [F] s_b_28_0=sym_9035_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_28_1 = sym_56602_3_parameter_value uint64_t */
        auto s_b_28_1 = emitter.load_local(DV_sym_56602_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2684 [F] s_b_29_0=sym_9035_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_29_1 = sym_56624_3_parameter_value uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_56624_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_eret(const aarch64_decode_a64_UB_REG&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:568 [D] s_b_0_0 = ReadReg 16 (u64) */
    auto s_b_0_0 = emitter.load_register(emitter.const_u32(1376), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1376), s_b_0_0, emitter.const_u8(8));
    }
    /* execute.a64:568 [D] s_b_0_1 = (u64)s_b_0_0 */
    auto s_b_0_1 = (dbt::el::Value *)s_b_0_0;
    /* execute.a64:568 [D] s_b_0_2 = ReadReg 17 (u32) */
    auto s_b_0_2 = emitter.load_register(emitter.const_u32(1384), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1384), s_b_0_2, emitter.const_u8(4));
    }
    /* execute.a64:568 [D] s_b_0_3 = (u32)s_b_0_2 */
    auto s_b_0_3 = (dbt::el::Value *)s_b_0_2;
    /* execute.a64:2851 [F] s_b_0_4 = constant u32 80000000 (const) */
    /* execute.a64:2851 [D] s_b_0_5 = s_b_0_3&s_b_0_4 */
    auto s_b_0_5 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)2147483648ULL));
    /* execute.a64:2851 [F] s_b_0_6 = constant u64 80000000 (const) */
    /* execute.a64:2851 [D] s_b_0_7 = (u64)s_b_0_5 */
    auto s_b_0_7 = emitter.zx(s_b_0_5, emitter.context().types().u64());
    /* execute.a64:2851 [D] s_b_0_8 = s_b_0_7==s_b_0_6 */
    auto s_b_0_8 = emitter.cmp_eq(s_b_0_7, emitter.const_u64((uint64_t)2147483648ULL));
    /* execute.a64:2851 [D] s_b_0_9: WriteReg 1 = s_b_0_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1296), s_b_0_8, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1296), s_b_0_8);
    /* execute.a64:2852 [F] s_b_0_10 = constant u32 40000000 (const) */
    /* execute.a64:2852 [D] s_b_0_11 = s_b_0_3&s_b_0_10 */
    auto s_b_0_11 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)1073741824ULL));
    /* execute.a64:2852 [F] s_b_0_12 = constant u64 40000000 (const) */
    /* execute.a64:2852 [D] s_b_0_13 = (u64)s_b_0_11 */
    auto s_b_0_13 = emitter.zx(s_b_0_11, emitter.context().types().u64());
    /* execute.a64:2852 [D] s_b_0_14 = s_b_0_13==s_b_0_12 */
    auto s_b_0_14 = emitter.cmp_eq(s_b_0_13, emitter.const_u64((uint64_t)1073741824ULL));
    /* execute.a64:2852 [D] s_b_0_15: WriteReg 2 = s_b_0_14 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1297), s_b_0_14, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1297), s_b_0_14);
    /* execute.a64:2853 [F] s_b_0_16 = constant u32 20000000 (const) */
    /* execute.a64:2853 [D] s_b_0_17 = s_b_0_3&s_b_0_16 */
    auto s_b_0_17 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)536870912ULL));
    /* execute.a64:2853 [F] s_b_0_18 = constant u64 20000000 (const) */
    /* execute.a64:2853 [D] s_b_0_19 = (u64)s_b_0_17 */
    auto s_b_0_19 = emitter.zx(s_b_0_17, emitter.context().types().u64());
    /* execute.a64:2853 [D] s_b_0_20 = s_b_0_19==s_b_0_18 */
    auto s_b_0_20 = emitter.cmp_eq(s_b_0_19, emitter.const_u64((uint64_t)536870912ULL));
    /* execute.a64:2853 [D] s_b_0_21: WriteReg 3 = s_b_0_20 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1298), s_b_0_20, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1298), s_b_0_20);
    /* execute.a64:2854 [F] s_b_0_22 = constant u32 10000000 (const) */
    /* execute.a64:2854 [D] s_b_0_23 = s_b_0_3&s_b_0_22 */
    auto s_b_0_23 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)268435456ULL));
    /* execute.a64:2854 [F] s_b_0_24 = constant u64 10000000 (const) */
    /* execute.a64:2854 [D] s_b_0_25 = (u64)s_b_0_23 */
    auto s_b_0_25 = emitter.zx(s_b_0_23, emitter.context().types().u64());
    /* execute.a64:2854 [D] s_b_0_26 = s_b_0_25==s_b_0_24 */
    auto s_b_0_26 = emitter.cmp_eq(s_b_0_25, emitter.const_u64((uint64_t)268435456ULL));
    /* execute.a64:2854 [D] s_b_0_27: WriteReg 4 = s_b_0_26 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1299), s_b_0_26, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1299), s_b_0_26);
    /* execute.a64:2856 [F] s_b_0_28 = constant u32 200 (const) */
    /* execute.a64:2856 [D] s_b_0_29 = s_b_0_3&s_b_0_28 */
    auto s_b_0_29 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)512ULL));
    /* execute.a64:2856 [F] s_b_0_30 = constant u64 200 (const) */
    /* execute.a64:2856 [D] s_b_0_31 = (u64)s_b_0_29 */
    auto s_b_0_31 = emitter.zx(s_b_0_29, emitter.context().types().u64());
    /* execute.a64:2856 [D] s_b_0_32 = s_b_0_31==s_b_0_30 */
    auto s_b_0_32 = emitter.cmp_eq(s_b_0_31, emitter.const_u64((uint64_t)512ULL));
    /* execute.a64:2856 [D] s_b_0_33: WriteReg 5 = s_b_0_32 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), s_b_0_32, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), s_b_0_32);
    /* execute.a64:2857 [F] s_b_0_34 = constant u32 100 (const) */
    /* execute.a64:2857 [D] s_b_0_35 = s_b_0_3&s_b_0_34 */
    auto s_b_0_35 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)256ULL));
    /* execute.a64:2857 [F] s_b_0_36 = constant u64 100 (const) */
    /* execute.a64:2857 [D] s_b_0_37 = (u64)s_b_0_35 */
    auto s_b_0_37 = emitter.zx(s_b_0_35, emitter.context().types().u64());
    /* execute.a64:2857 [D] s_b_0_38 = s_b_0_37==s_b_0_36 */
    auto s_b_0_38 = emitter.cmp_eq(s_b_0_37, emitter.const_u64((uint64_t)256ULL));
    /* execute.a64:2857 [D] s_b_0_39: WriteReg 6 = s_b_0_38 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), s_b_0_38, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), s_b_0_38);
    /* execute.a64:2858 [F] s_b_0_40 = constant u32 80 (const) */
    /* execute.a64:2858 [D] s_b_0_41 = s_b_0_3&s_b_0_40 */
    auto s_b_0_41 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)128ULL));
    /* execute.a64:2858 [F] s_b_0_42 = constant u64 80 (const) */
    /* execute.a64:2858 [D] s_b_0_43 = (u64)s_b_0_41 */
    auto s_b_0_43 = emitter.zx(s_b_0_41, emitter.context().types().u64());
    /* execute.a64:2858 [D] s_b_0_44 = s_b_0_43==s_b_0_42 */
    auto s_b_0_44 = emitter.cmp_eq(s_b_0_43, emitter.const_u64((uint64_t)128ULL));
    /* execute.a64:2858 [D] s_b_0_45: WriteReg 7 = s_b_0_44 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), s_b_0_44, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), s_b_0_44);
    /* execute.a64:2859 [F] s_b_0_46 = constant u32 40 (const) */
    /* execute.a64:2859 [D] s_b_0_47 = s_b_0_3&s_b_0_46 */
    auto s_b_0_47 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)64ULL));
    /* execute.a64:2859 [F] s_b_0_48 = constant u64 40 (const) */
    /* execute.a64:2859 [D] s_b_0_49 = (u64)s_b_0_47 */
    auto s_b_0_49 = emitter.zx(s_b_0_47, emitter.context().types().u64());
    /* execute.a64:2859 [D] s_b_0_50 = s_b_0_49==s_b_0_48 */
    auto s_b_0_50 = emitter.cmp_eq(s_b_0_49, emitter.const_u64((uint64_t)64ULL));
    /* execute.a64:2859 [D] s_b_0_51: WriteReg 8 = s_b_0_50 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), s_b_0_50, emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), s_b_0_50);
    /* execute.a64:2861 [F] s_b_0_52 = constant u32 2 (const) */
    /* execute.a64:2861 [D] s_b_0_53 = s_b_0_3>>s_b_0_52 */
    auto s_b_0_53 = emitter.shr(s_b_0_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.a64:2861 [D] s_b_0_54 = (u8)s_b_0_53 */
    auto s_b_0_54 = emitter.truncate(s_b_0_53, emitter.context().types().u8());
    /* execute.a64:2861 [F] s_b_0_55 = constant u8 3 (const) */
    /* execute.a64:2861 [D] s_b_0_56 = s_b_0_54&s_b_0_55 */
    auto s_b_0_56 = emitter.bitwise_and(s_b_0_54, emitter.const_u8((uint8_t)3ULL));
    /* execute.a64:3017 [F] s_b_0_57 = constant u32 0 (const) */
    /* execute.a64:3017 [D] s_b_0_58 = (u32)s_b_0_56 */
    auto s_b_0_58 = emitter.zx(s_b_0_56, emitter.context().types().u32());
    /* execute.a64:3017 [D] s_b_0_59 = __builtin_set_feature */
    emitter.set_feature((uint32_t)0ULL, s_b_0_58);
    /* execute.a64:2863 [F] s_b_0_60 = constant u32 1 (const) */
    /* execute.a64:2863 [D] s_b_0_61 = s_b_0_3&s_b_0_60 */
    auto s_b_0_61 = emitter.bitwise_and(s_b_0_3, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:2863 [D] s_b_0_62 = (u8)s_b_0_61 */
    auto s_b_0_62 = emitter.truncate(s_b_0_61, emitter.context().types().u8());
    /* execute.a64:2953 [F] s_b_0_63 = constant u32 1 (const) */
    /* execute.a64:2953 [D] s_b_0_64 = (u32)s_b_0_62 */
    auto s_b_0_64 = emitter.zx(s_b_0_62, emitter.context().types().u32());
    /* execute.a64:2953 [D] s_b_0_65 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, s_b_0_64);
    /* execute.a64:3005 [D] s_b_0_66 = write_pc */
    emitter.store_pc(s_b_0_1);
    /* ???:4294967295 [F] s_b_0_67: Return */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fcmgt_zero(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
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
    /* execute.simd:2163 [F] s_b_0_0=sym_10584_3_parameter_inst.size (const) */
    /* execute.simd:2163 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:2163 [F] s_b_0_2 = constant u32 2 (const) */
    /* execute.simd:2163 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:2163 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2164 [F] s_b_1_0=sym_10584_3_parameter_inst.rn (const) */
    /* execute.simd:6200 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:2165 [F] s_b_1_2 = constant f32 0 (const) */
    float s_b_1_2;
    {
      uint32_t __tmp = 0;
      s_b_1_2 = *(float *)&__tmp;
    }
    /* execute.simd:2165 [D] s_b_1_3 = s_b_1_1>s_b_1_2 */
    auto s_b_1_3 = emitter.cmp_gt(s_b_1_1, emitter.const_f32(s_b_1_2));
    /* execute.simd:2165 [D] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 */
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
      emitter.branch(s_b_1_3, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2171 [F] s_b_3_0=sym_10584_3_parameter_inst.rn (const) */
    /* execute.simd:6205 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:2172 [F] s_b_3_2 = constant f64 0 (const) */
    double s_b_3_2;
    {
      uint64_t __tmp = 0;
      s_b_3_2 = *(double *)&__tmp;
    }
    /* execute.simd:2172 [D] s_b_3_3 = s_b_3_1>s_b_3_2 */
    auto s_b_3_3 = emitter.cmp_gt(s_b_3_1, emitter.const_f64(s_b_3_2));
    /* execute.simd:2172 [D] s_b_3_4: If s_b_3_3: Jump b_6 else b_7 */
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
        /* execute.simd:2166 [F] s_b_4_0=sym_10584_3_parameter_inst.rd (const) */
        /* execute.simd:6239 [F] s_b_4_1 = constant u64 ffffffff (const) */
        /* execute.simd:6239 [F] s_b_4_2: WriteRegBank 2:s_b_4_0 = s_b_4_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)4294967295ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)4294967295ULL));
        /* execute.simd:6240 [F] s_b_4_3 = constant u64 0 (const) */
        /* execute.simd:6240 [F] s_b_4_4: WriteRegBank 3:s_b_4_0 = s_b_4_3 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
        /* execute.simd:2168 [F] s_b_5_0=sym_10584_3_parameter_inst.rd (const) */
        /* execute.simd:6239 [F] s_b_5_1 = constant u64 0 (const) */
        /* execute.simd:6239 [F] s_b_5_2: WriteRegBank 2:s_b_5_0 = s_b_5_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6240 [F] s_b_5_3 = constant u64 0 (const) */
        /* execute.simd:6240 [F] s_b_5_4: WriteRegBank 3:s_b_5_0 = s_b_5_3 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
        /* execute.simd:2173 [F] s_b_6_0=sym_10584_3_parameter_inst.rd (const) */
        /* execute.simd:2173 [F] s_b_6_1 = constant u64 ffffffffffffffff (const) */
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
        /* execute.simd:2175 [F] s_b_7_0=sym_10584_3_parameter_inst.rd (const) */
        /* execute.simd:2175 [F] s_b_7_1 = constant u64 0 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fcvtzs_simd(const aarch64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4553 [F] s_b_0_0=sym_11370_3_parameter_inst.U (const) */
    /* execute.simd:4553 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4553 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4553 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)0ULL));
    /* execute.simd:4553 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4554 [F] s_b_1_0=sym_11370_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4554 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4554 [F] s_b_1_2 = constant u32 1 (const) */
    /* execute.simd:4554 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:4554 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4599 [F] s_b_3_0=sym_11370_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4599 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4599 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:4599 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.SCALAR) == (uint32_t)1ULL));
    /* execute.simd:4599 [F] s_b_3_4: If s_b_3_3: Jump b_15 else b_16 (const) */
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
    /* execute.simd:4555 [F] s_b_4_0=sym_11370_3_parameter_inst.size (const) */
    /* execute.simd:4555 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:4555 [F] s_b_4_2 = constant u32 2 (const) */
    /* execute.simd:4555 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4555 [F] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 (const) */
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
    /* execute.simd:4563 [F] s_b_5_0=sym_11370_3_parameter_inst.Q (const) */
    /* execute.simd:4563 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:4563 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.simd:4563 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:4563 [F] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4557 [F] s_b_6_0=sym_11370_3_parameter_inst.rd (const) */
    /* execute.simd:4557 [F] s_b_6_1=sym_11370_3_parameter_inst.rn (const) */
    /* execute.simd:6200 [D] s_b_6_2 = ReadRegBank 9:s_b_6_1 (f32) */
    auto s_b_6_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_2,emitter.const_u8(4));
    }
    /* execute.simd:4557 [F] s_b_6_3 = constant u8 3 (const) */
    /* execute.simd:4557 [D] s_b_6_4 = __builtin_fcvt_f32_s32 */
    auto s_b_6_4 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_6_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4557 [D] s_b_6_5 = (u32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().u32());
    /* execute.simd:6239 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.zx(s_b_6_5, emitter.context().types().u64());
    /* execute.simd:6239 [D] s_b_6_7: WriteRegBank 2:s_b_6_0 = s_b_6_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_6);
    /* execute.simd:6240 [F] s_b_6_8 = constant u64 0 (const) */
    /* execute.simd:6240 [F] s_b_6_9: WriteRegBank 3:s_b_6_0 = s_b_6_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_10: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4560 [F] s_b_7_0=sym_11370_3_parameter_inst.rd (const) */
    /* execute.simd:4560 [F] s_b_7_1=sym_11370_3_parameter_inst.rn (const) */
    /* execute.simd:6205 [D] s_b_7_2 = ReadRegBank 11:s_b_7_1 (f64) */
    auto s_b_7_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_2,emitter.const_u8(8));
    }
    /* execute.simd:4560 [F] s_b_7_3 = constant u8 3 (const) */
    /* execute.simd:4560 [D] s_b_7_4 = __builtin_fcvt_f64_s64 */
    auto s_b_7_4 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_7_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4560 [D] s_b_7_5 = (u64)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().u64());
    /* execute.simd:6246 [D] s_b_7_6: WriteRegBank 2:s_b_7_0 = s_b_7_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_5);
    /* execute.simd:6247 [F] s_b_7_7 = constant u64 0 (const) */
    /* execute.simd:6247 [F] s_b_7_8: WriteRegBank 3:s_b_7_0 = s_b_7_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_7_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4564 [F] s_b_8_0=sym_11370_3_parameter_inst.size (const) */
    /* execute.simd:4564 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.simd:4564 [F] s_b_8_2 = constant u32 2 (const) */
    /* execute.simd:4564 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4564 [F] s_b_8_4: If s_b_8_3: Jump b_10 else b_2 (const) */
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
    /* execute.simd:4574 [F] s_b_9_0=sym_11370_3_parameter_inst.Q (const) */
    /* execute.simd:4574 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4574 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4574 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* execute.simd:4574 [F] s_b_9_4: If s_b_9_3: Jump b_11 else b_2 (const) */
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
    /* execute.simd:4566 [F] s_b_10_0=sym_11370_3_parameter_inst.rn (const) */
    /* execute.simd:4566 [D] s_b_10_1 = ReadRegBank 12:s_b_10_0 (v2f32) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_10_2 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:4569 [F] s_b_10_3 = constant s32 0 (const) */
    /* execute.simd:4569 [D] s_b_10_1[s_b_10_3] */
    auto s_b_10_4 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4569 [F] s_b_10_5 = constant u8 3 (const) */
    /* execute.simd:4569 [D] s_b_10_6 = __builtin_fcvt_f32_s32 */
    auto s_b_10_6 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_10_4, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4569 [F] s_b_10_7 = constant s32 0 (const) */
    /* execute.simd:4569 [D] s_b_10_8 = s_b_10_2[s_b_10_7] <= s_b_10_6 */
    auto s_b_10_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()), emitter.const_s32((int32_t)0ULL), s_b_10_6);
    /* execute.simd:4570 [F] s_b_10_9 = constant s32 1 (const) */
    /* execute.simd:4570 [D] s_b_10_1[s_b_10_9] */
    auto s_b_10_10 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4570 [F] s_b_10_11 = constant u8 3 (const) */
    /* execute.simd:4570 [D] s_b_10_12 = __builtin_fcvt_f32_s32 */
    auto s_b_10_12 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_10_10, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4570 [F] s_b_10_13 = constant s32 1 (const) */
    /* execute.simd:4570 [D] s_b_10_14 = s_b_10_8[s_b_10_13] <= s_b_10_12 */
    auto s_b_10_14 = emitter.vector_insert(s_b_10_8, emitter.const_s32((int32_t)1ULL), s_b_10_12);
    /* execute.simd:4572 [F] s_b_10_15=sym_11370_3_parameter_inst.rd (const) */
    /* execute.simd:4572 [D] s_b_10_16 = (v2u32)s_b_10_14 */
    auto s_b_10_16 = emitter.reinterpret(s_b_10_14, emitter.context().types().v2u32());
    /* execute.simd:4572 [D] s_b_10_17: WriteRegBank 19:s_b_10_15 = s_b_10_16 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_16,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_16);
    /* execute.simd:4566 [F] s_b_10_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4575 [F] s_b_11_0=sym_11370_3_parameter_inst.size (const) */
    /* execute.simd:4575 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
    /* execute.simd:4575 [F] s_b_11_2 = constant u32 2 (const) */
    /* execute.simd:4575 [F] s_b_11_3 = s_b_11_1==s_b_11_2 (const) */
    uint8_t s_b_11_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4575 [F] s_b_11_4: If s_b_11_3: Jump b_12 else b_13 (const) */
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
    /* execute.simd:4577 [F] s_b_12_0=sym_11370_3_parameter_inst.rn (const) */
    /* execute.simd:4577 [D] s_b_12_1 = ReadRegBank 13:s_b_12_0 (v4f32) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_12_2 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:4580 [F] s_b_12_3 = constant s32 0 (const) */
    /* execute.simd:4580 [D] s_b_12_1[s_b_12_3] */
    auto s_b_12_4 = emitter.vector_extract(s_b_12_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4580 [F] s_b_12_5 = constant u8 3 (const) */
    /* execute.simd:4580 [D] s_b_12_6 = __builtin_fcvt_f32_s32 */
    auto s_b_12_6 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_12_4, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4580 [F] s_b_12_7 = constant s32 0 (const) */
    /* execute.simd:4580 [D] s_b_12_8 = s_b_12_2[s_b_12_7] <= s_b_12_6 */
    auto s_b_12_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_12_6);
    /* execute.simd:4581 [F] s_b_12_9 = constant s32 1 (const) */
    /* execute.simd:4581 [D] s_b_12_1[s_b_12_9] */
    auto s_b_12_10 = emitter.vector_extract(s_b_12_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4581 [F] s_b_12_11 = constant u8 3 (const) */
    /* execute.simd:4581 [D] s_b_12_12 = __builtin_fcvt_f32_s32 */
    auto s_b_12_12 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_12_10, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4581 [F] s_b_12_13 = constant s32 1 (const) */
    /* execute.simd:4581 [D] s_b_12_14 = s_b_12_8[s_b_12_13] <= s_b_12_12 */
    auto s_b_12_14 = emitter.vector_insert(s_b_12_8, emitter.const_s32((int32_t)1ULL), s_b_12_12);
    /* execute.simd:4582 [F] s_b_12_15 = constant s32 2 (const) */
    /* execute.simd:4582 [D] s_b_12_1[s_b_12_15] */
    auto s_b_12_16 = emitter.vector_extract(s_b_12_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4582 [F] s_b_12_17 = constant u8 3 (const) */
    /* execute.simd:4582 [D] s_b_12_18 = __builtin_fcvt_f32_s32 */
    auto s_b_12_18 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_12_16, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4582 [F] s_b_12_19 = constant s32 2 (const) */
    /* execute.simd:4582 [D] s_b_12_20 = s_b_12_14[s_b_12_19] <= s_b_12_18 */
    auto s_b_12_20 = emitter.vector_insert(s_b_12_14, emitter.const_s32((int32_t)2ULL), s_b_12_18);
    /* execute.simd:4583 [F] s_b_12_21 = constant s32 3 (const) */
    /* execute.simd:4583 [D] s_b_12_1[s_b_12_21] */
    auto s_b_12_22 = emitter.vector_extract(s_b_12_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:4583 [F] s_b_12_23 = constant u8 3 (const) */
    /* execute.simd:4583 [D] s_b_12_24 = __builtin_fcvt_f32_s32 */
    auto s_b_12_24 = emitter.call(__captive___builtin_fcvt_f32_s32, s_b_12_22, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4583 [F] s_b_12_25 = constant s32 3 (const) */
    /* execute.simd:4583 [D] s_b_12_26 = s_b_12_20[s_b_12_25] <= s_b_12_24 */
    auto s_b_12_26 = emitter.vector_insert(s_b_12_20, emitter.const_s32((int32_t)3ULL), s_b_12_24);
    /* execute.simd:4585 [F] s_b_12_27=sym_11370_3_parameter_inst.rd (const) */
    /* execute.simd:4585 [D] s_b_12_28 = (v4u32)s_b_12_26 */
    auto s_b_12_28 = emitter.reinterpret(s_b_12_26, emitter.context().types().v4u32());
    /* execute.simd:4585 [D] s_b_12_29: WriteRegBank 20:s_b_12_27 = s_b_12_28 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_28,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_28);
    /* execute.simd:4577 [F] s_b_12_30: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4586 [F] s_b_13_0=sym_11370_3_parameter_inst.size (const) */
    /* execute.simd:4586 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.simd:4586 [F] s_b_13_2 = constant u32 3 (const) */
    /* execute.simd:4586 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.simd:4586 [F] s_b_13_4: If s_b_13_3: Jump b_14 else b_2 (const) */
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
    /* execute.simd:4588 [F] s_b_14_0=sym_11370_3_parameter_inst.rn (const) */
    /* execute.simd:4588 [D] s_b_14_1 = ReadRegBank 14:s_b_14_0 (v2f64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_14_2 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:4591 [F] s_b_14_3 = constant s32 0 (const) */
    /* execute.simd:4591 [D] s_b_14_1[s_b_14_3] */
    auto s_b_14_4 = emitter.vector_extract(s_b_14_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4591 [F] s_b_14_5 = constant u8 3 (const) */
    /* execute.simd:4591 [D] s_b_14_6 = __builtin_fcvt_f64_s64 */
    auto s_b_14_6 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_14_4, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4591 [F] s_b_14_7 = constant s32 0 (const) */
    /* execute.simd:4591 [D] s_b_14_8 = s_b_14_2[s_b_14_7] <= s_b_14_6 */
    auto s_b_14_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_14_6);
    /* execute.simd:4592 [F] s_b_14_9 = constant s32 1 (const) */
    /* execute.simd:4592 [D] s_b_14_1[s_b_14_9] */
    auto s_b_14_10 = emitter.vector_extract(s_b_14_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4592 [F] s_b_14_11 = constant u8 3 (const) */
    /* execute.simd:4592 [D] s_b_14_12 = __builtin_fcvt_f64_s64 */
    auto s_b_14_12 = emitter.call(__captive___builtin_fcvt_f64_s64, s_b_14_10, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:4592 [F] s_b_14_13 = constant s32 1 (const) */
    /* execute.simd:4592 [D] s_b_14_14 = s_b_14_8[s_b_14_13] <= s_b_14_12 */
    auto s_b_14_14 = emitter.vector_insert(s_b_14_8, emitter.const_s32((int32_t)1ULL), s_b_14_12);
    /* execute.simd:4594 [F] s_b_14_15=sym_11370_3_parameter_inst.rd (const) */
    /* execute.simd:4594 [D] s_b_14_16 = (v2u64)s_b_14_14 */
    auto s_b_14_16 = emitter.reinterpret(s_b_14_14, emitter.context().types().v2u64());
    /* execute.simd:4594 [D] s_b_14_17: WriteRegBank 21:s_b_14_15 = s_b_14_16 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_16,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_16);
    /* execute.simd:4588 [F] s_b_14_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_15: 
  {
    /* execute.simd:4600 [F] s_b_15_0=sym_11370_3_parameter_inst.size (const) */
    /* execute.simd:4600 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.simd:4600 [F] s_b_15_2 = constant u32 2 (const) */
    /* execute.simd:4600 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.simd:4600 [F] s_b_15_4: If s_b_15_3: Jump b_17 else b_18 (const) */
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
    /* execute.simd:4608 [D] s_b_16_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4608 [F] s_b_16_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_17: 
  {
    /* execute.simd:4602 [F] s_b_17_0=sym_11370_3_parameter_inst.rd (const) */
    /* execute.simd:4602 [F] s_b_17_1=sym_11370_3_parameter_inst.rn (const) */
    /* execute.simd:6200 [D] s_b_17_2 = ReadRegBank 9:s_b_17_1 (f32) */
    auto s_b_17_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_2,emitter.const_u8(4));
    }
    /* execute.simd:4602 [F] s_b_17_3 = constant u8 3 (const) */
    /* execute.simd:4602 [D] s_b_17_4 = __builtin_fcvt_f32_u32 */
    auto s_b_17_4 = emitter.call(__captive___builtin_fcvt_f32_u32, s_b_17_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:6239 [D] s_b_17_5 = (u64)s_b_17_4 */
    auto s_b_17_5 = emitter.zx(s_b_17_4, emitter.context().types().u64());
    /* execute.simd:6239 [D] s_b_17_6: WriteRegBank 2:s_b_17_0 = s_b_17_5 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_17_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_17_5);
    /* execute.simd:6240 [F] s_b_17_7 = constant u64 0 (const) */
    /* execute.simd:6240 [F] s_b_17_8: WriteRegBank 3:s_b_17_0 = s_b_17_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_17_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_18: 
  {
    /* execute.simd:4605 [F] s_b_18_0=sym_11370_3_parameter_inst.rd (const) */
    /* execute.simd:4605 [F] s_b_18_1=sym_11370_3_parameter_inst.rn (const) */
    /* execute.simd:6205 [D] s_b_18_2 = ReadRegBank 11:s_b_18_1 (f64) */
    auto s_b_18_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_18_2,emitter.const_u8(8));
    }
    /* execute.simd:4605 [F] s_b_18_3 = constant u8 3 (const) */
    /* execute.simd:4605 [D] s_b_18_4 = __builtin_fcvt_f64_u64 */
    auto s_b_18_4 = emitter.call(__captive___builtin_fcvt_f64_u64, s_b_18_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:6246 [D] s_b_18_5: WriteRegBank 2:s_b_18_0 = s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_18_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_18_4);
    /* execute.simd:6247 [F] s_b_18_6 = constant u64 0 (const) */
    /* execute.simd:6247 [F] s_b_18_7: WriteRegBank 3:s_b_18_0 = s_b_18_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fmla_vector(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1415 [F] s_b_0_0=sym_11862_3_parameter_inst.Q (const) */
    /* execute.simd:1416 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:1427 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:1415 [F] s_b_0_3: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_2, b_1, b_3,  */
    switch (insn.Q) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_2;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
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
    /* execute.simd:1417 [F] s_b_2_0=sym_11862_3_parameter_inst.rn (const) */
    /* execute.simd:1417 [D] s_b_2_1 = ReadRegBank 12:s_b_2_0 (v2f32) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1418 [F] s_b_2_2=sym_11862_3_parameter_inst.rm (const) */
    /* execute.simd:1418 [D] s_b_2_3 = ReadRegBank 12:s_b_2_2 (v2f32) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* execute.simd:1419 [F] s_b_2_4=sym_11862_3_parameter_inst.rd (const) */
    /* execute.simd:1419 [D] s_b_2_5 = ReadRegBank 12:s_b_2_4 (v2f32) */
    auto s_b_2_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_5,emitter.const_u8(8));
    }
    /* execute.simd:1421 [D] s_b_2_6 = s_b_2_1*s_b_2_3 */
    auto s_b_2_6 = emitter.mul(s_b_2_1, s_b_2_3);
    /* ???:4294967295 [D] s_b_2_7 = s_b_2_5+s_b_2_6 */
    auto s_b_2_7 = emitter.add(s_b_2_5, s_b_2_6);
    /* execute.simd:1422 [F] s_b_2_8=sym_11862_3_parameter_inst.rd (const) */
    /* execute.simd:1422 [D] s_b_2_9: WriteRegBank 12:s_b_2_8 = s_b_2_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_7);
    /* execute.simd:1423 [F] s_b_2_10=sym_11862_3_parameter_inst.rd (const) */
    /* execute.simd:1423 [F] s_b_2_11 = constant u64 0 (const) */
    /* execute.simd:1423 [F] s_b_2_12: WriteRegBank 3:s_b_2_10 = s_b_2_11 */
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
    /* execute.simd:1428 [F] s_b_3_0=sym_11862_3_parameter_inst.size (const) */
    /* execute.simd:1429 [F] s_b_3_1 = constant s32 0 (const) */
    /* execute.simd:1439 [F] s_b_3_2 = constant s32 1 (const) */
    /* execute.simd:1428 [F] s_b_3_3: Switch s_b_3_0: < <todo> > def b_1 (const) -> b_1, b_5, b_4,  */
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
    /* execute.simd:1430 [F] s_b_4_0=sym_11862_3_parameter_inst.rn (const) */
    /* execute.simd:1430 [D] s_b_4_1 = ReadRegBank 13:s_b_4_0 (v4f32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:1431 [F] s_b_4_2=sym_11862_3_parameter_inst.rm (const) */
    /* execute.simd:1431 [D] s_b_4_3 = ReadRegBank 13:s_b_4_2 (v4f32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(16));
    }
    /* execute.simd:1432 [F] s_b_4_4=sym_11862_3_parameter_inst.rd (const) */
    /* execute.simd:1432 [D] s_b_4_5 = ReadRegBank 13:s_b_4_4 (v4f32) */
    auto s_b_4_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_5,emitter.const_u8(16));
    }
    /* execute.simd:1434 [D] s_b_4_6 = s_b_4_1*s_b_4_3 */
    auto s_b_4_6 = emitter.mul(s_b_4_1, s_b_4_3);
    /* ???:4294967295 [D] s_b_4_7 = s_b_4_5+s_b_4_6 */
    auto s_b_4_7 = emitter.add(s_b_4_5, s_b_4_6);
    /* execute.simd:1435 [F] s_b_4_8=sym_11862_3_parameter_inst.rd (const) */
    /* execute.simd:1435 [D] s_b_4_9: WriteRegBank 13:s_b_4_8 = s_b_4_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_7,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_7);
    /* execute.simd:0 [F] s_b_4_10: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:1440 [F] s_b_5_0=sym_11862_3_parameter_inst.rn (const) */
    /* execute.simd:1440 [D] s_b_5_1 = ReadRegBank 14:s_b_5_0 (v2f64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1441 [F] s_b_5_2=sym_11862_3_parameter_inst.rm (const) */
    /* execute.simd:1441 [D] s_b_5_3 = ReadRegBank 14:s_b_5_2 (v2f64) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1442 [F] s_b_5_4=sym_11862_3_parameter_inst.rd (const) */
    /* execute.simd:1442 [D] s_b_5_5 = ReadRegBank 14:s_b_5_4 (v2f64) */
    auto s_b_5_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_5,emitter.const_u8(16));
    }
    /* execute.simd:1444 [D] s_b_5_6 = s_b_5_1*s_b_5_3 */
    auto s_b_5_6 = emitter.mul(s_b_5_1, s_b_5_3);
    /* ???:4294967295 [D] s_b_5_7 = s_b_5_5+s_b_5_6 */
    auto s_b_5_7 = emitter.add(s_b_5_5, s_b_5_6);
    /* execute.simd:1445 [F] s_b_5_8=sym_11862_3_parameter_inst.rd (const) */
    /* execute.simd:1445 [D] s_b_5_9: WriteRegBank 14:s_b_5_8 = s_b_5_7 */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_fnm(const aarch64_decode_a64_FP_DP_3&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_12561_0_m = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_12496_0_a = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_12502_0_n = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_12507_0_m = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_12556_0_n = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_12550_0_a = emitter.alloc_local(emitter.context().types().f64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4235 [F] s_b_0_0=sym_12481_3_parameter_inst.type (const) */
    /* execute.simd:4235 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4235 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4235 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4235 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4237 [F] s_b_1_0=sym_12481_3_parameter_inst.ra (const) */
    /* execute.simd:6200 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.ra))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.ra))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4237 [D] s_b_1_2 = (f64)s_b_1_1 */
    auto s_b_1_2 = emitter.convert(s_b_1_1, emitter.context().types().f64());
    /* execute.simd:4237 [D] s_b_1_3 = -s_b_1_2 */
    auto s_b_1_3 = emitter.neg(s_b_1_2);
    /* execute.simd:4237 [D] s_b_1_4: sym_12496_0_a = s_b_1_3, dominates: s_b_4_4 s_b_5_5  */
    emitter.store_local(DV_sym_12496_0_a, s_b_1_3);
    /* execute.simd:4238 [F] s_b_1_5=sym_12481_3_parameter_inst.rn (const) */
    /* execute.simd:6200 [D] s_b_1_6 = ReadRegBank 9:s_b_1_5 (f32) */
    auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_6,emitter.const_u8(4));
    }
    /* execute.simd:4238 [D] s_b_1_7 = (f64)s_b_1_6 */
    auto s_b_1_7 = emitter.convert(s_b_1_6, emitter.context().types().f64());
    /* execute.simd:4238 [D] s_b_1_8 = -s_b_1_7 */
    auto s_b_1_8 = emitter.neg(s_b_1_7);
    /* execute.simd:4238 [D] s_b_1_9: sym_12502_0_n = s_b_1_8, dominates: s_b_4_0 s_b_5_0  */
    emitter.store_local(DV_sym_12502_0_n, s_b_1_8);
    /* execute.simd:4239 [F] s_b_1_10=sym_12481_3_parameter_inst.rm (const) */
    /* execute.simd:6200 [D] s_b_1_11 = ReadRegBank 9:s_b_1_10 (f32) */
    auto s_b_1_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_11,emitter.const_u8(4));
    }
    /* execute.simd:4239 [D] s_b_1_12 = (f64)s_b_1_11 */
    auto s_b_1_12 = emitter.convert(s_b_1_11, emitter.context().types().f64());
    /* execute.simd:4239 [D] s_b_1_13: sym_12507_0_m = s_b_1_12, dominates: s_b_4_2 s_b_5_3  */
    emitter.store_local(DV_sym_12507_0_m, s_b_1_12);
    /* execute.simd:4241 [F] s_b_1_14=sym_12481_3_parameter_inst.o0 (const) */
    /* execute.simd:4241 [F] s_b_1_15 = (u32)s_b_1_14 (const) */
    /* execute.simd:4241 [F] s_b_1_16 = constant u32 0 (const) */
    /* execute.simd:4241 [F] s_b_1_17 = s_b_1_15==s_b_1_16 (const) */
    uint8_t s_b_1_17 = ((uint8_t)(((uint32_t)insn.o0) == (uint32_t)0ULL));
    /* execute.simd:4241 [F] s_b_1_18: If s_b_1_17: Jump b_4 else b_5 (const) */
    if (s_b_1_17) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_4, b_5, b_6, b_7,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:4250 [F] s_b_3_0=sym_12481_3_parameter_inst.ra (const) */
    /* execute.simd:6205 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.ra))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.ra))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4250 [D] s_b_3_2 = (f64)s_b_3_1 */
    auto s_b_3_2 = s_b_3_1;
    /* execute.simd:4250 [D] s_b_3_3 = -s_b_3_2 */
    auto s_b_3_3 = emitter.neg(s_b_3_2);
    /* execute.simd:4250 [D] s_b_3_4: sym_12550_0_a = s_b_3_3, dominates: s_b_6_2 s_b_7_3  */
    emitter.store_local(DV_sym_12550_0_a, s_b_3_3);
    /* execute.simd:4251 [F] s_b_3_5=sym_12481_3_parameter_inst.rn (const) */
    /* execute.simd:6205 [D] s_b_3_6 = ReadRegBank 11:s_b_3_5 (f64) */
    auto s_b_3_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_6,emitter.const_u8(8));
    }
    /* execute.simd:4251 [D] s_b_3_7 = (f64)s_b_3_6 */
    auto s_b_3_7 = s_b_3_6;
    /* execute.simd:4251 [D] s_b_3_8 = -s_b_3_7 */
    auto s_b_3_8 = emitter.neg(s_b_3_7);
    /* execute.simd:4251 [D] s_b_3_9: sym_12556_0_n = s_b_3_8, dominates: s_b_6_0 s_b_7_0  */
    emitter.store_local(DV_sym_12556_0_n, s_b_3_8);
    /* execute.simd:4252 [F] s_b_3_10=sym_12481_3_parameter_inst.rm (const) */
    /* execute.simd:6205 [D] s_b_3_11 = ReadRegBank 11:s_b_3_10 (f64) */
    auto s_b_3_11 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_11,emitter.const_u8(8));
    }
    /* execute.simd:4252 [D] s_b_3_12 = (f64)s_b_3_11 */
    auto s_b_3_12 = s_b_3_11;
    /* execute.simd:4252 [D] s_b_3_13: sym_12561_0_m = s_b_3_12, dominates: s_b_6_1 s_b_7_2  */
    emitter.store_local(DV_sym_12561_0_m, s_b_3_12);
    /* execute.simd:4254 [F] s_b_3_14=sym_12481_3_parameter_inst.o0 (const) */
    /* execute.simd:4254 [F] s_b_3_15 = (u32)s_b_3_14 (const) */
    /* execute.simd:4254 [F] s_b_3_16 = constant u32 0 (const) */
    /* execute.simd:4254 [F] s_b_3_17 = s_b_3_15==s_b_3_16 (const) */
    uint8_t s_b_3_17 = ((uint8_t)(((uint32_t)insn.o0) == (uint32_t)0ULL));
    /* execute.simd:4254 [F] s_b_3_18: If s_b_3_17: Jump b_6 else b_7 (const) */
    if (s_b_3_17) 
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
    /* execute.simd:4242 [D] s_b_4_0 = sym_12502_0_n double */
    auto s_b_4_0 = emitter.load_local(DV_sym_12502_0_n, emitter.context().types().f64());
    /* execute.simd:4242 [D] s_b_4_1 = (f32)s_b_4_0 */
    auto s_b_4_1 = emitter.convert(s_b_4_0, emitter.context().types().f32());
    /* execute.simd:4242 [D] s_b_4_2 = sym_12507_0_m double */
    auto s_b_4_2 = emitter.load_local(DV_sym_12507_0_m, emitter.context().types().f64());
    /* execute.simd:4242 [D] s_b_4_3 = (f32)s_b_4_2 */
    auto s_b_4_3 = emitter.convert(s_b_4_2, emitter.context().types().f32());
    /* execute.simd:4242 [D] s_b_4_4 = sym_12496_0_a double */
    auto s_b_4_4 = emitter.load_local(DV_sym_12496_0_a, emitter.context().types().f64());
    /* execute.simd:4242 [D] s_b_4_5 = (f32)s_b_4_4 */
    auto s_b_4_5 = emitter.convert(s_b_4_4, emitter.context().types().f32());
    /* execute.simd:4242 [D] s_b_4_6 = __builtin_fma32 */
    auto s_b_4_6 = emitter.call(__captive___builtin_fma32, s_b_4_1, s_b_4_3, s_b_4_5);
    /* execute.simd:4243 [F] s_b_4_7=sym_12481_3_parameter_inst.rd (const) */
    /* execute.simd:6210 [D] s_b_4_8: WriteRegBank 9:s_b_4_7 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_6);
    /* execute.simd:6211 [F] s_b_4_9 = constant u32 0 (const) */
    /* execute.simd:6211 [F] s_b_4_10: WriteRegBank 10:s_b_4_7 = s_b_4_9 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6212 [F] s_b_4_11 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_4_12: WriteRegBank 3:s_b_4_7 = s_b_4_11 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_4_13: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4245 [D] s_b_5_0 = sym_12502_0_n double */
    auto s_b_5_0 = emitter.load_local(DV_sym_12502_0_n, emitter.context().types().f64());
    /* execute.simd:4245 [D] s_b_5_1 = -s_b_5_0 */
    auto s_b_5_1 = emitter.neg(s_b_5_0);
    /* execute.simd:4245 [D] s_b_5_2 = (f32)s_b_5_1 */
    auto s_b_5_2 = emitter.convert(s_b_5_1, emitter.context().types().f32());
    /* execute.simd:4245 [D] s_b_5_3 = sym_12507_0_m double */
    auto s_b_5_3 = emitter.load_local(DV_sym_12507_0_m, emitter.context().types().f64());
    /* execute.simd:4245 [D] s_b_5_4 = (f32)s_b_5_3 */
    auto s_b_5_4 = emitter.convert(s_b_5_3, emitter.context().types().f32());
    /* execute.simd:4245 [D] s_b_5_5 = sym_12496_0_a double */
    auto s_b_5_5 = emitter.load_local(DV_sym_12496_0_a, emitter.context().types().f64());
    /* execute.simd:4245 [D] s_b_5_6 = (f32)s_b_5_5 */
    auto s_b_5_6 = emitter.convert(s_b_5_5, emitter.context().types().f32());
    /* execute.simd:4245 [D] s_b_5_7 = __builtin_fma32 */
    auto s_b_5_7 = emitter.call(__captive___builtin_fma32, s_b_5_2, s_b_5_4, s_b_5_6);
    /* execute.simd:4246 [F] s_b_5_8=sym_12481_3_parameter_inst.rd (const) */
    /* execute.simd:6210 [D] s_b_5_9: WriteRegBank 9:s_b_5_8 = s_b_5_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_7,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_7);
    /* execute.simd:6211 [F] s_b_5_10 = constant u32 0 (const) */
    /* execute.simd:6211 [F] s_b_5_11: WriteRegBank 10:s_b_5_8 = s_b_5_10 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6212 [F] s_b_5_12 = constant u64 0 (const) */
    /* execute.simd:6212 [F] s_b_5_13: WriteRegBank 3:s_b_5_8 = s_b_5_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_5_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4255 [D] s_b_6_0 = sym_12556_0_n double */
    auto s_b_6_0 = emitter.load_local(DV_sym_12556_0_n, emitter.context().types().f64());
    /* execute.simd:4255 [D] s_b_6_1 = sym_12561_0_m double */
    auto s_b_6_1 = emitter.load_local(DV_sym_12561_0_m, emitter.context().types().f64());
    /* execute.simd:4255 [D] s_b_6_2 = sym_12550_0_a double */
    auto s_b_6_2 = emitter.load_local(DV_sym_12550_0_a, emitter.context().types().f64());
    /* execute.simd:4255 [D] s_b_6_3 = __builtin_fma64 */
    auto s_b_6_3 = emitter.call(__captive___builtin_fma64, s_b_6_0, s_b_6_1, s_b_6_2);
    /* execute.simd:4256 [F] s_b_6_4=sym_12481_3_parameter_inst.rd (const) */
    /* execute.simd:6218 [D] s_b_6_5: WriteRegBank 11:s_b_6_4 = s_b_6_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_3);
    /* execute.simd:6219 [F] s_b_6_6 = constant u64 0 (const) */
    /* execute.simd:6219 [F] s_b_6_7: WriteRegBank 3:s_b_6_4 = s_b_6_6 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_6_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4258 [D] s_b_7_0 = sym_12556_0_n double */
    auto s_b_7_0 = emitter.load_local(DV_sym_12556_0_n, emitter.context().types().f64());
    /* execute.simd:4258 [D] s_b_7_1 = -s_b_7_0 */
    auto s_b_7_1 = emitter.neg(s_b_7_0);
    /* execute.simd:4258 [D] s_b_7_2 = sym_12561_0_m double */
    auto s_b_7_2 = emitter.load_local(DV_sym_12561_0_m, emitter.context().types().f64());
    /* execute.simd:4258 [D] s_b_7_3 = sym_12550_0_a double */
    auto s_b_7_3 = emitter.load_local(DV_sym_12550_0_a, emitter.context().types().f64());
    /* execute.simd:4258 [D] s_b_7_4 = __builtin_fma64 */
    auto s_b_7_4 = emitter.call(__captive___builtin_fma64, s_b_7_1, s_b_7_2, s_b_7_3);
    /* execute.simd:4259 [F] s_b_7_5=sym_12481_3_parameter_inst.rd (const) */
    /* execute.simd:6218 [D] s_b_7_6: WriteRegBank 11:s_b_7_5 = s_b_7_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_4);
    /* execute.simd:6219 [F] s_b_7_7 = constant u64 0 (const) */
    /* execute.simd:6219 [F] s_b_7_8: WriteRegBank 3:s_b_7_5 = s_b_7_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:0 [F] s_b_7_9: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ins_gen(const aarch64_decode_a64_SIMD_COPY&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:519 [F] s_b_0_0=sym_12975_3_parameter_inst.imm5 (const) */
    /* execute.simd:519 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:519 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.simd:519 [F] s_b_0_3 = s_b_0_1&s_b_0_2 (const) */
    uint32_t s_b_0_3 = ((uint32_t)(((uint32_t)insn.imm5) & (uint32_t)1ULL));
    /* execute.simd:519 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.simd:519 [F] s_b_0_5 = s_b_0_3==s_b_0_4 (const) */
    uint8_t s_b_0_5 = ((uint8_t)(s_b_0_3 == (uint32_t)1ULL));
    /* execute.simd:519 [F] s_b_0_6: If s_b_0_5: Jump b_1 else b_3 (const) */
    if (s_b_0_5) 
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
    /* execute.simd:521 [F] s_b_1_0=sym_12975_3_parameter_inst.rd (const) */
    /* execute.simd:521 [D] s_b_1_1 = ReadRegBank 16:s_b_1_0 (v16u8) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_1,emitter.const_u8(16));
    }
    /* execute.simd:522 [F] s_b_1_2=sym_12975_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_1_3 = (u32)s_b_1_2 (const) */
    /* execute.a64:2646 [F] s_b_1_4 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
    uint8_t s_b_1_5 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_1_6 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_1_7 = ReadRegBank 1:s_b_1_2 (u32) */
    auto s_b_1_7 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_7,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_1_8: Select s_b_1_5 ? s_b_1_6 : s_b_1_7 */
    dbt::el::Value *s_b_1_8;
    s_b_1_8 = (s_b_1_5) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_1_7);
    /* execute.simd:522 [F] s_b_1_9=sym_12975_3_parameter_inst.imm5 (const) */
    /* execute.simd:522 [F] s_b_1_10 = (u32)s_b_1_9 (const) */
    /* execute.simd:522 [F] s_b_1_11 = constant u32 1 (const) */
    /* execute.simd:522 [F] s_b_1_12 = s_b_1_10>>s_b_1_11 (const) */
    uint32_t s_b_1_12 = ((uint32_t)(((uint32_t)insn.imm5) >> (uint32_t)1ULL));
    /* execute.simd:522 [F] s_b_1_13 = (u64)s_b_1_12 (const) */
    /* execute.simd:522 [F] s_b_1_14 = constant u64 f (const) */
    /* execute.simd:522 [F] s_b_1_15 = s_b_1_13&s_b_1_14 (const) */
    uint64_t s_b_1_15 = ((uint64_t)(((uint64_t)s_b_1_12) & (uint64_t)15ULL));
    /* execute.simd:522 [D] s_b_1_16 = (u8)s_b_1_8 */
    auto s_b_1_16 = emitter.truncate(s_b_1_8, emitter.context().types().u8());
    /* execute.simd:522 [F] s_b_1_17 = (s32)s_b_1_15 (const) */
    /* execute.simd:522 [D] s_b_1_18 = s_b_1_1[s_b_1_17] <= s_b_1_16 */
    auto s_b_1_18 = emitter.vector_insert(s_b_1_1, emitter.const_s32(((int32_t)s_b_1_15)), s_b_1_16);
    /* execute.simd:523 [F] s_b_1_19=sym_12975_3_parameter_inst.rd (const) */
    /* execute.simd:523 [D] s_b_1_20: WriteRegBank 16:s_b_1_19 = s_b_1_18 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_18,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_18);
    /* execute.simd:521 [F] s_b_1_21: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_8, b_9,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:524 [F] s_b_3_0=sym_12975_3_parameter_inst.imm5 (const) */
    /* execute.simd:524 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:524 [F] s_b_3_2 = constant u32 3 (const) */
    /* execute.simd:524 [F] s_b_3_3 = s_b_3_1&s_b_3_2 (const) */
    uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.imm5) & (uint32_t)3ULL));
    /* execute.simd:524 [F] s_b_3_4 = constant u32 2 (const) */
    /* execute.simd:524 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
    uint8_t s_b_3_5 = ((uint8_t)(s_b_3_3 == (uint32_t)2ULL));
    /* execute.simd:524 [F] s_b_3_6: If s_b_3_5: Jump b_4 else b_5 (const) */
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
    /* execute.simd:526 [F] s_b_4_0=sym_12975_3_parameter_inst.rd (const) */
    /* execute.simd:526 [D] s_b_4_1 = ReadRegBank 18:s_b_4_0 (v8u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:527 [F] s_b_4_2=sym_12975_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_4_3 = (u32)s_b_4_2 (const) */
    /* execute.a64:2646 [F] s_b_4_4 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_4_5 = s_b_4_3==s_b_4_4 (const) */
    uint8_t s_b_4_5 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_4_6 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_4_7 = ReadRegBank 1:s_b_4_2 (u32) */
    auto s_b_4_7 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_7,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_4_8: Select s_b_4_5 ? s_b_4_6 : s_b_4_7 */
    dbt::el::Value *s_b_4_8;
    s_b_4_8 = (s_b_4_5) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_7);
    /* execute.simd:527 [F] s_b_4_9=sym_12975_3_parameter_inst.imm5 (const) */
    /* execute.simd:527 [F] s_b_4_10 = (u32)s_b_4_9 (const) */
    /* execute.simd:527 [F] s_b_4_11 = constant u32 2 (const) */
    /* execute.simd:527 [F] s_b_4_12 = s_b_4_10>>s_b_4_11 (const) */
    uint32_t s_b_4_12 = ((uint32_t)(((uint32_t)insn.imm5) >> (uint32_t)2ULL));
    /* execute.simd:527 [F] s_b_4_13 = (u64)s_b_4_12 (const) */
    /* execute.simd:527 [F] s_b_4_14 = constant u64 7 (const) */
    /* execute.simd:527 [F] s_b_4_15 = s_b_4_13&s_b_4_14 (const) */
    uint64_t s_b_4_15 = ((uint64_t)(((uint64_t)s_b_4_12) & (uint64_t)7ULL));
    /* execute.simd:527 [D] s_b_4_16 = (u16)s_b_4_8 */
    auto s_b_4_16 = emitter.truncate(s_b_4_8, emitter.context().types().u16());
    /* execute.simd:527 [F] s_b_4_17 = (s32)s_b_4_15 (const) */
    /* execute.simd:527 [D] s_b_4_18 = s_b_4_1[s_b_4_17] <= s_b_4_16 */
    auto s_b_4_18 = emitter.vector_insert(s_b_4_1, emitter.const_s32(((int32_t)s_b_4_15)), s_b_4_16);
    /* execute.simd:528 [F] s_b_4_19=sym_12975_3_parameter_inst.rd (const) */
    /* execute.simd:528 [D] s_b_4_20: WriteRegBank 18:s_b_4_19 = s_b_4_18 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_18,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_18);
    /* execute.simd:526 [F] s_b_4_21: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.simd:529 [F] s_b_5_0=sym_12975_3_parameter_inst.imm5 (const) */
    /* execute.simd:529 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.simd:529 [F] s_b_5_2 = constant u32 7 (const) */
    /* execute.simd:529 [F] s_b_5_3 = s_b_5_1&s_b_5_2 (const) */
    uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.imm5) & (uint32_t)7ULL));
    /* execute.simd:529 [F] s_b_5_4 = constant u32 4 (const) */
    /* execute.simd:529 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(s_b_5_3 == (uint32_t)4ULL));
    /* execute.simd:529 [F] s_b_5_6: If s_b_5_5: Jump b_6 else b_7 (const) */
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
    /* execute.simd:531 [F] s_b_6_0=sym_12975_3_parameter_inst.rd (const) */
    /* execute.simd:531 [D] s_b_6_1 = ReadRegBank 20:s_b_6_0 (v4u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_1,emitter.const_u8(16));
    }
    /* execute.simd:532 [F] s_b_6_2=sym_12975_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_6_3 = (u32)s_b_6_2 (const) */
    /* execute.a64:2646 [F] s_b_6_4 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_6_6 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_6_7 = ReadRegBank 1:s_b_6_2 (u32) */
    auto s_b_6_7 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_7,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_6_8: Select s_b_6_5 ? s_b_6_6 : s_b_6_7 */
    dbt::el::Value *s_b_6_8;
    s_b_6_8 = (s_b_6_5) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_6_7);
    /* execute.simd:532 [F] s_b_6_9=sym_12975_3_parameter_inst.imm5 (const) */
    /* execute.simd:532 [F] s_b_6_10 = (u32)s_b_6_9 (const) */
    /* execute.simd:532 [F] s_b_6_11 = constant u32 3 (const) */
    /* execute.simd:532 [F] s_b_6_12 = s_b_6_10>>s_b_6_11 (const) */
    uint32_t s_b_6_12 = ((uint32_t)(((uint32_t)insn.imm5) >> (uint32_t)3ULL));
    /* execute.simd:532 [F] s_b_6_13 = (u64)s_b_6_12 (const) */
    /* execute.simd:532 [F] s_b_6_14 = constant u64 3 (const) */
    /* execute.simd:532 [F] s_b_6_15 = s_b_6_13&s_b_6_14 (const) */
    uint64_t s_b_6_15 = ((uint64_t)(((uint64_t)s_b_6_12) & (uint64_t)3ULL));
    /* execute.simd:532 [F] s_b_6_16 = (s32)s_b_6_15 (const) */
    /* execute.simd:532 [D] s_b_6_17 = s_b_6_1[s_b_6_16] <= s_b_6_8 */
    auto s_b_6_17 = emitter.vector_insert(s_b_6_1, emitter.const_s32(((int32_t)s_b_6_15)), s_b_6_8);
    /* execute.simd:533 [F] s_b_6_18=sym_12975_3_parameter_inst.rd (const) */
    /* execute.simd:533 [D] s_b_6_19: WriteRegBank 20:s_b_6_18 = s_b_6_17 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_17,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_17);
    /* execute.simd:531 [F] s_b_6_20: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.simd:534 [F] s_b_7_0=sym_12975_3_parameter_inst.imm5 (const) */
    /* execute.simd:534 [F] s_b_7_1 = (u64)s_b_7_0 (const) */
    /* execute.simd:534 [F] s_b_7_2 = constant u64 f (const) */
    /* execute.simd:534 [F] s_b_7_3 = s_b_7_1&s_b_7_2 (const) */
    uint64_t s_b_7_3 = ((uint64_t)(((uint64_t)insn.imm5) & (uint64_t)15ULL));
    /* execute.simd:534 [F] s_b_7_4 = constant u64 8 (const) */
    /* execute.simd:534 [F] s_b_7_5 = s_b_7_3==s_b_7_4 (const) */
    uint8_t s_b_7_5 = ((uint8_t)(s_b_7_3 == (uint64_t)8ULL));
    /* execute.simd:534 [F] s_b_7_6: If s_b_7_5: Jump b_8 else b_9 (const) */
    if (s_b_7_5) 
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
    /* execute.simd:536 [F] s_b_8_0=sym_12975_3_parameter_inst.rd (const) */
    /* execute.simd:536 [D] s_b_8_1 = ReadRegBank 21:s_b_8_0 (v2u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_1,emitter.const_u8(16));
    }
    /* execute.simd:537 [F] s_b_8_2=sym_12975_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.a64:2651 [F] s_b_8_4 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_8_6 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_8_7 = ReadRegBank 0:s_b_8_2 (u64) */
    auto s_b_8_7 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_7,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_8_8: Select s_b_8_5 ? s_b_8_6 : s_b_8_7 */
    dbt::el::Value *s_b_8_8;
    s_b_8_8 = (s_b_8_5) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_8_7);
    /* execute.simd:537 [F] s_b_8_9=sym_12975_3_parameter_inst.imm5 (const) */
    /* execute.simd:537 [F] s_b_8_10 = (u32)s_b_8_9 (const) */
    /* execute.simd:537 [F] s_b_8_11 = constant u32 4 (const) */
    /* execute.simd:537 [F] s_b_8_12 = s_b_8_10>>s_b_8_11 (const) */
    uint32_t s_b_8_12 = ((uint32_t)(((uint32_t)insn.imm5) >> (uint32_t)4ULL));
    /* execute.simd:537 [F] s_b_8_13 = (u64)s_b_8_12 (const) */
    /* execute.simd:537 [F] s_b_8_14 = constant u64 1 (const) */
    /* execute.simd:537 [F] s_b_8_15 = s_b_8_13&s_b_8_14 (const) */
    uint64_t s_b_8_15 = ((uint64_t)(((uint64_t)s_b_8_12) & (uint64_t)1ULL));
    /* execute.simd:537 [F] s_b_8_16 = (s32)s_b_8_15 (const) */
    /* execute.simd:537 [D] s_b_8_17 = s_b_8_1[s_b_8_16] <= s_b_8_8 */
    auto s_b_8_17 = emitter.vector_insert(s_b_8_1, emitter.const_s32(((int32_t)s_b_8_15)), s_b_8_8);
    /* execute.simd:538 [F] s_b_8_18=sym_12975_3_parameter_inst.rd (const) */
    /* execute.simd:538 [D] s_b_8_19: WriteRegBank 21:s_b_8_18 = s_b_8_17 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_17,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_17);
    /* execute.simd:536 [F] s_b_8_20: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:3075 [D] s_b_9_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:0 [F] s_b_9_1: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ld3pi(const aarch64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_66303_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66358_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_66392_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint8_t CV_sym_66307_3_parameter_rt;
  auto DV_sym_66724_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66502_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66558_1__R_s_b_12_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66647_1__R_s_b_31_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66375_0_mem_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_66305_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_66270_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66409_0_mem_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66341_0_mem_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_66324_0_mem_value = emitter.alloc_local(emitter.context().types().u8(), false);
  uint8_t CV_sym_66313_3_parameter_lane;
  uint8_t CV_sym_66434_1_tmp_s_b_5_2;
  auto DV_sym_66437_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66483_1__R_s_b_7_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_13835_0_rt;
  uint8_t CV_sym_13823_0_lane;
  auto DV_sym_13789_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_13783_3_parameter_inst.rn (const) */
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
    /* execute.simd:2571 [F] s_b_1_0 = sym_13823_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_13823_0_lane;
    /* execute.simd:2571 [F] s_b_1_1=sym_13783_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2571 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
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
    /* execute.simd:2572 [F] s_b_2_1: sym_13835_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13835_0_rt = (uint8_t)0ULL;
    /* execute.simd:2572 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2578 [F] s_b_3_0=sym_13783_3_parameter_inst.rm (const) */
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
  /* b_2, b_19,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2572 [F] s_b_4_0 = sym_13835_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_13835_0_rt;
    /* execute.simd:2572 [F] s_b_4_1=sym_13783_3_parameter_inst.regcnt (const) */
    /* execute.simd:2572 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
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
    /* execute.simd:2573 [F] s_b_5_0=sym_13783_3_parameter_inst.arrangement (const) */
    /* execute.simd:2573 [F] s_b_5_1=sym_13783_3_parameter_inst.rt (const) */
    /* execute.simd:2573 [F] s_b_5_2 = sym_13835_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_13835_0_rt;
    /* execute.simd:2573 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2573 [F] s_b_5_4 = sym_13823_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_13823_0_lane;
    /* execute.simd:2573 [D] s_b_5_5 = sym_13789_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_13789_0_address, emitter.context().types().u64());
    /* execute.simd:2573 [F] s_b_5_6: sym_66307_3_parameter_rt = s_b_5_3 (const), dominates: s_b_13_2 s_b_18_2 s_b_17_2 s_b_16_2 s_b_15_2 s_b_14_2 s_b_12_2  */
    CV_sym_66307_3_parameter_rt = s_b_5_3;
    /* execute.simd:2573 [F] s_b_5_7: sym_66313_3_parameter_lane = s_b_5_4 (const), dominates: s_b_13_5 s_b_18_5 s_b_17_5 s_b_16_5 s_b_15_5 s_b_14_5 s_b_12_5  */
    CV_sym_66313_3_parameter_lane = s_b_5_4;
    /* execute.simd:2573 [D] s_b_5_8: sym_66303_3_parameter_addr = s_b_5_5, dominates: s_b_13_0 s_b_18_0 s_b_17_0 s_b_16_0 s_b_15_0 s_b_14_0 s_b_12_0  */
    emitter.store_local(DV_sym_66303_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_66434_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_19_1  */
    CV_sym_66434_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_66437_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_66437_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3808 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3817 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3826 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3835 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3844 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3853 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3862 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3807 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_11 (const) -> b_11, b_13, b_18, b_17, b_16, b_15, b_14, b_12,  */
    switch (insn.arrangement) 
    {
    case (int32_t)0ULL:
      goto fixed_block_b_12;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_18;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_15;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_17;
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
    /* execute.simd:2571 [F] s_b_6_0 = sym_13823_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_13823_0_lane;
    /* execute.simd:2571 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2571 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2571 [F] s_b_6_3: sym_13823_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13823_0_lane = s_b_6_2;
    /* execute.simd:2571 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2730 [F] s_b_7_0=sym_13783_3_parameter_inst.rn (const) */
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
    /* execute.simd:2582 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2582 [D] s_b_8_1 = sym_13789_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_13789_0_address, emitter.context().types().u64());
    /* execute.simd:2582 [D] s_b_8_2: sym_66502_3_parameter_value = s_b_8_1, dominates: s_b_22_0 s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_66502_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2733 [F] s_b_9_0=sym_13783_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_9_2: sym_66270_1__R_s_b_0_5 = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_66270_1__R_s_b_0_5, s_b_9_1);
    /* execute.a64:2733 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_31,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2565 [D] s_b_10_0 = sym_66270_1__R_s_b_0_5 uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_66270_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2565 [D] s_b_10_1: sym_13789_0_address = s_b_10_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13789_0_address, s_b_10_0);
    /* execute.simd:2567 [F] s_b_10_2=sym_13783_3_parameter_inst.rt (const) */
    /* execute.simd:2567 [F] s_b_10_3 = constant u64 0 (const) */
    /* execute.simd:2567 [F] s_b_10_4 = constant u64 0 (const) */
    /* execute.simd:6253 [F] s_b_10_5: WriteRegBank 2:s_b_10_2 = s_b_10_3 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6254 [F] s_b_10_6: WriteRegBank 3:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2568 [F] s_b_10_7=sym_13783_3_parameter_inst.rt (const) */
    /* execute.simd:2568 [F] s_b_10_8 = (u32)s_b_10_7 (const) */
    /* execute.simd:2568 [F] s_b_10_9 = constant u32 1 (const) */
    /* execute.simd:2568 [F] s_b_10_10 = s_b_10_8+s_b_10_9 (const) */
    uint32_t s_b_10_10 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)1ULL));
    /* execute.simd:2568 [F] s_b_10_11 = (u8)s_b_10_10 (const) */
    /* execute.simd:2568 [F] s_b_10_12 = constant u64 0 (const) */
    /* execute.simd:2568 [F] s_b_10_13 = constant u64 0 (const) */
    /* execute.simd:6253 [F] s_b_10_14: WriteRegBank 2:s_b_10_11 = s_b_10_12 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6254 [F] s_b_10_15: WriteRegBank 3:s_b_10_11 = s_b_10_13 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_10)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2569 [F] s_b_10_16=sym_13783_3_parameter_inst.rt (const) */
    /* execute.simd:2569 [F] s_b_10_17 = (u32)s_b_10_16 (const) */
    /* execute.simd:2569 [F] s_b_10_18 = constant u32 2 (const) */
    /* execute.simd:2569 [F] s_b_10_19 = s_b_10_17+s_b_10_18 (const) */
    uint32_t s_b_10_19 = ((uint32_t)(((uint32_t)insn.rt) + (uint32_t)2ULL));
    /* execute.simd:2569 [F] s_b_10_20 = (u8)s_b_10_19 (const) */
    /* execute.simd:2569 [F] s_b_10_21 = constant u64 0 (const) */
    /* execute.simd:2569 [F] s_b_10_22 = constant u64 0 (const) */
    /* execute.simd:6253 [F] s_b_10_23: WriteRegBank 2:s_b_10_20 = s_b_10_21 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:6254 [F] s_b_10_24: WriteRegBank 3:s_b_10_20 = s_b_10_22 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * ((uint8_t)s_b_10_19)))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2571 [F] s_b_10_25 = constant u8 0 (const) */
    /* execute.simd:2571 [F] s_b_10_26: sym_13823_0_lane = s_b_10_25 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_13823_0_lane = (uint8_t)0ULL;
    /* execute.simd:2571 [F] s_b_10_27: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_11: 
  {
    /* execute.simd:3872 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_11_1: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_5,  */
  fixed_block_b_12: 
  {
    /* execute.simd:3810 [D] s_b_12_0 = sym_66303_3_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_66303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 1 s_b_12_0 => sym_66305_0_mem_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66305_0_mem_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(1));
    }
    /* execute.simd:3812 [F] s_b_12_2 = sym_66307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_12_2 = CV_sym_66307_3_parameter_rt;
    /* execute.simd:3812 [D] s_b_12_3 = ReadRegBank 15:s_b_12_2 (v8u8) */
    auto s_b_12_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_12_2))),s_b_12_3,emitter.const_u8(8));
    }
    /* execute.simd:3813 [D] s_b_12_4 = sym_66305_0_mem_value uint8_t */
    auto s_b_12_4 = emitter.load_local(DV_sym_66305_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3813 [F] s_b_12_5 = sym_66313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_12_5 = CV_sym_66313_3_parameter_lane;
    /* execute.simd:3813 [F] s_b_12_6 = (s32)s_b_12_5 (const) */
    /* execute.simd:3813 [D] s_b_12_7 = s_b_12_3[s_b_12_6] <= s_b_12_4 */
    auto s_b_12_7 = emitter.vector_insert(s_b_12_3, emitter.const_s32(((int32_t)s_b_12_5)), s_b_12_4);
    /* execute.simd:3814 [D] s_b_12_8: WriteRegBank 15:s_b_12_2 = s_b_12_7 */
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
    /* execute.simd:3819 [D] s_b_13_0 = sym_66303_3_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_66303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 1 s_b_13_0 => sym_66324_0_mem_value */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_66324_0_mem_value, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(1));
    }
    /* execute.simd:3821 [F] s_b_13_2 = sym_66307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_13_2 = CV_sym_66307_3_parameter_rt;
    /* execute.simd:3821 [D] s_b_13_3 = ReadRegBank 16:s_b_13_2 (v16u8) */
    auto s_b_13_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_13_2))),s_b_13_3,emitter.const_u8(16));
    }
    /* execute.simd:3822 [D] s_b_13_4 = sym_66324_0_mem_value uint8_t */
    auto s_b_13_4 = emitter.load_local(DV_sym_66324_0_mem_value, emitter.context().types().u8());
    /* execute.simd:3822 [F] s_b_13_5 = sym_66313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_13_5 = CV_sym_66313_3_parameter_lane;
    /* execute.simd:3822 [F] s_b_13_6 = (s32)s_b_13_5 (const) */
    /* execute.simd:3822 [D] s_b_13_7 = s_b_13_3[s_b_13_6] <= s_b_13_4 */
    auto s_b_13_7 = emitter.vector_insert(s_b_13_3, emitter.const_s32(((int32_t)s_b_13_5)), s_b_13_4);
    /* execute.simd:3823 [D] s_b_13_8: WriteRegBank 16:s_b_13_2 = s_b_13_7 */
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
    /* execute.simd:3828 [D] s_b_14_0 = sym_66303_3_parameter_addr uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_66303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1 = Load 2 s_b_14_0 => sym_66341_0_mem_value */
    auto s_b_14_1 = emitter.load_memory(s_b_14_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_66341_0_mem_value, s_b_14_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_14_0, s_b_14_1, emitter.const_u8(2));
    }
    /* execute.simd:3830 [F] s_b_14_2 = sym_66307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_66307_3_parameter_rt;
    /* execute.simd:3830 [D] s_b_14_3 = ReadRegBank 17:s_b_14_2 (v4u16) */
    auto s_b_14_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_14_2))),s_b_14_3,emitter.const_u8(8));
    }
    /* execute.simd:3831 [D] s_b_14_4 = sym_66341_0_mem_value uint16_t */
    auto s_b_14_4 = emitter.load_local(DV_sym_66341_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3831 [F] s_b_14_5 = sym_66313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_14_5 = CV_sym_66313_3_parameter_lane;
    /* execute.simd:3831 [F] s_b_14_6 = (s32)s_b_14_5 (const) */
    /* execute.simd:3831 [D] s_b_14_7 = s_b_14_3[s_b_14_6] <= s_b_14_4 */
    auto s_b_14_7 = emitter.vector_insert(s_b_14_3, emitter.const_s32(((int32_t)s_b_14_5)), s_b_14_4);
    /* execute.simd:3832 [D] s_b_14_8: WriteRegBank 17:s_b_14_2 = s_b_14_7 */
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
    /* execute.simd:3837 [D] s_b_15_0 = sym_66303_3_parameter_addr uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_66303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1 = Load 2 s_b_15_0 => sym_66358_0_mem_value */
    auto s_b_15_1 = emitter.load_memory(s_b_15_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_66358_0_mem_value, s_b_15_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_15_0, s_b_15_1, emitter.const_u8(2));
    }
    /* execute.simd:3839 [F] s_b_15_2 = sym_66307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_15_2 = CV_sym_66307_3_parameter_rt;
    /* execute.simd:3839 [D] s_b_15_3 = ReadRegBank 18:s_b_15_2 (v8u16) */
    auto s_b_15_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_15_2))),s_b_15_3,emitter.const_u8(16));
    }
    /* execute.simd:3840 [D] s_b_15_4 = sym_66358_0_mem_value uint16_t */
    auto s_b_15_4 = emitter.load_local(DV_sym_66358_0_mem_value, emitter.context().types().u16());
    /* execute.simd:3840 [F] s_b_15_5 = sym_66313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_15_5 = CV_sym_66313_3_parameter_lane;
    /* execute.simd:3840 [F] s_b_15_6 = (s32)s_b_15_5 (const) */
    /* execute.simd:3840 [D] s_b_15_7 = s_b_15_3[s_b_15_6] <= s_b_15_4 */
    auto s_b_15_7 = emitter.vector_insert(s_b_15_3, emitter.const_s32(((int32_t)s_b_15_5)), s_b_15_4);
    /* execute.simd:3841 [D] s_b_15_8: WriteRegBank 18:s_b_15_2 = s_b_15_7 */
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
    /* execute.simd:3846 [D] s_b_16_0 = sym_66303_3_parameter_addr uint64_t */
    auto s_b_16_0 = emitter.load_local(DV_sym_66303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_16_1 = Load 4 s_b_16_0 => sym_66375_0_mem_value */
    auto s_b_16_1 = emitter.load_memory(s_b_16_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_66375_0_mem_value, s_b_16_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_16_0, s_b_16_1, emitter.const_u8(4));
    }
    /* execute.simd:3848 [F] s_b_16_2 = sym_66307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_16_2 = CV_sym_66307_3_parameter_rt;
    /* execute.simd:3848 [D] s_b_16_3 = ReadRegBank 19:s_b_16_2 (v2u32) */
    auto s_b_16_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_16_2))),s_b_16_3,emitter.const_u8(8));
    }
    /* execute.simd:3849 [D] s_b_16_4 = sym_66375_0_mem_value uint32_t */
    auto s_b_16_4 = emitter.load_local(DV_sym_66375_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3849 [F] s_b_16_5 = sym_66313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_16_5 = CV_sym_66313_3_parameter_lane;
    /* execute.simd:3849 [F] s_b_16_6 = (s32)s_b_16_5 (const) */
    /* execute.simd:3849 [D] s_b_16_7 = s_b_16_3[s_b_16_6] <= s_b_16_4 */
    auto s_b_16_7 = emitter.vector_insert(s_b_16_3, emitter.const_s32(((int32_t)s_b_16_5)), s_b_16_4);
    /* execute.simd:3850 [D] s_b_16_8: WriteRegBank 19:s_b_16_2 = s_b_16_7 */
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
    /* execute.simd:3855 [D] s_b_17_0 = sym_66303_3_parameter_addr uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_66303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = Load 4 s_b_17_0 => sym_66392_0_mem_value */
    auto s_b_17_1 = emitter.load_memory(s_b_17_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_66392_0_mem_value, s_b_17_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_17_0, s_b_17_1, emitter.const_u8(4));
    }
    /* execute.simd:3857 [F] s_b_17_2 = sym_66307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_17_2 = CV_sym_66307_3_parameter_rt;
    /* execute.simd:3857 [D] s_b_17_3 = ReadRegBank 20:s_b_17_2 (v4u32) */
    auto s_b_17_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_17_2))),s_b_17_3,emitter.const_u8(16));
    }
    /* execute.simd:3858 [D] s_b_17_4 = sym_66392_0_mem_value uint32_t */
    auto s_b_17_4 = emitter.load_local(DV_sym_66392_0_mem_value, emitter.context().types().u32());
    /* execute.simd:3858 [F] s_b_17_5 = sym_66313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_17_5 = CV_sym_66313_3_parameter_lane;
    /* execute.simd:3858 [F] s_b_17_6 = (s32)s_b_17_5 (const) */
    /* execute.simd:3858 [D] s_b_17_7 = s_b_17_3[s_b_17_6] <= s_b_17_4 */
    auto s_b_17_7 = emitter.vector_insert(s_b_17_3, emitter.const_s32(((int32_t)s_b_17_5)), s_b_17_4);
    /* execute.simd:3859 [D] s_b_17_8: WriteRegBank 20:s_b_17_2 = s_b_17_7 */
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
    /* execute.simd:3864 [D] s_b_18_0 = sym_66303_3_parameter_addr uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_66303_3_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1 = Load 8 s_b_18_0 => sym_66409_0_mem_value */
    auto s_b_18_1 = emitter.load_memory(s_b_18_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_66409_0_mem_value, s_b_18_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_18_0, s_b_18_1, emitter.const_u8(8));
    }
    /* execute.simd:3866 [F] s_b_18_2 = sym_66307_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_2 = CV_sym_66307_3_parameter_rt;
    /* execute.simd:3866 [D] s_b_18_3 = ReadRegBank 21:s_b_18_2 (v2u64) */
    auto s_b_18_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_2))),s_b_18_3,emitter.const_u8(16));
    }
    /* execute.simd:3867 [D] s_b_18_4 = sym_66409_0_mem_value uint64_t */
    auto s_b_18_4 = emitter.load_local(DV_sym_66409_0_mem_value, emitter.context().types().u64());
    /* execute.simd:3867 [F] s_b_18_5 = sym_66313_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_5 = CV_sym_66313_3_parameter_lane;
    /* execute.simd:3867 [F] s_b_18_6 = (s32)s_b_18_5 (const) */
    /* execute.simd:3867 [D] s_b_18_7 = s_b_18_3[s_b_18_6] <= s_b_18_4 */
    auto s_b_18_7 = emitter.vector_insert(s_b_18_3, emitter.const_s32(((int32_t)s_b_18_5)), s_b_18_4);
    /* execute.simd:3868 [D] s_b_18_8: WriteRegBank 21:s_b_18_2 = s_b_18_7 */
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
    /* ???:4294967295 [D] s_b_19_0 = sym_66437_1_tmp_s_b_5_5 uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_66437_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_19_1 = sym_66434_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_19_1 = CV_sym_66434_1_tmp_s_b_5_2;
    /* execute.simd:2574 [F] s_b_19_2=sym_13783_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_19_3 = (u64)s_b_19_2 (const) */
    /* ???:4294967295 [D] s_b_19_4 = s_b_19_0+s_b_19_3 */
    auto s_b_19_4 = emitter.add(s_b_19_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2574 [D] s_b_19_5: sym_13789_0_address = s_b_19_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_13789_0_address, s_b_19_4);
    /* execute.simd:2572 [F] s_b_19_6 = constant u8 1 (const) */
    /* execute.simd:2572 [F] s_b_19_7 = s_b_19_1+s_b_19_6 (const) */
    uint8_t s_b_19_7 = ((uint8_t)(s_b_19_1 + (uint8_t)1ULL));
    /* execute.simd:2572 [F] s_b_19_8: sym_13835_0_rt = s_b_19_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_13835_0_rt = s_b_19_7;
    /* execute.simd:2572 [F] s_b_19_9: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_7,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2733 [F] s_b_20_0=sym_13783_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_20_1 = ReadRegBank 0:s_b_20_0 (u64) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_20_2: sym_66483_1__R_s_b_7_5 = s_b_20_1, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_66483_1__R_s_b_7_5, s_b_20_1);
    /* execute.a64:2733 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_36,  */
  fixed_block_b_21: 
  {
    /* execute.simd:2579 [D] s_b_21_0 = sym_66483_1__R_s_b_7_5 uint64_t */
    auto s_b_21_0 = emitter.load_local(DV_sym_66483_1__R_s_b_7_5, emitter.context().types().u64());
    /* execute.simd:2579 [F] s_b_21_1=sym_13783_3_parameter_inst.rm (const) */
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
    /* execute.simd:2579 [D] s_b_21_8 = s_b_21_0+s_b_21_7 */
    auto s_b_21_8 = emitter.add(s_b_21_0, s_b_21_7);
    /* execute.simd:2579 [D] s_b_21_9: sym_13789_0_address = s_b_21_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_13789_0_address, s_b_21_8);
    /* execute.simd:2579 [F] s_b_21_10: Jump b_8 (const) */
    goto fixed_block_b_8;
  }
  /* b_8,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2747 [D] s_b_22_0 = sym_66502_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_66502_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_22_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_22_2 = s_b_22_0&s_b_22_1 */
    auto s_b_22_2 = emitter.bitwise_and(s_b_22_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_22_3: sym_66502_3_parameter_value = s_b_22_2, dominates: s_b_24_0 s_b_25_1  */
    emitter.store_local(DV_sym_66502_3_parameter_value, s_b_22_2);
    /* execute.a64:2747 [F] s_b_22_4: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_8, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2750 [F] s_b_23_0=sym_13783_3_parameter_inst.rn (const) */
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
    /* execute.a64:2751 [D] s_b_24_0 = sym_66502_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_66502_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_24_1: sym_66724_3_parameter_value = s_b_24_0, dominates: s_b_37_0 s_b_38_0 s_b_39_0  */
    emitter.store_local(DV_sym_66724_3_parameter_value, s_b_24_0);
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
    /* execute.a64:2753 [F] s_b_25_0=sym_13783_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_25_1 = sym_66502_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_66502_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2702 [D] s_b_28_1: sym_66558_1__R_s_b_12_0 = s_b_28_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_66558_1__R_s_b_12_0, s_b_28_0);
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
    /* execute.a64:2705 [D] s_b_29_1: sym_66558_1__R_s_b_12_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_66558_1__R_s_b_12_0, s_b_29_0);
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
    /* execute.a64:2707 [D] s_b_30_1: sym_66558_1__R_s_b_12_0 = s_b_30_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_66558_1__R_s_b_12_0, s_b_30_0);
    /* execute.a64:2707 [F] s_b_30_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_28, b_29, b_30,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2731 [D] s_b_31_0 = sym_66558_1__R_s_b_12_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_66558_1__R_s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_31_1: sym_66270_1__R_s_b_0_5 = s_b_31_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_66270_1__R_s_b_0_5, s_b_31_0);
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
    /* execute.a64:2702 [D] s_b_33_1: sym_66647_1__R_s_b_31_0 = s_b_33_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_66647_1__R_s_b_31_0, s_b_33_0);
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
    /* execute.a64:2705 [D] s_b_34_1: sym_66647_1__R_s_b_31_0 = s_b_34_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_66647_1__R_s_b_31_0, s_b_34_0);
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
    /* execute.a64:2707 [D] s_b_35_1: sym_66647_1__R_s_b_31_0 = s_b_35_0, dominates: s_b_36_0  */
    emitter.store_local(DV_sym_66647_1__R_s_b_31_0, s_b_35_0);
    /* execute.a64:2707 [F] s_b_35_2: Jump b_36 (const) */
    goto fixed_block_b_36;
  }
  /* b_33, b_34, b_35,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2731 [D] s_b_36_0 = sym_66647_1__R_s_b_31_0 uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_66647_1__R_s_b_31_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_36_1: sym_66483_1__R_s_b_7_5 = s_b_36_0, dominates: s_b_21_0  */
    emitter.store_local(DV_sym_66483_1__R_s_b_7_5, s_b_36_0);
    /* execute.a64:2731 [F] s_b_36_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_24,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2715 [D] s_b_37_0 = sym_66724_3_parameter_value uint64_t */
    auto s_b_37_0 = emitter.load_local(DV_sym_66724_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2718 [D] s_b_38_0 = sym_66724_3_parameter_value uint64_t */
    auto s_b_38_0 = emitter.load_local(DV_sym_66724_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2720 [D] s_b_39_0 = sym_66724_3_parameter_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_66724_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldaxrb(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_79657_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_79619_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_80324_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_79720_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_79725_0_data8 = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_14300_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_1_0=sym_14300_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_1_2: sym_79619_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_79619_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2733 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:639 [D] s_b_2_0 = sym_79619_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_79619_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:640 [D] s_b_2_1: sym_79720_3_parameter_address = s_b_2_0, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_79720_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 1 s_b_2_0 => sym_79725_0_data8 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_79725_0_data8, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(1));
    }
    /* execute.a64:1663 [D] s_b_2_3 = sym_79725_0_data8 uint8_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_79725_0_data8, emitter.context().types().u8());
    /* execute.a64:1663 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_2_5=sym_14300_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_2_6 = (u32)s_b_2_4 */
    auto s_b_2_6 = emitter.truncate(s_b_2_4, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_2_8: sym_80324_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_80324_3_parameter_value, s_b_2_7);
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
    /* execute.a64:2702 [D] s_b_4_1: sym_79657_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_79657_1__R_s_b_4_0, s_b_4_0);
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
    /* execute.a64:2705 [D] s_b_5_1: sym_79657_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_79657_1__R_s_b_4_0, s_b_5_0);
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
    /* execute.a64:2707 [D] s_b_6_1: sym_79657_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_79657_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2707 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2731 [D] s_b_7_0 = sym_79657_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_79657_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_7_1: sym_79619_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_79619_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2731 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1723 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_8_1 = sym_79720_3_parameter_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_79720_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_10_0=sym_14300_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_10_1 = sym_80324_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_80324_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldpswi(const aarch64_decode_a64_LS_REG_PAIR_IDX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14726_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14738_0_d1 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_14744_0_d2 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_89178_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89056_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89309_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89120_1__R_s_b_8_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89348_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89270_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_14720_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2730 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_0_4: If s_b_0_3: Jump b_8 else b_5 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_6,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1636 [D] s_b_1_0 = sym_14726_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14726_0_address, emitter.context().types().u64());
    /* execute.a64:1636 [F] s_b_1_1=sym_14720_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64(insn.immu64));
    /* execute.a64:1636 [D] s_b_1_3: sym_14726_0_address = s_b_1_2, dominates: s_b_2_0 s_b_3_0 s_b_14_1  */
    emitter.store_local(DV_sym_14726_0_address, s_b_1_2);
    /* execute.a64:1636 [F] s_b_1_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_6,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1642 [D] s_b_2_0 = sym_14726_0_address uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_14726_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_1 = Load 4 s_b_2_0 => sym_14738_0_d1 */
    auto s_b_2_1 = emitter.load_memory(s_b_2_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_14738_0_d1, s_b_2_1);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_1, emitter.const_u8(4));
    }
    /* execute.a64:1643 [F] s_b_2_2 = constant u64 4 (const) */
    /* execute.a64:1643 [D] s_b_2_3 = s_b_2_0+s_b_2_2 */
    auto s_b_2_3 = emitter.add(s_b_2_0, emitter.const_u64((uint64_t)4ULL));
    /* ???:4294967295 [D] s_b_2_4 = Load 4 s_b_2_3 => sym_14744_0_d2 */
    auto s_b_2_4 = emitter.load_memory(s_b_2_3, emitter.context().types().u32());
    emitter.store_local(DV_sym_14744_0_d2, s_b_2_4);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_3, s_b_2_4, emitter.const_u8(4));
    }
    /* execute.a64:1645 [F] s_b_2_5=sym_14720_3_parameter_inst.P (const) */
    /* execute.a64:1645 [F] s_b_2_6 = !s_b_2_5 (const) */
    uint8_t s_b_2_6 = !insn.P;
    /* execute.a64:1645 [F] s_b_2_7: If s_b_2_6: Jump b_3 else b_4 (const) */
    if (s_b_2_6) 
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
    /* execute.a64:1646 [D] s_b_3_0 = sym_14726_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14726_0_address, emitter.context().types().u64());
    /* execute.a64:1646 [F] s_b_3_1=sym_14720_3_parameter_inst.immu64 (const) */
    /* ???:4294967295 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.a64:1646 [D] s_b_3_3: sym_14726_0_address = s_b_3_2, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_14726_0_address, s_b_3_2);
    /* execute.a64:1646 [F] s_b_3_4: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_2, b_3,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1649 [D] s_b_4_0 = sym_14738_0_d1 uint32_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_14738_0_d1, emitter.context().types().u32());
    /* execute.a64:1649 [D] s_b_4_1 = (s32)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s32());
    /* execute.a64:1649 [D] s_b_4_2 = (s64)s_b_4_1 */
    auto s_b_4_2 = emitter.sx(s_b_4_1, emitter.context().types().s64());
    /* execute.a64:1649 [D] s_b_4_3 = (u64)s_b_4_2 */
    auto s_b_4_3 = emitter.reinterpret(s_b_4_2, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_4_4=sym_14720_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_4_5: sym_89178_3_parameter_value = s_b_4_3, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_89178_3_parameter_value, s_b_4_3);
    /* execute.a64:2682 [F] s_b_4_6 = (u32)s_b_4_4 (const) */
    /* execute.a64:2682 [F] s_b_4_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_4_8 = s_b_4_6==s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_4_9: If s_b_4_8: Jump b_7 else b_13 (const) */
    if (s_b_4_8) 
    {
      goto fixed_block_b_7;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2733 [F] s_b_5_0=sym_14720_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_5_2: sym_89056_1__R_s_b_0_5 = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_89056_1__R_s_b_0_5, s_b_5_1);
    /* execute.a64:2733 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_12,  */
  fixed_block_b_6: 
  {
    /* execute.a64:1633 [D] s_b_6_0 = sym_89056_1__R_s_b_0_5 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_89056_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1633 [D] s_b_6_1: sym_14726_0_address = s_b_6_0, dominates: s_b_1_0 s_b_2_0 s_b_3_0 s_b_14_1  */
    emitter.store_local(DV_sym_14726_0_address, s_b_6_0);
    /* execute.a64:1635 [F] s_b_6_2=sym_14720_3_parameter_inst.P (const) */
    /* execute.a64:1635 [F] s_b_6_3: If s_b_6_2: Jump b_1 else b_2 (const) */
    if (insn.P) 
    {
      goto fixed_block_b_1;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_4, b_13,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1650 [D] s_b_7_0 = sym_14744_0_d2 uint32_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_14744_0_d2, emitter.context().types().u32());
    /* execute.a64:1650 [D] s_b_7_1 = (s32)s_b_7_0 */
    auto s_b_7_1 = emitter.reinterpret(s_b_7_0, emitter.context().types().s32());
    /* execute.a64:1650 [D] s_b_7_2 = (s64)s_b_7_1 */
    auto s_b_7_2 = emitter.sx(s_b_7_1, emitter.context().types().s64());
    /* execute.a64:1650 [D] s_b_7_3 = (u64)s_b_7_2 */
    auto s_b_7_3 = emitter.reinterpret(s_b_7_2, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_7_4=sym_14720_3_parameter_inst.rt2 (const) */
    /* execute.a64:2691 [D] s_b_7_5: sym_89270_3_parameter_value = s_b_7_3, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_89270_3_parameter_value, s_b_7_3);
    /* execute.a64:2682 [F] s_b_7_6 = (u32)s_b_7_4 (const) */
    /* execute.a64:2682 [F] s_b_7_7 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_7_8 = s_b_7_6==s_b_7_7 (const) */
    uint8_t s_b_7_8 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_7_9: If s_b_7_8: Jump b_14 else b_16 (const) */
    if (s_b_7_8) 
    {
      goto fixed_block_b_14;
    }
    else 
    {
      goto fixed_block_b_16;
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
    /* execute.a64:2702 [D] s_b_9_1: sym_89120_1__R_s_b_8_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_89120_1__R_s_b_8_0, s_b_9_0);
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
    /* execute.a64:2705 [D] s_b_10_1: sym_89120_1__R_s_b_8_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_89120_1__R_s_b_8_0, s_b_10_0);
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
    /* execute.a64:2707 [D] s_b_11_1: sym_89120_1__R_s_b_8_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_89120_1__R_s_b_8_0, s_b_11_0);
    /* execute.a64:2707 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2731 [D] s_b_12_0 = sym_89120_1__R_s_b_8_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_89120_1__R_s_b_8_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_12_1: sym_89056_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_89056_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2731 [F] s_b_12_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2684 [F] s_b_13_0=sym_14720_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_13_1 = sym_89178_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_89178_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_7, b_16,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1652 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:1652 [D] s_b_14_1 = sym_14726_0_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_14726_0_address, emitter.context().types().u64());
    /* execute.a64:1652 [D] s_b_14_2: sym_89309_3_parameter_value = s_b_14_1, dominates: s_b_17_0 s_b_19_0 s_b_20_1  */
    emitter.store_local(DV_sym_89309_3_parameter_value, s_b_14_1);
    /* execute.a64:2746 [F] s_b_14_3 = !s_b_14_0 (const) */
    uint8_t s_b_14_3 = !(uint8_t)1ULL;
    /* execute.a64:2746 [F] s_b_14_4: If s_b_14_3: Jump b_17 else b_18 (const) */
    if (s_b_14_3) 
    {
      goto fixed_block_b_17;
    }
    else 
    {
      goto fixed_block_b_18;
    }
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
  /* b_7,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2684 [F] s_b_16_0=sym_14720_3_parameter_inst.rt2 (const) */
    /* execute.a64:2684 [D] s_b_16_1 = sym_89270_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_89270_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_16_1);
    /* execute.a64:0 [F] s_b_16_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_14,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2747 [D] s_b_17_0 = sym_89309_3_parameter_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_89309_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_17_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_17_2 = s_b_17_0&s_b_17_1 */
    auto s_b_17_2 = emitter.bitwise_and(s_b_17_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_17_3: sym_89309_3_parameter_value = s_b_17_2, dominates: s_b_19_0 s_b_20_1  */
    emitter.store_local(DV_sym_89309_3_parameter_value, s_b_17_2);
    /* execute.a64:2747 [F] s_b_17_4: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_14, b_17,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2750 [F] s_b_18_0=sym_14720_3_parameter_inst.rn (const) */
    /* execute.a64:2750 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
    /* execute.a64:2750 [F] s_b_18_2 = constant u32 1f (const) */
    /* execute.a64:2750 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
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
    /* execute.a64:2751 [D] s_b_19_0 = sym_89309_3_parameter_value uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_89309_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_19_1: sym_89348_3_parameter_value = s_b_19_0, dominates: s_b_22_0 s_b_23_0 s_b_24_0  */
    emitter.store_local(DV_sym_89348_3_parameter_value, s_b_19_0);
    /* execute.a64:2714 [F] s_b_19_2 = constant u32 1 (const) */
    /* execute.a64:2714 [F] s_b_19_3 = __builtin_get_feature */
    uint32_t s_b_19_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2714 [F] s_b_19_4 = constant u32 0 (const) */
    /* execute.a64:2714 [F] s_b_19_5 = s_b_19_3==s_b_19_4 (const) */
    uint8_t s_b_19_5 = ((uint8_t)(s_b_19_3 == (uint32_t)0ULL));
    /* execute.a64:2714 [F] s_b_19_6: If s_b_19_5: Jump b_22 else b_25 (const) */
    if (s_b_19_5) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_25;
    }
  }
  /* b_18,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2753 [F] s_b_20_0=sym_14720_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_20_1 = sym_89309_3_parameter_value uint64_t */
    auto s_b_20_1 = emitter.load_local(DV_sym_89309_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2753 [D] s_b_20_2: WriteRegBank 0:s_b_20_0 = s_b_20_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_20_1);
    /* execute.a64:2753 [F] s_b_20_3: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_20, b_22, b_23, b_24,  */
  fixed_block_b_21: 
  {
    /* ???:4294967295 [F] s_b_21_0: Return */
    goto fixed_done;
  }
  /* b_19,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2715 [D] s_b_22_0 = sym_89348_3_parameter_value uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_89348_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2715 [D] s_b_22_1: WriteReg 20 = s_b_22_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_22_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_22_0);
    /* execute.a64:2715 [F] s_b_22_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_25,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2718 [D] s_b_23_0 = sym_89348_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_89348_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2718 [D] s_b_23_1: WriteReg 20 = s_b_23_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_23_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_23_0);
    /* execute.a64:2718 [F] s_b_23_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_25,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2720 [D] s_b_24_0 = sym_89348_3_parameter_value uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_89348_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_24_1: WriteReg 21 = s_b_24_0 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_24_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_24_0);
    /* execute.a64:2720 [F] s_b_24_2: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_19,  */
  fixed_block_b_25: 
  {
    /* execute.a64:3012 [F] s_b_25_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_25_1 = __builtin_get_feature */
    uint32_t s_b_25_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_25_2 = (u8)s_b_25_1 (const) */
    /* execute.a64:2717 [F] s_b_25_3 = (u32)s_b_25_2 (const) */
    /* execute.a64:2717 [F] s_b_25_4 = constant u32 0 (const) */
    /* execute.a64:2717 [F] s_b_25_5 = s_b_25_3==s_b_25_4 (const) */
    uint8_t s_b_25_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_25_1)) == (uint32_t)0ULL));
    /* execute.a64:2717 [F] s_b_25_6: If s_b_25_5: Jump b_23 else b_24 (const) */
    if (s_b_25_5) 
    {
      goto fixed_block_b_23;
    }
    else 
    {
      goto fixed_block_b_24;
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldrbi(const aarch64_decode_a64_LS_REG_UIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_15716_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_102593_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102375_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102659_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102491_1__R_s_b_13_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_102571_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_15705_3_parameter_inst.rn (const) */
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
    /* execute.a64:1408 [D] s_b_1_0 = sym_15716_0_value uint8_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_15716_0_value, emitter.context().types().u8());
    /* execute.a64:1408 [D] s_b_1_1 = (u64)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_1_2=sym_15705_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_1_3 = (u32)s_b_1_1 */
    auto s_b_1_3 = emitter.truncate(s_b_1_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_1_5: sym_102571_3_parameter_value = s_b_1_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_102571_3_parameter_value, s_b_1_4);
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
    /* execute.a64:1409 [F] s_b_3_0=sym_15705_3_parameter_inst.opc (const) */
    /* execute.a64:1409 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1409 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:1409 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1409 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1410 [D] s_b_4_0 = sym_15716_0_value uint8_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_15716_0_value, emitter.context().types().u8());
    /* execute.a64:1410 [D] s_b_4_1 = (s8)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s8());
    /* execute.a64:1410 [D] s_b_4_2 = (s64)s_b_4_1 */
    auto s_b_4_2 = emitter.sx(s_b_4_1, emitter.context().types().s64());
    /* execute.a64:1410 [D] s_b_4_3 = (u64)s_b_4_2 */
    auto s_b_4_3 = emitter.reinterpret(s_b_4_2, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_4_4=sym_15705_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_4_5: sym_102593_3_parameter_value = s_b_4_3, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_102593_3_parameter_value, s_b_4_3);
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
    /* execute.a64:1411 [F] s_b_5_0=sym_15705_3_parameter_inst.opc (const) */
    /* execute.a64:1411 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1411 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:1411 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:1411 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1412 [D] s_b_6_0 = sym_15716_0_value uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_15716_0_value, emitter.context().types().u8());
    /* execute.a64:1412 [D] s_b_6_1 = (s8)s_b_6_0 */
    auto s_b_6_1 = emitter.reinterpret(s_b_6_0, emitter.context().types().s8());
    /* execute.a64:1412 [D] s_b_6_2 = (s64)s_b_6_1 */
    auto s_b_6_2 = emitter.sx(s_b_6_1, emitter.context().types().s64());
    /* execute.a64:1412 [D] s_b_6_3 = (u64)s_b_6_2 */
    auto s_b_6_3 = emitter.reinterpret(s_b_6_2, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_4=sym_15705_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_6_5 = (u32)s_b_6_3 */
    auto s_b_6_5 = emitter.truncate(s_b_6_3, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.zx(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_7: sym_102659_3_parameter_value = s_b_6_6, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_102659_3_parameter_value, s_b_6_6);
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
    /* execute.a64:1414 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1414 [F] s_b_7_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2733 [F] s_b_8_0=sym_15705_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_8_2: sym_102375_1__R_s_b_0_5 = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_102375_1__R_s_b_0_5, s_b_8_1);
    /* execute.a64:2733 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_14,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1402 [D] s_b_9_0 = sym_102375_1__R_s_b_0_5 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_102375_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1402 [F] s_b_9_1=sym_15705_3_parameter_inst.immu64 (const) */
    /* execute.a64:1402 [D] s_b_9_2 = s_b_9_0+s_b_9_1 */
    auto s_b_9_2 = emitter.add(s_b_9_0, emitter.const_u64(insn.immu64));
    /* ???:4294967295 [D] s_b_9_3 = Load 1 s_b_9_2 => sym_15716_0_value */
    auto s_b_9_3 = emitter.load_memory(s_b_9_2, emitter.context().types().u8());
    emitter.store_local(DV_sym_15716_0_value, s_b_9_3);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_2, s_b_9_3, emitter.const_u8(1));
    }
    /* execute.a64:1407 [F] s_b_9_4=sym_15705_3_parameter_inst.opc (const) */
    /* execute.a64:1407 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.a64:1407 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.a64:1407 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.a64:1407 [F] s_b_9_8: If s_b_9_7: Jump b_1 else b_3 (const) */
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
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_11_1: sym_102491_1__R_s_b_13_0 = s_b_11_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_102491_1__R_s_b_13_0, s_b_11_0);
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
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_12_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_12_1: sym_102491_1__R_s_b_13_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_102491_1__R_s_b_13_0, s_b_12_0);
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
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_13_1: sym_102491_1__R_s_b_13_0 = s_b_13_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_102491_1__R_s_b_13_0, s_b_13_0);
    /* execute.a64:2707 [F] s_b_13_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_11, b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2731 [D] s_b_14_0 = sym_102491_1__R_s_b_13_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_102491_1__R_s_b_13_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_14_1: sym_102375_1__R_s_b_0_5 = s_b_14_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_102375_1__R_s_b_0_5, s_b_14_0);
    /* execute.a64:2731 [F] s_b_14_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2684 [F] s_b_15_0=sym_15705_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_15_1 = sym_102571_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_102571_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_15_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_15_1);
    /* execute.a64:0 [F] s_b_15_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2684 [F] s_b_16_0=sym_15705_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_16_1 = sym_102593_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_102593_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1);
    /* execute.a64:0 [F] s_b_16_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2684 [F] s_b_17_0=sym_15705_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_17_1 = sym_102659_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_102659_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldtr(const aarch64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ldxp(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_111249_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112023_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_16475_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_110852_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_110955_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_111174_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_111026_1_tmp_s_b_1_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_110823_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112957_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_114237_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_111572_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112151_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_112675_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_111220_1_tmp_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_111675_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_111046_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_114171_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2730 [F] s_b_0_0=sym_16469_3_parameter_inst.rn (const) */
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
    /* execute.a64:818 [D] s_b_1_0 = sym_16475_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16475_0_address, emitter.context().types().u64());
    /* execute.a64:818 [D] s_b_1_1: sym_110852_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_110852_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2: sym_111026_1_tmp_s_b_1_0 = s_b_1_0, dominates: s_b_6_3  */
    emitter.store_local(DV_sym_111026_1_tmp_s_b_1_0, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_3 = Load 4 s_b_1_0 => sym_110955_0_data32 */
    auto s_b_1_3 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_110955_0_data32, s_b_1_3);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_3, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_1_4 = sym_110955_0_data32 uint32_t */
    auto s_b_1_4 = emitter.load_local(DV_sym_110955_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_1_5 = (u64)s_b_1_4 */
    auto s_b_1_5 = emitter.zx(s_b_1_4, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_1_6=sym_16469_3_parameter_inst.rt (const) */
    /* execute.a64:2693 [D] s_b_1_7 = (u32)s_b_1_5 */
    auto s_b_1_7 = emitter.truncate(s_b_1_5, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_1_8 = (u64)s_b_1_7 */
    auto s_b_1_8 = emitter.zx(s_b_1_7, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_1_9: sym_112675_3_parameter_value = s_b_1_8, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_112675_3_parameter_value, s_b_1_8);
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
    /* execute.a64:821 [D] s_b_3_0 = sym_16475_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_16475_0_address, emitter.context().types().u64());
    /* execute.a64:821 [D] s_b_3_1: sym_111046_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_111046_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2: sym_111220_1_tmp_s_b_3_0 = s_b_3_0, dominates: s_b_7_3  */
    emitter.store_local(DV_sym_111220_1_tmp_s_b_3_0, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_3 = Load 8 s_b_3_0 => sym_111174_0_data64 */
    auto s_b_3_3 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_111174_0_data64, s_b_3_3);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_3, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_3_4 = sym_111174_0_data64 uint64_t */
    auto s_b_3_4 = emitter.load_local(DV_sym_111174_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_3_5=sym_16469_3_parameter_inst.rt (const) */
    /* execute.a64:2691 [D] s_b_3_6: sym_112957_3_parameter_value = s_b_3_4, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_112957_3_parameter_value, s_b_3_4);
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
    /* execute.a64:2733 [F] s_b_4_0=sym_16469_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2733 [D] s_b_4_2: sym_110823_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_110823_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2733 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:815 [D] s_b_5_0 = sym_110823_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_110823_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:815 [D] s_b_5_1: sym_16475_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_16475_0_address, s_b_5_0);
    /* execute.a64:817 [F] s_b_5_2=sym_16469_3_parameter_inst.size (const) */
    /* execute.a64:817 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:817 [F] s_b_5_4 = constant u32 2 (const) */
    /* execute.a64:817 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:817 [F] s_b_5_6: If s_b_5_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1723 [D] s_b_6_1 = sym_110852_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_110852_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* ???:4294967295 [D] s_b_6_3 = sym_111026_1_tmp_s_b_1_0 uint64_t */
    auto s_b_6_3 = emitter.load_local(DV_sym_111026_1_tmp_s_b_1_0, emitter.context().types().u64());
    /* execute.a64:819 [F] s_b_6_4 = constant u64 4 (const) */
    /* execute.a64:819 [D] s_b_6_5 = s_b_6_3+s_b_6_4 */
    auto s_b_6_5 = emitter.add(s_b_6_3, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:819 [D] s_b_6_6: sym_111572_3_parameter_address = s_b_6_5, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_111572_3_parameter_address, s_b_6_5);
    /* ???:4294967295 [D] s_b_6_7 = Load 4 s_b_6_5 => sym_111675_0_data32 */
    auto s_b_6_7 = emitter.load_memory(s_b_6_5, emitter.context().types().u32());
    emitter.store_local(DV_sym_111675_0_data32, s_b_6_7);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_6_5, s_b_6_7, emitter.const_u8(4));
    }
    /* execute.a64:1693 [D] s_b_6_8 = sym_111675_0_data32 uint32_t */
    auto s_b_6_8 = emitter.load_local(DV_sym_111675_0_data32, emitter.context().types().u32());
    /* execute.a64:1693 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_10=sym_16469_3_parameter_inst.rt2 (const) */
    /* execute.a64:2693 [D] s_b_6_11 = (u32)s_b_6_9 */
    auto s_b_6_11 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_13: sym_114171_3_parameter_value = s_b_6_12, dominates: s_b_18_1  */
    emitter.store_local(DV_sym_114171_3_parameter_value, s_b_6_12);
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
    /* execute.a64:1723 [D] s_b_7_1 = sym_111046_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_111046_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_7_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_7_1);
    /* ???:4294967295 [D] s_b_7_3 = sym_111220_1_tmp_s_b_3_0 uint64_t */
    auto s_b_7_3 = emitter.load_local(DV_sym_111220_1_tmp_s_b_3_0, emitter.context().types().u64());
    /* execute.a64:822 [F] s_b_7_4 = constant u64 8 (const) */
    /* execute.a64:822 [D] s_b_7_5 = s_b_7_3+s_b_7_4 */
    auto s_b_7_5 = emitter.add(s_b_7_3, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:822 [D] s_b_7_6: sym_112023_3_parameter_address = s_b_7_5, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_112023_3_parameter_address, s_b_7_5);
    /* ???:4294967295 [D] s_b_7_7 = Load 8 s_b_7_5 => sym_112151_0_data64 */
    auto s_b_7_7 = emitter.load_memory(s_b_7_5, emitter.context().types().u64());
    emitter.store_local(DV_sym_112151_0_data64, s_b_7_7);
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_MEMORY, s_b_7_5, s_b_7_7, emitter.const_u8(8));
    }
    /* execute.a64:1701 [D] s_b_7_8 = sym_112151_0_data64 uint64_t */
    auto s_b_7_8 = emitter.load_local(DV_sym_112151_0_data64, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_7_9=sym_16469_3_parameter_inst.rt2 (const) */
    /* execute.a64:2691 [D] s_b_7_10: sym_114237_3_parameter_value = s_b_7_8, dominates: s_b_19_1  */
    emitter.store_local(DV_sym_114237_3_parameter_value, s_b_7_8);
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
    /* execute.a64:2702 [D] s_b_9_1: sym_111249_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_111249_1__R_s_b_7_0, s_b_9_0);
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
    /* execute.a64:2705 [D] s_b_10_1: sym_111249_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_111249_1__R_s_b_7_0, s_b_10_0);
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
    /* execute.a64:2707 [D] s_b_11_1: sym_111249_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_111249_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2707 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2731 [D] s_b_12_0 = sym_111249_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_111249_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2731 [D] s_b_12_1: sym_110823_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_110823_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2731 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_6, b_18,  */
  fixed_block_b_13: 
  {
    /* execute.a64:1723 [F] s_b_13_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_13_1 = sym_111572_3_parameter_address uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_111572_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1723 [D] s_b_13_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_13_1);
    /* execute.a64:0 [F] s_b_13_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7, b_19,  */
  fixed_block_b_14: 
  {
    /* execute.a64:1723 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:1723 [D] s_b_14_1 = sym_112023_3_parameter_address uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_112023_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_16_0=sym_16469_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_16_1 = sym_112675_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_112675_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_17_0=sym_16469_3_parameter_inst.rt (const) */
    /* execute.a64:2684 [D] s_b_17_1 = sym_112957_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_112957_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_18_0=sym_16469_3_parameter_inst.rt2 (const) */
    /* execute.a64:2684 [D] s_b_18_1 = sym_114171_3_parameter_value uint64_t */
    auto s_b_18_1 = emitter.load_local(DV_sym_114171_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_19_0=sym_16469_3_parameter_inst.rt2 (const) */
    /* execute.a64:2684 [D] s_b_19_1 = sym_114237_3_parameter_value uint64_t */
    auto s_b_19_1 = emitter.load_local(DV_sym_114237_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_mov(const aarch64_decode_a64_LOGICAL_SR&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_122636_1__R_s_b_3_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122790_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122760_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122605_1__R_s_b_1_6 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122696_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122856_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122812_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122834_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2487 [F] s_b_0_0=sym_16881_3_parameter_inst.N (const) */
    /* execute.a64:2487 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
    if (insn.N) 
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
    /* execute.a64:2487 [F] s_b_1_0=sym_16881_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_1_1: If s_b_1_0: Jump b_4 else b_5 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_5;
    }
  }
  /* b_10, b_11, b_12, b_13, b_14, b_15, b_16, b_17,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2488 [F] s_b_3_0=sym_16881_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_3_1: If s_b_3_0: Jump b_7 else b_8 (const) */
    if (insn.sf) 
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
    /* execute.a64:2657 [F] s_b_4_0=sym_16881_3_parameter_inst.rm (const) */
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
    /* execute.a64:2657 [D] s_b_4_7: sym_122605_1__R_s_b_1_6 = s_b_4_6, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_122605_1__R_s_b_1_6, s_b_4_6);
    /* execute.a64:2657 [F] s_b_4_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2659 [F] s_b_5_0=sym_16881_3_parameter_inst.rm (const) */
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
    /* execute.a64:2659 [D] s_b_5_8: sym_122605_1__R_s_b_1_6 = s_b_5_7, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_122605_1__R_s_b_1_6, s_b_5_7);
    /* execute.a64:2659 [F] s_b_5_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [F] s_b_6_0=sym_16881_3_parameter_inst.sf (const) */
    /* execute.a64:2487 [D] s_b_6_1 = sym_122605_1__R_s_b_1_6 uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_122605_1__R_s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2487 [D] s_b_6_2 = ~s_b_6_1 */
    auto s_b_6_2 = emitter.bitwise_not(s_b_6_1);
    /* execute.a64:2487 [D] s_b_6_3: sym_122696_3_parameter_value = s_b_6_2, dominates: s_b_10_1 s_b_11_1  */
    emitter.store_local(DV_sym_122696_3_parameter_value, s_b_6_2);
    /* execute.a64:2690 [F] s_b_6_4: If s_b_6_0: Jump b_10 else b_11 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2657 [F] s_b_7_0=sym_16881_3_parameter_inst.rm (const) */
    /* execute.a64:2651 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2651 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_7_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_7_5 = ReadRegBank 0:s_b_7_0 (u64) */
    auto s_b_7_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_7_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_7_6: Select s_b_7_3 ? s_b_7_4 : s_b_7_5 */
    dbt::el::Value *s_b_7_6;
    s_b_7_6 = (s_b_7_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_7_5);
    /* execute.a64:2657 [D] s_b_7_7: sym_122636_1__R_s_b_3_6 = s_b_7_6, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_122636_1__R_s_b_3_6, s_b_7_6);
    /* execute.a64:2657 [F] s_b_7_8: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2659 [F] s_b_8_0=sym_16881_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2646 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_8_5 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_8_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_8_5);
    /* execute.a64:2659 [D] s_b_8_7 = (u64)s_b_8_6 */
    auto s_b_8_7 = emitter.zx(s_b_8_6, emitter.context().types().u64());
    /* execute.a64:2659 [D] s_b_8_8: sym_122636_1__R_s_b_3_6 = s_b_8_7, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_122636_1__R_s_b_3_6, s_b_8_7);
    /* execute.a64:2659 [F] s_b_8_9: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* ???:4294967295 [F] s_b_9_0=sym_16881_3_parameter_inst.sf (const) */
    /* execute.a64:2488 [D] s_b_9_1 = sym_122636_1__R_s_b_3_6 uint64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_122636_1__R_s_b_3_6, emitter.context().types().u64());
    /* execute.a64:2488 [D] s_b_9_2: sym_122760_3_parameter_value = s_b_9_1, dominates: s_b_12_1 s_b_13_1  */
    emitter.store_local(DV_sym_122760_3_parameter_value, s_b_9_1);
    /* execute.a64:2690 [F] s_b_9_3: If s_b_9_0: Jump b_12 else b_13 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_13;
    }
  }
  /* b_6,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2691 [F] s_b_10_0=sym_16881_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_10_1 = sym_122696_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_122696_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_10_2: sym_122790_3_parameter_value = s_b_10_1, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_122790_3_parameter_value, s_b_10_1);
    /* execute.a64:2682 [F] s_b_10_3 = (u32)s_b_10_0 (const) */
    /* execute.a64:2682 [F] s_b_10_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_10_6: If s_b_10_5: Jump b_2 else b_14 (const) */
    if (s_b_10_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_6,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2693 [F] s_b_11_0=sym_16881_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_11_1 = sym_122696_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_122696_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_2 = (u32)s_b_11_1 */
    auto s_b_11_2 = emitter.truncate(s_b_11_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_11_3 = (u64)s_b_11_2 */
    auto s_b_11_3 = emitter.zx(s_b_11_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_11_4: sym_122812_3_parameter_value = s_b_11_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_122812_3_parameter_value, s_b_11_3);
    /* execute.a64:2682 [F] s_b_11_5 = (u32)s_b_11_0 (const) */
    /* execute.a64:2682 [F] s_b_11_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_11_7 = s_b_11_5==s_b_11_6 (const) */
    uint8_t s_b_11_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_11_8: If s_b_11_7: Jump b_2 else b_15 (const) */
    if (s_b_11_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_9,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2691 [F] s_b_12_0=sym_16881_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_12_1 = sym_122760_3_parameter_value uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_122760_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_12_2: sym_122834_3_parameter_value = s_b_12_1, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_122834_3_parameter_value, s_b_12_1);
    /* execute.a64:2682 [F] s_b_12_3 = (u32)s_b_12_0 (const) */
    /* execute.a64:2682 [F] s_b_12_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_12_6: If s_b_12_5: Jump b_2 else b_16 (const) */
    if (s_b_12_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_16;
    }
  }
  /* b_9,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2693 [F] s_b_13_0=sym_16881_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_13_1 = sym_122760_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_122760_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_13_2 = (u32)s_b_13_1 */
    auto s_b_13_2 = emitter.truncate(s_b_13_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_13_3 = (u64)s_b_13_2 */
    auto s_b_13_3 = emitter.zx(s_b_13_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_13_4: sym_122856_3_parameter_value = s_b_13_3, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_122856_3_parameter_value, s_b_13_3);
    /* execute.a64:2682 [F] s_b_13_5 = (u32)s_b_13_0 (const) */
    /* execute.a64:2682 [F] s_b_13_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_13_7 = s_b_13_5==s_b_13_6 (const) */
    uint8_t s_b_13_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_13_8: If s_b_13_7: Jump b_2 else b_17 (const) */
    if (s_b_13_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_17;
    }
  }
  /* b_10,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2684 [F] s_b_14_0=sym_16881_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_14_1 = sym_122790_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_122790_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_14_1);
    /* execute.a64:0 [F] s_b_14_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_11,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2684 [F] s_b_15_0=sym_16881_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_15_1 = sym_122812_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_122812_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2684 [F] s_b_16_0=sym_16881_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_16_1 = sym_122834_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_122834_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_1);
    /* execute.a64:0 [F] s_b_16_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_13,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2684 [F] s_b_17_0=sym_16881_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_17_1 = sym_122856_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_122856_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_17_1);
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_msr_sctlr(const aarch64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:427 [F] s_b_0_0=sym_18897_3_parameter_inst.rt (const) */
    /* execute.a64:2651 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2651 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_0_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_0_5 = ReadRegBank 0:s_b_0_0 (u64) */
    auto s_b_0_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_0_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_0_6: Select s_b_0_3 ? s_b_0_4 : s_b_0_5 */
    dbt::el::Value *s_b_0_6;
    s_b_0_6 = (s_b_0_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_0_5);
    /* execute.a64:428 [F] s_b_0_7=sym_18897_3_parameter_inst.ir (const) */
    /* execute.a64:428 [F] s_b_0_8 = constant u32 10 (const) */
    /* ???:4294967295 [D] s_b_0_9 = write_device64 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_DEVICE,emitter.const_u32((uint32_t)16ULL), emitter.const_u32(insn.ir), s_b_0_6);
    }
    emitter.store_device(emitter.const_u32((uint32_t)16ULL), emitter.const_u32(insn.ir), s_b_0_6);
    /* execute.a64:429 [D] s_b_0_10 = read_pc */
    auto s_b_0_10 = emitter.load_pc();
    /* execute.a64:429 [F] s_b_0_11 = constant u64 4 (const) */
    /* execute.a64:429 [D] s_b_0_12 = s_b_0_10+s_b_0_11 */
    auto s_b_0_12 = emitter.add(s_b_0_10, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:429 [D] s_b_0_13 = write_pc */
    emitter.store_pc(s_b_0_12);
    /* ???:4294967295 [F] s_b_0_14: Return */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_orr_vector(const aarch64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1105 [F] s_b_0_0=sym_19392_3_parameter_inst.Q (const) */
    /* execute.simd:1105 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:1105 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:1105 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:1105 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:1106 [F] s_b_1_0=sym_19392_3_parameter_inst.rd (const) */
    /* execute.simd:1106 [F] s_b_1_1=sym_19392_3_parameter_inst.rn (const) */
    /* execute.simd:6275 [D] s_b_1_2 = ReadRegBank 7:s_b_1_1 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:1106 [F] s_b_1_3=sym_19392_3_parameter_inst.rm (const) */
    /* execute.simd:6275 [D] s_b_1_4 = ReadRegBank 7:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:1106 [D] s_b_1_5 = s_b_1_2|s_b_1_4 */
    auto s_b_1_5 = emitter.bitwise_or(s_b_1_2, s_b_1_4);
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
  /* b_1, b_3,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:1113 [F] s_b_3_0=sym_19392_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_3_1 = ReadRegBank 2:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:6281 [D] s_b_3_2 = ReadRegBank 3:s_b_3_0 (u64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:1114 [F] s_b_3_3=sym_19392_3_parameter_inst.rm (const) */
    /* execute.simd:6280 [D] s_b_3_4 = ReadRegBank 2:s_b_3_3 (u64) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(8));
    }
    /* execute.simd:6281 [D] s_b_3_5 = ReadRegBank 3:s_b_3_3 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:1116 [F] s_b_3_6=sym_19392_3_parameter_inst.rd (const) */
    /* execute.simd:1116 [D] s_b_3_7 = s_b_3_1|s_b_3_4 */
    auto s_b_3_7 = emitter.bitwise_or(s_b_3_1, s_b_3_4);
    /* execute.simd:1116 [D] s_b_3_8 = s_b_3_2|s_b_3_5 */
    auto s_b_3_8 = emitter.bitwise_or(s_b_3_2, s_b_3_5);
    /* execute.simd:6253 [D] s_b_3_9: WriteRegBank 2:s_b_3_6 = s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_7);
    /* execute.simd:6254 [D] s_b_3_10: WriteRegBank 3:s_b_3_6 = s_b_3_8 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_8,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_3_8);
    /* execute.simd:0 [F] s_b_3_11: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_prfum(const aarch64_decode_a64_LS_REG_USIMM&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_rorv(const aarch64_decode_a64_DP_2S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_126394_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_126484_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_20516_0_amount = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_126506_3_parameter_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2317 [F] s_b_0_0=sym_20511_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_0_1: If s_b_0_0: Jump b_4 else b_6 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_6;
    }
  }
  /* b_5,  */
  fixed_block_b_1: 
  {
    /* execute.a64:2319 [D] s_b_1_0 = sym_20516_0_amount uint8_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_20516_0_amount, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_1_1 = (u64)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_1_2 = constant u64 3f (const) */
    /* ???:4294967295 [D] s_b_1_3 = s_b_1_1&s_b_1_2 */
    auto s_b_1_3 = emitter.bitwise_and(s_b_1_1, emitter.const_u64((uint64_t)63ULL));
    /* execute.a64:2319 [D] s_b_1_4 = (u8)s_b_1_3 */
    auto s_b_1_4 = emitter.truncate(s_b_1_3, emitter.context().types().u8());
    /* execute.a64:2319 [D] s_b_1_5: sym_20516_0_amount = s_b_1_4, dominates:  */
    emitter.store_local(DV_sym_20516_0_amount, s_b_1_4);
    /* execute.a64:2320 [F] s_b_1_6=sym_20511_3_parameter_inst.rd (const) */
    /* execute.a64:2320 [F] s_b_1_7=sym_20511_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_1_8 = (u32)s_b_1_7 (const) */
    /* execute.a64:2651 [F] s_b_1_9 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_1_10 = s_b_1_8==s_b_1_9 (const) */
    uint8_t s_b_1_10 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_1_11 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_1_12 = ReadRegBank 0:s_b_1_7 (u64) */
    auto s_b_1_12 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_12,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_1_13: Select s_b_1_10 ? s_b_1_11 : s_b_1_12 */
    dbt::el::Value *s_b_1_13;
    s_b_1_13 = (s_b_1_10) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_1_12);
    /* execute.a64:2320 [D] s_b_1_14 = (u64)s_b_1_4 */
    auto s_b_1_14 = emitter.zx(s_b_1_4, emitter.context().types().u64());
    /* execute.a64:2320 [D] s_b_1_15 = s_b_1_13>>>s_b_1_14 */
    auto s_b_1_15 = emitter.ror(s_b_1_13, s_b_1_14);
    /* execute.a64:2320 [D] s_b_1_16: sym_126484_3_parameter_value = s_b_1_15, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_126484_3_parameter_value, s_b_1_15);
    /* execute.a64:2682 [F] s_b_1_17 = (u32)s_b_1_6 (const) */
    /* execute.a64:2682 [F] s_b_1_18 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_1_19 = s_b_1_17==s_b_1_18 (const) */
    uint8_t s_b_1_19 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_1_20: If s_b_1_19: Jump b_2 else b_7 (const) */
    if (s_b_1_19) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_1, b_3, b_7, b_8,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_5,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2322 [D] s_b_3_0 = sym_20516_0_amount uint8_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_20516_0_amount, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_3_1 = (u64)s_b_3_0 */
    auto s_b_3_1 = emitter.zx(s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_3_2 = constant u64 1f (const) */
    /* ???:4294967295 [D] s_b_3_3 = s_b_3_1&s_b_3_2 */
    auto s_b_3_3 = emitter.bitwise_and(s_b_3_1, emitter.const_u64((uint64_t)31ULL));
    /* execute.a64:2322 [D] s_b_3_4 = (u8)s_b_3_3 */
    auto s_b_3_4 = emitter.truncate(s_b_3_3, emitter.context().types().u8());
    /* execute.a64:2322 [D] s_b_3_5: sym_20516_0_amount = s_b_3_4, dominates:  */
    emitter.store_local(DV_sym_20516_0_amount, s_b_3_4);
    /* execute.a64:2323 [F] s_b_3_6=sym_20511_3_parameter_inst.rd (const) */
    /* execute.a64:2323 [F] s_b_3_7=sym_20511_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
    /* execute.a64:2646 [F] s_b_3_9 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_3_10 = s_b_3_8==s_b_3_9 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_3_11 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_3_12 = ReadRegBank 1:s_b_3_7 (u32) */
    auto s_b_3_12 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_3_12,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_3_13: Select s_b_3_10 ? s_b_3_11 : s_b_3_12 */
    dbt::el::Value *s_b_3_13;
    s_b_3_13 = (s_b_3_10) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_3_12);
    /* execute.a64:2323 [D] s_b_3_14 = (u32)s_b_3_4 */
    auto s_b_3_14 = emitter.zx(s_b_3_4, emitter.context().types().u32());
    /* execute.a64:2323 [D] s_b_3_15 = s_b_3_13>>>s_b_3_14 */
    auto s_b_3_15 = emitter.ror(s_b_3_13, s_b_3_14);
    /* execute.a64:2323 [D] s_b_3_16: sym_126506_3_parameter_value = s_b_3_15, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_126506_3_parameter_value, s_b_3_15);
    /* execute.a64:2674 [F] s_b_3_17 = (u32)s_b_3_6 (const) */
    /* execute.a64:2674 [F] s_b_3_18 = constant u32 1f (const) */
    /* execute.a64:2674 [F] s_b_3_19 = s_b_3_17==s_b_3_18 (const) */
    uint8_t s_b_3_19 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2674 [F] s_b_3_20: If s_b_3_19: Jump b_2 else b_8 (const) */
    if (s_b_3_19) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:2657 [F] s_b_4_0=sym_20511_3_parameter_inst.rm (const) */
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
    /* ???:4294967295 [D] s_b_4_7: sym_126394_0_return_symbol = s_b_4_6, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_126394_0_return_symbol, s_b_4_6);
    /* ???:4294967295 [F] s_b_4_8: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_6,  */
  fixed_block_b_5: 
  {
    /* ???:4294967295 [D] s_b_5_0 = sym_126394_0_return_symbol uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_126394_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:2317 [D] s_b_5_1 = (u8)s_b_5_0 */
    auto s_b_5_1 = emitter.truncate(s_b_5_0, emitter.context().types().u8());
    /* execute.a64:2317 [D] s_b_5_2: sym_20516_0_amount = s_b_5_1, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_20516_0_amount, s_b_5_1);
    /* execute.a64:2318 [F] s_b_5_3=sym_20511_3_parameter_inst.sf (const) */
    /* execute.a64:2318 [F] s_b_5_4: If s_b_5_3: Jump b_1 else b_3 (const) */
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
  fixed_block_b_6: 
  {
    /* execute.a64:2659 [F] s_b_6_0=sym_20511_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2646 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_6_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_6_5 = ReadRegBank 1:s_b_6_0 (u32) */
    auto s_b_6_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_6_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_6_6: Select s_b_6_3 ? s_b_6_4 : s_b_6_5 */
    dbt::el::Value *s_b_6_6;
    s_b_6_6 = (s_b_6_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_6_5);
    /* execute.a64:2659 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_8: sym_126394_0_return_symbol = s_b_6_7, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_126394_0_return_symbol, s_b_6_7);
    /* ???:4294967295 [F] s_b_6_9: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_1,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2684 [F] s_b_7_0=sym_20511_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_7_1 = sym_126484_3_parameter_value uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_126484_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_7_2: WriteRegBank 0:s_b_7_0 = s_b_7_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_7_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_7_1);
    /* execute.a64:0 [F] s_b_7_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2676 [F] s_b_8_0=sym_20511_3_parameter_inst.rd (const) */
    /* execute.a64:2676 [D] s_b_8_1 = sym_126506_3_parameter_value uint32_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_126506_3_parameter_value, emitter.context().types().u32());
    /* execute.a64:2676 [D] s_b_8_2 = (u64)s_b_8_1 */
    auto s_b_8_2 = emitter.zx(s_b_8_1, emitter.context().types().u64());
    /* execute.a64:2676 [D] s_b_8_3: WriteRegBank 0:s_b_8_0 = s_b_8_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_8_2,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_8_2);
    /* execute.a64:0 [F] s_b_8_4: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_sdiv(const aarch64_decode_a64_DP_2S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_1 = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_3 = emitter.context().create_block();
  auto block_b_4 = emitter.context().create_block();
  auto block_b_5 = emitter.context().create_block();
  auto block_b_9 = emitter.context().create_block();
  auto block_b_10 = emitter.context().create_block();
  auto block_b_11 = emitter.context().create_block();
  auto block_b_15 = emitter.context().create_block();
  auto block_b_16 = emitter.context().create_block();
  auto DV_sym_128159_0_return_symbol = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_128200_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_128273_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_128228_0_return_symbol = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_128295_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_22660_0_rn = emitter.alloc_local(emitter.context().types().s64(), true);
  auto DV_sym_22665_0_rm = emitter.alloc_local(emitter.context().types().s64(), true);
  auto DV_sym_22676_0_result = emitter.alloc_local(emitter.context().types().s64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2262 [F] s_b_0_0=sym_22655_3_parameter_inst.sf (const) */
    /* execute.a64:2665 [F] s_b_0_1: If s_b_0_0: Jump b_6 else b_8 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_6;
    }
    else 
    {
      goto fixed_block_b_8;
    }
  }
  // BLOCK b_1 not fully fixed
  // BLOCK b_2 not fully fixed
  // BLOCK b_3 not fully fixed
  // BLOCK b_4 not fully fixed
  // BLOCK b_5 not fully fixed
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2666 [F] s_b_6_0=sym_22655_3_parameter_inst.rn (const) */
    /* execute.a64:2666 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2666 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_6_4 = constant s64 0 (const) */
    /* execute.a64:2666 [D] s_b_6_5 = ReadRegBank 0:s_b_6_0 (u64) */
    auto s_b_6_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_6_5,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_6_6 = (s64)s_b_6_5 */
    auto s_b_6_6 = emitter.reinterpret(s_b_6_5, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_6_7: Select s_b_6_3 ? s_b_6_4 : s_b_6_6 */
    dbt::el::Value *s_b_6_7;
    s_b_6_7 = (s_b_6_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_6_6);
    /* ???:4294967295 [D] s_b_6_8: sym_128159_0_return_symbol = s_b_6_7, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_128159_0_return_symbol, s_b_6_7);
    /* ???:4294967295 [F] s_b_6_9: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_6, b_8,  */
  fixed_block_b_7: 
  {
    /* ???:4294967295 [D] s_b_7_0 = sym_128159_0_return_symbol int64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_128159_0_return_symbol, emitter.context().types().s64());
    /* execute.a64:2262 [D] s_b_7_1: sym_22660_0_rn = s_b_7_0, dominates: s_b_4_0 s_b_5_0  */
    emitter.store_local(DV_sym_22660_0_rn, s_b_7_0);
    /* execute.a64:2263 [F] s_b_7_2=sym_22655_3_parameter_inst.sf (const) */
    /* execute.a64:2665 [F] s_b_7_3: If s_b_7_2: Jump b_12 else b_14 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_12;
    }
    else 
    {
      goto fixed_block_b_14;
    }
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2668 [F] s_b_8_0=sym_22655_3_parameter_inst.rn (const) */
    /* execute.a64:2668 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2668 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_8_4 = constant s64 0 (const) */
    /* execute.a64:2668 [D] s_b_8_5 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_5,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_8_6 = (s32)s_b_8_5 */
    auto s_b_8_6 = emitter.reinterpret(s_b_8_5, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_8_7 = (s64)s_b_8_6 */
    auto s_b_8_7 = emitter.sx(s_b_8_6, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_8_8: Select s_b_8_3 ? s_b_8_4 : s_b_8_7 */
    dbt::el::Value *s_b_8_8;
    s_b_8_8 = (s_b_8_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_8_7);
    /* ???:4294967295 [D] s_b_8_9: sym_128159_0_return_symbol = s_b_8_8, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_128159_0_return_symbol, s_b_8_8);
    /* ???:4294967295 [F] s_b_8_10: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  // BLOCK b_9 not fully fixed
  // BLOCK b_10 not fully fixed
  // BLOCK b_11 not fully fixed
  /* b_7,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2666 [F] s_b_12_0=sym_22655_3_parameter_inst.rm (const) */
    /* execute.a64:2666 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.a64:2666 [F] s_b_12_2 = constant u32 1f (const) */
    /* execute.a64:2666 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2666 [F] s_b_12_4 = constant s64 0 (const) */
    /* execute.a64:2666 [D] s_b_12_5 = ReadRegBank 0:s_b_12_0 (u64) */
    auto s_b_12_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_12_5,emitter.const_u8(8));
    }
    /* execute.a64:2666 [D] s_b_12_6 = (s64)s_b_12_5 */
    auto s_b_12_6 = emitter.reinterpret(s_b_12_5, emitter.context().types().s64());
    /* execute.a64:2666 [D] s_b_12_7: Select s_b_12_3 ? s_b_12_4 : s_b_12_6 */
    dbt::el::Value *s_b_12_7;
    s_b_12_7 = (s_b_12_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_12_6);
    /* ???:4294967295 [D] s_b_12_8: sym_128228_0_return_symbol = s_b_12_7, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_128228_0_return_symbol, s_b_12_7);
    /* ???:4294967295 [F] s_b_12_9: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
  /* b_12, b_14,  */
  fixed_block_b_13: 
  {
    /* ???:4294967295 [D] s_b_13_0 = sym_128228_0_return_symbol int64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_128228_0_return_symbol, emitter.context().types().s64());
    /* execute.a64:2263 [D] s_b_13_1: sym_22665_0_rm = s_b_13_0, dominates: s_b_4_1 s_b_5_2  */
    emitter.store_local(DV_sym_22665_0_rm, s_b_13_0);
    /* execute.a64:2266 [F] s_b_13_2 = constant s64 0 (const) */
    /* execute.a64:2266 [D] s_b_13_3 = s_b_13_0==s_b_13_2 */
    auto s_b_13_3 = emitter.cmp_eq(s_b_13_0, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2266 [D] s_b_13_4: If s_b_13_3: Jump b_1 else b_3 */
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
      emitter.branch(s_b_13_3, true_target, false_target);
    }
    goto fixed_done;
  }
  /* b_7,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2668 [F] s_b_14_0=sym_22655_3_parameter_inst.rm (const) */
    /* execute.a64:2668 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
    /* execute.a64:2668 [F] s_b_14_2 = constant u32 1f (const) */
    /* execute.a64:2668 [F] s_b_14_3 = s_b_14_1==s_b_14_2 (const) */
    uint8_t s_b_14_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2668 [F] s_b_14_4 = constant s64 0 (const) */
    /* execute.a64:2668 [D] s_b_14_5 = ReadRegBank 1:s_b_14_0 (u32) */
    auto s_b_14_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_14_5,emitter.const_u8(4));
    }
    /* execute.a64:2668 [D] s_b_14_6 = (s32)s_b_14_5 */
    auto s_b_14_6 = emitter.reinterpret(s_b_14_5, emitter.context().types().s32());
    /* execute.a64:2668 [D] s_b_14_7 = (s64)s_b_14_6 */
    auto s_b_14_7 = emitter.sx(s_b_14_6, emitter.context().types().s64());
    /* execute.a64:2668 [D] s_b_14_8: Select s_b_14_3 ? s_b_14_4 : s_b_14_7 */
    dbt::el::Value *s_b_14_8;
    s_b_14_8 = (s_b_14_3) ? (emitter.const_s64((int64_t)0ULL)) : (s_b_14_7);
    /* ???:4294967295 [D] s_b_14_9: sym_128228_0_return_symbol = s_b_14_8, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_128228_0_return_symbol, s_b_14_8);
    /* ???:4294967295 [F] s_b_14_10: Jump b_13 (const) */
    goto fixed_block_b_13;
  }
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
        /* execute.a64:2267 [F] s_b_1_0 = constant s64 0 (const) */
        /* execute.a64:2267 [D] s_b_1_1: sym_22676_0_result = s_b_1_0, dominates: s_b_2_1  */
        emitter.store_local(DV_sym_22676_0_result, emitter.const_s64((int64_t)0ULL));
        /* execute.a64:2267 [F] s_b_1_2: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_2) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_2);
        /* execute.a64:2276 [F] s_b_2_0=sym_22655_3_parameter_inst.sf (const) */
        /* execute.a64:2276 [D] s_b_2_1 = sym_22676_0_result int64_t */
        auto s_b_2_1 = emitter.load_local(DV_sym_22676_0_result, emitter.context().types().s64());
        /* execute.a64:2276 [D] s_b_2_2 = (u64)s_b_2_1 */
        auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().u64());
        /* execute.a64:2276 [D] s_b_2_3: sym_128200_3_parameter_value = s_b_2_2, dominates: s_b_9_1 s_b_10_1  */
        emitter.store_local(DV_sym_128200_3_parameter_value, s_b_2_2);
        /* execute.a64:2690 [F] s_b_2_4: If s_b_2_0: Jump b_9 else b_10 (const) */
        if (insn.sf) 
        {
          auto block = block_b_9;
          dynamic_block_queue.push(block_b_9);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_10;
          dynamic_block_queue.push(block_b_10);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_3) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_3);
        /* execute.a64:2269 [F] s_b_3_0=sym_22655_3_parameter_inst.sf (const) */
        /* execute.a64:2269 [F] s_b_3_1: If s_b_3_0: Jump b_4 else b_5 (const) */
        if (insn.sf) 
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
        /* execute.a64:2270 [D] s_b_4_0 = sym_22660_0_rn int64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_22660_0_rn, emitter.context().types().s64());
        /* execute.a64:2270 [D] s_b_4_1 = sym_22665_0_rm int64_t */
        auto s_b_4_1 = emitter.load_local(DV_sym_22665_0_rm, emitter.context().types().s64());
        /* execute.a64:2270 [D] s_b_4_2 = s_b_4_0/s_b_4_1 */
        auto s_b_4_2 = emitter.div(s_b_4_0, s_b_4_1);
        /* execute.a64:2270 [D] s_b_4_3: sym_22676_0_result = s_b_4_2, dominates: s_b_2_1  */
        emitter.store_local(DV_sym_22676_0_result, s_b_4_2);
        /* execute.a64:2270 [F] s_b_4_4: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.a64:2272 [D] s_b_5_0 = sym_22660_0_rn int64_t */
        auto s_b_5_0 = emitter.load_local(DV_sym_22660_0_rn, emitter.context().types().s64());
        /* execute.a64:2272 [D] s_b_5_1 = (s32)s_b_5_0 */
        auto s_b_5_1 = emitter.truncate(s_b_5_0, emitter.context().types().s32());
        /* execute.a64:2272 [D] s_b_5_2 = sym_22665_0_rm int64_t */
        auto s_b_5_2 = emitter.load_local(DV_sym_22665_0_rm, emitter.context().types().s64());
        /* execute.a64:2272 [D] s_b_5_3 = (s32)s_b_5_2 */
        auto s_b_5_3 = emitter.truncate(s_b_5_2, emitter.context().types().s32());
        /* execute.a64:2272 [D] s_b_5_4 = s_b_5_1/s_b_5_3 */
        auto s_b_5_4 = emitter.div(s_b_5_1, s_b_5_3);
        /* execute.a64:2272 [D] s_b_5_5 = (s64)s_b_5_4 */
        auto s_b_5_5 = emitter.sx(s_b_5_4, emitter.context().types().s64());
        /* execute.a64:2272 [D] s_b_5_6: sym_22676_0_result = s_b_5_5, dominates: s_b_2_1  */
        emitter.store_local(DV_sym_22676_0_result, s_b_5_5);
        /* execute.a64:2272 [F] s_b_5_7: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.a64:2691 [F] s_b_9_0=sym_22655_3_parameter_inst.rd (const) */
        /* execute.a64:2691 [D] s_b_9_1 = sym_128200_3_parameter_value uint64_t */
        auto s_b_9_1 = emitter.load_local(DV_sym_128200_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2691 [D] s_b_9_2: sym_128273_3_parameter_value = s_b_9_1, dominates: s_b_15_1  */
        emitter.store_local(DV_sym_128273_3_parameter_value, s_b_9_1);
        /* execute.a64:2682 [F] s_b_9_3 = (u32)s_b_9_0 (const) */
        /* execute.a64:2682 [F] s_b_9_4 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_9_5 = s_b_9_3==s_b_9_4 (const) */
        uint8_t s_b_9_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_9_6: If s_b_9_5: Jump b_11 else b_15 (const) */
        if (s_b_9_5) 
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_15;
          dynamic_block_queue.push(block_b_15);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_10) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_10);
        /* execute.a64:2693 [F] s_b_10_0=sym_22655_3_parameter_inst.rd (const) */
        /* execute.a64:2693 [D] s_b_10_1 = sym_128200_3_parameter_value uint64_t */
        auto s_b_10_1 = emitter.load_local(DV_sym_128200_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_10_2 = (u32)s_b_10_1 */
        auto s_b_10_2 = emitter.truncate(s_b_10_1, emitter.context().types().u32());
        /* execute.a64:2693 [D] s_b_10_3 = (u64)s_b_10_2 */
        auto s_b_10_3 = emitter.zx(s_b_10_2, emitter.context().types().u64());
        /* execute.a64:2693 [D] s_b_10_4: sym_128295_3_parameter_value = s_b_10_3, dominates: s_b_16_1  */
        emitter.store_local(DV_sym_128295_3_parameter_value, s_b_10_3);
        /* execute.a64:2682 [F] s_b_10_5 = (u32)s_b_10_0 (const) */
        /* execute.a64:2682 [F] s_b_10_6 = constant u32 1f (const) */
        /* execute.a64:2682 [F] s_b_10_7 = s_b_10_5==s_b_10_6 (const) */
        uint8_t s_b_10_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
        /* execute.a64:2682 [F] s_b_10_8: If s_b_10_7: Jump b_11 else b_16 (const) */
        if (s_b_10_7) 
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
        else 
        {
          auto block = block_b_16;
          dynamic_block_queue.push(block_b_16);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* ???:4294967295 [F] s_b_11_0: Return */
        emitter.jump(__exit_block);
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.a64:2684 [F] s_b_15_0=sym_22655_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_15_1 = sym_128273_3_parameter_value uint64_t */
        auto s_b_15_1 = emitter.load_local(DV_sym_128273_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_15_2: WriteRegBank 0:s_b_15_0 = s_b_15_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_15_1);
        /* execute.a64:0 [F] s_b_15_3: Jump b_11 (const) */
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.a64:2684 [F] s_b_16_0=sym_22655_3_parameter_inst.rd (const) */
        /* execute.a64:2684 [D] s_b_16_1 = sym_128295_3_parameter_value uint64_t */
        auto s_b_16_1 = emitter.load_local(DV_sym_128295_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2684 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_1,emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_16_1);
        /* execute.a64:0 [F] s_b_16_3: Jump b_11 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_smov(const aarch64_decode_a64_SIMD_COPY&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ssubw(const aarch64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5943 [F] s_b_0_0=sym_29623_3_parameter_inst.tb (const) */
    /* execute.simd:5944 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5957 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5970 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5983 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5996 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:6009 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5943 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5945 [F] s_b_2_0=sym_29623_3_parameter_inst.rn (const) */
    /* execute.simd:5945 [D] s_b_2_1 = ReadRegBank 18:s_b_2_0 (v8u16) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(16));
    }
    /* execute.simd:5945 [D] s_b_2_2 = (v8s16)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s16());
    /* execute.simd:5946 [F] s_b_2_3=sym_29623_3_parameter_inst.rm (const) */
    /* execute.simd:5946 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5946 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5951 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_2_9 = constant u8 0 (const) */
    /* execute.simd:5951 [D] s_b_2_5[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5951 [D] s_b_2_11 = (s16)s_b_2_10 */
    auto s_b_2_11 = emitter.sx(s_b_2_10, emitter.context().types().s16());
    /* execute.simd:5951 [D] s_b_2_12 = s_b_2_8-s_b_2_11 */
    auto s_b_2_12 = emitter.sub(s_b_2_8, s_b_2_11);
    /* execute.simd:5951 [F] s_b_2_13 = constant s32 0 (const) */
    /* execute.simd:5951 [D] s_b_2_14 = s_b_2_6[s_b_2_13] <= s_b_2_12 */
    auto s_b_2_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_12);
    /* ???:4294967295 [F] s_b_2_15 = constant u8 1 (const) */
    /* execute.simd:5951 [D] s_b_2_2[s_b_2_15] */
    auto s_b_2_16 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_2_17 = constant u8 1 (const) */
    /* execute.simd:5951 [D] s_b_2_5[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5951 [D] s_b_2_19 = (s16)s_b_2_18 */
    auto s_b_2_19 = emitter.sx(s_b_2_18, emitter.context().types().s16());
    /* execute.simd:5951 [D] s_b_2_20 = s_b_2_16-s_b_2_19 */
    auto s_b_2_20 = emitter.sub(s_b_2_16, s_b_2_19);
    /* execute.simd:5951 [F] s_b_2_21 = constant s32 1 (const) */
    /* execute.simd:5951 [D] s_b_2_22 = s_b_2_14[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_14, emitter.const_s32((int32_t)1ULL), s_b_2_20);
    /* ???:4294967295 [F] s_b_2_23 = constant u8 2 (const) */
    /* execute.simd:5951 [D] s_b_2_2[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5951 [D] s_b_2_5[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5951 [D] s_b_2_27 = (s16)s_b_2_26 */
    auto s_b_2_27 = emitter.sx(s_b_2_26, emitter.context().types().s16());
    /* execute.simd:5951 [D] s_b_2_28 = s_b_2_24-s_b_2_27 */
    auto s_b_2_28 = emitter.sub(s_b_2_24, s_b_2_27);
    /* execute.simd:5951 [F] s_b_2_29 = constant s32 2 (const) */
    /* execute.simd:5951 [D] s_b_2_30 = s_b_2_22[s_b_2_29] <= s_b_2_28 */
    auto s_b_2_30 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)2ULL), s_b_2_28);
    /* ???:4294967295 [F] s_b_2_31 = constant u8 3 (const) */
    /* execute.simd:5951 [D] s_b_2_2[s_b_2_31] */
    auto s_b_2_32 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_2_33 = constant u8 3 (const) */
    /* execute.simd:5951 [D] s_b_2_5[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5951 [D] s_b_2_35 = (s16)s_b_2_34 */
    auto s_b_2_35 = emitter.sx(s_b_2_34, emitter.context().types().s16());
    /* execute.simd:5951 [D] s_b_2_36 = s_b_2_32-s_b_2_35 */
    auto s_b_2_36 = emitter.sub(s_b_2_32, s_b_2_35);
    /* execute.simd:5951 [F] s_b_2_37 = constant s32 3 (const) */
    /* execute.simd:5951 [D] s_b_2_38 = s_b_2_30[s_b_2_37] <= s_b_2_36 */
    auto s_b_2_38 = emitter.vector_insert(s_b_2_30, emitter.const_s32((int32_t)3ULL), s_b_2_36);
    /* ???:4294967295 [F] s_b_2_39 = constant u8 4 (const) */
    /* execute.simd:5951 [D] s_b_2_2[s_b_2_39] */
    auto s_b_2_40 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [F] s_b_2_41 = constant u8 4 (const) */
    /* execute.simd:5951 [D] s_b_2_5[s_b_2_41] */
    auto s_b_2_42 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5951 [D] s_b_2_43 = (s16)s_b_2_42 */
    auto s_b_2_43 = emitter.sx(s_b_2_42, emitter.context().types().s16());
    /* execute.simd:5951 [D] s_b_2_44 = s_b_2_40-s_b_2_43 */
    auto s_b_2_44 = emitter.sub(s_b_2_40, s_b_2_43);
    /* execute.simd:5951 [F] s_b_2_45 = constant s32 4 (const) */
    /* execute.simd:5951 [D] s_b_2_46 = s_b_2_38[s_b_2_45] <= s_b_2_44 */
    auto s_b_2_46 = emitter.vector_insert(s_b_2_38, emitter.const_s32((int32_t)4ULL), s_b_2_44);
    /* ???:4294967295 [F] s_b_2_47 = constant u8 5 (const) */
    /* execute.simd:5951 [D] s_b_2_2[s_b_2_47] */
    auto s_b_2_48 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [F] s_b_2_49 = constant u8 5 (const) */
    /* execute.simd:5951 [D] s_b_2_5[s_b_2_49] */
    auto s_b_2_50 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5951 [D] s_b_2_51 = (s16)s_b_2_50 */
    auto s_b_2_51 = emitter.sx(s_b_2_50, emitter.context().types().s16());
    /* execute.simd:5951 [D] s_b_2_52 = s_b_2_48-s_b_2_51 */
    auto s_b_2_52 = emitter.sub(s_b_2_48, s_b_2_51);
    /* execute.simd:5951 [F] s_b_2_53 = constant s32 5 (const) */
    /* execute.simd:5951 [D] s_b_2_54 = s_b_2_46[s_b_2_53] <= s_b_2_52 */
    auto s_b_2_54 = emitter.vector_insert(s_b_2_46, emitter.const_s32((int32_t)5ULL), s_b_2_52);
    /* ???:4294967295 [F] s_b_2_55 = constant u8 6 (const) */
    /* execute.simd:5951 [D] s_b_2_2[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [F] s_b_2_57 = constant u8 6 (const) */
    /* execute.simd:5951 [D] s_b_2_5[s_b_2_57] */
    auto s_b_2_58 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5951 [D] s_b_2_59 = (s16)s_b_2_58 */
    auto s_b_2_59 = emitter.sx(s_b_2_58, emitter.context().types().s16());
    /* execute.simd:5951 [D] s_b_2_60 = s_b_2_56-s_b_2_59 */
    auto s_b_2_60 = emitter.sub(s_b_2_56, s_b_2_59);
    /* execute.simd:5951 [F] s_b_2_61 = constant s32 6 (const) */
    /* execute.simd:5951 [D] s_b_2_62 = s_b_2_54[s_b_2_61] <= s_b_2_60 */
    auto s_b_2_62 = emitter.vector_insert(s_b_2_54, emitter.const_s32((int32_t)6ULL), s_b_2_60);
    /* ???:4294967295 [F] s_b_2_63 = constant u8 7 (const) */
    /* execute.simd:5951 [D] s_b_2_2[s_b_2_63] */
    auto s_b_2_64 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [F] s_b_2_65 = constant u8 7 (const) */
    /* execute.simd:5951 [D] s_b_2_5[s_b_2_65] */
    auto s_b_2_66 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5951 [D] s_b_2_67 = (s16)s_b_2_66 */
    auto s_b_2_67 = emitter.sx(s_b_2_66, emitter.context().types().s16());
    /* execute.simd:5951 [D] s_b_2_68 = s_b_2_64-s_b_2_67 */
    auto s_b_2_68 = emitter.sub(s_b_2_64, s_b_2_67);
    /* execute.simd:5951 [F] s_b_2_69 = constant s32 7 (const) */
    /* execute.simd:5951 [D] s_b_2_70 = s_b_2_62[s_b_2_69] <= s_b_2_68 */
    auto s_b_2_70 = emitter.vector_insert(s_b_2_62, emitter.const_s32((int32_t)7ULL), s_b_2_68);
    /* execute.simd:5954 [F] s_b_2_71=sym_29623_3_parameter_inst.rd (const) */
    /* execute.simd:5954 [D] s_b_2_72 = (v8u16)s_b_2_70 */
    auto s_b_2_72 = emitter.reinterpret(s_b_2_70, emitter.context().types().v8u16());
    /* execute.simd:5954 [D] s_b_2_73: WriteRegBank 18:s_b_2_71 = s_b_2_72 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_72,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_72);
    /* execute.simd:0 [F] s_b_2_74: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.simd:5958 [F] s_b_3_0=sym_29623_3_parameter_inst.rn (const) */
    /* execute.simd:5958 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5958 [D] s_b_3_2 = (v8s16)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v8s16());
    /* execute.simd:5959 [F] s_b_3_3=sym_29623_3_parameter_inst.rm (const) */
    /* execute.simd:5959 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5959 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_3_7 = constant u8 0 (const) */
    /* execute.simd:5964 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5964 [F] s_b_3_9 = constant u32 8 (const) */
    /* execute.simd:5964 [D] s_b_3_5[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5964 [D] s_b_3_11 = (s16)s_b_3_10 */
    auto s_b_3_11 = emitter.sx(s_b_3_10, emitter.context().types().s16());
    /* execute.simd:5964 [D] s_b_3_12 = s_b_3_8-s_b_3_11 */
    auto s_b_3_12 = emitter.sub(s_b_3_8, s_b_3_11);
    /* execute.simd:5964 [F] s_b_3_13 = constant s32 0 (const) */
    /* execute.simd:5964 [D] s_b_3_14 = s_b_3_6[s_b_3_13] <= s_b_3_12 */
    auto s_b_3_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_12);
    /* ???:4294967295 [F] s_b_3_15 = constant u8 1 (const) */
    /* execute.simd:5964 [D] s_b_3_2[s_b_3_15] */
    auto s_b_3_16 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5964 [F] s_b_3_17 = constant u32 9 (const) */
    /* execute.simd:5964 [D] s_b_3_5[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5964 [D] s_b_3_19 = (s16)s_b_3_18 */
    auto s_b_3_19 = emitter.sx(s_b_3_18, emitter.context().types().s16());
    /* execute.simd:5964 [D] s_b_3_20 = s_b_3_16-s_b_3_19 */
    auto s_b_3_20 = emitter.sub(s_b_3_16, s_b_3_19);
    /* execute.simd:5964 [F] s_b_3_21 = constant s32 1 (const) */
    /* execute.simd:5964 [D] s_b_3_22 = s_b_3_14[s_b_3_21] <= s_b_3_20 */
    auto s_b_3_22 = emitter.vector_insert(s_b_3_14, emitter.const_s32((int32_t)1ULL), s_b_3_20);
    /* ???:4294967295 [F] s_b_3_23 = constant u8 2 (const) */
    /* execute.simd:5964 [D] s_b_3_2[s_b_3_23] */
    auto s_b_3_24 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5964 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5964 [D] s_b_3_5[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5964 [D] s_b_3_27 = (s16)s_b_3_26 */
    auto s_b_3_27 = emitter.sx(s_b_3_26, emitter.context().types().s16());
    /* execute.simd:5964 [D] s_b_3_28 = s_b_3_24-s_b_3_27 */
    auto s_b_3_28 = emitter.sub(s_b_3_24, s_b_3_27);
    /* execute.simd:5964 [F] s_b_3_29 = constant s32 2 (const) */
    /* execute.simd:5964 [D] s_b_3_30 = s_b_3_22[s_b_3_29] <= s_b_3_28 */
    auto s_b_3_30 = emitter.vector_insert(s_b_3_22, emitter.const_s32((int32_t)2ULL), s_b_3_28);
    /* ???:4294967295 [F] s_b_3_31 = constant u8 3 (const) */
    /* execute.simd:5964 [D] s_b_3_2[s_b_3_31] */
    auto s_b_3_32 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5964 [F] s_b_3_33 = constant u32 b (const) */
    /* execute.simd:5964 [D] s_b_3_5[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5964 [D] s_b_3_35 = (s16)s_b_3_34 */
    auto s_b_3_35 = emitter.sx(s_b_3_34, emitter.context().types().s16());
    /* execute.simd:5964 [D] s_b_3_36 = s_b_3_32-s_b_3_35 */
    auto s_b_3_36 = emitter.sub(s_b_3_32, s_b_3_35);
    /* execute.simd:5964 [F] s_b_3_37 = constant s32 3 (const) */
    /* execute.simd:5964 [D] s_b_3_38 = s_b_3_30[s_b_3_37] <= s_b_3_36 */
    auto s_b_3_38 = emitter.vector_insert(s_b_3_30, emitter.const_s32((int32_t)3ULL), s_b_3_36);
    /* ???:4294967295 [F] s_b_3_39 = constant u8 4 (const) */
    /* execute.simd:5964 [D] s_b_3_2[s_b_3_39] */
    auto s_b_3_40 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5964 [F] s_b_3_41 = constant u32 c (const) */
    /* execute.simd:5964 [D] s_b_3_5[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5964 [D] s_b_3_43 = (s16)s_b_3_42 */
    auto s_b_3_43 = emitter.sx(s_b_3_42, emitter.context().types().s16());
    /* execute.simd:5964 [D] s_b_3_44 = s_b_3_40-s_b_3_43 */
    auto s_b_3_44 = emitter.sub(s_b_3_40, s_b_3_43);
    /* execute.simd:5964 [F] s_b_3_45 = constant s32 4 (const) */
    /* execute.simd:5964 [D] s_b_3_46 = s_b_3_38[s_b_3_45] <= s_b_3_44 */
    auto s_b_3_46 = emitter.vector_insert(s_b_3_38, emitter.const_s32((int32_t)4ULL), s_b_3_44);
    /* ???:4294967295 [F] s_b_3_47 = constant u8 5 (const) */
    /* execute.simd:5964 [D] s_b_3_2[s_b_3_47] */
    auto s_b_3_48 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5964 [F] s_b_3_49 = constant u32 d (const) */
    /* execute.simd:5964 [D] s_b_3_5[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5964 [D] s_b_3_51 = (s16)s_b_3_50 */
    auto s_b_3_51 = emitter.sx(s_b_3_50, emitter.context().types().s16());
    /* execute.simd:5964 [D] s_b_3_52 = s_b_3_48-s_b_3_51 */
    auto s_b_3_52 = emitter.sub(s_b_3_48, s_b_3_51);
    /* execute.simd:5964 [F] s_b_3_53 = constant s32 5 (const) */
    /* execute.simd:5964 [D] s_b_3_54 = s_b_3_46[s_b_3_53] <= s_b_3_52 */
    auto s_b_3_54 = emitter.vector_insert(s_b_3_46, emitter.const_s32((int32_t)5ULL), s_b_3_52);
    /* ???:4294967295 [F] s_b_3_55 = constant u8 6 (const) */
    /* execute.simd:5964 [D] s_b_3_2[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5964 [F] s_b_3_57 = constant u32 e (const) */
    /* execute.simd:5964 [D] s_b_3_5[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5964 [D] s_b_3_59 = (s16)s_b_3_58 */
    auto s_b_3_59 = emitter.sx(s_b_3_58, emitter.context().types().s16());
    /* execute.simd:5964 [D] s_b_3_60 = s_b_3_56-s_b_3_59 */
    auto s_b_3_60 = emitter.sub(s_b_3_56, s_b_3_59);
    /* execute.simd:5964 [F] s_b_3_61 = constant s32 6 (const) */
    /* execute.simd:5964 [D] s_b_3_62 = s_b_3_54[s_b_3_61] <= s_b_3_60 */
    auto s_b_3_62 = emitter.vector_insert(s_b_3_54, emitter.const_s32((int32_t)6ULL), s_b_3_60);
    /* ???:4294967295 [F] s_b_3_63 = constant u8 7 (const) */
    /* execute.simd:5964 [D] s_b_3_2[s_b_3_63] */
    auto s_b_3_64 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5964 [F] s_b_3_65 = constant u32 f (const) */
    /* execute.simd:5964 [D] s_b_3_5[s_b_3_65] */
    auto s_b_3_66 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5964 [D] s_b_3_67 = (s16)s_b_3_66 */
    auto s_b_3_67 = emitter.sx(s_b_3_66, emitter.context().types().s16());
    /* execute.simd:5964 [D] s_b_3_68 = s_b_3_64-s_b_3_67 */
    auto s_b_3_68 = emitter.sub(s_b_3_64, s_b_3_67);
    /* execute.simd:5964 [F] s_b_3_69 = constant s32 7 (const) */
    /* execute.simd:5964 [D] s_b_3_70 = s_b_3_62[s_b_3_69] <= s_b_3_68 */
    auto s_b_3_70 = emitter.vector_insert(s_b_3_62, emitter.const_s32((int32_t)7ULL), s_b_3_68);
    /* execute.simd:5967 [F] s_b_3_71=sym_29623_3_parameter_inst.rd (const) */
    /* execute.simd:5967 [D] s_b_3_72 = (v8u16)s_b_3_70 */
    auto s_b_3_72 = emitter.reinterpret(s_b_3_70, emitter.context().types().v8u16());
    /* execute.simd:5967 [D] s_b_3_73: WriteRegBank 18:s_b_3_71 = s_b_3_72 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_72,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_72);
    /* execute.simd:0 [F] s_b_3_74: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.simd:5971 [F] s_b_4_0=sym_29623_3_parameter_inst.rn (const) */
    /* execute.simd:5971 [D] s_b_4_1 = ReadRegBank 20:s_b_4_0 (v4u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:5971 [D] s_b_4_2 = (v4s32)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s32());
    /* execute.simd:5972 [F] s_b_4_3=sym_29623_3_parameter_inst.rm (const) */
    /* execute.simd:5972 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5972 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5977 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_9 = constant u8 0 (const) */
    /* execute.simd:5977 [D] s_b_4_5[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5977 [D] s_b_4_11 = (s32)s_b_4_10 */
    auto s_b_4_11 = emitter.sx(s_b_4_10, emitter.context().types().s32());
    /* execute.simd:5977 [D] s_b_4_12 = s_b_4_8-s_b_4_11 */
    auto s_b_4_12 = emitter.sub(s_b_4_8, s_b_4_11);
    /* execute.simd:5977 [F] s_b_4_13 = constant s32 0 (const) */
    /* execute.simd:5977 [D] s_b_4_14 = s_b_4_6[s_b_4_13] <= s_b_4_12 */
    auto s_b_4_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_12);
    /* ???:4294967295 [F] s_b_4_15 = constant u8 1 (const) */
    /* execute.simd:5977 [D] s_b_4_2[s_b_4_15] */
    auto s_b_4_16 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_4_17 = constant u8 1 (const) */
    /* execute.simd:5977 [D] s_b_4_5[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5977 [D] s_b_4_19 = (s32)s_b_4_18 */
    auto s_b_4_19 = emitter.sx(s_b_4_18, emitter.context().types().s32());
    /* execute.simd:5977 [D] s_b_4_20 = s_b_4_16-s_b_4_19 */
    auto s_b_4_20 = emitter.sub(s_b_4_16, s_b_4_19);
    /* execute.simd:5977 [F] s_b_4_21 = constant s32 1 (const) */
    /* execute.simd:5977 [D] s_b_4_22 = s_b_4_14[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_14, emitter.const_s32((int32_t)1ULL), s_b_4_20);
    /* ???:4294967295 [F] s_b_4_23 = constant u8 2 (const) */
    /* execute.simd:5977 [D] s_b_4_2[s_b_4_23] */
    auto s_b_4_24 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5977 [D] s_b_4_5[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5977 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* execute.simd:5977 [D] s_b_4_28 = s_b_4_24-s_b_4_27 */
    auto s_b_4_28 = emitter.sub(s_b_4_24, s_b_4_27);
    /* execute.simd:5977 [F] s_b_4_29 = constant s32 2 (const) */
    /* execute.simd:5977 [D] s_b_4_30 = s_b_4_22[s_b_4_29] <= s_b_4_28 */
    auto s_b_4_30 = emitter.vector_insert(s_b_4_22, emitter.const_s32((int32_t)2ULL), s_b_4_28);
    /* ???:4294967295 [F] s_b_4_31 = constant u8 3 (const) */
    /* execute.simd:5977 [D] s_b_4_2[s_b_4_31] */
    auto s_b_4_32 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_4_33 = constant u8 3 (const) */
    /* execute.simd:5977 [D] s_b_4_5[s_b_4_33] */
    auto s_b_4_34 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5977 [D] s_b_4_35 = (s32)s_b_4_34 */
    auto s_b_4_35 = emitter.sx(s_b_4_34, emitter.context().types().s32());
    /* execute.simd:5977 [D] s_b_4_36 = s_b_4_32-s_b_4_35 */
    auto s_b_4_36 = emitter.sub(s_b_4_32, s_b_4_35);
    /* execute.simd:5977 [F] s_b_4_37 = constant s32 3 (const) */
    /* execute.simd:5977 [D] s_b_4_38 = s_b_4_30[s_b_4_37] <= s_b_4_36 */
    auto s_b_4_38 = emitter.vector_insert(s_b_4_30, emitter.const_s32((int32_t)3ULL), s_b_4_36);
    /* execute.simd:5980 [F] s_b_4_39=sym_29623_3_parameter_inst.rd (const) */
    /* execute.simd:5980 [D] s_b_4_40 = (v4u32)s_b_4_38 */
    auto s_b_4_40 = emitter.reinterpret(s_b_4_38, emitter.context().types().v4u32());
    /* execute.simd:5980 [D] s_b_4_41: WriteRegBank 20:s_b_4_39 = s_b_4_40 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_40,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_40);
    /* execute.simd:0 [F] s_b_4_42: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.simd:5984 [F] s_b_5_0=sym_29623_3_parameter_inst.rn (const) */
    /* execute.simd:5984 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5984 [D] s_b_5_2 = (v4s32)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v4s32());
    /* execute.simd:5985 [F] s_b_5_3=sym_29623_3_parameter_inst.rm (const) */
    /* execute.simd:5985 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5985 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_5_7 = constant u8 0 (const) */
    /* execute.simd:5990 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5990 [F] s_b_5_9 = constant u32 4 (const) */
    /* execute.simd:5990 [D] s_b_5_5[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5990 [D] s_b_5_11 = (s32)s_b_5_10 */
    auto s_b_5_11 = emitter.sx(s_b_5_10, emitter.context().types().s32());
    /* execute.simd:5990 [D] s_b_5_12 = s_b_5_8-s_b_5_11 */
    auto s_b_5_12 = emitter.sub(s_b_5_8, s_b_5_11);
    /* execute.simd:5990 [F] s_b_5_13 = constant s32 0 (const) */
    /* execute.simd:5990 [D] s_b_5_14 = s_b_5_6[s_b_5_13] <= s_b_5_12 */
    auto s_b_5_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_12);
    /* ???:4294967295 [F] s_b_5_15 = constant u8 1 (const) */
    /* execute.simd:5990 [D] s_b_5_2[s_b_5_15] */
    auto s_b_5_16 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5990 [F] s_b_5_17 = constant u32 5 (const) */
    /* execute.simd:5990 [D] s_b_5_5[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5990 [D] s_b_5_19 = (s32)s_b_5_18 */
    auto s_b_5_19 = emitter.sx(s_b_5_18, emitter.context().types().s32());
    /* execute.simd:5990 [D] s_b_5_20 = s_b_5_16-s_b_5_19 */
    auto s_b_5_20 = emitter.sub(s_b_5_16, s_b_5_19);
    /* execute.simd:5990 [F] s_b_5_21 = constant s32 1 (const) */
    /* execute.simd:5990 [D] s_b_5_22 = s_b_5_14[s_b_5_21] <= s_b_5_20 */
    auto s_b_5_22 = emitter.vector_insert(s_b_5_14, emitter.const_s32((int32_t)1ULL), s_b_5_20);
    /* ???:4294967295 [F] s_b_5_23 = constant u8 2 (const) */
    /* execute.simd:5990 [D] s_b_5_2[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5990 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5990 [D] s_b_5_5[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5990 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:5990 [D] s_b_5_28 = s_b_5_24-s_b_5_27 */
    auto s_b_5_28 = emitter.sub(s_b_5_24, s_b_5_27);
    /* execute.simd:5990 [F] s_b_5_29 = constant s32 2 (const) */
    /* execute.simd:5990 [D] s_b_5_30 = s_b_5_22[s_b_5_29] <= s_b_5_28 */
    auto s_b_5_30 = emitter.vector_insert(s_b_5_22, emitter.const_s32((int32_t)2ULL), s_b_5_28);
    /* ???:4294967295 [F] s_b_5_31 = constant u8 3 (const) */
    /* execute.simd:5990 [D] s_b_5_2[s_b_5_31] */
    auto s_b_5_32 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5990 [F] s_b_5_33 = constant u32 7 (const) */
    /* execute.simd:5990 [D] s_b_5_5[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5990 [D] s_b_5_35 = (s32)s_b_5_34 */
    auto s_b_5_35 = emitter.sx(s_b_5_34, emitter.context().types().s32());
    /* execute.simd:5990 [D] s_b_5_36 = s_b_5_32-s_b_5_35 */
    auto s_b_5_36 = emitter.sub(s_b_5_32, s_b_5_35);
    /* execute.simd:5990 [F] s_b_5_37 = constant s32 3 (const) */
    /* execute.simd:5990 [D] s_b_5_38 = s_b_5_30[s_b_5_37] <= s_b_5_36 */
    auto s_b_5_38 = emitter.vector_insert(s_b_5_30, emitter.const_s32((int32_t)3ULL), s_b_5_36);
    /* execute.simd:5993 [F] s_b_5_39=sym_29623_3_parameter_inst.rd (const) */
    /* execute.simd:5993 [D] s_b_5_40 = (v4u32)s_b_5_38 */
    auto s_b_5_40 = emitter.reinterpret(s_b_5_38, emitter.context().types().v4u32());
    /* execute.simd:5993 [D] s_b_5_41: WriteRegBank 20:s_b_5_39 = s_b_5_40 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_40,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_40);
    /* execute.simd:0 [F] s_b_5_42: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.simd:5997 [F] s_b_6_0=sym_29623_3_parameter_inst.rn (const) */
    /* execute.simd:5997 [D] s_b_6_1 = ReadRegBank 21:s_b_6_0 (v2u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(16));
    }
    /* execute.simd:5997 [D] s_b_6_2 = (v2s64)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s64());
    /* execute.simd:5998 [F] s_b_6_3=sym_29623_3_parameter_inst.rm (const) */
    /* execute.simd:5998 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5998 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:6003 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_9 = constant u8 0 (const) */
    /* execute.simd:6003 [D] s_b_6_5[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:6003 [D] s_b_6_11 = (s64)s_b_6_10 */
    auto s_b_6_11 = emitter.sx(s_b_6_10, emitter.context().types().s64());
    /* execute.simd:6003 [D] s_b_6_12 = s_b_6_8-s_b_6_11 */
    auto s_b_6_12 = emitter.sub(s_b_6_8, s_b_6_11);
    /* execute.simd:6003 [F] s_b_6_13 = constant s32 0 (const) */
    /* execute.simd:6003 [D] s_b_6_14 = s_b_6_6[s_b_6_13] <= s_b_6_12 */
    auto s_b_6_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_12);
    /* ???:4294967295 [F] s_b_6_15 = constant u8 1 (const) */
    /* execute.simd:6003 [D] s_b_6_2[s_b_6_15] */
    auto s_b_6_16 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_6_17 = constant u8 1 (const) */
    /* execute.simd:6003 [D] s_b_6_5[s_b_6_17] */
    auto s_b_6_18 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:6003 [D] s_b_6_19 = (s64)s_b_6_18 */
    auto s_b_6_19 = emitter.sx(s_b_6_18, emitter.context().types().s64());
    /* execute.simd:6003 [D] s_b_6_20 = s_b_6_16-s_b_6_19 */
    auto s_b_6_20 = emitter.sub(s_b_6_16, s_b_6_19);
    /* execute.simd:6003 [F] s_b_6_21 = constant s32 1 (const) */
    /* execute.simd:6003 [D] s_b_6_22 = s_b_6_14[s_b_6_21] <= s_b_6_20 */
    auto s_b_6_22 = emitter.vector_insert(s_b_6_14, emitter.const_s32((int32_t)1ULL), s_b_6_20);
    /* execute.simd:6006 [F] s_b_6_23=sym_29623_3_parameter_inst.rd (const) */
    /* execute.simd:6006 [D] s_b_6_24 = (v2u64)s_b_6_22 */
    auto s_b_6_24 = emitter.reinterpret(s_b_6_22, emitter.context().types().v2u64());
    /* execute.simd:6006 [D] s_b_6_25: WriteRegBank 21:s_b_6_23 = s_b_6_24 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_24,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_24);
    /* execute.simd:0 [F] s_b_6_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.simd:6010 [F] s_b_7_0=sym_29623_3_parameter_inst.rn (const) */
    /* execute.simd:6010 [D] s_b_7_1 = ReadRegBank 21:s_b_7_0 (v2u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:6010 [D] s_b_7_2 = (v2s64)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v2s64());
    /* execute.simd:6011 [F] s_b_7_3=sym_29623_3_parameter_inst.rm (const) */
    /* execute.simd:6011 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:6011 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_7_7 = constant u8 0 (const) */
    /* execute.simd:6016 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:6016 [F] s_b_7_9 = constant u32 2 (const) */
    /* execute.simd:6016 [D] s_b_7_5[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:6016 [D] s_b_7_11 = (s64)s_b_7_10 */
    auto s_b_7_11 = emitter.sx(s_b_7_10, emitter.context().types().s64());
    /* execute.simd:6016 [D] s_b_7_12 = s_b_7_8-s_b_7_11 */
    auto s_b_7_12 = emitter.sub(s_b_7_8, s_b_7_11);
    /* execute.simd:6016 [F] s_b_7_13 = constant s32 0 (const) */
    /* execute.simd:6016 [D] s_b_7_14 = s_b_7_6[s_b_7_13] <= s_b_7_12 */
    auto s_b_7_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_12);
    /* ???:4294967295 [F] s_b_7_15 = constant u8 1 (const) */
    /* execute.simd:6016 [D] s_b_7_2[s_b_7_15] */
    auto s_b_7_16 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:6016 [F] s_b_7_17 = constant u32 3 (const) */
    /* execute.simd:6016 [D] s_b_7_5[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:6016 [D] s_b_7_19 = (s64)s_b_7_18 */
    auto s_b_7_19 = emitter.sx(s_b_7_18, emitter.context().types().s64());
    /* execute.simd:6016 [D] s_b_7_20 = s_b_7_16-s_b_7_19 */
    auto s_b_7_20 = emitter.sub(s_b_7_16, s_b_7_19);
    /* execute.simd:6016 [F] s_b_7_21 = constant s32 1 (const) */
    /* execute.simd:6016 [D] s_b_7_22 = s_b_7_14[s_b_7_21] <= s_b_7_20 */
    auto s_b_7_22 = emitter.vector_insert(s_b_7_14, emitter.const_s32((int32_t)1ULL), s_b_7_20);
    /* execute.simd:6019 [F] s_b_7_23=sym_29623_3_parameter_inst.rd (const) */
    /* execute.simd:6019 [D] s_b_7_24 = (v2u64)s_b_7_22 */
    auto s_b_7_24 = emitter.reinterpret(s_b_7_22, emitter.context().types().v2u64());
    /* execute.simd:6019 [D] s_b_7_25: WriteRegBank 21:s_b_7_23 = s_b_7_24 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_24,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_24);
    /* execute.simd:0 [F] s_b_7_26: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.simd:6023 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5943 [F] s_b_8_1: Jump b_1 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_st3pi(const aarch64_decode_a64_SIMD_LS_MULT_PI&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_132500_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_132811_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_132716_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_132733_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_132617_3_parameter_lane;
  auto DV_sym_132614_3_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_132609_3_parameter_rt;
  auto DV_sym_132870_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_132517_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_132691_1_tmp_s_b_5_2;
  auto DV_sym_132694_1_tmp_s_b_5_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30865_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_30871_0_lane;
  uint8_t CV_sym_30883_0_rt;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2646 [F] s_b_0_0=sym_30859_3_parameter_inst.rn (const) */
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
    /* execute.simd:2648 [F] s_b_1_0 = sym_30871_0_lane (const) uint8_t */
    uint8_t s_b_1_0 = CV_sym_30871_0_lane;
    /* execute.simd:2648 [F] s_b_1_1=sym_30859_3_parameter_inst.elemcnt (const) */
    /* execute.simd:2648 [F] s_b_1_2 = s_b_1_0<s_b_1_1 (const) */
    uint8_t s_b_1_2 = ((uint8_t)(s_b_1_0 < insn.elemcnt));
    /* execute.simd:2648 [F] s_b_1_3: If s_b_1_2: Jump b_2 else b_3 (const) */
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
    /* execute.simd:2649 [F] s_b_2_0 = constant u8 0 (const) */
    /* execute.simd:2649 [F] s_b_2_1: sym_30883_0_rt = s_b_2_0 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30883_0_rt = (uint8_t)0ULL;
    /* execute.simd:2649 [F] s_b_2_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_1,  */
  fixed_block_b_3: 
  {
    /* execute.simd:2655 [F] s_b_3_0=sym_30859_3_parameter_inst.rm (const) */
    /* execute.simd:2655 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2655 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.simd:2655 [F] s_b_3_3 = s_b_3_1!=s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rm) != (uint32_t)31ULL));
    /* execute.simd:2655 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.simd:2649 [F] s_b_4_0 = sym_30883_0_rt (const) uint8_t */
    uint8_t s_b_4_0 = CV_sym_30883_0_rt;
    /* execute.simd:2649 [F] s_b_4_1=sym_30859_3_parameter_inst.regcnt (const) */
    /* execute.simd:2649 [F] s_b_4_2 = s_b_4_0<s_b_4_1 (const) */
    uint8_t s_b_4_2 = ((uint8_t)(s_b_4_0 < insn.regcnt));
    /* execute.simd:2649 [F] s_b_4_3: If s_b_4_2: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2650 [F] s_b_5_0=sym_30859_3_parameter_inst.arrangement (const) */
    /* execute.simd:2650 [F] s_b_5_1=sym_30859_3_parameter_inst.rt (const) */
    /* execute.simd:2650 [F] s_b_5_2 = sym_30883_0_rt (const) uint8_t */
    uint8_t s_b_5_2 = CV_sym_30883_0_rt;
    /* execute.simd:2650 [F] s_b_5_3 = s_b_5_1+s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(insn.rt + s_b_5_2));
    /* execute.simd:2650 [F] s_b_5_4 = sym_30871_0_lane (const) uint8_t */
    uint8_t s_b_5_4 = CV_sym_30871_0_lane;
    /* execute.simd:2650 [D] s_b_5_5 = sym_30865_0_address uint64_t */
    auto s_b_5_5 = emitter.load_local(DV_sym_30865_0_address, emitter.context().types().u64());
    /* execute.simd:2650 [F] s_b_5_6: sym_132609_3_parameter_rt = s_b_5_3 (const), dominates: s_b_18_0 s_b_21_0 s_b_20_0 s_b_24_0 s_b_19_0 s_b_23_0 s_b_22_0  */
    CV_sym_132609_3_parameter_rt = s_b_5_3;
    /* execute.simd:2650 [F] s_b_5_7: sym_132617_3_parameter_lane = s_b_5_4 (const), dominates: s_b_18_3 s_b_21_3 s_b_20_3 s_b_24_3 s_b_19_3 s_b_23_3 s_b_22_3  */
    CV_sym_132617_3_parameter_lane = s_b_5_4;
    /* execute.simd:2650 [D] s_b_5_8: sym_132614_3_parameter_addr = s_b_5_5, dominates: s_b_18_2 s_b_21_2 s_b_20_2 s_b_24_2 s_b_19_2 s_b_23_2 s_b_22_2  */
    emitter.store_local(DV_sym_132614_3_parameter_addr, s_b_5_5);
    /* ???:4294967295 [F] s_b_5_9: sym_132691_1_tmp_s_b_5_2 = s_b_5_2 (const), dominates: s_b_25_1  */
    CV_sym_132691_1_tmp_s_b_5_2 = s_b_5_2;
    /* ???:4294967295 [D] s_b_5_10: sym_132694_1_tmp_s_b_5_5 = s_b_5_5, dominates: s_b_25_0  */
    emitter.store_local(DV_sym_132694_1_tmp_s_b_5_5, s_b_5_5);
    /* execute.simd:3882 [F] s_b_5_11 = constant s32 0 (const) */
    /* execute.simd:3887 [F] s_b_5_12 = constant s32 1 (const) */
    /* execute.simd:3892 [F] s_b_5_13 = constant s32 2 (const) */
    /* execute.simd:3897 [F] s_b_5_14 = constant s32 3 (const) */
    /* execute.simd:3902 [F] s_b_5_15 = constant s32 4 (const) */
    /* execute.simd:3907 [F] s_b_5_16 = constant s32 5 (const) */
    /* execute.simd:3912 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:3881 [F] s_b_5_18: Switch s_b_5_0: < <todo> > def b_17 (const) -> b_17, b_18, b_21, b_20, b_24, b_19, b_23, b_22,  */
    switch (insn.arrangement) 
    {
    case (int32_t)5ULL:
      goto fixed_block_b_24;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_21;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_20;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_19;
      break;
    case (int32_t)4ULL:
      goto fixed_block_b_23;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_22;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_18;
      break;
    default:
      goto fixed_block_b_17;
    }
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2648 [F] s_b_6_0 = sym_30871_0_lane (const) uint8_t */
    uint8_t s_b_6_0 = CV_sym_30871_0_lane;
    /* execute.simd:2648 [F] s_b_6_1 = constant u8 1 (const) */
    /* execute.simd:2648 [F] s_b_6_2 = s_b_6_0+s_b_6_1 (const) */
    uint8_t s_b_6_2 = ((uint8_t)(s_b_6_0 + (uint8_t)1ULL));
    /* execute.simd:2648 [F] s_b_6_3: sym_30871_0_lane = s_b_6_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30871_0_lane = s_b_6_2;
    /* execute.simd:2648 [F] s_b_6_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2656 [F] s_b_7_0=sym_30859_3_parameter_inst.rn (const) */
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
    /* execute.simd:2659 [F] s_b_8_0 = constant u8 1 (const) */
    /* execute.simd:2659 [D] s_b_8_1 = sym_30865_0_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_30865_0_address, emitter.context().types().u64());
    /* execute.simd:2659 [D] s_b_8_2: sym_132811_3_parameter_value = s_b_8_1, dominates: s_b_34_0 s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_132811_3_parameter_value, s_b_8_1);
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
    /* execute.a64:2733 [F] s_b_10_0=sym_30859_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_10_1 = ReadRegBank 0:s_b_10_0 (u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_10_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_10_2: sym_132500_0_return_symbol = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_132500_0_return_symbol, s_b_10_1);
    /* ???:4294967295 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_14,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [D] s_b_11_0 = sym_132500_0_return_symbol uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_132500_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2646 [D] s_b_11_1: sym_30865_0_address = s_b_11_0, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30865_0_address, s_b_11_0);
    /* execute.simd:2648 [F] s_b_11_2 = constant u8 0 (const) */
    /* execute.simd:2648 [F] s_b_11_3: sym_30871_0_lane = s_b_11_2 (const), dominates: s_b_1_0 s_b_5_4 s_b_6_0  */
    CV_sym_30871_0_lane = (uint8_t)0ULL;
    /* execute.simd:2648 [F] s_b_11_4: Jump b_1 (const) */
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
    /* execute.a64:2702 [D] s_b_12_1: sym_132517_1__R_s_b_3_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_132517_1__R_s_b_3_0, s_b_12_0);
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
    /* execute.a64:2731 [D] s_b_14_0 = sym_132517_1__R_s_b_3_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_132517_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_1: sym_132500_0_return_symbol = s_b_14_0, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_132500_0_return_symbol, s_b_14_0);
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
    /* execute.a64:2705 [D] s_b_15_1: sym_132517_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_132517_1__R_s_b_3_0, s_b_15_0);
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
    /* execute.a64:2707 [D] s_b_16_1: sym_132517_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_132517_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2707 [F] s_b_16_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_5,  */
  fixed_block_b_17: 
  {
    /* execute.simd:3918 [D] s_b_17_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:0 [F] s_b_17_1: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_18: 
  {
    /* execute.simd:3913 [F] s_b_18_0 = sym_132609_3_parameter_rt (const) uint8_t */
    uint8_t s_b_18_0 = CV_sym_132609_3_parameter_rt;
    /* execute.simd:3913 [D] s_b_18_1 = ReadRegBank 21:s_b_18_0 (v2u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_18_0))),s_b_18_1,emitter.const_u8(16));
    }
    /* execute.simd:3914 [D] s_b_18_2 = sym_132614_3_parameter_addr uint64_t */
    auto s_b_18_2 = emitter.load_local(DV_sym_132614_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3914 [F] s_b_18_3 = sym_132617_3_parameter_lane (const) uint8_t */
    uint8_t s_b_18_3 = CV_sym_132617_3_parameter_lane;
    /* execute.simd:3914 [D] s_b_18_1[s_b_18_3] */
    auto s_b_18_4 = emitter.vector_extract(s_b_18_1, emitter.const_u8(s_b_18_3));
    /* ???:4294967295 [D] s_b_18_5: Store 8 s_b_18_2 <= s_b_18_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_18_2, s_b_18_4, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_18_2, s_b_18_4);
    /* execute.simd:0 [F] s_b_18_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_19: 
  {
    /* execute.simd:3883 [F] s_b_19_0 = sym_132609_3_parameter_rt (const) uint8_t */
    uint8_t s_b_19_0 = CV_sym_132609_3_parameter_rt;
    /* execute.simd:3883 [D] s_b_19_1 = ReadRegBank 15:s_b_19_0 (v8u8) */
    auto s_b_19_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_19_0))),s_b_19_1,emitter.const_u8(8));
    }
    /* execute.simd:3884 [D] s_b_19_2 = sym_132614_3_parameter_addr uint64_t */
    auto s_b_19_2 = emitter.load_local(DV_sym_132614_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3884 [F] s_b_19_3 = sym_132617_3_parameter_lane (const) uint8_t */
    uint8_t s_b_19_3 = CV_sym_132617_3_parameter_lane;
    /* execute.simd:3884 [D] s_b_19_1[s_b_19_3] */
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
    /* execute.simd:3888 [F] s_b_20_0 = sym_132609_3_parameter_rt (const) uint8_t */
    uint8_t s_b_20_0 = CV_sym_132609_3_parameter_rt;
    /* execute.simd:3888 [D] s_b_20_1 = ReadRegBank 16:s_b_20_0 (v16u8) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_20_0))),s_b_20_1,emitter.const_u8(16));
    }
    /* execute.simd:3889 [D] s_b_20_2 = sym_132614_3_parameter_addr uint64_t */
    auto s_b_20_2 = emitter.load_local(DV_sym_132614_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3889 [F] s_b_20_3 = sym_132617_3_parameter_lane (const) uint8_t */
    uint8_t s_b_20_3 = CV_sym_132617_3_parameter_lane;
    /* execute.simd:3889 [D] s_b_20_1[s_b_20_3] */
    auto s_b_20_4 = emitter.vector_extract(s_b_20_1, emitter.const_u8(s_b_20_3));
    /* ???:4294967295 [D] s_b_20_5: Store 1 s_b_20_2 <= s_b_20_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_20_2, s_b_20_4, emitter.const_u8(1));
    }
    emitter.store_memory(s_b_20_2, s_b_20_4);
    /* execute.simd:0 [F] s_b_20_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_21: 
  {
    /* execute.simd:3893 [F] s_b_21_0 = sym_132609_3_parameter_rt (const) uint8_t */
    uint8_t s_b_21_0 = CV_sym_132609_3_parameter_rt;
    /* execute.simd:3893 [D] s_b_21_1 = ReadRegBank 17:s_b_21_0 (v4u16) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_21_0))),s_b_21_1,emitter.const_u8(8));
    }
    /* execute.simd:3894 [D] s_b_21_2 = sym_132614_3_parameter_addr uint64_t */
    auto s_b_21_2 = emitter.load_local(DV_sym_132614_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3894 [F] s_b_21_3 = sym_132617_3_parameter_lane (const) uint8_t */
    uint8_t s_b_21_3 = CV_sym_132617_3_parameter_lane;
    /* execute.simd:3894 [D] s_b_21_1[s_b_21_3] */
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
    /* execute.simd:3898 [F] s_b_22_0 = sym_132609_3_parameter_rt (const) uint8_t */
    uint8_t s_b_22_0 = CV_sym_132609_3_parameter_rt;
    /* execute.simd:3898 [D] s_b_22_1 = ReadRegBank 18:s_b_22_0 (v8u16) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_22_0))),s_b_22_1,emitter.const_u8(16));
    }
    /* execute.simd:3899 [D] s_b_22_2 = sym_132614_3_parameter_addr uint64_t */
    auto s_b_22_2 = emitter.load_local(DV_sym_132614_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3899 [F] s_b_22_3 = sym_132617_3_parameter_lane (const) uint8_t */
    uint8_t s_b_22_3 = CV_sym_132617_3_parameter_lane;
    /* execute.simd:3899 [D] s_b_22_1[s_b_22_3] */
    auto s_b_22_4 = emitter.vector_extract(s_b_22_1, emitter.const_u8(s_b_22_3));
    /* ???:4294967295 [D] s_b_22_5: Store 2 s_b_22_2 <= s_b_22_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_22_2, s_b_22_4, emitter.const_u8(2));
    }
    emitter.store_memory(s_b_22_2, s_b_22_4);
    /* execute.simd:0 [F] s_b_22_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_5,  */
  fixed_block_b_23: 
  {
    /* execute.simd:3903 [F] s_b_23_0 = sym_132609_3_parameter_rt (const) uint8_t */
    uint8_t s_b_23_0 = CV_sym_132609_3_parameter_rt;
    /* execute.simd:3903 [D] s_b_23_1 = ReadRegBank 19:s_b_23_0 (v2u32) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_23_0))),s_b_23_1,emitter.const_u8(8));
    }
    /* execute.simd:3904 [D] s_b_23_2 = sym_132614_3_parameter_addr uint64_t */
    auto s_b_23_2 = emitter.load_local(DV_sym_132614_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3904 [F] s_b_23_3 = sym_132617_3_parameter_lane (const) uint8_t */
    uint8_t s_b_23_3 = CV_sym_132617_3_parameter_lane;
    /* execute.simd:3904 [D] s_b_23_1[s_b_23_3] */
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
    /* execute.simd:3908 [F] s_b_24_0 = sym_132609_3_parameter_rt (const) uint8_t */
    uint8_t s_b_24_0 = CV_sym_132609_3_parameter_rt;
    /* execute.simd:3908 [D] s_b_24_1 = ReadRegBank 20:s_b_24_0 (v4u32) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * s_b_24_0))),s_b_24_1,emitter.const_u8(16));
    }
    /* execute.simd:3909 [D] s_b_24_2 = sym_132614_3_parameter_addr uint64_t */
    auto s_b_24_2 = emitter.load_local(DV_sym_132614_3_parameter_addr, emitter.context().types().u64());
    /* execute.simd:3909 [F] s_b_24_3 = sym_132617_3_parameter_lane (const) uint8_t */
    uint8_t s_b_24_3 = CV_sym_132617_3_parameter_lane;
    /* execute.simd:3909 [D] s_b_24_1[s_b_24_3] */
    auto s_b_24_4 = emitter.vector_extract(s_b_24_1, emitter.const_u8(s_b_24_3));
    /* ???:4294967295 [D] s_b_24_5: Store 4 s_b_24_2 <= s_b_24_4 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_24_2, s_b_24_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_24_2, s_b_24_4);
    /* execute.simd:0 [F] s_b_24_6: Jump b_25 (const) */
    goto fixed_block_b_25;
  }
  /* b_17, b_18, b_19, b_20, b_21, b_22, b_23, b_24,  */
  fixed_block_b_25: 
  {
    /* ???:4294967295 [D] s_b_25_0 = sym_132694_1_tmp_s_b_5_5 uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_132694_1_tmp_s_b_5_5, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_25_1 = sym_132691_1_tmp_s_b_5_2 (const) uint8_t */
    uint8_t s_b_25_1 = CV_sym_132691_1_tmp_s_b_5_2;
    /* execute.simd:2651 [F] s_b_25_2=sym_30859_3_parameter_inst.elemsize (const) */
    /* ???:4294967295 [F] s_b_25_3 = (u64)s_b_25_2 (const) */
    /* ???:4294967295 [D] s_b_25_4 = s_b_25_0+s_b_25_3 */
    auto s_b_25_4 = emitter.add(s_b_25_0, emitter.const_u64(((uint64_t)insn.elemsize)));
    /* execute.simd:2651 [D] s_b_25_5: sym_30865_0_address = s_b_25_4, dominates: s_b_5_5 s_b_8_1  */
    emitter.store_local(DV_sym_30865_0_address, s_b_25_4);
    /* execute.simd:2649 [F] s_b_25_6 = constant u8 1 (const) */
    /* execute.simd:2649 [F] s_b_25_7 = s_b_25_1+s_b_25_6 (const) */
    uint8_t s_b_25_7 = ((uint8_t)(s_b_25_1 + (uint8_t)1ULL));
    /* execute.simd:2649 [F] s_b_25_8: sym_30883_0_rt = s_b_25_7 (const), dominates: s_b_4_0 s_b_5_2  */
    CV_sym_30883_0_rt = s_b_25_7;
    /* execute.simd:2649 [F] s_b_25_9: Jump b_4 (const) */
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
    /* execute.a64:2733 [F] s_b_27_0=sym_30859_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_27_1 = ReadRegBank 0:s_b_27_0 (u64) */
    auto s_b_27_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_27_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_27_2: sym_132716_0_return_symbol = s_b_27_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_132716_0_return_symbol, s_b_27_1);
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_31,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_132716_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_132716_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2656 [F] s_b_28_1=sym_30859_3_parameter_inst.rm (const) */
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
    /* execute.simd:2656 [D] s_b_28_8 = s_b_28_0+s_b_28_7 */
    auto s_b_28_8 = emitter.add(s_b_28_0, s_b_28_7);
    /* execute.simd:2656 [D] s_b_28_9: sym_30865_0_address = s_b_28_8, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_30865_0_address, s_b_28_8);
    /* execute.simd:2656 [F] s_b_28_10: Jump b_8 (const) */
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
    /* execute.a64:2702 [D] s_b_29_1: sym_132733_1__R_s_b_3_0 = s_b_29_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_132733_1__R_s_b_3_0, s_b_29_0);
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
    /* execute.a64:2731 [D] s_b_31_0 = sym_132733_1__R_s_b_3_0 uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_132733_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_31_1: sym_132716_0_return_symbol = s_b_31_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_132716_0_return_symbol, s_b_31_0);
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
    /* execute.a64:2705 [D] s_b_32_1: sym_132733_1__R_s_b_3_0 = s_b_32_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_132733_1__R_s_b_3_0, s_b_32_0);
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
    /* execute.a64:2707 [D] s_b_33_1: sym_132733_1__R_s_b_3_0 = s_b_33_0, dominates: s_b_31_0  */
    emitter.store_local(DV_sym_132733_1__R_s_b_3_0, s_b_33_0);
    /* execute.a64:2707 [F] s_b_33_2: Jump b_31 (const) */
    goto fixed_block_b_31;
  }
  /* b_8,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2747 [D] s_b_34_0 = sym_132811_3_parameter_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_132811_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [F] s_b_34_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_34_2 = s_b_34_0&s_b_34_1 */
    auto s_b_34_2 = emitter.bitwise_and(s_b_34_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2747 [D] s_b_34_3: sym_132811_3_parameter_value = s_b_34_2, dominates: s_b_36_0 s_b_37_1  */
    emitter.store_local(DV_sym_132811_3_parameter_value, s_b_34_2);
    /* execute.a64:2747 [F] s_b_34_4: Jump b_35 (const) */
    goto fixed_block_b_35;
  }
  /* b_8, b_34,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2750 [F] s_b_35_0=sym_30859_3_parameter_inst.rn (const) */
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
    /* execute.a64:2751 [D] s_b_36_0 = sym_132811_3_parameter_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_132811_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2751 [D] s_b_36_1: sym_132870_3_parameter_value = s_b_36_0, dominates: s_b_39_0 s_b_40_0 s_b_41_0  */
    emitter.store_local(DV_sym_132870_3_parameter_value, s_b_36_0);
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
    /* execute.a64:2753 [F] s_b_37_0=sym_30859_3_parameter_inst.rn (const) */
    /* execute.a64:2753 [D] s_b_37_1 = sym_132811_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_132811_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2715 [D] s_b_39_0 = sym_132870_3_parameter_value uint64_t */
    auto s_b_39_0 = emitter.load_local(DV_sym_132870_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2718 [D] s_b_40_0 = sym_132870_3_parameter_value uint64_t */
    auto s_b_40_0 = emitter.load_local(DV_sym_132870_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2720 [D] s_b_41_0 = sym_132870_3_parameter_value uint64_t */
    auto s_b_41_0 = emitter.load_local(DV_sym_132870_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stlxrb(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_135488_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31324_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_135505_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:621 [F] s_b_0_0=sym_31318_3_parameter_inst.rn (const) */
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
    /* execute.a64:2733 [F] s_b_5_0=sym_31318_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_135488_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_135488_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_135488_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_135488_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:621 [D] s_b_6_1: sym_31324_0_address = s_b_6_0, dominates: s_b_1_0  */
    emitter.store_local(DV_sym_31324_0_address, s_b_6_0);
    /* execute.a64:623 [F] s_b_6_2 = constant u32 0 (const) */
    /* execute.a64:623 [D] s_b_6_3 = mem_monitor_release */
    auto s_b_6_3 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_6_0);
    /* execute.a64:623 [D] s_b_6_4: If s_b_6_3: Jump b_1 else b_3 */
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
    /* execute.a64:2702 [D] s_b_7_1: sym_135505_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135505_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2731 [D] s_b_9_0 = sym_135505_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_135505_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_135488_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_135488_0_return_symbol, s_b_9_0);
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
    /* execute.a64:2705 [D] s_b_10_1: sym_135505_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135505_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2707 [D] s_b_11_1: sym_135505_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_135505_1__R_s_b_3_0, s_b_11_0);
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
        /* execute.a64:624 [D] s_b_1_0 = sym_31324_0_address uint64_t */
        auto s_b_1_0 = emitter.load_local(DV_sym_31324_0_address, emitter.context().types().u64());
        /* execute.a64:624 [F] s_b_1_1=sym_31318_3_parameter_inst.rt (const) */
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
        /* execute.a64:625 [F] s_b_1_11=sym_31318_3_parameter_inst.rs (const) */
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
        /* execute.a64:627 [F] s_b_3_0=sym_31318_3_parameter_inst.rs (const) */
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
        /* execute.a64:2676 [F] s_b_12_0=sym_31318_3_parameter_inst.rs (const) */
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
        /* execute.a64:2676 [F] s_b_13_0=sym_31318_3_parameter_inst.rs (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_str_reg(const aarch64_decode_a64_LS_REG_REG_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_138933_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_31890_0_shift;
  uint64_t CV_sym_31917_0_rm;
  auto DV_sym_31917_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32015_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32024_0_rt = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_139456_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_138950_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1219 [F] s_b_0_0=sym_31879_3_parameter_inst.S (const) */
    /* execute.a64:1219 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1219 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:1219 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.S) == (uint32_t)0ULL));
    /* execute.a64:1219 [F] s_b_0_4 = constant u8 0 (const) */
    /* execute.a64:1219 [F] s_b_0_5=sym_31879_3_parameter_inst.size (const) */
    /* execute.a64:1219 [F] s_b_0_6 = (u8)s_b_0_5 (const) */
    /* execute.a64:1219 [F] s_b_0_7: Select s_b_0_3 ? s_b_0_4 : s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(s_b_0_3 ? ((uint8_t)0ULL) : (((uint8_t)insn.size))));
    /* execute.a64:1219 [F] s_b_0_8: sym_31890_0_shift = s_b_0_7 (const), dominates: s_b_1_1 s_b_4_1 s_b_6_1 s_b_8_1  */
    CV_sym_31890_0_shift = s_b_0_7;
    /* execute.a64:1222 [F] s_b_0_9=sym_31879_3_parameter_inst.option0 (const) */
    /* execute.a64:1222 [F] s_b_0_10 = (u32)s_b_0_9 (const) */
    /* execute.a64:1222 [F] s_b_0_11 = constant u32 0 (const) */
    /* execute.a64:1222 [F] s_b_0_12 = s_b_0_10==s_b_0_11 (const) */
    uint8_t s_b_0_12 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1222 [F] s_b_0_13=sym_31879_3_parameter_inst.option21 (const) */
    /* execute.a64:1222 [F] s_b_0_14 = (u32)s_b_0_13 (const) */
    /* execute.a64:1222 [F] s_b_0_15 = constant u32 1 (const) */
    /* execute.a64:1222 [F] s_b_0_16 = s_b_0_14==s_b_0_15 (const) */
    uint8_t s_b_0_16 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_17 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_18 = s_b_0_12!=s_b_0_17 (const) */
    uint8_t s_b_0_18 = ((uint8_t)(s_b_0_12 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_19 = s_b_0_16!=s_b_0_17 (const) */
    uint8_t s_b_0_19 = ((uint8_t)(s_b_0_16 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_20 = s_b_0_18&s_b_0_19 (const) */
    uint8_t s_b_0_20 = ((uint8_t)(s_b_0_18 & s_b_0_19));
    /* execute.a64:1222 [F] s_b_0_21: If s_b_0_20: Jump b_1 else b_3 (const) */
    if (s_b_0_20) 
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
    /* execute.a64:1223 [F] s_b_1_0=sym_31879_3_parameter_inst.rm (const) */
    /* execute.a64:1223 [F] s_b_1_1 = sym_31890_0_shift (const) uint8_t */
    uint8_t s_b_1_1 = CV_sym_31890_0_shift;
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
    /* execute.a64:1223 [D] s_b_1_13: sym_31917_0_rm = s_b_1_12, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_31917_0_rm, s_b_1_12);
    /* execute.a64:1223 [F] s_b_1_14: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_4, b_6, b_8, b_9,  */
  fixed_block_b_2: 
  {
    /* execute.a64:1235 [F] s_b_2_0=sym_31879_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_2_1 = (u32)s_b_2_0 (const) */
    /* execute.a64:2730 [F] s_b_2_2 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_2_3 = s_b_2_1==s_b_2_2 (const) */
    uint8_t s_b_2_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_2_4: If s_b_2_3: Jump b_13 else b_14 (const) */
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
    /* execute.a64:1224 [F] s_b_3_0=sym_31879_3_parameter_inst.option0 (const) */
    /* execute.a64:1224 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1224 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:1224 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1224 [F] s_b_3_4=sym_31879_3_parameter_inst.option21 (const) */
    /* execute.a64:1224 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:1224 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.a64:1224 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:1224 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1225 [F] s_b_4_0=sym_31879_3_parameter_inst.rm (const) */
    /* execute.a64:1225 [F] s_b_4_1 = sym_31890_0_shift (const) uint8_t */
    uint8_t s_b_4_1 = CV_sym_31890_0_shift;
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
    /* execute.a64:1225 [D] s_b_4_14: sym_31917_0_rm = s_b_4_13, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_31917_0_rm, s_b_4_13);
    /* execute.a64:1225 [F] s_b_4_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1226 [F] s_b_5_0=sym_31879_3_parameter_inst.option0 (const) */
    /* execute.a64:1226 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1226 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.a64:1226 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1226 [F] s_b_5_4=sym_31879_3_parameter_inst.option21 (const) */
    /* execute.a64:1226 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1226 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.a64:1226 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1226 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1227 [F] s_b_6_0=sym_31879_3_parameter_inst.rm (const) */
    /* execute.a64:1227 [F] s_b_6_1 = sym_31890_0_shift (const) uint8_t */
    uint8_t s_b_6_1 = CV_sym_31890_0_shift;
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
    /* execute.a64:1227 [D] s_b_6_10: sym_31917_0_rm = s_b_6_9, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_31917_0_rm, s_b_6_9);
    /* execute.a64:1227 [F] s_b_6_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1228 [F] s_b_7_0=sym_31879_3_parameter_inst.option0 (const) */
    /* execute.a64:1228 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:1228 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.a64:1228 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1228 [F] s_b_7_4=sym_31879_3_parameter_inst.option21 (const) */
    /* execute.a64:1228 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:1228 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.a64:1228 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:1228 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.a64:1229 [F] s_b_8_0=sym_31879_3_parameter_inst.rm (const) */
    /* execute.a64:1229 [F] s_b_8_1 = sym_31890_0_shift (const) uint8_t */
    uint8_t s_b_8_1 = CV_sym_31890_0_shift;
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
    /* execute.a64:1229 [D] s_b_8_10: sym_31917_0_rm = s_b_8_9, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_31917_0_rm, s_b_8_9);
    /* execute.a64:1229 [F] s_b_8_11: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1231 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:1231 [F] s_b_9_1: sym_31917_0_rm = s_b_9_0 (const), dominates: s_b_15_1  */
    CV_sym_31917_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_31917_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1232 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1231 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_22,  */
  fixed_block_b_10: 
  {
    /* execute.a64:1239 [D] s_b_10_0 = sym_32015_0_address uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_32015_0_address, emitter.context().types().u64());
    /* execute.a64:1239 [D] s_b_10_1 = sym_32024_0_rt uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_32024_0_rt, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_2: Store 8 s_b_10_0 <= s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_10_0, s_b_10_1);
    /* execute.a64:1239 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10, b_12,  */
  fixed_block_b_11: 
  {
    /* ???:4294967295 [F] s_b_11_0: Return */
    goto fixed_done;
  }
  /* b_22,  */
  fixed_block_b_12: 
  {
    /* execute.a64:1241 [D] s_b_12_0 = sym_32015_0_address uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_32015_0_address, emitter.context().types().u64());
    /* execute.a64:1241 [D] s_b_12_1 = sym_32024_0_rt uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_32024_0_rt, emitter.context().types().u64());
    /* execute.a64:1241 [D] s_b_12_2 = (u32)s_b_12_1 */
    auto s_b_12_2 = emitter.truncate(s_b_12_1, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_12_3: Store 4 s_b_12_0 <= s_b_12_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_12_0, s_b_12_2, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_12_0, s_b_12_2);
    /* execute.a64:1241 [F] s_b_12_4: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_2,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2701 [F] s_b_13_0 = constant u32 1 (const) */
    /* execute.a64:2701 [F] s_b_13_1 = __builtin_get_feature */
    uint32_t s_b_13_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2701 [F] s_b_13_2 = constant u32 0 (const) */
    /* execute.a64:2701 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(s_b_13_1 == (uint32_t)0ULL));
    /* execute.a64:2701 [F] s_b_13_4: If s_b_13_3: Jump b_16 else b_17 (const) */
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
    /* execute.a64:2733 [F] s_b_14_0=sym_31879_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_14_2: sym_138933_0_return_symbol = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_138933_0_return_symbol, s_b_14_1);
    /* ???:4294967295 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14, b_18,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_138933_0_return_symbol uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_138933_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1235 [D] s_b_15_1 = sym_31917_0_rm uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_31917_0_rm, emitter.context().types().u64());
    /* execute.a64:1235 [D] s_b_15_2 = s_b_15_0+s_b_15_1 */
    auto s_b_15_2 = emitter.add(s_b_15_0, s_b_15_1);
    /* execute.a64:1235 [D] s_b_15_3: sym_32015_0_address = s_b_15_2, dominates: s_b_10_0 s_b_12_0  */
    emitter.store_local(DV_sym_32015_0_address, s_b_15_2);
    /* execute.a64:1237 [F] s_b_15_4=sym_31879_3_parameter_inst.size (const) */
    /* execute.a64:1237 [F] s_b_15_5 = (u32)s_b_15_4 (const) */
    /* execute.a64:1237 [F] s_b_15_6 = constant u32 3 (const) */
    /* execute.a64:1237 [F] s_b_15_7 = s_b_15_5==s_b_15_6 (const) */
    uint8_t s_b_15_7 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.a64:2656 [F] s_b_15_8: If s_b_15_7: Jump b_21 else b_23 (const) */
    if (s_b_15_7) 
    {
      goto fixed_block_b_21;
    }
    else 
    {
      goto fixed_block_b_23;
    }
  }
  /* b_13,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2702 [D] s_b_16_0 = ReadReg 20 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_16_1: sym_138950_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_138950_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2702 [F] s_b_16_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_13,  */
  fixed_block_b_17: 
  {
    /* execute.a64:3012 [F] s_b_17_0 = constant u32 0 (const) */
    /* execute.a64:3012 [F] s_b_17_1 = __builtin_get_feature */
    uint32_t s_b_17_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3012 [F] s_b_17_2 = (u8)s_b_17_1 (const) */
    /* execute.a64:2704 [F] s_b_17_3 = (u32)s_b_17_2 (const) */
    /* execute.a64:2704 [F] s_b_17_4 = constant u32 0 (const) */
    /* execute.a64:2704 [F] s_b_17_5 = s_b_17_3==s_b_17_4 (const) */
    uint8_t s_b_17_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_17_1)) == (uint32_t)0ULL));
    /* execute.a64:2704 [F] s_b_17_6: If s_b_17_5: Jump b_19 else b_20 (const) */
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
    /* execute.a64:2731 [D] s_b_18_0 = sym_138950_1__R_s_b_3_0 uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_138950_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1: sym_138933_0_return_symbol = s_b_18_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_138933_0_return_symbol, s_b_18_0);
    /* ???:4294967295 [F] s_b_18_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_17,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2705 [D] s_b_19_0 = ReadReg 20 (u64) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_19_1: sym_138950_1__R_s_b_3_0 = s_b_19_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_138950_1__R_s_b_3_0, s_b_19_0);
    /* execute.a64:2705 [F] s_b_19_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_17,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2707 [D] s_b_20_0 = ReadReg 21 (u64) */
    auto s_b_20_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_20_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_20_1: sym_138950_1__R_s_b_3_0 = s_b_20_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_138950_1__R_s_b_3_0, s_b_20_0);
    /* execute.a64:2707 [F] s_b_20_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_15,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2657 [F] s_b_21_0=sym_31879_3_parameter_inst.rt (const) */
    /* execute.a64:2651 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
    /* execute.a64:2651 [F] s_b_21_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
    uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_21_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_21_5 = ReadRegBank 0:s_b_21_0 (u64) */
    auto s_b_21_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_21_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_21_6: Select s_b_21_3 ? s_b_21_4 : s_b_21_5 */
    dbt::el::Value *s_b_21_6;
    s_b_21_6 = (s_b_21_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_21_5);
    /* ???:4294967295 [D] s_b_21_7: sym_139456_0_return_symbol = s_b_21_6, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_139456_0_return_symbol, s_b_21_6);
    /* ???:4294967295 [F] s_b_21_8: Jump b_22 (const) */
    goto fixed_block_b_22;
  }
  /* b_21, b_23,  */
  fixed_block_b_22: 
  {
    /* ???:4294967295 [D] s_b_22_0 = sym_139456_0_return_symbol uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_139456_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1237 [D] s_b_22_1: sym_32024_0_rt = s_b_22_0, dominates: s_b_10_1 s_b_12_1  */
    emitter.store_local(DV_sym_32024_0_rt, s_b_22_0);
    /* execute.a64:1238 [F] s_b_22_2=sym_31879_3_parameter_inst.size (const) */
    /* execute.a64:1238 [F] s_b_22_3 = (u32)s_b_22_2 (const) */
    /* execute.a64:1238 [F] s_b_22_4 = constant u32 3 (const) */
    /* execute.a64:1238 [F] s_b_22_5 = s_b_22_3==s_b_22_4 (const) */
    uint8_t s_b_22_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.a64:1238 [F] s_b_22_6: If s_b_22_5: Jump b_10 else b_12 (const) */
    if (s_b_22_5) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_15,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2659 [F] s_b_23_0=sym_31879_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
    /* execute.a64:2646 [F] s_b_23_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_23_3 = s_b_23_1==s_b_23_2 (const) */
    uint8_t s_b_23_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_23_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_23_5 = ReadRegBank 1:s_b_23_0 (u32) */
    auto s_b_23_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_23_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_23_6: Select s_b_23_3 ? s_b_23_4 : s_b_23_5 */
    dbt::el::Value *s_b_23_6;
    s_b_23_6 = (s_b_23_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_23_5);
    /* execute.a64:2659 [D] s_b_23_7 = (u64)s_b_23_6 */
    auto s_b_23_7 = emitter.zx(s_b_23_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_23_8: sym_139456_0_return_symbol = s_b_23_7, dominates: s_b_22_0  */
    emitter.store_local(DV_sym_139456_0_return_symbol, s_b_23_7);
    /* ???:4294967295 [F] s_b_23_9: Jump b_22 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stri(const aarch64_decode_a64_LS_REG_UIMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_142970_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_142953_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32688_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32696_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_142902_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1446 [F] s_b_0_0=sym_32679_3_parameter_inst.size (const) */
    /* execute.a64:1446 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1446 [F] s_b_0_2 = constant u32 3 (const) */
    /* execute.a64:1446 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.a64:2656 [F] s_b_0_4: If s_b_0_3: Jump b_5 else b_7 (const) */
    if (s_b_0_3) 
    {
      goto fixed_block_b_5;
    }
    else 
    {
      goto fixed_block_b_7;
    }
  }
  /* b_10,  */
  fixed_block_b_1: 
  {
    /* execute.a64:1450 [D] s_b_1_0 = sym_32696_0_addr uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_32696_0_addr, emitter.context().types().u64());
    /* execute.a64:1450 [D] s_b_1_1 = sym_32688_0_value uint64_t */
    auto s_b_1_1 = emitter.load_local(DV_sym_32688_0_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_2: Store 8 s_b_1_0 <= s_b_1_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_1_0, s_b_1_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_1_0, s_b_1_1);
    /* execute.a64:1450 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_3, b_4,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_3: 
  {
    /* execute.a64:1451 [F] s_b_3_0=sym_32679_3_parameter_inst.size (const) */
    /* execute.a64:1451 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1451 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:1451 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:1451 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_2 (const) */
    if (s_b_3_3) 
    {
      goto fixed_block_b_4;
    }
    else 
    {
      goto fixed_block_b_2;
    }
  }
  /* b_3,  */
  fixed_block_b_4: 
  {
    /* execute.a64:1452 [D] s_b_4_0 = sym_32696_0_addr uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_32696_0_addr, emitter.context().types().u64());
    /* execute.a64:1452 [D] s_b_4_1 = sym_32688_0_value uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_32688_0_value, emitter.context().types().u64());
    /* execute.a64:1452 [D] s_b_4_2 = (u32)s_b_4_1 */
    auto s_b_4_2 = emitter.truncate(s_b_4_1, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_4_3: Store 4 s_b_4_0 <= s_b_4_2 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_4_0, s_b_4_2, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_4_0, s_b_4_2);
    /* execute.a64:1452 [F] s_b_4_4: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2657 [F] s_b_5_0=sym_32679_3_parameter_inst.rt (const) */
    /* execute.a64:2651 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:2651 [F] s_b_5_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_5_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_5_5 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_5_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_5_6: Select s_b_5_3 ? s_b_5_4 : s_b_5_5 */
    dbt::el::Value *s_b_5_6;
    s_b_5_6 = (s_b_5_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_5_5);
    /* ???:4294967295 [D] s_b_5_7: sym_142902_0_return_symbol = s_b_5_6, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_142902_0_return_symbol, s_b_5_6);
    /* ???:4294967295 [F] s_b_5_8: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_7,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_142902_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_142902_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1446 [D] s_b_6_1: sym_32688_0_value = s_b_6_0, dominates: s_b_1_1 s_b_4_1  */
    emitter.store_local(DV_sym_32688_0_value, s_b_6_0);
    /* execute.a64:1447 [F] s_b_6_2=sym_32679_3_parameter_inst.rn (const) */
    /* execute.a64:2730 [F] s_b_6_3 = (u32)s_b_6_2 (const) */
    /* execute.a64:2730 [F] s_b_6_4 = constant u32 1f (const) */
    /* execute.a64:2730 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2730 [F] s_b_6_6: If s_b_6_5: Jump b_8 else b_9 (const) */
    if (s_b_6_5) 
    {
      goto fixed_block_b_8;
    }
    else 
    {
      goto fixed_block_b_9;
    }
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2659 [F] s_b_7_0=sym_32679_3_parameter_inst.rt (const) */
    /* execute.a64:2646 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:2646 [F] s_b_7_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_7_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_7_5 = ReadRegBank 1:s_b_7_0 (u32) */
    auto s_b_7_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_7_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_7_6: Select s_b_7_3 ? s_b_7_4 : s_b_7_5 */
    dbt::el::Value *s_b_7_6;
    s_b_7_6 = (s_b_7_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_7_5);
    /* execute.a64:2659 [D] s_b_7_7 = (u64)s_b_7_6 */
    auto s_b_7_7 = emitter.zx(s_b_7_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_7_8: sym_142902_0_return_symbol = s_b_7_7, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_142902_0_return_symbol, s_b_7_7);
    /* ???:4294967295 [F] s_b_7_9: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_6,  */
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
  /* b_6,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2733 [F] s_b_9_0=sym_32679_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_9_2: sym_142953_0_return_symbol = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_142953_0_return_symbol, s_b_9_1);
    /* ???:4294967295 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_13,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_142953_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_142953_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1447 [F] s_b_10_1=sym_32679_3_parameter_inst.immu64 (const) */
    /* execute.a64:1447 [D] s_b_10_2 = s_b_10_0+s_b_10_1 */
    auto s_b_10_2 = emitter.add(s_b_10_0, emitter.const_u64(insn.immu64));
    /* execute.a64:1447 [D] s_b_10_3: sym_32696_0_addr = s_b_10_2, dominates: s_b_1_0 s_b_4_0  */
    emitter.store_local(DV_sym_32696_0_addr, s_b_10_2);
    /* execute.a64:1449 [F] s_b_10_4=sym_32679_3_parameter_inst.size (const) */
    /* execute.a64:1449 [F] s_b_10_5 = (u32)s_b_10_4 (const) */
    /* execute.a64:1449 [F] s_b_10_6 = constant u32 3 (const) */
    /* execute.a64:1449 [F] s_b_10_7 = s_b_10_5==s_b_10_6 (const) */
    uint8_t s_b_10_7 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)3ULL));
    /* execute.a64:1449 [F] s_b_10_8: If s_b_10_7: Jump b_1 else b_3 (const) */
    if (s_b_10_7) 
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
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_11_1: sym_142970_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_142970_1__R_s_b_3_0, s_b_11_0);
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
    /* execute.a64:2731 [D] s_b_13_0 = sym_142970_1__R_s_b_3_0 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_142970_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1: sym_142953_0_return_symbol = s_b_13_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_142953_0_return_symbol, s_b_13_0);
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
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_14_1: sym_142970_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_142970_1__R_s_b_3_0, s_b_14_0);
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
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_15_1: sym_142970_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_142970_1__R_s_b_3_0, s_b_15_0);
    /* execute.a64:2707 [F] s_b_15_2: Jump b_13 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_stxr(const aarch64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_144232_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_144249_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_32931_0_address = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:705 [F] s_b_0_0=sym_32925_3_parameter_inst.rn (const) */
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
    /* execute.a64:708 [F] s_b_1_0 = constant u32 0 (const) */
    /* execute.a64:708 [D] s_b_1_1 = sym_32931_0_address uint64_t */
    auto s_b_1_1 = emitter.load_local(DV_sym_32931_0_address, emitter.context().types().u64());
    /* execute.a64:708 [D] s_b_1_2 = mem_monitor_release */
    auto s_b_1_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_1_1);
    /* execute.a64:708 [D] s_b_1_3: If s_b_1_2: Jump b_4 else b_5 */
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
      emitter.branch(s_b_1_2, true_target, false_target);
    }
    goto fixed_done;
  }
  // BLOCK b_2 not fully fixed
  /* b_10,  */
  fixed_block_b_3: 
  {
    /* execute.a64:715 [F] s_b_3_0 = constant u32 0 (const) */
    /* execute.a64:715 [D] s_b_3_1 = sym_32931_0_address uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_32931_0_address, emitter.context().types().u64());
    /* execute.a64:715 [D] s_b_3_2 = mem_monitor_release */
    auto s_b_3_2 = emitter.call(__captive_mem_monitor_release, emitter.const_u32((uint32_t)0ULL), s_b_3_1);
    /* execute.a64:715 [D] s_b_3_3: If s_b_3_2: Jump b_6 else b_7 */
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
    /* execute.a64:2733 [F] s_b_9_0=sym_32925_3_parameter_inst.rn (const) */
    /* execute.a64:2733 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_9_2: sym_144232_0_return_symbol = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_144232_0_return_symbol, s_b_9_1);
    /* ???:4294967295 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_13,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_144232_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_144232_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:705 [D] s_b_10_1: sym_32931_0_address = s_b_10_0, dominates: s_b_1_1 s_b_4_0 s_b_3_1 s_b_6_0  */
    emitter.store_local(DV_sym_32931_0_address, s_b_10_0);
    /* execute.a64:707 [F] s_b_10_2=sym_32925_3_parameter_inst.size (const) */
    /* execute.a64:707 [F] s_b_10_3 = (u32)s_b_10_2 (const) */
    /* execute.a64:707 [F] s_b_10_4 = constant u32 2 (const) */
    /* execute.a64:707 [F] s_b_10_5 = s_b_10_3==s_b_10_4 (const) */
    uint8_t s_b_10_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:707 [F] s_b_10_6: If s_b_10_5: Jump b_1 else b_3 (const) */
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
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2702 [D] s_b_11_1: sym_144249_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_144249_1__R_s_b_3_0, s_b_11_0);
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
    /* execute.a64:2731 [D] s_b_13_0 = sym_144249_1__R_s_b_3_0 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_144249_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1: sym_144232_0_return_symbol = s_b_13_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_144232_0_return_symbol, s_b_13_0);
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
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_14_0, emitter.const_u8(8));
    }
    /* execute.a64:2705 [D] s_b_14_1: sym_144249_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_144249_1__R_s_b_3_0, s_b_14_0);
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
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_15_0, emitter.const_u8(8));
    }
    /* execute.a64:2707 [D] s_b_15_1: sym_144249_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_144249_1__R_s_b_3_0, s_b_15_0);
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
        /* execute.a64:709 [D] s_b_4_0 = sym_32931_0_address uint64_t */
        auto s_b_4_0 = emitter.load_local(DV_sym_32931_0_address, emitter.context().types().u64());
        /* execute.a64:709 [F] s_b_4_1=sym_32925_3_parameter_inst.rt (const) */
        /* execute.a64:2646 [F] s_b_4_2 = (u32)s_b_4_1 (const) */
        /* execute.a64:2646 [F] s_b_4_3 = constant u32 1f (const) */
        /* execute.a64:2646 [F] s_b_4_4 = s_b_4_2==s_b_4_3 (const) */
        uint8_t s_b_4_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2646 [F] s_b_4_5 = constant u32 0 (const) */
        /* execute.a64:2646 [D] s_b_4_6 = ReadRegBank 1:s_b_4_1 (u32) */
        auto s_b_4_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_4_6,emitter.const_u8(4));
        }
        /* execute.a64:2646 [D] s_b_4_7: Select s_b_4_4 ? s_b_4_5 : s_b_4_6 */
        dbt::el::Value *s_b_4_7;
        s_b_4_7 = (s_b_4_4) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_4_6);
        /* execute.a64:2659 [D] s_b_4_8 = (u64)s_b_4_7 */
        auto s_b_4_8 = emitter.zx(s_b_4_7, emitter.context().types().u64());
        /* execute.a64:1792 [D] s_b_4_9 = (u32)s_b_4_8 */
        auto s_b_4_9 = emitter.truncate(s_b_4_8, emitter.context().types().u32());
        /* ???:4294967295 [D] s_b_4_10: Store 4 s_b_4_0 <= s_b_4_9 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_4_0, s_b_4_9, emitter.const_u8(4));
        }
        emitter.store_memory(s_b_4_0, s_b_4_9);
        /* execute.a64:710 [F] s_b_4_11=sym_32925_3_parameter_inst.rs (const) */
        /* execute.a64:2674 [F] s_b_4_12 = (u32)s_b_4_11 (const) */
        /* execute.a64:2674 [F] s_b_4_13 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_4_14 = s_b_4_12==s_b_4_13 (const) */
        uint8_t s_b_4_14 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_4_15: If s_b_4_14: Jump b_2 else b_18 (const) */
        if (s_b_4_14) 
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
        /* execute.a64:712 [F] s_b_5_0=sym_32925_3_parameter_inst.rs (const) */
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
        /* execute.a64:716 [D] s_b_6_0 = sym_32931_0_address uint64_t */
        auto s_b_6_0 = emitter.load_local(DV_sym_32931_0_address, emitter.context().types().u64());
        /* execute.a64:716 [F] s_b_6_1=sym_32925_3_parameter_inst.rt (const) */
        /* execute.a64:2651 [F] s_b_6_2 = (u32)s_b_6_1 (const) */
        /* execute.a64:2651 [F] s_b_6_3 = constant u32 1f (const) */
        /* execute.a64:2651 [F] s_b_6_4 = s_b_6_2==s_b_6_3 (const) */
        uint8_t s_b_6_4 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
        /* execute.a64:2651 [F] s_b_6_5 = constant u64 0 (const) */
        /* execute.a64:2651 [D] s_b_6_6 = ReadRegBank 0:s_b_6_1 (u64) */
        auto s_b_6_6 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_6_6,emitter.const_u8(8));
        }
        /* execute.a64:2651 [D] s_b_6_7: Select s_b_6_4 ? s_b_6_5 : s_b_6_6 */
        dbt::el::Value *s_b_6_7;
        s_b_6_7 = (s_b_6_4) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_6_6);
        /* ???:4294967295 [D] s_b_6_8: Store 8 s_b_6_0 <= s_b_6_7 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_MEMORY, s_b_6_0, s_b_6_7, emitter.const_u8(8));
        }
        emitter.store_memory(s_b_6_0, s_b_6_7);
        /* execute.a64:717 [F] s_b_6_9=sym_32925_3_parameter_inst.rs (const) */
        /* execute.a64:2674 [F] s_b_6_10 = (u32)s_b_6_9 (const) */
        /* execute.a64:2674 [F] s_b_6_11 = constant u32 1f (const) */
        /* execute.a64:2674 [F] s_b_6_12 = s_b_6_10==s_b_6_11 (const) */
        uint8_t s_b_6_12 = ((uint8_t)(((uint32_t)insn.rs) == (uint32_t)31ULL));
        /* execute.a64:2674 [F] s_b_6_13: If s_b_6_12: Jump b_2 else b_19 (const) */
        if (s_b_6_12) 
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
        /* execute.a64:719 [F] s_b_7_0=sym_32925_3_parameter_inst.rs (const) */
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
        /* execute.a64:2676 [F] s_b_16_0=sym_32925_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_16_1 = constant u64 1 (const) */
        /* execute.a64:2676 [F] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
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
        /* execute.a64:2676 [F] s_b_17_0=sym_32925_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_17_1 = constant u64 1 (const) */
        /* execute.a64:2676 [F] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)1ULL),emitter.const_u8(8));
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
        /* execute.a64:2676 [F] s_b_18_0=sym_32925_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_18_1 = constant u64 0 (const) */
        /* execute.a64:2676 [F] s_b_18_2: WriteRegBank 0:s_b_18_0 = s_b_18_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
        /* execute.a64:2676 [F] s_b_19_0=sym_32925_3_parameter_inst.rs (const) */
        /* execute.a64:2676 [F] s_b_19_1 = constant u64 0 (const) */
        /* execute.a64:2676 [F] s_b_19_2: WriteRegBank 0:s_b_19_0 = s_b_19_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rs))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_tbl(const aarch64_decode_a64_SIMD_TABLE_LOOKUP&insn, captive::arch::dbt::el::Emitter& emitter)
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
  auto DV_sym_33605_0_rm = emitter.alloc_local(emitter.context().types().u8(), true);
  auto DV_sym_34102_0_rm = emitter.alloc_local(emitter.context().types().u8(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3757 [F] s_b_0_0=sym_33582_3_parameter_inst.Q (const) */
    /* execute.simd:3757 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:3757 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:3757 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:3757 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:3759 [F] s_b_1_0=sym_33582_3_parameter_inst.rm (const) */
    /* execute.simd:3759 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:3759 [F] s_b_1_2 = constant u32 10 (const) */
    /* execute.simd:3759 [F] s_b_1_3 = s_b_1_1*s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
    /* execute.simd:3759 [F] s_b_1_4 = constant u32 0 (const) */
    /* execute.simd:3759 [F] s_b_1_5 = s_b_1_3+s_b_1_4 (const) */
    uint32_t s_b_1_5 = ((uint32_t)(s_b_1_3 + (uint32_t)0ULL));
    /* execute.simd:3759 [D] s_b_1_6 = ReadRegBank 23:s_b_1_5 (u8) */
    auto s_b_1_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_1_5))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_1_5))),s_b_1_6,emitter.const_u8(1));
    }
    /* execute.simd:3759 [D] s_b_1_7: sym_33605_0_rm = s_b_1_6, dominates: s_b_4_10  */
    emitter.store_local(DV_sym_33605_0_rm, s_b_1_6);
    /* execute.simd:3761 [F] s_b_1_8=sym_33582_3_parameter_inst.len (const) */
    /* execute.simd:3761 [F] s_b_1_9 = (u32)s_b_1_8 (const) */
    /* execute.simd:3761 [F] s_b_1_10 = constant u32 1 (const) */
    /* execute.simd:3761 [F] s_b_1_11 = s_b_1_9+s_b_1_10 (const) */
    uint32_t s_b_1_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
    /* execute.simd:3761 [F] s_b_1_12 = constant u32 10 (const) */
    /* execute.simd:3761 [F] s_b_1_13 = s_b_1_12*s_b_1_11 (const) */
    uint32_t s_b_1_13 = ((uint32_t)((uint32_t)16ULL * s_b_1_11));
    /* execute.simd:3761 [D] s_b_1_14 = (u32)s_b_1_6 */
    auto s_b_1_14 = emitter.zx(s_b_1_6, emitter.context().types().u32());
    /* execute.simd:3761 [D] s_b_1_15 = s_b_1_14<s_b_1_13 */
    auto s_b_1_15 = emitter.cmp_lt(s_b_1_14, emitter.const_u32(s_b_1_13));
    /* execute.simd:3761 [D] s_b_1_16: If s_b_1_15: Jump b_4 else b_6 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_4;
        dynamic_block_queue.push(block_b_4);
        true_target = block;
      }
      dbt::el::Block *false_target;
      {
        auto block = block_b_6;
        dynamic_block_queue.push(block_b_6);
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
    /* execute.simd:3771 [F] s_b_3_0=sym_33582_3_parameter_inst.rm (const) */
    /* execute.simd:3771 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:3771 [F] s_b_3_2 = constant u32 10 (const) */
    /* execute.simd:3771 [F] s_b_3_3 = s_b_3_1*s_b_3_2 (const) */
    uint32_t s_b_3_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
    /* execute.simd:3771 [F] s_b_3_4 = constant u32 0 (const) */
    /* execute.simd:3771 [F] s_b_3_5 = s_b_3_3+s_b_3_4 (const) */
    uint32_t s_b_3_5 = ((uint32_t)(s_b_3_3 + (uint32_t)0ULL));
    /* execute.simd:3771 [D] s_b_3_6 = ReadRegBank 23:s_b_3_5 (u8) */
    auto s_b_3_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_3_5))), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_3_5))),s_b_3_6,emitter.const_u8(1));
    }
    /* execute.simd:3771 [D] s_b_3_7: sym_34102_0_rm = s_b_3_6, dominates: s_b_28_10  */
    emitter.store_local(DV_sym_34102_0_rm, s_b_3_6);
    /* execute.simd:3773 [F] s_b_3_8=sym_33582_3_parameter_inst.len (const) */
    /* execute.simd:3773 [F] s_b_3_9 = (u32)s_b_3_8 (const) */
    /* execute.simd:3773 [F] s_b_3_10 = constant u32 1 (const) */
    /* execute.simd:3773 [F] s_b_3_11 = s_b_3_9+s_b_3_10 (const) */
    uint32_t s_b_3_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
    /* execute.simd:3773 [F] s_b_3_12 = constant u32 10 (const) */
    /* execute.simd:3773 [F] s_b_3_13 = s_b_3_12*s_b_3_11 (const) */
    uint32_t s_b_3_13 = ((uint32_t)((uint32_t)16ULL * s_b_3_11));
    /* execute.simd:3773 [D] s_b_3_14 = (u32)s_b_3_6 */
    auto s_b_3_14 = emitter.zx(s_b_3_6, emitter.context().types().u32());
    /* execute.simd:3773 [D] s_b_3_15 = s_b_3_14<s_b_3_13 */
    auto s_b_3_15 = emitter.cmp_lt(s_b_3_14, emitter.const_u32(s_b_3_13));
    /* execute.simd:3773 [D] s_b_3_16: If s_b_3_15: Jump b_28 else b_30 */
    {
      dbt::el::Block *true_target;
      {
        auto block = block_b_28;
        dynamic_block_queue.push(block_b_28);
        true_target = block;
      }
      dbt::el::Block *false_target;
      {
        auto block = block_b_30;
        dynamic_block_queue.push(block_b_30);
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
        /* execute.simd:3762 [F] s_b_4_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3762 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
        /* execute.simd:3762 [F] s_b_4_2 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_4_3 = s_b_4_1*s_b_4_2 (const) */
        uint32_t s_b_4_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3762 [F] s_b_4_4 = constant u32 0 (const) */
        /* execute.simd:3762 [F] s_b_4_5 = s_b_4_3+s_b_4_4 (const) */
        uint32_t s_b_4_5 = ((uint32_t)(s_b_4_3 + (uint32_t)0ULL));
        /* execute.simd:3762 [F] s_b_4_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3762 [F] s_b_4_7 = (u32)s_b_4_6 (const) */
        /* execute.simd:3762 [F] s_b_4_8 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_4_9 = s_b_4_7*s_b_4_8 (const) */
        uint32_t s_b_4_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3762 [D] s_b_4_10 = sym_33605_0_rm uint8_t */
        auto s_b_4_10 = emitter.load_local(DV_sym_33605_0_rm, emitter.context().types().u8());
        /* execute.simd:3762 [D] s_b_4_11 = (u32)s_b_4_10 */
        auto s_b_4_11 = emitter.zx(s_b_4_10, emitter.context().types().u32());
        /* execute.simd:3762 [D] s_b_4_12 = s_b_4_9+s_b_4_11 */
        auto s_b_4_12 = emitter.add(emitter.const_u32(s_b_4_9), s_b_4_11);
        /* execute.simd:3762 [D] s_b_4_13 = ReadRegBank 23:s_b_4_12 (u8) */
        dbt::el::Value *s_b_4_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_4_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_4_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3762 [D] s_b_4_14: WriteRegBank 23:s_b_4_5 = s_b_4_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_4_5))),s_b_4_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_4_5))),s_b_4_13);
        /* execute.simd:3762 [F] s_b_4_15: Jump b_5 (const) */
        {
          auto block = block_b_5;
          dynamic_block_queue.push(block_b_5);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_5) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_5);
        /* execute.simd:3759 [F] s_b_5_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3759 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
        /* execute.simd:3759 [F] s_b_5_2 = constant u32 10 (const) */
        /* execute.simd:3759 [F] s_b_5_3 = s_b_5_1*s_b_5_2 (const) */
        uint32_t s_b_5_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3759 [F] s_b_5_4 = constant u32 1 (const) */
        /* execute.simd:3759 [F] s_b_5_5 = s_b_5_3+s_b_5_4 (const) */
        uint32_t s_b_5_5 = ((uint32_t)(s_b_5_3 + (uint32_t)1ULL));
        /* execute.simd:3759 [D] s_b_5_6 = ReadRegBank 23:s_b_5_5 (u8) */
        auto s_b_5_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_5_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_5_5))),s_b_5_6,emitter.const_u8(1));
        }
        /* execute.simd:3759 [D] s_b_5_7: sym_33605_0_rm = s_b_5_6, dominates: s_b_7_10  */
        emitter.store_local(DV_sym_33605_0_rm, s_b_5_6);
        /* execute.simd:3761 [F] s_b_5_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3761 [F] s_b_5_9 = (u32)s_b_5_8 (const) */
        /* execute.simd:3761 [F] s_b_5_10 = constant u32 1 (const) */
        /* execute.simd:3761 [F] s_b_5_11 = s_b_5_9+s_b_5_10 (const) */
        uint32_t s_b_5_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3761 [F] s_b_5_12 = constant u32 10 (const) */
        /* execute.simd:3761 [F] s_b_5_13 = s_b_5_12*s_b_5_11 (const) */
        uint32_t s_b_5_13 = ((uint32_t)((uint32_t)16ULL * s_b_5_11));
        /* execute.simd:3761 [D] s_b_5_14 = (u32)s_b_5_6 */
        auto s_b_5_14 = emitter.zx(s_b_5_6, emitter.context().types().u32());
        /* execute.simd:3761 [D] s_b_5_15 = s_b_5_14<s_b_5_13 */
        auto s_b_5_15 = emitter.cmp_lt(s_b_5_14, emitter.const_u32(s_b_5_13));
        /* execute.simd:3761 [D] s_b_5_16: If s_b_5_15: Jump b_7 else b_9 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_7;
            dynamic_block_queue.push(block_b_7);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_9;
            dynamic_block_queue.push(block_b_9);
            false_target = block;
          }
          emitter.branch(s_b_5_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_6) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_6);
        /* execute.simd:3764 [F] s_b_6_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3764 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
        /* execute.simd:3764 [F] s_b_6_2 = constant u32 10 (const) */
        /* execute.simd:3764 [F] s_b_6_3 = s_b_6_1*s_b_6_2 (const) */
        uint32_t s_b_6_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3764 [F] s_b_6_4 = constant u32 0 (const) */
        /* execute.simd:3764 [F] s_b_6_5 = s_b_6_3+s_b_6_4 (const) */
        uint32_t s_b_6_5 = ((uint32_t)(s_b_6_3 + (uint32_t)0ULL));
        /* execute.simd:3764 [F] s_b_6_6 = constant u8 0 (const) */
        /* execute.simd:3764 [F] s_b_6_7: WriteRegBank 23:s_b_6_5 = s_b_6_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_6_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_6_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3764 [F] s_b_6_8: Jump b_5 (const) */
        {
          auto block = block_b_5;
          dynamic_block_queue.push(block_b_5);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_7) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_7);
        /* execute.simd:3762 [F] s_b_7_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3762 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
        /* execute.simd:3762 [F] s_b_7_2 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_7_3 = s_b_7_1*s_b_7_2 (const) */
        uint32_t s_b_7_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3762 [F] s_b_7_4 = constant u32 1 (const) */
        /* execute.simd:3762 [F] s_b_7_5 = s_b_7_3+s_b_7_4 (const) */
        uint32_t s_b_7_5 = ((uint32_t)(s_b_7_3 + (uint32_t)1ULL));
        /* execute.simd:3762 [F] s_b_7_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3762 [F] s_b_7_7 = (u32)s_b_7_6 (const) */
        /* execute.simd:3762 [F] s_b_7_8 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_7_9 = s_b_7_7*s_b_7_8 (const) */
        uint32_t s_b_7_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3762 [D] s_b_7_10 = sym_33605_0_rm uint8_t */
        auto s_b_7_10 = emitter.load_local(DV_sym_33605_0_rm, emitter.context().types().u8());
        /* execute.simd:3762 [D] s_b_7_11 = (u32)s_b_7_10 */
        auto s_b_7_11 = emitter.zx(s_b_7_10, emitter.context().types().u32());
        /* execute.simd:3762 [D] s_b_7_12 = s_b_7_9+s_b_7_11 */
        auto s_b_7_12 = emitter.add(emitter.const_u32(s_b_7_9), s_b_7_11);
        /* execute.simd:3762 [D] s_b_7_13 = ReadRegBank 23:s_b_7_12 (u8) */
        dbt::el::Value *s_b_7_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_7_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_7_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3762 [D] s_b_7_14: WriteRegBank 23:s_b_7_5 = s_b_7_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_7_5))),s_b_7_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_7_5))),s_b_7_13);
        /* execute.simd:3762 [F] s_b_7_15: Jump b_8 (const) */
        {
          auto block = block_b_8;
          dynamic_block_queue.push(block_b_8);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_8) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_8);
        /* execute.simd:3759 [F] s_b_8_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3759 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
        /* execute.simd:3759 [F] s_b_8_2 = constant u32 10 (const) */
        /* execute.simd:3759 [F] s_b_8_3 = s_b_8_1*s_b_8_2 (const) */
        uint32_t s_b_8_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3759 [F] s_b_8_4 = constant u32 2 (const) */
        /* execute.simd:3759 [F] s_b_8_5 = s_b_8_3+s_b_8_4 (const) */
        uint32_t s_b_8_5 = ((uint32_t)(s_b_8_3 + (uint32_t)2ULL));
        /* execute.simd:3759 [D] s_b_8_6 = ReadRegBank 23:s_b_8_5 (u8) */
        auto s_b_8_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_8_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_8_5))),s_b_8_6,emitter.const_u8(1));
        }
        /* execute.simd:3759 [D] s_b_8_7: sym_33605_0_rm = s_b_8_6, dominates: s_b_10_10  */
        emitter.store_local(DV_sym_33605_0_rm, s_b_8_6);
        /* execute.simd:3761 [F] s_b_8_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3761 [F] s_b_8_9 = (u32)s_b_8_8 (const) */
        /* execute.simd:3761 [F] s_b_8_10 = constant u32 1 (const) */
        /* execute.simd:3761 [F] s_b_8_11 = s_b_8_9+s_b_8_10 (const) */
        uint32_t s_b_8_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3761 [F] s_b_8_12 = constant u32 10 (const) */
        /* execute.simd:3761 [F] s_b_8_13 = s_b_8_12*s_b_8_11 (const) */
        uint32_t s_b_8_13 = ((uint32_t)((uint32_t)16ULL * s_b_8_11));
        /* execute.simd:3761 [D] s_b_8_14 = (u32)s_b_8_6 */
        auto s_b_8_14 = emitter.zx(s_b_8_6, emitter.context().types().u32());
        /* execute.simd:3761 [D] s_b_8_15 = s_b_8_14<s_b_8_13 */
        auto s_b_8_15 = emitter.cmp_lt(s_b_8_14, emitter.const_u32(s_b_8_13));
        /* execute.simd:3761 [D] s_b_8_16: If s_b_8_15: Jump b_10 else b_12 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_10;
            dynamic_block_queue.push(block_b_10);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_12;
            dynamic_block_queue.push(block_b_12);
            false_target = block;
          }
          emitter.branch(s_b_8_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_9) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_9);
        /* execute.simd:3764 [F] s_b_9_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3764 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
        /* execute.simd:3764 [F] s_b_9_2 = constant u32 10 (const) */
        /* execute.simd:3764 [F] s_b_9_3 = s_b_9_1*s_b_9_2 (const) */
        uint32_t s_b_9_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3764 [F] s_b_9_4 = constant u32 1 (const) */
        /* execute.simd:3764 [F] s_b_9_5 = s_b_9_3+s_b_9_4 (const) */
        uint32_t s_b_9_5 = ((uint32_t)(s_b_9_3 + (uint32_t)1ULL));
        /* execute.simd:3764 [F] s_b_9_6 = constant u8 0 (const) */
        /* execute.simd:3764 [F] s_b_9_7: WriteRegBank 23:s_b_9_5 = s_b_9_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_9_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_9_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3764 [F] s_b_9_8: Jump b_8 (const) */
        {
          auto block = block_b_8;
          dynamic_block_queue.push(block_b_8);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_10) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_10);
        /* execute.simd:3762 [F] s_b_10_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3762 [F] s_b_10_1 = (u32)s_b_10_0 (const) */
        /* execute.simd:3762 [F] s_b_10_2 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_10_3 = s_b_10_1*s_b_10_2 (const) */
        uint32_t s_b_10_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3762 [F] s_b_10_4 = constant u32 2 (const) */
        /* execute.simd:3762 [F] s_b_10_5 = s_b_10_3+s_b_10_4 (const) */
        uint32_t s_b_10_5 = ((uint32_t)(s_b_10_3 + (uint32_t)2ULL));
        /* execute.simd:3762 [F] s_b_10_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3762 [F] s_b_10_7 = (u32)s_b_10_6 (const) */
        /* execute.simd:3762 [F] s_b_10_8 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_10_9 = s_b_10_7*s_b_10_8 (const) */
        uint32_t s_b_10_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3762 [D] s_b_10_10 = sym_33605_0_rm uint8_t */
        auto s_b_10_10 = emitter.load_local(DV_sym_33605_0_rm, emitter.context().types().u8());
        /* execute.simd:3762 [D] s_b_10_11 = (u32)s_b_10_10 */
        auto s_b_10_11 = emitter.zx(s_b_10_10, emitter.context().types().u32());
        /* execute.simd:3762 [D] s_b_10_12 = s_b_10_9+s_b_10_11 */
        auto s_b_10_12 = emitter.add(emitter.const_u32(s_b_10_9), s_b_10_11);
        /* execute.simd:3762 [D] s_b_10_13 = ReadRegBank 23:s_b_10_12 (u8) */
        dbt::el::Value *s_b_10_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_10_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_10_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3762 [D] s_b_10_14: WriteRegBank 23:s_b_10_5 = s_b_10_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_10_5))),s_b_10_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_10_5))),s_b_10_13);
        /* execute.simd:3762 [F] s_b_10_15: Jump b_11 (const) */
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_11) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_11);
        /* execute.simd:3759 [F] s_b_11_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3759 [F] s_b_11_1 = (u32)s_b_11_0 (const) */
        /* execute.simd:3759 [F] s_b_11_2 = constant u32 10 (const) */
        /* execute.simd:3759 [F] s_b_11_3 = s_b_11_1*s_b_11_2 (const) */
        uint32_t s_b_11_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3759 [F] s_b_11_4 = constant u32 3 (const) */
        /* execute.simd:3759 [F] s_b_11_5 = s_b_11_3+s_b_11_4 (const) */
        uint32_t s_b_11_5 = ((uint32_t)(s_b_11_3 + (uint32_t)3ULL));
        /* execute.simd:3759 [D] s_b_11_6 = ReadRegBank 23:s_b_11_5 (u8) */
        auto s_b_11_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_11_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_11_5))),s_b_11_6,emitter.const_u8(1));
        }
        /* execute.simd:3759 [D] s_b_11_7: sym_33605_0_rm = s_b_11_6, dominates: s_b_13_10  */
        emitter.store_local(DV_sym_33605_0_rm, s_b_11_6);
        /* execute.simd:3761 [F] s_b_11_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3761 [F] s_b_11_9 = (u32)s_b_11_8 (const) */
        /* execute.simd:3761 [F] s_b_11_10 = constant u32 1 (const) */
        /* execute.simd:3761 [F] s_b_11_11 = s_b_11_9+s_b_11_10 (const) */
        uint32_t s_b_11_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3761 [F] s_b_11_12 = constant u32 10 (const) */
        /* execute.simd:3761 [F] s_b_11_13 = s_b_11_12*s_b_11_11 (const) */
        uint32_t s_b_11_13 = ((uint32_t)((uint32_t)16ULL * s_b_11_11));
        /* execute.simd:3761 [D] s_b_11_14 = (u32)s_b_11_6 */
        auto s_b_11_14 = emitter.zx(s_b_11_6, emitter.context().types().u32());
        /* execute.simd:3761 [D] s_b_11_15 = s_b_11_14<s_b_11_13 */
        auto s_b_11_15 = emitter.cmp_lt(s_b_11_14, emitter.const_u32(s_b_11_13));
        /* execute.simd:3761 [D] s_b_11_16: If s_b_11_15: Jump b_13 else b_15 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_13;
            dynamic_block_queue.push(block_b_13);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_15;
            dynamic_block_queue.push(block_b_15);
            false_target = block;
          }
          emitter.branch(s_b_11_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_12) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_12);
        /* execute.simd:3764 [F] s_b_12_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3764 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
        /* execute.simd:3764 [F] s_b_12_2 = constant u32 10 (const) */
        /* execute.simd:3764 [F] s_b_12_3 = s_b_12_1*s_b_12_2 (const) */
        uint32_t s_b_12_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3764 [F] s_b_12_4 = constant u32 2 (const) */
        /* execute.simd:3764 [F] s_b_12_5 = s_b_12_3+s_b_12_4 (const) */
        uint32_t s_b_12_5 = ((uint32_t)(s_b_12_3 + (uint32_t)2ULL));
        /* execute.simd:3764 [F] s_b_12_6 = constant u8 0 (const) */
        /* execute.simd:3764 [F] s_b_12_7: WriteRegBank 23:s_b_12_5 = s_b_12_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_12_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_12_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3764 [F] s_b_12_8: Jump b_11 (const) */
        {
          auto block = block_b_11;
          dynamic_block_queue.push(block_b_11);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_13) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_13);
        /* execute.simd:3762 [F] s_b_13_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3762 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
        /* execute.simd:3762 [F] s_b_13_2 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_13_3 = s_b_13_1*s_b_13_2 (const) */
        uint32_t s_b_13_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3762 [F] s_b_13_4 = constant u32 3 (const) */
        /* execute.simd:3762 [F] s_b_13_5 = s_b_13_3+s_b_13_4 (const) */
        uint32_t s_b_13_5 = ((uint32_t)(s_b_13_3 + (uint32_t)3ULL));
        /* execute.simd:3762 [F] s_b_13_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3762 [F] s_b_13_7 = (u32)s_b_13_6 (const) */
        /* execute.simd:3762 [F] s_b_13_8 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_13_9 = s_b_13_7*s_b_13_8 (const) */
        uint32_t s_b_13_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3762 [D] s_b_13_10 = sym_33605_0_rm uint8_t */
        auto s_b_13_10 = emitter.load_local(DV_sym_33605_0_rm, emitter.context().types().u8());
        /* execute.simd:3762 [D] s_b_13_11 = (u32)s_b_13_10 */
        auto s_b_13_11 = emitter.zx(s_b_13_10, emitter.context().types().u32());
        /* execute.simd:3762 [D] s_b_13_12 = s_b_13_9+s_b_13_11 */
        auto s_b_13_12 = emitter.add(emitter.const_u32(s_b_13_9), s_b_13_11);
        /* execute.simd:3762 [D] s_b_13_13 = ReadRegBank 23:s_b_13_12 (u8) */
        dbt::el::Value *s_b_13_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_13_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_13_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3762 [D] s_b_13_14: WriteRegBank 23:s_b_13_5 = s_b_13_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_13_5))),s_b_13_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_13_5))),s_b_13_13);
        /* execute.simd:3762 [F] s_b_13_15: Jump b_14 (const) */
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_14) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_14);
        /* execute.simd:3759 [F] s_b_14_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3759 [F] s_b_14_1 = (u32)s_b_14_0 (const) */
        /* execute.simd:3759 [F] s_b_14_2 = constant u32 10 (const) */
        /* execute.simd:3759 [F] s_b_14_3 = s_b_14_1*s_b_14_2 (const) */
        uint32_t s_b_14_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3759 [F] s_b_14_4 = constant u32 4 (const) */
        /* execute.simd:3759 [F] s_b_14_5 = s_b_14_3+s_b_14_4 (const) */
        uint32_t s_b_14_5 = ((uint32_t)(s_b_14_3 + (uint32_t)4ULL));
        /* execute.simd:3759 [D] s_b_14_6 = ReadRegBank 23:s_b_14_5 (u8) */
        auto s_b_14_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_14_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_14_5))),s_b_14_6,emitter.const_u8(1));
        }
        /* execute.simd:3759 [D] s_b_14_7: sym_33605_0_rm = s_b_14_6, dominates: s_b_16_10  */
        emitter.store_local(DV_sym_33605_0_rm, s_b_14_6);
        /* execute.simd:3761 [F] s_b_14_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3761 [F] s_b_14_9 = (u32)s_b_14_8 (const) */
        /* execute.simd:3761 [F] s_b_14_10 = constant u32 1 (const) */
        /* execute.simd:3761 [F] s_b_14_11 = s_b_14_9+s_b_14_10 (const) */
        uint32_t s_b_14_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3761 [F] s_b_14_12 = constant u32 10 (const) */
        /* execute.simd:3761 [F] s_b_14_13 = s_b_14_12*s_b_14_11 (const) */
        uint32_t s_b_14_13 = ((uint32_t)((uint32_t)16ULL * s_b_14_11));
        /* execute.simd:3761 [D] s_b_14_14 = (u32)s_b_14_6 */
        auto s_b_14_14 = emitter.zx(s_b_14_6, emitter.context().types().u32());
        /* execute.simd:3761 [D] s_b_14_15 = s_b_14_14<s_b_14_13 */
        auto s_b_14_15 = emitter.cmp_lt(s_b_14_14, emitter.const_u32(s_b_14_13));
        /* execute.simd:3761 [D] s_b_14_16: If s_b_14_15: Jump b_16 else b_18 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_16;
            dynamic_block_queue.push(block_b_16);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_18;
            dynamic_block_queue.push(block_b_18);
            false_target = block;
          }
          emitter.branch(s_b_14_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_15) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_15);
        /* execute.simd:3764 [F] s_b_15_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3764 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
        /* execute.simd:3764 [F] s_b_15_2 = constant u32 10 (const) */
        /* execute.simd:3764 [F] s_b_15_3 = s_b_15_1*s_b_15_2 (const) */
        uint32_t s_b_15_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3764 [F] s_b_15_4 = constant u32 3 (const) */
        /* execute.simd:3764 [F] s_b_15_5 = s_b_15_3+s_b_15_4 (const) */
        uint32_t s_b_15_5 = ((uint32_t)(s_b_15_3 + (uint32_t)3ULL));
        /* execute.simd:3764 [F] s_b_15_6 = constant u8 0 (const) */
        /* execute.simd:3764 [F] s_b_15_7: WriteRegBank 23:s_b_15_5 = s_b_15_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_15_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_15_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3764 [F] s_b_15_8: Jump b_14 (const) */
        {
          auto block = block_b_14;
          dynamic_block_queue.push(block_b_14);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_16) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_16);
        /* execute.simd:3762 [F] s_b_16_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3762 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
        /* execute.simd:3762 [F] s_b_16_2 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_16_3 = s_b_16_1*s_b_16_2 (const) */
        uint32_t s_b_16_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3762 [F] s_b_16_4 = constant u32 4 (const) */
        /* execute.simd:3762 [F] s_b_16_5 = s_b_16_3+s_b_16_4 (const) */
        uint32_t s_b_16_5 = ((uint32_t)(s_b_16_3 + (uint32_t)4ULL));
        /* execute.simd:3762 [F] s_b_16_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3762 [F] s_b_16_7 = (u32)s_b_16_6 (const) */
        /* execute.simd:3762 [F] s_b_16_8 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_16_9 = s_b_16_7*s_b_16_8 (const) */
        uint32_t s_b_16_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3762 [D] s_b_16_10 = sym_33605_0_rm uint8_t */
        auto s_b_16_10 = emitter.load_local(DV_sym_33605_0_rm, emitter.context().types().u8());
        /* execute.simd:3762 [D] s_b_16_11 = (u32)s_b_16_10 */
        auto s_b_16_11 = emitter.zx(s_b_16_10, emitter.context().types().u32());
        /* execute.simd:3762 [D] s_b_16_12 = s_b_16_9+s_b_16_11 */
        auto s_b_16_12 = emitter.add(emitter.const_u32(s_b_16_9), s_b_16_11);
        /* execute.simd:3762 [D] s_b_16_13 = ReadRegBank 23:s_b_16_12 (u8) */
        dbt::el::Value *s_b_16_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_16_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_16_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3762 [D] s_b_16_14: WriteRegBank 23:s_b_16_5 = s_b_16_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_16_5))),s_b_16_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_16_5))),s_b_16_13);
        /* execute.simd:3762 [F] s_b_16_15: Jump b_17 (const) */
        {
          auto block = block_b_17;
          dynamic_block_queue.push(block_b_17);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_17) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_17);
        /* execute.simd:3759 [F] s_b_17_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3759 [F] s_b_17_1 = (u32)s_b_17_0 (const) */
        /* execute.simd:3759 [F] s_b_17_2 = constant u32 10 (const) */
        /* execute.simd:3759 [F] s_b_17_3 = s_b_17_1*s_b_17_2 (const) */
        uint32_t s_b_17_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3759 [F] s_b_17_4 = constant u32 5 (const) */
        /* execute.simd:3759 [F] s_b_17_5 = s_b_17_3+s_b_17_4 (const) */
        uint32_t s_b_17_5 = ((uint32_t)(s_b_17_3 + (uint32_t)5ULL));
        /* execute.simd:3759 [D] s_b_17_6 = ReadRegBank 23:s_b_17_5 (u8) */
        auto s_b_17_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_17_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_17_5))),s_b_17_6,emitter.const_u8(1));
        }
        /* execute.simd:3759 [D] s_b_17_7: sym_33605_0_rm = s_b_17_6, dominates: s_b_19_10  */
        emitter.store_local(DV_sym_33605_0_rm, s_b_17_6);
        /* execute.simd:3761 [F] s_b_17_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3761 [F] s_b_17_9 = (u32)s_b_17_8 (const) */
        /* execute.simd:3761 [F] s_b_17_10 = constant u32 1 (const) */
        /* execute.simd:3761 [F] s_b_17_11 = s_b_17_9+s_b_17_10 (const) */
        uint32_t s_b_17_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3761 [F] s_b_17_12 = constant u32 10 (const) */
        /* execute.simd:3761 [F] s_b_17_13 = s_b_17_12*s_b_17_11 (const) */
        uint32_t s_b_17_13 = ((uint32_t)((uint32_t)16ULL * s_b_17_11));
        /* execute.simd:3761 [D] s_b_17_14 = (u32)s_b_17_6 */
        auto s_b_17_14 = emitter.zx(s_b_17_6, emitter.context().types().u32());
        /* execute.simd:3761 [D] s_b_17_15 = s_b_17_14<s_b_17_13 */
        auto s_b_17_15 = emitter.cmp_lt(s_b_17_14, emitter.const_u32(s_b_17_13));
        /* execute.simd:3761 [D] s_b_17_16: If s_b_17_15: Jump b_19 else b_21 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_19;
            dynamic_block_queue.push(block_b_19);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_21;
            dynamic_block_queue.push(block_b_21);
            false_target = block;
          }
          emitter.branch(s_b_17_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_18) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_18);
        /* execute.simd:3764 [F] s_b_18_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3764 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
        /* execute.simd:3764 [F] s_b_18_2 = constant u32 10 (const) */
        /* execute.simd:3764 [F] s_b_18_3 = s_b_18_1*s_b_18_2 (const) */
        uint32_t s_b_18_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3764 [F] s_b_18_4 = constant u32 4 (const) */
        /* execute.simd:3764 [F] s_b_18_5 = s_b_18_3+s_b_18_4 (const) */
        uint32_t s_b_18_5 = ((uint32_t)(s_b_18_3 + (uint32_t)4ULL));
        /* execute.simd:3764 [F] s_b_18_6 = constant u8 0 (const) */
        /* execute.simd:3764 [F] s_b_18_7: WriteRegBank 23:s_b_18_5 = s_b_18_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_18_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_18_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3764 [F] s_b_18_8: Jump b_17 (const) */
        {
          auto block = block_b_17;
          dynamic_block_queue.push(block_b_17);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_19) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_19);
        /* execute.simd:3762 [F] s_b_19_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3762 [F] s_b_19_1 = (u32)s_b_19_0 (const) */
        /* execute.simd:3762 [F] s_b_19_2 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_19_3 = s_b_19_1*s_b_19_2 (const) */
        uint32_t s_b_19_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3762 [F] s_b_19_4 = constant u32 5 (const) */
        /* execute.simd:3762 [F] s_b_19_5 = s_b_19_3+s_b_19_4 (const) */
        uint32_t s_b_19_5 = ((uint32_t)(s_b_19_3 + (uint32_t)5ULL));
        /* execute.simd:3762 [F] s_b_19_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3762 [F] s_b_19_7 = (u32)s_b_19_6 (const) */
        /* execute.simd:3762 [F] s_b_19_8 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_19_9 = s_b_19_7*s_b_19_8 (const) */
        uint32_t s_b_19_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3762 [D] s_b_19_10 = sym_33605_0_rm uint8_t */
        auto s_b_19_10 = emitter.load_local(DV_sym_33605_0_rm, emitter.context().types().u8());
        /* execute.simd:3762 [D] s_b_19_11 = (u32)s_b_19_10 */
        auto s_b_19_11 = emitter.zx(s_b_19_10, emitter.context().types().u32());
        /* execute.simd:3762 [D] s_b_19_12 = s_b_19_9+s_b_19_11 */
        auto s_b_19_12 = emitter.add(emitter.const_u32(s_b_19_9), s_b_19_11);
        /* execute.simd:3762 [D] s_b_19_13 = ReadRegBank 23:s_b_19_12 (u8) */
        dbt::el::Value *s_b_19_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_19_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_19_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3762 [D] s_b_19_14: WriteRegBank 23:s_b_19_5 = s_b_19_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_19_5))),s_b_19_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_19_5))),s_b_19_13);
        /* execute.simd:3762 [F] s_b_19_15: Jump b_20 (const) */
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_20) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_20);
        /* execute.simd:3759 [F] s_b_20_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3759 [F] s_b_20_1 = (u32)s_b_20_0 (const) */
        /* execute.simd:3759 [F] s_b_20_2 = constant u32 10 (const) */
        /* execute.simd:3759 [F] s_b_20_3 = s_b_20_1*s_b_20_2 (const) */
        uint32_t s_b_20_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3759 [F] s_b_20_4 = constant u32 6 (const) */
        /* execute.simd:3759 [F] s_b_20_5 = s_b_20_3+s_b_20_4 (const) */
        uint32_t s_b_20_5 = ((uint32_t)(s_b_20_3 + (uint32_t)6ULL));
        /* execute.simd:3759 [D] s_b_20_6 = ReadRegBank 23:s_b_20_5 (u8) */
        auto s_b_20_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_20_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_20_5))),s_b_20_6,emitter.const_u8(1));
        }
        /* execute.simd:3759 [D] s_b_20_7: sym_33605_0_rm = s_b_20_6, dominates: s_b_22_10  */
        emitter.store_local(DV_sym_33605_0_rm, s_b_20_6);
        /* execute.simd:3761 [F] s_b_20_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3761 [F] s_b_20_9 = (u32)s_b_20_8 (const) */
        /* execute.simd:3761 [F] s_b_20_10 = constant u32 1 (const) */
        /* execute.simd:3761 [F] s_b_20_11 = s_b_20_9+s_b_20_10 (const) */
        uint32_t s_b_20_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3761 [F] s_b_20_12 = constant u32 10 (const) */
        /* execute.simd:3761 [F] s_b_20_13 = s_b_20_12*s_b_20_11 (const) */
        uint32_t s_b_20_13 = ((uint32_t)((uint32_t)16ULL * s_b_20_11));
        /* execute.simd:3761 [D] s_b_20_14 = (u32)s_b_20_6 */
        auto s_b_20_14 = emitter.zx(s_b_20_6, emitter.context().types().u32());
        /* execute.simd:3761 [D] s_b_20_15 = s_b_20_14<s_b_20_13 */
        auto s_b_20_15 = emitter.cmp_lt(s_b_20_14, emitter.const_u32(s_b_20_13));
        /* execute.simd:3761 [D] s_b_20_16: If s_b_20_15: Jump b_22 else b_24 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_22;
            dynamic_block_queue.push(block_b_22);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_24;
            dynamic_block_queue.push(block_b_24);
            false_target = block;
          }
          emitter.branch(s_b_20_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_21) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_21);
        /* execute.simd:3764 [F] s_b_21_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3764 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
        /* execute.simd:3764 [F] s_b_21_2 = constant u32 10 (const) */
        /* execute.simd:3764 [F] s_b_21_3 = s_b_21_1*s_b_21_2 (const) */
        uint32_t s_b_21_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3764 [F] s_b_21_4 = constant u32 5 (const) */
        /* execute.simd:3764 [F] s_b_21_5 = s_b_21_3+s_b_21_4 (const) */
        uint32_t s_b_21_5 = ((uint32_t)(s_b_21_3 + (uint32_t)5ULL));
        /* execute.simd:3764 [F] s_b_21_6 = constant u8 0 (const) */
        /* execute.simd:3764 [F] s_b_21_7: WriteRegBank 23:s_b_21_5 = s_b_21_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_21_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_21_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3764 [F] s_b_21_8: Jump b_20 (const) */
        {
          auto block = block_b_20;
          dynamic_block_queue.push(block_b_20);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_22) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_22);
        /* execute.simd:3762 [F] s_b_22_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3762 [F] s_b_22_1 = (u32)s_b_22_0 (const) */
        /* execute.simd:3762 [F] s_b_22_2 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_22_3 = s_b_22_1*s_b_22_2 (const) */
        uint32_t s_b_22_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3762 [F] s_b_22_4 = constant u32 6 (const) */
        /* execute.simd:3762 [F] s_b_22_5 = s_b_22_3+s_b_22_4 (const) */
        uint32_t s_b_22_5 = ((uint32_t)(s_b_22_3 + (uint32_t)6ULL));
        /* execute.simd:3762 [F] s_b_22_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3762 [F] s_b_22_7 = (u32)s_b_22_6 (const) */
        /* execute.simd:3762 [F] s_b_22_8 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_22_9 = s_b_22_7*s_b_22_8 (const) */
        uint32_t s_b_22_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3762 [D] s_b_22_10 = sym_33605_0_rm uint8_t */
        auto s_b_22_10 = emitter.load_local(DV_sym_33605_0_rm, emitter.context().types().u8());
        /* execute.simd:3762 [D] s_b_22_11 = (u32)s_b_22_10 */
        auto s_b_22_11 = emitter.zx(s_b_22_10, emitter.context().types().u32());
        /* execute.simd:3762 [D] s_b_22_12 = s_b_22_9+s_b_22_11 */
        auto s_b_22_12 = emitter.add(emitter.const_u32(s_b_22_9), s_b_22_11);
        /* execute.simd:3762 [D] s_b_22_13 = ReadRegBank 23:s_b_22_12 (u8) */
        dbt::el::Value *s_b_22_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_22_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_22_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3762 [D] s_b_22_14: WriteRegBank 23:s_b_22_5 = s_b_22_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_22_5))),s_b_22_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_22_5))),s_b_22_13);
        /* execute.simd:3762 [F] s_b_22_15: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_23) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_23);
        /* execute.simd:3759 [F] s_b_23_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3759 [F] s_b_23_1 = (u32)s_b_23_0 (const) */
        /* execute.simd:3759 [F] s_b_23_2 = constant u32 10 (const) */
        /* execute.simd:3759 [F] s_b_23_3 = s_b_23_1*s_b_23_2 (const) */
        uint32_t s_b_23_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3759 [F] s_b_23_4 = constant u32 7 (const) */
        /* execute.simd:3759 [F] s_b_23_5 = s_b_23_3+s_b_23_4 (const) */
        uint32_t s_b_23_5 = ((uint32_t)(s_b_23_3 + (uint32_t)7ULL));
        /* execute.simd:3759 [D] s_b_23_6 = ReadRegBank 23:s_b_23_5 (u8) */
        auto s_b_23_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_23_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_23_5))),s_b_23_6,emitter.const_u8(1));
        }
        /* execute.simd:3759 [D] s_b_23_7: sym_33605_0_rm = s_b_23_6, dominates: s_b_25_10  */
        emitter.store_local(DV_sym_33605_0_rm, s_b_23_6);
        /* execute.simd:3761 [F] s_b_23_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3761 [F] s_b_23_9 = (u32)s_b_23_8 (const) */
        /* execute.simd:3761 [F] s_b_23_10 = constant u32 1 (const) */
        /* execute.simd:3761 [F] s_b_23_11 = s_b_23_9+s_b_23_10 (const) */
        uint32_t s_b_23_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3761 [F] s_b_23_12 = constant u32 10 (const) */
        /* execute.simd:3761 [F] s_b_23_13 = s_b_23_12*s_b_23_11 (const) */
        uint32_t s_b_23_13 = ((uint32_t)((uint32_t)16ULL * s_b_23_11));
        /* execute.simd:3761 [D] s_b_23_14 = (u32)s_b_23_6 */
        auto s_b_23_14 = emitter.zx(s_b_23_6, emitter.context().types().u32());
        /* execute.simd:3761 [D] s_b_23_15 = s_b_23_14<s_b_23_13 */
        auto s_b_23_15 = emitter.cmp_lt(s_b_23_14, emitter.const_u32(s_b_23_13));
        /* execute.simd:3761 [D] s_b_23_16: If s_b_23_15: Jump b_25 else b_27 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_25;
            dynamic_block_queue.push(block_b_25);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_27;
            dynamic_block_queue.push(block_b_27);
            false_target = block;
          }
          emitter.branch(s_b_23_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_24) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_24);
        /* execute.simd:3764 [F] s_b_24_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3764 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
        /* execute.simd:3764 [F] s_b_24_2 = constant u32 10 (const) */
        /* execute.simd:3764 [F] s_b_24_3 = s_b_24_1*s_b_24_2 (const) */
        uint32_t s_b_24_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3764 [F] s_b_24_4 = constant u32 6 (const) */
        /* execute.simd:3764 [F] s_b_24_5 = s_b_24_3+s_b_24_4 (const) */
        uint32_t s_b_24_5 = ((uint32_t)(s_b_24_3 + (uint32_t)6ULL));
        /* execute.simd:3764 [F] s_b_24_6 = constant u8 0 (const) */
        /* execute.simd:3764 [F] s_b_24_7: WriteRegBank 23:s_b_24_5 = s_b_24_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_24_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_24_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3764 [F] s_b_24_8: Jump b_23 (const) */
        {
          auto block = block_b_23;
          dynamic_block_queue.push(block_b_23);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_25) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_25);
        /* execute.simd:3762 [F] s_b_25_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3762 [F] s_b_25_1 = (u32)s_b_25_0 (const) */
        /* execute.simd:3762 [F] s_b_25_2 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_25_3 = s_b_25_1*s_b_25_2 (const) */
        uint32_t s_b_25_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3762 [F] s_b_25_4 = constant u32 7 (const) */
        /* execute.simd:3762 [F] s_b_25_5 = s_b_25_3+s_b_25_4 (const) */
        uint32_t s_b_25_5 = ((uint32_t)(s_b_25_3 + (uint32_t)7ULL));
        /* execute.simd:3762 [F] s_b_25_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3762 [F] s_b_25_7 = (u32)s_b_25_6 (const) */
        /* execute.simd:3762 [F] s_b_25_8 = constant u32 10 (const) */
        /* execute.simd:3762 [F] s_b_25_9 = s_b_25_7*s_b_25_8 (const) */
        uint32_t s_b_25_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3762 [D] s_b_25_10 = sym_33605_0_rm uint8_t */
        auto s_b_25_10 = emitter.load_local(DV_sym_33605_0_rm, emitter.context().types().u8());
        /* execute.simd:3762 [D] s_b_25_11 = (u32)s_b_25_10 */
        auto s_b_25_11 = emitter.zx(s_b_25_10, emitter.context().types().u32());
        /* execute.simd:3762 [D] s_b_25_12 = s_b_25_9+s_b_25_11 */
        auto s_b_25_12 = emitter.add(emitter.const_u32(s_b_25_9), s_b_25_11);
        /* execute.simd:3762 [D] s_b_25_13 = ReadRegBank 23:s_b_25_12 (u8) */
        dbt::el::Value *s_b_25_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_25_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_25_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3762 [D] s_b_25_14: WriteRegBank 23:s_b_25_5 = s_b_25_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_25_5))),s_b_25_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_25_5))),s_b_25_13);
        /* execute.simd:3762 [F] s_b_25_15: Jump b_26 (const) */
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_26) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_26);
        /* execute.simd:3768 [F] s_b_26_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3768 [F] s_b_26_1 = constant u64 0 (const) */
        /* execute.simd:3768 [F] s_b_26_2: WriteRegBank 3:s_b_26_0 = s_b_26_1 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:3758 [F] s_b_26_3: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_27) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_27);
        /* execute.simd:3764 [F] s_b_27_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3764 [F] s_b_27_1 = (u32)s_b_27_0 (const) */
        /* execute.simd:3764 [F] s_b_27_2 = constant u32 10 (const) */
        /* execute.simd:3764 [F] s_b_27_3 = s_b_27_1*s_b_27_2 (const) */
        uint32_t s_b_27_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3764 [F] s_b_27_4 = constant u32 7 (const) */
        /* execute.simd:3764 [F] s_b_27_5 = s_b_27_3+s_b_27_4 (const) */
        uint32_t s_b_27_5 = ((uint32_t)(s_b_27_3 + (uint32_t)7ULL));
        /* execute.simd:3764 [F] s_b_27_6 = constant u8 0 (const) */
        /* execute.simd:3764 [F] s_b_27_7: WriteRegBank 23:s_b_27_5 = s_b_27_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_27_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_27_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3764 [F] s_b_27_8: Jump b_26 (const) */
        {
          auto block = block_b_26;
          dynamic_block_queue.push(block_b_26);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_28) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_28);
        /* execute.simd:3774 [F] s_b_28_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_28_1 = (u32)s_b_28_0 (const) */
        /* execute.simd:3774 [F] s_b_28_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_28_3 = s_b_28_1*s_b_28_2 (const) */
        uint32_t s_b_28_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_28_4 = constant u32 0 (const) */
        /* execute.simd:3774 [F] s_b_28_5 = s_b_28_3+s_b_28_4 (const) */
        uint32_t s_b_28_5 = ((uint32_t)(s_b_28_3 + (uint32_t)0ULL));
        /* execute.simd:3774 [F] s_b_28_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_28_7 = (u32)s_b_28_6 (const) */
        /* execute.simd:3774 [F] s_b_28_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_28_9 = s_b_28_7*s_b_28_8 (const) */
        uint32_t s_b_28_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_28_10 = sym_34102_0_rm uint8_t */
        auto s_b_28_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_28_11 = (u32)s_b_28_10 */
        auto s_b_28_11 = emitter.zx(s_b_28_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_28_12 = s_b_28_9+s_b_28_11 */
        auto s_b_28_12 = emitter.add(emitter.const_u32(s_b_28_9), s_b_28_11);
        /* execute.simd:3774 [D] s_b_28_13 = ReadRegBank 23:s_b_28_12 (u8) */
        dbt::el::Value *s_b_28_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_28_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_28_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_28_14: WriteRegBank 23:s_b_28_5 = s_b_28_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_28_5))),s_b_28_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_28_5))),s_b_28_13);
        /* execute.simd:3774 [F] s_b_28_15: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_29) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_29);
        /* execute.simd:3771 [F] s_b_29_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_29_1 = (u32)s_b_29_0 (const) */
        /* execute.simd:3771 [F] s_b_29_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_29_3 = s_b_29_1*s_b_29_2 (const) */
        uint32_t s_b_29_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_29_4 = constant u32 1 (const) */
        /* execute.simd:3771 [F] s_b_29_5 = s_b_29_3+s_b_29_4 (const) */
        uint32_t s_b_29_5 = ((uint32_t)(s_b_29_3 + (uint32_t)1ULL));
        /* execute.simd:3771 [D] s_b_29_6 = ReadRegBank 23:s_b_29_5 (u8) */
        auto s_b_29_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_29_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_29_5))),s_b_29_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_29_7: sym_34102_0_rm = s_b_29_6, dominates: s_b_31_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_29_6);
        /* execute.simd:3773 [F] s_b_29_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_29_9 = (u32)s_b_29_8 (const) */
        /* execute.simd:3773 [F] s_b_29_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_29_11 = s_b_29_9+s_b_29_10 (const) */
        uint32_t s_b_29_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_29_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_29_13 = s_b_29_12*s_b_29_11 (const) */
        uint32_t s_b_29_13 = ((uint32_t)((uint32_t)16ULL * s_b_29_11));
        /* execute.simd:3773 [D] s_b_29_14 = (u32)s_b_29_6 */
        auto s_b_29_14 = emitter.zx(s_b_29_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_29_15 = s_b_29_14<s_b_29_13 */
        auto s_b_29_15 = emitter.cmp_lt(s_b_29_14, emitter.const_u32(s_b_29_13));
        /* execute.simd:3773 [D] s_b_29_16: If s_b_29_15: Jump b_31 else b_33 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_31;
            dynamic_block_queue.push(block_b_31);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_33;
            dynamic_block_queue.push(block_b_33);
            false_target = block;
          }
          emitter.branch(s_b_29_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_30) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_30);
        /* execute.simd:3776 [F] s_b_30_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_30_1 = (u32)s_b_30_0 (const) */
        /* execute.simd:3776 [F] s_b_30_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_30_3 = s_b_30_1*s_b_30_2 (const) */
        uint32_t s_b_30_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_30_4 = constant u32 0 (const) */
        /* execute.simd:3776 [F] s_b_30_5 = s_b_30_3+s_b_30_4 (const) */
        uint32_t s_b_30_5 = ((uint32_t)(s_b_30_3 + (uint32_t)0ULL));
        /* execute.simd:3776 [F] s_b_30_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_30_7: WriteRegBank 23:s_b_30_5 = s_b_30_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_30_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_30_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_30_8: Jump b_29 (const) */
        {
          auto block = block_b_29;
          dynamic_block_queue.push(block_b_29);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_31) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_31);
        /* execute.simd:3774 [F] s_b_31_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_31_1 = (u32)s_b_31_0 (const) */
        /* execute.simd:3774 [F] s_b_31_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_31_3 = s_b_31_1*s_b_31_2 (const) */
        uint32_t s_b_31_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_31_4 = constant u32 1 (const) */
        /* execute.simd:3774 [F] s_b_31_5 = s_b_31_3+s_b_31_4 (const) */
        uint32_t s_b_31_5 = ((uint32_t)(s_b_31_3 + (uint32_t)1ULL));
        /* execute.simd:3774 [F] s_b_31_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_31_7 = (u32)s_b_31_6 (const) */
        /* execute.simd:3774 [F] s_b_31_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_31_9 = s_b_31_7*s_b_31_8 (const) */
        uint32_t s_b_31_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_31_10 = sym_34102_0_rm uint8_t */
        auto s_b_31_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_31_11 = (u32)s_b_31_10 */
        auto s_b_31_11 = emitter.zx(s_b_31_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_31_12 = s_b_31_9+s_b_31_11 */
        auto s_b_31_12 = emitter.add(emitter.const_u32(s_b_31_9), s_b_31_11);
        /* execute.simd:3774 [D] s_b_31_13 = ReadRegBank 23:s_b_31_12 (u8) */
        dbt::el::Value *s_b_31_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_31_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_31_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_31_14: WriteRegBank 23:s_b_31_5 = s_b_31_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_31_5))),s_b_31_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_31_5))),s_b_31_13);
        /* execute.simd:3774 [F] s_b_31_15: Jump b_32 (const) */
        {
          auto block = block_b_32;
          dynamic_block_queue.push(block_b_32);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_32) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_32);
        /* execute.simd:3771 [F] s_b_32_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_32_1 = (u32)s_b_32_0 (const) */
        /* execute.simd:3771 [F] s_b_32_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_32_3 = s_b_32_1*s_b_32_2 (const) */
        uint32_t s_b_32_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_32_4 = constant u32 2 (const) */
        /* execute.simd:3771 [F] s_b_32_5 = s_b_32_3+s_b_32_4 (const) */
        uint32_t s_b_32_5 = ((uint32_t)(s_b_32_3 + (uint32_t)2ULL));
        /* execute.simd:3771 [D] s_b_32_6 = ReadRegBank 23:s_b_32_5 (u8) */
        auto s_b_32_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_32_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_32_5))),s_b_32_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_32_7: sym_34102_0_rm = s_b_32_6, dominates: s_b_34_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_32_6);
        /* execute.simd:3773 [F] s_b_32_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_32_9 = (u32)s_b_32_8 (const) */
        /* execute.simd:3773 [F] s_b_32_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_32_11 = s_b_32_9+s_b_32_10 (const) */
        uint32_t s_b_32_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_32_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_32_13 = s_b_32_12*s_b_32_11 (const) */
        uint32_t s_b_32_13 = ((uint32_t)((uint32_t)16ULL * s_b_32_11));
        /* execute.simd:3773 [D] s_b_32_14 = (u32)s_b_32_6 */
        auto s_b_32_14 = emitter.zx(s_b_32_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_32_15 = s_b_32_14<s_b_32_13 */
        auto s_b_32_15 = emitter.cmp_lt(s_b_32_14, emitter.const_u32(s_b_32_13));
        /* execute.simd:3773 [D] s_b_32_16: If s_b_32_15: Jump b_34 else b_36 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_34;
            dynamic_block_queue.push(block_b_34);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_36;
            dynamic_block_queue.push(block_b_36);
            false_target = block;
          }
          emitter.branch(s_b_32_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_33) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_33);
        /* execute.simd:3776 [F] s_b_33_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_33_1 = (u32)s_b_33_0 (const) */
        /* execute.simd:3776 [F] s_b_33_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_33_3 = s_b_33_1*s_b_33_2 (const) */
        uint32_t s_b_33_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_33_4 = constant u32 1 (const) */
        /* execute.simd:3776 [F] s_b_33_5 = s_b_33_3+s_b_33_4 (const) */
        uint32_t s_b_33_5 = ((uint32_t)(s_b_33_3 + (uint32_t)1ULL));
        /* execute.simd:3776 [F] s_b_33_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_33_7: WriteRegBank 23:s_b_33_5 = s_b_33_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_33_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_33_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_33_8: Jump b_32 (const) */
        {
          auto block = block_b_32;
          dynamic_block_queue.push(block_b_32);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_34) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_34);
        /* execute.simd:3774 [F] s_b_34_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_34_1 = (u32)s_b_34_0 (const) */
        /* execute.simd:3774 [F] s_b_34_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_34_3 = s_b_34_1*s_b_34_2 (const) */
        uint32_t s_b_34_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_34_4 = constant u32 2 (const) */
        /* execute.simd:3774 [F] s_b_34_5 = s_b_34_3+s_b_34_4 (const) */
        uint32_t s_b_34_5 = ((uint32_t)(s_b_34_3 + (uint32_t)2ULL));
        /* execute.simd:3774 [F] s_b_34_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_34_7 = (u32)s_b_34_6 (const) */
        /* execute.simd:3774 [F] s_b_34_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_34_9 = s_b_34_7*s_b_34_8 (const) */
        uint32_t s_b_34_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_34_10 = sym_34102_0_rm uint8_t */
        auto s_b_34_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_34_11 = (u32)s_b_34_10 */
        auto s_b_34_11 = emitter.zx(s_b_34_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_34_12 = s_b_34_9+s_b_34_11 */
        auto s_b_34_12 = emitter.add(emitter.const_u32(s_b_34_9), s_b_34_11);
        /* execute.simd:3774 [D] s_b_34_13 = ReadRegBank 23:s_b_34_12 (u8) */
        dbt::el::Value *s_b_34_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_34_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_34_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_34_14: WriteRegBank 23:s_b_34_5 = s_b_34_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_34_5))),s_b_34_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_34_5))),s_b_34_13);
        /* execute.simd:3774 [F] s_b_34_15: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_35) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_35);
        /* execute.simd:3771 [F] s_b_35_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_35_1 = (u32)s_b_35_0 (const) */
        /* execute.simd:3771 [F] s_b_35_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_35_3 = s_b_35_1*s_b_35_2 (const) */
        uint32_t s_b_35_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_35_4 = constant u32 3 (const) */
        /* execute.simd:3771 [F] s_b_35_5 = s_b_35_3+s_b_35_4 (const) */
        uint32_t s_b_35_5 = ((uint32_t)(s_b_35_3 + (uint32_t)3ULL));
        /* execute.simd:3771 [D] s_b_35_6 = ReadRegBank 23:s_b_35_5 (u8) */
        auto s_b_35_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_35_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_35_5))),s_b_35_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_35_7: sym_34102_0_rm = s_b_35_6, dominates: s_b_37_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_35_6);
        /* execute.simd:3773 [F] s_b_35_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_35_9 = (u32)s_b_35_8 (const) */
        /* execute.simd:3773 [F] s_b_35_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_35_11 = s_b_35_9+s_b_35_10 (const) */
        uint32_t s_b_35_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_35_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_35_13 = s_b_35_12*s_b_35_11 (const) */
        uint32_t s_b_35_13 = ((uint32_t)((uint32_t)16ULL * s_b_35_11));
        /* execute.simd:3773 [D] s_b_35_14 = (u32)s_b_35_6 */
        auto s_b_35_14 = emitter.zx(s_b_35_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_35_15 = s_b_35_14<s_b_35_13 */
        auto s_b_35_15 = emitter.cmp_lt(s_b_35_14, emitter.const_u32(s_b_35_13));
        /* execute.simd:3773 [D] s_b_35_16: If s_b_35_15: Jump b_37 else b_39 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_37;
            dynamic_block_queue.push(block_b_37);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_39;
            dynamic_block_queue.push(block_b_39);
            false_target = block;
          }
          emitter.branch(s_b_35_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_36) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_36);
        /* execute.simd:3776 [F] s_b_36_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_36_1 = (u32)s_b_36_0 (const) */
        /* execute.simd:3776 [F] s_b_36_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_36_3 = s_b_36_1*s_b_36_2 (const) */
        uint32_t s_b_36_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_36_4 = constant u32 2 (const) */
        /* execute.simd:3776 [F] s_b_36_5 = s_b_36_3+s_b_36_4 (const) */
        uint32_t s_b_36_5 = ((uint32_t)(s_b_36_3 + (uint32_t)2ULL));
        /* execute.simd:3776 [F] s_b_36_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_36_7: WriteRegBank 23:s_b_36_5 = s_b_36_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_36_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_36_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_36_8: Jump b_35 (const) */
        {
          auto block = block_b_35;
          dynamic_block_queue.push(block_b_35);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_37) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_37);
        /* execute.simd:3774 [F] s_b_37_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_37_1 = (u32)s_b_37_0 (const) */
        /* execute.simd:3774 [F] s_b_37_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_37_3 = s_b_37_1*s_b_37_2 (const) */
        uint32_t s_b_37_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_37_4 = constant u32 3 (const) */
        /* execute.simd:3774 [F] s_b_37_5 = s_b_37_3+s_b_37_4 (const) */
        uint32_t s_b_37_5 = ((uint32_t)(s_b_37_3 + (uint32_t)3ULL));
        /* execute.simd:3774 [F] s_b_37_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_37_7 = (u32)s_b_37_6 (const) */
        /* execute.simd:3774 [F] s_b_37_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_37_9 = s_b_37_7*s_b_37_8 (const) */
        uint32_t s_b_37_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_37_10 = sym_34102_0_rm uint8_t */
        auto s_b_37_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_37_11 = (u32)s_b_37_10 */
        auto s_b_37_11 = emitter.zx(s_b_37_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_37_12 = s_b_37_9+s_b_37_11 */
        auto s_b_37_12 = emitter.add(emitter.const_u32(s_b_37_9), s_b_37_11);
        /* execute.simd:3774 [D] s_b_37_13 = ReadRegBank 23:s_b_37_12 (u8) */
        dbt::el::Value *s_b_37_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_37_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_37_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_37_14: WriteRegBank 23:s_b_37_5 = s_b_37_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_37_5))),s_b_37_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_37_5))),s_b_37_13);
        /* execute.simd:3774 [F] s_b_37_15: Jump b_38 (const) */
        {
          auto block = block_b_38;
          dynamic_block_queue.push(block_b_38);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_38) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_38);
        /* execute.simd:3771 [F] s_b_38_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_38_1 = (u32)s_b_38_0 (const) */
        /* execute.simd:3771 [F] s_b_38_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_38_3 = s_b_38_1*s_b_38_2 (const) */
        uint32_t s_b_38_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_38_4 = constant u32 4 (const) */
        /* execute.simd:3771 [F] s_b_38_5 = s_b_38_3+s_b_38_4 (const) */
        uint32_t s_b_38_5 = ((uint32_t)(s_b_38_3 + (uint32_t)4ULL));
        /* execute.simd:3771 [D] s_b_38_6 = ReadRegBank 23:s_b_38_5 (u8) */
        auto s_b_38_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_38_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_38_5))),s_b_38_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_38_7: sym_34102_0_rm = s_b_38_6, dominates: s_b_40_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_38_6);
        /* execute.simd:3773 [F] s_b_38_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_38_9 = (u32)s_b_38_8 (const) */
        /* execute.simd:3773 [F] s_b_38_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_38_11 = s_b_38_9+s_b_38_10 (const) */
        uint32_t s_b_38_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_38_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_38_13 = s_b_38_12*s_b_38_11 (const) */
        uint32_t s_b_38_13 = ((uint32_t)((uint32_t)16ULL * s_b_38_11));
        /* execute.simd:3773 [D] s_b_38_14 = (u32)s_b_38_6 */
        auto s_b_38_14 = emitter.zx(s_b_38_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_38_15 = s_b_38_14<s_b_38_13 */
        auto s_b_38_15 = emitter.cmp_lt(s_b_38_14, emitter.const_u32(s_b_38_13));
        /* execute.simd:3773 [D] s_b_38_16: If s_b_38_15: Jump b_40 else b_42 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_40;
            dynamic_block_queue.push(block_b_40);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_42;
            dynamic_block_queue.push(block_b_42);
            false_target = block;
          }
          emitter.branch(s_b_38_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_39) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_39);
        /* execute.simd:3776 [F] s_b_39_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_39_1 = (u32)s_b_39_0 (const) */
        /* execute.simd:3776 [F] s_b_39_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_39_3 = s_b_39_1*s_b_39_2 (const) */
        uint32_t s_b_39_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_39_4 = constant u32 3 (const) */
        /* execute.simd:3776 [F] s_b_39_5 = s_b_39_3+s_b_39_4 (const) */
        uint32_t s_b_39_5 = ((uint32_t)(s_b_39_3 + (uint32_t)3ULL));
        /* execute.simd:3776 [F] s_b_39_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_39_7: WriteRegBank 23:s_b_39_5 = s_b_39_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_39_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_39_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_39_8: Jump b_38 (const) */
        {
          auto block = block_b_38;
          dynamic_block_queue.push(block_b_38);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_40) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_40);
        /* execute.simd:3774 [F] s_b_40_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_40_1 = (u32)s_b_40_0 (const) */
        /* execute.simd:3774 [F] s_b_40_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_40_3 = s_b_40_1*s_b_40_2 (const) */
        uint32_t s_b_40_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_40_4 = constant u32 4 (const) */
        /* execute.simd:3774 [F] s_b_40_5 = s_b_40_3+s_b_40_4 (const) */
        uint32_t s_b_40_5 = ((uint32_t)(s_b_40_3 + (uint32_t)4ULL));
        /* execute.simd:3774 [F] s_b_40_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_40_7 = (u32)s_b_40_6 (const) */
        /* execute.simd:3774 [F] s_b_40_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_40_9 = s_b_40_7*s_b_40_8 (const) */
        uint32_t s_b_40_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_40_10 = sym_34102_0_rm uint8_t */
        auto s_b_40_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_40_11 = (u32)s_b_40_10 */
        auto s_b_40_11 = emitter.zx(s_b_40_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_40_12 = s_b_40_9+s_b_40_11 */
        auto s_b_40_12 = emitter.add(emitter.const_u32(s_b_40_9), s_b_40_11);
        /* execute.simd:3774 [D] s_b_40_13 = ReadRegBank 23:s_b_40_12 (u8) */
        dbt::el::Value *s_b_40_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_40_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_40_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_40_14: WriteRegBank 23:s_b_40_5 = s_b_40_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_40_5))),s_b_40_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_40_5))),s_b_40_13);
        /* execute.simd:3774 [F] s_b_40_15: Jump b_41 (const) */
        {
          auto block = block_b_41;
          dynamic_block_queue.push(block_b_41);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_41) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_41);
        /* execute.simd:3771 [F] s_b_41_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_41_1 = (u32)s_b_41_0 (const) */
        /* execute.simd:3771 [F] s_b_41_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_41_3 = s_b_41_1*s_b_41_2 (const) */
        uint32_t s_b_41_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_41_4 = constant u32 5 (const) */
        /* execute.simd:3771 [F] s_b_41_5 = s_b_41_3+s_b_41_4 (const) */
        uint32_t s_b_41_5 = ((uint32_t)(s_b_41_3 + (uint32_t)5ULL));
        /* execute.simd:3771 [D] s_b_41_6 = ReadRegBank 23:s_b_41_5 (u8) */
        auto s_b_41_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_41_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_41_5))),s_b_41_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_41_7: sym_34102_0_rm = s_b_41_6, dominates: s_b_43_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_41_6);
        /* execute.simd:3773 [F] s_b_41_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_41_9 = (u32)s_b_41_8 (const) */
        /* execute.simd:3773 [F] s_b_41_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_41_11 = s_b_41_9+s_b_41_10 (const) */
        uint32_t s_b_41_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_41_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_41_13 = s_b_41_12*s_b_41_11 (const) */
        uint32_t s_b_41_13 = ((uint32_t)((uint32_t)16ULL * s_b_41_11));
        /* execute.simd:3773 [D] s_b_41_14 = (u32)s_b_41_6 */
        auto s_b_41_14 = emitter.zx(s_b_41_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_41_15 = s_b_41_14<s_b_41_13 */
        auto s_b_41_15 = emitter.cmp_lt(s_b_41_14, emitter.const_u32(s_b_41_13));
        /* execute.simd:3773 [D] s_b_41_16: If s_b_41_15: Jump b_43 else b_45 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_43;
            dynamic_block_queue.push(block_b_43);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_45;
            dynamic_block_queue.push(block_b_45);
            false_target = block;
          }
          emitter.branch(s_b_41_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_42) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_42);
        /* execute.simd:3776 [F] s_b_42_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_42_1 = (u32)s_b_42_0 (const) */
        /* execute.simd:3776 [F] s_b_42_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_42_3 = s_b_42_1*s_b_42_2 (const) */
        uint32_t s_b_42_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_42_4 = constant u32 4 (const) */
        /* execute.simd:3776 [F] s_b_42_5 = s_b_42_3+s_b_42_4 (const) */
        uint32_t s_b_42_5 = ((uint32_t)(s_b_42_3 + (uint32_t)4ULL));
        /* execute.simd:3776 [F] s_b_42_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_42_7: WriteRegBank 23:s_b_42_5 = s_b_42_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_42_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_42_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_42_8: Jump b_41 (const) */
        {
          auto block = block_b_41;
          dynamic_block_queue.push(block_b_41);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_43) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_43);
        /* execute.simd:3774 [F] s_b_43_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_43_1 = (u32)s_b_43_0 (const) */
        /* execute.simd:3774 [F] s_b_43_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_43_3 = s_b_43_1*s_b_43_2 (const) */
        uint32_t s_b_43_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_43_4 = constant u32 5 (const) */
        /* execute.simd:3774 [F] s_b_43_5 = s_b_43_3+s_b_43_4 (const) */
        uint32_t s_b_43_5 = ((uint32_t)(s_b_43_3 + (uint32_t)5ULL));
        /* execute.simd:3774 [F] s_b_43_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_43_7 = (u32)s_b_43_6 (const) */
        /* execute.simd:3774 [F] s_b_43_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_43_9 = s_b_43_7*s_b_43_8 (const) */
        uint32_t s_b_43_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_43_10 = sym_34102_0_rm uint8_t */
        auto s_b_43_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_43_11 = (u32)s_b_43_10 */
        auto s_b_43_11 = emitter.zx(s_b_43_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_43_12 = s_b_43_9+s_b_43_11 */
        auto s_b_43_12 = emitter.add(emitter.const_u32(s_b_43_9), s_b_43_11);
        /* execute.simd:3774 [D] s_b_43_13 = ReadRegBank 23:s_b_43_12 (u8) */
        dbt::el::Value *s_b_43_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_43_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_43_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_43_14: WriteRegBank 23:s_b_43_5 = s_b_43_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_43_5))),s_b_43_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_43_5))),s_b_43_13);
        /* execute.simd:3774 [F] s_b_43_15: Jump b_44 (const) */
        {
          auto block = block_b_44;
          dynamic_block_queue.push(block_b_44);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_44) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_44);
        /* execute.simd:3771 [F] s_b_44_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_44_1 = (u32)s_b_44_0 (const) */
        /* execute.simd:3771 [F] s_b_44_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_44_3 = s_b_44_1*s_b_44_2 (const) */
        uint32_t s_b_44_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_44_4 = constant u32 6 (const) */
        /* execute.simd:3771 [F] s_b_44_5 = s_b_44_3+s_b_44_4 (const) */
        uint32_t s_b_44_5 = ((uint32_t)(s_b_44_3 + (uint32_t)6ULL));
        /* execute.simd:3771 [D] s_b_44_6 = ReadRegBank 23:s_b_44_5 (u8) */
        auto s_b_44_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_44_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_44_5))),s_b_44_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_44_7: sym_34102_0_rm = s_b_44_6, dominates: s_b_46_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_44_6);
        /* execute.simd:3773 [F] s_b_44_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_44_9 = (u32)s_b_44_8 (const) */
        /* execute.simd:3773 [F] s_b_44_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_44_11 = s_b_44_9+s_b_44_10 (const) */
        uint32_t s_b_44_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_44_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_44_13 = s_b_44_12*s_b_44_11 (const) */
        uint32_t s_b_44_13 = ((uint32_t)((uint32_t)16ULL * s_b_44_11));
        /* execute.simd:3773 [D] s_b_44_14 = (u32)s_b_44_6 */
        auto s_b_44_14 = emitter.zx(s_b_44_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_44_15 = s_b_44_14<s_b_44_13 */
        auto s_b_44_15 = emitter.cmp_lt(s_b_44_14, emitter.const_u32(s_b_44_13));
        /* execute.simd:3773 [D] s_b_44_16: If s_b_44_15: Jump b_46 else b_48 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_46;
            dynamic_block_queue.push(block_b_46);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_48;
            dynamic_block_queue.push(block_b_48);
            false_target = block;
          }
          emitter.branch(s_b_44_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_45) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_45);
        /* execute.simd:3776 [F] s_b_45_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_45_1 = (u32)s_b_45_0 (const) */
        /* execute.simd:3776 [F] s_b_45_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_45_3 = s_b_45_1*s_b_45_2 (const) */
        uint32_t s_b_45_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_45_4 = constant u32 5 (const) */
        /* execute.simd:3776 [F] s_b_45_5 = s_b_45_3+s_b_45_4 (const) */
        uint32_t s_b_45_5 = ((uint32_t)(s_b_45_3 + (uint32_t)5ULL));
        /* execute.simd:3776 [F] s_b_45_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_45_7: WriteRegBank 23:s_b_45_5 = s_b_45_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_45_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_45_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_45_8: Jump b_44 (const) */
        {
          auto block = block_b_44;
          dynamic_block_queue.push(block_b_44);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_46) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_46);
        /* execute.simd:3774 [F] s_b_46_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_46_1 = (u32)s_b_46_0 (const) */
        /* execute.simd:3774 [F] s_b_46_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_46_3 = s_b_46_1*s_b_46_2 (const) */
        uint32_t s_b_46_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_46_4 = constant u32 6 (const) */
        /* execute.simd:3774 [F] s_b_46_5 = s_b_46_3+s_b_46_4 (const) */
        uint32_t s_b_46_5 = ((uint32_t)(s_b_46_3 + (uint32_t)6ULL));
        /* execute.simd:3774 [F] s_b_46_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_46_7 = (u32)s_b_46_6 (const) */
        /* execute.simd:3774 [F] s_b_46_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_46_9 = s_b_46_7*s_b_46_8 (const) */
        uint32_t s_b_46_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_46_10 = sym_34102_0_rm uint8_t */
        auto s_b_46_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_46_11 = (u32)s_b_46_10 */
        auto s_b_46_11 = emitter.zx(s_b_46_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_46_12 = s_b_46_9+s_b_46_11 */
        auto s_b_46_12 = emitter.add(emitter.const_u32(s_b_46_9), s_b_46_11);
        /* execute.simd:3774 [D] s_b_46_13 = ReadRegBank 23:s_b_46_12 (u8) */
        dbt::el::Value *s_b_46_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_46_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_46_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_46_14: WriteRegBank 23:s_b_46_5 = s_b_46_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_46_5))),s_b_46_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_46_5))),s_b_46_13);
        /* execute.simd:3774 [F] s_b_46_15: Jump b_47 (const) */
        {
          auto block = block_b_47;
          dynamic_block_queue.push(block_b_47);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_47) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_47);
        /* execute.simd:3771 [F] s_b_47_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_47_1 = (u32)s_b_47_0 (const) */
        /* execute.simd:3771 [F] s_b_47_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_47_3 = s_b_47_1*s_b_47_2 (const) */
        uint32_t s_b_47_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_47_4 = constant u32 7 (const) */
        /* execute.simd:3771 [F] s_b_47_5 = s_b_47_3+s_b_47_4 (const) */
        uint32_t s_b_47_5 = ((uint32_t)(s_b_47_3 + (uint32_t)7ULL));
        /* execute.simd:3771 [D] s_b_47_6 = ReadRegBank 23:s_b_47_5 (u8) */
        auto s_b_47_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_47_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_47_5))),s_b_47_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_47_7: sym_34102_0_rm = s_b_47_6, dominates: s_b_49_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_47_6);
        /* execute.simd:3773 [F] s_b_47_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_47_9 = (u32)s_b_47_8 (const) */
        /* execute.simd:3773 [F] s_b_47_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_47_11 = s_b_47_9+s_b_47_10 (const) */
        uint32_t s_b_47_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_47_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_47_13 = s_b_47_12*s_b_47_11 (const) */
        uint32_t s_b_47_13 = ((uint32_t)((uint32_t)16ULL * s_b_47_11));
        /* execute.simd:3773 [D] s_b_47_14 = (u32)s_b_47_6 */
        auto s_b_47_14 = emitter.zx(s_b_47_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_47_15 = s_b_47_14<s_b_47_13 */
        auto s_b_47_15 = emitter.cmp_lt(s_b_47_14, emitter.const_u32(s_b_47_13));
        /* execute.simd:3773 [D] s_b_47_16: If s_b_47_15: Jump b_49 else b_51 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_49;
            dynamic_block_queue.push(block_b_49);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_51;
            dynamic_block_queue.push(block_b_51);
            false_target = block;
          }
          emitter.branch(s_b_47_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_48) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_48);
        /* execute.simd:3776 [F] s_b_48_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_48_1 = (u32)s_b_48_0 (const) */
        /* execute.simd:3776 [F] s_b_48_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_48_3 = s_b_48_1*s_b_48_2 (const) */
        uint32_t s_b_48_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_48_4 = constant u32 6 (const) */
        /* execute.simd:3776 [F] s_b_48_5 = s_b_48_3+s_b_48_4 (const) */
        uint32_t s_b_48_5 = ((uint32_t)(s_b_48_3 + (uint32_t)6ULL));
        /* execute.simd:3776 [F] s_b_48_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_48_7: WriteRegBank 23:s_b_48_5 = s_b_48_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_48_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_48_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_48_8: Jump b_47 (const) */
        {
          auto block = block_b_47;
          dynamic_block_queue.push(block_b_47);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_49) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_49);
        /* execute.simd:3774 [F] s_b_49_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_49_1 = (u32)s_b_49_0 (const) */
        /* execute.simd:3774 [F] s_b_49_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_49_3 = s_b_49_1*s_b_49_2 (const) */
        uint32_t s_b_49_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_49_4 = constant u32 7 (const) */
        /* execute.simd:3774 [F] s_b_49_5 = s_b_49_3+s_b_49_4 (const) */
        uint32_t s_b_49_5 = ((uint32_t)(s_b_49_3 + (uint32_t)7ULL));
        /* execute.simd:3774 [F] s_b_49_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_49_7 = (u32)s_b_49_6 (const) */
        /* execute.simd:3774 [F] s_b_49_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_49_9 = s_b_49_7*s_b_49_8 (const) */
        uint32_t s_b_49_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_49_10 = sym_34102_0_rm uint8_t */
        auto s_b_49_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_49_11 = (u32)s_b_49_10 */
        auto s_b_49_11 = emitter.zx(s_b_49_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_49_12 = s_b_49_9+s_b_49_11 */
        auto s_b_49_12 = emitter.add(emitter.const_u32(s_b_49_9), s_b_49_11);
        /* execute.simd:3774 [D] s_b_49_13 = ReadRegBank 23:s_b_49_12 (u8) */
        dbt::el::Value *s_b_49_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_49_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_49_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_49_14: WriteRegBank 23:s_b_49_5 = s_b_49_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_49_5))),s_b_49_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_49_5))),s_b_49_13);
        /* execute.simd:3774 [F] s_b_49_15: Jump b_50 (const) */
        {
          auto block = block_b_50;
          dynamic_block_queue.push(block_b_50);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_50) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_50);
        /* execute.simd:3771 [F] s_b_50_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_50_1 = (u32)s_b_50_0 (const) */
        /* execute.simd:3771 [F] s_b_50_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_50_3 = s_b_50_1*s_b_50_2 (const) */
        uint32_t s_b_50_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_50_4 = constant u32 8 (const) */
        /* execute.simd:3771 [F] s_b_50_5 = s_b_50_3+s_b_50_4 (const) */
        uint32_t s_b_50_5 = ((uint32_t)(s_b_50_3 + (uint32_t)8ULL));
        /* execute.simd:3771 [D] s_b_50_6 = ReadRegBank 23:s_b_50_5 (u8) */
        auto s_b_50_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_50_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_50_5))),s_b_50_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_50_7: sym_34102_0_rm = s_b_50_6, dominates: s_b_52_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_50_6);
        /* execute.simd:3773 [F] s_b_50_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_50_9 = (u32)s_b_50_8 (const) */
        /* execute.simd:3773 [F] s_b_50_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_50_11 = s_b_50_9+s_b_50_10 (const) */
        uint32_t s_b_50_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_50_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_50_13 = s_b_50_12*s_b_50_11 (const) */
        uint32_t s_b_50_13 = ((uint32_t)((uint32_t)16ULL * s_b_50_11));
        /* execute.simd:3773 [D] s_b_50_14 = (u32)s_b_50_6 */
        auto s_b_50_14 = emitter.zx(s_b_50_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_50_15 = s_b_50_14<s_b_50_13 */
        auto s_b_50_15 = emitter.cmp_lt(s_b_50_14, emitter.const_u32(s_b_50_13));
        /* execute.simd:3773 [D] s_b_50_16: If s_b_50_15: Jump b_52 else b_54 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_52;
            dynamic_block_queue.push(block_b_52);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_54;
            dynamic_block_queue.push(block_b_54);
            false_target = block;
          }
          emitter.branch(s_b_50_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_51) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_51);
        /* execute.simd:3776 [F] s_b_51_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_51_1 = (u32)s_b_51_0 (const) */
        /* execute.simd:3776 [F] s_b_51_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_51_3 = s_b_51_1*s_b_51_2 (const) */
        uint32_t s_b_51_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_51_4 = constant u32 7 (const) */
        /* execute.simd:3776 [F] s_b_51_5 = s_b_51_3+s_b_51_4 (const) */
        uint32_t s_b_51_5 = ((uint32_t)(s_b_51_3 + (uint32_t)7ULL));
        /* execute.simd:3776 [F] s_b_51_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_51_7: WriteRegBank 23:s_b_51_5 = s_b_51_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_51_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_51_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_51_8: Jump b_50 (const) */
        {
          auto block = block_b_50;
          dynamic_block_queue.push(block_b_50);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_52) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_52);
        /* execute.simd:3774 [F] s_b_52_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_52_1 = (u32)s_b_52_0 (const) */
        /* execute.simd:3774 [F] s_b_52_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_52_3 = s_b_52_1*s_b_52_2 (const) */
        uint32_t s_b_52_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_52_4 = constant u32 8 (const) */
        /* execute.simd:3774 [F] s_b_52_5 = s_b_52_3+s_b_52_4 (const) */
        uint32_t s_b_52_5 = ((uint32_t)(s_b_52_3 + (uint32_t)8ULL));
        /* execute.simd:3774 [F] s_b_52_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_52_7 = (u32)s_b_52_6 (const) */
        /* execute.simd:3774 [F] s_b_52_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_52_9 = s_b_52_7*s_b_52_8 (const) */
        uint32_t s_b_52_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_52_10 = sym_34102_0_rm uint8_t */
        auto s_b_52_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_52_11 = (u32)s_b_52_10 */
        auto s_b_52_11 = emitter.zx(s_b_52_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_52_12 = s_b_52_9+s_b_52_11 */
        auto s_b_52_12 = emitter.add(emitter.const_u32(s_b_52_9), s_b_52_11);
        /* execute.simd:3774 [D] s_b_52_13 = ReadRegBank 23:s_b_52_12 (u8) */
        dbt::el::Value *s_b_52_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_52_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_52_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_52_14: WriteRegBank 23:s_b_52_5 = s_b_52_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_52_5))),s_b_52_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_52_5))),s_b_52_13);
        /* execute.simd:3774 [F] s_b_52_15: Jump b_53 (const) */
        {
          auto block = block_b_53;
          dynamic_block_queue.push(block_b_53);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_53) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_53);
        /* execute.simd:3771 [F] s_b_53_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_53_1 = (u32)s_b_53_0 (const) */
        /* execute.simd:3771 [F] s_b_53_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_53_3 = s_b_53_1*s_b_53_2 (const) */
        uint32_t s_b_53_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_53_4 = constant u32 9 (const) */
        /* execute.simd:3771 [F] s_b_53_5 = s_b_53_3+s_b_53_4 (const) */
        uint32_t s_b_53_5 = ((uint32_t)(s_b_53_3 + (uint32_t)9ULL));
        /* execute.simd:3771 [D] s_b_53_6 = ReadRegBank 23:s_b_53_5 (u8) */
        auto s_b_53_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_53_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_53_5))),s_b_53_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_53_7: sym_34102_0_rm = s_b_53_6, dominates: s_b_55_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_53_6);
        /* execute.simd:3773 [F] s_b_53_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_53_9 = (u32)s_b_53_8 (const) */
        /* execute.simd:3773 [F] s_b_53_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_53_11 = s_b_53_9+s_b_53_10 (const) */
        uint32_t s_b_53_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_53_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_53_13 = s_b_53_12*s_b_53_11 (const) */
        uint32_t s_b_53_13 = ((uint32_t)((uint32_t)16ULL * s_b_53_11));
        /* execute.simd:3773 [D] s_b_53_14 = (u32)s_b_53_6 */
        auto s_b_53_14 = emitter.zx(s_b_53_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_53_15 = s_b_53_14<s_b_53_13 */
        auto s_b_53_15 = emitter.cmp_lt(s_b_53_14, emitter.const_u32(s_b_53_13));
        /* execute.simd:3773 [D] s_b_53_16: If s_b_53_15: Jump b_55 else b_57 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_55;
            dynamic_block_queue.push(block_b_55);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_57;
            dynamic_block_queue.push(block_b_57);
            false_target = block;
          }
          emitter.branch(s_b_53_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_54) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_54);
        /* execute.simd:3776 [F] s_b_54_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_54_1 = (u32)s_b_54_0 (const) */
        /* execute.simd:3776 [F] s_b_54_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_54_3 = s_b_54_1*s_b_54_2 (const) */
        uint32_t s_b_54_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_54_4 = constant u32 8 (const) */
        /* execute.simd:3776 [F] s_b_54_5 = s_b_54_3+s_b_54_4 (const) */
        uint32_t s_b_54_5 = ((uint32_t)(s_b_54_3 + (uint32_t)8ULL));
        /* execute.simd:3776 [F] s_b_54_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_54_7: WriteRegBank 23:s_b_54_5 = s_b_54_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_54_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_54_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_54_8: Jump b_53 (const) */
        {
          auto block = block_b_53;
          dynamic_block_queue.push(block_b_53);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_55) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_55);
        /* execute.simd:3774 [F] s_b_55_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_55_1 = (u32)s_b_55_0 (const) */
        /* execute.simd:3774 [F] s_b_55_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_55_3 = s_b_55_1*s_b_55_2 (const) */
        uint32_t s_b_55_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_55_4 = constant u32 9 (const) */
        /* execute.simd:3774 [F] s_b_55_5 = s_b_55_3+s_b_55_4 (const) */
        uint32_t s_b_55_5 = ((uint32_t)(s_b_55_3 + (uint32_t)9ULL));
        /* execute.simd:3774 [F] s_b_55_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_55_7 = (u32)s_b_55_6 (const) */
        /* execute.simd:3774 [F] s_b_55_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_55_9 = s_b_55_7*s_b_55_8 (const) */
        uint32_t s_b_55_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_55_10 = sym_34102_0_rm uint8_t */
        auto s_b_55_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_55_11 = (u32)s_b_55_10 */
        auto s_b_55_11 = emitter.zx(s_b_55_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_55_12 = s_b_55_9+s_b_55_11 */
        auto s_b_55_12 = emitter.add(emitter.const_u32(s_b_55_9), s_b_55_11);
        /* execute.simd:3774 [D] s_b_55_13 = ReadRegBank 23:s_b_55_12 (u8) */
        dbt::el::Value *s_b_55_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_55_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_55_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_55_14: WriteRegBank 23:s_b_55_5 = s_b_55_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_55_5))),s_b_55_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_55_5))),s_b_55_13);
        /* execute.simd:3774 [F] s_b_55_15: Jump b_56 (const) */
        {
          auto block = block_b_56;
          dynamic_block_queue.push(block_b_56);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_56) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_56);
        /* execute.simd:3771 [F] s_b_56_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_56_1 = (u32)s_b_56_0 (const) */
        /* execute.simd:3771 [F] s_b_56_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_56_3 = s_b_56_1*s_b_56_2 (const) */
        uint32_t s_b_56_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_56_4 = constant u32 a (const) */
        /* execute.simd:3771 [F] s_b_56_5 = s_b_56_3+s_b_56_4 (const) */
        uint32_t s_b_56_5 = ((uint32_t)(s_b_56_3 + (uint32_t)10ULL));
        /* execute.simd:3771 [D] s_b_56_6 = ReadRegBank 23:s_b_56_5 (u8) */
        auto s_b_56_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_56_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_56_5))),s_b_56_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_56_7: sym_34102_0_rm = s_b_56_6, dominates: s_b_58_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_56_6);
        /* execute.simd:3773 [F] s_b_56_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_56_9 = (u32)s_b_56_8 (const) */
        /* execute.simd:3773 [F] s_b_56_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_56_11 = s_b_56_9+s_b_56_10 (const) */
        uint32_t s_b_56_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_56_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_56_13 = s_b_56_12*s_b_56_11 (const) */
        uint32_t s_b_56_13 = ((uint32_t)((uint32_t)16ULL * s_b_56_11));
        /* execute.simd:3773 [D] s_b_56_14 = (u32)s_b_56_6 */
        auto s_b_56_14 = emitter.zx(s_b_56_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_56_15 = s_b_56_14<s_b_56_13 */
        auto s_b_56_15 = emitter.cmp_lt(s_b_56_14, emitter.const_u32(s_b_56_13));
        /* execute.simd:3773 [D] s_b_56_16: If s_b_56_15: Jump b_58 else b_60 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_58;
            dynamic_block_queue.push(block_b_58);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_60;
            dynamic_block_queue.push(block_b_60);
            false_target = block;
          }
          emitter.branch(s_b_56_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_57) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_57);
        /* execute.simd:3776 [F] s_b_57_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_57_1 = (u32)s_b_57_0 (const) */
        /* execute.simd:3776 [F] s_b_57_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_57_3 = s_b_57_1*s_b_57_2 (const) */
        uint32_t s_b_57_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_57_4 = constant u32 9 (const) */
        /* execute.simd:3776 [F] s_b_57_5 = s_b_57_3+s_b_57_4 (const) */
        uint32_t s_b_57_5 = ((uint32_t)(s_b_57_3 + (uint32_t)9ULL));
        /* execute.simd:3776 [F] s_b_57_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_57_7: WriteRegBank 23:s_b_57_5 = s_b_57_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_57_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_57_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_57_8: Jump b_56 (const) */
        {
          auto block = block_b_56;
          dynamic_block_queue.push(block_b_56);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_58) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_58);
        /* execute.simd:3774 [F] s_b_58_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_58_1 = (u32)s_b_58_0 (const) */
        /* execute.simd:3774 [F] s_b_58_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_58_3 = s_b_58_1*s_b_58_2 (const) */
        uint32_t s_b_58_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_58_4 = constant u32 a (const) */
        /* execute.simd:3774 [F] s_b_58_5 = s_b_58_3+s_b_58_4 (const) */
        uint32_t s_b_58_5 = ((uint32_t)(s_b_58_3 + (uint32_t)10ULL));
        /* execute.simd:3774 [F] s_b_58_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_58_7 = (u32)s_b_58_6 (const) */
        /* execute.simd:3774 [F] s_b_58_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_58_9 = s_b_58_7*s_b_58_8 (const) */
        uint32_t s_b_58_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_58_10 = sym_34102_0_rm uint8_t */
        auto s_b_58_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_58_11 = (u32)s_b_58_10 */
        auto s_b_58_11 = emitter.zx(s_b_58_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_58_12 = s_b_58_9+s_b_58_11 */
        auto s_b_58_12 = emitter.add(emitter.const_u32(s_b_58_9), s_b_58_11);
        /* execute.simd:3774 [D] s_b_58_13 = ReadRegBank 23:s_b_58_12 (u8) */
        dbt::el::Value *s_b_58_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_58_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_58_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_58_14: WriteRegBank 23:s_b_58_5 = s_b_58_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_58_5))),s_b_58_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_58_5))),s_b_58_13);
        /* execute.simd:3774 [F] s_b_58_15: Jump b_59 (const) */
        {
          auto block = block_b_59;
          dynamic_block_queue.push(block_b_59);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_59) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_59);
        /* execute.simd:3771 [F] s_b_59_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_59_1 = (u32)s_b_59_0 (const) */
        /* execute.simd:3771 [F] s_b_59_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_59_3 = s_b_59_1*s_b_59_2 (const) */
        uint32_t s_b_59_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_59_4 = constant u32 b (const) */
        /* execute.simd:3771 [F] s_b_59_5 = s_b_59_3+s_b_59_4 (const) */
        uint32_t s_b_59_5 = ((uint32_t)(s_b_59_3 + (uint32_t)11ULL));
        /* execute.simd:3771 [D] s_b_59_6 = ReadRegBank 23:s_b_59_5 (u8) */
        auto s_b_59_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_59_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_59_5))),s_b_59_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_59_7: sym_34102_0_rm = s_b_59_6, dominates: s_b_61_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_59_6);
        /* execute.simd:3773 [F] s_b_59_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_59_9 = (u32)s_b_59_8 (const) */
        /* execute.simd:3773 [F] s_b_59_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_59_11 = s_b_59_9+s_b_59_10 (const) */
        uint32_t s_b_59_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_59_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_59_13 = s_b_59_12*s_b_59_11 (const) */
        uint32_t s_b_59_13 = ((uint32_t)((uint32_t)16ULL * s_b_59_11));
        /* execute.simd:3773 [D] s_b_59_14 = (u32)s_b_59_6 */
        auto s_b_59_14 = emitter.zx(s_b_59_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_59_15 = s_b_59_14<s_b_59_13 */
        auto s_b_59_15 = emitter.cmp_lt(s_b_59_14, emitter.const_u32(s_b_59_13));
        /* execute.simd:3773 [D] s_b_59_16: If s_b_59_15: Jump b_61 else b_63 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_61;
            dynamic_block_queue.push(block_b_61);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_63;
            dynamic_block_queue.push(block_b_63);
            false_target = block;
          }
          emitter.branch(s_b_59_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_60) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_60);
        /* execute.simd:3776 [F] s_b_60_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_60_1 = (u32)s_b_60_0 (const) */
        /* execute.simd:3776 [F] s_b_60_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_60_3 = s_b_60_1*s_b_60_2 (const) */
        uint32_t s_b_60_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_60_4 = constant u32 a (const) */
        /* execute.simd:3776 [F] s_b_60_5 = s_b_60_3+s_b_60_4 (const) */
        uint32_t s_b_60_5 = ((uint32_t)(s_b_60_3 + (uint32_t)10ULL));
        /* execute.simd:3776 [F] s_b_60_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_60_7: WriteRegBank 23:s_b_60_5 = s_b_60_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_60_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_60_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_60_8: Jump b_59 (const) */
        {
          auto block = block_b_59;
          dynamic_block_queue.push(block_b_59);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_61) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_61);
        /* execute.simd:3774 [F] s_b_61_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_61_1 = (u32)s_b_61_0 (const) */
        /* execute.simd:3774 [F] s_b_61_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_61_3 = s_b_61_1*s_b_61_2 (const) */
        uint32_t s_b_61_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_61_4 = constant u32 b (const) */
        /* execute.simd:3774 [F] s_b_61_5 = s_b_61_3+s_b_61_4 (const) */
        uint32_t s_b_61_5 = ((uint32_t)(s_b_61_3 + (uint32_t)11ULL));
        /* execute.simd:3774 [F] s_b_61_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_61_7 = (u32)s_b_61_6 (const) */
        /* execute.simd:3774 [F] s_b_61_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_61_9 = s_b_61_7*s_b_61_8 (const) */
        uint32_t s_b_61_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_61_10 = sym_34102_0_rm uint8_t */
        auto s_b_61_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_61_11 = (u32)s_b_61_10 */
        auto s_b_61_11 = emitter.zx(s_b_61_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_61_12 = s_b_61_9+s_b_61_11 */
        auto s_b_61_12 = emitter.add(emitter.const_u32(s_b_61_9), s_b_61_11);
        /* execute.simd:3774 [D] s_b_61_13 = ReadRegBank 23:s_b_61_12 (u8) */
        dbt::el::Value *s_b_61_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_61_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_61_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_61_14: WriteRegBank 23:s_b_61_5 = s_b_61_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_61_5))),s_b_61_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_61_5))),s_b_61_13);
        /* execute.simd:3774 [F] s_b_61_15: Jump b_62 (const) */
        {
          auto block = block_b_62;
          dynamic_block_queue.push(block_b_62);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_62) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_62);
        /* execute.simd:3771 [F] s_b_62_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_62_1 = (u32)s_b_62_0 (const) */
        /* execute.simd:3771 [F] s_b_62_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_62_3 = s_b_62_1*s_b_62_2 (const) */
        uint32_t s_b_62_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_62_4 = constant u32 c (const) */
        /* execute.simd:3771 [F] s_b_62_5 = s_b_62_3+s_b_62_4 (const) */
        uint32_t s_b_62_5 = ((uint32_t)(s_b_62_3 + (uint32_t)12ULL));
        /* execute.simd:3771 [D] s_b_62_6 = ReadRegBank 23:s_b_62_5 (u8) */
        auto s_b_62_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_62_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_62_5))),s_b_62_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_62_7: sym_34102_0_rm = s_b_62_6, dominates: s_b_64_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_62_6);
        /* execute.simd:3773 [F] s_b_62_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_62_9 = (u32)s_b_62_8 (const) */
        /* execute.simd:3773 [F] s_b_62_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_62_11 = s_b_62_9+s_b_62_10 (const) */
        uint32_t s_b_62_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_62_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_62_13 = s_b_62_12*s_b_62_11 (const) */
        uint32_t s_b_62_13 = ((uint32_t)((uint32_t)16ULL * s_b_62_11));
        /* execute.simd:3773 [D] s_b_62_14 = (u32)s_b_62_6 */
        auto s_b_62_14 = emitter.zx(s_b_62_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_62_15 = s_b_62_14<s_b_62_13 */
        auto s_b_62_15 = emitter.cmp_lt(s_b_62_14, emitter.const_u32(s_b_62_13));
        /* execute.simd:3773 [D] s_b_62_16: If s_b_62_15: Jump b_64 else b_66 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_64;
            dynamic_block_queue.push(block_b_64);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_66;
            dynamic_block_queue.push(block_b_66);
            false_target = block;
          }
          emitter.branch(s_b_62_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_63) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_63);
        /* execute.simd:3776 [F] s_b_63_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_63_1 = (u32)s_b_63_0 (const) */
        /* execute.simd:3776 [F] s_b_63_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_63_3 = s_b_63_1*s_b_63_2 (const) */
        uint32_t s_b_63_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_63_4 = constant u32 b (const) */
        /* execute.simd:3776 [F] s_b_63_5 = s_b_63_3+s_b_63_4 (const) */
        uint32_t s_b_63_5 = ((uint32_t)(s_b_63_3 + (uint32_t)11ULL));
        /* execute.simd:3776 [F] s_b_63_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_63_7: WriteRegBank 23:s_b_63_5 = s_b_63_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_63_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_63_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_63_8: Jump b_62 (const) */
        {
          auto block = block_b_62;
          dynamic_block_queue.push(block_b_62);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_64) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_64);
        /* execute.simd:3774 [F] s_b_64_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_64_1 = (u32)s_b_64_0 (const) */
        /* execute.simd:3774 [F] s_b_64_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_64_3 = s_b_64_1*s_b_64_2 (const) */
        uint32_t s_b_64_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_64_4 = constant u32 c (const) */
        /* execute.simd:3774 [F] s_b_64_5 = s_b_64_3+s_b_64_4 (const) */
        uint32_t s_b_64_5 = ((uint32_t)(s_b_64_3 + (uint32_t)12ULL));
        /* execute.simd:3774 [F] s_b_64_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_64_7 = (u32)s_b_64_6 (const) */
        /* execute.simd:3774 [F] s_b_64_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_64_9 = s_b_64_7*s_b_64_8 (const) */
        uint32_t s_b_64_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_64_10 = sym_34102_0_rm uint8_t */
        auto s_b_64_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_64_11 = (u32)s_b_64_10 */
        auto s_b_64_11 = emitter.zx(s_b_64_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_64_12 = s_b_64_9+s_b_64_11 */
        auto s_b_64_12 = emitter.add(emitter.const_u32(s_b_64_9), s_b_64_11);
        /* execute.simd:3774 [D] s_b_64_13 = ReadRegBank 23:s_b_64_12 (u8) */
        dbt::el::Value *s_b_64_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_64_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_64_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_64_14: WriteRegBank 23:s_b_64_5 = s_b_64_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_64_5))),s_b_64_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_64_5))),s_b_64_13);
        /* execute.simd:3774 [F] s_b_64_15: Jump b_65 (const) */
        {
          auto block = block_b_65;
          dynamic_block_queue.push(block_b_65);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_65) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_65);
        /* execute.simd:3771 [F] s_b_65_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_65_1 = (u32)s_b_65_0 (const) */
        /* execute.simd:3771 [F] s_b_65_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_65_3 = s_b_65_1*s_b_65_2 (const) */
        uint32_t s_b_65_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_65_4 = constant u32 d (const) */
        /* execute.simd:3771 [F] s_b_65_5 = s_b_65_3+s_b_65_4 (const) */
        uint32_t s_b_65_5 = ((uint32_t)(s_b_65_3 + (uint32_t)13ULL));
        /* execute.simd:3771 [D] s_b_65_6 = ReadRegBank 23:s_b_65_5 (u8) */
        auto s_b_65_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_65_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_65_5))),s_b_65_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_65_7: sym_34102_0_rm = s_b_65_6, dominates: s_b_67_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_65_6);
        /* execute.simd:3773 [F] s_b_65_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_65_9 = (u32)s_b_65_8 (const) */
        /* execute.simd:3773 [F] s_b_65_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_65_11 = s_b_65_9+s_b_65_10 (const) */
        uint32_t s_b_65_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_65_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_65_13 = s_b_65_12*s_b_65_11 (const) */
        uint32_t s_b_65_13 = ((uint32_t)((uint32_t)16ULL * s_b_65_11));
        /* execute.simd:3773 [D] s_b_65_14 = (u32)s_b_65_6 */
        auto s_b_65_14 = emitter.zx(s_b_65_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_65_15 = s_b_65_14<s_b_65_13 */
        auto s_b_65_15 = emitter.cmp_lt(s_b_65_14, emitter.const_u32(s_b_65_13));
        /* execute.simd:3773 [D] s_b_65_16: If s_b_65_15: Jump b_67 else b_69 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_67;
            dynamic_block_queue.push(block_b_67);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_69;
            dynamic_block_queue.push(block_b_69);
            false_target = block;
          }
          emitter.branch(s_b_65_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_66) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_66);
        /* execute.simd:3776 [F] s_b_66_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_66_1 = (u32)s_b_66_0 (const) */
        /* execute.simd:3776 [F] s_b_66_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_66_3 = s_b_66_1*s_b_66_2 (const) */
        uint32_t s_b_66_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_66_4 = constant u32 c (const) */
        /* execute.simd:3776 [F] s_b_66_5 = s_b_66_3+s_b_66_4 (const) */
        uint32_t s_b_66_5 = ((uint32_t)(s_b_66_3 + (uint32_t)12ULL));
        /* execute.simd:3776 [F] s_b_66_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_66_7: WriteRegBank 23:s_b_66_5 = s_b_66_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_66_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_66_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_66_8: Jump b_65 (const) */
        {
          auto block = block_b_65;
          dynamic_block_queue.push(block_b_65);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_67) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_67);
        /* execute.simd:3774 [F] s_b_67_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_67_1 = (u32)s_b_67_0 (const) */
        /* execute.simd:3774 [F] s_b_67_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_67_3 = s_b_67_1*s_b_67_2 (const) */
        uint32_t s_b_67_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_67_4 = constant u32 d (const) */
        /* execute.simd:3774 [F] s_b_67_5 = s_b_67_3+s_b_67_4 (const) */
        uint32_t s_b_67_5 = ((uint32_t)(s_b_67_3 + (uint32_t)13ULL));
        /* execute.simd:3774 [F] s_b_67_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_67_7 = (u32)s_b_67_6 (const) */
        /* execute.simd:3774 [F] s_b_67_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_67_9 = s_b_67_7*s_b_67_8 (const) */
        uint32_t s_b_67_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_67_10 = sym_34102_0_rm uint8_t */
        auto s_b_67_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_67_11 = (u32)s_b_67_10 */
        auto s_b_67_11 = emitter.zx(s_b_67_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_67_12 = s_b_67_9+s_b_67_11 */
        auto s_b_67_12 = emitter.add(emitter.const_u32(s_b_67_9), s_b_67_11);
        /* execute.simd:3774 [D] s_b_67_13 = ReadRegBank 23:s_b_67_12 (u8) */
        dbt::el::Value *s_b_67_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_67_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_67_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_67_14: WriteRegBank 23:s_b_67_5 = s_b_67_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_67_5))),s_b_67_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_67_5))),s_b_67_13);
        /* execute.simd:3774 [F] s_b_67_15: Jump b_68 (const) */
        {
          auto block = block_b_68;
          dynamic_block_queue.push(block_b_68);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_68) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_68);
        /* execute.simd:3771 [F] s_b_68_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_68_1 = (u32)s_b_68_0 (const) */
        /* execute.simd:3771 [F] s_b_68_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_68_3 = s_b_68_1*s_b_68_2 (const) */
        uint32_t s_b_68_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_68_4 = constant u32 e (const) */
        /* execute.simd:3771 [F] s_b_68_5 = s_b_68_3+s_b_68_4 (const) */
        uint32_t s_b_68_5 = ((uint32_t)(s_b_68_3 + (uint32_t)14ULL));
        /* execute.simd:3771 [D] s_b_68_6 = ReadRegBank 23:s_b_68_5 (u8) */
        auto s_b_68_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_68_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_68_5))),s_b_68_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_68_7: sym_34102_0_rm = s_b_68_6, dominates: s_b_70_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_68_6);
        /* execute.simd:3773 [F] s_b_68_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_68_9 = (u32)s_b_68_8 (const) */
        /* execute.simd:3773 [F] s_b_68_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_68_11 = s_b_68_9+s_b_68_10 (const) */
        uint32_t s_b_68_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_68_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_68_13 = s_b_68_12*s_b_68_11 (const) */
        uint32_t s_b_68_13 = ((uint32_t)((uint32_t)16ULL * s_b_68_11));
        /* execute.simd:3773 [D] s_b_68_14 = (u32)s_b_68_6 */
        auto s_b_68_14 = emitter.zx(s_b_68_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_68_15 = s_b_68_14<s_b_68_13 */
        auto s_b_68_15 = emitter.cmp_lt(s_b_68_14, emitter.const_u32(s_b_68_13));
        /* execute.simd:3773 [D] s_b_68_16: If s_b_68_15: Jump b_70 else b_72 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_70;
            dynamic_block_queue.push(block_b_70);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_72;
            dynamic_block_queue.push(block_b_72);
            false_target = block;
          }
          emitter.branch(s_b_68_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_69) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_69);
        /* execute.simd:3776 [F] s_b_69_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_69_1 = (u32)s_b_69_0 (const) */
        /* execute.simd:3776 [F] s_b_69_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_69_3 = s_b_69_1*s_b_69_2 (const) */
        uint32_t s_b_69_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_69_4 = constant u32 d (const) */
        /* execute.simd:3776 [F] s_b_69_5 = s_b_69_3+s_b_69_4 (const) */
        uint32_t s_b_69_5 = ((uint32_t)(s_b_69_3 + (uint32_t)13ULL));
        /* execute.simd:3776 [F] s_b_69_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_69_7: WriteRegBank 23:s_b_69_5 = s_b_69_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_69_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_69_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_69_8: Jump b_68 (const) */
        {
          auto block = block_b_68;
          dynamic_block_queue.push(block_b_68);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_70) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_70);
        /* execute.simd:3774 [F] s_b_70_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_70_1 = (u32)s_b_70_0 (const) */
        /* execute.simd:3774 [F] s_b_70_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_70_3 = s_b_70_1*s_b_70_2 (const) */
        uint32_t s_b_70_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_70_4 = constant u32 e (const) */
        /* execute.simd:3774 [F] s_b_70_5 = s_b_70_3+s_b_70_4 (const) */
        uint32_t s_b_70_5 = ((uint32_t)(s_b_70_3 + (uint32_t)14ULL));
        /* execute.simd:3774 [F] s_b_70_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_70_7 = (u32)s_b_70_6 (const) */
        /* execute.simd:3774 [F] s_b_70_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_70_9 = s_b_70_7*s_b_70_8 (const) */
        uint32_t s_b_70_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_70_10 = sym_34102_0_rm uint8_t */
        auto s_b_70_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_70_11 = (u32)s_b_70_10 */
        auto s_b_70_11 = emitter.zx(s_b_70_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_70_12 = s_b_70_9+s_b_70_11 */
        auto s_b_70_12 = emitter.add(emitter.const_u32(s_b_70_9), s_b_70_11);
        /* execute.simd:3774 [D] s_b_70_13 = ReadRegBank 23:s_b_70_12 (u8) */
        dbt::el::Value *s_b_70_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_70_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_70_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_70_14: WriteRegBank 23:s_b_70_5 = s_b_70_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_70_5))),s_b_70_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_70_5))),s_b_70_13);
        /* execute.simd:3774 [F] s_b_70_15: Jump b_71 (const) */
        {
          auto block = block_b_71;
          dynamic_block_queue.push(block_b_71);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_71) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_71);
        /* execute.simd:3771 [F] s_b_71_0=sym_33582_3_parameter_inst.rm (const) */
        /* execute.simd:3771 [F] s_b_71_1 = (u32)s_b_71_0 (const) */
        /* execute.simd:3771 [F] s_b_71_2 = constant u32 10 (const) */
        /* execute.simd:3771 [F] s_b_71_3 = s_b_71_1*s_b_71_2 (const) */
        uint32_t s_b_71_3 = ((uint32_t)(((uint32_t)insn.rm) * (uint32_t)16ULL));
        /* execute.simd:3771 [F] s_b_71_4 = constant u32 f (const) */
        /* execute.simd:3771 [F] s_b_71_5 = s_b_71_3+s_b_71_4 (const) */
        uint32_t s_b_71_5 = ((uint32_t)(s_b_71_3 + (uint32_t)15ULL));
        /* execute.simd:3771 [D] s_b_71_6 = ReadRegBank 23:s_b_71_5 (u8) */
        auto s_b_71_6 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_71_5))), emitter.context().types().u8());
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (1 * s_b_71_5))),s_b_71_6,emitter.const_u8(1));
        }
        /* execute.simd:3771 [D] s_b_71_7: sym_34102_0_rm = s_b_71_6, dominates: s_b_73_10  */
        emitter.store_local(DV_sym_34102_0_rm, s_b_71_6);
        /* execute.simd:3773 [F] s_b_71_8=sym_33582_3_parameter_inst.len (const) */
        /* execute.simd:3773 [F] s_b_71_9 = (u32)s_b_71_8 (const) */
        /* execute.simd:3773 [F] s_b_71_10 = constant u32 1 (const) */
        /* execute.simd:3773 [F] s_b_71_11 = s_b_71_9+s_b_71_10 (const) */
        uint32_t s_b_71_11 = ((uint32_t)(((uint32_t)insn.len) + (uint32_t)1ULL));
        /* execute.simd:3773 [F] s_b_71_12 = constant u32 10 (const) */
        /* execute.simd:3773 [F] s_b_71_13 = s_b_71_12*s_b_71_11 (const) */
        uint32_t s_b_71_13 = ((uint32_t)((uint32_t)16ULL * s_b_71_11));
        /* execute.simd:3773 [D] s_b_71_14 = (u32)s_b_71_6 */
        auto s_b_71_14 = emitter.zx(s_b_71_6, emitter.context().types().u32());
        /* execute.simd:3773 [D] s_b_71_15 = s_b_71_14<s_b_71_13 */
        auto s_b_71_15 = emitter.cmp_lt(s_b_71_14, emitter.const_u32(s_b_71_13));
        /* execute.simd:3773 [D] s_b_71_16: If s_b_71_15: Jump b_73 else b_74 */
        {
          dbt::el::Block *true_target;
          {
            auto block = block_b_73;
            dynamic_block_queue.push(block_b_73);
            true_target = block;
          }
          dbt::el::Block *false_target;
          {
            auto block = block_b_74;
            dynamic_block_queue.push(block_b_74);
            false_target = block;
          }
          emitter.branch(s_b_71_15, true_target, false_target);
        }
      }
      else if (block_index == block_b_72) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_72);
        /* execute.simd:3776 [F] s_b_72_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_72_1 = (u32)s_b_72_0 (const) */
        /* execute.simd:3776 [F] s_b_72_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_72_3 = s_b_72_1*s_b_72_2 (const) */
        uint32_t s_b_72_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_72_4 = constant u32 e (const) */
        /* execute.simd:3776 [F] s_b_72_5 = s_b_72_3+s_b_72_4 (const) */
        uint32_t s_b_72_5 = ((uint32_t)(s_b_72_3 + (uint32_t)14ULL));
        /* execute.simd:3776 [F] s_b_72_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_72_7: WriteRegBank 23:s_b_72_5 = s_b_72_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_72_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_72_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_72_8: Jump b_71 (const) */
        {
          auto block = block_b_71;
          dynamic_block_queue.push(block_b_71);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_73) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_73);
        /* execute.simd:3774 [F] s_b_73_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3774 [F] s_b_73_1 = (u32)s_b_73_0 (const) */
        /* execute.simd:3774 [F] s_b_73_2 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_73_3 = s_b_73_1*s_b_73_2 (const) */
        uint32_t s_b_73_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3774 [F] s_b_73_4 = constant u32 f (const) */
        /* execute.simd:3774 [F] s_b_73_5 = s_b_73_3+s_b_73_4 (const) */
        uint32_t s_b_73_5 = ((uint32_t)(s_b_73_3 + (uint32_t)15ULL));
        /* execute.simd:3774 [F] s_b_73_6=sym_33582_3_parameter_inst.rn (const) */
        /* execute.simd:3774 [F] s_b_73_7 = (u32)s_b_73_6 (const) */
        /* execute.simd:3774 [F] s_b_73_8 = constant u32 10 (const) */
        /* execute.simd:3774 [F] s_b_73_9 = s_b_73_7*s_b_73_8 (const) */
        uint32_t s_b_73_9 = ((uint32_t)(((uint32_t)insn.rn) * (uint32_t)16ULL));
        /* execute.simd:3774 [D] s_b_73_10 = sym_34102_0_rm uint8_t */
        auto s_b_73_10 = emitter.load_local(DV_sym_34102_0_rm, emitter.context().types().u8());
        /* execute.simd:3774 [D] s_b_73_11 = (u32)s_b_73_10 */
        auto s_b_73_11 = emitter.zx(s_b_73_10, emitter.context().types().u32());
        /* execute.simd:3774 [D] s_b_73_12 = s_b_73_9+s_b_73_11 */
        auto s_b_73_12 = emitter.add(emitter.const_u32(s_b_73_9), s_b_73_11);
        /* execute.simd:3774 [D] s_b_73_13 = ReadRegBank 23:s_b_73_12 (u8) */
        dbt::el::Value *s_b_73_13;
        {
          auto mulp = emitter.mul(emitter.const_u32(1), s_b_73_12);
          auto add = emitter.add(emitter.const_u32(256), mulp);
          s_b_73_13 = emitter.load_register(add, emitter.context().types().u8());
        }
        /* execute.simd:3774 [D] s_b_73_14: WriteRegBank 23:s_b_73_5 = s_b_73_13 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_73_5))),s_b_73_13,emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_73_5))),s_b_73_13);
        /* execute.simd:3774 [F] s_b_73_15: Jump b_2 (const) */
        {
          auto block = block_b_2;
          dynamic_block_queue.push(block_b_2);
          emitter.jump(block);
        }
      }
      else if (block_index == block_b_74) // BLOCK START LINE 0, END LINE 0
      {
        emitter.set_current_block(block_b_74);
        /* execute.simd:3776 [F] s_b_74_0=sym_33582_3_parameter_inst.rd (const) */
        /* execute.simd:3776 [F] s_b_74_1 = (u32)s_b_74_0 (const) */
        /* execute.simd:3776 [F] s_b_74_2 = constant u32 10 (const) */
        /* execute.simd:3776 [F] s_b_74_3 = s_b_74_1*s_b_74_2 (const) */
        uint32_t s_b_74_3 = ((uint32_t)(((uint32_t)insn.rd) * (uint32_t)16ULL));
        /* execute.simd:3776 [F] s_b_74_4 = constant u32 f (const) */
        /* execute.simd:3776 [F] s_b_74_5 = s_b_74_3+s_b_74_4 (const) */
        uint32_t s_b_74_5 = ((uint32_t)(s_b_74_3 + (uint32_t)15ULL));
        /* execute.simd:3776 [F] s_b_74_6 = constant u8 0 (const) */
        /* execute.simd:3776 [F] s_b_74_7: WriteRegBank 23:s_b_74_5 = s_b_74_6 */
        if (TRACE) 
        {
          emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (1 * s_b_74_5))),emitter.const_u8((uint8_t)0ULL),emitter.const_u8(1));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (1 * s_b_74_5))),emitter.const_u8((uint8_t)0ULL));
        /* execute.simd:3776 [F] s_b_74_8: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_ubfm(const aarch64_decode_a64_BITFIELD&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_148113_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148087_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_147772_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_147722_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_147754_1_tmp_s_b_1_12;
  auto DV_sym_148239_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148349_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148217_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148195_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148261_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_148076_1_tmp_s_b_15_13;
  auto DV_sym_148393_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148305_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_147965_0_replaced_parameter_len;
  auto DV_sym_148007_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148283_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_147916_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_147949_0_replaced_parameter_src = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148032_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_148026_0_replaced_parameter_src = emitter.alloc_local(emitter.context().types().u64(), false);
  uint8_t CV_sym_148042_0_replaced_parameter_len;
  auto DV_sym_147955_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_39468_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:112 [F] s_b_0_0=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:112 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:112 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:112 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:112 [F] s_b_0_4=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:112 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:112 [F] s_b_0_6 = constant u32 1f (const) */
    /* execute.a64:112 [F] s_b_0_7 = s_b_0_5!=s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.imms) != (uint32_t)31ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:112 [F] s_b_0_12=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:112 [F] s_b_0_13 = (u32)s_b_0_12 (const) */
    /* execute.a64:112 [F] s_b_0_14 = constant u32 1 (const) */
    /* execute.a64:112 [F] s_b_0_15 = s_b_0_13==s_b_0_14 (const) */
    uint8_t s_b_0_15 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.a64:112 [F] s_b_0_16=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:112 [F] s_b_0_17 = (u32)s_b_0_16 (const) */
    /* execute.a64:112 [F] s_b_0_18 = constant u32 3f (const) */
    /* execute.a64:112 [F] s_b_0_19 = s_b_0_17!=s_b_0_18 (const) */
    uint8_t s_b_0_19 = ((uint8_t)(((uint32_t)insn.imms) != (uint32_t)63ULL));
    /* ???:4294967295 [F] s_b_0_20 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_21 = s_b_0_15!=s_b_0_20 (const) */
    uint8_t s_b_0_21 = ((uint8_t)(s_b_0_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_22 = s_b_0_19!=s_b_0_20 (const) */
    uint8_t s_b_0_22 = ((uint8_t)(s_b_0_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_23 = s_b_0_21&s_b_0_22 (const) */
    uint8_t s_b_0_23 = ((uint8_t)(s_b_0_21 & s_b_0_22));
    /* ???:4294967295 [F] s_b_0_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_25 = s_b_0_11!=s_b_0_24 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(s_b_0_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_26 = s_b_0_23!=s_b_0_24 (const) */
    uint8_t s_b_0_26 = ((uint8_t)(s_b_0_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_27 = s_b_0_25|s_b_0_26 (const) */
    uint8_t s_b_0_27 = ((uint8_t)(s_b_0_25 | s_b_0_26));
    /* execute.a64:112 [F] s_b_0_28=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:112 [F] s_b_0_29 = (u32)s_b_0_28 (const) */
    /* execute.a64:112 [F] s_b_0_30 = constant u32 1 (const) */
    /* execute.a64:112 [F] s_b_0_31 = s_b_0_29+s_b_0_30 (const) */
    uint32_t s_b_0_31 = ((uint32_t)(((uint32_t)insn.imms) + (uint32_t)1ULL));
    /* execute.a64:112 [F] s_b_0_32=sym_39265_3_parameter_inst.immr (const) */
    /* execute.a64:112 [F] s_b_0_33 = (u32)s_b_0_32 (const) */
    /* execute.a64:112 [F] s_b_0_34 = s_b_0_31==s_b_0_33 (const) */
    uint8_t s_b_0_34 = ((uint8_t)(s_b_0_31 == ((uint32_t)insn.immr)));
    /* ???:4294967295 [F] s_b_0_35 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_36 = s_b_0_27!=s_b_0_35 (const) */
    uint8_t s_b_0_36 = ((uint8_t)(s_b_0_27 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_37 = s_b_0_34!=s_b_0_35 (const) */
    uint8_t s_b_0_37 = ((uint8_t)(s_b_0_34 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_38 = s_b_0_36&s_b_0_37 (const) */
    uint8_t s_b_0_38 = ((uint8_t)(s_b_0_36 & s_b_0_37));
    /* execute.a64:112 [F] s_b_0_39: If s_b_0_38: Jump b_1 else b_3 (const) */
    if (s_b_0_38) 
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
    /* execute.a64:114 [F] s_b_1_0=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:114 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:114 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.a64:114 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:114 [F] s_b_1_4 = constant s32 1f (const) */
    /* execute.a64:114 [F] s_b_1_5 = constant s32 3f (const) */
    /* execute.a64:114 [F] s_b_1_6: Select s_b_1_3 ? s_b_1_4 : s_b_1_5 (const) */
    int32_t s_b_1_6 = ((int32_t)(s_b_1_3 ? ((int32_t)31ULL) : ((int32_t)63ULL)));
    /* execute.a64:114 [F] s_b_1_7=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:114 [F] s_b_1_8 = (u32)s_b_1_6 (const) */
    /* execute.a64:114 [F] s_b_1_9 = (u32)s_b_1_7 (const) */
    /* execute.a64:114 [F] s_b_1_10 = s_b_1_8-s_b_1_9 (const) */
    uint32_t s_b_1_10 = ((uint32_t)(((uint32_t)s_b_1_6) - ((uint32_t)insn.imms)));
    /* execute.a64:114 [F] s_b_1_11 = (u8)s_b_1_10 (const) */
    /* execute.a64:115 [F] s_b_1_12=sym_39265_3_parameter_inst.sf (const) */
    /* ???:4294967295 [F] s_b_1_13: sym_147754_1_tmp_s_b_1_12 = s_b_1_11 (const), dominates: s_b_14_2  */
    CV_sym_147754_1_tmp_s_b_1_12 = ((uint8_t)s_b_1_10);
    /* execute.a64:2656 [F] s_b_1_14: If s_b_1_12: Jump b_13 else b_15 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_13;
    }
    else 
    {
      goto fixed_block_b_15;
    }
  }
  /* b_6, b_8, b_25, b_26, b_30, b_31, b_32, b_33, b_34, b_35, b_36, b_37, b_38, b_39, b_40, b_41,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:116 [F] s_b_3_0=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:116 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:116 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:116 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:116 [F] s_b_3_4=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:116 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:116 [F] s_b_3_6 = constant u32 1f (const) */
    /* execute.a64:116 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.imms) == (uint32_t)31ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:116 [F] s_b_3_12=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:116 [F] s_b_3_13 = (u32)s_b_3_12 (const) */
    /* execute.a64:116 [F] s_b_3_14 = constant u32 1 (const) */
    /* execute.a64:116 [F] s_b_3_15 = s_b_3_13==s_b_3_14 (const) */
    uint8_t s_b_3_15 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)1ULL));
    /* execute.a64:116 [F] s_b_3_16=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:116 [F] s_b_3_17 = (u32)s_b_3_16 (const) */
    /* execute.a64:116 [F] s_b_3_18 = constant u32 3f (const) */
    /* execute.a64:116 [F] s_b_3_19 = s_b_3_17==s_b_3_18 (const) */
    uint8_t s_b_3_19 = ((uint8_t)(((uint32_t)insn.imms) == (uint32_t)63ULL));
    /* ???:4294967295 [F] s_b_3_20 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_21 = s_b_3_15!=s_b_3_20 (const) */
    uint8_t s_b_3_21 = ((uint8_t)(s_b_3_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_22 = s_b_3_19!=s_b_3_20 (const) */
    uint8_t s_b_3_22 = ((uint8_t)(s_b_3_19 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_23 = s_b_3_21&s_b_3_22 (const) */
    uint8_t s_b_3_23 = ((uint8_t)(s_b_3_21 & s_b_3_22));
    /* ???:4294967295 [F] s_b_3_24 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_25 = s_b_3_11!=s_b_3_24 (const) */
    uint8_t s_b_3_25 = ((uint8_t)(s_b_3_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_26 = s_b_3_23!=s_b_3_24 (const) */
    uint8_t s_b_3_26 = ((uint8_t)(s_b_3_23 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_27 = s_b_3_25|s_b_3_26 (const) */
    uint8_t s_b_3_27 = ((uint8_t)(s_b_3_25 | s_b_3_26));
    /* execute.a64:116 [F] s_b_3_28: If s_b_3_27: Jump b_4 else b_5 (const) */
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
    /* execute.a64:119 [F] s_b_4_0=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_4_1: If s_b_4_0: Jump b_16 else b_18 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_16;
    }
    else 
    {
      goto fixed_block_b_18;
    }
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:120 [F] s_b_5_0=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:120 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:120 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:120 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:120 [F] s_b_5_4=sym_39265_3_parameter_inst.immr (const) */
    /* execute.a64:120 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:120 [F] s_b_5_6 = constant u32 0 (const) */
    /* execute.a64:120 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.immr) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:120 [F] s_b_5_12=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:120 [F] s_b_5_13 = (u32)s_b_5_12 (const) */
    /* execute.a64:120 [F] s_b_5_14 = constant u32 7 (const) */
    /* execute.a64:120 [F] s_b_5_15 = s_b_5_13==s_b_5_14 (const) */
    uint8_t s_b_5_15 = ((uint8_t)(((uint32_t)insn.imms) == (uint32_t)7ULL));
    /* ???:4294967295 [F] s_b_5_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_17 = s_b_5_11!=s_b_5_16 (const) */
    uint8_t s_b_5_17 = ((uint8_t)(s_b_5_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_18 = s_b_5_15!=s_b_5_16 (const) */
    uint8_t s_b_5_18 = ((uint8_t)(s_b_5_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_19 = s_b_5_17&s_b_5_18 (const) */
    uint8_t s_b_5_19 = ((uint8_t)(s_b_5_17 & s_b_5_18));
    /* execute.a64:120 [F] s_b_5_20: If s_b_5_19: Jump b_6 else b_7 (const) */
    if (s_b_5_19) 
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
    /* execute.a64:122 [F] s_b_6_0=sym_39265_3_parameter_inst.rn (const) */
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
    /* execute.a64:122 [D] s_b_6_8 = (u8)s_b_6_7 */
    auto s_b_6_8 = emitter.truncate(s_b_6_7, emitter.context().types().u8());
    /* execute.a64:122 [D] s_b_6_9 = (u64)s_b_6_8 */
    auto s_b_6_9 = emitter.zx(s_b_6_8, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_6_10=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_6_11 = (u32)s_b_6_9 */
    auto s_b_6_11 = emitter.truncate(s_b_6_9, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_6_12 = (u64)s_b_6_11 */
    auto s_b_6_12 = emitter.zx(s_b_6_11, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_6_13: sym_148349_3_parameter_value = s_b_6_12, dominates: s_b_40_1  */
    emitter.store_local(DV_sym_148349_3_parameter_value, s_b_6_12);
    /* execute.a64:2682 [F] s_b_6_14 = (u32)s_b_6_10 (const) */
    /* execute.a64:2682 [F] s_b_6_15 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_6_16 = s_b_6_14==s_b_6_15 (const) */
    uint8_t s_b_6_16 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_6_17: If s_b_6_16: Jump b_2 else b_40 (const) */
    if (s_b_6_16) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_40;
    }
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.a64:123 [F] s_b_7_0=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:123 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:123 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.a64:123 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:123 [F] s_b_7_4=sym_39265_3_parameter_inst.immr (const) */
    /* execute.a64:123 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:123 [F] s_b_7_6 = constant u32 0 (const) */
    /* execute.a64:123 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.immr) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:123 [F] s_b_7_12=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:123 [F] s_b_7_13 = (u32)s_b_7_12 (const) */
    /* execute.a64:123 [F] s_b_7_14 = constant u32 f (const) */
    /* execute.a64:123 [F] s_b_7_15 = s_b_7_13==s_b_7_14 (const) */
    uint8_t s_b_7_15 = ((uint8_t)(((uint32_t)insn.imms) == (uint32_t)15ULL));
    /* ???:4294967295 [F] s_b_7_16 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_17 = s_b_7_11!=s_b_7_16 (const) */
    uint8_t s_b_7_17 = ((uint8_t)(s_b_7_11 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_18 = s_b_7_15!=s_b_7_16 (const) */
    uint8_t s_b_7_18 = ((uint8_t)(s_b_7_15 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_19 = s_b_7_17&s_b_7_18 (const) */
    uint8_t s_b_7_19 = ((uint8_t)(s_b_7_17 & s_b_7_18));
    /* execute.a64:123 [F] s_b_7_20: If s_b_7_19: Jump b_8 else b_9 (const) */
    if (s_b_7_19) 
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
    /* execute.a64:125 [F] s_b_8_0=sym_39265_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_8_1 = (u32)s_b_8_0 (const) */
    /* execute.a64:2646 [F] s_b_8_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_8_3 = s_b_8_1==s_b_8_2 (const) */
    uint8_t s_b_8_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_8_5 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_8_6: Select s_b_8_3 ? s_b_8_4 : s_b_8_5 */
    dbt::el::Value *s_b_8_6;
    s_b_8_6 = (s_b_8_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_8_5);
    /* execute.a64:2659 [D] s_b_8_7 = (u64)s_b_8_6 */
    auto s_b_8_7 = emitter.zx(s_b_8_6, emitter.context().types().u64());
    /* execute.a64:125 [D] s_b_8_8 = (u16)s_b_8_7 */
    auto s_b_8_8 = emitter.truncate(s_b_8_7, emitter.context().types().u16());
    /* execute.a64:125 [D] s_b_8_9 = (u64)s_b_8_8 */
    auto s_b_8_9 = emitter.zx(s_b_8_8, emitter.context().types().u64());
    /* execute.a64:2693 [F] s_b_8_10=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_8_11 = (u32)s_b_8_9 */
    auto s_b_8_11 = emitter.truncate(s_b_8_9, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_8_12 = (u64)s_b_8_11 */
    auto s_b_8_12 = emitter.zx(s_b_8_11, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_8_13: sym_148393_3_parameter_value = s_b_8_12, dominates: s_b_41_1  */
    emitter.store_local(DV_sym_148393_3_parameter_value, s_b_8_12);
    /* execute.a64:2682 [F] s_b_8_14 = (u32)s_b_8_10 (const) */
    /* execute.a64:2682 [F] s_b_8_15 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_8_16 = s_b_8_14==s_b_8_15 (const) */
    uint8_t s_b_8_16 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_8_17: If s_b_8_16: Jump b_2 else b_41 (const) */
    if (s_b_8_16) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_41;
    }
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.a64:127 [F] s_b_9_0=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:2656 [F] s_b_9_1: If s_b_9_0: Jump b_19 else b_21 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_19;
    }
    else 
    {
      goto fixed_block_b_21;
    }
  }
  /* b_20,  */
  fixed_block_b_10: 
  {
    /* execute.a64:131 [F] s_b_10_0=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:131 [F] s_b_10_1=sym_39265_3_parameter_inst.immr (const) */
    /* execute.a64:131 [F] s_b_10_2 = s_b_10_0-s_b_10_1 (const) */
    uint8_t s_b_10_2 = ((uint8_t)(insn.imms - insn.immr));
    /* execute.a64:131 [F] s_b_10_3 = (u32)s_b_10_2 (const) */
    /* execute.a64:131 [F] s_b_10_4 = constant u32 1 (const) */
    /* execute.a64:131 [F] s_b_10_5 = s_b_10_3+s_b_10_4 (const) */
    uint32_t s_b_10_5 = ((uint32_t)(((uint32_t)s_b_10_2) + (uint32_t)1ULL));
    /* execute.a64:131 [F] s_b_10_6 = (u8)s_b_10_5 (const) */
    /* execute.a64:133 [D] s_b_10_7 = sym_39468_0_value uint64_t */
    auto s_b_10_7 = emitter.load_local(DV_sym_39468_0_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_8: sym_147949_0_replaced_parameter_src = s_b_10_7, dominates: s_b_22_0 s_b_24_0  */
    emitter.store_local(DV_sym_147949_0_replaced_parameter_src, s_b_10_7);
    /* ???:4294967295 [F] s_b_10_9: sym_147965_0_replaced_parameter_len = s_b_10_6 (const), dominates: s_b_24_5  */
    CV_sym_147965_0_replaced_parameter_len = ((uint8_t)s_b_10_5);
    /* execute.a64:2507 [F] s_b_10_10 = (u32)s_b_10_6 (const) */
    /* execute.a64:2507 [F] s_b_10_11 = constant u32 40 (const) */
    /* execute.a64:2507 [F] s_b_10_12 = s_b_10_10>=s_b_10_11 (const) */
    uint8_t s_b_10_12 = ((uint8_t)(((uint32_t)((uint8_t)s_b_10_5)) >= (uint32_t)64ULL));
    /* execute.a64:2507 [F] s_b_10_13: If s_b_10_12: Jump b_22 else b_24 (const) */
    if (s_b_10_12) 
    {
      goto fixed_block_b_22;
    }
    else 
    {
      goto fixed_block_b_24;
    }
  }
  /* b_23, b_28,  */
  fixed_block_b_11: 
  {
    /* execute.a64:142 [F] s_b_11_0=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:142 [D] s_b_11_1 = sym_39468_0_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_39468_0_value, emitter.context().types().u64());
    /* execute.a64:142 [D] s_b_11_2: sym_148007_3_parameter_value = s_b_11_1, dominates: s_b_25_1 s_b_26_1  */
    emitter.store_local(DV_sym_148007_3_parameter_value, s_b_11_1);
    /* execute.a64:2690 [F] s_b_11_3: If s_b_11_0: Jump b_25 else b_26 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_25;
    }
    else 
    {
      goto fixed_block_b_26;
    }
  }
  /* b_20,  */
  fixed_block_b_12: 
  {
    /* execute.a64:135 [F] s_b_12_0=sym_39265_3_parameter_inst.immr (const) */
    /* execute.a64:135 [F] s_b_12_1 = -s_b_12_0 (const) */
    uint8_t s_b_12_1 = -insn.immr;
    /* execute.a64:135 [F] s_b_12_2=sym_39265_3_parameter_inst.sf (const) */
    /* execute.a64:135 [F] s_b_12_3 = (u32)s_b_12_2 (const) */
    /* execute.a64:135 [F] s_b_12_4 = constant u32 0 (const) */
    /* execute.a64:135 [F] s_b_12_5 = s_b_12_3==s_b_12_4 (const) */
    uint8_t s_b_12_5 = ((uint8_t)(((uint32_t)insn.sf) == (uint32_t)0ULL));
    /* execute.a64:135 [F] s_b_12_6 = constant s32 20 (const) */
    /* execute.a64:135 [F] s_b_12_7 = constant s32 40 (const) */
    /* execute.a64:135 [F] s_b_12_8: Select s_b_12_5 ? s_b_12_6 : s_b_12_7 (const) */
    int32_t s_b_12_8 = ((int32_t)(s_b_12_5 ? ((int32_t)32ULL) : ((int32_t)64ULL)));
    /* execute.a64:135 [F] s_b_12_9 = (u32)s_b_12_1 (const) */
    /* execute.a64:135 [F] s_b_12_10 = (u32)s_b_12_8 (const) */
    /* execute.a64:135 [F] s_b_12_11 = s_b_12_9%s_b_12_10 (const) */
    uint32_t s_b_12_11 = ((uint32_t)(((uint32_t)s_b_12_1) % ((uint32_t)s_b_12_8)));
    /* execute.a64:135 [F] s_b_12_12 = (u8)s_b_12_11 (const) */
    /* execute.a64:136 [F] s_b_12_13=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:136 [F] s_b_12_14 = (u32)s_b_12_13 (const) */
    /* execute.a64:136 [F] s_b_12_15 = constant u32 1 (const) */
    /* execute.a64:136 [F] s_b_12_16 = s_b_12_14+s_b_12_15 (const) */
    uint32_t s_b_12_16 = ((uint32_t)(((uint32_t)insn.imms) + (uint32_t)1ULL));
    /* execute.a64:136 [F] s_b_12_17 = (u8)s_b_12_16 (const) */
    /* execute.a64:138 [D] s_b_12_18 = sym_39468_0_value uint64_t */
    auto s_b_12_18 = emitter.load_local(DV_sym_39468_0_value, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_12_19: sym_148076_1_tmp_s_b_15_13 = s_b_12_12 (const), dominates: s_b_28_1  */
    CV_sym_148076_1_tmp_s_b_15_13 = ((uint8_t)s_b_12_11);
    /* ???:4294967295 [D] s_b_12_20: sym_148026_0_replaced_parameter_src = s_b_12_18, dominates: s_b_27_0 s_b_29_0  */
    emitter.store_local(DV_sym_148026_0_replaced_parameter_src, s_b_12_18);
    /* ???:4294967295 [F] s_b_12_21: sym_148042_0_replaced_parameter_len = s_b_12_17 (const), dominates: s_b_29_4  */
    CV_sym_148042_0_replaced_parameter_len = ((uint8_t)s_b_12_16);
    /* execute.a64:2507 [F] s_b_12_22 = (u32)s_b_12_17 (const) */
    /* execute.a64:2507 [F] s_b_12_23 = constant u32 40 (const) */
    /* execute.a64:2507 [F] s_b_12_24 = s_b_12_22>=s_b_12_23 (const) */
    uint8_t s_b_12_24 = ((uint8_t)(((uint32_t)((uint8_t)s_b_12_16)) >= (uint32_t)64ULL));
    /* execute.a64:2507 [F] s_b_12_25: If s_b_12_24: Jump b_27 else b_29 (const) */
    if (s_b_12_24) 
    {
      goto fixed_block_b_27;
    }
    else 
    {
      goto fixed_block_b_29;
    }
  }
  /* b_1,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2657 [F] s_b_13_0=sym_39265_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_13_1 = (u32)s_b_13_0 (const) */
    /* execute.a64:2651 [F] s_b_13_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_13_3 = s_b_13_1==s_b_13_2 (const) */
    uint8_t s_b_13_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_13_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_13_5 = ReadRegBank 0:s_b_13_0 (u64) */
    auto s_b_13_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_13_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_13_6: Select s_b_13_3 ? s_b_13_4 : s_b_13_5 */
    dbt::el::Value *s_b_13_6;
    s_b_13_6 = (s_b_13_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_13_5);
    /* ???:4294967295 [D] s_b_13_7: sym_147722_0_return_symbol = s_b_13_6, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_147722_0_return_symbol, s_b_13_6);
    /* ???:4294967295 [F] s_b_13_8: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_13, b_15,  */
  fixed_block_b_14: 
  {
    /* ???:4294967295 [D] s_b_14_0 = sym_147722_0_return_symbol uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_147722_0_return_symbol, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_14_1=sym_39265_3_parameter_inst.sf (const) */
    /* ???:4294967295 [F] s_b_14_2 = sym_147754_1_tmp_s_b_1_12 (const) uint8_t */
    uint8_t s_b_14_2 = CV_sym_147754_1_tmp_s_b_1_12;
    /* execute.a64:115 [F] s_b_14_3 = (u64)s_b_14_2 (const) */
    /* execute.a64:115 [D] s_b_14_4 = s_b_14_0<<s_b_14_3 */
    auto s_b_14_4 = emitter.shl(s_b_14_0, emitter.const_u64(((uint64_t)s_b_14_2)));
    /* execute.a64:115 [D] s_b_14_5: sym_148087_3_parameter_value = s_b_14_4, dominates: s_b_30_1 s_b_31_1  */
    emitter.store_local(DV_sym_148087_3_parameter_value, s_b_14_4);
    /* execute.a64:2690 [F] s_b_14_6: If s_b_14_1: Jump b_30 else b_31 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_30;
    }
    else 
    {
      goto fixed_block_b_31;
    }
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2659 [F] s_b_15_0=sym_39265_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.a64:2646 [F] s_b_15_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_15_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_15_5 = ReadRegBank 1:s_b_15_0 (u32) */
    auto s_b_15_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_15_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_15_6: Select s_b_15_3 ? s_b_15_4 : s_b_15_5 */
    dbt::el::Value *s_b_15_6;
    s_b_15_6 = (s_b_15_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_15_5);
    /* execute.a64:2659 [D] s_b_15_7 = (u64)s_b_15_6 */
    auto s_b_15_7 = emitter.zx(s_b_15_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_8: sym_147722_0_return_symbol = s_b_15_7, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_147722_0_return_symbol, s_b_15_7);
    /* ???:4294967295 [F] s_b_15_9: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_4,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2657 [F] s_b_16_0=sym_39265_3_parameter_inst.rn (const) */
    /* execute.a64:2651 [F] s_b_16_1 = (u32)s_b_16_0 (const) */
    /* execute.a64:2651 [F] s_b_16_2 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_16_4 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_16_5 = ReadRegBank 0:s_b_16_0 (u64) */
    auto s_b_16_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_16_5,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_16_6: Select s_b_16_3 ? s_b_16_4 : s_b_16_5 */
    dbt::el::Value *s_b_16_6;
    s_b_16_6 = (s_b_16_3) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_16_5);
    /* ???:4294967295 [D] s_b_16_7: sym_147772_0_return_symbol = s_b_16_6, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_147772_0_return_symbol, s_b_16_6);
    /* ???:4294967295 [F] s_b_16_8: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_16, b_18,  */
  fixed_block_b_17: 
  {
    /* ???:4294967295 [D] s_b_17_0 = sym_147772_0_return_symbol uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_147772_0_return_symbol, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_17_1=sym_39265_3_parameter_inst.sf (const) */
    /* ???:4294967295 [F] s_b_17_2=sym_39265_3_parameter_inst.immr (const) */
    /* execute.a64:119 [F] s_b_17_3 = (u64)s_b_17_2 (const) */
    /* execute.a64:119 [D] s_b_17_4 = s_b_17_0>>s_b_17_3 */
    auto s_b_17_4 = emitter.shr(s_b_17_0, emitter.const_u64(((uint64_t)insn.immr)));
    /* execute.a64:119 [D] s_b_17_5: sym_148113_3_parameter_value = s_b_17_4, dominates: s_b_32_1 s_b_33_1  */
    emitter.store_local(DV_sym_148113_3_parameter_value, s_b_17_4);
    /* execute.a64:2690 [F] s_b_17_6: If s_b_17_1: Jump b_32 else b_33 (const) */
    if (insn.sf) 
    {
      goto fixed_block_b_32;
    }
    else 
    {
      goto fixed_block_b_33;
    }
  }
  /* b_4,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2659 [F] s_b_18_0=sym_39265_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_18_1 = (u32)s_b_18_0 (const) */
    /* execute.a64:2646 [F] s_b_18_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_18_3 = s_b_18_1==s_b_18_2 (const) */
    uint8_t s_b_18_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_18_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_18_5 = ReadRegBank 1:s_b_18_0 (u32) */
    auto s_b_18_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_18_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_18_6: Select s_b_18_3 ? s_b_18_4 : s_b_18_5 */
    dbt::el::Value *s_b_18_6;
    s_b_18_6 = (s_b_18_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_18_5);
    /* execute.a64:2659 [D] s_b_18_7 = (u64)s_b_18_6 */
    auto s_b_18_7 = emitter.zx(s_b_18_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_8: sym_147772_0_return_symbol = s_b_18_7, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_147772_0_return_symbol, s_b_18_7);
    /* ???:4294967295 [F] s_b_18_9: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_9,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2657 [F] s_b_19_0=sym_39265_3_parameter_inst.rn (const) */
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
    /* ???:4294967295 [D] s_b_19_7: sym_147916_0_return_symbol = s_b_19_6, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_147916_0_return_symbol, s_b_19_6);
    /* ???:4294967295 [F] s_b_19_8: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_19, b_21,  */
  fixed_block_b_20: 
  {
    /* ???:4294967295 [D] s_b_20_0 = sym_147916_0_return_symbol uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_147916_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:127 [D] s_b_20_1: sym_39468_0_value = s_b_20_0, dominates: s_b_10_7 s_b_12_18  */
    emitter.store_local(DV_sym_39468_0_value, s_b_20_0);
    /* execute.a64:129 [F] s_b_20_2=sym_39265_3_parameter_inst.imms (const) */
    /* execute.a64:129 [F] s_b_20_3=sym_39265_3_parameter_inst.immr (const) */
    /* execute.a64:129 [F] s_b_20_4 = s_b_20_2>=s_b_20_3 (const) */
    uint8_t s_b_20_4 = ((uint8_t)(insn.imms >= insn.immr));
    /* execute.a64:129 [F] s_b_20_5: If s_b_20_4: Jump b_10 else b_12 (const) */
    if (s_b_20_4) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_12;
    }
  }
  /* b_9,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2659 [F] s_b_21_0=sym_39265_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
    /* execute.a64:2646 [F] s_b_21_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
    uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_21_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_21_5 = ReadRegBank 1:s_b_21_0 (u32) */
    auto s_b_21_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_21_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_21_6: Select s_b_21_3 ? s_b_21_4 : s_b_21_5 */
    dbt::el::Value *s_b_21_6;
    s_b_21_6 = (s_b_21_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_21_5);
    /* execute.a64:2659 [D] s_b_21_7 = (u64)s_b_21_6 */
    auto s_b_21_7 = emitter.zx(s_b_21_6, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_21_8: sym_147916_0_return_symbol = s_b_21_7, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_147916_0_return_symbol, s_b_21_7);
    /* ???:4294967295 [F] s_b_21_9: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_10,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2508 [D] s_b_22_0 = sym_147949_0_replaced_parameter_src uint64_t */
    auto s_b_22_0 = emitter.load_local(DV_sym_147949_0_replaced_parameter_src, emitter.context().types().u64());
    /* execute.a64:2508 [F] s_b_22_1=sym_39265_3_parameter_inst.immr (const) */
    /* execute.a64:2508 [F] s_b_22_2 = (u64)s_b_22_1 (const) */
    /* execute.a64:2508 [D] s_b_22_3 = s_b_22_0>>s_b_22_2 */
    auto s_b_22_3 = emitter.shr(s_b_22_0, emitter.const_u64(((uint64_t)insn.immr)));
    /* ???:4294967295 [D] s_b_22_4: sym_147955_0_return_symbol = s_b_22_3, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_147955_0_return_symbol, s_b_22_3);
    /* ???:4294967295 [F] s_b_22_5: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_22, b_24,  */
  fixed_block_b_23: 
  {
    /* ???:4294967295 [D] s_b_23_0 = sym_147955_0_return_symbol uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_147955_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:133 [D] s_b_23_1: sym_39468_0_value = s_b_23_0, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_39468_0_value, s_b_23_0);
    /* execute.a64:130 [F] s_b_23_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_10,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2510 [D] s_b_24_0 = sym_147949_0_replaced_parameter_src uint64_t */
    auto s_b_24_0 = emitter.load_local(DV_sym_147949_0_replaced_parameter_src, emitter.context().types().u64());
    /* execute.a64:2510 [F] s_b_24_1=sym_39265_3_parameter_inst.immr (const) */
    /* execute.a64:2510 [F] s_b_24_2 = (u64)s_b_24_1 (const) */
    /* execute.a64:2510 [D] s_b_24_3 = s_b_24_0>>s_b_24_2 */
    auto s_b_24_3 = emitter.shr(s_b_24_0, emitter.const_u64(((uint64_t)insn.immr)));
    /* execute.a64:2510 [F] s_b_24_4 = constant u64 1 (const) */
    /* execute.a64:2510 [F] s_b_24_5 = sym_147965_0_replaced_parameter_len (const) uint8_t */
    uint8_t s_b_24_5 = CV_sym_147965_0_replaced_parameter_len;
    /* execute.a64:2510 [F] s_b_24_6 = (u64)s_b_24_5 (const) */
    /* execute.a64:2510 [F] s_b_24_7 = s_b_24_4<<s_b_24_6 (const) */
    uint64_t s_b_24_7 = ((uint64_t)((uint64_t)1ULL << ((uint64_t)s_b_24_5)));
    /* execute.a64:2510 [F] s_b_24_8 = constant u64 1 (const) */
    /* execute.a64:2510 [F] s_b_24_9 = s_b_24_7-s_b_24_8 (const) */
    uint64_t s_b_24_9 = ((uint64_t)(s_b_24_7 - (uint64_t)1ULL));
    /* execute.a64:2510 [D] s_b_24_10 = s_b_24_3&s_b_24_9 */
    auto s_b_24_10 = emitter.bitwise_and(s_b_24_3, emitter.const_u64(s_b_24_9));
    /* ???:4294967295 [D] s_b_24_11: sym_147955_0_return_symbol = s_b_24_10, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_147955_0_return_symbol, s_b_24_10);
    /* ???:4294967295 [F] s_b_24_12: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_11,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2691 [F] s_b_25_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_25_1 = sym_148007_3_parameter_value uint64_t */
    auto s_b_25_1 = emitter.load_local(DV_sym_148007_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_25_2: sym_148195_3_parameter_value = s_b_25_1, dominates: s_b_34_1  */
    emitter.store_local(DV_sym_148195_3_parameter_value, s_b_25_1);
    /* execute.a64:2682 [F] s_b_25_3 = (u32)s_b_25_0 (const) */
    /* execute.a64:2682 [F] s_b_25_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_25_5 = s_b_25_3==s_b_25_4 (const) */
    uint8_t s_b_25_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_25_6: If s_b_25_5: Jump b_2 else b_34 (const) */
    if (s_b_25_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_34;
    }
  }
  /* b_11,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2693 [F] s_b_26_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_26_1 = sym_148007_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_148007_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_26_2 = (u32)s_b_26_1 */
    auto s_b_26_2 = emitter.truncate(s_b_26_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_26_3 = (u64)s_b_26_2 */
    auto s_b_26_3 = emitter.zx(s_b_26_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_26_4: sym_148217_3_parameter_value = s_b_26_3, dominates: s_b_35_1  */
    emitter.store_local(DV_sym_148217_3_parameter_value, s_b_26_3);
    /* execute.a64:2682 [F] s_b_26_5 = (u32)s_b_26_0 (const) */
    /* execute.a64:2682 [F] s_b_26_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_26_7 = s_b_26_5==s_b_26_6 (const) */
    uint8_t s_b_26_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_26_8: If s_b_26_7: Jump b_2 else b_35 (const) */
    if (s_b_26_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_35;
    }
  }
  /* b_12,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2508 [D] s_b_27_0 = sym_148026_0_replaced_parameter_src uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_148026_0_replaced_parameter_src, emitter.context().types().u64());
    /* execute.a64:2508 [F] s_b_27_1 = constant u64 0 (const) */
    /* execute.a64:2508 [D] s_b_27_2 = s_b_27_0>>s_b_27_1 */
    auto s_b_27_2 = emitter.shr(s_b_27_0, emitter.const_u64((uint64_t)0ULL));
    /* ???:4294967295 [D] s_b_27_3: sym_148032_0_return_symbol = s_b_27_2, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_148032_0_return_symbol, s_b_27_2);
    /* ???:4294967295 [F] s_b_27_4: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_29,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_148032_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_148032_0_return_symbol, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_28_1 = sym_148076_1_tmp_s_b_15_13 (const) uint8_t */
    uint8_t s_b_28_1 = CV_sym_148076_1_tmp_s_b_15_13;
    /* execute.a64:138 [D] s_b_28_2: sym_39468_0_value = s_b_28_0, dominates:  */
    emitter.store_local(DV_sym_39468_0_value, s_b_28_0);
    /* ???:4294967295 [F] s_b_28_3 = (u64)s_b_28_1 (const) */
    /* ???:4294967295 [D] s_b_28_4 = s_b_28_0<<s_b_28_3 */
    auto s_b_28_4 = emitter.shl(s_b_28_0, emitter.const_u64(((uint64_t)s_b_28_1)));
    /* execute.a64:139 [D] s_b_28_5: sym_39468_0_value = s_b_28_4, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_39468_0_value, s_b_28_4);
    /* execute.a64:135 [F] s_b_28_6: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_12,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2510 [D] s_b_29_0 = sym_148026_0_replaced_parameter_src uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_148026_0_replaced_parameter_src, emitter.context().types().u64());
    /* execute.a64:2510 [F] s_b_29_1 = constant u64 0 (const) */
    /* execute.a64:2510 [D] s_b_29_2 = s_b_29_0>>s_b_29_1 */
    auto s_b_29_2 = emitter.shr(s_b_29_0, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2510 [F] s_b_29_3 = constant u64 1 (const) */
    /* execute.a64:2510 [F] s_b_29_4 = sym_148042_0_replaced_parameter_len (const) uint8_t */
    uint8_t s_b_29_4 = CV_sym_148042_0_replaced_parameter_len;
    /* execute.a64:2510 [F] s_b_29_5 = (u64)s_b_29_4 (const) */
    /* execute.a64:2510 [F] s_b_29_6 = s_b_29_3<<s_b_29_5 (const) */
    uint64_t s_b_29_6 = ((uint64_t)((uint64_t)1ULL << ((uint64_t)s_b_29_4)));
    /* execute.a64:2510 [F] s_b_29_7 = constant u64 1 (const) */
    /* execute.a64:2510 [F] s_b_29_8 = s_b_29_6-s_b_29_7 (const) */
    uint64_t s_b_29_8 = ((uint64_t)(s_b_29_6 - (uint64_t)1ULL));
    /* execute.a64:2510 [D] s_b_29_9 = s_b_29_2&s_b_29_8 */
    auto s_b_29_9 = emitter.bitwise_and(s_b_29_2, emitter.const_u64(s_b_29_8));
    /* ???:4294967295 [D] s_b_29_10: sym_148032_0_return_symbol = s_b_29_9, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_148032_0_return_symbol, s_b_29_9);
    /* ???:4294967295 [F] s_b_29_11: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_14,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2691 [F] s_b_30_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_30_1 = sym_148087_3_parameter_value uint64_t */
    auto s_b_30_1 = emitter.load_local(DV_sym_148087_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_30_2: sym_148239_3_parameter_value = s_b_30_1, dominates: s_b_36_1  */
    emitter.store_local(DV_sym_148239_3_parameter_value, s_b_30_1);
    /* execute.a64:2682 [F] s_b_30_3 = (u32)s_b_30_0 (const) */
    /* execute.a64:2682 [F] s_b_30_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_30_5 = s_b_30_3==s_b_30_4 (const) */
    uint8_t s_b_30_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_30_6: If s_b_30_5: Jump b_2 else b_36 (const) */
    if (s_b_30_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_36;
    }
  }
  /* b_14,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2693 [F] s_b_31_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_31_1 = sym_148087_3_parameter_value uint64_t */
    auto s_b_31_1 = emitter.load_local(DV_sym_148087_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_31_2 = (u32)s_b_31_1 */
    auto s_b_31_2 = emitter.truncate(s_b_31_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_31_3 = (u64)s_b_31_2 */
    auto s_b_31_3 = emitter.zx(s_b_31_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_31_4: sym_148261_3_parameter_value = s_b_31_3, dominates: s_b_37_1  */
    emitter.store_local(DV_sym_148261_3_parameter_value, s_b_31_3);
    /* execute.a64:2682 [F] s_b_31_5 = (u32)s_b_31_0 (const) */
    /* execute.a64:2682 [F] s_b_31_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_31_7 = s_b_31_5==s_b_31_6 (const) */
    uint8_t s_b_31_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_31_8: If s_b_31_7: Jump b_2 else b_37 (const) */
    if (s_b_31_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_37;
    }
  }
  /* b_17,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2691 [F] s_b_32_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_32_1 = sym_148113_3_parameter_value uint64_t */
    auto s_b_32_1 = emitter.load_local(DV_sym_148113_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_32_2: sym_148283_3_parameter_value = s_b_32_1, dominates: s_b_38_1  */
    emitter.store_local(DV_sym_148283_3_parameter_value, s_b_32_1);
    /* execute.a64:2682 [F] s_b_32_3 = (u32)s_b_32_0 (const) */
    /* execute.a64:2682 [F] s_b_32_4 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_32_5 = s_b_32_3==s_b_32_4 (const) */
    uint8_t s_b_32_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_32_6: If s_b_32_5: Jump b_2 else b_38 (const) */
    if (s_b_32_5) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_38;
    }
  }
  /* b_17,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2693 [F] s_b_33_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2693 [D] s_b_33_1 = sym_148113_3_parameter_value uint64_t */
    auto s_b_33_1 = emitter.load_local(DV_sym_148113_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_33_2 = (u32)s_b_33_1 */
    auto s_b_33_2 = emitter.truncate(s_b_33_1, emitter.context().types().u32());
    /* execute.a64:2693 [D] s_b_33_3 = (u64)s_b_33_2 */
    auto s_b_33_3 = emitter.zx(s_b_33_2, emitter.context().types().u64());
    /* execute.a64:2693 [D] s_b_33_4: sym_148305_3_parameter_value = s_b_33_3, dominates: s_b_39_1  */
    emitter.store_local(DV_sym_148305_3_parameter_value, s_b_33_3);
    /* execute.a64:2682 [F] s_b_33_5 = (u32)s_b_33_0 (const) */
    /* execute.a64:2682 [F] s_b_33_6 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_33_7 = s_b_33_5==s_b_33_6 (const) */
    uint8_t s_b_33_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_33_8: If s_b_33_7: Jump b_2 else b_39 (const) */
    if (s_b_33_7) 
    {
      goto fixed_block_b_2;
    }
    else 
    {
      goto fixed_block_b_39;
    }
  }
  /* b_25,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2684 [F] s_b_34_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_34_1 = sym_148195_3_parameter_value uint64_t */
    auto s_b_34_1 = emitter.load_local(DV_sym_148195_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_34_2: WriteRegBank 0:s_b_34_0 = s_b_34_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_34_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_34_1);
    /* execute.a64:0 [F] s_b_34_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_26,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2684 [F] s_b_35_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_35_1 = sym_148217_3_parameter_value uint64_t */
    auto s_b_35_1 = emitter.load_local(DV_sym_148217_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_35_2: WriteRegBank 0:s_b_35_0 = s_b_35_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_35_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_35_1);
    /* execute.a64:0 [F] s_b_35_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_30,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2684 [F] s_b_36_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_36_1 = sym_148239_3_parameter_value uint64_t */
    auto s_b_36_1 = emitter.load_local(DV_sym_148239_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_36_2: WriteRegBank 0:s_b_36_0 = s_b_36_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_36_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_36_1);
    /* execute.a64:0 [F] s_b_36_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_31,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2684 [F] s_b_37_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_37_1 = sym_148261_3_parameter_value uint64_t */
    auto s_b_37_1 = emitter.load_local(DV_sym_148261_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_37_2: WriteRegBank 0:s_b_37_0 = s_b_37_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_37_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_37_1);
    /* execute.a64:0 [F] s_b_37_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_32,  */
  fixed_block_b_38: 
  {
    /* execute.a64:2684 [F] s_b_38_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_38_1 = sym_148283_3_parameter_value uint64_t */
    auto s_b_38_1 = emitter.load_local(DV_sym_148283_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_38_2: WriteRegBank 0:s_b_38_0 = s_b_38_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_38_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_38_1);
    /* execute.a64:0 [F] s_b_38_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_33,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2684 [F] s_b_39_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_39_1 = sym_148305_3_parameter_value uint64_t */
    auto s_b_39_1 = emitter.load_local(DV_sym_148305_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_39_2: WriteRegBank 0:s_b_39_0 = s_b_39_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_39_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_39_1);
    /* execute.a64:0 [F] s_b_39_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2684 [F] s_b_40_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_40_1 = sym_148349_3_parameter_value uint64_t */
    auto s_b_40_1 = emitter.load_local(DV_sym_148349_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_40_2: WriteRegBank 0:s_b_40_0 = s_b_40_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_40_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_40_1);
    /* execute.a64:0 [F] s_b_40_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_41: 
  {
    /* execute.a64:2684 [F] s_b_41_0=sym_39265_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_41_1 = sym_148393_3_parameter_value uint64_t */
    auto s_b_41_1 = emitter.load_local(DV_sym_148393_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2684 [D] s_b_41_2: WriteRegBank 0:s_b_41_0 = s_b_41_1 */
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_41_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_41_1);
    /* execute.a64:0 [F] s_b_41_3: Jump b_2 (const) */
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_umsubl(const aarch64_decode_a64_DP_3S&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_149490_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2413 [F] s_b_0_0=sym_40096_3_parameter_inst.rn (const) */
    /* execute.a64:2646 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2646 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_0_4 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_0_5 = ReadRegBank 1:s_b_0_0 (u32) */
    auto s_b_0_5 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_0_5,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_0_6: Select s_b_0_3 ? s_b_0_4 : s_b_0_5 */
    dbt::el::Value *s_b_0_6;
    s_b_0_6 = (s_b_0_3) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_0_5);
    /* execute.a64:2659 [D] s_b_0_7 = (u64)s_b_0_6 */
    auto s_b_0_7 = emitter.zx(s_b_0_6, emitter.context().types().u64());
    /* execute.a64:2414 [F] s_b_0_8=sym_40096_3_parameter_inst.rm (const) */
    /* execute.a64:2646 [F] s_b_0_9 = (u32)s_b_0_8 (const) */
    /* execute.a64:2646 [F] s_b_0_10 = constant u32 1f (const) */
    /* execute.a64:2646 [F] s_b_0_11 = s_b_0_9==s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2646 [F] s_b_0_12 = constant u32 0 (const) */
    /* execute.a64:2646 [D] s_b_0_13 = ReadRegBank 1:s_b_0_8 (u32) */
    auto s_b_0_13 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_0_13,emitter.const_u8(4));
    }
    /* execute.a64:2646 [D] s_b_0_14: Select s_b_0_11 ? s_b_0_12 : s_b_0_13 */
    dbt::el::Value *s_b_0_14;
    s_b_0_14 = (s_b_0_11) ? (emitter.const_u32((uint32_t)0ULL)) : (s_b_0_13);
    /* execute.a64:2659 [D] s_b_0_15 = (u64)s_b_0_14 */
    auto s_b_0_15 = emitter.zx(s_b_0_14, emitter.context().types().u64());
    /* execute.a64:2415 [F] s_b_0_16=sym_40096_3_parameter_inst.ra (const) */
    /* execute.a64:2651 [F] s_b_0_17 = (u32)s_b_0_16 (const) */
    /* execute.a64:2651 [F] s_b_0_18 = constant u32 1f (const) */
    /* execute.a64:2651 [F] s_b_0_19 = s_b_0_17==s_b_0_18 (const) */
    uint8_t s_b_0_19 = ((uint8_t)(((uint32_t)insn.ra) == (uint32_t)31ULL));
    /* execute.a64:2651 [F] s_b_0_20 = constant u64 0 (const) */
    /* execute.a64:2651 [D] s_b_0_21 = ReadRegBank 0:s_b_0_16 (u64) */
    auto s_b_0_21 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_0_21,emitter.const_u8(8));
    }
    /* execute.a64:2651 [D] s_b_0_22: Select s_b_0_19 ? s_b_0_20 : s_b_0_21 */
    dbt::el::Value *s_b_0_22;
    s_b_0_22 = (s_b_0_19) ? (emitter.const_u64((uint64_t)0ULL)) : (s_b_0_21);
    /* execute.a64:2417 [D] s_b_0_23 = (u64)s_b_0_22 */
    auto s_b_0_23 = (dbt::el::Value *)s_b_0_22;
    /* execute.a64:2417 [D] s_b_0_24 = (u64)s_b_0_7 */
    auto s_b_0_24 = (dbt::el::Value *)s_b_0_7;
    /* execute.a64:2417 [D] s_b_0_25 = (u64)s_b_0_15 */
    auto s_b_0_25 = (dbt::el::Value *)s_b_0_15;
    /* execute.a64:2417 [D] s_b_0_26 = s_b_0_24*s_b_0_25 */
    auto s_b_0_26 = emitter.mul(s_b_0_24, s_b_0_25);
    /* execute.a64:2417 [D] s_b_0_27 = s_b_0_23-s_b_0_26 */
    auto s_b_0_27 = emitter.sub(s_b_0_23, s_b_0_26);
    /* execute.a64:2691 [F] s_b_0_28=sym_40096_3_parameter_inst.rd (const) */
    /* execute.a64:2691 [D] s_b_0_29: sym_149490_3_parameter_value = s_b_0_27, dominates: s_b_2_1  */
    emitter.store_local(DV_sym_149490_3_parameter_value, s_b_0_27);
    /* execute.a64:2682 [F] s_b_0_30 = (u32)s_b_0_28 (const) */
    /* execute.a64:2682 [F] s_b_0_31 = constant u32 1f (const) */
    /* execute.a64:2682 [F] s_b_0_32 = s_b_0_30==s_b_0_31 (const) */
    uint8_t s_b_0_32 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2682 [F] s_b_0_33: If s_b_0_32: Jump b_1 else b_2 (const) */
    if (s_b_0_32) 
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
    /* execute.a64:2684 [F] s_b_2_0=sym_40096_3_parameter_inst.rd (const) */
    /* execute.a64:2684 [D] s_b_2_1 = sym_149490_3_parameter_value uint64_t */
    auto s_b_2_1 = emitter.load_local(DV_sym_149490_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool aarch64_jit2<TRACE>::translate_a64_uzp1(const aarch64_decode_a64_SIMD_PERMUTE&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4966 [F] s_b_0_0=sym_45624_3_parameter_inst.arrangement (const) */
    /* execute.simd:4967 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:4984 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5009 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5022 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5039 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5050 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5063 [F] s_b_0_7 = constant s32 6 (const) */
    /* execute.simd:4966 [F] s_b_0_8: Switch s_b_0_0: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:4968 [F] s_b_2_0=sym_45624_3_parameter_inst.rn (const) */
    /* execute.simd:4968 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:4969 [F] s_b_2_2=sym_45624_3_parameter_inst.rm (const) */
    /* execute.simd:4969 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_4 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:4972 [F] s_b_2_5 = constant s32 0 (const) */
    /* execute.simd:4972 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4972 [F] s_b_2_7 = constant s32 0 (const) */
    /* execute.simd:4972 [D] s_b_2_8 = s_b_2_4[s_b_2_7] <= s_b_2_6 */
    auto s_b_2_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_2_6);
    /* execute.simd:4973 [F] s_b_2_9 = constant s32 2 (const) */
    /* execute.simd:4973 [D] s_b_2_1[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4973 [F] s_b_2_11 = constant s32 1 (const) */
    /* execute.simd:4973 [D] s_b_2_12 = s_b_2_8[s_b_2_11] <= s_b_2_10 */
    auto s_b_2_12 = emitter.vector_insert(s_b_2_8, emitter.const_s32((int32_t)1ULL), s_b_2_10);
    /* execute.simd:4974 [F] s_b_2_13 = constant s32 4 (const) */
    /* execute.simd:4974 [D] s_b_2_1[s_b_2_13] */
    auto s_b_2_14 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:4974 [F] s_b_2_15 = constant s32 2 (const) */
    /* execute.simd:4974 [D] s_b_2_16 = s_b_2_12[s_b_2_15] <= s_b_2_14 */
    auto s_b_2_16 = emitter.vector_insert(s_b_2_12, emitter.const_s32((int32_t)2ULL), s_b_2_14);
    /* execute.simd:4975 [F] s_b_2_17 = constant s32 6 (const) */
    /* execute.simd:4975 [D] s_b_2_1[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:4975 [F] s_b_2_19 = constant s32 3 (const) */
    /* execute.simd:4975 [D] s_b_2_20 = s_b_2_16[s_b_2_19] <= s_b_2_18 */
    auto s_b_2_20 = emitter.vector_insert(s_b_2_16, emitter.const_s32((int32_t)3ULL), s_b_2_18);
    /* execute.simd:4976 [F] s_b_2_21 = constant s32 0 (const) */
    /* execute.simd:4976 [D] s_b_2_3[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4976 [F] s_b_2_23 = constant s32 4 (const) */
    /* execute.simd:4976 [D] s_b_2_24 = s_b_2_20[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_20, emitter.const_s32((int32_t)4ULL), s_b_2_22);
    /* execute.simd:4977 [F] s_b_2_25 = constant s32 2 (const) */
    /* execute.simd:4977 [D] s_b_2_3[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4977 [F] s_b_2_27 = constant s32 5 (const) */
    /* execute.simd:4977 [D] s_b_2_28 = s_b_2_24[s_b_2_27] <= s_b_2_26 */
    auto s_b_2_28 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)5ULL), s_b_2_26);
    /* execute.simd:4978 [F] s_b_2_29 = constant s32 4 (const) */
    /* execute.simd:4978 [D] s_b_2_3[s_b_2_29] */
    auto s_b_2_30 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:4978 [F] s_b_2_31 = constant s32 6 (const) */
    /* execute.simd:4978 [D] s_b_2_32 = s_b_2_28[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_28, emitter.const_s32((int32_t)6ULL), s_b_2_30);
    /* execute.simd:4979 [F] s_b_2_33 = constant s32 6 (const) */
    /* execute.simd:4979 [D] s_b_2_3[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_3, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:4979 [F] s_b_2_35 = constant s32 7 (const) */
    /* execute.simd:4979 [D] s_b_2_36 = s_b_2_32[s_b_2_35] <= s_b_2_34 */
    auto s_b_2_36 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)7ULL), s_b_2_34);
    /* execute.simd:4981 [F] s_b_2_37=sym_45624_3_parameter_inst.rd (const) */
    /* execute.simd:4981 [D] s_b_2_38: WriteRegBank 16:s_b_2_37 = s_b_2_36 */
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
    /* execute.simd:4985 [F] s_b_3_0=sym_45624_3_parameter_inst.rn (const) */
    /* execute.simd:4985 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:4986 [F] s_b_3_2=sym_45624_3_parameter_inst.rm (const) */
    /* execute.simd:4986 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v16u8 
    {
    }
    (const) */
    /* execute.simd:4989 [F] s_b_3_5 = constant s32 0 (const) */
    /* execute.simd:4989 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4989 [F] s_b_3_7 = constant s32 0 (const) */
    /* execute.simd:4989 [D] s_b_3_8 = s_b_3_4[s_b_3_7] <= s_b_3_6 */
    auto s_b_3_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint8_t, 16>(0)[0], emitter.context().types().v16u8()), emitter.const_s32((int32_t)0ULL), s_b_3_6);
    /* execute.simd:4990 [F] s_b_3_9 = constant s32 2 (const) */
    /* execute.simd:4990 [D] s_b_3_1[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4990 [F] s_b_3_11 = constant s32 1 (const) */
    /* execute.simd:4990 [D] s_b_3_12 = s_b_3_8[s_b_3_11] <= s_b_3_10 */
    auto s_b_3_12 = emitter.vector_insert(s_b_3_8, emitter.const_s32((int32_t)1ULL), s_b_3_10);
    /* execute.simd:4991 [F] s_b_3_13 = constant s32 4 (const) */
    /* execute.simd:4991 [D] s_b_3_1[s_b_3_13] */
    auto s_b_3_14 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:4991 [F] s_b_3_15 = constant s32 2 (const) */
    /* execute.simd:4991 [D] s_b_3_16 = s_b_3_12[s_b_3_15] <= s_b_3_14 */
    auto s_b_3_16 = emitter.vector_insert(s_b_3_12, emitter.const_s32((int32_t)2ULL), s_b_3_14);
    /* execute.simd:4992 [F] s_b_3_17 = constant s32 6 (const) */
    /* execute.simd:4992 [D] s_b_3_1[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:4992 [F] s_b_3_19 = constant s32 3 (const) */
    /* execute.simd:4992 [D] s_b_3_20 = s_b_3_16[s_b_3_19] <= s_b_3_18 */
    auto s_b_3_20 = emitter.vector_insert(s_b_3_16, emitter.const_s32((int32_t)3ULL), s_b_3_18);
    /* execute.simd:4993 [F] s_b_3_21 = constant s32 8 (const) */
    /* execute.simd:4993 [D] s_b_3_1[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)8ULL));
    /* execute.simd:4993 [F] s_b_3_23 = constant s32 4 (const) */
    /* execute.simd:4993 [D] s_b_3_24 = s_b_3_20[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_20, emitter.const_s32((int32_t)4ULL), s_b_3_22);
    /* execute.simd:4994 [F] s_b_3_25 = constant s32 a (const) */
    /* execute.simd:4994 [D] s_b_3_1[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)10ULL));
    /* execute.simd:4994 [F] s_b_3_27 = constant s32 5 (const) */
    /* execute.simd:4994 [D] s_b_3_28 = s_b_3_24[s_b_3_27] <= s_b_3_26 */
    auto s_b_3_28 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)5ULL), s_b_3_26);
    /* execute.simd:4995 [F] s_b_3_29 = constant s32 c (const) */
    /* execute.simd:4995 [D] s_b_3_1[s_b_3_29] */
    auto s_b_3_30 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)12ULL));
    /* execute.simd:4995 [F] s_b_3_31 = constant s32 6 (const) */
    /* execute.simd:4995 [D] s_b_3_32 = s_b_3_28[s_b_3_31] <= s_b_3_30 */
    auto s_b_3_32 = emitter.vector_insert(s_b_3_28, emitter.const_s32((int32_t)6ULL), s_b_3_30);
    /* execute.simd:4996 [F] s_b_3_33 = constant s32 e (const) */
    /* execute.simd:4996 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_s32((int32_t)14ULL));
    /* execute.simd:4996 [F] s_b_3_35 = constant s32 7 (const) */
    /* execute.simd:4996 [D] s_b_3_36 = s_b_3_32[s_b_3_35] <= s_b_3_34 */
    auto s_b_3_36 = emitter.vector_insert(s_b_3_32, emitter.const_s32((int32_t)7ULL), s_b_3_34);
    /* execute.simd:4997 [F] s_b_3_37 = constant s32 0 (const) */
    /* execute.simd:4997 [D] s_b_3_3[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4997 [F] s_b_3_39 = constant s32 8 (const) */
    /* execute.simd:4997 [D] s_b_3_40 = s_b_3_36[s_b_3_39] <= s_b_3_38 */
    auto s_b_3_40 = emitter.vector_insert(s_b_3_36, emitter.const_s32((int32_t)8ULL), s_b_3_38);
    /* execute.simd:4998 [F] s_b_3_41 = constant s32 2 (const) */
    /* execute.simd:4998 [D] s_b_3_3[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4998 [F] s_b_3_43 = constant s32 9 (const) */
    /* execute.simd:4998 [D] s_b_3_44 = s_b_3_40[s_b_3_43] <= s_b_3_42 */
    auto s_b_3_44 = emitter.vector_insert(s_b_3_40, emitter.const_s32((int32_t)9ULL), s_b_3_42);
    /* execute.simd:4999 [F] s_b_3_45 = constant s32 4 (const) */
    /* execute.simd:4999 [D] s_b_3_3[s_b_3_45] */
    auto s_b_3_46 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:4999 [F] s_b_3_47 = constant s32 a (const) */
    /* execute.simd:4999 [D] s_b_3_48 = s_b_3_44[s_b_3_47] <= s_b_3_46 */
    auto s_b_3_48 = emitter.vector_insert(s_b_3_44, emitter.const_s32((int32_t)10ULL), s_b_3_46);
    /* execute.simd:5000 [F] s_b_3_49 = constant s32 6 (const) */
    /* execute.simd:5000 [D] s_b_3_3[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:5000 [F] s_b_3_51 = constant s32 b (const) */
    /* execute.simd:5000 [D] s_b_3_52 = s_b_3_48[s_b_3_51] <= s_b_3_50 */
    auto s_b_3_52 = emitter.vector_insert(s_b_3_48, emitter.const_s32((int32_t)11ULL), s_b_3_50);
    /* execute.simd:5001 [F] s_b_3_53 = constant s32 8 (const) */
    /* execute.simd:5001 [D] s_b_3_3[s_b_3_53] */
    auto s_b_3_54 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)8ULL));
    /* execute.simd:5001 [F] s_b_3_55 = constant s32 c (const) */
    /* execute.simd:5001 [D] s_b_3_56 = s_b_3_52[s_b_3_55] <= s_b_3_54 */
    auto s_b_3_56 = emitter.vector_insert(s_b_3_52, emitter.const_s32((int32_t)12ULL), s_b_3_54);
    /* execute.simd:5002 [F] s_b_3_57 = constant s32 a (const) */
    /* execute.simd:5002 [D] s_b_3_3[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)10ULL));
    /* execute.simd:5002 [F] s_b_3_59 = constant s32 d (const) */
    /* execute.simd:5002 [D] s_b_3_60 = s_b_3_56[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_56, emitter.const_s32((int32_t)13ULL), s_b_3_58);
    /* execute.simd:5003 [F] s_b_3_61 = constant s32 c (const) */
    /* execute.simd:5003 [D] s_b_3_3[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)12ULL));
    /* execute.simd:5003 [F] s_b_3_63 = constant s32 e (const) */
    /* execute.simd:5003 [D] s_b_3_64 = s_b_3_60[s_b_3_63] <= s_b_3_62 */
    auto s_b_3_64 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)14ULL), s_b_3_62);
    /* execute.simd:5004 [F] s_b_3_65 = constant s32 e (const) */
    /* execute.simd:5004 [D] s_b_3_3[s_b_3_65] */
    auto s_b_3_66 = emitter.vector_extract(s_b_3_3, emitter.const_s32((int32_t)14ULL));
    /* execute.simd:5004 [F] s_b_3_67 = constant s32 f (const) */
    /* execute.simd:5004 [D] s_b_3_68 = s_b_3_64[s_b_3_67] <= s_b_3_66 */
    auto s_b_3_68 = emitter.vector_insert(s_b_3_64, emitter.const_s32((int32_t)15ULL), s_b_3_66);
    /* execute.simd:5006 [F] s_b_3_69=sym_45624_3_parameter_inst.rd (const) */
    /* execute.simd:5006 [D] s_b_3_70: WriteRegBank 16:s_b_3_69 = s_b_3_68 */
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
    /* execute.simd:5010 [F] s_b_4_0=sym_45624_3_parameter_inst.rn (const) */
    /* execute.simd:5010 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5011 [F] s_b_4_2=sym_45624_3_parameter_inst.rm (const) */
    /* execute.simd:5011 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5014 [F] s_b_4_5 = constant s32 0 (const) */
    /* execute.simd:5014 [D] s_b_4_1[s_b_4_5] */
    auto s_b_4_6 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5014 [F] s_b_4_7 = constant s32 0 (const) */
    /* execute.simd:5014 [D] s_b_4_8 = s_b_4_4[s_b_4_7] <= s_b_4_6 */
    auto s_b_4_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_4_6);
    /* execute.simd:5015 [F] s_b_4_9 = constant s32 2 (const) */
    /* execute.simd:5015 [D] s_b_4_1[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5015 [F] s_b_4_11 = constant s32 1 (const) */
    /* execute.simd:5015 [D] s_b_4_12 = s_b_4_8[s_b_4_11] <= s_b_4_10 */
    auto s_b_4_12 = emitter.vector_insert(s_b_4_8, emitter.const_s32((int32_t)1ULL), s_b_4_10);
    /* execute.simd:5016 [F] s_b_4_13 = constant s32 0 (const) */
    /* execute.simd:5016 [D] s_b_4_3[s_b_4_13] */
    auto s_b_4_14 = emitter.vector_extract(s_b_4_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5016 [F] s_b_4_15 = constant s32 2 (const) */
    /* execute.simd:5016 [D] s_b_4_16 = s_b_4_12[s_b_4_15] <= s_b_4_14 */
    auto s_b_4_16 = emitter.vector_insert(s_b_4_12, emitter.const_s32((int32_t)2ULL), s_b_4_14);
    /* execute.simd:5017 [F] s_b_4_17 = constant s32 2 (const) */
    /* execute.simd:5017 [D] s_b_4_3[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5017 [F] s_b_4_19 = constant s32 3 (const) */
    /* execute.simd:5017 [D] s_b_4_20 = s_b_4_16[s_b_4_19] <= s_b_4_18 */
    auto s_b_4_20 = emitter.vector_insert(s_b_4_16, emitter.const_s32((int32_t)3ULL), s_b_4_18);
    /* execute.simd:5019 [F] s_b_4_21=sym_45624_3_parameter_inst.rd (const) */
    /* execute.simd:5019 [D] s_b_4_22: WriteRegBank 18:s_b_4_21 = s_b_4_20 */
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
    /* execute.simd:5023 [F] s_b_5_0=sym_45624_3_parameter_inst.rn (const) */
    /* execute.simd:5023 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5024 [F] s_b_5_2=sym_45624_3_parameter_inst.rm (const) */
    /* execute.simd:5024 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5027 [F] s_b_5_5 = constant s32 0 (const) */
    /* execute.simd:5027 [D] s_b_5_1[s_b_5_5] */
    auto s_b_5_6 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5027 [F] s_b_5_7 = constant s32 0 (const) */
    /* execute.simd:5027 [D] s_b_5_8 = s_b_5_4[s_b_5_7] <= s_b_5_6 */
    auto s_b_5_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_5_6);
    /* execute.simd:5028 [F] s_b_5_9 = constant s32 2 (const) */
    /* execute.simd:5028 [D] s_b_5_1[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5028 [F] s_b_5_11 = constant s32 1 (const) */
    /* execute.simd:5028 [D] s_b_5_12 = s_b_5_8[s_b_5_11] <= s_b_5_10 */
    auto s_b_5_12 = emitter.vector_insert(s_b_5_8, emitter.const_s32((int32_t)1ULL), s_b_5_10);
    /* execute.simd:5029 [F] s_b_5_13 = constant s32 4 (const) */
    /* execute.simd:5029 [D] s_b_5_1[s_b_5_13] */
    auto s_b_5_14 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:5029 [F] s_b_5_15 = constant s32 2 (const) */
    /* execute.simd:5029 [D] s_b_5_16 = s_b_5_12[s_b_5_15] <= s_b_5_14 */
    auto s_b_5_16 = emitter.vector_insert(s_b_5_12, emitter.const_s32((int32_t)2ULL), s_b_5_14);
    /* execute.simd:5030 [F] s_b_5_17 = constant s32 6 (const) */
    /* execute.simd:5030 [D] s_b_5_1[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:5030 [F] s_b_5_19 = constant s32 3 (const) */
    /* execute.simd:5030 [D] s_b_5_20 = s_b_5_16[s_b_5_19] <= s_b_5_18 */
    auto s_b_5_20 = emitter.vector_insert(s_b_5_16, emitter.const_s32((int32_t)3ULL), s_b_5_18);
    /* execute.simd:5031 [F] s_b_5_21 = constant s32 0 (const) */
    /* execute.simd:5031 [D] s_b_5_3[s_b_5_21] */
    auto s_b_5_22 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5031 [F] s_b_5_23 = constant s32 4 (const) */
    /* execute.simd:5031 [D] s_b_5_24 = s_b_5_20[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_20, emitter.const_s32((int32_t)4ULL), s_b_5_22);
    /* execute.simd:5032 [F] s_b_5_25 = constant s32 2 (const) */
    /* execute.simd:5032 [D] s_b_5_3[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5032 [F] s_b_5_27 = constant s32 5 (const) */
    /* execute.simd:5032 [D] s_b_5_28 = s_b_5_24[s_b_5_27] <= s_b_5_26 */
    auto s_b_5_28 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)5ULL), s_b_5_26);
    /* execute.simd:5033 [F] s_b_5_29 = constant s32 4 (const) */
    /* execute.simd:5033 [D] s_b_5_3[s_b_5_29] */
    auto s_b_5_30 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)4ULL));
    /* execute.simd:5033 [F] s_b_5_31 = constant s32 6 (const) */
    /* execute.simd:5033 [D] s_b_5_32 = s_b_5_28[s_b_5_31] <= s_b_5_30 */
    auto s_b_5_32 = emitter.vector_insert(s_b_5_28, emitter.const_s32((int32_t)6ULL), s_b_5_30);
    /* execute.simd:5034 [F] s_b_5_33 = constant s32 6 (const) */
    /* execute.simd:5034 [D] s_b_5_3[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)6ULL));
    /* execute.simd:5034 [F] s_b_5_35 = constant s32 7 (const) */
    /* execute.simd:5034 [D] s_b_5_36 = s_b_5_32[s_b_5_35] <= s_b_5_34 */
    auto s_b_5_36 = emitter.vector_insert(s_b_5_32, emitter.const_s32((int32_t)7ULL), s_b_5_34);
    /* execute.simd:5036 [F] s_b_5_37=sym_45624_3_parameter_inst.rd (const) */
    /* execute.simd:5036 [D] s_b_5_38: WriteRegBank 18:s_b_5_37 = s_b_5_36 */
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
    /* execute.simd:5040 [F] s_b_6_0=sym_45624_3_parameter_inst.rn (const) */
    /* execute.simd:5040 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5041 [F] s_b_6_2=sym_45624_3_parameter_inst.rm (const) */
    /* execute.simd:5041 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5044 [F] s_b_6_5 = constant s32 0 (const) */
    /* execute.simd:5044 [D] s_b_6_1[s_b_6_5] */
    auto s_b_6_6 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5044 [F] s_b_6_7 = constant s32 0 (const) */
    /* execute.simd:5044 [D] s_b_6_8 = s_b_6_4[s_b_6_7] <= s_b_6_6 */
    auto s_b_6_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_6_6);
    /* execute.simd:5045 [F] s_b_6_9 = constant s32 0 (const) */
    /* execute.simd:5045 [D] s_b_6_3[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5045 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:5045 [D] s_b_6_12 = s_b_6_8[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_8, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:5047 [F] s_b_6_13=sym_45624_3_parameter_inst.rd (const) */
    /* execute.simd:5047 [D] s_b_6_14: WriteRegBank 20:s_b_6_13 = s_b_6_12 */
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
    /* execute.simd:5051 [F] s_b_7_0=sym_45624_3_parameter_inst.rn (const) */
    /* execute.simd:5051 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5052 [F] s_b_7_2=sym_45624_3_parameter_inst.rm (const) */
    /* execute.simd:5052 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5055 [F] s_b_7_5 = constant s32 0 (const) */
    /* execute.simd:5055 [D] s_b_7_1[s_b_7_5] */
    auto s_b_7_6 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5055 [F] s_b_7_7 = constant s32 0 (const) */
    /* execute.simd:5055 [D] s_b_7_8 = s_b_7_4[s_b_7_7] <= s_b_7_6 */
    auto s_b_7_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_7_6);
    /* execute.simd:5056 [F] s_b_7_9 = constant s32 2 (const) */
    /* execute.simd:5056 [D] s_b_7_1[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5056 [F] s_b_7_11 = constant s32 1 (const) */
    /* execute.simd:5056 [D] s_b_7_12 = s_b_7_8[s_b_7_11] <= s_b_7_10 */
    auto s_b_7_12 = emitter.vector_insert(s_b_7_8, emitter.const_s32((int32_t)1ULL), s_b_7_10);
    /* execute.simd:5057 [F] s_b_7_13 = constant s32 0 (const) */
    /* execute.simd:5057 [D] s_b_7_3[s_b_7_13] */
    auto s_b_7_14 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5057 [F] s_b_7_15 = constant s32 2 (const) */
    /* execute.simd:5057 [D] s_b_7_16 = s_b_7_12[s_b_7_15] <= s_b_7_14 */
    auto s_b_7_16 = emitter.vector_insert(s_b_7_12, emitter.const_s32((int32_t)2ULL), s_b_7_14);
    /* execute.simd:5058 [F] s_b_7_17 = constant s32 2 (const) */
    /* execute.simd:5058 [D] s_b_7_3[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:5058 [F] s_b_7_19 = constant s32 3 (const) */
    /* execute.simd:5058 [D] s_b_7_20 = s_b_7_16[s_b_7_19] <= s_b_7_18 */
    auto s_b_7_20 = emitter.vector_insert(s_b_7_16, emitter.const_s32((int32_t)3ULL), s_b_7_18);
    /* execute.simd:5060 [F] s_b_7_21=sym_45624_3_parameter_inst.rd (const) */
    /* execute.simd:5060 [D] s_b_7_22: WriteRegBank 20:s_b_7_21 = s_b_7_20 */
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
    /* execute.simd:5064 [F] s_b_8_0=sym_45624_3_parameter_inst.rn (const) */
    /* execute.simd:5064 [D] s_b_8_1 = ReadRegBank 21:s_b_8_0 (v2u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* execute.simd:5065 [F] s_b_8_2=sym_45624_3_parameter_inst.rm (const) */
    /* execute.simd:5065 [D] s_b_8_3 = ReadRegBank 21:s_b_8_2 (v2u64) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_8_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_8_4 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:5068 [F] s_b_8_5 = constant s32 0 (const) */
    /* execute.simd:5068 [D] s_b_8_1[s_b_8_5] */
    auto s_b_8_6 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5068 [F] s_b_8_7 = constant s32 0 (const) */
    /* execute.simd:5068 [D] s_b_8_8 = s_b_8_4[s_b_8_7] <= s_b_8_6 */
    auto s_b_8_8 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_8_6);
    /* execute.simd:5069 [F] s_b_8_9 = constant s32 0 (const) */
    /* execute.simd:5069 [D] s_b_8_3[s_b_8_9] */
    auto s_b_8_10 = emitter.vector_extract(s_b_8_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:5069 [F] s_b_8_11 = constant s32 1 (const) */
    /* execute.simd:5069 [D] s_b_8_12 = s_b_8_8[s_b_8_11] <= s_b_8_10 */
    auto s_b_8_12 = emitter.vector_insert(s_b_8_8, emitter.const_s32((int32_t)1ULL), s_b_8_10);
    /* execute.simd:5071 [F] s_b_8_13=sym_45624_3_parameter_inst.rd (const) */
    /* execute.simd:5071 [D] s_b_8_14: WriteRegBank 21:s_b_8_13 = s_b_8_12 */
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
