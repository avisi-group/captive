/* SPDX-License-Identifier: MIT */

#include <devices/arm/gic.h>

using namespace captive::devices::arm;
using namespace captive::devices::irq;

GIC::GIC() : _distributor(*this), _next_cpu_id(0)
{
	for (unsigned int i = 0; i < nr_lines; i++) {
		auto line = new GICIRQLine(*this, i);
		
		if (i < 16) {
			line->_config |= 2;
		}
		
		if (i < 32) {
			line->_cpu_mask = 1;
		}
		
		line->attach(*this, i);
		_irq_lines.push_back(line);
	}
}

GIC::~GIC()
{

}

void GIC::dump() const
{
	for (auto& line : _irq_lines) {
		line->dump();
	}
}

GICIRQLine::GICIRQLine(GIC& gic, unsigned int id) : _gic(gic), _id(id), _last_active(nullptr), _enabled(false), _active(false), _pending(false), _priority(0), _cpu_mask(0), _config(0)
{

}

GICIRQLine::~GICIRQLine()
{

}

void GICIRQLine::dump() const
{
	fprintf(stderr, "GIC IRQ LINE %d: ENABLED=%u, ACTIVE=%u, PENDING=%u, PRIO=%u, CONFIG=%u\n", index(), _enabled, _active, _pending, _priority, _config);
}

GICCPUInterface& GIC::create_cpu_interface(IRQLineBase& irq)
{
	auto cpu = new GICCPUInterface(*this, _next_cpu_id, irq);
	_cpus[_next_cpu_id++] = cpu;
	
	return *cpu;
}


void GIC::irq_raised(IRQLineBase& line)
{
	//fprintf(stderr, "irq raised %u\n", line.index());
	std::unique_lock<std::recursive_mutex> l(_lock);
	GICIRQLine& gic_line = (GICIRQLine&)line;

	if (gic_line.edge_triggered()) gic_line._pending = true;
	
	for (auto& cpu : _cpus) {
		cpu.second->update();
	}
}

void GIC::irq_rescinded(IRQLineBase& line)
{
	//fprintf(stderr, "irq rescinded %u\n", line.index());
	std::unique_lock<std::recursive_mutex> l(_lock);
	
	//fprintf(stderr, "RESCINDED %u\n", line.index());
	for (auto& cpu : _cpus) {
		cpu.second->update();
	}
}

std::vector<GICIRQLine*> GIC::lines_for_bitvector(unsigned int base, uint8_t len, uint8_t bits)
{
	unsigned int start_index = (8 * base) / bits;
	unsigned int end_index = (8 * len) / bits + start_index;
	
	if (end_index > 1019) end_index = 1019;
	
	//fprintf(stderr, "LFB: B=%u L=%u BT=%u: start=%u, end=%u\n", base, len, bits, start_index, end_index);
	
	assert(start_index < _irq_lines.size());
	assert(end_index <= _irq_lines.size());
	
	
	std::vector<GICIRQLine *> ret;
	while (start_index < end_index) {
		ret.push_back(_irq_lines[start_index++]);
	}
	
	return ret;
}

GICDistributorInterface::GICDistributorInterface(GIC& gic) : _gic(gic)
{

}

GICDistributorInterface::~GICDistributorInterface()
{

}

