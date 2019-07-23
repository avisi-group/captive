/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_syscall(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	tcb.emit16(0x050f);
	return true;
}

bool Encoder::encode_sysenter(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return false;
}

bool Encoder::encode_sysret(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	return false;
}

bool Encoder::encode_int(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& nr = insn->get_operand(0);

	if (!nr.is_const() || nr.constant.width != 8) return false;

	if (nr.constant.value == 3) {
		tcb.emit8(0xcc);
	} else {
		tcb.emit8(0xcd);
		tcb.emit8(nr.constant.value);
	}

	return true;
}

bool Encoder::encode_out(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& val = insn->get_operand(0);
	const Operand& port = insn->get_operand(1);

	if (!val.is_reg() || val.reg.reg != X86PhysicalRegisters::A) return false;
	if (!port.is_const() || port.constant.width != 8) return false;

	if (val.reg.width == 8) {
		tcb.emit8(0xe6);
	} else if (val.reg.width == 16) {
		tcb.emit16(0xe766);
	} else if (val.reg.width == 32) {
		tcb.emit8(0xe7);
	} else {
		return false;
	}

	tcb.emit8(port.constant.value);

	return true;
}

bool Encoder::encode_mxcsr(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& op = insn->get_operand(0);
	if (!op.is_mem()) return false;

	switch (insn->kind()) {
	case InstructionKind::LDMXCSR:
		return encode_opcode_modrm_oper(tcb, 0x1ae, 2, op);
	case InstructionKind::STMXCSR:
		return encode_opcode_modrm_oper(tcb, 0x1ae, 3, op);
	default:
		return false;
	}
}

bool Encoder::encode_pku(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	tcb.emit8(0x0f);
	tcb.emit8(0x01);

	switch (insn->kind()) {
	case InstructionKind::WRPKU:
		tcb.emit8(0xef);
		return true;
	case InstructionKind::RDPKU:
		tcb.emit8(0xee);
		return true;
	default:
		return false;
	}
}

bool Encoder::encode_rd_sr_base(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	tcb.emit8(0xf3);

	switch (insn->kind()) {
	case InstructionKind::RDFSBASE:
		return encode_opcode_modrm_oper(tcb, 0x1ae, 0, insn->get_operand(0));
	case InstructionKind::RDGSBASE:
		return encode_opcode_modrm_oper(tcb, 0x1ae, 1, insn->get_operand(0));
	default:
		return false;
	}
}
