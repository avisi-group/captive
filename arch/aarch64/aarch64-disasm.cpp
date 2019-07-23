/* SPDX-License-Identifier: MIT */

#include <aarch64-disasm.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace captive::arch::aarch64;
const char *aarch64_disasm::_map_a64_arrg[] ={
	"8b", "16b", "4h", "8h", "2s", "4s", "2d",
}
;
const char *aarch64_disasm::_map_a64_breg[] ={
	"b0", "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "b9", "b10", "b11", "b12", "b13", "b14", "b15", "b16", "b17", "b18", "b19", "b20", "b21", "b22", "b23", "b24", "b25", "b26", "b27", "b28", "b29", "b30", "b31",
}
;
const char *aarch64_disasm::_map_a64_cond[] ={
	"eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le", "al", "nv",
}
;
const char *aarch64_disasm::_map_a64_dreg[] ={
	"d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8", "d9", "d10", "d11", "d12", "d13", "d14", "d15", "d16", "d17", "d18", "d19", "d20", "d21", "d22", "d23", "d24", "d25", "d26", "d27", "d28", "d29", "d30", "d31",
}
;
const char *aarch64_disasm::_map_a64_exttype32[] ={
	"uxtb", "uxth", "lsl", "uxtx", "sxtb", "sxth", "sxtw", "sxtx",
}
;
const char *aarch64_disasm::_map_a64_exttype64[] ={
	"uxtb", "uxth", "uxtw", "lsl", "sxtb", "sxth", "sxtw", "sxtx",
}
;
const char *aarch64_disasm::_map_a64_hreg[] ={
	"h0", "h1", "h2", "h3", "h4", "h5", "h6", "h7", "h8", "h9", "h10", "h11", "h12", "h13", "h14", "h15", "h16", "h17", "h18", "h19", "h20", "h21", "h22", "h23", "h24", "h25", "h26", "h27", "h28", "h29", "h30", "h31",
}
;
const char *aarch64_disasm::_map_a64_invcond[] ={
	"ne", "eq", "cc", "cs", "pl", "mi", "vc", "vs", "ls", "hi", "lt", "ge", "le", "gt", "nv", "al",
}
;
const char *aarch64_disasm::_map_a64_nzcvbits[] ={
	"", "v", "c", "cv", "z", "zv", "zc", "zcv", "n", "nv", "nc", "ncv", "nz", "nzv", "nzc", "nzcv",
}
;
const char *aarch64_disasm::_map_a64_qreg[] ={
	"q0", "q1", "q2", "q3", "q4", "q5", "q6", "q7", "q8", "q9", "q10", "q11", "q12", "q13", "q14", "q15", "q16", "q17", "q18", "q19", "q20", "q21", "q22", "q23", "q24", "q25", "q26", "q27", "q28", "q29", "q30", "q31",
}
;
const char *aarch64_disasm::_map_a64_regsw[] ={
	"w0", "w1", "w2", "w3", "w4", "w5", "w6", "w7", "w8", "w9", "w10", "w11", "w12", "w13", "w14", "w15", "w16", "w17", "w18", "w19", "w20", "w21", "w22", "w23", "w24", "w25", "w26", "w27", "w28", "w29", "w30", "wsp",
}
;
const char *aarch64_disasm::_map_a64_regsx[] ={
	"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30", "sp",
}
;
const char *aarch64_disasm::_map_a64_regw[] ={
	"w0", "w1", "w2", "w3", "w4", "w5", "w6", "w7", "w8", "w9", "w10", "w11", "w12", "w13", "w14", "w15", "w16", "w17", "w18", "w19", "w20", "w21", "w22", "w23", "w24", "w25", "w26", "w27", "w28", "w29", "w30", "wzr",
}
;
const char *aarch64_disasm::_map_a64_regx[] ={
	"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30", "xzr",
}
;
const char *aarch64_disasm::_map_a64_shifttype[] ={
	"lsl", "lsr", "asr", "ror",
}
;
const char *aarch64_disasm::_map_a64_sreg[] ={
	"s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "s12", "s13", "s14", "s15", "s16", "s17", "s18", "s19", "s20", "s21", "s22", "s23", "s24", "s25", "s26", "s27", "s28", "s29", "s30", "s31",
}
;
const char *aarch64_disasm::_map_a64_vreg[] ={
	"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31",
}
;

