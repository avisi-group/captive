/* SPDX-License-Identifier: MIT */

#include <devices/net/priv/priv-interface.h>

using namespace captive::devices::net;
using namespace captive::devices::net::priv;

PrivateInterface::PrivateInterface() {

}

PrivateInterface::~PrivateInterface() {

}

bool PrivateInterface::open(std::string socket)
{
	return true;
}


bool PrivateInterface::transmit_packet(const uint8_t* buffer, uint32_t length)
{
	fprintf(stderr, "************ TRANSMIT PACKET\n");
	
	for (unsigned int i = 0; i < length; i++) {
		fprintf(stderr, "%02x ", buffer[i]);
	}
	
	fprintf(stderr, "\n");
	
	return false;
}
