/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl350.h>

using namespace captive::devices::arm;

PL350::PL350() : Primecell(0x00041354)
{

}

PL350::~PL350()
{

}

bool PL350::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;
	return false;
}

bool PL350::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;
	return false;
}
