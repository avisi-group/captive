/* SPDX-License-Identifier: MIT */

#include <devices/arm/primecell.h>
#include <captive.h>

DECLARE_CONTEXT(Primecell);

using namespace captive::devices::arm;

Primecell::Primecell(uint32_t peripheral_id, uint32_t size) : peripheral_id(peripheral_id), primecell_id(0xb105f00d), _size(size)
{

}

Primecell::~Primecell()
{

}

bool Primecell::read(uint64_t off, uint8_t len, uint64_t& data)
{
	switch(off) {
	case 0xfec:
		data = peripheral_id >> 24;
		return true;
	case 0xfe8:
		data = peripheral_id >> 16;
		return true;
	case 0xfe4:
		data = peripheral_id >> 8;
		return true;
	case 0xfe0:
		data = peripheral_id;
		return true;
	case 0xffc:
		data = primecell_id >> 24;
		return true;
	case 0xff8:
		data = primecell_id >> 16;
		return true;
	case 0xff4:
		data = primecell_id >> 8;
		return true;
	case 0xff0:
		data = primecell_id;
		return true;
	}

	return false;
}

bool Primecell::write(uint64_t off, uint8_t len, uint64_t data)
{
	return false;
}
