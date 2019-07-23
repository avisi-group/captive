/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/block/aio.h>

namespace captive {
	namespace devices {
		namespace io {
			namespace block {

				class SyncAIO : public AIO {
				public:
					SyncAIO(int fd, BlockDevice& bdev);
					~SyncAIO();

					bool init() override;
					bool submit(BlockDeviceRequest *rq, BlockDevice::block_request_cb_t callback) override;
				};
			}
		}
	}
}
