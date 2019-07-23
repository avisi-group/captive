/* SPDX-License-Identifier: MIT */

#include <devices/io/virtio/virtio.h>
#include <devices/io/virtio/virtqueue.h>
#include <devices/irq/irq-line.h>
#include <hypervisor/guest.h>
#include <captive.h>

#include <string.h>
#include <unistd.h>

DECLARE_CONTEXT(VirtIO);

using namespace captive::devices::io::virtio;

#define VIRTIO_CHAR_SHIFT(c, s) (((uint32_t)((uint8_t)c)) << (s))
#define VIRTIO_MAGIC (VIRTIO_CHAR_SHIFT('v', 0) | VIRTIO_CHAR_SHIFT('i', 8) | VIRTIO_CHAR_SHIFT('r', 16) | VIRTIO_CHAR_SHIFT('t', 24))

#define VIRTIO_REG_MAGIC		0x00		// RO
#define VIRTIO_REG_VERSION		0x04		// RO
	#define VIRTIO_VERSION			0x02
#define VIRTIO_REG_DEVICEID		0x08		// RO
#define VIRTIO_REG_VENDORID		0x0c		// RO

#define VIRTIO_REG_DEVICE_FEATURES		0x10	// RO
#define VIRTIO_REG_DEVICE_FEATURES_SEL	0x14	// WO
#define VIRTIO_REG_DRIVER_FEATURES		0x20	// WO
#define VIRTIO_REG_DRIVER_FEATURES_SEL	0x24	// WO

#define VIRTIO_REG_QUEUE_SEL		0x30	// WO
#define VIRTIO_REG_QUEUE_NUM_MAX	0x34	// RO
#define VIRTIO_REG_QUEUE_NUM		0x38	// WO
#define VIRTIO_REG_QUEUE_READY		0x44	// RW
#define VIRTIO_REG_QUEUE_NOTIFY		0x50	// WO

#define VIRTIO_REG_INTERRUPT_STATUS	0x60	// RO
#define VIRTIO_REG_INTERRUPT_ACK	0x64	// WO
#define VIRTIO_REG_STATUS			0x70	// RW

#define VIRTIO_REG_QUEUE_DESC_LOW		0x080	// WO
#define VIRTIO_REG_QUEUE_DESC_HIGH		0x084	// WO
#define VIRTIO_REG_QUEUE_AVL_LOW		0x090	// WO
#define VIRTIO_REG_QUEUE_AVL_HIGH		0x094	// WO
#define VIRTIO_REG_QUEUE_USED_LOW		0x0a0	// WO
#define VIRTIO_REG_QUEUE_USED_HIGH		0x0a4	// WO

#define VIRTIO_REG_CONFIG_GENERATION	0x0fc		// RO

VirtIO::VirtIO(irq::IRQLineBase& irq, uint32_t device_id, uint8_t nr_queues)
	: _irq(irq),
	_isr(0),
	_device_features {0, 0},
	_device_features_sel(0),
	_device_id(device_id),
	_vendor_id(0x1af4),
	_driver_features(0),
	_driver_features_sel(0),
	_queue_sel(0),
	_status(0)
{
	for (uint8_t i = 0; i < nr_queues; i++) {
		queues.push_back(new VirtQueue(*this, i));
	}
}

VirtIO::~VirtIO()
{
	for (auto queue : queues) {
		delete queue;
	}

	queues.clear();
}

void VirtIOQueueEvent::submit()
{
	queue->owner().submit_event(this);
}

bool VirtIO::read(uint64_t off, uint8_t len, uint64_t& data)
{
	if (off >= 0x100 && off < (0x100 + config_area_size())) {
		uint32_t config_area_offset = off - 0x100;
		if (len > (config_area_size() - config_area_offset))
			return false;

		const uint8_t *config_area_data = config_area();
		data = 0;
		memcpy((void *)&data, (const void *)(config_area_data + config_area_offset), len);
		return true;
	} else {
		switch (off) {
		case VIRTIO_REG_MAGIC: data = VIRTIO_MAGIC; break;
		case VIRTIO_REG_VERSION: data = VIRTIO_VERSION; break;
		case VIRTIO_REG_DEVICEID: data = _device_id; break;
		case VIRTIO_REG_VENDORID: data = _vendor_id; break;

		// Device Features
		case VIRTIO_REG_DEVICE_FEATURES: data = _device_features[_device_features_sel & 1];	break;

		// Queue Configuration
		case VIRTIO_REG_QUEUE_READY: 
			assert(current_queue());
			data = current_queue()->ready() ? 1 : 0; 
			break;
			
		case VIRTIO_REG_QUEUE_NUM_MAX: 
			if (!current_queue()) {
				data = 0;
			} else {
				data = current_queue()->num_max(); 
			}
			break;

		// Status Registers
		case VIRTIO_REG_INTERRUPT_STATUS: data = _isr; break;
		case VIRTIO_REG_STATUS: data = _status; break;
		case VIRTIO_REG_CONFIG_GENERATION: data = 0; break;
		
		default:
			return false;
		}
	}

	DEBUG << CONTEXT(VirtIO) << "READ @ " << std::hex << off << "(" << (uint32_t)len << ") = " << data;
	return true;
}