const char *aarch64_disasm::disassemble(uint64_t pc, const uint8_t *data)
{
	const aarch64_decode& insn = (const aarch64_decode&) *((const aarch64_decode*) data);
	clear();
	switch (insn.opcode) {
	case aarch64_decode::aarch64_a64_abs_simd:
		disassemble_a64_abs_simd(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_adc:
		disassemble_a64_adc(pc, (const aarch64_decode_a64_ADD_SUB_CARRY&) insn);
		break;
	case aarch64_decode::aarch64_a64_add_ereg:
		disassemble_a64_add_ereg(pc, (const aarch64_decode_a64_ADD_SUB_EREG&) insn);
		break;
	case aarch64_decode::aarch64_a64_add_sreg:
		disassemble_a64_add_sreg(pc, (const aarch64_decode_a64_ADD_SUB_SREG&) insn);
		break;
	case aarch64_decode::aarch64_a64_add_vector:
		disassemble_a64_add_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_addi:
		disassemble_a64_addi(pc, (const aarch64_decode_a64_ADD_SUB_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_addp_scalar:
		disassemble_a64_addp_scalar(pc, (const aarch64_decode_a64_SIMD_SCALAR_PW&) insn);
		break;
	case aarch64_decode::aarch64_a64_addp_vector:
		disassemble_a64_addp_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_addv:
		disassemble_a64_addv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_adr:
		disassemble_a64_adr(pc, (const aarch64_decode_a64_PC_REL&) insn);
		break;
	case aarch64_decode::aarch64_a64_and_vector:
		disassemble_a64_and_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_andi:
		disassemble_a64_andi(pc, (const aarch64_decode_a64_LOGICAL_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_andsr:
		disassemble_a64_andsr(pc, (const aarch64_decode_a64_LOGICAL_SR&) insn);
		break;
	case aarch64_decode::aarch64_a64_asrv:
		disassemble_a64_asrv(pc, (const aarch64_decode_a64_DP_2S&) insn);
		break;
	case aarch64_decode::aarch64_a64_b:
		disassemble_a64_b(pc, (const aarch64_decode_a64_UB_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_barrier:
		disassemble_a64_barrier(pc, (const aarch64_decode_a64_SYSTEM&) insn);
		break;
	case aarch64_decode::aarch64_a64_bcond:
		disassemble_a64_bcond(pc, (const aarch64_decode_a64_COND_B_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_bfm:
		disassemble_a64_bfm(pc, (const aarch64_decode_a64_BITFIELD&) insn);
		break;
	case aarch64_decode::aarch64_a64_bic_vector:
		disassemble_a64_bic_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_bici:
		disassemble_a64_bici(pc, (const aarch64_decode_a64_SIMD_MOD_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_bicsr:
		disassemble_a64_bicsr(pc, (const aarch64_decode_a64_LOGICAL_SR&) insn);
		break;
	case aarch64_decode::aarch64_a64_bif:
		disassemble_a64_bif(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_bit:
		disassemble_a64_bit(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_br:
		disassemble_a64_br(pc, (const aarch64_decode_a64_UB_REG&) insn);
		break;
	case aarch64_decode::aarch64_a64_bsl:
		disassemble_a64_bsl(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_cbz:
		disassemble_a64_cbz(pc, (const aarch64_decode_a64_CMP_B_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ccmni:
		disassemble_a64_ccmni(pc, (const aarch64_decode_a64_COND_CMP_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ccmnr:
		disassemble_a64_ccmnr(pc, (const aarch64_decode_a64_COND_CMP_REG&) insn);
		break;
	case aarch64_decode::aarch64_a64_ccmpi:
		disassemble_a64_ccmpi(pc, (const aarch64_decode_a64_COND_CMP_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ccmpr:
		disassemble_a64_ccmpr(pc, (const aarch64_decode_a64_COND_CMP_REG&) insn);
		break;
	case aarch64_decode::aarch64_a64_clrex:
		disassemble_a64_clrex(pc, (const aarch64_decode_a64_SYSTEM&) insn);
		break;
	case aarch64_decode::aarch64_a64_cls:
		disassemble_a64_cls(pc, (const aarch64_decode_a64_DP_1S&) insn);
		break;
	case aarch64_decode::aarch64_a64_clz:
		disassemble_a64_clz(pc, (const aarch64_decode_a64_DP_1S&) insn);
		break;
	case aarch64_decode::aarch64_a64_cmeq_reg:
		disassemble_a64_cmeq_reg(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_cmeq_zero:
		disassemble_a64_cmeq_zero(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_cmge_zero:
		disassemble_a64_cmge_zero(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_cmhi_reg:
		disassemble_a64_cmhi_reg(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_cmlt_zero:
		disassemble_a64_cmlt_zero(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_cmtst:
		disassemble_a64_cmtst(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_cnt:
		disassemble_a64_cnt(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_crc32:
		disassemble_a64_crc32(pc, (const aarch64_decode_a64_DP_2S&) insn);
		break;
	case aarch64_decode::aarch64_a64_crc32c:
		disassemble_a64_crc32c(pc, (const aarch64_decode_a64_DP_2S&) insn);
		break;
	case aarch64_decode::aarch64_a64_csel:
		disassemble_a64_csel(pc, (const aarch64_decode_a64_COND_SEL&) insn);
		break;
	case aarch64_decode::aarch64_a64_csinc:
		disassemble_a64_csinc(pc, (const aarch64_decode_a64_COND_SEL&) insn);
		break;
	case aarch64_decode::aarch64_a64_csinv:
		disassemble_a64_csinv(pc, (const aarch64_decode_a64_COND_SEL&) insn);
		break;
	case aarch64_decode::aarch64_a64_csneg:
		disassemble_a64_csneg(pc, (const aarch64_decode_a64_COND_SEL&) insn);
		break;
	case aarch64_decode::aarch64_a64_drps:
		disassemble_a64_drps(pc, (const aarch64_decode_a64_UB_REG&) insn);
		break;
	case aarch64_decode::aarch64_a64_dup_elem:
		disassemble_a64_dup_elem(pc, (const aarch64_decode_a64_SIMD_COPY&) insn);
		break;
	case aarch64_decode::aarch64_a64_dup_gen:
		disassemble_a64_dup_gen(pc, (const aarch64_decode_a64_SIMD_COPY&) insn);
		break;
	case aarch64_decode::aarch64_a64_eor_vector:
		disassemble_a64_eor_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_eori:
		disassemble_a64_eori(pc, (const aarch64_decode_a64_LOGICAL_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_eorsr:
		disassemble_a64_eorsr(pc, (const aarch64_decode_a64_LOGICAL_SR&) insn);
		break;
	case aarch64_decode::aarch64_a64_eret:
		disassemble_a64_eret(pc, (const aarch64_decode_a64_UB_REG&) insn);
		break;
	case aarch64_decode::aarch64_a64_exgen:
		disassemble_a64_exgen(pc, (const aarch64_decode_a64_EX_GEN&) insn);
		break;
	case aarch64_decode::aarch64_a64_ext:
		disassemble_a64_ext(pc, (const aarch64_decode_a64_SIMD_EXTRACT&) insn);
		break;
	case aarch64_decode::aarch64_a64_extr:
		disassemble_a64_extr(pc, (const aarch64_decode_a64_EXTRACT&) insn);
		break;
	case aarch64_decode::aarch64_a64_fabd:
		disassemble_a64_fabd(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_fabs:
		disassemble_a64_fabs(pc, (const aarch64_decode_a64_FP_DP_1&) insn);
		break;
	case aarch64_decode::aarch64_a64_fadd:
		disassemble_a64_fadd(pc, (const aarch64_decode_a64_FP_DP_2&) insn);
		break;
	case aarch64_decode::aarch64_a64_fccmpe:
		disassemble_a64_fccmpe(pc, (const aarch64_decode_a64_FP_CCMP&) insn);
		break;
	case aarch64_decode::aarch64_a64_fcmgt_zero:
		disassemble_a64_fcmgt_zero(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_fcmpe:
		disassemble_a64_fcmpe(pc, (const aarch64_decode_a64_FP_CMP&) insn);
		break;
	case aarch64_decode::aarch64_a64_fcsel:
		disassemble_a64_fcsel(pc, (const aarch64_decode_a64_FP_CSEL&) insn);
		break;
	case aarch64_decode::aarch64_a64_fcvt:
		disassemble_a64_fcvt(pc, (const aarch64_decode_a64_FP_DP_1&) insn);
		break;
	case aarch64_decode::aarch64_a64_fcvtas_simd:
		disassemble_a64_fcvtas_simd(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_fcvti:
		disassemble_a64_fcvti(pc, (const aarch64_decode_a64_CVT_FP_I&) insn);
		break;
	case aarch64_decode::aarch64_a64_fcvtz:
		disassemble_a64_fcvtz(pc, (const aarch64_decode_a64_CVT_FP_I&) insn);
		break;
	case aarch64_decode::aarch64_a64_fcvtz_fxp:
		disassemble_a64_fcvtz_fxp(pc, (const aarch64_decode_a64_CVT_FP_FXP&) insn);
		break;
	case aarch64_decode::aarch64_a64_fcvtzs_simd:
		disassemble_a64_fcvtzs_simd(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_fdiv:
		disassemble_a64_fdiv(pc, (const aarch64_decode_a64_FP_DP_2&) insn);
		break;
	case aarch64_decode::aarch64_a64_fm:
		disassemble_a64_fm(pc, (const aarch64_decode_a64_FP_DP_3&) insn);
		break;
	case aarch64_decode::aarch64_a64_fmaxnmv:
		disassemble_a64_fmaxnmv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_fmaxv:
		disassemble_a64_fmaxv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_fminnmv:
		disassemble_a64_fminnmv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_fminv:
		disassemble_a64_fminv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_fmov:
		disassemble_a64_fmov(pc, (const aarch64_decode_a64_FP_DP_1&) insn);
		break;
	case aarch64_decode::aarch64_a64_fmov_gen:
		disassemble_a64_fmov_gen(pc, (const aarch64_decode_a64_CVT_FP_I&) insn);
		break;
	case aarch64_decode::aarch64_a64_fmov_simd:
		disassemble_a64_fmov_simd(pc, (const aarch64_decode_a64_SIMD_MOD_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_fmovi:
		disassemble_a64_fmovi(pc, (const aarch64_decode_a64_FP_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_fmul:
		disassemble_a64_fmul(pc, (const aarch64_decode_a64_FP_DP_2&) insn);
		break;
	case aarch64_decode::aarch64_a64_fmul_vector:
		disassemble_a64_fmul_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_fneg:
		disassemble_a64_fneg(pc, (const aarch64_decode_a64_FP_DP_1&) insn);
		break;
	case aarch64_decode::aarch64_a64_fnm:
		disassemble_a64_fnm(pc, (const aarch64_decode_a64_FP_DP_3&) insn);
		break;
	case aarch64_decode::aarch64_a64_fnmul:
		disassemble_a64_fnmul(pc, (const aarch64_decode_a64_FP_DP_2&) insn);
		break;
	case aarch64_decode::aarch64_a64_frintx:
		disassemble_a64_frintx(pc, (const aarch64_decode_a64_FP_DP_1&) insn);
		break;
	case aarch64_decode::aarch64_a64_fsqrt:
		disassemble_a64_fsqrt(pc, (const aarch64_decode_a64_FP_DP_1&) insn);
		break;
	case aarch64_decode::aarch64_a64_fsub:
		disassemble_a64_fsub(pc, (const aarch64_decode_a64_FP_DP_2&) insn);
		break;
	case aarch64_decode::aarch64_a64_fsub_vector:
		disassemble_a64_fsub_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_hint:
		disassemble_a64_hint(pc, (const aarch64_decode_a64_SYSTEM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ins_elem:
		disassemble_a64_ins_elem(pc, (const aarch64_decode_a64_SIMD_COPY&) insn);
		break;
	case aarch64_decode::aarch64_a64_ins_gen:
		disassemble_a64_ins_gen(pc, (const aarch64_decode_a64_SIMD_COPY&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld1:
		disassemble_a64_ld1(pc, (const aarch64_decode_a64_SIMD_LS_MULT&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld1pi:
		disassemble_a64_ld1pi(pc, (const aarch64_decode_a64_SIMD_LS_MULT_PI&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld1r:
		disassemble_a64_ld1r(pc, (const aarch64_decode_a64_SIMD_LS_SINGLE&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld1s:
		disassemble_a64_ld1s(pc, (const aarch64_decode_a64_SIMD_LS_SINGLE&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld2:
		disassemble_a64_ld2(pc, (const aarch64_decode_a64_SIMD_LS_MULT&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld2pi:
		disassemble_a64_ld2pi(pc, (const aarch64_decode_a64_SIMD_LS_MULT_PI&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld3:
		disassemble_a64_ld3(pc, (const aarch64_decode_a64_SIMD_LS_MULT&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld3pi:
		disassemble_a64_ld3pi(pc, (const aarch64_decode_a64_SIMD_LS_MULT_PI&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld4:
		disassemble_a64_ld4(pc, (const aarch64_decode_a64_SIMD_LS_MULT&) insn);
		break;
	case aarch64_decode::aarch64_a64_ld4pi:
		disassemble_a64_ld4pi(pc, (const aarch64_decode_a64_SIMD_LS_MULT_PI&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldar:
		disassemble_a64_ldar(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldarb:
		disassemble_a64_ldarb(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldarh:
		disassemble_a64_ldarh(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldaxp:
		disassemble_a64_ldaxp(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldaxr:
		disassemble_a64_ldaxr(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldaxrb:
		disassemble_a64_ldaxrb(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldaxrh:
		disassemble_a64_ldaxrh(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldnp:
		disassemble_a64_ldnp(pc, (const aarch64_decode_a64_LS_NO_ALLOC&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldp:
		disassemble_a64_ldp(pc, (const aarch64_decode_a64_LS_REG_PAIR_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldp_simd:
		disassemble_a64_ldp_simd(pc, (const aarch64_decode_a64_LS_REG_PAIR_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldpi:
		disassemble_a64_ldpi(pc, (const aarch64_decode_a64_LS_REG_PAIR_IDX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldpi_simd:
		disassemble_a64_ldpi_simd(pc, (const aarch64_decode_a64_LS_REG_PAIR_IDX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldpsw:
		disassemble_a64_ldpsw(pc, (const aarch64_decode_a64_LS_REG_PAIR_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldpswi:
		disassemble_a64_ldpswi(pc, (const aarch64_decode_a64_LS_REG_PAIR_IDX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldr:
		disassemble_a64_ldr(pc, (const aarch64_decode_a64_LS_REG_IMM_POST&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldr_lit:
		disassemble_a64_ldr_lit(pc, (const aarch64_decode_a64_LOAD_REG_LIT&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldr_lit_simd:
		disassemble_a64_ldr_lit_simd(pc, (const aarch64_decode_a64_LOAD_REG_LIT&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldr_reg:
		disassemble_a64_ldr_reg(pc, (const aarch64_decode_a64_LS_REG_REG_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldr_reg_simd:
		disassemble_a64_ldr_reg_simd(pc, (const aarch64_decode_a64_LS_REG_REG_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldrb:
		disassemble_a64_ldrb(pc, (const aarch64_decode_a64_LS_REG_IMM_POST&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldrb_reg:
		disassemble_a64_ldrb_reg(pc, (const aarch64_decode_a64_LS_REG_REG_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldrbi:
		disassemble_a64_ldrbi(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldrh:
		disassemble_a64_ldrh(pc, (const aarch64_decode_a64_LS_REG_IMM_POST&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldrh_reg:
		disassemble_a64_ldrh_reg(pc, (const aarch64_decode_a64_LS_REG_REG_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldrhi:
		disassemble_a64_ldrhi(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldri:
		disassemble_a64_ldri(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldrsw:
		disassemble_a64_ldrsw(pc, (const aarch64_decode_a64_LS_REG_IMM_POST&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldrsw_lit:
		disassemble_a64_ldrsw_lit(pc, (const aarch64_decode_a64_LOAD_REG_LIT&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldrswi:
		disassemble_a64_ldrswi(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldtr:
		disassemble_a64_ldtr(pc, (const aarch64_decode_a64_LS_REG_UNPRIV&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldtrb:
		disassemble_a64_ldtrb(pc, (const aarch64_decode_a64_LS_REG_UNPRIV&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldtrh:
		disassemble_a64_ldtrh(pc, (const aarch64_decode_a64_LS_REG_UNPRIV&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldtrsw:
		disassemble_a64_ldtrsw(pc, (const aarch64_decode_a64_LS_REG_UNPRIV&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldur:
		disassemble_a64_ldur(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldurb:
		disassemble_a64_ldurb(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldurh:
		disassemble_a64_ldurh(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldursw:
		disassemble_a64_ldursw(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldxp:
		disassemble_a64_ldxp(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldxr:
		disassemble_a64_ldxr(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldxrb:
		disassemble_a64_ldxrb(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_ldxrh:
		disassemble_a64_ldxrh(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_lslv:
		disassemble_a64_lslv(pc, (const aarch64_decode_a64_DP_2S&) insn);
		break;
	case aarch64_decode::aarch64_a64_lsrv:
		disassemble_a64_lsrv(pc, (const aarch64_decode_a64_DP_2S&) insn);
		break;
	case aarch64_decode::aarch64_a64_madd:
		disassemble_a64_madd(pc, (const aarch64_decode_a64_DP_3S&) insn);
		break;
	case aarch64_decode::aarch64_a64_mla_vector:
		disassemble_a64_mla_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_mov:
		disassemble_a64_mov(pc, (const aarch64_decode_a64_LOGICAL_SR&) insn);
		break;
	case aarch64_decode::aarch64_a64_movi:
		disassemble_a64_movi(pc, (const aarch64_decode_a64_SIMD_MOD_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_movk:
		disassemble_a64_movk(pc, (const aarch64_decode_a64_MOVE_WIDE_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_movn:
		disassemble_a64_movn(pc, (const aarch64_decode_a64_MOVE_WIDE_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_movz:
		disassemble_a64_movz(pc, (const aarch64_decode_a64_MOVE_WIDE_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_mrs:
		disassemble_a64_mrs(pc, (const aarch64_decode_a64_SYSTEM&) insn);
		break;
	case aarch64_decode::aarch64_a64_msr_imm:
		disassemble_a64_msr_imm(pc, (const aarch64_decode_a64_SYSTEM&) insn);
		break;
	case aarch64_decode::aarch64_a64_msr_reg:
		disassemble_a64_msr_reg(pc, (const aarch64_decode_a64_SYSTEM&) insn);
		break;
	case aarch64_decode::aarch64_a64_msr_sctlr:
		disassemble_a64_msr_sctlr(pc, (const aarch64_decode_a64_SYSTEM&) insn);
		break;
	case aarch64_decode::aarch64_a64_msub:
		disassemble_a64_msub(pc, (const aarch64_decode_a64_DP_3S&) insn);
		break;
	case aarch64_decode::aarch64_a64_mul_idx_vector:
		disassemble_a64_mul_idx_vector(pc, (const aarch64_decode_a64_SIMD_VECTOR_IDX&) insn);
		break;
	case aarch64_decode::aarch64_a64_mul_vector:
		disassemble_a64_mul_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_mvni:
		disassemble_a64_mvni(pc, (const aarch64_decode_a64_SIMD_MOD_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_neg_simd:
		disassemble_a64_neg_simd(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_not_simd:
		disassemble_a64_not_simd(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_orn_vector:
		disassemble_a64_orn_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_orr_vector:
		disassemble_a64_orr_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_orri:
		disassemble_a64_orri(pc, (const aarch64_decode_a64_LOGICAL_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_orrsr:
		disassemble_a64_orrsr(pc, (const aarch64_decode_a64_LOGICAL_SR&) insn);
		break;
	case aarch64_decode::aarch64_a64_pmull:
		disassemble_a64_pmull(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_prfm:
		disassemble_a64_prfm(pc, (const aarch64_decode_a64_LS_REG_IMM_POST&) insn);
		break;
	case aarch64_decode::aarch64_a64_prfm_lit:
		disassemble_a64_prfm_lit(pc, (const aarch64_decode_a64_LOAD_REG_LIT&) insn);
		break;
	case aarch64_decode::aarch64_a64_prfm_reg:
		disassemble_a64_prfm_reg(pc, (const aarch64_decode_a64_LS_REG_REG_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_prfmi:
		disassemble_a64_prfmi(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_prfum:
		disassemble_a64_prfum(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_rbit:
		disassemble_a64_rbit(pc, (const aarch64_decode_a64_DP_1S&) insn);
		break;
	case aarch64_decode::aarch64_a64_ret:
		disassemble_a64_ret(pc, (const aarch64_decode_a64_UB_REG&) insn);
		break;
	case aarch64_decode::aarch64_a64_rev:
		disassemble_a64_rev(pc, (const aarch64_decode_a64_DP_1S&) insn);
		break;
	case aarch64_decode::aarch64_a64_rev16:
		disassemble_a64_rev16(pc, (const aarch64_decode_a64_DP_1S&) insn);
		break;
	case aarch64_decode::aarch64_a64_rev32:
		disassemble_a64_rev32(pc, (const aarch64_decode_a64_DP_1S&) insn);
		break;
	case aarch64_decode::aarch64_a64_rev32_simd:
		disassemble_a64_rev32_simd(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_rev64_simd:
		disassemble_a64_rev64_simd(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_rorv:
		disassemble_a64_rorv(pc, (const aarch64_decode_a64_DP_2S&) insn);
		break;
	case aarch64_decode::aarch64_a64_saddl:
		disassemble_a64_saddl(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_saddlv:
		disassemble_a64_saddlv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_saddw:
		disassemble_a64_saddw(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_sbc:
		disassemble_a64_sbc(pc, (const aarch64_decode_a64_ADD_SUB_CARRY&) insn);
		break;
	case aarch64_decode::aarch64_a64_sbfm:
		disassemble_a64_sbfm(pc, (const aarch64_decode_a64_BITFIELD&) insn);
		break;
	case aarch64_decode::aarch64_a64_scvtf:
		disassemble_a64_scvtf(pc, (const aarch64_decode_a64_CVT_FP_I&) insn);
		break;
	case aarch64_decode::aarch64_a64_scvtf_simd:
		disassemble_a64_scvtf_simd(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_sdiv:
		disassemble_a64_sdiv(pc, (const aarch64_decode_a64_DP_2S&) insn);
		break;
	case aarch64_decode::aarch64_a64_shl_simd:
		disassemble_a64_shl_simd(pc, (const aarch64_decode_a64_SIMD_SHIFT_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_shll:
		disassemble_a64_shll(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_smaddl:
		disassemble_a64_smaddl(pc, (const aarch64_decode_a64_DP_3S&) insn);
		break;
	case aarch64_decode::aarch64_a64_smax:
		disassemble_a64_smax(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_smaxv:
		disassemble_a64_smaxv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_smin:
		disassemble_a64_smin(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_sminv:
		disassemble_a64_sminv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_smov:
		disassemble_a64_smov(pc, (const aarch64_decode_a64_SIMD_COPY&) insn);
		break;
	case aarch64_decode::aarch64_a64_smsubl:
		disassemble_a64_smsubl(pc, (const aarch64_decode_a64_DP_3S&) insn);
		break;
	case aarch64_decode::aarch64_a64_smulh:
		disassemble_a64_smulh(pc, (const aarch64_decode_a64_DP_3S&) insn);
		break;
	case aarch64_decode::aarch64_a64_smull:
		disassemble_a64_smull(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_sshl:
		disassemble_a64_sshl(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_sshll:
		disassemble_a64_sshll(pc, (const aarch64_decode_a64_SIMD_SHIFT_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_sshr:
		disassemble_a64_sshr(pc, (const aarch64_decode_a64_SIMD_SHIFT_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ssubl:
		disassemble_a64_ssubl(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ssubw:
		disassemble_a64_ssubw(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_st1:
		disassemble_a64_st1(pc, (const aarch64_decode_a64_SIMD_LS_MULT&) insn);
		break;
	case aarch64_decode::aarch64_a64_st1pi:
		disassemble_a64_st1pi(pc, (const aarch64_decode_a64_SIMD_LS_MULT_PI&) insn);
		break;
	case aarch64_decode::aarch64_a64_st1s:
		disassemble_a64_st1s(pc, (const aarch64_decode_a64_SIMD_LS_SINGLE&) insn);
		break;
	case aarch64_decode::aarch64_a64_st1spi:
		disassemble_a64_st1spi(pc, (const aarch64_decode_a64_SIMD_LS_SINGLE_PI&) insn);
		break;
	case aarch64_decode::aarch64_a64_st2:
		disassemble_a64_st2(pc, (const aarch64_decode_a64_SIMD_LS_MULT&) insn);
		break;
	case aarch64_decode::aarch64_a64_st2pi:
		disassemble_a64_st2pi(pc, (const aarch64_decode_a64_SIMD_LS_MULT_PI&) insn);
		break;
	case aarch64_decode::aarch64_a64_st3:
		disassemble_a64_st3(pc, (const aarch64_decode_a64_SIMD_LS_MULT&) insn);
		break;
	case aarch64_decode::aarch64_a64_st3pi:
		disassemble_a64_st3pi(pc, (const aarch64_decode_a64_SIMD_LS_MULT_PI&) insn);
		break;
	case aarch64_decode::aarch64_a64_st4:
		disassemble_a64_st4(pc, (const aarch64_decode_a64_SIMD_LS_MULT&) insn);
		break;
	case aarch64_decode::aarch64_a64_st4pi:
		disassemble_a64_st4pi(pc, (const aarch64_decode_a64_SIMD_LS_MULT_PI&) insn);
		break;
	case aarch64_decode::aarch64_a64_stlr:
		disassemble_a64_stlr(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stlrb:
		disassemble_a64_stlrb(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stlrh:
		disassemble_a64_stlrh(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stlxp:
		disassemble_a64_stlxp(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stlxr:
		disassemble_a64_stlxr(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stlxrb:
		disassemble_a64_stlxrb(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stlxrh:
		disassemble_a64_stlxrh(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stnp:
		disassemble_a64_stnp(pc, (const aarch64_decode_a64_LS_NO_ALLOC&) insn);
		break;
	case aarch64_decode::aarch64_a64_stp:
		disassemble_a64_stp(pc, (const aarch64_decode_a64_LS_REG_PAIR_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_stp_simd:
		disassemble_a64_stp_simd(pc, (const aarch64_decode_a64_LS_REG_PAIR_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_stpi:
		disassemble_a64_stpi(pc, (const aarch64_decode_a64_LS_REG_PAIR_IDX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stpi_simd:
		disassemble_a64_stpi_simd(pc, (const aarch64_decode_a64_LS_REG_PAIR_IDX&) insn);
		break;
	case aarch64_decode::aarch64_a64_str:
		disassemble_a64_str(pc, (const aarch64_decode_a64_LS_REG_IMM_POST&) insn);
		break;
	case aarch64_decode::aarch64_a64_str_reg:
		disassemble_a64_str_reg(pc, (const aarch64_decode_a64_LS_REG_REG_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_str_reg_simd:
		disassemble_a64_str_reg_simd(pc, (const aarch64_decode_a64_LS_REG_REG_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_strb:
		disassemble_a64_strb(pc, (const aarch64_decode_a64_LS_REG_IMM_POST&) insn);
		break;
	case aarch64_decode::aarch64_a64_strb_reg:
		disassemble_a64_strb_reg(pc, (const aarch64_decode_a64_LS_REG_REG_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_strbi:
		disassemble_a64_strbi(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_strh:
		disassemble_a64_strh(pc, (const aarch64_decode_a64_LS_REG_IMM_POST&) insn);
		break;
	case aarch64_decode::aarch64_a64_strh_reg:
		disassemble_a64_strh_reg(pc, (const aarch64_decode_a64_LS_REG_REG_OFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_strhi:
		disassemble_a64_strhi(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_stri:
		disassemble_a64_stri(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_sttr:
		disassemble_a64_sttr(pc, (const aarch64_decode_a64_LS_REG_UNPRIV&) insn);
		break;
	case aarch64_decode::aarch64_a64_sttrb:
		disassemble_a64_sttrb(pc, (const aarch64_decode_a64_LS_REG_UNPRIV&) insn);
		break;
	case aarch64_decode::aarch64_a64_sttrh:
		disassemble_a64_sttrh(pc, (const aarch64_decode_a64_LS_REG_UNPRIV&) insn);
		break;
	case aarch64_decode::aarch64_a64_stur:
		disassemble_a64_stur(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_sturb:
		disassemble_a64_sturb(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_sturh:
		disassemble_a64_sturh(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_stxp:
		disassemble_a64_stxp(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stxr:
		disassemble_a64_stxr(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stxrb:
		disassemble_a64_stxrb(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_stxrh:
		disassemble_a64_stxrh(pc, (const aarch64_decode_a64_LS_EX&) insn);
		break;
	case aarch64_decode::aarch64_a64_sub_ereg:
		disassemble_a64_sub_ereg(pc, (const aarch64_decode_a64_ADD_SUB_EREG&) insn);
		break;
	case aarch64_decode::aarch64_a64_sub_sreg:
		disassemble_a64_sub_sreg(pc, (const aarch64_decode_a64_ADD_SUB_SREG&) insn);
		break;
	case aarch64_decode::aarch64_a64_sub_vector:
		disassemble_a64_sub_vector(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_subi:
		disassemble_a64_subi(pc, (const aarch64_decode_a64_ADD_SUB_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_sys:
		disassemble_a64_sys(pc, (const aarch64_decode_a64_SYSTEM&) insn);
		break;
	case aarch64_decode::aarch64_a64_tbl:
		disassemble_a64_tbl(pc, (const aarch64_decode_a64_SIMD_TABLE_LOOKUP&) insn);
		break;
	case aarch64_decode::aarch64_a64_tbx:
		disassemble_a64_tbx(pc, (const aarch64_decode_a64_SIMD_TABLE_LOOKUP&) insn);
		break;
	case aarch64_decode::aarch64_a64_tbz:
		disassemble_a64_tbz(pc, (const aarch64_decode_a64_TEST_B_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_uadalp:
		disassemble_a64_uadalp(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_uaddl:
		disassemble_a64_uaddl(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_uaddlp:
		disassemble_a64_uaddlp(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_uaddlv:
		disassemble_a64_uaddlv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_uaddw:
		disassemble_a64_uaddw(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ubfm:
		disassemble_a64_ubfm(pc, (const aarch64_decode_a64_BITFIELD&) insn);
		break;
	case aarch64_decode::aarch64_a64_ucvtf:
		disassemble_a64_ucvtf(pc, (const aarch64_decode_a64_CVT_FP_I&) insn);
		break;
	case aarch64_decode::aarch64_a64_ucvtf_simd:
		disassemble_a64_ucvtf_simd(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	case aarch64_decode::aarch64_a64_udiv:
		disassemble_a64_udiv(pc, (const aarch64_decode_a64_DP_2S&) insn);
		break;
	case aarch64_decode::aarch64_a64_umaddl:
		disassemble_a64_umaddl(pc, (const aarch64_decode_a64_DP_3S&) insn);
		break;
	case aarch64_decode::aarch64_a64_umaxv:
		disassemble_a64_umaxv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_uminv:
		disassemble_a64_uminv(pc, (const aarch64_decode_a64_SIMD_ACROSS_LANES&) insn);
		break;
	case aarch64_decode::aarch64_a64_umov:
		disassemble_a64_umov(pc, (const aarch64_decode_a64_SIMD_COPY&) insn);
		break;
	case aarch64_decode::aarch64_a64_umsubl:
		disassemble_a64_umsubl(pc, (const aarch64_decode_a64_DP_3S&) insn);
		break;
	case aarch64_decode::aarch64_a64_umulh:
		disassemble_a64_umulh(pc, (const aarch64_decode_a64_DP_3S&) insn);
		break;
	case aarch64_decode::aarch64_a64_umull:
		disassemble_a64_umull(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_ushl:
		disassemble_a64_ushl(pc, (const aarch64_decode_a64_SIMD_THREE_SAME&) insn);
		break;
	case aarch64_decode::aarch64_a64_ushll:
		disassemble_a64_ushll(pc, (const aarch64_decode_a64_SIMD_SHIFT_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_ushr:
		disassemble_a64_ushr(pc, (const aarch64_decode_a64_SIMD_SHIFT_IMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_usubl:
		disassemble_a64_usubl(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_usubw:
		disassemble_a64_usubw(pc, (const aarch64_decode_a64_SIMD_THREE_DIFF&) insn);
		break;
	case aarch64_decode::aarch64_a64_uzp1:
		disassemble_a64_uzp1(pc, (const aarch64_decode_a64_SIMD_PERMUTE&) insn);
		break;
	case aarch64_decode::aarch64_a64_uzp2:
		disassemble_a64_uzp2(pc, (const aarch64_decode_a64_SIMD_PERMUTE&) insn);
		break;
	case aarch64_decode::aarch64_a64_vldr:
		disassemble_a64_vldr(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_vldur:
		disassemble_a64_vldur(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_vstr:
		disassemble_a64_vstr(pc, (const aarch64_decode_a64_LS_REG_UIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_vstur:
		disassemble_a64_vstur(pc, (const aarch64_decode_a64_LS_REG_USIMM&) insn);
		break;
	case aarch64_decode::aarch64_a64_xtn:
		disassemble_a64_xtn(pc, (const aarch64_decode_a64_SIMD_TWO_REG_MISC&) insn);
		break;
	default: append_str("???");
		break;
	}
	return buffer();
}

void aarch64_disasm::disassemble_a64_abs_simd(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	append_str("abs_simd");
}

void aarch64_disasm::disassemble_a64_adc(uint64_t pc, const aarch64_decode_a64_ADD_SUB_CARRY& insn)
{
	uint32_t map_val = 0;
	append_str("adc");
}

void aarch64_disasm::disassemble_a64_add_ereg(uint64_t pc, const aarch64_decode_a64_ADD_SUB_EREG& insn)
{
	uint32_t map_val = 0;
	if ((insn.S == (1)) && (insn.option == (7)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (3)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (6)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (5)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (4)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (2)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (1)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (0)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (7)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (3)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (6)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (5)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (4)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (2)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (1)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (0)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (0))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (0))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_add_sreg(uint64_t pc, const aarch64_decode_a64_ADD_SUB_SREG& insn)
{
	uint32_t map_val = 0;
	if ((insn.S == (1)) && (insn.imm6 == (0)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (1)) && (insn.imm6 == (0)) && (insn.sf == (0))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (0)) && (insn.imm6 == (0)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (0)) && (insn.imm6 == (0)) && (insn.sf == (0))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (0))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (0))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_add_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (0))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_addi(uint64_t pc, const aarch64_decode_a64_ADD_SUB_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.S == (1)) && (insn.sf == (1))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (0))) {
		append_str("adds");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (1))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (0))) {
		append_str("add");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_addp_scalar(uint64_t pc, const aarch64_decode_a64_SIMD_SCALAR_PW& insn)
{
	uint32_t map_val = 0;
	append_str("addp");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_dreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	append_str("2");
	append_str("d");
	return;
}

void aarch64_disasm::disassemble_a64_addp_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("addp");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_addv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (2))) {
		append_str("addv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.size == (1))) {
		append_str("addv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_hreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.size == (0))) {
		append_str("addv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_breg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_adr(uint64_t pc, const aarch64_decode_a64_PC_REL& insn)
{
	uint32_t map_val = 0;
	if ((insn.op == (1))) {
		append_str("adrp");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
	if ((insn.op == (0))) {
		append_str("adr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
}

void aarch64_disasm::disassemble_a64_and_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("and");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		return;
	}
	if ((insn.Q == (0))) {
		append_str("and");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		return;
	}
}

void aarch64_disasm::disassemble_a64_andi(uint64_t pc, const aarch64_decode_a64_LOGICAL_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.N == (0)) && (insn.opc == (3)) && (insn.rd == (31)) && (insn.sf == (0))) {
		append_str("tst");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint32_t) ((insn.immu32)));
		return;
	}
	if ((insn.opc == (3)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("tst");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint64_t) ((insn.immu64)));
		return;
	}
	if ((insn.N == (0)) && (insn.opc == (3)) && (insn.sf == (0))) {
		append_str("ands");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint32_t) ((insn.immu32)));
		return;
	}
	if ((insn.opc == (3)) && (insn.sf == (1))) {
		append_str("ands");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint64_t) ((insn.immu64)));
		return;
	}
	if ((insn.N == (0)) && (insn.sf == (0))) {
		append_str("and");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint32_t) ((insn.immu32)));
		return;
	}
	if ((insn.sf == (1))) {
		append_str("and");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint64_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_andsr(uint64_t pc, const aarch64_decode_a64_LOGICAL_SR& insn)
{
	uint32_t map_val = 0;
	if ((insn.imm6 == (0)) && (insn.opc == (3)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("tst");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.imm6 == (0)) && (insn.opc == (3)) && (insn.rd == (31)) && (insn.sf == (0))) {
		append_str("tst");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opc == (3)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("tst");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.opc == (3)) && (insn.rd == (31)) && (insn.sf == (0))) {
		append_str("tst");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.imm6 == (0)) && (insn.opc == (3)) && (insn.sf == (1))) {
		append_str("ands");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.imm6 == (0)) && (insn.opc == (3)) && (insn.sf == (0))) {
		append_str("ands");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.imm6 == (0)) && (insn.opc == (0)) && (insn.sf == (1))) {
		append_str("and");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.imm6 == (0)) && (insn.opc == (0)) && (insn.sf == (0))) {
		append_str("and");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opc == (3)) && (insn.sf == (1))) {
		append_str("ands");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.opc == (3)) && (insn.sf == (0))) {
		append_str("ands");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.opc == (0)) && (insn.sf == (1))) {
		append_str("and");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.opc == (0)) && (insn.sf == (0))) {
		append_str("and");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_asrv(uint64_t pc, const aarch64_decode_a64_DP_2S& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("asrv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("asrv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_b(uint64_t pc, const aarch64_decode_a64_UB_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.op == (1))) {
		append_str("bl");
		append_str(" ");
		append_str("#");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
	if ((insn.op == (0))) {
		append_str("b");
		append_str(" ");
		append_str("#");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
}

void aarch64_disasm::disassemble_a64_barrier(uint64_t pc, const aarch64_decode_a64_SYSTEM& insn)
{
	uint32_t map_val = 0;
	if ((insn.op2 == (6))) {
		append_str("isb");
		return;
	}
	if ((insn.op2 == (5))) {
		append_str("dmb");
		return;
	}
	if ((insn.op2 == (4))) {
		append_str("dsb");
		return;
	}
}

void aarch64_disasm::disassemble_a64_bcond(uint64_t pc, const aarch64_decode_a64_COND_B_IMM& insn)
{
	uint32_t map_val = 0;
	append_str("b");
	append_str(".");
	map_val = 0 + (insn.cond);
	if (map_val < 16) {
		append_str(_map_a64_cond[map_val]);
	} else {
		append_str("???");
	}
	append_str(" ");
	append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
	return;
}

void aarch64_disasm::disassemble_a64_bfm(uint64_t pc, const aarch64_decode_a64_BITFIELD& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("bfm");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immr)));
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms)));
		return;
	}
	if ((insn.sf == (0))) {
		append_str("bfm");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immr)));
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_bic_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("bic");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		return;
	}
	if ((insn.Q == (0))) {
		append_str("bic");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		return;
	}
}

void aarch64_disasm::disassemble_a64_bici(uint64_t pc, const aarch64_decode_a64_SIMD_MOD_IMM& insn)
{
	uint32_t map_val = 0;
	append_str("bici");
}

void aarch64_disasm::disassemble_a64_bicsr(uint64_t pc, const aarch64_decode_a64_LOGICAL_SR& insn)
{
	uint32_t map_val = 0;
	if ((insn.imm6 == (0)) && (insn.opc == (3)) && (insn.sf == (1))) {
		append_str("bics");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.imm6 == (0)) && (insn.opc == (3)) && (insn.sf == (0))) {
		append_str("bics");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.imm6 == (0)) && (insn.opc == (0)) && (insn.sf == (1))) {
		append_str("bic");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.imm6 == (0)) && (insn.opc == (0)) && (insn.sf == (0))) {
		append_str("bic");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opc == (3)) && (insn.sf == (1))) {
		append_str("bics");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.opc == (3)) && (insn.sf == (0))) {
		append_str("bics");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.opc == (0)) && (insn.sf == (1))) {
		append_str("bic");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.opc == (0)) && (insn.sf == (0))) {
		append_str("bic");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_bif(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("bif");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_bit(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("bit");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_br(uint64_t pc, const aarch64_decode_a64_UB_REG& insn)
{
	uint32_t map_val = 0;
	if ((insn.opc == (1))) {
		append_str("blr");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opc == (0))) {
		append_str("br");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_bsl(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("bsl");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_cbz(uint64_t pc, const aarch64_decode_a64_CMP_B_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.op == (1)) && (insn.sf == (1))) {
		append_str("cbnz");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
	if ((insn.op == (0)) && (insn.sf == (1))) {
		append_str("cbz");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
	if ((insn.op == (1)) && (insn.sf == (0))) {
		append_str("cbnz");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
	if ((insn.op == (0)) && (insn.sf == (0))) {
		append_str("cbz");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ccmni(uint64_t pc, const aarch64_decode_a64_COND_CMP_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("ccmn");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm5)));
		append_str(",");
		append_str(" ");
		append_str("#");
		map_val = 0 + (insn.nzcv);
		if (map_val < 16) {
			append_str(_map_a64_nzcvbits[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("ccmn");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm5)));
		append_str(",");
		append_str(" ");
		append_str("#");
		map_val = 0 + (insn.nzcv);
		if (map_val < 16) {
			append_str(_map_a64_nzcvbits[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_ccmnr(uint64_t pc, const aarch64_decode_a64_COND_CMP_REG& insn)
{
	uint32_t map_val = 0;
	append_str("ccmn");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("#");
	map_val = 0 + (insn.nzcv);
	if (map_val < 16) {
		append_str(_map_a64_nzcvbits[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.cond);
	if (map_val < 16) {
		append_str(_map_a64_cond[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_ccmpi(uint64_t pc, const aarch64_decode_a64_COND_CMP_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("ccmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm5)));
		append_str(",");
		append_str(" ");
		append_str("#");
		map_val = 0 + (insn.nzcv);
		if (map_val < 16) {
			append_str(_map_a64_nzcvbits[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("ccmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm5)));
		append_str(",");
		append_str(" ");
		append_str("#");
		map_val = 0 + (insn.nzcv);
		if (map_val < 16) {
			append_str(_map_a64_nzcvbits[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_ccmpr(uint64_t pc, const aarch64_decode_a64_COND_CMP_REG& insn)
{
	uint32_t map_val = 0;
	append_str("ccmp");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("#");
	map_val = 0 + (insn.nzcv);
	if (map_val < 16) {
		append_str(_map_a64_nzcvbits[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.cond);
	if (map_val < 16) {
		append_str(_map_a64_cond[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_clrex(uint64_t pc, const aarch64_decode_a64_SYSTEM& insn)
{
	uint32_t map_val = 0;
	append_str("clrex");
	return;
}

void aarch64_disasm::disassemble_a64_cls(uint64_t pc, const aarch64_decode_a64_DP_1S& insn)
{
	uint32_t map_val = 0;
	append_str("cls");
}

void aarch64_disasm::disassemble_a64_clz(uint64_t pc, const aarch64_decode_a64_DP_1S& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("clz");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("clz");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_cmeq_reg(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.size == (3))) {
		append_str("cmeq");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (0))) {
		append_str("cmeq");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_cmeq_zero(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.size == (3))) {
		append_str("cmeq");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
	if ((insn.SCALAR == (0))) {
		append_str("cmeq");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
}

void aarch64_disasm::disassemble_a64_cmge_zero(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.U == (0)) && (insn.size == (3))) {
		append_str("cmgt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.U == (1)) && (insn.size == (3))) {
		append_str("cmge");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
	if ((insn.SCALAR == (0)) && (insn.U == (0))) {
		append_str("cmgt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
	if ((insn.SCALAR == (0)) && (insn.U == (1))) {
		append_str("cmge");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
}

void aarch64_disasm::disassemble_a64_cmhi_reg(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.size == (3))) {
		append_str("cmhi");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (0))) {
		append_str("cmhi");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_cmlt_zero(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.U == (0)) && (insn.size == (3))) {
		append_str("cmlt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.U == (1)) && (insn.size == (3))) {
		append_str("cmle");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
	if ((insn.SCALAR == (0)) && (insn.U == (0))) {
		append_str("cmlt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
	if ((insn.SCALAR == (0)) && (insn.U == (1))) {
		append_str("cmle");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
}

void aarch64_disasm::disassemble_a64_cmtst(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.size == (3))) {
		append_str("cmtst");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (0))) {
		append_str("cmtst");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_cnt(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (0))) {
		append_str("cnt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_crc32(uint64_t pc, const aarch64_decode_a64_DP_2S& insn)
{
	uint32_t map_val = 0;
	append_str("crc32");
}

void aarch64_disasm::disassemble_a64_crc32c(uint64_t pc, const aarch64_decode_a64_DP_2S& insn)
{
	uint32_t map_val = 0;
	append_str("crc32c");
}

void aarch64_disasm::disassemble_a64_csel(uint64_t pc, const aarch64_decode_a64_COND_SEL& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("csel");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("csel");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_csinc(uint64_t pc, const aarch64_decode_a64_COND_SEL& insn)
{
	uint32_t map_val = 0;
	if ((insn.rm == (31)) && (insn.rn == (31)) && (insn.sf == (1))) {
		append_str("cset");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_invcond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.rm == (31)) && (insn.rn == (31)) && (insn.sf == (0))) {
		append_str("cset");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_invcond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (1))) {
		append_str("csinc");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("csinc");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_csinv(uint64_t pc, const aarch64_decode_a64_COND_SEL& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("csinv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("csinv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_csneg(uint64_t pc, const aarch64_decode_a64_COND_SEL& insn)
{
	uint32_t map_val = 0;
	append_str("csneg");
}

void aarch64_disasm::disassemble_a64_drps(uint64_t pc, const aarch64_decode_a64_UB_REG& insn)
{
	uint32_t map_val = 0;
	append_str("drps");
}

void aarch64_disasm::disassemble_a64_dup_elem(uint64_t pc, const aarch64_decode_a64_SIMD_COPY& insn)
{
	uint32_t map_val = 0;
	append_str("dup_elem");
}

void aarch64_disasm::disassemble_a64_dup_gen(uint64_t pc, const aarch64_decode_a64_SIMD_COPY& insn)
{
	uint32_t map_val = 0;
	if ((insn.width == (64))) {
		append_str("dup");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.width == (32))) {
		append_str("dup");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_eor_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("eor");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		return;
	}
	if ((insn.Q == (0))) {
		append_str("eor");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		return;
	}
}

void aarch64_disasm::disassemble_a64_eori(uint64_t pc, const aarch64_decode_a64_LOGICAL_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.N == (0)) && (insn.sf == (0))) {
		append_str("eor");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint32_t) ((insn.immu32)));
		return;
	}
	if ((insn.sf == (1))) {
		append_str("eor");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint64_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_eorsr(uint64_t pc, const aarch64_decode_a64_LOGICAL_SR& insn)
{
	uint32_t map_val = 0;
	if ((insn.N == (1)) && (insn.imm6 == (0)) && (insn.sf == (1))) {
		append_str("eon");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (1)) && (insn.imm6 == (0)) && (insn.sf == (0))) {
		append_str("eon");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (0)) && (insn.imm6 == (0)) && (insn.sf == (1))) {
		append_str("eor");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (0)) && (insn.imm6 == (0)) && (insn.sf == (0))) {
		append_str("eor");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (1)) && (insn.sf == (1))) {
		append_str("eon");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.N == (1)) && (insn.sf == (0))) {
		append_str("eon");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.N == (0)) && (insn.sf == (1))) {
		append_str("eor");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.N == (0)) && (insn.sf == (0))) {
		append_str("eor");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_eret(uint64_t pc, const aarch64_decode_a64_UB_REG& insn)
{
	uint32_t map_val = 0;
	append_str("eret");
	return;
}

void aarch64_disasm::disassemble_a64_exgen(uint64_t pc, const aarch64_decode_a64_EX_GEN& insn)
{
	uint32_t map_val = 0;
	if ((insn.ll == (3)) && (insn.opc == (0))) {
		append_str("smc");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.ll == (2)) && (insn.opc == (0))) {
		append_str("hvc");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.ll == (1)) && (insn.opc == (0))) {
		append_str("svc");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.opc == (2))) {
		append_str("hlt");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.opc == (1))) {
		append_str("brk");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ext(uint64_t pc, const aarch64_decode_a64_SIMD_EXTRACT& insn)
{
	uint32_t map_val = 0;
	append_str("ext");
}

void aarch64_disasm::disassemble_a64_extr(uint64_t pc, const aarch64_decode_a64_EXTRACT& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("extr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms)));
		return;
	}
	if ((insn.sf == (0))) {
		append_str("extr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_fabd(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.size == (3))) {
		append_str("fabd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.Q == (1)) && (insn.SCALAR == (1)) && (insn.size == (2))) {
		append_str("fabd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (0))) {
		append_str("fabd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fabs(uint64_t pc, const aarch64_decode_a64_FP_DP_1& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fabs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fabs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fadd(uint64_t pc, const aarch64_decode_a64_FP_DP_2& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fadd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fadd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fccmpe(uint64_t pc, const aarch64_decode_a64_FP_CCMP& insn)
{
	uint32_t map_val = 0;
	if ((insn.op == (1)) && (insn.type == (1))) {
		append_str("fccmpe");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		map_val = 0 + (insn.nzcv);
		if (map_val < 16) {
			append_str(_map_a64_nzcvbits[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.op == (1)) && (insn.type == (0))) {
		append_str("fccmpe");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		map_val = 0 + (insn.nzcv);
		if (map_val < 16) {
			append_str(_map_a64_nzcvbits[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.op == (0)) && (insn.type == (1))) {
		append_str("fccmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		map_val = 0 + (insn.nzcv);
		if (map_val < 16) {
			append_str(_map_a64_nzcvbits[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.op == (0)) && (insn.type == (0))) {
		append_str("fccmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		map_val = 0 + (insn.nzcv);
		if (map_val < 16) {
			append_str(_map_a64_nzcvbits[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fcmgt_zero(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (1)) && (insn.size == (3))) {
		append_str("fcmgt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
	if ((insn.SCALAR == (1)) && (insn.size == (2))) {
		append_str("fcmgt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		return;
	}
}

void aarch64_disasm::disassemble_a64_fcmpe(uint64_t pc, const aarch64_decode_a64_FP_CMP& insn)
{
	uint32_t map_val = 0;
	if ((insn.opcode2 == (8)) && (insn.type == (1))) {
		append_str("fcmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		append_str(".");
		append_str("0");
		return;
	}
	if ((insn.opcode2 == (0)) && (insn.type == (1))) {
		append_str("fcmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode2 == (8)) && (insn.type == (0))) {
		append_str("fcmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		append_str(".");
		append_str("0");
		return;
	}
	if ((insn.opcode2 == (0)) && (insn.type == (0))) {
		append_str("fcmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode2 == (24)) && (insn.type == (1))) {
		append_str("fcmpe");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		append_str(".");
		append_str("0");
		return;
	}
	if ((insn.opcode2 == (16)) && (insn.type == (1))) {
		append_str("fcmpe");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode2 == (24)) && (insn.type == (0))) {
		append_str("fcmpe");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("0");
		append_str(".");
		append_str("0");
		return;
	}
	if ((insn.opcode2 == (16)) && (insn.type == (0))) {
		append_str("fcmpe");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fcsel(uint64_t pc, const aarch64_decode_a64_FP_CSEL& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fcsel");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fcsel");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.cond);
		if (map_val < 16) {
			append_str(_map_a64_cond[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fcvt(uint64_t pc, const aarch64_decode_a64_FP_DP_1& insn)
{
	uint32_t map_val = 0;
	if ((insn.opcode == (4)) && (insn.type == (1))) {
		append_str("fcvt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (7)) && (insn.type == (1))) {
		append_str("fcvt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_hreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (5)) && (insn.type == (0))) {
		append_str("fcvt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (7)) && (insn.type == (0))) {
		append_str("fcvt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_hreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (5)) && (insn.type == (3))) {
		append_str("fcvt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_hreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (4)) && (insn.type == (3))) {
		append_str("fcvt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_hreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fcvtas_simd(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (1))) {
		append_str("fcvtas");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.size == (0))) {
		append_str("fcvtas");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fcvti(uint64_t pc, const aarch64_decode_a64_CVT_FP_I& insn)
{
	uint32_t map_val = 0;
	if ((insn.opcode == (1)) && (insn.rmode == (2)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtmu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (2)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtms");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (2)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtmu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (2)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtms");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (2)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtmu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (2)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtms");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (2)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtmu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (2)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtms");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (1)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtpu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (1)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtps");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (1)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtpu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (1)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtps");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (1)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtpu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (1)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtps");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (1)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtpu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (1)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtps");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (5)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtau");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (4)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtas");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtnu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtns");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (5)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtau");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (4)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtas");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtnu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtns");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (5)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtau");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (4)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtas");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtnu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtns");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (5)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtau");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (4)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtas");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtnu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtns");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fcvtz(uint64_t pc, const aarch64_decode_a64_CVT_FP_I& insn)
{
	uint32_t map_val = 0;
	if ((insn.opcode == (1)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (1)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (0)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fcvtz_fxp(uint64_t pc, const aarch64_decode_a64_CVT_FP_FXP& insn)
{
	uint32_t map_val = 0;
	if ((insn.opcode == (1)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.opcode == (1)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.opcode == (1)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.opcode == (1)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.opcode == (0)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.opcode == (0)) && (insn.sf == (1)) && (insn.type == (0))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.opcode == (0)) && (insn.sf == (0)) && (insn.type == (1))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.opcode == (0)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_fcvtzs_simd(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.U == (1)) && (insn.size == (3))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.U == (1)) && (insn.size == (2))) {
		append_str("fcvtzu");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.U == (0)) && (insn.size == (3))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.U == (0)) && (insn.size == (2))) {
		append_str("fcvtzs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fdiv(uint64_t pc, const aarch64_decode_a64_FP_DP_2& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fdiv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fdiv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fm(uint64_t pc, const aarch64_decode_a64_FP_DP_3& insn)
{
	uint32_t map_val = 0;
	if ((insn.o0 == (1)) && (insn.type == (1))) {
		append_str("fmsub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.o0 == (1)) && (insn.type == (0))) {
		append_str("fmsub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.o0 == (0)) && (insn.type == (1))) {
		append_str("fmadd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.o0 == (0)) && (insn.type == (0))) {
		append_str("fmadd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fmaxnmv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("fmaxnmv");
}

void aarch64_disasm::disassemble_a64_fmaxv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("fmaxv");
}

void aarch64_disasm::disassemble_a64_fminnmv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("fminnmv");
}

void aarch64_disasm::disassemble_a64_fminv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("fminv");
}

void aarch64_disasm::disassemble_a64_fmov(uint64_t pc, const aarch64_decode_a64_FP_DP_1& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fmov_gen(uint64_t pc, const aarch64_decode_a64_CVT_FP_I& insn)
{
	uint32_t map_val = 0;
	if ((insn.opcode == (6)) && (insn.rmode == (1)) && (insn.sf == (1)) && (insn.type == (2))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("D");
		append_str("[");
		append_str("1");
		append_str("]");
		return;
	}
	if ((insn.opcode == (6)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (7)) && (insn.rmode == (1)) && (insn.sf == (1)) && (insn.type == (2))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("D");
		append_str("[");
		append_str("1");
		append_str("]");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (7)) && (insn.rmode == (0)) && (insn.sf == (1)) && (insn.type == (1))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (6)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (7)) && (insn.rmode == (0)) && (insn.sf == (0)) && (insn.type == (0))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fmov_simd(uint64_t pc, const aarch64_decode_a64_SIMD_MOD_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.op == (1))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("d");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.Q == (1)) && (insn.op == (0))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("4");
		append_str("s");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.Q == (0)) && (insn.op == (0))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("s");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_fmovi(uint64_t pc, const aarch64_decode_a64_FP_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.type == (0))) {
		append_str("fmov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_fmul(uint64_t pc, const aarch64_decode_a64_FP_DP_2& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fmul");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fmul");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fmul_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.size == (1))) {
		append_str("fmul");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("d");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("d");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("d");
		return;
	}
	if ((insn.Q == (1)) && (insn.size == (0))) {
		append_str("fmul");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("4");
		append_str("s");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("4");
		append_str("s");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("4");
		append_str("s");
		return;
	}
	if ((insn.Q == (0)) && (insn.size == (0))) {
		append_str("fmul");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("s");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("s");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("s");
		return;
	}
}

void aarch64_disasm::disassemble_a64_fneg(uint64_t pc, const aarch64_decode_a64_FP_DP_1& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fneg");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fneg");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fnm(uint64_t pc, const aarch64_decode_a64_FP_DP_3& insn)
{
	uint32_t map_val = 0;
	if ((insn.o0 == (1)) && (insn.type == (1))) {
		append_str("fnmsub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.o0 == (1)) && (insn.type == (0))) {
		append_str("fnmsub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.o0 == (0)) && (insn.type == (1))) {
		append_str("fnmadd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.o0 == (0)) && (insn.type == (0))) {
		append_str("fnmadd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fnmul(uint64_t pc, const aarch64_decode_a64_FP_DP_2& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fnmul");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fnmul");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_frintx(uint64_t pc, const aarch64_decode_a64_FP_DP_1& insn)
{
	uint32_t map_val = 0;
	if ((insn.opcode == (15)) && (insn.type == (1))) {
		append_str("frinti");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (15)) && (insn.type == (0))) {
		append_str("frinti");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (14)) && (insn.type == (1))) {
		append_str("frintx");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (14)) && (insn.type == (0))) {
		append_str("frintx");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (12)) && (insn.type == (1))) {
		append_str("frinta");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (12)) && (insn.type == (0))) {
		append_str("frinta");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (11)) && (insn.type == (1))) {
		append_str("frintz");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (11)) && (insn.type == (0))) {
		append_str("frintz");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (10)) && (insn.type == (1))) {
		append_str("frintm");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (10)) && (insn.type == (0))) {
		append_str("frintm");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (9)) && (insn.type == (1))) {
		append_str("frintp");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (9)) && (insn.type == (0))) {
		append_str("frintp");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (8)) && (insn.type == (1))) {
		append_str("frintn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (8)) && (insn.type == (0))) {
		append_str("frintn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fsqrt(uint64_t pc, const aarch64_decode_a64_FP_DP_1& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fsqrt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fsqrt");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fsub(uint64_t pc, const aarch64_decode_a64_FP_DP_2& insn)
{
	uint32_t map_val = 0;
	if ((insn.type == (1))) {
		append_str("fsub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.type == (0))) {
		append_str("fsub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_fsub_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.size == (3))) {
		append_str("fsub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("d");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("d");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("d");
		return;
	}
	if ((insn.Q == (1)) && (insn.size == (2))) {
		append_str("fsub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("4");
		append_str("s");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("4");
		append_str("s");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("4");
		append_str("s");
		return;
	}
	if ((insn.Q == (0)) && (insn.size == (2))) {
		append_str("fsub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("s");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("s");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("2");
		append_str("s");
		return;
	}
}

void aarch64_disasm::disassemble_a64_hint(uint64_t pc, const aarch64_decode_a64_SYSTEM& insn)
{
	uint32_t map_val = 0;
	if ((insn.crm == (0)) && (insn.op2 == (5))) {
		append_str("sevl");
		return;
	}
	if ((insn.crm == (0)) && (insn.op2 == (4))) {
		append_str("sev");
		return;
	}
	if ((insn.crm == (0)) && (insn.op2 == (3))) {
		append_str("wfi");
		return;
	}
	if ((insn.crm == (0)) && (insn.op2 == (2))) {
		append_str("wfe");
		return;
	}
	if ((insn.crm == (0)) && (insn.op2 == (1))) {
		append_str("yield");
		return;
	}
	if ((insn.crm == (0)) && (insn.op2 == (0))) {
		append_str("nop");
		return;
	}
	append_str("hint");
	append_str(" ");
	append_str("#");
	append_dec((uint32_t) ((insn.crm)));
	append_str(" ");
	append_dec((uint32_t) ((insn.op2)));
	return;
}

void aarch64_disasm::disassemble_a64_ins_elem(uint64_t pc, const aarch64_decode_a64_SIMD_COPY& insn)
{
	uint32_t map_val = 0;
	append_str("ins_elem");
}

void aarch64_disasm::disassemble_a64_ins_gen(uint64_t pc, const aarch64_decode_a64_SIMD_COPY& insn)
{
	uint32_t map_val = 0;
	append_str("ins_gen");
}

void aarch64_disasm::disassemble_a64_ld1(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT& insn)
{
	uint32_t map_val = 0;
	append_str("ld1");
}

void aarch64_disasm::disassemble_a64_ld1pi(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT_PI& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.opcode == (2)) && (insn.rm == (31))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("*");
		append_str("4");
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("64");
		return;
	}
	if ((insn.Q == (0)) && (insn.opcode == (2)) && (insn.rm == (31))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("*");
		append_str("4");
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("32");
		return;
	}
	if ((insn.Q == (1)) && (insn.opcode == (6)) && (insn.rm == (31))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("*");
		append_str("3");
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("48");
		return;
	}
	if ((insn.Q == (0)) && (insn.opcode == (6)) && (insn.rm == (31))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("*");
		append_str("3");
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("24");
		return;
	}
	if ((insn.Q == (1)) && (insn.opcode == (10)) && (insn.rm == (31))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("*");
		append_str("2");
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("32");
		return;
	}
	if ((insn.Q == (0)) && (insn.opcode == (10)) && (insn.rm == (31))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("*");
		append_str("2");
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("16");
		return;
	}
	if ((insn.Q == (1)) && (insn.opcode == (7)) && (insn.rm == (31))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("16");
		return;
	}
	if ((insn.Q == (0)) && (insn.opcode == (7)) && (insn.rm == (31))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_str("8");
		return;
	}
	if ((insn.opcode == (2))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("*");
		append_str("4");
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (6))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("*");
		append_str("3");
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (10))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("*");
		append_str("2");
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.opcode == (7))) {
		append_str("ld1");
		append_str(" ");
		append_str("{");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("}");
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_ld1r(uint64_t pc, const aarch64_decode_a64_SIMD_LS_SINGLE& insn)
{
	uint32_t map_val = 0;
	append_str("ld1r");
	return;
}

void aarch64_disasm::disassemble_a64_ld1s(uint64_t pc, const aarch64_decode_a64_SIMD_LS_SINGLE& insn)
{
	uint32_t map_val = 0;
	append_str("ld1s");
	return;
}

void aarch64_disasm::disassemble_a64_ld2(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT& insn)
{
	uint32_t map_val = 0;
	append_str("ld2");
}

void aarch64_disasm::disassemble_a64_ld2pi(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT_PI& insn)
{
	uint32_t map_val = 0;
	append_str("ld2pi");
}

void aarch64_disasm::disassemble_a64_ld3(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT& insn)
{
	uint32_t map_val = 0;
	append_str("ld3");
}

void aarch64_disasm::disassemble_a64_ld3pi(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT_PI& insn)
{
	uint32_t map_val = 0;
	append_str("ld3pi");
}

void aarch64_disasm::disassemble_a64_ld4(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT& insn)
{
	uint32_t map_val = 0;
	append_str("ld4");
}

void aarch64_disasm::disassemble_a64_ld4pi(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT_PI& insn)
{
	uint32_t map_val = 0;
	append_str("ld4pi");
}

void aarch64_disasm::disassemble_a64_ldar(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("ldar");
}

void aarch64_disasm::disassemble_a64_ldarb(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("ldarb");
}

void aarch64_disasm::disassemble_a64_ldarh(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("ldarh");
}

void aarch64_disasm::disassemble_a64_ldaxp(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("ldaxp");
}

void aarch64_disasm::disassemble_a64_ldaxr(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (3))) {
		append_str("ldaxr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("ldaxr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldaxrb(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("ldaxrb");
}

void aarch64_disasm::disassemble_a64_ldaxrh(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("ldaxrh");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_ldnp(uint64_t pc, const aarch64_decode_a64_LS_NO_ALLOC& insn)
{
	uint32_t map_val = 0;
	if ((insn.opc == (2))) {
		append_str("ldnp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (0))) {
		append_str("ldnp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldp(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_OFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.imm7 == (0)) && (insn.opc == (2))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.imm7 == (0)) && (insn.opc == (0))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.opc == (2))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (0))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldp_simd(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_OFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.imm7 == (0)) && (insn.opc == (2))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.imm7 == (0)) && (insn.opc == (1))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.imm7 == (0)) && (insn.opc == (0))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.opc == (2))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (1))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (0))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldpi(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_IDX& insn)
{
	uint32_t map_val = 0;
	if ((insn.P == (1)) && (insn.opc == (2))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (1)) && (insn.opc == (0))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.opc == (2))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.P == (0)) && (insn.opc == (0))) {
		append_str("ldp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldpi_simd(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_IDX& insn)
{
	uint32_t map_val = 0;
	append_str("ldpi_simd");
}

void aarch64_disasm::disassemble_a64_ldpsw(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_OFF& insn)
{
	uint32_t map_val = 0;
	append_str("ldpsw");
}

void aarch64_disasm::disassemble_a64_ldpswi(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_IDX& insn)
{
	uint32_t map_val = 0;
	append_str("ldpswi");
}

void aarch64_disasm::disassemble_a64_ldr(uint64_t pc, const aarch64_decode_a64_LS_REG_IMM_POST& insn)
{
	uint32_t map_val = 0;
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (1))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_hreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (1))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_hreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (1)) && (insn.size == (0))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (1)) && (insn.size == (0))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (0))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_breg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (0))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_breg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (0)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (1)) && (insn.V == (0)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (0)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (0)) && (insn.V == (0)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldr_lit(uint64_t pc, const aarch64_decode_a64_LOAD_REG_LIT& insn)
{
	uint32_t map_val = 0;
	if ((insn.opc == (1))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.label))));
		return;
	}
	if ((insn.opc == (0))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.label))));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldr_lit_simd(uint64_t pc, const aarch64_decode_a64_LOAD_REG_LIT& insn)
{
	uint32_t map_val = 0;
	if ((insn.opc == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.label))));
		return;
	}
	if ((insn.opc == (1))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.label))));
		return;
	}
	if ((insn.opc == (0))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.label))));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldr_reg(uint64_t pc, const aarch64_decode_a64_LS_REG_REG_OFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.L == (0)) && (insn.S == (1)) && (insn.X == (1)) && (insn.option0 == (1))) {
		append_str("ldrsw");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype64[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.L == (0)) && (insn.S == (1)) && (insn.X == (1)) && (insn.option0 == (0))) {
		append_str("ldrsw");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.L == (0)) && (insn.S == (0)) && (insn.X == (1)) && (insn.option0 == (1))) {
		append_str("ldrsw");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype64[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.L == (0)) && (insn.S == (0)) && (insn.X == (1)) && (insn.option0 == (0))) {
		append_str("ldrsw");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (1)) && (insn.option21 == (3)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTX");
		append_str(" ");
		append_str("#");
		append_str("3");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (0)) && (insn.option21 == (3)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTW");
		append_str(" ");
		append_str("#");
		append_str("3");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (1)) && (insn.option21 == (1)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_str("3");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (0)) && (insn.option21 == (1)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("UXTW");
		append_str(" ");
		append_str("#");
		append_str("3");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (1)) && (insn.option21 == (3)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTX");
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (0)) && (insn.option21 == (3)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTW");
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (1)) && (insn.option21 == (1)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (0)) && (insn.option21 == (1)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("UXTW");
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.S == (0)) && (insn.option0 == (1)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTX");
		append_str("]");
		return;
	}
	if ((insn.S == (0)) && (insn.option0 == (0)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTW");
		append_str("]");
		return;
	}
	if ((insn.S == (0)) && (insn.option0 == (1)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str("]");
		return;
	}
	if ((insn.S == (0)) && (insn.option0 == (0)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("UXTW");
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldr_reg_simd(uint64_t pc, const aarch64_decode_a64_LS_REG_REG_OFF& insn)
{
	uint32_t map_val = 0;
	append_str("ldr_reg_simd");
}

void aarch64_disasm::disassemble_a64_ldrb(uint64_t pc, const aarch64_decode_a64_LS_REG_IMM_POST& insn)
{
	uint32_t map_val = 0;
	if ((insn.L == (0)) && (insn.P == (1)) && (insn.X == (1))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.L == (0)) && (insn.P == (0)) && (insn.X == (1))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.L == (1)) && (insn.P == (1)) && (insn.X == (1))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.L == (1)) && (insn.P == (0)) && (insn.X == (1))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1))) {
		append_str("ldrb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0))) {
		append_str("ldrb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldrb_reg(uint64_t pc, const aarch64_decode_a64_LS_REG_REG_OFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.L == (0)) && (insn.X == (1)) && (insn.ext_type == (3))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.S)));
		append_str("]");
		return;
	}
	if ((insn.L == (0)) && (insn.S == (1)) && (insn.X == (1))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_str("1");
		append_str("]");
		return;
	}
	if ((insn.L == (0)) && (insn.S == (0)) && (insn.X == (1))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.L == (1)) && (insn.X == (1)) && (insn.ext_type == (3))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.S)));
		append_str("]");
		return;
	}
	if ((insn.L == (1)) && (insn.S == (1)) && (insn.X == (1))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_str("1");
		append_str("]");
		return;
	}
	if ((insn.L == (1)) && (insn.S == (0)) && (insn.X == (1))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.ext_type == (3))) {
		append_str("ldrb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.S)));
		append_str("]");
		return;
	}
	if ((insn.S == (1))) {
		append_str("ldrb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_str("1");
		append_str("]");
		return;
	}
	if ((insn.S == (0))) {
		append_str("ldrb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldrbi(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.immu64 == (0)) && (insn.opc == (2))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.immu64 == (0)) && (insn.opc == (3))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.immu64 == (0)) && (insn.opc == (1))) {
		append_str("ldrb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.opc == (2))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (3))) {
		append_str("ldrsb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (1))) {
		append_str("ldrb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldrh(uint64_t pc, const aarch64_decode_a64_LS_REG_IMM_POST& insn)
{
	uint32_t map_val = 0;
	if ((insn.L == (0)) && (insn.P == (1)) && (insn.X == (1))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.L == (0)) && (insn.P == (0)) && (insn.X == (1))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.L == (1)) && (insn.P == (1)) && (insn.X == (1))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.L == (1)) && (insn.P == (0)) && (insn.X == (1))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1))) {
		append_str("ldrh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0))) {
		append_str("ldrh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldrh_reg(uint64_t pc, const aarch64_decode_a64_LS_REG_REG_OFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.L == (0)) && (insn.X == (1)) && (insn.ext_type == (3))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.S)));
		append_str("]");
		return;
	}
	if ((insn.L == (0)) && (insn.S == (1)) && (insn.X == (1))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_str("1");
		append_str("]");
		return;
	}
	if ((insn.L == (0)) && (insn.S == (0)) && (insn.X == (1))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.L == (1)) && (insn.X == (1)) && (insn.ext_type == (3))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.S)));
		append_str("]");
		return;
	}
	if ((insn.L == (1)) && (insn.S == (1)) && (insn.X == (1))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_str("1");
		append_str("]");
		return;
	}
	if ((insn.L == (1)) && (insn.S == (0)) && (insn.X == (1))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.ext_type == (3))) {
		append_str("ldrh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.S)));
		append_str("]");
		return;
	}
	if ((insn.S == (1))) {
		append_str("ldrh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_str("1");
		append_str("]");
		return;
	}
	if ((insn.S == (0))) {
		append_str("ldrh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldrhi(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.immu64 == (0)) && (insn.opc == (2))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.immu64 == (0)) && (insn.opc == (3))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.immu64 == (0)) && (insn.opc == (1))) {
		append_str("ldrh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.opc == (2))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (3))) {
		append_str("ldrsh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (1))) {
		append_str("ldrh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldri(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.immu64 == (0)) && (insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.immu64 == (0)) && (insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (3))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("ldr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldrsw(uint64_t pc, const aarch64_decode_a64_LS_REG_IMM_POST& insn)
{
	uint32_t map_val = 0;
	append_str("ldrsw");
}

void aarch64_disasm::disassemble_a64_ldrsw_lit(uint64_t pc, const aarch64_decode_a64_LOAD_REG_LIT& insn)
{
	uint32_t map_val = 0;
	append_str("ldrsw_lit");
}

void aarch64_disasm::disassemble_a64_ldrswi(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.immu64 == (0))) {
		append_str("ldrsw");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	append_str("ldrsw");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("#");
	append_dec((uint32_t) ((insn.immu64)));
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_ldtr(uint64_t pc, const aarch64_decode_a64_LS_REG_UNPRIV& insn)
{
	uint32_t map_val = 0;
	append_str("ldtr");
}

void aarch64_disasm::disassemble_a64_ldtrb(uint64_t pc, const aarch64_decode_a64_LS_REG_UNPRIV& insn)
{
	uint32_t map_val = 0;
	append_str("ldtrb");
}

void aarch64_disasm::disassemble_a64_ldtrh(uint64_t pc, const aarch64_decode_a64_LS_REG_UNPRIV& insn)
{
	uint32_t map_val = 0;
	append_str("ldtrh");
}

void aarch64_disasm::disassemble_a64_ldtrsw(uint64_t pc, const aarch64_decode_a64_LS_REG_UNPRIV& insn)
{
	uint32_t map_val = 0;
	append_str("ldtrsw");
}

void aarch64_disasm::disassemble_a64_ldur(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	append_str("ldur");
}

void aarch64_disasm::disassemble_a64_ldurb(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.opc == (3))) {
		append_str("ldursb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (2))) {
		append_str("ldursb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (1))) {
		append_str("ldurb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldurh(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	append_str("ldurh");
}

void aarch64_disasm::disassemble_a64_ldursw(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	append_str("ldursw");
}

void aarch64_disasm::disassemble_a64_ldxp(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (3))) {
		append_str("ldxp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("ldxp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldxr(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (3))) {
		append_str("ldxr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("ldxr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_ldxrb(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("ldxrb");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_ldxrh(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("ldxrh");
}

void aarch64_disasm::disassemble_a64_lslv(uint64_t pc, const aarch64_decode_a64_DP_2S& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("lslv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("lslv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_lsrv(uint64_t pc, const aarch64_decode_a64_DP_2S& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("lsrv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("lsrv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_madd(uint64_t pc, const aarch64_decode_a64_DP_3S& insn)
{
	uint32_t map_val = 0;
	if ((insn.ra == (31)) && (insn.sf == (1))) {
		append_str("mul");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.ra == (31)) && (insn.sf == (0))) {
		append_str("mul");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (1))) {
		append_str("madd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("madd");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_mla_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("mla");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_mov(uint64_t pc, const aarch64_decode_a64_LOGICAL_SR& insn)
{
	uint32_t map_val = 0;
	if ((insn.N == (1)) && (insn.sf == (1))) {
		append_str("mvn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (1)) && (insn.sf == (0))) {
		append_str("mvn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (0)) && (insn.sf == (1))) {
		append_str("mov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (0)) && (insn.sf == (0))) {
		append_str("mov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_movi(uint64_t pc, const aarch64_decode_a64_SIMD_MOD_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (0)) && (insn.cmode == (14)) && (insn.op == (1))) {
		append_str("movi");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.Q == (1)) && (insn.cmode == (14)) && (insn.op == (0))) {
		append_str("movi");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.Q == (0)) && (insn.cmode == (14)) && (insn.op == (0))) {
		append_str("movi");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_movk(uint64_t pc, const aarch64_decode_a64_MOVE_WIDE_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.hw == (0)) && (insn.sf == (1))) {
		append_str("movk");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.hw == (0)) && (insn.sf == (0))) {
		append_str("movk");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.sf == (1))) {
		append_str("movk");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.sf == (0))) {
		append_str("movk");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_movn(uint64_t pc, const aarch64_decode_a64_MOVE_WIDE_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.hw == (0)) && (insn.sf == (1))) {
		append_str("movn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.hw == (0)) && (insn.sf == (0))) {
		append_str("movn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.sf == (1))) {
		append_str("movn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.sf == (0))) {
		append_str("movn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_movz(uint64_t pc, const aarch64_decode_a64_MOVE_WIDE_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.hw == (0)) && (insn.sf == (1))) {
		append_str("movz");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.hw == (0)) && (insn.sf == (0))) {
		append_str("movz");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		return;
	}
	if ((insn.sf == (1))) {
		append_str("movz");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.sf == (0))) {
		append_str("movz");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm16)));
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_mrs(uint64_t pc, const aarch64_decode_a64_SYSTEM& insn)
{
	uint32_t map_val = 0;
	if ((insn.crm == (0)) && (insn.crn == (13)) && (insn.op0 == (3)) && (insn.op1 == (0)) && (insn.op2 == (4))) {
		append_str("mrs");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("tpidr");
		append_str("_");
		append_str("el1");
		return;
	}
	if ((insn.crm == (0)) && (insn.crn == (13)) && (insn.op0 == (3)) && (insn.op1 == (3)) && (insn.op2 == (2))) {
		append_str("mrs");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("tpidr");
		append_str("_");
		append_str("el0");
		return;
	}
	if ((insn.crm == (2)) && (insn.crn == (4)) && (insn.op0 == (3)) && (insn.op1 == (0)) && (insn.op2 == (2))) {
		append_str("mrs");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("currentel");
		return;
	}
	append_str("mrs");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("S");
	append_dec((uint32_t) ((insn.op0)));
	append_str("_");
	append_dec((uint32_t) ((insn.op1)));
	append_str("_");
	append_str("C");
	append_dec((uint32_t) ((insn.crn)));
	append_str("_");
	append_str("C");
	append_dec((uint32_t) ((insn.crm)));
	append_str("_");
	append_dec((uint32_t) ((insn.op2)));
	return;
}

void aarch64_disasm::disassemble_a64_msr_imm(uint64_t pc, const aarch64_decode_a64_SYSTEM& insn)
{
	uint32_t map_val = 0;
	if ((insn.op1 == (3)) && (insn.op2 == (7))) {
		append_str("msr");
		append_str(" ");
		append_str("daifclr");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.crm)));
		return;
	}
	if ((insn.op1 == (3)) && (insn.op2 == (6))) {
		append_str("msr");
		append_str(" ");
		append_str("daifset");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.crm)));
		return;
	}
	if ((insn.op1 == (0)) && (insn.op2 == (5))) {
		append_str("msr");
		append_str(" ");
		append_str("spsel");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.crm)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_msr_reg(uint64_t pc, const aarch64_decode_a64_SYSTEM& insn)
{
	uint32_t map_val = 0;
	if ((insn.crm == (0)) && (insn.crn == (13)) && (insn.op0 == (3)) && (insn.op1 == (0)) && (insn.op2 == (4))) {
		append_str("msr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("tpidr");
		append_str("_");
		append_str("el1");
		return;
	}
	if ((insn.crm == (0)) && (insn.crn == (13)) && (insn.op0 == (3)) && (insn.op1 == (3)) && (insn.op2 == (2))) {
		append_str("msr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("tpidr");
		append_str("_");
		append_str("el0");
		return;
	}
	append_str("msr");
	append_str(" ");
	append_str("S");
	append_dec((uint32_t) ((insn.op0)));
	append_str("_");
	append_dec((uint32_t) ((insn.op1)));
	append_str("_");
	append_str("C");
	append_dec((uint32_t) ((insn.crn)));
	append_str("_");
	append_str("C");
	append_dec((uint32_t) ((insn.crm)));
	append_str("_");
	append_dec((uint32_t) ((insn.op2)));
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_msr_sctlr(uint64_t pc, const aarch64_decode_a64_SYSTEM& insn)
{
	uint32_t map_val = 0;
	append_str("msr");
	append_str(" ");
	append_str("sctlr");
	append_str("_");
	append_str("el1");
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_msub(uint64_t pc, const aarch64_decode_a64_DP_3S& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("msub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("msub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ra);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_mul_idx_vector(uint64_t pc, const aarch64_decode_a64_SIMD_VECTOR_IDX& insn)
{
	uint32_t map_val = 0;
	append_str("mul");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(" ");
	append_str("ARRG");
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(" ");
	append_str("ARRG");
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(" ");
	append_str("ARRG");
	append_str(" ");
	append_str("[");
	append_dec((uint32_t) ((insn.eindex)));
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_mul_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("mul");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_mvni(uint64_t pc, const aarch64_decode_a64_SIMD_MOD_IMM& insn)
{
	uint32_t map_val = 0;
	append_str("mvni");
}

void aarch64_disasm::disassemble_a64_neg_simd(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (0))) {
		append_str("neg");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (1))) {
		append_str("neg");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_not_simd(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	append_str("not");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_orn_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("orn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		return;
	}
	if ((insn.Q == (0))) {
		append_str("orn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		return;
	}
}

void aarch64_disasm::disassemble_a64_orr_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1)) && (insn.rn == (insn.rm))) {
		append_str("mov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		return;
	}
	if ((insn.Q == (0)) && (insn.rn == (insn.rm))) {
		append_str("mov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		return;
	}
	if ((insn.Q == (1))) {
		append_str("orr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("16");
		append_str("b");
		return;
	}
	if ((insn.Q == (0))) {
		append_str("orr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("8");
		append_str("b");
		return;
	}
}

void aarch64_disasm::disassemble_a64_orri(uint64_t pc, const aarch64_decode_a64_LOGICAL_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.N == (0)) && (insn.sf == (0))) {
		append_str("orr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint32_t) ((insn.immu32)));
		return;
	}
	if ((insn.sf == (1))) {
		append_str("orr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_hex((uint64_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_orrsr(uint64_t pc, const aarch64_decode_a64_LOGICAL_SR& insn)
{
	uint32_t map_val = 0;
	if ((insn.N == (1)) && (insn.imm6 == (0)) && (insn.sf == (1))) {
		append_str("orn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (1)) && (insn.imm6 == (0)) && (insn.sf == (0))) {
		append_str("orn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (0)) && (insn.imm6 == (0)) && (insn.sf == (1))) {
		append_str("orr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (0)) && (insn.imm6 == (0)) && (insn.sf == (0))) {
		append_str("orr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (1)) && (insn.sf == (1))) {
		append_str("orn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.N == (1)) && (insn.sf == (0))) {
		append_str("orn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.N == (0)) && (insn.sf == (1))) {
		append_str("orr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.N == (0)) && (insn.sf == (0))) {
		append_str("orr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_pmull(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("pmull2");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.Q == (0))) {
		append_str("pmull");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_prfm(uint64_t pc, const aarch64_decode_a64_LS_REG_IMM_POST& insn)
{
	uint32_t map_val = 0;
	append_str("prfm");
}

void aarch64_disasm::disassemble_a64_prfm_lit(uint64_t pc, const aarch64_decode_a64_LOAD_REG_LIT& insn)
{
	uint32_t map_val = 0;
	append_str("prfm_lit");
}

void aarch64_disasm::disassemble_a64_prfm_reg(uint64_t pc, const aarch64_decode_a64_LS_REG_REG_OFF& insn)
{
	uint32_t map_val = 0;
	append_str("prfm_reg");
}

void aarch64_disasm::disassemble_a64_prfmi(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	append_str("prfmi");
}

void aarch64_disasm::disassemble_a64_prfum(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	append_str("prfum");
}

void aarch64_disasm::disassemble_a64_rbit(uint64_t pc, const aarch64_decode_a64_DP_1S& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("rbit");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("rbit");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_ret(uint64_t pc, const aarch64_decode_a64_UB_REG& insn)
{
	uint32_t map_val = 0;
	if ((insn.rn == (30))) {
		append_str("ret");
		return;
	}
	append_str("ret");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_rev(uint64_t pc, const aarch64_decode_a64_DP_1S& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("rev");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("rev");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_rev16(uint64_t pc, const aarch64_decode_a64_DP_1S& insn)
{
	uint32_t map_val = 0;
	append_str("rev16");
}

void aarch64_disasm::disassemble_a64_rev32(uint64_t pc, const aarch64_decode_a64_DP_1S& insn)
{
	uint32_t map_val = 0;
	append_str("rev32");
}

void aarch64_disasm::disassemble_a64_rev32_simd(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	append_str("rev32");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_rev64_simd(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	append_str("rev64");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_rorv(uint64_t pc, const aarch64_decode_a64_DP_2S& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("rorv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("rorv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_saddl(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	append_str("saddl");
}

void aarch64_disasm::disassemble_a64_saddlv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("saddlv");
}

void aarch64_disasm::disassemble_a64_saddw(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	append_str("saddw");
}

void aarch64_disasm::disassemble_a64_sbc(uint64_t pc, const aarch64_decode_a64_ADD_SUB_CARRY& insn)
{
	uint32_t map_val = 0;
	append_str("sbc");
}

void aarch64_disasm::disassemble_a64_sbfm(uint64_t pc, const aarch64_decode_a64_BITFIELD& insn)
{
	uint32_t map_val = 0;
	if ((insn.N == (1)) && (insn.immr == (0)) && (insn.imms == (31)) && (insn.sf == (1))) {
		append_str("sxtw");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (1)) && (insn.immr == (0)) && (insn.imms == (15)) && (insn.sf == (1))) {
		append_str("sxth");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (0)) && (insn.immr == (0)) && (insn.imms == (15)) && (insn.sf == (0))) {
		append_str("sxth");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (1)) && (insn.immr == (0)) && (insn.imms == (7)) && (insn.sf == (1))) {
		append_str("sxtb");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.N == (0)) && (insn.immr == (0)) && (insn.imms == (7)) && (insn.sf == (0))) {
		append_str("sxtb");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (1))) {
		append_str("sbfm");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immr)));
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms)));
		return;
	}
	if ((insn.sf == (0))) {
		append_str("sbfm");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immr)));
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_scvtf(uint64_t pc, const aarch64_decode_a64_CVT_FP_I& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1)) && (insn.type == (1))) {
		append_str("scvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0)) && (insn.type == (1))) {
		append_str("scvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (1)) && (insn.type == (0))) {
		append_str("scvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0)) && (insn.type == (0))) {
		append_str("scvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_scvtf_simd(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (1)) && (insn.size == (1))) {
		append_str("scvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (1)) && (insn.size == (0))) {
		append_str("scvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (0))) {
		append_str("scvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_sdiv(uint64_t pc, const aarch64_decode_a64_DP_2S& insn)
{
	uint32_t map_val = 0;
	append_str("sdiv");
}

void aarch64_disasm::disassemble_a64_shl_simd(uint64_t pc, const aarch64_decode_a64_SIMD_SHIFT_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (0))) {
		append_str("shl");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.SCALAR == (1))) {
		append_str("shl");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_shll(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("shll2");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("ARRG");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.size)));
		append_str(" ");
		append_str("*");
		append_str(" ");
		append_str("8");
		return;
	}
	if ((insn.Q == (0))) {
		append_str("shll");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("ARRG");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.size)));
		append_str(" ");
		append_str("*");
		append_str(" ");
		append_str("8");
		return;
	}
}

void aarch64_disasm::disassemble_a64_smaddl(uint64_t pc, const aarch64_decode_a64_DP_3S& insn)
{
	uint32_t map_val = 0;
	append_str("smaddl");
}

void aarch64_disasm::disassemble_a64_smax(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("smax");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	return;
}

void aarch64_disasm::disassemble_a64_smaxv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("smaxv");
}

void aarch64_disasm::disassemble_a64_smin(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("smin");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	return;
}

void aarch64_disasm::disassemble_a64_sminv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("sminv");
}

void aarch64_disasm::disassemble_a64_smov(uint64_t pc, const aarch64_decode_a64_SIMD_COPY& insn)
{
	uint32_t map_val = 0;
	append_str("smov");
}

void aarch64_disasm::disassemble_a64_smsubl(uint64_t pc, const aarch64_decode_a64_DP_3S& insn)
{
	uint32_t map_val = 0;
	append_str("smsubl");
}

void aarch64_disasm::disassemble_a64_smulh(uint64_t pc, const aarch64_decode_a64_DP_3S& insn)
{
	uint32_t map_val = 0;
	append_str("smulh");
}

void aarch64_disasm::disassemble_a64_smull(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("smull2");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.Q == (0))) {
		append_str("smull");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_sshl(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("sshl");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	return;
}

void aarch64_disasm::disassemble_a64_sshll(uint64_t pc, const aarch64_decode_a64_SIMD_SHIFT_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("sshll2");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("ARRG");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.Q == (0))) {
		append_str("sshll");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("ARRG");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_sshr(uint64_t pc, const aarch64_decode_a64_SIMD_SHIFT_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (0))) {
		append_str("sshr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.SCALAR == (1))) {
		append_str("sshr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ssubl(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	append_str("ssubl");
}

void aarch64_disasm::disassemble_a64_ssubw(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("ssubw2");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.Q == (0))) {
		append_str("ssubw");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_st1(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT& insn)
{
	uint32_t map_val = 0;
	append_str("st1");
}

void aarch64_disasm::disassemble_a64_st1pi(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT_PI& insn)
{
	uint32_t map_val = 0;
	append_str("st1pi");
}

void aarch64_disasm::disassemble_a64_st1s(uint64_t pc, const aarch64_decode_a64_SIMD_LS_SINGLE& insn)
{
	uint32_t map_val = 0;
	append_str("st1s");
	return;
}

void aarch64_disasm::disassemble_a64_st1spi(uint64_t pc, const aarch64_decode_a64_SIMD_LS_SINGLE_PI& insn)
{
	uint32_t map_val = 0;
	append_str("st1spi");
	return;
}

void aarch64_disasm::disassemble_a64_st2(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT& insn)
{
	uint32_t map_val = 0;
	append_str("st2");
}

void aarch64_disasm::disassemble_a64_st2pi(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT_PI& insn)
{
	uint32_t map_val = 0;
	append_str("st2pi");
}

void aarch64_disasm::disassemble_a64_st3(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT& insn)
{
	uint32_t map_val = 0;
	append_str("st3");
}

void aarch64_disasm::disassemble_a64_st3pi(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT_PI& insn)
{
	uint32_t map_val = 0;
	append_str("st3pi");
}

void aarch64_disasm::disassemble_a64_st4(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT& insn)
{
	uint32_t map_val = 0;
	append_str("st4");
}

void aarch64_disasm::disassemble_a64_st4pi(uint64_t pc, const aarch64_decode_a64_SIMD_LS_MULT_PI& insn)
{
	uint32_t map_val = 0;
	append_str("st4pi");
}

void aarch64_disasm::disassemble_a64_stlr(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (3))) {
		append_str("stlr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("stlr");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_stlrb(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("stlrb");
}

void aarch64_disasm::disassemble_a64_stlrh(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("stlrh");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_stlxp(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (3))) {
		append_str("stlxp");
		append_str(" ");
		map_val = 0 + (insn.rs);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("stlxp");
		append_str(" ");
		map_val = 0 + (insn.rs);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_stlxr(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (3))) {
		append_str("stlxr");
		append_str(" ");
		map_val = 0 + (insn.rs);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("stlxr");
		append_str(" ");
		map_val = 0 + (insn.rs);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_stlxrb(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("stlxrb");
}

void aarch64_disasm::disassemble_a64_stlxrh(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("stlxrh");
}

void aarch64_disasm::disassemble_a64_stnp(uint64_t pc, const aarch64_decode_a64_LS_NO_ALLOC& insn)
{
	uint32_t map_val = 0;
	if ((insn.opc == (2))) {
		append_str("stnp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (0))) {
		append_str("stnp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_stp(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_OFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.imm7 == (0)) && (insn.opc == (2))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.imm7 == (0)) && (insn.opc == (0))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.opc == (2))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm7)));
		append_str("]");
		return;
	}
	if ((insn.opc == (0))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm7)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_stp_simd(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_OFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.imm7 == (0)) && (insn.opc == (2))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.imm7 == (0)) && (insn.opc == (1))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.imm7 == (0)) && (insn.opc == (0))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.opc == (2))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (1))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.opc == (0))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_stpi(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_IDX& insn)
{
	uint32_t map_val = 0;
	if ((insn.P == (1)) && (insn.opc == (2))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (1)) && (insn.opc == (0))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.opc == (2))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.P == (0)) && (insn.opc == (0))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_stpi_simd(uint64_t pc, const aarch64_decode_a64_LS_REG_PAIR_IDX& insn)
{
	uint32_t map_val = 0;
	if ((insn.P == (1)) && (insn.opc == (2))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (1)) && (insn.opc == (1))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (1)) && (insn.opc == (0))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.opc == (2))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.P == (0)) && (insn.opc == (1))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
	if ((insn.P == (0)) && (insn.opc == (0))) {
		append_str("stp");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_str(uint64_t pc, const aarch64_decode_a64_LS_REG_IMM_POST& insn)
{
	uint32_t map_val = 0;
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (1))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_hreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (1))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_hreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (1)) && (insn.size == (0))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (1)) && (insn.size == (0))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_qreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (0))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_breg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (1)) && (insn.X == (0)) && (insn.size == (0))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_breg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (1)) && (insn.V == (0)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (1)) && (insn.V == (0)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0)) && (insn.V == (0)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
	if ((insn.P == (0)) && (insn.V == (0)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_str_reg(uint64_t pc, const aarch64_decode_a64_LS_REG_REG_OFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.S == (1)) && (insn.option0 == (1)) && (insn.option21 == (3)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTX");
		append_str(" ");
		append_str("#");
		append_str("3");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (0)) && (insn.option21 == (3)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTW");
		append_str(" ");
		append_str("#");
		append_str("3");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (1)) && (insn.option21 == (1)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_str("3");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (0)) && (insn.option21 == (1)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("UXTW");
		append_str(" ");
		append_str("#");
		append_str("3");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (1)) && (insn.option21 == (3)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTX");
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (0)) && (insn.option21 == (3)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTW");
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (1)) && (insn.option21 == (1)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.S == (1)) && (insn.option0 == (0)) && (insn.option21 == (1)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("UXTW");
		append_str(" ");
		append_str("#");
		append_str("2");
		append_str("]");
		return;
	}
	if ((insn.S == (0)) && (insn.option0 == (1)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTX");
		append_str("]");
		return;
	}
	if ((insn.S == (0)) && (insn.option0 == (0)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("SXTW");
		append_str("]");
		return;
	}
	if ((insn.S == (0)) && (insn.option0 == (1)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str("]");
		return;
	}
	if ((insn.S == (0)) && (insn.option0 == (0)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("UXTW");
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_str_reg_simd(uint64_t pc, const aarch64_decode_a64_LS_REG_REG_OFF& insn)
{
	uint32_t map_val = 0;
	append_str("str_reg_simd");
}

void aarch64_disasm::disassemble_a64_strb(uint64_t pc, const aarch64_decode_a64_LS_REG_IMM_POST& insn)
{
	uint32_t map_val = 0;
	if ((insn.P == (1))) {
		append_str("strb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0))) {
		append_str("strb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_strb_reg(uint64_t pc, const aarch64_decode_a64_LS_REG_REG_OFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.ext_type == (3))) {
		append_str("strb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		append_str("LSL");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.S)));
		append_str("]");
		return;
	}
	if ((insn.S == (1))) {
		append_str("strb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_str("1");
		append_str("]");
		return;
	}
	if ((insn.S == (0))) {
		append_str("strb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("(");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(")");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.ext_type);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_strbi(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.immu64 == (0))) {
		append_str("strb");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	append_str("strb");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("#");
	append_dec((uint32_t) ((insn.immu64)));
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_strh(uint64_t pc, const aarch64_decode_a64_LS_REG_IMM_POST& insn)
{
	uint32_t map_val = 0;
	if ((insn.P == (1))) {
		append_str("strh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		append_str("!");
		return;
	}
	if ((insn.P == (0))) {
		append_str("strh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_strh_reg(uint64_t pc, const aarch64_decode_a64_LS_REG_REG_OFF& insn)
{
	uint32_t map_val = 0;
	append_str("strh_reg");
}

void aarch64_disasm::disassemble_a64_strhi(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.immu64 == (0))) {
		append_str("strh");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	append_str("strh");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("#");
	append_dec((uint32_t) ((insn.immu64)));
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_stri(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.immu64 == (0)) && (insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.immu64 == (0)) && (insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (3))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("str");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immu64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_sttr(uint64_t pc, const aarch64_decode_a64_LS_REG_UNPRIV& insn)
{
	uint32_t map_val = 0;
	append_str("sttr");
}

void aarch64_disasm::disassemble_a64_sttrb(uint64_t pc, const aarch64_decode_a64_LS_REG_UNPRIV& insn)
{
	uint32_t map_val = 0;
	append_str("sttrb");
}

void aarch64_disasm::disassemble_a64_sttrh(uint64_t pc, const aarch64_decode_a64_LS_REG_UNPRIV& insn)
{
	uint32_t map_val = 0;
	append_str("sttrh");
}

void aarch64_disasm::disassemble_a64_stur(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (3))) {
		append_str("stur");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("stur");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms64)));
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_sturb(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	append_str("sturb");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("#");
	append_dec((uint32_t) ((insn.imms64)));
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_sturh(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	append_str("sturh");
}

void aarch64_disasm::disassemble_a64_stxp(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (3))) {
		append_str("stxp");
		append_str(" ");
		map_val = 0 + (insn.rs);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("stxp");
		append_str(" ");
		map_val = 0 + (insn.rs);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt2);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_stxr(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	if ((insn.size == (3))) {
		append_str("stxr");
		append_str(" ");
		map_val = 0 + (insn.rs);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	if ((insn.size == (2))) {
		append_str("stxr");
		append_str(" ");
		map_val = 0 + (insn.rs);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
}

void aarch64_disasm::disassemble_a64_stxrb(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("stxrb");
	append_str(" ");
	map_val = 0 + (insn.rs);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_stxrh(uint64_t pc, const aarch64_decode_a64_LS_EX& insn)
{
	uint32_t map_val = 0;
	append_str("stxrh");
}

void aarch64_disasm::disassemble_a64_sub_ereg(uint64_t pc, const aarch64_decode_a64_ADD_SUB_EREG& insn)
{
	uint32_t map_val = 0;
	if ((insn.S == (1)) && (insn.option == (7)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (3)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (6)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (5)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (4)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (2)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (1)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (0)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.rd == (31)) && (insn.sf == (0))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (7)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (3)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (6)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (5)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (4)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (2)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (1)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.option == (0)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (7)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (3)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (6)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (5)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (4)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (2)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (1)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.option == (0)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (0))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (0))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.option);
		if (map_val < 8) {
			append_str(_map_a64_exttype32[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_sub_sreg(uint64_t pc, const aarch64_decode_a64_ADD_SUB_SREG& insn)
{
	uint32_t map_val = 0;
	if ((insn.S == (1)) && (insn.imm6 == (0)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (1)) && (insn.imm6 == (0)) && (insn.rd == (31)) && (insn.sf == (0))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (1)) && (insn.rd == (31)) && (insn.sf == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.S == (1)) && (insn.rd == (31)) && (insn.sf == (0))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.S == (1)) && (insn.imm6 == (0)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (1)) && (insn.imm6 == (0)) && (insn.sf == (0))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (0)) && (insn.imm6 == (0)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (0)) && (insn.imm6 == (0)) && (insn.sf == (0))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (0))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (0))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		map_val = 0 + (insn.shift);
		if (map_val < 4) {
			append_str(_map_a64_shifttype[map_val]);
		} else {
			append_str("???");
		}
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm6)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_sub_vector(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (0))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_subi(uint64_t pc, const aarch64_decode_a64_ADD_SUB_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.S == (1)) && (insn.rd == (31)) && (insn.sf == (1)) && (insn.shift == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		append_str(",");
		append_str(" ");
		append_str("lsl");
		append_str(" ");
		append_str("#");
		append_str("12");
		return;
	}
	if ((insn.S == (1)) && (insn.rd == (31)) && (insn.sf == (1)) && (insn.shift == (0))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
	if ((insn.S == (1)) && (insn.rd == (31)) && (insn.sf == (0)) && (insn.shift == (1))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		append_str(",");
		append_str(" ");
		append_str("lsl");
		append_str(" ");
		append_str("#");
		append_str("12");
		return;
	}
	if ((insn.S == (1)) && (insn.rd == (31)) && (insn.sf == (0)) && (insn.shift == (0))) {
		append_str("cmp");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (1)) && (insn.shift == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		append_str(",");
		append_str(" ");
		append_str("lsl");
		append_str(" ");
		append_str("#");
		append_str("12");
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (1)) && (insn.shift == (0))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (0)) && (insn.shift == (1))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		append_str(",");
		append_str(" ");
		append_str("lsl");
		append_str(" ");
		append_str("#");
		append_str("12");
		return;
	}
	if ((insn.S == (1)) && (insn.sf == (0)) && (insn.shift == (0))) {
		append_str("subs");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (1)) && (insn.shift == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		append_str(",");
		append_str(" ");
		append_str("lsl");
		append_str(" ");
		append_str("#");
		append_str("12");
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (1)) && (insn.shift == (0))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (0)) && (insn.shift == (1))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		append_str(",");
		append_str(" ");
		append_str("lsl");
		append_str(" ");
		append_str("#");
		append_str("12");
		return;
	}
	if ((insn.S == (0)) && (insn.sf == (0)) && (insn.shift == (0))) {
		append_str("sub");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imm12)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_sys(uint64_t pc, const aarch64_decode_a64_SYSTEM& insn)
{
	uint32_t map_val = 0;
	if ((insn.crm == (3)) && (insn.crn == (8)) && (insn.op1 == (0)) && (insn.op2 == (1))) {
		append_str("tlbi");
		append_str(" ");
		append_str("vae1is");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (3)) && (insn.crn == (8)) && (insn.op1 == (0)) && (insn.op2 == (0))) {
		append_str("tlbi");
		append_str(" ");
		append_str("vmalle1is");
		return;
	}
	if ((insn.crm == (5)) && (insn.crn == (7)) && (insn.op1 == (3)) && (insn.op2 == (1))) {
		append_str("ic");
		append_str(" ");
		append_str("ivau");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (5)) && (insn.crn == (7)) && (insn.op1 == (0)) && (insn.op2 == (0))) {
		append_str("ic");
		append_str(" ");
		append_str("iallu");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (1)) && (insn.crn == (7)) && (insn.op1 == (0)) && (insn.op2 == (0))) {
		append_str("ic");
		append_str(" ");
		append_str("ialluis");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (14)) && (insn.crn == (7)) && (insn.op1 == (3)) && (insn.op2 == (1))) {
		append_str("dc");
		append_str(" ");
		append_str("civac");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (11)) && (insn.crn == (7)) && (insn.op1 == (3)) && (insn.op2 == (1))) {
		append_str("dc");
		append_str(" ");
		append_str("cvau");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (10)) && (insn.crn == (7)) && (insn.op1 == (3)) && (insn.op2 == (1))) {
		append_str("dc");
		append_str(" ");
		append_str("cvac");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (4)) && (insn.crn == (7)) && (insn.op1 == (3)) && (insn.op2 == (1))) {
		append_str("dc");
		append_str(" ");
		append_str("zva");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (14)) && (insn.crn == (7)) && (insn.op1 == (0)) && (insn.op2 == (2))) {
		append_str("dc");
		append_str(" ");
		append_str("cisw");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (10)) && (insn.crn == (7)) && (insn.op1 == (0)) && (insn.op2 == (2))) {
		append_str("dc");
		append_str(" ");
		append_str("csw");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (6)) && (insn.crn == (7)) && (insn.op1 == (0)) && (insn.op2 == (2))) {
		append_str("dc");
		append_str(" ");
		append_str("isw");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crm == (6)) && (insn.crn == (7)) && (insn.op1 == (0)) && (insn.op2 == (1))) {
		append_str("dc");
		append_str(" ");
		append_str("ivac");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.crn == (8))) {
		append_str("tlbi");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	append_str("sys");
	append_str(" ");
	append_str("#");
	append_dec((uint32_t) ((insn.op1)));
	append_str(",");
	append_str(" ");
	append_str("C");
	append_dec((uint32_t) ((insn.crn)));
	append_str(",");
	append_str(" ");
	append_str("C");
	append_dec((uint32_t) ((insn.crm)));
	append_str(",");
	append_str(" ");
	append_str("#");
	append_dec((uint32_t) ((insn.op2)));
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_tbl(uint64_t pc, const aarch64_decode_a64_SIMD_TABLE_LOOKUP& insn)
{
	uint32_t map_val = 0;
	append_str("tbl");
}

void aarch64_disasm::disassemble_a64_tbx(uint64_t pc, const aarch64_decode_a64_SIMD_TABLE_LOOKUP& insn)
{
	uint32_t map_val = 0;
	append_str("tbx");
}

void aarch64_disasm::disassemble_a64_tbz(uint64_t pc, const aarch64_decode_a64_TEST_B_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.b5 == (1)) && (insn.op == (1))) {
		append_str("tbnz");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.bit_pos)));
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
	if ((insn.b5 == (0)) && (insn.op == (1))) {
		append_str("tbnz");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.bit_pos)));
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
	if ((insn.b5 == (1)) && (insn.op == (0))) {
		append_str("tbz");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.bit_pos)));
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
	if ((insn.b5 == (0)) && (insn.op == (0))) {
		append_str("tbz");
		append_str(" ");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.bit_pos)));
		append_str(",");
		append_str(" ");
		append_hex((uint64_t) ((int64_t) pc + (int64_t) (uint64_t) ((insn.imms64))));
		return;
	}
}

void aarch64_disasm::disassemble_a64_uadalp(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	append_str("uadalp");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_uaddl(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	append_str("uaddl");
}

void aarch64_disasm::disassemble_a64_uaddlp(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	append_str("uaddlp");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_uaddlv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("uaddlv");
}

void aarch64_disasm::disassemble_a64_uaddw(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	append_str("uaddw");
}

void aarch64_disasm::disassemble_a64_ubfm(uint64_t pc, const aarch64_decode_a64_BITFIELD& insn)
{
	uint32_t map_val = 0;
	if ((insn.immr == (0)) && (insn.imms == (15)) && (insn.sf == (0))) {
		append_str("uxth");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.immr == (0)) && (insn.imms == (7)) && (insn.sf == (0))) {
		append_str("uxtb");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (1))) {
		append_str("ubfm");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immr)));
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms)));
		return;
	}
	if ((insn.sf == (0))) {
		append_str("ubfm");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.immr)));
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.imms)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ucvtf(uint64_t pc, const aarch64_decode_a64_CVT_FP_I& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1)) && (insn.type == (1))) {
		append_str("ucvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0)) && (insn.type == (1))) {
		append_str("ucvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (1)) && (insn.type == (0))) {
		append_str("ucvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0)) && (insn.type == (0))) {
		append_str("ucvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_ucvtf_simd(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (1)) && (insn.size == (1))) {
		append_str("ucvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (1)) && (insn.size == (0))) {
		append_str("ucvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_sreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.SCALAR == (0))) {
		append_str("ucvtf");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_udiv(uint64_t pc, const aarch64_decode_a64_DP_2S& insn)
{
	uint32_t map_val = 0;
	if ((insn.sf == (1))) {
		append_str("udiv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.sf == (0))) {
		append_str("udiv");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_umaddl(uint64_t pc, const aarch64_decode_a64_DP_3S& insn)
{
	uint32_t map_val = 0;
	append_str("umaddl");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.ra);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_umaxv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("umaxv");
}

void aarch64_disasm::disassemble_a64_uminv(uint64_t pc, const aarch64_decode_a64_SIMD_ACROSS_LANES& insn)
{
	uint32_t map_val = 0;
	append_str("uminv");
}

void aarch64_disasm::disassemble_a64_umov(uint64_t pc, const aarch64_decode_a64_SIMD_COPY& insn)
{
	uint32_t map_val = 0;
	if ((insn.width == (64))) {
		append_str("umov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regx[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		return;
	}
	if ((insn.width == (32))) {
		append_str("umov");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		return;
	}
}

void aarch64_disasm::disassemble_a64_umsubl(uint64_t pc, const aarch64_decode_a64_DP_3S& insn)
{
	uint32_t map_val = 0;
	append_str("umsubl");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.ra);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_umulh(uint64_t pc, const aarch64_decode_a64_DP_3S& insn)
{
	uint32_t map_val = 0;
	append_str("umulh");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_regx[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_umull(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("umull2");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.Q == (0))) {
		append_str("umull");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_ushl(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_SAME& insn)
{
	uint32_t map_val = 0;
	append_str("ushl");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	return;
}

void aarch64_disasm::disassemble_a64_ushll(uint64_t pc, const aarch64_decode_a64_SIMD_SHIFT_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("ushll2");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("ARRG");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.Q == (0))) {
		append_str("ushll");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str("ARRG");
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_ushr(uint64_t pc, const aarch64_decode_a64_SIMD_SHIFT_IMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.SCALAR == (0))) {
		append_str("ushr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
	if ((insn.SCALAR == (1))) {
		append_str("ushr");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_dreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("#");
		append_dec((uint32_t) ((insn.shift_amount)));
		return;
	}
}

void aarch64_disasm::disassemble_a64_usubl(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	append_str("usubl");
}

void aarch64_disasm::disassemble_a64_usubw(uint64_t pc, const aarch64_decode_a64_SIMD_THREE_DIFF& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("usubw2");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
	if ((insn.Q == (0))) {
		append_str("usubw");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rm);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		return;
	}
}

void aarch64_disasm::disassemble_a64_uzp1(uint64_t pc, const aarch64_decode_a64_SIMD_PERMUTE& insn)
{
	uint32_t map_val = 0;
	append_str("uzp1");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_uzp2(uint64_t pc, const aarch64_decode_a64_SIMD_PERMUTE& insn)
{
	uint32_t map_val = 0;
	append_str("uzp2");
	append_str(" ");
	map_val = 0 + (insn.rd);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	map_val = 0 + (insn.rm);
	if (map_val < 32) {
		append_str(_map_a64_vreg[map_val]);
	} else {
		append_str("???");
	}
	append_str(".");
	map_val = 0 + (insn.arrangement);
	if (map_val < 7) {
		append_str(_map_a64_arrg[map_val]);
	} else {
		append_str("???");
	}
	return;
}

void aarch64_disasm::disassemble_a64_vldr(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	append_str("vldr");
}

void aarch64_disasm::disassemble_a64_vldur(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	append_str("vldur");
}

void aarch64_disasm::disassemble_a64_vstr(uint64_t pc, const aarch64_decode_a64_LS_REG_UIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.immu64 == (0))) {
		append_str("str");
		append_str(" ");
		append_str("V");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	append_str("str");
	append_str(" ");
	append_str("V");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("#");
	append_dec((uint32_t) ((insn.immu64)));
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_vstur(uint64_t pc, const aarch64_decode_a64_LS_REG_USIMM& insn)
{
	uint32_t map_val = 0;
	if ((insn.immu64 == (0))) {
		append_str("stur");
		append_str(" ");
		append_str("V");
		map_val = 0 + (insn.rt);
		if (map_val < 32) {
			append_str(_map_a64_regw[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		append_str("[");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_regsx[map_val]);
		} else {
			append_str("???");
		}
		append_str("]");
		return;
	}
	append_str("stur");
	append_str(" ");
	append_str("V");
	map_val = 0 + (insn.rt);
	if (map_val < 32) {
		append_str(_map_a64_regw[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("[");
	map_val = 0 + (insn.rn);
	if (map_val < 32) {
		append_str(_map_a64_regsx[map_val]);
	} else {
		append_str("???");
	}
	append_str(",");
	append_str(" ");
	append_str("#");
	append_dec((uint32_t) ((insn.immu64)));
	append_str("]");
	return;
}

void aarch64_disasm::disassemble_a64_xtn(uint64_t pc, const aarch64_decode_a64_SIMD_TWO_REG_MISC& insn)
{
	uint32_t map_val = 0;
	if ((insn.Q == (1))) {
		append_str("xtn2");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str(" ");
		append_str("XX");
		return;
	}
	if ((insn.Q == (0))) {
		append_str("xtn");
		append_str(" ");
		map_val = 0 + (insn.rd);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		map_val = 0 + (insn.arrangement);
		if (map_val < 7) {
			append_str(_map_a64_arrg[map_val]);
		} else {
			append_str("???");
		}
		append_str(",");
		append_str(" ");
		map_val = 0 + (insn.rn);
		if (map_val < 32) {
			append_str(_map_a64_vreg[map_val]);
		} else {
			append_str("???");
		}
		append_str(".");
		append_str(" ");
		append_str("XX");
		return;
	}
}
