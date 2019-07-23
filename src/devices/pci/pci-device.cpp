/* SPDX-License-Identifier: MIT */

#include <devices/pci/pci-device.h>

using namespace captive::devices::pci;

PCIDevice::PCIDevice(uint32_t class_code) : _class_code(class_code)
{

}

bool PCIDevice::read(uint64_t off, uint8_t len, uint64_t& data)
{
	switch (off) {
	case 0x9:	// CLASSC
		data = _class_code & 0xffffff;
		return true;
	}
	
	data = 0;
	return false;
}

bool PCIDevice::write(uint64_t off, uint8_t len, uint64_t data)
{
	return false;
}
