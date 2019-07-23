/* SPDX-License-Identifier: MIT */

#include <devices/arm/sp805.h>

using namespace captive::devices::arm;

SP805::SP805() : Primecell(0x00141805)
{

}

SP805::~SP805()
{

}

bool SP805::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;
	data = 0;
	return true;
}

bool SP805::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;
	return true;
}
