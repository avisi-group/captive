/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl061.h>

using namespace captive::devices::arm;

PL061::PL061(irq::IRQLineBase& irq) : Primecell(0x00041061), _irq(irq)
{

}

PL061::~PL061()
{

}

bool PL061::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;
	
	switch (off) {
	case 0x000 ... 0x3fc:
		return true;
		
	case 0x400:
		data = direction;
		return true;
		
	case 0x404:
		data = sense;
		return true;
		
	case 0x408:
		data = edges;
		return true;

	case 0x40c:
		data = evt;
		return true;
		
	case 0x410:
		data = mask;
		return true;
		
	case 0x414:
		data = 0;
		return true;
		
	case 0x418:
		data = 0;
		return true;
		
	case 0x420:
		data = mode;
		return true;
	}
	
	return false;
}

bool PL061::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;
	
	switch (off) {
	case 0x000 ... 0x3fc:
		return true;
		
	case 0x400:
		direction = data;
		return true;
		
	case 0x404:
		sense = data;
		return true;
		
	case 0x408:
		edges = data;
		return true;

	case 0x40c:
		evt = data;
		return true;
		
	case 0x410:
		mask = data;
		return true;
			
	case 0x41c:
		return true;
			
	case 0x420:
		data = mode;
		return true;
	}
	
	return false;
}