bool GICDistributorInterface::read(uint64_t off, uint8_t len, uint64_t& data)
{
	std::unique_lock<std::recursive_mutex> l(_gic._lock);
	//fprintf(stderr, "gicd: read: %lx\n", off);
	
	switch (off) {
	case 0x000:		// GICD_CTLR
		data = _enabled ? 1 : 0;
		return true;
		
	case 0x004:		// GICD_TYPER
		data = 0x0000081f;
		return true;
		
	case 0x008:		// GICD_IIDR
		data = 0x0200143b;
		return true;
		
	case 0x080 ... 0x0ff:	// GICD_IGROUP
		return false;
		
	case 0x100 ... 0x17c:
	case 0x300 ... 0x37c:
		data = 0;
		return true;
		
	case 0x800 ... 0xbfb:	// GICD_ITARGETS
		{
			auto lines = _gic.lines_for_bitvector(off - 0x800, len, 8);
			
			uint64_t ret = 0, idx = 0;
			for (const auto& line : lines) {
				ret |= line->_cpu_mask << idx;
				idx += 8;
			}
			
			data = ret;
		}
		return true;
		
	case 0xc00 ... 0xdff:	// GICD_ICFG
		{
			auto lines = _gic.lines_for_bitvector(off - 0xc00, len, 2);
			
			uint64_t ret = 0, idx = 0;
			for (const auto& line : lines) {
				ret |= line->_config << idx;
				idx += 2;
			}
			
			data = ret;
		}
		return true;
		
	case 0xfe0: data = 0x90; return true;
	case 0xfe4: data = 0xb4; return true;
	case 0xfe8: data = 0x2b; return true;
	case 0xfec: data = 0x00; return true;
	case 0xff0: data = 0x0d; return true;
	case 0xff4: data = 0xf0; return true;
	case 0xff8: data = 0x05; return true;
	case 0xffc: data = 0xb1; return true;
	}
	
	return false;
}

bool GICDistributorInterface::write(uint64_t off, uint8_t len, uint64_t data)
{
	std::unique_lock<std::recursive_mutex> l(_gic._lock);
	//fprintf(stderr, "gicd: write: %lx %lx\n", off, data);
	
	switch (off) {
	case 0x000:		// GICD_CTLR
		_enabled = !!(data & 1);
		return true;

	case 0x100 ... 0x17f:	// GICD_ISENABLE
		{
			auto lines = _gic.lines_for_bitvector(off - 0x100, len, 1);
			
			for (const auto& line : lines) {
				line->_enabled |= !!(data & 1);
				data >>= 1;
			}
		}
		return true;
		
	case 0x180 ... 0x1ff:	// GICD_ICENABLE
		{
			auto lines = _gic.lines_for_bitvector(off - 0x180, len, 1);
			
			for (const auto& line : lines) {
				line->_enabled = line->_enabled && !(data & 1);
				data >>= 1;
			}
		}
		return true;
		
	case 0x380 ... 0x3ff:	// GICD_ICACTIVE
		{
			auto lines = _gic.lines_for_bitvector(off - 0x380, len, 1);
			
			for (const auto& line : lines) {
				line->_active = line->_active && !(data & 1);
				data >>= 1;
			}
		}
		return true;
		
	case 0x400 ... 0x7fb:	// GICD_IPRIORITY
		{
			auto lines = _gic.lines_for_bitvector(off - 0x400, len, 8);
			
			for (const auto& line : lines) {
				line->_priority = data & 0xff;
				data >>= 8;
			}
		}
		return true;
		
	case 0x800 ... 0xbfb:	// GICD_ITARGETS
		{
			auto lines = _gic.lines_for_bitvector(off - 0x800, len, 8);
			
			for (const auto& line : lines) {
				line->_cpu_mask = data & 0xff;
				data >>= 8;
			}
		}
		return true;
		
	case 0xc00 ... 0xdff:	// GICD_ICFG
		{
			auto lines = _gic.lines_for_bitvector(off - 0xc00, len, 2);
			
			for (const auto& line : lines) {
				line->_config = data & 0x03;
				data >>= 2;
			}
		}
		return true;
		
	case 0xf00:				// GICD_SGIR
		fprintf(stderr, "SGIR %lx\n", data);
		data = (uint8_t)data;
		if (data >= 0 && data < 16) {
			GICIRQLine& gic_line = *_gic._irq_lines[data];
			gic_line.raise();
		}
		return true;
		
	case 0xf10 ... 0xf1f:	// GICD_CPENDSGIR
		{
			auto lines = _gic.lines_for_bitvector(off - 0xf10, len, 1);
			
			for (const auto& line : lines) {
				line->_pending = line->_pending && !(data & 1);
				line->rescind();
				data >>= 1;
			}
		}
		return true;
		
	case 0xf20 ... 0xf2f:	// GICD_SPENDSGIR
		{
			auto lines = _gic.lines_for_bitvector(off - 0xf20, len, 1);
			
			for (const auto& line : lines) {
				line->_pending |= !!(data & 1);
				data >>= 1;
			}
		}
		return true;
	}
	
	fprintf(stderr, "gic-distributor: write %lx %u %lx\n", off, len, data);	
	return false;
}

