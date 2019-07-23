/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl080.h>

using namespace captive::devices::arm;

PL080::PL080() : Primecell(0x0a041080)
{

}

PL080::~PL080()
{

}

bool PL080::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;
	return false;
}

bool PL080::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;
	return false;
}
