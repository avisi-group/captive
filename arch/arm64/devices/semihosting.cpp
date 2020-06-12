/* SPDX-License-Identifier: MIT */

#include <devices/semihosting.h>
#include <arm64-cpu.h>
#include <mmu/guest-mmu.h>
#include <arm64-env.h>
#include <printf.h>

#include "mmu/strategy/strategy.h"

using namespace captive::arch;
using namespace captive::arch::arm64::devices;

SemihostingHandler::SemihostingHandler(arm64_environment& env) : CoreDevice(env)
{
}

bool SemihostingHandler::read(CPU& cpu, uint32_t reg, uint64_t& data)
{
	return false;
}

bool SemihostingHandler::write(CPU& cpu, uint32_t reg, uint64_t data)
{
	arm64_cpu& core = (arm64_cpu&) cpu;

	switch (reg) {
	case 0:
	{
		uint64_t semihosting_call_no, args, result;

		semihosting_call_no = core.reg_offsets.RBX[0];
		args = core.reg_offsets.RBX[1];

		captive::arch::mmu::AddressTranslationContext atc;

		if (captive::arch::mmu::strategy::mmu_strategy.enabled()) {
			atc.privilege = captive::arch::mmu::AddressTranslationPrivilege::SUPERVISOR;
			atc.type = captive::arch::mmu::AddressTranslationType::READ;

			if (!captive::arch::mmu::guest_mmu.translate(args, atc)) {
				printf("XXX MEMORY FAILURE WHEN RESOLVING ARGUMENTS\n");
				return false;
			}

			if (atc.result != captive::arch::mmu::AddressTranslationResult::OK) {
				printf("XXX MEMORY FAULT WHEN RESOLVING ARGUMENTS\n");
				return false;
			}

			args = atc.pa;
		}

		asm volatile("out %%al, $0xed" : "=a"(result) : "a"(semihosting_call_no), "D"(args));

		core.reg_offsets.RBX[0] = result;
		return true;
	}
	case 1:
	{
		uint64_t result;

		asm volatile("mov %0, %%r8" ::"r"(core.reg_offsets.RBX[0]));
		asm volatile("mov %0, %%r9" ::"r"(core.reg_offsets.RBX[1]));
		asm volatile("mov %0, %%r10" ::"r"(core.reg_offsets.RBX[2]));
		asm volatile("mov %0, %%r11" ::"r"(core.reg_offsets.RBX[3]));
		asm volatile("mov %0, %%r12" ::"r"(core.reg_offsets.RBX[4]));
		asm volatile("mov %0, %%r13" ::"r"(core.reg_offsets.RBX[5]));
		asm volatile("mov %0, %%r14" ::"r"(core.reg_offsets.RBX[8]));
		asm volatile("out %%al, $0xed" : "=a"(result) : "a"(data));

		core.reg_offsets.RBX[0] = result;
		return true;
	}
	default:
		printf("XXX %x\n", reg);
		return false;
	}
}
