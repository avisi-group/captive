/* SPDX-License-Identifier: MIT */

#include <devices/arm/hdlcd.h>

using namespace captive::devices;
using namespace captive::devices::arm;

HDLCD::HDLCD(gfx::VirtualScreen& screen, irq::IRQLineBase& irq) : _screen(screen), _irq(irq)
{
	
}

HDLCD::~HDLCD()
{

}

bool HDLCD::read(uint64_t off, uint8_t len, uint64_t& data)
{
	fprintf(stderr, "hdlcd: read %lu\n", off);
	data = 0;
	return true;
}

bool HDLCD::write(uint64_t off, uint8_t len, uint64_t data)
{
	fprintf(stderr, "hdlcd: write %lu %lx\n", off, data);
	return true;
}
