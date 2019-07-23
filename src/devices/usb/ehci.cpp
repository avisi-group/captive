/* SPDX-License-Identifier: MIT */

#include <devices/usb/ehci.h>

using namespace captive::devices::pci;
using namespace captive::devices::usb;

EHCI::EHCI() : PCIDevice(0x0c0320)
{

}

bool EHCI::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (PCIDevice::read(off, len, data)) return true;
		
	switch (off) {
	case 0x0:	// CAPLENGTH
		data = 0x18;
		return true;
		
	case 0x04:	// HCSPARAMS
	{
		struct cap_params {
			unsigned int reserved0:8;
			unsigned int debug_port_number:4;
			unsigned int reserved1:3;
			unsigned int port_indicators:1;
			unsigned int n_cc:4;
			unsigned int n_pcc:4;
			unsigned int port_routing:1;
			unsigned int reserved2:2;
			unsigned int ppc:1;
			unsigned int n_ports:4;
		} params;
		
		params.reserved0 = 0;
		params.reserved1 = 0;
		params.reserved2 = 0;
		params.debug_port_number = 0;
		params.port_indicators = 0;
		params.n_cc = 0;
		params.n_pcc = 0;
		params.port_routing = 0;
		params.ppc = 0;
		params.n_ports = 1;
		
		data = *(uint64_t *)&params;
		return true;
	}
	
	case 0x08:	// HCCPARAMS
	{
		struct cap_params {
			unsigned int reserved0:16;
			unsigned int eecp:8;
			unsigned int ist:4;
			unsigned int reserved1:1;
			unsigned int aspc:1;
			unsigned int pflf:1;
			unsigned int addr64:1;
		} params;
		
		params.reserved0 = 0;
		params.reserved1 = 0;
		params.eecp = 0;
		params.ist = 0;
		params.aspc = 0;
		params.pflf = 0;
		params.addr64 = 1;
		
		data = *(uint64_t *)&params;
		return true;
	}
	
	case 0x18 ... 0x5f:
		switch  (off - 0x18) {
		case 0x0:
			data = 0;
			return true;
		case 0x4:	// USBSTS
			data = 1 << 4;
			return true;
		}
		
		printf("ehci: unimplemented op read: off=%lx, len=%u\n", off - 0x18, len);
		return false;
	}
	
	printf("ehci: unimplemented read: off=%lx, len=%u\n", off, len);
	return false;
}

bool EHCI::write(uint64_t off, uint8_t len, uint64_t data)
{
	if (PCIDevice::write(off, len, data)) return true;
	
	printf("ehci: unimplemented write: off=%x, len=%u, data=%lx\n", off, len, data);
	return true;
}
