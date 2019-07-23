/* SPDX-License-Identifier: MIT */

#include <devices/io/block/posix-aio.h>
#include <captive.h>

USE_CONTEXT(AIO);
DECLARE_CHILD_CONTEXT(POSIXAIO, AIO);

using namespace captive::devices::io::block;

POSIXAIO::POSIXAIO(int fd, BlockDevice& bdev) : AIO(fd, bdev)
{

}

POSIXAIO::~POSIXAIO()
{
}

bool POSIXAIO::init()
{
	return true;
}

void POSIXAIO::posix_aio_notify(sigval_t sv)
{
	BlockDeviceRequestContext *ctx = (BlockDeviceRequestContext *)sv.sival_ptr;
	
	int err;
	while ((err = aio_error(&ctx->aio_cb)) == EINPROGRESS);
	
	if (err) {
		fprintf(stderr, "ERROR\n");
		exit(0);
	}
	
	uint64_t transferred = aio_return(&ctx->aio_cb);
	bool success = transferred == ctx->aio_cb.aio_nbytes;
	
	if (ctx->cb) {
		ctx->cb(ctx->rq, success);
	}
		
	delete ctx;
}

bool POSIXAIO::submit(BlockDeviceRequest *rq, BlockDevice::block_request_cb_t callback)
{
	BlockDeviceRequestContext *ctx = new BlockDeviceRequestContext(rq, callback);
	bzero(&ctx->aio_cb, sizeof(ctx->aio_cb));
	
	ctx->aio_cb.aio_buf = rq->buffer;
	ctx->aio_cb.aio_fildes = fd();
	ctx->aio_cb.aio_lio_opcode = 0;
	ctx->aio_cb.aio_nbytes = rq->block_count * block_size();
	ctx->aio_cb.aio_offset = rq->block_offset * block_size();
	ctx->aio_cb.aio_reqprio = 0;
	
	ctx->aio_cb.aio_sigevent.sigev_notify = SIGEV_THREAD;
	ctx->aio_cb.aio_sigevent.sigev_notify_function = posix_aio_notify;
	ctx->aio_cb.aio_sigevent.sigev_value.sival_ptr = ctx;
	
	
	if (rq->is_read)
		return aio_read(&ctx->aio_cb) == 0;
	else
		return aio_write(&ctx->aio_cb) == 0;
}

