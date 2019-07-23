/* SPDX-License-Identifier: MIT */

#include <devices/io/block/linux-aio.h>
#include <captive.h>

#include <unistd.h>
#include <sys/syscall.h>

USE_CONTEXT(AIO);
DECLARE_CHILD_CONTEXT(LinuxAIO, AIO);

inline int io_setup(unsigned nr, aio_context_t *ctxp)
{
	return syscall(__NR_io_setup, nr, ctxp);
}

inline int io_destroy(aio_context_t ctx) 
{
	return syscall(__NR_io_destroy, ctx);
}

inline int io_submit(aio_context_t ctx, long nr,  struct iocb **iocbpp) 
{
	return syscall(__NR_io_submit, ctx, nr, iocbpp);
}

inline int io_getevents(aio_context_t ctx, long min_nr, long max_nr, struct io_event *events, struct timespec *timeout)
{
	return syscall(__NR_io_getevents, ctx, min_nr, max_nr, events, timeout);
}

using namespace captive::devices::io::block;

LinuxAIO::LinuxAIO(int fd, BlockDevice& bdev) : AIO(fd, bdev)
{

}

LinuxAIO::~LinuxAIO() {
	_terminate = true;
	io_destroy(_aio);

	if (_aio_thread->joinable()) _aio_thread->join();	
}

bool LinuxAIO::init()
{
	bzero((void *)&_aio, sizeof(_aio));
	
	if (io_setup(128, &_aio)) {
		ERROR << CONTEXT(LinuxAIO) << "Unable to setup AIO:" << strerror(errno);
		return false;
	}
	
	_terminate = false;
	_aio_thread = new std::thread(aio_thread_proc, this);
	
	return true;
}

bool LinuxAIO::submit(BlockDeviceRequest *rq, BlockDevice::block_request_cb_t callback)
{
	struct iocb *cb = (struct iocb *)malloc(sizeof(struct iocb));
	
	bzero(cb, sizeof(*cb));
	cb->aio_fildes = fd();
	
	if (rq->is_read)
		cb->aio_lio_opcode = IOCB_CMD_PREAD;
	else
		cb->aio_lio_opcode = IOCB_CMD_PWRITE;
	
	cb->aio_buf = (uint64_t)rq->buffer;
	cb->aio_offset = rq->block_offset * block_size();
	cb->aio_nbytes = rq->block_count * block_size();
	cb->aio_data = (uint64_t)new BlockDeviceRequestContext(rq, callback);
	
	DEBUG << CONTEXT(LinuxAIO) << "Submitting IO request";
	
	int rc;
	do {
		rc = io_submit(_aio, 1, &cb);
		if (rc < 0) {
			if (errno == EAGAIN) {
				usleep(10);
				continue;
			}

			ERROR << CONTEXT(LinuxAIO) << "IO submission error: " << LAST_ERROR_TEXT;
			return false;
		} else if (rc != 1) {
			ERROR << CONTEXT(LinuxAIO) << "IO submission rejection";
			return false;
		} else {
			return true;
		}
	} while (true);
}

void LinuxAIO::aio_thread_proc(LinuxAIO *aio)
{
	pthread_setname_np(pthread_self(), "aio");
	
	struct io_event events[8];
	while (!aio->_terminate) {		
		int rc = io_getevents(aio->_aio, 1, 8, events, NULL);
		if (rc < 0) {
			if (errno == EINTR) continue;
			
			ERROR << CONTEXT(LinuxAIO) << "IO event error";
			break;
		}
		
		for (int i = 0; i < rc; i++) {
			BlockDeviceRequestContext *ctx = (BlockDeviceRequestContext *)events[i].data;
			bool success = events[i].res == (ctx->rq->block_count * aio->block_size());

			if (ctx->cb) {
				ctx->cb(ctx->rq, success);
			}
		
			delete ctx;
			free((void *)events[i].obj);
		}
	}
}
