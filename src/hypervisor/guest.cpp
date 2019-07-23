/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <hypervisor/config.h>
#include <hypervisor/guest.h>
#include <hypervisor/semihosting-context.h>
#include <platform/platform.h>
#include <simulation/simulation.h>

#include <chrono>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

USE_CONTEXT(Hypervisor)
DECLARE_CHILD_CONTEXT(Guest, Hypervisor);

#define MAX_PHYS_MEM_SIZE		0x100000000
#define MIN_PHYS_MEM_SIZE		0

using namespace captive::hypervisor;

__thread CPU *Guest::current_core;

Guest::Guest(Hypervisor& owner, engine::Engine& engine, platform::Platform& pfm) : _owner(owner), _engine(engine), _pfm(pfm), simulation_event_buffer(nullptr), _semihosting_ctx(nullptr)
{

}

Guest::~Guest()
{

}

bool Guest::init(const util::config::Configuration& cfg)
{
	if (!platform().config().validate())
		return false;

	return true;
}

bool Guest::init_semihosting()
{
	if (_semihosting_ctx != nullptr) {
		return _semihosting_ctx->init();
	} else {
		return true;
	}
}

bool Guest::initialise_simulations(void *seb)
{
	simulation_event_buffer = (uint64_t *)seb;
	
	for (auto sim : _simulations) {
		if (!sim->init()) return false;
	}
	
	return true;
}

void Guest::start_simulations()
{
	for (auto sim : _simulations) {
		sim->start();
	}
}

void Guest::stop_simulations()
{
	for (auto sim : _simulations) {
		sim->stop();
		sim->dump();
	}
}

void Guest::dump_simulations()
{
	for (auto sim : _simulations)
	{
		sim->dump();
	}
}


void Guest::add_simulation(simulation::Simulation& simulation)
{
	_simulations.push_back(&simulation);
}

void Guest::handle_simulation_events(CPU& core, uint32_t count)
{
	for (auto sim : _simulations) {
		sim->process_events((const simulation::Simulation::EventPacket *)(simulation_event_buffer + 1), count);
	}
}

bool Guest::handle_semihosting_call(CPU& core, SemihostingCallData& call_data)
{
	if (_semihosting_ctx == nullptr) return false;
	return _semihosting_ctx->handle_semihosting_call(call_data);
}
