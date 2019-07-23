/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/virtio/virtio.h>

namespace captive {
	namespace devices {
		namespace io {
			namespace block {
				class BlockDevice;
			}

			namespace virtio {

				class VirtIOBlockDevice : public VirtIO {
				public:
					VirtIOBlockDevice(irq::IRQLineBase& irq, block::BlockDevice& bdev);
					virtual ~VirtIOBlockDevice();

				protected:
					void reset() override;

					const uint8_t* config_area() const override
					{
						return(const uint8_t *) &config;
					}

					uint32_t config_area_size() const override
					{
						return sizeof(config);
					}

					void process_event(VirtIOQueueEvent *evt) override;

				private:
					block::BlockDevice& _bdev;

					void handle_read_event(uint64_t sector, VirtIOQueueEvent *evt);
					void handle_write_event(uint64_t sector, VirtIOQueueEvent *evt);

					//bool handle_read(uint64_t sector, uint8_t *buffer, uint32_t len);
					//bool handle_write(uint64_t sector, uint8_t *buffer, uint32_t len);

					struct virtio_blk_req {
						uint32_t type;
						uint32_t ioprio;
						uint64_t sector;
					} __packed;

					struct {
						uint64_t capacity;
						uint32_t size_max;
						uint32_t seg_max;

						struct {
							uint16_t cylinders;
							uint8_t heads;
							uint8_t sectors;
						} geometry;
						uint32_t block_size;

						struct {
							uint8_t physical_block_exp;
							uint8_t alignment_offset;
							uint16_t min_io_size;
							uint32_t opt_io_size;
						} topology;
						uint8_t reserved;
					} __packed config;
				};
			}
		}
	}
}
