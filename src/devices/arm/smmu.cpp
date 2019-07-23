/* SPDX-License-Identifier: MIT */

#include <devices/arm/smmu.h>

using namespace captive::devices::arm;

SMMU::SMMU()
{
	
}

SMMU::~SMMU()
{

}

bool SMMU::read(uint64_t off, uint8_t len, uint64_t& data)
{
	data = 0;
	return true;
}

bool SMMU::write(uint64_t off, uint8_t len, uint64_t data)
{
	return true;
}
