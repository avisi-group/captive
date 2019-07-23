/* SPDX-License-Identifier: MIT */

#include <devices/arm/versatile-sic.h>
#include <captive.h>

using namespace captive::devices::arm;

VersatileSIC::VersatileSIC(irq::IRQLineBase& irq) : _irq(irq)
{
}

VersatileSIC::~VersatileSIC()
{

}

bool VersatileSIC::read(uint64_t off, uint8_t len, uint64_t& data)
{
	switch (off) {
	case 0x00:
		data = status & enable_mask;
		break;

	case 0x04:
		data = status;
		break;

	case 0x08:
		data = enable_mask;
		break;
	}

	return true;
}

bool VersatileSIC::write(uint64_t off, uint8_t len, uint64_t data)
{
	switch (off) {
	case 0x08:
		enable_mask |= data;
		break;

	case 0x0c:
		enable_mask &= ~data;
		break;
	}

	return true;
}

void VersatileSIC::irq_raised(irq::IRQLineBase& line)
{
	// DEBUG << CONTEXT(VersatileSIC) << "IRQ Raised: " << line.index();

	status |= 1 << line.index();
	_irq.raise();
}

void VersatileSIC::irq_rescinded(irq::IRQLineBase& line)
{
	// DEBUG << CONTEXT(VersatileSIC) << "IRQ Rescinded: " << line.index();

	status &= ~(1 << line.index());
	if (status == 0) {
		_irq.rescind();
	}
}
