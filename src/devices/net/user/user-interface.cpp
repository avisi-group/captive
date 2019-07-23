/* SPDX-License-Identifier: MIT */

#include <devices/net/user/user-interface.h>

using namespace captive::devices::net;
using namespace captive::devices::net::user;

UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{

}

bool UserInterface::start()
{
	return true;
}

void UserInterface::stop()
{

}

bool UserInterface::transmit_packet(const uint8_t* buffer, uint32_t length)
{
	/*fprintf(stderr, "************ TRANSMIT PACKET\n");
	
	for (int i = 0; i < length; i++) {
		fprintf(stderr, "%02x ", buffer[i]);
	}
	
	fprintf(stderr, "\n");*/

	return true;
}
