/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

bool Encoder::encode_nop(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const auto& operand = insn->get_operand(0);

	if (operand.kind == OperandKind::INVALID) {
		tcb.emit8(0x90);
		return true;
	} else if (operand.is_mem()) {
		return encode_opcode_modrm_oper(tcb, 0x11f, 0, operand);
	}

	return false;
}

bool Encoder::encode_jmp(TranslatedCodeBuffer& tcb, const Instruction *insn)
{
	const auto& target = insn->get_operand(0);

	switch (target.kind) {
	case OperandKind::LABEL:
	{
		tcb.emit8(0xe9);

		dbt_off_t offset = tcb.emit32(0);
		register_relocation(offset, 32, target.label.target);

		return true;
	}

	case OperandKind::REGISTER:
	case OperandKind::MEMORY:
		return encode_opcode_modrm_oper(tcb, 0xff, 4, target, true);

	default:
		assert_true(false, "jmp: invalid target operand", insn);
		return false;
	}
}

bool Encoder::encode_cjmp(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& target = insn->get_operand(0);

	unsigned int jmp_type;
	switch (insn->kind()) {
	case InstructionKind::JO: jmp_type = 0;
		break;
	case InstructionKind::JNO: jmp_type = 1;
		break;
	case InstructionKind::JB: case InstructionKind::JNAE: case InstructionKind::JC: jmp_type = 2;
		break;
	case InstructionKind::JNB: case InstructionKind::JAE: case InstructionKind::JNC: jmp_type = 3;
		break;
	case InstructionKind::JZ: case InstructionKind::JE: jmp_type = 4;
		break;
	case InstructionKind::JNZ: case InstructionKind::JNE: jmp_type = 5;
		break;
	case InstructionKind::JBE: case InstructionKind::JNA: jmp_type = 6;
		break;
	case InstructionKind::JNBE: case InstructionKind::JA: jmp_type = 7;
		break;
	case InstructionKind::JS: jmp_type = 8;
		break;
	case InstructionKind::JNS: jmp_type = 9;
		break;
	case InstructionKind::JP: case InstructionKind::JPE: jmp_type = 10;
		break;
	case InstructionKind::JNP: case InstructionKind::JPO: jmp_type = 11;
		break;
	case InstructionKind::JL: case InstructionKind::JNGE: jmp_type = 12;
		break;
	case InstructionKind::JNL: case InstructionKind::JGE: jmp_type = 13;
		break;
	case InstructionKind::JLE: case InstructionKind::JNG: jmp_type = 14;
		break;
	case InstructionKind::JNLE: case InstructionKind::JG: jmp_type = 15;
		break;
	default: assert_true(false, "cjmp: invalid conditional jump type", insn);
		return false;
	}

	switch (target.kind) {
	case OperandKind::LABEL:
	{
		tcb.emit8(0x0f);
		tcb.emit8(0x80 | (jmp_type & 0xf));

		dbt_off_t offset = tcb.emit32(0);
		register_relocation(offset, 32, target.label.target);

		return true;
	}

	case OperandKind::CONSTANT:
	{
		if (target.constant.width == 8) {
			tcb.emit8(0x70 | (jmp_type & 0xf));
			tcb.emit8(target.constant.value);
		} else {
			return false;
		}

		return true;
	}

	default:
		assert_true(false, "cjmp: invalid target operand", insn);
		return false;
	}
}

bool Encoder::encode_ret(TranslatedCodeBuffer& tcb, const Instruction *insn)
{
	tcb.emit8(0xc3);
	return true;
}

bool Encoder::encode_call(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& target = insn->get_operand(0);

	switch (target.kind) {
	case OperandKind::REGISTER:
	{
		if (target.reg.reg.needs_extension()) {
			tcb.emit8(0x41);
		}

		tcb.emit8(0xff);
		encode_mod_reg_rm(tcb, Operand::make_register(X86Registers::RDX), target);

		return true;
	}

	default:
		assert_true(false, "call: invalid target operand", insn);
		return false;
	}
}

bool Encoder::encode_lcall(TranslatedCodeBuffer& tcb, const Instruction* insn)
{
	const Operand& target = insn->get_operand(0);

	if (!target.is_mem()) return false;

	return encode_opcode_modrm_oper(tcb, 0xff, 3, target);
}

void Encoder::register_label(dbt_off_t offset, const Instruction* label)
{
	_labels.put(label, offset);
}

void Encoder::register_relocation(dbt_off_t offset, dbt_u8 width_in_bits, const Instruction* target)
{
	_relocations.put(offset, target);
}

void Encoder::perform_relocations(TranslatedCodeBuffer& tcb)
{
	for (const auto& reloc : _relocations) {
		dbt_off_t label_offset = 0;
		if (!_labels.get(reloc.value(), label_offset)) {
			assert_true(false, "relocation to unregistered label", nullptr);
			return;
		}

		dbt_s32 target_offset = label_offset - (reloc.key() + 4);
		tcb.write32(reloc.key(), (dbt_u32) target_offset);
	}
}
