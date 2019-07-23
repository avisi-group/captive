/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl050.h>
#include <devices/io/ps2.h>
#include <captive.h>

#define PL050_TXEMPTY         (1 << 6)
#define PL050_TXBUSY          (1 << 5)
#define PL050_RXFULL          (1 << 4)
#define PL050_RXBUSY          (1 << 3)
#define PL050_RXPARITY        (1 << 2)
#define PL050_KMIC            (1 << 1)
#define PL050_KMID            (1 << 0)

#define FKMIC			(1 << 0)
#define FKMID			(1 << 1)
#define KMIEN			(1 << 2)
#define KMITXINTREN		(1 << 3)
#define KMIRXINTREN		(1 << 4)
#define KMITYPE			(1 << 5)

#define KMICR		0x00
#define KMISTAT		0x04
#define KMIDATA		0x08
#define KMICLKDIV	0x0c
#define KMIIR		0x10

using namespace captive::devices::arm;

PL050::PL050(io::PS2Device& ps2) : Primecell(0x00041050), _ps2(ps2), cr(0), clkdiv(0), last(0)
{

}

PL050::~PL050()
{

}

bool PL050::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;

	switch (off) {
	case KMICR:
		data = cr;
		break;

	case KMISTAT:
	{
		uint8_t val;
		uint32_t stat;

		val = last;
		val = val ^ (val >> 4);
		val = val ^ (val >> 2);
		val = (val ^ (val >> 1)) & 1;

		stat = PL050_TXEMPTY;
		if (val) {
			stat |= PL050_RXPARITY;
		}

		if (_ps2.data_pending()) {
			stat |= PL050_RXFULL;
		}

		data = stat;
		break;
	}

	case KMIDATA:
		if (_ps2.data_pending()) {
			last = _ps2.read();
		}

		data = last;
		break;

	case KMICLKDIV:
		data = clkdiv;
		break;

	case KMIIR:
		data = (_ps2.data_pending() ? 1 : 0) | 2;
		break;

	default:
		return false;
	}

	return true;
}

bool PL050::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;

	switch (off) {
	case KMICR:
		assert(!(data & KMITXINTREN));

		if ((data & KMIRXINTREN) == KMIRXINTREN) {
			_ps2.enable_irq();
		} else {
			_ps2.disable_irq();
		}

		cr = data;
		break;

	case KMIDATA:
		_ps2.send_command(data & 0xff);
		break;

	case KMICLKDIV:
		clkdiv = data;
		break;

	default:
		return false;
	}

	return true;

}
