/* SPDX-License-Identifier: MIT */

#include <devices/arm/sbcon.h>

using namespace captive::devices::arm;

SBCON::SBCON() : in(0), out(0)
{
	
}

SBCON::~SBCON()
{
	
}

bool SBCON::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (off == 0) {
		data = (out & 1) | (in << 1);
		return true;
	}
	
	return false;
}

bool SBCON::write(uint64_t off, uint8_t len, uint64_t data)
{
	switch (off) {
	case 0:
		out |= data & 3;
		return true;
	case 4:
		out &= ~(data & 3);
		return true;
	}
	
	return false;
}
