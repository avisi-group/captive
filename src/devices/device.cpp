/* SPDX-License-Identifier: MIT */

#include <devices/device.h>

using namespace captive::devices;

Device::Device()
{

}

Device::~Device()
{

}

const std::vector<RegisterDescriptor> Device::registers() const
{
	return std::vector<RegisterDescriptor>(0);
}
