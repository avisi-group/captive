/* SPDX-License-Identifier: MIT */

#include <trace.h>
#include <disasm.h>
#include <string.h>
#include <printf.h>

using namespace captive::arch;

Trace::Trace(Disasm& disasm) : _disasm(disasm), _enabled(false), _building_record(false)
{

}

Trace::~Trace()
{

}

void Trace::start_record(uint64_t insn_count, uint32_t pc, const Decode *decode_obj)
{
	if (!_enabled) return;
	if (_building_record) return;
	_building_record = true;

	current_record.insn_count = insn_count;
	current_record.pc = pc;
	current_record.nr_actions = 0;

	memcpy((void *) &current_record.decode_data[0], (const void *) decode_obj, sizeof(current_record.decode_data));
}

void Trace::abort_record()
{
	_building_record = false;
}

void Trace::end_record()
{
	if (!_building_record) return;
	_building_record = false;

	printf("%d [%08x] ", current_record.insn_count, current_record.pc);
	printf("%20s", _disasm.disassemble(current_record.pc, current_record.decode_data));

	for (int i = 0; i < current_record.nr_actions; i++) {
		const trace_action& action = current_record.actions[i];

		switch (action.type) {
		case trace_action::REG_BANK_WRITE:
			printf("(RB[%s][%d] <= %08x)", action.reg_bank_write.bank_id, action.reg_bank_write.reg_idx, action.reg_bank_write.value);
			break;
		case trace_action::REG_BANK_READ:
			printf("(RB[%s][%d] => %08x)", action.reg_bank_read.bank_id, action.reg_bank_read.reg_idx, action.reg_bank_read.value);
			break;
		case trace_action::REG_WRITE:
			printf("(R[%s] <= %08x)", action.reg_write.reg_id, action.reg_write.value);
			break;
		case trace_action::REG_READ:
			printf("(R[%s] => %08x)", action.reg_read.reg_id, action.reg_read.value);
			break;
		case trace_action::MESSAGE:
			printf("\"%s\"", action.message.msg);
			break;
		default:
			printf("(?)");
			break;
		}
	}
	printf("\n");
}

void Trace::add_action(const trace_action& action)
{
	if (!_building_record) return;
	if (current_record.nr_actions == MAX_RECORD_ACTIONS) return;

	current_record.actions[current_record.nr_actions] = action;
	current_record.nr_actions++;
}
