/* SPDX-License-Identifier: MIT */

#include <platform/platform.h>

using namespace captive;
using namespace captive::platform;
using namespace captive::devices::timers;

Platform::Platform(const util::config::Configuration& cfg, TimerManager& timer_manager) : _cfg(cfg), _timer_manager(timer_manager)
{
	
}

Platform::~Platform()
{
	
}

void Platform::dump() const
{
	fprintf(stderr, "(no platform info)\n");
}

bool Platform::prepare_guest_memory(void* ptr)
{
	return true;
}

gpa_t Platform::stackpointer() const
{
	return 0;
}
