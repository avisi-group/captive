/* SPDX-License-Identifier: MIT */

#include <simulation/insn-count.h>
#include <hypervisor/cpu.h>

using namespace captive::simulation;

bool InstructionCounter::init()
{
	return true;
}

void InstructionCounter::start()
{

}

void InstructionCounter::stop()
{

}

void InstructionCounter::dump()
{
	fprintf(stderr, "*** INSTRUCTION COUNT *** (%lu)\n", _count);
	
	for (auto core : cores()) {
		fprintf(stderr, "core %d: %lu\n", core->id(), core->per_cpu_data().insns_executed);
	}
}

void InstructionCounter::process_events(const EventPacket* events, uint32_t count)
{
	for (uint32_t i = 0; i < count; i++) {
		if (events[i].type == EventPacket::INSTRUCTION_FETCH) {
			_count++;
		}
	}
}
