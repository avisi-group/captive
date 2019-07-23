/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>
#include <vector>
#include <atomic>
#include <mutex>
#include <util/completion.h>

//#define SYNCHRONOUS

namespace captive {
	namespace devices {
		namespace irq {
			class IRQLineBase;
		}

		namespace io {
			namespace virtio {

				struct VirtIOQueueEventBuffer {
				public:

					VirtIOQueueEventBuffer(void *data, uint32_t size) : data(data), size(size)
					{
					}

					void *data;
					uint32_t size;
				};

				class VirtQueue;

				class VirtIOQueueEvent {
				public:

					VirtIOQueueEvent(VirtQueue *queue, uint32_t descr_idx) : response_size(0), queue(queue), descr_idx(descr_idx)
					{
					}

					inline void add_read_buffer(void *data, uint32_t size)
					{
						read_buffers.push_back(VirtIOQueueEventBuffer(data, size));
					}

					inline void add_write_buffer(void *data, uint32_t size)
					{
						write_buffers.push_back(VirtIOQueueEventBuffer(data, size));
					}

					inline void clear()
					{
						response_size = 0;
						read_buffers.clear();
						write_buffers.clear();
					}

					std::vector<VirtIOQueueEventBuffer> read_buffers;
					std::vector<VirtIOQueueEventBuffer> write_buffers;

					uint32_t response_size;
					VirtQueue *queue;
					uint32_t descr_idx;

					util::Completion<bool> complete;

					void submit();
				};

				class VirtIO : public Device {
					friend class VirtIOQueueEvent;
					friend class VirtQueue;

				public:
					VirtIO(irq::IRQLineBase& irq, uint32_t device_id, uint8_t nr_queues);
					virtual ~VirtIO();

					bool read(uint64_t off, uint8_t len, uint64_t& data) override;
					bool write(uint64_t off, uint8_t len, uint64_t data) override;

					virtual uint32_t size() const
					{
						return 0x1000;
					}

				protected:
					virtual void reset() = 0;

					virtual const uint8_t *config_area() const = 0;
					virtual uint32_t config_area_size() const = 0;

					inline VirtQueue *current_queue() const
					{
						return queue(_queue_sel);
					}

					inline VirtQueue *queue(uint8_t index) const
					{
						if (index > queues.size()) return NULL;
						else return queues[index];
					}

					virtual void process_event(VirtIOQueueEvent *evt) = 0;
					virtual void submit_event(VirtIOQueueEvent *evt);

					std::mutex _isr_lock;

					inline void assert_interrupt(int idx)
					{
						//std::unique_lock<std::mutex> l(_isr_lock);
						std::lock_guard<std::mutex> l(_isr_lock);
						_isr |= 1 << idx;
					}

					inline void rescind_interrupt(int idx)
					{
						//std::unique_lock<std::mutex> l(_isr_lock);
						std::lock_guard<std::mutex> l(_isr_lock);
						_isr &= ~(1 << idx);
					}

					inline void set_host_feature(int idx)
					{
						if (idx > 31) {
							_device_features[1] |= 1 << (idx - 32);
						} else {
							_device_features[0] |= 1 << idx;
						}
					}

					inline void clear_host_feature(int idx)
					{
						if (idx > 31) {
							_device_features[1] &= ~(1 << (idx - 32));
						} else {
							_device_features[0] &= ~(1 << idx);
						}
					}

				private:
					void process_queue(VirtQueue *queue);
					void update_irq();

					std::vector<VirtQueue *> queues;
					irq::IRQLineBase& _irq;

					std::atomic<uint32_t> _isr;

					uint32_t _device_features[2], _device_features_sel;

					uint32_t _device_id;
					uint32_t _vendor_id;

					uint32_t _driver_features;
					uint32_t _driver_features_sel;

					uint32_t _queue_sel;

					uint32_t _status;
				};
			}
		}
	}
}
