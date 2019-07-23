/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl310.h>

using namespace captive::devices::arm;

PL310::PL310() : ctrl(0), aux(0x02020000), tag(0), dc(0)
{
	
}

PL310::~PL310()
{
}

bool PL310::read(uint64_t off, uint8_t len, uint64_t& data)
{
	switch (off) {
	case 0x000:
		data = 0x410000c8;
		return true;
		
	case 0x100:
		data = ctrl;
		return true;
		
	case 0x104:
		data = aux;
		return true;

	case 0x108:
		data = tag;
		return true;

	case 0x10c:
		data = dc;
		return true;

	case 0xc00:
		data = filt_start;
		return true;

	case 0xc04:
		data = filt_end;
		return true;
		
	case 0xf40:
	case 0xf60:
	case 0xf80:
		data = 0;
		return true;
	}
	
	//fprintf(stderr, "pl310: invalid register read @ %x\n", off);
	data = 0;
	return true;
}

bool PL310::write(uint64_t off, uint8_t len, uint64_t data)
{
	switch (off) {
	case 0x100:
		ctrl = data;
		return true;
	case 0x104:
		aux = data;
		return true;
	case 0x108:
		tag = data;
		return true;
	case 0x10c:
		dc = data;
		return true;
	case 0xc00:
		filt_start = data;
		return true;
	case 0xc04:
		filt_end = data;
		return true;
		
	case 0xf40:
	case 0xf60:
	case 0xf80:
		return true;
	}
	
	//fprintf(stderr, "pl310: invalid register write @ %x = %x\n", off, data);
	return true;
}
