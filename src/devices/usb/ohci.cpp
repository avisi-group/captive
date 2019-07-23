/* SPDX-License-Identifier: MIT */

#include <devices/usb/ohci.h>

using namespace captive::devices::pci;
using namespace captive::devices::usb;

OHCI::OHCI() : PCIDevice(0x0c0320)
{

}

bool OHCI::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (PCIDevice::read(off, len, data)) return true;

	data = 0;
	
	printf("ohci: unimplemented read: off=%u, len=%u\n", off, len);
	return true;
}

bool OHCI::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (PCIDevice::write(off, len, data)) return true;
	
	printf("ohci: unimplemented write: off=%u, len=%u, data=%lx\n", off, len, data);
	return true;
}
