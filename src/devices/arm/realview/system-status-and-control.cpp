/* SPDX-License-Identifier: MIT */

#include <devices/arm/realview/system-status-and-control.h>
#include <devices/timers/timer-manager.h>

#include <captive.h>

#include <map>

DECLARE_CONTEXT(SystemStatusAndControl);

#define LOCK_VALUE 0xa05f

using namespace captive::devices::arm::realview;

std::map<uint64_t, uint64_t> off_reads, off_writes;

SystemStatusAndControl::SystemStatusAndControl(timers::TimerManager& timer_manager) : 
	_timer_manager(timer_manager),
	osc { 0x00012c5c, 0x00002cc0, 0x00002c75, 0x00020211, 0x00002c75 },
	colour_mode(0x1f00),
	lockval(0),
	leds(0),
	flags(0)
{
	
}
SystemStatusAndControl::~SystemStatusAndControl() {
	for (auto off : off_reads) {
		fprintf(stderr, "rd %03lx: %lu\n", off.first, off.second);
	}
	for (auto off : off_writes) {
		fprintf(stderr, "wr %03lx: %lu\n", off.first, off.second);
	}
}

	
bool SystemStatusAndControl::read(uint64_t off, uint8_t len, uint64_t& data)
{
	//off_reads[off]++;
	
	switch (off) {
	case 0x000:
		data = 0x01780500;		// Cortex A8;
		//data = 0x1182f500;		// Cortex A9;
		return true;
		
	case 0x004:
		data = 0;
		return true;
		
	case 0x008:
		data = leds;
		return true;
		
	case 0x020:
		data = lockval;
		return true;
		
	case 0x30:
		data = flags;
		return true;
		
	case 0x05c:
		data = std::chrono::duration_cast<tick_24MHz_t>(_timer_manager.ticks()).count();
		return true;
		
	case 0x50:
		data = colour_mode;
		return true;
		
	case 0x84:
		data = 0x0c000000;
		return true;
		
	case 0x88:
		data = 0xff000000;
		return true;
		
	case 0x00c ... 0x001c:
		data = osc[(off - 0xc) >> 2];
		return true;
	}
	
	ERROR << CONTEXT(SystemStatusAndControl) << "Unknown register read @ " << std::hex << off;
	return false;
}

bool SystemStatusAndControl::write(uint64_t off, uint8_t len, uint64_t data)
{
	//off_writes[off]++;
	
	switch (off) {
	case 0x008:
		leds = data;
		return true;
		
	case 0x00c ... 0x01c:
		osc[(off - 0x00c) >> 2] = data;
		return true;

	case 0x20:
		if (data == LOCK_VALUE) lockval = data;
		else lockval = data & 0x7fff;
		return true;
		
	case 0x30:
		flags |= data;
		return true;
		
	case 0x34:
		flags &= ~data;
		return true;
		
	case 0x40:
		DEBUG << CONTEXT(SystemStatusAndControl) << "Unknown RESET register write @ " << std::hex << off << " = " << data << ENABLE;
		return true;
		
	case 0x050:
		colour_mode &= 0x3f00;
		colour_mode |= (data & ~0x3f00);
		return true;
	}
	
	ERROR << CONTEXT(SystemStatusAndControl) << "Unknown register write @ " << std::hex << off << " = " << data;
	return false;
}
