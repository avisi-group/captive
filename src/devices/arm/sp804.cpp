/* SPDX-License-Identifier: MIT */

#include <devices/arm/sp804.h>
#include <devices/irq/irq-line.h>
#include <captive.h>

#include <mutex>

using namespace captive::devices::arm;

SP804::SP804(timers::TimerManager& timer_manager, irq::IRQLineBase& irq) : Primecell(0x00141804), irq(irq)
{
	timers[0].owner(*this);
	timers[1].owner(*this);

	timer_manager.add_timer(RATE_MHZ, *this);
}

SP804::~SP804()
{

}

bool SP804::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;

	if (off < 0x20) {
		return timers[0].read(off, len, data);
	} else if (off < 0x40) {
		return timers[1].read(off - 0x20, len, data);
	}

	return false;
}

bool SP804::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;

	if (off < 0x20) {
		return timers[0].write(off, len, data);
	} else if (off < 0x40) {
		return timers[1].write(off - 0x20, len, data);
	}

	return false;
}

void SP804::timer_expired(uint64_t ticks)
{
	if (timers[0].enabled()) timers[0].tick(ticks);
	if (timers[1].enabled()) timers[1].tick(ticks);
}

void SP804::update_irq()
{
	if ((timers[0].isr() && timers[0].irq_enabled()) || (timers[1].isr() && timers[1].irq_enabled())) {
		irq.raise();
	} else {
		irq.rescind();
	}
}

SP804::SP804Timer::SP804Timer() : _enabled(false), load_value(0), current_value(0xffffffff), _isr(0)
{
	control_reg.value = 0x20;
}

bool SP804::SP804Timer::read(uint64_t off, uint8_t len, uint64_t& data)
{
	//std::shared_lock<std::shared_timed_mutex> l(lock);
	
	switch (off) {
	case 0x00:
		data = load_value;
		break;

	case 0x04:
		data = current_value;
		break;

	case 0x08:
		data = control_reg.value;
		break;

	case 0x10:
		data = _isr;
		break;

	case 0x14:
		data = _isr & control_reg.bits.int_en;
		break;

	case 0x18:
		data = load_value;
		break;

	default:
		return false;
	}

	return true;
}

bool SP804::SP804Timer::write(uint64_t off, uint8_t len, uint64_t data)
{
	std::unique_lock<std::shared_timed_mutex> l(lock);
	
	switch (off) {
	case 0x00:
		load_value = data;
		current_value = data;
		break;

	case 0x04:
		break;

	case 0x08:
		control_reg.value = data;
		update();
		break;

	case 0x0c:
		_isr = 0;
		_owner->update_irq();
		break;

	case 0x18:
		load_value = data;
		break;

	default:
		return false;
	}

	return true;
}

void SP804::SP804Timer::tick(uint64_t delta)
{
	if (!_enabled) return;
	
	std::unique_lock<std::shared_timed_mutex> l(lock);
	if (current_value.fetch_sub(delta) <= delta) {
		init_period();

		_isr |= 1;
		if (control_reg.bits.int_en) _owner->update_irq();
	}
}

void SP804::SP804Timer::update()
{
	if (control_reg.bits.enable && !_enabled) {
		init_period();
		_enabled = true;
	} else if (!control_reg.bits.enable && _enabled) {
		_enabled = false;
	}

	_owner->update_irq();
}

void SP804::SP804Timer::init_period()
{
	if (control_reg.bits.mode == 0) {
		if (control_reg.bits.size == 0) {
			current_value = 0xffff;
		} else {
			current_value = 0xffffffff;
		}
	} else {
		current_value = load_value;
	}
}
