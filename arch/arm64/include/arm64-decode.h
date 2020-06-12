#pragma once
#include <decode.h>
namespace captive 
{
  namespace arch 
  {
    namespace arm64 
    {
      class arm64_decode : public Decode
      {
        public:
        enum arm64_isa_modes 
        {
          arm64_a64 = 0,
        }
        ;
        enum arm64_opcodes 
        {
          arm64_a64_abs_simd,
          arm64_a64_adc,
          arm64_a64_add_ereg,
          arm64_a64_add_sreg,
          arm64_a64_add_vector,
          arm64_a64_addi,
          arm64_a64_addp_scalar,
          arm64_a64_addp_vector,
          arm64_a64_addv,
          arm64_a64_adr,
          arm64_a64_and_vector,
          arm64_a64_andi,
          arm64_a64_andsr,
          arm64_a64_asrv,
          arm64_a64_b,
          arm64_a64_barrier,
          arm64_a64_bcond,
          arm64_a64_bfm,
          arm64_a64_bic_vector,
          arm64_a64_bici,
          arm64_a64_bicsr,
          arm64_a64_bif,
          arm64_a64_bit,
          arm64_a64_br,
          arm64_a64_bsl,
          arm64_a64_cbz,
          arm64_a64_ccmni,
          arm64_a64_ccmnr,
          arm64_a64_ccmpi,
          arm64_a64_ccmpr,
          arm64_a64_clrex,
          arm64_a64_cls,
          arm64_a64_clz,
          arm64_a64_cmeq_reg,
          arm64_a64_cmeq_zero,
          arm64_a64_cmge_zero,
          arm64_a64_cmhi_reg,
          arm64_a64_cmlt_zero,
          arm64_a64_cmtst,
          arm64_a64_cnt,
          arm64_a64_crc32,
          arm64_a64_crc32c,
          arm64_a64_csel,
          arm64_a64_csinc,
          arm64_a64_csinv,
          arm64_a64_csneg,
          arm64_a64_drps,
          arm64_a64_dup_elem,
          arm64_a64_dup_gen,
          arm64_a64_eor_vector,
          arm64_a64_eori,
          arm64_a64_eorsr,
          arm64_a64_eret,
          arm64_a64_exgen,
          arm64_a64_ext,
          arm64_a64_extr,
          arm64_a64_fabd,
          arm64_a64_fabs,
          arm64_a64_fadd,
          arm64_a64_fccmpe,
          arm64_a64_fcmgt_zero,
          arm64_a64_fcmpe,
          arm64_a64_fcsel,
          arm64_a64_fcvt,
          arm64_a64_fcvtas_simd,
          arm64_a64_fcvti,
          arm64_a64_fcvtz,
          arm64_a64_fcvtz_fxp,
          arm64_a64_fcvtzs_simd,
          arm64_a64_fdiv,
          arm64_a64_fm,
          arm64_a64_fmaxnmv,
          arm64_a64_fmaxv,
          arm64_a64_fminnmv,
          arm64_a64_fminv,
          arm64_a64_fmov,
          arm64_a64_fmov_gen,
          arm64_a64_fmov_simd,
          arm64_a64_fmovi,
          arm64_a64_fmul,
          arm64_a64_fmul_vector,
          arm64_a64_fneg,
          arm64_a64_fnm,
          arm64_a64_fnmul,
          arm64_a64_frintx,
          arm64_a64_fsqrt,
          arm64_a64_fsub,
          arm64_a64_fsub_vector,
          arm64_a64_hint,
          arm64_a64_ins_elem,
          arm64_a64_ins_gen,
          arm64_a64_ld1,
          arm64_a64_ld1pi,
          arm64_a64_ld1r,
          arm64_a64_ld1s,
          arm64_a64_ld2,
          arm64_a64_ld2pi,
          arm64_a64_ld3,
          arm64_a64_ld3pi,
          arm64_a64_ld4,
          arm64_a64_ld4pi,
          arm64_a64_ldar,
          arm64_a64_ldarb,
          arm64_a64_ldarh,
          arm64_a64_ldaxp,
          arm64_a64_ldaxr,
          arm64_a64_ldaxrb,
          arm64_a64_ldaxrh,
          arm64_a64_ldnp,
          arm64_a64_ldp,
          arm64_a64_ldp_simd,
          arm64_a64_ldpi,
          arm64_a64_ldpi_simd,
          arm64_a64_ldpsw,
          arm64_a64_ldpswi,
          arm64_a64_ldr,
          arm64_a64_ldr_lit,
          arm64_a64_ldr_lit_simd,
          arm64_a64_ldr_reg,
          arm64_a64_ldr_reg_simd,
          arm64_a64_ldrb,
          arm64_a64_ldrb_reg,
          arm64_a64_ldrbi,
          arm64_a64_ldrh,
          arm64_a64_ldrh_reg,
          arm64_a64_ldrhi,
          arm64_a64_ldri,
          arm64_a64_ldrsw,
          arm64_a64_ldrsw_lit,
          arm64_a64_ldrswi,
          arm64_a64_ldtr,
          arm64_a64_ldtrb,
          arm64_a64_ldtrh,
          arm64_a64_ldtrsw,
          arm64_a64_ldur,
          arm64_a64_ldurb,
          arm64_a64_ldurh,
          arm64_a64_ldursw,
          arm64_a64_ldxp,
          arm64_a64_ldxr,
          arm64_a64_ldxrb,
          arm64_a64_ldxrh,
          arm64_a64_lslv,
          arm64_a64_lsrv,
          arm64_a64_madd,
          arm64_a64_mla_vector,
          arm64_a64_mov,
          arm64_a64_movi,
          arm64_a64_movk,
          arm64_a64_movn,
          arm64_a64_movz,
          arm64_a64_mrs,
          arm64_a64_msr_imm,
          arm64_a64_msr_reg,
          arm64_a64_msr_sctlr,
          arm64_a64_msub,
          arm64_a64_mul_idx_vector,
          arm64_a64_mul_vector,
          arm64_a64_mvni,
          arm64_a64_neg_simd,
          arm64_a64_not_simd,
          arm64_a64_orn_vector,
          arm64_a64_orr_vector,
          arm64_a64_orri,
          arm64_a64_orrsr,
          arm64_a64_pmull,
          arm64_a64_prfm,
          arm64_a64_prfm_lit,
          arm64_a64_prfm_reg,
          arm64_a64_prfmi,
          arm64_a64_prfum,
          arm64_a64_rbit,
          arm64_a64_ret,
          arm64_a64_rev,
          arm64_a64_rev16,
          arm64_a64_rev32,
          arm64_a64_rev32_simd,
          arm64_a64_rev64_simd,
          arm64_a64_rorv,
          arm64_a64_saddl,
          arm64_a64_saddlv,
          arm64_a64_saddw,
          arm64_a64_sbc,
          arm64_a64_sbfm,
          arm64_a64_scvtf,
          arm64_a64_scvtf_simd,
          arm64_a64_sdiv,
          arm64_a64_shl_simd,
          arm64_a64_shll,
          arm64_a64_smaddl,
          arm64_a64_smax,
          arm64_a64_smaxv,
          arm64_a64_smin,
          arm64_a64_sminv,
          arm64_a64_smov,
          arm64_a64_smsubl,
          arm64_a64_smulh,
          arm64_a64_smull,
          arm64_a64_sshl,
          arm64_a64_sshll,
          arm64_a64_sshr,
          arm64_a64_ssubl,
          arm64_a64_ssubw,
          arm64_a64_st1,
          arm64_a64_st1pi,
          arm64_a64_st1s,
          arm64_a64_st1spi,
          arm64_a64_st2,
          arm64_a64_st2pi,
          arm64_a64_st3,
          arm64_a64_st3pi,
          arm64_a64_st4,
          arm64_a64_st4pi,
          arm64_a64_stlr,
          arm64_a64_stlrb,
          arm64_a64_stlrh,
          arm64_a64_stlxp,
          arm64_a64_stlxr,
          arm64_a64_stlxrb,
          arm64_a64_stlxrh,
          arm64_a64_stnp,
          arm64_a64_stp,
          arm64_a64_stp_simd,
          arm64_a64_stpi,
          arm64_a64_stpi_simd,
          arm64_a64_str,
          arm64_a64_str_reg,
          arm64_a64_str_reg_simd,
          arm64_a64_strb,
          arm64_a64_strb_reg,
          arm64_a64_strbi,
          arm64_a64_strh,
          arm64_a64_strh_reg,
          arm64_a64_strhi,
          arm64_a64_stri,
          arm64_a64_sttr,
          arm64_a64_sttrb,
          arm64_a64_sttrh,
          arm64_a64_stur,
          arm64_a64_sturb,
          arm64_a64_sturh,
          arm64_a64_stxp,
          arm64_a64_stxr,
          arm64_a64_stxrb,
          arm64_a64_stxrh,
          arm64_a64_sub_ereg,
          arm64_a64_sub_sreg,
          arm64_a64_sub_vector,
          arm64_a64_subi,
          arm64_a64_sys,
          arm64_a64_tbl,
          arm64_a64_tbx,
          arm64_a64_tbz,
          arm64_a64_uadalp,
          arm64_a64_uaddl,
          arm64_a64_uaddlp,
          arm64_a64_uaddlv,
          arm64_a64_uaddw,
          arm64_a64_ubfm,
          arm64_a64_ucvtf,
          arm64_a64_ucvtf_simd,
          arm64_a64_udiv,
          arm64_a64_umaddl,
          arm64_a64_umaxv,
          arm64_a64_uminv,
          arm64_a64_umov,
          arm64_a64_umsubl,
          arm64_a64_umulh,
          arm64_a64_umull,
          arm64_a64_ushl,
          arm64_a64_ushll,
          arm64_a64_ushr,
          arm64_a64_usubl,
          arm64_a64_usubw,
          arm64_a64_uzp1,
          arm64_a64_uzp2,
          arm64_a64_vldr,
          arm64_a64_vldur,
          arm64_a64_vstr,
          arm64_a64_vstur,
          arm64_a64_xtn,
          arm64_unknown = -1
        }
        ;
        arm64_isa_modes isa_mode;
        arm64_opcodes opcode;
        uint32_t ir;
        bool decode(uint32_t isa_mode, uint64_t insn_pc, const uint8_t *ptr) override;
        JumpInfo get_jump_info() override;
        private:
        bool decode_a64(uint32_t ir);
      }
      ;
      class arm64_decode_a64 : public arm64_decode
      {
        public:
        uint32_t immu32;
        int32_t imms32;
        uint64_t immu64;
        int64_t imms64;
        uint8_t shift_amount;
        int64_t label;
        uint8_t bit_pos;
        uint8_t ext_type;
        uint8_t arrangement;
        uint8_t width;
        uint8_t size;
        uint8_t regcnt;
        uint8_t elemcnt;
        uint8_t elemsize;
        uint8_t ta;
        uint8_t tb;
        uint8_t eindex;
        uint8_t eindex2;
        uint8_t rmr;
      }
      ;
      class arm64_decode_a64_ADD_SUB_CARRY : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op;
        uint8_t S;
        uint8_t rm;
        uint8_t opcode2;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_ADD_SUB_CARRY) <= 128, "Decode class for format ADD_SUB_CARRY is too big!");
      class arm64_decode_a64_ADD_SUB_EREG : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op;
        uint8_t S;
        uint8_t opt;
        uint8_t rm;
        uint8_t option;
        uint8_t imm3;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            shift_amount = imm3;
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_ADD_SUB_EREG) <= 128, "Decode class for format ADD_SUB_EREG is too big!");
      class arm64_decode_a64_ADD_SUB_IMM : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op;
        uint8_t S;
        uint8_t shift;
        uint16_t imm12;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_ADD_SUB_IMM) <= 128, "Decode class for format ADD_SUB_IMM is too big!");
      class arm64_decode_a64_ADD_SUB_SREG : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op;
        uint8_t S;
        uint8_t shift;
        uint8_t rm;
        uint8_t imm6;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_ADD_SUB_SREG) <= 128, "Decode class for format ADD_SUB_SREG is too big!");
      class arm64_decode_a64_BITFIELD : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t opc;
        uint8_t N;
        uint8_t immr;
        uint8_t imms;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_BITFIELD) <= 128, "Decode class for format BITFIELD is too big!");
      class arm64_decode_a64_CMP_B_IMM : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op;
        uint32_t imm19;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            imms64 = ((int64_t)imm19 << (64 - 19)) >> (64 - 21);
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_CMP_B_IMM) <= 128, "Decode class for format CMP_B_IMM is too big!");
      class arm64_decode_a64_COND_B_IMM : public arm64_decode_a64
      {
        public:
        uint8_t o1;
        uint32_t imm19;
        uint8_t o0;
        uint8_t cond;
        inline void decode_behaviour()
        {
          {
            imms64 = ((int64_t)imm19 << (64 - 19)) >> (64 - 21);
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_COND_B_IMM) <= 128, "Decode class for format COND_B_IMM is too big!");
      class arm64_decode_a64_COND_CMP_IMM : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op;
        uint8_t S;
        uint8_t imm5;
        uint8_t cond;
        uint8_t o2;
        uint8_t rn;
        uint8_t o3;
        uint8_t nzcv;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_COND_CMP_IMM) <= 128, "Decode class for format COND_CMP_IMM is too big!");
      class arm64_decode_a64_COND_CMP_REG : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op;
        uint8_t S;
        uint8_t rm;
        uint8_t cond;
        uint8_t o2;
        uint8_t rn;
        uint8_t o3;
        uint8_t nzcv;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_COND_CMP_REG) <= 128, "Decode class for format COND_CMP_REG is too big!");
      class arm64_decode_a64_COND_SEL : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op;
        uint8_t S;
        uint8_t rm;
        uint8_t cond;
        uint8_t op2;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_COND_SEL) <= 128, "Decode class for format COND_SEL is too big!");
      class arm64_decode_a64_CVT_FP_FXP : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t S;
        uint8_t type;
        uint8_t rmode;
        uint8_t opcode;
        uint8_t scale;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            immu64 = 64 - scale;
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_CVT_FP_FXP) <= 128, "Decode class for format CVT_FP_FXP is too big!");
      class arm64_decode_a64_CVT_FP_I : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t S;
        uint8_t type;
        uint8_t rmode;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_CVT_FP_I) <= 128, "Decode class for format CVT_FP_I is too big!");
      class arm64_decode_a64_DP_1S : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t S;
        uint8_t opcode2;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_DP_1S) <= 128, "Decode class for format DP_1S is too big!");
      class arm64_decode_a64_DP_2S : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t S;
        uint8_t rm;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_DP_2S) <= 128, "Decode class for format DP_2S is too big!");
      class arm64_decode_a64_DP_3S : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op54;
        uint8_t op31;
        uint8_t rm;
        uint8_t o0;
        uint8_t ra;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_DP_3S) <= 128, "Decode class for format DP_3S is too big!");
      class arm64_decode_a64_EXTRACT : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t op21;
        uint8_t N;
        uint8_t o0;
        uint8_t rm;
        uint8_t imms;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_EXTRACT) <= 128, "Decode class for format EXTRACT is too big!");
      class arm64_decode_a64_EX_GEN : public arm64_decode_a64
      {
        public:
        uint8_t opc;
        uint16_t imm16;
        uint8_t op2;
        uint8_t ll;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_EX_GEN) <= 128, "Decode class for format EX_GEN is too big!");
      class arm64_decode_a64_FP_CCMP : public arm64_decode_a64
      {
        public:
        uint8_t M;
        uint8_t S;
        uint8_t type;
        uint8_t rm;
        uint8_t cond;
        uint8_t rn;
        uint8_t op;
        uint8_t nzcv;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_FP_CCMP) <= 128, "Decode class for format FP_CCMP is too big!");
      class arm64_decode_a64_FP_CMP : public arm64_decode_a64
      {
        public:
        uint8_t M;
        uint8_t S;
        uint8_t type;
        uint8_t rm;
        uint8_t op;
        uint8_t rn;
        uint8_t opcode2;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_FP_CMP) <= 128, "Decode class for format FP_CMP is too big!");
      class arm64_decode_a64_FP_CSEL : public arm64_decode_a64
      {
        public:
        uint8_t M;
        uint8_t S;
        uint8_t type;
        uint8_t rm;
        uint8_t cond;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_FP_CSEL) <= 128, "Decode class for format FP_CSEL is too big!");
      class arm64_decode_a64_FP_DP_1 : public arm64_decode_a64
      {
        public:
        uint8_t M;
        uint8_t S;
        uint8_t type;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_FP_DP_1) <= 128, "Decode class for format FP_DP_1 is too big!");
      class arm64_decode_a64_FP_DP_2 : public arm64_decode_a64
      {
        public:
        uint8_t M;
        uint8_t S;
        uint8_t type;
        uint8_t rm;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_FP_DP_2) <= 128, "Decode class for format FP_DP_2 is too big!");
      class arm64_decode_a64_FP_DP_3 : public arm64_decode_a64
      {
        public:
        uint8_t M;
        uint8_t S;
        uint8_t type;
        uint8_t o1;
        uint8_t rm;
        uint8_t o0;
        uint8_t ra;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_FP_DP_3) <= 128, "Decode class for format FP_DP_3 is too big!");
      class arm64_decode_a64_FP_IMM : public arm64_decode_a64
      {
        public:
        uint8_t M;
        uint8_t S;
        uint8_t type;
        uint8_t imm8;
        uint8_t imm5;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            immu64 = 0;
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_FP_IMM) <= 128, "Decode class for format FP_IMM is too big!");
      class arm64_decode_a64_LOAD_REG_LIT : public arm64_decode_a64
      {
        public:
        uint8_t opc;
        uint8_t V;
        uint32_t imm19;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            label = __SEXT64(imm19 << 2, 21);
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LOAD_REG_LIT) <= 128, "Decode class for format LOAD_REG_LIT is too big!");
      class arm64_decode_a64_LOGICAL_IMM : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t opc;
        uint8_t N;
        uint8_t immr;
        uint8_t imms;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            int len = 31 - __CLZ32((N << 6) | (~imms & 0x3f));
            unsigned int e = 1 << len;
            unsigned int levels = e - 1;
            unsigned int s = imms & levels;
            unsigned int r = immr & levels;
            uint64_t mask = __ONES(s + 1);
            if (r) 
            {
              mask = (mask >> r) | (mask << (e - r));
              mask &= __ONES(e);
            }
            if (sf) 
            {
              immu64 = __REPLICATE(mask, e);
            }
            else 
            {
              immu32 = (uint32_t)__REPLICATE(mask, e);
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LOGICAL_IMM) <= 128, "Decode class for format LOGICAL_IMM is too big!");
      class arm64_decode_a64_LOGICAL_SR : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t opc;
        uint8_t shift;
        uint8_t N;
        uint8_t rm;
        uint8_t imm6;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LOGICAL_SR) <= 128, "Decode class for format LOGICAL_SR is too big!");
      class arm64_decode_a64_LS_EX : public arm64_decode_a64
      {
        public:
        uint8_t size;
        uint8_t o2;
        uint8_t L;
        uint8_t o1;
        uint8_t rs;
        uint8_t o0;
        uint8_t rt2;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LS_EX) <= 128, "Decode class for format LS_EX is too big!");
      class arm64_decode_a64_LS_NO_ALLOC : public arm64_decode_a64
      {
        public:
        uint8_t opc;
        uint8_t V;
        uint8_t L;
        uint8_t imm7;
        uint8_t rt2;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            if (opc == 0) 
            {
              imms64 = __SEXT64(imm7, 7) << 2;
            }
            else if (opc == 2) 
            {
              imms64 = __SEXT64(imm7, 7) << 3;
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LS_NO_ALLOC) <= 128, "Decode class for format LS_NO_ALLOC is too big!");
      class arm64_decode_a64_LS_REG_IMM_POST : public arm64_decode_a64
      {
        public:
        uint8_t size;
        uint8_t V;
        uint8_t X;
        uint8_t L;
        uint16_t imm9;
        uint8_t P;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            imms64 = __SEXT64(imm9, 9);
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LS_REG_IMM_POST) <= 128, "Decode class for format LS_REG_IMM_POST is too big!");
      class arm64_decode_a64_LS_REG_PAIR_IDX : public arm64_decode_a64
      {
        public:
        uint8_t opc;
        uint8_t V;
        uint8_t P;
        uint8_t L;
        uint8_t imm7;
        uint8_t rt2;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            int scale = 2 + ((V == 1) ? (opc) : (opc >> 1));
            immu64 = (((int64_t)imm7 << (64 - 7)) >> (64 - 7)) << scale;
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LS_REG_PAIR_IDX) <= 128, "Decode class for format LS_REG_PAIR_IDX is too big!");
      class arm64_decode_a64_LS_REG_PAIR_OFF : public arm64_decode_a64
      {
        public:
        uint8_t opc;
        uint8_t V;
        uint8_t L;
        uint8_t imm7;
        uint8_t rt2;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            int scale = 2 + ((V == 1) ? (opc) : (opc >> 1));
            imms64 = __SEXT64(imm7, 7) << scale;
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LS_REG_PAIR_OFF) <= 128, "Decode class for format LS_REG_PAIR_OFF is too big!");
      class arm64_decode_a64_LS_REG_REG_OFF : public arm64_decode_a64
      {
        public:
        uint8_t size;
        uint8_t V;
        uint8_t X;
        uint8_t L;
        uint8_t rm;
        uint8_t option21;
        uint8_t option0;
        uint8_t S;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            ext_type = option0 | (option21 << 1);
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LS_REG_REG_OFF) <= 128, "Decode class for format LS_REG_REG_OFF is too big!");
      class arm64_decode_a64_LS_REG_UIMM : public arm64_decode_a64
      {
        public:
        uint8_t size;
        uint8_t V;
        uint8_t opc;
        uint16_t imm12;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            if (size == 0 && (opc == 2 || opc == 3) && V == 1) 
            {
              immu64 = ((uint64_t)imm12) << 4;
            }
            else 
            {
              immu64 = ((uint64_t)imm12) << size;
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LS_REG_UIMM) <= 128, "Decode class for format LS_REG_UIMM is too big!");
      class arm64_decode_a64_LS_REG_UNPRIV : public arm64_decode_a64
      {
        public:
        uint8_t size;
        uint8_t V;
        uint8_t opc;
        uint16_t imm9;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LS_REG_UNPRIV) <= 128, "Decode class for format LS_REG_UNPRIV is too big!");
      class arm64_decode_a64_LS_REG_USIMM : public arm64_decode_a64
      {
        public:
        uint8_t size;
        uint8_t V;
        uint8_t opc;
        uint16_t imm9;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            imms64 = __SEXT64(imm9, 9);
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_LS_REG_USIMM) <= 128, "Decode class for format LS_REG_USIMM is too big!");
      class arm64_decode_a64_MOVE_WIDE_IMM : public arm64_decode_a64
      {
        public:
        uint8_t sf;
        uint8_t opc;
        uint8_t hw;
        uint16_t imm16;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            shift_amount = hw << 4;
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_MOVE_WIDE_IMM) <= 128, "Decode class for format MOVE_WIDE_IMM is too big!");
      class arm64_decode_a64_PC_REL : public arm64_decode_a64
      {
        public:
        uint8_t op;
        uint8_t immlo;
        uint32_t immhi;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            uint64_t imm = ((uint64_t)immhi << 2) | (uint64_t)(immlo & 0x3);
            if (op == 1) 
            {
              imms64 = __SEXT64(imm << 12, 33);
            }
            else 
            {
              imms64 = __SEXT64(imm, 21);
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_PC_REL) <= 128, "Decode class for format PC_REL is too big!");
      class arm64_decode_a64_SIMD_ACROSS_LANES : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t U;
        uint8_t size;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            if (size == 0 && Q == 0) 
            {
              arrangement = 0;
              // 8B
            }
            else if (size == 0 && Q == 1) 
            {
              arrangement = 1;
              // 16B
            }
            else if (size == 1 && Q == 0) 
            {
              arrangement = 2;
              // 4H
            }
            else if (size == 1 && Q == 1) 
            {
              arrangement = 3;
              // 8H
            }
            else if (size == 2 && Q == 0) 
            {
              arrangement = 4;
              // 2S
            }
            else if (size == 2 && Q == 1) 
            {
              arrangement = 5;
              // 4S
            }
            else if (size == 3 && Q == 1) 
            {
              arrangement = 6;
              // 2D
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_ACROSS_LANES) <= 128, "Decode class for format SIMD_ACROSS_LANES is too big!");
      class arm64_decode_a64_SIMD_COPY : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t op;
        uint8_t imm5;
        uint8_t imm4;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            if (((imm5 & 1) == 1) && Q == 0) 
            {
              arrangement = 0;
              // 8B
            }
            else if (((imm5 & 1) == 1) && Q == 1) 
            {
              arrangement = 1;
              // 16B
            }
            else if (((imm5 & 3) == 2) && Q == 0) 
            {
              arrangement = 2;
              // 4H
            }
            else if (((imm5 & 3) == 2) && Q == 1) 
            {
              arrangement = 3;
              // 8H
            }
            else if (((imm5 & 7) == 4) && Q == 0) 
            {
              arrangement = 4;
              // 2S
            }
            else if (((imm5 & 7) == 4) && Q == 1) 
            {
              arrangement = 5;
              // 4S
            }
            else if (((imm5 & 15) == 8) && Q == 1) 
            {
              arrangement = 6;
              // 2D
            }
            if ((imm5 & 1) == 1) 
            {
              width = 32;
              size = 0;
            }
            else if ((imm5 & 3) == 2) 
            {
              width = 32;
              size = 1;
            }
            else if ((imm5 & 7) == 4) 
            {
              width = 32;
              size = 2;
            }
            else if ((imm5 & 15) == 8) 
            {
              width = 64;
              size = 3;
            }
            eindex = imm5 >> (size + 1);
            eindex2 = imm4 >> (size);
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_COPY) <= 128, "Decode class for format SIMD_COPY is too big!");
      class arm64_decode_a64_SIMD_EXTRACT : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t op2;
        uint8_t rm;
        uint8_t imm4;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_EXTRACT) <= 128, "Decode class for format SIMD_EXTRACT is too big!");
      class arm64_decode_a64_SIMD_LS_MULT : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t L;
        uint8_t opcode;
        uint8_t size;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            if (size == 0 && Q == 0) 
            {
              arrangement = 0;
              // 8B
              elemcnt = 8;
              elemsize = 1;
            }
            else if (size == 0 && Q == 1) 
            {
              arrangement = 1;
              // 16B
              elemcnt = 16;
              elemsize = 1;
            }
            else if (size == 1 && Q == 0) 
            {
              arrangement = 2;
              // 4H
              elemcnt = 4;
              elemsize = 2;
            }
            else if (size == 1 && Q == 1) 
            {
              arrangement = 3;
              // 8H
              elemcnt = 8;
              elemsize = 2;
            }
            else if (size == 2 && Q == 0) 
            {
              arrangement = 4;
              // 2S
              elemcnt = 2;
              elemsize = 4;
            }
            else if (size == 2 && Q == 1) 
            {
              arrangement = 5;
              // 4S
              elemcnt = 4;
              elemsize = 4;
            }
            else if (size == 3 && Q == 1) 
            {
              arrangement = 6;
              // 2D
              elemcnt = 2;
              elemsize = 8;
            }
            if (opcode == 2 || opcode == 0) 
            {
              regcnt = 4;
            }
            else if (opcode == 6 || opcode == 4) 
            {
              regcnt = 3;
            }
            else if (opcode == 7) 
            {
              regcnt = 1;
            }
            else if (opcode == 10 || opcode == 8) 
            {
              regcnt = 2;
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_LS_MULT) <= 128, "Decode class for format SIMD_LS_MULT is too big!");
      class arm64_decode_a64_SIMD_LS_MULT_PI : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t L;
        uint8_t rm;
        uint8_t opcode;
        uint8_t size;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            if (size == 0 && Q == 0) 
            {
              arrangement = 0;
              // 8B
              elemcnt = 8;
              elemsize = 1;
            }
            else if (size == 0 && Q == 1) 
            {
              arrangement = 1;
              // 16B
              elemcnt = 16;
              elemsize = 1;
            }
            else if (size == 1 && Q == 0) 
            {
              arrangement = 2;
              // 4H
              elemcnt = 4;
              elemsize = 2;
            }
            else if (size == 1 && Q == 1) 
            {
              arrangement = 3;
              // 8H
              elemcnt = 8;
              elemsize = 2;
            }
            else if (size == 2 && Q == 0) 
            {
              arrangement = 4;
              // 2S
              elemcnt = 2;
              elemsize = 4;
            }
            else if (size == 2 && Q == 1) 
            {
              arrangement = 5;
              // 4S
              elemcnt = 4;
              elemsize = 4;
            }
            else if (size == 3 && Q == 1) 
            {
              arrangement = 6;
              // 2D
              elemcnt = 2;
              elemsize = 8;
            }
            if (opcode == 2) 
            {
              regcnt = 4;
            }
            else if (opcode == 6) 
            {
              regcnt = 3;
            }
            else if (opcode == 7) 
            {
              regcnt = 1;
            }
            else if (opcode == 10) 
            {
              regcnt = 2;
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_LS_MULT_PI) <= 128, "Decode class for format SIMD_LS_MULT_PI is too big!");
      class arm64_decode_a64_SIMD_LS_SINGLE : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t L;
        uint8_t R;
        uint8_t opcode;
        uint8_t S;
        uint8_t size;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            if (opcode == 0) 
            {
              eindex = Q << 3 | S << 2 | size;
            }
            else if (opcode == 2) 
            {
              eindex = Q << 2 | S << 1 | (size >> 1);
            }
            else if (opcode == 4) 
            {
              if (size == 0) 
              {
                eindex = Q << 1 | S;
              }
              else 
              {
                eindex = Q;
              }
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_LS_SINGLE) <= 128, "Decode class for format SIMD_LS_SINGLE is too big!");
      class arm64_decode_a64_SIMD_LS_SINGLE_PI : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t L;
        uint8_t R;
        uint8_t rm;
        uint8_t opcode;
        uint8_t S;
        uint8_t size;
        uint8_t rn;
        uint8_t rt;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_LS_SINGLE_PI) <= 128, "Decode class for format SIMD_LS_SINGLE_PI is too big!");
      class arm64_decode_a64_SIMD_MOD_IMM : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t op;
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t cmode;
        uint8_t o2;
        uint8_t d;
        uint8_t e;
        uint8_t f;
        uint8_t g;
        uint8_t h;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            uint64_t tmp = 0;
            tmp |= a << 7;
            tmp |= b << 6;
            tmp |= c << 5;
            tmp |= d << 4;
            tmp |= e << 3;
            tmp |= f << 2;
            tmp |= g << 1;
            tmp |= h << 0;
            switch ((cmode >> 1) & 7) 
            {
            case 0:
              immu64 = tmp << 32 | tmp;
              break;
            case 1:
              immu64 = tmp << 40 | tmp << 8;
              break;
            case 2:
              immu64 = tmp << 48 | tmp << 16;
              break;
            case 3:
              immu64 = tmp << 56 | tmp << 24;
              break;
            case 4:
              immu64 = tmp << 48 | tmp << 32 | tmp << 16 | tmp;
              break;
            case 5:
              immu64 = tmp << 56 | tmp << 40 | tmp << 24 | tmp << 8;
              break;
            case 6:
              if ((cmode & 1) == 0) 
              {
                immu64 = 0x000000ff000000ff;
                immu64 |= (tmp << 40);
                immu64 |= (tmp << 8);
              }
              else 
              {
                immu64 = 0x0000ffff0000ffff;
                immu64 |= (tmp << 48);
                immu64 |= (tmp << 16);
              }
              break;
            case 7:
              if (((cmode & 1) == 0) && op == 0) 
              {
                immu64 = tmp << 56 | tmp << 48 | tmp << 40 | tmp << 32 | tmp << 24 | tmp << 16 | tmp << 8 | tmp;
              }
              else if (((cmode & 1) == 0) && op == 1) 
              {
                immu64 = 0;
                immu64 |= (tmp & 0x80) ? 0xff00000000000000 : 0;
                immu64 |= (tmp & 0x40) ? 0x00ff000000000000 : 0;
                immu64 |= (tmp & 0x20) ? 0x0000ff0000000000 : 0;
                immu64 |= (tmp & 0x10) ? 0x000000ff00000000 : 0;
                immu64 |= (tmp & 0x08) ? 0x00000000ff000000 : 0;
                immu64 |= (tmp & 0x04) ? 0x0000000000ff0000 : 0;
                immu64 |= (tmp & 0x02) ? 0x000000000000ff00 : 0;
                immu64 |= (tmp & 0x01) ? 0x00000000000000ff : 0;
              }
              else if (((cmode & 1) == 1) && op == 0) 
              {
                uint32_t tmp32 = a << 31;
                tmp32 |= (!b) << 30;
                tmp32 |= b ? 0x3e000000 : 0;
                tmp32 |= (tmp & 0x3f) << 19;
                immu64 = ((uint64_t)tmp32 << 32) | tmp32;
              }
              else if (((cmode & 1) == 1) && op == 1) 
              {
                uint32_t tmp32 = a << 31;
                tmp32 |= (!b) << 30;
                tmp32 |= b ? 0x3fc00000 : 0;
                tmp32 |= (tmp & 0x3f) << 21;
                immu64 = ((uint64_t)tmp32 << 32);
              }
              break;
            /*case 15:
              if (op == 0) 
              {
                uint32_t tmp32;
                tmp32 = (tmp & 0x80) << 5;
                tmp32 |= ((~tmp) & 0x40) << 5;
                if (tmp & 0x40) 
                {
                  tmp32 |= 0x1f << 6;
                }
                tmp32 |= (tmp & 0x3f);
                tmp32 <<= 19;
                immu64 = (uint64_t)tmp32 | ((uint64_t)tmp32 << 32);
              }
              else if (op == 1) 
              {
                immu64 = (tmp & 0x80) << 8;
                immu64 |= ((~tmp) & 0x40) << 8;
                if (tmp & 0x40) 
                {
                  immu64 |= 0xff << 6;
                }
                immu64 |= (tmp & 0x3f);
                immu64 <<= 48;
              }
              break;
              */
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_MOD_IMM) <= 128, "Decode class for format SIMD_MOD_IMM is too big!");
      class arm64_decode_a64_SIMD_PERMUTE : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t size;
        uint8_t rm;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            if (size == 0 && Q == 0) 
            {
              arrangement = 0;
              // 8B
              elemcnt = 8;
              elemsize = 1;
            }
            else if (size == 0 && Q == 1) 
            {
              arrangement = 1;
              // 16B
              elemcnt = 16;
              elemsize = 1;
            }
            else if (size == 1 && Q == 0) 
            {
              arrangement = 2;
              // 4H
              elemcnt = 4;
              elemsize = 2;
            }
            else if (size == 1 && Q == 1) 
            {
              arrangement = 3;
              // 8H
              elemcnt = 8;
              elemsize = 2;
            }
            else if (size == 2 && Q == 0) 
            {
              arrangement = 4;
              // 2S
              elemcnt = 2;
              elemsize = 4;
            }
            else if (size == 2 && Q == 1) 
            {
              arrangement = 5;
              // 4S
              elemcnt = 4;
              elemsize = 4;
            }
            else if (size == 3 && Q == 1) 
            {
              arrangement = 6;
              // 2D
              elemcnt = 2;
              elemsize = 8;
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_PERMUTE) <= 128, "Decode class for format SIMD_PERMUTE is too big!");
      class arm64_decode_a64_SIMD_SCALAR_PW : public arm64_decode_a64
      {
        public:
        uint8_t U;
        uint8_t size;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_SCALAR_PW) <= 128, "Decode class for format SIMD_SCALAR_PW is too big!");
      class arm64_decode_a64_SIMD_SHIFT_IMM : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t U;
        uint8_t SCALAR;
        uint8_t immh;
        uint8_t immb;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            if (SCALAR) 
            {
              shift_amount = ((immh << 3) | immb) - 64;
            }
            else 
            {
              if (immh == 1 && Q == 0) 
              {
                // 8B
                arrangement = 0;
                shift_amount = ((immh << 3) | immb) - 8;
              }
              else if (immh == 1 && Q == 1) 
              {
                // 16B
                arrangement = 1;
                shift_amount = ((immh << 3) | immb) - 8;
              }
              else if ((immh & 0xe) == 2 && Q == 0) 
              {
                // 4H
                arrangement = 2;
                shift_amount = ((immh << 3) | immb) - 16;
              }
              else if ((immh & 0xe) == 2 && Q == 1) 
              {
                // 8H
                arrangement = 3;
                shift_amount = ((immh << 3) | immb) - 16;
              }
              else if ((immh & 0xc) == 4 && Q == 0) 
              {
                // 2S
                arrangement = 4;
                shift_amount = ((immh << 3) | immb) - 32;
              }
              else if ((immh & 0xc) == 4 && Q == 1) 
              {
                // 4S
                arrangement = 5;
                shift_amount = ((immh << 3) | immb) - 32;
              }
              else if ((immh & 0x8) == 8 && Q == 1) 
              {
                // 2D
                arrangement = 6;
                shift_amount = ((immh << 3) | immb) - 64;
              }
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_SHIFT_IMM) <= 128, "Decode class for format SIMD_SHIFT_IMM is too big!");
      class arm64_decode_a64_SIMD_TABLE_LOOKUP : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t op2;
        uint8_t rm;
        uint8_t len;
        uint8_t op;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_TABLE_LOOKUP) <= 128, "Decode class for format SIMD_TABLE_LOOKUP is too big!");
      class arm64_decode_a64_SIMD_THREE_DIFF : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t U;
        uint8_t SCALAR;
        uint8_t size;
        uint8_t rm;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            if (size == 0) 
            {
              ta = 0;
              // 8H
            }
            else if (size == 1) 
            {
              ta = 1;
              // 4S
            }
            else if (size == 2) 
            {
              ta = 2;
              // 2D
            }
            else if (size == 3) 
            {
              ta = 3;
              // 1Q
            }
            if (size == 0 && Q == 0) 
            {
              tb = 0;
              // 8B
            }
            else if (size == 0 && Q == 1) 
            {
              tb = 1;
              // 16B
            }
            else if (size == 1 && Q == 0) 
            {
              tb = 2;
              // 4H
            }
            else if (size == 1 && Q == 1) 
            {
              tb = 3;
              // 8H
            }
            else if (size == 2 && Q == 0) 
            {
              tb = 4;
              // 2S
            }
            else if (size == 2 && Q == 1) 
            {
              tb = 5;
              // 4S
            }
            else if (size == 3 && Q == 0) 
            {
              tb = 6;
              // 1D
            }
            else if (size == 3 && Q == 1) 
            {
              tb = 7;
              // 2D
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_THREE_DIFF) <= 128, "Decode class for format SIMD_THREE_DIFF is too big!");
      class arm64_decode_a64_SIMD_THREE_SAME : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t U;
        uint8_t SCALAR;
        uint8_t size;
        uint8_t rm;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            if (size == 0 && Q == 0) 
            {
              arrangement = 0;
              // 8B
            }
            else if (size == 0 && Q == 1) 
            {
              arrangement = 1;
              // 16B
            }
            else if (size == 1 && Q == 0) 
            {
              arrangement = 2;
              // 4H
            }
            else if (size == 1 && Q == 1) 
            {
              arrangement = 3;
              // 8H
            }
            else if (size == 2 && Q == 0) 
            {
              arrangement = 4;
              // 2S
            }
            else if (size == 2 && Q == 1) 
            {
              arrangement = 5;
              // 4S
            }
            else if (size == 3 && Q == 1) 
            {
              arrangement = 6;
              // 2D
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_THREE_SAME) <= 128, "Decode class for format SIMD_THREE_SAME is too big!");
      class arm64_decode_a64_SIMD_TWO_REG_MISC : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t U;
        uint8_t SCALAR;
        uint8_t size;
        uint8_t opcode;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            if (size == 0 && Q == 0) 
            {
              arrangement = 0;
              // 8B
            }
            else if (size == 0 && Q == 1) 
            {
              arrangement = 1;
              // 16B
            }
            else if (size == 1 && Q == 0) 
            {
              arrangement = 2;
              // 4H
            }
            else if (size == 1 && Q == 1) 
            {
              arrangement = 3;
              // 8H
            }
            else if (size == 2 && Q == 0) 
            {
              arrangement = 4;
              // 2S
            }
            else if (size == 2 && Q == 1) 
            {
              arrangement = 5;
              // 4S
            }
            else if (size == 3 && Q == 1) 
            {
              arrangement = 6;
              // 2D
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_TWO_REG_MISC) <= 128, "Decode class for format SIMD_TWO_REG_MISC is too big!");
      class arm64_decode_a64_SIMD_VECTOR_IDX : public arm64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t U;
        uint8_t size;
        uint8_t L;
        uint8_t M;
        uint8_t rm;
        uint8_t opcode;
        uint8_t H;
        uint8_t rn;
        uint8_t rd;
        inline void decode_behaviour()
        {
          {
            if (size == 1) 
            {
              eindex = (H << 2) | (L << 1) | M;
              arrangement = Q ? 3 : 2;
              rmr = rm;
            }
            else if (size == 2) 
            {
              eindex = (H << 1) | L;
              arrangement = Q ? 5 : 4;
              rmr = rm + (M ? 16 : 0);
            }
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SIMD_VECTOR_IDX) <= 128, "Decode class for format SIMD_VECTOR_IDX is too big!");
      class arm64_decode_a64_SYSTEM : public arm64_decode_a64
      {
        public:
        uint8_t l;
        uint8_t op0;
        uint8_t op1;
        uint8_t crn;
        uint8_t crm;
        uint8_t op2;
        uint8_t rt;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_SYSTEM) <= 128, "Decode class for format SYSTEM is too big!");
      class arm64_decode_a64_TEST_B_IMM : public arm64_decode_a64
      {
        public:
        uint8_t b5;
        uint8_t op;
        uint8_t b40;
        uint16_t imm14;
        uint8_t rt;
        inline void decode_behaviour()
        {
          {
            imms64 = __SEXT64(imm14 << 2, 16);
            bit_pos = (b5 << 5) | b40;
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_TEST_B_IMM) <= 128, "Decode class for format TEST_B_IMM is too big!");
      class arm64_decode_a64_UB_IMM : public arm64_decode_a64
      {
        public:
        uint8_t op;
        uint32_t imm26;
        inline void decode_behaviour()
        {
          {
            imms64 = ((int64_t)imm26 << (64 - 26)) >> (64 - 28);
          }
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_UB_IMM) <= 128, "Decode class for format UB_IMM is too big!");
      class arm64_decode_a64_UB_REG : public arm64_decode_a64
      {
        public:
        uint8_t opc;
        uint8_t op2;
        uint8_t op3;
        uint8_t rn;
        uint8_t op4;
        inline void decode_behaviour()
        {
        }
      }
      ;
      static_assert(sizeof(arm64_decode_a64_UB_REG) <= 128, "Decode class for format UB_REG is too big!");
    }
  }
}
