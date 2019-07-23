/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/mc/x86/instruction.h>

namespace captive {
	namespace arch {

		namespace dbt {
			namespace mc {
				namespace x86 {
					class Instruction;

					template<typename Formatter, typename Writer>
					class Printer {
					public:

						void print(const Instruction *head)
						{
							const Instruction *current = head;

							do {
								if (current->kind() != InstructionKind::DEAD) {
									writer.print(formatter.format_instruction(current));
									writer.print("\n");
								}

								current = current->next();
							} while (current != head);
						}

						Formatter formatter;
						Writer writer;
					};
				}
			}
		}
	}
}
