#include <arm64-jit2.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::arm64;
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_addp_scalar(const arm64_decode_a64_SIMD_SCALAR_PW&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:1123 [F] s_b_0_0=sym_3682_3_parameter_inst.rn (const) */
    /* execute.simd:1123 [D] s_b_0_1 = ReadRegBank 21:s_b_0_0 (v2u64) */
    auto s_b_0_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_0_1,emitter.const_u8(16));
    }
    /* execute.simd:1124 [F] s_b_0_2=sym_3682_3_parameter_inst.rd (const) */
    /* execute.simd:1124 [F] s_b_0_3 = constant s32 0 (const) */
    /* execute.simd:1124 [D] s_b_0_1[s_b_0_3] */
    auto s_b_0_4 = emitter.vector_extract(s_b_0_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:1124 [F] s_b_0_5 = constant s32 1 (const) */
    /* execute.simd:1124 [D] s_b_0_1[s_b_0_5] */
    auto s_b_0_6 = emitter.vector_extract(s_b_0_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:1124 [D] s_b_0_7 = s_b_0_4+s_b_0_6 */
    auto s_b_0_7 = emitter.add(s_b_0_4, s_b_0_6);
    /* execute.simd:6326 [D] s_b_0_8: WriteRegBank 2:s_b_0_2 = s_b_0_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_0_7,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_0_7);
    /* execute.simd:6327 [F] s_b_0_9 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_0_10: WriteRegBank 3:s_b_0_2 = s_b_0_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11: Return */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_b(const arm64_decode_a64_UB_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:602 [F] s_b_0_0=sym_5960_3_parameter_inst.op (const) */
    /* execute.a64:602 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_2 (const) */
    if (insn.op) 
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
    /* execute.a64:603 [D] s_b_1_0 = read_pc */
    auto s_b_1_0 = emitter.load_pc();
    /* execute.a64:603 [F] s_b_1_1 = constant u64 4 (const) */
    /* execute.a64:603 [D] s_b_1_2 = s_b_1_0+s_b_1_1 */
    auto s_b_1_2 = emitter.add(s_b_1_0, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2747 [F] s_b_1_3 = constant u8 1e (const) */
    /* execute.a64:2747 [D] s_b_1_4: WriteRegBank 0:s_b_1_3 = s_b_1_2 */
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
    /* execute.a64:606 [D] s_b_2_0 = read_pc */
    auto s_b_2_0 = emitter.load_pc();
    /* execute.a64:606 [D] s_b_2_1 = (s64)s_b_2_0 */
    auto s_b_2_1 = emitter.reinterpret(s_b_2_0, emitter.context().types().s64());
    /* execute.a64:606 [F] s_b_2_2=sym_5960_3_parameter_inst.imms64 (const) */
    /* execute.a64:606 [D] s_b_2_3 = s_b_2_1+s_b_2_2 */
    auto s_b_2_3 = emitter.add(s_b_2_1, emitter.const_s64(insn.imms64));
    /* execute.a64:606 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.reinterpret(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:571 [D] s_b_2_5 = write_pc */
    emitter.store_pc(s_b_2_4);
    /* execute.a64:572 [D] s_b_2_6 = __branch_taken */
    emitter.call(__captive___branch_taken);
    /* ???:4294967295 [F] s_b_2_7: Return */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_bit(const arm64_decode_a64_SIMD_THREE_SAME&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2409 [F] s_b_0_0=sym_6364_3_parameter_inst.Q (const) */
    /* execute.simd:2409 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2417 [F] s_b_1_0=sym_6364_3_parameter_inst.rd (const) */
    /* execute.simd:6360 [D] s_b_1_1 = ReadRegBank 2:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_1_2 = ReadRegBank 3:s_b_1_0 (u64) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),s_b_1_2,emitter.const_u8(8));
    }
    /* execute.simd:2418 [F] s_b_1_3=sym_6364_3_parameter_inst.rn (const) */
    /* execute.simd:6360 [D] s_b_1_4 = ReadRegBank 2:s_b_1_3 (u64) */
    auto s_b_1_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_4,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_1_5 = ReadRegBank 3:s_b_1_3 (u64) */
    auto s_b_1_5 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rn))),s_b_1_5,emitter.const_u8(8));
    }
    /* execute.simd:2419 [F] s_b_1_6=sym_6364_3_parameter_inst.rm (const) */
    /* execute.simd:6360 [D] s_b_1_7 = ReadRegBank 2:s_b_1_6 (u64) */
    auto s_b_1_7 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_7,emitter.const_u8(8));
    }
    /* execute.simd:6361 [D] s_b_1_8 = ReadRegBank 3:s_b_1_6 (u64) */
    auto s_b_1_8 = emitter.load_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(264 + (16 * insn.rm))),s_b_1_8,emitter.const_u8(8));
    }
    /* execute.simd:2421 [F] s_b_1_9=sym_6364_3_parameter_inst.rd (const) */
    /* execute.simd:2421 [D] s_b_1_10 = s_b_1_1^s_b_1_4 */
    auto s_b_1_10 = emitter.bitwise_xor(s_b_1_1, s_b_1_4);
    /* execute.simd:2421 [D] s_b_1_11 = s_b_1_10&s_b_1_7 */
    auto s_b_1_11 = emitter.bitwise_and(s_b_1_10, s_b_1_7);
    /* execute.simd:2421 [D] s_b_1_12 = s_b_1_1^s_b_1_11 */
    auto s_b_1_12 = emitter.bitwise_xor(s_b_1_1, s_b_1_11);
    /* execute.simd:2421 [D] s_b_1_13 = s_b_1_2^s_b_1_5 */
    auto s_b_1_13 = emitter.bitwise_xor(s_b_1_2, s_b_1_5);
    /* execute.simd:2421 [D] s_b_1_14 = s_b_1_13&s_b_1_8 */
    auto s_b_1_14 = emitter.bitwise_and(s_b_1_13, s_b_1_8);
    /* execute.simd:2421 [D] s_b_1_15 = s_b_1_2^s_b_1_14 */
    auto s_b_1_15 = emitter.bitwise_xor(s_b_1_2, s_b_1_14);
    /* execute.simd:6333 [D] s_b_1_16: WriteRegBank 2:s_b_1_9 = s_b_1_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_12);
    /* execute.simd:6334 [D] s_b_1_17: WriteRegBank 3:s_b_1_9 = s_b_1_15 */
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
    /* execute.simd:2427 [F] s_b_3_0=sym_6364_3_parameter_inst.rd (const) */
    /* execute.simd:6355 [D] s_b_3_1 = ReadRegBank 7:s_b_3_0 (u64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:2428 [F] s_b_3_2=sym_6364_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_3_3 = ReadRegBank 7:s_b_3_2 (u64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:2429 [F] s_b_3_4=sym_6364_3_parameter_inst.rm (const) */
    /* execute.simd:6355 [D] s_b_3_5 = ReadRegBank 7:s_b_3_4 (u64) */
    auto s_b_3_5 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_5,emitter.const_u8(8));
    }
    /* execute.simd:2431 [F] s_b_3_6=sym_6364_3_parameter_inst.rd (const) */
    /* execute.simd:2431 [D] s_b_3_7 = s_b_3_1^s_b_3_3 */
    auto s_b_3_7 = emitter.bitwise_xor(s_b_3_1, s_b_3_3);
    /* execute.simd:2431 [D] s_b_3_8 = s_b_3_7&s_b_3_5 */
    auto s_b_3_8 = emitter.bitwise_and(s_b_3_7, s_b_3_5);
    /* execute.simd:2431 [D] s_b_3_9 = s_b_3_1^s_b_3_8 */
    auto s_b_3_9 = emitter.bitwise_xor(s_b_3_1, s_b_3_8);
    /* execute.simd:6326 [D] s_b_3_10: WriteRegBank 2:s_b_3_6 = s_b_3_9 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_9,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_9);
    /* execute.simd:6327 [F] s_b_3_11 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_3_12: WriteRegBank 3:s_b_3_6 = s_b_3_11 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_clrex(const arm64_decode_a64_SYSTEM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:566 [F] s_b_0_0 = constant u32 0 (const) */
    /* execute.a64:566 [D] s_b_0_1 = mem_monitor_release_all */
    auto s_b_0_1 = emitter.call(__captive_mem_monitor_release_all, emitter.const_u32((uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_0_2: Return */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_cmlt_zero(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto block_b_2 = emitter.context().create_block();
  auto block_b_6 = emitter.context().create_block();
  auto block_b_7 = emitter.context().create_block();
  auto block_b_8 = emitter.context().create_block();
  auto block_b_9 = emitter.context().create_block();
  auto DV_sym_8162_0_rn = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2057 [F] s_b_0_0=sym_8153_3_parameter_inst.SCALAR (const) */
    /* execute.simd:2057 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:2058 [F] s_b_1_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_1_1 = ReadRegBank 7:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.simd:2058 [D] s_b_1_2: sym_8162_0_rn = s_b_1_1, dominates: s_b_4_0 s_b_5_0  */
    emitter.store_local(DV_sym_8162_0_rn, s_b_1_1);
    /* execute.simd:2060 [F] s_b_1_3=sym_8153_3_parameter_inst.U (const) */
    /* execute.simd:2060 [F] s_b_1_4 = (u32)s_b_1_3 (const) */
    /* execute.simd:2060 [F] s_b_1_5 = constant u32 1 (const) */
    /* execute.simd:2060 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:2060 [F] s_b_1_7: If s_b_1_6: Jump b_4 else b_5 (const) */
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
    /* execute.simd:2074 [F] s_b_3_0=sym_8153_3_parameter_inst.U (const) */
    /* execute.simd:2074 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:2074 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:2074 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.U) == (uint32_t)1ULL));
    /* execute.simd:2074 [F] s_b_3_4: If s_b_3_3: Jump b_10 else b_11 (const) */
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
    /* execute.simd:2061 [D] s_b_4_0 = sym_8162_0_rn uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_8162_0_rn, emitter.context().types().u64());
    /* execute.simd:2061 [D] s_b_4_1 = (s64)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s64());
    /* execute.simd:2061 [F] s_b_4_2 = constant s64 0 (const) */
    /* execute.simd:2061 [D] s_b_4_3 = s_b_4_1<=s_b_4_2 */
    auto s_b_4_3 = emitter.cmp_le(s_b_4_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:2061 [D] s_b_4_4: If s_b_4_3: Jump b_6 else b_7 */
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
    /* execute.simd:2067 [D] s_b_5_0 = sym_8162_0_rn uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_8162_0_rn, emitter.context().types().u64());
    /* execute.simd:2067 [D] s_b_5_1 = (s64)s_b_5_0 */
    auto s_b_5_1 = emitter.reinterpret(s_b_5_0, emitter.context().types().s64());
    /* execute.simd:2067 [F] s_b_5_2 = constant s64 0 (const) */
    /* execute.simd:2067 [D] s_b_5_3 = s_b_5_1<s_b_5_2 */
    auto s_b_5_3 = emitter.cmp_lt(s_b_5_1, emitter.const_s64((int64_t)0ULL));
    /* execute.simd:2067 [D] s_b_5_4: If s_b_5_3: Jump b_8 else b_9 */
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
    /* execute.simd:2075 [F] s_b_10_0=sym_8153_3_parameter_inst.arrangement (const) */
    /* execute.simd:2076 [F] s_b_10_1 = constant s32 0 (const) */
    /* execute.simd:2085 [F] s_b_10_2 = constant s32 1 (const) */
    /* execute.simd:2093 [F] s_b_10_3 = constant s32 2 (const) */
    /* execute.simd:2102 [F] s_b_10_4 = constant s32 3 (const) */
    /* execute.simd:2110 [F] s_b_10_5 = constant s32 4 (const) */
    /* execute.simd:2119 [F] s_b_10_6 = constant s32 5 (const) */
    /* execute.simd:2127 [F] s_b_10_7 = constant s32 6 (const) */
    /* execute.simd:2075 [F] s_b_10_8: Switch s_b_10_0: < <todo> > def b_19 (const) -> b_19, b_18, b_17, b_16, b_15, b_14, b_13, b_12,  */
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
    /* execute.simd:2141 [F] s_b_11_0=sym_8153_3_parameter_inst.arrangement (const) */
    /* execute.simd:2142 [F] s_b_11_1 = constant s32 0 (const) */
    /* execute.simd:2151 [F] s_b_11_2 = constant s32 1 (const) */
    /* execute.simd:2159 [F] s_b_11_3 = constant s32 2 (const) */
    /* execute.simd:2168 [F] s_b_11_4 = constant s32 3 (const) */
    /* execute.simd:2176 [F] s_b_11_5 = constant s32 4 (const) */
    /* execute.simd:2185 [F] s_b_11_6 = constant s32 5 (const) */
    /* execute.simd:2193 [F] s_b_11_7 = constant s32 6 (const) */
    /* execute.simd:2141 [F] s_b_11_8: Switch s_b_11_0: < <todo> > def b_27 (const) -> b_27, b_26, b_25, b_24, b_23, b_22, b_21, b_20,  */
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
    /* execute.simd:2077 [F] s_b_12_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2077 [D] s_b_12_1 = ReadRegBank 15:s_b_12_0 (v8u8) */
    auto s_b_12_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_12_1,emitter.const_u8(8));
    }
    /* execute.simd:2077 [D] s_b_12_2 = (v8s8)s_b_12_1 */
    auto s_b_12_2 = emitter.reinterpret(s_b_12_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_12_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:2079 [D] s_b_12_4 = s_b_12_2<=s_b_12_3 */
    auto s_b_12_4 = emitter.cmp_le(s_b_12_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:2079 [D] s_b_12_5 = (v8u8)s_b_12_4 */
    auto s_b_12_5 = emitter.reinterpret(s_b_12_4, emitter.context().types().v8u8());
    /* execute.simd:2080 [F] s_b_12_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2080 [D] s_b_12_7: WriteRegBank 15:s_b_12_6 = s_b_12_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_12_5);
    /* execute.simd:2081 [F] s_b_12_8=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2081 [F] s_b_12_9 = constant u64 0 (const) */
    /* execute.simd:2081 [F] s_b_12_10: WriteRegBank 3:s_b_12_8 = s_b_12_9 */
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
    /* execute.simd:2086 [F] s_b_13_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2086 [D] s_b_13_1 = ReadRegBank 16:s_b_13_0 (v16u8) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_13_1,emitter.const_u8(16));
    }
    /* execute.simd:2086 [D] s_b_13_2 = (v16s8)s_b_13_1 */
    auto s_b_13_2 = emitter.reinterpret(s_b_13_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_13_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:2088 [D] s_b_13_4 = s_b_13_2<=s_b_13_3 */
    auto s_b_13_4 = emitter.cmp_le(s_b_13_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:2088 [D] s_b_13_5 = (v16u8)s_b_13_4 */
    auto s_b_13_5 = emitter.reinterpret(s_b_13_4, emitter.context().types().v16u8());
    /* execute.simd:2089 [F] s_b_13_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2089 [D] s_b_13_7: WriteRegBank 16:s_b_13_6 = s_b_13_5 */
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
    /* execute.simd:2094 [F] s_b_14_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2094 [D] s_b_14_1 = ReadRegBank 17:s_b_14_0 (v4u16) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.simd:2094 [D] s_b_14_2 = (v4s16)s_b_14_1 */
    auto s_b_14_2 = emitter.reinterpret(s_b_14_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_14_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:2096 [D] s_b_14_4 = s_b_14_2<=s_b_14_3 */
    auto s_b_14_4 = emitter.cmp_le(s_b_14_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:2096 [D] s_b_14_5 = (v4u16)s_b_14_4 */
    auto s_b_14_5 = emitter.reinterpret(s_b_14_4, emitter.context().types().v4u16());
    /* execute.simd:2097 [F] s_b_14_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2097 [D] s_b_14_7: WriteRegBank 17:s_b_14_6 = s_b_14_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_14_5);
    /* execute.simd:2098 [F] s_b_14_8=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2098 [F] s_b_14_9 = constant u64 0 (const) */
    /* execute.simd:2098 [F] s_b_14_10: WriteRegBank 3:s_b_14_8 = s_b_14_9 */
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
    /* execute.simd:2103 [F] s_b_15_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2103 [D] s_b_15_1 = ReadRegBank 18:s_b_15_0 (v8u16) */
    auto s_b_15_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_15_1,emitter.const_u8(16));
    }
    /* execute.simd:2103 [D] s_b_15_2 = (v8s16)s_b_15_1 */
    auto s_b_15_2 = emitter.reinterpret(s_b_15_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_15_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:2105 [D] s_b_15_4 = s_b_15_2<=s_b_15_3 */
    auto s_b_15_4 = emitter.cmp_le(s_b_15_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:2105 [D] s_b_15_5 = (v8u16)s_b_15_4 */
    auto s_b_15_5 = emitter.reinterpret(s_b_15_4, emitter.context().types().v8u16());
    /* execute.simd:2107 [F] s_b_15_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2107 [D] s_b_15_7: WriteRegBank 18:s_b_15_6 = s_b_15_5 */
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
    /* execute.simd:2111 [F] s_b_16_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2111 [D] s_b_16_1 = ReadRegBank 19:s_b_16_0 (v2u32) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.simd:2111 [D] s_b_16_2 = (v2s32)s_b_16_1 */
    auto s_b_16_2 = emitter.reinterpret(s_b_16_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_16_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:2113 [D] s_b_16_4 = s_b_16_2<=s_b_16_3 */
    auto s_b_16_4 = emitter.cmp_le(s_b_16_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:2113 [D] s_b_16_5 = (v2u32)s_b_16_4 */
    auto s_b_16_5 = emitter.reinterpret(s_b_16_4, emitter.context().types().v2u32());
    /* execute.simd:2114 [F] s_b_16_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2114 [D] s_b_16_7: WriteRegBank 19:s_b_16_6 = s_b_16_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_16_5);
    /* execute.simd:2115 [F] s_b_16_8=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2115 [F] s_b_16_9 = constant u64 0 (const) */
    /* execute.simd:2115 [F] s_b_16_10: WriteRegBank 3:s_b_16_8 = s_b_16_9 */
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
    /* execute.simd:2120 [F] s_b_17_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2120 [D] s_b_17_1 = ReadRegBank 20:s_b_17_0 (v4u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_17_1,emitter.const_u8(16));
    }
    /* execute.simd:2120 [D] s_b_17_2 = (v4s32)s_b_17_1 */
    auto s_b_17_2 = emitter.reinterpret(s_b_17_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_17_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:2122 [D] s_b_17_4 = s_b_17_2<=s_b_17_3 */
    auto s_b_17_4 = emitter.cmp_le(s_b_17_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:2122 [D] s_b_17_5 = (v4u32)s_b_17_4 */
    auto s_b_17_5 = emitter.reinterpret(s_b_17_4, emitter.context().types().v4u32());
    /* execute.simd:2124 [F] s_b_17_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2124 [D] s_b_17_7: WriteRegBank 20:s_b_17_6 = s_b_17_5 */
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
    /* execute.simd:2128 [F] s_b_18_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2128 [D] s_b_18_1 = ReadRegBank 21:s_b_18_0 (v2u64) */
    auto s_b_18_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_18_1,emitter.const_u8(16));
    }
    /* execute.simd:2128 [D] s_b_18_2 = (v2s64)s_b_18_1 */
    auto s_b_18_2 = emitter.reinterpret(s_b_18_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_18_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:2130 [D] s_b_18_4 = s_b_18_2<=s_b_18_3 */
    auto s_b_18_4 = emitter.cmp_le(s_b_18_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:2130 [D] s_b_18_5 = (v2u64)s_b_18_4 */
    auto s_b_18_5 = emitter.reinterpret(s_b_18_4, emitter.context().types().v2u64());
    /* execute.simd:2132 [F] s_b_18_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2132 [D] s_b_18_7: WriteRegBank 21:s_b_18_6 = s_b_18_5 */
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
    /* execute.simd:2136 [D] s_b_19_0 = trap */
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
    /* execute.simd:2143 [F] s_b_20_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2143 [D] s_b_20_1 = ReadRegBank 15:s_b_20_0 (v8u8) */
    auto s_b_20_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_20_1,emitter.const_u8(8));
    }
    /* execute.simd:2143 [D] s_b_20_2 = (v8s8)s_b_20_1 */
    auto s_b_20_2 = emitter.reinterpret(s_b_20_1, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_20_3 = constant v8s8 
    {
    }
    (const) */
    /* execute.simd:2145 [D] s_b_20_4 = s_b_20_2<s_b_20_3 */
    auto s_b_20_4 = emitter.cmp_lt(s_b_20_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 8>(0)[0], emitter.context().types().v8s8()));
    /* execute.simd:2145 [D] s_b_20_5 = (v8u8)s_b_20_4 */
    auto s_b_20_5 = emitter.reinterpret(s_b_20_4, emitter.context().types().v8u8());
    /* execute.simd:2146 [F] s_b_20_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2146 [D] s_b_20_7: WriteRegBank 15:s_b_20_6 = s_b_20_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_20_5);
    /* execute.simd:2147 [F] s_b_20_8=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2147 [F] s_b_20_9 = constant u64 0 (const) */
    /* execute.simd:2147 [F] s_b_20_10: WriteRegBank 3:s_b_20_8 = s_b_20_9 */
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
    /* execute.simd:2152 [F] s_b_21_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2152 [D] s_b_21_1 = ReadRegBank 16:s_b_21_0 (v16u8) */
    auto s_b_21_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_21_1,emitter.const_u8(16));
    }
    /* execute.simd:2152 [D] s_b_21_2 = (v16s8)s_b_21_1 */
    auto s_b_21_2 = emitter.reinterpret(s_b_21_1, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_21_3 = constant v16s8 
    {
    }
    (const) */
    /* execute.simd:2154 [D] s_b_21_4 = s_b_21_2<s_b_21_3 */
    auto s_b_21_4 = emitter.cmp_lt(s_b_21_2, emitter.constant_vector_splat(wutils::Vector<int8_t, 16>(0)[0], emitter.context().types().v16s8()));
    /* execute.simd:2154 [D] s_b_21_5 = (v16u8)s_b_21_4 */
    auto s_b_21_5 = emitter.reinterpret(s_b_21_4, emitter.context().types().v16u8());
    /* execute.simd:2155 [F] s_b_21_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2155 [D] s_b_21_7: WriteRegBank 16:s_b_21_6 = s_b_21_5 */
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
    /* execute.simd:2160 [F] s_b_22_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2160 [D] s_b_22_1 = ReadRegBank 17:s_b_22_0 (v4u16) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_22_1,emitter.const_u8(8));
    }
    /* execute.simd:2160 [D] s_b_22_2 = (v4s16)s_b_22_1 */
    auto s_b_22_2 = emitter.reinterpret(s_b_22_1, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_22_3 = constant v4s16 
    {
    }
    (const) */
    /* execute.simd:2162 [D] s_b_22_4 = s_b_22_2<s_b_22_3 */
    auto s_b_22_4 = emitter.cmp_lt(s_b_22_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 4>(0)[0], emitter.context().types().v4s16()));
    /* execute.simd:2162 [D] s_b_22_5 = (v4u16)s_b_22_4 */
    auto s_b_22_5 = emitter.reinterpret(s_b_22_4, emitter.context().types().v4u16());
    /* execute.simd:2163 [F] s_b_22_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2163 [D] s_b_22_7: WriteRegBank 17:s_b_22_6 = s_b_22_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_22_5);
    /* execute.simd:2164 [F] s_b_22_8=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2164 [F] s_b_22_9 = constant u64 0 (const) */
    /* execute.simd:2164 [F] s_b_22_10: WriteRegBank 3:s_b_22_8 = s_b_22_9 */
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
    /* execute.simd:2169 [F] s_b_23_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2169 [D] s_b_23_1 = ReadRegBank 18:s_b_23_0 (v8u16) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_23_1,emitter.const_u8(16));
    }
    /* execute.simd:2169 [D] s_b_23_2 = (v8s16)s_b_23_1 */
    auto s_b_23_2 = emitter.reinterpret(s_b_23_1, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_23_3 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:2171 [D] s_b_23_4 = s_b_23_2<s_b_23_3 */
    auto s_b_23_4 = emitter.cmp_lt(s_b_23_2, emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()));
    /* execute.simd:2171 [D] s_b_23_5 = (v8u16)s_b_23_4 */
    auto s_b_23_5 = emitter.reinterpret(s_b_23_4, emitter.context().types().v8u16());
    /* execute.simd:2173 [F] s_b_23_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2173 [D] s_b_23_7: WriteRegBank 18:s_b_23_6 = s_b_23_5 */
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
    /* execute.simd:2177 [F] s_b_24_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2177 [D] s_b_24_1 = ReadRegBank 19:s_b_24_0 (v2u32) */
    auto s_b_24_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_24_1,emitter.const_u8(8));
    }
    /* execute.simd:2177 [D] s_b_24_2 = (v2s32)s_b_24_1 */
    auto s_b_24_2 = emitter.reinterpret(s_b_24_1, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_24_3 = constant v2s32 
    {
    }
    (const) */
    /* execute.simd:2179 [D] s_b_24_4 = s_b_24_2<s_b_24_3 */
    auto s_b_24_4 = emitter.cmp_lt(s_b_24_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 2>(0)[0], emitter.context().types().v2s32()));
    /* execute.simd:2179 [D] s_b_24_5 = (v2u32)s_b_24_4 */
    auto s_b_24_5 = emitter.reinterpret(s_b_24_4, emitter.context().types().v2u32());
    /* execute.simd:2180 [F] s_b_24_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2180 [D] s_b_24_7: WriteRegBank 19:s_b_24_6 = s_b_24_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_24_5);
    /* execute.simd:2181 [F] s_b_24_8=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2181 [F] s_b_24_9 = constant u64 0 (const) */
    /* execute.simd:2181 [F] s_b_24_10: WriteRegBank 3:s_b_24_8 = s_b_24_9 */
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
    /* execute.simd:2186 [F] s_b_25_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2186 [D] s_b_25_1 = ReadRegBank 20:s_b_25_0 (v4u32) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_25_1,emitter.const_u8(16));
    }
    /* execute.simd:2186 [D] s_b_25_2 = (v4s32)s_b_25_1 */
    auto s_b_25_2 = emitter.reinterpret(s_b_25_1, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_25_3 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:2188 [D] s_b_25_4 = s_b_25_2<s_b_25_3 */
    auto s_b_25_4 = emitter.cmp_lt(s_b_25_2, emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()));
    /* execute.simd:2188 [D] s_b_25_5 = (v4u32)s_b_25_4 */
    auto s_b_25_5 = emitter.reinterpret(s_b_25_4, emitter.context().types().v4u32());
    /* execute.simd:2190 [F] s_b_25_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2190 [D] s_b_25_7: WriteRegBank 20:s_b_25_6 = s_b_25_5 */
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
    /* execute.simd:2194 [F] s_b_26_0=sym_8153_3_parameter_inst.rn (const) */
    /* execute.simd:2194 [D] s_b_26_1 = ReadRegBank 21:s_b_26_0 (v2u64) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_26_1,emitter.const_u8(16));
    }
    /* execute.simd:2194 [D] s_b_26_2 = (v2s64)s_b_26_1 */
    auto s_b_26_2 = emitter.reinterpret(s_b_26_1, emitter.context().types().v2s64());
    /* ???:4294967295 [F] s_b_26_3 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:2196 [D] s_b_26_4 = s_b_26_2<s_b_26_3 */
    auto s_b_26_4 = emitter.cmp_lt(s_b_26_2, emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()));
    /* execute.simd:2196 [D] s_b_26_5 = (v2u64)s_b_26_4 */
    auto s_b_26_5 = emitter.reinterpret(s_b_26_4, emitter.context().types().v2u64());
    /* execute.simd:2198 [F] s_b_26_6=sym_8153_3_parameter_inst.rd (const) */
    /* execute.simd:2198 [D] s_b_26_7: WriteRegBank 21:s_b_26_6 = s_b_26_5 */
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
    /* execute.simd:2202 [D] s_b_27_0 = trap */
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
        /* execute.simd:2062 [F] s_b_6_0=sym_8153_3_parameter_inst.rd (const) */
        /* execute.simd:2062 [F] s_b_6_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6326 [F] s_b_6_2: WriteRegBank 2:s_b_6_0 = s_b_6_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6327 [F] s_b_6_3 = constant u64 0 (const) */
        /* execute.simd:6327 [F] s_b_6_4: WriteRegBank 3:s_b_6_0 = s_b_6_3 */
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
        /* execute.simd:2064 [F] s_b_7_0=sym_8153_3_parameter_inst.rd (const) */
        /* execute.simd:2064 [F] s_b_7_1 = constant u64 0 (const) */
        /* execute.simd:6326 [F] s_b_7_2: WriteRegBank 2:s_b_7_0 = s_b_7_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6327 [F] s_b_7_3 = constant u64 0 (const) */
        /* execute.simd:6327 [F] s_b_7_4: WriteRegBank 3:s_b_7_0 = s_b_7_3 */
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
        /* execute.simd:2068 [F] s_b_8_0=sym_8153_3_parameter_inst.rd (const) */
        /* execute.simd:2068 [F] s_b_8_1 = constant u64 ffffffffffffffff (const) */
        /* execute.simd:6326 [F] s_b_8_2: WriteRegBank 2:s_b_8_0 = s_b_8_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)18446744073709551615ULL));
        /* execute.simd:6327 [F] s_b_8_3 = constant u64 0 (const) */
        /* execute.simd:6327 [F] s_b_8_4: WriteRegBank 3:s_b_8_0 = s_b_8_3 */
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
        /* execute.simd:2070 [F] s_b_9_0=sym_8153_3_parameter_inst.rd (const) */
        /* execute.simd:2070 [F] s_b_9_1 = constant u64 0 (const) */
        /* execute.simd:6326 [F] s_b_9_2: WriteRegBank 2:s_b_9_0 = s_b_9_1 */
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
        }
        emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
        /* execute.simd:6327 [F] s_b_9_3 = constant u64 0 (const) */
        /* execute.simd:6327 [F] s_b_9_4: WriteRegBank 3:s_b_9_0 = s_b_9_3 */
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
  auto DV_sym_59072_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_59116_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_59017_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_59094_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_59042_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_59138_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58882_1__R_s_b_3_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58935_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), true);
  auto DV_sym_58960_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58851_1__R_s_b_1_6 = emitter.alloc_local(emitter.context().types().u64(), true);
  uint8_t CV_sym_58757_0_state;
  auto DV_sym_58757_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_58800_0_return_symbol = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_58907_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  auto DV_sym_58989_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), true);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2202 [F] s_b_0_0=sym_9258_3_parameter_inst.cond (const) */
    /* execute.a64:2854 [F] s_b_0_1 = constant u8 0 (const) */
    /* execute.a64:2854 [F] s_b_0_2: sym_58757_0_state = s_b_0_1 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_58757_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_58757_0_state, emitter.const_u8((uint8_t)0ULL));
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
    /* execute.a64:2856 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_4 (const) -> b_4, b_7, b_8, b_9, b_10, b_11, b_12, b_13, b_14,  */
    switch (s_b_0_5) 
    {
    case (int32_t)4ULL:
      goto fixed_block_b_11;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_13;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_14;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_8;
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
    case (int32_t)0ULL:
      goto fixed_block_b_7;
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
    /* execute.a64:2891 [F] s_b_4_0=sym_9258_3_parameter_inst.cond (const) */
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
    /* execute.a64:2892 [D] s_b_5_0 = sym_58757_0_state uint8_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_58757_0_state, emitter.context().types().u8());
    /* execute.a64:2892 [D] s_b_5_1 = !s_b_5_0 */
    auto s_b_5_1 = emitter.cmp_eq(s_b_5_0, emitter.const_u8(0));
    /* ???:4294967295 [D] s_b_5_2: sym_58800_0_return_symbol = s_b_5_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_58800_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2894 [D] s_b_6_0 = sym_58757_0_state uint8_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_58757_0_state, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_6_1: sym_58800_0_return_symbol = s_b_6_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_58800_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2858 [D] s_b_7_1: sym_58757_0_state = s_b_7_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58757_0_state, s_b_7_0);
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
    /* execute.a64:2862 [D] s_b_8_1: sym_58757_0_state = s_b_8_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58757_0_state, s_b_8_0);
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
    /* execute.a64:2866 [D] s_b_9_1: sym_58757_0_state = s_b_9_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58757_0_state, s_b_9_0);
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
    /* execute.a64:2870 [D] s_b_10_1: sym_58757_0_state = s_b_10_0, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58757_0_state, s_b_10_0);
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
    /* execute.a64:2874 [D] s_b_11_4: sym_58757_0_state = s_b_11_3, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58757_0_state, s_b_11_3);
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
    /* execute.a64:2878 [D] s_b_12_3: sym_58757_0_state = s_b_12_2, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58757_0_state, s_b_12_2);
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
    /* execute.a64:2882 [D] s_b_13_6: sym_58757_0_state = s_b_13_5, dominates: s_b_5_0 s_b_6_0  */
    emitter.store_local(DV_sym_58757_0_state, s_b_13_5);
    /* execute.a64:0 [F] s_b_13_7: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2886 [F] s_b_14_0 = constant u8 1 (const) */
    /* execute.a64:2886 [F] s_b_14_1: sym_58757_0_state = s_b_14_0 (const), dominates: s_b_5_0 s_b_6_0  */
    CV_sym_58757_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_58757_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_14_2: Jump b_4 (const) */
    goto fixed_block_b_4;
  }
  /* b_5, b_6,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_58800_0_return_symbol uint8_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_58800_0_return_symbol, emitter.context().types().u8());
    /* execute.a64:2204 [D] s_b_15_1 = (u32)s_b_15_0 */
    auto s_b_15_1 = emitter.zx(s_b_15_0, emitter.context().types().u32());
    /* execute.a64:2204 [F] s_b_15_2 = constant u32 0 (const) */
    /* execute.a64:2204 [D] s_b_15_3 = s_b_15_1==s_b_15_2 */
    auto s_b_15_3 = emitter.cmp_eq(s_b_15_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2204 [D] s_b_15_4: If s_b_15_3: Jump b_1 else b_3 */
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
        /* execute.a64:2205 [F] s_b_1_0=sym_9258_3_parameter_inst.sf (const) */
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
        /* execute.a64:2207 [F] s_b_3_0=sym_9258_3_parameter_inst.sf (const) */
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
        /* execute.a64:2720 [F] s_b_16_0=sym_9258_3_parameter_inst.rm (const) */
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
        /* execute.a64:2722 [F] s_b_17_0=sym_9258_3_parameter_inst.rm (const) */
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
        /* ???:4294967295 [F] s_b_18_0=sym_9258_3_parameter_inst.sf (const) */
        /* execute.a64:2205 [D] s_b_18_1 = sym_58851_1__R_s_b_1_6 uint64_t */
        auto s_b_18_1 = emitter.load_local(DV_sym_58851_1__R_s_b_1_6, emitter.context().types().u64());
        /* execute.a64:2205 [D] s_b_18_2 = ~s_b_18_1 */
        auto s_b_18_2 = emitter.bitwise_not(s_b_18_1);
        /* execute.a64:2205 [F] s_b_18_3 = constant u64 1 (const) */
        /* execute.a64:2205 [D] s_b_18_4 = s_b_18_2+s_b_18_3 */
        auto s_b_18_4 = emitter.add(s_b_18_2, emitter.const_u64((uint64_t)1ULL));
        /* execute.a64:2205 [D] s_b_18_5: sym_58960_3_parameter_value = s_b_18_4, dominates: s_b_28_1 s_b_29_1  */
        emitter.store_local(DV_sym_58960_3_parameter_value, s_b_18_4);
        /* execute.a64:2753 [F] s_b_18_6: If s_b_18_0: Jump b_28 else b_29 (const) */
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
        /* execute.a64:2720 [F] s_b_19_0=sym_9258_3_parameter_inst.rn (const) */
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
        /* execute.a64:2722 [F] s_b_20_0=sym_9258_3_parameter_inst.rn (const) */
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
        /* ???:4294967295 [F] s_b_21_0=sym_9258_3_parameter_inst.sf (const) */
        /* execute.a64:2207 [D] s_b_21_1 = sym_58882_1__R_s_b_3_6 uint64_t */
        auto s_b_21_1 = emitter.load_local(DV_sym_58882_1__R_s_b_3_6, emitter.context().types().u64());
        /* execute.a64:2207 [D] s_b_21_2: sym_59042_3_parameter_value = s_b_21_1, dominates: s_b_36_1 s_b_37_1  */
        emitter.store_local(DV_sym_59042_3_parameter_value, s_b_21_1);
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
        /* execute.a64:2714 [D] s_b_22_1: sym_58907_1_temporary_value = s_b_22_0, dominates: s_b_24_0  */
        emitter.store_local(DV_sym_58907_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [F] s_b_23_0=sym_9258_3_parameter_inst.rm (const) */
        /* execute.a64:2714 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
        auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_23_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_23_2: sym_58907_1_temporary_value = s_b_23_1, dominates: s_b_24_0  */
        emitter.store_local(DV_sym_58907_1_temporary_value, s_b_23_1);
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
        /* execute.a64:2714 [D] s_b_24_0 = sym_58907_1_temporary_value uint64_t */
        auto s_b_24_0 = emitter.load_local(DV_sym_58907_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2720 [D] s_b_24_1: sym_58851_1__R_s_b_1_6 = s_b_24_0, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_58851_1__R_s_b_1_6, s_b_24_0);
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
        /* execute.a64:2709 [D] s_b_25_1: sym_58935_1_temporary_value = s_b_25_0, dominates: s_b_27_0  */
        emitter.store_local(DV_sym_58935_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_26_0=sym_9258_3_parameter_inst.rm (const) */
        /* execute.a64:2709 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
        auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_26_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_26_2: sym_58935_1_temporary_value = s_b_26_1, dominates: s_b_27_0  */
        emitter.store_local(DV_sym_58935_1_temporary_value, s_b_26_1);
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
        /* execute.a64:2709 [D] s_b_27_0 = sym_58935_1_temporary_value uint32_t */
        auto s_b_27_0 = emitter.load_local(DV_sym_58935_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_27_1 = (u64)s_b_27_0 */
        auto s_b_27_1 = emitter.zx(s_b_27_0, emitter.context().types().u64());
        /* execute.a64:2722 [D] s_b_27_2: sym_58851_1__R_s_b_1_6 = s_b_27_1, dominates: s_b_18_1  */
        emitter.store_local(DV_sym_58851_1__R_s_b_1_6, s_b_27_1);
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
        /* execute.a64:2754 [F] s_b_28_0=sym_9258_3_parameter_inst.rd (const) */
        /* execute.a64:2754 [D] s_b_28_1 = sym_58960_3_parameter_value uint64_t */
        auto s_b_28_1 = emitter.load_local(DV_sym_58960_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2754 [D] s_b_28_2: sym_59072_3_parameter_value = s_b_28_1, dominates: s_b_38_1  */
        emitter.store_local(DV_sym_59072_3_parameter_value, s_b_28_1);
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
        /* execute.a64:2756 [F] s_b_29_0=sym_9258_3_parameter_inst.rd (const) */
        /* execute.a64:2756 [D] s_b_29_1 = sym_58960_3_parameter_value uint64_t */
        auto s_b_29_1 = emitter.load_local(DV_sym_58960_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_29_2 = (u32)s_b_29_1 */
        auto s_b_29_2 = emitter.truncate(s_b_29_1, emitter.context().types().u32());
        /* execute.a64:2756 [D] s_b_29_3 = (u64)s_b_29_2 */
        auto s_b_29_3 = emitter.zx(s_b_29_2, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_29_4: sym_59094_3_parameter_value = s_b_29_3, dominates: s_b_39_1  */
        emitter.store_local(DV_sym_59094_3_parameter_value, s_b_29_3);
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
        /* execute.a64:2714 [D] s_b_30_1: sym_58989_1_temporary_value = s_b_30_0, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_58989_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
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
        /* execute.a64:2714 [F] s_b_31_0=sym_9258_3_parameter_inst.rn (const) */
        /* execute.a64:2714 [D] s_b_31_1 = ReadRegBank 0:s_b_31_0 (u64) */
        auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_31_1,emitter.const_u8(8));
        }
        /* execute.a64:2714 [D] s_b_31_2: sym_58989_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
        emitter.store_local(DV_sym_58989_1_temporary_value, s_b_31_1);
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
        /* execute.a64:2714 [D] s_b_32_0 = sym_58989_1_temporary_value uint64_t */
        auto s_b_32_0 = emitter.load_local(DV_sym_58989_1_temporary_value, emitter.context().types().u64());
        /* execute.a64:2720 [D] s_b_32_1: sym_58882_1__R_s_b_3_6 = s_b_32_0, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_58882_1__R_s_b_3_6, s_b_32_0);
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
        /* execute.a64:2709 [D] s_b_33_1: sym_59017_1_temporary_value = s_b_33_0, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_59017_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
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
        /* execute.a64:2709 [F] s_b_34_0=sym_9258_3_parameter_inst.rn (const) */
        /* execute.a64:2709 [D] s_b_34_1 = ReadRegBank 1:s_b_34_0 (u32) */
        auto s_b_34_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
        if (TRACE) 
        {
          emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_34_1,emitter.const_u8(4));
        }
        /* execute.a64:2709 [D] s_b_34_2: sym_59017_1_temporary_value = s_b_34_1, dominates: s_b_35_0  */
        emitter.store_local(DV_sym_59017_1_temporary_value, s_b_34_1);
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
        /* execute.a64:2709 [D] s_b_35_0 = sym_59017_1_temporary_value uint32_t */
        auto s_b_35_0 = emitter.load_local(DV_sym_59017_1_temporary_value, emitter.context().types().u32());
        /* execute.a64:2722 [D] s_b_35_1 = (u64)s_b_35_0 */
        auto s_b_35_1 = emitter.zx(s_b_35_0, emitter.context().types().u64());
        /* execute.a64:2722 [D] s_b_35_2: sym_58882_1__R_s_b_3_6 = s_b_35_1, dominates: s_b_21_1  */
        emitter.store_local(DV_sym_58882_1__R_s_b_3_6, s_b_35_1);
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
        /* execute.a64:2754 [F] s_b_36_0=sym_9258_3_parameter_inst.rd (const) */
        /* execute.a64:2754 [D] s_b_36_1 = sym_59042_3_parameter_value uint64_t */
        auto s_b_36_1 = emitter.load_local(DV_sym_59042_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2754 [D] s_b_36_2: sym_59116_3_parameter_value = s_b_36_1, dominates: s_b_40_1  */
        emitter.store_local(DV_sym_59116_3_parameter_value, s_b_36_1);
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
        /* execute.a64:2756 [F] s_b_37_0=sym_9258_3_parameter_inst.rd (const) */
        /* execute.a64:2756 [D] s_b_37_1 = sym_59042_3_parameter_value uint64_t */
        auto s_b_37_1 = emitter.load_local(DV_sym_59042_3_parameter_value, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_37_2 = (u32)s_b_37_1 */
        auto s_b_37_2 = emitter.truncate(s_b_37_1, emitter.context().types().u32());
        /* execute.a64:2756 [D] s_b_37_3 = (u64)s_b_37_2 */
        auto s_b_37_3 = emitter.zx(s_b_37_2, emitter.context().types().u64());
        /* execute.a64:2756 [D] s_b_37_4: sym_59138_3_parameter_value = s_b_37_3, dominates: s_b_41_1  */
        emitter.store_local(DV_sym_59138_3_parameter_value, s_b_37_3);
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
        /* execute.a64:2747 [F] s_b_38_0=sym_9258_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_38_1 = sym_59072_3_parameter_value uint64_t */
        auto s_b_38_1 = emitter.load_local(DV_sym_59072_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2747 [F] s_b_39_0=sym_9258_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_39_1 = sym_59094_3_parameter_value uint64_t */
        auto s_b_39_1 = emitter.load_local(DV_sym_59094_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2747 [F] s_b_40_0=sym_9258_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_40_1 = sym_59116_3_parameter_value uint64_t */
        auto s_b_40_1 = emitter.load_local(DV_sym_59116_3_parameter_value, emitter.context().types().u64());
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
        /* execute.a64:2747 [F] s_b_41_0=sym_9258_3_parameter_inst.rd (const) */
        /* execute.a64:2747 [D] s_b_41_1 = sym_59138_3_parameter_value uint64_t */
        auto s_b_41_1 = emitter.load_local(DV_sym_59138_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_exgen(const arm64_decode_a64_EX_GEN&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  emitter.mark_used_feature(4);
  emitter.mark_used_feature(5);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_60865_0_spsr = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_60741_0_parameter_syndrome;
  auto DV_sym_60743_0_parameter_retaddr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_60797_0_spsr = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_60745_0_parameter_voff;
  uint64_t CV_sym_60877_3_parameter_voff;
  auto DV_sym_60915_3_parameter_retaddr = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_60966_3_parameter_syndrome;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:356 [F] s_b_0_0=sym_10201_3_parameter_inst.opc (const) */
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
    /* execute.a64:357 [F] s_b_1_0=sym_10201_3_parameter_inst.imm16 (const) */
    /* execute.a64:2933 [D] s_b_1_1 = read_pc */
    auto s_b_1_1 = emitter.load_pc();
    /* execute.a64:2934 [F] s_b_1_2 = constant u64 0 (const) */
    /* execute.a64:2936 [F] s_b_1_3 = constant u8 1 (const) */
    /* execute.a64:2936 [F] s_b_1_4 = (u32)s_b_1_0 (const) */
    /* execute.a64:2936 [F] s_b_1_5: sym_60966_3_parameter_syndrome = s_b_1_4 (const), dominates: s_b_21_11  */
    CV_sym_60966_3_parameter_syndrome = ((uint32_t)insn.imm16);
    /* execute.a64:2936 [D] s_b_1_6: sym_60915_3_parameter_retaddr = s_b_1_1, dominates: s_b_21_8  */
    emitter.store_local(DV_sym_60915_3_parameter_retaddr, s_b_1_1);
    /* execute.a64:2936 [F] s_b_1_7: sym_60877_3_parameter_voff = s_b_1_2 (const), dominates: s_b_19_0 s_b_22_0 s_b_21_25  */
    CV_sym_60877_3_parameter_voff = (uint64_t)0ULL;
    /* execute.a64:2900 [D] s_b_1_8 = ReadReg 1 (u8) */
    auto s_b_1_8 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_1_8, emitter.const_u8(1));
    }
    /* execute.a64:2900 [D] s_b_1_9 = (u32)s_b_1_8 */
    auto s_b_1_9 = emitter.zx(s_b_1_8, emitter.context().types().u32());
    /* execute.a64:2900 [F] s_b_1_10 = constant u32 1f (const) */
    /* execute.a64:2900 [D] s_b_1_11 = s_b_1_9<<s_b_1_10 */
    auto s_b_1_11 = emitter.shl(s_b_1_9, emitter.const_u32((uint32_t)31ULL));
    /* execute.a64:2901 [D] s_b_1_12 = ReadReg 2 (u8) */
    auto s_b_1_12 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_1_12, emitter.const_u8(1));
    }
    /* execute.a64:2901 [D] s_b_1_13 = (u32)s_b_1_12 */
    auto s_b_1_13 = emitter.zx(s_b_1_12, emitter.context().types().u32());
    /* execute.a64:2901 [F] s_b_1_14 = constant u32 1e (const) */
    /* execute.a64:2901 [D] s_b_1_15 = s_b_1_13<<s_b_1_14 */
    auto s_b_1_15 = emitter.shl(s_b_1_13, emitter.const_u32((uint32_t)30ULL));
    /* execute.a64:2900 [D] s_b_1_16 = s_b_1_11|s_b_1_15 */
    auto s_b_1_16 = emitter.bitwise_or(s_b_1_11, s_b_1_15);
    /* execute.a64:2902 [D] s_b_1_17 = ReadReg 3 (u8) */
    auto s_b_1_17 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_1_17, emitter.const_u8(1));
    }
    /* execute.a64:2902 [D] s_b_1_18 = (u32)s_b_1_17 */
    auto s_b_1_18 = emitter.zx(s_b_1_17, emitter.context().types().u32());
    /* execute.a64:2902 [F] s_b_1_19 = constant u32 1d (const) */
    /* execute.a64:2902 [D] s_b_1_20 = s_b_1_18<<s_b_1_19 */
    auto s_b_1_20 = emitter.shl(s_b_1_18, emitter.const_u32((uint32_t)29ULL));
    /* execute.a64:2901 [D] s_b_1_21 = s_b_1_16|s_b_1_20 */
    auto s_b_1_21 = emitter.bitwise_or(s_b_1_16, s_b_1_20);
    /* execute.a64:2903 [D] s_b_1_22 = ReadReg 4 (u8) */
    auto s_b_1_22 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_1_22, emitter.const_u8(1));
    }
    /* execute.a64:2903 [D] s_b_1_23 = (u32)s_b_1_22 */
    auto s_b_1_23 = emitter.zx(s_b_1_22, emitter.context().types().u32());
    /* execute.a64:2903 [F] s_b_1_24 = constant u32 1c (const) */
    /* execute.a64:2903 [D] s_b_1_25 = s_b_1_23<<s_b_1_24 */
    auto s_b_1_25 = emitter.shl(s_b_1_23, emitter.const_u32((uint32_t)28ULL));
    /* execute.a64:2902 [D] s_b_1_26 = s_b_1_21|s_b_1_25 */
    auto s_b_1_26 = emitter.bitwise_or(s_b_1_21, s_b_1_25);
    /* execute.a64:2904 [D] s_b_1_27 = ReadReg 5 (u8) */
    auto s_b_1_27 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_1_27, emitter.const_u8(1));
    }
    /* execute.a64:2904 [D] s_b_1_28 = (u32)s_b_1_27 */
    auto s_b_1_28 = emitter.zx(s_b_1_27, emitter.context().types().u32());
    /* execute.a64:2904 [F] s_b_1_29 = constant u32 9 (const) */
    /* execute.a64:2904 [D] s_b_1_30 = s_b_1_28<<s_b_1_29 */
    auto s_b_1_30 = emitter.shl(s_b_1_28, emitter.const_u32((uint32_t)9ULL));
    /* execute.a64:2903 [D] s_b_1_31 = s_b_1_26|s_b_1_30 */
    auto s_b_1_31 = emitter.bitwise_or(s_b_1_26, s_b_1_30);
    /* execute.a64:2905 [D] s_b_1_32 = ReadReg 6 (u8) */
    auto s_b_1_32 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_1_32, emitter.const_u8(1));
    }
    /* execute.a64:2905 [D] s_b_1_33 = (u32)s_b_1_32 */
    auto s_b_1_33 = emitter.zx(s_b_1_32, emitter.context().types().u32());
    /* execute.a64:2905 [F] s_b_1_34 = constant u32 8 (const) */
    /* execute.a64:2905 [D] s_b_1_35 = s_b_1_33<<s_b_1_34 */
    auto s_b_1_35 = emitter.shl(s_b_1_33, emitter.const_u32((uint32_t)8ULL));
    /* execute.a64:2904 [D] s_b_1_36 = s_b_1_31|s_b_1_35 */
    auto s_b_1_36 = emitter.bitwise_or(s_b_1_31, s_b_1_35);
    /* execute.a64:2906 [D] s_b_1_37 = ReadReg 7 (u8) */
    auto s_b_1_37 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_1_37, emitter.const_u8(1));
    }
    /* execute.a64:2906 [D] s_b_1_38 = (u32)s_b_1_37 */
    auto s_b_1_38 = emitter.zx(s_b_1_37, emitter.context().types().u32());
    /* execute.a64:2906 [F] s_b_1_39 = constant u32 7 (const) */
    /* execute.a64:2906 [D] s_b_1_40 = s_b_1_38<<s_b_1_39 */
    auto s_b_1_40 = emitter.shl(s_b_1_38, emitter.const_u32((uint32_t)7ULL));
    /* execute.a64:2905 [D] s_b_1_41 = s_b_1_36|s_b_1_40 */
    auto s_b_1_41 = emitter.bitwise_or(s_b_1_36, s_b_1_40);
    /* execute.a64:2907 [D] s_b_1_42 = ReadReg 8 (u8) */
    auto s_b_1_42 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_1_42, emitter.const_u8(1));
    }
    /* execute.a64:2907 [D] s_b_1_43 = (u32)s_b_1_42 */
    auto s_b_1_43 = emitter.zx(s_b_1_42, emitter.context().types().u32());
    /* execute.a64:2907 [F] s_b_1_44 = constant u32 6 (const) */
    /* execute.a64:2907 [D] s_b_1_45 = s_b_1_43<<s_b_1_44 */
    auto s_b_1_45 = emitter.shl(s_b_1_43, emitter.const_u32((uint32_t)6ULL));
    /* execute.a64:2906 [D] s_b_1_46 = s_b_1_41|s_b_1_45 */
    auto s_b_1_46 = emitter.bitwise_or(s_b_1_41, s_b_1_45);
    /* execute.a64:3075 [F] s_b_1_47 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_1_48 = __builtin_get_feature */
    uint32_t s_b_1_48 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_1_49 = (u8)s_b_1_48 (const) */
    /* execute.a64:2908 [F] s_b_1_50 = (u32)s_b_1_49 (const) */
    /* execute.a64:2908 [F] s_b_1_51 = constant u32 2 (const) */
    /* execute.a64:2908 [F] s_b_1_52 = s_b_1_50<<s_b_1_51 (const) */
    uint32_t s_b_1_52 = ((uint32_t)(((uint32_t)((uint8_t)s_b_1_48)) << (uint32_t)2ULL));
    /* execute.a64:2907 [D] s_b_1_53 = s_b_1_46|s_b_1_52 */
    auto s_b_1_53 = emitter.bitwise_or(s_b_1_46, emitter.const_u32(s_b_1_52));
    /* execute.a64:2909 [F] s_b_1_54 = constant u32 1 (const) */
    /* execute.a64:2909 [F] s_b_1_55 = __builtin_get_feature */
    uint32_t s_b_1_55 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2909 [F] s_b_1_56 = (u32)s_b_1_55 (const) */
    /* execute.a64:2908 [D] s_b_1_57 = s_b_1_53|s_b_1_56 */
    auto s_b_1_57 = emitter.bitwise_or(s_b_1_53, emitter.const_u32(((uint32_t)s_b_1_55)));
    /* execute.a64:3022 [D] s_b_1_58: sym_60865_0_spsr = s_b_1_57, dominates: s_b_21_6  */
    emitter.store_local(DV_sym_60865_0_spsr, s_b_1_57);
    /* execute.a64:3075 [F] s_b_1_59 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_1_60 = __builtin_get_feature */
    uint32_t s_b_1_60 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_1_61 = (u8)s_b_1_60 (const) */
    /* execute.a64:3025 [F] s_b_1_62 = s_b_1_3>s_b_1_61 (const) */
    uint8_t s_b_1_62 = ((uint8_t)((uint8_t)1ULL > ((uint8_t)s_b_1_60)));
    /* execute.a64:3025 [F] s_b_1_63: If s_b_1_62: Jump b_19 else b_20 (const) */
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
    /* execute.a64:358 [F] s_b_3_0=sym_10201_3_parameter_inst.opc (const) */
    /* execute.a64:358 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:358 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:358 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:358 [F] s_b_3_4=sym_10201_3_parameter_inst.ll (const) */
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
    /* execute.a64:2942 [F] s_b_4_0 = constant u32 4 (const) */
    /* execute.a64:2942 [F] s_b_4_1 = __builtin_get_feature */
    uint32_t s_b_4_1 = __get_feature((uint32_t)4ULL);
    /* execute.a64:2942 [F] s_b_4_2: If s_b_4_1: Jump b_11 else b_12 (const) */
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
    /* execute.a64:360 [F] s_b_5_0=sym_10201_3_parameter_inst.opc (const) */
    /* execute.a64:360 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:360 [F] s_b_5_2 = constant u32 0 (const) */
    /* execute.a64:360 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)0ULL));
    /* execute.a64:360 [F] s_b_5_4=sym_10201_3_parameter_inst.ll (const) */
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
    /* execute.a64:363 [F] s_b_7_0=sym_10201_3_parameter_inst.opc (const) */
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
    /* execute.a64:364 [F] s_b_8_0=sym_10201_3_parameter_inst.imm16 (const) */
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
    /* execute.a64:2943 [F] s_b_11_0=sym_10201_3_parameter_inst.imm16 (const) */
    /* execute.a64:2943 [F] s_b_11_1 = constant u32 13 (const) */
    /* execute.a64:2943 [F] s_b_11_2 = constant u32 1 (const) */
    /* execute.a64:2943 [F] s_b_11_3 = (u64)s_b_11_0 (const) */
    /* ???:4294967295 [D] s_b_11_4 = write_device64 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_DEVICE,emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)1ULL), emitter.const_u64(((uint64_t)insn.imm16)));
    }
    emitter.store_device(emitter.const_u32((uint32_t)19ULL), emitter.const_u32((uint32_t)1ULL), emitter.const_u64(((uint64_t)insn.imm16)));
    /* execute.a64:2944 [D] s_b_11_5 = read_pc */
    auto s_b_11_5 = emitter.load_pc();
    /* execute.a64:2944 [F] s_b_11_6 = constant u64 4 (const) */
    /* execute.a64:2944 [D] s_b_11_7 = s_b_11_5+s_b_11_6 */
    auto s_b_11_7 = emitter.add(s_b_11_5, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2944 [D] s_b_11_8 = write_pc */
    emitter.store_pc(s_b_11_7);
    /* execute.a64:2943 [F] s_b_11_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2945 [F] s_b_12_0 = constant u32 5 (const) */
    /* execute.a64:2945 [F] s_b_12_1 = __builtin_get_feature */
    uint32_t s_b_12_1 = __get_feature((uint32_t)5ULL);
    /* execute.a64:2945 [F] s_b_12_2: If s_b_12_1: Jump b_13 else b_14 (const) */
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
    /* execute.a64:2946 [F] s_b_13_0 = constant u32 3 (const) */
    /* execute.a64:2946 [F] s_b_13_1=sym_10201_3_parameter_inst.imm16 (const) */
    /* execute.a64:2946 [F] s_b_13_2 = (u32)s_b_13_1 (const) */
    /* execute.a64:2946 [D] s_b_13_3 = take_exception */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2947 [D] s_b_13_4 = read_pc */
    auto s_b_13_4 = emitter.load_pc();
    /* execute.a64:2947 [F] s_b_13_5 = constant u64 4 (const) */
    /* execute.a64:2947 [D] s_b_13_6 = s_b_13_4+s_b_13_5 */
    auto s_b_13_6 = emitter.add(s_b_13_4, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2947 [D] s_b_13_7 = write_pc */
    emitter.store_pc(s_b_13_6);
    /* execute.a64:2946 [F] s_b_13_8: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2949 [D] s_b_14_0 = read_pc */
    auto s_b_14_0 = emitter.load_pc();
    /* execute.a64:2949 [F] s_b_14_1 = constant u64 4 (const) */
    /* execute.a64:2949 [D] s_b_14_2 = s_b_14_0+s_b_14_1 */
    auto s_b_14_2 = emitter.add(s_b_14_0, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:2950 [F] s_b_14_3 = constant u64 0 (const) */
    /* execute.a64:2952 [F] s_b_14_4 = constant u8 1 (const) */
    /* execute.a64:2952 [F] s_b_14_5=sym_10201_3_parameter_inst.imm16 (const) */
    /* execute.a64:2952 [F] s_b_14_6 = (u32)s_b_14_5 (const) */
    /* execute.a64:2952 [F] s_b_14_7: sym_60741_0_parameter_syndrome = s_b_14_6 (const), dominates: s_b_17_11  */
    CV_sym_60741_0_parameter_syndrome = ((uint32_t)insn.imm16);
    /* execute.a64:2952 [D] s_b_14_8: sym_60743_0_parameter_retaddr = s_b_14_2, dominates: s_b_17_8  */
    emitter.store_local(DV_sym_60743_0_parameter_retaddr, s_b_14_2);
    /* execute.a64:2952 [F] s_b_14_9: sym_60745_0_parameter_voff = s_b_14_3 (const), dominates: s_b_15_0 s_b_18_0 s_b_17_25  */
    CV_sym_60745_0_parameter_voff = (uint64_t)0ULL;
    /* execute.a64:2900 [D] s_b_14_10 = ReadReg 1 (u8) */
    auto s_b_14_10 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_14_10, emitter.const_u8(1));
    }
    /* execute.a64:2900 [D] s_b_14_11 = (u32)s_b_14_10 */
    auto s_b_14_11 = emitter.zx(s_b_14_10, emitter.context().types().u32());
    /* execute.a64:2900 [F] s_b_14_12 = constant u32 1f (const) */
    /* execute.a64:2900 [D] s_b_14_13 = s_b_14_11<<s_b_14_12 */
    auto s_b_14_13 = emitter.shl(s_b_14_11, emitter.const_u32((uint32_t)31ULL));
    /* execute.a64:2901 [D] s_b_14_14 = ReadReg 2 (u8) */
    auto s_b_14_14 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_14_14, emitter.const_u8(1));
    }
    /* execute.a64:2901 [D] s_b_14_15 = (u32)s_b_14_14 */
    auto s_b_14_15 = emitter.zx(s_b_14_14, emitter.context().types().u32());
    /* execute.a64:2901 [F] s_b_14_16 = constant u32 1e (const) */
    /* execute.a64:2901 [D] s_b_14_17 = s_b_14_15<<s_b_14_16 */
    auto s_b_14_17 = emitter.shl(s_b_14_15, emitter.const_u32((uint32_t)30ULL));
    /* execute.a64:2900 [D] s_b_14_18 = s_b_14_13|s_b_14_17 */
    auto s_b_14_18 = emitter.bitwise_or(s_b_14_13, s_b_14_17);
    /* execute.a64:2902 [D] s_b_14_19 = ReadReg 3 (u8) */
    auto s_b_14_19 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_14_19, emitter.const_u8(1));
    }
    /* execute.a64:2902 [D] s_b_14_20 = (u32)s_b_14_19 */
    auto s_b_14_20 = emitter.zx(s_b_14_19, emitter.context().types().u32());
    /* execute.a64:2902 [F] s_b_14_21 = constant u32 1d (const) */
    /* execute.a64:2902 [D] s_b_14_22 = s_b_14_20<<s_b_14_21 */
    auto s_b_14_22 = emitter.shl(s_b_14_20, emitter.const_u32((uint32_t)29ULL));
    /* execute.a64:2901 [D] s_b_14_23 = s_b_14_18|s_b_14_22 */
    auto s_b_14_23 = emitter.bitwise_or(s_b_14_18, s_b_14_22);
    /* execute.a64:2903 [D] s_b_14_24 = ReadReg 4 (u8) */
    auto s_b_14_24 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_14_24, emitter.const_u8(1));
    }
    /* execute.a64:2903 [D] s_b_14_25 = (u32)s_b_14_24 */
    auto s_b_14_25 = emitter.zx(s_b_14_24, emitter.context().types().u32());
    /* execute.a64:2903 [F] s_b_14_26 = constant u32 1c (const) */
    /* execute.a64:2903 [D] s_b_14_27 = s_b_14_25<<s_b_14_26 */
    auto s_b_14_27 = emitter.shl(s_b_14_25, emitter.const_u32((uint32_t)28ULL));
    /* execute.a64:2902 [D] s_b_14_28 = s_b_14_23|s_b_14_27 */
    auto s_b_14_28 = emitter.bitwise_or(s_b_14_23, s_b_14_27);
    /* execute.a64:2904 [D] s_b_14_29 = ReadReg 5 (u8) */
    auto s_b_14_29 = emitter.load_register(emitter.const_u32(1300), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1300), s_b_14_29, emitter.const_u8(1));
    }
    /* execute.a64:2904 [D] s_b_14_30 = (u32)s_b_14_29 */
    auto s_b_14_30 = emitter.zx(s_b_14_29, emitter.context().types().u32());
    /* execute.a64:2904 [F] s_b_14_31 = constant u32 9 (const) */
    /* execute.a64:2904 [D] s_b_14_32 = s_b_14_30<<s_b_14_31 */
    auto s_b_14_32 = emitter.shl(s_b_14_30, emitter.const_u32((uint32_t)9ULL));
    /* execute.a64:2903 [D] s_b_14_33 = s_b_14_28|s_b_14_32 */
    auto s_b_14_33 = emitter.bitwise_or(s_b_14_28, s_b_14_32);
    /* execute.a64:2905 [D] s_b_14_34 = ReadReg 6 (u8) */
    auto s_b_14_34 = emitter.load_register(emitter.const_u32(1301), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1301), s_b_14_34, emitter.const_u8(1));
    }
    /* execute.a64:2905 [D] s_b_14_35 = (u32)s_b_14_34 */
    auto s_b_14_35 = emitter.zx(s_b_14_34, emitter.context().types().u32());
    /* execute.a64:2905 [F] s_b_14_36 = constant u32 8 (const) */
    /* execute.a64:2905 [D] s_b_14_37 = s_b_14_35<<s_b_14_36 */
    auto s_b_14_37 = emitter.shl(s_b_14_35, emitter.const_u32((uint32_t)8ULL));
    /* execute.a64:2904 [D] s_b_14_38 = s_b_14_33|s_b_14_37 */
    auto s_b_14_38 = emitter.bitwise_or(s_b_14_33, s_b_14_37);
    /* execute.a64:2906 [D] s_b_14_39 = ReadReg 7 (u8) */
    auto s_b_14_39 = emitter.load_register(emitter.const_u32(1302), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1302), s_b_14_39, emitter.const_u8(1));
    }
    /* execute.a64:2906 [D] s_b_14_40 = (u32)s_b_14_39 */
    auto s_b_14_40 = emitter.zx(s_b_14_39, emitter.context().types().u32());
    /* execute.a64:2906 [F] s_b_14_41 = constant u32 7 (const) */
    /* execute.a64:2906 [D] s_b_14_42 = s_b_14_40<<s_b_14_41 */
    auto s_b_14_42 = emitter.shl(s_b_14_40, emitter.const_u32((uint32_t)7ULL));
    /* execute.a64:2905 [D] s_b_14_43 = s_b_14_38|s_b_14_42 */
    auto s_b_14_43 = emitter.bitwise_or(s_b_14_38, s_b_14_42);
    /* execute.a64:2907 [D] s_b_14_44 = ReadReg 8 (u8) */
    auto s_b_14_44 = emitter.load_register(emitter.const_u32(1303), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1303), s_b_14_44, emitter.const_u8(1));
    }
    /* execute.a64:2907 [D] s_b_14_45 = (u32)s_b_14_44 */
    auto s_b_14_45 = emitter.zx(s_b_14_44, emitter.context().types().u32());
    /* execute.a64:2907 [F] s_b_14_46 = constant u32 6 (const) */
    /* execute.a64:2907 [D] s_b_14_47 = s_b_14_45<<s_b_14_46 */
    auto s_b_14_47 = emitter.shl(s_b_14_45, emitter.const_u32((uint32_t)6ULL));
    /* execute.a64:2906 [D] s_b_14_48 = s_b_14_43|s_b_14_47 */
    auto s_b_14_48 = emitter.bitwise_or(s_b_14_43, s_b_14_47);
    /* execute.a64:3075 [F] s_b_14_49 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_14_50 = __builtin_get_feature */
    uint32_t s_b_14_50 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_14_51 = (u8)s_b_14_50 (const) */
    /* execute.a64:2908 [F] s_b_14_52 = (u32)s_b_14_51 (const) */
    /* execute.a64:2908 [F] s_b_14_53 = constant u32 2 (const) */
    /* execute.a64:2908 [F] s_b_14_54 = s_b_14_52<<s_b_14_53 (const) */
    uint32_t s_b_14_54 = ((uint32_t)(((uint32_t)((uint8_t)s_b_14_50)) << (uint32_t)2ULL));
    /* execute.a64:2907 [D] s_b_14_55 = s_b_14_48|s_b_14_54 */
    auto s_b_14_55 = emitter.bitwise_or(s_b_14_48, emitter.const_u32(s_b_14_54));
    /* execute.a64:2909 [F] s_b_14_56 = constant u32 1 (const) */
    /* execute.a64:2909 [F] s_b_14_57 = __builtin_get_feature */
    uint32_t s_b_14_57 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2909 [F] s_b_14_58 = (u32)s_b_14_57 (const) */
    /* execute.a64:2908 [D] s_b_14_59 = s_b_14_55|s_b_14_58 */
    auto s_b_14_59 = emitter.bitwise_or(s_b_14_55, emitter.const_u32(((uint32_t)s_b_14_57)));
    /* execute.a64:3022 [D] s_b_14_60: sym_60797_0_spsr = s_b_14_59, dominates: s_b_17_6  */
    emitter.store_local(DV_sym_60797_0_spsr, s_b_14_59);
    /* execute.a64:3075 [F] s_b_14_61 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_14_62 = __builtin_get_feature */
    uint32_t s_b_14_62 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_14_63 = (u8)s_b_14_62 (const) */
    /* execute.a64:3025 [F] s_b_14_64 = s_b_14_4>s_b_14_63 (const) */
    uint8_t s_b_14_64 = ((uint8_t)((uint8_t)1ULL > ((uint8_t)s_b_14_62)));
    /* execute.a64:3025 [F] s_b_14_65: If s_b_14_64: Jump b_15 else b_16 (const) */
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
    /* execute.a64:3026 [F] s_b_15_0 = sym_60745_0_parameter_voff (const) uint64_t */
    uint64_t s_b_15_0 = CV_sym_60745_0_parameter_voff;
    /* ???:4294967295 [F] s_b_15_1 = constant u64 400 (const) */
    /* ???:4294967295 [F] s_b_15_2 = s_b_15_0+s_b_15_1 (const) */
    uint64_t s_b_15_2 = ((uint64_t)(s_b_15_0 + (uint64_t)1024ULL));
    /* execute.a64:3026 [F] s_b_15_3: sym_60745_0_parameter_voff = s_b_15_2 (const), dominates: s_b_17_25  */
    CV_sym_60745_0_parameter_voff = s_b_15_2;
    /* execute.a64:3026 [F] s_b_15_4: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:3027 [F] s_b_16_0 = constant u32 1 (const) */
    /* execute.a64:3027 [F] s_b_16_1 = __builtin_get_feature */
    uint32_t s_b_16_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:3027 [F] s_b_16_2 = constant u32 1 (const) */
    /* execute.a64:3027 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(s_b_16_1 == (uint32_t)1ULL));
    /* execute.a64:3027 [F] s_b_16_4: If s_b_16_3: Jump b_18 else b_17 (const) */
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
    /* execute.a64:3080 [F] s_b_17_0 = constant u32 0 (const) */
    /* execute.a64:3080 [F] s_b_17_1 = constant u32 1 (const) */
    /* execute.a64:3080 [D] s_b_17_2 = __builtin_set_feature */
    emitter.set_feature((uint32_t)0ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:3016 [F] s_b_17_3 = constant u32 1 (const) */
    /* execute.a64:3016 [F] s_b_17_4 = constant u32 1 (const) */
    /* execute.a64:3016 [D] s_b_17_5 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:3038 [D] s_b_17_6 = sym_60797_0_spsr uint32_t */
    auto s_b_17_6 = emitter.load_local(DV_sym_60797_0_spsr, emitter.context().types().u32());
    /* execute.a64:3038 [D] s_b_17_7: WriteReg 18 = s_b_17_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1384), s_b_17_6, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1384), s_b_17_6);
    /* execute.a64:3039 [D] s_b_17_8 = sym_60743_0_parameter_retaddr uint64_t */
    auto s_b_17_8 = emitter.load_local(DV_sym_60743_0_parameter_retaddr, emitter.context().types().u64());
    /* execute.a64:3039 [D] s_b_17_9: WriteReg 17 = s_b_17_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1376), s_b_17_8, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1376), s_b_17_8);
    /* execute.a64:3044 [F] s_b_17_10 = constant u32 56000000 (const) */
    /* execute.a64:3044 [F] s_b_17_11 = sym_60741_0_parameter_syndrome (const) uint32_t */
    uint32_t s_b_17_11 = CV_sym_60741_0_parameter_syndrome;
    /* execute.a64:3044 [F] s_b_17_12 = constant u32 1ffffff (const) */
    /* execute.a64:3044 [F] s_b_17_13 = s_b_17_11&s_b_17_12 (const) */
    uint32_t s_b_17_13 = ((uint32_t)(s_b_17_11 & (uint32_t)33554431ULL));
    /* execute.a64:3044 [F] s_b_17_14 = s_b_17_10|s_b_17_13 (const) */
    uint32_t s_b_17_14 = ((uint32_t)((uint32_t)1442840576ULL | s_b_17_13));
    /* execute.a64:3044 [F] s_b_17_15: WriteReg 19 = s_b_17_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1392), emitter.const_u32(s_b_17_14), emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1392), emitter.const_u32(s_b_17_14));
    /* execute.a64:3054 [F] s_b_17_16 = constant u8 1 (const) */
    /* execute.a64:3054 [F] s_b_17_17: WriteReg 5 = s_b_17_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3055 [F] s_b_17_18 = constant u8 1 (const) */
    /* execute.a64:3055 [F] s_b_17_19: WriteReg 6 = s_b_17_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3056 [F] s_b_17_20 = constant u8 1 (const) */
    /* execute.a64:3056 [F] s_b_17_21: WriteReg 7 = s_b_17_20 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3057 [F] s_b_17_22 = constant u8 1 (const) */
    /* execute.a64:3057 [F] s_b_17_23: WriteReg 8 = s_b_17_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3059 [D] s_b_17_24 = ReadReg 13 (u64) */
    auto s_b_17_24 = emitter.load_register(emitter.const_u32(1336), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1336), s_b_17_24, emitter.const_u8(8));
    }
    /* execute.a64:3061 [F] s_b_17_25 = sym_60745_0_parameter_voff (const) uint64_t */
    uint64_t s_b_17_25 = CV_sym_60745_0_parameter_voff;
    /* execute.a64:3061 [D] s_b_17_26 = s_b_17_24+s_b_17_25 */
    auto s_b_17_26 = emitter.add(s_b_17_24, emitter.const_u64(s_b_17_25));
    /* execute.a64:3061 [D] s_b_17_27 = write_pc */
    emitter.store_pc(s_b_17_26);
    /* execute.a64:0 [F] s_b_17_28: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_16,  */
  fixed_block_b_18: 
  {
    /* execute.a64:3028 [F] s_b_18_0 = sym_60745_0_parameter_voff (const) uint64_t */
    uint64_t s_b_18_0 = CV_sym_60745_0_parameter_voff;
    /* ???:4294967295 [F] s_b_18_1 = constant u64 200 (const) */
    /* ???:4294967295 [F] s_b_18_2 = s_b_18_0+s_b_18_1 (const) */
    uint64_t s_b_18_2 = ((uint64_t)(s_b_18_0 + (uint64_t)512ULL));
    /* execute.a64:3028 [F] s_b_18_3: sym_60745_0_parameter_voff = s_b_18_2 (const), dominates: s_b_17_25  */
    CV_sym_60745_0_parameter_voff = s_b_18_2;
    /* execute.a64:3028 [F] s_b_18_4: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_1,  */
  fixed_block_b_19: 
  {
    /* execute.a64:3026 [F] s_b_19_0 = sym_60877_3_parameter_voff (const) uint64_t */
    uint64_t s_b_19_0 = CV_sym_60877_3_parameter_voff;
    /* ???:4294967295 [F] s_b_19_1 = constant u64 400 (const) */
    /* ???:4294967295 [F] s_b_19_2 = s_b_19_0+s_b_19_1 (const) */
    uint64_t s_b_19_2 = ((uint64_t)(s_b_19_0 + (uint64_t)1024ULL));
    /* execute.a64:3026 [F] s_b_19_3: sym_60877_3_parameter_voff = s_b_19_2 (const), dominates: s_b_21_25  */
    CV_sym_60877_3_parameter_voff = s_b_19_2;
    /* execute.a64:3026 [F] s_b_19_4: Jump b_21 (const) */
    goto fixed_block_b_21;
  }
  /* b_1,  */
  fixed_block_b_20: 
  {
    /* execute.a64:3027 [F] s_b_20_0 = constant u32 1 (const) */
    /* execute.a64:3027 [F] s_b_20_1 = __builtin_get_feature */
    uint32_t s_b_20_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:3027 [F] s_b_20_2 = constant u32 1 (const) */
    /* execute.a64:3027 [F] s_b_20_3 = s_b_20_1==s_b_20_2 (const) */
    uint8_t s_b_20_3 = ((uint8_t)(s_b_20_1 == (uint32_t)1ULL));
    /* execute.a64:3027 [F] s_b_20_4: If s_b_20_3: Jump b_22 else b_21 (const) */
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
    /* execute.a64:3080 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:3080 [F] s_b_21_1 = constant u32 1 (const) */
    /* execute.a64:3080 [D] s_b_21_2 = __builtin_set_feature */
    emitter.set_feature((uint32_t)0ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:3016 [F] s_b_21_3 = constant u32 1 (const) */
    /* execute.a64:3016 [F] s_b_21_4 = constant u32 1 (const) */
    /* execute.a64:3016 [D] s_b_21_5 = __builtin_set_feature */
    emitter.set_feature((uint32_t)1ULL, emitter.const_u32((uint32_t)1ULL));
    /* execute.a64:3038 [D] s_b_21_6 = sym_60865_0_spsr uint32_t */
    auto s_b_21_6 = emitter.load_local(DV_sym_60865_0_spsr, emitter.context().types().u32());
    /* execute.a64:3038 [D] s_b_21_7: WriteReg 18 = s_b_21_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1384), s_b_21_6, emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1384), s_b_21_6);
    /* execute.a64:3039 [D] s_b_21_8 = sym_60915_3_parameter_retaddr uint64_t */
    auto s_b_21_8 = emitter.load_local(DV_sym_60915_3_parameter_retaddr, emitter.context().types().u64());
    /* execute.a64:3039 [D] s_b_21_9: WriteReg 17 = s_b_21_8 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1376), s_b_21_8, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1376), s_b_21_8);
    /* execute.a64:3044 [F] s_b_21_10 = constant u32 f2000000 (const) */
    /* execute.a64:3044 [F] s_b_21_11 = sym_60966_3_parameter_syndrome (const) uint32_t */
    uint32_t s_b_21_11 = CV_sym_60966_3_parameter_syndrome;
    /* execute.a64:3044 [F] s_b_21_12 = constant u32 1ffffff (const) */
    /* execute.a64:3044 [F] s_b_21_13 = s_b_21_11&s_b_21_12 (const) */
    uint32_t s_b_21_13 = ((uint32_t)(s_b_21_11 & (uint32_t)33554431ULL));
    /* execute.a64:3044 [F] s_b_21_14 = s_b_21_10|s_b_21_13 (const) */
    uint32_t s_b_21_14 = ((uint32_t)((uint32_t)4060086272ULL | s_b_21_13));
    /* execute.a64:3044 [F] s_b_21_15: WriteReg 19 = s_b_21_14 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1392), emitter.const_u32(s_b_21_14), emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32(1392), emitter.const_u32(s_b_21_14));
    /* execute.a64:3054 [F] s_b_21_16 = constant u8 1 (const) */
    /* execute.a64:3054 [F] s_b_21_17: WriteReg 5 = s_b_21_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1300), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3055 [F] s_b_21_18 = constant u8 1 (const) */
    /* execute.a64:3055 [F] s_b_21_19: WriteReg 6 = s_b_21_18 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1301), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3056 [F] s_b_21_20 = constant u8 1 (const) */
    /* execute.a64:3056 [F] s_b_21_21: WriteReg 7 = s_b_21_20 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1302), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3057 [F] s_b_21_22 = constant u8 1 (const) */
    /* execute.a64:3057 [F] s_b_21_23: WriteReg 8 = s_b_21_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL), emitter.const_u8(1));
    }
    emitter.store_register(emitter.const_u32(1303), emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:3059 [D] s_b_21_24 = ReadReg 13 (u64) */
    auto s_b_21_24 = emitter.load_register(emitter.const_u32(1336), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1336), s_b_21_24, emitter.const_u8(8));
    }
    /* execute.a64:3061 [F] s_b_21_25 = sym_60877_3_parameter_voff (const) uint64_t */
    uint64_t s_b_21_25 = CV_sym_60877_3_parameter_voff;
    /* execute.a64:3061 [D] s_b_21_26 = s_b_21_24+s_b_21_25 */
    auto s_b_21_26 = emitter.add(s_b_21_24, emitter.const_u64(s_b_21_25));
    /* execute.a64:3061 [D] s_b_21_27 = write_pc */
    emitter.store_pc(s_b_21_26);
    /* execute.a64:0 [F] s_b_21_28: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_20,  */
  fixed_block_b_22: 
  {
    /* execute.a64:3028 [F] s_b_22_0 = sym_60877_3_parameter_voff (const) uint64_t */
    uint64_t s_b_22_0 = CV_sym_60877_3_parameter_voff;
    /* ???:4294967295 [F] s_b_22_1 = constant u64 200 (const) */
    /* ???:4294967295 [F] s_b_22_2 = s_b_22_0+s_b_22_1 (const) */
    uint64_t s_b_22_2 = ((uint64_t)(s_b_22_0 + (uint64_t)512ULL));
    /* execute.a64:3028 [F] s_b_22_3: sym_60877_3_parameter_voff = s_b_22_2 (const), dominates: s_b_21_25  */
    CV_sym_60877_3_parameter_voff = s_b_22_2;
    /* execute.a64:3028 [F] s_b_22_4: Jump b_21 (const) */
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
  auto DV_sym_10788_0_rn = emitter.alloc_local(emitter.context().types().f32(), false);
  float CV_sym_10807_1_temporary_value;
  auto DV_sym_10807_1_temporary_value = emitter.alloc_local(emitter.context().types().f32(), false);
  auto DV_sym_10870_0_rm = emitter.alloc_local(emitter.context().types().f64(), false);
  double CV_sym_10859_1_temporary_value;
  auto DV_sym_10859_1_temporary_value = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_10840_0_rn = emitter.alloc_local(emitter.context().types().f64(), false);
  auto DV_sym_10818_0_rm = emitter.alloc_local(emitter.context().types().f32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4775 [F] s_b_0_0=sym_10775_3_parameter_inst.type (const) */
    /* execute.simd:4775 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4775 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4775 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4775 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4777 [F] s_b_1_0=sym_10775_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4777 [D] s_b_1_2: sym_10788_0_rn = s_b_1_1, dominates: s_b_7_0 s_b_8_0  */
    emitter.store_local(DV_sym_10788_0_rn, s_b_1_1);
    /* execute.simd:4778 [F] s_b_1_3=sym_10775_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4778 [F] s_b_1_4 = (u32)s_b_1_3 (const) */
    /* execute.simd:4778 [F] s_b_1_5 = constant u32 18 (const) */
    /* execute.simd:4778 [F] s_b_1_6 = s_b_1_4==s_b_1_5 (const) */
    uint8_t s_b_1_6 = ((uint8_t)(((uint32_t)insn.opcode2) == (uint32_t)24ULL));
    /* execute.simd:4778 [F] s_b_1_7=sym_10775_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4778 [F] s_b_1_8 = (u32)s_b_1_7 (const) */
    /* execute.simd:4778 [F] s_b_1_9 = constant u32 8 (const) */
    /* execute.simd:4778 [F] s_b_1_10 = s_b_1_8==s_b_1_9 (const) */
    uint8_t s_b_1_10 = ((uint8_t)(((uint32_t)insn.opcode2) == (uint32_t)8ULL));
    /* ???:4294967295 [F] s_b_1_11 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_1_12 = s_b_1_6!=s_b_1_11 (const) */
    uint8_t s_b_1_12 = ((uint8_t)(s_b_1_6 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_13 = s_b_1_10!=s_b_1_11 (const) */
    uint8_t s_b_1_13 = ((uint8_t)(s_b_1_10 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_1_14 = s_b_1_12|s_b_1_13 (const) */
    uint8_t s_b_1_14 = ((uint8_t)(s_b_1_12 | s_b_1_13));
    /* execute.simd:4778 [F] s_b_1_15: If s_b_1_14: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4787 [F] s_b_3_0=sym_10775_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4787 [D] s_b_3_2: sym_10840_0_rn = s_b_3_1, dominates: s_b_12_0 s_b_13_0  */
    emitter.store_local(DV_sym_10840_0_rn, s_b_3_1);
    /* execute.simd:4788 [F] s_b_3_3=sym_10775_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4788 [F] s_b_3_4 = (u32)s_b_3_3 (const) */
    /* execute.simd:4788 [F] s_b_3_5 = constant u32 18 (const) */
    /* execute.simd:4788 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint32_t)insn.opcode2) == (uint32_t)24ULL));
    /* execute.simd:4788 [F] s_b_3_7=sym_10775_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4788 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
    /* execute.simd:4788 [F] s_b_3_9 = constant u32 8 (const) */
    /* execute.simd:4788 [F] s_b_3_10 = s_b_3_8==s_b_3_9 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(((uint32_t)insn.opcode2) == (uint32_t)8ULL));
    /* ???:4294967295 [F] s_b_3_11 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_12 = s_b_3_6!=s_b_3_11 (const) */
    uint8_t s_b_3_12 = ((uint8_t)(s_b_3_6 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_13 = s_b_3_10!=s_b_3_11 (const) */
    uint8_t s_b_3_13 = ((uint8_t)(s_b_3_10 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_14 = s_b_3_12|s_b_3_13 (const) */
    uint8_t s_b_3_14 = ((uint8_t)(s_b_3_12 | s_b_3_13));
    /* execute.simd:4788 [F] s_b_3_15: If s_b_3_14: Jump b_9 else b_10 (const) */
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
    /* execute.simd:4778 [F] s_b_4_0 = constant f32 0 (const) */
    float s_b_4_0;
    {
      uint32_t __tmp = 0;
      s_b_4_0 = *(float *)&__tmp;
    }
    /* execute.simd:4778 [F] s_b_4_1: sym_10807_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_10807_1_temporary_value = s_b_4_0;
    emitter.store_local(DV_sym_10807_1_temporary_value, emitter.const_f32(s_b_4_0));
    /* execute.simd:4778 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.simd:4778 [F] s_b_5_0=sym_10775_3_parameter_inst.rm (const) */
    /* execute.simd:6280 [D] s_b_5_1 = ReadRegBank 9:s_b_5_0 (f32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_1,emitter.const_u8(4));
    }
    /* execute.simd:4778 [D] s_b_5_2: sym_10807_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_10807_1_temporary_value, s_b_5_1);
    /* execute.simd:4778 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.simd:4778 [D] s_b_6_0 = sym_10807_1_temporary_value float */
    auto s_b_6_0 = emitter.load_local(DV_sym_10807_1_temporary_value, emitter.context().types().f32());
    /* execute.simd:4778 [D] s_b_6_1: sym_10818_0_rm = s_b_6_0, dominates: s_b_7_1 s_b_8_1  */
    emitter.store_local(DV_sym_10818_0_rm, s_b_6_0);
    /* execute.simd:4780 [F] s_b_6_2=sym_10775_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4780 [F] s_b_6_3 = (u32)s_b_6_2 (const) */
    /* execute.simd:4780 [F] s_b_6_4 = constant u32 10 (const) */
    /* execute.simd:4780 [F] s_b_6_5 = s_b_6_3&s_b_6_4 (const) */
    uint32_t s_b_6_5 = ((uint32_t)(((uint32_t)insn.opcode2) & (uint32_t)16ULL));
    /* execute.simd:4780 [F] s_b_6_6: If s_b_6_5: Jump b_7 else b_8 (const) */
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
    /* execute.simd:4781 [D] s_b_7_0 = sym_10788_0_rn float */
    auto s_b_7_0 = emitter.load_local(DV_sym_10788_0_rn, emitter.context().types().f32());
    /* execute.simd:4781 [D] s_b_7_1 = sym_10818_0_rm float */
    auto s_b_7_1 = emitter.load_local(DV_sym_10818_0_rm, emitter.context().types().f32());
    /* execute.simd:4781 [D] s_b_7_2 = __builtin_cmpf32e_flags */
    emitter.call(__captive___builtin_cmpf32e_flags, s_b_7_0, s_b_7_1);
    /* execute.simd:4781 [F] s_b_7_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.simd:4783 [D] s_b_8_0 = sym_10788_0_rn float */
    auto s_b_8_0 = emitter.load_local(DV_sym_10788_0_rn, emitter.context().types().f32());
    /* execute.simd:4783 [D] s_b_8_1 = sym_10818_0_rm float */
    auto s_b_8_1 = emitter.load_local(DV_sym_10818_0_rm, emitter.context().types().f32());
    /* execute.simd:4783 [D] s_b_8_2 = __builtin_cmpf32_flags */
    emitter.call(__captive___builtin_cmpf32_flags, s_b_8_0, s_b_8_1);
    /* execute.simd:4783 [F] s_b_8_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4788 [F] s_b_9_0 = constant f64 0 (const) */
    double s_b_9_0;
    {
      uint64_t __tmp = 0;
      s_b_9_0 = *(double *)&__tmp;
    }
    /* execute.simd:4788 [F] s_b_9_1: sym_10859_1_temporary_value = s_b_9_0 (const), dominates: s_b_11_0  */
    CV_sym_10859_1_temporary_value = s_b_9_0;
    emitter.store_local(DV_sym_10859_1_temporary_value, emitter.const_f64(s_b_9_0));
    /* execute.simd:4788 [F] s_b_9_2: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_3,  */
  fixed_block_b_10: 
  {
    /* execute.simd:4788 [F] s_b_10_0=sym_10775_3_parameter_inst.rm (const) */
    /* execute.simd:6285 [D] s_b_10_1 = ReadRegBank 11:s_b_10_0 (f64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_10_1,emitter.const_u8(8));
    }
    /* execute.simd:4788 [D] s_b_10_2: sym_10859_1_temporary_value = s_b_10_1, dominates: s_b_11_0  */
    emitter.store_local(DV_sym_10859_1_temporary_value, s_b_10_1);
    /* execute.simd:4788 [F] s_b_10_3: Jump b_11 (const) */
    goto fixed_block_b_11;
  }
  /* b_9, b_10,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4788 [D] s_b_11_0 = sym_10859_1_temporary_value double */
    auto s_b_11_0 = emitter.load_local(DV_sym_10859_1_temporary_value, emitter.context().types().f64());
    /* execute.simd:4788 [D] s_b_11_1: sym_10870_0_rm = s_b_11_0, dominates: s_b_12_1 s_b_13_1  */
    emitter.store_local(DV_sym_10870_0_rm, s_b_11_0);
    /* execute.simd:4790 [F] s_b_11_2=sym_10775_3_parameter_inst.opcode2 (const) */
    /* execute.simd:4790 [F] s_b_11_3 = (u32)s_b_11_2 (const) */
    /* execute.simd:4790 [F] s_b_11_4 = constant u32 10 (const) */
    /* execute.simd:4790 [F] s_b_11_5 = s_b_11_3&s_b_11_4 (const) */
    uint32_t s_b_11_5 = ((uint32_t)(((uint32_t)insn.opcode2) & (uint32_t)16ULL));
    /* execute.simd:4790 [F] s_b_11_6: If s_b_11_5: Jump b_12 else b_13 (const) */
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
    /* execute.simd:4791 [D] s_b_12_0 = sym_10840_0_rn double */
    auto s_b_12_0 = emitter.load_local(DV_sym_10840_0_rn, emitter.context().types().f64());
    /* execute.simd:4791 [D] s_b_12_1 = sym_10870_0_rm double */
    auto s_b_12_1 = emitter.load_local(DV_sym_10870_0_rm, emitter.context().types().f64());
    /* execute.simd:4791 [D] s_b_12_2 = __builtin_cmpf64e_flags */
    emitter.call(__captive___builtin_cmpf64e_flags, s_b_12_0, s_b_12_1);
    /* execute.simd:4791 [F] s_b_12_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:4793 [D] s_b_13_0 = sym_10840_0_rn double */
    auto s_b_13_0 = emitter.load_local(DV_sym_10840_0_rn, emitter.context().types().f64());
    /* execute.simd:4793 [D] s_b_13_1 = sym_10870_0_rm double */
    auto s_b_13_1 = emitter.load_local(DV_sym_10870_0_rm, emitter.context().types().f64());
    /* execute.simd:4793 [D] s_b_13_2 = __builtin_cmpf64_flags */
    emitter.call(__captive___builtin_cmpf64_flags, s_b_13_0, s_b_13_1);
    /* execute.simd:4793 [F] s_b_13_3: Jump b_2 (const) */
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
    /* execute.simd:4234 [F] s_b_0_0=sym_11755_3_parameter_inst.type (const) */
    /* execute.simd:4234 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4234 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4234 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4234 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4236 [F] s_b_1_0=sym_11755_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_1_1 = ReadRegBank 9:s_b_1_0 (f32) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_1,emitter.const_u8(4));
    }
    /* execute.simd:4237 [F] s_b_1_2=sym_11755_3_parameter_inst.rm (const) */
    /* execute.simd:6280 [D] s_b_1_3 = ReadRegBank 9:s_b_1_2 (f32) */
    auto s_b_1_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_1_3,emitter.const_u8(4));
    }
    /* execute.simd:4239 [D] s_b_1_4 = s_b_1_1/s_b_1_3 */
    auto s_b_1_4 = emitter.div(s_b_1_1, s_b_1_3);
    /* execute.simd:4240 [F] s_b_1_5=sym_11755_3_parameter_inst.rd (const) */
    /* execute.simd:6290 [D] s_b_1_6: WriteRegBank 9:s_b_1_5 = s_b_1_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_4);
    /* execute.simd:6291 [F] s_b_1_7 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_1_8: WriteRegBank 10:s_b_1_5 = s_b_1_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_1_9 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_1_10: WriteRegBank 3:s_b_1_5 = s_b_1_9 */
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
    /* execute.simd:4243 [F] s_b_3_0=sym_11755_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_3_1 = ReadRegBank 11:s_b_3_0 (f64) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(8));
    }
    /* execute.simd:4244 [F] s_b_3_2=sym_11755_3_parameter_inst.rm (const) */
    /* execute.simd:6285 [D] s_b_3_3 = ReadRegBank 11:s_b_3_2 (f64) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(8));
    }
    /* execute.simd:4246 [D] s_b_3_4 = s_b_3_1/s_b_3_3 */
    auto s_b_3_4 = emitter.div(s_b_3_1, s_b_3_3);
    /* execute.simd:4247 [F] s_b_3_5=sym_11755_3_parameter_inst.rd (const) */
    /* execute.simd:6298 [D] s_b_3_6: WriteRegBank 11:s_b_3_5 = s_b_3_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_4);
    /* execute.simd:6299 [F] s_b_3_7 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_3_8: WriteRegBank 3:s_b_3_5 = s_b_3_7 */
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
    /* execute.simd:5030 [F] s_b_0_0=sym_12227_3_parameter_inst.op (const) */
    /* execute.simd:5030 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:5030 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:5030 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.op) == (uint32_t)0ULL));
    /* execute.simd:5030 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:5031 [F] s_b_1_0=sym_12227_3_parameter_inst.Q (const) */
    /* execute.simd:5031 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:5031 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:5031 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:5031 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:5038 [F] s_b_3_0=sym_12227_3_parameter_inst.Q (const) */
    /* execute.simd:5038 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:5038 [F] s_b_3_2 = constant u32 1 (const) */
    /* execute.simd:5038 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* execute.simd:5038 [F] s_b_3_4=sym_12227_3_parameter_inst.op (const) */
    /* execute.simd:5038 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:5038 [F] s_b_3_6 = constant u32 1 (const) */
    /* execute.simd:5038 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.op) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:5038 [F] s_b_3_12: If s_b_3_11: Jump b_6 else b_2 (const) */
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
    /* execute.simd:5033 [F] s_b_4_0=sym_12227_3_parameter_inst.rd (const) */
    /* execute.simd:5033 [F] s_b_4_1=sym_12227_3_parameter_inst.immu64 (const) */
    /* execute.simd:6326 [F] s_b_4_2: WriteRegBank 2:s_b_4_0 = s_b_4_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6327 [F] s_b_4_3 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_4_4: WriteRegBank 3:s_b_4_0 = s_b_4_3 */
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
    /* execute.simd:5036 [F] s_b_5_0=sym_12227_3_parameter_inst.rd (const) */
    /* execute.simd:5036 [F] s_b_5_1=sym_12227_3_parameter_inst.immu64 (const) */
    /* execute.simd:5036 [F] s_b_5_2=sym_12227_3_parameter_inst.immu64 (const) */
    /* execute.simd:6333 [F] s_b_5_3: WriteRegBank 2:s_b_5_0 = s_b_5_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6334 [F] s_b_5_4: WriteRegBank 3:s_b_5_0 = s_b_5_2 */
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
    /* execute.simd:5040 [F] s_b_6_0=sym_12227_3_parameter_inst.rd (const) */
    /* execute.simd:5040 [F] s_b_6_1=sym_12227_3_parameter_inst.immu64 (const) */
    /* execute.simd:5040 [F] s_b_6_2=sym_12227_3_parameter_inst.immu64 (const) */
    /* execute.simd:6333 [F] s_b_6_3: WriteRegBank 2:s_b_6_0 = s_b_6_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),emitter.const_u64(insn.immu64));
    /* execute.simd:6334 [F] s_b_6_4: WriteRegBank 3:s_b_6_0 = s_b_6_2 */
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
    /* execute.simd:4757 [F] s_b_0_0=sym_12697_3_parameter_inst.type (const) */
    /* execute.simd:4757 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.simd:4757 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.simd:4757 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.type) == (uint32_t)0ULL));
    /* execute.simd:4757 [F] s_b_0_4: If s_b_0_3: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4758 [F] s_b_1_0=sym_12697_3_parameter_inst.rd (const) */
    /* execute.simd:4758 [F] s_b_1_1=sym_12697_3_parameter_inst.rn (const) */
    /* execute.simd:6280 [D] s_b_1_2 = ReadRegBank 9:s_b_1_1 (f32) */
    auto s_b_1_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_1_2,emitter.const_u8(4));
    }
    /* execute.simd:4758 [D] s_b_1_3 = float_sqrt */
    auto s_b_1_3 = emitter.call(__captive_float_sqrt, s_b_1_2);
    /* execute.simd:6290 [D] s_b_1_4: WriteRegBank 9:s_b_1_0 = s_b_1_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_1_3);
    /* execute.simd:6291 [F] s_b_1_5 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_1_6: WriteRegBank 10:s_b_1_0 = s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_1_7 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_1_8: WriteRegBank 3:s_b_1_0 = s_b_1_7 */
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
    /* execute.simd:4760 [F] s_b_3_0=sym_12697_3_parameter_inst.rd (const) */
    /* execute.simd:4760 [F] s_b_3_1=sym_12697_3_parameter_inst.rn (const) */
    /* execute.simd:6285 [D] s_b_3_2 = ReadRegBank 11:s_b_3_1 (f64) */
    auto s_b_3_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().f64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_2,emitter.const_u8(8));
    }
    /* execute.simd:4760 [D] s_b_3_3 = double_sqrt */
    auto s_b_3_3 = emitter.call(__captive_double_sqrt, s_b_3_2);
    /* execute.simd:6298 [D] s_b_3_4: WriteRegBank 11:s_b_3_0 = s_b_3_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3);
    /* execute.simd:6299 [F] s_b_3_5 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_3_6: WriteRegBank 3:s_b_3_0 = s_b_3_5 */
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
  auto DV_sym_66934_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_66972_1__R_s_b_21_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_13360_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_13325_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_13290_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_13255_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_13248_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_13242_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:2793 [F] s_b_0_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_4: If s_b_0_3: Jump b_16 else b_14 (const) */
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
    /* execute.simd:2736 [D] s_b_2_0 = sym_13248_0_addr uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_13248_0_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_1 = Load 1 s_b_2_0 => sym_13255_0_value */
    auto s_b_2_1 = emitter.load_memory(s_b_2_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_13255_0_value, s_b_2_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_1, emitter.const_u8(1));
    }
    /* execute.simd:2738 [F] s_b_2_2=sym_13242_3_parameter_inst.Q (const) */
    /* execute.simd:2738 [F] s_b_2_3 = (u32)s_b_2_2 (const) */
    /* execute.simd:2738 [F] s_b_2_4 = constant u32 0 (const) */
    /* execute.simd:2738 [F] s_b_2_5 = s_b_2_3==s_b_2_4 (const) */
    uint8_t s_b_2_5 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:2738 [F] s_b_2_6: If s_b_2_5: Jump b_3 else b_4 (const) */
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
    /* execute.simd:2739 [D] s_b_3_0 = sym_13255_0_value uint8_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_13255_0_value, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_3_1 = (v8u8)s_b_3_0 */
    auto s_b_3_1 = emitter.splat(s_b_3_0, emitter.context().types().v8u8());
    /* execute.simd:2740 [F] s_b_3_2=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2740 [D] s_b_3_3: WriteRegBank 15:s_b_3_2 = s_b_3_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_1);
    /* execute.simd:2741 [F] s_b_3_4=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2741 [F] s_b_3_5 = constant u64 0 (const) */
    /* execute.simd:2741 [F] s_b_3_6: WriteRegBank 3:s_b_3_4 = s_b_3_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2739 [F] s_b_3_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_2,  */
  fixed_block_b_4: 
  {
    /* execute.simd:2743 [D] s_b_4_0 = sym_13255_0_value uint8_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_13255_0_value, emitter.context().types().u8());
    /* ???:4294967295 [D] s_b_4_1 = (v16u8)s_b_4_0 */
    auto s_b_4_1 = emitter.splat(s_b_4_0, emitter.context().types().v16u8());
    /* execute.simd:2744 [F] s_b_4_2=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2744 [D] s_b_4_3: WriteRegBank 16:s_b_4_2 = s_b_4_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_4_1,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_4_1);
    /* execute.simd:2743 [F] s_b_4_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_5: 
  {
    /* execute.simd:2750 [D] s_b_5_0 = sym_13248_0_addr uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_13248_0_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_5_1 = Load 2 s_b_5_0 => sym_13290_0_value */
    auto s_b_5_1 = emitter.load_memory(s_b_5_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_13290_0_value, s_b_5_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_5_0, s_b_5_1, emitter.const_u8(2));
    }
    /* execute.simd:2752 [F] s_b_5_2=sym_13242_3_parameter_inst.Q (const) */
    /* execute.simd:2752 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.simd:2752 [F] s_b_5_4 = constant u32 0 (const) */
    /* execute.simd:2752 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:2752 [F] s_b_5_6: If s_b_5_5: Jump b_6 else b_7 (const) */
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
    /* execute.simd:2753 [D] s_b_6_0 = sym_13290_0_value uint16_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_13290_0_value, emitter.context().types().u16());
    /* ???:4294967295 [D] s_b_6_1 = (v4u16)s_b_6_0 */
    auto s_b_6_1 = emitter.splat(s_b_6_0, emitter.context().types().v4u16());
    /* execute.simd:2754 [F] s_b_6_2=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2754 [D] s_b_6_3: WriteRegBank 17:s_b_6_2 = s_b_6_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_6_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_6_1);
    /* execute.simd:2755 [F] s_b_6_4=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2755 [F] s_b_6_5 = constant u64 0 (const) */
    /* execute.simd:2755 [F] s_b_6_6: WriteRegBank 3:s_b_6_4 = s_b_6_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2753 [F] s_b_6_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_5,  */
  fixed_block_b_7: 
  {
    /* execute.simd:2757 [D] s_b_7_0 = sym_13290_0_value uint16_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_13290_0_value, emitter.context().types().u16());
    /* ???:4294967295 [D] s_b_7_1 = (v8u16)s_b_7_0 */
    auto s_b_7_1 = emitter.splat(s_b_7_0, emitter.context().types().v8u16());
    /* execute.simd:2758 [F] s_b_7_2=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2758 [D] s_b_7_3: WriteRegBank 18:s_b_7_2 = s_b_7_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_7_1,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_7_1);
    /* execute.simd:2757 [F] s_b_7_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_8: 
  {
    /* execute.simd:2764 [D] s_b_8_0 = sym_13248_0_addr uint64_t */
    auto s_b_8_0 = emitter.load_local(DV_sym_13248_0_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_8_1 = Load 4 s_b_8_0 => sym_13325_0_value */
    auto s_b_8_1 = emitter.load_memory(s_b_8_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_13325_0_value, s_b_8_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_8_0, s_b_8_1, emitter.const_u8(4));
    }
    /* execute.simd:2766 [F] s_b_8_2=sym_13242_3_parameter_inst.Q (const) */
    /* execute.simd:2766 [F] s_b_8_3 = (u32)s_b_8_2 (const) */
    /* execute.simd:2766 [F] s_b_8_4 = constant u32 0 (const) */
    /* execute.simd:2766 [F] s_b_8_5 = s_b_8_3==s_b_8_4 (const) */
    uint8_t s_b_8_5 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:2766 [F] s_b_8_6: If s_b_8_5: Jump b_9 else b_10 (const) */
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
    /* execute.simd:2767 [D] s_b_9_0 = sym_13325_0_value uint32_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_13325_0_value, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_9_1 = (v2u32)s_b_9_0 */
    auto s_b_9_1 = emitter.splat(s_b_9_0, emitter.context().types().v2u32());
    /* execute.simd:2768 [F] s_b_9_2=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2768 [D] s_b_9_3: WriteRegBank 19:s_b_9_2 = s_b_9_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_1);
    /* execute.simd:2769 [F] s_b_9_4=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2769 [F] s_b_9_5 = constant u64 0 (const) */
    /* execute.simd:2769 [F] s_b_9_6: WriteRegBank 3:s_b_9_4 = s_b_9_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2767 [F] s_b_9_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_8,  */
  fixed_block_b_10: 
  {
    /* execute.simd:2771 [D] s_b_10_0 = sym_13325_0_value uint32_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_13325_0_value, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_10_1 = (v4u32)s_b_10_0 */
    auto s_b_10_1 = emitter.splat(s_b_10_0, emitter.context().types().v4u32());
    /* execute.simd:2772 [F] s_b_10_2=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2772 [D] s_b_10_3: WriteRegBank 20:s_b_10_2 = s_b_10_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_1,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_1);
    /* execute.simd:2771 [F] s_b_10_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_15,  */
  fixed_block_b_11: 
  {
    /* execute.simd:2778 [D] s_b_11_0 = sym_13248_0_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_13248_0_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 8 s_b_11_0 => sym_13360_0_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_13360_0_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(8));
    }
    /* execute.simd:2780 [F] s_b_11_2=sym_13242_3_parameter_inst.Q (const) */
    /* execute.simd:2780 [F] s_b_11_3 = (u32)s_b_11_2 (const) */
    /* execute.simd:2780 [F] s_b_11_4 = constant u32 0 (const) */
    /* execute.simd:2780 [F] s_b_11_5 = s_b_11_3==s_b_11_4 (const) */
    uint8_t s_b_11_5 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* execute.simd:2780 [F] s_b_11_6: If s_b_11_5: Jump b_12 else b_13 (const) */
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
    /* execute.simd:2781 [F] s_b_12_0=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2781 [D] s_b_12_1 = sym_13360_0_value uint64_t */
    auto s_b_12_1 = emitter.load_local(DV_sym_13360_0_value, emitter.context().types().u64());
    /* execute.simd:2781 [D] s_b_12_2: WriteRegBank 2:s_b_12_0 = s_b_12_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_1);
    /* execute.simd:2782 [F] s_b_12_3=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2782 [F] s_b_12_4 = constant u64 0 (const) */
    /* execute.simd:2782 [F] s_b_12_5: WriteRegBank 3:s_b_12_3 = s_b_12_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rt))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:2781 [F] s_b_12_6: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_11,  */
  fixed_block_b_13: 
  {
    /* execute.simd:2784 [D] s_b_13_0 = sym_13360_0_value uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_13360_0_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = (v2u64)s_b_13_0 */
    auto s_b_13_1 = emitter.splat(s_b_13_0, emitter.context().types().v2u64());
    /* execute.simd:2785 [F] s_b_13_2=sym_13242_3_parameter_inst.rt (const) */
    /* execute.simd:2785 [D] s_b_13_3: WriteRegBank 21:s_b_13_2 = s_b_13_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_1,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_1);
    /* execute.simd:2784 [F] s_b_13_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2796 [F] s_b_14_0=sym_13242_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_14_2: sym_66934_1__R_s_b_0_5 = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_66934_1__R_s_b_0_5, s_b_14_1);
    /* execute.a64:2796 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14, b_20,  */
  fixed_block_b_15: 
  {
    /* execute.simd:2731 [D] s_b_15_0 = sym_66934_1__R_s_b_0_5 uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_66934_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.simd:2731 [D] s_b_15_1: sym_13248_0_addr = s_b_15_0, dominates: s_b_11_0 s_b_8_0 s_b_5_0 s_b_2_0  */
    emitter.store_local(DV_sym_13248_0_addr, s_b_15_0);
    /* execute.simd:2733 [F] s_b_15_2=sym_13242_3_parameter_inst.size (const) */
    /* execute.simd:2734 [F] s_b_15_3 = constant s32 0 (const) */
    /* execute.simd:2748 [F] s_b_15_4 = constant s32 1 (const) */
    /* execute.simd:2762 [F] s_b_15_5 = constant s32 2 (const) */
    /* execute.simd:2776 [F] s_b_15_6 = constant s32 3 (const) */
    /* execute.simd:2733 [F] s_b_15_7: Switch s_b_15_2: < <todo> > def b_1 (const) -> b_11, b_8, b_5, b_2, b_1,  */
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
    /* execute.a64:2764 [F] s_b_16_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_16_1 = __builtin_get_feature */
    uint32_t s_b_16_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_16_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_16_3 = s_b_16_1==s_b_16_2 (const) */
    uint8_t s_b_16_3 = ((uint8_t)(s_b_16_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_16_4: If s_b_16_3: Jump b_17 else b_21 (const) */
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
    /* execute.a64:2765 [D] s_b_17_0 = ReadReg 21 (u64) */
    auto s_b_17_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_17_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_17_1: sym_66972_1__R_s_b_21_0 = s_b_17_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_66972_1__R_s_b_21_0, s_b_17_0);
    /* execute.a64:2765 [F] s_b_17_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_21,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2768 [D] s_b_18_0 = ReadReg 21 (u64) */
    auto s_b_18_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_18_1: sym_66972_1__R_s_b_21_0 = s_b_18_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_66972_1__R_s_b_21_0, s_b_18_0);
    /* execute.a64:2768 [F] s_b_18_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_21,  */
  fixed_block_b_19: 
  {
    /* execute.a64:2770 [D] s_b_19_0 = ReadReg 22 (u64) */
    auto s_b_19_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_19_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_19_1: sym_66972_1__R_s_b_21_0 = s_b_19_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_66972_1__R_s_b_21_0, s_b_19_0);
    /* execute.a64:2770 [F] s_b_19_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_17, b_18, b_19,  */
  fixed_block_b_20: 
  {
    /* execute.a64:2794 [D] s_b_20_0 = sym_66972_1__R_s_b_21_0 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_66972_1__R_s_b_21_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_20_1: sym_66934_1__R_s_b_0_5 = s_b_20_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_66934_1__R_s_b_0_5, s_b_20_0);
    /* execute.a64:2794 [F] s_b_20_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_16,  */
  fixed_block_b_21: 
  {
    /* execute.a64:3075 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_21_1 = __builtin_get_feature */
    uint32_t s_b_21_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_21_2 = (u8)s_b_21_1 (const) */
    /* execute.a64:2767 [F] s_b_21_3 = (u32)s_b_21_2 (const) */
    /* execute.a64:2767 [F] s_b_21_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_21_5 = s_b_21_3==s_b_21_4 (const) */
    uint8_t s_b_21_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_21_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_21_6: If s_b_21_5: Jump b_18 else b_19 (const) */
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
  auto DV_sym_70619_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_70747_0_data64 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_71885_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_71863_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_70399_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_70428_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_70819_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_70531_0_data32 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_14073_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_14067_3_parameter_inst.rn (const) */
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
    /* execute.a64:918 [D] s_b_1_0 = sym_14073_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14073_0_address, emitter.context().types().u64());
    /* execute.a64:918 [D] s_b_1_1: sym_70428_3_parameter_address = s_b_1_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_70428_3_parameter_address, s_b_1_0);
    /* ???:4294967295 [D] s_b_1_2 = Load 4 s_b_1_0 => sym_70531_0_data32 */
    auto s_b_1_2 = emitter.load_memory(s_b_1_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_70531_0_data32, s_b_1_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_2, emitter.const_u8(4));
    }
    /* execute.a64:1756 [D] s_b_1_3 = sym_70531_0_data32 uint32_t */
    auto s_b_1_3 = emitter.load_local(DV_sym_70531_0_data32, emitter.context().types().u32());
    /* execute.a64:1756 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_5=sym_14067_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_6 = (u32)s_b_1_4 */
    auto s_b_1_6 = emitter.truncate(s_b_1_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_7 = (u64)s_b_1_6 */
    auto s_b_1_7 = emitter.zx(s_b_1_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_8: sym_71863_3_parameter_value = s_b_1_7, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_71863_3_parameter_value, s_b_1_7);
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
    /* execute.a64:920 [D] s_b_3_0 = sym_14073_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14073_0_address, emitter.context().types().u64());
    /* execute.a64:920 [D] s_b_3_1: sym_70619_3_parameter_address = s_b_3_0, dominates: s_b_7_1  */
    emitter.store_local(DV_sym_70619_3_parameter_address, s_b_3_0);
    /* ???:4294967295 [D] s_b_3_2 = Load 8 s_b_3_0 => sym_70747_0_data64 */
    auto s_b_3_2 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_70747_0_data64, s_b_3_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(8));
    }
    /* execute.a64:1764 [D] s_b_3_3 = sym_70747_0_data64 uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_70747_0_data64, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_3_4=sym_14067_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_3_5: sym_71885_3_parameter_value = s_b_3_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_71885_3_parameter_value, s_b_3_3);
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
    /* execute.a64:2796 [F] s_b_4_0=sym_14067_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_4_2: sym_70399_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_70399_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2796 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:915 [D] s_b_5_0 = sym_70399_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_70399_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:915 [D] s_b_5_1: sym_14073_0_address = s_b_5_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_14073_0_address, s_b_5_0);
    /* execute.a64:917 [F] s_b_5_2=sym_14067_3_parameter_inst.size (const) */
    /* execute.a64:917 [F] s_b_5_3 = (u32)s_b_5_2 (const) */
    /* execute.a64:917 [F] s_b_5_4 = constant u32 2 (const) */
    /* execute.a64:917 [F] s_b_5_5 = s_b_5_3==s_b_5_4 (const) */
    uint8_t s_b_5_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:917 [F] s_b_5_6: If s_b_5_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1786 [D] s_b_6_1 = sym_70428_3_parameter_address uint64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_70428_3_parameter_address, emitter.context().types().u64());
    /* execute.a64:1786 [D] s_b_6_2 = mem_monitor_acquire */
    emitter.call(__captive_mem_monitor_acquire, emitter.const_u32((uint32_t)0ULL), s_b_6_1);
    /* execute.a64:0 [F] s_b_6_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3, b_15,  */
  fixed_block_b_7: 
  {
    /* execute.a64:1786 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_7_1 = sym_70619_3_parameter_address uint64_t */
    auto s_b_7_1 = emitter.load_local(DV_sym_70619_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2765 [D] s_b_9_1: sym_70819_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_70819_1__R_s_b_7_0, s_b_9_0);
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
    /* execute.a64:2768 [D] s_b_10_1: sym_70819_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_70819_1__R_s_b_7_0, s_b_10_0);
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
    /* execute.a64:2770 [D] s_b_11_1: sym_70819_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_70819_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2794 [D] s_b_12_0 = sym_70819_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_70819_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_12_1: sym_70399_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_70399_1__R_s_b_0_5, s_b_12_0);
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
    /* execute.a64:2747 [F] s_b_14_0=sym_14067_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_14_1 = sym_71863_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_71863_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_15_0=sym_14067_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_15_1 = sym_71885_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_71885_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldp(const arm64_decode_a64_LS_REG_PAIR_OFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_14388_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14405_0_data1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14411_0_data2 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14425_0_data1 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_14431_0_data2 = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_89009_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89249_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89319_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89385_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89157_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_89099_1__R_s_b_7_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_14382_3_parameter_inst.rn (const) */
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
    /* execute.a64:1587 [D] s_b_1_0 = sym_14388_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_14388_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_1 = Load 8 s_b_1_0 => sym_14405_0_data1 */
    auto s_b_1_1 = emitter.load_memory(s_b_1_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_14405_0_data1, s_b_1_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_0, s_b_1_1, emitter.const_u8(8));
    }
    /* execute.a64:1588 [F] s_b_1_2 = constant u64 8 (const) */
    /* execute.a64:1588 [D] s_b_1_3 = s_b_1_0+s_b_1_2 */
    auto s_b_1_3 = emitter.add(s_b_1_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_1_4 = Load 8 s_b_1_3 => sym_14411_0_data2 */
    auto s_b_1_4 = emitter.load_memory(s_b_1_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_14411_0_data2, s_b_1_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_1_3, s_b_1_4, emitter.const_u8(8));
    }
    /* execute.a64:1590 [D] s_b_1_5 = sym_14405_0_data1 uint64_t */
    auto s_b_1_5 = emitter.load_local(DV_sym_14405_0_data1, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_1_6=sym_14382_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_1_7: sym_89157_3_parameter_value = s_b_1_5, dominates: s_b_13_1  */
    emitter.store_local(DV_sym_89157_3_parameter_value, s_b_1_5);
    /* execute.a64:2745 [F] s_b_1_8 = (u32)s_b_1_6 (const) */
    /* execute.a64:2745 [F] s_b_1_9 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_1_10 = s_b_1_8==s_b_1_9 (const) */
    uint8_t s_b_1_10 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_1_11: If s_b_1_10: Jump b_6 else b_13 (const) */
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
    /* execute.a64:1596 [D] s_b_3_0 = sym_14388_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14388_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_1 = Load 4 s_b_3_0 => sym_14425_0_data1 */
    auto s_b_3_1 = emitter.load_memory(s_b_3_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_14425_0_data1, s_b_3_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_1, emitter.const_u8(4));
    }
    /* execute.a64:1597 [F] s_b_3_2 = constant u64 4 (const) */
    /* execute.a64:1597 [D] s_b_3_3 = s_b_3_0+s_b_3_2 */
    auto s_b_3_3 = emitter.add(s_b_3_0, emitter.const_u64((uint64_t)4ULL));
    /* ???:4294967295 [D] s_b_3_4 = Load 4 s_b_3_3 => sym_14431_0_data2 */
    auto s_b_3_4 = emitter.load_memory(s_b_3_3, emitter.context().types().u32());
    emitter.store_local(DV_sym_14431_0_data2, s_b_3_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_3, s_b_3_4, emitter.const_u8(4));
    }
    /* execute.a64:1599 [D] s_b_3_5 = sym_14425_0_data1 uint32_t */
    auto s_b_3_5 = emitter.load_local(DV_sym_14425_0_data1, emitter.context().types().u32());
    /* execute.a64:1599 [D] s_b_3_6 = (u64)s_b_3_5 */
    auto s_b_3_6 = emitter.zx(s_b_3_5, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_3_7=sym_14382_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_3_8 = (u32)s_b_3_6 */
    auto s_b_3_8 = emitter.truncate(s_b_3_6, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_3_9 = (u64)s_b_3_8 */
    auto s_b_3_9 = emitter.zx(s_b_3_8, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_3_10: sym_89249_3_parameter_value = s_b_3_9, dominates: s_b_14_1  */
    emitter.store_local(DV_sym_89249_3_parameter_value, s_b_3_9);
    /* execute.a64:2745 [F] s_b_3_11 = (u32)s_b_3_7 (const) */
    /* execute.a64:2745 [F] s_b_3_12 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_3_13 = s_b_3_11==s_b_3_12 (const) */
    uint8_t s_b_3_13 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_3_14: If s_b_3_13: Jump b_7 else b_14 (const) */
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
    /* execute.a64:2796 [F] s_b_4_0=sym_14382_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_4_1 = ReadRegBank 0:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_4_2: sym_89009_1__R_s_b_0_5 = s_b_4_1, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_89009_1__R_s_b_0_5, s_b_4_1);
    /* execute.a64:2796 [F] s_b_4_3: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_4, b_12,  */
  fixed_block_b_5: 
  {
    /* execute.a64:1580 [D] s_b_5_0 = sym_89009_1__R_s_b_0_5 uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_89009_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1580 [D] s_b_5_1: sym_14388_0_address = s_b_5_0, dominates:  */
    emitter.store_local(DV_sym_14388_0_address, s_b_5_0);
    /* execute.a64:1581 [F] s_b_5_2=sym_14382_3_parameter_inst.imms64 (const) */
    /* ???:4294967295 [F] s_b_5_3 = (u64)s_b_5_2 (const) */
    /* ???:4294967295 [D] s_b_5_4 = s_b_5_0+s_b_5_3 */
    auto s_b_5_4 = emitter.add(s_b_5_0, emitter.const_u64(((uint64_t)insn.imms64)));
    /* execute.a64:1581 [D] s_b_5_5: sym_14388_0_address = s_b_5_4, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_14388_0_address, s_b_5_4);
    /* execute.a64:1583 [F] s_b_5_6=sym_14382_3_parameter_inst.opc (const) */
    /* execute.a64:1583 [F] s_b_5_7 = (u32)s_b_5_6 (const) */
    /* execute.a64:1583 [F] s_b_5_8 = constant u32 2 (const) */
    /* execute.a64:1583 [F] s_b_5_9 = s_b_5_7==s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1583 [F] s_b_5_10: If s_b_5_9: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1591 [D] s_b_6_0 = sym_14411_0_data2 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_14411_0_data2, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_6_1=sym_14382_3_parameter_inst.rt2 (const) */
    /* execute.a64:2754 [D] s_b_6_2: sym_89319_3_parameter_value = s_b_6_0, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_89319_3_parameter_value, s_b_6_0);
    /* execute.a64:2745 [F] s_b_6_3 = (u32)s_b_6_1 (const) */
    /* execute.a64:2745 [F] s_b_6_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_6_6: If s_b_6_5: Jump b_2 else b_16 (const) */
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
    /* execute.a64:1600 [D] s_b_7_0 = sym_14431_0_data2 uint32_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_14431_0_data2, emitter.context().types().u32());
    /* execute.a64:1600 [D] s_b_7_1 = (u64)s_b_7_0 */
    auto s_b_7_1 = emitter.zx(s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_7_2=sym_14382_3_parameter_inst.rt2 (const) */
    /* execute.a64:2756 [D] s_b_7_3 = (u32)s_b_7_1 */
    auto s_b_7_3 = emitter.truncate(s_b_7_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_7_4 = (u64)s_b_7_3 */
    auto s_b_7_4 = emitter.zx(s_b_7_3, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_7_5: sym_89385_3_parameter_value = s_b_7_4, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_89385_3_parameter_value, s_b_7_4);
    /* execute.a64:2745 [F] s_b_7_6 = (u32)s_b_7_2 (const) */
    /* execute.a64:2745 [F] s_b_7_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_7_8 = s_b_7_6==s_b_7_7 (const) */
    uint8_t s_b_7_8 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_7_9: If s_b_7_8: Jump b_2 else b_17 (const) */
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
    /* execute.a64:2765 [D] s_b_9_1: sym_89099_1__R_s_b_7_0 = s_b_9_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_89099_1__R_s_b_7_0, s_b_9_0);
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
    /* execute.a64:2768 [D] s_b_10_1: sym_89099_1__R_s_b_7_0 = s_b_10_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_89099_1__R_s_b_7_0, s_b_10_0);
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
    /* execute.a64:2770 [D] s_b_11_1: sym_89099_1__R_s_b_7_0 = s_b_11_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_89099_1__R_s_b_7_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_9, b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2794 [D] s_b_12_0 = sym_89099_1__R_s_b_7_0 uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_89099_1__R_s_b_7_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_12_1: sym_89009_1__R_s_b_0_5 = s_b_12_0, dominates: s_b_5_0  */
    emitter.store_local(DV_sym_89009_1__R_s_b_0_5, s_b_12_0);
    /* execute.a64:2794 [F] s_b_12_2: Jump b_5 (const) */
    goto fixed_block_b_5;
  }
  /* b_1,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2747 [F] s_b_13_0=sym_14382_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_13_1 = sym_89157_3_parameter_value uint64_t */
    auto s_b_13_1 = emitter.load_local(DV_sym_89157_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_13_2: WriteRegBank 0:s_b_13_0 = s_b_13_1 */
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
    /* execute.a64:2747 [F] s_b_14_0=sym_14382_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_14_1 = sym_89249_3_parameter_value uint64_t */
    auto s_b_14_1 = emitter.load_local(DV_sym_89249_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_14_2: WriteRegBank 0:s_b_14_0 = s_b_14_1 */
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
  /* b_6,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2747 [F] s_b_16_0=sym_14382_3_parameter_inst.rt2 (const) */
    /* execute.a64:2747 [D] s_b_16_1 = sym_89319_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_89319_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_16_2: WriteRegBank 0:s_b_16_0 = s_b_16_1 */
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
    /* execute.a64:2747 [F] s_b_17_0=sym_14382_3_parameter_inst.rt2 (const) */
    /* execute.a64:2747 [D] s_b_17_1 = sym_89385_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_89385_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_17_2: WriteRegBank 0:s_b_17_0 = s_b_17_1 */
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
  auto DV_sym_97417_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_14970_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_97411_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_97265_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_97338_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4004 [D] s_b_0_0 = read_pc */
    auto s_b_0_0 = emitter.load_pc();
    /* execute.simd:4004 [F] s_b_0_1=sym_14964_3_parameter_inst.label (const) */
    /* execute.simd:4004 [F] s_b_0_2 = (u64)s_b_0_1 (const) */
    /* execute.simd:4004 [D] s_b_0_3 = s_b_0_0+s_b_0_2 */
    auto s_b_0_3 = emitter.add(s_b_0_0, emitter.const_u64(((uint64_t)insn.label)));
    /* execute.simd:4004 [D] s_b_0_4: sym_14970_0_address = s_b_0_3, dominates: s_b_2_0 s_b_3_0 s_b_4_0  */
    emitter.store_local(DV_sym_14970_0_address, s_b_0_3);
    /* execute.simd:4006 [F] s_b_0_5=sym_14964_3_parameter_inst.opc (const) */
    /* execute.simd:4007 [F] s_b_0_6 = constant s32 0 (const) */
    /* execute.simd:4011 [F] s_b_0_7 = constant s32 1 (const) */
    /* execute.simd:4015 [F] s_b_0_8 = constant s32 2 (const) */
    /* execute.simd:4006 [F] s_b_0_9: Switch s_b_0_5: < <todo> > def b_5 (const) -> b_2, b_3, b_4, b_5,  */
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
    /* execute.simd:4008 [D] s_b_2_0 = sym_14970_0_address uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_14970_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_2_1 = Load 4 s_b_2_0 => sym_97265_0_value */
    auto s_b_2_1 = emitter.load_memory(s_b_2_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_97265_0_value, s_b_2_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_1, emitter.const_u8(4));
    }
    /* execute.simd:3781 [F] s_b_2_2=sym_14964_3_parameter_inst.rt (const) */
    /* execute.simd:3781 [D] s_b_2_3 = sym_97265_0_value uint32_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_97265_0_value, emitter.context().types().u32());
    /* execute.simd:6319 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.simd:6319 [D] s_b_2_5: WriteRegBank 2:s_b_2_2 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_2_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_2_4);
    /* execute.simd:6320 [F] s_b_2_6 = constant u64 0 (const) */
    /* execute.simd:6320 [F] s_b_2_7: WriteRegBank 3:s_b_2_2 = s_b_2_6 */
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
    /* execute.simd:4012 [D] s_b_3_0 = sym_14970_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_14970_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_3_1 = Load 8 s_b_3_0 => sym_97338_0_value */
    auto s_b_3_1 = emitter.load_memory(s_b_3_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_97338_0_value, s_b_3_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_3_0, s_b_3_1, emitter.const_u8(8));
    }
    /* execute.simd:3788 [F] s_b_3_2=sym_14964_3_parameter_inst.rt (const) */
    /* execute.simd:3788 [D] s_b_3_3 = sym_97338_0_value uint64_t */
    auto s_b_3_3 = emitter.load_local(DV_sym_97338_0_value, emitter.context().types().u64());
    /* execute.simd:6326 [D] s_b_3_4: WriteRegBank 2:s_b_3_2 = s_b_3_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_3);
    /* execute.simd:6327 [F] s_b_3_5 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_3_6: WriteRegBank 3:s_b_3_2 = s_b_3_5 */
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
    /* execute.simd:4016 [D] s_b_4_0 = sym_14970_0_address uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_14970_0_address, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_4_1 = Load 8 s_b_4_0 => sym_97411_0_vl */
    auto s_b_4_1 = emitter.load_memory(s_b_4_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_97411_0_vl, s_b_4_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_4_0, s_b_4_1, emitter.const_u8(8));
    }
    /* execute.simd:3796 [F] s_b_4_2 = constant u64 8 (const) */
    /* execute.simd:3796 [D] s_b_4_3 = s_b_4_0+s_b_4_2 */
    auto s_b_4_3 = emitter.add(s_b_4_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_4_4 = Load 8 s_b_4_3 => sym_97417_0_vh */
    auto s_b_4_4 = emitter.load_memory(s_b_4_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_97417_0_vh, s_b_4_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_4_3, s_b_4_4, emitter.const_u8(8));
    }
    /* execute.simd:3797 [F] s_b_4_5=sym_14964_3_parameter_inst.rt (const) */
    /* execute.simd:3797 [D] s_b_4_6 = sym_97411_0_vl uint64_t */
    auto s_b_4_6 = emitter.load_local(DV_sym_97411_0_vl, emitter.context().types().u64());
    /* execute.simd:3797 [D] s_b_4_7 = sym_97417_0_vh uint64_t */
    auto s_b_4_7 = emitter.load_local(DV_sym_97417_0_vh, emitter.context().types().u64());
    /* execute.simd:6333 [D] s_b_4_8: WriteRegBank 2:s_b_4_5 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_4_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_4_6);
    /* execute.simd:6334 [D] s_b_4_9: WriteRegBank 3:s_b_4_5 = s_b_4_7 */
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
    /* execute.simd:4020 [D] s_b_5_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4006 [F] s_b_5_1: Jump b_1 (const) */
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
  auto DV_sym_16008_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_110102_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_110386_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_110218_1__R_s_b_13_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_110298_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_110320_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_15997_3_parameter_inst.rn (const) */
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
    /* execute.a64:1497 [D] s_b_1_0 = sym_16008_0_value uint16_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_16008_0_value, emitter.context().types().u16());
    /* execute.a64:1497 [D] s_b_1_1 = (u64)s_b_1_0 */
    auto s_b_1_1 = emitter.zx(s_b_1_0, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_1_2=sym_15997_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_1_3 = (u32)s_b_1_1 */
    auto s_b_1_3 = emitter.truncate(s_b_1_1, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_1_4 = (u64)s_b_1_3 */
    auto s_b_1_4 = emitter.zx(s_b_1_3, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_1_5: sym_110298_3_parameter_value = s_b_1_4, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_110298_3_parameter_value, s_b_1_4);
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
    /* execute.a64:1498 [F] s_b_3_0=sym_15997_3_parameter_inst.opc (const) */
    /* execute.a64:1498 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1498 [F] s_b_3_2 = constant u32 2 (const) */
    /* execute.a64:1498 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1498 [F] s_b_3_4: If s_b_3_3: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1499 [D] s_b_4_0 = sym_16008_0_value uint16_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_16008_0_value, emitter.context().types().u16());
    /* execute.a64:1499 [D] s_b_4_1 = (s16)s_b_4_0 */
    auto s_b_4_1 = emitter.reinterpret(s_b_4_0, emitter.context().types().s16());
    /* execute.a64:1499 [D] s_b_4_2 = (s64)s_b_4_1 */
    auto s_b_4_2 = emitter.sx(s_b_4_1, emitter.context().types().s64());
    /* execute.a64:1499 [D] s_b_4_3 = (u64)s_b_4_2 */
    auto s_b_4_3 = emitter.reinterpret(s_b_4_2, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_4_4=sym_15997_3_parameter_inst.rt (const) */
    /* execute.a64:2754 [D] s_b_4_5: sym_110320_3_parameter_value = s_b_4_3, dominates: s_b_16_1  */
    emitter.store_local(DV_sym_110320_3_parameter_value, s_b_4_3);
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
    /* execute.a64:1500 [F] s_b_5_0=sym_15997_3_parameter_inst.opc (const) */
    /* execute.a64:1500 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1500 [F] s_b_5_2 = constant u32 3 (const) */
    /* execute.a64:1500 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)3ULL));
    /* execute.a64:1500 [F] s_b_5_4: If s_b_5_3: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1501 [D] s_b_6_0 = sym_16008_0_value uint16_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_16008_0_value, emitter.context().types().u16());
    /* execute.a64:1501 [D] s_b_6_1 = (s16)s_b_6_0 */
    auto s_b_6_1 = emitter.reinterpret(s_b_6_0, emitter.context().types().s16());
    /* execute.a64:1501 [D] s_b_6_2 = (s64)s_b_6_1 */
    auto s_b_6_2 = emitter.sx(s_b_6_1, emitter.context().types().s64());
    /* execute.a64:1501 [D] s_b_6_3 = (u64)s_b_6_2 */
    auto s_b_6_3 = emitter.reinterpret(s_b_6_2, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_6_4=sym_15997_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_6_5 = (u32)s_b_6_3 */
    auto s_b_6_5 = emitter.truncate(s_b_6_3, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_6_6 = (u64)s_b_6_5 */
    auto s_b_6_6 = emitter.zx(s_b_6_5, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_6_7: sym_110386_3_parameter_value = s_b_6_6, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_110386_3_parameter_value, s_b_6_6);
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
    /* execute.a64:1503 [D] s_b_7_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1503 [F] s_b_7_1: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2796 [F] s_b_8_0=sym_15997_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_8_2: sym_110102_1__R_s_b_0_5 = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_110102_1__R_s_b_0_5, s_b_8_1);
    /* execute.a64:2796 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_8, b_14,  */
  fixed_block_b_9: 
  {
    /* execute.a64:1491 [D] s_b_9_0 = sym_110102_1__R_s_b_0_5 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_110102_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:1491 [F] s_b_9_1=sym_15997_3_parameter_inst.immu64 (const) */
    /* execute.a64:1491 [D] s_b_9_2 = s_b_9_0+s_b_9_1 */
    auto s_b_9_2 = emitter.add(s_b_9_0, emitter.const_u64(insn.immu64));
    /* ???:4294967295 [D] s_b_9_3 = Load 2 s_b_9_2 => sym_16008_0_value */
    auto s_b_9_3 = emitter.load_memory(s_b_9_2, emitter.context().types().u16());
    emitter.store_local(DV_sym_16008_0_value, s_b_9_3);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_2, s_b_9_3, emitter.const_u8(2));
    }
    /* execute.a64:1496 [F] s_b_9_4=sym_15997_3_parameter_inst.opc (const) */
    /* execute.a64:1496 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.a64:1496 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.a64:1496 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.a64:1496 [F] s_b_9_8: If s_b_9_7: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2765 [D] s_b_11_1: sym_110218_1__R_s_b_13_0 = s_b_11_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_110218_1__R_s_b_13_0, s_b_11_0);
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
    /* execute.a64:2768 [D] s_b_12_1: sym_110218_1__R_s_b_13_0 = s_b_12_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_110218_1__R_s_b_13_0, s_b_12_0);
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
    /* execute.a64:2770 [D] s_b_13_1: sym_110218_1__R_s_b_13_0 = s_b_13_0, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_110218_1__R_s_b_13_0, s_b_13_0);
    /* execute.a64:2770 [F] s_b_13_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_11, b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2794 [D] s_b_14_0 = sym_110218_1__R_s_b_13_0 uint64_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_110218_1__R_s_b_13_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_14_1: sym_110102_1__R_s_b_0_5 = s_b_14_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_110102_1__R_s_b_0_5, s_b_14_0);
    /* execute.a64:2794 [F] s_b_14_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2747 [F] s_b_15_0=sym_15997_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_15_1 = sym_110298_3_parameter_value uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_110298_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_16_0=sym_15997_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_16_1 = sym_110320_3_parameter_value uint64_t */
    auto s_b_16_1 = emitter.load_local(DV_sym_110320_3_parameter_value, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_17_0=sym_15997_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_17_1 = sym_110386_3_parameter_value uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_110386_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldtrsw(const arm64_decode_a64_LS_REG_UNPRIV&insn, captive::arch::dbt::el::Emitter& emitter)
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ldxrh(const arm64_decode_a64_LS_EX&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_121675_1__R_s_b_0_5 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_121713_1__R_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_122512_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_121776_3_parameter_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_121831_0_data16 = emitter.alloc_local(emitter.context().types().u16(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2793 [F] s_b_0_0=sym_16570_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_1_0=sym_16570_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_1_1 = ReadRegBank 0:s_b_1_0 (u64) */
    auto s_b_1_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_1_1,emitter.const_u8(8));
    }
    /* execute.a64:2796 [D] s_b_1_2: sym_121675_1__R_s_b_0_5 = s_b_1_1, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_121675_1__R_s_b_0_5, s_b_1_1);
    /* execute.a64:2796 [F] s_b_1_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1, b_7,  */
  fixed_block_b_2: 
  {
    /* execute.a64:744 [D] s_b_2_0 = sym_121675_1__R_s_b_0_5 uint64_t */
    auto s_b_2_0 = emitter.load_local(DV_sym_121675_1__R_s_b_0_5, emitter.context().types().u64());
    /* execute.a64:745 [D] s_b_2_1: sym_121776_3_parameter_address = s_b_2_0, dominates: s_b_8_1  */
    emitter.store_local(DV_sym_121776_3_parameter_address, s_b_2_0);
    /* ???:4294967295 [D] s_b_2_2 = Load 2 s_b_2_0 => sym_121831_0_data16 */
    auto s_b_2_2 = emitter.load_memory(s_b_2_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_121831_0_data16, s_b_2_2);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_2_0, s_b_2_2, emitter.const_u8(2));
    }
    /* execute.a64:1740 [D] s_b_2_3 = sym_121831_0_data16 uint16_t */
    auto s_b_2_3 = emitter.load_local(DV_sym_121831_0_data16, emitter.context().types().u16());
    /* execute.a64:1740 [D] s_b_2_4 = (u64)s_b_2_3 */
    auto s_b_2_4 = emitter.zx(s_b_2_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_2_5=sym_16570_3_parameter_inst.rt (const) */
    /* execute.a64:2756 [D] s_b_2_6 = (u32)s_b_2_4 */
    auto s_b_2_6 = emitter.truncate(s_b_2_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_2_7 = (u64)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_2_8: sym_122512_3_parameter_value = s_b_2_7, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_122512_3_parameter_value, s_b_2_7);
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
    /* execute.a64:2765 [D] s_b_4_1: sym_121713_1__R_s_b_4_0 = s_b_4_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_121713_1__R_s_b_4_0, s_b_4_0);
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
    /* execute.a64:2768 [D] s_b_5_1: sym_121713_1__R_s_b_4_0 = s_b_5_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_121713_1__R_s_b_4_0, s_b_5_0);
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
    /* execute.a64:2770 [D] s_b_6_1: sym_121713_1__R_s_b_4_0 = s_b_6_0, dominates: s_b_7_0  */
    emitter.store_local(DV_sym_121713_1__R_s_b_4_0, s_b_6_0);
    /* execute.a64:2770 [F] s_b_6_2: Jump b_7 (const) */
    goto fixed_block_b_7;
  }
  /* b_4, b_5, b_6,  */
  fixed_block_b_7: 
  {
    /* execute.a64:2794 [D] s_b_7_0 = sym_121713_1__R_s_b_4_0 uint64_t */
    auto s_b_7_0 = emitter.load_local(DV_sym_121713_1__R_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:2794 [D] s_b_7_1: sym_121675_1__R_s_b_0_5 = s_b_7_0, dominates: s_b_2_0  */
    emitter.store_local(DV_sym_121675_1__R_s_b_0_5, s_b_7_0);
    /* execute.a64:2794 [F] s_b_7_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_2, b_10,  */
  fixed_block_b_8: 
  {
    /* execute.a64:1786 [F] s_b_8_0 = constant u32 0 (const) */
    /* execute.a64:1786 [D] s_b_8_1 = sym_121776_3_parameter_address uint64_t */
    auto s_b_8_1 = emitter.load_local(DV_sym_121776_3_parameter_address, emitter.context().types().u64());
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
    /* execute.a64:2747 [F] s_b_10_0=sym_16570_3_parameter_inst.rt (const) */
    /* execute.a64:2747 [D] s_b_10_1 = sym_122512_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_122512_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_movn(const arm64_decode_a64_MOVE_WIDE_IMM&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  uint64_t CV_sym_126219_3_parameter_value;
  uint64_t CV_sym_126189_3_parameter_value;
  uint64_t CV_sym_126241_3_parameter_value;
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:244 [F] s_b_0_0=sym_16920_3_parameter_inst.imm16 (const) */
    /* execute.a64:244 [F] s_b_0_1 = (u64)s_b_0_0 (const) */
    /* execute.a64:244 [F] s_b_0_2=sym_16920_3_parameter_inst.shift_amount (const) */
    /* execute.a64:244 [F] s_b_0_3 = (u64)s_b_0_2 (const) */
    /* execute.a64:244 [F] s_b_0_4 = s_b_0_1<<s_b_0_3 (const) */
    uint64_t s_b_0_4 = ((uint64_t)(((uint64_t)insn.imm16) << ((uint64_t)insn.shift_amount)));
    /* execute.a64:245 [F] s_b_0_5=sym_16920_3_parameter_inst.sf (const) */
    /* execute.a64:245 [F] s_b_0_6 = ~s_b_0_4 (const) */
    uint64_t s_b_0_6 = ~s_b_0_4;
    /* execute.a64:245 [F] s_b_0_7: sym_126189_3_parameter_value = s_b_0_6 (const), dominates: s_b_1_1 s_b_2_1  */
    CV_sym_126189_3_parameter_value = s_b_0_6;
    /* execute.a64:2753 [F] s_b_0_8: If s_b_0_5: Jump b_1 else b_2 (const) */
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
    /* execute.a64:2754 [F] s_b_1_0=sym_16920_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [F] s_b_1_1 = sym_126189_3_parameter_value (const) uint64_t */
    uint64_t s_b_1_1 = CV_sym_126189_3_parameter_value;
    /* execute.a64:2754 [F] s_b_1_2: sym_126219_3_parameter_value = s_b_1_1 (const), dominates: s_b_4_1  */
    CV_sym_126219_3_parameter_value = s_b_1_1;
    /* execute.a64:2745 [F] s_b_1_3 = (u32)s_b_1_0 (const) */
    /* execute.a64:2745 [F] s_b_1_4 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
    uint8_t s_b_1_5 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_1_6: If s_b_1_5: Jump b_3 else b_4 (const) */
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
    /* execute.a64:2756 [F] s_b_2_0=sym_16920_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [F] s_b_2_1 = sym_126189_3_parameter_value (const) uint64_t */
    uint64_t s_b_2_1 = CV_sym_126189_3_parameter_value;
    /* execute.a64:2756 [F] s_b_2_2 = (u32)s_b_2_1 (const) */
    /* execute.a64:2756 [F] s_b_2_3 = (u64)s_b_2_2 (const) */
    /* execute.a64:2756 [F] s_b_2_4: sym_126241_3_parameter_value = s_b_2_3 (const), dominates: s_b_5_1  */
    CV_sym_126241_3_parameter_value = ((uint64_t)((uint32_t)s_b_2_1));
    /* execute.a64:2745 [F] s_b_2_5 = (u32)s_b_2_0 (const) */
    /* execute.a64:2745 [F] s_b_2_6 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_2_7 = s_b_2_5==s_b_2_6 (const) */
    uint8_t s_b_2_7 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_2_8: If s_b_2_7: Jump b_3 else b_5 (const) */
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
    /* execute.a64:2747 [F] s_b_4_0=sym_16920_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [F] s_b_4_1 = sym_126219_3_parameter_value (const) uint64_t */
    uint64_t s_b_4_1 = CV_sym_126219_3_parameter_value;
    /* execute.a64:2747 [F] s_b_4_2: WriteRegBank 0:s_b_4_0 = s_b_4_1 */
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
    /* execute.a64:2747 [F] s_b_5_0=sym_16920_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [F] s_b_5_1 = sym_126241_3_parameter_value (const) uint64_t */
    uint64_t s_b_5_1 = CV_sym_126241_3_parameter_value;
    /* execute.a64:2747 [F] s_b_5_2: WriteRegBank 0:s_b_5_0 = s_b_5_1 */
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
    /* execute.simd:1214 [F] s_b_0_0=sym_19255_3_parameter_inst.arrangement (const) */
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
    /* execute.simd:1216 [F] s_b_2_0=sym_19255_3_parameter_inst.rn (const) */
    /* execute.simd:1216 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:1217 [F] s_b_2_2=sym_19255_3_parameter_inst.rm (const) */
    /* execute.simd:1217 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_3,emitter.const_u8(8));
    }
    /* execute.simd:1218 [D] s_b_2_4 = s_b_2_1*s_b_2_3 */
    auto s_b_2_4 = emitter.mul(s_b_2_1, s_b_2_3);
    /* execute.simd:1220 [F] s_b_2_5=sym_19255_3_parameter_inst.rd (const) */
    /* execute.simd:1220 [D] s_b_2_6: WriteRegBank 15:s_b_2_5 = s_b_2_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_4);
    /* execute.simd:1221 [F] s_b_2_7=sym_19255_3_parameter_inst.rd (const) */
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
    /* execute.simd:1225 [F] s_b_3_0=sym_19255_3_parameter_inst.rn (const) */
    /* execute.simd:1225 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:1226 [F] s_b_3_2=sym_19255_3_parameter_inst.rm (const) */
    /* execute.simd:1226 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* execute.simd:1227 [D] s_b_3_4 = s_b_3_1*s_b_3_3 */
    auto s_b_3_4 = emitter.mul(s_b_3_1, s_b_3_3);
    /* execute.simd:1229 [F] s_b_3_5=sym_19255_3_parameter_inst.rd (const) */
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
    /* execute.simd:1233 [F] s_b_4_0=sym_19255_3_parameter_inst.rn (const) */
    /* execute.simd:1233 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:1234 [F] s_b_4_2=sym_19255_3_parameter_inst.rm (const) */
    /* execute.simd:1234 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* execute.simd:1235 [D] s_b_4_4 = s_b_4_1*s_b_4_3 */
    auto s_b_4_4 = emitter.mul(s_b_4_1, s_b_4_3);
    /* execute.simd:1237 [F] s_b_4_5=sym_19255_3_parameter_inst.rd (const) */
    /* execute.simd:1237 [D] s_b_4_6: WriteRegBank 17:s_b_4_5 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:1238 [F] s_b_4_7=sym_19255_3_parameter_inst.rd (const) */
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
    /* execute.simd:1242 [F] s_b_5_0=sym_19255_3_parameter_inst.rn (const) */
    /* execute.simd:1242 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:1243 [F] s_b_5_2=sym_19255_3_parameter_inst.rm (const) */
    /* execute.simd:1243 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:1244 [D] s_b_5_4 = s_b_5_1*s_b_5_3 */
    auto s_b_5_4 = emitter.mul(s_b_5_1, s_b_5_3);
    /* execute.simd:1246 [F] s_b_5_5=sym_19255_3_parameter_inst.rd (const) */
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
    /* execute.simd:1250 [F] s_b_6_0=sym_19255_3_parameter_inst.rn (const) */
    /* execute.simd:1250 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:1251 [F] s_b_6_2=sym_19255_3_parameter_inst.rm (const) */
    /* execute.simd:1251 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_3,emitter.const_u8(8));
    }
    /* execute.simd:1252 [D] s_b_6_4 = s_b_6_1*s_b_6_3 */
    auto s_b_6_4 = emitter.mul(s_b_6_1, s_b_6_3);
    /* execute.simd:1254 [F] s_b_6_5=sym_19255_3_parameter_inst.rd (const) */
    /* execute.simd:1254 [D] s_b_6_6: WriteRegBank 19:s_b_6_5 = s_b_6_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_4);
    /* execute.simd:1255 [F] s_b_6_7=sym_19255_3_parameter_inst.rd (const) */
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
    /* execute.simd:1259 [F] s_b_7_0=sym_19255_3_parameter_inst.rn (const) */
    /* execute.simd:1259 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:1260 [F] s_b_7_2=sym_19255_3_parameter_inst.rm (const) */
    /* execute.simd:1260 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:1261 [D] s_b_7_4 = s_b_7_1*s_b_7_3 */
    auto s_b_7_4 = emitter.mul(s_b_7_1, s_b_7_3);
    /* execute.simd:1263 [F] s_b_7_5=sym_19255_3_parameter_inst.rd (const) */
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
    /* execute.simd:5300 [F] s_b_0_0=sym_19707_3_parameter_inst.tb (const) */
    /* execute.simd:5301 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5314 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5327 [F] s_b_0_3 = constant s32 6 (const) */
    /* execute.simd:5335 [F] s_b_0_4 = constant s32 7 (const) */
    /* execute.simd:5300 [F] s_b_0_5: Switch s_b_0_0: < <todo> > def b_6 (const) -> b_2, b_3, b_4, b_5, b_6,  */
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
    /* execute.simd:5302 [F] s_b_2_0=sym_19707_3_parameter_inst.rn (const) */
    /* execute.simd:5302 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5303 [F] s_b_2_2=sym_19707_3_parameter_inst.rm (const) */
    /* execute.simd:5303 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
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
    /* execute.simd:5308 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5308 [D] s_b_2_3[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5308 [D] s_b_2_9 = __builtin_polymul8 */
    auto s_b_2_9 = emitter.call(__captive___builtin_polymul8, s_b_2_6, s_b_2_8);
    /* execute.simd:5308 [F] s_b_2_10 = constant s32 0 (const) */
    /* execute.simd:5308 [D] s_b_2_11 = s_b_2_4[s_b_2_10] <= s_b_2_9 */
    auto s_b_2_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_2_9);
    /* ???:4294967295 [F] s_b_2_12 = constant u8 1 (const) */
    /* execute.simd:5308 [D] s_b_2_1[s_b_2_12] */
    auto s_b_2_13 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_2_14 = constant u8 1 (const) */
    /* execute.simd:5308 [D] s_b_2_3[s_b_2_14] */
    auto s_b_2_15 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5308 [D] s_b_2_16 = __builtin_polymul8 */
    auto s_b_2_16 = emitter.call(__captive___builtin_polymul8, s_b_2_13, s_b_2_15);
    /* execute.simd:5308 [F] s_b_2_17 = constant s32 1 (const) */
    /* execute.simd:5308 [D] s_b_2_18 = s_b_2_11[s_b_2_17] <= s_b_2_16 */
    auto s_b_2_18 = emitter.vector_insert(s_b_2_11, emitter.const_s32((int32_t)1ULL), s_b_2_16);
    /* ???:4294967295 [F] s_b_2_19 = constant u8 2 (const) */
    /* execute.simd:5308 [D] s_b_2_1[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_2_21 = constant u8 2 (const) */
    /* execute.simd:5308 [D] s_b_2_3[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5308 [D] s_b_2_23 = __builtin_polymul8 */
    auto s_b_2_23 = emitter.call(__captive___builtin_polymul8, s_b_2_20, s_b_2_22);
    /* execute.simd:5308 [F] s_b_2_24 = constant s32 2 (const) */
    /* execute.simd:5308 [D] s_b_2_25 = s_b_2_18[s_b_2_24] <= s_b_2_23 */
    auto s_b_2_25 = emitter.vector_insert(s_b_2_18, emitter.const_s32((int32_t)2ULL), s_b_2_23);
    /* ???:4294967295 [F] s_b_2_26 = constant u8 3 (const) */
    /* execute.simd:5308 [D] s_b_2_1[s_b_2_26] */
    auto s_b_2_27 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_2_28 = constant u8 3 (const) */
    /* execute.simd:5308 [D] s_b_2_3[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5308 [D] s_b_2_30 = __builtin_polymul8 */
    auto s_b_2_30 = emitter.call(__captive___builtin_polymul8, s_b_2_27, s_b_2_29);
    /* execute.simd:5308 [F] s_b_2_31 = constant s32 3 (const) */
    /* execute.simd:5308 [D] s_b_2_32 = s_b_2_25[s_b_2_31] <= s_b_2_30 */
    auto s_b_2_32 = emitter.vector_insert(s_b_2_25, emitter.const_s32((int32_t)3ULL), s_b_2_30);
    /* ???:4294967295 [F] s_b_2_33 = constant u8 4 (const) */
    /* execute.simd:5308 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [F] s_b_2_35 = constant u8 4 (const) */
    /* execute.simd:5308 [D] s_b_2_3[s_b_2_35] */
    auto s_b_2_36 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5308 [D] s_b_2_37 = __builtin_polymul8 */
    auto s_b_2_37 = emitter.call(__captive___builtin_polymul8, s_b_2_34, s_b_2_36);
    /* execute.simd:5308 [F] s_b_2_38 = constant s32 4 (const) */
    /* execute.simd:5308 [D] s_b_2_39 = s_b_2_32[s_b_2_38] <= s_b_2_37 */
    auto s_b_2_39 = emitter.vector_insert(s_b_2_32, emitter.const_s32((int32_t)4ULL), s_b_2_37);
    /* ???:4294967295 [F] s_b_2_40 = constant u8 5 (const) */
    /* execute.simd:5308 [D] s_b_2_1[s_b_2_40] */
    auto s_b_2_41 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [F] s_b_2_42 = constant u8 5 (const) */
    /* execute.simd:5308 [D] s_b_2_3[s_b_2_42] */
    auto s_b_2_43 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5308 [D] s_b_2_44 = __builtin_polymul8 */
    auto s_b_2_44 = emitter.call(__captive___builtin_polymul8, s_b_2_41, s_b_2_43);
    /* execute.simd:5308 [F] s_b_2_45 = constant s32 5 (const) */
    /* execute.simd:5308 [D] s_b_2_46 = s_b_2_39[s_b_2_45] <= s_b_2_44 */
    auto s_b_2_46 = emitter.vector_insert(s_b_2_39, emitter.const_s32((int32_t)5ULL), s_b_2_44);
    /* ???:4294967295 [F] s_b_2_47 = constant u8 6 (const) */
    /* execute.simd:5308 [D] s_b_2_1[s_b_2_47] */
    auto s_b_2_48 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [F] s_b_2_49 = constant u8 6 (const) */
    /* execute.simd:5308 [D] s_b_2_3[s_b_2_49] */
    auto s_b_2_50 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5308 [D] s_b_2_51 = __builtin_polymul8 */
    auto s_b_2_51 = emitter.call(__captive___builtin_polymul8, s_b_2_48, s_b_2_50);
    /* execute.simd:5308 [F] s_b_2_52 = constant s32 6 (const) */
    /* execute.simd:5308 [D] s_b_2_53 = s_b_2_46[s_b_2_52] <= s_b_2_51 */
    auto s_b_2_53 = emitter.vector_insert(s_b_2_46, emitter.const_s32((int32_t)6ULL), s_b_2_51);
    /* ???:4294967295 [F] s_b_2_54 = constant u8 7 (const) */
    /* execute.simd:5308 [D] s_b_2_1[s_b_2_54] */
    auto s_b_2_55 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [F] s_b_2_56 = constant u8 7 (const) */
    /* execute.simd:5308 [D] s_b_2_3[s_b_2_56] */
    auto s_b_2_57 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5308 [D] s_b_2_58 = __builtin_polymul8 */
    auto s_b_2_58 = emitter.call(__captive___builtin_polymul8, s_b_2_55, s_b_2_57);
    /* execute.simd:5308 [F] s_b_2_59 = constant s32 7 (const) */
    /* execute.simd:5308 [D] s_b_2_60 = s_b_2_53[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_53, emitter.const_s32((int32_t)7ULL), s_b_2_58);
    /* execute.simd:5311 [F] s_b_2_61=sym_19707_3_parameter_inst.rd (const) */
    /* execute.simd:5311 [D] s_b_2_62: WriteRegBank 18:s_b_2_61 = s_b_2_60 */
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
    /* execute.simd:5315 [F] s_b_3_0=sym_19707_3_parameter_inst.rn (const) */
    /* execute.simd:5315 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5316 [F] s_b_3_2=sym_19707_3_parameter_inst.rm (const) */
    /* execute.simd:5316 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5321 [F] s_b_3_5 = constant u32 8 (const) */
    /* execute.simd:5321 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5321 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5321 [D] s_b_3_3[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5321 [D] s_b_3_9 = __builtin_polymul8 */
    auto s_b_3_9 = emitter.call(__captive___builtin_polymul8, s_b_3_6, s_b_3_8);
    /* execute.simd:5321 [F] s_b_3_10 = constant s32 0 (const) */
    /* execute.simd:5321 [D] s_b_3_11 = s_b_3_4[s_b_3_10] <= s_b_3_9 */
    auto s_b_3_11 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_9);
    /* execute.simd:5321 [F] s_b_3_12 = constant u32 9 (const) */
    /* execute.simd:5321 [D] s_b_3_1[s_b_3_12] */
    auto s_b_3_13 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5321 [F] s_b_3_14 = constant u32 9 (const) */
    /* execute.simd:5321 [D] s_b_3_3[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5321 [D] s_b_3_16 = __builtin_polymul8 */
    auto s_b_3_16 = emitter.call(__captive___builtin_polymul8, s_b_3_13, s_b_3_15);
    /* execute.simd:5321 [F] s_b_3_17 = constant s32 1 (const) */
    /* execute.simd:5321 [D] s_b_3_18 = s_b_3_11[s_b_3_17] <= s_b_3_16 */
    auto s_b_3_18 = emitter.vector_insert(s_b_3_11, emitter.const_s32((int32_t)1ULL), s_b_3_16);
    /* execute.simd:5321 [F] s_b_3_19 = constant u32 a (const) */
    /* execute.simd:5321 [D] s_b_3_1[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5321 [F] s_b_3_21 = constant u32 a (const) */
    /* execute.simd:5321 [D] s_b_3_3[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5321 [D] s_b_3_23 = __builtin_polymul8 */
    auto s_b_3_23 = emitter.call(__captive___builtin_polymul8, s_b_3_20, s_b_3_22);
    /* execute.simd:5321 [F] s_b_3_24 = constant s32 2 (const) */
    /* execute.simd:5321 [D] s_b_3_25 = s_b_3_18[s_b_3_24] <= s_b_3_23 */
    auto s_b_3_25 = emitter.vector_insert(s_b_3_18, emitter.const_s32((int32_t)2ULL), s_b_3_23);
    /* execute.simd:5321 [F] s_b_3_26 = constant u32 b (const) */
    /* execute.simd:5321 [D] s_b_3_1[s_b_3_26] */
    auto s_b_3_27 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5321 [F] s_b_3_28 = constant u32 b (const) */
    /* execute.simd:5321 [D] s_b_3_3[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5321 [D] s_b_3_30 = __builtin_polymul8 */
    auto s_b_3_30 = emitter.call(__captive___builtin_polymul8, s_b_3_27, s_b_3_29);
    /* execute.simd:5321 [F] s_b_3_31 = constant s32 3 (const) */
    /* execute.simd:5321 [D] s_b_3_32 = s_b_3_25[s_b_3_31] <= s_b_3_30 */
    auto s_b_3_32 = emitter.vector_insert(s_b_3_25, emitter.const_s32((int32_t)3ULL), s_b_3_30);
    /* execute.simd:5321 [F] s_b_3_33 = constant u32 c (const) */
    /* execute.simd:5321 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5321 [F] s_b_3_35 = constant u32 c (const) */
    /* execute.simd:5321 [D] s_b_3_3[s_b_3_35] */
    auto s_b_3_36 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5321 [D] s_b_3_37 = __builtin_polymul8 */
    auto s_b_3_37 = emitter.call(__captive___builtin_polymul8, s_b_3_34, s_b_3_36);
    /* execute.simd:5321 [F] s_b_3_38 = constant s32 4 (const) */
    /* execute.simd:5321 [D] s_b_3_39 = s_b_3_32[s_b_3_38] <= s_b_3_37 */
    auto s_b_3_39 = emitter.vector_insert(s_b_3_32, emitter.const_s32((int32_t)4ULL), s_b_3_37);
    /* execute.simd:5321 [F] s_b_3_40 = constant u32 d (const) */
    /* execute.simd:5321 [D] s_b_3_1[s_b_3_40] */
    auto s_b_3_41 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5321 [F] s_b_3_42 = constant u32 d (const) */
    /* execute.simd:5321 [D] s_b_3_3[s_b_3_42] */
    auto s_b_3_43 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5321 [D] s_b_3_44 = __builtin_polymul8 */
    auto s_b_3_44 = emitter.call(__captive___builtin_polymul8, s_b_3_41, s_b_3_43);
    /* execute.simd:5321 [F] s_b_3_45 = constant s32 5 (const) */
    /* execute.simd:5321 [D] s_b_3_46 = s_b_3_39[s_b_3_45] <= s_b_3_44 */
    auto s_b_3_46 = emitter.vector_insert(s_b_3_39, emitter.const_s32((int32_t)5ULL), s_b_3_44);
    /* execute.simd:5321 [F] s_b_3_47 = constant u32 e (const) */
    /* execute.simd:5321 [D] s_b_3_1[s_b_3_47] */
    auto s_b_3_48 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5321 [F] s_b_3_49 = constant u32 e (const) */
    /* execute.simd:5321 [D] s_b_3_3[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5321 [D] s_b_3_51 = __builtin_polymul8 */
    auto s_b_3_51 = emitter.call(__captive___builtin_polymul8, s_b_3_48, s_b_3_50);
    /* execute.simd:5321 [F] s_b_3_52 = constant s32 6 (const) */
    /* execute.simd:5321 [D] s_b_3_53 = s_b_3_46[s_b_3_52] <= s_b_3_51 */
    auto s_b_3_53 = emitter.vector_insert(s_b_3_46, emitter.const_s32((int32_t)6ULL), s_b_3_51);
    /* execute.simd:5321 [F] s_b_3_54 = constant u32 f (const) */
    /* execute.simd:5321 [D] s_b_3_1[s_b_3_54] */
    auto s_b_3_55 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5321 [F] s_b_3_56 = constant u32 f (const) */
    /* execute.simd:5321 [D] s_b_3_3[s_b_3_56] */
    auto s_b_3_57 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5321 [D] s_b_3_58 = __builtin_polymul8 */
    auto s_b_3_58 = emitter.call(__captive___builtin_polymul8, s_b_3_55, s_b_3_57);
    /* execute.simd:5321 [F] s_b_3_59 = constant s32 7 (const) */
    /* execute.simd:5321 [D] s_b_3_60 = s_b_3_53[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_53, emitter.const_s32((int32_t)7ULL), s_b_3_58);
    /* execute.simd:5324 [F] s_b_3_61=sym_19707_3_parameter_inst.rd (const) */
    /* execute.simd:5324 [D] s_b_3_62: WriteRegBank 18:s_b_3_61 = s_b_3_60 */
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
    /* execute.simd:5328 [F] s_b_4_0=sym_19707_3_parameter_inst.rn (const) */
    /* execute.simd:5328 [D] s_b_4_1 = ReadRegBank 7:s_b_4_0 (u64) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5329 [F] s_b_4_2=sym_19707_3_parameter_inst.rm (const) */
    /* execute.simd:5329 [D] s_b_4_3 = ReadRegBank 7:s_b_4_2 (u64) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_3,emitter.const_u8(8));
    }
    /* execute.simd:5331 [D] s_b_4_4 = __builtin_polymul64 */
    auto s_b_4_4 = emitter.call(__captive___builtin_polymul64, s_b_4_1, s_b_4_3);
    /* execute.simd:5332 [F] s_b_4_5=sym_19707_3_parameter_inst.rd (const) */
    /* execute.simd:5332 [D] s_b_4_6: WriteRegBank 22:s_b_4_5 = s_b_4_4 */
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
    /* execute.simd:5336 [F] s_b_5_0=sym_19707_3_parameter_inst.rn (const) */
    /* execute.simd:5336 [D] s_b_5_1 = ReadRegBank 21:s_b_5_0 (v2u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5337 [F] s_b_5_2=sym_19707_3_parameter_inst.rm (const) */
    /* execute.simd:5337 [D] s_b_5_3 = ReadRegBank 21:s_b_5_2 (v2u64) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* execute.simd:5339 [F] s_b_5_4 = constant s32 1 (const) */
    /* execute.simd:5339 [D] s_b_5_1[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5339 [F] s_b_5_6 = constant s32 1 (const) */
    /* execute.simd:5339 [D] s_b_5_3[s_b_5_6] */
    auto s_b_5_7 = emitter.vector_extract(s_b_5_3, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:5339 [D] s_b_5_8 = __builtin_polymul64 */
    auto s_b_5_8 = emitter.call(__captive___builtin_polymul64, s_b_5_5, s_b_5_7);
    /* execute.simd:5340 [F] s_b_5_9=sym_19707_3_parameter_inst.rd (const) */
    /* execute.simd:5340 [D] s_b_5_10: WriteRegBank 22:s_b_5_9 = s_b_5_8 */
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
    /* execute.simd:5344 [D] s_b_6_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5300 [F] s_b_6_1: Jump b_1 (const) */
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
  auto DV_sym_129508_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_129409_1_temporary_value;
  auto DV_sym_129409_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_129324_1_temporary_value;
  auto DV_sym_129324_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_129574_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2231 [F] s_b_0_0=sym_20206_3_parameter_inst.sf (const) */
    /* execute.a64:2231 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2232 [F] s_b_1_0=sym_20206_3_parameter_inst.rn (const) */
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
  /* b_6, b_9, b_10, b_11,  */
  fixed_block_b_2: 
  {
    /* ???:4294967295 [F] s_b_2_0: Return */
    goto fixed_done;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2234 [F] s_b_3_0=sym_20206_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:2709 [F] s_b_3_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_3_4: If s_b_3_3: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2714 [F] s_b_4_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_4_1: sym_129324_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_129324_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_129324_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_1,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2714 [F] s_b_5_0=sym_20206_3_parameter_inst.rn (const) */
    /* execute.a64:2714 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_5_2: sym_129324_1_temporary_value = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_129324_1_temporary_value, s_b_5_1);
    /* execute.a64:2714 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2714 [D] s_b_6_0 = sym_129324_1_temporary_value uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_129324_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2232 [D] s_b_6_1 = __builtin_bswap64 */
    auto s_b_6_1 = emitter.bswap(s_b_6_0);
    /* execute.a64:2754 [F] s_b_6_2=sym_20206_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_6_3: sym_129508_3_parameter_value = s_b_6_1, dominates: s_b_10_1  */
    emitter.store_local(DV_sym_129508_3_parameter_value, s_b_6_1);
    /* execute.a64:2745 [F] s_b_6_4 = (u32)s_b_6_2 (const) */
    /* execute.a64:2745 [F] s_b_6_5 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_6_6 = s_b_6_4==s_b_6_5 (const) */
    uint8_t s_b_6_6 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_6_7: If s_b_6_6: Jump b_2 else b_10 (const) */
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
    /* execute.a64:2709 [F] s_b_7_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_7_1: sym_129409_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_129409_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_129409_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_3,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2709 [F] s_b_8_0=sym_20206_3_parameter_inst.rn (const) */
    /* execute.a64:2709 [D] s_b_8_1 = ReadRegBank 1:s_b_8_0 (u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_8_2: sym_129409_1_temporary_value = s_b_8_1, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_129409_1_temporary_value, s_b_8_1);
    /* execute.a64:2709 [F] s_b_8_3: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2709 [D] s_b_9_0 = sym_129409_1_temporary_value uint32_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_129409_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_9_1 = (u64)s_b_9_0 */
    auto s_b_9_1 = emitter.zx(s_b_9_0, emitter.context().types().u64());
    /* execute.a64:2234 [D] s_b_9_2 = (u32)s_b_9_1 */
    auto s_b_9_2 = emitter.truncate(s_b_9_1, emitter.context().types().u32());
    /* execute.a64:2234 [D] s_b_9_3 = __builtin_bswap32 */
    auto s_b_9_3 = emitter.bswap(s_b_9_2);
    /* execute.a64:2234 [D] s_b_9_4 = (u64)s_b_9_3 */
    auto s_b_9_4 = emitter.zx(s_b_9_3, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_9_5=sym_20206_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_9_6 = (u32)s_b_9_4 */
    auto s_b_9_6 = emitter.truncate(s_b_9_4, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_9_7 = (u64)s_b_9_6 */
    auto s_b_9_7 = emitter.zx(s_b_9_6, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_9_8: sym_129574_3_parameter_value = s_b_9_7, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_129574_3_parameter_value, s_b_9_7);
    /* execute.a64:2745 [F] s_b_9_9 = (u32)s_b_9_5 (const) */
    /* execute.a64:2745 [F] s_b_9_10 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_9_11 = s_b_9_9==s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_9_12: If s_b_9_11: Jump b_2 else b_11 (const) */
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
    /* execute.a64:2747 [F] s_b_10_0=sym_20206_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_10_1 = sym_129508_3_parameter_value uint64_t */
    auto s_b_10_1 = emitter.load_local(DV_sym_129508_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_10_2: WriteRegBank 0:s_b_10_0 = s_b_10_1 */
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
    /* execute.a64:2747 [F] s_b_11_0=sym_20206_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_11_1 = sym_129574_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_129574_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_11_2: WriteRegBank 0:s_b_11_0 = s_b_11_1 */
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
    /* execute.simd:5687 [F] s_b_0_0=sym_21564_3_parameter_inst.tb (const) */
    /* execute.simd:5688 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5701 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5714 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5727 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5740 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5753 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5687 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5689 [F] s_b_2_0=sym_21564_3_parameter_inst.rn (const) */
    /* execute.simd:5689 [D] s_b_2_1 = ReadRegBank 18:s_b_2_0 (v8u16) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(16));
    }
    /* execute.simd:5689 [D] s_b_2_2 = (v8s16)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s16());
    /* execute.simd:5690 [F] s_b_2_3=sym_21564_3_parameter_inst.rm (const) */
    /* execute.simd:5690 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5690 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5695 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_2_9 = constant u8 0 (const) */
    /* execute.simd:5695 [D] s_b_2_5[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5695 [D] s_b_2_11 = (s16)s_b_2_10 */
    auto s_b_2_11 = emitter.sx(s_b_2_10, emitter.context().types().s16());
    /* execute.simd:5695 [D] s_b_2_12 = s_b_2_8+s_b_2_11 */
    auto s_b_2_12 = emitter.add(s_b_2_8, s_b_2_11);
    /* execute.simd:5695 [F] s_b_2_13 = constant s32 0 (const) */
    /* execute.simd:5695 [D] s_b_2_14 = s_b_2_6[s_b_2_13] <= s_b_2_12 */
    auto s_b_2_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_12);
    /* ???:4294967295 [F] s_b_2_15 = constant u8 1 (const) */
    /* execute.simd:5695 [D] s_b_2_2[s_b_2_15] */
    auto s_b_2_16 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_2_17 = constant u8 1 (const) */
    /* execute.simd:5695 [D] s_b_2_5[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5695 [D] s_b_2_19 = (s16)s_b_2_18 */
    auto s_b_2_19 = emitter.sx(s_b_2_18, emitter.context().types().s16());
    /* execute.simd:5695 [D] s_b_2_20 = s_b_2_16+s_b_2_19 */
    auto s_b_2_20 = emitter.add(s_b_2_16, s_b_2_19);
    /* execute.simd:5695 [F] s_b_2_21 = constant s32 1 (const) */
    /* execute.simd:5695 [D] s_b_2_22 = s_b_2_14[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_14, emitter.const_s32((int32_t)1ULL), s_b_2_20);
    /* ???:4294967295 [F] s_b_2_23 = constant u8 2 (const) */
    /* execute.simd:5695 [D] s_b_2_2[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5695 [D] s_b_2_5[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5695 [D] s_b_2_27 = (s16)s_b_2_26 */
    auto s_b_2_27 = emitter.sx(s_b_2_26, emitter.context().types().s16());
    /* execute.simd:5695 [D] s_b_2_28 = s_b_2_24+s_b_2_27 */
    auto s_b_2_28 = emitter.add(s_b_2_24, s_b_2_27);
    /* execute.simd:5695 [F] s_b_2_29 = constant s32 2 (const) */
    /* execute.simd:5695 [D] s_b_2_30 = s_b_2_22[s_b_2_29] <= s_b_2_28 */
    auto s_b_2_30 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)2ULL), s_b_2_28);
    /* ???:4294967295 [F] s_b_2_31 = constant u8 3 (const) */
    /* execute.simd:5695 [D] s_b_2_2[s_b_2_31] */
    auto s_b_2_32 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_2_33 = constant u8 3 (const) */
    /* execute.simd:5695 [D] s_b_2_5[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5695 [D] s_b_2_35 = (s16)s_b_2_34 */
    auto s_b_2_35 = emitter.sx(s_b_2_34, emitter.context().types().s16());
    /* execute.simd:5695 [D] s_b_2_36 = s_b_2_32+s_b_2_35 */
    auto s_b_2_36 = emitter.add(s_b_2_32, s_b_2_35);
    /* execute.simd:5695 [F] s_b_2_37 = constant s32 3 (const) */
    /* execute.simd:5695 [D] s_b_2_38 = s_b_2_30[s_b_2_37] <= s_b_2_36 */
    auto s_b_2_38 = emitter.vector_insert(s_b_2_30, emitter.const_s32((int32_t)3ULL), s_b_2_36);
    /* ???:4294967295 [F] s_b_2_39 = constant u8 4 (const) */
    /* execute.simd:5695 [D] s_b_2_2[s_b_2_39] */
    auto s_b_2_40 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* ???:4294967295 [F] s_b_2_41 = constant u8 4 (const) */
    /* execute.simd:5695 [D] s_b_2_5[s_b_2_41] */
    auto s_b_2_42 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5695 [D] s_b_2_43 = (s16)s_b_2_42 */
    auto s_b_2_43 = emitter.sx(s_b_2_42, emitter.context().types().s16());
    /* execute.simd:5695 [D] s_b_2_44 = s_b_2_40+s_b_2_43 */
    auto s_b_2_44 = emitter.add(s_b_2_40, s_b_2_43);
    /* execute.simd:5695 [F] s_b_2_45 = constant s32 4 (const) */
    /* execute.simd:5695 [D] s_b_2_46 = s_b_2_38[s_b_2_45] <= s_b_2_44 */
    auto s_b_2_46 = emitter.vector_insert(s_b_2_38, emitter.const_s32((int32_t)4ULL), s_b_2_44);
    /* ???:4294967295 [F] s_b_2_47 = constant u8 5 (const) */
    /* execute.simd:5695 [D] s_b_2_2[s_b_2_47] */
    auto s_b_2_48 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* ???:4294967295 [F] s_b_2_49 = constant u8 5 (const) */
    /* execute.simd:5695 [D] s_b_2_5[s_b_2_49] */
    auto s_b_2_50 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5695 [D] s_b_2_51 = (s16)s_b_2_50 */
    auto s_b_2_51 = emitter.sx(s_b_2_50, emitter.context().types().s16());
    /* execute.simd:5695 [D] s_b_2_52 = s_b_2_48+s_b_2_51 */
    auto s_b_2_52 = emitter.add(s_b_2_48, s_b_2_51);
    /* execute.simd:5695 [F] s_b_2_53 = constant s32 5 (const) */
    /* execute.simd:5695 [D] s_b_2_54 = s_b_2_46[s_b_2_53] <= s_b_2_52 */
    auto s_b_2_54 = emitter.vector_insert(s_b_2_46, emitter.const_s32((int32_t)5ULL), s_b_2_52);
    /* ???:4294967295 [F] s_b_2_55 = constant u8 6 (const) */
    /* execute.simd:5695 [D] s_b_2_2[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* ???:4294967295 [F] s_b_2_57 = constant u8 6 (const) */
    /* execute.simd:5695 [D] s_b_2_5[s_b_2_57] */
    auto s_b_2_58 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5695 [D] s_b_2_59 = (s16)s_b_2_58 */
    auto s_b_2_59 = emitter.sx(s_b_2_58, emitter.context().types().s16());
    /* execute.simd:5695 [D] s_b_2_60 = s_b_2_56+s_b_2_59 */
    auto s_b_2_60 = emitter.add(s_b_2_56, s_b_2_59);
    /* execute.simd:5695 [F] s_b_2_61 = constant s32 6 (const) */
    /* execute.simd:5695 [D] s_b_2_62 = s_b_2_54[s_b_2_61] <= s_b_2_60 */
    auto s_b_2_62 = emitter.vector_insert(s_b_2_54, emitter.const_s32((int32_t)6ULL), s_b_2_60);
    /* ???:4294967295 [F] s_b_2_63 = constant u8 7 (const) */
    /* execute.simd:5695 [D] s_b_2_2[s_b_2_63] */
    auto s_b_2_64 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* ???:4294967295 [F] s_b_2_65 = constant u8 7 (const) */
    /* execute.simd:5695 [D] s_b_2_5[s_b_2_65] */
    auto s_b_2_66 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5695 [D] s_b_2_67 = (s16)s_b_2_66 */
    auto s_b_2_67 = emitter.sx(s_b_2_66, emitter.context().types().s16());
    /* execute.simd:5695 [D] s_b_2_68 = s_b_2_64+s_b_2_67 */
    auto s_b_2_68 = emitter.add(s_b_2_64, s_b_2_67);
    /* execute.simd:5695 [F] s_b_2_69 = constant s32 7 (const) */
    /* execute.simd:5695 [D] s_b_2_70 = s_b_2_62[s_b_2_69] <= s_b_2_68 */
    auto s_b_2_70 = emitter.vector_insert(s_b_2_62, emitter.const_s32((int32_t)7ULL), s_b_2_68);
    /* execute.simd:5698 [F] s_b_2_71=sym_21564_3_parameter_inst.rd (const) */
    /* execute.simd:5698 [D] s_b_2_72 = (v8u16)s_b_2_70 */
    auto s_b_2_72 = emitter.reinterpret(s_b_2_70, emitter.context().types().v8u16());
    /* execute.simd:5698 [D] s_b_2_73: WriteRegBank 18:s_b_2_71 = s_b_2_72 */
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
    /* execute.simd:5702 [F] s_b_3_0=sym_21564_3_parameter_inst.rn (const) */
    /* execute.simd:5702 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5702 [D] s_b_3_2 = (v8s16)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v8s16());
    /* execute.simd:5703 [F] s_b_3_3=sym_21564_3_parameter_inst.rm (const) */
    /* execute.simd:5703 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5703 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_3_7 = constant u8 0 (const) */
    /* execute.simd:5708 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5708 [F] s_b_3_9 = constant u32 8 (const) */
    /* execute.simd:5708 [D] s_b_3_5[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5708 [D] s_b_3_11 = (s16)s_b_3_10 */
    auto s_b_3_11 = emitter.sx(s_b_3_10, emitter.context().types().s16());
    /* execute.simd:5708 [D] s_b_3_12 = s_b_3_8+s_b_3_11 */
    auto s_b_3_12 = emitter.add(s_b_3_8, s_b_3_11);
    /* execute.simd:5708 [F] s_b_3_13 = constant s32 0 (const) */
    /* execute.simd:5708 [D] s_b_3_14 = s_b_3_6[s_b_3_13] <= s_b_3_12 */
    auto s_b_3_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_12);
    /* ???:4294967295 [F] s_b_3_15 = constant u8 1 (const) */
    /* execute.simd:5708 [D] s_b_3_2[s_b_3_15] */
    auto s_b_3_16 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5708 [F] s_b_3_17 = constant u32 9 (const) */
    /* execute.simd:5708 [D] s_b_3_5[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5708 [D] s_b_3_19 = (s16)s_b_3_18 */
    auto s_b_3_19 = emitter.sx(s_b_3_18, emitter.context().types().s16());
    /* execute.simd:5708 [D] s_b_3_20 = s_b_3_16+s_b_3_19 */
    auto s_b_3_20 = emitter.add(s_b_3_16, s_b_3_19);
    /* execute.simd:5708 [F] s_b_3_21 = constant s32 1 (const) */
    /* execute.simd:5708 [D] s_b_3_22 = s_b_3_14[s_b_3_21] <= s_b_3_20 */
    auto s_b_3_22 = emitter.vector_insert(s_b_3_14, emitter.const_s32((int32_t)1ULL), s_b_3_20);
    /* ???:4294967295 [F] s_b_3_23 = constant u8 2 (const) */
    /* execute.simd:5708 [D] s_b_3_2[s_b_3_23] */
    auto s_b_3_24 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5708 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5708 [D] s_b_3_5[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5708 [D] s_b_3_27 = (s16)s_b_3_26 */
    auto s_b_3_27 = emitter.sx(s_b_3_26, emitter.context().types().s16());
    /* execute.simd:5708 [D] s_b_3_28 = s_b_3_24+s_b_3_27 */
    auto s_b_3_28 = emitter.add(s_b_3_24, s_b_3_27);
    /* execute.simd:5708 [F] s_b_3_29 = constant s32 2 (const) */
    /* execute.simd:5708 [D] s_b_3_30 = s_b_3_22[s_b_3_29] <= s_b_3_28 */
    auto s_b_3_30 = emitter.vector_insert(s_b_3_22, emitter.const_s32((int32_t)2ULL), s_b_3_28);
    /* ???:4294967295 [F] s_b_3_31 = constant u8 3 (const) */
    /* execute.simd:5708 [D] s_b_3_2[s_b_3_31] */
    auto s_b_3_32 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5708 [F] s_b_3_33 = constant u32 b (const) */
    /* execute.simd:5708 [D] s_b_3_5[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5708 [D] s_b_3_35 = (s16)s_b_3_34 */
    auto s_b_3_35 = emitter.sx(s_b_3_34, emitter.context().types().s16());
    /* execute.simd:5708 [D] s_b_3_36 = s_b_3_32+s_b_3_35 */
    auto s_b_3_36 = emitter.add(s_b_3_32, s_b_3_35);
    /* execute.simd:5708 [F] s_b_3_37 = constant s32 3 (const) */
    /* execute.simd:5708 [D] s_b_3_38 = s_b_3_30[s_b_3_37] <= s_b_3_36 */
    auto s_b_3_38 = emitter.vector_insert(s_b_3_30, emitter.const_s32((int32_t)3ULL), s_b_3_36);
    /* ???:4294967295 [F] s_b_3_39 = constant u8 4 (const) */
    /* execute.simd:5708 [D] s_b_3_2[s_b_3_39] */
    auto s_b_3_40 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5708 [F] s_b_3_41 = constant u32 c (const) */
    /* execute.simd:5708 [D] s_b_3_5[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5708 [D] s_b_3_43 = (s16)s_b_3_42 */
    auto s_b_3_43 = emitter.sx(s_b_3_42, emitter.context().types().s16());
    /* execute.simd:5708 [D] s_b_3_44 = s_b_3_40+s_b_3_43 */
    auto s_b_3_44 = emitter.add(s_b_3_40, s_b_3_43);
    /* execute.simd:5708 [F] s_b_3_45 = constant s32 4 (const) */
    /* execute.simd:5708 [D] s_b_3_46 = s_b_3_38[s_b_3_45] <= s_b_3_44 */
    auto s_b_3_46 = emitter.vector_insert(s_b_3_38, emitter.const_s32((int32_t)4ULL), s_b_3_44);
    /* ???:4294967295 [F] s_b_3_47 = constant u8 5 (const) */
    /* execute.simd:5708 [D] s_b_3_2[s_b_3_47] */
    auto s_b_3_48 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5708 [F] s_b_3_49 = constant u32 d (const) */
    /* execute.simd:5708 [D] s_b_3_5[s_b_3_49] */
    auto s_b_3_50 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5708 [D] s_b_3_51 = (s16)s_b_3_50 */
    auto s_b_3_51 = emitter.sx(s_b_3_50, emitter.context().types().s16());
    /* execute.simd:5708 [D] s_b_3_52 = s_b_3_48+s_b_3_51 */
    auto s_b_3_52 = emitter.add(s_b_3_48, s_b_3_51);
    /* execute.simd:5708 [F] s_b_3_53 = constant s32 5 (const) */
    /* execute.simd:5708 [D] s_b_3_54 = s_b_3_46[s_b_3_53] <= s_b_3_52 */
    auto s_b_3_54 = emitter.vector_insert(s_b_3_46, emitter.const_s32((int32_t)5ULL), s_b_3_52);
    /* ???:4294967295 [F] s_b_3_55 = constant u8 6 (const) */
    /* execute.simd:5708 [D] s_b_3_2[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5708 [F] s_b_3_57 = constant u32 e (const) */
    /* execute.simd:5708 [D] s_b_3_5[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5708 [D] s_b_3_59 = (s16)s_b_3_58 */
    auto s_b_3_59 = emitter.sx(s_b_3_58, emitter.context().types().s16());
    /* execute.simd:5708 [D] s_b_3_60 = s_b_3_56+s_b_3_59 */
    auto s_b_3_60 = emitter.add(s_b_3_56, s_b_3_59);
    /* execute.simd:5708 [F] s_b_3_61 = constant s32 6 (const) */
    /* execute.simd:5708 [D] s_b_3_62 = s_b_3_54[s_b_3_61] <= s_b_3_60 */
    auto s_b_3_62 = emitter.vector_insert(s_b_3_54, emitter.const_s32((int32_t)6ULL), s_b_3_60);
    /* ???:4294967295 [F] s_b_3_63 = constant u8 7 (const) */
    /* execute.simd:5708 [D] s_b_3_2[s_b_3_63] */
    auto s_b_3_64 = emitter.vector_extract(s_b_3_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5708 [F] s_b_3_65 = constant u32 f (const) */
    /* execute.simd:5708 [D] s_b_3_5[s_b_3_65] */
    auto s_b_3_66 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5708 [D] s_b_3_67 = (s16)s_b_3_66 */
    auto s_b_3_67 = emitter.sx(s_b_3_66, emitter.context().types().s16());
    /* execute.simd:5708 [D] s_b_3_68 = s_b_3_64+s_b_3_67 */
    auto s_b_3_68 = emitter.add(s_b_3_64, s_b_3_67);
    /* execute.simd:5708 [F] s_b_3_69 = constant s32 7 (const) */
    /* execute.simd:5708 [D] s_b_3_70 = s_b_3_62[s_b_3_69] <= s_b_3_68 */
    auto s_b_3_70 = emitter.vector_insert(s_b_3_62, emitter.const_s32((int32_t)7ULL), s_b_3_68);
    /* execute.simd:5711 [F] s_b_3_71=sym_21564_3_parameter_inst.rd (const) */
    /* execute.simd:5711 [D] s_b_3_72 = (v8u16)s_b_3_70 */
    auto s_b_3_72 = emitter.reinterpret(s_b_3_70, emitter.context().types().v8u16());
    /* execute.simd:5711 [D] s_b_3_73: WriteRegBank 18:s_b_3_71 = s_b_3_72 */
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
    /* execute.simd:5715 [F] s_b_4_0=sym_21564_3_parameter_inst.rn (const) */
    /* execute.simd:5715 [D] s_b_4_1 = ReadRegBank 20:s_b_4_0 (v4u32) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(16));
    }
    /* execute.simd:5715 [D] s_b_4_2 = (v4s32)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s32());
    /* execute.simd:5716 [F] s_b_4_3=sym_21564_3_parameter_inst.rm (const) */
    /* execute.simd:5716 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5716 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5721 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_4_9 = constant u8 0 (const) */
    /* execute.simd:5721 [D] s_b_4_5[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5721 [D] s_b_4_11 = (s32)s_b_4_10 */
    auto s_b_4_11 = emitter.sx(s_b_4_10, emitter.context().types().s32());
    /* execute.simd:5721 [D] s_b_4_12 = s_b_4_8+s_b_4_11 */
    auto s_b_4_12 = emitter.add(s_b_4_8, s_b_4_11);
    /* execute.simd:5721 [F] s_b_4_13 = constant s32 0 (const) */
    /* execute.simd:5721 [D] s_b_4_14 = s_b_4_6[s_b_4_13] <= s_b_4_12 */
    auto s_b_4_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_12);
    /* ???:4294967295 [F] s_b_4_15 = constant u8 1 (const) */
    /* execute.simd:5721 [D] s_b_4_2[s_b_4_15] */
    auto s_b_4_16 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_4_17 = constant u8 1 (const) */
    /* execute.simd:5721 [D] s_b_4_5[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5721 [D] s_b_4_19 = (s32)s_b_4_18 */
    auto s_b_4_19 = emitter.sx(s_b_4_18, emitter.context().types().s32());
    /* execute.simd:5721 [D] s_b_4_20 = s_b_4_16+s_b_4_19 */
    auto s_b_4_20 = emitter.add(s_b_4_16, s_b_4_19);
    /* execute.simd:5721 [F] s_b_4_21 = constant s32 1 (const) */
    /* execute.simd:5721 [D] s_b_4_22 = s_b_4_14[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_14, emitter.const_s32((int32_t)1ULL), s_b_4_20);
    /* ???:4294967295 [F] s_b_4_23 = constant u8 2 (const) */
    /* execute.simd:5721 [D] s_b_4_2[s_b_4_23] */
    auto s_b_4_24 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5721 [D] s_b_4_5[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5721 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* execute.simd:5721 [D] s_b_4_28 = s_b_4_24+s_b_4_27 */
    auto s_b_4_28 = emitter.add(s_b_4_24, s_b_4_27);
    /* execute.simd:5721 [F] s_b_4_29 = constant s32 2 (const) */
    /* execute.simd:5721 [D] s_b_4_30 = s_b_4_22[s_b_4_29] <= s_b_4_28 */
    auto s_b_4_30 = emitter.vector_insert(s_b_4_22, emitter.const_s32((int32_t)2ULL), s_b_4_28);
    /* ???:4294967295 [F] s_b_4_31 = constant u8 3 (const) */
    /* execute.simd:5721 [D] s_b_4_2[s_b_4_31] */
    auto s_b_4_32 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* ???:4294967295 [F] s_b_4_33 = constant u8 3 (const) */
    /* execute.simd:5721 [D] s_b_4_5[s_b_4_33] */
    auto s_b_4_34 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5721 [D] s_b_4_35 = (s32)s_b_4_34 */
    auto s_b_4_35 = emitter.sx(s_b_4_34, emitter.context().types().s32());
    /* execute.simd:5721 [D] s_b_4_36 = s_b_4_32+s_b_4_35 */
    auto s_b_4_36 = emitter.add(s_b_4_32, s_b_4_35);
    /* execute.simd:5721 [F] s_b_4_37 = constant s32 3 (const) */
    /* execute.simd:5721 [D] s_b_4_38 = s_b_4_30[s_b_4_37] <= s_b_4_36 */
    auto s_b_4_38 = emitter.vector_insert(s_b_4_30, emitter.const_s32((int32_t)3ULL), s_b_4_36);
    /* execute.simd:5724 [F] s_b_4_39=sym_21564_3_parameter_inst.rd (const) */
    /* execute.simd:5724 [D] s_b_4_40 = (v4u32)s_b_4_38 */
    auto s_b_4_40 = emitter.reinterpret(s_b_4_38, emitter.context().types().v4u32());
    /* execute.simd:5724 [D] s_b_4_41: WriteRegBank 20:s_b_4_39 = s_b_4_40 */
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
    /* execute.simd:5728 [F] s_b_5_0=sym_21564_3_parameter_inst.rn (const) */
    /* execute.simd:5728 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5728 [D] s_b_5_2 = (v4s32)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v4s32());
    /* execute.simd:5729 [F] s_b_5_3=sym_21564_3_parameter_inst.rm (const) */
    /* execute.simd:5729 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5729 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_5_7 = constant u8 0 (const) */
    /* execute.simd:5734 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5734 [F] s_b_5_9 = constant u32 4 (const) */
    /* execute.simd:5734 [D] s_b_5_5[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5734 [D] s_b_5_11 = (s32)s_b_5_10 */
    auto s_b_5_11 = emitter.sx(s_b_5_10, emitter.context().types().s32());
    /* execute.simd:5734 [D] s_b_5_12 = s_b_5_8+s_b_5_11 */
    auto s_b_5_12 = emitter.add(s_b_5_8, s_b_5_11);
    /* execute.simd:5734 [F] s_b_5_13 = constant s32 0 (const) */
    /* execute.simd:5734 [D] s_b_5_14 = s_b_5_6[s_b_5_13] <= s_b_5_12 */
    auto s_b_5_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_12);
    /* ???:4294967295 [F] s_b_5_15 = constant u8 1 (const) */
    /* execute.simd:5734 [D] s_b_5_2[s_b_5_15] */
    auto s_b_5_16 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5734 [F] s_b_5_17 = constant u32 5 (const) */
    /* execute.simd:5734 [D] s_b_5_5[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5734 [D] s_b_5_19 = (s32)s_b_5_18 */
    auto s_b_5_19 = emitter.sx(s_b_5_18, emitter.context().types().s32());
    /* execute.simd:5734 [D] s_b_5_20 = s_b_5_16+s_b_5_19 */
    auto s_b_5_20 = emitter.add(s_b_5_16, s_b_5_19);
    /* execute.simd:5734 [F] s_b_5_21 = constant s32 1 (const) */
    /* execute.simd:5734 [D] s_b_5_22 = s_b_5_14[s_b_5_21] <= s_b_5_20 */
    auto s_b_5_22 = emitter.vector_insert(s_b_5_14, emitter.const_s32((int32_t)1ULL), s_b_5_20);
    /* ???:4294967295 [F] s_b_5_23 = constant u8 2 (const) */
    /* execute.simd:5734 [D] s_b_5_2[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5734 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5734 [D] s_b_5_5[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5734 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:5734 [D] s_b_5_28 = s_b_5_24+s_b_5_27 */
    auto s_b_5_28 = emitter.add(s_b_5_24, s_b_5_27);
    /* execute.simd:5734 [F] s_b_5_29 = constant s32 2 (const) */
    /* execute.simd:5734 [D] s_b_5_30 = s_b_5_22[s_b_5_29] <= s_b_5_28 */
    auto s_b_5_30 = emitter.vector_insert(s_b_5_22, emitter.const_s32((int32_t)2ULL), s_b_5_28);
    /* ???:4294967295 [F] s_b_5_31 = constant u8 3 (const) */
    /* execute.simd:5734 [D] s_b_5_2[s_b_5_31] */
    auto s_b_5_32 = emitter.vector_extract(s_b_5_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5734 [F] s_b_5_33 = constant u32 7 (const) */
    /* execute.simd:5734 [D] s_b_5_5[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5734 [D] s_b_5_35 = (s32)s_b_5_34 */
    auto s_b_5_35 = emitter.sx(s_b_5_34, emitter.context().types().s32());
    /* execute.simd:5734 [D] s_b_5_36 = s_b_5_32+s_b_5_35 */
    auto s_b_5_36 = emitter.add(s_b_5_32, s_b_5_35);
    /* execute.simd:5734 [F] s_b_5_37 = constant s32 3 (const) */
    /* execute.simd:5734 [D] s_b_5_38 = s_b_5_30[s_b_5_37] <= s_b_5_36 */
    auto s_b_5_38 = emitter.vector_insert(s_b_5_30, emitter.const_s32((int32_t)3ULL), s_b_5_36);
    /* execute.simd:5737 [F] s_b_5_39=sym_21564_3_parameter_inst.rd (const) */
    /* execute.simd:5737 [D] s_b_5_40 = (v4u32)s_b_5_38 */
    auto s_b_5_40 = emitter.reinterpret(s_b_5_38, emitter.context().types().v4u32());
    /* execute.simd:5737 [D] s_b_5_41: WriteRegBank 20:s_b_5_39 = s_b_5_40 */
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
    /* execute.simd:5741 [F] s_b_6_0=sym_21564_3_parameter_inst.rn (const) */
    /* execute.simd:5741 [D] s_b_6_1 = ReadRegBank 21:s_b_6_0 (v2u64) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(16));
    }
    /* execute.simd:5741 [D] s_b_6_2 = (v2s64)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s64());
    /* execute.simd:5742 [F] s_b_6_3=sym_21564_3_parameter_inst.rm (const) */
    /* execute.simd:5742 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5742 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5747 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_6_9 = constant u8 0 (const) */
    /* execute.simd:5747 [D] s_b_6_5[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5747 [D] s_b_6_11 = (s64)s_b_6_10 */
    auto s_b_6_11 = emitter.sx(s_b_6_10, emitter.context().types().s64());
    /* execute.simd:5747 [D] s_b_6_12 = s_b_6_8+s_b_6_11 */
    auto s_b_6_12 = emitter.add(s_b_6_8, s_b_6_11);
    /* execute.simd:5747 [F] s_b_6_13 = constant s32 0 (const) */
    /* execute.simd:5747 [D] s_b_6_14 = s_b_6_6[s_b_6_13] <= s_b_6_12 */
    auto s_b_6_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_12);
    /* ???:4294967295 [F] s_b_6_15 = constant u8 1 (const) */
    /* execute.simd:5747 [D] s_b_6_2[s_b_6_15] */
    auto s_b_6_16 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* ???:4294967295 [F] s_b_6_17 = constant u8 1 (const) */
    /* execute.simd:5747 [D] s_b_6_5[s_b_6_17] */
    auto s_b_6_18 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5747 [D] s_b_6_19 = (s64)s_b_6_18 */
    auto s_b_6_19 = emitter.sx(s_b_6_18, emitter.context().types().s64());
    /* execute.simd:5747 [D] s_b_6_20 = s_b_6_16+s_b_6_19 */
    auto s_b_6_20 = emitter.add(s_b_6_16, s_b_6_19);
    /* execute.simd:5747 [F] s_b_6_21 = constant s32 1 (const) */
    /* execute.simd:5747 [D] s_b_6_22 = s_b_6_14[s_b_6_21] <= s_b_6_20 */
    auto s_b_6_22 = emitter.vector_insert(s_b_6_14, emitter.const_s32((int32_t)1ULL), s_b_6_20);
    /* execute.simd:5750 [F] s_b_6_23=sym_21564_3_parameter_inst.rd (const) */
    /* execute.simd:5750 [D] s_b_6_24 = (v2u64)s_b_6_22 */
    auto s_b_6_24 = emitter.reinterpret(s_b_6_22, emitter.context().types().v2u64());
    /* execute.simd:5750 [D] s_b_6_25: WriteRegBank 21:s_b_6_23 = s_b_6_24 */
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
    /* execute.simd:5754 [F] s_b_7_0=sym_21564_3_parameter_inst.rn (const) */
    /* execute.simd:5754 [D] s_b_7_1 = ReadRegBank 21:s_b_7_0 (v2u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5754 [D] s_b_7_2 = (v2s64)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v2s64());
    /* execute.simd:5755 [F] s_b_7_3=sym_21564_3_parameter_inst.rm (const) */
    /* execute.simd:5755 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5755 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_7_7 = constant u8 0 (const) */
    /* execute.simd:5760 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5760 [F] s_b_7_9 = constant u32 2 (const) */
    /* execute.simd:5760 [D] s_b_7_5[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5760 [D] s_b_7_11 = (s64)s_b_7_10 */
    auto s_b_7_11 = emitter.sx(s_b_7_10, emitter.context().types().s64());
    /* execute.simd:5760 [D] s_b_7_12 = s_b_7_8+s_b_7_11 */
    auto s_b_7_12 = emitter.add(s_b_7_8, s_b_7_11);
    /* execute.simd:5760 [F] s_b_7_13 = constant s32 0 (const) */
    /* execute.simd:5760 [D] s_b_7_14 = s_b_7_6[s_b_7_13] <= s_b_7_12 */
    auto s_b_7_14 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_12);
    /* ???:4294967295 [F] s_b_7_15 = constant u8 1 (const) */
    /* execute.simd:5760 [D] s_b_7_2[s_b_7_15] */
    auto s_b_7_16 = emitter.vector_extract(s_b_7_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5760 [F] s_b_7_17 = constant u32 3 (const) */
    /* execute.simd:5760 [D] s_b_7_5[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5760 [D] s_b_7_19 = (s64)s_b_7_18 */
    auto s_b_7_19 = emitter.sx(s_b_7_18, emitter.context().types().s64());
    /* execute.simd:5760 [D] s_b_7_20 = s_b_7_16+s_b_7_19 */
    auto s_b_7_20 = emitter.add(s_b_7_16, s_b_7_19);
    /* execute.simd:5760 [F] s_b_7_21 = constant s32 1 (const) */
    /* execute.simd:5760 [D] s_b_7_22 = s_b_7_14[s_b_7_21] <= s_b_7_20 */
    auto s_b_7_22 = emitter.vector_insert(s_b_7_14, emitter.const_s32((int32_t)1ULL), s_b_7_20);
    /* execute.simd:5763 [F] s_b_7_23=sym_21564_3_parameter_inst.rd (const) */
    /* execute.simd:5763 [D] s_b_7_24 = (v2u64)s_b_7_22 */
    auto s_b_7_24 = emitter.reinterpret(s_b_7_22, emitter.context().types().v2u64());
    /* execute.simd:5763 [D] s_b_7_25: WriteRegBank 21:s_b_7_23 = s_b_7_24 */
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
    /* execute.simd:5767 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5687 [F] s_b_8_1: Jump b_1 (const) */
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
  auto DV_sym_132968_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_132924_1_tmp_s_b_22_0 = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_132927_1_tmp_s_b_22_1 = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_132828_1_temporary_value;
  auto DV_sym_132828_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_132879_1_temporary_value;
  auto DV_sym_132879_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  auto DV_sym_132858_1_tmp_s_b_11_0 = emitter.alloc_local(emitter.context().types().s64(), false);
  int64_t CV_sym_132765_1_temporary_value;
  auto DV_sym_132765_1_temporary_value = emitter.alloc_local(emitter.context().types().s64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:2422 [F] s_b_0_0=sym_23039_3_parameter_inst.rn (const) */
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
    /* execute.a64:2731 [F] s_b_1_1: sym_132765_1_temporary_value = s_b_1_0 (const), dominates: s_b_3_0  */
    CV_sym_132765_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_132765_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2731 [F] s_b_1_2: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:2731 [F] s_b_2_0=sym_23039_3_parameter_inst.rn (const) */
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
    /* execute.a64:2731 [D] s_b_2_4: sym_132765_1_temporary_value = s_b_2_3, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_132765_1_temporary_value, s_b_2_3);
    /* execute.a64:2731 [F] s_b_2_5: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_1, b_2,  */
  fixed_block_b_3: 
  {
    /* execute.a64:2731 [D] s_b_3_0 = sym_132765_1_temporary_value int64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_132765_1_temporary_value, emitter.context().types().s64());
    /* execute.a64:2423 [F] s_b_3_1=sym_23039_3_parameter_inst.rm (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_132858_1_tmp_s_b_11_0 = s_b_3_0, dominates: s_b_6_1  */
    emitter.store_local(DV_sym_132858_1_tmp_s_b_11_0, s_b_3_0);
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
    /* execute.a64:2731 [F] s_b_4_1: sym_132828_1_temporary_value = s_b_4_0 (const), dominates: s_b_6_0  */
    CV_sym_132828_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_132828_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2731 [F] s_b_4_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_5: 
  {
    /* execute.a64:2731 [F] s_b_5_0=sym_23039_3_parameter_inst.rm (const) */
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
    /* execute.a64:2731 [D] s_b_5_4: sym_132828_1_temporary_value = s_b_5_3, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_132828_1_temporary_value, s_b_5_3);
    /* execute.a64:2731 [F] s_b_5_5: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_4, b_5,  */
  fixed_block_b_6: 
  {
    /* execute.a64:2731 [D] s_b_6_0 = sym_132828_1_temporary_value int64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_132828_1_temporary_value, emitter.context().types().s64());
    /* ???:4294967295 [D] s_b_6_1 = sym_132858_1_tmp_s_b_11_0 int64_t */
    auto s_b_6_1 = emitter.load_local(DV_sym_132858_1_tmp_s_b_11_0, emitter.context().types().s64());
    /* execute.a64:2424 [F] s_b_6_2=sym_23039_3_parameter_inst.ra (const) */
    /* ???:4294967295 [D] s_b_6_3: sym_132924_1_tmp_s_b_22_0 = s_b_6_1, dominates: s_b_9_2  */
    emitter.store_local(DV_sym_132924_1_tmp_s_b_22_0, s_b_6_1);
    /* ???:4294967295 [D] s_b_6_4: sym_132927_1_tmp_s_b_22_1 = s_b_6_0, dominates: s_b_9_1  */
    emitter.store_local(DV_sym_132927_1_tmp_s_b_22_1, s_b_6_0);
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
    /* execute.a64:2729 [F] s_b_7_1: sym_132879_1_temporary_value = s_b_7_0 (const), dominates: s_b_9_0  */
    CV_sym_132879_1_temporary_value = (int64_t)0ULL;
    emitter.store_local(DV_sym_132879_1_temporary_value, emitter.const_s64((int64_t)0ULL));
    /* execute.a64:2729 [F] s_b_7_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6,  */
  fixed_block_b_8: 
  {
    /* execute.a64:2729 [F] s_b_8_0=sym_23039_3_parameter_inst.ra (const) */
    /* execute.a64:2729 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.ra))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.ra))),s_b_8_1,emitter.const_u8(8));
    }
    /* execute.a64:2729 [D] s_b_8_2 = (s64)s_b_8_1 */
    auto s_b_8_2 = emitter.reinterpret(s_b_8_1, emitter.context().types().s64());
    /* execute.a64:2729 [D] s_b_8_3: sym_132879_1_temporary_value = s_b_8_2, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_132879_1_temporary_value, s_b_8_2);
    /* execute.a64:2729 [F] s_b_8_4: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_7, b_8,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2729 [D] s_b_9_0 = sym_132879_1_temporary_value int64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_132879_1_temporary_value, emitter.context().types().s64());
    /* ???:4294967295 [D] s_b_9_1 = sym_132927_1_tmp_s_b_22_1 int64_t */
    auto s_b_9_1 = emitter.load_local(DV_sym_132927_1_tmp_s_b_22_1, emitter.context().types().s64());
    /* ???:4294967295 [D] s_b_9_2 = sym_132924_1_tmp_s_b_22_0 int64_t */
    auto s_b_9_2 = emitter.load_local(DV_sym_132924_1_tmp_s_b_22_0, emitter.context().types().s64());
    /* execute.a64:2426 [D] s_b_9_3 = (s64)s_b_9_2 */
    auto s_b_9_3 = (captive::arch::dbt::el::Value *)s_b_9_2;
    /* execute.a64:2426 [D] s_b_9_4 = s_b_9_3*s_b_9_1 */
    auto s_b_9_4 = emitter.mul(s_b_9_3, s_b_9_1);
    /* execute.a64:2426 [D] s_b_9_5 = s_b_9_0+s_b_9_4 */
    auto s_b_9_5 = emitter.add(s_b_9_0, s_b_9_4);
    /* execute.a64:2426 [D] s_b_9_6 = (u64)s_b_9_5 */
    auto s_b_9_6 = emitter.reinterpret(s_b_9_5, emitter.context().types().u64());
    /* execute.a64:2754 [F] s_b_9_7=sym_23039_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_9_8: sym_132968_3_parameter_value = s_b_9_6, dominates: s_b_11_1  */
    emitter.store_local(DV_sym_132968_3_parameter_value, s_b_9_6);
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
    /* execute.a64:2747 [F] s_b_11_0=sym_23039_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_11_1 = sym_132968_3_parameter_value uint64_t */
    auto s_b_11_1 = emitter.load_local(DV_sym_132968_3_parameter_value, emitter.context().types().u64());
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_smull(const arm64_decode_a64_SIMD_THREE_DIFF&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:5351 [F] s_b_0_0=sym_24979_3_parameter_inst.tb (const) */
    /* execute.simd:5352 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5365 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5378 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5391 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5404 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5417 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5351 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5353 [F] s_b_2_0=sym_24979_3_parameter_inst.rn (const) */
    /* execute.simd:5353 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5353 [D] s_b_2_2 = (v8s8)s_b_2_1 */
    auto s_b_2_2 = emitter.reinterpret(s_b_2_1, emitter.context().types().v8s8());
    /* execute.simd:5354 [F] s_b_2_3=sym_24979_3_parameter_inst.rm (const) */
    /* execute.simd:5354 [D] s_b_2_4 = ReadRegBank 15:s_b_2_3 (v8u8) */
    auto s_b_2_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_2_4,emitter.const_u8(8));
    }
    /* execute.simd:5354 [D] s_b_2_5 = (v8s8)s_b_2_4 */
    auto s_b_2_5 = emitter.reinterpret(s_b_2_4, emitter.context().types().v8s8());
    /* ???:4294967295 [F] s_b_2_6 = constant v8s16 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_2_7 = constant u8 0 (const) */
    /* execute.simd:5359 [D] s_b_2_2[s_b_2_7] */
    auto s_b_2_8 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5359 [D] s_b_2_9 = (s16)s_b_2_8 */
    auto s_b_2_9 = emitter.sx(s_b_2_8, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_10 = constant u8 0 (const) */
    /* execute.simd:5359 [D] s_b_2_5[s_b_2_10] */
    auto s_b_2_11 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5359 [D] s_b_2_12 = (s16)s_b_2_11 */
    auto s_b_2_12 = emitter.sx(s_b_2_11, emitter.context().types().s16());
    /* execute.simd:5359 [D] s_b_2_13 = s_b_2_9*s_b_2_12 */
    auto s_b_2_13 = emitter.mul(s_b_2_9, s_b_2_12);
    /* execute.simd:5359 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:5359 [D] s_b_2_15 = s_b_2_6[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:5359 [D] s_b_2_2[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5359 [D] s_b_2_18 = (s16)s_b_2_17 */
    auto s_b_2_18 = emitter.sx(s_b_2_17, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_19 = constant u8 1 (const) */
    /* execute.simd:5359 [D] s_b_2_5[s_b_2_19] */
    auto s_b_2_20 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5359 [D] s_b_2_21 = (s16)s_b_2_20 */
    auto s_b_2_21 = emitter.sx(s_b_2_20, emitter.context().types().s16());
    /* execute.simd:5359 [D] s_b_2_22 = s_b_2_18*s_b_2_21 */
    auto s_b_2_22 = emitter.mul(s_b_2_18, s_b_2_21);
    /* execute.simd:5359 [F] s_b_2_23 = constant s32 1 (const) */
    /* execute.simd:5359 [D] s_b_2_24 = s_b_2_15[s_b_2_23] <= s_b_2_22 */
    auto s_b_2_24 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_22);
    /* ???:4294967295 [F] s_b_2_25 = constant u8 2 (const) */
    /* execute.simd:5359 [D] s_b_2_2[s_b_2_25] */
    auto s_b_2_26 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5359 [D] s_b_2_27 = (s16)s_b_2_26 */
    auto s_b_2_27 = emitter.sx(s_b_2_26, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:5359 [D] s_b_2_5[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5359 [D] s_b_2_30 = (s16)s_b_2_29 */
    auto s_b_2_30 = emitter.sx(s_b_2_29, emitter.context().types().s16());
    /* execute.simd:5359 [D] s_b_2_31 = s_b_2_27*s_b_2_30 */
    auto s_b_2_31 = emitter.mul(s_b_2_27, s_b_2_30);
    /* execute.simd:5359 [F] s_b_2_32 = constant s32 2 (const) */
    /* execute.simd:5359 [D] s_b_2_33 = s_b_2_24[s_b_2_32] <= s_b_2_31 */
    auto s_b_2_33 = emitter.vector_insert(s_b_2_24, emitter.const_s32((int32_t)2ULL), s_b_2_31);
    /* ???:4294967295 [F] s_b_2_34 = constant u8 3 (const) */
    /* execute.simd:5359 [D] s_b_2_2[s_b_2_34] */
    auto s_b_2_35 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5359 [D] s_b_2_36 = (s16)s_b_2_35 */
    auto s_b_2_36 = emitter.sx(s_b_2_35, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_37 = constant u8 3 (const) */
    /* execute.simd:5359 [D] s_b_2_5[s_b_2_37] */
    auto s_b_2_38 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5359 [D] s_b_2_39 = (s16)s_b_2_38 */
    auto s_b_2_39 = emitter.sx(s_b_2_38, emitter.context().types().s16());
    /* execute.simd:5359 [D] s_b_2_40 = s_b_2_36*s_b_2_39 */
    auto s_b_2_40 = emitter.mul(s_b_2_36, s_b_2_39);
    /* execute.simd:5359 [F] s_b_2_41 = constant s32 3 (const) */
    /* execute.simd:5359 [D] s_b_2_42 = s_b_2_33[s_b_2_41] <= s_b_2_40 */
    auto s_b_2_42 = emitter.vector_insert(s_b_2_33, emitter.const_s32((int32_t)3ULL), s_b_2_40);
    /* ???:4294967295 [F] s_b_2_43 = constant u8 4 (const) */
    /* execute.simd:5359 [D] s_b_2_2[s_b_2_43] */
    auto s_b_2_44 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5359 [D] s_b_2_45 = (s16)s_b_2_44 */
    auto s_b_2_45 = emitter.sx(s_b_2_44, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_46 = constant u8 4 (const) */
    /* execute.simd:5359 [D] s_b_2_5[s_b_2_46] */
    auto s_b_2_47 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5359 [D] s_b_2_48 = (s16)s_b_2_47 */
    auto s_b_2_48 = emitter.sx(s_b_2_47, emitter.context().types().s16());
    /* execute.simd:5359 [D] s_b_2_49 = s_b_2_45*s_b_2_48 */
    auto s_b_2_49 = emitter.mul(s_b_2_45, s_b_2_48);
    /* execute.simd:5359 [F] s_b_2_50 = constant s32 4 (const) */
    /* execute.simd:5359 [D] s_b_2_51 = s_b_2_42[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_42, emitter.const_s32((int32_t)4ULL), s_b_2_49);
    /* ???:4294967295 [F] s_b_2_52 = constant u8 5 (const) */
    /* execute.simd:5359 [D] s_b_2_2[s_b_2_52] */
    auto s_b_2_53 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5359 [D] s_b_2_54 = (s16)s_b_2_53 */
    auto s_b_2_54 = emitter.sx(s_b_2_53, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_55 = constant u8 5 (const) */
    /* execute.simd:5359 [D] s_b_2_5[s_b_2_55] */
    auto s_b_2_56 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5359 [D] s_b_2_57 = (s16)s_b_2_56 */
    auto s_b_2_57 = emitter.sx(s_b_2_56, emitter.context().types().s16());
    /* execute.simd:5359 [D] s_b_2_58 = s_b_2_54*s_b_2_57 */
    auto s_b_2_58 = emitter.mul(s_b_2_54, s_b_2_57);
    /* execute.simd:5359 [F] s_b_2_59 = constant s32 5 (const) */
    /* execute.simd:5359 [D] s_b_2_60 = s_b_2_51[s_b_2_59] <= s_b_2_58 */
    auto s_b_2_60 = emitter.vector_insert(s_b_2_51, emitter.const_s32((int32_t)5ULL), s_b_2_58);
    /* ???:4294967295 [F] s_b_2_61 = constant u8 6 (const) */
    /* execute.simd:5359 [D] s_b_2_2[s_b_2_61] */
    auto s_b_2_62 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5359 [D] s_b_2_63 = (s16)s_b_2_62 */
    auto s_b_2_63 = emitter.sx(s_b_2_62, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_64 = constant u8 6 (const) */
    /* execute.simd:5359 [D] s_b_2_5[s_b_2_64] */
    auto s_b_2_65 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5359 [D] s_b_2_66 = (s16)s_b_2_65 */
    auto s_b_2_66 = emitter.sx(s_b_2_65, emitter.context().types().s16());
    /* execute.simd:5359 [D] s_b_2_67 = s_b_2_63*s_b_2_66 */
    auto s_b_2_67 = emitter.mul(s_b_2_63, s_b_2_66);
    /* execute.simd:5359 [F] s_b_2_68 = constant s32 6 (const) */
    /* execute.simd:5359 [D] s_b_2_69 = s_b_2_60[s_b_2_68] <= s_b_2_67 */
    auto s_b_2_69 = emitter.vector_insert(s_b_2_60, emitter.const_s32((int32_t)6ULL), s_b_2_67);
    /* ???:4294967295 [F] s_b_2_70 = constant u8 7 (const) */
    /* execute.simd:5359 [D] s_b_2_2[s_b_2_70] */
    auto s_b_2_71 = emitter.vector_extract(s_b_2_2, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5359 [D] s_b_2_72 = (s16)s_b_2_71 */
    auto s_b_2_72 = emitter.sx(s_b_2_71, emitter.context().types().s16());
    /* ???:4294967295 [F] s_b_2_73 = constant u8 7 (const) */
    /* execute.simd:5359 [D] s_b_2_5[s_b_2_73] */
    auto s_b_2_74 = emitter.vector_extract(s_b_2_5, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5359 [D] s_b_2_75 = (s16)s_b_2_74 */
    auto s_b_2_75 = emitter.sx(s_b_2_74, emitter.context().types().s16());
    /* execute.simd:5359 [D] s_b_2_76 = s_b_2_72*s_b_2_75 */
    auto s_b_2_76 = emitter.mul(s_b_2_72, s_b_2_75);
    /* execute.simd:5359 [F] s_b_2_77 = constant s32 7 (const) */
    /* execute.simd:5359 [D] s_b_2_78 = s_b_2_69[s_b_2_77] <= s_b_2_76 */
    auto s_b_2_78 = emitter.vector_insert(s_b_2_69, emitter.const_s32((int32_t)7ULL), s_b_2_76);
    /* execute.simd:5362 [F] s_b_2_79=sym_24979_3_parameter_inst.rd (const) */
    /* execute.simd:5362 [D] s_b_2_80 = (v8u16)s_b_2_78 */
    auto s_b_2_80 = emitter.reinterpret(s_b_2_78, emitter.context().types().v8u16());
    /* execute.simd:5362 [D] s_b_2_81: WriteRegBank 18:s_b_2_79 = s_b_2_80 */
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
    /* execute.simd:5366 [F] s_b_3_0=sym_24979_3_parameter_inst.rn (const) */
    /* execute.simd:5366 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5366 [D] s_b_3_2 = (v16s8)s_b_3_1 */
    auto s_b_3_2 = emitter.reinterpret(s_b_3_1, emitter.context().types().v16s8());
    /* execute.simd:5367 [F] s_b_3_3=sym_24979_3_parameter_inst.rm (const) */
    /* execute.simd:5367 [D] s_b_3_4 = ReadRegBank 16:s_b_3_3 (v16u8) */
    auto s_b_3_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_4,emitter.const_u8(16));
    }
    /* execute.simd:5367 [D] s_b_3_5 = (v16s8)s_b_3_4 */
    auto s_b_3_5 = emitter.reinterpret(s_b_3_4, emitter.context().types().v16s8());
    /* ???:4294967295 [F] s_b_3_6 = constant v8s16 
    {
    }
    (const) */
    /* execute.simd:5372 [F] s_b_3_7 = constant u32 8 (const) */
    /* execute.simd:5372 [D] s_b_3_2[s_b_3_7] */
    auto s_b_3_8 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5372 [D] s_b_3_9 = (s16)s_b_3_8 */
    auto s_b_3_9 = emitter.sx(s_b_3_8, emitter.context().types().s16());
    /* execute.simd:5372 [F] s_b_3_10 = constant u32 8 (const) */
    /* execute.simd:5372 [D] s_b_3_5[s_b_3_10] */
    auto s_b_3_11 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5372 [D] s_b_3_12 = (s16)s_b_3_11 */
    auto s_b_3_12 = emitter.sx(s_b_3_11, emitter.context().types().s16());
    /* execute.simd:5372 [D] s_b_3_13 = s_b_3_9*s_b_3_12 */
    auto s_b_3_13 = emitter.mul(s_b_3_9, s_b_3_12);
    /* execute.simd:5372 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:5372 [D] s_b_3_15 = s_b_3_6[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int16_t, 8>(0)[0], emitter.context().types().v8s16()), emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* execute.simd:5372 [F] s_b_3_16 = constant u32 9 (const) */
    /* execute.simd:5372 [D] s_b_3_2[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5372 [D] s_b_3_18 = (s16)s_b_3_17 */
    auto s_b_3_18 = emitter.sx(s_b_3_17, emitter.context().types().s16());
    /* execute.simd:5372 [F] s_b_3_19 = constant u32 9 (const) */
    /* execute.simd:5372 [D] s_b_3_5[s_b_3_19] */
    auto s_b_3_20 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5372 [D] s_b_3_21 = (s16)s_b_3_20 */
    auto s_b_3_21 = emitter.sx(s_b_3_20, emitter.context().types().s16());
    /* execute.simd:5372 [D] s_b_3_22 = s_b_3_18*s_b_3_21 */
    auto s_b_3_22 = emitter.mul(s_b_3_18, s_b_3_21);
    /* execute.simd:5372 [F] s_b_3_23 = constant s32 1 (const) */
    /* execute.simd:5372 [D] s_b_3_24 = s_b_3_15[s_b_3_23] <= s_b_3_22 */
    auto s_b_3_24 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_22);
    /* execute.simd:5372 [F] s_b_3_25 = constant u32 a (const) */
    /* execute.simd:5372 [D] s_b_3_2[s_b_3_25] */
    auto s_b_3_26 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5372 [D] s_b_3_27 = (s16)s_b_3_26 */
    auto s_b_3_27 = emitter.sx(s_b_3_26, emitter.context().types().s16());
    /* execute.simd:5372 [F] s_b_3_28 = constant u32 a (const) */
    /* execute.simd:5372 [D] s_b_3_5[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5372 [D] s_b_3_30 = (s16)s_b_3_29 */
    auto s_b_3_30 = emitter.sx(s_b_3_29, emitter.context().types().s16());
    /* execute.simd:5372 [D] s_b_3_31 = s_b_3_27*s_b_3_30 */
    auto s_b_3_31 = emitter.mul(s_b_3_27, s_b_3_30);
    /* execute.simd:5372 [F] s_b_3_32 = constant s32 2 (const) */
    /* execute.simd:5372 [D] s_b_3_33 = s_b_3_24[s_b_3_32] <= s_b_3_31 */
    auto s_b_3_33 = emitter.vector_insert(s_b_3_24, emitter.const_s32((int32_t)2ULL), s_b_3_31);
    /* execute.simd:5372 [F] s_b_3_34 = constant u32 b (const) */
    /* execute.simd:5372 [D] s_b_3_2[s_b_3_34] */
    auto s_b_3_35 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5372 [D] s_b_3_36 = (s16)s_b_3_35 */
    auto s_b_3_36 = emitter.sx(s_b_3_35, emitter.context().types().s16());
    /* execute.simd:5372 [F] s_b_3_37 = constant u32 b (const) */
    /* execute.simd:5372 [D] s_b_3_5[s_b_3_37] */
    auto s_b_3_38 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5372 [D] s_b_3_39 = (s16)s_b_3_38 */
    auto s_b_3_39 = emitter.sx(s_b_3_38, emitter.context().types().s16());
    /* execute.simd:5372 [D] s_b_3_40 = s_b_3_36*s_b_3_39 */
    auto s_b_3_40 = emitter.mul(s_b_3_36, s_b_3_39);
    /* execute.simd:5372 [F] s_b_3_41 = constant s32 3 (const) */
    /* execute.simd:5372 [D] s_b_3_42 = s_b_3_33[s_b_3_41] <= s_b_3_40 */
    auto s_b_3_42 = emitter.vector_insert(s_b_3_33, emitter.const_s32((int32_t)3ULL), s_b_3_40);
    /* execute.simd:5372 [F] s_b_3_43 = constant u32 c (const) */
    /* execute.simd:5372 [D] s_b_3_2[s_b_3_43] */
    auto s_b_3_44 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5372 [D] s_b_3_45 = (s16)s_b_3_44 */
    auto s_b_3_45 = emitter.sx(s_b_3_44, emitter.context().types().s16());
    /* execute.simd:5372 [F] s_b_3_46 = constant u32 c (const) */
    /* execute.simd:5372 [D] s_b_3_5[s_b_3_46] */
    auto s_b_3_47 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5372 [D] s_b_3_48 = (s16)s_b_3_47 */
    auto s_b_3_48 = emitter.sx(s_b_3_47, emitter.context().types().s16());
    /* execute.simd:5372 [D] s_b_3_49 = s_b_3_45*s_b_3_48 */
    auto s_b_3_49 = emitter.mul(s_b_3_45, s_b_3_48);
    /* execute.simd:5372 [F] s_b_3_50 = constant s32 4 (const) */
    /* execute.simd:5372 [D] s_b_3_51 = s_b_3_42[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_42, emitter.const_s32((int32_t)4ULL), s_b_3_49);
    /* execute.simd:5372 [F] s_b_3_52 = constant u32 d (const) */
    /* execute.simd:5372 [D] s_b_3_2[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5372 [D] s_b_3_54 = (s16)s_b_3_53 */
    auto s_b_3_54 = emitter.sx(s_b_3_53, emitter.context().types().s16());
    /* execute.simd:5372 [F] s_b_3_55 = constant u32 d (const) */
    /* execute.simd:5372 [D] s_b_3_5[s_b_3_55] */
    auto s_b_3_56 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5372 [D] s_b_3_57 = (s16)s_b_3_56 */
    auto s_b_3_57 = emitter.sx(s_b_3_56, emitter.context().types().s16());
    /* execute.simd:5372 [D] s_b_3_58 = s_b_3_54*s_b_3_57 */
    auto s_b_3_58 = emitter.mul(s_b_3_54, s_b_3_57);
    /* execute.simd:5372 [F] s_b_3_59 = constant s32 5 (const) */
    /* execute.simd:5372 [D] s_b_3_60 = s_b_3_51[s_b_3_59] <= s_b_3_58 */
    auto s_b_3_60 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)5ULL), s_b_3_58);
    /* execute.simd:5372 [F] s_b_3_61 = constant u32 e (const) */
    /* execute.simd:5372 [D] s_b_3_2[s_b_3_61] */
    auto s_b_3_62 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5372 [D] s_b_3_63 = (s16)s_b_3_62 */
    auto s_b_3_63 = emitter.sx(s_b_3_62, emitter.context().types().s16());
    /* execute.simd:5372 [F] s_b_3_64 = constant u32 e (const) */
    /* execute.simd:5372 [D] s_b_3_5[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5372 [D] s_b_3_66 = (s16)s_b_3_65 */
    auto s_b_3_66 = emitter.sx(s_b_3_65, emitter.context().types().s16());
    /* execute.simd:5372 [D] s_b_3_67 = s_b_3_63*s_b_3_66 */
    auto s_b_3_67 = emitter.mul(s_b_3_63, s_b_3_66);
    /* execute.simd:5372 [F] s_b_3_68 = constant s32 6 (const) */
    /* execute.simd:5372 [D] s_b_3_69 = s_b_3_60[s_b_3_68] <= s_b_3_67 */
    auto s_b_3_69 = emitter.vector_insert(s_b_3_60, emitter.const_s32((int32_t)6ULL), s_b_3_67);
    /* execute.simd:5372 [F] s_b_3_70 = constant u32 f (const) */
    /* execute.simd:5372 [D] s_b_3_2[s_b_3_70] */
    auto s_b_3_71 = emitter.vector_extract(s_b_3_2, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5372 [D] s_b_3_72 = (s16)s_b_3_71 */
    auto s_b_3_72 = emitter.sx(s_b_3_71, emitter.context().types().s16());
    /* execute.simd:5372 [F] s_b_3_73 = constant u32 f (const) */
    /* execute.simd:5372 [D] s_b_3_5[s_b_3_73] */
    auto s_b_3_74 = emitter.vector_extract(s_b_3_5, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5372 [D] s_b_3_75 = (s16)s_b_3_74 */
    auto s_b_3_75 = emitter.sx(s_b_3_74, emitter.context().types().s16());
    /* execute.simd:5372 [D] s_b_3_76 = s_b_3_72*s_b_3_75 */
    auto s_b_3_76 = emitter.mul(s_b_3_72, s_b_3_75);
    /* execute.simd:5372 [F] s_b_3_77 = constant s32 7 (const) */
    /* execute.simd:5372 [D] s_b_3_78 = s_b_3_69[s_b_3_77] <= s_b_3_76 */
    auto s_b_3_78 = emitter.vector_insert(s_b_3_69, emitter.const_s32((int32_t)7ULL), s_b_3_76);
    /* execute.simd:5375 [F] s_b_3_79=sym_24979_3_parameter_inst.rd (const) */
    /* execute.simd:5375 [D] s_b_3_80 = (v8u16)s_b_3_78 */
    auto s_b_3_80 = emitter.reinterpret(s_b_3_78, emitter.context().types().v8u16());
    /* execute.simd:5375 [D] s_b_3_81: WriteRegBank 18:s_b_3_79 = s_b_3_80 */
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
    /* execute.simd:5379 [F] s_b_4_0=sym_24979_3_parameter_inst.rn (const) */
    /* execute.simd:5379 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5379 [D] s_b_4_2 = (v4s16)s_b_4_1 */
    auto s_b_4_2 = emitter.reinterpret(s_b_4_1, emitter.context().types().v4s16());
    /* execute.simd:5380 [F] s_b_4_3=sym_24979_3_parameter_inst.rm (const) */
    /* execute.simd:5380 [D] s_b_4_4 = ReadRegBank 17:s_b_4_3 (v4u16) */
    auto s_b_4_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_4_4,emitter.const_u8(8));
    }
    /* execute.simd:5380 [D] s_b_4_5 = (v4s16)s_b_4_4 */
    auto s_b_4_5 = emitter.reinterpret(s_b_4_4, emitter.context().types().v4s16());
    /* ???:4294967295 [F] s_b_4_6 = constant v4s32 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_4_7 = constant u8 0 (const) */
    /* execute.simd:5385 [D] s_b_4_2[s_b_4_7] */
    auto s_b_4_8 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5385 [D] s_b_4_9 = (s32)s_b_4_8 */
    auto s_b_4_9 = emitter.sx(s_b_4_8, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_10 = constant u8 0 (const) */
    /* execute.simd:5385 [D] s_b_4_5[s_b_4_10] */
    auto s_b_4_11 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5385 [D] s_b_4_12 = (s32)s_b_4_11 */
    auto s_b_4_12 = emitter.sx(s_b_4_11, emitter.context().types().s32());
    /* execute.simd:5385 [D] s_b_4_13 = s_b_4_9*s_b_4_12 */
    auto s_b_4_13 = emitter.mul(s_b_4_9, s_b_4_12);
    /* execute.simd:5385 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:5385 [D] s_b_4_15 = s_b_4_6[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:5385 [D] s_b_4_2[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5385 [D] s_b_4_18 = (s32)s_b_4_17 */
    auto s_b_4_18 = emitter.sx(s_b_4_17, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_19 = constant u8 1 (const) */
    /* execute.simd:5385 [D] s_b_4_5[s_b_4_19] */
    auto s_b_4_20 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5385 [D] s_b_4_21 = (s32)s_b_4_20 */
    auto s_b_4_21 = emitter.sx(s_b_4_20, emitter.context().types().s32());
    /* execute.simd:5385 [D] s_b_4_22 = s_b_4_18*s_b_4_21 */
    auto s_b_4_22 = emitter.mul(s_b_4_18, s_b_4_21);
    /* execute.simd:5385 [F] s_b_4_23 = constant s32 1 (const) */
    /* execute.simd:5385 [D] s_b_4_24 = s_b_4_15[s_b_4_23] <= s_b_4_22 */
    auto s_b_4_24 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_22);
    /* ???:4294967295 [F] s_b_4_25 = constant u8 2 (const) */
    /* execute.simd:5385 [D] s_b_4_2[s_b_4_25] */
    auto s_b_4_26 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5385 [D] s_b_4_27 = (s32)s_b_4_26 */
    auto s_b_4_27 = emitter.sx(s_b_4_26, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_28 = constant u8 2 (const) */
    /* execute.simd:5385 [D] s_b_4_5[s_b_4_28] */
    auto s_b_4_29 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5385 [D] s_b_4_30 = (s32)s_b_4_29 */
    auto s_b_4_30 = emitter.sx(s_b_4_29, emitter.context().types().s32());
    /* execute.simd:5385 [D] s_b_4_31 = s_b_4_27*s_b_4_30 */
    auto s_b_4_31 = emitter.mul(s_b_4_27, s_b_4_30);
    /* execute.simd:5385 [F] s_b_4_32 = constant s32 2 (const) */
    /* execute.simd:5385 [D] s_b_4_33 = s_b_4_24[s_b_4_32] <= s_b_4_31 */
    auto s_b_4_33 = emitter.vector_insert(s_b_4_24, emitter.const_s32((int32_t)2ULL), s_b_4_31);
    /* ???:4294967295 [F] s_b_4_34 = constant u8 3 (const) */
    /* execute.simd:5385 [D] s_b_4_2[s_b_4_34] */
    auto s_b_4_35 = emitter.vector_extract(s_b_4_2, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5385 [D] s_b_4_36 = (s32)s_b_4_35 */
    auto s_b_4_36 = emitter.sx(s_b_4_35, emitter.context().types().s32());
    /* ???:4294967295 [F] s_b_4_37 = constant u8 3 (const) */
    /* execute.simd:5385 [D] s_b_4_5[s_b_4_37] */
    auto s_b_4_38 = emitter.vector_extract(s_b_4_5, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5385 [D] s_b_4_39 = (s32)s_b_4_38 */
    auto s_b_4_39 = emitter.sx(s_b_4_38, emitter.context().types().s32());
    /* execute.simd:5385 [D] s_b_4_40 = s_b_4_36*s_b_4_39 */
    auto s_b_4_40 = emitter.mul(s_b_4_36, s_b_4_39);
    /* execute.simd:5385 [F] s_b_4_41 = constant s32 3 (const) */
    /* execute.simd:5385 [D] s_b_4_42 = s_b_4_33[s_b_4_41] <= s_b_4_40 */
    auto s_b_4_42 = emitter.vector_insert(s_b_4_33, emitter.const_s32((int32_t)3ULL), s_b_4_40);
    /* execute.simd:5388 [F] s_b_4_43=sym_24979_3_parameter_inst.rd (const) */
    /* execute.simd:5388 [D] s_b_4_44 = (v4u32)s_b_4_42 */
    auto s_b_4_44 = emitter.reinterpret(s_b_4_42, emitter.context().types().v4u32());
    /* execute.simd:5388 [D] s_b_4_45: WriteRegBank 20:s_b_4_43 = s_b_4_44 */
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
    /* execute.simd:5392 [F] s_b_5_0=sym_24979_3_parameter_inst.rn (const) */
    /* execute.simd:5392 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5392 [D] s_b_5_2 = (v8s16)s_b_5_1 */
    auto s_b_5_2 = emitter.reinterpret(s_b_5_1, emitter.context().types().v8s16());
    /* execute.simd:5393 [F] s_b_5_3=sym_24979_3_parameter_inst.rm (const) */
    /* execute.simd:5393 [D] s_b_5_4 = ReadRegBank 18:s_b_5_3 (v8u16) */
    auto s_b_5_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_4,emitter.const_u8(16));
    }
    /* execute.simd:5393 [D] s_b_5_5 = (v8s16)s_b_5_4 */
    auto s_b_5_5 = emitter.reinterpret(s_b_5_4, emitter.context().types().v8s16());
    /* ???:4294967295 [F] s_b_5_6 = constant v4s32 
    {
    }
    (const) */
    /* execute.simd:5398 [F] s_b_5_7 = constant u32 4 (const) */
    /* execute.simd:5398 [D] s_b_5_2[s_b_5_7] */
    auto s_b_5_8 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5398 [D] s_b_5_9 = (s32)s_b_5_8 */
    auto s_b_5_9 = emitter.sx(s_b_5_8, emitter.context().types().s32());
    /* execute.simd:5398 [F] s_b_5_10 = constant u32 4 (const) */
    /* execute.simd:5398 [D] s_b_5_5[s_b_5_10] */
    auto s_b_5_11 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5398 [D] s_b_5_12 = (s32)s_b_5_11 */
    auto s_b_5_12 = emitter.sx(s_b_5_11, emitter.context().types().s32());
    /* execute.simd:5398 [D] s_b_5_13 = s_b_5_9*s_b_5_12 */
    auto s_b_5_13 = emitter.mul(s_b_5_9, s_b_5_12);
    /* execute.simd:5398 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:5398 [D] s_b_5_15 = s_b_5_6[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int32_t, 4>(0)[0], emitter.context().types().v4s32()), emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* execute.simd:5398 [F] s_b_5_16 = constant u32 5 (const) */
    /* execute.simd:5398 [D] s_b_5_2[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5398 [D] s_b_5_18 = (s32)s_b_5_17 */
    auto s_b_5_18 = emitter.sx(s_b_5_17, emitter.context().types().s32());
    /* execute.simd:5398 [F] s_b_5_19 = constant u32 5 (const) */
    /* execute.simd:5398 [D] s_b_5_5[s_b_5_19] */
    auto s_b_5_20 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5398 [D] s_b_5_21 = (s32)s_b_5_20 */
    auto s_b_5_21 = emitter.sx(s_b_5_20, emitter.context().types().s32());
    /* execute.simd:5398 [D] s_b_5_22 = s_b_5_18*s_b_5_21 */
    auto s_b_5_22 = emitter.mul(s_b_5_18, s_b_5_21);
    /* execute.simd:5398 [F] s_b_5_23 = constant s32 1 (const) */
    /* execute.simd:5398 [D] s_b_5_24 = s_b_5_15[s_b_5_23] <= s_b_5_22 */
    auto s_b_5_24 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_22);
    /* execute.simd:5398 [F] s_b_5_25 = constant u32 6 (const) */
    /* execute.simd:5398 [D] s_b_5_2[s_b_5_25] */
    auto s_b_5_26 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5398 [D] s_b_5_27 = (s32)s_b_5_26 */
    auto s_b_5_27 = emitter.sx(s_b_5_26, emitter.context().types().s32());
    /* execute.simd:5398 [F] s_b_5_28 = constant u32 6 (const) */
    /* execute.simd:5398 [D] s_b_5_5[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5398 [D] s_b_5_30 = (s32)s_b_5_29 */
    auto s_b_5_30 = emitter.sx(s_b_5_29, emitter.context().types().s32());
    /* execute.simd:5398 [D] s_b_5_31 = s_b_5_27*s_b_5_30 */
    auto s_b_5_31 = emitter.mul(s_b_5_27, s_b_5_30);
    /* execute.simd:5398 [F] s_b_5_32 = constant s32 2 (const) */
    /* execute.simd:5398 [D] s_b_5_33 = s_b_5_24[s_b_5_32] <= s_b_5_31 */
    auto s_b_5_33 = emitter.vector_insert(s_b_5_24, emitter.const_s32((int32_t)2ULL), s_b_5_31);
    /* execute.simd:5398 [F] s_b_5_34 = constant u32 7 (const) */
    /* execute.simd:5398 [D] s_b_5_2[s_b_5_34] */
    auto s_b_5_35 = emitter.vector_extract(s_b_5_2, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5398 [D] s_b_5_36 = (s32)s_b_5_35 */
    auto s_b_5_36 = emitter.sx(s_b_5_35, emitter.context().types().s32());
    /* execute.simd:5398 [F] s_b_5_37 = constant u32 7 (const) */
    /* execute.simd:5398 [D] s_b_5_5[s_b_5_37] */
    auto s_b_5_38 = emitter.vector_extract(s_b_5_5, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5398 [D] s_b_5_39 = (s32)s_b_5_38 */
    auto s_b_5_39 = emitter.sx(s_b_5_38, emitter.context().types().s32());
    /* execute.simd:5398 [D] s_b_5_40 = s_b_5_36*s_b_5_39 */
    auto s_b_5_40 = emitter.mul(s_b_5_36, s_b_5_39);
    /* execute.simd:5398 [F] s_b_5_41 = constant s32 3 (const) */
    /* execute.simd:5398 [D] s_b_5_42 = s_b_5_33[s_b_5_41] <= s_b_5_40 */
    auto s_b_5_42 = emitter.vector_insert(s_b_5_33, emitter.const_s32((int32_t)3ULL), s_b_5_40);
    /* execute.simd:5401 [F] s_b_5_43=sym_24979_3_parameter_inst.rd (const) */
    /* execute.simd:5401 [D] s_b_5_44 = (v4u32)s_b_5_42 */
    auto s_b_5_44 = emitter.reinterpret(s_b_5_42, emitter.context().types().v4u32());
    /* execute.simd:5401 [D] s_b_5_45: WriteRegBank 20:s_b_5_43 = s_b_5_44 */
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
    /* execute.simd:5405 [F] s_b_6_0=sym_24979_3_parameter_inst.rn (const) */
    /* execute.simd:5405 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5405 [D] s_b_6_2 = (v2s32)s_b_6_1 */
    auto s_b_6_2 = emitter.reinterpret(s_b_6_1, emitter.context().types().v2s32());
    /* execute.simd:5406 [F] s_b_6_3=sym_24979_3_parameter_inst.rm (const) */
    /* execute.simd:5406 [D] s_b_6_4 = ReadRegBank 19:s_b_6_3 (v2u32) */
    auto s_b_6_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_6_4,emitter.const_u8(8));
    }
    /* execute.simd:5406 [D] s_b_6_5 = (v2s32)s_b_6_4 */
    auto s_b_6_5 = emitter.reinterpret(s_b_6_4, emitter.context().types().v2s32());
    /* ???:4294967295 [F] s_b_6_6 = constant v2s64 
    {
    }
    (const) */
    /* ???:4294967295 [F] s_b_6_7 = constant u8 0 (const) */
    /* execute.simd:5411 [D] s_b_6_2[s_b_6_7] */
    auto s_b_6_8 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5411 [D] s_b_6_9 = (s64)s_b_6_8 */
    auto s_b_6_9 = emitter.sx(s_b_6_8, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_10 = constant u8 0 (const) */
    /* execute.simd:5411 [D] s_b_6_5[s_b_6_10] */
    auto s_b_6_11 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5411 [D] s_b_6_12 = (s64)s_b_6_11 */
    auto s_b_6_12 = emitter.sx(s_b_6_11, emitter.context().types().s64());
    /* execute.simd:5411 [D] s_b_6_13 = s_b_6_9*s_b_6_12 */
    auto s_b_6_13 = emitter.mul(s_b_6_9, s_b_6_12);
    /* execute.simd:5411 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:5411 [D] s_b_6_15 = s_b_6_6[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* ???:4294967295 [F] s_b_6_16 = constant u8 1 (const) */
    /* execute.simd:5411 [D] s_b_6_2[s_b_6_16] */
    auto s_b_6_17 = emitter.vector_extract(s_b_6_2, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5411 [D] s_b_6_18 = (s64)s_b_6_17 */
    auto s_b_6_18 = emitter.sx(s_b_6_17, emitter.context().types().s64());
    /* ???:4294967295 [F] s_b_6_19 = constant u8 1 (const) */
    /* execute.simd:5411 [D] s_b_6_5[s_b_6_19] */
    auto s_b_6_20 = emitter.vector_extract(s_b_6_5, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5411 [D] s_b_6_21 = (s64)s_b_6_20 */
    auto s_b_6_21 = emitter.sx(s_b_6_20, emitter.context().types().s64());
    /* execute.simd:5411 [D] s_b_6_22 = s_b_6_18*s_b_6_21 */
    auto s_b_6_22 = emitter.mul(s_b_6_18, s_b_6_21);
    /* execute.simd:5411 [F] s_b_6_23 = constant s32 1 (const) */
    /* execute.simd:5411 [D] s_b_6_24 = s_b_6_15[s_b_6_23] <= s_b_6_22 */
    auto s_b_6_24 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), s_b_6_22);
    /* execute.simd:5414 [F] s_b_6_25=sym_24979_3_parameter_inst.rd (const) */
    /* execute.simd:5414 [D] s_b_6_26 = (v2u64)s_b_6_24 */
    auto s_b_6_26 = emitter.reinterpret(s_b_6_24, emitter.context().types().v2u64());
    /* execute.simd:5414 [D] s_b_6_27: WriteRegBank 21:s_b_6_25 = s_b_6_26 */
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
    /* execute.simd:5418 [F] s_b_7_0=sym_24979_3_parameter_inst.rn (const) */
    /* execute.simd:5418 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5418 [D] s_b_7_2 = (v4s32)s_b_7_1 */
    auto s_b_7_2 = emitter.reinterpret(s_b_7_1, emitter.context().types().v4s32());
    /* execute.simd:5419 [F] s_b_7_3=sym_24979_3_parameter_inst.rm (const) */
    /* execute.simd:5419 [D] s_b_7_4 = ReadRegBank 20:s_b_7_3 (v4u32) */
    auto s_b_7_4 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_4,emitter.const_u8(16));
    }
    /* execute.simd:5419 [D] s_b_7_5 = (v4s32)s_b_7_4 */
    auto s_b_7_5 = emitter.reinterpret(s_b_7_4, emitter.context().types().v4s32());
    /* ???:4294967295 [F] s_b_7_6 = constant v2s64 
    {
    }
    (const) */
    /* execute.simd:5424 [F] s_b_7_7 = constant u32 2 (const) */
    /* execute.simd:5424 [D] s_b_7_2[s_b_7_7] */
    auto s_b_7_8 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5424 [D] s_b_7_9 = (s64)s_b_7_8 */
    auto s_b_7_9 = emitter.sx(s_b_7_8, emitter.context().types().s64());
    /* execute.simd:5424 [F] s_b_7_10 = constant u32 2 (const) */
    /* execute.simd:5424 [D] s_b_7_5[s_b_7_10] */
    auto s_b_7_11 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5424 [D] s_b_7_12 = (s64)s_b_7_11 */
    auto s_b_7_12 = emitter.sx(s_b_7_11, emitter.context().types().s64());
    /* execute.simd:5424 [D] s_b_7_13 = s_b_7_9*s_b_7_12 */
    auto s_b_7_13 = emitter.mul(s_b_7_9, s_b_7_12);
    /* execute.simd:5424 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:5424 [D] s_b_7_15 = s_b_7_6[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<int64_t, 2>(0)[0], emitter.context().types().v2s64()), emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:5424 [F] s_b_7_16 = constant u32 3 (const) */
    /* execute.simd:5424 [D] s_b_7_2[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_2, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5424 [D] s_b_7_18 = (s64)s_b_7_17 */
    auto s_b_7_18 = emitter.sx(s_b_7_17, emitter.context().types().s64());
    /* execute.simd:5424 [F] s_b_7_19 = constant u32 3 (const) */
    /* execute.simd:5424 [D] s_b_7_5[s_b_7_19] */
    auto s_b_7_20 = emitter.vector_extract(s_b_7_5, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5424 [D] s_b_7_21 = (s64)s_b_7_20 */
    auto s_b_7_21 = emitter.sx(s_b_7_20, emitter.context().types().s64());
    /* execute.simd:5424 [D] s_b_7_22 = s_b_7_18*s_b_7_21 */
    auto s_b_7_22 = emitter.mul(s_b_7_18, s_b_7_21);
    /* execute.simd:5424 [F] s_b_7_23 = constant s32 1 (const) */
    /* execute.simd:5424 [D] s_b_7_24 = s_b_7_15[s_b_7_23] <= s_b_7_22 */
    auto s_b_7_24 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_22);
    /* execute.simd:5427 [F] s_b_7_25=sym_24979_3_parameter_inst.rd (const) */
    /* execute.simd:5427 [D] s_b_7_26 = (v2u64)s_b_7_24 */
    auto s_b_7_26 = emitter.reinterpret(s_b_7_24, emitter.context().types().v2u64());
    /* execute.simd:5427 [D] s_b_7_27: WriteRegBank 21:s_b_7_25 = s_b_7_26 */
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
    /* execute.simd:5431 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5351 [F] s_b_8_1: Jump b_1 (const) */
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
  auto DV_sym_135389_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_135372_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_30682_0_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:2838 [F] s_b_0_0=sym_30676_3_parameter_inst.rn (const) */
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
  /* b_2, b_3, b_5, b_6, b_7, b_10,  */
  fixed_block_b_1: 
  {
    /* ???:4294967295 [F] s_b_1_0: Return */
    goto fixed_done;
  }
  /* b_10,  */
  fixed_block_b_2: 
  {
    /* execute.simd:2842 [F] s_b_2_0=sym_30676_3_parameter_inst.rt (const) */
    /* execute.simd:2842 [D] s_b_2_1 = ReadRegBank 16:s_b_2_0 (v16u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_2_1,emitter.const_u8(16));
    }
    /* execute.simd:2843 [D] s_b_2_2 = sym_30682_0_addr uint64_t */
    auto s_b_2_2 = emitter.load_local(DV_sym_30682_0_addr, emitter.context().types().u64());
    /* execute.simd:2843 [F] s_b_2_3=sym_30676_3_parameter_inst.eindex (const) */
    /* execute.simd:2843 [D] s_b_2_1[s_b_2_3] */
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
    /* execute.simd:2847 [F] s_b_3_0=sym_30676_3_parameter_inst.rt (const) */
    /* execute.simd:2847 [D] s_b_3_1 = ReadRegBank 18:s_b_3_0 (v8u16) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:2848 [D] s_b_3_2 = sym_30682_0_addr uint64_t */
    auto s_b_3_2 = emitter.load_local(DV_sym_30682_0_addr, emitter.context().types().u64());
    /* execute.simd:2848 [F] s_b_3_3=sym_30676_3_parameter_inst.eindex (const) */
    /* execute.simd:2848 [D] s_b_3_1[s_b_3_3] */
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
    /* execute.simd:2852 [F] s_b_4_0=sym_30676_3_parameter_inst.size (const) */
    /* execute.simd:2852 [F] s_b_4_1 = (u32)s_b_4_0 (const) */
    /* execute.simd:2852 [F] s_b_4_2 = constant u32 0 (const) */
    /* execute.simd:2852 [F] s_b_4_3 = s_b_4_1==s_b_4_2 (const) */
    uint8_t s_b_4_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:2852 [F] s_b_4_4: If s_b_4_3: Jump b_5 else b_6 (const) */
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
    /* execute.simd:2853 [F] s_b_5_0=sym_30676_3_parameter_inst.rt (const) */
    /* execute.simd:2853 [D] s_b_5_1 = ReadRegBank 20:s_b_5_0 (v4u32) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:2854 [D] s_b_5_2 = sym_30682_0_addr uint64_t */
    auto s_b_5_2 = emitter.load_local(DV_sym_30682_0_addr, emitter.context().types().u64());
    /* execute.simd:2854 [F] s_b_5_3=sym_30676_3_parameter_inst.eindex (const) */
    /* execute.simd:2854 [D] s_b_5_1[s_b_5_3] */
    auto s_b_5_4 = emitter.vector_extract(s_b_5_1, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_5_5: Store 4 s_b_5_2 <= s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_5_2, s_b_5_4, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_5_2, s_b_5_4);
    /* execute.simd:2853 [F] s_b_5_6: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_4,  */
  fixed_block_b_6: 
  {
    /* execute.simd:2855 [F] s_b_6_0=sym_30676_3_parameter_inst.size (const) */
    /* execute.simd:2855 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.simd:2855 [F] s_b_6_2 = constant u32 1 (const) */
    /* execute.simd:2855 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:2855 [F] s_b_6_4: If s_b_6_3: Jump b_7 else b_1 (const) */
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
    /* execute.simd:2856 [F] s_b_7_0=sym_30676_3_parameter_inst.rt (const) */
    /* execute.simd:2856 [D] s_b_7_1 = ReadRegBank 21:s_b_7_0 (v2u64) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:2857 [D] s_b_7_2 = sym_30682_0_addr uint64_t */
    auto s_b_7_2 = emitter.load_local(DV_sym_30682_0_addr, emitter.context().types().u64());
    /* execute.simd:2857 [F] s_b_7_3=sym_30676_3_parameter_inst.eindex (const) */
    /* execute.simd:2857 [D] s_b_7_1[s_b_7_3] */
    auto s_b_7_4 = emitter.vector_extract(s_b_7_1, emitter.const_u8(insn.eindex));
    /* ???:4294967295 [D] s_b_7_5: Store 8 s_b_7_2 <= s_b_7_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_7_2, s_b_7_4, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_7_2, s_b_7_4);
    /* execute.simd:2856 [F] s_b_7_6: Jump b_1 (const) */
    goto fixed_block_b_1;
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
    /* execute.a64:2796 [F] s_b_9_0=sym_30676_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_9_1 = ReadRegBank 0:s_b_9_0 (u64) */
    auto s_b_9_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_9_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_9_2: sym_135372_0_return_symbol = s_b_9_1, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_135372_0_return_symbol, s_b_9_1);
    /* ???:4294967295 [F] s_b_9_3: Jump b_10 (const) */
    goto fixed_block_b_10;
  }
  /* b_9, b_13,  */
  fixed_block_b_10: 
  {
    /* ???:4294967295 [D] s_b_10_0 = sym_135372_0_return_symbol uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_135372_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:2838 [D] s_b_10_1: sym_30682_0_addr = s_b_10_0, dominates: s_b_2_2 s_b_3_2 s_b_5_2 s_b_7_2  */
    emitter.store_local(DV_sym_30682_0_addr, s_b_10_0);
    /* execute.simd:2840 [F] s_b_10_2=sym_30676_3_parameter_inst.opcode (const) */
    /* execute.simd:2841 [F] s_b_10_3 = constant s32 0 (const) */
    /* execute.simd:2846 [F] s_b_10_4 = constant s32 2 (const) */
    /* execute.simd:2851 [F] s_b_10_5 = constant s32 4 (const) */
    /* execute.simd:2840 [F] s_b_10_6: Switch s_b_10_2: < <todo> > def b_1 (const) -> b_1, b_2, b_3, b_4,  */
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
    /* execute.a64:2765 [D] s_b_11_0 = ReadReg 21 (u64) */
    auto s_b_11_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_11_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_11_1: sym_135389_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_135389_1__R_s_b_3_0, s_b_11_0);
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
    /* execute.a64:2794 [D] s_b_13_0 = sym_135389_1__R_s_b_3_0 uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_135389_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1: sym_135372_0_return_symbol = s_b_13_0, dominates: s_b_10_0  */
    emitter.store_local(DV_sym_135372_0_return_symbol, s_b_13_0);
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
    /* execute.a64:2768 [D] s_b_14_1: sym_135389_1__R_s_b_3_0 = s_b_14_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_135389_1__R_s_b_3_0, s_b_14_0);
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
    /* execute.a64:2770 [D] s_b_15_1: sym_135389_1__R_s_b_3_0 = s_b_15_0, dominates: s_b_13_0  */
    emitter.store_local(DV_sym_135389_1__R_s_b_3_0, s_b_15_0);
    /* execute.a64:2770 [F] s_b_15_2: Jump b_13 (const) */
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
  auto DV_sym_137863_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137880_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_138196_1_tmp_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_137984_1_tmp_s_b_4_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_138056_1_temporary_value;
  auto DV_sym_138056_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_31282_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_138270_1_temporary_value;
  auto DV_sym_138270_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:904 [F] s_b_0_0=sym_31276_3_parameter_inst.rn (const) */
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
    /* execute.a64:907 [D] s_b_1_0 = sym_31282_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31282_0_address, emitter.context().types().u64());
    /* execute.a64:907 [F] s_b_1_1=sym_31276_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_1_2: sym_137984_1_tmp_s_b_4_0 = s_b_1_0, dominates: s_b_14_2  */
    emitter.store_local(DV_sym_137984_1_tmp_s_b_4_0, s_b_1_0);
    /* execute.a64:2709 [F] s_b_1_3 = (u32)s_b_1_1 (const) */
    /* execute.a64:2709 [F] s_b_1_4 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_1_5 = s_b_1_3==s_b_1_4 (const) */
    uint8_t s_b_1_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_1_6: If s_b_1_5: Jump b_12 else b_13 (const) */
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
    /* execute.a64:909 [D] s_b_3_0 = sym_31282_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_31282_0_address, emitter.context().types().u64());
    /* execute.a64:909 [F] s_b_3_1=sym_31276_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_3_2: sym_138196_1_tmp_s_b_5_0 = s_b_3_0, dominates: s_b_17_1  */
    emitter.store_local(DV_sym_138196_1_tmp_s_b_5_0, s_b_3_0);
    /* execute.a64:2714 [F] s_b_3_3 = (u32)s_b_3_1 (const) */
    /* execute.a64:2714 [F] s_b_3_4 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_3_5 = s_b_3_3==s_b_3_4 (const) */
    uint8_t s_b_3_5 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_3_6: If s_b_3_5: Jump b_15 else b_16 (const) */
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
    /* execute.a64:2796 [F] s_b_5_0=sym_31276_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_137863_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_137863_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_137863_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_137863_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:904 [D] s_b_6_1: sym_31282_0_address = s_b_6_0, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_31282_0_address, s_b_6_0);
    /* execute.a64:906 [F] s_b_6_2=sym_31276_3_parameter_inst.size (const) */
    /* execute.a64:906 [F] s_b_6_3 = (u32)s_b_6_2 (const) */
    /* execute.a64:906 [F] s_b_6_4 = constant u32 2 (const) */
    /* execute.a64:906 [F] s_b_6_5 = s_b_6_3==s_b_6_4 (const) */
    uint8_t s_b_6_5 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)2ULL));
    /* execute.a64:906 [F] s_b_6_6: If s_b_6_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2765 [D] s_b_7_0 = ReadReg 21 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_7_1: sym_137880_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_137880_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2794 [D] s_b_9_0 = sym_137880_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_137880_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_137863_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_137863_0_return_symbol, s_b_9_0);
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
    /* execute.a64:2768 [D] s_b_10_1: sym_137880_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_137880_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2770 [D] s_b_11_1: sym_137880_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_137880_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_1,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [F] s_b_12_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_12_1: sym_138056_1_temporary_value = s_b_12_0 (const), dominates: s_b_14_0  */
    CV_sym_138056_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_138056_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_12_2: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_1,  */
  fixed_block_b_13: 
  {
    /* execute.a64:2709 [F] s_b_13_0=sym_31276_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_13_1 = ReadRegBank 1:s_b_13_0 (u32) */
    auto s_b_13_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_13_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_13_2: sym_138056_1_temporary_value = s_b_13_1, dominates: s_b_14_0  */
    emitter.store_local(DV_sym_138056_1_temporary_value, s_b_13_1);
    /* execute.a64:2709 [F] s_b_13_3: Jump b_14 (const) */
    goto fixed_block_b_14;
  }
  /* b_12, b_13,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2709 [D] s_b_14_0 = sym_138056_1_temporary_value uint32_t */
    auto s_b_14_0 = emitter.load_local(DV_sym_138056_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_14_1 = (u64)s_b_14_0 */
    auto s_b_14_1 = emitter.zx(s_b_14_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_14_2 = sym_137984_1_tmp_s_b_4_0 uint64_t */
    auto s_b_14_2 = emitter.load_local(DV_sym_137984_1_tmp_s_b_4_0, emitter.context().types().u64());
    /* execute.a64:1855 [D] s_b_14_3 = (u32)s_b_14_1 */
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
    /* execute.a64:2714 [F] s_b_15_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_15_1: sym_138270_1_temporary_value = s_b_15_0 (const), dominates: s_b_17_0  */
    CV_sym_138270_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_138270_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_15_2: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_3,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2714 [F] s_b_16_0=sym_31276_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_16_1 = ReadRegBank 0:s_b_16_0 (u64) */
    auto s_b_16_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_16_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_16_2: sym_138270_1_temporary_value = s_b_16_1, dominates: s_b_17_0  */
    emitter.store_local(DV_sym_138270_1_temporary_value, s_b_16_1);
    /* execute.a64:2714 [F] s_b_16_3: Jump b_17 (const) */
    goto fixed_block_b_17;
  }
  /* b_15, b_16,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2714 [D] s_b_17_0 = sym_138270_1_temporary_value uint64_t */
    auto s_b_17_0 = emitter.load_local(DV_sym_138270_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_17_1 = sym_138196_1_tmp_s_b_5_0 uint64_t */
    auto s_b_17_1 = emitter.load_local(DV_sym_138196_1_tmp_s_b_5_0, emitter.context().types().u64());
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
  uint64_t CV_sym_142803_1_temporary_value;
  auto DV_sym_142803_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_142877_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_142868_1_temporary_value;
  auto DV_sym_142868_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_142882_1_temporary_value;
  auto DV_sym_142882_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_142812_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_142690_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_142707_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31693_0_address = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31707_0_data1 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_31716_0_data2 = emitter.alloc_local(emitter.context().types().u64(), false);
  int64_t CV_sym_142778_1_tmp_s_b_14_5;
  uint32_t CV_sym_142817_1_temporary_value;
  auto DV_sym_142817_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1560 [F] s_b_0_0=sym_31661_3_parameter_inst.opc (const) */
    /* execute.a64:1560 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1560 [F] s_b_0_2 = constant u32 1 (const) */
    /* execute.a64:1560 [F] s_b_0_3 = s_b_0_1>>s_b_0_2 (const) */
    uint32_t s_b_0_3 = ((uint32_t)(((uint32_t)insn.opc) >> (uint32_t)1ULL));
    /* execute.a64:1560 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:1560 [F] s_b_0_5 = s_b_0_3&s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(s_b_0_3 & (uint32_t)1ULL));
    /* execute.a64:1560 [F] s_b_0_6 = constant u32 2 (const) */
    /* execute.a64:1560 [F] s_b_0_7 = s_b_0_6+s_b_0_5 (const) */
    uint32_t s_b_0_7 = ((uint32_t)((uint32_t)2ULL + s_b_0_5));
    /* execute.a64:1560 [F] s_b_0_8 = (u8)s_b_0_7 (const) */
    /* execute.a64:1561 [F] s_b_0_9=sym_31661_3_parameter_inst.imm7 (const) */
    /* execute.a64:1561 [F] s_b_0_10 = (u64)s_b_0_9 (const) */
    /* execute.a64:2848 [F] s_b_0_11 = (s64)s_b_0_10 (const) */
    /* execute.a64:2848 [F] s_b_0_12 = constant s64 39 (const) */
    /* execute.a64:2848 [F] s_b_0_13 = s_b_0_11<<s_b_0_12 (const) */
    int64_t s_b_0_13 = ((int64_t)(((int64_t)((uint64_t)insn.imm7)) << (int64_t)57ULL));
    /* execute.a64:2848 [F] s_b_0_14 = (s64)s_b_0_13 (const) */
    /* execute.a64:2848 [F] s_b_0_15 = constant s64 39 (const) */
    /* execute.a64:2848 [F] s_b_0_16 = s_b_0_14->>s_b_0_15 (const) */
    int64_t s_b_0_16 = ((int64_t)(((int64_t)s_b_0_13) >> (int64_t)57ULL));
    /* execute.a64:1561 [F] s_b_0_17 = (u64)s_b_0_16 (const) */
    /* execute.a64:1561 [F] s_b_0_18 = (u64)s_b_0_8 (const) */
    /* execute.a64:1561 [F] s_b_0_19 = s_b_0_17<<s_b_0_18 (const) */
    uint64_t s_b_0_19 = ((uint64_t)(((uint64_t)s_b_0_16) << ((uint64_t)((uint8_t)s_b_0_7))));
    /* execute.a64:1561 [F] s_b_0_20 = (s64)s_b_0_19 (const) */
    /* execute.a64:1563 [F] s_b_0_21=sym_31661_3_parameter_inst.rn (const) */
    /* ???:4294967295 [F] s_b_0_22: sym_142778_1_tmp_s_b_14_5 = s_b_0_20 (const), dominates: s_b_6_1  */
    CV_sym_142778_1_tmp_s_b_14_5 = ((int64_t)s_b_0_19);
    /* execute.a64:2793 [F] s_b_0_23 = (u32)s_b_0_21 (const) */
    /* execute.a64:2793 [F] s_b_0_24 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_0_25 = s_b_0_23==s_b_0_24 (const) */
    uint8_t s_b_0_25 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_0_26: If s_b_0_25: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1570 [D] s_b_1_0 = sym_31693_0_address uint64_t */
    auto s_b_1_0 = emitter.load_local(DV_sym_31693_0_address, emitter.context().types().u64());
    /* execute.a64:1570 [D] s_b_1_1 = sym_31707_0_data1 uint64_t */
    auto s_b_1_1 = emitter.load_local(DV_sym_31707_0_data1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_2: Store 8 s_b_1_0 <= s_b_1_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_1_0, s_b_1_1, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_1_0, s_b_1_1);
    /* execute.a64:1571 [F] s_b_1_3 = constant u64 8 (const) */
    /* execute.a64:1571 [D] s_b_1_4 = s_b_1_0+s_b_1_3 */
    auto s_b_1_4 = emitter.add(s_b_1_0, emitter.const_u64((uint64_t)8ULL));
    /* execute.a64:1571 [D] s_b_1_5 = sym_31716_0_data2 uint64_t */
    auto s_b_1_5 = emitter.load_local(DV_sym_31716_0_data2, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_1_6: Store 8 s_b_1_4 <= s_b_1_5 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_1_4, s_b_1_5, emitter.const_u8(8));
    }
    emitter.store_memory(s_b_1_4, s_b_1_5);
    /* execute.a64:1570 [F] s_b_1_7: Jump b_2 (const) */
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
    /* execute.a64:1573 [D] s_b_3_0 = sym_31693_0_address uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_31693_0_address, emitter.context().types().u64());
    /* execute.a64:1573 [D] s_b_3_1 = sym_31707_0_data1 uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_31707_0_data1, emitter.context().types().u64());
    /* execute.a64:1573 [D] s_b_3_2 = (u32)s_b_3_1 */
    auto s_b_3_2 = emitter.truncate(s_b_3_1, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_3_3: Store 4 s_b_3_0 <= s_b_3_2 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_0, s_b_3_2, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_3_0, s_b_3_2);
    /* execute.a64:1574 [F] s_b_3_4 = constant u64 4 (const) */
    /* execute.a64:1574 [D] s_b_3_5 = s_b_3_0+s_b_3_4 */
    auto s_b_3_5 = emitter.add(s_b_3_0, emitter.const_u64((uint64_t)4ULL));
    /* execute.a64:1574 [D] s_b_3_6 = sym_31716_0_data2 uint64_t */
    auto s_b_3_6 = emitter.load_local(DV_sym_31716_0_data2, emitter.context().types().u64());
    /* execute.a64:1574 [D] s_b_3_7 = (u32)s_b_3_6 */
    auto s_b_3_7 = emitter.truncate(s_b_3_6, emitter.context().types().u32());
    /* ???:4294967295 [D] s_b_3_8: Store 4 s_b_3_5 <= s_b_3_7 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_MEMORY, s_b_3_5, s_b_3_7, emitter.const_u8(4));
    }
    emitter.store_memory(s_b_3_5, s_b_3_7);
    /* execute.a64:1573 [F] s_b_3_9: Jump b_2 (const) */
    goto fixed_block_b_2;
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
    /* execute.a64:2796 [F] s_b_5_0=sym_31661_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_5_1 = ReadRegBank 0:s_b_5_0 (u64) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_5_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_5_2: sym_142690_0_return_symbol = s_b_5_1, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_142690_0_return_symbol, s_b_5_1);
    /* ???:4294967295 [F] s_b_5_3: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_5, b_9,  */
  fixed_block_b_6: 
  {
    /* ???:4294967295 [D] s_b_6_0 = sym_142690_0_return_symbol uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_142690_0_return_symbol, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_1 = sym_142778_1_tmp_s_b_14_5 (const) int64_t */
    int64_t s_b_6_1 = CV_sym_142778_1_tmp_s_b_14_5;
    /* execute.a64:1563 [D] s_b_6_2: sym_31693_0_address = s_b_6_0, dominates:  */
    emitter.store_local(DV_sym_31693_0_address, s_b_6_0);
    /* ???:4294967295 [F] s_b_6_3 = (u64)s_b_6_1 (const) */
    /* ???:4294967295 [D] s_b_6_4 = s_b_6_0+s_b_6_3 */
    auto s_b_6_4 = emitter.add(s_b_6_0, emitter.const_u64(((uint64_t)s_b_6_1)));
    /* execute.a64:1564 [D] s_b_6_5: sym_31693_0_address = s_b_6_4, dominates: s_b_1_0 s_b_3_0  */
    emitter.store_local(DV_sym_31693_0_address, s_b_6_4);
    /* execute.a64:1566 [F] s_b_6_6=sym_31661_3_parameter_inst.opc (const) */
    /* execute.a64:1566 [F] s_b_6_7 = (u32)s_b_6_6 (const) */
    /* execute.a64:1566 [F] s_b_6_8 = constant u32 2 (const) */
    /* execute.a64:1566 [F] s_b_6_9 = s_b_6_7==s_b_6_8 (const) */
    uint8_t s_b_6_9 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:2719 [F] s_b_6_10: If s_b_6_9: Jump b_12 else b_15 (const) */
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
    /* execute.a64:2765 [D] s_b_7_0 = ReadReg 21 (u64) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_7_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_7_1: sym_142707_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_142707_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2794 [D] s_b_9_0 = sym_142707_1__R_s_b_3_0 uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_142707_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1: sym_142690_0_return_symbol = s_b_9_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_142690_0_return_symbol, s_b_9_0);
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
    /* execute.a64:2768 [D] s_b_10_1: sym_142707_1__R_s_b_3_0 = s_b_10_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_142707_1__R_s_b_3_0, s_b_10_0);
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
    /* execute.a64:2770 [D] s_b_11_1: sym_142707_1__R_s_b_3_0 = s_b_11_0, dominates: s_b_9_0  */
    emitter.store_local(DV_sym_142707_1__R_s_b_3_0, s_b_11_0);
    /* execute.a64:2770 [F] s_b_11_2: Jump b_9 (const) */
    goto fixed_block_b_9;
  }
  /* b_6,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2720 [F] s_b_12_0=sym_31661_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [F] s_b_12_1 = (u32)s_b_12_0 (const) */
    /* execute.a64:2714 [F] s_b_12_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_12_3 = s_b_12_1==s_b_12_2 (const) */
    uint8_t s_b_12_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_12_4: If s_b_12_3: Jump b_13 else b_14 (const) */
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
    /* execute.a64:2714 [F] s_b_13_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_13_1: sym_142803_1_temporary_value = s_b_13_0 (const), dominates: s_b_18_0  */
    CV_sym_142803_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_142803_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_13_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_12,  */
  fixed_block_b_14: 
  {
    /* execute.a64:2714 [F] s_b_14_0=sym_31661_3_parameter_inst.rt (const) */
    /* execute.a64:2714 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_14_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_14_2: sym_142803_1_temporary_value = s_b_14_1, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_142803_1_temporary_value, s_b_14_1);
    /* execute.a64:2714 [F] s_b_14_3: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_6,  */
  fixed_block_b_15: 
  {
    /* execute.a64:2722 [F] s_b_15_0=sym_31661_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [F] s_b_15_1 = (u32)s_b_15_0 (const) */
    /* execute.a64:2709 [F] s_b_15_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_15_3 = s_b_15_1==s_b_15_2 (const) */
    uint8_t s_b_15_3 = ((uint8_t)(((uint32_t)insn.rt) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_15_4: If s_b_15_3: Jump b_16 else b_17 (const) */
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
    /* execute.a64:2709 [F] s_b_16_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_16_1: sym_142817_1_temporary_value = s_b_16_0 (const), dominates: s_b_20_0  */
    CV_sym_142817_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_142817_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_16_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_15,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2709 [F] s_b_17_0=sym_31661_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_17_1 = ReadRegBank 1:s_b_17_0 (u32) */
    auto s_b_17_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_17_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_17_2: sym_142817_1_temporary_value = s_b_17_1, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_142817_1_temporary_value, s_b_17_1);
    /* execute.a64:2709 [F] s_b_17_3: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_13, b_14,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2714 [D] s_b_18_0 = sym_142803_1_temporary_value uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_142803_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1: sym_142812_0_return_symbol = s_b_18_0, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_142812_0_return_symbol, s_b_18_0);
    /* ???:4294967295 [F] s_b_18_2: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_18, b_20,  */
  fixed_block_b_19: 
  {
    /* ???:4294967295 [D] s_b_19_0 = sym_142812_0_return_symbol uint64_t */
    auto s_b_19_0 = emitter.load_local(DV_sym_142812_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1566 [D] s_b_19_1: sym_31707_0_data1 = s_b_19_0, dominates: s_b_1_1 s_b_3_1  */
    emitter.store_local(DV_sym_31707_0_data1, s_b_19_0);
    /* execute.a64:1567 [F] s_b_19_2=sym_31661_3_parameter_inst.opc (const) */
    /* execute.a64:1567 [F] s_b_19_3 = (u32)s_b_19_2 (const) */
    /* execute.a64:1567 [F] s_b_19_4 = constant u32 2 (const) */
    /* execute.a64:1567 [F] s_b_19_5 = s_b_19_3==s_b_19_4 (const) */
    uint8_t s_b_19_5 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:2719 [F] s_b_19_6: If s_b_19_5: Jump b_21 else b_24 (const) */
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
    /* execute.a64:2709 [D] s_b_20_0 = sym_142817_1_temporary_value uint32_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_142817_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_20_1 = (u64)s_b_20_0 */
    auto s_b_20_1 = emitter.zx(s_b_20_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_2: sym_142812_0_return_symbol = s_b_20_1, dominates: s_b_19_0  */
    emitter.store_local(DV_sym_142812_0_return_symbol, s_b_20_1);
    /* ???:4294967295 [F] s_b_20_3: Jump b_19 (const) */
    goto fixed_block_b_19;
  }
  /* b_19,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2720 [F] s_b_21_0=sym_31661_3_parameter_inst.rt2 (const) */
    /* execute.a64:2714 [F] s_b_21_1 = (u32)s_b_21_0 (const) */
    /* execute.a64:2714 [F] s_b_21_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_21_3 = s_b_21_1==s_b_21_2 (const) */
    uint8_t s_b_21_3 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_21_4: If s_b_21_3: Jump b_22 else b_23 (const) */
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
    /* execute.a64:2714 [F] s_b_22_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_22_1: sym_142868_1_temporary_value = s_b_22_0 (const), dominates: s_b_27_0  */
    CV_sym_142868_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_142868_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_22_2: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_21,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2714 [F] s_b_23_0=sym_31661_3_parameter_inst.rt2 (const) */
    /* execute.a64:2714 [D] s_b_23_1 = ReadRegBank 0:s_b_23_0 (u64) */
    auto s_b_23_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_23_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_23_2: sym_142868_1_temporary_value = s_b_23_1, dominates: s_b_27_0  */
    emitter.store_local(DV_sym_142868_1_temporary_value, s_b_23_1);
    /* execute.a64:2714 [F] s_b_23_3: Jump b_27 (const) */
    goto fixed_block_b_27;
  }
  /* b_19,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2722 [F] s_b_24_0=sym_31661_3_parameter_inst.rt2 (const) */
    /* execute.a64:2709 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
    /* execute.a64:2709 [F] s_b_24_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(((uint32_t)insn.rt2) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_24_4: If s_b_24_3: Jump b_25 else b_26 (const) */
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
    /* execute.a64:2709 [F] s_b_25_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_25_1: sym_142882_1_temporary_value = s_b_25_0 (const), dominates: s_b_29_0  */
    CV_sym_142882_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_142882_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_25_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_24,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2709 [F] s_b_26_0=sym_31661_3_parameter_inst.rt2 (const) */
    /* execute.a64:2709 [D] s_b_26_1 = ReadRegBank 1:s_b_26_0 (u32) */
    auto s_b_26_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt2))),s_b_26_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_26_2: sym_142882_1_temporary_value = s_b_26_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_142882_1_temporary_value, s_b_26_1);
    /* execute.a64:2709 [F] s_b_26_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_22, b_23,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2714 [D] s_b_27_0 = sym_142868_1_temporary_value uint64_t */
    auto s_b_27_0 = emitter.load_local(DV_sym_142868_1_temporary_value, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_27_1: sym_142877_0_return_symbol = s_b_27_0, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_142877_0_return_symbol, s_b_27_0);
    /* ???:4294967295 [F] s_b_27_2: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_29,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_142877_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_142877_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1567 [D] s_b_28_1: sym_31716_0_data2 = s_b_28_0, dominates: s_b_1_5 s_b_3_6  */
    emitter.store_local(DV_sym_31716_0_data2, s_b_28_0);
    /* execute.a64:1569 [F] s_b_28_2=sym_31661_3_parameter_inst.opc (const) */
    /* execute.a64:1569 [F] s_b_28_3 = (u32)s_b_28_2 (const) */
    /* execute.a64:1569 [F] s_b_28_4 = constant u32 2 (const) */
    /* execute.a64:1569 [F] s_b_28_5 = s_b_28_3==s_b_28_4 (const) */
    uint8_t s_b_28_5 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)2ULL));
    /* execute.a64:1569 [F] s_b_28_6: If s_b_28_5: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2709 [D] s_b_29_0 = sym_142882_1_temporary_value uint32_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_142882_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_29_1 = (u64)s_b_29_0 */
    auto s_b_29_1 = emitter.zx(s_b_29_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_29_2: sym_142877_0_return_symbol = s_b_29_1, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_142877_0_return_symbol, s_b_29_1);
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
  uint64_t CV_sym_32549_0_rm;
  auto DV_sym_32549_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_147291_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_147218_1_temporary_value;
  auto DV_sym_147218_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint32_t CV_sym_147896_1_temporary_value;
  auto DV_sym_147896_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_147925_1_tmp_s_b_52_2 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_147491_1_temporary_value;
  auto DV_sym_147491_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  uint64_t CV_sym_147645_1_temporary_value;
  auto DV_sym_147645_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_147811_1_temporary_value;
  auto DV_sym_147811_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_147274_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1172 [F] s_b_0_0=sym_32522_3_parameter_inst.option0 (const) */
    /* execute.a64:1172 [F] s_b_0_1 = (u32)s_b_0_0 (const) */
    /* execute.a64:1172 [F] s_b_0_2 = constant u32 0 (const) */
    /* execute.a64:1172 [F] s_b_0_3 = s_b_0_1==s_b_0_2 (const) */
    uint8_t s_b_0_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1172 [F] s_b_0_4=sym_32522_3_parameter_inst.option21 (const) */
    /* execute.a64:1172 [F] s_b_0_5 = (u32)s_b_0_4 (const) */
    /* execute.a64:1172 [F] s_b_0_6 = constant u32 1 (const) */
    /* execute.a64:1172 [F] s_b_0_7 = s_b_0_5==s_b_0_6 (const) */
    uint8_t s_b_0_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_0_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_0_9 = s_b_0_3!=s_b_0_8 (const) */
    uint8_t s_b_0_9 = ((uint8_t)(s_b_0_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_10 = s_b_0_7!=s_b_0_8 (const) */
    uint8_t s_b_0_10 = ((uint8_t)(s_b_0_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_0_11 = s_b_0_9&s_b_0_10 (const) */
    uint8_t s_b_0_11 = ((uint8_t)(s_b_0_9 & s_b_0_10));
    /* execute.a64:1172 [F] s_b_0_12: If s_b_0_11: Jump b_1 else b_3 (const) */
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
    /* execute.a64:1173 [F] s_b_1_0=sym_32522_3_parameter_inst.rm (const) */
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
    /* execute.a64:1185 [F] s_b_2_0=sym_32522_3_parameter_inst.rn (const) */
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
    /* execute.a64:1174 [F] s_b_3_0=sym_32522_3_parameter_inst.option0 (const) */
    /* execute.a64:1174 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.a64:1174 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.a64:1174 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)0ULL));
    /* execute.a64:1174 [F] s_b_3_4=sym_32522_3_parameter_inst.option21 (const) */
    /* execute.a64:1174 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.a64:1174 [F] s_b_3_6 = constant u32 3 (const) */
    /* execute.a64:1174 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.a64:1174 [F] s_b_3_12: If s_b_3_11: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1175 [F] s_b_4_0=sym_32522_3_parameter_inst.rm (const) */
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
    /* execute.a64:1176 [F] s_b_5_0=sym_32522_3_parameter_inst.option0 (const) */
    /* execute.a64:1176 [F] s_b_5_1 = (u32)s_b_5_0 (const) */
    /* execute.a64:1176 [F] s_b_5_2 = constant u32 1 (const) */
    /* execute.a64:1176 [F] s_b_5_3 = s_b_5_1==s_b_5_2 (const) */
    uint8_t s_b_5_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1176 [F] s_b_5_4=sym_32522_3_parameter_inst.option21 (const) */
    /* execute.a64:1176 [F] s_b_5_5 = (u32)s_b_5_4 (const) */
    /* execute.a64:1176 [F] s_b_5_6 = constant u32 1 (const) */
    /* execute.a64:1176 [F] s_b_5_7 = s_b_5_5==s_b_5_6 (const) */
    uint8_t s_b_5_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_5_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_5_9 = s_b_5_3!=s_b_5_8 (const) */
    uint8_t s_b_5_9 = ((uint8_t)(s_b_5_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_10 = s_b_5_7!=s_b_5_8 (const) */
    uint8_t s_b_5_10 = ((uint8_t)(s_b_5_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_5_11 = s_b_5_9&s_b_5_10 (const) */
    uint8_t s_b_5_11 = ((uint8_t)(s_b_5_9 & s_b_5_10));
    /* execute.a64:1176 [F] s_b_5_12: If s_b_5_11: Jump b_6 else b_7 (const) */
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
    /* execute.a64:1177 [F] s_b_6_0=sym_32522_3_parameter_inst.rm (const) */
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
    /* execute.a64:1178 [F] s_b_7_0=sym_32522_3_parameter_inst.option0 (const) */
    /* execute.a64:1178 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.a64:1178 [F] s_b_7_2 = constant u32 1 (const) */
    /* execute.a64:1178 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.option0) == (uint32_t)1ULL));
    /* execute.a64:1178 [F] s_b_7_4=sym_32522_3_parameter_inst.option21 (const) */
    /* execute.a64:1178 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.a64:1178 [F] s_b_7_6 = constant u32 3 (const) */
    /* execute.a64:1178 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.option21) == (uint32_t)3ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.a64:1178 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.a64:1179 [F] s_b_8_0=sym_32522_3_parameter_inst.rm (const) */
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
    /* execute.a64:1181 [F] s_b_9_0 = constant u64 0 (const) */
    /* execute.a64:1181 [F] s_b_9_1: sym_32549_0_rm = s_b_9_0 (const), dominates: s_b_15_1  */
    CV_sym_32549_0_rm = (uint64_t)0ULL;
    emitter.store_local(DV_sym_32549_0_rm, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:1182 [D] s_b_9_2 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:1181 [F] s_b_9_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_1,  */
  fixed_block_b_10: 
  {
    /* execute.a64:2709 [F] s_b_10_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_10_1: sym_147218_1_temporary_value = s_b_10_0 (const), dominates: s_b_12_0  */
    CV_sym_147218_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_147218_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_10_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_1,  */
  fixed_block_b_11: 
  {
    /* execute.a64:2709 [F] s_b_11_0=sym_32522_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_11_1 = ReadRegBank 1:s_b_11_0 (u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_11_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_11_2: sym_147218_1_temporary_value = s_b_11_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_147218_1_temporary_value, s_b_11_1);
    /* execute.a64:2709 [F] s_b_11_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_10, b_11,  */
  fixed_block_b_12: 
  {
    /* execute.a64:2709 [D] s_b_12_0 = sym_147218_1_temporary_value uint32_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_147218_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_12_1 = (u64)s_b_12_0 */
    auto s_b_12_1 = emitter.zx(s_b_12_0, emitter.context().types().u64());
    /* execute.a64:2679 [D] s_b_12_2 = (u32)s_b_12_1 */
    auto s_b_12_2 = emitter.truncate(s_b_12_1, emitter.context().types().u32());
    /* execute.a64:2679 [D] s_b_12_3 = (u64)s_b_12_2 */
    auto s_b_12_3 = emitter.zx(s_b_12_2, emitter.context().types().u64());
    /* execute.a64:2679 [F] s_b_12_4=sym_32522_3_parameter_inst.S (const) */
    /* execute.a64:2679 [F] s_b_12_5 = (u64)s_b_12_4 (const) */
    /* execute.a64:2679 [D] s_b_12_6 = s_b_12_3<<s_b_12_5 */
    auto s_b_12_6 = emitter.shl(s_b_12_3, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1173 [D] s_b_12_7: sym_32549_0_rm = s_b_12_6, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32549_0_rm, s_b_12_6);
    /* execute.a64:1173 [F] s_b_12_8: Jump b_2 (const) */
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
    /* execute.a64:2796 [F] s_b_14_0=sym_32522_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_14_1 = ReadRegBank 0:s_b_14_0 (u64) */
    auto s_b_14_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_14_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_14_2: sym_147274_0_return_symbol = s_b_14_1, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_147274_0_return_symbol, s_b_14_1);
    /* ???:4294967295 [F] s_b_14_3: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14, b_18,  */
  fixed_block_b_15: 
  {
    /* ???:4294967295 [D] s_b_15_0 = sym_147274_0_return_symbol uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_147274_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1185 [D] s_b_15_1 = sym_32549_0_rm uint64_t */
    auto s_b_15_1 = emitter.load_local(DV_sym_32549_0_rm, emitter.context().types().u64());
    /* execute.a64:1185 [D] s_b_15_2 = s_b_15_0+s_b_15_1 */
    auto s_b_15_2 = emitter.add(s_b_15_0, s_b_15_1);
    /* execute.a64:1187 [F] s_b_15_3=sym_32522_3_parameter_inst.rt (const) */
    /* ???:4294967295 [D] s_b_15_4: sym_147925_1_tmp_s_b_52_2 = s_b_15_2, dominates: s_b_32_2  */
    emitter.store_local(DV_sym_147925_1_tmp_s_b_52_2, s_b_15_2);
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
    /* execute.a64:2765 [D] s_b_16_1: sym_147291_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_147291_1__R_s_b_3_0, s_b_16_0);
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
    /* execute.a64:2794 [D] s_b_18_0 = sym_147291_1__R_s_b_3_0 uint64_t */
    auto s_b_18_0 = emitter.load_local(DV_sym_147291_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_18_1: sym_147274_0_return_symbol = s_b_18_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_147274_0_return_symbol, s_b_18_0);
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
    /* execute.a64:2768 [D] s_b_19_1: sym_147291_1__R_s_b_3_0 = s_b_19_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_147291_1__R_s_b_3_0, s_b_19_0);
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
    /* execute.a64:2770 [D] s_b_20_1: sym_147291_1__R_s_b_3_0 = s_b_20_0, dominates: s_b_18_0  */
    emitter.store_local(DV_sym_147291_1__R_s_b_3_0, s_b_20_0);
    /* execute.a64:2770 [F] s_b_20_2: Jump b_18 (const) */
    goto fixed_block_b_18;
  }
  /* b_4,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2709 [F] s_b_21_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_21_1: sym_147491_1_temporary_value = s_b_21_0 (const), dominates: s_b_23_0  */
    CV_sym_147491_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_147491_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_21_2: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_4,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2709 [F] s_b_22_0=sym_32522_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_22_1 = ReadRegBank 1:s_b_22_0 (u32) */
    auto s_b_22_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_22_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_22_2: sym_147491_1_temporary_value = s_b_22_1, dominates: s_b_23_0  */
    emitter.store_local(DV_sym_147491_1_temporary_value, s_b_22_1);
    /* execute.a64:2709 [F] s_b_22_3: Jump b_23 (const) */
    goto fixed_block_b_23;
  }
  /* b_21, b_22,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2709 [D] s_b_23_0 = sym_147491_1_temporary_value uint32_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_147491_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_23_1 = (u64)s_b_23_0 */
    auto s_b_23_1 = emitter.zx(s_b_23_0, emitter.context().types().u64());
    /* execute.a64:2695 [D] s_b_23_2 = (s32)s_b_23_1 */
    auto s_b_23_2 = emitter.truncate(s_b_23_1, emitter.context().types().s32());
    /* execute.a64:2695 [D] s_b_23_3 = (s64)s_b_23_2 */
    auto s_b_23_3 = emitter.sx(s_b_23_2, emitter.context().types().s64());
    /* execute.a64:2695 [D] s_b_23_4 = (u64)s_b_23_3 */
    auto s_b_23_4 = emitter.reinterpret(s_b_23_3, emitter.context().types().u64());
    /* execute.a64:2695 [F] s_b_23_5=sym_32522_3_parameter_inst.S (const) */
    /* execute.a64:2695 [F] s_b_23_6 = (u64)s_b_23_5 (const) */
    /* execute.a64:2695 [D] s_b_23_7 = s_b_23_4<<s_b_23_6 */
    auto s_b_23_7 = emitter.shl(s_b_23_4, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1175 [D] s_b_23_8: sym_32549_0_rm = s_b_23_7, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32549_0_rm, s_b_23_7);
    /* execute.a64:1175 [F] s_b_23_9: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_6,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2714 [F] s_b_24_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_24_1: sym_147645_1_temporary_value = s_b_24_0 (const), dominates: s_b_26_0  */
    CV_sym_147645_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_147645_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_24_2: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_6,  */
  fixed_block_b_25: 
  {
    /* execute.a64:2714 [F] s_b_25_0=sym_32522_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_25_1 = ReadRegBank 0:s_b_25_0 (u64) */
    auto s_b_25_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_25_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_25_2: sym_147645_1_temporary_value = s_b_25_1, dominates: s_b_26_0  */
    emitter.store_local(DV_sym_147645_1_temporary_value, s_b_25_1);
    /* execute.a64:2714 [F] s_b_25_3: Jump b_26 (const) */
    goto fixed_block_b_26;
  }
  /* b_24, b_25,  */
  fixed_block_b_26: 
  {
    /* execute.a64:2714 [D] s_b_26_0 = sym_147645_1_temporary_value uint64_t */
    auto s_b_26_0 = emitter.load_local(DV_sym_147645_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2683 [F] s_b_26_1=sym_32522_3_parameter_inst.S (const) */
    /* execute.a64:2683 [F] s_b_26_2 = (u64)s_b_26_1 (const) */
    /* execute.a64:2683 [D] s_b_26_3 = s_b_26_0<<s_b_26_2 */
    auto s_b_26_3 = emitter.shl(s_b_26_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1177 [D] s_b_26_4: sym_32549_0_rm = s_b_26_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32549_0_rm, s_b_26_3);
    /* execute.a64:1177 [F] s_b_26_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_8,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2714 [F] s_b_27_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_27_1: sym_147811_1_temporary_value = s_b_27_0 (const), dominates: s_b_29_0  */
    CV_sym_147811_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_147811_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_27_2: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_8,  */
  fixed_block_b_28: 
  {
    /* execute.a64:2714 [F] s_b_28_0=sym_32522_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_28_1 = ReadRegBank 0:s_b_28_0 (u64) */
    auto s_b_28_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_28_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_28_2: sym_147811_1_temporary_value = s_b_28_1, dominates: s_b_29_0  */
    emitter.store_local(DV_sym_147811_1_temporary_value, s_b_28_1);
    /* execute.a64:2714 [F] s_b_28_3: Jump b_29 (const) */
    goto fixed_block_b_29;
  }
  /* b_27, b_28,  */
  fixed_block_b_29: 
  {
    /* execute.a64:2714 [D] s_b_29_0 = sym_147811_1_temporary_value uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_147811_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2699 [F] s_b_29_1=sym_32522_3_parameter_inst.S (const) */
    /* execute.a64:2699 [F] s_b_29_2 = (u64)s_b_29_1 (const) */
    /* execute.a64:2699 [D] s_b_29_3 = s_b_29_0<<s_b_29_2 */
    auto s_b_29_3 = emitter.shl(s_b_29_0, emitter.const_u64(((uint64_t)insn.S)));
    /* execute.a64:1179 [D] s_b_29_4: sym_32549_0_rm = s_b_29_3, dominates: s_b_15_1  */
    emitter.store_local(DV_sym_32549_0_rm, s_b_29_3);
    /* execute.a64:1179 [F] s_b_29_5: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_15,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2709 [F] s_b_30_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_30_1: sym_147896_1_temporary_value = s_b_30_0 (const), dominates: s_b_32_0  */
    CV_sym_147896_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_147896_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_30_2: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_15,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2709 [F] s_b_31_0=sym_32522_3_parameter_inst.rt (const) */
    /* execute.a64:2709 [D] s_b_31_1 = ReadRegBank 1:s_b_31_0 (u32) */
    auto s_b_31_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rt))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rt))),s_b_31_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_31_2: sym_147896_1_temporary_value = s_b_31_1, dominates: s_b_32_0  */
    emitter.store_local(DV_sym_147896_1_temporary_value, s_b_31_1);
    /* execute.a64:2709 [F] s_b_31_3: Jump b_32 (const) */
    goto fixed_block_b_32;
  }
  /* b_30, b_31,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2709 [D] s_b_32_0 = sym_147896_1_temporary_value uint32_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_147896_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_32_1 = (u64)s_b_32_0 */
    auto s_b_32_1 = emitter.zx(s_b_32_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_32_2 = sym_147925_1_tmp_s_b_52_2 uint64_t */
    auto s_b_32_2 = emitter.load_local(DV_sym_147925_1_tmp_s_b_52_2, emitter.context().types().u64());
    /* execute.a64:1187 [D] s_b_32_3 = (u8)s_b_32_1 */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_sub_ereg(const arm64_decode_a64_ADD_SUB_EREG&insn, captive::arch::dbt::el::Emitter& emitter)
{
  emitter.mark_used_feature(0);
  emitter.mark_used_feature(1);
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  auto DV_sym_152890_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153161_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152745_1__R_s_b_5_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_33280_0_rn = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_33294_0_rm = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152800_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_152885_0_return_symbol;
  auto DV_sym_152885_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_153095_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152705_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  uint32_t CV_sym_153011_1_temporary_value;
  auto DV_sym_153011_1_temporary_value = emitter.alloc_local(emitter.context().types().u32(), false);
  auto DV_sym_153057_3_parameter_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152984_1__R_s_b_0_4 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_152722_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  uint64_t CV_sym_152999_1_temporary_value;
  auto DV_sym_152999_1_temporary_value = emitter.alloc_local(emitter.context().types().u64(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:1947 [F] s_b_0_0=sym_33275_3_parameter_inst.sf (const) */
    /* execute.a64:2792 [F] s_b_0_1: If s_b_0_0: Jump b_6 else b_9 (const) */
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
    /* execute.a64:1951 [F] s_b_1_0=sym_33275_3_parameter_inst.sf (const) */
    /* execute.a64:1951 [F] s_b_1_1: If s_b_1_0: Jump b_4 else b_5 (const) */
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
    /* execute.a64:1957 [F] s_b_3_0=sym_33275_3_parameter_inst.sf (const) */
    /* execute.a64:1957 [D] s_b_3_1 = sym_33280_0_rn uint64_t */
    auto s_b_3_1 = emitter.load_local(DV_sym_33280_0_rn, emitter.context().types().u64());
    /* execute.a64:1957 [D] s_b_3_2 = sym_33294_0_rm uint64_t */
    auto s_b_3_2 = emitter.load_local(DV_sym_33294_0_rm, emitter.context().types().u64());
    /* execute.a64:1957 [D] s_b_3_3 = s_b_3_1-s_b_3_2 */
    auto s_b_3_3 = emitter.sub(s_b_3_1, s_b_3_2);
    /* execute.a64:1957 [D] s_b_3_4: sym_152800_3_parameter_value = s_b_3_3, dominates: s_b_23_0 s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_152800_3_parameter_value, s_b_3_3);
    /* execute.a64:2809 [F] s_b_3_5 = !s_b_3_0 (const) */
    uint8_t s_b_3_5 = !insn.sf;
    /* execute.a64:2809 [F] s_b_3_6: If s_b_3_5: Jump b_23 else b_24 (const) */
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
    /* execute.a64:1952 [D] s_b_4_0 = sym_33280_0_rn uint64_t */
    auto s_b_4_0 = emitter.load_local(DV_sym_33280_0_rn, emitter.context().types().u64());
    /* execute.a64:1952 [D] s_b_4_1 = sym_33294_0_rm uint64_t */
    auto s_b_4_1 = emitter.load_local(DV_sym_33294_0_rm, emitter.context().types().u64());
    /* execute.a64:1952 [F] s_b_4_2 = constant u8 0 (const) */
    /* execute.a64:1952 [D] s_b_4_3 = __builtin_sbc64_flags */
    auto s_b_4_3 = emitter.sbcf(s_b_4_0, s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:2754 [F] s_b_4_4=sym_33275_3_parameter_inst.rd (const) */
    /* execute.a64:2754 [D] s_b_4_5: sym_153095_3_parameter_value = s_b_4_3, dominates: s_b_49_1  */
    emitter.store_local(DV_sym_153095_3_parameter_value, s_b_4_3);
    /* execute.a64:2745 [F] s_b_4_6 = (u32)s_b_4_4 (const) */
    /* execute.a64:2745 [F] s_b_4_7 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_4_8 = s_b_4_6==s_b_4_7 (const) */
    uint8_t s_b_4_8 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_4_9: If s_b_4_8: Jump b_2 else b_49 (const) */
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
    /* execute.a64:1954 [D] s_b_5_0 = sym_33280_0_rn uint64_t */
    auto s_b_5_0 = emitter.load_local(DV_sym_33280_0_rn, emitter.context().types().u64());
    /* execute.a64:1954 [D] s_b_5_1 = (u32)s_b_5_0 */
    auto s_b_5_1 = emitter.truncate(s_b_5_0, emitter.context().types().u32());
    /* execute.a64:1954 [D] s_b_5_2 = sym_33294_0_rm uint64_t */
    auto s_b_5_2 = emitter.load_local(DV_sym_33294_0_rm, emitter.context().types().u64());
    /* execute.a64:1954 [D] s_b_5_3 = (u32)s_b_5_2 */
    auto s_b_5_3 = emitter.truncate(s_b_5_2, emitter.context().types().u32());
    /* execute.a64:1954 [F] s_b_5_4 = constant u8 0 (const) */
    /* execute.a64:1954 [D] s_b_5_5 = __builtin_sbc32_flags */
    auto s_b_5_5 = emitter.sbcf(s_b_5_1, s_b_5_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:1954 [D] s_b_5_6 = (u64)s_b_5_5 */
    auto s_b_5_6 = emitter.zx(s_b_5_5, emitter.context().types().u64());
    /* execute.a64:2756 [F] s_b_5_7=sym_33275_3_parameter_inst.rd (const) */
    /* execute.a64:2756 [D] s_b_5_8 = (u32)s_b_5_6 */
    auto s_b_5_8 = emitter.truncate(s_b_5_6, emitter.context().types().u32());
    /* execute.a64:2756 [D] s_b_5_9 = (u64)s_b_5_8 */
    auto s_b_5_9 = emitter.zx(s_b_5_8, emitter.context().types().u64());
    /* execute.a64:2756 [D] s_b_5_10: sym_153161_3_parameter_value = s_b_5_9, dominates: s_b_50_1  */
    emitter.store_local(DV_sym_153161_3_parameter_value, s_b_5_9);
    /* execute.a64:2745 [F] s_b_5_11 = (u32)s_b_5_7 (const) */
    /* execute.a64:2745 [F] s_b_5_12 = constant u32 1f (const) */
    /* execute.a64:2745 [F] s_b_5_13 = s_b_5_11==s_b_5_12 (const) */
    uint8_t s_b_5_13 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
    /* execute.a64:2745 [F] s_b_5_14: If s_b_5_13: Jump b_2 else b_50 (const) */
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
    /* execute.a64:2793 [F] s_b_6_0=sym_33275_3_parameter_inst.rn (const) */
    /* execute.a64:2793 [F] s_b_6_1 = (u32)s_b_6_0 (const) */
    /* execute.a64:2793 [F] s_b_6_2 = constant u32 1f (const) */
    /* execute.a64:2793 [F] s_b_6_3 = s_b_6_1==s_b_6_2 (const) */
    uint8_t s_b_6_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2793 [F] s_b_6_4: If s_b_6_3: Jump b_7 else b_8 (const) */
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
    /* execute.a64:2764 [F] s_b_7_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_7_1 = __builtin_get_feature */
    uint32_t s_b_7_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(s_b_7_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_7_4: If s_b_7_3: Jump b_13 else b_14 (const) */
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
    /* execute.a64:2796 [F] s_b_8_0=sym_33275_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_8_1 = ReadRegBank 0:s_b_8_0 (u64) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_8_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_8_2: sym_152705_0_return_symbol = s_b_8_1, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_152705_0_return_symbol, s_b_8_1);
    /* ???:4294967295 [F] s_b_8_3: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:2799 [F] s_b_9_0=sym_33275_3_parameter_inst.rn (const) */
    /* execute.a64:2799 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.a64:2799 [F] s_b_9_2 = constant u32 1f (const) */
    /* execute.a64:2799 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.rn) == (uint32_t)31ULL));
    /* execute.a64:2799 [F] s_b_9_4: If s_b_9_3: Jump b_10 else b_11 (const) */
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
    /* execute.a64:2764 [F] s_b_10_0 = constant u32 1 (const) */
    /* execute.a64:2764 [F] s_b_10_1 = __builtin_get_feature */
    uint32_t s_b_10_1 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2764 [F] s_b_10_2 = constant u32 0 (const) */
    /* execute.a64:2764 [F] s_b_10_3 = s_b_10_1==s_b_10_2 (const) */
    uint8_t s_b_10_3 = ((uint8_t)(s_b_10_1 == (uint32_t)0ULL));
    /* execute.a64:2764 [F] s_b_10_4: If s_b_10_3: Jump b_18 else b_19 (const) */
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
    /* execute.a64:2802 [F] s_b_11_0=sym_33275_3_parameter_inst.rn (const) */
    /* execute.a64:2802 [D] s_b_11_1 = ReadRegBank 1:s_b_11_0 (u32) */
    auto s_b_11_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_11_1,emitter.const_u8(4));
    }
    /* execute.a64:2802 [D] s_b_11_2 = (u64)s_b_11_1 */
    auto s_b_11_2 = emitter.zx(s_b_11_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_3: sym_152705_0_return_symbol = s_b_11_2, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_152705_0_return_symbol, s_b_11_2);
    /* ???:4294967295 [F] s_b_11_4: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_8, b_11, b_15, b_20,  */
  fixed_block_b_12: 
  {
    /* ???:4294967295 [D] s_b_12_0 = sym_152705_0_return_symbol uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_152705_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1947 [D] s_b_12_1: sym_33280_0_rn = s_b_12_0, dominates: s_b_4_0 s_b_5_0 s_b_3_1  */
    emitter.store_local(DV_sym_33280_0_rn, s_b_12_0);
    /* execute.a64:1948 [F] s_b_12_2=sym_33275_3_parameter_inst.option (const) */
    /* execute.a64:1948 [F] s_b_12_3 = (u32)s_b_12_2 (const) */
    /* execute.a64:1948 [F] s_b_12_4 = constant u32 3 (const) */
    /* execute.a64:1948 [F] s_b_12_5 = s_b_12_3&s_b_12_4 (const) */
    uint32_t s_b_12_5 = ((uint32_t)(((uint32_t)insn.option) & (uint32_t)3ULL));
    /* execute.a64:1948 [F] s_b_12_6 = constant u32 3 (const) */
    /* execute.a64:1948 [F] s_b_12_7 = s_b_12_5==s_b_12_6 (const) */
    uint8_t s_b_12_7 = ((uint8_t)(s_b_12_5 == (uint32_t)3ULL));
    /* execute.a64:2719 [F] s_b_12_8: If s_b_12_7: Jump b_37 else b_40 (const) */
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
    /* execute.a64:2765 [D] s_b_13_0 = ReadReg 21 (u64) */
    auto s_b_13_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_13_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_13_1: sym_152722_1__R_s_b_3_0 = s_b_13_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_152722_1__R_s_b_3_0, s_b_13_0);
    /* execute.a64:2765 [F] s_b_13_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_7,  */
  fixed_block_b_14: 
  {
    /* execute.a64:3075 [F] s_b_14_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_14_1 = __builtin_get_feature */
    uint32_t s_b_14_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_14_2 = (u8)s_b_14_1 (const) */
    /* execute.a64:2767 [F] s_b_14_3 = (u32)s_b_14_2 (const) */
    /* execute.a64:2767 [F] s_b_14_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_14_5 = s_b_14_3==s_b_14_4 (const) */
    uint8_t s_b_14_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_14_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_14_6: If s_b_14_5: Jump b_16 else b_17 (const) */
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
    /* execute.a64:2794 [D] s_b_15_0 = sym_152722_1__R_s_b_3_0 uint64_t */
    auto s_b_15_0 = emitter.load_local(DV_sym_152722_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_15_1: sym_152705_0_return_symbol = s_b_15_0, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_152705_0_return_symbol, s_b_15_0);
    /* ???:4294967295 [F] s_b_15_2: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_14,  */
  fixed_block_b_16: 
  {
    /* execute.a64:2768 [D] s_b_16_0 = ReadReg 21 (u64) */
    auto s_b_16_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_16_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_16_1: sym_152722_1__R_s_b_3_0 = s_b_16_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_152722_1__R_s_b_3_0, s_b_16_0);
    /* execute.a64:2768 [F] s_b_16_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_14,  */
  fixed_block_b_17: 
  {
    /* execute.a64:2770 [D] s_b_17_0 = ReadReg 22 (u64) */
    auto s_b_17_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_17_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_17_1: sym_152722_1__R_s_b_3_0 = s_b_17_0, dominates: s_b_15_0  */
    emitter.store_local(DV_sym_152722_1__R_s_b_3_0, s_b_17_0);
    /* execute.a64:2770 [F] s_b_17_2: Jump b_15 (const) */
    goto fixed_block_b_15;
  }
  /* b_10,  */
  fixed_block_b_18: 
  {
    /* execute.a64:2765 [D] s_b_18_0 = ReadReg 21 (u64) */
    auto s_b_18_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_18_0, emitter.const_u8(8));
    }
    /* execute.a64:2765 [D] s_b_18_1: sym_152745_1__R_s_b_5_0 = s_b_18_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_152745_1__R_s_b_5_0, s_b_18_0);
    /* execute.a64:2765 [F] s_b_18_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_10,  */
  fixed_block_b_19: 
  {
    /* execute.a64:3075 [F] s_b_19_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_19_1 = __builtin_get_feature */
    uint32_t s_b_19_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_19_2 = (u8)s_b_19_1 (const) */
    /* execute.a64:2767 [F] s_b_19_3 = (u32)s_b_19_2 (const) */
    /* execute.a64:2767 [F] s_b_19_4 = constant u32 0 (const) */
    /* execute.a64:2767 [F] s_b_19_5 = s_b_19_3==s_b_19_4 (const) */
    uint8_t s_b_19_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_19_1)) == (uint32_t)0ULL));
    /* execute.a64:2767 [F] s_b_19_6: If s_b_19_5: Jump b_21 else b_22 (const) */
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
    /* execute.a64:2800 [D] s_b_20_0 = sym_152745_1__R_s_b_5_0 uint64_t */
    auto s_b_20_0 = emitter.load_local(DV_sym_152745_1__R_s_b_5_0, emitter.context().types().u64());
    /* execute.a64:2800 [D] s_b_20_1 = (u32)s_b_20_0 */
    auto s_b_20_1 = emitter.truncate(s_b_20_0, emitter.context().types().u32());
    /* execute.a64:2800 [D] s_b_20_2 = (u64)s_b_20_1 */
    auto s_b_20_2 = emitter.zx(s_b_20_1, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_20_3: sym_152705_0_return_symbol = s_b_20_2, dominates: s_b_12_0  */
    emitter.store_local(DV_sym_152705_0_return_symbol, s_b_20_2);
    /* ???:4294967295 [F] s_b_20_4: Jump b_12 (const) */
    goto fixed_block_b_12;
  }
  /* b_19,  */
  fixed_block_b_21: 
  {
    /* execute.a64:2768 [D] s_b_21_0 = ReadReg 21 (u64) */
    auto s_b_21_0 = emitter.load_register(emitter.const_u32(1408), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1408), s_b_21_0, emitter.const_u8(8));
    }
    /* execute.a64:2768 [D] s_b_21_1: sym_152745_1__R_s_b_5_0 = s_b_21_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_152745_1__R_s_b_5_0, s_b_21_0);
    /* execute.a64:2768 [F] s_b_21_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_19,  */
  fixed_block_b_22: 
  {
    /* execute.a64:2770 [D] s_b_22_0 = ReadReg 22 (u64) */
    auto s_b_22_0 = emitter.load_register(emitter.const_u32(1416), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1416), s_b_22_0, emitter.const_u8(8));
    }
    /* execute.a64:2770 [D] s_b_22_1: sym_152745_1__R_s_b_5_0 = s_b_22_0, dominates: s_b_20_0  */
    emitter.store_local(DV_sym_152745_1__R_s_b_5_0, s_b_22_0);
    /* execute.a64:2770 [F] s_b_22_2: Jump b_20 (const) */
    goto fixed_block_b_20;
  }
  /* b_3,  */
  fixed_block_b_23: 
  {
    /* execute.a64:2810 [D] s_b_23_0 = sym_152800_3_parameter_value uint64_t */
    auto s_b_23_0 = emitter.load_local(DV_sym_152800_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2810 [F] s_b_23_1 = constant u64 ffffffff (const) */
    /* ???:4294967295 [D] s_b_23_2 = s_b_23_0&s_b_23_1 */
    auto s_b_23_2 = emitter.bitwise_and(s_b_23_0, emitter.const_u64((uint64_t)4294967295ULL));
    /* execute.a64:2810 [D] s_b_23_3: sym_152800_3_parameter_value = s_b_23_2, dominates: s_b_25_0 s_b_26_1  */
    emitter.store_local(DV_sym_152800_3_parameter_value, s_b_23_2);
    /* execute.a64:2810 [F] s_b_23_4: Jump b_24 (const) */
    goto fixed_block_b_24;
  }
  /* b_3, b_23,  */
  fixed_block_b_24: 
  {
    /* execute.a64:2813 [F] s_b_24_0=sym_33275_3_parameter_inst.rd (const) */
    /* execute.a64:2813 [F] s_b_24_1 = (u32)s_b_24_0 (const) */
    /* execute.a64:2813 [F] s_b_24_2 = constant u32 1f (const) */
    /* execute.a64:2813 [F] s_b_24_3 = s_b_24_1==s_b_24_2 (const) */
    uint8_t s_b_24_3 = ((uint8_t)(((uint32_t)insn.rd) == (uint32_t)31ULL));
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
    /* execute.a64:2814 [D] s_b_25_0 = sym_152800_3_parameter_value uint64_t */
    auto s_b_25_0 = emitter.load_local(DV_sym_152800_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2814 [D] s_b_25_1: sym_153057_3_parameter_value = s_b_25_0, dominates: s_b_46_0 s_b_47_0 s_b_48_0  */
    emitter.store_local(DV_sym_153057_3_parameter_value, s_b_25_0);
    /* execute.a64:2777 [F] s_b_25_2 = constant u32 1 (const) */
    /* execute.a64:2777 [F] s_b_25_3 = __builtin_get_feature */
    uint32_t s_b_25_3 = __get_feature((uint32_t)1ULL);
    /* execute.a64:2777 [F] s_b_25_4 = constant u32 0 (const) */
    /* execute.a64:2777 [F] s_b_25_5 = s_b_25_3==s_b_25_4 (const) */
    uint8_t s_b_25_5 = ((uint8_t)(s_b_25_3 == (uint32_t)0ULL));
    /* execute.a64:2777 [F] s_b_25_6: If s_b_25_5: Jump b_46 else b_51 (const) */
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
    /* execute.a64:2816 [F] s_b_26_0=sym_33275_3_parameter_inst.rd (const) */
    /* execute.a64:2816 [D] s_b_26_1 = sym_152800_3_parameter_value uint64_t */
    auto s_b_26_1 = emitter.load_local(DV_sym_152800_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2816 [D] s_b_26_2: WriteRegBank 0:s_b_26_0 = s_b_26_1 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rd))),s_b_26_1);
    /* execute.a64:2816 [F] s_b_26_3: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_43,  */
  fixed_block_b_27: 
  {
    /* execute.a64:2703 [D] s_b_27_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.a64:2704 [F] s_b_27_1 = constant u64 0 (const) */
    /* ???:4294967295 [F] s_b_27_2: sym_152885_0_return_symbol = s_b_27_1 (const), dominates: s_b_28_0  */
    CV_sym_152885_0_return_symbol = (uint64_t)0ULL;
    emitter.store_local(DV_sym_152885_0_return_symbol, emitter.const_u64((uint64_t)0ULL));
    /* ???:4294967295 [F] s_b_27_3: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_27, b_29, b_30, b_31, b_32, b_33, b_34, b_35, b_36,  */
  fixed_block_b_28: 
  {
    /* ???:4294967295 [D] s_b_28_0 = sym_152885_0_return_symbol uint64_t */
    auto s_b_28_0 = emitter.load_local(DV_sym_152885_0_return_symbol, emitter.context().types().u64());
    /* execute.a64:1948 [D] s_b_28_1: sym_33294_0_rm = s_b_28_0, dominates: s_b_4_1 s_b_5_2 s_b_3_2  */
    emitter.store_local(DV_sym_33294_0_rm, s_b_28_0);
    /* execute.a64:1950 [F] s_b_28_2=sym_33275_3_parameter_inst.S (const) */
    /* execute.a64:1950 [F] s_b_28_3: If s_b_28_2: Jump b_1 else b_3 (const) */
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
    /* execute.a64:2671 [D] s_b_29_0 = sym_152890_0_value uint64_t */
    auto s_b_29_0 = emitter.load_local(DV_sym_152890_0_value, emitter.context().types().u64());
    /* execute.a64:2671 [D] s_b_29_1 = (u8)s_b_29_0 */
    auto s_b_29_1 = emitter.truncate(s_b_29_0, emitter.context().types().u8());
    /* execute.a64:2671 [D] s_b_29_2 = (u64)s_b_29_1 */
    auto s_b_29_2 = emitter.zx(s_b_29_1, emitter.context().types().u64());
    /* execute.a64:2671 [F] s_b_29_3=sym_33275_3_parameter_inst.imm3 (const) */
    /* execute.a64:2671 [F] s_b_29_4 = (u64)s_b_29_3 (const) */
    /* execute.a64:2671 [D] s_b_29_5 = s_b_29_2<<s_b_29_4 */
    auto s_b_29_5 = emitter.shl(s_b_29_2, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_29_6: sym_152885_0_return_symbol = s_b_29_5, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152885_0_return_symbol, s_b_29_5);
    /* ???:4294967295 [F] s_b_29_7: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_30: 
  {
    /* execute.a64:2675 [D] s_b_30_0 = sym_152890_0_value uint64_t */
    auto s_b_30_0 = emitter.load_local(DV_sym_152890_0_value, emitter.context().types().u64());
    /* execute.a64:2675 [D] s_b_30_1 = (u16)s_b_30_0 */
    auto s_b_30_1 = emitter.truncate(s_b_30_0, emitter.context().types().u16());
    /* execute.a64:2675 [D] s_b_30_2 = (u64)s_b_30_1 */
    auto s_b_30_2 = emitter.zx(s_b_30_1, emitter.context().types().u64());
    /* execute.a64:2675 [F] s_b_30_3=sym_33275_3_parameter_inst.imm3 (const) */
    /* execute.a64:2675 [F] s_b_30_4 = (u64)s_b_30_3 (const) */
    /* execute.a64:2675 [D] s_b_30_5 = s_b_30_2<<s_b_30_4 */
    auto s_b_30_5 = emitter.shl(s_b_30_2, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_30_6: sym_152885_0_return_symbol = s_b_30_5, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152885_0_return_symbol, s_b_30_5);
    /* ???:4294967295 [F] s_b_30_7: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_31: 
  {
    /* execute.a64:2679 [D] s_b_31_0 = sym_152890_0_value uint64_t */
    auto s_b_31_0 = emitter.load_local(DV_sym_152890_0_value, emitter.context().types().u64());
    /* execute.a64:2679 [D] s_b_31_1 = (u32)s_b_31_0 */
    auto s_b_31_1 = emitter.truncate(s_b_31_0, emitter.context().types().u32());
    /* execute.a64:2679 [D] s_b_31_2 = (u64)s_b_31_1 */
    auto s_b_31_2 = emitter.zx(s_b_31_1, emitter.context().types().u64());
    /* execute.a64:2679 [F] s_b_31_3=sym_33275_3_parameter_inst.imm3 (const) */
    /* execute.a64:2679 [F] s_b_31_4 = (u64)s_b_31_3 (const) */
    /* execute.a64:2679 [D] s_b_31_5 = s_b_31_2<<s_b_31_4 */
    auto s_b_31_5 = emitter.shl(s_b_31_2, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_31_6: sym_152885_0_return_symbol = s_b_31_5, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152885_0_return_symbol, s_b_31_5);
    /* ???:4294967295 [F] s_b_31_7: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_32: 
  {
    /* execute.a64:2683 [D] s_b_32_0 = sym_152890_0_value uint64_t */
    auto s_b_32_0 = emitter.load_local(DV_sym_152890_0_value, emitter.context().types().u64());
    /* execute.a64:2683 [F] s_b_32_1=sym_33275_3_parameter_inst.imm3 (const) */
    /* execute.a64:2683 [F] s_b_32_2 = (u64)s_b_32_1 (const) */
    /* execute.a64:2683 [D] s_b_32_3 = s_b_32_0<<s_b_32_2 */
    auto s_b_32_3 = emitter.shl(s_b_32_0, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_32_4: sym_152885_0_return_symbol = s_b_32_3, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152885_0_return_symbol, s_b_32_3);
    /* ???:4294967295 [F] s_b_32_5: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_33: 
  {
    /* execute.a64:2687 [D] s_b_33_0 = sym_152890_0_value uint64_t */
    auto s_b_33_0 = emitter.load_local(DV_sym_152890_0_value, emitter.context().types().u64());
    /* execute.a64:2687 [D] s_b_33_1 = (s8)s_b_33_0 */
    auto s_b_33_1 = emitter.truncate(s_b_33_0, emitter.context().types().s8());
    /* execute.a64:2687 [D] s_b_33_2 = (s64)s_b_33_1 */
    auto s_b_33_2 = emitter.sx(s_b_33_1, emitter.context().types().s64());
    /* execute.a64:2687 [D] s_b_33_3 = (u64)s_b_33_2 */
    auto s_b_33_3 = emitter.reinterpret(s_b_33_2, emitter.context().types().u64());
    /* execute.a64:2687 [F] s_b_33_4=sym_33275_3_parameter_inst.imm3 (const) */
    /* execute.a64:2687 [F] s_b_33_5 = (u64)s_b_33_4 (const) */
    /* execute.a64:2687 [D] s_b_33_6 = s_b_33_3<<s_b_33_5 */
    auto s_b_33_6 = emitter.shl(s_b_33_3, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_33_7: sym_152885_0_return_symbol = s_b_33_6, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152885_0_return_symbol, s_b_33_6);
    /* ???:4294967295 [F] s_b_33_8: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_34: 
  {
    /* execute.a64:2691 [D] s_b_34_0 = sym_152890_0_value uint64_t */
    auto s_b_34_0 = emitter.load_local(DV_sym_152890_0_value, emitter.context().types().u64());
    /* execute.a64:2691 [D] s_b_34_1 = (s16)s_b_34_0 */
    auto s_b_34_1 = emitter.truncate(s_b_34_0, emitter.context().types().s16());
    /* execute.a64:2691 [D] s_b_34_2 = (s64)s_b_34_1 */
    auto s_b_34_2 = emitter.sx(s_b_34_1, emitter.context().types().s64());
    /* execute.a64:2691 [D] s_b_34_3 = (u64)s_b_34_2 */
    auto s_b_34_3 = emitter.reinterpret(s_b_34_2, emitter.context().types().u64());
    /* execute.a64:2691 [F] s_b_34_4=sym_33275_3_parameter_inst.imm3 (const) */
    /* execute.a64:2691 [F] s_b_34_5 = (u64)s_b_34_4 (const) */
    /* execute.a64:2691 [D] s_b_34_6 = s_b_34_3<<s_b_34_5 */
    auto s_b_34_6 = emitter.shl(s_b_34_3, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_34_7: sym_152885_0_return_symbol = s_b_34_6, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152885_0_return_symbol, s_b_34_6);
    /* ???:4294967295 [F] s_b_34_8: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_35: 
  {
    /* execute.a64:2695 [D] s_b_35_0 = sym_152890_0_value uint64_t */
    auto s_b_35_0 = emitter.load_local(DV_sym_152890_0_value, emitter.context().types().u64());
    /* execute.a64:2695 [D] s_b_35_1 = (s32)s_b_35_0 */
    auto s_b_35_1 = emitter.truncate(s_b_35_0, emitter.context().types().s32());
    /* execute.a64:2695 [D] s_b_35_2 = (s64)s_b_35_1 */
    auto s_b_35_2 = emitter.sx(s_b_35_1, emitter.context().types().s64());
    /* execute.a64:2695 [D] s_b_35_3 = (u64)s_b_35_2 */
    auto s_b_35_3 = emitter.reinterpret(s_b_35_2, emitter.context().types().u64());
    /* execute.a64:2695 [F] s_b_35_4=sym_33275_3_parameter_inst.imm3 (const) */
    /* execute.a64:2695 [F] s_b_35_5 = (u64)s_b_35_4 (const) */
    /* execute.a64:2695 [D] s_b_35_6 = s_b_35_3<<s_b_35_5 */
    auto s_b_35_6 = emitter.shl(s_b_35_3, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_35_7: sym_152885_0_return_symbol = s_b_35_6, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152885_0_return_symbol, s_b_35_6);
    /* ???:4294967295 [F] s_b_35_8: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_43,  */
  fixed_block_b_36: 
  {
    /* execute.a64:2699 [D] s_b_36_0 = sym_152890_0_value uint64_t */
    auto s_b_36_0 = emitter.load_local(DV_sym_152890_0_value, emitter.context().types().u64());
    /* execute.a64:2699 [F] s_b_36_1=sym_33275_3_parameter_inst.imm3 (const) */
    /* execute.a64:2699 [F] s_b_36_2 = (u64)s_b_36_1 (const) */
    /* execute.a64:2699 [D] s_b_36_3 = s_b_36_0<<s_b_36_2 */
    auto s_b_36_3 = emitter.shl(s_b_36_0, emitter.const_u64(((uint64_t)insn.imm3)));
    /* ???:4294967295 [D] s_b_36_4: sym_152885_0_return_symbol = s_b_36_3, dominates: s_b_28_0  */
    emitter.store_local(DV_sym_152885_0_return_symbol, s_b_36_3);
    /* ???:4294967295 [F] s_b_36_5: Jump b_28 (const) */
    goto fixed_block_b_28;
  }
  /* b_12,  */
  fixed_block_b_37: 
  {
    /* execute.a64:2720 [F] s_b_37_0=sym_33275_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [F] s_b_37_1 = (u32)s_b_37_0 (const) */
    /* execute.a64:2714 [F] s_b_37_2 = constant u32 1f (const) */
    /* execute.a64:2714 [F] s_b_37_3 = s_b_37_1==s_b_37_2 (const) */
    uint8_t s_b_37_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2714 [F] s_b_37_4: If s_b_37_3: Jump b_38 else b_39 (const) */
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
    /* execute.a64:2714 [F] s_b_38_0 = constant u64 0 (const) */
    /* execute.a64:2714 [F] s_b_38_1: sym_152999_1_temporary_value = s_b_38_0 (const), dominates: s_b_44_0  */
    CV_sym_152999_1_temporary_value = (uint64_t)0ULL;
    emitter.store_local(DV_sym_152999_1_temporary_value, emitter.const_u64((uint64_t)0ULL));
    /* execute.a64:2714 [F] s_b_38_2: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  /* b_37,  */
  fixed_block_b_39: 
  {
    /* execute.a64:2714 [F] s_b_39_0=sym_33275_3_parameter_inst.rm (const) */
    /* execute.a64:2714 [D] s_b_39_1 = ReadRegBank 0:s_b_39_0 (u64) */
    auto s_b_39_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_39_1,emitter.const_u8(8));
    }
    /* execute.a64:2714 [D] s_b_39_2: sym_152999_1_temporary_value = s_b_39_1, dominates: s_b_44_0  */
    emitter.store_local(DV_sym_152999_1_temporary_value, s_b_39_1);
    /* execute.a64:2714 [F] s_b_39_3: Jump b_44 (const) */
    goto fixed_block_b_44;
  }
  /* b_12,  */
  fixed_block_b_40: 
  {
    /* execute.a64:2722 [F] s_b_40_0=sym_33275_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [F] s_b_40_1 = (u32)s_b_40_0 (const) */
    /* execute.a64:2709 [F] s_b_40_2 = constant u32 1f (const) */
    /* execute.a64:2709 [F] s_b_40_3 = s_b_40_1==s_b_40_2 (const) */
    uint8_t s_b_40_3 = ((uint8_t)(((uint32_t)insn.rm) == (uint32_t)31ULL));
    /* execute.a64:2709 [F] s_b_40_4: If s_b_40_3: Jump b_41 else b_42 (const) */
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
    /* execute.a64:2709 [F] s_b_41_0 = constant u32 0 (const) */
    /* execute.a64:2709 [F] s_b_41_1: sym_153011_1_temporary_value = s_b_41_0 (const), dominates: s_b_45_0  */
    CV_sym_153011_1_temporary_value = (uint32_t)0ULL;
    emitter.store_local(DV_sym_153011_1_temporary_value, emitter.const_u32((uint32_t)0ULL));
    /* execute.a64:2709 [F] s_b_41_2: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_40,  */
  fixed_block_b_42: 
  {
    /* execute.a64:2709 [F] s_b_42_0=sym_33275_3_parameter_inst.rm (const) */
    /* execute.a64:2709 [D] s_b_42_1 = ReadRegBank 1:s_b_42_0 (u32) */
    auto s_b_42_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rm))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rm))),s_b_42_1,emitter.const_u8(4));
    }
    /* execute.a64:2709 [D] s_b_42_2: sym_153011_1_temporary_value = s_b_42_1, dominates: s_b_45_0  */
    emitter.store_local(DV_sym_153011_1_temporary_value, s_b_42_1);
    /* execute.a64:2709 [F] s_b_42_3: Jump b_45 (const) */
    goto fixed_block_b_45;
  }
  /* b_44, b_45,  */
  fixed_block_b_43: 
  {
    /* execute.a64:2666 [D] s_b_43_0 = sym_152984_1__R_s_b_0_4 uint64_t */
    auto s_b_43_0 = emitter.load_local(DV_sym_152984_1__R_s_b_0_4, emitter.context().types().u64());
    /* execute.a64:2666 [D] s_b_43_1: sym_152890_0_value = s_b_43_0, dominates: s_b_29_0 s_b_32_0 s_b_36_0 s_b_35_0 s_b_34_0 s_b_33_0 s_b_31_0 s_b_30_0  */
    emitter.store_local(DV_sym_152890_0_value, s_b_43_0);
    /* execute.a64:2668 [F] s_b_43_2=sym_33275_3_parameter_inst.option (const) */
    /* execute.a64:2669 [F] s_b_43_3 = constant s32 0 (const) */
    /* execute.a64:2673 [F] s_b_43_4 = constant s32 1 (const) */
    /* execute.a64:2677 [F] s_b_43_5 = constant s32 2 (const) */
    /* execute.a64:2681 [F] s_b_43_6 = constant s32 3 (const) */
    /* execute.a64:2685 [F] s_b_43_7 = constant s32 4 (const) */
    /* execute.a64:2689 [F] s_b_43_8 = constant s32 5 (const) */
    /* execute.a64:2693 [F] s_b_43_9 = constant s32 6 (const) */
    /* execute.a64:2697 [F] s_b_43_10 = constant s32 7 (const) */
    /* execute.a64:2668 [F] s_b_43_11: Switch s_b_43_2: < <todo> > def b_27 (const) -> b_29, b_32, b_36, b_35, b_34, b_33, b_27, b_31, b_30,  */
    switch (insn.option) 
    {
    case (int32_t)1ULL:
      goto fixed_block_b_30;
      break;
    case (int32_t)6ULL:
      goto fixed_block_b_35;
      break;
    case (int32_t)7ULL:
      goto fixed_block_b_36;
      break;
    case (int32_t)0ULL:
      goto fixed_block_b_29;
      break;
    case (int32_t)2ULL:
      goto fixed_block_b_31;
      break;
    case (int32_t)5ULL:
      goto fixed_block_b_34;
      break;
    case (int32_t)3ULL:
      goto fixed_block_b_32;
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
    /* execute.a64:2714 [D] s_b_44_0 = sym_152999_1_temporary_value uint64_t */
    auto s_b_44_0 = emitter.load_local(DV_sym_152999_1_temporary_value, emitter.context().types().u64());
    /* execute.a64:2720 [D] s_b_44_1: sym_152984_1__R_s_b_0_4 = s_b_44_0, dominates: s_b_43_0  */
    emitter.store_local(DV_sym_152984_1__R_s_b_0_4, s_b_44_0);
    /* execute.a64:2720 [F] s_b_44_2: Jump b_43 (const) */
    goto fixed_block_b_43;
  }
  /* b_41, b_42,  */
  fixed_block_b_45: 
  {
    /* execute.a64:2709 [D] s_b_45_0 = sym_153011_1_temporary_value uint32_t */
    auto s_b_45_0 = emitter.load_local(DV_sym_153011_1_temporary_value, emitter.context().types().u32());
    /* execute.a64:2722 [D] s_b_45_1 = (u64)s_b_45_0 */
    auto s_b_45_1 = emitter.zx(s_b_45_0, emitter.context().types().u64());
    /* execute.a64:2722 [D] s_b_45_2: sym_152984_1__R_s_b_0_4 = s_b_45_1, dominates: s_b_43_0  */
    emitter.store_local(DV_sym_152984_1__R_s_b_0_4, s_b_45_1);
    /* execute.a64:2722 [F] s_b_45_3: Jump b_43 (const) */
    goto fixed_block_b_43;
  }
  /* b_25,  */
  fixed_block_b_46: 
  {
    /* execute.a64:2778 [D] s_b_46_0 = sym_153057_3_parameter_value uint64_t */
    auto s_b_46_0 = emitter.load_local(DV_sym_153057_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2778 [D] s_b_46_1: WriteReg 21 = s_b_46_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_46_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_46_0);
    /* execute.a64:2778 [F] s_b_46_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_51,  */
  fixed_block_b_47: 
  {
    /* execute.a64:2781 [D] s_b_47_0 = sym_153057_3_parameter_value uint64_t */
    auto s_b_47_0 = emitter.load_local(DV_sym_153057_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2781 [D] s_b_47_1: WriteReg 21 = s_b_47_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1408), s_b_47_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1408), s_b_47_0);
    /* execute.a64:2781 [F] s_b_47_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_51,  */
  fixed_block_b_48: 
  {
    /* execute.a64:2783 [D] s_b_48_0 = sym_153057_3_parameter_value uint64_t */
    auto s_b_48_0 = emitter.load_local(DV_sym_153057_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2783 [D] s_b_48_1: WriteReg 22 = s_b_48_0 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER, emitter.const_u32(1416), s_b_48_0, emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32(1416), s_b_48_0);
    /* execute.a64:2783 [F] s_b_48_2: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_4,  */
  fixed_block_b_49: 
  {
    /* execute.a64:2747 [F] s_b_49_0=sym_33275_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_49_1 = sym_153095_3_parameter_value uint64_t */
    auto s_b_49_1 = emitter.load_local(DV_sym_153095_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_49_2: WriteRegBank 0:s_b_49_0 = s_b_49_1 */
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
    /* execute.a64:2747 [F] s_b_50_0=sym_33275_3_parameter_inst.rd (const) */
    /* execute.a64:2747 [D] s_b_50_1 = sym_153161_3_parameter_value uint64_t */
    auto s_b_50_1 = emitter.load_local(DV_sym_153161_3_parameter_value, emitter.context().types().u64());
    /* execute.a64:2747 [D] s_b_50_2: WriteRegBank 0:s_b_50_0 = s_b_50_1 */
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
    /* execute.a64:3075 [F] s_b_51_0 = constant u32 0 (const) */
    /* execute.a64:3075 [F] s_b_51_1 = __builtin_get_feature */
    uint32_t s_b_51_1 = __get_feature((uint32_t)0ULL);
    /* execute.a64:3075 [F] s_b_51_2 = (u8)s_b_51_1 (const) */
    /* execute.a64:2780 [F] s_b_51_3 = (u32)s_b_51_2 (const) */
    /* execute.a64:2780 [F] s_b_51_4 = constant u32 0 (const) */
    /* execute.a64:2780 [F] s_b_51_5 = s_b_51_3==s_b_51_4 (const) */
    uint8_t s_b_51_5 = ((uint8_t)(((uint32_t)((uint8_t)s_b_51_1)) == (uint32_t)0ULL));
    /* execute.a64:2780 [F] s_b_51_6: If s_b_51_5: Jump b_47 else b_48 (const) */
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
    /* execute.simd:3554 [F] s_b_0_0=sym_36464_3_parameter_inst.arrangement (const) */
    /* execute.simd:3555 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:3567 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:3578 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:3590 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:3601 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:3611 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:3554 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:3556 [F] s_b_2_0=sym_36464_3_parameter_inst.rn (const) */
    /* execute.simd:3556 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:3557 [F] s_b_2_2=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3557 [D] s_b_2_3 = ReadRegBank 17:s_b_2_2 (v4u16) */
    auto s_b_2_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_2_4 = constant u8 0 (const) */
    /* execute.simd:3560 [D] s_b_2_3[s_b_2_4] */
    auto s_b_2_5 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3560 [F] s_b_2_6 = constant u32 0 (const) */
    /* execute.simd:3560 [D] s_b_2_1[s_b_2_6] */
    auto s_b_2_7 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3560 [D] s_b_2_8 = (u16)s_b_2_7 */
    auto s_b_2_8 = emitter.zx(s_b_2_7, emitter.context().types().u16());
    /* execute.simd:3560 [F] s_b_2_9 = constant u32 1 (const) */
    /* execute.simd:3560 [D] s_b_2_1[s_b_2_9] */
    auto s_b_2_10 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3560 [D] s_b_2_11 = (u16)s_b_2_10 */
    auto s_b_2_11 = emitter.zx(s_b_2_10, emitter.context().types().u16());
    /* execute.simd:3560 [D] s_b_2_12 = s_b_2_8+s_b_2_11 */
    auto s_b_2_12 = emitter.add(s_b_2_8, s_b_2_11);
    /* ???:4294967295 [D] s_b_2_13 = s_b_2_5+s_b_2_12 */
    auto s_b_2_13 = emitter.add(s_b_2_5, s_b_2_12);
    /* execute.simd:3560 [F] s_b_2_14 = constant s32 0 (const) */
    /* execute.simd:3560 [D] s_b_2_15 = s_b_2_3[s_b_2_14] <= s_b_2_13 */
    auto s_b_2_15 = emitter.vector_insert(s_b_2_3, emitter.const_s32((int32_t)0ULL), s_b_2_13);
    /* ???:4294967295 [F] s_b_2_16 = constant u8 1 (const) */
    /* execute.simd:3560 [D] s_b_2_15[s_b_2_16] */
    auto s_b_2_17 = emitter.vector_extract(s_b_2_15, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3560 [F] s_b_2_18 = constant u32 2 (const) */
    /* execute.simd:3560 [D] s_b_2_1[s_b_2_18] */
    auto s_b_2_19 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3560 [D] s_b_2_20 = (u16)s_b_2_19 */
    auto s_b_2_20 = emitter.zx(s_b_2_19, emitter.context().types().u16());
    /* execute.simd:3560 [F] s_b_2_21 = constant u32 3 (const) */
    /* execute.simd:3560 [D] s_b_2_1[s_b_2_21] */
    auto s_b_2_22 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3560 [D] s_b_2_23 = (u16)s_b_2_22 */
    auto s_b_2_23 = emitter.zx(s_b_2_22, emitter.context().types().u16());
    /* execute.simd:3560 [D] s_b_2_24 = s_b_2_20+s_b_2_23 */
    auto s_b_2_24 = emitter.add(s_b_2_20, s_b_2_23);
    /* ???:4294967295 [D] s_b_2_25 = s_b_2_17+s_b_2_24 */
    auto s_b_2_25 = emitter.add(s_b_2_17, s_b_2_24);
    /* execute.simd:3560 [F] s_b_2_26 = constant s32 1 (const) */
    /* execute.simd:3560 [D] s_b_2_27 = s_b_2_15[s_b_2_26] <= s_b_2_25 */
    auto s_b_2_27 = emitter.vector_insert(s_b_2_15, emitter.const_s32((int32_t)1ULL), s_b_2_25);
    /* ???:4294967295 [F] s_b_2_28 = constant u8 2 (const) */
    /* execute.simd:3560 [D] s_b_2_27[s_b_2_28] */
    auto s_b_2_29 = emitter.vector_extract(s_b_2_27, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3560 [F] s_b_2_30 = constant u32 4 (const) */
    /* execute.simd:3560 [D] s_b_2_1[s_b_2_30] */
    auto s_b_2_31 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:3560 [D] s_b_2_32 = (u16)s_b_2_31 */
    auto s_b_2_32 = emitter.zx(s_b_2_31, emitter.context().types().u16());
    /* execute.simd:3560 [F] s_b_2_33 = constant u32 5 (const) */
    /* execute.simd:3560 [D] s_b_2_1[s_b_2_33] */
    auto s_b_2_34 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:3560 [D] s_b_2_35 = (u16)s_b_2_34 */
    auto s_b_2_35 = emitter.zx(s_b_2_34, emitter.context().types().u16());
    /* execute.simd:3560 [D] s_b_2_36 = s_b_2_32+s_b_2_35 */
    auto s_b_2_36 = emitter.add(s_b_2_32, s_b_2_35);
    /* ???:4294967295 [D] s_b_2_37 = s_b_2_29+s_b_2_36 */
    auto s_b_2_37 = emitter.add(s_b_2_29, s_b_2_36);
    /* execute.simd:3560 [F] s_b_2_38 = constant s32 2 (const) */
    /* execute.simd:3560 [D] s_b_2_39 = s_b_2_27[s_b_2_38] <= s_b_2_37 */
    auto s_b_2_39 = emitter.vector_insert(s_b_2_27, emitter.const_s32((int32_t)2ULL), s_b_2_37);
    /* ???:4294967295 [F] s_b_2_40 = constant u8 3 (const) */
    /* execute.simd:3560 [D] s_b_2_39[s_b_2_40] */
    auto s_b_2_41 = emitter.vector_extract(s_b_2_39, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3560 [F] s_b_2_42 = constant u32 6 (const) */
    /* execute.simd:3560 [D] s_b_2_1[s_b_2_42] */
    auto s_b_2_43 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:3560 [D] s_b_2_44 = (u16)s_b_2_43 */
    auto s_b_2_44 = emitter.zx(s_b_2_43, emitter.context().types().u16());
    /* execute.simd:3560 [F] s_b_2_45 = constant u32 7 (const) */
    /* execute.simd:3560 [D] s_b_2_1[s_b_2_45] */
    auto s_b_2_46 = emitter.vector_extract(s_b_2_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:3560 [D] s_b_2_47 = (u16)s_b_2_46 */
    auto s_b_2_47 = emitter.zx(s_b_2_46, emitter.context().types().u16());
    /* execute.simd:3560 [D] s_b_2_48 = s_b_2_44+s_b_2_47 */
    auto s_b_2_48 = emitter.add(s_b_2_44, s_b_2_47);
    /* ???:4294967295 [D] s_b_2_49 = s_b_2_41+s_b_2_48 */
    auto s_b_2_49 = emitter.add(s_b_2_41, s_b_2_48);
    /* execute.simd:3560 [F] s_b_2_50 = constant s32 3 (const) */
    /* execute.simd:3560 [D] s_b_2_51 = s_b_2_39[s_b_2_50] <= s_b_2_49 */
    auto s_b_2_51 = emitter.vector_insert(s_b_2_39, emitter.const_s32((int32_t)3ULL), s_b_2_49);
    /* execute.simd:3563 [F] s_b_2_52=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3563 [D] s_b_2_53: WriteRegBank 17:s_b_2_52 = s_b_2_51 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_51,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_2_51);
    /* execute.simd:3564 [F] s_b_2_54=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3564 [F] s_b_2_55 = constant u64 0 (const) */
    /* execute.simd:3564 [F] s_b_2_56: WriteRegBank 3:s_b_2_54 = s_b_2_55 */
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
    /* execute.simd:3568 [F] s_b_3_0=sym_36464_3_parameter_inst.rn (const) */
    /* execute.simd:3568 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:3569 [F] s_b_3_2=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3569 [D] s_b_3_3 = ReadRegBank 18:s_b_3_2 (v8u16) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant u8 0 (const) */
    /* execute.simd:3572 [D] s_b_3_3[s_b_3_4] */
    auto s_b_3_5 = emitter.vector_extract(s_b_3_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3572 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_6] */
    auto s_b_3_7 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3572 [D] s_b_3_8 = (u16)s_b_3_7 */
    auto s_b_3_8 = emitter.zx(s_b_3_7, emitter.context().types().u16());
    /* execute.simd:3572 [F] s_b_3_9 = constant u32 1 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_9] */
    auto s_b_3_10 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3572 [D] s_b_3_11 = (u16)s_b_3_10 */
    auto s_b_3_11 = emitter.zx(s_b_3_10, emitter.context().types().u16());
    /* execute.simd:3572 [D] s_b_3_12 = s_b_3_8+s_b_3_11 */
    auto s_b_3_12 = emitter.add(s_b_3_8, s_b_3_11);
    /* ???:4294967295 [D] s_b_3_13 = s_b_3_5+s_b_3_12 */
    auto s_b_3_13 = emitter.add(s_b_3_5, s_b_3_12);
    /* execute.simd:3572 [F] s_b_3_14 = constant s32 0 (const) */
    /* execute.simd:3572 [D] s_b_3_15 = s_b_3_3[s_b_3_14] <= s_b_3_13 */
    auto s_b_3_15 = emitter.vector_insert(s_b_3_3, emitter.const_s32((int32_t)0ULL), s_b_3_13);
    /* ???:4294967295 [F] s_b_3_16 = constant u8 1 (const) */
    /* execute.simd:3572 [D] s_b_3_15[s_b_3_16] */
    auto s_b_3_17 = emitter.vector_extract(s_b_3_15, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3572 [F] s_b_3_18 = constant u32 2 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_18] */
    auto s_b_3_19 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3572 [D] s_b_3_20 = (u16)s_b_3_19 */
    auto s_b_3_20 = emitter.zx(s_b_3_19, emitter.context().types().u16());
    /* execute.simd:3572 [F] s_b_3_21 = constant u32 3 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_21] */
    auto s_b_3_22 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3572 [D] s_b_3_23 = (u16)s_b_3_22 */
    auto s_b_3_23 = emitter.zx(s_b_3_22, emitter.context().types().u16());
    /* execute.simd:3572 [D] s_b_3_24 = s_b_3_20+s_b_3_23 */
    auto s_b_3_24 = emitter.add(s_b_3_20, s_b_3_23);
    /* ???:4294967295 [D] s_b_3_25 = s_b_3_17+s_b_3_24 */
    auto s_b_3_25 = emitter.add(s_b_3_17, s_b_3_24);
    /* execute.simd:3572 [F] s_b_3_26 = constant s32 1 (const) */
    /* execute.simd:3572 [D] s_b_3_27 = s_b_3_15[s_b_3_26] <= s_b_3_25 */
    auto s_b_3_27 = emitter.vector_insert(s_b_3_15, emitter.const_s32((int32_t)1ULL), s_b_3_25);
    /* ???:4294967295 [F] s_b_3_28 = constant u8 2 (const) */
    /* execute.simd:3572 [D] s_b_3_27[s_b_3_28] */
    auto s_b_3_29 = emitter.vector_extract(s_b_3_27, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3572 [F] s_b_3_30 = constant u32 4 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_30] */
    auto s_b_3_31 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:3572 [D] s_b_3_32 = (u16)s_b_3_31 */
    auto s_b_3_32 = emitter.zx(s_b_3_31, emitter.context().types().u16());
    /* execute.simd:3572 [F] s_b_3_33 = constant u32 5 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_33] */
    auto s_b_3_34 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:3572 [D] s_b_3_35 = (u16)s_b_3_34 */
    auto s_b_3_35 = emitter.zx(s_b_3_34, emitter.context().types().u16());
    /* execute.simd:3572 [D] s_b_3_36 = s_b_3_32+s_b_3_35 */
    auto s_b_3_36 = emitter.add(s_b_3_32, s_b_3_35);
    /* ???:4294967295 [D] s_b_3_37 = s_b_3_29+s_b_3_36 */
    auto s_b_3_37 = emitter.add(s_b_3_29, s_b_3_36);
    /* execute.simd:3572 [F] s_b_3_38 = constant s32 2 (const) */
    /* execute.simd:3572 [D] s_b_3_39 = s_b_3_27[s_b_3_38] <= s_b_3_37 */
    auto s_b_3_39 = emitter.vector_insert(s_b_3_27, emitter.const_s32((int32_t)2ULL), s_b_3_37);
    /* ???:4294967295 [F] s_b_3_40 = constant u8 3 (const) */
    /* execute.simd:3572 [D] s_b_3_39[s_b_3_40] */
    auto s_b_3_41 = emitter.vector_extract(s_b_3_39, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3572 [F] s_b_3_42 = constant u32 6 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_42] */
    auto s_b_3_43 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:3572 [D] s_b_3_44 = (u16)s_b_3_43 */
    auto s_b_3_44 = emitter.zx(s_b_3_43, emitter.context().types().u16());
    /* execute.simd:3572 [F] s_b_3_45 = constant u32 7 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_45] */
    auto s_b_3_46 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:3572 [D] s_b_3_47 = (u16)s_b_3_46 */
    auto s_b_3_47 = emitter.zx(s_b_3_46, emitter.context().types().u16());
    /* execute.simd:3572 [D] s_b_3_48 = s_b_3_44+s_b_3_47 */
    auto s_b_3_48 = emitter.add(s_b_3_44, s_b_3_47);
    /* ???:4294967295 [D] s_b_3_49 = s_b_3_41+s_b_3_48 */
    auto s_b_3_49 = emitter.add(s_b_3_41, s_b_3_48);
    /* execute.simd:3572 [F] s_b_3_50 = constant s32 3 (const) */
    /* execute.simd:3572 [D] s_b_3_51 = s_b_3_39[s_b_3_50] <= s_b_3_49 */
    auto s_b_3_51 = emitter.vector_insert(s_b_3_39, emitter.const_s32((int32_t)3ULL), s_b_3_49);
    /* ???:4294967295 [F] s_b_3_52 = constant u8 4 (const) */
    /* execute.simd:3572 [D] s_b_3_51[s_b_3_52] */
    auto s_b_3_53 = emitter.vector_extract(s_b_3_51, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:3572 [F] s_b_3_54 = constant u32 8 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_54] */
    auto s_b_3_55 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:3572 [D] s_b_3_56 = (u16)s_b_3_55 */
    auto s_b_3_56 = emitter.zx(s_b_3_55, emitter.context().types().u16());
    /* execute.simd:3572 [F] s_b_3_57 = constant u32 9 (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_57] */
    auto s_b_3_58 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:3572 [D] s_b_3_59 = (u16)s_b_3_58 */
    auto s_b_3_59 = emitter.zx(s_b_3_58, emitter.context().types().u16());
    /* execute.simd:3572 [D] s_b_3_60 = s_b_3_56+s_b_3_59 */
    auto s_b_3_60 = emitter.add(s_b_3_56, s_b_3_59);
    /* ???:4294967295 [D] s_b_3_61 = s_b_3_53+s_b_3_60 */
    auto s_b_3_61 = emitter.add(s_b_3_53, s_b_3_60);
    /* execute.simd:3572 [F] s_b_3_62 = constant s32 4 (const) */
    /* execute.simd:3572 [D] s_b_3_63 = s_b_3_51[s_b_3_62] <= s_b_3_61 */
    auto s_b_3_63 = emitter.vector_insert(s_b_3_51, emitter.const_s32((int32_t)4ULL), s_b_3_61);
    /* ???:4294967295 [F] s_b_3_64 = constant u8 5 (const) */
    /* execute.simd:3572 [D] s_b_3_63[s_b_3_64] */
    auto s_b_3_65 = emitter.vector_extract(s_b_3_63, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:3572 [F] s_b_3_66 = constant u32 a (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_66] */
    auto s_b_3_67 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:3572 [D] s_b_3_68 = (u16)s_b_3_67 */
    auto s_b_3_68 = emitter.zx(s_b_3_67, emitter.context().types().u16());
    /* execute.simd:3572 [F] s_b_3_69 = constant u32 b (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_69] */
    auto s_b_3_70 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:3572 [D] s_b_3_71 = (u16)s_b_3_70 */
    auto s_b_3_71 = emitter.zx(s_b_3_70, emitter.context().types().u16());
    /* execute.simd:3572 [D] s_b_3_72 = s_b_3_68+s_b_3_71 */
    auto s_b_3_72 = emitter.add(s_b_3_68, s_b_3_71);
    /* ???:4294967295 [D] s_b_3_73 = s_b_3_65+s_b_3_72 */
    auto s_b_3_73 = emitter.add(s_b_3_65, s_b_3_72);
    /* execute.simd:3572 [F] s_b_3_74 = constant s32 5 (const) */
    /* execute.simd:3572 [D] s_b_3_75 = s_b_3_63[s_b_3_74] <= s_b_3_73 */
    auto s_b_3_75 = emitter.vector_insert(s_b_3_63, emitter.const_s32((int32_t)5ULL), s_b_3_73);
    /* ???:4294967295 [F] s_b_3_76 = constant u8 6 (const) */
    /* execute.simd:3572 [D] s_b_3_75[s_b_3_76] */
    auto s_b_3_77 = emitter.vector_extract(s_b_3_75, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:3572 [F] s_b_3_78 = constant u32 c (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_78] */
    auto s_b_3_79 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:3572 [D] s_b_3_80 = (u16)s_b_3_79 */
    auto s_b_3_80 = emitter.zx(s_b_3_79, emitter.context().types().u16());
    /* execute.simd:3572 [F] s_b_3_81 = constant u32 d (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_81] */
    auto s_b_3_82 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:3572 [D] s_b_3_83 = (u16)s_b_3_82 */
    auto s_b_3_83 = emitter.zx(s_b_3_82, emitter.context().types().u16());
    /* execute.simd:3572 [D] s_b_3_84 = s_b_3_80+s_b_3_83 */
    auto s_b_3_84 = emitter.add(s_b_3_80, s_b_3_83);
    /* ???:4294967295 [D] s_b_3_85 = s_b_3_77+s_b_3_84 */
    auto s_b_3_85 = emitter.add(s_b_3_77, s_b_3_84);
    /* execute.simd:3572 [F] s_b_3_86 = constant s32 6 (const) */
    /* execute.simd:3572 [D] s_b_3_87 = s_b_3_75[s_b_3_86] <= s_b_3_85 */
    auto s_b_3_87 = emitter.vector_insert(s_b_3_75, emitter.const_s32((int32_t)6ULL), s_b_3_85);
    /* ???:4294967295 [F] s_b_3_88 = constant u8 7 (const) */
    /* execute.simd:3572 [D] s_b_3_87[s_b_3_88] */
    auto s_b_3_89 = emitter.vector_extract(s_b_3_87, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:3572 [F] s_b_3_90 = constant u32 e (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_90] */
    auto s_b_3_91 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:3572 [D] s_b_3_92 = (u16)s_b_3_91 */
    auto s_b_3_92 = emitter.zx(s_b_3_91, emitter.context().types().u16());
    /* execute.simd:3572 [F] s_b_3_93 = constant u32 f (const) */
    /* execute.simd:3572 [D] s_b_3_1[s_b_3_93] */
    auto s_b_3_94 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:3572 [D] s_b_3_95 = (u16)s_b_3_94 */
    auto s_b_3_95 = emitter.zx(s_b_3_94, emitter.context().types().u16());
    /* execute.simd:3572 [D] s_b_3_96 = s_b_3_92+s_b_3_95 */
    auto s_b_3_96 = emitter.add(s_b_3_92, s_b_3_95);
    /* ???:4294967295 [D] s_b_3_97 = s_b_3_89+s_b_3_96 */
    auto s_b_3_97 = emitter.add(s_b_3_89, s_b_3_96);
    /* execute.simd:3572 [F] s_b_3_98 = constant s32 7 (const) */
    /* execute.simd:3572 [D] s_b_3_99 = s_b_3_87[s_b_3_98] <= s_b_3_97 */
    auto s_b_3_99 = emitter.vector_insert(s_b_3_87, emitter.const_s32((int32_t)7ULL), s_b_3_97);
    /* execute.simd:3575 [F] s_b_3_100=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3575 [D] s_b_3_101: WriteRegBank 18:s_b_3_100 = s_b_3_99 */
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
    /* execute.simd:3579 [F] s_b_4_0=sym_36464_3_parameter_inst.rn (const) */
    /* execute.simd:3579 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:3580 [F] s_b_4_2=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3580 [D] s_b_4_3 = ReadRegBank 19:s_b_4_2 (v2u32) */
    auto s_b_4_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_3,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_4_4 = constant u8 0 (const) */
    /* execute.simd:3583 [D] s_b_4_3[s_b_4_4] */
    auto s_b_4_5 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3583 [F] s_b_4_6 = constant u32 0 (const) */
    /* execute.simd:3583 [D] s_b_4_1[s_b_4_6] */
    auto s_b_4_7 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3583 [D] s_b_4_8 = (u32)s_b_4_7 */
    auto s_b_4_8 = emitter.zx(s_b_4_7, emitter.context().types().u32());
    /* execute.simd:3583 [F] s_b_4_9 = constant u32 1 (const) */
    /* execute.simd:3583 [D] s_b_4_1[s_b_4_9] */
    auto s_b_4_10 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3583 [D] s_b_4_11 = (u32)s_b_4_10 */
    auto s_b_4_11 = emitter.zx(s_b_4_10, emitter.context().types().u32());
    /* execute.simd:3583 [D] s_b_4_12 = s_b_4_8+s_b_4_11 */
    auto s_b_4_12 = emitter.add(s_b_4_8, s_b_4_11);
    /* ???:4294967295 [D] s_b_4_13 = s_b_4_5+s_b_4_12 */
    auto s_b_4_13 = emitter.add(s_b_4_5, s_b_4_12);
    /* execute.simd:3583 [F] s_b_4_14 = constant s32 0 (const) */
    /* execute.simd:3583 [D] s_b_4_15 = s_b_4_3[s_b_4_14] <= s_b_4_13 */
    auto s_b_4_15 = emitter.vector_insert(s_b_4_3, emitter.const_s32((int32_t)0ULL), s_b_4_13);
    /* ???:4294967295 [F] s_b_4_16 = constant u8 1 (const) */
    /* execute.simd:3583 [D] s_b_4_15[s_b_4_16] */
    auto s_b_4_17 = emitter.vector_extract(s_b_4_15, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3583 [F] s_b_4_18 = constant u32 2 (const) */
    /* execute.simd:3583 [D] s_b_4_1[s_b_4_18] */
    auto s_b_4_19 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3583 [D] s_b_4_20 = (u32)s_b_4_19 */
    auto s_b_4_20 = emitter.zx(s_b_4_19, emitter.context().types().u32());
    /* execute.simd:3583 [F] s_b_4_21 = constant u32 3 (const) */
    /* execute.simd:3583 [D] s_b_4_1[s_b_4_21] */
    auto s_b_4_22 = emitter.vector_extract(s_b_4_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3583 [D] s_b_4_23 = (u32)s_b_4_22 */
    auto s_b_4_23 = emitter.zx(s_b_4_22, emitter.context().types().u32());
    /* execute.simd:3583 [D] s_b_4_24 = s_b_4_20+s_b_4_23 */
    auto s_b_4_24 = emitter.add(s_b_4_20, s_b_4_23);
    /* ???:4294967295 [D] s_b_4_25 = s_b_4_17+s_b_4_24 */
    auto s_b_4_25 = emitter.add(s_b_4_17, s_b_4_24);
    /* execute.simd:3583 [F] s_b_4_26 = constant s32 1 (const) */
    /* execute.simd:3583 [D] s_b_4_27 = s_b_4_15[s_b_4_26] <= s_b_4_25 */
    auto s_b_4_27 = emitter.vector_insert(s_b_4_15, emitter.const_s32((int32_t)1ULL), s_b_4_25);
    /* execute.simd:3586 [F] s_b_4_28=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3586 [D] s_b_4_29: WriteRegBank 19:s_b_4_28 = s_b_4_27 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_27,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_27);
    /* execute.simd:3587 [F] s_b_4_30=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3587 [F] s_b_4_31 = constant u64 0 (const) */
    /* execute.simd:3587 [F] s_b_4_32: WriteRegBank 3:s_b_4_30 = s_b_4_31 */
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
    /* execute.simd:3591 [F] s_b_5_0=sym_36464_3_parameter_inst.rn (const) */
    /* execute.simd:3591 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:3592 [F] s_b_5_2=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3592 [D] s_b_5_3 = ReadRegBank 20:s_b_5_2 (v4u32) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant u8 0 (const) */
    /* execute.simd:3595 [D] s_b_5_3[s_b_5_4] */
    auto s_b_5_5 = emitter.vector_extract(s_b_5_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:3595 [F] s_b_5_6 = constant u32 0 (const) */
    /* execute.simd:3595 [D] s_b_5_1[s_b_5_6] */
    auto s_b_5_7 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:3595 [D] s_b_5_8 = (u32)s_b_5_7 */
    auto s_b_5_8 = emitter.zx(s_b_5_7, emitter.context().types().u32());
    /* execute.simd:3595 [F] s_b_5_9 = constant u32 1 (const) */
    /* execute.simd:3595 [D] s_b_5_1[s_b_5_9] */
    auto s_b_5_10 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)1ULL));
    /* execute.simd:3595 [D] s_b_5_11 = (u32)s_b_5_10 */
    auto s_b_5_11 = emitter.zx(s_b_5_10, emitter.context().types().u32());
    /* execute.simd:3595 [D] s_b_5_12 = s_b_5_8+s_b_5_11 */
    auto s_b_5_12 = emitter.add(s_b_5_8, s_b_5_11);
    /* ???:4294967295 [D] s_b_5_13 = s_b_5_5+s_b_5_12 */
    auto s_b_5_13 = emitter.add(s_b_5_5, s_b_5_12);
    /* execute.simd:3595 [F] s_b_5_14 = constant s32 0 (const) */
    /* execute.simd:3595 [D] s_b_5_15 = s_b_5_3[s_b_5_14] <= s_b_5_13 */
    auto s_b_5_15 = emitter.vector_insert(s_b_5_3, emitter.const_s32((int32_t)0ULL), s_b_5_13);
    /* ???:4294967295 [F] s_b_5_16 = constant u8 1 (const) */
    /* execute.simd:3595 [D] s_b_5_15[s_b_5_16] */
    auto s_b_5_17 = emitter.vector_extract(s_b_5_15, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:3595 [F] s_b_5_18 = constant u32 2 (const) */
    /* execute.simd:3595 [D] s_b_5_1[s_b_5_18] */
    auto s_b_5_19 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:3595 [D] s_b_5_20 = (u32)s_b_5_19 */
    auto s_b_5_20 = emitter.zx(s_b_5_19, emitter.context().types().u32());
    /* execute.simd:3595 [F] s_b_5_21 = constant u32 3 (const) */
    /* execute.simd:3595 [D] s_b_5_1[s_b_5_21] */
    auto s_b_5_22 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:3595 [D] s_b_5_23 = (u32)s_b_5_22 */
    auto s_b_5_23 = emitter.zx(s_b_5_22, emitter.context().types().u32());
    /* execute.simd:3595 [D] s_b_5_24 = s_b_5_20+s_b_5_23 */
    auto s_b_5_24 = emitter.add(s_b_5_20, s_b_5_23);
    /* ???:4294967295 [D] s_b_5_25 = s_b_5_17+s_b_5_24 */
    auto s_b_5_25 = emitter.add(s_b_5_17, s_b_5_24);
    /* execute.simd:3595 [F] s_b_5_26 = constant s32 1 (const) */
    /* execute.simd:3595 [D] s_b_5_27 = s_b_5_15[s_b_5_26] <= s_b_5_25 */
    auto s_b_5_27 = emitter.vector_insert(s_b_5_15, emitter.const_s32((int32_t)1ULL), s_b_5_25);
    /* ???:4294967295 [F] s_b_5_28 = constant u8 2 (const) */
    /* execute.simd:3595 [D] s_b_5_27[s_b_5_28] */
    auto s_b_5_29 = emitter.vector_extract(s_b_5_27, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:3595 [F] s_b_5_30 = constant u32 4 (const) */
    /* execute.simd:3595 [D] s_b_5_1[s_b_5_30] */
    auto s_b_5_31 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:3595 [D] s_b_5_32 = (u32)s_b_5_31 */
    auto s_b_5_32 = emitter.zx(s_b_5_31, emitter.context().types().u32());
    /* execute.simd:3595 [F] s_b_5_33 = constant u32 5 (const) */
    /* execute.simd:3595 [D] s_b_5_1[s_b_5_33] */
    auto s_b_5_34 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:3595 [D] s_b_5_35 = (u32)s_b_5_34 */
    auto s_b_5_35 = emitter.zx(s_b_5_34, emitter.context().types().u32());
    /* execute.simd:3595 [D] s_b_5_36 = s_b_5_32+s_b_5_35 */
    auto s_b_5_36 = emitter.add(s_b_5_32, s_b_5_35);
    /* ???:4294967295 [D] s_b_5_37 = s_b_5_29+s_b_5_36 */
    auto s_b_5_37 = emitter.add(s_b_5_29, s_b_5_36);
    /* execute.simd:3595 [F] s_b_5_38 = constant s32 2 (const) */
    /* execute.simd:3595 [D] s_b_5_39 = s_b_5_27[s_b_5_38] <= s_b_5_37 */
    auto s_b_5_39 = emitter.vector_insert(s_b_5_27, emitter.const_s32((int32_t)2ULL), s_b_5_37);
    /* ???:4294967295 [F] s_b_5_40 = constant u8 3 (const) */
    /* execute.simd:3595 [D] s_b_5_39[s_b_5_40] */
    auto s_b_5_41 = emitter.vector_extract(s_b_5_39, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:3595 [F] s_b_5_42 = constant u32 6 (const) */
    /* execute.simd:3595 [D] s_b_5_1[s_b_5_42] */
    auto s_b_5_43 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:3595 [D] s_b_5_44 = (u32)s_b_5_43 */
    auto s_b_5_44 = emitter.zx(s_b_5_43, emitter.context().types().u32());
    /* execute.simd:3595 [F] s_b_5_45 = constant u32 7 (const) */
    /* execute.simd:3595 [D] s_b_5_1[s_b_5_45] */
    auto s_b_5_46 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:3595 [D] s_b_5_47 = (u32)s_b_5_46 */
    auto s_b_5_47 = emitter.zx(s_b_5_46, emitter.context().types().u32());
    /* execute.simd:3595 [D] s_b_5_48 = s_b_5_44+s_b_5_47 */
    auto s_b_5_48 = emitter.add(s_b_5_44, s_b_5_47);
    /* ???:4294967295 [D] s_b_5_49 = s_b_5_41+s_b_5_48 */
    auto s_b_5_49 = emitter.add(s_b_5_41, s_b_5_48);
    /* execute.simd:3595 [F] s_b_5_50 = constant s32 3 (const) */
    /* execute.simd:3595 [D] s_b_5_51 = s_b_5_39[s_b_5_50] <= s_b_5_49 */
    auto s_b_5_51 = emitter.vector_insert(s_b_5_39, emitter.const_s32((int32_t)3ULL), s_b_5_49);
    /* execute.simd:3598 [F] s_b_5_52=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3598 [D] s_b_5_53: WriteRegBank 20:s_b_5_52 = s_b_5_51 */
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
    /* execute.simd:3602 [F] s_b_6_0=sym_36464_3_parameter_inst.rn (const) */
    /* execute.simd:3602 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:3603 [F] s_b_6_2=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3603 [D] s_b_6_3 = ReadRegBank 21:s_b_6_2 (v2u64) */
    auto s_b_6_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_3,emitter.const_u8(16));
    }
    /* execute.simd:3605 [F] s_b_6_4 = constant s32 0 (const) */
    /* execute.simd:3605 [D] s_b_6_3[s_b_6_4] */
    auto s_b_6_5 = emitter.vector_extract(s_b_6_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3605 [F] s_b_6_6 = constant s32 0 (const) */
    /* execute.simd:3605 [D] s_b_6_1[s_b_6_6] */
    auto s_b_6_7 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3605 [D] s_b_6_8 = (u64)s_b_6_7 */
    auto s_b_6_8 = emitter.zx(s_b_6_7, emitter.context().types().u64());
    /* execute.simd:3605 [F] s_b_6_9 = constant s32 1 (const) */
    /* execute.simd:3605 [D] s_b_6_1[s_b_6_9] */
    auto s_b_6_10 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:3605 [D] s_b_6_11 = (u64)s_b_6_10 */
    auto s_b_6_11 = emitter.zx(s_b_6_10, emitter.context().types().u64());
    /* execute.simd:3605 [D] s_b_6_12 = s_b_6_8+s_b_6_11 */
    auto s_b_6_12 = emitter.add(s_b_6_8, s_b_6_11);
    /* ???:4294967295 [D] s_b_6_13 = s_b_6_5+s_b_6_12 */
    auto s_b_6_13 = emitter.add(s_b_6_5, s_b_6_12);
    /* execute.simd:3605 [F] s_b_6_14 = constant s32 0 (const) */
    /* execute.simd:3605 [D] s_b_6_15 = s_b_6_3[s_b_6_14] <= s_b_6_13 */
    auto s_b_6_15 = emitter.vector_insert(s_b_6_3, emitter.const_s32((int32_t)0ULL), s_b_6_13);
    /* execute.simd:3606 [F] s_b_6_16 = constant s32 1 (const) */
    /* execute.simd:3606 [F] s_b_6_17 = constant u64 0 (const) */
    /* execute.simd:3606 [D] s_b_6_18 = s_b_6_15[s_b_6_16] <= s_b_6_17 */
    auto s_b_6_18 = emitter.vector_insert(s_b_6_15, emitter.const_s32((int32_t)1ULL), emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:3608 [F] s_b_6_19=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3608 [D] s_b_6_20: WriteRegBank 21:s_b_6_19 = s_b_6_18 */
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
    /* execute.simd:3612 [F] s_b_7_0=sym_36464_3_parameter_inst.rn (const) */
    /* execute.simd:3612 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:3613 [F] s_b_7_2=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3613 [D] s_b_7_3 = ReadRegBank 21:s_b_7_2 (v2u64) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_7_3,emitter.const_u8(16));
    }
    /* execute.simd:3615 [F] s_b_7_4 = constant s32 0 (const) */
    /* execute.simd:3615 [D] s_b_7_3[s_b_7_4] */
    auto s_b_7_5 = emitter.vector_extract(s_b_7_3, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3615 [F] s_b_7_6 = constant s32 0 (const) */
    /* execute.simd:3615 [D] s_b_7_1[s_b_7_6] */
    auto s_b_7_7 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:3615 [D] s_b_7_8 = (u64)s_b_7_7 */
    auto s_b_7_8 = emitter.zx(s_b_7_7, emitter.context().types().u64());
    /* execute.simd:3615 [F] s_b_7_9 = constant s32 1 (const) */
    /* execute.simd:3615 [D] s_b_7_1[s_b_7_9] */
    auto s_b_7_10 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:3615 [D] s_b_7_11 = (u64)s_b_7_10 */
    auto s_b_7_11 = emitter.zx(s_b_7_10, emitter.context().types().u64());
    /* execute.simd:3615 [D] s_b_7_12 = s_b_7_8+s_b_7_11 */
    auto s_b_7_12 = emitter.add(s_b_7_8, s_b_7_11);
    /* ???:4294967295 [D] s_b_7_13 = s_b_7_5+s_b_7_12 */
    auto s_b_7_13 = emitter.add(s_b_7_5, s_b_7_12);
    /* execute.simd:3615 [F] s_b_7_14 = constant s32 0 (const) */
    /* execute.simd:3615 [D] s_b_7_15 = s_b_7_3[s_b_7_14] <= s_b_7_13 */
    auto s_b_7_15 = emitter.vector_insert(s_b_7_3, emitter.const_s32((int32_t)0ULL), s_b_7_13);
    /* execute.simd:3616 [F] s_b_7_16 = constant s32 1 (const) */
    /* execute.simd:3616 [D] s_b_7_15[s_b_7_16] */
    auto s_b_7_17 = emitter.vector_extract(s_b_7_15, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:3616 [F] s_b_7_18 = constant s32 2 (const) */
    /* execute.simd:3616 [D] s_b_7_1[s_b_7_18] */
    auto s_b_7_19 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:3616 [D] s_b_7_20 = (u64)s_b_7_19 */
    auto s_b_7_20 = emitter.zx(s_b_7_19, emitter.context().types().u64());
    /* execute.simd:3616 [F] s_b_7_21 = constant s32 3 (const) */
    /* execute.simd:3616 [D] s_b_7_1[s_b_7_21] */
    auto s_b_7_22 = emitter.vector_extract(s_b_7_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:3616 [D] s_b_7_23 = (u64)s_b_7_22 */
    auto s_b_7_23 = emitter.zx(s_b_7_22, emitter.context().types().u64());
    /* execute.simd:3616 [D] s_b_7_24 = s_b_7_20+s_b_7_23 */
    auto s_b_7_24 = emitter.add(s_b_7_20, s_b_7_23);
    /* ???:4294967295 [D] s_b_7_25 = s_b_7_17+s_b_7_24 */
    auto s_b_7_25 = emitter.add(s_b_7_17, s_b_7_24);
    /* execute.simd:3616 [F] s_b_7_26 = constant s32 1 (const) */
    /* execute.simd:3616 [D] s_b_7_27 = s_b_7_15[s_b_7_26] <= s_b_7_25 */
    auto s_b_7_27 = emitter.vector_insert(s_b_7_15, emitter.const_s32((int32_t)1ULL), s_b_7_25);
    /* execute.simd:3618 [F] s_b_7_28=sym_36464_3_parameter_inst.rd (const) */
    /* execute.simd:3618 [D] s_b_7_29: WriteRegBank 21:s_b_7_28 = s_b_7_27 */
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
    /* execute.simd:3622 [D] s_b_8_0 = trap */
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
template<bool TRACE>bool arm64_jit2<TRACE>::translate_a64_ucvtf_simd(const arm64_decode_a64_SIMD_TWO_REG_MISC&insn, captive::arch::dbt::el::Emitter& emitter)
{
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:4381 [F] s_b_0_0=sym_39943_3_parameter_inst.SCALAR (const) */
    /* execute.simd:4381 [F] s_b_0_1: If s_b_0_0: Jump b_1 else b_3 (const) */
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
    /* execute.simd:4382 [F] s_b_1_0=sym_39943_3_parameter_inst.size (const) */
    /* execute.simd:4382 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.simd:4382 [F] s_b_1_2 = constant u32 0 (const) */
    /* execute.simd:4382 [F] s_b_1_3 = s_b_1_1==s_b_1_2 (const) */
    uint8_t s_b_1_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4382 [F] s_b_1_4: If s_b_1_3: Jump b_4 else b_5 (const) */
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
    /* execute.simd:4390 [F] s_b_3_0=sym_39943_3_parameter_inst.size (const) */
    /* execute.simd:4390 [F] s_b_3_1 = (u32)s_b_3_0 (const) */
    /* execute.simd:4390 [F] s_b_3_2 = constant u32 0 (const) */
    /* execute.simd:4390 [F] s_b_3_3 = s_b_3_1==s_b_3_2 (const) */
    uint8_t s_b_3_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4390 [F] s_b_3_4=sym_39943_3_parameter_inst.Q (const) */
    /* execute.simd:4390 [F] s_b_3_5 = (u32)s_b_3_4 (const) */
    /* execute.simd:4390 [F] s_b_3_6 = constant u32 0 (const) */
    /* execute.simd:4390 [F] s_b_3_7 = s_b_3_5==s_b_3_6 (const) */
    uint8_t s_b_3_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)0ULL));
    /* ???:4294967295 [F] s_b_3_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_3_9 = s_b_3_3!=s_b_3_8 (const) */
    uint8_t s_b_3_9 = ((uint8_t)(s_b_3_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_10 = s_b_3_7!=s_b_3_8 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(s_b_3_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_3_11 = s_b_3_9&s_b_3_10 (const) */
    uint8_t s_b_3_11 = ((uint8_t)(s_b_3_9 & s_b_3_10));
    /* execute.simd:4390 [F] s_b_3_12: If s_b_3_11: Jump b_6 else b_7 (const) */
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
    /* execute.simd:4384 [F] s_b_4_0=sym_39943_3_parameter_inst.rd (const) */
    /* execute.simd:4384 [F] s_b_4_1=sym_39943_3_parameter_inst.rn (const) */
    /* execute.simd:6350 [D] s_b_4_2 = ReadRegBank 6:s_b_4_1 (u32) */
    auto s_b_4_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_2,emitter.const_u8(4));
    }
    /* execute.simd:4384 [D] s_b_4_3 = (u32)s_b_4_2 */
    auto s_b_4_3 = (captive::arch::dbt::el::Value *)s_b_4_2;
    /* execute.simd:4384 [D] s_b_4_4 = (f32)s_b_4_3 */
    auto s_b_4_4 = emitter.convert(s_b_4_3, emitter.context().types().f32());
    /* execute.simd:6290 [D] s_b_4_5: WriteRegBank 9:s_b_4_0 = s_b_4_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4,emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_4_4);
    /* execute.simd:6291 [F] s_b_4_6 = constant u32 0 (const) */
    /* execute.simd:6291 [F] s_b_4_7: WriteRegBank 10:s_b_4_0 = s_b_4_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL),emitter.const_u8(4));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(260 + (16 * insn.rd))),emitter.const_u32((uint32_t)0ULL));
    /* execute.simd:6292 [F] s_b_4_8 = constant u64 0 (const) */
    /* execute.simd:6292 [F] s_b_4_9: WriteRegBank 3:s_b_4_0 = s_b_4_8 */
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
    /* execute.simd:4387 [F] s_b_5_0=sym_39943_3_parameter_inst.rd (const) */
    /* execute.simd:4387 [F] s_b_5_1=sym_39943_3_parameter_inst.rn (const) */
    /* execute.simd:6355 [D] s_b_5_2 = ReadRegBank 7:s_b_5_1 (u64) */
    auto s_b_5_2 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_2,emitter.const_u8(8));
    }
    /* execute.simd:4387 [D] s_b_5_3 = (u64)s_b_5_2 */
    auto s_b_5_3 = (captive::arch::dbt::el::Value *)s_b_5_2;
    /* execute.simd:4387 [D] s_b_5_4 = (f64)s_b_5_3 */
    auto s_b_5_4 = emitter.convert(s_b_5_3, emitter.context().types().f64());
    /* execute.simd:6298 [D] s_b_5_5: WriteRegBank 11:s_b_5_0 = s_b_5_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_5_4);
    /* execute.simd:6299 [F] s_b_5_6 = constant u64 0 (const) */
    /* execute.simd:6299 [F] s_b_5_7: WriteRegBank 3:s_b_5_0 = s_b_5_6 */
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
    /* execute.simd:4391 [F] s_b_6_0=sym_39943_3_parameter_inst.rn (const) */
    /* execute.simd:4391 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [F] s_b_6_2 = constant v2f32 
    {
    }
    (const) */
    /* execute.simd:4394 [F] s_b_6_3 = constant s32 0 (const) */
    /* execute.simd:4394 [D] s_b_6_1[s_b_6_3] */
    auto s_b_6_4 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4394 [D] s_b_6_5 = (f32)s_b_6_4 */
    auto s_b_6_5 = emitter.convert(s_b_6_4, emitter.context().types().f32());
    /* execute.simd:4394 [F] s_b_6_6 = constant s32 0 (const) */
    /* execute.simd:4394 [D] s_b_6_7 = s_b_6_2[s_b_6_6] <= s_b_6_5 */
    auto s_b_6_7 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<float, 2>(0.000000)[0], emitter.context().types().v2f32()), emitter.const_s32((int32_t)0ULL), s_b_6_5);
    /* execute.simd:4395 [F] s_b_6_8 = constant s32 1 (const) */
    /* execute.simd:4395 [D] s_b_6_1[s_b_6_8] */
    auto s_b_6_9 = emitter.vector_extract(s_b_6_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4395 [D] s_b_6_10 = (f32)s_b_6_9 */
    auto s_b_6_10 = emitter.convert(s_b_6_9, emitter.context().types().f32());
    /* execute.simd:4395 [F] s_b_6_11 = constant s32 1 (const) */
    /* execute.simd:4395 [D] s_b_6_12 = s_b_6_7[s_b_6_11] <= s_b_6_10 */
    auto s_b_6_12 = emitter.vector_insert(s_b_6_7, emitter.const_s32((int32_t)1ULL), s_b_6_10);
    /* execute.simd:4397 [F] s_b_6_13=sym_39943_3_parameter_inst.rd (const) */
    /* execute.simd:4397 [D] s_b_6_14: WriteRegBank 12:s_b_6_13 = s_b_6_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_6_12);
    /* execute.simd:4398 [F] s_b_6_15=sym_39943_3_parameter_inst.rd (const) */
    /* execute.simd:4398 [F] s_b_6_16 = constant u64 0 (const) */
    /* execute.simd:4398 [F] s_b_6_17: WriteRegBank 3:s_b_6_15 = s_b_6_16 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL),emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(264 + (16 * insn.rd))),emitter.const_u64((uint64_t)0ULL));
    /* execute.simd:4391 [F] s_b_6_18: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_3,  */
  fixed_block_b_7: 
  {
    /* execute.simd:4399 [F] s_b_7_0=sym_39943_3_parameter_inst.size (const) */
    /* execute.simd:4399 [F] s_b_7_1 = (u32)s_b_7_0 (const) */
    /* execute.simd:4399 [F] s_b_7_2 = constant u32 0 (const) */
    /* execute.simd:4399 [F] s_b_7_3 = s_b_7_1==s_b_7_2 (const) */
    uint8_t s_b_7_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:4399 [F] s_b_7_4=sym_39943_3_parameter_inst.Q (const) */
    /* execute.simd:4399 [F] s_b_7_5 = (u32)s_b_7_4 (const) */
    /* execute.simd:4399 [F] s_b_7_6 = constant u32 1 (const) */
    /* execute.simd:4399 [F] s_b_7_7 = s_b_7_5==s_b_7_6 (const) */
    uint8_t s_b_7_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_7_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_7_9 = s_b_7_3!=s_b_7_8 (const) */
    uint8_t s_b_7_9 = ((uint8_t)(s_b_7_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_10 = s_b_7_7!=s_b_7_8 (const) */
    uint8_t s_b_7_10 = ((uint8_t)(s_b_7_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_7_11 = s_b_7_9&s_b_7_10 (const) */
    uint8_t s_b_7_11 = ((uint8_t)(s_b_7_9 & s_b_7_10));
    /* execute.simd:4399 [F] s_b_7_12: If s_b_7_11: Jump b_8 else b_9 (const) */
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
    /* execute.simd:4400 [F] s_b_8_0=sym_39943_3_parameter_inst.rn (const) */
    /* execute.simd:4400 [D] s_b_8_1 = ReadRegBank 20:s_b_8_0 (v4u32) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_8_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_8_2 = constant v4f32 
    {
    }
    (const) */
    /* execute.simd:4403 [F] s_b_8_3 = constant s32 0 (const) */
    /* execute.simd:4403 [D] s_b_8_1[s_b_8_3] */
    auto s_b_8_4 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4403 [D] s_b_8_5 = (f32)s_b_8_4 */
    auto s_b_8_5 = emitter.convert(s_b_8_4, emitter.context().types().f32());
    /* execute.simd:4403 [F] s_b_8_6 = constant s32 0 (const) */
    /* execute.simd:4403 [D] s_b_8_7 = s_b_8_2[s_b_8_6] <= s_b_8_5 */
    auto s_b_8_7 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<float, 4>(0.000000)[0], emitter.context().types().v4f32()), emitter.const_s32((int32_t)0ULL), s_b_8_5);
    /* execute.simd:4404 [F] s_b_8_8 = constant s32 1 (const) */
    /* execute.simd:4404 [D] s_b_8_1[s_b_8_8] */
    auto s_b_8_9 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4404 [D] s_b_8_10 = (f32)s_b_8_9 */
    auto s_b_8_10 = emitter.convert(s_b_8_9, emitter.context().types().f32());
    /* execute.simd:4404 [F] s_b_8_11 = constant s32 1 (const) */
    /* execute.simd:4404 [D] s_b_8_12 = s_b_8_7[s_b_8_11] <= s_b_8_10 */
    auto s_b_8_12 = emitter.vector_insert(s_b_8_7, emitter.const_s32((int32_t)1ULL), s_b_8_10);
    /* execute.simd:4405 [F] s_b_8_13 = constant s32 2 (const) */
    /* execute.simd:4405 [D] s_b_8_1[s_b_8_13] */
    auto s_b_8_14 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)2ULL));
    /* execute.simd:4405 [D] s_b_8_15 = (f32)s_b_8_14 */
    auto s_b_8_15 = emitter.convert(s_b_8_14, emitter.context().types().f32());
    /* execute.simd:4405 [F] s_b_8_16 = constant s32 2 (const) */
    /* execute.simd:4405 [D] s_b_8_17 = s_b_8_12[s_b_8_16] <= s_b_8_15 */
    auto s_b_8_17 = emitter.vector_insert(s_b_8_12, emitter.const_s32((int32_t)2ULL), s_b_8_15);
    /* execute.simd:4406 [F] s_b_8_18 = constant s32 3 (const) */
    /* execute.simd:4406 [D] s_b_8_1[s_b_8_18] */
    auto s_b_8_19 = emitter.vector_extract(s_b_8_1, emitter.const_s32((int32_t)3ULL));
    /* execute.simd:4406 [D] s_b_8_20 = (f32)s_b_8_19 */
    auto s_b_8_20 = emitter.convert(s_b_8_19, emitter.context().types().f32());
    /* execute.simd:4406 [F] s_b_8_21 = constant s32 3 (const) */
    /* execute.simd:4406 [D] s_b_8_22 = s_b_8_17[s_b_8_21] <= s_b_8_20 */
    auto s_b_8_22 = emitter.vector_insert(s_b_8_17, emitter.const_s32((int32_t)3ULL), s_b_8_20);
    /* execute.simd:4408 [F] s_b_8_23=sym_39943_3_parameter_inst.rd (const) */
    /* execute.simd:4408 [D] s_b_8_24: WriteRegBank 13:s_b_8_23 = s_b_8_22 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_22,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_8_22);
    /* execute.simd:4400 [F] s_b_8_25: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_7,  */
  fixed_block_b_9: 
  {
    /* execute.simd:4409 [F] s_b_9_0=sym_39943_3_parameter_inst.size (const) */
    /* execute.simd:4409 [F] s_b_9_1 = (u32)s_b_9_0 (const) */
    /* execute.simd:4409 [F] s_b_9_2 = constant u32 1 (const) */
    /* execute.simd:4409 [F] s_b_9_3 = s_b_9_1==s_b_9_2 (const) */
    uint8_t s_b_9_3 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)1ULL));
    /* execute.simd:4409 [F] s_b_9_4=sym_39943_3_parameter_inst.Q (const) */
    /* execute.simd:4409 [F] s_b_9_5 = (u32)s_b_9_4 (const) */
    /* execute.simd:4409 [F] s_b_9_6 = constant u32 1 (const) */
    /* execute.simd:4409 [F] s_b_9_7 = s_b_9_5==s_b_9_6 (const) */
    uint8_t s_b_9_7 = ((uint8_t)(((uint32_t)insn.Q) == (uint32_t)1ULL));
    /* ???:4294967295 [F] s_b_9_8 = constant u8 0 (const) */
    /* ???:4294967295 [F] s_b_9_9 = s_b_9_3!=s_b_9_8 (const) */
    uint8_t s_b_9_9 = ((uint8_t)(s_b_9_3 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_10 = s_b_9_7!=s_b_9_8 (const) */
    uint8_t s_b_9_10 = ((uint8_t)(s_b_9_7 != (uint8_t)0ULL));
    /* ???:4294967295 [F] s_b_9_11 = s_b_9_9&s_b_9_10 (const) */
    uint8_t s_b_9_11 = ((uint8_t)(s_b_9_9 & s_b_9_10));
    /* execute.simd:4409 [F] s_b_9_12: If s_b_9_11: Jump b_10 else b_11 (const) */
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
    /* execute.simd:4410 [F] s_b_10_0=sym_39943_3_parameter_inst.rn (const) */
    /* execute.simd:4410 [D] s_b_10_1 = ReadRegBank 21:s_b_10_0 (v2u64) */
    auto s_b_10_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_10_1,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_10_2 = constant v2f64 
    {
    }
    (const) */
    /* execute.simd:4413 [F] s_b_10_3 = constant s32 0 (const) */
    /* execute.simd:4413 [D] s_b_10_1[s_b_10_3] */
    auto s_b_10_4 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)0ULL));
    /* execute.simd:4413 [D] s_b_10_5 = (f64)s_b_10_4 */
    auto s_b_10_5 = emitter.convert(s_b_10_4, emitter.context().types().f64());
    /* execute.simd:4413 [F] s_b_10_6 = constant s32 0 (const) */
    /* execute.simd:4413 [D] s_b_10_7 = s_b_10_2[s_b_10_6] <= s_b_10_5 */
    auto s_b_10_7 = emitter.vector_insert(emitter.constant_vector_splat_f(wutils::Vector<double, 2>(0.000000)[0], emitter.context().types().v2f64()), emitter.const_s32((int32_t)0ULL), s_b_10_5);
    /* execute.simd:4414 [F] s_b_10_8 = constant s32 1 (const) */
    /* execute.simd:4414 [D] s_b_10_1[s_b_10_8] */
    auto s_b_10_9 = emitter.vector_extract(s_b_10_1, emitter.const_s32((int32_t)1ULL));
    /* execute.simd:4414 [D] s_b_10_10 = (f64)s_b_10_9 */
    auto s_b_10_10 = emitter.convert(s_b_10_9, emitter.context().types().f64());
    /* execute.simd:4414 [F] s_b_10_11 = constant s32 1 (const) */
    /* execute.simd:4414 [D] s_b_10_12 = s_b_10_7[s_b_10_11] <= s_b_10_10 */
    auto s_b_10_12 = emitter.vector_insert(s_b_10_7, emitter.const_s32((int32_t)1ULL), s_b_10_10);
    /* execute.simd:4416 [F] s_b_10_13=sym_39943_3_parameter_inst.rd (const) */
    /* execute.simd:4416 [D] s_b_10_14: WriteRegBank 14:s_b_10_13 = s_b_10_12 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_12,emitter.const_u8(16));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rd))),s_b_10_12);
    /* execute.simd:4410 [F] s_b_10_15: Jump b_2 (const) */
    goto fixed_block_b_2;
  }
  /* b_9,  */
  fixed_block_b_11: 
  {
    /* execute.simd:4418 [D] s_b_11_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:4418 [F] s_b_11_1: Jump b_2 (const) */
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
    /* execute.simd:5438 [F] s_b_0_0=sym_41150_3_parameter_inst.tb (const) */
    /* execute.simd:5439 [F] s_b_0_1 = constant s32 0 (const) */
    /* execute.simd:5452 [F] s_b_0_2 = constant s32 1 (const) */
    /* execute.simd:5465 [F] s_b_0_3 = constant s32 2 (const) */
    /* execute.simd:5478 [F] s_b_0_4 = constant s32 3 (const) */
    /* execute.simd:5491 [F] s_b_0_5 = constant s32 4 (const) */
    /* execute.simd:5504 [F] s_b_0_6 = constant s32 5 (const) */
    /* execute.simd:5438 [F] s_b_0_7: Switch s_b_0_0: < <todo> > def b_8 (const) -> b_2, b_3, b_4, b_5, b_6, b_7, b_8,  */
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
    /* execute.simd:5440 [F] s_b_2_0=sym_41150_3_parameter_inst.rn (const) */
    /* execute.simd:5440 [D] s_b_2_1 = ReadRegBank 15:s_b_2_0 (v8u8) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* execute.simd:5441 [F] s_b_2_2=sym_41150_3_parameter_inst.rm (const) */
    /* execute.simd:5441 [D] s_b_2_3 = ReadRegBank 15:s_b_2_2 (v8u8) */
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
    /* execute.simd:5446 [D] s_b_2_1[s_b_2_5] */
    auto s_b_2_6 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5446 [D] s_b_2_7 = (u16)s_b_2_6 */
    auto s_b_2_7 = emitter.zx(s_b_2_6, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_8 = constant u8 0 (const) */
    /* execute.simd:5446 [D] s_b_2_3[s_b_2_8] */
    auto s_b_2_9 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5446 [D] s_b_2_10 = (u16)s_b_2_9 */
    auto s_b_2_10 = emitter.zx(s_b_2_9, emitter.context().types().u16());
    /* execute.simd:5446 [D] s_b_2_11 = s_b_2_7*s_b_2_10 */
    auto s_b_2_11 = emitter.mul(s_b_2_7, s_b_2_10);
    /* execute.simd:5446 [F] s_b_2_12 = constant s32 0 (const) */
    /* execute.simd:5446 [D] s_b_2_13 = s_b_2_4[s_b_2_12] <= s_b_2_11 */
    auto s_b_2_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_2_11);
    /* ???:4294967295 [F] s_b_2_14 = constant u8 1 (const) */
    /* execute.simd:5446 [D] s_b_2_1[s_b_2_14] */
    auto s_b_2_15 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5446 [D] s_b_2_16 = (u16)s_b_2_15 */
    auto s_b_2_16 = emitter.zx(s_b_2_15, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_17 = constant u8 1 (const) */
    /* execute.simd:5446 [D] s_b_2_3[s_b_2_17] */
    auto s_b_2_18 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5446 [D] s_b_2_19 = (u16)s_b_2_18 */
    auto s_b_2_19 = emitter.zx(s_b_2_18, emitter.context().types().u16());
    /* execute.simd:5446 [D] s_b_2_20 = s_b_2_16*s_b_2_19 */
    auto s_b_2_20 = emitter.mul(s_b_2_16, s_b_2_19);
    /* execute.simd:5446 [F] s_b_2_21 = constant s32 1 (const) */
    /* execute.simd:5446 [D] s_b_2_22 = s_b_2_13[s_b_2_21] <= s_b_2_20 */
    auto s_b_2_22 = emitter.vector_insert(s_b_2_13, emitter.const_s32((int32_t)1ULL), s_b_2_20);
    /* ???:4294967295 [F] s_b_2_23 = constant u8 2 (const) */
    /* execute.simd:5446 [D] s_b_2_1[s_b_2_23] */
    auto s_b_2_24 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5446 [D] s_b_2_25 = (u16)s_b_2_24 */
    auto s_b_2_25 = emitter.zx(s_b_2_24, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_26 = constant u8 2 (const) */
    /* execute.simd:5446 [D] s_b_2_3[s_b_2_26] */
    auto s_b_2_27 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5446 [D] s_b_2_28 = (u16)s_b_2_27 */
    auto s_b_2_28 = emitter.zx(s_b_2_27, emitter.context().types().u16());
    /* execute.simd:5446 [D] s_b_2_29 = s_b_2_25*s_b_2_28 */
    auto s_b_2_29 = emitter.mul(s_b_2_25, s_b_2_28);
    /* execute.simd:5446 [F] s_b_2_30 = constant s32 2 (const) */
    /* execute.simd:5446 [D] s_b_2_31 = s_b_2_22[s_b_2_30] <= s_b_2_29 */
    auto s_b_2_31 = emitter.vector_insert(s_b_2_22, emitter.const_s32((int32_t)2ULL), s_b_2_29);
    /* ???:4294967295 [F] s_b_2_32 = constant u8 3 (const) */
    /* execute.simd:5446 [D] s_b_2_1[s_b_2_32] */
    auto s_b_2_33 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5446 [D] s_b_2_34 = (u16)s_b_2_33 */
    auto s_b_2_34 = emitter.zx(s_b_2_33, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_35 = constant u8 3 (const) */
    /* execute.simd:5446 [D] s_b_2_3[s_b_2_35] */
    auto s_b_2_36 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5446 [D] s_b_2_37 = (u16)s_b_2_36 */
    auto s_b_2_37 = emitter.zx(s_b_2_36, emitter.context().types().u16());
    /* execute.simd:5446 [D] s_b_2_38 = s_b_2_34*s_b_2_37 */
    auto s_b_2_38 = emitter.mul(s_b_2_34, s_b_2_37);
    /* execute.simd:5446 [F] s_b_2_39 = constant s32 3 (const) */
    /* execute.simd:5446 [D] s_b_2_40 = s_b_2_31[s_b_2_39] <= s_b_2_38 */
    auto s_b_2_40 = emitter.vector_insert(s_b_2_31, emitter.const_s32((int32_t)3ULL), s_b_2_38);
    /* ???:4294967295 [F] s_b_2_41 = constant u8 4 (const) */
    /* execute.simd:5446 [D] s_b_2_1[s_b_2_41] */
    auto s_b_2_42 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5446 [D] s_b_2_43 = (u16)s_b_2_42 */
    auto s_b_2_43 = emitter.zx(s_b_2_42, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_44 = constant u8 4 (const) */
    /* execute.simd:5446 [D] s_b_2_3[s_b_2_44] */
    auto s_b_2_45 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)4ULL));
    /* execute.simd:5446 [D] s_b_2_46 = (u16)s_b_2_45 */
    auto s_b_2_46 = emitter.zx(s_b_2_45, emitter.context().types().u16());
    /* execute.simd:5446 [D] s_b_2_47 = s_b_2_43*s_b_2_46 */
    auto s_b_2_47 = emitter.mul(s_b_2_43, s_b_2_46);
    /* execute.simd:5446 [F] s_b_2_48 = constant s32 4 (const) */
    /* execute.simd:5446 [D] s_b_2_49 = s_b_2_40[s_b_2_48] <= s_b_2_47 */
    auto s_b_2_49 = emitter.vector_insert(s_b_2_40, emitter.const_s32((int32_t)4ULL), s_b_2_47);
    /* ???:4294967295 [F] s_b_2_50 = constant u8 5 (const) */
    /* execute.simd:5446 [D] s_b_2_1[s_b_2_50] */
    auto s_b_2_51 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5446 [D] s_b_2_52 = (u16)s_b_2_51 */
    auto s_b_2_52 = emitter.zx(s_b_2_51, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_53 = constant u8 5 (const) */
    /* execute.simd:5446 [D] s_b_2_3[s_b_2_53] */
    auto s_b_2_54 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)5ULL));
    /* execute.simd:5446 [D] s_b_2_55 = (u16)s_b_2_54 */
    auto s_b_2_55 = emitter.zx(s_b_2_54, emitter.context().types().u16());
    /* execute.simd:5446 [D] s_b_2_56 = s_b_2_52*s_b_2_55 */
    auto s_b_2_56 = emitter.mul(s_b_2_52, s_b_2_55);
    /* execute.simd:5446 [F] s_b_2_57 = constant s32 5 (const) */
    /* execute.simd:5446 [D] s_b_2_58 = s_b_2_49[s_b_2_57] <= s_b_2_56 */
    auto s_b_2_58 = emitter.vector_insert(s_b_2_49, emitter.const_s32((int32_t)5ULL), s_b_2_56);
    /* ???:4294967295 [F] s_b_2_59 = constant u8 6 (const) */
    /* execute.simd:5446 [D] s_b_2_1[s_b_2_59] */
    auto s_b_2_60 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5446 [D] s_b_2_61 = (u16)s_b_2_60 */
    auto s_b_2_61 = emitter.zx(s_b_2_60, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_62 = constant u8 6 (const) */
    /* execute.simd:5446 [D] s_b_2_3[s_b_2_62] */
    auto s_b_2_63 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)6ULL));
    /* execute.simd:5446 [D] s_b_2_64 = (u16)s_b_2_63 */
    auto s_b_2_64 = emitter.zx(s_b_2_63, emitter.context().types().u16());
    /* execute.simd:5446 [D] s_b_2_65 = s_b_2_61*s_b_2_64 */
    auto s_b_2_65 = emitter.mul(s_b_2_61, s_b_2_64);
    /* execute.simd:5446 [F] s_b_2_66 = constant s32 6 (const) */
    /* execute.simd:5446 [D] s_b_2_67 = s_b_2_58[s_b_2_66] <= s_b_2_65 */
    auto s_b_2_67 = emitter.vector_insert(s_b_2_58, emitter.const_s32((int32_t)6ULL), s_b_2_65);
    /* ???:4294967295 [F] s_b_2_68 = constant u8 7 (const) */
    /* execute.simd:5446 [D] s_b_2_1[s_b_2_68] */
    auto s_b_2_69 = emitter.vector_extract(s_b_2_1, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5446 [D] s_b_2_70 = (u16)s_b_2_69 */
    auto s_b_2_70 = emitter.zx(s_b_2_69, emitter.context().types().u16());
    /* ???:4294967295 [F] s_b_2_71 = constant u8 7 (const) */
    /* execute.simd:5446 [D] s_b_2_3[s_b_2_71] */
    auto s_b_2_72 = emitter.vector_extract(s_b_2_3, emitter.const_u8((uint8_t)7ULL));
    /* execute.simd:5446 [D] s_b_2_73 = (u16)s_b_2_72 */
    auto s_b_2_73 = emitter.zx(s_b_2_72, emitter.context().types().u16());
    /* execute.simd:5446 [D] s_b_2_74 = s_b_2_70*s_b_2_73 */
    auto s_b_2_74 = emitter.mul(s_b_2_70, s_b_2_73);
    /* execute.simd:5446 [F] s_b_2_75 = constant s32 7 (const) */
    /* execute.simd:5446 [D] s_b_2_76 = s_b_2_67[s_b_2_75] <= s_b_2_74 */
    auto s_b_2_76 = emitter.vector_insert(s_b_2_67, emitter.const_s32((int32_t)7ULL), s_b_2_74);
    /* execute.simd:5449 [F] s_b_2_77=sym_41150_3_parameter_inst.rd (const) */
    /* execute.simd:5449 [D] s_b_2_78: WriteRegBank 18:s_b_2_77 = s_b_2_76 */
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
    /* execute.simd:5453 [F] s_b_3_0=sym_41150_3_parameter_inst.rn (const) */
    /* execute.simd:5453 [D] s_b_3_1 = ReadRegBank 16:s_b_3_0 (v16u8) */
    auto s_b_3_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_3_1,emitter.const_u8(16));
    }
    /* execute.simd:5454 [F] s_b_3_2=sym_41150_3_parameter_inst.rm (const) */
    /* execute.simd:5454 [D] s_b_3_3 = ReadRegBank 16:s_b_3_2 (v16u8) */
    auto s_b_3_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v16u8());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_3_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_3_4 = constant v8u16 
    {
    }
    (const) */
    /* execute.simd:5459 [F] s_b_3_5 = constant u32 8 (const) */
    /* execute.simd:5459 [D] s_b_3_1[s_b_3_5] */
    auto s_b_3_6 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5459 [D] s_b_3_7 = (u16)s_b_3_6 */
    auto s_b_3_7 = emitter.zx(s_b_3_6, emitter.context().types().u16());
    /* execute.simd:5459 [F] s_b_3_8 = constant u32 8 (const) */
    /* execute.simd:5459 [D] s_b_3_3[s_b_3_8] */
    auto s_b_3_9 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)8ULL));
    /* execute.simd:5459 [D] s_b_3_10 = (u16)s_b_3_9 */
    auto s_b_3_10 = emitter.zx(s_b_3_9, emitter.context().types().u16());
    /* execute.simd:5459 [D] s_b_3_11 = s_b_3_7*s_b_3_10 */
    auto s_b_3_11 = emitter.mul(s_b_3_7, s_b_3_10);
    /* execute.simd:5459 [F] s_b_3_12 = constant s32 0 (const) */
    /* execute.simd:5459 [D] s_b_3_13 = s_b_3_4[s_b_3_12] <= s_b_3_11 */
    auto s_b_3_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint16_t, 8>(0)[0], emitter.context().types().v8u16()), emitter.const_s32((int32_t)0ULL), s_b_3_11);
    /* execute.simd:5459 [F] s_b_3_14 = constant u32 9 (const) */
    /* execute.simd:5459 [D] s_b_3_1[s_b_3_14] */
    auto s_b_3_15 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5459 [D] s_b_3_16 = (u16)s_b_3_15 */
    auto s_b_3_16 = emitter.zx(s_b_3_15, emitter.context().types().u16());
    /* execute.simd:5459 [F] s_b_3_17 = constant u32 9 (const) */
    /* execute.simd:5459 [D] s_b_3_3[s_b_3_17] */
    auto s_b_3_18 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)9ULL));
    /* execute.simd:5459 [D] s_b_3_19 = (u16)s_b_3_18 */
    auto s_b_3_19 = emitter.zx(s_b_3_18, emitter.context().types().u16());
    /* execute.simd:5459 [D] s_b_3_20 = s_b_3_16*s_b_3_19 */
    auto s_b_3_20 = emitter.mul(s_b_3_16, s_b_3_19);
    /* execute.simd:5459 [F] s_b_3_21 = constant s32 1 (const) */
    /* execute.simd:5459 [D] s_b_3_22 = s_b_3_13[s_b_3_21] <= s_b_3_20 */
    auto s_b_3_22 = emitter.vector_insert(s_b_3_13, emitter.const_s32((int32_t)1ULL), s_b_3_20);
    /* execute.simd:5459 [F] s_b_3_23 = constant u32 a (const) */
    /* execute.simd:5459 [D] s_b_3_1[s_b_3_23] */
    auto s_b_3_24 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5459 [D] s_b_3_25 = (u16)s_b_3_24 */
    auto s_b_3_25 = emitter.zx(s_b_3_24, emitter.context().types().u16());
    /* execute.simd:5459 [F] s_b_3_26 = constant u32 a (const) */
    /* execute.simd:5459 [D] s_b_3_3[s_b_3_26] */
    auto s_b_3_27 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)10ULL));
    /* execute.simd:5459 [D] s_b_3_28 = (u16)s_b_3_27 */
    auto s_b_3_28 = emitter.zx(s_b_3_27, emitter.context().types().u16());
    /* execute.simd:5459 [D] s_b_3_29 = s_b_3_25*s_b_3_28 */
    auto s_b_3_29 = emitter.mul(s_b_3_25, s_b_3_28);
    /* execute.simd:5459 [F] s_b_3_30 = constant s32 2 (const) */
    /* execute.simd:5459 [D] s_b_3_31 = s_b_3_22[s_b_3_30] <= s_b_3_29 */
    auto s_b_3_31 = emitter.vector_insert(s_b_3_22, emitter.const_s32((int32_t)2ULL), s_b_3_29);
    /* execute.simd:5459 [F] s_b_3_32 = constant u32 b (const) */
    /* execute.simd:5459 [D] s_b_3_1[s_b_3_32] */
    auto s_b_3_33 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5459 [D] s_b_3_34 = (u16)s_b_3_33 */
    auto s_b_3_34 = emitter.zx(s_b_3_33, emitter.context().types().u16());
    /* execute.simd:5459 [F] s_b_3_35 = constant u32 b (const) */
    /* execute.simd:5459 [D] s_b_3_3[s_b_3_35] */
    auto s_b_3_36 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)11ULL));
    /* execute.simd:5459 [D] s_b_3_37 = (u16)s_b_3_36 */
    auto s_b_3_37 = emitter.zx(s_b_3_36, emitter.context().types().u16());
    /* execute.simd:5459 [D] s_b_3_38 = s_b_3_34*s_b_3_37 */
    auto s_b_3_38 = emitter.mul(s_b_3_34, s_b_3_37);
    /* execute.simd:5459 [F] s_b_3_39 = constant s32 3 (const) */
    /* execute.simd:5459 [D] s_b_3_40 = s_b_3_31[s_b_3_39] <= s_b_3_38 */
    auto s_b_3_40 = emitter.vector_insert(s_b_3_31, emitter.const_s32((int32_t)3ULL), s_b_3_38);
    /* execute.simd:5459 [F] s_b_3_41 = constant u32 c (const) */
    /* execute.simd:5459 [D] s_b_3_1[s_b_3_41] */
    auto s_b_3_42 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5459 [D] s_b_3_43 = (u16)s_b_3_42 */
    auto s_b_3_43 = emitter.zx(s_b_3_42, emitter.context().types().u16());
    /* execute.simd:5459 [F] s_b_3_44 = constant u32 c (const) */
    /* execute.simd:5459 [D] s_b_3_3[s_b_3_44] */
    auto s_b_3_45 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)12ULL));
    /* execute.simd:5459 [D] s_b_3_46 = (u16)s_b_3_45 */
    auto s_b_3_46 = emitter.zx(s_b_3_45, emitter.context().types().u16());
    /* execute.simd:5459 [D] s_b_3_47 = s_b_3_43*s_b_3_46 */
    auto s_b_3_47 = emitter.mul(s_b_3_43, s_b_3_46);
    /* execute.simd:5459 [F] s_b_3_48 = constant s32 4 (const) */
    /* execute.simd:5459 [D] s_b_3_49 = s_b_3_40[s_b_3_48] <= s_b_3_47 */
    auto s_b_3_49 = emitter.vector_insert(s_b_3_40, emitter.const_s32((int32_t)4ULL), s_b_3_47);
    /* execute.simd:5459 [F] s_b_3_50 = constant u32 d (const) */
    /* execute.simd:5459 [D] s_b_3_1[s_b_3_50] */
    auto s_b_3_51 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5459 [D] s_b_3_52 = (u16)s_b_3_51 */
    auto s_b_3_52 = emitter.zx(s_b_3_51, emitter.context().types().u16());
    /* execute.simd:5459 [F] s_b_3_53 = constant u32 d (const) */
    /* execute.simd:5459 [D] s_b_3_3[s_b_3_53] */
    auto s_b_3_54 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)13ULL));
    /* execute.simd:5459 [D] s_b_3_55 = (u16)s_b_3_54 */
    auto s_b_3_55 = emitter.zx(s_b_3_54, emitter.context().types().u16());
    /* execute.simd:5459 [D] s_b_3_56 = s_b_3_52*s_b_3_55 */
    auto s_b_3_56 = emitter.mul(s_b_3_52, s_b_3_55);
    /* execute.simd:5459 [F] s_b_3_57 = constant s32 5 (const) */
    /* execute.simd:5459 [D] s_b_3_58 = s_b_3_49[s_b_3_57] <= s_b_3_56 */
    auto s_b_3_58 = emitter.vector_insert(s_b_3_49, emitter.const_s32((int32_t)5ULL), s_b_3_56);
    /* execute.simd:5459 [F] s_b_3_59 = constant u32 e (const) */
    /* execute.simd:5459 [D] s_b_3_1[s_b_3_59] */
    auto s_b_3_60 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5459 [D] s_b_3_61 = (u16)s_b_3_60 */
    auto s_b_3_61 = emitter.zx(s_b_3_60, emitter.context().types().u16());
    /* execute.simd:5459 [F] s_b_3_62 = constant u32 e (const) */
    /* execute.simd:5459 [D] s_b_3_3[s_b_3_62] */
    auto s_b_3_63 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)14ULL));
    /* execute.simd:5459 [D] s_b_3_64 = (u16)s_b_3_63 */
    auto s_b_3_64 = emitter.zx(s_b_3_63, emitter.context().types().u16());
    /* execute.simd:5459 [D] s_b_3_65 = s_b_3_61*s_b_3_64 */
    auto s_b_3_65 = emitter.mul(s_b_3_61, s_b_3_64);
    /* execute.simd:5459 [F] s_b_3_66 = constant s32 6 (const) */
    /* execute.simd:5459 [D] s_b_3_67 = s_b_3_58[s_b_3_66] <= s_b_3_65 */
    auto s_b_3_67 = emitter.vector_insert(s_b_3_58, emitter.const_s32((int32_t)6ULL), s_b_3_65);
    /* execute.simd:5459 [F] s_b_3_68 = constant u32 f (const) */
    /* execute.simd:5459 [D] s_b_3_1[s_b_3_68] */
    auto s_b_3_69 = emitter.vector_extract(s_b_3_1, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5459 [D] s_b_3_70 = (u16)s_b_3_69 */
    auto s_b_3_70 = emitter.zx(s_b_3_69, emitter.context().types().u16());
    /* execute.simd:5459 [F] s_b_3_71 = constant u32 f (const) */
    /* execute.simd:5459 [D] s_b_3_3[s_b_3_71] */
    auto s_b_3_72 = emitter.vector_extract(s_b_3_3, emitter.const_u32((uint32_t)15ULL));
    /* execute.simd:5459 [D] s_b_3_73 = (u16)s_b_3_72 */
    auto s_b_3_73 = emitter.zx(s_b_3_72, emitter.context().types().u16());
    /* execute.simd:5459 [D] s_b_3_74 = s_b_3_70*s_b_3_73 */
    auto s_b_3_74 = emitter.mul(s_b_3_70, s_b_3_73);
    /* execute.simd:5459 [F] s_b_3_75 = constant s32 7 (const) */
    /* execute.simd:5459 [D] s_b_3_76 = s_b_3_67[s_b_3_75] <= s_b_3_74 */
    auto s_b_3_76 = emitter.vector_insert(s_b_3_67, emitter.const_s32((int32_t)7ULL), s_b_3_74);
    /* execute.simd:5462 [F] s_b_3_77=sym_41150_3_parameter_inst.rd (const) */
    /* execute.simd:5462 [D] s_b_3_78: WriteRegBank 18:s_b_3_77 = s_b_3_76 */
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
    /* execute.simd:5466 [F] s_b_4_0=sym_41150_3_parameter_inst.rn (const) */
    /* execute.simd:5466 [D] s_b_4_1 = ReadRegBank 17:s_b_4_0 (v4u16) */
    auto s_b_4_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_4_1,emitter.const_u8(8));
    }
    /* execute.simd:5467 [F] s_b_4_2=sym_41150_3_parameter_inst.rm (const) */
    /* execute.simd:5467 [D] s_b_4_3 = ReadRegBank 17:s_b_4_2 (v4u16) */
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
    /* execute.simd:5472 [D] s_b_4_1[s_b_4_5] */
    auto s_b_4_6 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5472 [D] s_b_4_7 = (u32)s_b_4_6 */
    auto s_b_4_7 = emitter.zx(s_b_4_6, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_8 = constant u8 0 (const) */
    /* execute.simd:5472 [D] s_b_4_3[s_b_4_8] */
    auto s_b_4_9 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5472 [D] s_b_4_10 = (u32)s_b_4_9 */
    auto s_b_4_10 = emitter.zx(s_b_4_9, emitter.context().types().u32());
    /* execute.simd:5472 [D] s_b_4_11 = s_b_4_7*s_b_4_10 */
    auto s_b_4_11 = emitter.mul(s_b_4_7, s_b_4_10);
    /* execute.simd:5472 [F] s_b_4_12 = constant s32 0 (const) */
    /* execute.simd:5472 [D] s_b_4_13 = s_b_4_4[s_b_4_12] <= s_b_4_11 */
    auto s_b_4_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_4_11);
    /* ???:4294967295 [F] s_b_4_14 = constant u8 1 (const) */
    /* execute.simd:5472 [D] s_b_4_1[s_b_4_14] */
    auto s_b_4_15 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5472 [D] s_b_4_16 = (u32)s_b_4_15 */
    auto s_b_4_16 = emitter.zx(s_b_4_15, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_17 = constant u8 1 (const) */
    /* execute.simd:5472 [D] s_b_4_3[s_b_4_17] */
    auto s_b_4_18 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5472 [D] s_b_4_19 = (u32)s_b_4_18 */
    auto s_b_4_19 = emitter.zx(s_b_4_18, emitter.context().types().u32());
    /* execute.simd:5472 [D] s_b_4_20 = s_b_4_16*s_b_4_19 */
    auto s_b_4_20 = emitter.mul(s_b_4_16, s_b_4_19);
    /* execute.simd:5472 [F] s_b_4_21 = constant s32 1 (const) */
    /* execute.simd:5472 [D] s_b_4_22 = s_b_4_13[s_b_4_21] <= s_b_4_20 */
    auto s_b_4_22 = emitter.vector_insert(s_b_4_13, emitter.const_s32((int32_t)1ULL), s_b_4_20);
    /* ???:4294967295 [F] s_b_4_23 = constant u8 2 (const) */
    /* execute.simd:5472 [D] s_b_4_1[s_b_4_23] */
    auto s_b_4_24 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5472 [D] s_b_4_25 = (u32)s_b_4_24 */
    auto s_b_4_25 = emitter.zx(s_b_4_24, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_26 = constant u8 2 (const) */
    /* execute.simd:5472 [D] s_b_4_3[s_b_4_26] */
    auto s_b_4_27 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)2ULL));
    /* execute.simd:5472 [D] s_b_4_28 = (u32)s_b_4_27 */
    auto s_b_4_28 = emitter.zx(s_b_4_27, emitter.context().types().u32());
    /* execute.simd:5472 [D] s_b_4_29 = s_b_4_25*s_b_4_28 */
    auto s_b_4_29 = emitter.mul(s_b_4_25, s_b_4_28);
    /* execute.simd:5472 [F] s_b_4_30 = constant s32 2 (const) */
    /* execute.simd:5472 [D] s_b_4_31 = s_b_4_22[s_b_4_30] <= s_b_4_29 */
    auto s_b_4_31 = emitter.vector_insert(s_b_4_22, emitter.const_s32((int32_t)2ULL), s_b_4_29);
    /* ???:4294967295 [F] s_b_4_32 = constant u8 3 (const) */
    /* execute.simd:5472 [D] s_b_4_1[s_b_4_32] */
    auto s_b_4_33 = emitter.vector_extract(s_b_4_1, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5472 [D] s_b_4_34 = (u32)s_b_4_33 */
    auto s_b_4_34 = emitter.zx(s_b_4_33, emitter.context().types().u32());
    /* ???:4294967295 [F] s_b_4_35 = constant u8 3 (const) */
    /* execute.simd:5472 [D] s_b_4_3[s_b_4_35] */
    auto s_b_4_36 = emitter.vector_extract(s_b_4_3, emitter.const_u8((uint8_t)3ULL));
    /* execute.simd:5472 [D] s_b_4_37 = (u32)s_b_4_36 */
    auto s_b_4_37 = emitter.zx(s_b_4_36, emitter.context().types().u32());
    /* execute.simd:5472 [D] s_b_4_38 = s_b_4_34*s_b_4_37 */
    auto s_b_4_38 = emitter.mul(s_b_4_34, s_b_4_37);
    /* execute.simd:5472 [F] s_b_4_39 = constant s32 3 (const) */
    /* execute.simd:5472 [D] s_b_4_40 = s_b_4_31[s_b_4_39] <= s_b_4_38 */
    auto s_b_4_40 = emitter.vector_insert(s_b_4_31, emitter.const_s32((int32_t)3ULL), s_b_4_38);
    /* execute.simd:5475 [F] s_b_4_41=sym_41150_3_parameter_inst.rd (const) */
    /* execute.simd:5475 [D] s_b_4_42: WriteRegBank 20:s_b_4_41 = s_b_4_40 */
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
    /* execute.simd:5479 [F] s_b_5_0=sym_41150_3_parameter_inst.rn (const) */
    /* execute.simd:5479 [D] s_b_5_1 = ReadRegBank 18:s_b_5_0 (v8u16) */
    auto s_b_5_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_5_1,emitter.const_u8(16));
    }
    /* execute.simd:5480 [F] s_b_5_2=sym_41150_3_parameter_inst.rm (const) */
    /* execute.simd:5480 [D] s_b_5_3 = ReadRegBank 18:s_b_5_2 (v8u16) */
    auto s_b_5_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v8u16());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_5_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_5_4 = constant v4u32 
    {
    }
    (const) */
    /* execute.simd:5485 [F] s_b_5_5 = constant u32 4 (const) */
    /* execute.simd:5485 [D] s_b_5_1[s_b_5_5] */
    auto s_b_5_6 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5485 [D] s_b_5_7 = (u32)s_b_5_6 */
    auto s_b_5_7 = emitter.zx(s_b_5_6, emitter.context().types().u32());
    /* execute.simd:5485 [F] s_b_5_8 = constant u32 4 (const) */
    /* execute.simd:5485 [D] s_b_5_3[s_b_5_8] */
    auto s_b_5_9 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)4ULL));
    /* execute.simd:5485 [D] s_b_5_10 = (u32)s_b_5_9 */
    auto s_b_5_10 = emitter.zx(s_b_5_9, emitter.context().types().u32());
    /* execute.simd:5485 [D] s_b_5_11 = s_b_5_7*s_b_5_10 */
    auto s_b_5_11 = emitter.mul(s_b_5_7, s_b_5_10);
    /* execute.simd:5485 [F] s_b_5_12 = constant s32 0 (const) */
    /* execute.simd:5485 [D] s_b_5_13 = s_b_5_4[s_b_5_12] <= s_b_5_11 */
    auto s_b_5_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint32_t, 4>(0)[0], emitter.context().types().v4u32()), emitter.const_s32((int32_t)0ULL), s_b_5_11);
    /* execute.simd:5485 [F] s_b_5_14 = constant u32 5 (const) */
    /* execute.simd:5485 [D] s_b_5_1[s_b_5_14] */
    auto s_b_5_15 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5485 [D] s_b_5_16 = (u32)s_b_5_15 */
    auto s_b_5_16 = emitter.zx(s_b_5_15, emitter.context().types().u32());
    /* execute.simd:5485 [F] s_b_5_17 = constant u32 5 (const) */
    /* execute.simd:5485 [D] s_b_5_3[s_b_5_17] */
    auto s_b_5_18 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)5ULL));
    /* execute.simd:5485 [D] s_b_5_19 = (u32)s_b_5_18 */
    auto s_b_5_19 = emitter.zx(s_b_5_18, emitter.context().types().u32());
    /* execute.simd:5485 [D] s_b_5_20 = s_b_5_16*s_b_5_19 */
    auto s_b_5_20 = emitter.mul(s_b_5_16, s_b_5_19);
    /* execute.simd:5485 [F] s_b_5_21 = constant s32 1 (const) */
    /* execute.simd:5485 [D] s_b_5_22 = s_b_5_13[s_b_5_21] <= s_b_5_20 */
    auto s_b_5_22 = emitter.vector_insert(s_b_5_13, emitter.const_s32((int32_t)1ULL), s_b_5_20);
    /* execute.simd:5485 [F] s_b_5_23 = constant u32 6 (const) */
    /* execute.simd:5485 [D] s_b_5_1[s_b_5_23] */
    auto s_b_5_24 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5485 [D] s_b_5_25 = (u32)s_b_5_24 */
    auto s_b_5_25 = emitter.zx(s_b_5_24, emitter.context().types().u32());
    /* execute.simd:5485 [F] s_b_5_26 = constant u32 6 (const) */
    /* execute.simd:5485 [D] s_b_5_3[s_b_5_26] */
    auto s_b_5_27 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)6ULL));
    /* execute.simd:5485 [D] s_b_5_28 = (u32)s_b_5_27 */
    auto s_b_5_28 = emitter.zx(s_b_5_27, emitter.context().types().u32());
    /* execute.simd:5485 [D] s_b_5_29 = s_b_5_25*s_b_5_28 */
    auto s_b_5_29 = emitter.mul(s_b_5_25, s_b_5_28);
    /* execute.simd:5485 [F] s_b_5_30 = constant s32 2 (const) */
    /* execute.simd:5485 [D] s_b_5_31 = s_b_5_22[s_b_5_30] <= s_b_5_29 */
    auto s_b_5_31 = emitter.vector_insert(s_b_5_22, emitter.const_s32((int32_t)2ULL), s_b_5_29);
    /* execute.simd:5485 [F] s_b_5_32 = constant u32 7 (const) */
    /* execute.simd:5485 [D] s_b_5_1[s_b_5_32] */
    auto s_b_5_33 = emitter.vector_extract(s_b_5_1, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5485 [D] s_b_5_34 = (u32)s_b_5_33 */
    auto s_b_5_34 = emitter.zx(s_b_5_33, emitter.context().types().u32());
    /* execute.simd:5485 [F] s_b_5_35 = constant u32 7 (const) */
    /* execute.simd:5485 [D] s_b_5_3[s_b_5_35] */
    auto s_b_5_36 = emitter.vector_extract(s_b_5_3, emitter.const_u32((uint32_t)7ULL));
    /* execute.simd:5485 [D] s_b_5_37 = (u32)s_b_5_36 */
    auto s_b_5_37 = emitter.zx(s_b_5_36, emitter.context().types().u32());
    /* execute.simd:5485 [D] s_b_5_38 = s_b_5_34*s_b_5_37 */
    auto s_b_5_38 = emitter.mul(s_b_5_34, s_b_5_37);
    /* execute.simd:5485 [F] s_b_5_39 = constant s32 3 (const) */
    /* execute.simd:5485 [D] s_b_5_40 = s_b_5_31[s_b_5_39] <= s_b_5_38 */
    auto s_b_5_40 = emitter.vector_insert(s_b_5_31, emitter.const_s32((int32_t)3ULL), s_b_5_38);
    /* execute.simd:5488 [F] s_b_5_41=sym_41150_3_parameter_inst.rd (const) */
    /* execute.simd:5488 [D] s_b_5_42: WriteRegBank 20:s_b_5_41 = s_b_5_40 */
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
    /* execute.simd:5492 [F] s_b_6_0=sym_41150_3_parameter_inst.rn (const) */
    /* execute.simd:5492 [D] s_b_6_1 = ReadRegBank 19:s_b_6_0 (v2u32) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v2u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_6_1,emitter.const_u8(8));
    }
    /* execute.simd:5493 [F] s_b_6_2=sym_41150_3_parameter_inst.rm (const) */
    /* execute.simd:5493 [D] s_b_6_3 = ReadRegBank 19:s_b_6_2 (v2u32) */
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
    /* execute.simd:5498 [D] s_b_6_1[s_b_6_5] */
    auto s_b_6_6 = emitter.vector_extract(s_b_6_1, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5498 [D] s_b_6_7 = (u64)s_b_6_6 */
    auto s_b_6_7 = emitter.zx(s_b_6_6, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_8 = constant u8 0 (const) */
    /* execute.simd:5498 [D] s_b_6_3[s_b_6_8] */
    auto s_b_6_9 = emitter.vector_extract(s_b_6_3, emitter.const_u8((uint8_t)0ULL));
    /* execute.simd:5498 [D] s_b_6_10 = (u64)s_b_6_9 */
    auto s_b_6_10 = emitter.zx(s_b_6_9, emitter.context().types().u64());
    /* execute.simd:5498 [D] s_b_6_11 = s_b_6_7*s_b_6_10 */
    auto s_b_6_11 = emitter.mul(s_b_6_7, s_b_6_10);
    /* execute.simd:5498 [F] s_b_6_12 = constant s32 0 (const) */
    /* execute.simd:5498 [D] s_b_6_13 = s_b_6_4[s_b_6_12] <= s_b_6_11 */
    auto s_b_6_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_6_11);
    /* ???:4294967295 [F] s_b_6_14 = constant u8 1 (const) */
    /* execute.simd:5498 [D] s_b_6_1[s_b_6_14] */
    auto s_b_6_15 = emitter.vector_extract(s_b_6_1, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5498 [D] s_b_6_16 = (u64)s_b_6_15 */
    auto s_b_6_16 = emitter.zx(s_b_6_15, emitter.context().types().u64());
    /* ???:4294967295 [F] s_b_6_17 = constant u8 1 (const) */
    /* execute.simd:5498 [D] s_b_6_3[s_b_6_17] */
    auto s_b_6_18 = emitter.vector_extract(s_b_6_3, emitter.const_u8((uint8_t)1ULL));
    /* execute.simd:5498 [D] s_b_6_19 = (u64)s_b_6_18 */
    auto s_b_6_19 = emitter.zx(s_b_6_18, emitter.context().types().u64());
    /* execute.simd:5498 [D] s_b_6_20 = s_b_6_16*s_b_6_19 */
    auto s_b_6_20 = emitter.mul(s_b_6_16, s_b_6_19);
    /* execute.simd:5498 [F] s_b_6_21 = constant s32 1 (const) */
    /* execute.simd:5498 [D] s_b_6_22 = s_b_6_13[s_b_6_21] <= s_b_6_20 */
    auto s_b_6_22 = emitter.vector_insert(s_b_6_13, emitter.const_s32((int32_t)1ULL), s_b_6_20);
    /* execute.simd:5501 [F] s_b_6_23=sym_41150_3_parameter_inst.rd (const) */
    /* execute.simd:5501 [D] s_b_6_24: WriteRegBank 21:s_b_6_23 = s_b_6_22 */
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
    /* execute.simd:5505 [F] s_b_7_0=sym_41150_3_parameter_inst.rn (const) */
    /* execute.simd:5505 [D] s_b_7_1 = ReadRegBank 20:s_b_7_0 (v4u32) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rn))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rn))),s_b_7_1,emitter.const_u8(16));
    }
    /* execute.simd:5506 [F] s_b_7_2=sym_41150_3_parameter_inst.rm (const) */
    /* execute.simd:5506 [D] s_b_7_3 = ReadRegBank 20:s_b_7_2 (v4u32) */
    auto s_b_7_3 = emitter.load_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rm))), emitter.context().types().v4u32());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(256 + (16 * insn.rm))),s_b_7_3,emitter.const_u8(16));
    }
    /* ???:4294967295 [F] s_b_7_4 = constant v2u64 
    {
    }
    (const) */
    /* execute.simd:5511 [F] s_b_7_5 = constant u32 2 (const) */
    /* execute.simd:5511 [D] s_b_7_1[s_b_7_5] */
    auto s_b_7_6 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5511 [D] s_b_7_7 = (u64)s_b_7_6 */
    auto s_b_7_7 = emitter.zx(s_b_7_6, emitter.context().types().u64());
    /* execute.simd:5511 [F] s_b_7_8 = constant u32 2 (const) */
    /* execute.simd:5511 [D] s_b_7_3[s_b_7_8] */
    auto s_b_7_9 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)2ULL));
    /* execute.simd:5511 [D] s_b_7_10 = (u64)s_b_7_9 */
    auto s_b_7_10 = emitter.zx(s_b_7_9, emitter.context().types().u64());
    /* execute.simd:5511 [D] s_b_7_11 = s_b_7_7*s_b_7_10 */
    auto s_b_7_11 = emitter.mul(s_b_7_7, s_b_7_10);
    /* execute.simd:5511 [F] s_b_7_12 = constant s32 0 (const) */
    /* execute.simd:5511 [D] s_b_7_13 = s_b_7_4[s_b_7_12] <= s_b_7_11 */
    auto s_b_7_13 = emitter.vector_insert(emitter.constant_vector_splat(wutils::Vector<uint64_t, 2>(0)[0], emitter.context().types().v2u64()), emitter.const_s32((int32_t)0ULL), s_b_7_11);
    /* execute.simd:5511 [F] s_b_7_14 = constant u32 3 (const) */
    /* execute.simd:5511 [D] s_b_7_1[s_b_7_14] */
    auto s_b_7_15 = emitter.vector_extract(s_b_7_1, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5511 [D] s_b_7_16 = (u64)s_b_7_15 */
    auto s_b_7_16 = emitter.zx(s_b_7_15, emitter.context().types().u64());
    /* execute.simd:5511 [F] s_b_7_17 = constant u32 3 (const) */
    /* execute.simd:5511 [D] s_b_7_3[s_b_7_17] */
    auto s_b_7_18 = emitter.vector_extract(s_b_7_3, emitter.const_u32((uint32_t)3ULL));
    /* execute.simd:5511 [D] s_b_7_19 = (u64)s_b_7_18 */
    auto s_b_7_19 = emitter.zx(s_b_7_18, emitter.context().types().u64());
    /* execute.simd:5511 [D] s_b_7_20 = s_b_7_16*s_b_7_19 */
    auto s_b_7_20 = emitter.mul(s_b_7_16, s_b_7_19);
    /* execute.simd:5511 [F] s_b_7_21 = constant s32 1 (const) */
    /* execute.simd:5511 [D] s_b_7_22 = s_b_7_13[s_b_7_21] <= s_b_7_20 */
    auto s_b_7_22 = emitter.vector_insert(s_b_7_13, emitter.const_s32((int32_t)1ULL), s_b_7_20);
    /* execute.simd:5514 [F] s_b_7_23=sym_41150_3_parameter_inst.rd (const) */
    /* execute.simd:5514 [D] s_b_7_24: WriteRegBank 21:s_b_7_23 = s_b_7_22 */
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
    /* execute.simd:5518 [D] s_b_8_0 = trap */
    emitter.raise(emitter.const_u8(0));
    /* execute.simd:5438 [F] s_b_8_1: Jump b_1 (const) */
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
  auto DV_sym_159185_0_return_symbol = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_159202_1__R_s_b_3_0 = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_159276_0_replaced_parameter_addr = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_159278_0_value = emitter.alloc_local(emitter.context().types().u8(), false);
  auto DV_sym_159312_0_value = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_159290_0_value = emitter.alloc_local(emitter.context().types().u16(), false);
  auto DV_sym_159326_0_vh = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_159322_0_vl = emitter.alloc_local(emitter.context().types().u64(), false);
  auto DV_sym_159301_0_value = emitter.alloc_local(emitter.context().types().u32(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.simd:3982 [F] s_b_0_0=sym_47500_3_parameter_inst.rn (const) */
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
    /* execute.a64:2796 [F] s_b_2_0=sym_47500_3_parameter_inst.rn (const) */
    /* execute.a64:2796 [D] s_b_2_1 = ReadRegBank 0:s_b_2_0 (u64) */
    auto s_b_2_1 = emitter.load_register(emitter.const_u32((uint32_t)(0 + (8 * insn.rn))), emitter.context().types().u64());
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32((uint32_t)(0 + (8 * insn.rn))),s_b_2_1,emitter.const_u8(8));
    }
    /* ???:4294967295 [D] s_b_2_2: sym_159185_0_return_symbol = s_b_2_1, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_159185_0_return_symbol, s_b_2_1);
    /* ???:4294967295 [F] s_b_2_3: Jump b_3 (const) */
    goto fixed_block_b_3;
  }
  /* b_2, b_6,  */
  fixed_block_b_3: 
  {
    /* ???:4294967295 [D] s_b_3_0 = sym_159185_0_return_symbol uint64_t */
    auto s_b_3_0 = emitter.load_local(DV_sym_159185_0_return_symbol, emitter.context().types().u64());
    /* execute.simd:3982 [F] s_b_3_1=sym_47500_3_parameter_inst.immu64 (const) */
    /* execute.simd:3982 [D] s_b_3_2 = s_b_3_0+s_b_3_1 */
    auto s_b_3_2 = emitter.add(s_b_3_0, emitter.const_u64(insn.immu64));
    /* execute.simd:3983 [F] s_b_3_3=sym_47500_3_parameter_inst.size (const) */
    /* execute.simd:3983 [F] s_b_3_4 = (u32)s_b_3_3 (const) */
    /* execute.simd:3983 [F] s_b_3_5 = constant u32 0 (const) */
    /* execute.simd:3983 [F] s_b_3_6 = s_b_3_4==s_b_3_5 (const) */
    uint8_t s_b_3_6 = ((uint8_t)(((uint32_t)insn.size) == (uint32_t)0ULL));
    /* execute.simd:3983 [F] s_b_3_7=sym_47500_3_parameter_inst.opc (const) */
    /* execute.simd:3983 [F] s_b_3_8 = (u32)s_b_3_7 (const) */
    /* execute.simd:3983 [F] s_b_3_9 = constant u32 1 (const) */
    /* execute.simd:3983 [F] s_b_3_10 = s_b_3_8==s_b_3_9 (const) */
    uint8_t s_b_3_10 = ((uint8_t)(((uint32_t)insn.opc) == (uint32_t)1ULL));
    /* execute.simd:3983 [F] s_b_3_11 = constant u8 0 (const) */
    /* execute.simd:3983 [F] s_b_3_12 = constant u8 4 (const) */
    /* execute.simd:3983 [F] s_b_3_13: Select s_b_3_10 ? s_b_3_11 : s_b_3_12 (const) */
    uint8_t s_b_3_13 = ((uint8_t)(s_b_3_10 ? ((uint8_t)0ULL) : ((uint8_t)4ULL)));
    /* execute.simd:3983 [F] s_b_3_14=sym_47500_3_parameter_inst.size (const) */
    /* execute.simd:3983 [F] s_b_3_15 = (u8)s_b_3_14 (const) */
    /* execute.simd:3983 [F] s_b_3_16: Select s_b_3_6 ? s_b_3_13 : s_b_3_15 (const) */
    uint8_t s_b_3_16 = ((uint8_t)(s_b_3_6 ? (s_b_3_13) : (((uint8_t)insn.size))));
    /* ???:4294967295 [D] s_b_3_17: sym_159276_0_replaced_parameter_addr = s_b_3_2, dominates: s_b_9_0 s_b_12_0 s_b_11_0 s_b_10_0 s_b_13_0  */
    emitter.store_local(DV_sym_159276_0_replaced_parameter_addr, s_b_3_2);
    /* execute.simd:3763 [F] s_b_3_18 = constant s32 0 (const) */
    /* execute.simd:3770 [F] s_b_3_19 = constant s32 1 (const) */
    /* execute.simd:3777 [F] s_b_3_20 = constant s32 2 (const) */
    /* execute.simd:3784 [F] s_b_3_21 = constant s32 3 (const) */
    /* execute.simd:3791 [F] s_b_3_22 = constant s32 4 (const) */
    /* execute.simd:3762 [F] s_b_3_23: Switch s_b_3_16: < <todo> > def b_14 (const) -> b_9, b_12, b_11, b_10, b_13, b_14,  */
    switch (s_b_3_16) 
    {
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
    /* execute.a64:2765 [D] s_b_4_1: sym_159202_1__R_s_b_3_0 = s_b_4_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_159202_1__R_s_b_3_0, s_b_4_0);
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
    /* execute.a64:2794 [D] s_b_6_0 = sym_159202_1__R_s_b_3_0 uint64_t */
    auto s_b_6_0 = emitter.load_local(DV_sym_159202_1__R_s_b_3_0, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_6_1: sym_159185_0_return_symbol = s_b_6_0, dominates: s_b_3_0  */
    emitter.store_local(DV_sym_159185_0_return_symbol, s_b_6_0);
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
    /* execute.a64:2768 [D] s_b_7_1: sym_159202_1__R_s_b_3_0 = s_b_7_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_159202_1__R_s_b_3_0, s_b_7_0);
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
    /* execute.a64:2770 [D] s_b_8_1: sym_159202_1__R_s_b_3_0 = s_b_8_0, dominates: s_b_6_0  */
    emitter.store_local(DV_sym_159202_1__R_s_b_3_0, s_b_8_0);
    /* execute.a64:2770 [F] s_b_8_2: Jump b_6 (const) */
    goto fixed_block_b_6;
  }
  /* b_3,  */
  fixed_block_b_9: 
  {
    /* execute.simd:3766 [D] s_b_9_0 = sym_159276_0_replaced_parameter_addr uint64_t */
    auto s_b_9_0 = emitter.load_local(DV_sym_159276_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_9_1 = Load 1 s_b_9_0 => sym_159278_0_value */
    auto s_b_9_1 = emitter.load_memory(s_b_9_0, emitter.context().types().u8());
    emitter.store_local(DV_sym_159278_0_value, s_b_9_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_9_0, s_b_9_1, emitter.const_u8(1));
    }
    /* execute.simd:3767 [F] s_b_9_2=sym_47500_3_parameter_inst.rt (const) */
    /* execute.simd:3767 [D] s_b_9_3 = sym_159278_0_value uint8_t */
    auto s_b_9_3 = emitter.load_local(DV_sym_159278_0_value, emitter.context().types().u8());
    /* execute.simd:6305 [D] s_b_9_4 = (u64)s_b_9_3 */
    auto s_b_9_4 = emitter.zx(s_b_9_3, emitter.context().types().u64());
    /* execute.simd:6305 [D] s_b_9_5: WriteRegBank 2:s_b_9_2 = s_b_9_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_9_4);
    /* execute.simd:6306 [F] s_b_9_6 = constant u64 0 (const) */
    /* execute.simd:6306 [F] s_b_9_7: WriteRegBank 3:s_b_9_2 = s_b_9_6 */
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
    /* execute.simd:3773 [D] s_b_10_0 = sym_159276_0_replaced_parameter_addr uint64_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_159276_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_10_1 = Load 2 s_b_10_0 => sym_159290_0_value */
    auto s_b_10_1 = emitter.load_memory(s_b_10_0, emitter.context().types().u16());
    emitter.store_local(DV_sym_159290_0_value, s_b_10_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_10_0, s_b_10_1, emitter.const_u8(2));
    }
    /* execute.simd:3774 [F] s_b_10_2=sym_47500_3_parameter_inst.rt (const) */
    /* execute.simd:3774 [D] s_b_10_3 = sym_159290_0_value uint16_t */
    auto s_b_10_3 = emitter.load_local(DV_sym_159290_0_value, emitter.context().types().u16());
    /* execute.simd:6312 [D] s_b_10_4 = (u64)s_b_10_3 */
    auto s_b_10_4 = emitter.zx(s_b_10_3, emitter.context().types().u64());
    /* execute.simd:6312 [D] s_b_10_5: WriteRegBank 2:s_b_10_2 = s_b_10_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_10_4);
    /* execute.simd:6313 [F] s_b_10_6 = constant u64 0 (const) */
    /* execute.simd:6313 [F] s_b_10_7: WriteRegBank 3:s_b_10_2 = s_b_10_6 */
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
    /* execute.simd:3780 [D] s_b_11_0 = sym_159276_0_replaced_parameter_addr uint64_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_159276_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_11_1 = Load 4 s_b_11_0 => sym_159301_0_value */
    auto s_b_11_1 = emitter.load_memory(s_b_11_0, emitter.context().types().u32());
    emitter.store_local(DV_sym_159301_0_value, s_b_11_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_11_0, s_b_11_1, emitter.const_u8(4));
    }
    /* execute.simd:3781 [F] s_b_11_2=sym_47500_3_parameter_inst.rt (const) */
    /* execute.simd:3781 [D] s_b_11_3 = sym_159301_0_value uint32_t */
    auto s_b_11_3 = emitter.load_local(DV_sym_159301_0_value, emitter.context().types().u32());
    /* execute.simd:6319 [D] s_b_11_4 = (u64)s_b_11_3 */
    auto s_b_11_4 = emitter.zx(s_b_11_3, emitter.context().types().u64());
    /* execute.simd:6319 [D] s_b_11_5: WriteRegBank 2:s_b_11_2 = s_b_11_4 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_11_4,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_11_4);
    /* execute.simd:6320 [F] s_b_11_6 = constant u64 0 (const) */
    /* execute.simd:6320 [F] s_b_11_7: WriteRegBank 3:s_b_11_2 = s_b_11_6 */
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
    /* execute.simd:3787 [D] s_b_12_0 = sym_159276_0_replaced_parameter_addr uint64_t */
    auto s_b_12_0 = emitter.load_local(DV_sym_159276_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_12_1 = Load 8 s_b_12_0 => sym_159312_0_value */
    auto s_b_12_1 = emitter.load_memory(s_b_12_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_159312_0_value, s_b_12_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_12_0, s_b_12_1, emitter.const_u8(8));
    }
    /* execute.simd:3788 [F] s_b_12_2=sym_47500_3_parameter_inst.rt (const) */
    /* execute.simd:3788 [D] s_b_12_3 = sym_159312_0_value uint64_t */
    auto s_b_12_3 = emitter.load_local(DV_sym_159312_0_value, emitter.context().types().u64());
    /* execute.simd:6326 [D] s_b_12_4: WriteRegBank 2:s_b_12_2 = s_b_12_3 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_3,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_12_3);
    /* execute.simd:6327 [F] s_b_12_5 = constant u64 0 (const) */
    /* execute.simd:6327 [F] s_b_12_6: WriteRegBank 3:s_b_12_2 = s_b_12_5 */
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
    /* execute.simd:3795 [D] s_b_13_0 = sym_159276_0_replaced_parameter_addr uint64_t */
    auto s_b_13_0 = emitter.load_local(DV_sym_159276_0_replaced_parameter_addr, emitter.context().types().u64());
    /* ???:4294967295 [D] s_b_13_1 = Load 8 s_b_13_0 => sym_159322_0_vl */
    auto s_b_13_1 = emitter.load_memory(s_b_13_0, emitter.context().types().u64());
    emitter.store_local(DV_sym_159322_0_vl, s_b_13_1);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_0, s_b_13_1, emitter.const_u8(8));
    }
    /* execute.simd:3796 [F] s_b_13_2 = constant u64 8 (const) */
    /* execute.simd:3796 [D] s_b_13_3 = s_b_13_0+s_b_13_2 */
    auto s_b_13_3 = emitter.add(s_b_13_0, emitter.const_u64((uint64_t)8ULL));
    /* ???:4294967295 [D] s_b_13_4 = Load 8 s_b_13_3 => sym_159326_0_vh */
    auto s_b_13_4 = emitter.load_memory(s_b_13_3, emitter.context().types().u64());
    emitter.store_local(DV_sym_159326_0_vh, s_b_13_4);
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::LOAD_MEMORY, s_b_13_3, s_b_13_4, emitter.const_u8(8));
    }
    /* execute.simd:3797 [F] s_b_13_5=sym_47500_3_parameter_inst.rt (const) */
    /* execute.simd:3797 [D] s_b_13_6 = sym_159322_0_vl uint64_t */
    auto s_b_13_6 = emitter.load_local(DV_sym_159322_0_vl, emitter.context().types().u64());
    /* execute.simd:3797 [D] s_b_13_7 = sym_159326_0_vh uint64_t */
    auto s_b_13_7 = emitter.load_local(DV_sym_159326_0_vh, emitter.context().types().u64());
    /* execute.simd:6333 [D] s_b_13_8: WriteRegBank 2:s_b_13_5 = s_b_13_6 */
    if (TRACE) 
    {
      emitter.trace(captive::arch::dbt::el::TraceEvent::STORE_REGISTER,emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_6,emitter.const_u8(8));
    }
    emitter.store_register(emitter.const_u32((uint32_t)(256 + (16 * insn.rt))),s_b_13_6);
    /* execute.simd:6334 [D] s_b_13_9: WriteRegBank 3:s_b_13_5 = s_b_13_7 */
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
