/* SPDX-License-Identifier: MIT */

#include <devices/arm/realview/system-controller.h>

using namespace captive::devices::arm::realview;

SystemController::SystemController(ControllerIndex index) : Primecell(0x00041011), index(index), cr(0)
{

}

bool SystemController::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data)) return true;
	
	if (off == 0) {
		data = cr;
		return true;
	}
	
	return false;
}

bool SystemController::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data)) return true;
	
	if (off == 0) {
		cr = data;
		return true;
	}
	
	return false;
}
