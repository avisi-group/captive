/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl131.h>

using namespace captive::devices::arm;

PL131::PL131() : Primecell(0x00041131)
{

}

PL131::~PL131()
{

}

bool PL131::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;
	return false;
}

bool PL131::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;
	return false;
}
