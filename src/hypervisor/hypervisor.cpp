/* SPDX-License-Identifier: MIT */

#include <hypervisor/hypervisor.h>
#include <captive.h>

DECLARE_CONTEXT(Hypervisor);

using namespace captive::hypervisor;

Hypervisor::Hypervisor(Debugger *debugger) : _debugger(debugger)
{

}

Hypervisor::~Hypervisor()
{

}

bool Hypervisor::init()
{
	if (debugger()) {
		if (!debugger()->init()) {
			return false; 
		}
	}
	
	return true;
}
