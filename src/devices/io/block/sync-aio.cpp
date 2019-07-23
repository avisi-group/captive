/* SPDX-License-Identifier: MIT */

#include <devices/io/block/sync-aio.h>
#include <unistd.h>

using namespace captive;
using namespace captive::devices;
using namespace captive::devices::io;
using namespace captive::devices::io::block;

SyncAIO::SyncAIO(int fd, BlockDevice& bdev) : AIO(fd, bdev)
{
	
}

SyncAIO::~SyncAIO()
{

}

bool SyncAIO::init()
{
	return true;
}

bool SyncAIO::submit(BlockDeviceRequest* rq, BlockDevice::block_request_cb_t callback)
{
	off_t off = rq->block_offset * block_size();
	size_t size = rq->block_count * block_size();
	ssize_t rc;
	
	if (rq->is_read) {
		rc = pread(fd(), rq->buffer, size, off);
	} else {
		rc = pwrite(fd(), rq->buffer, size, off);
	}
	
	if (callback) {
		callback(rq, rc == (ssize_t)size);
	}
	
	return rc > 0;
}
