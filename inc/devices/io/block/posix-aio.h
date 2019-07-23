/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/block/aio.h>

#include <thread>
#include <aio.h>
#include <signal.h>

namespace captive {
	namespace devices {
		namespace io {
			namespace block {

				class POSIXAIO : public AIO {
				public:
					POSIXAIO(int fd, BlockDevice& bdev);
					~POSIXAIO();

					bool init() override;
					bool submit(BlockDeviceRequest *rq, BlockDevice::block_request_cb_t callback) override;

				private:
					static void posix_aio_notify(sigval_t sv);

					struct BlockDeviceRequestContext {

						BlockDeviceRequestContext(BlockDeviceRequest *rq, BlockDevice::block_request_cb_t cb) : rq(rq), cb(cb)
						{
						}

						BlockDeviceRequest *rq;
						BlockDevice::block_request_cb_t cb;

						struct aiocb aio_cb;
					};
				};
			}
		}
	}
}
