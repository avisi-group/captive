/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl330.h>

using namespace captive::devices::arm;


PL330::PL330() : Primecell(0x00041330)
{

}

PL330::~PL330()
{

}

bool PL330::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;
	
	data = 0;
	return true;
}

bool PL330::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;
	return true;
}
