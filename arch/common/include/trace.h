/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <printf.h>

#define MAX_RECORD_ACTIONS 32

namespace captive {
	namespace arch {
		class Disasm;
		class Decode;

		class Trace {
		public:
			Trace(Disasm& disasm);
			~Trace();

			inline Disasm& disasm() const
			{
				return _disasm;
			}

			inline void enable()
			{
				_enabled = true;
			}

			inline void disable()
			{
				_enabled = false;
			}

			inline bool enabled() const
			{
				return _enabled;
			}

			inline bool recording() const
			{
				return _building_record;
			}

			struct trace_action {

				enum action_type {
					REG_READ,
					REG_WRITE,
					REG_BANK_READ,
					REG_BANK_WRITE,
					MEM_READ,
					MEM_WRITE,
					MESSAGE
				};

				action_type type;

				union {

					struct {
						const char *reg_id;
						uint32_t value;
					} reg_read, reg_write;

					struct {
						const char *bank_id;
						uint32_t reg_idx;
						uint32_t value;
					} reg_bank_read, reg_bank_write;

					struct {
						uint32_t mem_addr;
						uint32_t value;
					} mem_read, mem_write;

					struct {
						const char *msg;
					} message;
				};
			} packed;

			struct trace_record {
				uint64_t insn_count;
				uint32_t pc;

				uint8_t decode_data[128];

				int nr_actions;
				trace_action actions[MAX_RECORD_ACTIONS];
			} packed;

			void start_record(uint64_t insn_count, uint32_t pc, const Decode *decode_data);
			void abort_record();
			void end_record();

			void add_action(const trace_action& action);

			inline void add_str(const char *str)
			{
				trace_action action;
				action.type = trace_action::MESSAGE;
				action.message.msg = str;

				add_action(action);
			}

			inline void add_reg_read(const char *reg_id, uint32_t value)
			{
				trace_action action;
				action.type = trace_action::REG_READ;
				action.reg_read.reg_id = reg_id;
				action.reg_read.value = value;

				add_action(action);
			}

			inline void add_reg_write(const char *reg_id, uint32_t value)
			{
				trace_action action;
				action.type = trace_action::REG_WRITE;
				action.reg_read.reg_id = reg_id;
				action.reg_read.value = value;

				add_action(action);
			}

			inline void add_reg_bank_read(const char *bank_id, uint32_t reg_idx, uint32_t value)
			{
				trace_action action;
				action.type = trace_action::REG_BANK_READ;
				action.reg_bank_read.bank_id = bank_id;
				action.reg_bank_read.reg_idx = reg_idx;
				action.reg_bank_read.value = value;

				add_action(action);
			}

			inline void add_reg_bank_write(const char *bank_id, uint32_t reg_idx, uint32_t value)
			{
				trace_action action;
				action.type = trace_action::REG_BANK_WRITE;
				action.reg_bank_read.bank_id = bank_id;
				action.reg_bank_read.reg_idx = reg_idx;
				action.reg_bank_read.value = value;

				add_action(action);
			}

		private:
			Disasm& _disasm;
			bool _enabled;
			bool _building_record;
			trace_record current_record;
		};
	}
}