GICCPUInterface::GICCPUInterface(GIC& gic, uint8_t id, IRQLineBase& irq) : _gic(gic), _id(id), _irq(irq), _enabled(false), _pmr(0), _current_pending(nullptr), _current_running(nullptr)
{

}

GICCPUInterface::~GICCPUInterface()
{

}

bool GICCPUInterface::read(uint64_t off, uint8_t len, uint64_t& data)
{
	std::unique_lock<std::recursive_mutex> l(_gic._lock);
	
	//fprintf(stderr, "gicc: read: %lx\n", off);
	
	switch (off) {
	case 0x000:		// GICC_CTLR
		data = _enabled ? 1 : 0;
		return true;
		
	case 0x000c:	// GICC_IAR
		data = acknowledge();
		return true;
		
	case 0x00fc:
		data = 0;
		return true;
	}
	
	fprintf(stderr, "gic-cpu: read %lx %u\n", off, len);
	return false;
}

bool GICCPUInterface::write(uint64_t off, uint8_t len, uint64_t data)
{
	std::unique_lock<std::recursive_mutex> l(_gic._lock);
	//fprintf(stderr, "gicc: write: %lx %lx\n", off, data);
	
	switch (off) {
	case 0x000:		// GICC_CTLR
		_enabled = !!(data & 1);
		return true;
		
	case 0x004:		// GICC_PMR
		_pmr = data & 0xff;
		return true;
		
	case 0x010:		// GICC_EOIR
		eoi(data);
		return true;
	}
	
	fprintf(stderr, "gic-cpu: write %lx %u %lx\n", off, len, data);	
	return false;
}

uint64_t GICCPUInterface::acknowledge()
{
	_irq.acknowledge();

	GICIRQLine *irq = _current_pending;
	if (irq == nullptr || irq->_priority >= running_priority()) {
		if (irq == nullptr) _current_running = nullptr;
		//fprintf(stderr, "***** ACKNOWLEDGE 1023\n");
		return 1023;
	}

	irq->_last_active = _current_running;

	irq->_pending = false;
	_current_running = irq;

	update();
	//fprintf(stderr, "***** ACKNOWLEDGE %u\n", irq->index());
	return irq->index();
}

void GICCPUInterface::eoi(uint64_t irqid)
{
	//fprintf(stderr, "***** EOI %u\n", irqid);
	
	if (irqid >= _gic._irq_lines.size()) {
		return;
	}
	
	if (_current_running == nullptr) {
		return;
	}
	
	GICIRQLine *irq = &_gic.get_irq_line(irqid);
	if (irq != _current_running) {
		GICIRQLine *last = _current_running;
		while (last) {
			if (last == irq) {
				last->_last_active = irq->_last_active;
				break;
			}
			
			last = last->_last_active;
		}
	} else {
		_current_running = _current_running->_last_active;
	}
	
	//fprintf(stderr, "  cr=%p\n", _current_running);
	
	update();
}

void GICCPUInterface::update()
{
	//fprintf(stderr, "***** UPDATE\n");

	_current_pending = nullptr;
	if (!_enabled || !_gic._distributor._enabled) {
		//fprintf(stderr, "rescind\n");
		_irq.rescind();
		return;
	}
	
	GICIRQLine *best_irq = nullptr;	
	for (const auto line : _gic._irq_lines) {
		if (line->_enabled && (line->_pending || (line->level_triggered() && line->raised()))) {
			if (!best_irq || line->_priority < best_irq->_priority) {
				best_irq = line;
			}
		}
	}

	bool raise = false;
	if (best_irq) {
		
		if (best_irq->_priority < _pmr) {
			_current_pending = best_irq;
			
			if (best_irq->_priority < running_priority()) {
				//fprintf(stderr, "***** yoyoyo %p %u\n", best_irq, best_irq->index());
				raise = true;
			}
		}
	}
	
	if (raise) {
		//fprintf(stderr, "raise\n");
		_irq.raise();
	} else {
		//fprintf(stderr, "rescind\n");
		_irq.rescind();
	}
}

uint32_t GICCPUInterface::running_priority() const
{
	return _current_running == nullptr ? 0x100 : _current_running->_priority;
}
