/* SPDX-License-Identifier: MIT */

#include <devices/arm/generic-timer.h>
#include <devices/timers/timer-manager.h>
#include <devices/irq/irq-line.h>

using namespace captive::devices::arm;

GenericTimer::GenericTimer(timers::TimerManager& timer_manager, irq::IRQLineBase& irq) : timer_manager(timer_manager), irq(irq), Control(*this)
{
}

GenericTimer::~GenericTimer() {

}

bool GenericTimer::_Control::read(uint64_t off, uint8_t len, uint64_t& data)
{
	fprintf(stderr, "gt: invalid register read @ %lx\n", off);
	
	data = 0;
	return true;
}

bool GenericTimer::_Control::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (off == 0xfff && len == 1) {
		if (data & 1) {
			_owner.irq.raise();
		} else {
			_owner.irq.rescind();
		}
		
		return true;
	}
	
	fprintf(stderr, "gt: invalid register write @ %lx = %lx\n", off, data);
	return true;
}
