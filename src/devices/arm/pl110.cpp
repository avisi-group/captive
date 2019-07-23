/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl110.h>
#include <devices/gfx/virtual-screen.h>
#include <devices/irq/irq-line.h>
#include <hypervisor/guest.h>
#include <captive.h>

USE_CONTEXT(Primecell);
DECLARE_CHILD_CONTEXT(PL110, Primecell);

using namespace captive::devices::arm;

PL110::PL110(gfx::VirtualScreen& screen, irq::IRQLineBase& irq, DeviceVariant v)
	: Primecell(v == V_PL110 ? 0x00041110 : 0x00041111, 0x10000), _screen(screen), _irq(irq), lcd_timing { 0, 0, 0, 0 }, upper_fbbase(0), lower_fbbase(0), isr(0), irq_mask(0)
{
	control.data = 0;
	
	screen.palette((uint8_t *)&palette[0]);
}

PL110::~PL110()
{

}

bool PL110::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;

	switch (off) {
	case 0x00:
		data = lcd_timing[0];
		break;
	case 0x04:
		data = lcd_timing[1];
		break;
	case 0x08:
		data = lcd_timing[2];
		break;
	case 0x0c:
		data = lcd_timing[3];
		break;

	case 0x10:
	case 0x2c:
		data = upper_fbbase;
		break;
	case 0x14:
	case 0x30:
		data = lower_fbbase;
		break;

	case 0x18:
		data = control.data;
		break;

	case 0x1c:
		data = irq_mask;
		break;

	case 0x20:
		data = isr;
		break;

	case 0x24:
		data = isr & irq_mask;
		break;

	case 0x200 ... 0x3fc:
		data = palette[(off - 0x200) >> 2];
		break;
		
	default:
		return false;
	}

	return true;
}

bool PL110::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;

	switch (off) {
	case 0x00:
		lcd_timing[0] = data;
		break;
	case 0x04:
		lcd_timing[1] = data;
		break;
	case 0x08:
		lcd_timing[2] = data;
		break;
	case 0x0c:
		lcd_timing[3] = data;
		break;

	case 0x10:
		upper_fbbase = data;

		DEBUG << CONTEXT(PL110) << "Setting framebuffer to GPA=" << std::hex << data;
		void *gpa;
		if (guest().resolve_gpa((gpa_t)upper_fbbase, gpa)) {
			DEBUG << CONTEXT(PL110) << "Framebuffer resolved to " << std::hex << gpa;
			_screen.framebuffer((uint8_t *)gpa);
		}

		break;

	case 0x14:
		lower_fbbase = data;
		break;

	case 0x18:
		control.data = data;
		update_control();
		break;

	case 0x1c:
		irq_mask = data;
		update_irq();
		break;

	case 0x28:
		isr &= ~data;
		update_irq();
		break;

	case 0x200 ... 0x3fc:
		palette[(off - 0x200) >> 2] = data;
		break;

	default:
		return false;
	}

	return true;
}

void PL110::update_control()
{
	DEBUG << CONTEXT(PL110) << "Update Control " << std::hex << control.data;

	if (control.fields.en && !_screen.configured()) {
		uint32_t ppl = 16 * (1 + ((lcd_timing[0] >> 2) & 0x3f));
		uint32_t lines = (lcd_timing[1] & 0x3ff) + 1;

		gfx::VirtualScreenConfiguration::VirtualScreenMode mode;

		switch(control.fields.bpp) {
		case 3:
			mode = gfx::VirtualScreenConfiguration::VS_8bpp;
			break;

		case 4:
			mode = gfx::VirtualScreenConfiguration::VS_16bpp;
			break;

		case 6:
			mode = gfx::VirtualScreenConfiguration::VS_16bpp;
			break;

		default:
			mode = gfx::VirtualScreenConfiguration::VS_None;
			break;
		}

		_screen.configure(gfx::VirtualScreenConfiguration(ppl, lines, mode));
		_screen.initialise();
	} else if (_screen.configured()) {
		_screen.reset();
	}
}

void PL110::update_irq()
{
	if (isr & irq_mask) {
		_irq.raise();
	} else {
		_irq.rescind();
	}
}
