/* SPDX-License-Identifier: MIT */

#include <devices/arm/mhu.h>

using namespace captive::devices::arm;

MHU::MHU()
{
	
}

bool MHU::read(uint64_t off, uint8_t len, uint64_t& data)
{
	fprintf(stderr, "mhu: read: %lu %u\n", off, len);
	data = 0;
	return true;
}

bool MHU::write(uint64_t off, uint8_t len, uint64_t data)
{
	fprintf(stderr, "mhu: write: %lu %u %lu\n", off, len, data);
	return true;
}
