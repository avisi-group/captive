/* SPDX-License-Identifier: MIT */

#include <devices/arm/pl190.h>
#include <captive.h>

using namespace captive::devices::arm;

PL190::PL190(irq::IRQLineBase& irq, irq::IRQLineBase& fiq) : Primecell(0x00041190), irq(irq), fiq(fiq)
{
	for(int i = 0; i < 16; ++i) {
		vector_addrs[i] = 0;
		vector_ctrls[i] = 0;
	}

	default_vector_address = 0;
	prio_mask[17] = 0xffffffff;
	priority = 17;

	mask = 0;
	soft_status = 0;
	irq_status = 0;
	fiq_select = 0;

	update_vectors();
}

PL190::~PL190()
{

}

bool PL190::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (Primecell::read(off, len, data))
		return true;

	switch (off) {
	case 0x00:
		data = get_irq_status();
		break;
	case 0x04:
		data = get_fiq_status();
		break;
	case 0x08:
		data = irq_status | soft_status;
		break;
	case 0x0c:
		data = fiq_select;
		break;
	case 0x10:
		data = mask;
		break;
	case 0x18:
		data = soft_status;
		break;
	case 0x24:
		data = 0;
		break;
	case 0x30:
		data = read_var();
		break;
	case 0x34:
		data = default_vector_address;
		break;

	case 0x100 ... 0x1ff:
	{
		uint8_t vector = (off - 0x200) / 4;
		if (vector <= 16) {
			vector_addrs[vector] = data;
			update_vectors();
		}

		break;
	}

	case 0x200 ... 0xfdf:
	{
		uint8_t vector = (off - 0x200) / 4;
		if (vector <= 16) {
			vector_ctrls[vector] = data;
			update_vectors();
		}

		break;
	}

	default:
		return false;
	}

	return true;
}

bool PL190::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (Primecell::write(off, len, data))
		return true;

	switch (off) {
	case 0x00:
	case 0x04:
	case 0x08:
		update_lines();
		break;

	case 0x0c:
		fiq_select = data;
		update_lines();
		break;

	case 0x10:
		mask |= data;
		update_lines();
		break;

	case 0x14:
		mask &= ~data;
		update_lines();
		break;

	case 0x18:
		soft_status |= data;
		update_lines();
		break;

	case 0x1c:
		soft_status &= ~data;
		update_lines();
		break;

	case 0x20:
		return false;

	case 0x30:
		write_var();
		break;

	case 0x34:
		default_vector_address = data;
		break;

	case 0x100 ... 0x1ff:
	{
		uint8_t vector = (off - 0x200) / 4;
		if (vector <= 16) {
			vector_addrs[vector] = data;
			update_vectors();
		}
		break;
	}

	case 0x200 ... 0xfdf:
		break;

	default:
		return false;
	}

	return true;
}

void PL190::irq_raised(irq::IRQLineBase& line)
{
	//DEBUG << CONTEXT(PL190) << "IRQ Raised: " << line.index();

	irq_status |= 1 << line.index();
	update_lines();
}

void PL190::irq_rescinded(irq::IRQLineBase& line)
{
	//DEBUG << CONTEXT(PL190) << "IRQ Rescinded: " << line.index();

	irq_status &= ~(1 << line.index());
	update_lines();
}

void PL190::update_vectors()
{
	uint32_t n, mask = 0;

	for (int i = 0; i < 16; i++) {
		prio_mask[i] = mask;
		if (vector_ctrls[i] & 0x20) {
			n = vector_ctrls[i] & 0x1f;
			mask |= 1 << n;
		}
	}

	prio_mask[16] = mask;
	update_lines();
}

void PL190::update_lines()
{
	if (get_irq_status() & prio_mask[priority]) {
		irq.raise();
	} else {
		irq.rescind();
	}

	if (get_fiq_status() & prio_mask[priority]) {
		fiq.raise();
	} else {
		fiq.rescind();
	}
}

uint32_t PL190::read_var()
{
	uint32_t i = 0;

	for (i = 0; i < priority; ++i) {
		if ((irq_status | soft_status) & prio_mask[i + 1]) {
			break;
		}
	}

	if (i == 17) {
		return default_vector_address;
	}

	if (i < priority) {
		prev_priority[i] = priority;
		priority = i;
		update_lines();
	}

	return vector_addrs[priority];
}

void PL190::write_var()
{
	if (priority < 17)
		priority = prev_priority[priority];
	update_lines();
}
