/* SPDX-License-Identifier: MIT */

#include <aarch64-decode.h>
using namespace captive::arch::aarch64;

bool aarch64_decode::decode(uint32_t isa_mode, uint64_t insn_pc, const uint8_t *ptr)
{
	opcode = aarch64_unknown;
	pc = insn_pc;
	ir = *(const uint32_t *) ptr;
	end_of_block = false;
	is_predicated = false;
	bool result = false;
	switch ((aarch64_isa_modes) isa_mode) {
	case aarch64_a64:
		result = decode_a64(ir);
		break;
	}
	if (opcode == aarch64_unknown) {
		end_of_block = true;
		result = true;
	}
	return result;
}

captive::arch::JumpInfo aarch64_decode::get_jump_info()
{
	JumpInfo info;
	info.type = captive::arch::JumpInfo::NONE;
	info.target = 0;
	switch (opcode) {
	case aarch64_a64_b:
		info.type = captive::arch::JumpInfo::DIRECT;
		info.target = pc + ((aarch64_decode_a64_UB_IMM *)this)->imms64;
		break;
	case aarch64_a64_bcond:
		info.type = captive::arch::JumpInfo::INDIRECT;
		break;
	case aarch64_a64_br:
		info.type = captive::arch::JumpInfo::INDIRECT;
		break;
	case aarch64_a64_cbz:
		info.type = captive::arch::JumpInfo::DIRECT_PREDICATED;
		info.target = pc + ((aarch64_decode_a64_CMP_B_IMM *)this)->imms64;
		break;
	case aarch64_a64_drps:
		info.type = captive::arch::JumpInfo::INDIRECT;
		break;
	case aarch64_a64_eret:
		info.type = captive::arch::JumpInfo::INDIRECT;
		break;
	case aarch64_a64_exgen:
		info.type = captive::arch::JumpInfo::INDIRECT;
		break;
	case aarch64_a64_msr_sctlr:
		info.type = captive::arch::JumpInfo::INDIRECT;
		break;
	case aarch64_a64_ret:
		info.type = captive::arch::JumpInfo::INDIRECT;
		break;
	case aarch64_a64_tbz:
		info.type = captive::arch::JumpInfo::DIRECT_PREDICATED;
		info.target = pc + ((aarch64_decode_a64_TEST_B_IMM *)this)->imms64;
		break;
	case aarch64_unknown:
		info.type = captive::arch::JumpInfo::INDIRECT;
		break;
	default: break;
	}
	return info;
}

