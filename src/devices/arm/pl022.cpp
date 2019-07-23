/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl022.h>

using namespace captive::devices::arm;

PL022::PL022() : Primecell(0xdeadbeef) //0x00241022)
{

}

PL022::~PL022()
{

}

bool PL022::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;
	return false;
}

bool PL022::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;
	return false;
}
