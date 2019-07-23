/* SPDX-License-Identifier: MIT */

#include <platform/virt.h>
#include <util/config/config.h>

#include <devices/arm/cpu-irq.h>
#include <devices/arm/gic.h>
#include <devices/arm/mhu.h>
#include <devices/arm/generic-timer.h>

#include <devices/arm/pl011.h>
#include <devices/arm/pl031.h>
#include <devices/arm/pl050.h>
#include <devices/arm/pl061.h>
#include <devices/arm/pl180.h>
#include <devices/arm/pl330.h>
#include <devices/arm/pl354.h>

#include <devices/arm/sp810.h>
#include <devices/arm/sp804.h>
#include <devices/arm/sp805.h>

#include <devices/io/console-uart.h>
#include <devices/io/block/file-backed-block-device.h>
#include <devices/io/virtio/virtio-block-device.h>
#include <devices/io/virtio/virtio-net-device.h>
#include <devices/net/tap/tap-interface.h>
#include <devices/net/user/user-interface.h>

#include <captive.h>

using namespace captive;
using namespace captive::hypervisor;
using namespace captive::platform;
using namespace captive::devices;
using namespace captive::devices::io;
using namespace captive::devices::io::block;
using namespace captive::devices::io::virtio;
using namespace captive::devices::arm;
using namespace captive::devices::net;
using namespace captive::devices::net::tap;

#define KB(_v) ((_v) * 1024ULL)
#define MB(_v) (KB(_v) * 1024ULL)
#define GB(_v) (MB(_v) * 1024ULL)

Virtual::Virtual(const util::config::Configuration& hcfg, devices::timers::TimerManager& timer_manager)
: Platform(hcfg, timer_manager), cfg(), uart0(nullptr), net_iface(nullptr)
{
	cfg.memory_regions.clear();

	cfg.memory_regions.push_back(GuestMemoryRegionConfiguration(0, MB(128)));
	cfg.memory_regions.push_back(GuestMemoryRegionConfiguration(0x40000000, GB(12)));


	ArmCpuIRQController *core0irq = new ArmCpuIRQController();
	GuestCPUConfiguration core0(*core0irq);
	cfg.cores.push_back(core0);

	auto gic0 = new GIC();
	auto& gic0core0 = gic0->create_cpu_interface(*core0irq->get_irq_line(1));

	cfg.devices.push_back(GuestDeviceConfiguration(0x08110000, gic0core0));
	cfg.devices.push_back(GuestDeviceConfiguration(0x08100000, gic0->get_distributor()));

	GenericTimer *gt0 = new GenericTimer(timer_manager, gic0->get_irq_line(27));
	cfg.devices.push_back(GuestDeviceConfiguration(0x08030000, gt0->control_region()));

	/*SP804 *timer01 = new SP804(timer_manager, gic0->get_irq_line(68));
	cfg.devices.push_back(GuestDeviceConfiguration(0x08, *timer01));
	cfg.devices.push_back(GuestDeviceConfiguration(0x300051000, *timer01));

	SP804 *timer23 = new SP804(timer_manager, gic0->get_irq_line(69));
	cfg.devices.push_back(GuestDeviceConfiguration(0x300060000, *timer23));
	cfg.devices.push_back(GuestDeviceConfiguration(0x300061000, *timer23));*/

	PL031 *pl031 = new PL031(timer_manager, gic0->get_irq_line(68));
	cfg.devices.push_back(GuestDeviceConfiguration(0x08040000, *pl031));

	auto console = new devices::io::ConsoleUART();
	console->open();

	uart0 = new devices::arm::PL011(gic0->get_irq_line(66), *console);
	cfg.devices.push_back(GuestDeviceConfiguration(0x08020000, *uart0));

	if (!hcfg.block_device_file) {
		ERROR << "You must specify a block device file";
		throw 0;
	}

	FileBackedBlockDevice *bdev = new FileBackedBlockDevice();

	if (!bdev->open_file(hcfg.block_device_file.value())) {
		ERROR << "Unable to open block device file '" << hcfg.block_device_file.value() << "'";
		throw 0;
	}

	VirtIOBlockDevice *vbd = new VirtIOBlockDevice(gic0->get_irq_line(64), *bdev);
	cfg.devices.push_back(GuestDeviceConfiguration(0x08000000, *vbd));

	if (hcfg.net_tap_device) {
		if (!hcfg.net_mac_addr) {
			ERROR << "You must specify a MAC address";
			throw 0;
		}

		net_iface = new TapInterface(hcfg.net_tap_device.value());
	} else {
		net_iface = new user::UserInterface();
	}

	if (!net_iface->start()) {
		ERROR << "Unable to start TAP interface";
		throw 0;
	}

	VirtIONetworkDevice *vnd = new VirtIONetworkDevice(gic0->get_irq_line(65), *net_iface, strtoul(hcfg.net_mac_addr.value().c_str(), NULL, 16));
	cfg.devices.push_back(GuestDeviceConfiguration(0x08010000, *vnd));
}

Virtual::~Virtual()
{

}

bool Virtual::start()
{
	uart0->start_reading();
	return true;
}

bool Virtual::stop()
{
	uart0->stop_reading();

	if (net_iface) {
		net_iface->stop();
	}

	return true;
}

void Virtual::dump() const
{

}
