#pragma once
#include <decode.h>
namespace captive 
{
  namespace arch 
  {
    namespace aarch64 
    {
      class aarch64_decode : public Decode
      {
        public:
        enum aarch64_isa_modes 
        {
          aarch64_a64 = 0,
        }
        ;
        enum aarch64_opcodes 
        {
          aarch64_a64_abs_simd,
          aarch64_a64_adc,
          aarch64_a64_add_ereg,
          aarch64_a64_add_sreg,
          aarch64_a64_add_vector,
          aarch64_a64_addi,
          aarch64_a64_addp_scalar,
          aarch64_a64_addp_vector,
          aarch64_a64_addv,
          aarch64_a64_adr,
          aarch64_a64_and_vector,
          aarch64_a64_andi,
          aarch64_a64_andsr,
          aarch64_a64_asrv,
          aarch64_a64_b,
          aarch64_a64_barrier,
          aarch64_a64_bcond,
          aarch64_a64_bfm,
          aarch64_a64_bic_vector,
          aarch64_a64_bici,
          aarch64_a64_bicsr,
          aarch64_a64_bif,
          aarch64_a64_bit,
          aarch64_a64_br,
          aarch64_a64_bsl,
          aarch64_a64_cbz,
          aarch64_a64_ccmni,
          aarch64_a64_ccmnr,
          aarch64_a64_ccmpi,
          aarch64_a64_ccmpr,
          aarch64_a64_clrex,
          aarch64_a64_cls,
          aarch64_a64_clz,
          aarch64_a64_cmeq_reg,
          aarch64_a64_cmeq_zero,
          aarch64_a64_cmge_zero,
          aarch64_a64_cmhi_reg,
          aarch64_a64_cmlt_zero,
          aarch64_a64_cmtst,
          aarch64_a64_cnt,
          aarch64_a64_crc32,
          aarch64_a64_crc32c,
          aarch64_a64_csel,
          aarch64_a64_csinc,
          aarch64_a64_csinv,
          aarch64_a64_csneg,
          aarch64_a64_drps,
          aarch64_a64_dup_elem,
          aarch64_a64_dup_gen,
          aarch64_a64_eor_vector,
          aarch64_a64_eori,
          aarch64_a64_eorsr,
          aarch64_a64_eret,
          aarch64_a64_exgen,
          aarch64_a64_ext,
          aarch64_a64_extr,
          aarch64_a64_fabd,
          aarch64_a64_fabs,
          aarch64_a64_fadd,
          aarch64_a64_fccmpe,
          aarch64_a64_fcmgt_zero,
          aarch64_a64_fcmpe,
          aarch64_a64_fcsel,
          aarch64_a64_fcvt,
          aarch64_a64_fcvtas_simd,
          aarch64_a64_fcvti,
          aarch64_a64_fcvtz,
          aarch64_a64_fcvtz_fxp,
          aarch64_a64_fcvtzs_simd,
          aarch64_a64_fdiv,
          aarch64_a64_fdiv_vector,
          aarch64_a64_fm,
          aarch64_a64_fmaxnmv,
          aarch64_a64_fmaxv,
          aarch64_a64_fminnmv,
          aarch64_a64_fminv,
          aarch64_a64_fmla_vector,
          aarch64_a64_fmov,
          aarch64_a64_fmov_gen,
          aarch64_a64_fmov_simd,
          aarch64_a64_fmovi,
          aarch64_a64_fmul,
          aarch64_a64_fmul_vector,
          aarch64_a64_fneg,
          aarch64_a64_fnm,
          aarch64_a64_fnmul,
          aarch64_a64_frintx,
          aarch64_a64_fsqrt,
          aarch64_a64_fsub,
          aarch64_a64_fsub_vector,
          aarch64_a64_hint,
          aarch64_a64_ins_elem,
          aarch64_a64_ins_gen,
          aarch64_a64_ld1,
          aarch64_a64_ld1pi,
          aarch64_a64_ld1r,
          aarch64_a64_ld1s,
          aarch64_a64_ld2,
          aarch64_a64_ld2pi,
          aarch64_a64_ld3,
          aarch64_a64_ld3pi,
          aarch64_a64_ld4,
          aarch64_a64_ld4pi,
          aarch64_a64_ldar,
          aarch64_a64_ldarb,
          aarch64_a64_ldarh,
          aarch64_a64_ldaxp,
          aarch64_a64_ldaxr,
          aarch64_a64_ldaxrb,
          aarch64_a64_ldaxrh,
          aarch64_a64_ldnp,
          aarch64_a64_ldp,
          aarch64_a64_ldp_simd,
          aarch64_a64_ldpi,
          aarch64_a64_ldpi_simd,
          aarch64_a64_ldpsw,
          aarch64_a64_ldpswi,
          aarch64_a64_ldr,
          aarch64_a64_ldr_lit,
          aarch64_a64_ldr_lit_simd,
          aarch64_a64_ldr_reg,
          aarch64_a64_ldr_reg_simd,
          aarch64_a64_ldrb,
          aarch64_a64_ldrb_reg,
          aarch64_a64_ldrbi,
          aarch64_a64_ldrh,
          aarch64_a64_ldrh_reg,
          aarch64_a64_ldrhi,
          aarch64_a64_ldri,
          aarch64_a64_ldrsw,
          aarch64_a64_ldrsw_lit,
          aarch64_a64_ldrswi,
          aarch64_a64_ldtr,
          aarch64_a64_ldtrb,
          aarch64_a64_ldtrh,
          aarch64_a64_ldtrsw,
          aarch64_a64_ldur,
          aarch64_a64_ldurb,
          aarch64_a64_ldurh,
          aarch64_a64_ldursw,
          aarch64_a64_ldxp,
          aarch64_a64_ldxr,
          aarch64_a64_ldxrb,
          aarch64_a64_ldxrh,
          aarch64_a64_lslv,
          aarch64_a64_lsrv,
          aarch64_a64_madd,
          aarch64_a64_mla_vector,
          aarch64_a64_mov,
          aarch64_a64_movi,
          aarch64_a64_movk,
          aarch64_a64_movn,
          aarch64_a64_movz,
          aarch64_a64_mrs,
          aarch64_a64_msr_imm,
          aarch64_a64_msr_reg,
          aarch64_a64_msr_sctlr,
          aarch64_a64_msub,
          aarch64_a64_mul_idx_vector,
          aarch64_a64_mul_vector,
          aarch64_a64_mvni,
          aarch64_a64_neg_simd,
          aarch64_a64_not_simd,
          aarch64_a64_orn_vector,
          aarch64_a64_orr_vector,
          aarch64_a64_orri,
          aarch64_a64_orrsr,
          aarch64_a64_pmull,
          aarch64_a64_prfm,
          aarch64_a64_prfm_lit,
          aarch64_a64_prfm_reg,
          aarch64_a64_prfmi,
          aarch64_a64_prfum,
          aarch64_a64_rbit,
          aarch64_a64_ret,
          aarch64_a64_rev,
          aarch64_a64_rev16,
          aarch64_a64_rev32,
          aarch64_a64_rev32_simd,
          aarch64_a64_rev64_simd,
          aarch64_a64_rorv,
          aarch64_a64_saddl,
          aarch64_a64_saddlv,
          aarch64_a64_saddw,
          aarch64_a64_sbc,
          aarch64_a64_sbfm,
          aarch64_a64_scvtf,
          aarch64_a64_scvtf_simd,
          aarch64_a64_sdiv,
          aarch64_a64_shl_simd,
          aarch64_a64_shll,
          aarch64_a64_smaddl,
          aarch64_a64_smax,
          aarch64_a64_smaxv,
          aarch64_a64_smin,
          aarch64_a64_sminv,
          aarch64_a64_smov,
          aarch64_a64_smsubl,
          aarch64_a64_smulh,
          aarch64_a64_smull,
          aarch64_a64_sshl,
          aarch64_a64_sshll,
          aarch64_a64_sshr,
          aarch64_a64_ssubl,
          aarch64_a64_ssubw,
          aarch64_a64_st1,
          aarch64_a64_st1pi,
          aarch64_a64_st1s,
          aarch64_a64_st1spi,
          aarch64_a64_st2,
          aarch64_a64_st2pi,
          aarch64_a64_st3,
          aarch64_a64_st3pi,
          aarch64_a64_st4,
          aarch64_a64_st4pi,
          aarch64_a64_stlr,
          aarch64_a64_stlrb,
          aarch64_a64_stlrh,
          aarch64_a64_stlxp,
          aarch64_a64_stlxr,
          aarch64_a64_stlxrb,
          aarch64_a64_stlxrh,
          aarch64_a64_stnp,
          aarch64_a64_stp,
          aarch64_a64_stp_simd,
          aarch64_a64_stpi,
          aarch64_a64_stpi_simd,
          aarch64_a64_str,
          aarch64_a64_str_reg,
          aarch64_a64_str_reg_simd,
          aarch64_a64_strb,
          aarch64_a64_strb_reg,
          aarch64_a64_strbi,
          aarch64_a64_strh,
          aarch64_a64_strh_reg,
          aarch64_a64_strhi,
          aarch64_a64_stri,
          aarch64_a64_sttr,
          aarch64_a64_sttrb,
          aarch64_a64_sttrh,
          aarch64_a64_stur,
          aarch64_a64_sturb,
          aarch64_a64_sturh,
          aarch64_a64_stxp,
          aarch64_a64_stxr,
          aarch64_a64_stxrb,
          aarch64_a64_stxrh,
          aarch64_a64_sub_ereg,
          aarch64_a64_sub_sreg,
          aarch64_a64_sub_vector,
          aarch64_a64_subi,
          aarch64_a64_sys,
          aarch64_a64_tbl,
          aarch64_a64_tbx,
          aarch64_a64_tbz,
          aarch64_a64_uadalp,
          aarch64_a64_uaddl,
          aarch64_a64_uaddlp,
          aarch64_a64_uaddlv,
          aarch64_a64_uaddw,
          aarch64_a64_ubfm,
          aarch64_a64_ucvtf,
          aarch64_a64_ucvtf_simd,
          aarch64_a64_udiv,
          aarch64_a64_umaddl,
          aarch64_a64_umaxv,
          aarch64_a64_uminv,
          aarch64_a64_umov,
          aarch64_a64_umsubl,
          aarch64_a64_umulh,
          aarch64_a64_umull,
          aarch64_a64_ushl,
          aarch64_a64_ushll,
          aarch64_a64_ushr,
          aarch64_a64_usubl,
          aarch64_a64_usubw,
          aarch64_a64_uzp1,
          aarch64_a64_uzp2,
          aarch64_a64_vldr,
          aarch64_a64_vldur,
          aarch64_a64_vstr,
          aarch64_a64_vstur,
          aarch64_a64_xtn,
          aarch64_unknown = -1
        }
        ;
        aarch64_isa_modes isa_mode;
        aarch64_opcodes opcode;
        uint32_t ir;
        bool decode(uint32_t isa_mode, uint64_t insn_pc, const uint8_t *ptr) override;
        JumpInfo get_jump_info() override;
        private:
        bool decode_a64(uint32_t ir);
      }
      ;
      class aarch64_decode_a64 : public aarch64_decode
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
      class aarch64_decode_a64_ADD_SUB_CARRY : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_ADD_SUB_CARRY) <= 128, "Decode class for format ADD_SUB_CARRY is too big!");
      class aarch64_decode_a64_ADD_SUB_EREG : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_ADD_SUB_EREG) <= 128, "Decode class for format ADD_SUB_EREG is too big!");
      class aarch64_decode_a64_ADD_SUB_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_ADD_SUB_IMM) <= 128, "Decode class for format ADD_SUB_IMM is too big!");
      class aarch64_decode_a64_ADD_SUB_SREG : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_ADD_SUB_SREG) <= 128, "Decode class for format ADD_SUB_SREG is too big!");
      class aarch64_decode_a64_BITFIELD : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_BITFIELD) <= 128, "Decode class for format BITFIELD is too big!");
      class aarch64_decode_a64_CMP_B_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_CMP_B_IMM) <= 128, "Decode class for format CMP_B_IMM is too big!");
      class aarch64_decode_a64_COND_B_IMM : public aarch64_decode_a64
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
        inline bool decode_is_predicated() const
        {
          {
            //return internal_opcode() == opcodes::aarch64_a64_bcond;
            return opcode == aarch64_a64_bcond;
          }
        }
      }
      ;
      static_assert(sizeof(aarch64_decode_a64_COND_B_IMM) <= 128, "Decode class for format COND_B_IMM is too big!");
      class aarch64_decode_a64_COND_CMP_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_COND_CMP_IMM) <= 128, "Decode class for format COND_CMP_IMM is too big!");
      class aarch64_decode_a64_COND_CMP_REG : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_COND_CMP_REG) <= 128, "Decode class for format COND_CMP_REG is too big!");
      class aarch64_decode_a64_COND_SEL : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_COND_SEL) <= 128, "Decode class for format COND_SEL is too big!");
      class aarch64_decode_a64_CVT_FP_FXP : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_CVT_FP_FXP) <= 128, "Decode class for format CVT_FP_FXP is too big!");
      class aarch64_decode_a64_CVT_FP_I : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_CVT_FP_I) <= 128, "Decode class for format CVT_FP_I is too big!");
      class aarch64_decode_a64_DP_1S : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_DP_1S) <= 128, "Decode class for format DP_1S is too big!");
      class aarch64_decode_a64_DP_2S : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_DP_2S) <= 128, "Decode class for format DP_2S is too big!");
      class aarch64_decode_a64_DP_3S : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_DP_3S) <= 128, "Decode class for format DP_3S is too big!");
      class aarch64_decode_a64_EXTRACT : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_EXTRACT) <= 128, "Decode class for format EXTRACT is too big!");
      class aarch64_decode_a64_EX_GEN : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_EX_GEN) <= 128, "Decode class for format EX_GEN is too big!");
      class aarch64_decode_a64_FP_CCMP : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_FP_CCMP) <= 128, "Decode class for format FP_CCMP is too big!");
      class aarch64_decode_a64_FP_CMP : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_FP_CMP) <= 128, "Decode class for format FP_CMP is too big!");
      class aarch64_decode_a64_FP_CSEL : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_FP_CSEL) <= 128, "Decode class for format FP_CSEL is too big!");
      class aarch64_decode_a64_FP_DP_1 : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_FP_DP_1) <= 128, "Decode class for format FP_DP_1 is too big!");
      class aarch64_decode_a64_FP_DP_2 : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_FP_DP_2) <= 128, "Decode class for format FP_DP_2 is too big!");
      class aarch64_decode_a64_FP_DP_3 : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_FP_DP_3) <= 128, "Decode class for format FP_DP_3 is too big!");
      class aarch64_decode_a64_FP_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_FP_IMM) <= 128, "Decode class for format FP_IMM is too big!");
      class aarch64_decode_a64_LOAD_REG_LIT : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LOAD_REG_LIT) <= 128, "Decode class for format LOAD_REG_LIT is too big!");
      class aarch64_decode_a64_LOGICAL_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LOGICAL_IMM) <= 128, "Decode class for format LOGICAL_IMM is too big!");
      class aarch64_decode_a64_LOGICAL_SR : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LOGICAL_SR) <= 128, "Decode class for format LOGICAL_SR is too big!");
      class aarch64_decode_a64_LS_EX : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LS_EX) <= 128, "Decode class for format LS_EX is too big!");
      class aarch64_decode_a64_LS_NO_ALLOC : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LS_NO_ALLOC) <= 128, "Decode class for format LS_NO_ALLOC is too big!");
      class aarch64_decode_a64_LS_REG_IMM_POST : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LS_REG_IMM_POST) <= 128, "Decode class for format LS_REG_IMM_POST is too big!");
      class aarch64_decode_a64_LS_REG_PAIR_IDX : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LS_REG_PAIR_IDX) <= 128, "Decode class for format LS_REG_PAIR_IDX is too big!");
      class aarch64_decode_a64_LS_REG_PAIR_OFF : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LS_REG_PAIR_OFF) <= 128, "Decode class for format LS_REG_PAIR_OFF is too big!");
      class aarch64_decode_a64_LS_REG_REG_OFF : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LS_REG_REG_OFF) <= 128, "Decode class for format LS_REG_REG_OFF is too big!");
      class aarch64_decode_a64_LS_REG_UIMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LS_REG_UIMM) <= 128, "Decode class for format LS_REG_UIMM is too big!");
      class aarch64_decode_a64_LS_REG_UNPRIV : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LS_REG_UNPRIV) <= 128, "Decode class for format LS_REG_UNPRIV is too big!");
      class aarch64_decode_a64_LS_REG_USIMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_LS_REG_USIMM) <= 128, "Decode class for format LS_REG_USIMM is too big!");
      class aarch64_decode_a64_MOVE_WIDE_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_MOVE_WIDE_IMM) <= 128, "Decode class for format MOVE_WIDE_IMM is too big!");
      class aarch64_decode_a64_PC_REL : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_PC_REL) <= 128, "Decode class for format PC_REL is too big!");
      class aarch64_decode_a64_SIMD_ACROSS_LANES : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_ACROSS_LANES) <= 128, "Decode class for format SIMD_ACROSS_LANES is too big!");
      class aarch64_decode_a64_SIMD_COPY : public aarch64_decode_a64
      {
        public:
        uint8_t Q;
        uint8_t op;
        uint8_t SCALAR;
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_COPY) <= 128, "Decode class for format SIMD_COPY is too big!");
      class aarch64_decode_a64_SIMD_EXTRACT : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_EXTRACT) <= 128, "Decode class for format SIMD_EXTRACT is too big!");
      class aarch64_decode_a64_SIMD_LS_MULT : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_LS_MULT) <= 128, "Decode class for format SIMD_LS_MULT is too big!");
      class aarch64_decode_a64_SIMD_LS_MULT_PI : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_LS_MULT_PI) <= 128, "Decode class for format SIMD_LS_MULT_PI is too big!");
      class aarch64_decode_a64_SIMD_LS_SINGLE : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_LS_SINGLE) <= 128, "Decode class for format SIMD_LS_SINGLE is too big!");
      class aarch64_decode_a64_SIMD_LS_SINGLE_PI : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_LS_SINGLE_PI) <= 128, "Decode class for format SIMD_LS_SINGLE_PI is too big!");
      class aarch64_decode_a64_SIMD_MOD_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_MOD_IMM) <= 128, "Decode class for format SIMD_MOD_IMM is too big!");
      class aarch64_decode_a64_SIMD_PERMUTE : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_PERMUTE) <= 128, "Decode class for format SIMD_PERMUTE is too big!");
      class aarch64_decode_a64_SIMD_SCALAR_PW : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_SCALAR_PW) <= 128, "Decode class for format SIMD_SCALAR_PW is too big!");
      class aarch64_decode_a64_SIMD_SHIFT_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_SHIFT_IMM) <= 128, "Decode class for format SIMD_SHIFT_IMM is too big!");
      class aarch64_decode_a64_SIMD_TABLE_LOOKUP : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_TABLE_LOOKUP) <= 128, "Decode class for format SIMD_TABLE_LOOKUP is too big!");
      class aarch64_decode_a64_SIMD_THREE_DIFF : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_THREE_DIFF) <= 128, "Decode class for format SIMD_THREE_DIFF is too big!");
      class aarch64_decode_a64_SIMD_THREE_SAME : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_THREE_SAME) <= 128, "Decode class for format SIMD_THREE_SAME is too big!");
      class aarch64_decode_a64_SIMD_TWO_REG_MISC : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_TWO_REG_MISC) <= 128, "Decode class for format SIMD_TWO_REG_MISC is too big!");
      class aarch64_decode_a64_SIMD_VECTOR_IDX : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SIMD_VECTOR_IDX) <= 128, "Decode class for format SIMD_VECTOR_IDX is too big!");
      class aarch64_decode_a64_SYSTEM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_SYSTEM) <= 128, "Decode class for format SYSTEM is too big!");
      class aarch64_decode_a64_TEST_B_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_TEST_B_IMM) <= 128, "Decode class for format TEST_B_IMM is too big!");
      class aarch64_decode_a64_UB_IMM : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_UB_IMM) <= 128, "Decode class for format UB_IMM is too big!");
      class aarch64_decode_a64_UB_REG : public aarch64_decode_a64
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
      static_assert(sizeof(aarch64_decode_a64_UB_REG) <= 128, "Decode class for format UB_REG is too big!");
    }
  }
}
