#include <arm64-decode.h>
using namespace captive::arch::arm64;
bool arm64_decode::decode(uint32_t isa_mode, uint64_t insn_pc, const uint8_t *ptr)
{
  opcode = arm64_unknown;
  pc = insn_pc;
  ir = *(const uint32_t *)ptr;
  end_of_block = false;
  is_predicated = false;
  bool result = false;
  switch ((arm64_isa_modes)isa_mode) 
  {
  case arm64_a64:
    result = decode_a64(ir);
    break;
  }
  if (opcode == arm64_unknown) 
  {
    end_of_block = true;
    result = true;
  }
  return result;
}
captive::arch::JumpInfo arm64_decode::get_jump_info()
{
  JumpInfo info;
  info.type = captive::arch::JumpInfo::NONE;
  info.target = 0;
  switch (opcode) 
  {
  case arm64_a64_b:
    info.type = captive::arch::JumpInfo::DIRECT;
    info.target = pc + ((arm64_decode_a64_UB_IMM *)this)->imms64;
    break;
  case arm64_a64_bcond:
    info.type = captive::arch::JumpInfo::INDIRECT;
    break;
  case arm64_a64_br:
    info.type = captive::arch::JumpInfo::INDIRECT;
    break;
  case arm64_a64_cbz:
    info.type = captive::arch::JumpInfo::DIRECT_PREDICATED;
    info.target = pc + ((arm64_decode_a64_CMP_B_IMM *)this)->imms64;
    break;
  case arm64_a64_drps:
    info.type = captive::arch::JumpInfo::INDIRECT;
    break;
  case arm64_a64_eret:
    info.type = captive::arch::JumpInfo::INDIRECT;
    break;
  case arm64_a64_exgen:
    info.type = captive::arch::JumpInfo::INDIRECT;
    break;
  case arm64_a64_msr_sctlr:
    info.type = captive::arch::JumpInfo::INDIRECT;
    break;
  case arm64_a64_ret:
    info.type = captive::arch::JumpInfo::INDIRECT;
    break;
  case arm64_a64_tbz:
    info.type = captive::arch::JumpInfo::DIRECT_PREDICATED;
    info.target = pc + ((arm64_decode_a64_TEST_B_IMM *)this)->imms64;
    break;
  case arm64_unknown:
    info.type = captive::arch::JumpInfo::INDIRECT;
    break;
  default: break;
  }
  return info;
}
inline bool arm64_decode::decode_a64(uint32_t ir)
{
  isa_mode = arm64_a64;
  // Node 0
  switch (UNSIGNED_BITS(ir, 31,30)) 
  {
  case 0:
    {
      // Node 1508
      switch (UNSIGNED_BITS(ir, 29,27)) 
      {
      case 5:
        {
          // Node 1534
          switch (UNSIGNED_BITS(ir, 26,19)) 
          {
          case 224:
            {
              // Node 884
              // Node 885
              switch (UNSIGNED_BITS(ir, 15,12)) 
              {
              case 14:
                {
                  // Node 886
                  // Node 887
                  switch ((ir & BIT_LSB(10)) >> 10)
                  {
                  case 1:
                    {
                      // Node 888
                      // Node 889
                      opcode = arm64_a64_movi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 26,22)) 
          {
          case 21:
            {
              // Node 644
              // Node 645
              opcode = arm64_a64_ldp_simd;
              length = 4;
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 20:
            {
              // Node 1212
              // Node 1213
              opcode = arm64_a64_stp_simd;
              length = 4;
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 26,25)) 
          {
          case 2:
            {
              // Node 1226
              // Node 1227
              switch (UNSIGNED_BITS(ir, 23,22)) 
              {
              case 2:
                {
                  // Node 1228
                  // Node 1229
                  opcode = arm64_a64_stpi_simd;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).P = BITSEL(ir, 24);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 0:
            {
              // Node 1554
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 1:
                {
                  // Node 634
                  // Node 635
                  opcode = arm64_a64_ldnp;
                  length = 4;
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 5:
                {
                  // Node 638
                  // Node 639
                  opcode = arm64_a64_ldp;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 1202
                  // Node 1203
                  opcode = arm64_a64_stnp;
                  length = 4;
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1206
                  // Node 1207
                  opcode = arm64_a64_stp;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              // Node 650
              // Node 651
              switch (UNSIGNED_BITS(ir, 23,22)) 
              {
              case 3:
                {
                  // Node 652
                  // Node 653
                  opcode = arm64_a64_ldpi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).P = BITSEL(ir, 24);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 2:
                {
                  // Node 1216
                  // Node 1217
                  opcode = arm64_a64_stpi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).P = BITSEL(ir, 24);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      case 1:
        {
          // Node 1535
          switch (UNSIGNED_BITS(ir, 26,21)) 
          {
          case 48:
            {
              // Node 1074
              // Node 1075
              switch (UNSIGNED_BITS(ir, 15,10)) 
              {
              case 11:
                {
                  // Node 1076
                  // Node 1077
                  opcode = arm64_a64_smov;
                  length = 4;
                  ((arm64_decode_a64_SIMD_COPY&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_COPY&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_COPY&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_SIMD_COPY&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                  ((arm64_decode_a64_SIMD_COPY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_COPY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_COPY&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 15:
                {
                  // Node 1422
                  // Node 1423
                  opcode = arm64_a64_umov;
                  length = 4;
                  ((arm64_decode_a64_SIMD_COPY&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_COPY&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_COPY&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_SIMD_COPY&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                  ((arm64_decode_a64_SIMD_COPY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_COPY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_COPY&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 26,24)) 
          {
          case 0:
            {
              // Node 1555
              switch (UNSIGNED_BITS(ir, 23,21)) 
              {
              case 6:
                {
                  // Node 600
                  // Node 601
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 1:
                    {
                      // Node 602
                      // Node 603
                      opcode = arm64_a64_ldarb;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 2:
                {
                  // Node 624
                  // Node 625
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 1:
                    {
                      // Node 626
                      // Node 627
                      opcode = arm64_a64_ldaxrb;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 858
                      // Node 859
                      opcode = arm64_a64_ldxrb;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 4:
                {
                  // Node 1168
                  // Node 1169
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 1:
                    {
                      // Node 1170
                      // Node 1171
                      opcode = arm64_a64_stlrb;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1192
                  // Node 1193
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 1:
                    {
                      // Node 1194
                      // Node 1195
                      opcode = arm64_a64_stlxrb;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 1338
                      // Node 1339
                      opcode = arm64_a64_stxrb;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 29,28)) 
      {
      case 1:
        {
          // Node 1532
          switch (UNSIGNED_BITS(ir, 27,21)) 
          {
          case 86:
            {
              // Node 206
              // Node 207
              switch (UNSIGNED_BITS(ir, 15,13)) 
              {
              case 2:
                {
                  // Node 1547
                  switch (UNSIGNED_BITS(ir, 12,10)) 
                  {
                  case 2:
                    {
                      // Node 208
                      // Node 209
                      opcode = arm64_a64_crc32;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1:
                    {
                      // Node 210
                      // Node 211
                      opcode = arm64_a64_crc32;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 212
                      // Node 213
                      opcode = arm64_a64_crc32;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 6:
                    {
                      // Node 216
                      // Node 217
                      opcode = arm64_a64_crc32c;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 5:
                    {
                      // Node 218
                      // Node 219
                      opcode = arm64_a64_crc32c;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 4:
                    {
                      // Node 220
                      // Node 221
                      opcode = arm64_a64_crc32c;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          case 28:
            {
              // Node 273
              // Node 274
              opcode = arm64_a64_extr;
              length = 4;
              ((arm64_decode_a64_EXTRACT&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_EXTRACT&)*this).op21 = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_EXTRACT&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_EXTRACT&)*this).o0 = BITSEL(ir, 21);
              ((arm64_decode_a64_EXTRACT&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_EXTRACT&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_EXTRACT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_EXTRACT&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_EXTRACT&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,22)) 
          {
          case 8:
            {
              // Node 57
              // Node 58
              opcode = arm64_a64_andi;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 12:
            {
              // Node 1028
              // Node 1029
              opcode = arm64_a64_sbfm;
              length = 4;
              ((arm64_decode_a64_BITFIELD&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_BITFIELD&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_BITFIELD&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_BITFIELD&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_BITFIELD&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_BITFIELD&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_BITFIELD&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_BITFIELD&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,24)) 
          {
          case 8:
            {
              // Node 697
              // Node 698
              opcode = arm64_a64_ldr_lit;
              length = 4;
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).imm19 = UNSIGNED_BITS(ir, 23,5);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,25)) 
          {
          case 7:
            {
              // Node 1536
              switch (UNSIGNED_BITS(ir, 24,10)) 
              {
              case 14512:
                {
                  // Node 339
                  // Node 340
                  opcode = arm64_a64_fcvt;
                  length = 4;
                  ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                  ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                  ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 14480:
                {
                  // Node 341
                  // Node 342
                  opcode = arm64_a64_fcvt;
                  length = 4;
                  ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                  ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                  ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,16)) 
              {
              case 195:
                {
                  // Node 1398
                  // Node 1399
                  opcode = arm64_a64_ucvtf_fxp;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,23)) 
              {
              case 0:
                {
                  // Node 1537
                  switch (UNSIGNED_BITS(ir, 22,16)) 
                  {
                  case 89:
                    {
                      // Node 391
                      // Node 392
                      opcode = arm64_a64_fcvtz_fxp;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 25:
                    {
                      // Node 393
                      // Node 394
                      opcode = arm64_a64_fcvtz_fxp;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 88:
                    {
                      // Node 399
                      // Node 400
                      opcode = arm64_a64_fcvtz_fxp;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 24:
                    {
                      // Node 401
                      // Node 402
                      opcode = arm64_a64_fcvtz_fxp;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 67:
                    {
                      // Node 1394
                      // Node 1395
                      opcode = arm64_a64_ucvtf_fxp;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 3:
                    {
                      // Node 1396
                      // Node 1397
                      opcode = arm64_a64_ucvtf_fxp;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 22,19)) 
                  {
                  case 12:
                    {
                      // Node 1539
                      switch (UNSIGNED_BITS(ir, 18,10)) 
                      {
                      case 144:
                        {
                          // Node 331
                          // Node 332
                          opcode = arm64_a64_fcvt;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 240:
                        {
                          // Node 333
                          // Node 334
                          opcode = arm64_a64_fcvt;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 496:
                        {
                          // Node 489
                          // Node 490
                          opcode = arm64_a64_frintx;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 464:
                        {
                          // Node 493
                          // Node 494
                          opcode = arm64_a64_frintx;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 400:
                        {
                          // Node 497
                          // Node 498
                          opcode = arm64_a64_frintx;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      switch (UNSIGNED_BITS(ir, 18,17)) 
                      {
                      case 2:
                        {
                          // Node 1543
                          switch (UNSIGNED_BITS(ir, 16,10)) 
                          {
                          case 112:
                            {
                              // Node 501
                              // Node 502
                              opcode = arm64_a64_frintx;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 80:
                            {
                              // Node 505
                              // Node 506
                              opcode = arm64_a64_frintx;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 48:
                            {
                              // Node 509
                              // Node 510
                              opcode = arm64_a64_frintx;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 16:
                            {
                              // Node 513
                              // Node 514
                              opcode = arm64_a64_frintx;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          }
                          break;
                        }
                      case 0:
                        {
                          // Node 1544
                          switch (UNSIGNED_BITS(ir, 16,10)) 
                          {
                          case 48:
                            {
                              // Node 285
                              // Node 286
                              opcode = arm64_a64_fabs;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 16:
                            {
                              // Node 437
                              // Node 438
                              opcode = arm64_a64_fmov;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 80:
                            {
                              // Node 477
                              // Node 478
                              opcode = arm64_a64_fneg;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 112:
                            {
                              // Node 517
                              // Node 518
                              opcode = arm64_a64_fsqrt;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          }
                          break;
                        }
                      }
                      break;
                    }
                  case 4:
                    {
                      // Node 1540
                      switch (UNSIGNED_BITS(ir, 18,10)) 
                      {
                      case 176:
                        {
                          // Node 335
                          // Node 336
                          opcode = arm64_a64_fcvt;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 240:
                        {
                          // Node 337
                          // Node 338
                          opcode = arm64_a64_fcvt;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 496:
                        {
                          // Node 491
                          // Node 492
                          opcode = arm64_a64_frintx;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 464:
                        {
                          // Node 495
                          // Node 496
                          opcode = arm64_a64_frintx;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 400:
                        {
                          // Node 499
                          // Node 500
                          opcode = arm64_a64_frintx;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                          ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      switch (UNSIGNED_BITS(ir, 18,17)) 
                      {
                      case 2:
                        {
                          // Node 1545
                          switch (UNSIGNED_BITS(ir, 16,10)) 
                          {
                          case 112:
                            {
                              // Node 503
                              // Node 504
                              opcode = arm64_a64_frintx;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 80:
                            {
                              // Node 507
                              // Node 508
                              opcode = arm64_a64_frintx;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 48:
                            {
                              // Node 511
                              // Node 512
                              opcode = arm64_a64_frintx;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 16:
                            {
                              // Node 515
                              // Node 516
                              opcode = arm64_a64_frintx;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          }
                          break;
                        }
                      case 0:
                        {
                          // Node 1546
                          switch (UNSIGNED_BITS(ir, 16,10)) 
                          {
                          case 48:
                            {
                              // Node 287
                              // Node 288
                              opcode = arm64_a64_fabs;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 16:
                            {
                              // Node 439
                              // Node 440
                              opcode = arm64_a64_fmov;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 80:
                            {
                              // Node 479
                              // Node 480
                              opcode = arm64_a64_fneg;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 112:
                            {
                              // Node 519
                              // Node 520
                              opcode = arm64_a64_fsqrt;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_1&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_1&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_1&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_1&)*this).opcode = UNSIGNED_BITS(ir, 20,15);
                              ((arm64_decode_a64_FP_DP_1&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_1&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_1&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          }
                          break;
                        }
                      }
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 3:
                    {
                      // Node 289
                      // Node 290
                      switch (UNSIGNED_BITS(ir, 15,10)) 
                      {
                      case 34:
                        {
                          // Node 485
                          // Node 486
                          opcode = arm64_a64_fnmul;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      switch (UNSIGNED_BITS(ir, 15,14)) 
                      {
                      case 0:
                        {
                          // Node 1541
                          switch (UNSIGNED_BITS(ir, 13,10)) 
                          {
                          case 10:
                            {
                              // Node 291
                              // Node 292
                              opcode = arm64_a64_fadd;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 8:
                            {
                              // Node 315
                              // Node 316
                              switch (UNSIGNED_BITS(ir, 4,0)) 
                              {
                              case 8:
                                {
                                  // Node 317
                                  opcode = arm64_a64_fcmpe;
                                  length = 4;
                                  ((arm64_decode_a64_FP_CMP&)*this).M = BITSEL(ir, 31);
                                  ((arm64_decode_a64_FP_CMP&)*this).S = BITSEL(ir, 29);
                                  ((arm64_decode_a64_FP_CMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                                  ((arm64_decode_a64_FP_CMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                                  ((arm64_decode_a64_FP_CMP&)*this).op = UNSIGNED_BITS(ir, 15,14);
                                  ((arm64_decode_a64_FP_CMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                                  ((arm64_decode_a64_FP_CMP&)*this).opcode2 = UNSIGNED_BITS(ir, 4,0);
                                  ((arm64_decode_a64_FP_CMP&)*this).decode_behaviour();
                                  is_predicated = false;
                                  return true;
                                  break;
                                }
                              case 0:
                                {
                                  // Node 318
                                  opcode = arm64_a64_fcmpe;
                                  length = 4;
                                  ((arm64_decode_a64_FP_CMP&)*this).M = BITSEL(ir, 31);
                                  ((arm64_decode_a64_FP_CMP&)*this).S = BITSEL(ir, 29);
                                  ((arm64_decode_a64_FP_CMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                                  ((arm64_decode_a64_FP_CMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                                  ((arm64_decode_a64_FP_CMP&)*this).op = UNSIGNED_BITS(ir, 15,14);
                                  ((arm64_decode_a64_FP_CMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                                  ((arm64_decode_a64_FP_CMP&)*this).opcode2 = UNSIGNED_BITS(ir, 4,0);
                                  ((arm64_decode_a64_FP_CMP&)*this).decode_behaviour();
                                  is_predicated = false;
                                  return true;
                                  break;
                                }
                              case 24:
                                {
                                  // Node 323
                                  opcode = arm64_a64_fcmpe;
                                  length = 4;
                                  ((arm64_decode_a64_FP_CMP&)*this).M = BITSEL(ir, 31);
                                  ((arm64_decode_a64_FP_CMP&)*this).S = BITSEL(ir, 29);
                                  ((arm64_decode_a64_FP_CMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                                  ((arm64_decode_a64_FP_CMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                                  ((arm64_decode_a64_FP_CMP&)*this).op = UNSIGNED_BITS(ir, 15,14);
                                  ((arm64_decode_a64_FP_CMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                                  ((arm64_decode_a64_FP_CMP&)*this).opcode2 = UNSIGNED_BITS(ir, 4,0);
                                  ((arm64_decode_a64_FP_CMP&)*this).decode_behaviour();
                                  is_predicated = false;
                                  return true;
                                  break;
                                }
                              case 16:
                                {
                                  // Node 324
                                  opcode = arm64_a64_fcmpe;
                                  length = 4;
                                  ((arm64_decode_a64_FP_CMP&)*this).M = BITSEL(ir, 31);
                                  ((arm64_decode_a64_FP_CMP&)*this).S = BITSEL(ir, 29);
                                  ((arm64_decode_a64_FP_CMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                                  ((arm64_decode_a64_FP_CMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                                  ((arm64_decode_a64_FP_CMP&)*this).op = UNSIGNED_BITS(ir, 15,14);
                                  ((arm64_decode_a64_FP_CMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                                  ((arm64_decode_a64_FP_CMP&)*this).opcode2 = UNSIGNED_BITS(ir, 4,0);
                                  ((arm64_decode_a64_FP_CMP&)*this).decode_behaviour();
                                  is_predicated = false;
                                  return true;
                                  break;
                                }
                              }
                              break;
                            }
                          case 6:
                            {
                              // Node 413
                              // Node 414
                              opcode = arm64_a64_fdiv;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 2:
                            {
                              // Node 467
                              // Node 468
                              opcode = arm64_a64_fmul;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 14:
                            {
                              // Node 521
                              // Node 522
                              opcode = arm64_a64_fsub;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          }
                          break;
                        }
                      }
                      // Node 461
                      switch (UNSIGNED_BITS(ir, 12,5)) 
                      {
                      case 128:
                        {
                          // Node 462
                          // Node 463
                          opcode = arm64_a64_fmovi;
                          length = 4;
                          ((arm64_decode_a64_FP_IMM&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_IMM&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_IMM&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_IMM&)*this).imm8 = UNSIGNED_BITS(ir, 20,13);
                          ((arm64_decode_a64_FP_IMM&)*this).imm5 = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_IMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 297
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 1:
                        {
                          // Node 298
                          // Node 299
                          switch ((ir & BIT_LSB(4)) >> 4)
                          {
                          case 1:
                            {
                              // Node 300
                              // Node 301
                              opcode = arm64_a64_fccmpe;
                              length = 4;
                              ((arm64_decode_a64_FP_CCMP&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_CCMP&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_CCMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_CCMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_CCMP&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_CCMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_CCMP&)*this).op = BITSEL(ir, 4);
                              ((arm64_decode_a64_FP_CCMP&)*this).nzcv = UNSIGNED_BITS(ir, 3,0);
                              ((arm64_decode_a64_FP_CCMP&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 0:
                            {
                              // Node 302
                              // Node 303
                              opcode = arm64_a64_fccmpe;
                              length = 4;
                              ((arm64_decode_a64_FP_CCMP&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_CCMP&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_CCMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_CCMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_CCMP&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_CCMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_CCMP&)*this).op = BITSEL(ir, 4);
                              ((arm64_decode_a64_FP_CCMP&)*this).nzcv = UNSIGNED_BITS(ir, 3,0);
                              ((arm64_decode_a64_FP_CCMP&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          }
                          break;
                        }
                      case 3:
                        {
                          // Node 327
                          // Node 328
                          opcode = arm64_a64_fcsel;
                          length = 4;
                          ((arm64_decode_a64_FP_CSEL&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_CSEL&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_CSEL&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_CSEL&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_FP_CSEL&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_FP_CSEL&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_CSEL&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_CSEL&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 293
                      // Node 294
                      switch (UNSIGNED_BITS(ir, 15,10)) 
                      {
                      case 34:
                        {
                          // Node 487
                          // Node 488
                          opcode = arm64_a64_fnmul;
                          length = 4;
                          ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      switch (UNSIGNED_BITS(ir, 15,14)) 
                      {
                      case 0:
                        {
                          // Node 1542
                          switch (UNSIGNED_BITS(ir, 13,10)) 
                          {
                          case 10:
                            {
                              // Node 295
                              // Node 296
                              opcode = arm64_a64_fadd;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 8:
                            {
                              // Node 319
                              // Node 320
                              switch (UNSIGNED_BITS(ir, 4,0)) 
                              {
                              case 8:
                                {
                                  // Node 321
                                  opcode = arm64_a64_fcmpe;
                                  length = 4;
                                  ((arm64_decode_a64_FP_CMP&)*this).M = BITSEL(ir, 31);
                                  ((arm64_decode_a64_FP_CMP&)*this).S = BITSEL(ir, 29);
                                  ((arm64_decode_a64_FP_CMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                                  ((arm64_decode_a64_FP_CMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                                  ((arm64_decode_a64_FP_CMP&)*this).op = UNSIGNED_BITS(ir, 15,14);
                                  ((arm64_decode_a64_FP_CMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                                  ((arm64_decode_a64_FP_CMP&)*this).opcode2 = UNSIGNED_BITS(ir, 4,0);
                                  ((arm64_decode_a64_FP_CMP&)*this).decode_behaviour();
                                  is_predicated = false;
                                  return true;
                                  break;
                                }
                              case 0:
                                {
                                  // Node 322
                                  opcode = arm64_a64_fcmpe;
                                  length = 4;
                                  ((arm64_decode_a64_FP_CMP&)*this).M = BITSEL(ir, 31);
                                  ((arm64_decode_a64_FP_CMP&)*this).S = BITSEL(ir, 29);
                                  ((arm64_decode_a64_FP_CMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                                  ((arm64_decode_a64_FP_CMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                                  ((arm64_decode_a64_FP_CMP&)*this).op = UNSIGNED_BITS(ir, 15,14);
                                  ((arm64_decode_a64_FP_CMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                                  ((arm64_decode_a64_FP_CMP&)*this).opcode2 = UNSIGNED_BITS(ir, 4,0);
                                  ((arm64_decode_a64_FP_CMP&)*this).decode_behaviour();
                                  is_predicated = false;
                                  return true;
                                  break;
                                }
                              case 24:
                                {
                                  // Node 325
                                  opcode = arm64_a64_fcmpe;
                                  length = 4;
                                  ((arm64_decode_a64_FP_CMP&)*this).M = BITSEL(ir, 31);
                                  ((arm64_decode_a64_FP_CMP&)*this).S = BITSEL(ir, 29);
                                  ((arm64_decode_a64_FP_CMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                                  ((arm64_decode_a64_FP_CMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                                  ((arm64_decode_a64_FP_CMP&)*this).op = UNSIGNED_BITS(ir, 15,14);
                                  ((arm64_decode_a64_FP_CMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                                  ((arm64_decode_a64_FP_CMP&)*this).opcode2 = UNSIGNED_BITS(ir, 4,0);
                                  ((arm64_decode_a64_FP_CMP&)*this).decode_behaviour();
                                  is_predicated = false;
                                  return true;
                                  break;
                                }
                              case 16:
                                {
                                  // Node 326
                                  opcode = arm64_a64_fcmpe;
                                  length = 4;
                                  ((arm64_decode_a64_FP_CMP&)*this).M = BITSEL(ir, 31);
                                  ((arm64_decode_a64_FP_CMP&)*this).S = BITSEL(ir, 29);
                                  ((arm64_decode_a64_FP_CMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                                  ((arm64_decode_a64_FP_CMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                                  ((arm64_decode_a64_FP_CMP&)*this).op = UNSIGNED_BITS(ir, 15,14);
                                  ((arm64_decode_a64_FP_CMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                                  ((arm64_decode_a64_FP_CMP&)*this).opcode2 = UNSIGNED_BITS(ir, 4,0);
                                  ((arm64_decode_a64_FP_CMP&)*this).decode_behaviour();
                                  is_predicated = false;
                                  return true;
                                  break;
                                }
                              }
                              break;
                            }
                          case 6:
                            {
                              // Node 415
                              // Node 416
                              opcode = arm64_a64_fdiv;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 2:
                            {
                              // Node 469
                              // Node 470
                              opcode = arm64_a64_fmul;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 14:
                            {
                              // Node 523
                              // Node 524
                              opcode = arm64_a64_fsub;
                              length = 4;
                              ((arm64_decode_a64_FP_DP_2&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_DP_2&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_DP_2&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_DP_2&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_DP_2&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_DP_2&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_DP_2&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_FP_DP_2&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          }
                          break;
                        }
                      }
                      // Node 464
                      switch (UNSIGNED_BITS(ir, 12,5)) 
                      {
                      case 128:
                        {
                          // Node 465
                          // Node 466
                          opcode = arm64_a64_fmovi;
                          length = 4;
                          ((arm64_decode_a64_FP_IMM&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_IMM&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_IMM&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_IMM&)*this).imm8 = UNSIGNED_BITS(ir, 20,13);
                          ((arm64_decode_a64_FP_IMM&)*this).imm5 = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_IMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 304
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 1:
                        {
                          // Node 305
                          // Node 306
                          switch ((ir & BIT_LSB(4)) >> 4)
                          {
                          case 1:
                            {
                              // Node 307
                              // Node 308
                              opcode = arm64_a64_fccmpe;
                              length = 4;
                              ((arm64_decode_a64_FP_CCMP&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_CCMP&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_CCMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_CCMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_CCMP&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_CCMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_CCMP&)*this).op = BITSEL(ir, 4);
                              ((arm64_decode_a64_FP_CCMP&)*this).nzcv = UNSIGNED_BITS(ir, 3,0);
                              ((arm64_decode_a64_FP_CCMP&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          case 0:
                            {
                              // Node 309
                              // Node 310
                              opcode = arm64_a64_fccmpe;
                              length = 4;
                              ((arm64_decode_a64_FP_CCMP&)*this).M = BITSEL(ir, 31);
                              ((arm64_decode_a64_FP_CCMP&)*this).S = BITSEL(ir, 29);
                              ((arm64_decode_a64_FP_CCMP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                              ((arm64_decode_a64_FP_CCMP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                              ((arm64_decode_a64_FP_CCMP&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_FP_CCMP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                              ((arm64_decode_a64_FP_CCMP&)*this).op = BITSEL(ir, 4);
                              ((arm64_decode_a64_FP_CCMP&)*this).nzcv = UNSIGNED_BITS(ir, 3,0);
                              ((arm64_decode_a64_FP_CCMP&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          }
                          break;
                        }
                      case 3:
                        {
                          // Node 329
                          // Node 330
                          opcode = arm64_a64_fcsel;
                          length = 4;
                          ((arm64_decode_a64_FP_CSEL&)*this).M = BITSEL(ir, 31);
                          ((arm64_decode_a64_FP_CSEL&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_FP_CSEL&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_FP_CSEL&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_FP_CSEL&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_FP_CSEL&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_FP_CSEL&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_FP_CSEL&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              case 2:
                {
                  // Node 1538
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 417
                      // Node 418
                      opcode = arm64_a64_fm;
                      length = 4;
                      ((arm64_decode_a64_FP_DP_3&)*this).M = BITSEL(ir, 31);
                      ((arm64_decode_a64_FP_DP_3&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_FP_DP_3&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_FP_DP_3&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_FP_DP_3&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_FP_DP_3&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_FP_DP_3&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_FP_DP_3&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_FP_DP_3&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_FP_DP_3&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 419
                      // Node 420
                      opcode = arm64_a64_fm;
                      length = 4;
                      ((arm64_decode_a64_FP_DP_3&)*this).M = BITSEL(ir, 31);
                      ((arm64_decode_a64_FP_DP_3&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_FP_DP_3&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_FP_DP_3&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_FP_DP_3&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_FP_DP_3&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_FP_DP_3&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_FP_DP_3&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_FP_DP_3&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_FP_DP_3&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 3:
                    {
                      // Node 481
                      // Node 482
                      opcode = arm64_a64_fnm;
                      length = 4;
                      ((arm64_decode_a64_FP_DP_3&)*this).M = BITSEL(ir, 31);
                      ((arm64_decode_a64_FP_DP_3&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_FP_DP_3&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_FP_DP_3&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_FP_DP_3&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_FP_DP_3&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_FP_DP_3&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_FP_DP_3&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_FP_DP_3&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_FP_DP_3&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1:
                    {
                      // Node 483
                      // Node 484
                      opcode = arm64_a64_fnm;
                      length = 4;
                      ((arm64_decode_a64_FP_DP_3&)*this).M = BITSEL(ir, 31);
                      ((arm64_decode_a64_FP_DP_3&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_FP_DP_3&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_FP_DP_3&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_FP_DP_3&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_FP_DP_3&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_FP_DP_3&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_FP_DP_3&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_FP_DP_3&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_FP_DP_3&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      case 3:
        {
          // Node 1533
          switch (UNSIGNED_BITS(ir, 27,22)) 
          {
          case 12:
            {
              // Node 84
              // Node 85
              opcode = arm64_a64_bfm;
              length = 4;
              ((arm64_decode_a64_BITFIELD&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_BITFIELD&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_BITFIELD&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_BITFIELD&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_BITFIELD&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_BITFIELD&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_BITFIELD&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_BITFIELD&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 8:
            {
              // Node 975
              // Node 976
              opcode = arm64_a64_orri;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,25)) 
          {
          case 6:
            {
              // Node 1548
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 7:
                {
                  // Node 1456
                  // Node 1457
                  opcode = arm64_a64_vldr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 5:
                {
                  // Node 1464
                  // Node 1465
                  opcode = arm64_a64_vldr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 6:
                {
                  // Node 1481
                  // Node 1482
                  opcode = arm64_a64_vstr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1489
                  // Node 1490
                  opcode = arm64_a64_vstr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,23)) 
              {
              case 1:
                {
                  // Node 1550
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 679
                      // Node 1466
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1467
                          // Node 1468
                          opcode = arm64_a64_vldur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 680
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 681
                          // Node 682
                          opcode = arm64_a64_ldr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 713
                      // Node 714
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 715
                          // Node 716
                          opcode = arm64_a64_ldr_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1242
                      // Node 1491
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1492
                          // Node 1493
                          opcode = arm64_a64_vstur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 1243
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 1244
                          // Node 1245
                          opcode = arm64_a64_str;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 1266
                      // Node 1267
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1268
                          // Node 1269
                          opcode = arm64_a64_str_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1551
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 683
                      // Node 1478
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1479
                          // Node 1480
                          opcode = arm64_a64_vldur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 684
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 685
                          // Node 686
                          opcode = arm64_a64_ldr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 729
                      // Node 730
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 731
                          // Node 732
                          opcode = arm64_a64_ldr_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1246
                      // Node 1503
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1504
                          // Node 1505
                          opcode = arm64_a64_vstur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 1247
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 1248
                          // Node 1249
                          opcode = arm64_a64_str;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 1282
                      // Node 1283
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1284
                          // Node 1285
                          opcode = arm64_a64_str_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          case 4:
            {
              // Node 1549
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 7:
                {
                  // Node 757
                  // Node 758
                  opcode = arm64_a64_ldrbi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 6:
                {
                  // Node 759
                  // Node 760
                  opcode = arm64_a64_ldrbi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 5:
                {
                  // Node 761
                  // Node 762
                  opcode = arm64_a64_ldrbi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1294
                  // Node 1295
                  opcode = arm64_a64_strbi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,23)) 
              {
              case 1:
                {
                  // Node 1552
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 733
                      // Node 811
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 812
                          // Node 813
                          opcode = arm64_a64_ldtrb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 836
                          // Node 837
                          opcode = arm64_a64_ldurb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 734
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 735
                          // Node 736
                          opcode = arm64_a64_ldrb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 737
                      // Node 814
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 815
                          // Node 816
                          opcode = arm64_a64_ldtrb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 838
                          // Node 839
                          opcode = arm64_a64_ldurb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 738
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 739
                          // Node 740
                          opcode = arm64_a64_ldrb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 745
                      // Node 746
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 747
                          // Node 748
                          opcode = arm64_a64_ldrb_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 749
                      // Node 750
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 751
                          // Node 752
                          opcode = arm64_a64_ldrb_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1553
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 741
                      // Node 817
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 818
                          // Node 819
                          opcode = arm64_a64_ldtrb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 840
                          // Node 841
                          opcode = arm64_a64_ldurb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 742
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 743
                          // Node 744
                          opcode = arm64_a64_ldrb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 753
                      // Node 754
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 755
                          // Node 756
                          opcode = arm64_a64_ldrb_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1286
                      // Node 1316
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1317
                          // Node 1318
                          opcode = arm64_a64_sttrb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 1326
                          // Node 1327
                          opcode = arm64_a64_sturb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 1287
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 1288
                          // Node 1289
                          opcode = arm64_a64_strb;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 1290
                      // Node 1291
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1292
                          // Node 1293
                          opcode = arm64_a64_strb_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      break;
    }
  case 1:
    {
      // Node 1509
      switch (UNSIGNED_BITS(ir, 29,27)) 
      {
      case 5:
        {
          // Node 1558
          switch (UNSIGNED_BITS(ir, 26,19)) 
          {
          case 224:
            {
              // Node 453
              // Node 454
              switch (UNSIGNED_BITS(ir, 15,10)) 
              {
              case 61:
                {
                  // Node 455
                  // Node 456
                  opcode = arm64_a64_fmov_simd;
                  length = 4;
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 15,12)) 
              {
              case 14:
                {
                  // Node 880
                  // Node 881
                  switch ((ir & BIT_LSB(10)) >> 10)
                  {
                  case 1:
                    {
                      // Node 882
                      // Node 883
                      opcode = arm64_a64_movi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 26,21)) 
          {
          case 51:
            {
              // Node 471
              // Node 472
              switch (UNSIGNED_BITS(ir, 15,10)) 
              {
              case 55:
                {
                  // Node 473
                  // Node 474
                  opcode = arm64_a64_fmul_vector;
                  length = 4;
                  ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                  ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 48:
            {
              // Node 536
              // Node 537
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 0:
                {
                  // Node 538
                  // Node 539
                  switch ((ir & BIT_LSB(10)) >> 10)
                  {
                  case 1:
                    {
                      // Node 540
                      // Node 541
                      opcode = arm64_a64_ins_elem;
                      length = 4;
                      ((arm64_decode_a64_SIMD_COPY&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_COPY&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_COPY&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 26,22)) 
          {
          case 21:
            {
              // Node 642
              // Node 643
              opcode = arm64_a64_ldp_simd;
              length = 4;
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 5:
            {
              // Node 661
              // Node 662
              opcode = arm64_a64_ldpsw;
              length = 4;
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 20:
            {
              // Node 1210
              // Node 1211
              opcode = arm64_a64_stp_simd;
              length = 4;
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 26,25)) 
          {
          case 0:
            {
              // Node 663
              // Node 664
              switch (UNSIGNED_BITS(ir, 23,22)) 
              {
              case 3:
                {
                  // Node 665
                  // Node 666
                  opcode = arm64_a64_ldpswi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).P = BITSEL(ir, 24);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 2:
            {
              // Node 1222
              // Node 1223
              switch (UNSIGNED_BITS(ir, 23,22)) 
              {
              case 2:
                {
                  // Node 1224
                  // Node 1225
                  opcode = arm64_a64_stpi_simd;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).P = BITSEL(ir, 24);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      case 1:
        {
          // Node 1559
          switch (UNSIGNED_BITS(ir, 26,24)) 
          {
          case 6:
            {
              // Node 1569
              switch (UNSIGNED_BITS(ir, 23,10)) 
              {
              case 1551:
                {
                  // Node 1418
                  // Node 1419
                  opcode = arm64_a64_umov;
                  length = 4;
                  ((arm64_decode_a64_SIMD_COPY&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_COPY&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_COPY&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_SIMD_COPY&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                  ((arm64_decode_a64_SIMD_COPY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_COPY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_COPY&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 527:
                {
                  // Node 1420
                  // Node 1421
                  opcode = arm64_a64_umov;
                  length = 4;
                  ((arm64_decode_a64_SIMD_COPY&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_COPY&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_COPY&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_SIMD_COPY&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                  ((arm64_decode_a64_SIMD_COPY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_COPY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_COPY&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 23,21)) 
              {
              case 7:
                {
                  // Node 525
                  // Node 526
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 53:
                    {
                      // Node 527
                      // Node 528
                      opcode = arm64_a64_fsub_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 542
                  // Node 543
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 7:
                    {
                      // Node 544
                      // Node 545
                      opcode = arm64_a64_ins_gen;
                      length = 4;
                      ((arm64_decode_a64_SIMD_COPY&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_COPY&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_COPY&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 11:
                    {
                      // Node 1072
                      // Node 1073
                      opcode = arm64_a64_smov;
                      length = 4;
                      ((arm64_decode_a64_SIMD_COPY&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_COPY&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_COPY&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          case 0:
            {
              // Node 1570
              switch (UNSIGNED_BITS(ir, 23,21)) 
              {
              case 6:
                {
                  // Node 604
                  // Node 605
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 1:
                    {
                      // Node 606
                      // Node 607
                      opcode = arm64_a64_ldarh;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 2:
                {
                  // Node 628
                  // Node 629
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 1:
                    {
                      // Node 630
                      // Node 631
                      opcode = arm64_a64_ldaxrh;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 860
                      // Node 861
                      opcode = arm64_a64_ldxrh;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 4:
                {
                  // Node 1172
                  // Node 1173
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 1:
                    {
                      // Node 1174
                      // Node 1175
                      opcode = arm64_a64_stlrh;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1196
                  // Node 1197
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 1:
                    {
                      // Node 1198
                      // Node 1199
                      opcode = arm64_a64_stlxrh;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 1340
                      // Node 1341
                      opcode = arm64_a64_stxrh;
                      length = 4;
                      ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                      ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                      ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                      ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 29,28)) 
      {
      case 3:
        {
          // Node 1556
          switch (UNSIGNED_BITS(ir, 27,22)) 
          {
          case 8:
            {
              // Node 51
              // Node 52
              opcode = arm64_a64_andi;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,25)) 
          {
          case 4:
            {
              // Node 1561
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 7:
                {
                  // Node 787
                  // Node 788
                  opcode = arm64_a64_ldrhi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 6:
                {
                  // Node 789
                  // Node 790
                  opcode = arm64_a64_ldrhi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 5:
                {
                  // Node 791
                  // Node 792
                  opcode = arm64_a64_ldrhi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1304
                  // Node 1305
                  opcode = arm64_a64_strhi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,23)) 
              {
              case 1:
                {
                  // Node 1564
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 763
                      // Node 820
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 821
                          // Node 822
                          opcode = arm64_a64_ldtrh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 842
                          // Node 843
                          opcode = arm64_a64_ldurh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 764
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 765
                          // Node 766
                          opcode = arm64_a64_ldrh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 767
                      // Node 823
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 824
                          // Node 825
                          opcode = arm64_a64_ldtrh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 844
                          // Node 845
                          opcode = arm64_a64_ldurh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 768
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 769
                          // Node 770
                          opcode = arm64_a64_ldrh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 775
                      // Node 776
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 777
                          // Node 778
                          opcode = arm64_a64_ldrh_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 779
                      // Node 780
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 781
                          // Node 782
                          opcode = arm64_a64_ldrh_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1565
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 771
                      // Node 826
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 827
                          // Node 828
                          opcode = arm64_a64_ldtrh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 846
                          // Node 847
                          opcode = arm64_a64_ldurh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 772
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 773
                          // Node 774
                          opcode = arm64_a64_ldrh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 783
                      // Node 784
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 785
                          // Node 786
                          opcode = arm64_a64_ldrh_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1296
                      // Node 1319
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1320
                          // Node 1321
                          opcode = arm64_a64_sttrh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 1328
                          // Node 1329
                          opcode = arm64_a64_sturh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 1297
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 1298
                          // Node 1299
                          opcode = arm64_a64_strh;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 1300
                      // Node 1301
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1302
                          // Node 1303
                          opcode = arm64_a64_strh_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,26)) 
          {
          case 3:
            {
              // Node 1560
              switch (UNSIGNED_BITS(ir, 25,22)) 
              {
              case 5:
                {
                  // Node 1462
                  // Node 1463
                  opcode = arm64_a64_vldr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1487
                  // Node 1488
                  opcode = arm64_a64_vstr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 25,23)) 
              {
              case 6:
                {
                  // Node 1444
                  // Node 1445
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 1:
                    {
                      // Node 1446
                      // Node 1447
                      opcode = arm64_a64_ushr;
                      length = 4;
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immh = UNSIGNED_BITS(ir, 22,19);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immb = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1563
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 675
                      // Node 1475
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1476
                          // Node 1477
                          opcode = arm64_a64_vldur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 676
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 677
                          // Node 678
                          opcode = arm64_a64_ldr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 725
                      // Node 726
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 727
                          // Node 728
                          opcode = arm64_a64_ldr_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1238
                      // Node 1500
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1501
                          // Node 1502
                          opcode = arm64_a64_vstur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 1239
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 1240
                          // Node 1241
                          opcode = arm64_a64_str;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 1278
                      // Node 1279
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1280
                          // Node 1281
                          opcode = arm64_a64_str_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 25,24)) 
              {
              case 2:
                {
                  // Node 1562
                  switch (UNSIGNED_BITS(ir, 23,10)) 
                  {
                  case 14374:
                    {
                      // Node 188
                      // Node 189
                      opcode = arm64_a64_cmlt_zero;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 14382:
                    {
                      // Node 961
                      // Node 962
                      opcode = arm64_a64_neg_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 6262:
                    {
                      // Node 1404
                      // Node 1405
                      opcode = arm64_a64_ucvtf_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2166:
                    {
                      // Node 1406
                      // Node 1407
                      opcode = arm64_a64_ucvtf_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 23,21)) 
                  {
                  case 7:
                    {
                      // Node 159
                      // Node 160
                      switch (UNSIGNED_BITS(ir, 15,10)) 
                      {
                      case 35:
                        {
                          // Node 161
                          // Node 162
                          opcode = arm64_a64_cmeq_reg;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 13:
                        {
                          // Node 178
                          // Node 179
                          opcode = arm64_a64_cmhi_reg;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 15:
                        {
                          // Node 182
                          // Node 183
                          opcode = arm64_a64_cmhs_reg;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 53:
                        {
                          // Node 279
                          // Node 280
                          opcode = arm64_a64_fabd;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 5:
                    {
                      // Node 281
                      // Node 282
                      switch (UNSIGNED_BITS(ir, 15,10)) 
                      {
                      case 53:
                        {
                          // Node 283
                          // Node 284
                          opcode = arm64_a64_fabd;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  // Node 407
                  // Node 408
                  switch (UNSIGNED_BITS(ir, 21,10)) 
                  {
                  case 2158:
                    {
                      // Node 409
                      // Node 410
                      opcode = arm64_a64_fcvtzs_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      case 1:
        {
          // Node 1557
          switch (UNSIGNED_BITS(ir, 27,10)) 
          {
          case 176130:
            {
              // Node 1002
              // Node 1003
              opcode = arm64_a64_rev;
              length = 4;
              ((arm64_decode_a64_DP_1S&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_DP_1S&)*this).S = BITSEL(ir, 29);
              ((arm64_decode_a64_DP_1S&)*this).opcode2 = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_DP_1S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_DP_1S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_DP_1S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_DP_1S&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,22)) 
          {
          case 8:
            {
              // Node 249
              // Node 250
              opcode = arm64_a64_eori;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 12:
            {
              // Node 1382
              // Node 1383
              opcode = arm64_a64_ubfm;
              length = 4;
              ((arm64_decode_a64_BITFIELD&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_BITFIELD&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_BITFIELD&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_BITFIELD&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_BITFIELD&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_BITFIELD&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_BITFIELD&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_BITFIELD&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,24)) 
          {
          case 4:
            {
              // Node 78
              // Node 79
              switch ((ir & BIT_LSB(4)) >> 4)
              {
              case 0:
                {
                  // Node 80
                  // Node 81
                  opcode = arm64_a64_bcond;
                  length = 4;
                  ((arm64_decode_a64_COND_B_IMM&)*this).o1 = BITSEL(ir, 24);
                  ((arm64_decode_a64_COND_B_IMM&)*this).imm19 = UNSIGNED_BITS(ir, 23,5);
                  ((arm64_decode_a64_COND_B_IMM&)*this).o0 = BITSEL(ir, 4);
                  ((arm64_decode_a64_COND_B_IMM&)*this).cond = UNSIGNED_BITS(ir, 3,0);
                  ((arm64_decode_a64_COND_B_IMM&)*this).decode_behaviour();
                  end_of_block = true;
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 8:
            {
              // Node 695
              // Node 696
              opcode = arm64_a64_ldr_lit;
              length = 4;
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).imm19 = UNSIGNED_BITS(ir, 23,5);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,26)) 
          {
          case 3:
            {
              // Node 1566
              switch (UNSIGNED_BITS(ir, 25,23)) 
              {
              case 6:
                {
                  // Node 1048
                  // Node 1049
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 21:
                    {
                      // Node 1050
                      // Node 1051
                      opcode = arm64_a64_shl_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immh = UNSIGNED_BITS(ir, 22,19);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immb = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1:
                    {
                      // Node 1094
                      // Node 1095
                      opcode = arm64_a64_sshr;
                      length = 4;
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immh = UNSIGNED_BITS(ir, 22,19);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immb = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 25,24)) 
              {
              case 2:
                {
                  // Node 1567
                  switch (UNSIGNED_BITS(ir, 23,10)) 
                  {
                  case 10290:
                    {
                      // Node 313
                      // Node 314
                      opcode = arm64_a64_fcmgt_zero;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 6262:
                    {
                      // Node 1038
                      // Node 1039
                      opcode = arm64_a64_scvtf_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2166:
                    {
                      // Node 1040
                      // Node 1041
                      opcode = arm64_a64_scvtf_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 23,21)) 
                  {
                  case 7:
                    {
                      // Node 1568
                      switch (UNSIGNED_BITS(ir, 20,10)) 
                      {
                      case 1134:
                        {
                          // Node 34
                          // Node 35
                          opcode = arm64_a64_addp_scalar;
                          length = 4;
                          ((arm64_decode_a64_SIMD_SCALAR_PW&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_SCALAR_PW&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_SCALAR_PW&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                          ((arm64_decode_a64_SIMD_SCALAR_PW&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_SCALAR_PW&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_SCALAR_PW&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 38:
                        {
                          // Node 165
                          // Node 166
                          opcode = arm64_a64_cmeq_zero;
                          length = 4;
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 42:
                        {
                          // Node 190
                          // Node 191
                          opcode = arm64_a64_cmlt_zero;
                          length = 4;
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 50:
                        {
                          // Node 311
                          // Node 312
                          opcode = arm64_a64_fcmgt_zero;
                          length = 4;
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 194
                      // Node 195
                      switch (UNSIGNED_BITS(ir, 15,10)) 
                      {
                      case 35:
                        {
                          // Node 196
                          // Node 197
                          opcode = arm64_a64_cmtst;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  // Node 343
                  // Node 344
                  switch (UNSIGNED_BITS(ir, 21,10)) 
                  {
                  case 2162:
                    {
                      // Node 345
                      // Node 346
                      opcode = arm64_a64_fcvtas_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2158:
                    {
                      // Node 411
                      // Node 412
                      opcode = arm64_a64_fcvtzs_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      // Node 172
      // Node 173
      switch (UNSIGNED_BITS(ir, 28,10)) 
      {
      case 505890:
        {
          // Node 174
          // Node 175
          opcode = arm64_a64_cmge_zero;
          length = 4;
          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      }
      break;
    }
  case 2:
    {
      // Node 1510
      switch (UNSIGNED_BITS(ir, 29,24)) 
      {
      case 8:
        {
          // Node 1574
          switch (UNSIGNED_BITS(ir, 23,21)) 
          {
          case 6:
            {
              // Node 596
              // Node 597
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 598
                  // Node 599
                  opcode = arm64_a64_ldar;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 3:
            {
              // Node 612
              // Node 613
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 614
                  // Node 615
                  opcode = arm64_a64_ldaxp;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 852
                  // Node 853
                  opcode = arm64_a64_ldxp;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 2:
            {
              // Node 620
              // Node 621
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 622
                  // Node 623
                  opcode = arm64_a64_ldaxr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 856
                  // Node 857
                  opcode = arm64_a64_ldxr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 4:
            {
              // Node 1164
              // Node 1165
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 1166
                  // Node 1167
                  opcode = arm64_a64_stlr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 1:
            {
              // Node 1180
              // Node 1181
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 1182
                  // Node 1183
                  opcode = arm64_a64_stlxp;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 1332
                  // Node 1333
                  opcode = arm64_a64_stxp;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 0:
            {
              // Node 1188
              // Node 1189
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 1190
                  // Node 1191
                  opcode = arm64_a64_stlxr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 1336
                  // Node 1337
                  opcode = arm64_a64_stxr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 29,27)) 
      {
      case 5:
        {
          // Node 1573
          switch (UNSIGNED_BITS(ir, 26,22)) 
          {
          case 21:
            {
              // Node 640
              // Node 641
              opcode = arm64_a64_ldp_simd;
              length = 4;
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 20:
            {
              // Node 1208
              // Node 1209
              opcode = arm64_a64_stp_simd;
              length = 4;
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 26,25)) 
          {
          case 2:
            {
              // Node 1218
              // Node 1219
              switch (UNSIGNED_BITS(ir, 23,22)) 
              {
              case 2:
                {
                  // Node 1220
                  // Node 1221
                  opcode = arm64_a64_stpi_simd;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).P = BITSEL(ir, 24);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 0:
            {
              // Node 1583
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 1:
                {
                  // Node 632
                  // Node 633
                  opcode = arm64_a64_ldnp;
                  length = 4;
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 5:
                {
                  // Node 636
                  // Node 637
                  opcode = arm64_a64_ldp;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 1200
                  // Node 1201
                  opcode = arm64_a64_stnp;
                  length = 4;
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_NO_ALLOC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1204
                  // Node 1205
                  opcode = arm64_a64_stp;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_OFF&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              // Node 646
              // Node 647
              switch (UNSIGNED_BITS(ir, 23,22)) 
              {
              case 3:
                {
                  // Node 648
                  // Node 649
                  opcode = arm64_a64_ldpi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).P = BITSEL(ir, 24);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 2:
                {
                  // Node 1214
                  // Node 1215
                  opcode = arm64_a64_stpi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).P = BITSEL(ir, 24);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 29,28)) 
      {
      case 3:
        {
          // Node 1571
          switch (UNSIGNED_BITS(ir, 27,22)) 
          {
          case 13:
            {
              // Node 82
              // Node 83
              opcode = arm64_a64_bfm;
              length = 4;
              ((arm64_decode_a64_BITFIELD&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_BITFIELD&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_BITFIELD&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_BITFIELD&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_BITFIELD&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_BITFIELD&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_BITFIELD&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_BITFIELD&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 9:
            {
              // Node 971
              // Node 972
              opcode = arm64_a64_orri;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 8:
            {
              // Node 973
              // Node 974
              opcode = arm64_a64_orri;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,25)) 
          {
          case 4:
            {
              // Node 1575
              switch (UNSIGNED_BITS(ir, 24,21)) 
              {
              case 5:
                {
                  // Node 701
                  // Node 702
                  switch (UNSIGNED_BITS(ir, 11,10)) 
                  {
                  case 2:
                    {
                      // Node 703
                      // Node 704
                      opcode = arm64_a64_ldr_reg;
                      length = 4;
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 4:
                {
                  // Node 797
                  // Node 829
                  switch (UNSIGNED_BITS(ir, 11,10)) 
                  {
                  case 2:
                    {
                      // Node 830
                      // Node 831
                      opcode = arm64_a64_ldtrsw;
                      length = 4;
                      ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                      ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                      ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 848
                      // Node 849
                      opcode = arm64_a64_ldursw;
                      length = 4;
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  // Node 798
                  switch ((ir & BIT_LSB(10)) >> 10)
                  {
                  case 1:
                    {
                      // Node 799
                      // Node 800
                      opcode = arm64_a64_ldrsw;
                      length = 4;
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 5:
                {
                  // Node 795
                  // Node 796
                  opcode = arm64_a64_ldri;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 6:
                {
                  // Node 803
                  // Node 804
                  opcode = arm64_a64_ldrswi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1308
                  // Node 1309
                  opcode = arm64_a64_stri;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,23)) 
              {
              case 0:
                {
                  // Node 1577
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 691
                      // Node 808
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 809
                          // Node 810
                          opcode = arm64_a64_ldtr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 834
                          // Node 835
                          opcode = arm64_a64_ldur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 692
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 693
                          // Node 694
                          opcode = arm64_a64_ldr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 709
                      // Node 710
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 711
                          // Node 712
                          opcode = arm64_a64_ldr_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1254
                      // Node 1313
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1314
                          // Node 1315
                          opcode = arm64_a64_sttr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 1324
                          // Node 1325
                          opcode = arm64_a64_stur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 1255
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 1256
                          // Node 1257
                          opcode = arm64_a64_str;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 1262
                      // Node 1263
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1264
                          // Node 1265
                          opcode = arm64_a64_str_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          case 6:
            {
              // Node 1576
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 5:
                {
                  // Node 1460
                  // Node 1461
                  opcode = arm64_a64_vldr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1485
                  // Node 1486
                  opcode = arm64_a64_vstr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,23)) 
              {
              case 0:
                {
                  // Node 1578
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 671
                      // Node 1472
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1473
                          // Node 1474
                          opcode = arm64_a64_vldur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 672
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 673
                          // Node 674
                          opcode = arm64_a64_ldr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 721
                      // Node 722
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 723
                          // Node 724
                          opcode = arm64_a64_ldr_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1234
                      // Node 1497
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1498
                          // Node 1499
                          opcode = arm64_a64_vstur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 1235
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 1236
                          // Node 1237
                          opcode = arm64_a64_str;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 1274
                      // Node 1275
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1276
                          // Node 1277
                          opcode = arm64_a64_str_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      case 1:
        {
          // Node 1572
          switch (UNSIGNED_BITS(ir, 27,24)) 
          {
          case 14:
            {
              // Node 1579
              switch (UNSIGNED_BITS(ir, 23,16)) 
              {
              case 89:
                {
                  // Node 387
                  // Node 388
                  opcode = arm64_a64_fcvtz_fxp;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 25:
                {
                  // Node 389
                  // Node 390
                  opcode = arm64_a64_fcvtz_fxp;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 88:
                {
                  // Node 395
                  // Node 396
                  opcode = arm64_a64_fcvtz_fxp;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 24:
                {
                  // Node 397
                  // Node 398
                  opcode = arm64_a64_fcvtz_fxp;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 67:
                {
                  // Node 1388
                  // Node 1389
                  opcode = arm64_a64_ucvtf_fxp;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 3:
                {
                  // Node 1390
                  // Node 1391
                  opcode = arm64_a64_ucvtf_fxp;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 195:
                {
                  // Node 1392
                  // Node 1393
                  opcode = arm64_a64_ucvtf_fxp;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).scale = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_FXP&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,25)) 
          {
          case 1:
            {
              // Node 1581
              switch (UNSIGNED_BITS(ir, 24,21)) 
              {
              case 14:
                {
                  // Node 271
                  // Node 272
                  opcode = arm64_a64_extr;
                  length = 4;
                  ((arm64_decode_a64_EXTRACT&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_EXTRACT&)*this).op21 = UNSIGNED_BITS(ir, 30,29);
                  ((arm64_decode_a64_EXTRACT&)*this).N = BITSEL(ir, 22);
                  ((arm64_decode_a64_EXTRACT&)*this).o0 = BITSEL(ir, 21);
                  ((arm64_decode_a64_EXTRACT&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_EXTRACT&)*this).imms = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_EXTRACT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_EXTRACT&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_EXTRACT&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 1:
                {
                  // Node 53
                  // Node 54
                  opcode = arm64_a64_andi;
                  length = 4;
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 55
                  // Node 56
                  opcode = arm64_a64_andi;
                  length = 4;
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 5:
                {
                  // Node 1026
                  // Node 1027
                  opcode = arm64_a64_sbfm;
                  length = 4;
                  ((arm64_decode_a64_BITFIELD&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_BITFIELD&)*this).opc = UNSIGNED_BITS(ir, 30,29);
                  ((arm64_decode_a64_BITFIELD&)*this).N = BITSEL(ir, 22);
                  ((arm64_decode_a64_BITFIELD&)*this).immr = UNSIGNED_BITS(ir, 21,16);
                  ((arm64_decode_a64_BITFIELD&)*this).imms = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_BITFIELD&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_BITFIELD&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_BITFIELD&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,26)) 
          {
          case 2:
            {
              // Node 1580
              switch (UNSIGNED_BITS(ir, 25,21)) 
              {
              case 22:
                {
                  // Node 202
                  // Node 203
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 19:
                    {
                      // Node 204
                      // Node 205
                      opcode = arm64_a64_crc32;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 23:
                    {
                      // Node 214
                      // Node 215
                      opcode = arm64_a64_crc32c;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 25,24)) 
              {
              case 0:
                {
                  // Node 801
                  // Node 802
                  opcode = arm64_a64_ldrsw_lit;
                  length = 4;
                  ((arm64_decode_a64_LOAD_REG_LIT&)*this).opc = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LOAD_REG_LIT&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LOAD_REG_LIT&)*this).imm19 = UNSIGNED_BITS(ir, 23,5);
                  ((arm64_decode_a64_LOAD_REG_LIT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LOAD_REG_LIT&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 3:
                {
                  // Node 1582
                  switch (UNSIGNED_BITS(ir, 23,21)) 
                  {
                  case 1:
                    {
                      // Node 1058
                      // Node 1059
                      switch ((ir & BIT_LSB(15)) >> 15)
                      {
                      case 0:
                        {
                          // Node 1060
                          // Node 1061
                          opcode = arm64_a64_smaddl;
                          length = 4;
                          ((arm64_decode_a64_DP_3S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_3S&)*this).op54 = UNSIGNED_BITS(ir, 30,29);
                          ((arm64_decode_a64_DP_3S&)*this).op31 = UNSIGNED_BITS(ir, 23,21);
                          ((arm64_decode_a64_DP_3S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_3S&)*this).o0 = BITSEL(ir, 15);
                          ((arm64_decode_a64_DP_3S&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                          ((arm64_decode_a64_DP_3S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_3S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_3S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 1:
                        {
                          // Node 1078
                          // Node 1079
                          opcode = arm64_a64_smsubl;
                          length = 4;
                          ((arm64_decode_a64_DP_3S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_3S&)*this).op54 = UNSIGNED_BITS(ir, 30,29);
                          ((arm64_decode_a64_DP_3S&)*this).op31 = UNSIGNED_BITS(ir, 23,21);
                          ((arm64_decode_a64_DP_3S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_3S&)*this).o0 = BITSEL(ir, 15);
                          ((arm64_decode_a64_DP_3S&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                          ((arm64_decode_a64_DP_3S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_3S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_3S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 2:
                    {
                      // Node 1080
                      // Node 1081
                      switch ((ir & BIT_LSB(15)) >> 15)
                      {
                      case 0:
                        {
                          // Node 1082
                          // Node 1083
                          opcode = arm64_a64_smulh;
                          length = 4;
                          ((arm64_decode_a64_DP_3S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_3S&)*this).op54 = UNSIGNED_BITS(ir, 30,29);
                          ((arm64_decode_a64_DP_3S&)*this).op31 = UNSIGNED_BITS(ir, 23,21);
                          ((arm64_decode_a64_DP_3S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_3S&)*this).o0 = BITSEL(ir, 15);
                          ((arm64_decode_a64_DP_3S&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                          ((arm64_decode_a64_DP_3S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_3S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_3S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 5:
                    {
                      // Node 1410
                      // Node 1411
                      switch ((ir & BIT_LSB(15)) >> 15)
                      {
                      case 0:
                        {
                          // Node 1412
                          // Node 1413
                          opcode = arm64_a64_umaddl;
                          length = 4;
                          ((arm64_decode_a64_DP_3S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_3S&)*this).op54 = UNSIGNED_BITS(ir, 30,29);
                          ((arm64_decode_a64_DP_3S&)*this).op31 = UNSIGNED_BITS(ir, 23,21);
                          ((arm64_decode_a64_DP_3S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_3S&)*this).o0 = BITSEL(ir, 15);
                          ((arm64_decode_a64_DP_3S&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                          ((arm64_decode_a64_DP_3S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_3S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_3S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 1:
                        {
                          // Node 1424
                          // Node 1425
                          opcode = arm64_a64_umsubl;
                          length = 4;
                          ((arm64_decode_a64_DP_3S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_3S&)*this).op54 = UNSIGNED_BITS(ir, 30,29);
                          ((arm64_decode_a64_DP_3S&)*this).op31 = UNSIGNED_BITS(ir, 23,21);
                          ((arm64_decode_a64_DP_3S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_3S&)*this).o0 = BITSEL(ir, 15);
                          ((arm64_decode_a64_DP_3S&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                          ((arm64_decode_a64_DP_3S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_3S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_3S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 6:
                    {
                      // Node 1426
                      // Node 1427
                      switch ((ir & BIT_LSB(15)) >> 15)
                      {
                      case 0:
                        {
                          // Node 1428
                          // Node 1429
                          opcode = arm64_a64_umulh;
                          length = 4;
                          ((arm64_decode_a64_DP_3S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_3S&)*this).op54 = UNSIGNED_BITS(ir, 30,29);
                          ((arm64_decode_a64_DP_3S&)*this).op31 = UNSIGNED_BITS(ir, 23,21);
                          ((arm64_decode_a64_DP_3S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_3S&)*this).o0 = BITSEL(ir, 15);
                          ((arm64_decode_a64_DP_3S&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                          ((arm64_decode_a64_DP_3S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_3S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_3S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      break;
    }
  case 3:
    {
      // Node 1511
      switch (UNSIGNED_BITS(ir, 29,24)) 
      {
      case 8:
        {
          // Node 1586
          switch (UNSIGNED_BITS(ir, 23,21)) 
          {
          case 6:
            {
              // Node 592
              // Node 593
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 594
                  // Node 595
                  opcode = arm64_a64_ldar;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 3:
            {
              // Node 608
              // Node 609
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 610
                  // Node 611
                  opcode = arm64_a64_ldaxp;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 850
                  // Node 851
                  opcode = arm64_a64_ldxp;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 2:
            {
              // Node 616
              // Node 617
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 618
                  // Node 619
                  opcode = arm64_a64_ldaxr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 854
                  // Node 855
                  opcode = arm64_a64_ldxr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 4:
            {
              // Node 1160
              // Node 1161
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 1162
                  // Node 1163
                  opcode = arm64_a64_stlr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 1:
            {
              // Node 1176
              // Node 1177
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 1178
                  // Node 1179
                  opcode = arm64_a64_stlxp;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 1330
                  // Node 1331
                  opcode = arm64_a64_stxp;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 0:
            {
              // Node 1184
              // Node 1185
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 1:
                {
                  // Node 1186
                  // Node 1187
                  opcode = arm64_a64_stlxr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 1334
                  // Node 1335
                  opcode = arm64_a64_stxr;
                  length = 4;
                  ((arm64_decode_a64_LS_EX&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_EX&)*this).o2 = BITSEL(ir, 23);
                  ((arm64_decode_a64_LS_EX&)*this).L = BITSEL(ir, 22);
                  ((arm64_decode_a64_LS_EX&)*this).o1 = BITSEL(ir, 21);
                  ((arm64_decode_a64_LS_EX&)*this).rs = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_LS_EX&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_LS_EX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_LS_EX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_EX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_EX&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 29,28)) 
      {
      case 1:
        {
          // Node 1584
          switch (UNSIGNED_BITS(ir, 27,10)) 
          {
          case 176131:
            {
              // Node 1000
              // Node 1001
              opcode = arm64_a64_rev;
              length = 4;
              ((arm64_decode_a64_DP_1S&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_DP_1S&)*this).S = BITSEL(ir, 29);
              ((arm64_decode_a64_DP_1S&)*this).opcode2 = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_DP_1S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_DP_1S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_DP_1S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_DP_1S&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 176130:
            {
              // Node 1006
              // Node 1007
              opcode = arm64_a64_rev32;
              length = 4;
              ((arm64_decode_a64_DP_1S&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_DP_1S&)*this).S = BITSEL(ir, 29);
              ((arm64_decode_a64_DP_1S&)*this).opcode2 = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_DP_1S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_DP_1S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_DP_1S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_DP_1S&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,22)) 
          {
          case 9:
            {
              // Node 245
              // Node 246
              opcode = arm64_a64_eori;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 8:
            {
              // Node 247
              // Node 248
              opcode = arm64_a64_eori;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 13:
            {
              // Node 1380
              // Node 1381
              opcode = arm64_a64_ubfm;
              length = 4;
              ((arm64_decode_a64_BITFIELD&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_BITFIELD&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_BITFIELD&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_BITFIELD&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_BITFIELD&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_BITFIELD&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_BITFIELD&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_BITFIELD&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,24)) 
          {
          case 8:
            {
              // Node 984
              // Node 985
              opcode = arm64_a64_prfm_lit;
              length = 4;
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).imm19 = UNSIGNED_BITS(ir, 23,5);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOAD_REG_LIT&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,26)) 
          {
          case 1:
            {
              // Node 1587
              switch (UNSIGNED_BITS(ir, 25,21)) 
              {
              case 2:
                {
                  // Node 254
                  // Node 255
                  switch (UNSIGNED_BITS(ir, 4,0)) 
                  {
                  case 0:
                    {
                      // Node 256
                      opcode = arm64_a64_exgen;
                      length = 4;
                      ((arm64_decode_a64_EX_GEN&)*this).opc = UNSIGNED_BITS(ir, 23,21);
                      ((arm64_decode_a64_EX_GEN&)*this).imm16 = UNSIGNED_BITS(ir, 20,5);
                      ((arm64_decode_a64_EX_GEN&)*this).op2 = UNSIGNED_BITS(ir, 4,2);
                      ((arm64_decode_a64_EX_GEN&)*this).ll = UNSIGNED_BITS(ir, 1,0);
                      ((arm64_decode_a64_EX_GEN&)*this).decode_behaviour();
                      end_of_block = true;
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 1:
                {
                  // Node 257
                  // Node 258
                  switch (UNSIGNED_BITS(ir, 4,0)) 
                  {
                  case 0:
                    {
                      // Node 259
                      opcode = arm64_a64_exgen;
                      length = 4;
                      ((arm64_decode_a64_EX_GEN&)*this).opc = UNSIGNED_BITS(ir, 23,21);
                      ((arm64_decode_a64_EX_GEN&)*this).imm16 = UNSIGNED_BITS(ir, 20,5);
                      ((arm64_decode_a64_EX_GEN&)*this).op2 = UNSIGNED_BITS(ir, 4,2);
                      ((arm64_decode_a64_EX_GEN&)*this).ll = UNSIGNED_BITS(ir, 1,0);
                      ((arm64_decode_a64_EX_GEN&)*this).decode_behaviour();
                      end_of_block = true;
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 260
                  // Node 261
                  switch (UNSIGNED_BITS(ir, 4,0)) 
                  {
                  case 3:
                    {
                      // Node 262
                      opcode = arm64_a64_exgen;
                      length = 4;
                      ((arm64_decode_a64_EX_GEN&)*this).opc = UNSIGNED_BITS(ir, 23,21);
                      ((arm64_decode_a64_EX_GEN&)*this).imm16 = UNSIGNED_BITS(ir, 20,5);
                      ((arm64_decode_a64_EX_GEN&)*this).op2 = UNSIGNED_BITS(ir, 4,2);
                      ((arm64_decode_a64_EX_GEN&)*this).ll = UNSIGNED_BITS(ir, 1,0);
                      ((arm64_decode_a64_EX_GEN&)*this).decode_behaviour();
                      end_of_block = true;
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2:
                    {
                      // Node 263
                      opcode = arm64_a64_exgen;
                      length = 4;
                      ((arm64_decode_a64_EX_GEN&)*this).opc = UNSIGNED_BITS(ir, 23,21);
                      ((arm64_decode_a64_EX_GEN&)*this).imm16 = UNSIGNED_BITS(ir, 20,5);
                      ((arm64_decode_a64_EX_GEN&)*this).op2 = UNSIGNED_BITS(ir, 4,2);
                      ((arm64_decode_a64_EX_GEN&)*this).ll = UNSIGNED_BITS(ir, 1,0);
                      ((arm64_decode_a64_EX_GEN&)*this).decode_behaviour();
                      end_of_block = true;
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1:
                    {
                      // Node 264
                      opcode = arm64_a64_exgen;
                      length = 4;
                      ((arm64_decode_a64_EX_GEN&)*this).opc = UNSIGNED_BITS(ir, 23,21);
                      ((arm64_decode_a64_EX_GEN&)*this).imm16 = UNSIGNED_BITS(ir, 20,5);
                      ((arm64_decode_a64_EX_GEN&)*this).op2 = UNSIGNED_BITS(ir, 4,2);
                      ((arm64_decode_a64_EX_GEN&)*this).ll = UNSIGNED_BITS(ir, 1,0);
                      ((arm64_decode_a64_EX_GEN&)*this).decode_behaviour();
                      end_of_block = true;
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 25,22)) 
              {
              case 4:
                {
                  // Node 1588
                  switch (UNSIGNED_BITS(ir, 21,5)) 
                  {
                  case 49280:
                    {
                      // Node 927
                      // Node 928
                      opcode = arm64_a64_msr_sctlr;
                      length = 4;
                      ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                      ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                      ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                      ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                      end_of_block = true;
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 21,12)) 
                  {
                  case 51:
                    {
                      // Node 73
                      // Node 74
                      switch (UNSIGNED_BITS(ir, 7,0)) 
                      {
                      case 223:
                        {
                          // Node 75
                          opcode = arm64_a64_barrier;
                          length = 4;
                          ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                          ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                          ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                          ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 191:
                        {
                          // Node 76
                          opcode = arm64_a64_barrier;
                          length = 4;
                          ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                          ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                          ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                          ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 159:
                        {
                          // Node 77
                          opcode = arm64_a64_barrier;
                          length = 4;
                          ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                          ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                          ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                          ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 95:
                        {
                          // Node 148
                          opcode = arm64_a64_clrex;
                          length = 4;
                          ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                          ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                          ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                          ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 50:
                    {
                      // Node 533
                      // Node 534
                      switch (UNSIGNED_BITS(ir, 4,0)) 
                      {
                      case 31:
                        {
                          // Node 535
                          opcode = arm64_a64_hint;
                          length = 4;
                          ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                          ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                          ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                          ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 21,19)) 
                  {
                  case 7:
                    {
                      // Node 914
                      // Node 915
                      opcode = arm64_a64_mrs;
                      length = 4;
                      ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                      ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                      ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                      ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 6:
                    {
                      // Node 916
                      // Node 917
                      opcode = arm64_a64_mrs;
                      length = 4;
                      ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                      ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                      ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                      ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 918
                      // Node 919
                      switch (UNSIGNED_BITS(ir, 15,12)) 
                      {
                      case 4:
                        {
                          // Node 920
                          // Node 921
                          switch (UNSIGNED_BITS(ir, 4,0)) 
                          {
                          case 31:
                            {
                              // Node 922
                              opcode = arm64_a64_msr_imm;
                              length = 4;
                              ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                              ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                              ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                              ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                              ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                              ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                              ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                              ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                              is_predicated = false;
                              return true;
                              break;
                            }
                          }
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 923
                      // Node 924
                      opcode = arm64_a64_msr_reg;
                      length = 4;
                      ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                      ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                      ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                      ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2:
                    {
                      // Node 925
                      // Node 926
                      opcode = arm64_a64_msr_reg;
                      length = 4;
                      ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                      ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                      ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                      ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1:
                    {
                      // Node 1358
                      // Node 1359
                      opcode = arm64_a64_sys;
                      length = 4;
                      ((arm64_decode_a64_SYSTEM&)*this).l = BITSEL(ir, 21);
                      ((arm64_decode_a64_SYSTEM&)*this).op0 = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_SYSTEM&)*this).op1 = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_SYSTEM&)*this).crn = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SYSTEM&)*this).crm = UNSIGNED_BITS(ir, 11,8);
                      ((arm64_decode_a64_SYSTEM&)*this).op2 = UNSIGNED_BITS(ir, 7,5);
                      ((arm64_decode_a64_SYSTEM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SYSTEM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 25,24)) 
              {
              case 2:
                {
                  // Node 1589
                  switch (UNSIGNED_BITS(ir, 23,0)) 
                  {
                  case 12518368:
                    {
                      // Node 234
                      opcode = arm64_a64_drps;
                      length = 4;
                      ((arm64_decode_a64_UB_REG&)*this).opc = UNSIGNED_BITS(ir, 24,21);
                      ((arm64_decode_a64_UB_REG&)*this).op2 = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_UB_REG&)*this).op3 = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_UB_REG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_UB_REG&)*this).op4 = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_UB_REG&)*this).decode_behaviour();
                      end_of_block = true;
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 10421216:
                    {
                      // Node 253
                      opcode = arm64_a64_eret;
                      length = 4;
                      ((arm64_decode_a64_UB_REG&)*this).opc = UNSIGNED_BITS(ir, 24,21);
                      ((arm64_decode_a64_UB_REG&)*this).op2 = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_UB_REG&)*this).op3 = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_UB_REG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_UB_REG&)*this).op4 = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_UB_REG&)*this).decode_behaviour();
                      end_of_block = true;
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 23,10)) 
                  {
                  case 4032:
                    {
                      // Node 116
                      // Node 117
                      switch (UNSIGNED_BITS(ir, 4,0)) 
                      {
                      case 0:
                        {
                          // Node 118
                          opcode = arm64_a64_br;
                          length = 4;
                          ((arm64_decode_a64_UB_REG&)*this).opc = UNSIGNED_BITS(ir, 24,21);
                          ((arm64_decode_a64_UB_REG&)*this).op2 = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_UB_REG&)*this).op3 = UNSIGNED_BITS(ir, 15,10);
                          ((arm64_decode_a64_UB_REG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_UB_REG&)*this).op4 = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_UB_REG&)*this).decode_behaviour();
                          end_of_block = true;
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1984:
                    {
                      // Node 119
                      // Node 120
                      switch (UNSIGNED_BITS(ir, 4,0)) 
                      {
                      case 0:
                        {
                          // Node 121
                          opcode = arm64_a64_br;
                          length = 4;
                          ((arm64_decode_a64_UB_REG&)*this).opc = UNSIGNED_BITS(ir, 24,21);
                          ((arm64_decode_a64_UB_REG&)*this).op2 = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_UB_REG&)*this).op3 = UNSIGNED_BITS(ir, 15,10);
                          ((arm64_decode_a64_UB_REG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_UB_REG&)*this).op4 = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_UB_REG&)*this).decode_behaviour();
                          end_of_block = true;
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 6080:
                    {
                      // Node 997
                      // Node 998
                      switch (UNSIGNED_BITS(ir, 4,0)) 
                      {
                      case 0:
                        {
                          // Node 999
                          opcode = arm64_a64_ret;
                          length = 4;
                          ((arm64_decode_a64_UB_REG&)*this).opc = UNSIGNED_BITS(ir, 24,21);
                          ((arm64_decode_a64_UB_REG&)*this).op2 = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_UB_REG&)*this).op3 = UNSIGNED_BITS(ir, 15,10);
                          ((arm64_decode_a64_UB_REG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_UB_REG&)*this).op4 = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_UB_REG&)*this).decode_behaviour();
                          end_of_block = true;
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      case 3:
        {
          // Node 1585
          switch (UNSIGNED_BITS(ir, 27,22)) 
          {
          case 9:
            {
              // Node 47
              // Node 48
              opcode = arm64_a64_andi;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 8:
            {
              // Node 49
              // Node 50
              opcode = arm64_a64_andi;
              length = 4;
              ((arm64_decode_a64_LOGICAL_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).N = BITSEL(ir, 22);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).immr = UNSIGNED_BITS(ir, 21,16);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).imms = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,25)) 
          {
          case 4:
            {
              // Node 1590
              switch (UNSIGNED_BITS(ir, 24,21)) 
              {
              case 4:
                {
                  // Node 980
                  // Node 992
                  switch (UNSIGNED_BITS(ir, 11,10)) 
                  {
                  case 0:
                    {
                      // Node 993
                      // Node 994
                      opcode = arm64_a64_prfum;
                      length = 4;
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  // Node 981
                  switch ((ir & BIT_LSB(10)) >> 10)
                  {
                  case 1:
                    {
                      // Node 982
                      // Node 983
                      opcode = arm64_a64_prfm;
                      length = 4;
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 5:
                {
                  // Node 986
                  // Node 987
                  switch (UNSIGNED_BITS(ir, 11,10)) 
                  {
                  case 2:
                    {
                      // Node 988
                      // Node 989
                      opcode = arm64_a64_prfm_reg;
                      length = 4;
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 5:
                {
                  // Node 793
                  // Node 794
                  opcode = arm64_a64_ldri;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 6:
                {
                  // Node 990
                  // Node 991
                  opcode = arm64_a64_prfmi;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1306
                  // Node 1307
                  opcode = arm64_a64_stri;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,23)) 
              {
              case 0:
                {
                  // Node 1592
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 687
                      // Node 805
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 806
                          // Node 807
                          opcode = arm64_a64_ldtr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 832
                          // Node 833
                          opcode = arm64_a64_ldur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 688
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 689
                          // Node 690
                          opcode = arm64_a64_ldr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 705
                      // Node 706
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 707
                          // Node 708
                          opcode = arm64_a64_ldr_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1250
                      // Node 1310
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1311
                          // Node 1312
                          opcode = arm64_a64_sttr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_UNPRIV&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 1322
                          // Node 1323
                          opcode = arm64_a64_stur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 1251
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 1252
                          // Node 1253
                          opcode = arm64_a64_str;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 1258
                      // Node 1259
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1260
                          // Node 1261
                          opcode = arm64_a64_str_reg;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          case 6:
            {
              // Node 1591
              switch (UNSIGNED_BITS(ir, 24,22)) 
              {
              case 5:
                {
                  // Node 1458
                  // Node 1459
                  opcode = arm64_a64_vldr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 1483
                  // Node 1484
                  opcode = arm64_a64_vstr;
                  length = 4;
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).V = BITSEL(ir, 26);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_LS_REG_UIMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 24,23)) 
              {
              case 0:
                {
                  // Node 1593
                  switch (UNSIGNED_BITS(ir, 22,21)) 
                  {
                  case 2:
                    {
                      // Node 667
                      // Node 1469
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1470
                          // Node 1471
                          opcode = arm64_a64_vldur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 668
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 669
                          // Node 670
                          opcode = arm64_a64_ldr;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 3:
                    {
                      // Node 717
                      // Node 718
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 719
                          // Node 720
                          opcode = arm64_a64_ldr_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1230
                      // Node 1494
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1495
                          // Node 1496
                          opcode = arm64_a64_vstur;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).opc = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_USIMM&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      // Node 1231
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 1:
                        {
                          // Node 1232
                          // Node 1233
                          opcode = arm64_a64_str;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).imm9 = UNSIGNED_BITS(ir, 20,12);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).P = BITSEL(ir, 11);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_IMM_POST&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 1:
                    {
                      // Node 1270
                      // Node 1271
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1272
                          // Node 1273
                          opcode = arm64_a64_str_reg_simd;
                          length = 4;
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).size = UNSIGNED_BITS(ir, 31,30);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).V = BITSEL(ir, 26);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).X = BITSEL(ir, 23);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option21 = UNSIGNED_BITS(ir, 15,14);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).option0 = BITSEL(ir, 13);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_LS_REG_REG_OFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      break;
    }
  }
  switch ((ir & BIT_LSB(31)) >> 31)
  {
  case 0:
    {
      // Node 1
      // Node 2
      switch (UNSIGNED_BITS(ir, 29,21)) 
      {
      case 247:
        {
          // Node 22
          // Node 23
          switch (UNSIGNED_BITS(ir, 15,10)) 
          {
          case 33:
            {
              // Node 24
              // Node 25
              opcode = arm64_a64_add_vector;
              length = 4;
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      case 503:
        {
          // Node 1348
          // Node 1349
          switch (UNSIGNED_BITS(ir, 15,10)) 
          {
          case 33:
            {
              // Node 1350
              // Node 1351
              opcode = arm64_a64_sub_vector;
              length = 4;
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 29,26)) 
      {
      case 3:
        {
          // Node 1512
          switch (UNSIGNED_BITS(ir, 25,19)) 
          {
          case 96:
            {
              // Node 457
              // Node 458
              switch (UNSIGNED_BITS(ir, 15,10)) 
              {
              case 25:
                {
                  // Node 894
                  // Node 895
                  opcode = arm64_a64_movi;
                  length = 4;
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 17:
                {
                  // Node 896
                  // Node 897
                  opcode = arm64_a64_movi;
                  length = 4;
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 9:
                {
                  // Node 898
                  // Node 899
                  opcode = arm64_a64_movi;
                  length = 4;
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 1:
                {
                  // Node 900
                  // Node 901
                  opcode = arm64_a64_movi;
                  length = 4;
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 41:
                {
                  // Node 902
                  // Node 903
                  opcode = arm64_a64_movi;
                  length = 4;
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 33:
                {
                  // Node 904
                  // Node 905
                  opcode = arm64_a64_movi;
                  length = 4;
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 15,14)) 
              {
              case 3:
                {
                  // Node 1524
                  switch (UNSIGNED_BITS(ir, 13,10)) 
                  {
                  case 13:
                    {
                      // Node 459
                      // Node 460
                      opcode = arm64_a64_fmov_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 5:
                    {
                      // Node 890
                      // Node 891
                      opcode = arm64_a64_movi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1:
                    {
                      // Node 892
                      // Node 893
                      opcode = arm64_a64_movi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 9:
                    {
                      // Node 906
                      // Node 907
                      opcode = arm64_a64_movi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 25,23)) 
          {
          case 6:
            {
              // Node 1044
              // Node 1045
              switch (UNSIGNED_BITS(ir, 15,10)) 
              {
              case 21:
                {
                  // Node 1046
                  // Node 1047
                  opcode = arm64_a64_shl_simd;
                  length = 4;
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immh = UNSIGNED_BITS(ir, 22,19);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immb = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 1:
                {
                  // Node 1092
                  // Node 1093
                  opcode = arm64_a64_sshr;
                  length = 4;
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immh = UNSIGNED_BITS(ir, 22,19);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immb = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 25,24)) 
          {
          case 3:
            {
              // Node 931
              // Node 932
              switch (UNSIGNED_BITS(ir, 15,12)) 
              {
              case 8:
                {
                  // Node 933
                  // Node 934
                  switch ((ir & BIT_LSB(10)) >> 10)
                  {
                  case 0:
                    {
                      // Node 935
                      // Node 936
                      opcode = arm64_a64_mul_idx_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).L = BITSEL(ir, 21);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).M = BITSEL(ir, 20);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).rm = UNSIGNED_BITS(ir, 19,16);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).H = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_VECTOR_IDX&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          case 0:
            {
              // Node 1514
              switch (UNSIGNED_BITS(ir, 23,16)) 
              {
              case 64:
                {
                  // Node 1517
                  switch (UNSIGNED_BITS(ir, 15,12)) 
                  {
                  case 10:
                    {
                      // Node 546
                      // Node 547
                      opcode = arm64_a64_ld1;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 7:
                    {
                      // Node 548
                      // Node 549
                      opcode = arm64_a64_ld1;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 6:
                    {
                      // Node 550
                      // Node 551
                      opcode = arm64_a64_ld1;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2:
                    {
                      // Node 552
                      // Node 553
                      opcode = arm64_a64_ld1;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 8:
                    {
                      // Node 580
                      // Node 581
                      opcode = arm64_a64_ld2;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 4:
                    {
                      // Node 584
                      // Node 585
                      opcode = arm64_a64_ld3;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 588
                      // Node 589
                      opcode = arm64_a64_ld4;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1518
                  switch (UNSIGNED_BITS(ir, 15,12)) 
                  {
                  case 10:
                    {
                      // Node 1100
                      // Node 1101
                      opcode = arm64_a64_st1;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 7:
                    {
                      // Node 1102
                      // Node 1103
                      opcode = arm64_a64_st1;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 6:
                    {
                      // Node 1104
                      // Node 1105
                      opcode = arm64_a64_st1;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2:
                    {
                      // Node 1106
                      // Node 1107
                      opcode = arm64_a64_st1;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 8:
                    {
                      // Node 1148
                      // Node 1149
                      opcode = arm64_a64_st2;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 4:
                    {
                      // Node 1152
                      // Node 1153
                      opcode = arm64_a64_st3;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 1156
                      // Node 1157
                      opcode = arm64_a64_st4;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 23,21)) 
              {
              case 6:
                {
                  // Node 554
                  // Node 555
                  switch (UNSIGNED_BITS(ir, 15,12)) 
                  {
                  case 10:
                    {
                      // Node 556
                      // Node 557
                      opcode = arm64_a64_ld1pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 7:
                    {
                      // Node 558
                      // Node 559
                      opcode = arm64_a64_ld1pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 6:
                    {
                      // Node 560
                      // Node 561
                      opcode = arm64_a64_ld1pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2:
                    {
                      // Node 562
                      // Node 563
                      opcode = arm64_a64_ld1pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 8:
                    {
                      // Node 582
                      // Node 583
                      opcode = arm64_a64_ld2pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 4:
                    {
                      // Node 586
                      // Node 587
                      opcode = arm64_a64_ld3pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 590
                      // Node 591
                      opcode = arm64_a64_ld4pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 4:
                {
                  // Node 1108
                  // Node 1109
                  switch (UNSIGNED_BITS(ir, 15,12)) 
                  {
                  case 10:
                    {
                      // Node 1110
                      // Node 1111
                      opcode = arm64_a64_st1pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 7:
                    {
                      // Node 1112
                      // Node 1113
                      opcode = arm64_a64_st1pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 6:
                    {
                      // Node 1114
                      // Node 1115
                      opcode = arm64_a64_st1pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2:
                    {
                      // Node 1116
                      // Node 1117
                      opcode = arm64_a64_st1pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 8:
                    {
                      // Node 1150
                      // Node 1151
                      opcode = arm64_a64_st2pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 4:
                    {
                      // Node 1154
                      // Node 1155
                      opcode = arm64_a64_st3pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 0:
                    {
                      // Node 1158
                      // Node 1159
                      opcode = arm64_a64_st4pi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_MULT_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          case 1:
            {
              // Node 1515
              switch (UNSIGNED_BITS(ir, 23,16)) 
              {
              case 64:
                {
                  // Node 1519
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 33:
                    {
                      // Node 566
                      // Node 567
                      opcode = arm64_a64_ld1s;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 15,12)) 
                  {
                  case 12:
                    {
                      // Node 564
                      // Node 565
                      opcode = arm64_a64_ld1r;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 15,13)) 
                  {
                  case 4:
                    {
                      // Node 568
                      // Node 569
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 570
                          // Node 571
                          opcode = arm64_a64_ld1s;
                          length = 4;
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 2:
                    {
                      // Node 572
                      // Node 573
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 574
                          // Node 575
                          opcode = arm64_a64_ld1s;
                          length = 4;
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 576
                          // Node 577
                          opcode = arm64_a64_ld1s;
                          length = 4;
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 578
                      // Node 579
                      opcode = arm64_a64_ld1s;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1520
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 33:
                    {
                      // Node 1118
                      // Node 1119
                      opcode = arm64_a64_st1s;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 15,13)) 
                  {
                  case 4:
                    {
                      // Node 1120
                      // Node 1121
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1122
                          // Node 1123
                          opcode = arm64_a64_st1s;
                          length = 4;
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 2:
                    {
                      // Node 1124
                      // Node 1125
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1126
                          // Node 1127
                          opcode = arm64_a64_st1s;
                          length = 4;
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 1128
                          // Node 1129
                          opcode = arm64_a64_st1s;
                          length = 4;
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1130
                      // Node 1131
                      opcode = arm64_a64_st1s;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).R = BITSEL(ir, 21);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).S = BITSEL(ir, 12);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_SINGLE&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 23,21)) 
              {
              case 4:
                {
                  // Node 1132
                  // Node 1133
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 33:
                    {
                      // Node 1134
                      // Node 1135
                      opcode = arm64_a64_st1spi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).R = BITSEL(ir, 21);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).S = BITSEL(ir, 12);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 15,13)) 
                  {
                  case 4:
                    {
                      // Node 1136
                      // Node 1137
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 0:
                        {
                          // Node 1138
                          // Node 1139
                          opcode = arm64_a64_st1spi;
                          length = 4;
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).R = BITSEL(ir, 21);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 2:
                    {
                      // Node 1140
                      // Node 1141
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 1142
                          // Node 1143
                          opcode = arm64_a64_st1spi;
                          length = 4;
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).R = BITSEL(ir, 21);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 1144
                          // Node 1145
                          opcode = arm64_a64_st1spi;
                          length = 4;
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).L = BITSEL(ir, 22);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).R = BITSEL(ir, 21);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).S = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  case 0:
                    {
                      // Node 1146
                      // Node 1147
                      opcode = arm64_a64_st1spi;
                      length = 4;
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).L = BITSEL(ir, 22);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).R = BITSEL(ir, 21);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).opcode = UNSIGNED_BITS(ir, 15,13);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).S = BITSEL(ir, 12);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).size = UNSIGNED_BITS(ir, 11,10);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).rt = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_LS_SINGLE_PI&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          case 2:
            {
              // Node 1516
              switch (UNSIGNED_BITS(ir, 23,10)) 
              {
              case 14446:
                {
                  // Node 403
                  // Node 404
                  opcode = arm64_a64_fcvtzs_simd;
                  length = 4;
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 10350:
                {
                  // Node 405
                  // Node 406
                  opcode = arm64_a64_fcvtzs_simd;
                  length = 4;
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 6262:
                {
                  // Node 1034
                  // Node 1035
                  opcode = arm64_a64_scvtf_simd;
                  length = 4;
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 2166:
                {
                  // Node 1036
                  // Node 1037
                  opcode = arm64_a64_scvtf_simd;
                  length = 4;
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 23,21)) 
              {
              case 1:
                {
                  // Node 43
                  // Node 44
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 7:
                    {
                      // Node 45
                      // Node 46
                      opcode = arm64_a64_and_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 37:
                    {
                      // Node 874
                      // Node 875
                      opcode = arm64_a64_mla_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 39:
                    {
                      // Node 941
                      // Node 942
                      opcode = arm64_a64_mul_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 3:
                {
                  // Node 86
                  // Node 87
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 7:
                    {
                      // Node 88
                      // Node 89
                      opcode = arm64_a64_bic_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 37:
                    {
                      // Node 872
                      // Node 873
                      opcode = arm64_a64_mla_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 39:
                    {
                      // Node 939
                      // Node 940
                      opcode = arm64_a64_mul_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 235
                  // Node 236
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 1:
                    {
                      // Node 237
                      // Node 238
                      opcode = arm64_a64_dup_elem;
                      length = 4;
                      ((arm64_decode_a64_SIMD_COPY&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_COPY&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_COPY&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 3:
                    {
                      // Node 239
                      // Node 240
                      opcode = arm64_a64_dup_gen;
                      length = 4;
                      ((arm64_decode_a64_SIMD_COPY&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_COPY&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_COPY&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_COPY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_COPY&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 5:
                {
                  // Node 529
                  // Node 530
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 53:
                    {
                      // Node 531
                      // Node 532
                      opcode = arm64_a64_fsub_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 37:
                    {
                      // Node 870
                      // Node 871
                      opcode = arm64_a64_mla_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 39:
                    {
                      // Node 937
                      // Node 938
                      opcode = arm64_a64_mul_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 7:
                    {
                      // Node 969
                      // Node 970
                      opcode = arm64_a64_orr_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 7:
                {
                  // Node 965
                  // Node 966
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 7:
                    {
                      // Node 967
                      // Node 968
                      opcode = arm64_a64_orn_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              // Node 26
              // Node 27
              switch (UNSIGNED_BITS(ir, 21,16)) 
              {
              case 32:
                {
                  // Node 1521
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 38:
                    {
                      // Node 163
                      // Node 164
                      opcode = arm64_a64_cmeq_zero;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 42:
                    {
                      // Node 186
                      // Node 187
                      opcode = arm64_a64_cmlt_zero;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 22:
                    {
                      // Node 198
                      // Node 199
                      opcode = arm64_a64_cnt;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2:
                    {
                      // Node 1010
                      // Node 1011
                      opcode = arm64_a64_rev64_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 21,17)) 
              {
              case 24:
                {
                  // Node 1522
                  switch (UNSIGNED_BITS(ir, 16,10)) 
                  {
                  case 110:
                    {
                      // Node 38
                      // Node 39
                      opcode = arm64_a64_addv;
                      length = 4;
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 14:
                    {
                      // Node 1016
                      // Node 1017
                      opcode = arm64_a64_saddlv;
                      length = 4;
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 42:
                    {
                      // Node 1066
                      // Node 1067
                      opcode = arm64_a64_smaxv;
                      length = 4;
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 106:
                    {
                      // Node 1070
                      // Node 1071
                      opcode = arm64_a64_sminv;
                      length = 4;
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch ((ir & BIT_LSB(21)) >> 21)
              {
              case 1:
                {
                  // Node 28
                  // Node 29
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 33:
                    {
                      // Node 30
                      // Node 31
                      opcode = arm64_a64_add_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 47:
                    {
                      // Node 36
                      // Node 37
                      opcode = arm64_a64_addp_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 35:
                    {
                      // Node 192
                      // Node 193
                      opcode = arm64_a64_cmtst;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 56:
                    {
                      // Node 978
                      // Node 979
                      opcode = arm64_a64_pmull;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 48:
                    {
                      // Node 1084
                      // Node 1085
                      opcode = arm64_a64_smull;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 15,14)) 
                  {
                  case 0:
                    {
                      // Node 1523
                      switch (UNSIGNED_BITS(ir, 13,10)) 
                      {
                      case 0:
                        {
                          // Node 1014
                          // Node 1015
                          opcode = arm64_a64_saddl;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 4:
                        {
                          // Node 1018
                          // Node 1019
                          opcode = arm64_a64_saddw;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 8:
                        {
                          // Node 1096
                          // Node 1097
                          opcode = arm64_a64_ssubl;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 12:
                        {
                          // Node 1098
                          // Node 1099
                          opcode = arm64_a64_ssubw;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1360
                  // Node 1361
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 6:
                    {
                      // Node 1452
                      // Node 1453
                      opcode = arm64_a64_uzp1;
                      length = 4;
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).opcode = UNSIGNED_BITS(ir, 14,12);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 22:
                    {
                      // Node 1454
                      // Node 1455
                      opcode = arm64_a64_uzp2;
                      length = 4;
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).opcode = UNSIGNED_BITS(ir, 14,12);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_PERMUTE&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 0:
                    {
                      // Node 1362
                      // Node 1363
                      switch (UNSIGNED_BITS(ir, 12,10)) 
                      {
                      case 0:
                        {
                          // Node 1364
                          // Node 1365
                          opcode = arm64_a64_tbl;
                          length = 4;
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).op2 = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).len = UNSIGNED_BITS(ir, 14,13);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).op = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 4:
                        {
                          // Node 1366
                          // Node 1367
                          opcode = arm64_a64_tbx;
                          length = 4;
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).op2 = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).len = UNSIGNED_BITS(ir, 14,13);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).op = BITSEL(ir, 12);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_TABLE_LOOKUP&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      case 11:
        {
          // Node 1513
          switch (UNSIGNED_BITS(ir, 25,19)) 
          {
          case 96:
            {
              // Node 90
              // Node 91
              switch (UNSIGNED_BITS(ir, 15,10)) 
              {
              case 53:
                {
                  // Node 943
                  // Node 944
                  opcode = arm64_a64_mvni;
                  length = 4;
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 49:
                {
                  // Node 945
                  // Node 946
                  opcode = arm64_a64_mvni;
                  length = 4;
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 15,14)) 
              {
              case 2:
                {
                  // Node 1529
                  switch (UNSIGNED_BITS(ir, 13,10)) 
                  {
                  case 13:
                    {
                      // Node 92
                      // Node 93
                      opcode = arm64_a64_bici;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 5:
                    {
                      // Node 94
                      // Node 95
                      opcode = arm64_a64_bici;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 9:
                    {
                      // Node 947
                      // Node 948
                      opcode = arm64_a64_mvni;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1:
                    {
                      // Node 949
                      // Node 950
                      opcode = arm64_a64_mvni;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 1:
                {
                  // Node 1530
                  switch (UNSIGNED_BITS(ir, 13,10)) 
                  {
                  case 13:
                    {
                      // Node 96
                      // Node 97
                      opcode = arm64_a64_bici;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 5:
                    {
                      // Node 98
                      // Node 99
                      opcode = arm64_a64_bici;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 9:
                    {
                      // Node 951
                      // Node 952
                      opcode = arm64_a64_mvni;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1:
                    {
                      // Node 953
                      // Node 954
                      opcode = arm64_a64_mvni;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 1531
                  switch (UNSIGNED_BITS(ir, 13,10)) 
                  {
                  case 13:
                    {
                      // Node 100
                      // Node 101
                      opcode = arm64_a64_bici;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 5:
                    {
                      // Node 102
                      // Node 103
                      opcode = arm64_a64_bici;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 9:
                    {
                      // Node 955
                      // Node 956
                      opcode = arm64_a64_mvni;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1:
                    {
                      // Node 957
                      // Node 958
                      opcode = arm64_a64_mvni;
                      length = 4;
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).op = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).a = BITSEL(ir, 18);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).b = BITSEL(ir, 17);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).c = BITSEL(ir, 16);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).cmode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).o2 = BITSEL(ir, 11);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).d = BITSEL(ir, 9);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).e = BITSEL(ir, 8);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).f = BITSEL(ir, 7);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).g = BITSEL(ir, 6);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).h = BITSEL(ir, 5);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_MOD_IMM&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 25,23)) 
          {
          case 6:
            {
              // Node 1440
              // Node 1441
              switch (UNSIGNED_BITS(ir, 15,10)) 
              {
              case 1:
                {
                  // Node 1442
                  // Node 1443
                  opcode = arm64_a64_ushr;
                  length = 4;
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immh = UNSIGNED_BITS(ir, 22,19);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immb = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 25,24)) 
          {
          case 2:
            {
              // Node 1525
              switch (UNSIGNED_BITS(ir, 23,10)) 
              {
              case 7218:
                {
                  // Node 421
                  // Node 422
                  opcode = arm64_a64_fmaxnmv;
                  length = 4;
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 7230:
                {
                  // Node 425
                  // Node 426
                  opcode = arm64_a64_fmaxv;
                  length = 4;
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 15410:
                {
                  // Node 429
                  // Node 430
                  opcode = arm64_a64_fminnmv;
                  length = 4;
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 11314:
                {
                  // Node 431
                  // Node 432
                  opcode = arm64_a64_fminnmv;
                  length = 4;
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 15422:
                {
                  // Node 433
                  // Node 434
                  opcode = arm64_a64_fminv;
                  length = 4;
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 11326:
                {
                  // Node 435
                  // Node 436
                  opcode = arm64_a64_fminv;
                  length = 4;
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 6262:
                {
                  // Node 1400
                  // Node 1401
                  opcode = arm64_a64_ucvtf_simd;
                  length = 4;
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 23,21)) 
              {
              case 7:
                {
                  // Node 108
                  // Node 109
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 7:
                    {
                      // Node 110
                      // Node 111
                      opcode = arm64_a64_bif;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 53:
                    {
                      // Node 275
                      // Node 276
                      opcode = arm64_a64_fabd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 5:
                {
                  // Node 112
                  // Node 113
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 7:
                    {
                      // Node 114
                      // Node 115
                      opcode = arm64_a64_bit;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 53:
                    {
                      // Node 277
                      // Node 278
                      opcode = arm64_a64_fabd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 3:
                {
                  // Node 122
                  // Node 123
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 7:
                    {
                      // Node 124
                      // Node 125
                      opcode = arm64_a64_bsl;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              case 1:
                {
                  // Node 1526
                  switch (UNSIGNED_BITS(ir, 20,10)) 
                  {
                  case 1074:
                    {
                      // Node 423
                      // Node 424
                      opcode = arm64_a64_fmaxnmv;
                      length = 4;
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1086:
                    {
                      // Node 427
                      // Node 428
                      opcode = arm64_a64_fmaxv;
                      length = 4;
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 22:
                    {
                      // Node 963
                      // Node 964
                      opcode = arm64_a64_not_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 118:
                    {
                      // Node 1402
                      // Node 1403
                      opcode = arm64_a64_ucvtf_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  // Node 241
                  // Node 242
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 7:
                    {
                      // Node 243
                      // Node 244
                      opcode = arm64_a64_eor_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 55:
                    {
                      // Node 475
                      // Node 476
                      opcode = arm64_a64_fmul_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              // Node 153
              // Node 154
              switch (UNSIGNED_BITS(ir, 21,10)) 
              {
              case 3086:
                {
                  // Node 1376
                  // Node 1377
                  opcode = arm64_a64_uaddlv;
                  length = 4;
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 3114:
                {
                  // Node 1414
                  // Node 1415
                  opcode = arm64_a64_umaxv;
                  length = 4;
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 3178:
                {
                  // Node 1416
                  // Node 1417
                  opcode = arm64_a64_uminv;
                  length = 4;
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_ACROSS_LANES&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 21,16)) 
              {
              case 32:
                {
                  // Node 1527
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 38:
                    {
                      // Node 184
                      // Node 185
                      opcode = arm64_a64_cmlt_zero;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 46:
                    {
                      // Node 959
                      // Node 960
                      opcode = arm64_a64_neg_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2:
                    {
                      // Node 1008
                      // Node 1009
                      opcode = arm64_a64_rev32_simd;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 26:
                    {
                      // Node 1370
                      // Node 1371
                      opcode = arm64_a64_uadalp;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 10:
                    {
                      // Node 1374
                      // Node 1375
                      opcode = arm64_a64_uaddlp;
                      length = 4;
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              switch ((ir & BIT_LSB(21)) >> 21)
              {
              case 1:
                {
                  // Node 155
                  // Node 156
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 35:
                    {
                      // Node 157
                      // Node 158
                      opcode = arm64_a64_cmeq_reg;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 33:
                    {
                      // Node 1352
                      // Node 1353
                      opcode = arm64_a64_sub_vector;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 48:
                    {
                      // Node 1430
                      // Node 1431
                      opcode = arm64_a64_umull;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 15,14)) 
                  {
                  case 0:
                    {
                      // Node 1528
                      switch (UNSIGNED_BITS(ir, 13,10)) 
                      {
                      case 13:
                        {
                          // Node 176
                          // Node 177
                          opcode = arm64_a64_cmhi_reg;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 15:
                        {
                          // Node 180
                          // Node 181
                          opcode = arm64_a64_cmhs_reg;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 1372
                          // Node 1373
                          opcode = arm64_a64_uaddl;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 4:
                        {
                          // Node 1378
                          // Node 1379
                          opcode = arm64_a64_uaddw;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 8:
                        {
                          // Node 1448
                          // Node 1449
                          opcode = arm64_a64_usubl;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 12:
                        {
                          // Node 1450
                          // Node 1451
                          opcode = arm64_a64_usubw;
                          length = 4;
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).U = BITSEL(ir, 29);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).SCALAR = BITSEL(ir, 28);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).size = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).opcode = UNSIGNED_BITS(ir, 15,12);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_THREE_DIFF&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              case 0:
                {
                  // Node 265
                  // Node 266
                  switch ((ir & BIT_LSB(15)) >> 15)
                  {
                  case 0:
                    {
                      // Node 267
                      // Node 268
                      switch ((ir & BIT_LSB(10)) >> 10)
                      {
                      case 0:
                        {
                          // Node 269
                          // Node 270
                          opcode = arm64_a64_ext;
                          length = 4;
                          ((arm64_decode_a64_SIMD_EXTRACT&)*this).Q = BITSEL(ir, 30);
                          ((arm64_decode_a64_SIMD_EXTRACT&)*this).op2 = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_SIMD_EXTRACT&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_SIMD_EXTRACT&)*this).imm4 = UNSIGNED_BITS(ir, 14,11);
                          ((arm64_decode_a64_SIMD_EXTRACT&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_SIMD_EXTRACT&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_SIMD_EXTRACT&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      switch ((ir & BIT_LSB(29)) >> 29)
      {
      case 0:
        {
          // Node 3
          // Node 4
          switch (UNSIGNED_BITS(ir, 27,23)) 
          {
          case 30:
            {
              // Node 1088
              // Node 1089
              switch (UNSIGNED_BITS(ir, 15,10)) 
              {
              case 41:
                {
                  // Node 1090
                  // Node 1091
                  opcode = arm64_a64_sshll;
                  length = 4;
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immh = UNSIGNED_BITS(ir, 22,19);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immb = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,24)) 
          {
          case 14:
            {
              // Node 5
              // Node 6
              switch (UNSIGNED_BITS(ir, 21,10)) 
              {
              case 2094:
                {
                  // Node 7
                  // Node 8
                  opcode = arm64_a64_abs_simd;
                  length = 4;
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 2070:
                {
                  // Node 200
                  // Node 201
                  opcode = arm64_a64_cnt;
                  length = 4;
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 2122:
                {
                  // Node 1506
                  // Node 1507
                  opcode = arm64_a64_xtn;
                  length = 4;
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch ((ir & BIT_LSB(21)) >> 21)
              {
              case 1:
                {
                  // Node 1062
                  // Node 1063
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 25:
                    {
                      // Node 1064
                      // Node 1065
                      opcode = arm64_a64_smax;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 27:
                    {
                      // Node 1068
                      // Node 1069
                      opcode = arm64_a64_smin;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 17:
                    {
                      // Node 1086
                      // Node 1087
                      opcode = arm64_a64_sshl;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      case 1:
        {
          // Node 1052
          // Node 1053
          switch (UNSIGNED_BITS(ir, 27,23)) 
          {
          case 30:
            {
              // Node 1436
              // Node 1437
              switch (UNSIGNED_BITS(ir, 15,10)) 
              {
              case 41:
                {
                  // Node 1438
                  // Node 1439
                  opcode = arm64_a64_ushll;
                  length = 4;
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immh = UNSIGNED_BITS(ir, 22,19);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).immb = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_SHIFT_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 27,24)) 
          {
          case 14:
            {
              // Node 1054
              // Node 1055
              switch (UNSIGNED_BITS(ir, 21,10)) 
              {
              case 2126:
                {
                  // Node 1056
                  // Node 1057
                  opcode = arm64_a64_shll;
                  length = 4;
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch ((ir & BIT_LSB(21)) >> 21)
              {
              case 1:
                {
                  // Node 1432
                  // Node 1433
                  switch (UNSIGNED_BITS(ir, 15,10)) 
                  {
                  case 17:
                    {
                      // Node 1434
                      // Node 1435
                      opcode = arm64_a64_ushl;
                      length = 4;
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).Q = BITSEL(ir, 30);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).U = BITSEL(ir, 29);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).SCALAR = BITSEL(ir, 28);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).size = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).opcode = UNSIGNED_BITS(ir, 15,11);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_SIMD_THREE_SAME&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      // Node 167
      switch (UNSIGNED_BITS(ir, 28,24)) 
      {
      case 14:
        {
          // Node 168
          // Node 169
          switch (UNSIGNED_BITS(ir, 21,10)) 
          {
          case 2082:
            {
              // Node 170
              // Node 171
              opcode = arm64_a64_cmge_zero;
              length = 4;
              ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).Q = BITSEL(ir, 30);
              ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).U = BITSEL(ir, 29);
              ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).SCALAR = BITSEL(ir, 28);
              ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).size = UNSIGNED_BITS(ir, 23,22);
              ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).opcode = UNSIGNED_BITS(ir, 16,12);
              ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_SIMD_TWO_REG_MISC&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      }
      break;
    }
  }
  // Node 9
  switch (UNSIGNED_BITS(ir, 30,21)) 
  {
  case 978:
    {
      // Node 138
      // Node 139
      switch (UNSIGNED_BITS(ir, 11,10)) 
      {
      case 2:
        {
          // Node 140
          // Node 141
          switch ((ir & BIT_LSB(4)) >> 4)
          {
          case 0:
            {
              // Node 142
              // Node 143
              opcode = arm64_a64_ccmpi;
              length = 4;
              ((arm64_decode_a64_COND_CMP_IMM&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_COND_CMP_IMM&)*this).op = BITSEL(ir, 30);
              ((arm64_decode_a64_COND_CMP_IMM&)*this).S = BITSEL(ir, 29);
              ((arm64_decode_a64_COND_CMP_IMM&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_COND_CMP_IMM&)*this).cond = UNSIGNED_BITS(ir, 15,12);
              ((arm64_decode_a64_COND_CMP_IMM&)*this).o2 = BITSEL(ir, 10);
              ((arm64_decode_a64_COND_CMP_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_COND_CMP_IMM&)*this).o3 = BITSEL(ir, 4);
              ((arm64_decode_a64_COND_CMP_IMM&)*this).nzcv = UNSIGNED_BITS(ir, 3,0);
              ((arm64_decode_a64_COND_CMP_IMM&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      case 0:
        {
          // Node 144
          // Node 145
          switch ((ir & BIT_LSB(4)) >> 4)
          {
          case 0:
            {
              // Node 146
              // Node 147
              opcode = arm64_a64_ccmpr;
              length = 4;
              ((arm64_decode_a64_COND_CMP_REG&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_COND_CMP_REG&)*this).op = BITSEL(ir, 30);
              ((arm64_decode_a64_COND_CMP_REG&)*this).S = BITSEL(ir, 29);
              ((arm64_decode_a64_COND_CMP_REG&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_COND_CMP_REG&)*this).cond = UNSIGNED_BITS(ir, 15,12);
              ((arm64_decode_a64_COND_CMP_REG&)*this).o2 = BITSEL(ir, 10);
              ((arm64_decode_a64_COND_CMP_REG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_COND_CMP_REG&)*this).o3 = BITSEL(ir, 4);
              ((arm64_decode_a64_COND_CMP_REG&)*this).nzcv = UNSIGNED_BITS(ir, 3,0);
              ((arm64_decode_a64_COND_CMP_REG&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      }
      break;
    }
  }
  switch (UNSIGNED_BITS(ir, 30,23)) 
  {
  case 229:
    {
      // Node 908
      // Node 909
      opcode = arm64_a64_movk;
      length = 4;
      ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).sf = BITSEL(ir, 31);
      ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
      ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).hw = UNSIGNED_BITS(ir, 22,21);
      ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).imm16 = UNSIGNED_BITS(ir, 20,5);
      ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
      ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).decode_behaviour();
      is_predicated = false;
      return true;
      break;
    }
  }
  switch (UNSIGNED_BITS(ir, 30,24)) 
  {
  case 106:
    {
      // Node 59
      // Node 60
      switch ((ir & BIT_LSB(21)) >> 21)
      {
      case 0:
        {
          // Node 61
          // Node 62
          opcode = arm64_a64_andsr;
          length = 4;
          ((arm64_decode_a64_LOGICAL_SR&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_LOGICAL_SR&)*this).opc = UNSIGNED_BITS(ir, 30,29);
          ((arm64_decode_a64_LOGICAL_SR&)*this).shift = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_LOGICAL_SR&)*this).N = BITSEL(ir, 21);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rm = UNSIGNED_BITS(ir, 20,16);
          ((arm64_decode_a64_LOGICAL_SR&)*this).imm6 = UNSIGNED_BITS(ir, 15,10);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_LOGICAL_SR&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      case 1:
        {
          // Node 104
          // Node 105
          opcode = arm64_a64_bicsr;
          length = 4;
          ((arm64_decode_a64_LOGICAL_SR&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_LOGICAL_SR&)*this).opc = UNSIGNED_BITS(ir, 30,29);
          ((arm64_decode_a64_LOGICAL_SR&)*this).shift = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_LOGICAL_SR&)*this).N = BITSEL(ir, 21);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rm = UNSIGNED_BITS(ir, 20,16);
          ((arm64_decode_a64_LOGICAL_SR&)*this).imm6 = UNSIGNED_BITS(ir, 15,10);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_LOGICAL_SR&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      }
      break;
    }
  }
  switch (UNSIGNED_BITS(ir, 30,29)) 
  {
  case 0:
    {
      // Node 1594
      switch (UNSIGNED_BITS(ir, 28,23)) 
      {
      case 37:
        {
          // Node 910
          // Node 911
          opcode = arm64_a64_movn;
          length = 4;
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).hw = UNSIGNED_BITS(ir, 22,21);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).imm16 = UNSIGNED_BITS(ir, 20,5);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 28,24)) 
      {
      case 10:
        {
          // Node 63
          // Node 64
          switch ((ir & BIT_LSB(21)) >> 21)
          {
          case 0:
            {
              // Node 65
              // Node 66
              opcode = arm64_a64_andsr;
              length = 4;
              ((arm64_decode_a64_LOGICAL_SR&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_SR&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_SR&)*this).shift = UNSIGNED_BITS(ir, 23,22);
              ((arm64_decode_a64_LOGICAL_SR&)*this).N = BITSEL(ir, 21);
              ((arm64_decode_a64_LOGICAL_SR&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_LOGICAL_SR&)*this).imm6 = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_SR&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_SR&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_SR&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          case 1:
            {
              // Node 106
              // Node 107
              opcode = arm64_a64_bicsr;
              length = 4;
              ((arm64_decode_a64_LOGICAL_SR&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_SR&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_SR&)*this).shift = UNSIGNED_BITS(ir, 23,22);
              ((arm64_decode_a64_LOGICAL_SR&)*this).N = BITSEL(ir, 21);
              ((arm64_decode_a64_LOGICAL_SR&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_LOGICAL_SR&)*this).imm6 = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_SR&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_SR&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_SR&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 28,26)) 
      {
      case 5:
        {
          // Node 71
          // Node 72
          opcode = arm64_a64_b;
          length = 4;
          ((arm64_decode_a64_UB_IMM&)*this).op = BITSEL(ir, 31);
          ((arm64_decode_a64_UB_IMM&)*this).imm26 = UNSIGNED_BITS(ir, 25,0);
          ((arm64_decode_a64_UB_IMM&)*this).decode_behaviour();
          end_of_block = true;
          is_predicated = false;
          return true;
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 28,27)) 
      {
      case 3:
        {
          // Node 1597
          switch (UNSIGNED_BITS(ir, 26,21)) 
          {
          case 22:
            {
              // Node 67
              // Node 68
              switch (UNSIGNED_BITS(ir, 15,14)) 
              {
              case 0:
                {
                  // Node 1603
                  switch (UNSIGNED_BITS(ir, 13,10)) 
                  {
                  case 3:
                    {
                      // Node 1042
                      // Node 1043
                      opcode = arm64_a64_sdiv;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 2:
                    {
                      // Node 1408
                      // Node 1409
                      opcode = arm64_a64_udiv;
                      length = 4;
                      ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                      ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                      ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 13,12)) 
                  {
                  case 2:
                    {
                      // Node 1604
                      switch (UNSIGNED_BITS(ir, 11,10)) 
                      {
                      case 2:
                        {
                          // Node 69
                          // Node 70
                          opcode = arm64_a64_asrv;
                          length = 4;
                          ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                          ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 862
                          // Node 863
                          opcode = arm64_a64_lslv;
                          length = 4;
                          ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                          ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 1:
                        {
                          // Node 864
                          // Node 865
                          opcode = arm64_a64_lsrv;
                          length = 4;
                          ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                          ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 3:
                        {
                          // Node 1012
                          // Node 1013
                          opcode = arm64_a64_rorv;
                          length = 4;
                          ((arm64_decode_a64_DP_2S&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_DP_2S&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_DP_2S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                          ((arm64_decode_a64_DP_2S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                          ((arm64_decode_a64_DP_2S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_DP_2S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_DP_2S&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          case 20:
            {
              // Node 222
              // Node 223
              switch (UNSIGNED_BITS(ir, 11,10)) 
              {
              case 0:
                {
                  // Node 224
                  // Node 225
                  opcode = arm64_a64_csel;
                  length = 4;
                  ((arm64_decode_a64_COND_SEL&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_COND_SEL&)*this).op = BITSEL(ir, 30);
                  ((arm64_decode_a64_COND_SEL&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_COND_SEL&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_COND_SEL&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_COND_SEL&)*this).op2 = UNSIGNED_BITS(ir, 11,10);
                  ((arm64_decode_a64_COND_SEL&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_COND_SEL&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_COND_SEL&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 1:
                {
                  // Node 226
                  // Node 227
                  opcode = arm64_a64_csinc;
                  length = 4;
                  ((arm64_decode_a64_COND_SEL&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_COND_SEL&)*this).op = BITSEL(ir, 30);
                  ((arm64_decode_a64_COND_SEL&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_COND_SEL&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_COND_SEL&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_COND_SEL&)*this).op2 = UNSIGNED_BITS(ir, 11,10);
                  ((arm64_decode_a64_COND_SEL&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_COND_SEL&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_COND_SEL&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 24:
            {
              // Node 866
              // Node 867
              switch ((ir & BIT_LSB(15)) >> 15)
              {
              case 0:
                {
                  // Node 868
                  // Node 869
                  opcode = arm64_a64_madd;
                  length = 4;
                  ((arm64_decode_a64_DP_3S&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_DP_3S&)*this).op54 = UNSIGNED_BITS(ir, 30,29);
                  ((arm64_decode_a64_DP_3S&)*this).op31 = UNSIGNED_BITS(ir, 23,21);
                  ((arm64_decode_a64_DP_3S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_DP_3S&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_DP_3S&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_DP_3S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_DP_3S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_DP_3S&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 1:
                {
                  // Node 929
                  // Node 930
                  opcode = arm64_a64_msub;
                  length = 4;
                  ((arm64_decode_a64_DP_3S&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_DP_3S&)*this).op54 = UNSIGNED_BITS(ir, 30,29);
                  ((arm64_decode_a64_DP_3S&)*this).op31 = UNSIGNED_BITS(ir, 23,21);
                  ((arm64_decode_a64_DP_3S&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_DP_3S&)*this).o0 = BITSEL(ir, 15);
                  ((arm64_decode_a64_DP_3S&)*this).ra = UNSIGNED_BITS(ir, 14,10);
                  ((arm64_decode_a64_DP_3S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_DP_3S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_DP_3S&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 26,24)) 
          {
          case 6:
            {
              // Node 1598
              switch (UNSIGNED_BITS(ir, 23,10)) 
              {
              case 11200:
                {
                  // Node 441
                  // Node 442
                  opcode = arm64_a64_fmov_gen;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 11136:
                {
                  // Node 443
                  // Node 444
                  opcode = arm64_a64_fmov_gen;
                  length = 4;
                  ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                  ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                  ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                  ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              switch (UNSIGNED_BITS(ir, 23,21)) 
              {
              case 3:
                {
                  // Node 1599
                  switch (UNSIGNED_BITS(ir, 20,10)) 
                  {
                  case 1088:
                    {
                      // Node 347
                      // Node 348
                      opcode = arm64_a64_fcvti;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1024:
                    {
                      // Node 349
                      // Node 350
                      opcode = arm64_a64_fcvti;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 576:
                    {
                      // Node 351
                      // Node 352
                      opcode = arm64_a64_fcvti;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 512:
                    {
                      // Node 353
                      // Node 354
                      opcode = arm64_a64_fcvti;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1600:
                    {
                      // Node 379
                      // Node 380
                      opcode = arm64_a64_fcvtz;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1536:
                    {
                      // Node 381
                      // Node 382
                      opcode = arm64_a64_fcvtz;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 20,19)) 
                  {
                  case 0:
                    {
                      // Node 1601
                      switch (UNSIGNED_BITS(ir, 18,10)) 
                      {
                      case 320:
                        {
                          // Node 355
                          // Node 356
                          opcode = arm64_a64_fcvti;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 256:
                        {
                          // Node 357
                          // Node 358
                          opcode = arm64_a64_fcvti;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 64:
                        {
                          // Node 359
                          // Node 360
                          opcode = arm64_a64_fcvti;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 361
                          // Node 362
                          opcode = arm64_a64_fcvti;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 448:
                        {
                          // Node 445
                          // Node 446
                          opcode = arm64_a64_fmov_gen;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 384:
                        {
                          // Node 447
                          // Node 448
                          opcode = arm64_a64_fmov_gen;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 128:
                        {
                          // Node 1030
                          // Node 1031
                          opcode = arm64_a64_scvtf;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 192:
                        {
                          // Node 1384
                          // Node 1385
                          opcode = arm64_a64_ucvtf;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              case 1:
                {
                  // Node 1600
                  switch (UNSIGNED_BITS(ir, 20,10)) 
                  {
                  case 1088:
                    {
                      // Node 363
                      // Node 364
                      opcode = arm64_a64_fcvti;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1024:
                    {
                      // Node 365
                      // Node 366
                      opcode = arm64_a64_fcvti;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 576:
                    {
                      // Node 367
                      // Node 368
                      opcode = arm64_a64_fcvti;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 512:
                    {
                      // Node 369
                      // Node 370
                      opcode = arm64_a64_fcvti;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1600:
                    {
                      // Node 383
                      // Node 384
                      opcode = arm64_a64_fcvtz;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  case 1536:
                    {
                      // Node 385
                      // Node 386
                      opcode = arm64_a64_fcvtz;
                      length = 4;
                      ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                      ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                      ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                      ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                      ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                      ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                      is_predicated = false;
                      return true;
                      break;
                    }
                  }
                  switch (UNSIGNED_BITS(ir, 20,19)) 
                  {
                  case 0:
                    {
                      // Node 1602
                      switch (UNSIGNED_BITS(ir, 18,10)) 
                      {
                      case 320:
                        {
                          // Node 371
                          // Node 372
                          opcode = arm64_a64_fcvti;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 256:
                        {
                          // Node 373
                          // Node 374
                          opcode = arm64_a64_fcvti;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 64:
                        {
                          // Node 375
                          // Node 376
                          opcode = arm64_a64_fcvti;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 0:
                        {
                          // Node 377
                          // Node 378
                          opcode = arm64_a64_fcvti;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 448:
                        {
                          // Node 449
                          // Node 450
                          opcode = arm64_a64_fmov_gen;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 384:
                        {
                          // Node 451
                          // Node 452
                          opcode = arm64_a64_fmov_gen;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 128:
                        {
                          // Node 1032
                          // Node 1033
                          opcode = arm64_a64_scvtf;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      case 192:
                        {
                          // Node 1386
                          // Node 1387
                          opcode = arm64_a64_ucvtf;
                          length = 4;
                          ((arm64_decode_a64_CVT_FP_I&)*this).sf = BITSEL(ir, 31);
                          ((arm64_decode_a64_CVT_FP_I&)*this).S = BITSEL(ir, 29);
                          ((arm64_decode_a64_CVT_FP_I&)*this).type = UNSIGNED_BITS(ir, 23,22);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rmode = UNSIGNED_BITS(ir, 20,19);
                          ((arm64_decode_a64_CVT_FP_I&)*this).opcode = UNSIGNED_BITS(ir, 18,16);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                          ((arm64_decode_a64_CVT_FP_I&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                          ((arm64_decode_a64_CVT_FP_I&)*this).decode_behaviour();
                          is_predicated = false;
                          return true;
                          break;
                        }
                      }
                      break;
                    }
                  }
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      break;
    }
  case 2:
    {
      // Node 1595
      switch (UNSIGNED_BITS(ir, 28,23)) 
      {
      case 37:
        {
          // Node 912
          // Node 913
          opcode = arm64_a64_movz;
          length = 4;
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).opc = UNSIGNED_BITS(ir, 30,29);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).hw = UNSIGNED_BITS(ir, 22,21);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).imm16 = UNSIGNED_BITS(ir, 20,5);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_MOVE_WIDE_IMM&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      case 53:
        {
          // Node 1605
          switch (UNSIGNED_BITS(ir, 22,13)) 
          {
          case 512:
            {
              // Node 1606
              switch (UNSIGNED_BITS(ir, 12,10)) 
              {
              case 5:
                {
                  // Node 149
                  // Node 150
                  opcode = arm64_a64_cls;
                  length = 4;
                  ((arm64_decode_a64_DP_1S&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_DP_1S&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_DP_1S&)*this).opcode2 = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_DP_1S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_DP_1S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_DP_1S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_DP_1S&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 4:
                {
                  // Node 151
                  // Node 152
                  opcode = arm64_a64_clz;
                  length = 4;
                  ((arm64_decode_a64_DP_1S&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_DP_1S&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_DP_1S&)*this).opcode2 = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_DP_1S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_DP_1S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_DP_1S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_DP_1S&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 0:
                {
                  // Node 995
                  // Node 996
                  opcode = arm64_a64_rbit;
                  length = 4;
                  ((arm64_decode_a64_DP_1S&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_DP_1S&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_DP_1S&)*this).opcode2 = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_DP_1S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_DP_1S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_DP_1S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_DP_1S&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 1:
                {
                  // Node 1004
                  // Node 1005
                  opcode = arm64_a64_rev16;
                  length = 4;
                  ((arm64_decode_a64_DP_1S&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_DP_1S&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_DP_1S&)*this).opcode2 = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_DP_1S&)*this).opcode = UNSIGNED_BITS(ir, 15,10);
                  ((arm64_decode_a64_DP_1S&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_DP_1S&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_DP_1S&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          switch (UNSIGNED_BITS(ir, 22,21)) 
          {
          case 0:
            {
              // Node 228
              // Node 229
              switch (UNSIGNED_BITS(ir, 11,10)) 
              {
              case 0:
                {
                  // Node 230
                  // Node 231
                  opcode = arm64_a64_csinv;
                  length = 4;
                  ((arm64_decode_a64_COND_SEL&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_COND_SEL&)*this).op = BITSEL(ir, 30);
                  ((arm64_decode_a64_COND_SEL&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_COND_SEL&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_COND_SEL&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_COND_SEL&)*this).op2 = UNSIGNED_BITS(ir, 11,10);
                  ((arm64_decode_a64_COND_SEL&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_COND_SEL&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_COND_SEL&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              case 1:
                {
                  // Node 232
                  // Node 233
                  opcode = arm64_a64_csneg;
                  length = 4;
                  ((arm64_decode_a64_COND_SEL&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_COND_SEL&)*this).op = BITSEL(ir, 30);
                  ((arm64_decode_a64_COND_SEL&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_COND_SEL&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_COND_SEL&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_COND_SEL&)*this).op2 = UNSIGNED_BITS(ir, 11,10);
                  ((arm64_decode_a64_COND_SEL&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_COND_SEL&)*this).rd = UNSIGNED_BITS(ir, 4,0);
                  ((arm64_decode_a64_COND_SEL&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 28,24)) 
      {
      case 10:
        {
          // Node 251
          // Node 252
          opcode = arm64_a64_eorsr;
          length = 4;
          ((arm64_decode_a64_LOGICAL_SR&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_LOGICAL_SR&)*this).opc = UNSIGNED_BITS(ir, 30,29);
          ((arm64_decode_a64_LOGICAL_SR&)*this).shift = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_LOGICAL_SR&)*this).N = BITSEL(ir, 21);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rm = UNSIGNED_BITS(ir, 20,16);
          ((arm64_decode_a64_LOGICAL_SR&)*this).imm6 = UNSIGNED_BITS(ir, 15,10);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_LOGICAL_SR&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      }
      break;
    }
  case 1:
    {
      // Node 1596
      switch (UNSIGNED_BITS(ir, 28,21)) 
      {
      case 210:
        {
          // Node 128
          // Node 129
          switch (UNSIGNED_BITS(ir, 11,10)) 
          {
          case 2:
            {
              // Node 130
              // Node 131
              switch ((ir & BIT_LSB(4)) >> 4)
              {
              case 0:
                {
                  // Node 132
                  // Node 133
                  opcode = arm64_a64_ccmni;
                  length = 4;
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).op = BITSEL(ir, 30);
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).imm5 = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).o2 = BITSEL(ir, 10);
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).o3 = BITSEL(ir, 4);
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).nzcv = UNSIGNED_BITS(ir, 3,0);
                  ((arm64_decode_a64_COND_CMP_IMM&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          case 0:
            {
              // Node 134
              // Node 135
              switch ((ir & BIT_LSB(4)) >> 4)
              {
              case 0:
                {
                  // Node 136
                  // Node 137
                  opcode = arm64_a64_ccmnr;
                  length = 4;
                  ((arm64_decode_a64_COND_CMP_REG&)*this).sf = BITSEL(ir, 31);
                  ((arm64_decode_a64_COND_CMP_REG&)*this).op = BITSEL(ir, 30);
                  ((arm64_decode_a64_COND_CMP_REG&)*this).S = BITSEL(ir, 29);
                  ((arm64_decode_a64_COND_CMP_REG&)*this).rm = UNSIGNED_BITS(ir, 20,16);
                  ((arm64_decode_a64_COND_CMP_REG&)*this).cond = UNSIGNED_BITS(ir, 15,12);
                  ((arm64_decode_a64_COND_CMP_REG&)*this).o2 = BITSEL(ir, 10);
                  ((arm64_decode_a64_COND_CMP_REG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
                  ((arm64_decode_a64_COND_CMP_REG&)*this).o3 = BITSEL(ir, 4);
                  ((arm64_decode_a64_COND_CMP_REG&)*this).nzcv = UNSIGNED_BITS(ir, 3,0);
                  ((arm64_decode_a64_COND_CMP_REG&)*this).decode_behaviour();
                  is_predicated = false;
                  return true;
                  break;
                }
              }
              break;
            }
          }
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 28,24)) 
      {
      case 10:
        {
          // Node 876
          // Node 877
          switch (UNSIGNED_BITS(ir, 15,5)) 
          {
          case 31:
            {
              // Node 878
              // Node 879
              opcode = arm64_a64_mov;
              length = 4;
              ((arm64_decode_a64_LOGICAL_SR&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_LOGICAL_SR&)*this).opc = UNSIGNED_BITS(ir, 30,29);
              ((arm64_decode_a64_LOGICAL_SR&)*this).shift = UNSIGNED_BITS(ir, 23,22);
              ((arm64_decode_a64_LOGICAL_SR&)*this).N = BITSEL(ir, 21);
              ((arm64_decode_a64_LOGICAL_SR&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_LOGICAL_SR&)*this).imm6 = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_LOGICAL_SR&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LOGICAL_SR&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LOGICAL_SR&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          // Node 977
          opcode = arm64_a64_orrsr;
          length = 4;
          ((arm64_decode_a64_LOGICAL_SR&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_LOGICAL_SR&)*this).opc = UNSIGNED_BITS(ir, 30,29);
          ((arm64_decode_a64_LOGICAL_SR&)*this).shift = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_LOGICAL_SR&)*this).N = BITSEL(ir, 21);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rm = UNSIGNED_BITS(ir, 20,16);
          ((arm64_decode_a64_LOGICAL_SR&)*this).imm6 = UNSIGNED_BITS(ir, 15,10);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_LOGICAL_SR&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_LOGICAL_SR&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 28,25)) 
      {
      case 10:
        {
          // Node 126
          // Node 127
          opcode = arm64_a64_cbz;
          length = 4;
          ((arm64_decode_a64_CMP_B_IMM&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_CMP_B_IMM&)*this).op = BITSEL(ir, 24);
          ((arm64_decode_a64_CMP_B_IMM&)*this).imm19 = UNSIGNED_BITS(ir, 23,5);
          ((arm64_decode_a64_CMP_B_IMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_CMP_B_IMM&)*this).decode_behaviour();
          end_of_block = true;
          is_predicated = false;
          return true;
          break;
        }
      case 11:
        {
          // Node 1368
          // Node 1369
          opcode = arm64_a64_tbz;
          length = 4;
          ((arm64_decode_a64_TEST_B_IMM&)*this).b5 = BITSEL(ir, 31);
          ((arm64_decode_a64_TEST_B_IMM&)*this).op = BITSEL(ir, 24);
          ((arm64_decode_a64_TEST_B_IMM&)*this).b40 = UNSIGNED_BITS(ir, 23,19);
          ((arm64_decode_a64_TEST_B_IMM&)*this).imm14 = UNSIGNED_BITS(ir, 18,5);
          ((arm64_decode_a64_TEST_B_IMM&)*this).rt = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_TEST_B_IMM&)*this).decode_behaviour();
          end_of_block = true;
          is_predicated = false;
          return true;
          break;
        }
      }
      break;
    }
  }
  switch ((ir & BIT_LSB(30)) >> 30)
  {
  case 0:
    {
      // Node 10
      // Node 11
      switch (UNSIGNED_BITS(ir, 28,21)) 
      {
      case 208:
        {
          // Node 12
          // Node 13
          switch (UNSIGNED_BITS(ir, 15,10)) 
          {
          case 0:
            {
              // Node 14
              // Node 15
              opcode = arm64_a64_adc;
              length = 4;
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).op = BITSEL(ir, 30);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).S = BITSEL(ir, 29);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).opcode2 = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      case 89:
        {
          // Node 16
          // Node 17
          opcode = arm64_a64_add_ereg;
          length = 4;
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).op = BITSEL(ir, 30);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).S = BITSEL(ir, 29);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).opt = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).rm = UNSIGNED_BITS(ir, 20,16);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).option = UNSIGNED_BITS(ir, 15,13);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).imm3 = UNSIGNED_BITS(ir, 12,10);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 28,24)) 
      {
      case 11:
        {
          // Node 18
          // Node 19
          switch ((ir & BIT_LSB(21)) >> 21)
          {
          case 0:
            {
              // Node 20
              // Node 21
              opcode = arm64_a64_add_sreg;
              length = 4;
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).op = BITSEL(ir, 30);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).S = BITSEL(ir, 29);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).shift = UNSIGNED_BITS(ir, 23,22);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).imm6 = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      case 17:
        {
          // Node 32
          // Node 33
          opcode = arm64_a64_addi;
          length = 4;
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).op = BITSEL(ir, 30);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).S = BITSEL(ir, 29);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).shift = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      }
      break;
    }
  case 1:
    {
      // Node 1020
      // Node 1021
      switch (UNSIGNED_BITS(ir, 28,21)) 
      {
      case 208:
        {
          // Node 1022
          // Node 1023
          switch (UNSIGNED_BITS(ir, 15,10)) 
          {
          case 0:
            {
              // Node 1024
              // Node 1025
              opcode = arm64_a64_sbc;
              length = 4;
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).op = BITSEL(ir, 30);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).S = BITSEL(ir, 29);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).opcode2 = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_ADD_SUB_CARRY&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      case 89:
        {
          // Node 1342
          // Node 1343
          opcode = arm64_a64_sub_ereg;
          length = 4;
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).op = BITSEL(ir, 30);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).S = BITSEL(ir, 29);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).opt = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).rm = UNSIGNED_BITS(ir, 20,16);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).option = UNSIGNED_BITS(ir, 15,13);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).imm3 = UNSIGNED_BITS(ir, 12,10);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_ADD_SUB_EREG&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 28,22)) 
      {
      case 69:
        {
          // Node 1354
          // Node 1355
          opcode = arm64_a64_subi;
          length = 4;
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).op = BITSEL(ir, 30);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).S = BITSEL(ir, 29);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).shift = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      case 68:
        {
          // Node 1356
          // Node 1357
          opcode = arm64_a64_subi;
          length = 4;
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).sf = BITSEL(ir, 31);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).op = BITSEL(ir, 30);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).S = BITSEL(ir, 29);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).shift = UNSIGNED_BITS(ir, 23,22);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).imm12 = UNSIGNED_BITS(ir, 21,10);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).rn = UNSIGNED_BITS(ir, 9,5);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).rd = UNSIGNED_BITS(ir, 4,0);
          ((arm64_decode_a64_ADD_SUB_IMM&)*this).decode_behaviour();
          is_predicated = false;
          return true;
          break;
        }
      }
      switch (UNSIGNED_BITS(ir, 28,24)) 
      {
      case 11:
        {
          // Node 1344
          // Node 1345
          switch ((ir & BIT_LSB(21)) >> 21)
          {
          case 0:
            {
              // Node 1346
              // Node 1347
              opcode = arm64_a64_sub_sreg;
              length = 4;
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).sf = BITSEL(ir, 31);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).op = BITSEL(ir, 30);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).S = BITSEL(ir, 29);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).shift = UNSIGNED_BITS(ir, 23,22);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).rm = UNSIGNED_BITS(ir, 20,16);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).imm6 = UNSIGNED_BITS(ir, 15,10);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).rd = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_ADD_SUB_SREG&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      }
      break;
    }
  }
  // Node 654
  switch (UNSIGNED_BITS(ir, 29,24)) 
  {
  case 28:
    {
      // Node 699
      // Node 700
      opcode = arm64_a64_ldr_lit_simd;
      length = 4;
      ((arm64_decode_a64_LOAD_REG_LIT&)*this).opc = UNSIGNED_BITS(ir, 31,30);
      ((arm64_decode_a64_LOAD_REG_LIT&)*this).V = BITSEL(ir, 26);
      ((arm64_decode_a64_LOAD_REG_LIT&)*this).imm19 = UNSIGNED_BITS(ir, 23,5);
      ((arm64_decode_a64_LOAD_REG_LIT&)*this).rt = UNSIGNED_BITS(ir, 4,0);
      ((arm64_decode_a64_LOAD_REG_LIT&)*this).decode_behaviour();
      is_predicated = false;
      return true;
      break;
    }
  }
  switch (UNSIGNED_BITS(ir, 29,27)) 
  {
  case 5:
    {
      // Node 655
      // Node 656
      switch ((ir & BIT_LSB(25)) >> 25)
      {
      case 0:
        {
          // Node 657
          // Node 658
          switch ((ir & BIT_LSB(23)) >> 23)
          {
          case 1:
            {
              // Node 659
              // Node 660
              opcode = arm64_a64_ldpi_simd;
              length = 4;
              ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).opc = UNSIGNED_BITS(ir, 31,30);
              ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).V = BITSEL(ir, 26);
              ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).P = BITSEL(ir, 24);
              ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).L = BITSEL(ir, 22);
              ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).imm7 = UNSIGNED_BITS(ir, 21,15);
              ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt2 = UNSIGNED_BITS(ir, 14,10);
              ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rn = UNSIGNED_BITS(ir, 9,5);
              ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).rt = UNSIGNED_BITS(ir, 4,0);
              ((arm64_decode_a64_LS_REG_PAIR_IDX&)*this).decode_behaviour();
              is_predicated = false;
              return true;
              break;
            }
          }
          break;
        }
      }
      break;
    }
  }
  // Node 40
  switch (UNSIGNED_BITS(ir, 28,24)) 
  {
  case 16:
    {
      // Node 41
      // Node 42
      opcode = arm64_a64_adr;
      length = 4;
      ((arm64_decode_a64_PC_REL&)*this).op = BITSEL(ir, 31);
      ((arm64_decode_a64_PC_REL&)*this).immlo = UNSIGNED_BITS(ir, 30,29);
      ((arm64_decode_a64_PC_REL&)*this).immhi = UNSIGNED_BITS(ir, 23,5);
      ((arm64_decode_a64_PC_REL&)*this).rd = UNSIGNED_BITS(ir, 4,0);
      ((arm64_decode_a64_PC_REL&)*this).decode_behaviour();
      is_predicated = false;
      return true;
      break;
    }
  }
  return false;
}
