/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl354.h>

using namespace captive::devices::arm;


PL354::PL354() : Primecell(0x00041354)
{

}

PL354::~PL354()
{

}

bool PL354::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;

	data = 0;
	return true;
}

bool PL354::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;
	return true;
}
