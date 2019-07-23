/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/block/aio.h>

#include <thread>
#include <linux/aio_abi.h>

namespace captive {
	namespace devices {
		namespace io {
			namespace block {

				class LinuxAIO : public AIO {
				public:
					LinuxAIO(int fd, BlockDevice& bdev);
					~LinuxAIO();

					bool init() override;
					bool submit(BlockDeviceRequest *rq, BlockDevice::block_request_cb_t callback) override;

				private:
					aio_context_t _aio;
					std::thread *_aio_thread;
					bool _terminate;

					static void aio_thread_proc(LinuxAIO *aio);

					struct BlockDeviceRequestContext {

						BlockDeviceRequestContext(BlockDeviceRequest *rq, BlockDevice::block_request_cb_t cb) : rq(rq), cb(cb)
						{
						}

						BlockDeviceRequest *rq;
						BlockDevice::block_request_cb_t cb;
					};
				};
			}
		}
	}
}
