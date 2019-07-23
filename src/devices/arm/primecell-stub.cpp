/* SPDX-License-Identifier: MIT */

#include <devices/arm/primecell-stub.h>

using namespace captive::devices::arm;

PrimecellStub::PrimecellStub(uint32_t device_id, std::string name, uint32_t size) : Primecell(device_id), _name(name), _size(size)
{

}

PrimecellStub::~PrimecellStub()
{

}

bool PrimecellStub::read(uint64_t off, uint8_t len, uint64_t& data)
{
	Primecell::read(off, len, data);
	return true;
}

bool PrimecellStub::write(uint64_t off, uint8_t len, uint64_t data)
{
	Primecell::write(off, len, data);
	return true;
}
