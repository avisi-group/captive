/* SPDX-License-Identifier: MIT */

#include <devices/io/block/block-device.h>
#include <captive.h>

DECLARE_CONTEXT(BlockDevice)

using namespace captive::devices::io::block;

BlockDevice::BlockDevice(uint32_t block_size) : _block_size(block_size)
{
	
}

BlockDevice::~BlockDevice()
{

}
