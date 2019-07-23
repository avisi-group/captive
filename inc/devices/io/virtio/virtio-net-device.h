/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/virtio/virtio.h>
#include <devices/net/network-interface.h>

#include <list>
#include <mutex>

namespace captive {
	namespace devices {
		namespace io {
			namespace virtio {

				class VirtIONetworkDevice : public VirtIO, public net::NetworkInterfaceReceiveCallback {
				public:
					VirtIONetworkDevice(irq::IRQLineBase& irq, net::NetworkInterface& iface, uint64_t mac_address);
					virtual ~VirtIONetworkDevice();

					void receive_packet(const uint8_t *buffer, uint32_t length) override;

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
					net::NetworkInterface& _iface;

					std::mutex _receive_buffer_lock;
					std::list<VirtIOQueueEvent *> _receive_buffers;

					struct {
						uint8_t mac[6];
						uint16_t status;
						uint16_t max_virtqueue_pairs;
					} __packed config;

					struct virtio_net_hdr {
						uint8_t flags;
						uint8_t gso_type;
						uint16_t hdr_len;
						uint16_t gso_size;
						uint16_t csum_start, csum_offset;
						uint16_t num_buffers;
						uint8_t data[];
					} __packed;
				};
			}
		}
	}
}