inline bool aarch64_decode::decode_a64(uint32_t ir)
{
	isa_mode = aarch64_a64;
	// Node 0
	switch (UNSIGNED_BITS(ir, 31, 5)) {
	case 111722624:
	{
		// Node 923
		// Node 924
		opcode = aarch64_a64_msr_sctlr;
		length = 4;
		((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
		((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
		((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
		((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
		((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
		((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
		((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
		end_of_block = true;
		is_predicated = false;
		return true;
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 31, 10)) {
	case 3584003:
	{
		// Node 996
		// Node 997
		opcode = aarch64_a64_rev;
		length = 4;
		((aarch64_decode_a64_DP_1S&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_DP_1S&) * this).S = BITSEL(ir, 29);
		((aarch64_decode_a64_DP_1S&) * this).opcode2 = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_DP_1S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_DP_1S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_DP_1S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_DP_1S&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 1486850:
	{
		// Node 998
		// Node 999
		opcode = aarch64_a64_rev;
		length = 4;
		((aarch64_decode_a64_DP_1S&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_DP_1S&) * this).S = BITSEL(ir, 29);
		((aarch64_decode_a64_DP_1S&) * this).opcode2 = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_DP_1S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_DP_1S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_DP_1S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_DP_1S&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 3584002:
	{
		// Node 1002
		// Node 1003
		opcode = aarch64_a64_rev32;
		length = 4;
		((aarch64_decode_a64_DP_1S&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_DP_1S&) * this).S = BITSEL(ir, 29);
		((aarch64_decode_a64_DP_1S&) * this).opcode2 = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_DP_1S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_DP_1S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_DP_1S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_DP_1S&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 1279503:
	{
		// Node 1402
		// Node 1403
		opcode = aarch64_a64_umov;
		length = 4;
		((aarch64_decode_a64_SIMD_COPY&) * this).Q = BITSEL(ir, 30);
		((aarch64_decode_a64_SIMD_COPY&) * this).op = BITSEL(ir, 29);
		((aarch64_decode_a64_SIMD_COPY&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_SIMD_COPY&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
		((aarch64_decode_a64_SIMD_COPY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_SIMD_COPY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_SIMD_COPY&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 1278479:
	{
		// Node 1404
		// Node 1405
		opcode = aarch64_a64_umov;
		length = 4;
		((aarch64_decode_a64_SIMD_COPY&) * this).Q = BITSEL(ir, 30);
		((aarch64_decode_a64_SIMD_COPY&) * this).op = BITSEL(ir, 29);
		((aarch64_decode_a64_SIMD_COPY&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_SIMD_COPY&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
		((aarch64_decode_a64_SIMD_COPY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_SIMD_COPY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_SIMD_COPY&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 31, 12)) {
	case 872499:
	{
		// Node 73
		// Node 74
		switch (UNSIGNED_BITS(ir, 7, 0)) {
		case 223:
		{
			// Node 75
			opcode = aarch64_a64_barrier;
			length = 4;
			((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
			((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
			((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
			((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 191:
		{
			// Node 76
			opcode = aarch64_a64_barrier;
			length = 4;
			((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
			((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
			((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
			((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 159:
		{
			// Node 77
			opcode = aarch64_a64_barrier;
			length = 4;
			((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
			((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
			((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
			((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 95:
		{
			// Node 148
			opcode = aarch64_a64_clrex;
			length = 4;
			((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
			((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
			((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
			((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 872498:
	{
		// Node 529
		// Node 530
		switch (UNSIGNED_BITS(ir, 4, 0)) {
		case 31:
		{
			// Node 531
			opcode = aarch64_a64_hint;
			length = 4;
			((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
			((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
			((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
			((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 31, 19)) {
	case 3552:
	{
		// Node 449
		// Node 450
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 61:
		{
			// Node 451
			// Node 452
			opcode = aarch64_a64_fmov_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 15, 12)) {
		case 14:
		{
			// Node 876
			// Node 877
			switch ((ir & BIT_LSB(10)) >> 10) {
			case 1:
			{
				// Node 878
				// Node 879
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
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
	case 1504:
	{
		// Node 880
		// Node 881
		switch (UNSIGNED_BITS(ir, 15, 12)) {
		case 14:
		{
			// Node 882
			// Node 883
			switch ((ir & BIT_LSB(10)) >> 10) {
			case 1:
			{
				// Node 884
				// Node 885
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
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
	case 6823:
	{
		// Node 910
		// Node 911
		opcode = aarch64_a64_mrs;
		length = 4;
		((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
		((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
		((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
		((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
		((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
		((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
		((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 6822:
	{
		// Node 912
		// Node 913
		opcode = aarch64_a64_mrs;
		length = 4;
		((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
		((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
		((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
		((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
		((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
		((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
		((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 6816:
	{
		// Node 914
		// Node 915
		switch (UNSIGNED_BITS(ir, 15, 12)) {
		case 4:
		{
			// Node 916
			// Node 917
			switch (UNSIGNED_BITS(ir, 4, 0)) {
			case 31:
			{
				// Node 918
				opcode = aarch64_a64_msr_imm;
				length = 4;
				((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
				((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
				((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
				((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
				((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
				((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
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
	case 6819:
	{
		// Node 919
		// Node 920
		opcode = aarch64_a64_msr_reg;
		length = 4;
		((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
		((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
		((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
		((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
		((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
		((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
		((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 6818:
	{
		// Node 921
		// Node 922
		opcode = aarch64_a64_msr_reg;
		length = 4;
		((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
		((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
		((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
		((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
		((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
		((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
		((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 6817:
	{
		// Node 1354
		// Node 1355
		opcode = aarch64_a64_sys;
		length = 4;
		((aarch64_decode_a64_SYSTEM&) * this).l = BITSEL(ir, 21);
		((aarch64_decode_a64_SYSTEM&) * this).op0 = UNSIGNED_BITS(ir, 20, 19);
		((aarch64_decode_a64_SYSTEM&) * this).op1 = UNSIGNED_BITS(ir, 18, 16);
		((aarch64_decode_a64_SYSTEM&) * this).crn = UNSIGNED_BITS(ir, 15, 12);
		((aarch64_decode_a64_SYSTEM&) * this).crm = UNSIGNED_BITS(ir, 11, 8);
		((aarch64_decode_a64_SYSTEM&) * this).op2 = UNSIGNED_BITS(ir, 7, 5);
		((aarch64_decode_a64_SYSTEM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_SYSTEM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 31, 21)) {
	case 1238:
	{
		// Node 198
		// Node 199
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 19:
		{
			// Node 200
			// Node 201
			opcode = aarch64_a64_crc32;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 23:
		{
			// Node 210
			// Node 211
			opcode = aarch64_a64_crc32c;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 214:
	{
		// Node 202
		// Node 203
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 18:
		{
			// Node 204
			// Node 205
			opcode = aarch64_a64_crc32;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 17:
		{
			// Node 206
			// Node 207
			opcode = aarch64_a64_crc32;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 16:
		{
			// Node 208
			// Node 209
			opcode = aarch64_a64_crc32;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 22:
		{
			// Node 212
			// Node 213
			opcode = aarch64_a64_crc32c;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 21:
		{
			// Node 214
			// Node 215
			opcode = aarch64_a64_crc32c;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 20:
		{
			// Node 216
			// Node 217
			opcode = aarch64_a64_crc32c;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1698:
	{
		// Node 250
		// Node 251
		switch (UNSIGNED_BITS(ir, 4, 0)) {
		case 0:
		{
			// Node 252
			opcode = aarch64_a64_exgen;
			length = 4;
			((aarch64_decode_a64_EX_GEN&) * this).opc = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_EX_GEN&) * this).imm16 = UNSIGNED_BITS(ir, 20, 5);
			((aarch64_decode_a64_EX_GEN&) * this).op2 = UNSIGNED_BITS(ir, 4, 2);
			((aarch64_decode_a64_EX_GEN&) * this).ll = UNSIGNED_BITS(ir, 1, 0);
			((aarch64_decode_a64_EX_GEN&) * this).decode_behaviour();
			end_of_block = true;
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1697:
	{
		// Node 253
		// Node 254
		switch (UNSIGNED_BITS(ir, 4, 0)) {
		case 0:
		{
			// Node 255
			opcode = aarch64_a64_exgen;
			length = 4;
			((aarch64_decode_a64_EX_GEN&) * this).opc = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_EX_GEN&) * this).imm16 = UNSIGNED_BITS(ir, 20, 5);
			((aarch64_decode_a64_EX_GEN&) * this).op2 = UNSIGNED_BITS(ir, 4, 2);
			((aarch64_decode_a64_EX_GEN&) * this).ll = UNSIGNED_BITS(ir, 1, 0);
			((aarch64_decode_a64_EX_GEN&) * this).decode_behaviour();
			end_of_block = true;
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1696:
	{
		// Node 256
		// Node 257
		switch (UNSIGNED_BITS(ir, 4, 0)) {
		case 3:
		{
			// Node 258
			opcode = aarch64_a64_exgen;
			length = 4;
			((aarch64_decode_a64_EX_GEN&) * this).opc = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_EX_GEN&) * this).imm16 = UNSIGNED_BITS(ir, 20, 5);
			((aarch64_decode_a64_EX_GEN&) * this).op2 = UNSIGNED_BITS(ir, 4, 2);
			((aarch64_decode_a64_EX_GEN&) * this).ll = UNSIGNED_BITS(ir, 1, 0);
			((aarch64_decode_a64_EX_GEN&) * this).decode_behaviour();
			end_of_block = true;
			is_predicated = false;
			return true;
			break;
		}
		case 2:
		{
			// Node 259
			opcode = aarch64_a64_exgen;
			length = 4;
			((aarch64_decode_a64_EX_GEN&) * this).opc = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_EX_GEN&) * this).imm16 = UNSIGNED_BITS(ir, 20, 5);
			((aarch64_decode_a64_EX_GEN&) * this).op2 = UNSIGNED_BITS(ir, 4, 2);
			((aarch64_decode_a64_EX_GEN&) * this).ll = UNSIGNED_BITS(ir, 1, 0);
			((aarch64_decode_a64_EX_GEN&) * this).decode_behaviour();
			end_of_block = true;
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 260
			opcode = aarch64_a64_exgen;
			length = 4;
			((aarch64_decode_a64_EX_GEN&) * this).opc = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_EX_GEN&) * this).imm16 = UNSIGNED_BITS(ir, 20, 5);
			((aarch64_decode_a64_EX_GEN&) * this).op2 = UNSIGNED_BITS(ir, 4, 2);
			((aarch64_decode_a64_EX_GEN&) * this).ll = UNSIGNED_BITS(ir, 1, 0);
			((aarch64_decode_a64_EX_GEN&) * this).decode_behaviour();
			end_of_block = true;
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1182:
	{
		// Node 267
		// Node 268
		opcode = aarch64_a64_extr;
		length = 4;
		((aarch64_decode_a64_EXTRACT&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_EXTRACT&) * this).op21 = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_EXTRACT&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_EXTRACT&) * this).o0 = BITSEL(ir, 21);
		((aarch64_decode_a64_EXTRACT&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_EXTRACT&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_EXTRACT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_EXTRACT&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_EXTRACT&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 156:
	{
		// Node 269
		// Node 270
		opcode = aarch64_a64_extr;
		length = 4;
		((aarch64_decode_a64_EXTRACT&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_EXTRACT&) * this).op21 = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_EXTRACT&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_EXTRACT&) * this).o0 = BITSEL(ir, 21);
		((aarch64_decode_a64_EXTRACT&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_EXTRACT&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_EXTRACT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_EXTRACT&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_EXTRACT&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 250:
	{
		// Node 413
		// Node 414
		opcode = aarch64_a64_fm;
		length = 4;
		((aarch64_decode_a64_FP_DP_3&) * this).M = BITSEL(ir, 31);
		((aarch64_decode_a64_FP_DP_3&) * this).S = BITSEL(ir, 29);
		((aarch64_decode_a64_FP_DP_3&) * this).type = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_FP_DP_3&) * this).o1 = BITSEL(ir, 21);
		((aarch64_decode_a64_FP_DP_3&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_FP_DP_3&) * this).o0 = BITSEL(ir, 15);
		((aarch64_decode_a64_FP_DP_3&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_FP_DP_3&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_FP_DP_3&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_FP_DP_3&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 248:
	{
		// Node 415
		// Node 416
		opcode = aarch64_a64_fm;
		length = 4;
		((aarch64_decode_a64_FP_DP_3&) * this).M = BITSEL(ir, 31);
		((aarch64_decode_a64_FP_DP_3&) * this).S = BITSEL(ir, 29);
		((aarch64_decode_a64_FP_DP_3&) * this).type = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_FP_DP_3&) * this).o1 = BITSEL(ir, 21);
		((aarch64_decode_a64_FP_DP_3&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_FP_DP_3&) * this).o0 = BITSEL(ir, 15);
		((aarch64_decode_a64_FP_DP_3&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_FP_DP_3&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_FP_DP_3&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_FP_DP_3&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 883:
	{
		// Node 467
		// Node 468
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 55:
		{
			// Node 469
			// Node 470
			opcode = aarch64_a64_fmul_vector;
			length = 4;
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 251:
	{
		// Node 477
		// Node 478
		opcode = aarch64_a64_fnm;
		length = 4;
		((aarch64_decode_a64_FP_DP_3&) * this).M = BITSEL(ir, 31);
		((aarch64_decode_a64_FP_DP_3&) * this).S = BITSEL(ir, 29);
		((aarch64_decode_a64_FP_DP_3&) * this).type = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_FP_DP_3&) * this).o1 = BITSEL(ir, 21);
		((aarch64_decode_a64_FP_DP_3&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_FP_DP_3&) * this).o0 = BITSEL(ir, 15);
		((aarch64_decode_a64_FP_DP_3&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_FP_DP_3&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_FP_DP_3&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_FP_DP_3&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 249:
	{
		// Node 479
		// Node 480
		opcode = aarch64_a64_fnm;
		length = 4;
		((aarch64_decode_a64_FP_DP_3&) * this).M = BITSEL(ir, 31);
		((aarch64_decode_a64_FP_DP_3&) * this).S = BITSEL(ir, 29);
		((aarch64_decode_a64_FP_DP_3&) * this).type = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_FP_DP_3&) * this).o1 = BITSEL(ir, 21);
		((aarch64_decode_a64_FP_DP_3&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_FP_DP_3&) * this).o0 = BITSEL(ir, 15);
		((aarch64_decode_a64_FP_DP_3&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_FP_DP_3&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_FP_DP_3&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_FP_DP_3&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 631:
	{
		// Node 521
		// Node 522
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 53:
		{
			// Node 523
			// Node 524
			opcode = aarch64_a64_fsub_vector;
			length = 4;
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 880:
	{
		// Node 532
		// Node 533
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 0:
		{
			// Node 534
			// Node 535
			switch ((ir & BIT_LSB(10)) >> 10) {
			case 1:
			{
				// Node 536
				// Node 537
				opcode = aarch64_a64_ins_elem;
				length = 4;
				((aarch64_decode_a64_SIMD_COPY&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_COPY&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_COPY&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_COPY&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
				((aarch64_decode_a64_SIMD_COPY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_COPY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_COPY&) * this).decode_behaviour();
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
	case 624:
	{
		// Node 538
		// Node 539
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 7:
		{
			// Node 540
			// Node 541
			opcode = aarch64_a64_ins_gen;
			length = 4;
			((aarch64_decode_a64_SIMD_COPY&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_COPY&) * this).op = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_COPY&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_SIMD_COPY&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
			((aarch64_decode_a64_SIMD_COPY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_COPY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_COPY&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 11:
		{
			// Node 1068
			// Node 1069
			opcode = aarch64_a64_smov;
			length = 4;
			((aarch64_decode_a64_SIMD_COPY&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_COPY&) * this).op = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_COPY&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_SIMD_COPY&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
			((aarch64_decode_a64_SIMD_COPY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_COPY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_COPY&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1606:
	{
		// Node 588
		// Node 589
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 590
			// Node 591
			opcode = aarch64_a64_ldar;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1094:
	{
		// Node 592
		// Node 593
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 594
			// Node 595
			opcode = aarch64_a64_ldar;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 70:
	{
		// Node 596
		// Node 597
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 598
			// Node 599
			opcode = aarch64_a64_ldarb;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 582:
	{
		// Node 600
		// Node 601
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 602
			// Node 603
			opcode = aarch64_a64_ldarh;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1603:
	{
		// Node 604
		// Node 605
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 606
			// Node 607
			opcode = aarch64_a64_ldaxp;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 846
			// Node 847
			opcode = aarch64_a64_ldxp;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1091:
	{
		// Node 608
		// Node 609
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 610
			// Node 611
			opcode = aarch64_a64_ldaxp;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 848
			// Node 849
			opcode = aarch64_a64_ldxp;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1602:
	{
		// Node 612
		// Node 613
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 614
			// Node 615
			opcode = aarch64_a64_ldaxr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 850
			// Node 851
			opcode = aarch64_a64_ldxr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1090:
	{
		// Node 616
		// Node 617
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 618
			// Node 619
			opcode = aarch64_a64_ldaxr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 852
			// Node 853
			opcode = aarch64_a64_ldxr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 66:
	{
		// Node 620
		// Node 621
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 622
			// Node 623
			opcode = aarch64_a64_ldaxrb;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 854
			// Node 855
			opcode = aarch64_a64_ldxrb;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 578:
	{
		// Node 624
		// Node 625
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 626
			// Node 627
			opcode = aarch64_a64_ldaxrh;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 856
			// Node 857
			opcode = aarch64_a64_ldxrh;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 2018:
	{
		// Node 663
		// Node 1453
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1454
			// Node 1455
			opcode = aarch64_a64_vldur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 664
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 665
			// Node 666
			opcode = aarch64_a64_ldr;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1506:
	{
		// Node 667
		// Node 1456
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1457
			// Node 1458
			opcode = aarch64_a64_vldur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 668
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 669
			// Node 670
			opcode = aarch64_a64_ldr;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 994:
	{
		// Node 671
		// Node 1459
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1460
			// Node 1461
			opcode = aarch64_a64_vldur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 672
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 673
			// Node 674
			opcode = aarch64_a64_ldr;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 486:
	{
		// Node 675
		// Node 1450
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1451
			// Node 1452
			opcode = aarch64_a64_vldur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 676
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 677
			// Node 678
			opcode = aarch64_a64_ldr;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 482:
	{
		// Node 679
		// Node 1462
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1463
			// Node 1464
			opcode = aarch64_a64_vldur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 680
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 681
			// Node 682
			opcode = aarch64_a64_ldr;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1986:
	{
		// Node 683
		// Node 801
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 802
			// Node 803
			opcode = aarch64_a64_ldtr;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 828
			// Node 829
			opcode = aarch64_a64_ldur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 684
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 685
			// Node 686
			opcode = aarch64_a64_ldr;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1474:
	{
		// Node 687
		// Node 804
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 805
			// Node 806
			opcode = aarch64_a64_ldtr;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 830
			// Node 831
			opcode = aarch64_a64_ldur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 688
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 689
			// Node 690
			opcode = aarch64_a64_ldr;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1477:
	{
		// Node 697
		// Node 698
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 699
			// Node 700
			opcode = aarch64_a64_ldr_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1987:
	{
		// Node 701
		// Node 702
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 703
			// Node 704
			opcode = aarch64_a64_ldr_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1475:
	{
		// Node 705
		// Node 706
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 707
			// Node 708
			opcode = aarch64_a64_ldr_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 487:
	{
		// Node 709
		// Node 710
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 711
			// Node 712
			opcode = aarch64_a64_ldr_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 2019:
	{
		// Node 713
		// Node 714
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 715
			// Node 716
			opcode = aarch64_a64_ldr_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1507:
	{
		// Node 717
		// Node 718
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 719
			// Node 720
			opcode = aarch64_a64_ldr_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 995:
	{
		// Node 721
		// Node 722
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 723
			// Node 724
			opcode = aarch64_a64_ldr_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 483:
	{
		// Node 725
		// Node 726
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 727
			// Node 728
			opcode = aarch64_a64_ldr_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 454:
	{
		// Node 729
		// Node 807
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 808
			// Node 809
			opcode = aarch64_a64_ldtrb;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 832
			// Node 833
			opcode = aarch64_a64_ldurb;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 730
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 731
			// Node 732
			opcode = aarch64_a64_ldrb;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 452:
	{
		// Node 733
		// Node 810
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 811
			// Node 812
			opcode = aarch64_a64_ldtrb;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 834
			// Node 835
			opcode = aarch64_a64_ldurb;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 734
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 735
			// Node 736
			opcode = aarch64_a64_ldrb;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 450:
	{
		// Node 737
		// Node 813
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 814
			// Node 815
			opcode = aarch64_a64_ldtrb;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 836
			// Node 837
			opcode = aarch64_a64_ldurb;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 738
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 739
			// Node 740
			opcode = aarch64_a64_ldrb;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 455:
	{
		// Node 741
		// Node 742
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 743
			// Node 744
			opcode = aarch64_a64_ldrb_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 453:
	{
		// Node 745
		// Node 746
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 747
			// Node 748
			opcode = aarch64_a64_ldrb_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 451:
	{
		// Node 749
		// Node 750
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 751
			// Node 752
			opcode = aarch64_a64_ldrb_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 966:
	{
		// Node 759
		// Node 816
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 817
			// Node 818
			opcode = aarch64_a64_ldtrh;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 838
			// Node 839
			opcode = aarch64_a64_ldurh;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 760
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 761
			// Node 762
			opcode = aarch64_a64_ldrh;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 964:
	{
		// Node 763
		// Node 819
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 820
			// Node 821
			opcode = aarch64_a64_ldtrh;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 840
			// Node 841
			opcode = aarch64_a64_ldurh;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 764
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 765
			// Node 766
			opcode = aarch64_a64_ldrh;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 962:
	{
		// Node 767
		// Node 822
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 823
			// Node 824
			opcode = aarch64_a64_ldtrh;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 842
			// Node 843
			opcode = aarch64_a64_ldurh;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 768
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 769
			// Node 770
			opcode = aarch64_a64_ldrh;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 967:
	{
		// Node 771
		// Node 772
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 773
			// Node 774
			opcode = aarch64_a64_ldrh_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 965:
	{
		// Node 775
		// Node 776
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 777
			// Node 778
			opcode = aarch64_a64_ldrh_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 963:
	{
		// Node 779
		// Node 780
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 781
			// Node 782
			opcode = aarch64_a64_ldrh_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1476:
	{
		// Node 793
		// Node 825
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 826
			// Node 827
			opcode = aarch64_a64_ldtrsw;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 844
			// Node 845
			opcode = aarch64_a64_ldursw;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 794
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 795
			// Node 796
			opcode = aarch64_a64_ldrsw;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1988:
	{
		// Node 976
		// Node 988
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 989
			// Node 990
			opcode = aarch64_a64_prfum;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 977
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 978
			// Node 979
			opcode = aarch64_a64_prfm;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1989:
	{
		// Node 982
		// Node 983
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 984
			// Node 985
			opcode = aarch64_a64_prfm_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1241:
	{
		// Node 1054
		// Node 1055
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 0:
		{
			// Node 1056
			// Node 1057
			opcode = aarch64_a64_smaddl;
			length = 4;
			((aarch64_decode_a64_DP_3S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_3S&) * this).op54 = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_DP_3S&) * this).op31 = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_DP_3S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_3S&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_DP_3S&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_DP_3S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_3S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_3S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 1074
			// Node 1075
			opcode = aarch64_a64_smsubl;
			length = 4;
			((aarch64_decode_a64_DP_3S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_3S&) * this).op54 = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_DP_3S&) * this).op31 = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_DP_3S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_3S&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_DP_3S&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_DP_3S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_3S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_3S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 112:
	{
		// Node 1070
		// Node 1071
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 11:
		{
			// Node 1072
			// Node 1073
			opcode = aarch64_a64_smov;
			length = 4;
			((aarch64_decode_a64_SIMD_COPY&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_COPY&) * this).op = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_COPY&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_SIMD_COPY&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
			((aarch64_decode_a64_SIMD_COPY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_COPY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_COPY&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 15:
		{
			// Node 1406
			// Node 1407
			opcode = aarch64_a64_umov;
			length = 4;
			((aarch64_decode_a64_SIMD_COPY&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_COPY&) * this).op = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_COPY&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_SIMD_COPY&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
			((aarch64_decode_a64_SIMD_COPY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_COPY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_COPY&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1242:
	{
		// Node 1076
		// Node 1077
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 0:
		{
			// Node 1078
			// Node 1079
			opcode = aarch64_a64_smulh;
			length = 4;
			((aarch64_decode_a64_DP_3S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_3S&) * this).op54 = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_DP_3S&) * this).op31 = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_DP_3S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_3S&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_DP_3S&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_DP_3S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_3S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_3S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1604:
	{
		// Node 1156
		// Node 1157
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1158
			// Node 1159
			opcode = aarch64_a64_stlr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1092:
	{
		// Node 1160
		// Node 1161
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1162
			// Node 1163
			opcode = aarch64_a64_stlr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 68:
	{
		// Node 1164
		// Node 1165
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1166
			// Node 1167
			opcode = aarch64_a64_stlrb;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 580:
	{
		// Node 1168
		// Node 1169
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1170
			// Node 1171
			opcode = aarch64_a64_stlrh;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1601:
	{
		// Node 1172
		// Node 1173
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1174
			// Node 1175
			opcode = aarch64_a64_stlxp;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1326
			// Node 1327
			opcode = aarch64_a64_stxp;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1089:
	{
		// Node 1176
		// Node 1177
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1178
			// Node 1179
			opcode = aarch64_a64_stlxp;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1328
			// Node 1329
			opcode = aarch64_a64_stxp;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1600:
	{
		// Node 1180
		// Node 1181
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1182
			// Node 1183
			opcode = aarch64_a64_stlxr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1330
			// Node 1331
			opcode = aarch64_a64_stxr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1088:
	{
		// Node 1184
		// Node 1185
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1186
			// Node 1187
			opcode = aarch64_a64_stlxr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1332
			// Node 1333
			opcode = aarch64_a64_stxr;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 64:
	{
		// Node 1188
		// Node 1189
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1190
			// Node 1191
			opcode = aarch64_a64_stlxrb;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1334
			// Node 1335
			opcode = aarch64_a64_stxrb;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 576:
	{
		// Node 1192
		// Node 1193
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 1:
		{
			// Node 1194
			// Node 1195
			opcode = aarch64_a64_stlxrh;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1336
			// Node 1337
			opcode = aarch64_a64_stxrh;
			length = 4;
			((aarch64_decode_a64_LS_EX&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_EX&) * this).o2 = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_EX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_EX&) * this).o1 = BITSEL(ir, 21);
			((aarch64_decode_a64_LS_EX&) * this).rs = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_EX&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_LS_EX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_EX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_EX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_EX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 2016:
	{
		// Node 1226
		// Node 1478
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1479
			// Node 1480
			opcode = aarch64_a64_vstur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 1227
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 1228
			// Node 1229
			opcode = aarch64_a64_str;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1504:
	{
		// Node 1230
		// Node 1481
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1482
			// Node 1483
			opcode = aarch64_a64_vstur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 1231
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 1232
			// Node 1233
			opcode = aarch64_a64_str;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 992:
	{
		// Node 1234
		// Node 1484
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1485
			// Node 1486
			opcode = aarch64_a64_vstur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 1235
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 1236
			// Node 1237
			opcode = aarch64_a64_str;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 484:
	{
		// Node 1238
		// Node 1475
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1476
			// Node 1477
			opcode = aarch64_a64_vstur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 1239
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 1240
			// Node 1241
			opcode = aarch64_a64_str;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 480:
	{
		// Node 1242
		// Node 1487
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 1488
			// Node 1489
			opcode = aarch64_a64_vstur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 1243
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 1244
			// Node 1245
			opcode = aarch64_a64_str;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1984:
	{
		// Node 1246
		// Node 1306
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1307
			// Node 1308
			opcode = aarch64_a64_sttr;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1318
			// Node 1319
			opcode = aarch64_a64_stur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 1247
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 1248
			// Node 1249
			opcode = aarch64_a64_str;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1472:
	{
		// Node 1250
		// Node 1309
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1310
			// Node 1311
			opcode = aarch64_a64_sttr;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1320
			// Node 1321
			opcode = aarch64_a64_stur;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 1251
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 1252
			// Node 1253
			opcode = aarch64_a64_str;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1985:
	{
		// Node 1254
		// Node 1255
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1256
			// Node 1257
			opcode = aarch64_a64_str_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1473:
	{
		// Node 1258
		// Node 1259
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1260
			// Node 1261
			opcode = aarch64_a64_str_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 485:
	{
		// Node 1262
		// Node 1263
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1264
			// Node 1265
			opcode = aarch64_a64_str_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 2017:
	{
		// Node 1266
		// Node 1267
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1268
			// Node 1269
			opcode = aarch64_a64_str_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1505:
	{
		// Node 1270
		// Node 1271
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1272
			// Node 1273
			opcode = aarch64_a64_str_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 993:
	{
		// Node 1274
		// Node 1275
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1276
			// Node 1277
			opcode = aarch64_a64_str_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 481:
	{
		// Node 1278
		// Node 1279
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1280
			// Node 1281
			opcode = aarch64_a64_str_reg_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 448:
	{
		// Node 1282
		// Node 1312
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1313
			// Node 1314
			opcode = aarch64_a64_sttrb;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1322
			// Node 1323
			opcode = aarch64_a64_sturb;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 1283
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 1284
			// Node 1285
			opcode = aarch64_a64_strb;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 449:
	{
		// Node 1286
		// Node 1287
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1288
			// Node 1289
			opcode = aarch64_a64_strb_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 960:
	{
		// Node 1292
		// Node 1315
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1316
			// Node 1317
			opcode = aarch64_a64_sttrh;
			length = 4;
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_UNPRIV&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 1324
			// Node 1325
			opcode = aarch64_a64_sturh;
			length = 4;
			((aarch64_decode_a64_LS_REG_USIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_USIMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 1293
		switch ((ir & BIT_LSB(10)) >> 10) {
		case 1:
		{
			// Node 1294
			// Node 1295
			opcode = aarch64_a64_strh;
			length = 4;
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).imm9 = UNSIGNED_BITS(ir, 20, 12);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).P = BITSEL(ir, 11);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_IMM_POST&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 961:
	{
		// Node 1296
		// Node 1297
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 1298
			// Node 1299
			opcode = aarch64_a64_strh_reg;
			length = 4;
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).size = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).X = BITSEL(ir, 23);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option21 = UNSIGNED_BITS(ir, 15, 14);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).option0 = BITSEL(ir, 13);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).S = BITSEL(ir, 12);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_REG_OFF&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1245:
	{
		// Node 1394
		// Node 1395
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 0:
		{
			// Node 1396
			// Node 1397
			opcode = aarch64_a64_umaddl;
			length = 4;
			((aarch64_decode_a64_DP_3S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_3S&) * this).op54 = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_DP_3S&) * this).op31 = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_DP_3S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_3S&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_DP_3S&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_DP_3S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_3S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_3S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 1408
			// Node 1409
			opcode = aarch64_a64_umsubl;
			length = 4;
			((aarch64_decode_a64_DP_3S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_3S&) * this).op54 = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_DP_3S&) * this).op31 = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_DP_3S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_3S&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_DP_3S&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_DP_3S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_3S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_3S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1246:
	{
		// Node 1410
		// Node 1411
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 0:
		{
			// Node 1412
			// Node 1413
			opcode = aarch64_a64_umulh;
			length = 4;
			((aarch64_decode_a64_DP_3S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_3S&) * this).op54 = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_DP_3S&) * this).op31 = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_DP_3S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_3S&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_DP_3S&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_DP_3S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_3S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_3S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 31, 22)) {
	case 969:
	{
		// Node 47
		// Node 48
		opcode = aarch64_a64_andi;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 968:
	{
		// Node 49
		// Node 50
		opcode = aarch64_a64_andi;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 456:
	{
		// Node 51
		// Node 52
		opcode = aarch64_a64_andi;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 585:
	{
		// Node 53
		// Node 54
		opcode = aarch64_a64_andi;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 584:
	{
		// Node 55
		// Node 56
		opcode = aarch64_a64_andi;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 72:
	{
		// Node 57
		// Node 58
		opcode = aarch64_a64_andi;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 717:
	{
		// Node 82
		// Node 83
		opcode = aarch64_a64_bfm;
		length = 4;
		((aarch64_decode_a64_BITFIELD&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_BITFIELD&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_BITFIELD&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_BITFIELD&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_BITFIELD&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_BITFIELD&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_BITFIELD&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_BITFIELD&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 204:
	{
		// Node 84
		// Node 85
		opcode = aarch64_a64_bfm;
		length = 4;
		((aarch64_decode_a64_BITFIELD&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_BITFIELD&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_BITFIELD&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_BITFIELD&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_BITFIELD&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_BITFIELD&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_BITFIELD&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_BITFIELD&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 841:
	{
		// Node 241
		// Node 242
		opcode = aarch64_a64_eori;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 840:
	{
		// Node 243
		// Node 244
		opcode = aarch64_a64_eori;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 328:
	{
		// Node 245
		// Node 246
		opcode = aarch64_a64_eori;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 673:
	{
		// Node 628
		// Node 629
		opcode = aarch64_a64_ldnp;
		length = 4;
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 161:
	{
		// Node 630
		// Node 631
		opcode = aarch64_a64_ldnp;
		length = 4;
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 677:
	{
		// Node 632
		// Node 633
		opcode = aarch64_a64_ldp;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 165:
	{
		// Node 634
		// Node 635
		opcode = aarch64_a64_ldp;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 693:
	{
		// Node 636
		// Node 637
		opcode = aarch64_a64_ldp_simd;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 437:
	{
		// Node 638
		// Node 639
		opcode = aarch64_a64_ldp_simd;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 181:
	{
		// Node 640
		// Node 641
		opcode = aarch64_a64_ldp_simd;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 421:
	{
		// Node 657
		// Node 658
		opcode = aarch64_a64_ldpsw;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 231:
	{
		// Node 753
		// Node 754
		opcode = aarch64_a64_ldrbi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 230:
	{
		// Node 755
		// Node 756
		opcode = aarch64_a64_ldrbi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 229:
	{
		// Node 757
		// Node 758
		opcode = aarch64_a64_ldrbi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 487:
	{
		// Node 783
		// Node 784
		opcode = aarch64_a64_ldrhi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 486:
	{
		// Node 785
		// Node 786
		opcode = aarch64_a64_ldrhi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 485:
	{
		// Node 787
		// Node 788
		opcode = aarch64_a64_ldrhi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 997:
	{
		// Node 789
		// Node 790
		opcode = aarch64_a64_ldri;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 741:
	{
		// Node 791
		// Node 792
		opcode = aarch64_a64_ldri;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 742:
	{
		// Node 799
		// Node 800
		opcode = aarch64_a64_ldrswi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 713:
	{
		// Node 967
		// Node 968
		opcode = aarch64_a64_orri;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 712:
	{
		// Node 969
		// Node 970
		opcode = aarch64_a64_orri;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 200:
	{
		// Node 971
		// Node 972
		opcode = aarch64_a64_orri;
		length = 4;
		((aarch64_decode_a64_LOGICAL_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 998:
	{
		// Node 986
		// Node 987
		opcode = aarch64_a64_prfmi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 589:
	{
		// Node 1022
		// Node 1023
		opcode = aarch64_a64_sbfm;
		length = 4;
		((aarch64_decode_a64_BITFIELD&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_BITFIELD&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_BITFIELD&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_BITFIELD&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_BITFIELD&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_BITFIELD&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_BITFIELD&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_BITFIELD&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 76:
	{
		// Node 1024
		// Node 1025
		opcode = aarch64_a64_sbfm;
		length = 4;
		((aarch64_decode_a64_BITFIELD&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_BITFIELD&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_BITFIELD&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_BITFIELD&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_BITFIELD&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_BITFIELD&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_BITFIELD&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_BITFIELD&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 672:
	{
		// Node 1196
		// Node 1197
		opcode = aarch64_a64_stnp;
		length = 4;
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 160:
	{
		// Node 1198
		// Node 1199
		opcode = aarch64_a64_stnp;
		length = 4;
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_NO_ALLOC&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 676:
	{
		// Node 1200
		// Node 1201
		opcode = aarch64_a64_stp;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 164:
	{
		// Node 1202
		// Node 1203
		opcode = aarch64_a64_stp;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 692:
	{
		// Node 1204
		// Node 1205
		opcode = aarch64_a64_stp_simd;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 436:
	{
		// Node 1206
		// Node 1207
		opcode = aarch64_a64_stp_simd;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 180:
	{
		// Node 1208
		// Node 1209
		opcode = aarch64_a64_stp_simd;
		length = 4;
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).L = BITSEL(ir, 22);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_PAIR_OFF&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 228:
	{
		// Node 1290
		// Node 1291
		opcode = aarch64_a64_strbi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 484:
	{
		// Node 1300
		// Node 1301
		opcode = aarch64_a64_strhi;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 996:
	{
		// Node 1302
		// Node 1303
		opcode = aarch64_a64_stri;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 740:
	{
		// Node 1304
		// Node 1305
		opcode = aarch64_a64_stri;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 845:
	{
		// Node 1376
		// Node 1377
		opcode = aarch64_a64_ubfm;
		length = 4;
		((aarch64_decode_a64_BITFIELD&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_BITFIELD&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_BITFIELD&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_BITFIELD&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_BITFIELD&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_BITFIELD&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_BITFIELD&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_BITFIELD&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 332:
	{
		// Node 1378
		// Node 1379
		opcode = aarch64_a64_ubfm;
		length = 4;
		((aarch64_decode_a64_BITFIELD&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_BITFIELD&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_BITFIELD&) * this).N = BITSEL(ir, 22);
		((aarch64_decode_a64_BITFIELD&) * this).immr = UNSIGNED_BITS(ir, 21, 16);
		((aarch64_decode_a64_BITFIELD&) * this).imms = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_BITFIELD&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_BITFIELD&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_BITFIELD&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 247:
	{
		// Node 1440
		// Node 1441
		opcode = aarch64_a64_vldr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 1013:
	{
		// Node 1442
		// Node 1443
		opcode = aarch64_a64_vldr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 757:
	{
		// Node 1444
		// Node 1445
		opcode = aarch64_a64_vldr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 501:
	{
		// Node 1446
		// Node 1447
		opcode = aarch64_a64_vldr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 245:
	{
		// Node 1448
		// Node 1449
		opcode = aarch64_a64_vldr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 246:
	{
		// Node 1465
		// Node 1466
		opcode = aarch64_a64_vstr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 1012:
	{
		// Node 1467
		// Node 1468
		opcode = aarch64_a64_vstr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 756:
	{
		// Node 1469
		// Node 1470
		opcode = aarch64_a64_vstr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 500:
	{
		// Node 1471
		// Node 1472
		opcode = aarch64_a64_vstr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 244:
	{
		// Node 1473
		// Node 1474
		opcode = aarch64_a64_vstr;
		length = 4;
		((aarch64_decode_a64_LS_REG_UIMM&) * this).size = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).opc = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LS_REG_UIMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 31, 23)) {
	case 190:
	{
		// Node 1044
		// Node 1045
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 21:
		{
			// Node 1046
			// Node 1047
			opcode = aarch64_a64_shl_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immh = UNSIGNED_BITS(ir, 22, 19);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immb = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 1090
			// Node 1091
			opcode = aarch64_a64_sshr;
			length = 4;
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immh = UNSIGNED_BITS(ir, 22, 19);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immb = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 254:
	{
		// Node 1428
		// Node 1429
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 1:
		{
			// Node 1430
			// Node 1431
			opcode = aarch64_a64_ushr;
			length = 4;
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immh = UNSIGNED_BITS(ir, 22, 19);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immb = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 31, 24)) {
	case 84:
	{
		// Node 78
		// Node 79
		switch ((ir & BIT_LSB(4)) >> 4) {
		case 0:
		{
			// Node 80
			// Node 81
			opcode = aarch64_a64_bcond;
			length = 4;
			((aarch64_decode_a64_COND_B_IMM&) * this).o1 = BITSEL(ir, 24);
			((aarch64_decode_a64_COND_B_IMM&) * this).imm19 = UNSIGNED_BITS(ir, 23, 5);
			((aarch64_decode_a64_COND_B_IMM&) * this).o0 = BITSEL(ir, 4);
			((aarch64_decode_a64_COND_B_IMM&) * this).cond = UNSIGNED_BITS(ir, 3, 0);
			((aarch64_decode_a64_COND_B_IMM&) * this).decode_behaviour();
			end_of_block = true;
			is_predicated = ((aarch64_decode_a64_COND_B_IMM&) * this).decode_is_predicated();
			return true;
			break;
		}
		}
		break;
	}
	case 88:
	{
		// Node 691
		// Node 692
		opcode = aarch64_a64_ldr_lit;
		length = 4;
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).imm19 = UNSIGNED_BITS(ir, 23, 5);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 24:
	{
		// Node 693
		// Node 694
		opcode = aarch64_a64_ldr_lit;
		length = 4;
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).imm19 = UNSIGNED_BITS(ir, 23, 5);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 152:
	{
		// Node 797
		// Node 798
		opcode = aarch64_a64_ldrsw_lit;
		length = 4;
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).imm19 = UNSIGNED_BITS(ir, 23, 5);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 216:
	{
		// Node 980
		// Node 981
		opcode = aarch64_a64_prfm_lit;
		length = 4;
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).imm19 = UNSIGNED_BITS(ir, 23, 5);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 30:
	{
		// Node 1492
		switch (UNSIGNED_BITS(ir, 23, 10)) {
		case 6192:
		{
			// Node 281
			// Node 282
			opcode = aarch64_a64_fabs;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2096:
		{
			// Node 283
			// Node 284
			opcode = aarch64_a64_fabs;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6288:
		{
			// Node 327
			// Node 328
			opcode = aarch64_a64_fcvt;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6384:
		{
			// Node 329
			// Node 330
			opcode = aarch64_a64_fcvt;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2224:
		{
			// Node 331
			// Node 332
			opcode = aarch64_a64_fcvt;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2288:
		{
			// Node 333
			// Node 334
			opcode = aarch64_a64_fcvt;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 14512:
		{
			// Node 335
			// Node 336
			opcode = aarch64_a64_fcvt;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 14480:
		{
			// Node 337
			// Node 338
			opcode = aarch64_a64_fcvt;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6160:
		{
			// Node 433
			// Node 434
			opcode = aarch64_a64_fmov;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2064:
		{
			// Node 435
			// Node 436
			opcode = aarch64_a64_fmov;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6224:
		{
			// Node 473
			// Node 474
			opcode = aarch64_a64_fneg;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2128:
		{
			// Node 475
			// Node 476
			opcode = aarch64_a64_fneg;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6640:
		{
			// Node 485
			// Node 486
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2544:
		{
			// Node 487
			// Node 488
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6608:
		{
			// Node 489
			// Node 490
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2512:
		{
			// Node 491
			// Node 492
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6544:
		{
			// Node 493
			// Node 494
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2448:
		{
			// Node 495
			// Node 496
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6512:
		{
			// Node 497
			// Node 498
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2416:
		{
			// Node 499
			// Node 500
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6480:
		{
			// Node 501
			// Node 502
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2384:
		{
			// Node 503
			// Node 504
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6448:
		{
			// Node 505
			// Node 506
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2352:
		{
			// Node 507
			// Node 508
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6416:
		{
			// Node 509
			// Node 510
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2320:
		{
			// Node 511
			// Node 512
			opcode = aarch64_a64_frintx;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6256:
		{
			// Node 513
			// Node 514
			opcode = aarch64_a64_fsqrt;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2160:
		{
			// Node 515
			// Node 516
			opcode = aarch64_a64_fsqrt;
			length = 4;
			((aarch64_decode_a64_FP_DP_1&) * this).M = BITSEL(ir, 31);
			((aarch64_decode_a64_FP_DP_1&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_FP_DP_1&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_FP_DP_1&) * this).opcode = UNSIGNED_BITS(ir, 20, 15);
			((aarch64_decode_a64_FP_DP_1&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_FP_DP_1&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_FP_DP_1&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 23, 16)) {
		case 89:
		{
			// Node 387
			// Node 388
			opcode = aarch64_a64_fcvtz_fxp;
			length = 4;
			((aarch64_decode_a64_CVT_FP_FXP&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).scale = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 25:
		{
			// Node 389
			// Node 390
			opcode = aarch64_a64_fcvtz_fxp;
			length = 4;
			((aarch64_decode_a64_CVT_FP_FXP&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).scale = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 88:
		{
			// Node 395
			// Node 396
			opcode = aarch64_a64_fcvtz_fxp;
			length = 4;
			((aarch64_decode_a64_CVT_FP_FXP&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).scale = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 24:
		{
			// Node 397
			// Node 398
			opcode = aarch64_a64_fcvtz_fxp;
			length = 4;
			((aarch64_decode_a64_CVT_FP_FXP&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).scale = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 23, 21)) {
		case 3:
		{
			// Node 285
			// Node 286
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 10:
			{
				// Node 287
				// Node 288
				opcode = aarch64_a64_fadd;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 8:
			{
				// Node 311
				// Node 312
				switch (UNSIGNED_BITS(ir, 4, 0)) {
				case 8:
				{
					// Node 313
					opcode = aarch64_a64_fcmpe;
					length = 4;
					((aarch64_decode_a64_FP_CMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CMP&) * this).op = UNSIGNED_BITS(ir, 15, 14);
					((aarch64_decode_a64_FP_CMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CMP&) * this).opcode2 = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_FP_CMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 0:
				{
					// Node 314
					opcode = aarch64_a64_fcmpe;
					length = 4;
					((aarch64_decode_a64_FP_CMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CMP&) * this).op = UNSIGNED_BITS(ir, 15, 14);
					((aarch64_decode_a64_FP_CMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CMP&) * this).opcode2 = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_FP_CMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 24:
				{
					// Node 319
					opcode = aarch64_a64_fcmpe;
					length = 4;
					((aarch64_decode_a64_FP_CMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CMP&) * this).op = UNSIGNED_BITS(ir, 15, 14);
					((aarch64_decode_a64_FP_CMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CMP&) * this).opcode2 = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_FP_CMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 16:
				{
					// Node 320
					opcode = aarch64_a64_fcmpe;
					length = 4;
					((aarch64_decode_a64_FP_CMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CMP&) * this).op = UNSIGNED_BITS(ir, 15, 14);
					((aarch64_decode_a64_FP_CMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CMP&) * this).opcode2 = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_FP_CMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 6:
			{
				// Node 409
				// Node 410
				opcode = aarch64_a64_fdiv;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2:
			{
				// Node 463
				// Node 464
				opcode = aarch64_a64_fmul;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 34:
			{
				// Node 481
				// Node 482
				opcode = aarch64_a64_fnmul;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 14:
			{
				// Node 517
				// Node 518
				opcode = aarch64_a64_fsub;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			// Node 457
			switch (UNSIGNED_BITS(ir, 12, 5)) {
			case 128:
			{
				// Node 458
				// Node 459
				opcode = aarch64_a64_fmovi;
				length = 4;
				((aarch64_decode_a64_FP_IMM&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_IMM&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_IMM&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_IMM&) * this).imm8 = UNSIGNED_BITS(ir, 20, 13);
				((aarch64_decode_a64_FP_IMM&) * this).imm5 = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			// Node 293
			switch (UNSIGNED_BITS(ir, 11, 10)) {
			case 1:
			{
				// Node 294
				// Node 295
				switch ((ir & BIT_LSB(4)) >> 4) {
				case 1:
				{
					// Node 296
					// Node 297
					opcode = aarch64_a64_fccmpe;
					length = 4;
					((aarch64_decode_a64_FP_CCMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CCMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CCMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CCMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CCMP&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_FP_CCMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CCMP&) * this).op = BITSEL(ir, 4);
					((aarch64_decode_a64_FP_CCMP&) * this).nzcv = UNSIGNED_BITS(ir, 3, 0);
					((aarch64_decode_a64_FP_CCMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 0:
				{
					// Node 298
					// Node 299
					opcode = aarch64_a64_fccmpe;
					length = 4;
					((aarch64_decode_a64_FP_CCMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CCMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CCMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CCMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CCMP&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_FP_CCMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CCMP&) * this).op = BITSEL(ir, 4);
					((aarch64_decode_a64_FP_CCMP&) * this).nzcv = UNSIGNED_BITS(ir, 3, 0);
					((aarch64_decode_a64_FP_CCMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 3:
			{
				// Node 323
				// Node 324
				opcode = aarch64_a64_fcsel;
				length = 4;
				((aarch64_decode_a64_FP_CSEL&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_CSEL&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_CSEL&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_CSEL&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_CSEL&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_CSEL&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_CSEL&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_CSEL&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 1:
		{
			// Node 289
			// Node 290
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 10:
			{
				// Node 291
				// Node 292
				opcode = aarch64_a64_fadd;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 8:
			{
				// Node 315
				// Node 316
				switch (UNSIGNED_BITS(ir, 4, 0)) {
				case 8:
				{
					// Node 317
					opcode = aarch64_a64_fcmpe;
					length = 4;
					((aarch64_decode_a64_FP_CMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CMP&) * this).op = UNSIGNED_BITS(ir, 15, 14);
					((aarch64_decode_a64_FP_CMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CMP&) * this).opcode2 = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_FP_CMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 0:
				{
					// Node 318
					opcode = aarch64_a64_fcmpe;
					length = 4;
					((aarch64_decode_a64_FP_CMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CMP&) * this).op = UNSIGNED_BITS(ir, 15, 14);
					((aarch64_decode_a64_FP_CMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CMP&) * this).opcode2 = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_FP_CMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 24:
				{
					// Node 321
					opcode = aarch64_a64_fcmpe;
					length = 4;
					((aarch64_decode_a64_FP_CMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CMP&) * this).op = UNSIGNED_BITS(ir, 15, 14);
					((aarch64_decode_a64_FP_CMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CMP&) * this).opcode2 = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_FP_CMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 16:
				{
					// Node 322
					opcode = aarch64_a64_fcmpe;
					length = 4;
					((aarch64_decode_a64_FP_CMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CMP&) * this).op = UNSIGNED_BITS(ir, 15, 14);
					((aarch64_decode_a64_FP_CMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CMP&) * this).opcode2 = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_FP_CMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 6:
			{
				// Node 411
				// Node 412
				opcode = aarch64_a64_fdiv;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2:
			{
				// Node 465
				// Node 466
				opcode = aarch64_a64_fmul;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 34:
			{
				// Node 483
				// Node 484
				opcode = aarch64_a64_fnmul;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 14:
			{
				// Node 519
				// Node 520
				opcode = aarch64_a64_fsub;
				length = 4;
				((aarch64_decode_a64_FP_DP_2&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_DP_2&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_DP_2&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_DP_2&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_DP_2&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_DP_2&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_DP_2&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_DP_2&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			// Node 460
			switch (UNSIGNED_BITS(ir, 12, 5)) {
			case 128:
			{
				// Node 461
				// Node 462
				opcode = aarch64_a64_fmovi;
				length = 4;
				((aarch64_decode_a64_FP_IMM&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_IMM&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_IMM&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_IMM&) * this).imm8 = UNSIGNED_BITS(ir, 20, 13);
				((aarch64_decode_a64_FP_IMM&) * this).imm5 = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			// Node 300
			switch (UNSIGNED_BITS(ir, 11, 10)) {
			case 1:
			{
				// Node 301
				// Node 302
				switch ((ir & BIT_LSB(4)) >> 4) {
				case 1:
				{
					// Node 303
					// Node 304
					opcode = aarch64_a64_fccmpe;
					length = 4;
					((aarch64_decode_a64_FP_CCMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CCMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CCMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CCMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CCMP&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_FP_CCMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CCMP&) * this).op = BITSEL(ir, 4);
					((aarch64_decode_a64_FP_CCMP&) * this).nzcv = UNSIGNED_BITS(ir, 3, 0);
					((aarch64_decode_a64_FP_CCMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 0:
				{
					// Node 305
					// Node 306
					opcode = aarch64_a64_fccmpe;
					length = 4;
					((aarch64_decode_a64_FP_CCMP&) * this).M = BITSEL(ir, 31);
					((aarch64_decode_a64_FP_CCMP&) * this).S = BITSEL(ir, 29);
					((aarch64_decode_a64_FP_CCMP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_FP_CCMP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_FP_CCMP&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_FP_CCMP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_FP_CCMP&) * this).op = BITSEL(ir, 4);
					((aarch64_decode_a64_FP_CCMP&) * this).nzcv = UNSIGNED_BITS(ir, 3, 0);
					((aarch64_decode_a64_FP_CCMP&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 3:
			{
				// Node 325
				// Node 326
				opcode = aarch64_a64_fcsel;
				length = 4;
				((aarch64_decode_a64_FP_CSEL&) * this).M = BITSEL(ir, 31);
				((aarch64_decode_a64_FP_CSEL&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_FP_CSEL&) * this).type = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_FP_CSEL&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_FP_CSEL&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_FP_CSEL&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_FP_CSEL&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_FP_CSEL&) * this).decode_behaviour();
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
	case 94:
	{
		// Node 1493
		switch (UNSIGNED_BITS(ir, 23, 10)) {
		case 15470:
		{
			// Node 34
			// Node 35
			opcode = aarch64_a64_addp_scalar;
			length = 4;
			((aarch64_decode_a64_SIMD_SCALAR_PW&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_SCALAR_PW&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_SCALAR_PW&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_SCALAR_PW&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_SCALAR_PW&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_SCALAR_PW&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 14374:
		{
			// Node 165
			// Node 166
			opcode = aarch64_a64_cmeq_zero;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 14378:
		{
			// Node 186
			// Node 187
			opcode = aarch64_a64_cmlt_zero;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 14386:
		{
			// Node 307
			// Node 308
			opcode = aarch64_a64_fcmgt_zero;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 10290:
		{
			// Node 309
			// Node 310
			opcode = aarch64_a64_fcmgt_zero;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6262:
		{
			// Node 1034
			// Node 1035
			opcode = aarch64_a64_scvtf_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2166:
		{
			// Node 1036
			// Node 1037
			opcode = aarch64_a64_scvtf_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 23, 21)) {
		case 7:
		{
			// Node 190
			// Node 191
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 35:
			{
				// Node 192
				// Node 193
				opcode = aarch64_a64_cmtst;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		}
		// Node 339
		// Node 340
		switch (UNSIGNED_BITS(ir, 21, 10)) {
		case 2162:
		{
			// Node 341
			// Node 342
			opcode = aarch64_a64_fcvtas_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2158:
		{
			// Node 407
			// Node 408
			opcode = aarch64_a64_fcvtzs_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 214:
	{
		// Node 1494
		switch (UNSIGNED_BITS(ir, 23, 0)) {
		case 12518368:
		{
			// Node 230
			opcode = aarch64_a64_drps;
			length = 4;
			((aarch64_decode_a64_UB_REG&) * this).opc = UNSIGNED_BITS(ir, 24, 21);
			((aarch64_decode_a64_UB_REG&) * this).op2 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_UB_REG&) * this).op3 = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_UB_REG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_UB_REG&) * this).op4 = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_UB_REG&) * this).decode_behaviour();
			end_of_block = true;
			is_predicated = false;
			return true;
			break;
		}
		case 10421216:
		{
			// Node 249
			opcode = aarch64_a64_eret;
			length = 4;
			((aarch64_decode_a64_UB_REG&) * this).opc = UNSIGNED_BITS(ir, 24, 21);
			((aarch64_decode_a64_UB_REG&) * this).op2 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_UB_REG&) * this).op3 = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_UB_REG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_UB_REG&) * this).op4 = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_UB_REG&) * this).decode_behaviour();
			end_of_block = true;
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 23, 10)) {
		case 4032:
		{
			// Node 116
			// Node 117
			switch (UNSIGNED_BITS(ir, 4, 0)) {
			case 0:
			{
				// Node 118
				opcode = aarch64_a64_br;
				length = 4;
				((aarch64_decode_a64_UB_REG&) * this).opc = UNSIGNED_BITS(ir, 24, 21);
				((aarch64_decode_a64_UB_REG&) * this).op2 = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_UB_REG&) * this).op3 = UNSIGNED_BITS(ir, 15, 10);
				((aarch64_decode_a64_UB_REG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_UB_REG&) * this).op4 = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_UB_REG&) * this).decode_behaviour();
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
			switch (UNSIGNED_BITS(ir, 4, 0)) {
			case 0:
			{
				// Node 121
				opcode = aarch64_a64_br;
				length = 4;
				((aarch64_decode_a64_UB_REG&) * this).opc = UNSIGNED_BITS(ir, 24, 21);
				((aarch64_decode_a64_UB_REG&) * this).op2 = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_UB_REG&) * this).op3 = UNSIGNED_BITS(ir, 15, 10);
				((aarch64_decode_a64_UB_REG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_UB_REG&) * this).op4 = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_UB_REG&) * this).decode_behaviour();
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
			// Node 993
			// Node 994
			switch (UNSIGNED_BITS(ir, 4, 0)) {
			case 0:
			{
				// Node 995
				opcode = aarch64_a64_ret;
				length = 4;
				((aarch64_decode_a64_UB_REG&) * this).opc = UNSIGNED_BITS(ir, 24, 21);
				((aarch64_decode_a64_UB_REG&) * this).op2 = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_UB_REG&) * this).op3 = UNSIGNED_BITS(ir, 15, 10);
				((aarch64_decode_a64_UB_REG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_UB_REG&) * this).op4 = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_UB_REG&) * this).decode_behaviour();
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
	case 158:
	{
		// Node 1495
		switch (UNSIGNED_BITS(ir, 23, 16)) {
		case 89:
		{
			// Node 383
			// Node 384
			opcode = aarch64_a64_fcvtz_fxp;
			length = 4;
			((aarch64_decode_a64_CVT_FP_FXP&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).scale = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 25:
		{
			// Node 385
			// Node 386
			opcode = aarch64_a64_fcvtz_fxp;
			length = 4;
			((aarch64_decode_a64_CVT_FP_FXP&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).scale = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 88:
		{
			// Node 391
			// Node 392
			opcode = aarch64_a64_fcvtz_fxp;
			length = 4;
			((aarch64_decode_a64_CVT_FP_FXP&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).scale = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 24:
		{
			// Node 393
			// Node 394
			opcode = aarch64_a64_fcvtz_fxp;
			length = 4;
			((aarch64_decode_a64_CVT_FP_FXP&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).scale = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_FXP&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 126:
	{
		// Node 1496
		switch (UNSIGNED_BITS(ir, 23, 10)) {
		case 14374:
		{
			// Node 184
			// Node 185
			opcode = aarch64_a64_cmlt_zero;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 14382:
		{
			// Node 957
			// Node 958
			opcode = aarch64_a64_neg_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6262:
		{
			// Node 1388
			// Node 1389
			opcode = aarch64_a64_ucvtf_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2166:
		{
			// Node 1390
			// Node 1391
			opcode = aarch64_a64_ucvtf_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 23, 21)) {
		case 7:
		{
			// Node 159
			// Node 160
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 35:
			{
				// Node 161
				// Node 162
				opcode = aarch64_a64_cmeq_reg;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 13:
			{
				// Node 178
				// Node 179
				opcode = aarch64_a64_cmhi_reg;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 53:
			{
				// Node 275
				// Node 276
				opcode = aarch64_a64_fabd;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 5:
		{
			// Node 277
			// Node 278
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 53:
			{
				// Node 279
				// Node 280
				opcode = aarch64_a64_fabd;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		}
		// Node 403
		// Node 404
		switch (UNSIGNED_BITS(ir, 21, 10)) {
		case 2158:
		{
			// Node 405
			// Node 406
			opcode = aarch64_a64_fcvtzs_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 31, 25)) {
	case 84:
	{
		// Node 642
		// Node 643
		switch (UNSIGNED_BITS(ir, 23, 22)) {
		case 3:
		{
			// Node 644
			// Node 645
			opcode = aarch64_a64_ldpi;
			length = 4;
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).P = BITSEL(ir, 24);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2:
		{
			// Node 1210
			// Node 1211
			opcode = aarch64_a64_stpi;
			length = 4;
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).P = BITSEL(ir, 24);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 20:
	{
		// Node 646
		// Node 647
		switch (UNSIGNED_BITS(ir, 23, 22)) {
		case 3:
		{
			// Node 648
			// Node 649
			opcode = aarch64_a64_ldpi;
			length = 4;
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).P = BITSEL(ir, 24);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2:
		{
			// Node 1212
			// Node 1213
			opcode = aarch64_a64_stpi;
			length = 4;
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).P = BITSEL(ir, 24);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 52:
	{
		// Node 659
		// Node 660
		switch (UNSIGNED_BITS(ir, 23, 22)) {
		case 3:
		{
			// Node 661
			// Node 662
			opcode = aarch64_a64_ldpswi;
			length = 4;
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).P = BITSEL(ir, 24);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 86:
	{
		// Node 1214
		// Node 1215
		switch (UNSIGNED_BITS(ir, 23, 22)) {
		case 2:
		{
			// Node 1216
			// Node 1217
			opcode = aarch64_a64_stpi_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).P = BITSEL(ir, 24);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 54:
	{
		// Node 1218
		// Node 1219
		switch (UNSIGNED_BITS(ir, 23, 22)) {
		case 2:
		{
			// Node 1220
			// Node 1221
			opcode = aarch64_a64_stpi_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).P = BITSEL(ir, 24);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 22:
	{
		// Node 1222
		// Node 1223
		switch (UNSIGNED_BITS(ir, 23, 22)) {
		case 2:
		{
			// Node 1224
			// Node 1225
			opcode = aarch64_a64_stpi_simd;
			length = 4;
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).V = BITSEL(ir, 26);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).P = BITSEL(ir, 24);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).L = BITSEL(ir, 22);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 31, 30)) {
	case 1:
	{
		// Node 172
		// Node 173
		switch (UNSIGNED_BITS(ir, 28, 10)) {
		case 505890:
		{
			// Node 174
			// Node 175
			opcode = aarch64_a64_cmge_zero;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	}
	switch ((ir & BIT_LSB(31)) >> 31) {
	case 0:
	{
		// Node 1
		// Node 2
		switch (UNSIGNED_BITS(ir, 29, 10)) {
		case 243822:
		{
			// Node 399
			// Node 400
			opcode = aarch64_a64_fcvtzs_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 239726:
		{
			// Node 401
			// Node 402
			opcode = aarch64_a64_fcvtzs_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 760882:
		{
			// Node 417
			// Node 418
			opcode = aarch64_a64_fmaxnmv;
			length = 4;
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 760894:
		{
			// Node 421
			// Node 422
			opcode = aarch64_a64_fmaxv;
			length = 4;
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 769074:
		{
			// Node 425
			// Node 426
			opcode = aarch64_a64_fminnmv;
			length = 4;
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 764978:
		{
			// Node 427
			// Node 428
			opcode = aarch64_a64_fminnmv;
			length = 4;
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 769086:
		{
			// Node 429
			// Node 430
			opcode = aarch64_a64_fminv;
			length = 4;
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 764990:
		{
			// Node 431
			// Node 432
			opcode = aarch64_a64_fminv;
			length = 4;
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 235638:
		{
			// Node 1030
			// Node 1031
			opcode = aarch64_a64_scvtf_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 231542:
		{
			// Node 1032
			// Node 1033
			opcode = aarch64_a64_scvtf_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 759926:
		{
			// Node 1384
			// Node 1385
			opcode = aarch64_a64_ucvtf_simd;
			length = 4;
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 29, 19)) {
		case 1504:
		{
			// Node 90
			// Node 91
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 45:
			{
				// Node 92
				// Node 93
				opcode = aarch64_a64_bici;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 37:
			{
				// Node 94
				// Node 95
				opcode = aarch64_a64_bici;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 29:
			{
				// Node 96
				// Node 97
				opcode = aarch64_a64_bici;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 21:
			{
				// Node 98
				// Node 99
				opcode = aarch64_a64_bici;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 13:
			{
				// Node 100
				// Node 101
				opcode = aarch64_a64_bici;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 5:
			{
				// Node 102
				// Node 103
				opcode = aarch64_a64_bici;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 53:
			{
				// Node 939
				// Node 940
				opcode = aarch64_a64_mvni;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 49:
			{
				// Node 941
				// Node 942
				opcode = aarch64_a64_mvni;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 41:
			{
				// Node 943
				// Node 944
				opcode = aarch64_a64_mvni;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 33:
			{
				// Node 945
				// Node 946
				opcode = aarch64_a64_mvni;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 25:
			{
				// Node 947
				// Node 948
				opcode = aarch64_a64_mvni;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 17:
			{
				// Node 949
				// Node 950
				opcode = aarch64_a64_mvni;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 9:
			{
				// Node 951
				// Node 952
				opcode = aarch64_a64_mvni;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 1:
			{
				// Node 953
				// Node 954
				opcode = aarch64_a64_mvni;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 480:
		{
			// Node 453
			// Node 454
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 61:
			{
				// Node 455
				// Node 456
				opcode = aarch64_a64_fmov_simd;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 53:
			{
				// Node 886
				// Node 887
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 49:
			{
				// Node 888
				// Node 889
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 25:
			{
				// Node 890
				// Node 891
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 17:
			{
				// Node 892
				// Node 893
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 9:
			{
				// Node 894
				// Node 895
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 1:
			{
				// Node 896
				// Node 897
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 41:
			{
				// Node 898
				// Node 899
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 33:
			{
				// Node 900
				// Node 901
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 57:
			{
				// Node 902
				// Node 903
				opcode = aarch64_a64_movi;
				length = 4;
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).a = BITSEL(ir, 18);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).b = BITSEL(ir, 17);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).c = BITSEL(ir, 16);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).cmode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).o2 = BITSEL(ir, 11);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).d = BITSEL(ir, 9);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).e = BITSEL(ir, 8);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).f = BITSEL(ir, 7);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).g = BITSEL(ir, 6);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).h = BITSEL(ir, 5);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_MOD_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 29, 20)) {
		case 196:
		{
			// Node 1497
			switch (UNSIGNED_BITS(ir, 19, 12)) {
			case 10:
			{
				// Node 542
				// Node 543
				opcode = aarch64_a64_ld1;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 7:
			{
				// Node 544
				// Node 545
				opcode = aarch64_a64_ld1;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 6:
			{
				// Node 546
				// Node 547
				opcode = aarch64_a64_ld1;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2:
			{
				// Node 548
				// Node 549
				opcode = aarch64_a64_ld1;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 8:
			{
				// Node 576
				// Node 577
				opcode = aarch64_a64_ld2;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 4:
			{
				// Node 580
				// Node 581
				opcode = aarch64_a64_ld3;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 0:
			{
				// Node 584
				// Node 585
				opcode = aarch64_a64_ld4;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 192:
		{
			// Node 1498
			switch (UNSIGNED_BITS(ir, 19, 12)) {
			case 10:
			{
				// Node 1096
				// Node 1097
				opcode = aarch64_a64_st1;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 7:
			{
				// Node 1098
				// Node 1099
				opcode = aarch64_a64_st1;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 6:
			{
				// Node 1100
				// Node 1101
				opcode = aarch64_a64_st1;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2:
			{
				// Node 1102
				// Node 1103
				opcode = aarch64_a64_st1;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 8:
			{
				// Node 1144
				// Node 1145
				opcode = aarch64_a64_st2;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 4:
			{
				// Node 1148
				// Node 1149
				opcode = aarch64_a64_st3;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 0:
			{
				// Node 1152
				// Node 1153
				opcode = aarch64_a64_st4;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 29, 21)) {
		case 247:
		{
			// Node 22
			// Node 23
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 33:
			{
				// Node 24
				// Node 25
				opcode = aarch64_a64_add_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 113:
		{
			// Node 43
			// Node 44
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 7:
			{
				// Node 45
				// Node 46
				opcode = aarch64_a64_and_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 37:
			{
				// Node 870
				// Node 871
				opcode = aarch64_a64_mla_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 39:
			{
				// Node 937
				// Node 938
				opcode = aarch64_a64_mul_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 115:
		{
			// Node 86
			// Node 87
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 7:
			{
				// Node 88
				// Node 89
				opcode = aarch64_a64_bic_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 37:
			{
				// Node 868
				// Node 869
				opcode = aarch64_a64_mla_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 39:
			{
				// Node 935
				// Node 936
				opcode = aarch64_a64_mul_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 375:
		{
			// Node 108
			// Node 109
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 7:
			{
				// Node 110
				// Node 111
				opcode = aarch64_a64_bif;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 53:
			{
				// Node 271
				// Node 272
				opcode = aarch64_a64_fabd;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 373:
		{
			// Node 112
			// Node 113
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 7:
			{
				// Node 114
				// Node 115
				opcode = aarch64_a64_bit;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 53:
			{
				// Node 273
				// Node 274
				opcode = aarch64_a64_fabd;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 371:
		{
			// Node 122
			// Node 123
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 7:
			{
				// Node 124
				// Node 125
				opcode = aarch64_a64_bsl;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 112:
		{
			// Node 231
			// Node 232
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 1:
			{
				// Node 233
				// Node 234
				opcode = aarch64_a64_dup_elem;
				length = 4;
				((aarch64_decode_a64_SIMD_COPY&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_COPY&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_COPY&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_COPY&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
				((aarch64_decode_a64_SIMD_COPY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_COPY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_COPY&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 3:
			{
				// Node 235
				// Node 236
				opcode = aarch64_a64_dup_gen;
				length = 4;
				((aarch64_decode_a64_SIMD_COPY&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_COPY&) * this).op = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_COPY&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_COPY&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
				((aarch64_decode_a64_SIMD_COPY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_COPY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_COPY&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 117:
		{
			// Node 525
			// Node 526
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 53:
			{
				// Node 527
				// Node 528
				opcode = aarch64_a64_fsub_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 37:
			{
				// Node 866
				// Node 867
				opcode = aarch64_a64_mla_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 39:
			{
				// Node 933
				// Node 934
				opcode = aarch64_a64_mul_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 7:
			{
				// Node 965
				// Node 966
				opcode = aarch64_a64_orr_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 102:
		{
			// Node 550
			// Node 551
			switch (UNSIGNED_BITS(ir, 15, 12)) {
			case 10:
			{
				// Node 552
				// Node 553
				opcode = aarch64_a64_ld1pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 7:
			{
				// Node 554
				// Node 555
				opcode = aarch64_a64_ld1pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 6:
			{
				// Node 556
				// Node 557
				opcode = aarch64_a64_ld1pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2:
			{
				// Node 558
				// Node 559
				opcode = aarch64_a64_ld1pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 8:
			{
				// Node 578
				// Node 579
				opcode = aarch64_a64_ld2pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 4:
			{
				// Node 582
				// Node 583
				opcode = aarch64_a64_ld3pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 0:
			{
				// Node 586
				// Node 587
				opcode = aarch64_a64_ld4pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 119:
		{
			// Node 961
			// Node 962
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 7:
			{
				// Node 963
				// Node 964
				opcode = aarch64_a64_orn_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 100:
		{
			// Node 1104
			// Node 1105
			switch (UNSIGNED_BITS(ir, 15, 12)) {
			case 10:
			{
				// Node 1106
				// Node 1107
				opcode = aarch64_a64_st1pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 7:
			{
				// Node 1108
				// Node 1109
				opcode = aarch64_a64_st1pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 6:
			{
				// Node 1110
				// Node 1111
				opcode = aarch64_a64_st1pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2:
			{
				// Node 1112
				// Node 1113
				opcode = aarch64_a64_st1pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 8:
			{
				// Node 1146
				// Node 1147
				opcode = aarch64_a64_st2pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 4:
			{
				// Node 1150
				// Node 1151
				opcode = aarch64_a64_st3pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 0:
			{
				// Node 1154
				// Node 1155
				opcode = aarch64_a64_st4pi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_MULT_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 108:
		{
			// Node 1128
			// Node 1129
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 33:
			{
				// Node 1130
				// Node 1131
				opcode = aarch64_a64_st1spi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).R = BITSEL(ir, 21);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).S = BITSEL(ir, 12);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			switch (UNSIGNED_BITS(ir, 15, 13)) {
			case 4:
			{
				// Node 1132
				// Node 1133
				switch (UNSIGNED_BITS(ir, 11, 10)) {
				case 0:
				{
					// Node 1134
					// Node 1135
					opcode = aarch64_a64_st1spi;
					length = 4;
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).L = BITSEL(ir, 22);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).R = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).S = BITSEL(ir, 12);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 2:
			{
				// Node 1136
				// Node 1137
				switch (UNSIGNED_BITS(ir, 11, 10)) {
				case 2:
				{
					// Node 1138
					// Node 1139
					opcode = aarch64_a64_st1spi;
					length = 4;
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).L = BITSEL(ir, 22);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).R = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).S = BITSEL(ir, 12);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 0:
				{
					// Node 1140
					// Node 1141
					opcode = aarch64_a64_st1spi;
					length = 4;
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).L = BITSEL(ir, 22);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).R = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).S = BITSEL(ir, 12);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 0:
			{
				// Node 1142
				// Node 1143
				opcode = aarch64_a64_st1spi;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).R = BITSEL(ir, 21);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).S = BITSEL(ir, 12);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_SINGLE_PI&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 503:
		{
			// Node 1344
			// Node 1345
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 33:
			{
				// Node 1346
				// Node 1347
				opcode = aarch64_a64_sub_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 106:
		{
			// Node 1499
			switch (UNSIGNED_BITS(ir, 20, 10)) {
			case 33:
			{
				// Node 562
				// Node 563
				opcode = aarch64_a64_ld1s;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			switch (UNSIGNED_BITS(ir, 20, 12)) {
			case 12:
			{
				// Node 560
				// Node 561
				opcode = aarch64_a64_ld1r;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			switch (UNSIGNED_BITS(ir, 20, 13)) {
			case 4:
			{
				// Node 564
				// Node 565
				switch (UNSIGNED_BITS(ir, 11, 10)) {
				case 0:
				{
					// Node 566
					// Node 567
					opcode = aarch64_a64_ld1s;
					length = 4;
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 2:
			{
				// Node 568
				// Node 569
				switch (UNSIGNED_BITS(ir, 11, 10)) {
				case 2:
				{
					// Node 570
					// Node 571
					opcode = aarch64_a64_ld1s;
					length = 4;
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 0:
				{
					// Node 572
					// Node 573
					opcode = aarch64_a64_ld1s;
					length = 4;
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 0:
			{
				// Node 574
				// Node 575
				opcode = aarch64_a64_ld1s;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 369:
		{
			// Node 1500
			switch (UNSIGNED_BITS(ir, 20, 10)) {
			case 1074:
			{
				// Node 419
				// Node 420
				opcode = aarch64_a64_fmaxnmv;
				length = 4;
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 1086:
			{
				// Node 423
				// Node 424
				opcode = aarch64_a64_fmaxv;
				length = 4;
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 22:
			{
				// Node 959
				// Node 960
				opcode = aarch64_a64_not_simd;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 118:
			{
				// Node 1386
				// Node 1387
				opcode = aarch64_a64_ucvtf_simd;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			// Node 237
			// Node 238
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 7:
			{
				// Node 239
				// Node 240
				opcode = aarch64_a64_eor_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 55:
			{
				// Node 471
				// Node 472
				opcode = aarch64_a64_fmul_vector;
				length = 4;
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 104:
		{
			// Node 1501
			switch (UNSIGNED_BITS(ir, 20, 10)) {
			case 33:
			{
				// Node 1114
				// Node 1115
				opcode = aarch64_a64_st1s;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			switch (UNSIGNED_BITS(ir, 20, 13)) {
			case 4:
			{
				// Node 1116
				// Node 1117
				switch (UNSIGNED_BITS(ir, 11, 10)) {
				case 0:
				{
					// Node 1118
					// Node 1119
					opcode = aarch64_a64_st1s;
					length = 4;
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 2:
			{
				// Node 1120
				// Node 1121
				switch (UNSIGNED_BITS(ir, 11, 10)) {
				case 2:
				{
					// Node 1122
					// Node 1123
					opcode = aarch64_a64_st1s;
					length = 4;
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 0:
				{
					// Node 1124
					// Node 1125
					opcode = aarch64_a64_st1s;
					length = 4;
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 0:
			{
				// Node 1126
				// Node 1127
				opcode = aarch64_a64_st1s;
				length = 4;
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).R = BITSEL(ir, 21);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).opcode = UNSIGNED_BITS(ir, 15, 13);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).S = BITSEL(ir, 12);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).size = UNSIGNED_BITS(ir, 11, 10);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_LS_SINGLE&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 29, 23)) {
		case 30:
		{
			// Node 1040
			// Node 1041
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 21:
			{
				// Node 1042
				// Node 1043
				opcode = aarch64_a64_shl_simd;
				length = 4;
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immh = UNSIGNED_BITS(ir, 22, 19);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immb = UNSIGNED_BITS(ir, 18, 16);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 1:
			{
				// Node 1088
				// Node 1089
				opcode = aarch64_a64_sshr;
				length = 4;
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immh = UNSIGNED_BITS(ir, 22, 19);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immb = UNSIGNED_BITS(ir, 18, 16);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 94:
		{
			// Node 1424
			// Node 1425
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 1:
			{
				// Node 1426
				// Node 1427
				opcode = aarch64_a64_ushr;
				length = 4;
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immh = UNSIGNED_BITS(ir, 22, 19);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immb = UNSIGNED_BITS(ir, 18, 16);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 29, 24)) {
		case 14:
		{
			// Node 26
			// Node 27
			switch (UNSIGNED_BITS(ir, 21, 10)) {
			case 3182:
			{
				// Node 38
				// Node 39
				opcode = aarch64_a64_addv;
				length = 4;
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2086:
			{
				// Node 163
				// Node 164
				opcode = aarch64_a64_cmeq_zero;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2090:
			{
				// Node 182
				// Node 183
				opcode = aarch64_a64_cmlt_zero;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2070:
			{
				// Node 194
				// Node 195
				opcode = aarch64_a64_cnt;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2050:
			{
				// Node 1006
				// Node 1007
				opcode = aarch64_a64_rev64_simd;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 3086:
			{
				// Node 1012
				// Node 1013
				opcode = aarch64_a64_saddlv;
				length = 4;
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 3114:
			{
				// Node 1062
				// Node 1063
				opcode = aarch64_a64_smaxv;
				length = 4;
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 3178:
			{
				// Node 1066
				// Node 1067
				opcode = aarch64_a64_sminv;
				length = 4;
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			switch ((ir & BIT_LSB(21)) >> 21) {
			case 1:
			{
				// Node 28
				// Node 29
				switch (UNSIGNED_BITS(ir, 15, 10)) {
				case 33:
				{
					// Node 30
					// Node 31
					opcode = aarch64_a64_add_vector;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 47:
				{
					// Node 36
					// Node 37
					opcode = aarch64_a64_addp_vector;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 35:
				{
					// Node 188
					// Node 189
					opcode = aarch64_a64_cmtst;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 56:
				{
					// Node 974
					// Node 975
					opcode = aarch64_a64_pmull;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 0:
				{
					// Node 1010
					// Node 1011
					opcode = aarch64_a64_saddl;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 4:
				{
					// Node 1014
					// Node 1015
					opcode = aarch64_a64_saddw;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 48:
				{
					// Node 1080
					// Node 1081
					opcode = aarch64_a64_smull;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 8:
				{
					// Node 1092
					// Node 1093
					opcode = aarch64_a64_ssubl;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 12:
				{
					// Node 1094
					// Node 1095
					opcode = aarch64_a64_ssubw;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 0:
			{
				// Node 1356
				// Node 1357
				switch (UNSIGNED_BITS(ir, 15, 10)) {
				case 6:
				{
					// Node 1436
					// Node 1437
					opcode = aarch64_a64_uzp1;
					length = 4;
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).opcode = UNSIGNED_BITS(ir, 14, 12);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 22:
				{
					// Node 1438
					// Node 1439
					opcode = aarch64_a64_uzp2;
					length = 4;
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).opcode = UNSIGNED_BITS(ir, 14, 12);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_PERMUTE&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				switch ((ir & BIT_LSB(15)) >> 15) {
				case 0:
				{
					// Node 1358
					// Node 1359
					switch (UNSIGNED_BITS(ir, 12, 10)) {
					case 0:
					{
						// Node 1360
						// Node 1361
						opcode = aarch64_a64_tbl;
						length = 4;
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).Q = BITSEL(ir, 30);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).op2 = UNSIGNED_BITS(ir, 23, 22);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).len = UNSIGNED_BITS(ir, 14, 13);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).op = BITSEL(ir, 12);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).decode_behaviour();
						is_predicated = false;
						return true;
						break;
					}
					case 4:
					{
						// Node 1362
						// Node 1363
						opcode = aarch64_a64_tbx;
						length = 4;
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).Q = BITSEL(ir, 30);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).op2 = UNSIGNED_BITS(ir, 23, 22);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).len = UNSIGNED_BITS(ir, 14, 13);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).op = BITSEL(ir, 12);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
						((aarch64_decode_a64_SIMD_TABLE_LOOKUP&) * this).decode_behaviour();
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
		case 46:
		{
			// Node 153
			// Node 154
			switch (UNSIGNED_BITS(ir, 21, 10)) {
			case 2086:
			{
				// Node 180
				// Node 181
				opcode = aarch64_a64_cmlt_zero;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2094:
			{
				// Node 955
				// Node 956
				opcode = aarch64_a64_neg_simd;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2050:
			{
				// Node 1004
				// Node 1005
				opcode = aarch64_a64_rev32_simd;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2074:
			{
				// Node 1366
				// Node 1367
				opcode = aarch64_a64_uadalp;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 2058:
			{
				// Node 1370
				// Node 1371
				opcode = aarch64_a64_uaddlp;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 3086:
			{
				// Node 1372
				// Node 1373
				opcode = aarch64_a64_uaddlv;
				length = 4;
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 3114:
			{
				// Node 1398
				// Node 1399
				opcode = aarch64_a64_umaxv;
				length = 4;
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			case 3178:
			{
				// Node 1400
				// Node 1401
				opcode = aarch64_a64_uminv;
				length = 4;
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_ACROSS_LANES&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			switch ((ir & BIT_LSB(21)) >> 21) {
			case 1:
			{
				// Node 155
				// Node 156
				switch (UNSIGNED_BITS(ir, 15, 10)) {
				case 35:
				{
					// Node 157
					// Node 158
					opcode = aarch64_a64_cmeq_reg;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 13:
				{
					// Node 176
					// Node 177
					opcode = aarch64_a64_cmhi_reg;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 33:
				{
					// Node 1348
					// Node 1349
					opcode = aarch64_a64_sub_vector;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 0:
				{
					// Node 1368
					// Node 1369
					opcode = aarch64_a64_uaddl;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 4:
				{
					// Node 1374
					// Node 1375
					opcode = aarch64_a64_uaddw;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 48:
				{
					// Node 1414
					// Node 1415
					opcode = aarch64_a64_umull;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 8:
				{
					// Node 1432
					// Node 1433
					opcode = aarch64_a64_usubl;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 12:
				{
					// Node 1434
					// Node 1435
					opcode = aarch64_a64_usubw;
					length = 4;
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_THREE_DIFF&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			case 0:
			{
				// Node 261
				// Node 262
				switch ((ir & BIT_LSB(15)) >> 15) {
				case 0:
				{
					// Node 263
					// Node 264
					switch ((ir & BIT_LSB(10)) >> 10) {
					case 0:
					{
						// Node 265
						// Node 266
						opcode = aarch64_a64_ext;
						length = 4;
						((aarch64_decode_a64_SIMD_EXTRACT&) * this).Q = BITSEL(ir, 30);
						((aarch64_decode_a64_SIMD_EXTRACT&) * this).op2 = UNSIGNED_BITS(ir, 23, 22);
						((aarch64_decode_a64_SIMD_EXTRACT&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
						((aarch64_decode_a64_SIMD_EXTRACT&) * this).imm4 = UNSIGNED_BITS(ir, 14, 11);
						((aarch64_decode_a64_SIMD_EXTRACT&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
						((aarch64_decode_a64_SIMD_EXTRACT&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
						((aarch64_decode_a64_SIMD_EXTRACT&) * this).decode_behaviour();
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
		case 15:
		{
			// Node 927
			// Node 928
			switch (UNSIGNED_BITS(ir, 15, 12)) {
			case 8:
			{
				// Node 929
				// Node 930
				switch ((ir & BIT_LSB(10)) >> 10) {
				case 0:
				{
					// Node 931
					// Node 932
					opcode = aarch64_a64_mul_idx_vector;
					length = 4;
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).L = BITSEL(ir, 21);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).M = BITSEL(ir, 20);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).rm = UNSIGNED_BITS(ir, 19, 16);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).opcode = UNSIGNED_BITS(ir, 15, 12);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).H = BITSEL(ir, 11);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_VECTOR_IDX&) * this).decode_behaviour();
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
		switch ((ir & BIT_LSB(29)) >> 29) {
		case 0:
		{
			// Node 3
			// Node 4
			switch (UNSIGNED_BITS(ir, 27, 23)) {
			case 30:
			{
				// Node 1084
				// Node 1085
				switch (UNSIGNED_BITS(ir, 15, 10)) {
				case 41:
				{
					// Node 1086
					// Node 1087
					opcode = aarch64_a64_sshll;
					length = 4;
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immh = UNSIGNED_BITS(ir, 22, 19);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immb = UNSIGNED_BITS(ir, 18, 16);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			}
			switch (UNSIGNED_BITS(ir, 27, 24)) {
			case 14:
			{
				// Node 5
				// Node 6
				switch (UNSIGNED_BITS(ir, 21, 10)) {
				case 2094:
				{
					// Node 7
					// Node 8
					opcode = aarch64_a64_abs_simd;
					length = 4;
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 2070:
				{
					// Node 196
					// Node 197
					opcode = aarch64_a64_cnt;
					length = 4;
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				case 2122:
				{
					// Node 1490
					// Node 1491
					opcode = aarch64_a64_xtn;
					length = 4;
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				switch ((ir & BIT_LSB(21)) >> 21) {
				case 1:
				{
					// Node 1058
					// Node 1059
					switch (UNSIGNED_BITS(ir, 15, 10)) {
					case 25:
					{
						// Node 1060
						// Node 1061
						opcode = aarch64_a64_smax;
						length = 4;
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
						is_predicated = false;
						return true;
						break;
					}
					case 27:
					{
						// Node 1064
						// Node 1065
						opcode = aarch64_a64_smin;
						length = 4;
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
						is_predicated = false;
						return true;
						break;
					}
					case 17:
					{
						// Node 1082
						// Node 1083
						opcode = aarch64_a64_sshl;
						length = 4;
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
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
			// Node 1048
			// Node 1049
			switch (UNSIGNED_BITS(ir, 27, 23)) {
			case 30:
			{
				// Node 1420
				// Node 1421
				switch (UNSIGNED_BITS(ir, 15, 10)) {
				case 41:
				{
					// Node 1422
					// Node 1423
					opcode = aarch64_a64_ushll;
					length = 4;
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immh = UNSIGNED_BITS(ir, 22, 19);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).immb = UNSIGNED_BITS(ir, 18, 16);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_SHIFT_IMM&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				break;
			}
			}
			switch (UNSIGNED_BITS(ir, 27, 24)) {
			case 14:
			{
				// Node 1050
				// Node 1051
				switch (UNSIGNED_BITS(ir, 21, 10)) {
				case 2126:
				{
					// Node 1052
					// Node 1053
					opcode = aarch64_a64_shll;
					length = 4;
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
					((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
					is_predicated = false;
					return true;
					break;
				}
				}
				switch ((ir & BIT_LSB(21)) >> 21) {
				case 1:
				{
					// Node 1416
					// Node 1417
					switch (UNSIGNED_BITS(ir, 15, 10)) {
					case 17:
					{
						// Node 1418
						// Node 1419
						opcode = aarch64_a64_ushl;
						length = 4;
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).Q = BITSEL(ir, 30);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).U = BITSEL(ir, 29);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).SCALAR = BITSEL(ir, 28);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).size = UNSIGNED_BITS(ir, 23, 22);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).opcode = UNSIGNED_BITS(ir, 15, 11);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
						((aarch64_decode_a64_SIMD_THREE_SAME&) * this).decode_behaviour();
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
		switch (UNSIGNED_BITS(ir, 28, 24)) {
		case 14:
		{
			// Node 168
			// Node 169
			switch (UNSIGNED_BITS(ir, 21, 10)) {
			case 2082:
			{
				// Node 170
				// Node 171
				opcode = aarch64_a64_cmge_zero;
				length = 4;
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).Q = BITSEL(ir, 30);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).U = BITSEL(ir, 29);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).SCALAR = BITSEL(ir, 28);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).size = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).opcode = UNSIGNED_BITS(ir, 16, 12);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_SIMD_TWO_REG_MISC&) * this).decode_behaviour();
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
	switch (UNSIGNED_BITS(ir, 30, 10)) {
	case 502720:
	{
		// Node 437
		// Node 438
		opcode = aarch64_a64_fmov_gen;
		length = 4;
		((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
		((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
		((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
		((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 502656:
	{
		// Node 439
		// Node 440
		opcode = aarch64_a64_fmov_gen;
		length = 4;
		((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
		((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
		((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
		((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 30, 18)) {
	case 5808:
	{
		// Node 1503
		switch (UNSIGNED_BITS(ir, 17, 10)) {
		case 5:
		{
			// Node 149
			// Node 150
			opcode = aarch64_a64_cls;
			length = 4;
			((aarch64_decode_a64_DP_1S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_1S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_1S&) * this).opcode2 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_1S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_1S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_1S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_1S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 4:
		{
			// Node 151
			// Node 152
			opcode = aarch64_a64_clz;
			length = 4;
			((aarch64_decode_a64_DP_1S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_1S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_1S&) * this).opcode2 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_1S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_1S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_1S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_1S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 0:
		{
			// Node 991
			// Node 992
			opcode = aarch64_a64_rbit;
			length = 4;
			((aarch64_decode_a64_DP_1S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_1S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_1S&) * this).opcode2 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_1S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_1S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_1S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_1S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 1000
			// Node 1001
			opcode = aarch64_a64_rev16;
			length = 4;
			((aarch64_decode_a64_DP_1S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_1S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_1S&) * this).opcode2 = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_1S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_1S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_1S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_1S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 30, 21)) {
	case 214:
	{
		// Node 67
		// Node 68
		switch (UNSIGNED_BITS(ir, 15, 10)) {
		case 10:
		{
			// Node 69
			// Node 70
			opcode = aarch64_a64_asrv;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 8:
		{
			// Node 858
			// Node 859
			opcode = aarch64_a64_lslv;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 9:
		{
			// Node 860
			// Node 861
			opcode = aarch64_a64_lsrv;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 11:
		{
			// Node 1008
			// Node 1009
			opcode = aarch64_a64_rorv;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 3:
		{
			// Node 1038
			// Node 1039
			opcode = aarch64_a64_sdiv;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2:
		{
			// Node 1392
			// Node 1393
			opcode = aarch64_a64_udiv;
			length = 4;
			((aarch64_decode_a64_DP_2S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_2S&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_DP_2S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_2S&) * this).opcode = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_DP_2S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_2S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_2S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 466:
	{
		// Node 128
		// Node 129
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 130
			// Node 131
			switch ((ir & BIT_LSB(4)) >> 4) {
			case 0:
			{
				// Node 132
				// Node 133
				opcode = aarch64_a64_ccmni;
				length = 4;
				((aarch64_decode_a64_COND_CMP_IMM&) * this).sf = BITSEL(ir, 31);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).op = BITSEL(ir, 30);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).o2 = BITSEL(ir, 10);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).o3 = BITSEL(ir, 4);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).nzcv = UNSIGNED_BITS(ir, 3, 0);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).decode_behaviour();
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
			switch ((ir & BIT_LSB(4)) >> 4) {
			case 0:
			{
				// Node 136
				// Node 137
				opcode = aarch64_a64_ccmnr;
				length = 4;
				((aarch64_decode_a64_COND_CMP_REG&) * this).sf = BITSEL(ir, 31);
				((aarch64_decode_a64_COND_CMP_REG&) * this).op = BITSEL(ir, 30);
				((aarch64_decode_a64_COND_CMP_REG&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_COND_CMP_REG&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_COND_CMP_REG&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_COND_CMP_REG&) * this).o2 = BITSEL(ir, 10);
				((aarch64_decode_a64_COND_CMP_REG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_COND_CMP_REG&) * this).o3 = BITSEL(ir, 4);
				((aarch64_decode_a64_COND_CMP_REG&) * this).nzcv = UNSIGNED_BITS(ir, 3, 0);
				((aarch64_decode_a64_COND_CMP_REG&) * this).decode_behaviour();
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
	case 978:
	{
		// Node 138
		// Node 139
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 2:
		{
			// Node 140
			// Node 141
			switch ((ir & BIT_LSB(4)) >> 4) {
			case 0:
			{
				// Node 142
				// Node 143
				opcode = aarch64_a64_ccmpi;
				length = 4;
				((aarch64_decode_a64_COND_CMP_IMM&) * this).sf = BITSEL(ir, 31);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).op = BITSEL(ir, 30);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).imm5 = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).o2 = BITSEL(ir, 10);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).o3 = BITSEL(ir, 4);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).nzcv = UNSIGNED_BITS(ir, 3, 0);
				((aarch64_decode_a64_COND_CMP_IMM&) * this).decode_behaviour();
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
			switch ((ir & BIT_LSB(4)) >> 4) {
			case 0:
			{
				// Node 146
				// Node 147
				opcode = aarch64_a64_ccmpr;
				length = 4;
				((aarch64_decode_a64_COND_CMP_REG&) * this).sf = BITSEL(ir, 31);
				((aarch64_decode_a64_COND_CMP_REG&) * this).op = BITSEL(ir, 30);
				((aarch64_decode_a64_COND_CMP_REG&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_COND_CMP_REG&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_COND_CMP_REG&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
				((aarch64_decode_a64_COND_CMP_REG&) * this).o2 = BITSEL(ir, 10);
				((aarch64_decode_a64_COND_CMP_REG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_COND_CMP_REG&) * this).o3 = BITSEL(ir, 4);
				((aarch64_decode_a64_COND_CMP_REG&) * this).nzcv = UNSIGNED_BITS(ir, 3, 0);
				((aarch64_decode_a64_COND_CMP_REG&) * this).decode_behaviour();
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
	case 212:
	{
		// Node 218
		// Node 219
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 220
			// Node 221
			opcode = aarch64_a64_csel;
			length = 4;
			((aarch64_decode_a64_COND_SEL&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_COND_SEL&) * this).op = BITSEL(ir, 30);
			((aarch64_decode_a64_COND_SEL&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_COND_SEL&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_COND_SEL&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_COND_SEL&) * this).op2 = UNSIGNED_BITS(ir, 11, 10);
			((aarch64_decode_a64_COND_SEL&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_COND_SEL&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_COND_SEL&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 222
			// Node 223
			opcode = aarch64_a64_csinc;
			length = 4;
			((aarch64_decode_a64_COND_SEL&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_COND_SEL&) * this).op = BITSEL(ir, 30);
			((aarch64_decode_a64_COND_SEL&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_COND_SEL&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_COND_SEL&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_COND_SEL&) * this).op2 = UNSIGNED_BITS(ir, 11, 10);
			((aarch64_decode_a64_COND_SEL&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_COND_SEL&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_COND_SEL&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 724:
	{
		// Node 224
		// Node 225
		switch (UNSIGNED_BITS(ir, 11, 10)) {
		case 0:
		{
			// Node 226
			// Node 227
			opcode = aarch64_a64_csinv;
			length = 4;
			((aarch64_decode_a64_COND_SEL&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_COND_SEL&) * this).op = BITSEL(ir, 30);
			((aarch64_decode_a64_COND_SEL&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_COND_SEL&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_COND_SEL&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_COND_SEL&) * this).op2 = UNSIGNED_BITS(ir, 11, 10);
			((aarch64_decode_a64_COND_SEL&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_COND_SEL&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_COND_SEL&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 228
			// Node 229
			opcode = aarch64_a64_csneg;
			length = 4;
			((aarch64_decode_a64_COND_SEL&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_COND_SEL&) * this).op = BITSEL(ir, 30);
			((aarch64_decode_a64_COND_SEL&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_COND_SEL&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_COND_SEL&) * this).cond = UNSIGNED_BITS(ir, 15, 12);
			((aarch64_decode_a64_COND_SEL&) * this).op2 = UNSIGNED_BITS(ir, 11, 10);
			((aarch64_decode_a64_COND_SEL&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_COND_SEL&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_COND_SEL&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 216:
	{
		// Node 862
		// Node 863
		switch ((ir & BIT_LSB(15)) >> 15) {
		case 0:
		{
			// Node 864
			// Node 865
			opcode = aarch64_a64_madd;
			length = 4;
			((aarch64_decode_a64_DP_3S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_3S&) * this).op54 = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_DP_3S&) * this).op31 = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_DP_3S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_3S&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_DP_3S&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_DP_3S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_3S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_3S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 925
			// Node 926
			opcode = aarch64_a64_msub;
			length = 4;
			((aarch64_decode_a64_DP_3S&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_DP_3S&) * this).op54 = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_DP_3S&) * this).op31 = UNSIGNED_BITS(ir, 23, 21);
			((aarch64_decode_a64_DP_3S&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_DP_3S&) * this).o0 = BITSEL(ir, 15);
			((aarch64_decode_a64_DP_3S&) * this).ra = UNSIGNED_BITS(ir, 14, 10);
			((aarch64_decode_a64_DP_3S&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_DP_3S&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_DP_3S&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 30, 23)) {
	case 229:
	{
		// Node 904
		// Node 905
		opcode = aarch64_a64_movk;
		length = 4;
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).hw = UNSIGNED_BITS(ir, 22, 21);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).imm16 = UNSIGNED_BITS(ir, 20, 5);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 37:
	{
		// Node 906
		// Node 907
		opcode = aarch64_a64_movn;
		length = 4;
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).hw = UNSIGNED_BITS(ir, 22, 21);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).imm16 = UNSIGNED_BITS(ir, 20, 5);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 165:
	{
		// Node 908
		// Node 909
		opcode = aarch64_a64_movz;
		length = 4;
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).hw = UNSIGNED_BITS(ir, 22, 21);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).imm16 = UNSIGNED_BITS(ir, 20, 5);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_MOVE_WIDE_IMM&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 60:
	{
		// Node 1502
		switch (UNSIGNED_BITS(ir, 22, 10)) {
		case 7232:
		{
			// Node 343
			// Node 344
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 7168:
		{
			// Node 345
			// Node 346
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6720:
		{
			// Node 347
			// Node 348
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6656:
		{
			// Node 349
			// Node 350
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6464:
		{
			// Node 351
			// Node 352
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6400:
		{
			// Node 353
			// Node 354
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6208:
		{
			// Node 355
			// Node 356
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6144:
		{
			// Node 357
			// Node 358
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 3136:
		{
			// Node 359
			// Node 360
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 3072:
		{
			// Node 361
			// Node 362
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2624:
		{
			// Node 363
			// Node 364
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2560:
		{
			// Node 365
			// Node 366
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2368:
		{
			// Node 367
			// Node 368
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2304:
		{
			// Node 369
			// Node 370
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2112:
		{
			// Node 371
			// Node 372
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2048:
		{
			// Node 373
			// Node 374
			opcode = aarch64_a64_fcvti;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 7744:
		{
			// Node 375
			// Node 376
			opcode = aarch64_a64_fcvtz;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 7680:
		{
			// Node 377
			// Node 378
			opcode = aarch64_a64_fcvtz;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 3648:
		{
			// Node 379
			// Node 380
			opcode = aarch64_a64_fcvtz;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 3584:
		{
			// Node 381
			// Node 382
			opcode = aarch64_a64_fcvtz;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6592:
		{
			// Node 441
			// Node 442
			opcode = aarch64_a64_fmov_gen;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6528:
		{
			// Node 443
			// Node 444
			opcode = aarch64_a64_fmov_gen;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2496:
		{
			// Node 445
			// Node 446
			opcode = aarch64_a64_fmov_gen;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2432:
		{
			// Node 447
			// Node 448
			opcode = aarch64_a64_fmov_gen;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6272:
		{
			// Node 1026
			// Node 1027
			opcode = aarch64_a64_scvtf;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2176:
		{
			// Node 1028
			// Node 1029
			opcode = aarch64_a64_scvtf;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 6336:
		{
			// Node 1380
			// Node 1381
			opcode = aarch64_a64_ucvtf;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 2240:
		{
			// Node 1382
			// Node 1383
			opcode = aarch64_a64_ucvtf;
			length = 4;
			((aarch64_decode_a64_CVT_FP_I&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_CVT_FP_I&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_CVT_FP_I&) * this).type = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_CVT_FP_I&) * this).rmode = UNSIGNED_BITS(ir, 20, 19);
			((aarch64_decode_a64_CVT_FP_I&) * this).opcode = UNSIGNED_BITS(ir, 18, 16);
			((aarch64_decode_a64_CVT_FP_I&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_CVT_FP_I&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_CVT_FP_I&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 30, 24)) {
	case 106:
	{
		// Node 59
		// Node 60
		switch ((ir & BIT_LSB(21)) >> 21) {
		case 0:
		{
			// Node 61
			// Node 62
			opcode = aarch64_a64_andsr;
			length = 4;
			((aarch64_decode_a64_LOGICAL_SR&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_LOGICAL_SR&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_LOGICAL_SR&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LOGICAL_SR&) * this).N = BITSEL(ir, 21);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LOGICAL_SR&) * this).imm6 = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LOGICAL_SR&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 104
			// Node 105
			opcode = aarch64_a64_bicsr;
			length = 4;
			((aarch64_decode_a64_LOGICAL_SR&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_LOGICAL_SR&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_LOGICAL_SR&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LOGICAL_SR&) * this).N = BITSEL(ir, 21);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LOGICAL_SR&) * this).imm6 = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LOGICAL_SR&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 10:
	{
		// Node 63
		// Node 64
		switch ((ir & BIT_LSB(21)) >> 21) {
		case 0:
		{
			// Node 65
			// Node 66
			opcode = aarch64_a64_andsr;
			length = 4;
			((aarch64_decode_a64_LOGICAL_SR&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_LOGICAL_SR&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_LOGICAL_SR&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LOGICAL_SR&) * this).N = BITSEL(ir, 21);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LOGICAL_SR&) * this).imm6 = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LOGICAL_SR&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 1:
		{
			// Node 106
			// Node 107
			opcode = aarch64_a64_bicsr;
			length = 4;
			((aarch64_decode_a64_LOGICAL_SR&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_LOGICAL_SR&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_LOGICAL_SR&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LOGICAL_SR&) * this).N = BITSEL(ir, 21);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LOGICAL_SR&) * this).imm6 = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LOGICAL_SR&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 74:
	{
		// Node 247
		// Node 248
		opcode = aarch64_a64_eorsr;
		length = 4;
		((aarch64_decode_a64_LOGICAL_SR&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_SR&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_SR&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LOGICAL_SR&) * this).N = BITSEL(ir, 21);
		((aarch64_decode_a64_LOGICAL_SR&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_LOGICAL_SR&) * this).imm6 = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_SR&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_SR&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_SR&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	case 42:
	{
		// Node 872
		// Node 873
		switch (UNSIGNED_BITS(ir, 15, 5)) {
		case 31:
		{
			// Node 874
			// Node 875
			opcode = aarch64_a64_mov;
			length = 4;
			((aarch64_decode_a64_LOGICAL_SR&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_LOGICAL_SR&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
			((aarch64_decode_a64_LOGICAL_SR&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_LOGICAL_SR&) * this).N = BITSEL(ir, 21);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_LOGICAL_SR&) * this).imm6 = UNSIGNED_BITS(ir, 15, 10);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_LOGICAL_SR&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_LOGICAL_SR&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		// Node 973
		opcode = aarch64_a64_orrsr;
		length = 4;
		((aarch64_decode_a64_LOGICAL_SR&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_LOGICAL_SR&) * this).opc = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_LOGICAL_SR&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
		((aarch64_decode_a64_LOGICAL_SR&) * this).N = BITSEL(ir, 21);
		((aarch64_decode_a64_LOGICAL_SR&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
		((aarch64_decode_a64_LOGICAL_SR&) * this).imm6 = UNSIGNED_BITS(ir, 15, 10);
		((aarch64_decode_a64_LOGICAL_SR&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
		((aarch64_decode_a64_LOGICAL_SR&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOGICAL_SR&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 30, 25)) {
	case 26:
	{
		// Node 126
		// Node 127
		opcode = aarch64_a64_cbz;
		length = 4;
		((aarch64_decode_a64_CMP_B_IMM&) * this).sf = BITSEL(ir, 31);
		((aarch64_decode_a64_CMP_B_IMM&) * this).op = BITSEL(ir, 24);
		((aarch64_decode_a64_CMP_B_IMM&) * this).imm19 = UNSIGNED_BITS(ir, 23, 5);
		((aarch64_decode_a64_CMP_B_IMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_CMP_B_IMM&) * this).decode_behaviour();
		end_of_block = true;
		is_predicated = false;
		return true;
		break;
	}
	case 27:
	{
		// Node 1364
		// Node 1365
		opcode = aarch64_a64_tbz;
		length = 4;
		((aarch64_decode_a64_TEST_B_IMM&) * this).b5 = BITSEL(ir, 31);
		((aarch64_decode_a64_TEST_B_IMM&) * this).op = BITSEL(ir, 24);
		((aarch64_decode_a64_TEST_B_IMM&) * this).b40 = UNSIGNED_BITS(ir, 23, 19);
		((aarch64_decode_a64_TEST_B_IMM&) * this).imm14 = UNSIGNED_BITS(ir, 18, 5);
		((aarch64_decode_a64_TEST_B_IMM&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_TEST_B_IMM&) * this).decode_behaviour();
		end_of_block = true;
		is_predicated = false;
		return true;
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 30, 26)) {
	case 5:
	{
		// Node 71
		// Node 72
		opcode = aarch64_a64_b;
		length = 4;
		((aarch64_decode_a64_UB_IMM&) * this).op = BITSEL(ir, 31);
		((aarch64_decode_a64_UB_IMM&) * this).imm26 = UNSIGNED_BITS(ir, 25, 0);
		((aarch64_decode_a64_UB_IMM&) * this).decode_behaviour();
		end_of_block = true;
		is_predicated = false;
		return true;
		break;
	}
	}
	switch ((ir & BIT_LSB(30)) >> 30) {
	case 0:
	{
		// Node 10
		// Node 11
		switch (UNSIGNED_BITS(ir, 28, 21)) {
		case 208:
		{
			// Node 12
			// Node 13
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 0:
			{
				// Node 14
				// Node 15
				opcode = aarch64_a64_adc;
				length = 4;
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).sf = BITSEL(ir, 31);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).op = BITSEL(ir, 30);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).opcode2 = UNSIGNED_BITS(ir, 15, 10);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).decode_behaviour();
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
			opcode = aarch64_a64_add_ereg;
			length = 4;
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).op = BITSEL(ir, 30);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).opt = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).option = UNSIGNED_BITS(ir, 15, 13);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).imm3 = UNSIGNED_BITS(ir, 12, 10);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 28, 24)) {
		case 11:
		{
			// Node 18
			// Node 19
			switch ((ir & BIT_LSB(21)) >> 21) {
			case 0:
			{
				// Node 20
				// Node 21
				opcode = aarch64_a64_add_sreg;
				length = 4;
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).sf = BITSEL(ir, 31);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).op = BITSEL(ir, 30);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).imm6 = UNSIGNED_BITS(ir, 15, 10);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).decode_behaviour();
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
			opcode = aarch64_a64_addi;
			length = 4;
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).op = BITSEL(ir, 30);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		break;
	}
	case 1:
	{
		// Node 1016
		// Node 1017
		switch (UNSIGNED_BITS(ir, 28, 21)) {
		case 208:
		{
			// Node 1018
			// Node 1019
			switch (UNSIGNED_BITS(ir, 15, 10)) {
			case 0:
			{
				// Node 1020
				// Node 1021
				opcode = aarch64_a64_sbc;
				length = 4;
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).sf = BITSEL(ir, 31);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).op = BITSEL(ir, 30);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).opcode2 = UNSIGNED_BITS(ir, 15, 10);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_ADD_SUB_CARRY&) * this).decode_behaviour();
				is_predicated = false;
				return true;
				break;
			}
			}
			break;
		}
		case 89:
		{
			// Node 1338
			// Node 1339
			opcode = aarch64_a64_sub_ereg;
			length = 4;
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).op = BITSEL(ir, 30);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).opt = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).option = UNSIGNED_BITS(ir, 15, 13);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).imm3 = UNSIGNED_BITS(ir, 12, 10);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_ADD_SUB_EREG&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 28, 22)) {
		case 69:
		{
			// Node 1350
			// Node 1351
			opcode = aarch64_a64_subi;
			length = 4;
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).op = BITSEL(ir, 30);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		case 68:
		{
			// Node 1352
			// Node 1353
			opcode = aarch64_a64_subi;
			length = 4;
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).sf = BITSEL(ir, 31);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).op = BITSEL(ir, 30);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).S = BITSEL(ir, 29);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).imm12 = UNSIGNED_BITS(ir, 21, 10);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
			((aarch64_decode_a64_ADD_SUB_IMM&) * this).decode_behaviour();
			is_predicated = false;
			return true;
			break;
		}
		}
		switch (UNSIGNED_BITS(ir, 28, 24)) {
		case 11:
		{
			// Node 1340
			// Node 1341
			switch ((ir & BIT_LSB(21)) >> 21) {
			case 0:
			{
				// Node 1342
				// Node 1343
				opcode = aarch64_a64_sub_sreg;
				length = 4;
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).sf = BITSEL(ir, 31);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).op = BITSEL(ir, 30);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).S = BITSEL(ir, 29);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).shift = UNSIGNED_BITS(ir, 23, 22);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).rm = UNSIGNED_BITS(ir, 20, 16);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).imm6 = UNSIGNED_BITS(ir, 15, 10);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_ADD_SUB_SREG&) * this).decode_behaviour();
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
	// Node 650
	switch (UNSIGNED_BITS(ir, 29, 24)) {
	case 28:
	{
		// Node 695
		// Node 696
		opcode = aarch64_a64_ldr_lit_simd;
		length = 4;
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).V = BITSEL(ir, 26);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).imm19 = UNSIGNED_BITS(ir, 23, 5);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_LOAD_REG_LIT&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	}
	switch (UNSIGNED_BITS(ir, 29, 27)) {
	case 5:
	{
		// Node 651
		// Node 652
		switch ((ir & BIT_LSB(25)) >> 25) {
		case 0:
		{
			// Node 653
			// Node 654
			switch ((ir & BIT_LSB(23)) >> 23) {
			case 1:
			{
				// Node 655
				// Node 656
				opcode = aarch64_a64_ldpi_simd;
				length = 4;
				((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).opc = UNSIGNED_BITS(ir, 31, 30);
				((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).V = BITSEL(ir, 26);
				((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).P = BITSEL(ir, 24);
				((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).L = BITSEL(ir, 22);
				((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).imm7 = UNSIGNED_BITS(ir, 21, 15);
				((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt2 = UNSIGNED_BITS(ir, 14, 10);
				((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rn = UNSIGNED_BITS(ir, 9, 5);
				((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).rt = UNSIGNED_BITS(ir, 4, 0);
				((aarch64_decode_a64_LS_REG_PAIR_IDX&) * this).decode_behaviour();
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
	switch (UNSIGNED_BITS(ir, 28, 24)) {
	case 16:
	{
		// Node 41
		// Node 42
		opcode = aarch64_a64_adr;
		length = 4;
		((aarch64_decode_a64_PC_REL&) * this).op = BITSEL(ir, 31);
		((aarch64_decode_a64_PC_REL&) * this).immlo = UNSIGNED_BITS(ir, 30, 29);
		((aarch64_decode_a64_PC_REL&) * this).immhi = UNSIGNED_BITS(ir, 23, 5);
		((aarch64_decode_a64_PC_REL&) * this).rd = UNSIGNED_BITS(ir, 4, 0);
		((aarch64_decode_a64_PC_REL&) * this).decode_behaviour();
		is_predicated = false;
		return true;
		break;
	}
	}
	return false;
}
