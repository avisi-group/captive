/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_vfmadd(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	auto& op0 = insn->get_operand(0);
	auto& op1 = insn->get_operand(1);
	auto& op2 = insn->get_operand(2);

	if (insn->match3() != InstructionMatch::FREG_FREG_FREG) return false;

	unsigned char vex[3] = {0xc4, 0xe2, 0x00};

	vex[2] = ((~op1.reg.reg.unique_index()) & 0xf) << 3;
	vex[2] |= 1;

	switch (insn->kind()) {
	case InstructionKind::VFMADD132SD:
	case InstructionKind::VFMADD213SD:
	case InstructionKind::VFMADD231SD:
		vex[2] |= 0x80;
		break;
	default: break;
	}

	tcb.emit8(vex[0]);
	tcb.emit8(vex[1]);
	tcb.emit8(vex[2]);

	// opcode
	switch (insn->kind()) {
	case InstructionKind::VFMADD132SD:
	case InstructionKind::VFMADD132SS:
		tcb.emit8(0x99);
		break;
	case InstructionKind::VFMADD213SD:
	case InstructionKind::VFMADD213SS:
		tcb.emit8(0xa9);
		break;
	case InstructionKind::VFMADD231SD:
	case InstructionKind::VFMADD231SS:
		tcb.emit8(0xb9);
		break;
	default: return false;
	}

	char modrm = 0xc0;
	modrm |= (op0.reg.reg.unique_index() & 0x7) << 0;
	modrm |= (op2.reg.reg.unique_index() & 0x7) << 3;

	tcb.emit8(modrm);
	return true;
}
