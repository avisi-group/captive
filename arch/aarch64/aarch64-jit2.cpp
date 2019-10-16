#include <aarch64-jit2.h>
#include <aarch64-cpu.h>
#include <queue>
#include <set>
#pragma GCC diagnostic ignored "-Wunused-variable"
void __behaviour_trampoline_undef(captive::arch::aarch64::aarch64_cpu *cpu) 
{
  cpu->handle_undefined_instruction();
}
using namespace captive::arch::aarch64;
template<bool TRACE>aarch64_jit2<TRACE>::aarch64_jit2() 
{
}
template<bool TRACE>aarch64_jit2<TRACE>::~aarch64_jit2() 
{
}
template<bool TRACE>bool aarch64_jit2<TRACE>::translate(const Decode *decode_obj, captive::arch::dbt::el::Emitter& emitter)
{
  const aarch64_decode& insn = *((const aarch64_decode *)decode_obj);
  switch (insn.opcode) 
  {
  case aarch64_decode::aarch64_a64_abs_simd:
    return translate_a64_abs_simd((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_adc:
    return translate_a64_adc((const aarch64_decode_a64_ADD_SUB_CARRY&)insn, emitter);
  case aarch64_decode::aarch64_a64_add_ereg:
    return translate_a64_add_ereg((const aarch64_decode_a64_ADD_SUB_EREG&)insn, emitter);
  case aarch64_decode::aarch64_a64_add_sreg:
    return translate_a64_add_sreg((const aarch64_decode_a64_ADD_SUB_SREG&)insn, emitter);
  case aarch64_decode::aarch64_a64_add_vector:
    return translate_a64_add_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_addi:
    return translate_a64_addi((const aarch64_decode_a64_ADD_SUB_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_addp_scalar:
    return translate_a64_addp_scalar((const aarch64_decode_a64_SIMD_SCALAR_PW&)insn, emitter);
  case aarch64_decode::aarch64_a64_addp_vector:
    return translate_a64_addp_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_addv:
    return translate_a64_addv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_adr:
    return translate_a64_adr((const aarch64_decode_a64_PC_REL&)insn, emitter);
  case aarch64_decode::aarch64_a64_and_vector:
    return translate_a64_and_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_andi:
    return translate_a64_andi((const aarch64_decode_a64_LOGICAL_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_andsr:
    return translate_a64_andsr((const aarch64_decode_a64_LOGICAL_SR&)insn, emitter);
  case aarch64_decode::aarch64_a64_asrv:
    return translate_a64_asrv((const aarch64_decode_a64_DP_2S&)insn, emitter);
  case aarch64_decode::aarch64_a64_b:
    return translate_a64_b((const aarch64_decode_a64_UB_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_barrier:
    return translate_a64_barrier((const aarch64_decode_a64_SYSTEM&)insn, emitter);
  case aarch64_decode::aarch64_a64_bcond:
    return translate_a64_bcond((const aarch64_decode_a64_COND_B_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_bfm:
    return translate_a64_bfm((const aarch64_decode_a64_BITFIELD&)insn, emitter);
  case aarch64_decode::aarch64_a64_bic_vector:
    return translate_a64_bic_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_bici:
    return translate_a64_bici((const aarch64_decode_a64_SIMD_MOD_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_bicsr:
    return translate_a64_bicsr((const aarch64_decode_a64_LOGICAL_SR&)insn, emitter);
  case aarch64_decode::aarch64_a64_bif:
    return translate_a64_bif((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_bit:
    return translate_a64_bit((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_br:
    return translate_a64_br((const aarch64_decode_a64_UB_REG&)insn, emitter);
  case aarch64_decode::aarch64_a64_bsl:
    return translate_a64_bsl((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_cbz:
    return translate_a64_cbz((const aarch64_decode_a64_CMP_B_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ccmni:
    return translate_a64_ccmni((const aarch64_decode_a64_COND_CMP_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ccmnr:
    return translate_a64_ccmnr((const aarch64_decode_a64_COND_CMP_REG&)insn, emitter);
  case aarch64_decode::aarch64_a64_ccmpi:
    return translate_a64_ccmpi((const aarch64_decode_a64_COND_CMP_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ccmpr:
    return translate_a64_ccmpr((const aarch64_decode_a64_COND_CMP_REG&)insn, emitter);
  case aarch64_decode::aarch64_a64_clrex:
    return translate_a64_clrex((const aarch64_decode_a64_SYSTEM&)insn, emitter);
  case aarch64_decode::aarch64_a64_cls:
    return translate_a64_cls((const aarch64_decode_a64_DP_1S&)insn, emitter);
  case aarch64_decode::aarch64_a64_clz:
    return translate_a64_clz((const aarch64_decode_a64_DP_1S&)insn, emitter);
  case aarch64_decode::aarch64_a64_cmeq_reg:
    return translate_a64_cmeq_reg((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_cmeq_zero:
    return translate_a64_cmeq_zero((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_cmge_zero:
    return translate_a64_cmge_zero((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_cmhi_reg:
    return translate_a64_cmhi_reg((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_cmlt_zero:
    return translate_a64_cmlt_zero((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_cmtst:
    return translate_a64_cmtst((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_cnt:
    return translate_a64_cnt((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_crc32:
    return translate_a64_crc32((const aarch64_decode_a64_DP_2S&)insn, emitter);
  case aarch64_decode::aarch64_a64_crc32c:
    return translate_a64_crc32c((const aarch64_decode_a64_DP_2S&)insn, emitter);
  case aarch64_decode::aarch64_a64_csel:
    return translate_a64_csel((const aarch64_decode_a64_COND_SEL&)insn, emitter);
  case aarch64_decode::aarch64_a64_csinc:
    return translate_a64_csinc((const aarch64_decode_a64_COND_SEL&)insn, emitter);
  case aarch64_decode::aarch64_a64_csinv:
    return translate_a64_csinv((const aarch64_decode_a64_COND_SEL&)insn, emitter);
  case aarch64_decode::aarch64_a64_csneg:
    return translate_a64_csneg((const aarch64_decode_a64_COND_SEL&)insn, emitter);
  case aarch64_decode::aarch64_a64_drps:
    return translate_a64_drps((const aarch64_decode_a64_UB_REG&)insn, emitter);
  case aarch64_decode::aarch64_a64_dup_elem:
    return translate_a64_dup_elem((const aarch64_decode_a64_SIMD_COPY&)insn, emitter);
  case aarch64_decode::aarch64_a64_dup_gen:
    return translate_a64_dup_gen((const aarch64_decode_a64_SIMD_COPY&)insn, emitter);
  case aarch64_decode::aarch64_a64_eor_vector:
    return translate_a64_eor_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_eori:
    return translate_a64_eori((const aarch64_decode_a64_LOGICAL_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_eorsr:
    return translate_a64_eorsr((const aarch64_decode_a64_LOGICAL_SR&)insn, emitter);
  case aarch64_decode::aarch64_a64_eret:
    return translate_a64_eret((const aarch64_decode_a64_UB_REG&)insn, emitter);
  case aarch64_decode::aarch64_a64_exgen:
    return translate_a64_exgen((const aarch64_decode_a64_EX_GEN&)insn, emitter);
  case aarch64_decode::aarch64_a64_ext:
    return translate_a64_ext((const aarch64_decode_a64_SIMD_EXTRACT&)insn, emitter);
  case aarch64_decode::aarch64_a64_extr:
    return translate_a64_extr((const aarch64_decode_a64_EXTRACT&)insn, emitter);
  case aarch64_decode::aarch64_a64_fabd:
    return translate_a64_fabd((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_fabs:
    return translate_a64_fabs((const aarch64_decode_a64_FP_DP_1&)insn, emitter);
  case aarch64_decode::aarch64_a64_fadd:
    return translate_a64_fadd((const aarch64_decode_a64_FP_DP_2&)insn, emitter);
  case aarch64_decode::aarch64_a64_fccmpe:
    return translate_a64_fccmpe((const aarch64_decode_a64_FP_CCMP&)insn, emitter);
  case aarch64_decode::aarch64_a64_fcmgt_zero:
    return translate_a64_fcmgt_zero((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_fcmpe:
    return translate_a64_fcmpe((const aarch64_decode_a64_FP_CMP&)insn, emitter);
  case aarch64_decode::aarch64_a64_fcsel:
    return translate_a64_fcsel((const aarch64_decode_a64_FP_CSEL&)insn, emitter);
  case aarch64_decode::aarch64_a64_fcvt:
    return translate_a64_fcvt((const aarch64_decode_a64_FP_DP_1&)insn, emitter);
  case aarch64_decode::aarch64_a64_fcvtas_simd:
    return translate_a64_fcvtas_simd((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_fcvti:
    return translate_a64_fcvti((const aarch64_decode_a64_CVT_FP_I&)insn, emitter);
  case aarch64_decode::aarch64_a64_fcvtz:
    return translate_a64_fcvtz((const aarch64_decode_a64_CVT_FP_I&)insn, emitter);
  case aarch64_decode::aarch64_a64_fcvtz_fxp:
    return translate_a64_fcvtz_fxp((const aarch64_decode_a64_CVT_FP_FXP&)insn, emitter);
  case aarch64_decode::aarch64_a64_fcvtzs_simd:
    return translate_a64_fcvtzs_simd((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_fdiv:
    return translate_a64_fdiv((const aarch64_decode_a64_FP_DP_2&)insn, emitter);
  case aarch64_decode::aarch64_a64_fdiv_vector:
    return translate_a64_fdiv_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_fm:
    return translate_a64_fm((const aarch64_decode_a64_FP_DP_3&)insn, emitter);
  case aarch64_decode::aarch64_a64_fmaxnmv:
    return translate_a64_fmaxnmv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_fmaxv:
    return translate_a64_fmaxv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_fminnmv:
    return translate_a64_fminnmv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_fminv:
    return translate_a64_fminv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_fmov:
    return translate_a64_fmov((const aarch64_decode_a64_FP_DP_1&)insn, emitter);
  case aarch64_decode::aarch64_a64_fmov_gen:
    return translate_a64_fmov_gen((const aarch64_decode_a64_CVT_FP_I&)insn, emitter);
  case aarch64_decode::aarch64_a64_fmov_simd:
    return translate_a64_fmov_simd((const aarch64_decode_a64_SIMD_MOD_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_fmovi:
    return translate_a64_fmovi((const aarch64_decode_a64_FP_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_fmul:
    return translate_a64_fmul((const aarch64_decode_a64_FP_DP_2&)insn, emitter);
  case aarch64_decode::aarch64_a64_fmul_vector:
    return translate_a64_fmul_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_fneg:
    return translate_a64_fneg((const aarch64_decode_a64_FP_DP_1&)insn, emitter);
  case aarch64_decode::aarch64_a64_fnm:
    return translate_a64_fnm((const aarch64_decode_a64_FP_DP_3&)insn, emitter);
  case aarch64_decode::aarch64_a64_fnmul:
    return translate_a64_fnmul((const aarch64_decode_a64_FP_DP_2&)insn, emitter);
  case aarch64_decode::aarch64_a64_frintx:
    return translate_a64_frintx((const aarch64_decode_a64_FP_DP_1&)insn, emitter);
  case aarch64_decode::aarch64_a64_fsqrt:
    return translate_a64_fsqrt((const aarch64_decode_a64_FP_DP_1&)insn, emitter);
  case aarch64_decode::aarch64_a64_fsub:
    return translate_a64_fsub((const aarch64_decode_a64_FP_DP_2&)insn, emitter);
  case aarch64_decode::aarch64_a64_fsub_vector:
    return translate_a64_fsub_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_hint:
    return translate_a64_hint((const aarch64_decode_a64_SYSTEM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ins_elem:
    return translate_a64_ins_elem((const aarch64_decode_a64_SIMD_COPY&)insn, emitter);
  case aarch64_decode::aarch64_a64_ins_gen:
    return translate_a64_ins_gen((const aarch64_decode_a64_SIMD_COPY&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld1:
    return translate_a64_ld1((const aarch64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld1pi:
    return translate_a64_ld1pi((const aarch64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld1r:
    return translate_a64_ld1r((const aarch64_decode_a64_SIMD_LS_SINGLE&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld1s:
    return translate_a64_ld1s((const aarch64_decode_a64_SIMD_LS_SINGLE&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld2:
    return translate_a64_ld2((const aarch64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld2pi:
    return translate_a64_ld2pi((const aarch64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld3:
    return translate_a64_ld3((const aarch64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld3pi:
    return translate_a64_ld3pi((const aarch64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld4:
    return translate_a64_ld4((const aarch64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case aarch64_decode::aarch64_a64_ld4pi:
    return translate_a64_ld4pi((const aarch64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldar:
    return translate_a64_ldar((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldarb:
    return translate_a64_ldarb((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldarh:
    return translate_a64_ldarh((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldaxp:
    return translate_a64_ldaxp((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldaxr:
    return translate_a64_ldaxr((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldaxrb:
    return translate_a64_ldaxrb((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldaxrh:
    return translate_a64_ldaxrh((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldnp:
    return translate_a64_ldnp((const aarch64_decode_a64_LS_NO_ALLOC&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldp:
    return translate_a64_ldp((const aarch64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldp_simd:
    return translate_a64_ldp_simd((const aarch64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldpi:
    return translate_a64_ldpi((const aarch64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldpi_simd:
    return translate_a64_ldpi_simd((const aarch64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldpsw:
    return translate_a64_ldpsw((const aarch64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldpswi:
    return translate_a64_ldpswi((const aarch64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldr:
    return translate_a64_ldr((const aarch64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldr_lit:
    return translate_a64_ldr_lit((const aarch64_decode_a64_LOAD_REG_LIT&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldr_lit_simd:
    return translate_a64_ldr_lit_simd((const aarch64_decode_a64_LOAD_REG_LIT&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldr_reg:
    return translate_a64_ldr_reg((const aarch64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldr_reg_simd:
    return translate_a64_ldr_reg_simd((const aarch64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldrb:
    return translate_a64_ldrb((const aarch64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldrb_reg:
    return translate_a64_ldrb_reg((const aarch64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldrbi:
    return translate_a64_ldrbi((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldrh:
    return translate_a64_ldrh((const aarch64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldrh_reg:
    return translate_a64_ldrh_reg((const aarch64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldrhi:
    return translate_a64_ldrhi((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldri:
    return translate_a64_ldri((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldrsw:
    return translate_a64_ldrsw((const aarch64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldrsw_lit:
    return translate_a64_ldrsw_lit((const aarch64_decode_a64_LOAD_REG_LIT&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldrswi:
    return translate_a64_ldrswi((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldtr:
    return translate_a64_ldtr((const aarch64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldtrb:
    return translate_a64_ldtrb((const aarch64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldtrh:
    return translate_a64_ldtrh((const aarch64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldtrsw:
    return translate_a64_ldtrsw((const aarch64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldur:
    return translate_a64_ldur((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldurb:
    return translate_a64_ldurb((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldurh:
    return translate_a64_ldurh((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldursw:
    return translate_a64_ldursw((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldxp:
    return translate_a64_ldxp((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldxr:
    return translate_a64_ldxr((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldxrb:
    return translate_a64_ldxrb((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_ldxrh:
    return translate_a64_ldxrh((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_lslv:
    return translate_a64_lslv((const aarch64_decode_a64_DP_2S&)insn, emitter);
  case aarch64_decode::aarch64_a64_lsrv:
    return translate_a64_lsrv((const aarch64_decode_a64_DP_2S&)insn, emitter);
  case aarch64_decode::aarch64_a64_madd:
    return translate_a64_madd((const aarch64_decode_a64_DP_3S&)insn, emitter);
  case aarch64_decode::aarch64_a64_mla_vector:
    return translate_a64_mla_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_mov:
    return translate_a64_mov((const aarch64_decode_a64_LOGICAL_SR&)insn, emitter);
  case aarch64_decode::aarch64_a64_movi:
    return translate_a64_movi((const aarch64_decode_a64_SIMD_MOD_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_movk:
    return translate_a64_movk((const aarch64_decode_a64_MOVE_WIDE_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_movn:
    return translate_a64_movn((const aarch64_decode_a64_MOVE_WIDE_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_movz:
    return translate_a64_movz((const aarch64_decode_a64_MOVE_WIDE_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_mrs:
    return translate_a64_mrs((const aarch64_decode_a64_SYSTEM&)insn, emitter);
  case aarch64_decode::aarch64_a64_msr_imm:
    return translate_a64_msr_imm((const aarch64_decode_a64_SYSTEM&)insn, emitter);
  case aarch64_decode::aarch64_a64_msr_reg:
    return translate_a64_msr_reg((const aarch64_decode_a64_SYSTEM&)insn, emitter);
  case aarch64_decode::aarch64_a64_msr_sctlr:
    return translate_a64_msr_sctlr((const aarch64_decode_a64_SYSTEM&)insn, emitter);
  case aarch64_decode::aarch64_a64_msub:
    return translate_a64_msub((const aarch64_decode_a64_DP_3S&)insn, emitter);
  case aarch64_decode::aarch64_a64_mul_idx_vector:
    return translate_a64_mul_idx_vector((const aarch64_decode_a64_SIMD_VECTOR_IDX&)insn, emitter);
  case aarch64_decode::aarch64_a64_mul_vector:
    return translate_a64_mul_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_mvni:
    return translate_a64_mvni((const aarch64_decode_a64_SIMD_MOD_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_neg_simd:
    return translate_a64_neg_simd((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_not_simd:
    return translate_a64_not_simd((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_orn_vector:
    return translate_a64_orn_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_orr_vector:
    return translate_a64_orr_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_orri:
    return translate_a64_orri((const aarch64_decode_a64_LOGICAL_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_orrsr:
    return translate_a64_orrsr((const aarch64_decode_a64_LOGICAL_SR&)insn, emitter);
  case aarch64_decode::aarch64_a64_pmull:
    return translate_a64_pmull((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_prfm:
    return translate_a64_prfm((const aarch64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case aarch64_decode::aarch64_a64_prfm_lit:
    return translate_a64_prfm_lit((const aarch64_decode_a64_LOAD_REG_LIT&)insn, emitter);
  case aarch64_decode::aarch64_a64_prfm_reg:
    return translate_a64_prfm_reg((const aarch64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_prfmi:
    return translate_a64_prfmi((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_prfum:
    return translate_a64_prfum((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_rbit:
    return translate_a64_rbit((const aarch64_decode_a64_DP_1S&)insn, emitter);
  case aarch64_decode::aarch64_a64_ret:
    return translate_a64_ret((const aarch64_decode_a64_UB_REG&)insn, emitter);
  case aarch64_decode::aarch64_a64_rev:
    return translate_a64_rev((const aarch64_decode_a64_DP_1S&)insn, emitter);
  case aarch64_decode::aarch64_a64_rev16:
    return translate_a64_rev16((const aarch64_decode_a64_DP_1S&)insn, emitter);
  case aarch64_decode::aarch64_a64_rev32:
    return translate_a64_rev32((const aarch64_decode_a64_DP_1S&)insn, emitter);
  case aarch64_decode::aarch64_a64_rev32_simd:
    return translate_a64_rev32_simd((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_rev64_simd:
    return translate_a64_rev64_simd((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_rorv:
    return translate_a64_rorv((const aarch64_decode_a64_DP_2S&)insn, emitter);
  case aarch64_decode::aarch64_a64_saddl:
    return translate_a64_saddl((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_saddlv:
    return translate_a64_saddlv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_saddw:
    return translate_a64_saddw((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_sbc:
    return translate_a64_sbc((const aarch64_decode_a64_ADD_SUB_CARRY&)insn, emitter);
  case aarch64_decode::aarch64_a64_sbfm:
    return translate_a64_sbfm((const aarch64_decode_a64_BITFIELD&)insn, emitter);
  case aarch64_decode::aarch64_a64_scvtf:
    return translate_a64_scvtf((const aarch64_decode_a64_CVT_FP_I&)insn, emitter);
  case aarch64_decode::aarch64_a64_scvtf_simd:
    return translate_a64_scvtf_simd((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_sdiv:
    return translate_a64_sdiv((const aarch64_decode_a64_DP_2S&)insn, emitter);
  case aarch64_decode::aarch64_a64_shl_simd:
    return translate_a64_shl_simd((const aarch64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_shll:
    return translate_a64_shll((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_smaddl:
    return translate_a64_smaddl((const aarch64_decode_a64_DP_3S&)insn, emitter);
  case aarch64_decode::aarch64_a64_smax:
    return translate_a64_smax((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_smaxv:
    return translate_a64_smaxv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_smin:
    return translate_a64_smin((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_sminv:
    return translate_a64_sminv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_smov:
    return translate_a64_smov((const aarch64_decode_a64_SIMD_COPY&)insn, emitter);
  case aarch64_decode::aarch64_a64_smsubl:
    return translate_a64_smsubl((const aarch64_decode_a64_DP_3S&)insn, emitter);
  case aarch64_decode::aarch64_a64_smulh:
    return translate_a64_smulh((const aarch64_decode_a64_DP_3S&)insn, emitter);
  case aarch64_decode::aarch64_a64_smull:
    return translate_a64_smull((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_sshl:
    return translate_a64_sshl((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_sshll:
    return translate_a64_sshll((const aarch64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_sshr:
    return translate_a64_sshr((const aarch64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ssubl:
    return translate_a64_ssubl((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ssubw:
    return translate_a64_ssubw((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_st1:
    return translate_a64_st1((const aarch64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case aarch64_decode::aarch64_a64_st1pi:
    return translate_a64_st1pi((const aarch64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case aarch64_decode::aarch64_a64_st1s:
    return translate_a64_st1s((const aarch64_decode_a64_SIMD_LS_SINGLE&)insn, emitter);
  case aarch64_decode::aarch64_a64_st1spi:
    return translate_a64_st1spi((const aarch64_decode_a64_SIMD_LS_SINGLE_PI&)insn, emitter);
  case aarch64_decode::aarch64_a64_st2:
    return translate_a64_st2((const aarch64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case aarch64_decode::aarch64_a64_st2pi:
    return translate_a64_st2pi((const aarch64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case aarch64_decode::aarch64_a64_st3:
    return translate_a64_st3((const aarch64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case aarch64_decode::aarch64_a64_st3pi:
    return translate_a64_st3pi((const aarch64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case aarch64_decode::aarch64_a64_st4:
    return translate_a64_st4((const aarch64_decode_a64_SIMD_LS_MULT&)insn, emitter);
  case aarch64_decode::aarch64_a64_st4pi:
    return translate_a64_st4pi((const aarch64_decode_a64_SIMD_LS_MULT_PI&)insn, emitter);
  case aarch64_decode::aarch64_a64_stlr:
    return translate_a64_stlr((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stlrb:
    return translate_a64_stlrb((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stlrh:
    return translate_a64_stlrh((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stlxp:
    return translate_a64_stlxp((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stlxr:
    return translate_a64_stlxr((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stlxrb:
    return translate_a64_stlxrb((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stlxrh:
    return translate_a64_stlxrh((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stnp:
    return translate_a64_stnp((const aarch64_decode_a64_LS_NO_ALLOC&)insn, emitter);
  case aarch64_decode::aarch64_a64_stp:
    return translate_a64_stp((const aarch64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_stp_simd:
    return translate_a64_stp_simd((const aarch64_decode_a64_LS_REG_PAIR_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_stpi:
    return translate_a64_stpi((const aarch64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stpi_simd:
    return translate_a64_stpi_simd((const aarch64_decode_a64_LS_REG_PAIR_IDX&)insn, emitter);
  case aarch64_decode::aarch64_a64_str:
    return translate_a64_str((const aarch64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case aarch64_decode::aarch64_a64_str_reg:
    return translate_a64_str_reg((const aarch64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_str_reg_simd:
    return translate_a64_str_reg_simd((const aarch64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_strb:
    return translate_a64_strb((const aarch64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case aarch64_decode::aarch64_a64_strb_reg:
    return translate_a64_strb_reg((const aarch64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_strbi:
    return translate_a64_strbi((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_strh:
    return translate_a64_strh((const aarch64_decode_a64_LS_REG_IMM_POST&)insn, emitter);
  case aarch64_decode::aarch64_a64_strh_reg:
    return translate_a64_strh_reg((const aarch64_decode_a64_LS_REG_REG_OFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_strhi:
    return translate_a64_strhi((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_stri:
    return translate_a64_stri((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_sttr:
    return translate_a64_sttr((const aarch64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case aarch64_decode::aarch64_a64_sttrb:
    return translate_a64_sttrb((const aarch64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case aarch64_decode::aarch64_a64_sttrh:
    return translate_a64_sttrh((const aarch64_decode_a64_LS_REG_UNPRIV&)insn, emitter);
  case aarch64_decode::aarch64_a64_stur:
    return translate_a64_stur((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_sturb:
    return translate_a64_sturb((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_sturh:
    return translate_a64_sturh((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_stxp:
    return translate_a64_stxp((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stxr:
    return translate_a64_stxr((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stxrb:
    return translate_a64_stxrb((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_stxrh:
    return translate_a64_stxrh((const aarch64_decode_a64_LS_EX&)insn, emitter);
  case aarch64_decode::aarch64_a64_sub_ereg:
    return translate_a64_sub_ereg((const aarch64_decode_a64_ADD_SUB_EREG&)insn, emitter);
  case aarch64_decode::aarch64_a64_sub_sreg:
    return translate_a64_sub_sreg((const aarch64_decode_a64_ADD_SUB_SREG&)insn, emitter);
  case aarch64_decode::aarch64_a64_sub_vector:
    return translate_a64_sub_vector((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_subi:
    return translate_a64_subi((const aarch64_decode_a64_ADD_SUB_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_sys:
    return translate_a64_sys((const aarch64_decode_a64_SYSTEM&)insn, emitter);
  case aarch64_decode::aarch64_a64_tbl:
    return translate_a64_tbl((const aarch64_decode_a64_SIMD_TABLE_LOOKUP&)insn, emitter);
  case aarch64_decode::aarch64_a64_tbx:
    return translate_a64_tbx((const aarch64_decode_a64_SIMD_TABLE_LOOKUP&)insn, emitter);
  case aarch64_decode::aarch64_a64_tbz:
    return translate_a64_tbz((const aarch64_decode_a64_TEST_B_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_uadalp:
    return translate_a64_uadalp((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_uaddl:
    return translate_a64_uaddl((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_uaddlp:
    return translate_a64_uaddlp((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_uaddlv:
    return translate_a64_uaddlv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_uaddw:
    return translate_a64_uaddw((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ubfm:
    return translate_a64_ubfm((const aarch64_decode_a64_BITFIELD&)insn, emitter);
  case aarch64_decode::aarch64_a64_ucvtf:
    return translate_a64_ucvtf((const aarch64_decode_a64_CVT_FP_I&)insn, emitter);
  case aarch64_decode::aarch64_a64_ucvtf_simd:
    return translate_a64_ucvtf_simd((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_a64_udiv:
    return translate_a64_udiv((const aarch64_decode_a64_DP_2S&)insn, emitter);
  case aarch64_decode::aarch64_a64_umaddl:
    return translate_a64_umaddl((const aarch64_decode_a64_DP_3S&)insn, emitter);
  case aarch64_decode::aarch64_a64_umaxv:
    return translate_a64_umaxv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_uminv:
    return translate_a64_uminv((const aarch64_decode_a64_SIMD_ACROSS_LANES&)insn, emitter);
  case aarch64_decode::aarch64_a64_umov:
    return translate_a64_umov((const aarch64_decode_a64_SIMD_COPY&)insn, emitter);
  case aarch64_decode::aarch64_a64_umsubl:
    return translate_a64_umsubl((const aarch64_decode_a64_DP_3S&)insn, emitter);
  case aarch64_decode::aarch64_a64_umulh:
    return translate_a64_umulh((const aarch64_decode_a64_DP_3S&)insn, emitter);
  case aarch64_decode::aarch64_a64_umull:
    return translate_a64_umull((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_ushl:
    return translate_a64_ushl((const aarch64_decode_a64_SIMD_THREE_SAME&)insn, emitter);
  case aarch64_decode::aarch64_a64_ushll:
    return translate_a64_ushll((const aarch64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_ushr:
    return translate_a64_ushr((const aarch64_decode_a64_SIMD_SHIFT_IMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_usubl:
    return translate_a64_usubl((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_usubw:
    return translate_a64_usubw((const aarch64_decode_a64_SIMD_THREE_DIFF&)insn, emitter);
  case aarch64_decode::aarch64_a64_uzp1:
    return translate_a64_uzp1((const aarch64_decode_a64_SIMD_PERMUTE&)insn, emitter);
  case aarch64_decode::aarch64_a64_uzp2:
    return translate_a64_uzp2((const aarch64_decode_a64_SIMD_PERMUTE&)insn, emitter);
  case aarch64_decode::aarch64_a64_vldr:
    return translate_a64_vldr((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_vldur:
    return translate_a64_vldur((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_vstr:
    return translate_a64_vstr((const aarch64_decode_a64_LS_REG_UIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_vstur:
    return translate_a64_vstur((const aarch64_decode_a64_LS_REG_USIMM&)insn, emitter);
  case aarch64_decode::aarch64_a64_xtn:
    return translate_a64_xtn((const aarch64_decode_a64_SIMD_TWO_REG_MISC&)insn, emitter);
  case aarch64_decode::aarch64_unknown:
    #ifdef CONFIG_PRINT_UNKNOWN_INSTRUCTIONS
    printf("*** unknown instruction: %08x\n", insn.ir);
    #endif
    emitter.call((void *)&__behaviour_trampoline_undef);
    emitter.leave();
    return true;
  default: return false;
  }
}
template<bool TRACE>captive::arch::dbt::el::Value *aarch64_jit2<TRACE>::generate_predicate_a64_COND_B_IMM(const aarch64_decode_a64_COND_B_IMM& insn, captive::arch::dbt::el::Emitter& emitter)
{
  std::queue<captive::arch::dbt::el::Block *> dynamic_block_queue;
  captive::arch::dbt::el::Block *__exit_block = emitter.context().create_block();
  captive::arch::dbt::el::Value *__result = emitter.alloc_local(emitter.context().types().u8(), true);
  uint8_t CV_sym_844_0_state;
  auto DV_sym_844_0_state = emitter.alloc_local(emitter.context().types().u8(), false);
  goto fixed_block_b_0;
  /*  */
  fixed_block_b_0: 
  {
    /* execute.a64:3028 [F] s_b_0_0 = constant u8 0 (const) */
    /* execute.a64:3028 [F] s_b_0_1: sym_844_0_state = s_b_0_0 (const), dominates: s_b_10_0 s_b_11_0  */
    CV_sym_844_0_state = (uint8_t)0ULL;
    emitter.store_local(DV_sym_844_0_state, emitter.const_u8((uint8_t)0ULL));
    /* execute.a64:3030 [F] s_b_0_2=sym_841_3_parameter_inst.cond (const) */
    /* execute.a64:3030 [F] s_b_0_3 = (u32)s_b_0_2 (const) */
    /* execute.a64:3030 [F] s_b_0_4 = constant u32 1 (const) */
    /* execute.a64:3030 [F] s_b_0_5 = s_b_0_3>>s_b_0_4 (const) */
    uint32_t s_b_0_5 = ((uint32_t)(((uint32_t)insn.cond) >> (uint32_t)1ULL));
    /* execute.a64:3031 [F] s_b_0_6 = constant s32 0 (const) */
    /* execute.a64:3035 [F] s_b_0_7 = constant s32 1 (const) */
    /* execute.a64:3039 [F] s_b_0_8 = constant s32 2 (const) */
    /* execute.a64:3043 [F] s_b_0_9 = constant s32 3 (const) */
    /* execute.a64:3047 [F] s_b_0_10 = constant s32 4 (const) */
    /* execute.a64:3051 [F] s_b_0_11 = constant s32 5 (const) */
    /* execute.a64:3055 [F] s_b_0_12 = constant s32 6 (const) */
    /* execute.a64:3059 [F] s_b_0_13 = constant s32 7 (const) */
    /* execute.a64:3030 [F] s_b_0_14: Switch s_b_0_5: < <todo> > def b_1 (const) -> b_3, b_2, b_4, b_6, b_7, b_8, b_5, b_1, b_9,  */
    switch (s_b_0_5) 
    {
    case (int32_t)2ULL:
      goto fixed_block_b_4;
      break;
    case (int32_t)1ULL:
      goto fixed_block_b_3;
      break;
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
    case (int32_t)7ULL:
      goto fixed_block_b_9;
      break;
    default:
      goto fixed_block_b_1;
    }
  }
  /* b_0, b_2, b_3, b_4, b_5, b_6, b_7, b_8, b_9,  */
  fixed_block_b_1: 
  {
    /* execute.a64:3065 [F] s_b_1_0=sym_841_3_parameter_inst.cond (const) */
    /* execute.a64:3065 [F] s_b_1_1 = (u32)s_b_1_0 (const) */
    /* execute.a64:3065 [F] s_b_1_2 = constant u32 1 (const) */
    /* execute.a64:3065 [F] s_b_1_3 = s_b_1_1&s_b_1_2 (const) */
    uint32_t s_b_1_3 = ((uint32_t)(((uint32_t)insn.cond) & (uint32_t)1ULL));
    /* execute.a64:3065 [F] s_b_1_4: If s_b_1_3: Jump b_10 else b_11 (const) */
    if (s_b_1_3) 
    {
      goto fixed_block_b_10;
    }
    else 
    {
      goto fixed_block_b_11;
    }
  }
  /* b_0,  */
  fixed_block_b_2: 
  {
    /* execute.a64:3032 [D] s_b_2_0 = ReadReg 2 (u8) */
    auto s_b_2_0 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_2_0, emitter.const_u8(1));
    }
    /* execute.a64:3032 [D] s_b_2_1: sym_844_0_state = s_b_2_0, dominates: s_b_10_0 s_b_11_0  */
    emitter.store_local(DV_sym_844_0_state, s_b_2_0);
    /* execute.a64:0 [F] s_b_2_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_3: 
  {
    /* execute.a64:3036 [D] s_b_3_0 = ReadReg 3 (u8) */
    auto s_b_3_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_3_0, emitter.const_u8(1));
    }
    /* execute.a64:3036 [D] s_b_3_1: sym_844_0_state = s_b_3_0, dominates: s_b_10_0 s_b_11_0  */
    emitter.store_local(DV_sym_844_0_state, s_b_3_0);
    /* execute.a64:0 [F] s_b_3_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_4: 
  {
    /* execute.a64:3040 [D] s_b_4_0 = ReadReg 1 (u8) */
    auto s_b_4_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_4_0, emitter.const_u8(1));
    }
    /* execute.a64:3040 [D] s_b_4_1: sym_844_0_state = s_b_4_0, dominates: s_b_10_0 s_b_11_0  */
    emitter.store_local(DV_sym_844_0_state, s_b_4_0);
    /* execute.a64:0 [F] s_b_4_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_5: 
  {
    /* execute.a64:3044 [D] s_b_5_0 = ReadReg 4 (u8) */
    auto s_b_5_0 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_5_0, emitter.const_u8(1));
    }
    /* execute.a64:3044 [D] s_b_5_1: sym_844_0_state = s_b_5_0, dominates: s_b_10_0 s_b_11_0  */
    emitter.store_local(DV_sym_844_0_state, s_b_5_0);
    /* execute.a64:0 [F] s_b_5_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_6: 
  {
    /* execute.a64:3048 [D] s_b_6_0 = ReadReg 3 (u8) */
    auto s_b_6_0 = emitter.load_register(emitter.const_u32(1298), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1298), s_b_6_0, emitter.const_u8(1));
    }
    /* execute.a64:3048 [D] s_b_6_1 = ReadReg 2 (u8) */
    auto s_b_6_1 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_6_1, emitter.const_u8(1));
    }
    /* execute.a64:3048 [D] s_b_6_2 = !s_b_6_1 */
    auto s_b_6_2 = emitter.cmp_eq(s_b_6_1, emitter.const_u8(0));
    /* execute.a64:3048 [D] s_b_6_3 = s_b_6_0&s_b_6_2 */
    auto s_b_6_3 = emitter.bitwise_and(s_b_6_0, s_b_6_2);
    /* execute.a64:3048 [D] s_b_6_4: sym_844_0_state = s_b_6_3, dominates: s_b_10_0 s_b_11_0  */
    emitter.store_local(DV_sym_844_0_state, s_b_6_3);
    /* execute.a64:0 [F] s_b_6_5: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_7: 
  {
    /* execute.a64:3052 [D] s_b_7_0 = ReadReg 1 (u8) */
    auto s_b_7_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_7_0, emitter.const_u8(1));
    }
    /* execute.a64:3052 [D] s_b_7_1 = ReadReg 4 (u8) */
    auto s_b_7_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_7_1, emitter.const_u8(1));
    }
    /* execute.a64:3052 [D] s_b_7_2 = s_b_7_0==s_b_7_1 */
    auto s_b_7_2 = emitter.cmp_eq(s_b_7_0, s_b_7_1);
    /* execute.a64:3052 [D] s_b_7_3: sym_844_0_state = s_b_7_2, dominates: s_b_10_0 s_b_11_0  */
    emitter.store_local(DV_sym_844_0_state, s_b_7_2);
    /* execute.a64:0 [F] s_b_7_4: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_8: 
  {
    /* execute.a64:3056 [D] s_b_8_0 = ReadReg 1 (u8) */
    auto s_b_8_0 = emitter.load_register(emitter.const_u32(1296), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1296), s_b_8_0, emitter.const_u8(1));
    }
    /* execute.a64:3056 [D] s_b_8_1 = ReadReg 4 (u8) */
    auto s_b_8_1 = emitter.load_register(emitter.const_u32(1299), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1299), s_b_8_1, emitter.const_u8(1));
    }
    /* execute.a64:3056 [D] s_b_8_2 = s_b_8_0==s_b_8_1 */
    auto s_b_8_2 = emitter.cmp_eq(s_b_8_0, s_b_8_1);
    /* execute.a64:3056 [D] s_b_8_3 = ReadReg 2 (u8) */
    auto s_b_8_3 = emitter.load_register(emitter.const_u32(1297), emitter.context().types().u8());
    if (TRACE) 
    {
      emitter.trace(dbt::el::TraceEvent::LOAD_REGISTER, emitter.const_u32(1297), s_b_8_3, emitter.const_u8(1));
    }
    /* execute.a64:3056 [D] s_b_8_4 = !s_b_8_3 */
    auto s_b_8_4 = emitter.cmp_eq(s_b_8_3, emitter.const_u8(0));
    /* execute.a64:3056 [D] s_b_8_5 = s_b_8_2&s_b_8_4 */
    auto s_b_8_5 = emitter.bitwise_and(s_b_8_2, s_b_8_4);
    /* execute.a64:3056 [D] s_b_8_6: sym_844_0_state = s_b_8_5, dominates: s_b_10_0 s_b_11_0  */
    emitter.store_local(DV_sym_844_0_state, s_b_8_5);
    /* execute.a64:0 [F] s_b_8_7: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_0,  */
  fixed_block_b_9: 
  {
    /* execute.a64:3060 [F] s_b_9_0 = constant u8 1 (const) */
    /* execute.a64:3060 [F] s_b_9_1: sym_844_0_state = s_b_9_0 (const), dominates: s_b_10_0 s_b_11_0  */
    CV_sym_844_0_state = (uint8_t)1ULL;
    emitter.store_local(DV_sym_844_0_state, emitter.const_u8((uint8_t)1ULL));
    /* execute.a64:0 [F] s_b_9_2: Jump b_1 (const) */
    goto fixed_block_b_1;
  }
  /* b_1,  */
  fixed_block_b_10: 
  {
    /* execute.a64:3066 [D] s_b_10_0 = sym_844_0_state uint8_t */
    auto s_b_10_0 = emitter.load_local(DV_sym_844_0_state, emitter.context().types().u8());
    /* execute.a64:3066 [D] s_b_10_1 = !s_b_10_0 */
    auto s_b_10_1 = emitter.cmp_eq(s_b_10_0, emitter.const_u8(0));
    /* execute.a64:3066 [F] s_b_10_2: Return s_b_10_1 */
    emitter.store_local(__result, s_b_10_1);
    goto fixed_done;
  }
  /* b_1,  */
  fixed_block_b_11: 
  {
    /* execute.a64:3068 [D] s_b_11_0 = sym_844_0_state uint8_t */
    auto s_b_11_0 = emitter.load_local(DV_sym_844_0_state, emitter.context().types().u8());
    /* execute.a64:3068 [F] s_b_11_1: Return s_b_11_0 */
    emitter.store_local(__result, s_b_11_0);
    goto fixed_done;
  }
  fixed_done:
  emitter.jump(__exit_block);
  emitter.set_current_block(__exit_block);
  return __result;
}
template class aarch64_jit2<true>;
template class aarch64_jit2<false>;
