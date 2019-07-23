/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace devices {
		namespace io {
			namespace block {

				struct BlockDeviceRequest {
					uint64_t block_offset;
					uint32_t block_count;
					uint8_t *buffer;
					bool is_read;
					void *opaque;
				};

				class BlockDevice {
				public:
					typedef void (*block_request_cb_t)(BlockDeviceRequest *rq, bool success);

					BlockDevice(uint32_t block_size = 4096);
					virtual ~BlockDevice();

					virtual bool submit_request(BlockDeviceRequest *rq, block_request_cb_t cb) = 0;

					inline uint32_t block_size() const
					{
						return _block_size;
					}

					virtual uint64_t blocks() const = 0;
					virtual bool read_only() const = 0;

				protected:

					inline uint64_t calculate_byte_offset(uint64_t block_idx) const __attribute__((pure))
					{
						return _block_size * block_idx;
					}

				private:
					uint32_t _block_size;
				};
			}
		}
	}
}
