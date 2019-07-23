/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/block/block-device.h>

namespace captive {
	namespace devices {
		namespace io {
			namespace block {

				class AIO {
				public:

					AIO(int fd, BlockDevice& bdev) : _fd(fd), _bdev(bdev), _block_size(bdev.block_size())
					{
					}

					virtual ~AIO()
					{
					}

					virtual bool init() = 0;
					virtual bool submit(BlockDeviceRequest *rq, BlockDevice::block_request_cb_t callback) = 0;

				protected:

					inline int fd() const
					{
						return _fd;
					}

					inline const BlockDevice& block_device() const
					{
						return _bdev;
					}

					inline uint32_t block_size() const
					{
						return _block_size;
					}

				private:
					int _fd;
					BlockDevice& _bdev;
					uint32_t _block_size;
				};
			}
		}
	}
}
