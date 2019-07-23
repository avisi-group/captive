/* SPDX-License-Identifier: MIT */

#include <devices/arm/sp810.h>
#include <devices/timers/timer-manager.h>
#include <captive.h>

#include <chrono>

#define LOCK_VALUE 0xa05f

using namespace captive::devices::arm;

SP810::SP810(timers::TimerManager& timer_manager) : Primecell(0x00041011), _timer_manager(timer_manager), leds(0), lockval(0), colour_mode(0x1f00), cfgdata1(0), cfgdata2(0)
{
}

SP810::~SP810()
{

}

bool SP810::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;

	data = 0;
	
	switch (off) {
	case 0x00:
		//data = 0x41008004;
		data = 0x3262F400;
		break;

	case 0x04:
		data = 0;
		break;

	case 0x08:
		data = leds;
		break;

	case 0x0c:
	case 0x10:
	case 0x14:
	case 0x18:
	case 0x1c:
		data = 0;
		break;

	case 0x20:
		data = lockval;
		break;

	case 0x24:
		data = std::chrono::duration_cast<tick_100Hz_t>(_timer_manager.ticks()).count();
		break;
		
	case 0x28:
		data = cfgdata1;
		break;

	case 0x2c:
		data = cfgdata2;
		break;

	case 0x50:
		data = colour_mode;
		break;

	case 0x5c:
		data = std::chrono::duration_cast<tick_24MHz_t>(_timer_manager.ticks()).count();
		break;
	}

	return true;
}

bool SP810::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;

	switch (off) {
	case 0x00:
		break;

	case 0x08:	// LEDs
		leds = data;
		break;

	case 0x20:	// Lock Val
		if (data == LOCK_VALUE) lockval = data;
		else lockval = data & 0x7fff;
		break;

	case 0x28:
		cfgdata1 = data;
		break;

	case 0x2c:
		cfgdata2 = data;
		break;
		
	case 0x50:	// LCD
		colour_mode &= 0x3f00;
		colour_mode |= (data & ~0x3f00);
		break;
	}

	return true;
}
