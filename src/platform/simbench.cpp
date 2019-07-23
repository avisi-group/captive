/* SPDX-License-Identifier: MIT */

#include <platform/simbench.h>
#include <util/config/config.h>

#include <devices/arm/cpu-irq.h>
#include <devices/arm/gic.h>

#include <devices/arm/pl011.h>

#include <devices/io/console-uart.h>

using namespace captive;
using namespace captive::hypervisor;
using namespace captive::platform;
using namespace captive::devices;
using namespace captive::devices::arm;

#define KB(_v) ((_v) * 1024ULL)
#define MB(_v) (KB(_v) * 1024ULL)
#define GB(_v) (MB(_v) * 1024ULL)

Simbench::Simbench(const util::config::Configuration& hcfg, devices::timers::TimerManager& timer_manager) : Platform(hcfg, timer_manager), cfg()
{
	cfg.memory_regions.clear();
	
	cfg.memory_regions.push_back(GuestMemoryRegionConfiguration(0x40000000, MB(512)));
	cfg.memory_regions.push_back(GuestMemoryRegionConfiguration(0x80000000, GB(1)));	
	
	ArmCpuIRQController *core0irq = new ArmCpuIRQController();
	GuestCPUConfiguration core0(*core0irq);
	cfg.cores.push_back(core0);
	
	auto gic0 = new GIC();
	auto& gic0core0 = gic0->create_cpu_interface(*core0irq->get_irq_line(1));

	cfg.devices.push_back(GuestDeviceConfiguration(0x08010000, gic0core0));
	cfg.devices.push_back(GuestDeviceConfiguration(0x08000000, gic0->get_distributor()));
	
	auto console = new devices::io::ConsoleUART();
	//console->open();
	
	auto uart0 = new devices::arm::PL011(gic0->get_irq_line(115), *console);
	cfg.devices.push_back(GuestDeviceConfiguration(0x09000000, *uart0));
}

Simbench::~Simbench() {

}

bool Simbench::start()
{
	return true;
}

bool Simbench::stop()
{
	return true;
}

void Simbench::dump() const
{

}
