/* SPDX-License-Identifier: MIT */

#include <devices/io/virtio/virtio-net-device.h>
#include <devices/io/virtio/virtqueue.h>
#include <captive.h>

USE_CONTEXT(VirtIO);
DECLARE_CHILD_CONTEXT(VirtIONetworkDevice, VirtIO);

using namespace captive::devices::io::virtio;
using namespace captive::util;

VirtIONetworkDevice::VirtIONetworkDevice(irq::IRQLineBase& irq, net::NetworkInterface& iface, uint64_t mac_address)
	: VirtIO(irq, 1, 2),
	_iface(iface)
{
	bzero(&config, sizeof(config));

	config.mac[0] = (mac_address >> 40) & 0xff;
	config.mac[1] = (mac_address >> 32) & 0xff;
	config.mac[2] = (mac_address >> 24) & 0xff;
	config.mac[3] = (mac_address >> 16) & 0xff;
	config.mac[4] = (mac_address >>  8) & 0xff;
	config.mac[5] = (mac_address >>  0) & 0xff;

	config.status = 1;

	set_host_feature(5);	// MAC
	set_host_feature(16);	// STATUS
	set_host_feature(32);	// V1

	iface.attach(*this);
}

VirtIONetworkDevice::~VirtIONetworkDevice()
{

}

void VirtIONetworkDevice::reset()
{

}

void VirtIONetworkDevice::process_event(VirtIOQueueEvent* evt)
{
	if (evt->queue->index() == 0) {
		std::unique_lock<std::mutex> l(_receive_buffer_lock);
		_receive_buffers.push_back(evt);
	} else if (evt->queue->index() == 1) {
		assert(evt->read_buffers.size() > 0);
		
		VirtIOQueueEventBuffer& buffer = evt->read_buffers.front();
		
		const virtio_net_hdr *hdr = (const virtio_net_hdr *)buffer.data;
		
		_iface.transmit_packet((const uint8_t *)&hdr->data, buffer.size - sizeof(virtio_net_hdr));
		
		for (unsigned int i = 1; i < evt->read_buffers.size(); i++) {
			_iface.transmit_packet((const uint8_t *)evt->read_buffers[i].data, evt->read_buffers[i].size);
		}
		
		submit_event(evt);
	}
}

void VirtIONetworkDevice::receive_packet(const uint8_t* buffer, uint32_t length)
{
	_receive_buffer_lock.lock();
	
	if (_receive_buffers.size() == 0) {
		_receive_buffer_lock.unlock();
		return;
	}
	
	VirtIOQueueEvent *evt = _receive_buffers.front();
	_receive_buffers.pop_front();
	
	_receive_buffer_lock.unlock();
	
	assert(evt->write_buffers.size() == 1);
		
	VirtIOQueueEventBuffer& data_buffer = evt->write_buffers.front();

	virtio_net_hdr *net_hdr = (virtio_net_hdr *)data_buffer.data;
	memset(net_hdr, 0, sizeof(*net_hdr));
	net_hdr->num_buffers = 1;
	
	size_t remaining_size = data_buffer.size - sizeof(virtio_net_hdr);
		
	unsigned int used_length = (length > remaining_size) ? remaining_size : length;
	memcpy(&net_hdr->data, buffer, used_length);
	
	evt->response_size = sizeof(virtio_net_hdr) + used_length;
	submit_event(evt);
}
