/* SPDX-License-Identifier: MIT */

#include <hypervisor/cpu.h>
#include <hypervisor/config.h>
#include <captive.h>
#include <hypervisor/guest.h>
#include <engine/engine.h>
#include <unordered_map>

#include <stdio.h>

USE_CONTEXT(Guest);
DECLARE_CHILD_CONTEXT(CPU, Guest);

using namespace captive::hypervisor;

CPU::CPU(int id, Guest& owner, const GuestCPUConfiguration& config, PerCPUData *per_cpu_data) : _id(id), _owner(owner), _config(config), _per_cpu_data(per_cpu_data)
{

}

CPU::~CPU()
{

}

bool CPU::init()
{
	return config().validate();
}

static std::unordered_map<uint64_t, uint64_t> fn_histogram;

void CPU::instrument_dump()
{
	if (fn_histogram.size() == 0) return;
	
	FILE *f = fopen("trace.out", "wt");
	for (auto fn : fn_histogram) {
		std::string fname;
		if (!owner().engine().resolve_symbol(fn.first, fname)) fname = std::to_string(fn.first);
		fprintf(f, "%lu\t%s\n", fn.second, fname.c_str());
	}
	fclose(f);
}

void CPU::instrument_fn_enter(uint64_t fnptr, uint64_t callsite)
{
	fn_histogram[fnptr]++;
}

void CPU::instrument_fn_exit(uint64_t fnptr, uint64_t callsite)
{
	//
}
