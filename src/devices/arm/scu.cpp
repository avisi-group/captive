/* SPDX-License-Identifier: MIT */

#include <devices/arm/scu.h>

using namespace captive::devices::arm;

SnoopControlUnit::SnoopControlUnit() : control(0)
{
}

SnoopControlUnit::~SnoopControlUnit()
{
}

#define NR_CPU 2

bool SnoopControlUnit::read(uint64_t off, uint8_t len, uint64_t& data)
{
	switch (off) {
	case 0x00:
		data = control;
		return true;
		
	case 0x04:
        data = (((1 << NR_CPU) - 1) << 4) | (NR_CPU - 1);
		return true;
	}
	
	fprintf(stderr, "scu: unknown register read: %02lx\n", off);
	return false;
}

bool SnoopControlUnit::write(uint64_t off, uint8_t len, uint64_t data)
{
	switch (off) {
	case 0x00:
		control = data & 1;
		return true;
	}
	
	fprintf(stderr, "scu: unknown register write: %02lx\n", off);
	return false;
}