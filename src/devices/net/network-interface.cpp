/* SPDX-License-Identifier: MIT */

#include <devices/net/network-interface.h>
#include <devices/net/network-device.h>
#include <captive.h>

DECLARE_CONTEXT(Network);

using namespace captive::devices::net;

void NetworkInterface::invoke_receive(const uint8_t *buffer, uint32_t length)
{
	if (_receive_callback) {
		_receive_callback->receive_packet(buffer, length);
	}
}
