#include <arm64-jit2.h>
#include <arm64-cpu.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
void __behaviour_trampoline_undef(captive::arch::arm64::arm64_cpu *cpu) 
{
  cpu->handle_undefined_instruction();
}
using namespace captive::arch::arm64;
template<bool TRACE>arm64_jit2<TRACE>::arm64_jit2() 
{
}
template<bool TRACE>arm64_jit2<TRACE>::~arm64_jit2() 
{
}
template<bool TRACE>bool arm64_jit2<TRACE>::translate(const Decode *decode_obj, captive::arch::dbt::el::Emitter& emitter)
{
  const arm64_decode& insn = *((const arm64_decode *)decode_obj);
  switch (insn.opcode) 
  {
  case arm64_decode::arm64_a64_abs_simd:
    return translate_a64_abs_simd((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_adc:
    return translate_a64_adc((const arm64_decode_a64_ADD_SUB_CARRY&)insn, emitter);
  case arm64_decode::arm64_a64_add_ereg:
    return translate_a64_add_ereg((const arm64_decode_a64_ADD_SUB_EREG&)insn, emitter);
  case arm64_decode::arm64_a64_add_sreg:
    return translate_a64_add_sreg((const arm64_decode_a64_ADD_SUB_SREG&)insn, emitter);
  case arm64_decode::arm64_a64_add_vector:
    return translate_a64_add_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_addi:
    return translate_a64_addi((const arm64_decode_a64_ADD_SUB_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_addp_scalar:
    return translate_a64_addp_scalar((const arm64_decode_a64_SIMD_SCALAR_PW&)insn, emitter);
  case arm64_decode::arm64_a64_addp_vector:
    return translate_a64_addp_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_addv:
    return translate_a64_addv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_adr:
    return translate_a64_adr((const arm64_decode_a64_PC_REL&)insn, emitter);
  case arm64_decode::arm64_a64_and_vector:
    return translate_a64_and_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_andi:
    return translate_a64_andi((const arm64_decode_a64_LOGICAL_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_andsr:
    return translate_a64_andsr((const arm64_decode_a64_LOGICAL_SR&)insn, emitter);
  case arm64_decode::arm64_a64_asrv:
    return translate_a64_asrv((const arm64_decode_a64_DP_2S&)insn, emitter);
  case arm64_decode::arm64_a64_b:
    return translate_a64_b((const arm64_decode_a64_UB_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_barrier:
    return translate_a64_barrier((const arm64_decode_a64_SYSTEM&)insn, emitter);
  case arm64_decode::arm64_a64_bcond:
    return translate_a64_bcond((const arm64_decode_a64_COND_B_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_bfm:
    return translate_a64_bfm((const arm64_decode_a64_BITFIELD&)insn, emitter);
  case arm64_decode::arm64_a64_bic_vector:
    return translate_a64_bic_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_bici:
    return translate_a64_bici((const arm64_decode_a64_SIMD_MOD_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_bicsr:
    return translate_a64_bicsr((const arm64_decode_a64_LOGICAL_SR&)insn, emitter);
  case arm64_decode::arm64_a64_bif:
    return translate_a64_bif((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_bit:
    return translate_a64_bit((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_br:
    return translate_a64_br((const arm64_decode_a64_UB_REG&)insn, emitter);
  case arm64_decode::arm64_a64_bsl:
    return translate_a64_bsl((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_cbz:
    return translate_a64_cbz((const arm64_decode_a64_CMP_B_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_ccmni:
    return translate_a64_ccmni((const arm64_decode_a64_COND_CMP_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_ccmnr:
    return translate_a64_ccmnr((const arm64_decode_a64_COND_CMP_REG&)insn, emitter);
  case arm64_decode::arm64_a64_ccmpi:
    return translate_a64_ccmpi((const arm64_decode_a64_COND_CMP_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_ccmpr:
    return translate_a64_ccmpr((const arm64_decode_a64_COND_CMP_REG&)insn, emitter);
  case arm64_decode::arm64_a64_clrex:
    return translate_a64_clrex((const arm64_decode_a64_SYSTEM&)insn, emitter);
  case arm64_decode::arm64_a64_cls:
    return translate_a64_cls((const arm64_decode_a64_DP_1S&)insn, emitter);
  case arm64_decode::arm64_a64_clz:
    return translate_a64_clz((const arm64_decode_a64_DP_1S&)insn, emitter);
  case arm64_decode::arm64_a64_cmeq_reg:
    return translate_a64_cmeq_reg((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_cmeq_zero:
    return translate_a64_cmeq_zero((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_cmge_zero:
    return translate_a64_cmge_zero((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_cmhi_reg:
    return translate_a64_cmhi_reg((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_cmhs_reg:
    return translate_a64_cmhs_reg((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_cmlt_zero:
    return translate_a64_cmlt_zero((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_cmtst:
    return translate_a64_cmtst((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_cnt:
    return translate_a64_cnt((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_crc32:
    return translate_a64_crc32((const arm64_decode_a64_DP_2S&)insn, emitter);
  case arm64_decode::arm64_a64_crc32c:
    return translate_a64_crc32c((const arm64_decode_a64_DP_2S&)insn, emitter);
  case arm64_decode::arm64_a64_csel:
    return translate_a64_csel((const arm64_decode_a64_COND_SEL&)insn, emitter);
  case arm64_decode::arm64_a64_csinc:
    return translate_a64_csinc((const arm64_decode_a64_COND_SEL&)insn, emitter);
  case arm64_decode::arm64_a64_csinv:
    return translate_a64_csinv((const arm64_decode_a64_COND_SEL&)insn, emitter);
  case arm64_decode::arm64_a64_csneg:
    return translate_a64_csneg((const arm64_decode_a64_COND_SEL&)insn, emitter);
  case arm64_decode::arm64_a64_drps:
    return translate_a64_drps((const arm64_decode_a64_UB_REG&)insn, emitter);
  case arm64_decode::arm64_a64_dup_elem:
    return translate_a64_dup_elem((const arm64_decode_a64_SIMD_COPY&)insn, emitter);
  case arm64_decode::arm64_a64_dup_gen:
    return translate_a64_dup_gen((const arm64_decode_a64_SIMD_COPY&)insn, emitter);
  case arm64_decode::arm64_a64_eor_vector:
    return translate_a64_eor_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_eori:
    return translate_a64_eori((const arm64_decode_a64_LOGICAL_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_eorsr:
    return translate_a64_eorsr((const arm64_decode_a64_LOGICAL_SR&)insn, emitter);
  case arm64_decode::arm64_a64_eret:
    return translate_a64_eret((const arm64_decode_a64_UB_REG&)insn, emitter);
  case arm64_decode::arm64_a64_exgen:
    return translate_a64_exgen((const arm64_decode_a64_EX_GEN&)insn, emitter);
  case arm64_decode::arm64_a64_ext:
    return translate_a64_ext((const arm64_decode_a64_SIMD_EXTRACT&)insn, emitter);
  case arm64_decode::arm64_a64_extr:
    return translate_a64_extr((const arm64_decode_a64_EXTRACT&)insn, emitter);
  case arm64_decode::arm64_a64_fabd:
    return translate_a64_fabd((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_fabs:
    return translate_a64_fabs((const arm64_decode_a64_FP_DP_1&)insn, emitter);
  case arm64_decode::arm64_a64_fadd:
    return translate_a64_fadd((const arm64_decode_a64_FP_DP_2&)insn, emitter);
  case arm64_decode::arm64_a64_fccmpe:
    return translate_a64_fccmpe((const arm64_decode_a64_FP_CCMP&)insn, emitter);
  case arm64_decode::arm64_a64_fcmgt_zero:
    return translate_a64_fcmgt_zero((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_fcmpe:
    return translate_a64_fcmpe((const arm64_decode_a64_FP_CMP&)insn, emitter);
  case arm64_decode::arm64_a64_fcsel:
    return translate_a64_fcsel((const arm64_decode_a64_FP_CSEL&)insn, emitter);
  case arm64_decode::arm64_a64_fcvt:
    return translate_a64_fcvt((const arm64_decode_a64_FP_DP_1&)insn, emitter);
  case arm64_decode::arm64_a64_fcvtas_simd:
    return translate_a64_fcvtas_simd((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_fcvti:
    return translate_a64_fcvti((const arm64_decode_a64_CVT_FP_I&)insn, emitter);
  case arm64_decode::arm64_a64_fcvtz:
    return translate_a64_fcvtz((const arm64_decode_a64_CVT_FP_I&)insn, emitter);
  case arm64_decode::arm64_a64_fcvtz_fxp:
    return translate_a64_fcvtz_fxp((const arm64_decode_a64_CVT_FP_FXP&)insn, emitter);
  case arm64_decode::arm64_a64_fcvtzs_simd:
    return translate_a64_fcvtzs_simd((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_fdiv:
    return translate_a64_fdiv((const arm64_decode_a64_FP_DP_2&)insn, emitter);
  case arm64_decode::arm64_a64_fm:
    return translate_a64_fm((const arm64_decode_a64_FP_DP_3&)insn, emitter);
  case arm64_decode::arm64_a64_fmaxnmv:
    return translate_a64_fmaxnmv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_fmaxv:
    return translate_a64_fmaxv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_fminnmv:
    return translate_a64_fminnmv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_fminv:
    return translate_a64_fminv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_fmov:
    return translate_a64_fmov((const arm64_decode_a64_FP_DP_1&)insn, emitter);
  case arm64_decode::arm64_a64_fmov_gen:
    return translate_a64_fmov_gen((const arm64_decode_a64_CVT_FP_I&)insn, emitter);
  case arm64_decode::arm64_a64_fmov_simd:
    return translate_a64_fmov_simd((const arm64_decode_a64_SIMD_MOD_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_fmovi:
    return translate_a64_fmovi((const arm64_decode_a64_FP_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_fmul:
    return translate_a64_fmul((const arm64_decode_a64_FP_DP_2&)insn, emitter);
  case arm64_decode::arm64_a64_fmul_vector:
    return translate_a64_fmul_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_fneg:
    return translate_a64_fneg((const arm64_decode_a64_FP_DP_1&)insn, emitter);
  case arm64_decode::arm64_a64_fnm:
    return translate_a64_fnm((const arm64_decode_a64_FP_DP_3&)insn, emitter);
  case arm64_decode::arm64_a64_fnmul:
    return translate_a64_fnmul((const arm64_decode_a64_FP_DP_2&)insn, emitter);
  case arm64_decode::arm64_a64_frintx:
    return translate_a64_frintx((const arm64_decode_a64_FP_DP_1&)insn, emitter);
  case arm64_decode::arm64_a64_fsqrt:
    return translate_a64_fsqrt((const arm64_decode_a64_FP_DP_1&)insn, emitter);
  case arm64_decode::arm64_a64_fsub:
    return translate_a64_fsub((const arm64_decode_a64_FP_DP_2&)insn, emitter);
  case arm64_decode::arm64_a64_fsub_vector:
    return translate_a64_fsub_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_hint:
    return translate_a64_hint((const arm64_decode_a64_SYSTEM&)insn, emitter);
  case arm64_decode::arm64_a64_ins_elem:
    return translate_a64_ins_elem((const arm64_decode_a64_SIMD_COPY&)insn, emitter);
  case arm64_decode::arm64_a64_ins_gen:
    return translate_a64_ins_gen((const arm64_decode_a64_SIMD_COPY&)insn, emitter);
  case arm64_decode::arm64_a64_ld1:
    return translate_a64_ld1((const arm64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case arm64_decode::arm64_a64_ld1pi:
    return translate_a64_ld1pi((const arm64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case arm64_decode::arm64_a64_ld1r:
    return translate_a64_ld1r((const arm64_decode_a64_SIMD_LS_SINGLE&)insn, emitter);
  case arm64_decode::arm64_a64_ld1s:
    return translate_a64_ld1s((const arm64_decode_a64_SIMD_LS_SINGLE&)insn, emitter);
  case arm64_decode::arm64_a64_ld2:
    return translate_a64_ld2((const arm64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case arm64_decode::arm64_a64_ld2pi:
    return translate_a64_ld2pi((const arm64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case arm64_decode::arm64_a64_ld3:
    return translate_a64_ld3((const arm64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case arm64_decode::arm64_a64_ld3pi:
    return translate_a64_ld3pi((const arm64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case arm64_decode::arm64_a64_ld4:
    return translate_a64_ld4((const arm64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case arm64_decode::arm64_a64_ld4pi:
    return translate_a64_ld4pi((const arm64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case arm64_decode::arm64_a64_ldar:
    return translate_a64_ldar((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldarb:
    return translate_a64_ldarb((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldarh:
    return translate_a64_ldarh((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldaxp:
    return translate_a64_ldaxp((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldaxr:
    return translate_a64_ldaxr((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldaxrb:
    return translate_a64_ldaxrb((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldaxrh:
    return translate_a64_ldaxrh((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldnp:
    return translate_a64_ldnp((const arm64_decode_a64_LS_NO_ALLOC&)insn, emitter);
  case arm64_decode::arm64_a64_ldp:
    return translate_a64_ldp((const arm64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_ldp_simd:
    return translate_a64_ldp_simd((const arm64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_ldpi:
    return translate_a64_ldpi((const arm64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case arm64_decode::arm64_a64_ldpi_simd:
    return translate_a64_ldpi_simd((const arm64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case arm64_decode::arm64_a64_ldpsw:
    return translate_a64_ldpsw((const arm64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_ldpswi:
    return translate_a64_ldpswi((const arm64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case arm64_decode::arm64_a64_ldr:
    return translate_a64_ldr((const arm64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case arm64_decode::arm64_a64_ldr_lit:
    return translate_a64_ldr_lit((const arm64_decode_a64_LOAD_REG_LIT&)insn, emitter);
  case arm64_decode::arm64_a64_ldr_lit_simd:
    return translate_a64_ldr_lit_simd((const arm64_decode_a64_LOAD_REG_LIT&)insn, emitter);
  case arm64_decode::arm64_a64_ldr_reg:
    return translate_a64_ldr_reg((const arm64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_ldr_reg_simd:
    return translate_a64_ldr_reg_simd((const arm64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_ldrb:
    return translate_a64_ldrb((const arm64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case arm64_decode::arm64_a64_ldrb_reg:
    return translate_a64_ldrb_reg((const arm64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_ldrbi:
    return translate_a64_ldrbi((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_ldrh:
    return translate_a64_ldrh((const arm64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case arm64_decode::arm64_a64_ldrh_reg:
    return translate_a64_ldrh_reg((const arm64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_ldrhi:
    return translate_a64_ldrhi((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_ldri:
    return translate_a64_ldri((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_ldrsw:
    return translate_a64_ldrsw((const arm64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case arm64_decode::arm64_a64_ldrsw_lit:
    return translate_a64_ldrsw_lit((const arm64_decode_a64_LOAD_REG_LIT&)insn, emitter);
  case arm64_decode::arm64_a64_ldrswi:
    return translate_a64_ldrswi((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_ldtr:
    return translate_a64_ldtr((const arm64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case arm64_decode::arm64_a64_ldtrb:
    return translate_a64_ldtrb((const arm64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case arm64_decode::arm64_a64_ldtrh:
    return translate_a64_ldtrh((const arm64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case arm64_decode::arm64_a64_ldtrsw:
    return translate_a64_ldtrsw((const arm64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case arm64_decode::arm64_a64_ldur:
    return translate_a64_ldur((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_ldurb:
    return translate_a64_ldurb((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_ldurh:
    return translate_a64_ldurh((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_ldursw:
    return translate_a64_ldursw((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_ldxp:
    return translate_a64_ldxp((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldxr:
    return translate_a64_ldxr((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldxrb:
    return translate_a64_ldxrb((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_ldxrh:
    return translate_a64_ldxrh((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_lslv:
    return translate_a64_lslv((const arm64_decode_a64_DP_2S&)insn, emitter);
  case arm64_decode::arm64_a64_lsrv:
    return translate_a64_lsrv((const arm64_decode_a64_DP_2S&)insn, emitter);
  case arm64_decode::arm64_a64_madd:
    return translate_a64_madd((const arm64_decode_a64_DP_3S&)insn, emitter);
  case arm64_decode::arm64_a64_mla_vector:
    return translate_a64_mla_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_mov:
    return translate_a64_mov((const arm64_decode_a64_LOGICAL_SR&)insn, emitter);
  case arm64_decode::arm64_a64_movi:
    return translate_a64_movi((const arm64_decode_a64_SIMD_MOD_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_movk:
    return translate_a64_movk((const arm64_decode_a64_MOVE_WIDE_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_movn:
    return translate_a64_movn((const arm64_decode_a64_MOVE_WIDE_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_movz:
    return translate_a64_movz((const arm64_decode_a64_MOVE_WIDE_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_mrs:
    return translate_a64_mrs((const arm64_decode_a64_SYSTEM&)insn, emitter);
  case arm64_decode::arm64_a64_msr_imm:
    return translate_a64_msr_imm((const arm64_decode_a64_SYSTEM&)insn, emitter);
  case arm64_decode::arm64_a64_msr_reg:
    return translate_a64_msr_reg((const arm64_decode_a64_SYSTEM&)insn, emitter);
  case arm64_decode::arm64_a64_msr_sctlr:
    return translate_a64_msr_sctlr((const arm64_decode_a64_SYSTEM&)insn, emitter);
  case arm64_decode::arm64_a64_msub:
    return translate_a64_msub((const arm64_decode_a64_DP_3S&)insn, emitter);
  case arm64_decode::arm64_a64_mul_idx_vector:
    return translate_a64_mul_idx_vector((const arm64_decode_a64_SIMD_VECTOR_IDX&)insn, emitter);
  case arm64_decode::arm64_a64_mul_vector:
    return translate_a64_mul_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_mvni:
    return translate_a64_mvni((const arm64_decode_a64_SIMD_MOD_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_neg_simd:
    return translate_a64_neg_simd((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_not_simd:
    return translate_a64_not_simd((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_orn_vector:
    return translate_a64_orn_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_orr_vector:
    return translate_a64_orr_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_orri:
    return translate_a64_orri((const arm64_decode_a64_LOGICAL_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_orrsr:
    return translate_a64_orrsr((const arm64_decode_a64_LOGICAL_SR&)insn, emitter);
  case arm64_decode::arm64_a64_pmull:
    return translate_a64_pmull((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_prfm:
    return translate_a64_prfm((const arm64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case arm64_decode::arm64_a64_prfm_lit:
    return translate_a64_prfm_lit((const arm64_decode_a64_LOAD_REG_LIT&)insn, emitter);
  case arm64_decode::arm64_a64_prfm_reg:
    return translate_a64_prfm_reg((const arm64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_prfmi:
    return translate_a64_prfmi((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_prfum:
    return translate_a64_prfum((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_rbit:
    return translate_a64_rbit((const arm64_decode_a64_DP_1S&)insn, emitter);
  case arm64_decode::arm64_a64_ret:
    return translate_a64_ret((const arm64_decode_a64_UB_REG&)insn, emitter);
  case arm64_decode::arm64_a64_rev:
    return translate_a64_rev((const arm64_decode_a64_DP_1S&)insn, emitter);
  case arm64_decode::arm64_a64_rev16:
    return translate_a64_rev16((const arm64_decode_a64_DP_1S&)insn, emitter);
  case arm64_decode::arm64_a64_rev32:
    return translate_a64_rev32((const arm64_decode_a64_DP_1S&)insn, emitter);
  case arm64_decode::arm64_a64_rev32_simd:
    return translate_a64_rev32_simd((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_rev64_simd:
    return translate_a64_rev64_simd((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_rorv:
    return translate_a64_rorv((const arm64_decode_a64_DP_2S&)insn, emitter);
  case arm64_decode::arm64_a64_saddl:
    return translate_a64_saddl((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_saddlv:
    return translate_a64_saddlv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_saddw:
    return translate_a64_saddw((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_sbc:
    return translate_a64_sbc((const arm64_decode_a64_ADD_SUB_CARRY&)insn, emitter);
  case arm64_decode::arm64_a64_sbfm:
    return translate_a64_sbfm((const arm64_decode_a64_BITFIELD&)insn, emitter);
  case arm64_decode::arm64_a64_scvtf:
    return translate_a64_scvtf((const arm64_decode_a64_CVT_FP_I&)insn, emitter);
  case arm64_decode::arm64_a64_scvtf_simd:
    return translate_a64_scvtf_simd((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_sdiv:
    return translate_a64_sdiv((const arm64_decode_a64_DP_2S&)insn, emitter);
  case arm64_decode::arm64_a64_shl_simd:
    return translate_a64_shl_simd((const arm64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_shll:
    return translate_a64_shll((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_smaddl:
    return translate_a64_smaddl((const arm64_decode_a64_DP_3S&)insn, emitter);
  case arm64_decode::arm64_a64_smax:
    return translate_a64_smax((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_smaxv:
    return translate_a64_smaxv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_smin:
    return translate_a64_smin((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_sminv:
    return translate_a64_sminv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_smov:
    return translate_a64_smov((const arm64_decode_a64_SIMD_COPY&)insn, emitter);
  case arm64_decode::arm64_a64_smsubl:
    return translate_a64_smsubl((const arm64_decode_a64_DP_3S&)insn, emitter);
  case arm64_decode::arm64_a64_smulh:
    return translate_a64_smulh((const arm64_decode_a64_DP_3S&)insn, emitter);
  case arm64_decode::arm64_a64_smull:
    return translate_a64_smull((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_sshl:
    return translate_a64_sshl((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_sshll:
    return translate_a64_sshll((const arm64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_sshr:
    return translate_a64_sshr((const arm64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_ssubl:
    return translate_a64_ssubl((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_ssubw:
    return translate_a64_ssubw((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_st1:
    return translate_a64_st1((const arm64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case arm64_decode::arm64_a64_st1pi:
    return translate_a64_st1pi((const arm64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case arm64_decode::arm64_a64_st1s:
    return translate_a64_st1s((const arm64_decode_a64_SIMD_LS_SINGLE&)insn, emitter);
  case arm64_decode::arm64_a64_st1spi:
    return translate_a64_st1spi((const arm64_decode_a64_SIMD_LS_SINGLE_PI&)insn, emitter);
  case arm64_decode::arm64_a64_st2:
    return translate_a64_st2((const arm64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case arm64_decode::arm64_a64_st2pi:
    return translate_a64_st2pi((const arm64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case arm64_decode::arm64_a64_st3:
    return translate_a64_st3((const arm64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case arm64_decode::arm64_a64_st3pi:
    return translate_a64_st3pi((const arm64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case arm64_decode::arm64_a64_st4:
    return translate_a64_st4((const arm64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case arm64_decode::arm64_a64_st4pi:
    return translate_a64_st4pi((const arm64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case arm64_decode::arm64_a64_stlr:
    return translate_a64_stlr((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stlrb:
    return translate_a64_stlrb((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stlrh:
    return translate_a64_stlrh((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stlxp:
    return translate_a64_stlxp((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stlxr:
    return translate_a64_stlxr((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stlxrb:
    return translate_a64_stlxrb((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stlxrh:
    return translate_a64_stlxrh((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stnp:
    return translate_a64_stnp((const arm64_decode_a64_LS_NO_ALLOC&)insn, emitter);
  case arm64_decode::arm64_a64_stp:
    return translate_a64_stp((const arm64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_stp_simd:
    return translate_a64_stp_simd((const arm64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_stpi:
    return translate_a64_stpi((const arm64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case arm64_decode::arm64_a64_stpi_simd:
    return translate_a64_stpi_simd((const arm64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case arm64_decode::arm64_a64_str:
    return translate_a64_str((const arm64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case arm64_decode::arm64_a64_str_reg:
    return translate_a64_str_reg((const arm64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_str_reg_simd:
    return translate_a64_str_reg_simd((const arm64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_strb:
    return translate_a64_strb((const arm64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case arm64_decode::arm64_a64_strb_reg:
    return translate_a64_strb_reg((const arm64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_strbi:
    return translate_a64_strbi((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_strh:
    return translate_a64_strh((const arm64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case arm64_decode::arm64_a64_strh_reg:
    return translate_a64_strh_reg((const arm64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case arm64_decode::arm64_a64_strhi:
    return translate_a64_strhi((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_stri:
    return translate_a64_stri((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_sttr:
    return translate_a64_sttr((const arm64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case arm64_decode::arm64_a64_sttrb:
    return translate_a64_sttrb((const arm64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case arm64_decode::arm64_a64_sttrh:
    return translate_a64_sttrh((const arm64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case arm64_decode::arm64_a64_stur:
    return translate_a64_stur((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_sturb:
    return translate_a64_sturb((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_sturh:
    return translate_a64_sturh((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_stxp:
    return translate_a64_stxp((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stxr:
    return translate_a64_stxr((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stxrb:
    return translate_a64_stxrb((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_stxrh:
    return translate_a64_stxrh((const arm64_decode_a64_LS_EX&)insn, emitter);
  case arm64_decode::arm64_a64_sub_ereg:
    return translate_a64_sub_ereg((const arm64_decode_a64_ADD_SUB_EREG&)insn, emitter);
  case arm64_decode::arm64_a64_sub_sreg:
    return translate_a64_sub_sreg((const arm64_decode_a64_ADD_SUB_SREG&)insn, emitter);
  case arm64_decode::arm64_a64_sub_vector:
    return translate_a64_sub_vector((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_subi:
    return translate_a64_subi((const arm64_decode_a64_ADD_SUB_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_sys:
    return translate_a64_sys((const arm64_decode_a64_SYSTEM&)insn, emitter);
  case arm64_decode::arm64_a64_tbl:
    return translate_a64_tbl((const arm64_decode_a64_SIMD_TABLE_LOOKUP&)insn, emitter);
  case arm64_decode::arm64_a64_tbx:
    return translate_a64_tbx((const arm64_decode_a64_SIMD_TABLE_LOOKUP&)insn, emitter);
  case arm64_decode::arm64_a64_tbz:
    return translate_a64_tbz((const arm64_decode_a64_TEST_B_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_uadalp:
    return translate_a64_uadalp((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_uaddl:
    return translate_a64_uaddl((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_uaddlp:
    return translate_a64_uaddlp((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_uaddlv:
    return translate_a64_uaddlv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_uaddw:
    return translate_a64_uaddw((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_ubfm:
    return translate_a64_ubfm((const arm64_decode_a64_BITFIELD&)insn, emitter);
  case arm64_decode::arm64_a64_ucvtf:
    return translate_a64_ucvtf((const arm64_decode_a64_CVT_FP_I&)insn, emitter);
  case arm64_decode::arm64_a64_ucvtf_fxp:
    return translate_a64_ucvtf_fxp((const arm64_decode_a64_CVT_FP_FXP&)insn, emitter);
  case arm64_decode::arm64_a64_ucvtf_simd:
    return translate_a64_ucvtf_simd((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_a64_udiv:
    return translate_a64_udiv((const arm64_decode_a64_DP_2S&)insn, emitter);
  case arm64_decode::arm64_a64_umaddl:
    return translate_a64_umaddl((const arm64_decode_a64_DP_3S&)insn, emitter);
  case arm64_decode::arm64_a64_umaxv:
    return translate_a64_umaxv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_uminv:
    return translate_a64_uminv((const arm64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case arm64_decode::arm64_a64_umov:
    return translate_a64_umov((const arm64_decode_a64_SIMD_COPY&)insn, emitter);
  case arm64_decode::arm64_a64_umsubl:
    return translate_a64_umsubl((const arm64_decode_a64_DP_3S&)insn, emitter);
  case arm64_decode::arm64_a64_umulh:
    return translate_a64_umulh((const arm64_decode_a64_DP_3S&)insn, emitter);
  case arm64_decode::arm64_a64_umull:
    return translate_a64_umull((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_ushl:
    return translate_a64_ushl((const arm64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case arm64_decode::arm64_a64_ushll:
    return translate_a64_ushll((const arm64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_ushr:
    return translate_a64_ushr((const arm64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case arm64_decode::arm64_a64_usubl:
    return translate_a64_usubl((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_usubw:
    return translate_a64_usubw((const arm64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case arm64_decode::arm64_a64_uzp1:
    return translate_a64_uzp1((const arm64_decode_a64_SIMD_PERMUTE&)insn, emitter);
  case arm64_decode::arm64_a64_uzp2:
    return translate_a64_uzp2((const arm64_decode_a64_SIMD_PERMUTE&)insn, emitter);
  case arm64_decode::arm64_a64_vldr:
    return translate_a64_vldr((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_vldur:
    return translate_a64_vldur((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_vstr:
    return translate_a64_vstr((const arm64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case arm64_decode::arm64_a64_vstur:
    return translate_a64_vstur((const arm64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case arm64_decode::arm64_a64_xtn:
    return translate_a64_xtn((const arm64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case arm64_decode::arm64_unknown:
    #ifdef CONFIG_PRINT_UNKNOWN_INSTRUCTIONS
    printf("*** unknown instruction: %08x\n", insn.ir);
    #endif
    emitter.call((void *)&__behaviour_trampoline_undef);
    emitter.leave();
    return true;
  default: return false;
  }
}
template class arm64_jit2<true>;
template class arm64_jit2<false>;
