/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl041.h>

using namespace captive::devices::arm;

PL041::PL041() : Primecell(0)
{

}

PL041::~PL041()
{

}

bool PL041::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;
	return false;
}

bool PL041::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;
	return false;
}
