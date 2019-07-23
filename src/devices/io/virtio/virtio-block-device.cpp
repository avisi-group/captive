/* SPDX-License-Identifier: MIT */

#include <devices/io/virtio/virtio-block-device.h>
#include <devices/io/block/block-device.h>
#include <captive.h>

#include <string.h>

USE_CONTEXT(VirtIO);
DECLARE_CHILD_CONTEXT(VirtIOBlockDevice, VirtIO);

using namespace captive::devices::io::block;
using namespace captive::devices::io::virtio;

VirtIOBlockDevice::VirtIOBlockDevice(irq::IRQLineBase& irq, BlockDevice& bdev) : VirtIO(irq, 2, 1), _bdev(bdev)
{
	bzero(&config, sizeof(config));
	config.capacity = bdev.blocks();
	config.block_size = bdev.block_size();

	set_host_feature(6);
	set_host_feature(32);
}

VirtIOBlockDevice::~VirtIOBlockDevice()
{

}

static void read_event_callback(BlockDeviceRequest *rq, bool success)
{
	VirtIOQueueEvent *evt = (VirtIOQueueEvent *)rq->opaque;

	DEBUG << CONTEXT(VirtIOBlockDevice) << "Read request callback, success=" << std::boolalpha << success;
	
	/*uint8_t *pdata = ((uint8_t *)evt->write_buffers.front().data);
	
	std::string fname = "vbd-" + std::to_string(rq->block_offset) + ".bin";*/
	
	/*FILE *f = fopen(fname.c_str(), "wb");
	fwrite(pdata, 512, rq->block_count, f);
	fclose(f);*/
	
	*((uint8_t *)evt->write_buffers.back().data) = success ? 0 : 1;
	evt->response_size = 1 + (success ? evt->write_buffers.front().size : 0);
	evt->submit();
	
#ifdef SYNCHRONOUS
	evt->complete.signal(true);
#endif
	
	delete rq;
}

static void write_event_callback(BlockDeviceRequest *rq, bool success)
{
	VirtIOQueueEvent *evt = (VirtIOQueueEvent *)rq->opaque;

	DEBUG << CONTEXT(VirtIOBlockDevice) << "Write request callback, success=" << std::boolalpha << success;
	
	*((uint8_t *)evt->write_buffers.back().data) = success ? 0 : 1;
	evt->response_size = 1;
	evt->submit();

#ifdef SYNCHRONOUS
	evt->complete.signal(true);
#endif
	
	delete rq;
}

void VirtIOBlockDevice::handle_read_event(uint64_t sector, VirtIOQueueEvent* evt)
{
	assert(evt->write_buffers.size() == 2);
	
	BlockDeviceRequest *rq = new BlockDeviceRequest();
	rq->block_count = evt->write_buffers.front().size / _bdev.block_size();
	rq->block_offset = sector;
	rq->buffer = (uint8_t *)evt->write_buffers.front().data;
	rq->is_read = true;
	rq->opaque = evt;

	DEBUG << CONTEXT(VirtIOBlockDevice) << "Submitting read request, offset=" << rq->block_offset << ", count=" << rq->block_count << ", buffer=" << std::hex << (uint64_t)rq->buffer;
		
	if (!_bdev.submit_request(rq, read_event_callback)) {
		*(uint8_t *)evt->write_buffers.back().data = 1;
		evt->response_size = 1;
		submit_event(evt);
#ifdef SYNCHRONOUS
		evt->complete.signal(false);
#endif
	}
}

void VirtIOBlockDevice::handle_write_event(uint64_t sector, VirtIOQueueEvent* evt)
{
	assert(evt->read_buffers.size() == 2);
	
	DEBUG << CONTEXT(VirtIOBlockDevice) << "Handling Write Event";
	
	BlockDeviceRequest *rq = new BlockDeviceRequest();
	rq->block_count = evt->read_buffers.back().size / _bdev.block_size();
	rq->block_offset = sector;
	rq->buffer = (uint8_t *)evt->read_buffers.back().data;
	rq->is_read = false;
	rq->opaque = evt;
	
	DEBUG << CONTEXT(VirtIOBlockDevice) << "Submitting write request, offset=" << rq->block_offset << ", count=" << rq->block_count << ", buffer=" << std::hex << (uint64_t)rq->buffer;
	
	if (!_bdev.submit_request(rq, write_event_callback)) {
		*(uint8_t *)evt->write_buffers.back().data = 1;
		evt->response_size = 1;
		submit_event(evt);
#ifdef SYNCHRONOUS
		evt->complete.signal(false);
#endif
	}
}

void VirtIOBlockDevice::process_event(VirtIOQueueEvent *evt)
{
	DEBUG << CONTEXT(VirtIOBlockDevice) << "Processing Event " << std::hex << evt << ", rd=" << evt->read_buffers.size() << ", wr=" << evt->write_buffers.size();

	if (evt->read_buffers.size() == 0 && evt->write_buffers.size() == 0) {
		return;
	}

	if (evt->read_buffers.front().size < sizeof(struct virtio_blk_req)) {
		WARNING << CONTEXT(VirtIOBlockDevice) << "Discarding event with invalid header";
		return;
	}

	const struct virtio_blk_req *req = (const struct virtio_blk_req *)evt->read_buffers.front().data;

	switch (req->type) {
	case 0: 
		handle_read_event(req->sector, evt);
		break;

	case 1:
		handle_write_event(req->sector, evt);
		break;
		
	case 8: // Get ID
	{
		assert(evt->write_buffers.size() == 2);

		DEBUG << CONTEXT(VirtIOBlockDevice) << "Handling Get ID Event";
		
		char *serial_number = (char *)evt->write_buffers.front().data;
		strncpy(serial_number, "virtio", evt->write_buffers.front().size);

		// Size is the size of the status flag, plus the length of the null-terminated string.
		evt->response_size = 8;

		// Write the status flag
		*(uint8_t *)evt->write_buffers.back().data = 0;

		submit_event(evt);
#ifdef SYNCHRONOUS
		evt->complete.signal(true);
#endif
		break;
	}
	
	default:
		WARNING << CONTEXT(VirtIOBlockDevice) << "Rejecting event with unsupported type " << (uint32_t)req->type;

		evt->response_size = 1;
		*(uint8_t *)evt->write_buffers.back().data = 2;
	
		submit_event(evt);
#ifdef SYNCHRONOUS
		evt->complete.signal(false);
#endif
		break;
	}
}

void VirtIOBlockDevice::reset()
{

}