bool VirtIO::write(uint64_t off, uint8_t len, uint64_t data)
{
	DEBUG << CONTEXT(VirtIO) << "WRITE @ " << std::hex << off << "(" << (uint32_t)len << ") = " << data;
	
	switch (off) {
	// Device Features
	case VIRTIO_REG_DEVICE_FEATURES_SEL: _device_features_sel = data & 1; break;

	// Driver Features
	case VIRTIO_REG_DRIVER_FEATURES: _driver_features = data; break;
	case VIRTIO_REG_DRIVER_FEATURES_SEL: _driver_features_sel = data; break;

	// Queue Configuration
	case VIRTIO_REG_QUEUE_SEL: _queue_sel = data; break;

	case VIRTIO_REG_QUEUE_NUM: current_queue()->num(data); break;
	case VIRTIO_REG_QUEUE_READY: current_queue()->ready(data == 1); break;
	
	case VIRTIO_REG_QUEUE_DESC_LOW: current_queue()->descriptor_gpa_low(data); break;
	case VIRTIO_REG_QUEUE_DESC_HIGH: current_queue()->descriptor_gpa_high(data); break;
	case VIRTIO_REG_QUEUE_AVL_LOW: current_queue()->avail_gpa_low(data); break;
	case VIRTIO_REG_QUEUE_AVL_HIGH: current_queue()->avail_gpa_high(data); break;
	case VIRTIO_REG_QUEUE_USED_LOW: current_queue()->used_gpa_low(data); break;
	case VIRTIO_REG_QUEUE_USED_HIGH: current_queue()->used_gpa_high(data); break;
	
	/*case VIRTIO_REG_QUEUE_PFN:
		if (data == 0) {
			_driver_features_sel = 0;
			_driver_features = 0;

			reset();
		} else {
			gpa_t queue_phys_addr = data << _guest_page_shift;
			VirtQueue *cq = current_queue();

			void *queue_host_addr;
			if (!guest().resolve_gpa(queue_phys_addr, queue_host_addr)) {
				ERROR << CONTEXT(VirtIO) << "Unable to resolve GPA: " << std::hex << queue_phys_addr;
				assert(false);
			}

			DEBUG << CONTEXT(VirtIO) << "Resolved PFN from " << std::hex << queue_phys_addr << " to " << queue_host_addr;
			cq->guest_phys_addr(queue_phys_addr);
			cq->queue_host_addr(queue_host_addr);
		}
		break;*/

	case VIRTIO_REG_QUEUE_NOTIFY:
		process_queue(queue(data));
		break;

	case VIRTIO_REG_INTERRUPT_ACK:
		{
			std::lock_guard<std::mutex> l(_isr_lock);
			_isr &= ~data;
		}
	
		update_irq();
		break;

	case VIRTIO_REG_STATUS:
		_status = data;

		if (_status == 0) {
			_driver_features_sel = 0;
			_driver_features = 0;

			reset();
		}

		break;

	default:
		return false;
	}

	return true;
}

void VirtIO::process_queue(VirtQueue* queue)
{
	assert(queue);
	
	DEBUG << CONTEXT(VirtIO) << "Processing queue " << queue;
	
	uint32_t idx = -1;
	const VirtRingDescr *descr;
	
	queue->lock.lock();
	while ((descr = queue->pop(idx)) != NULL) {
		DEBUG << CONTEXT(VirtIO) << "Popped a descriptor chain head, idx=" << std::dec << idx;
		
		VirtIOQueueEvent *evt = new VirtIOQueueEvent(queue, idx);
		do {
			void *descr_host_addr;
			if (!guest().resolve_gpa((gpa_t)descr->addr, descr_host_addr)) {
				ERROR << "Unable to resolve VirtIO descriptor physical address to host address";
				abort();
			}
			
			assert(!descr->is_indirect());
			
			if (descr->is_write()) {
				DEBUG << CONTEXT(VirtIO) << "Has a write buffer len=" << descr->length;
				evt->add_write_buffer(descr_host_addr, descr->length);
			} else {
				DEBUG << CONTEXT(VirtIO) << "Has a read buffer len=" << descr->length;
				evt->add_read_buffer(descr_host_addr, descr->length);
			}
			
			if (descr->has_next()) {
				descr = queue->get_descr(descr->next);
			} else {
				descr = NULL;
			}
		} while(descr);
		
		queue->lock.unlock();
		process_event(evt);
		queue->lock.lock();
		
#ifdef SYNCHRONOUS
		evt->complete.wait();
		delete evt;
#endif
	}
	queue->lock.unlock();
}

void VirtIO::submit_event(VirtIOQueueEvent *evt)
{
	assert(evt && evt->queue);
	
	DEBUG << CONTEXT(VirtIO) << "Asserting interrupt for " << std::hex << evt;
	
	evt->queue->lock.lock();
	evt->queue->push(evt->descr_idx, evt->response_size);
	evt->queue->lock.unlock();
	
	assert_interrupt(0);
	_irq.raise();
	
#ifndef SYNCHRONOUS
	delete evt;
#endif
}

void VirtIO::update_irq()
{
	std::lock_guard<std::mutex> l(_isr_lock);
	
	if (_isr) {
		_irq.raise();
	} else {
		_irq.rescind();
	}
}
