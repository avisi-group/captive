/* SPDX-License-Identifier: MIT */

#include <devices/io/block/file-backed-block-device.h>
#include <devices/io/block/linux-aio.h>
#include <devices/io/block/posix-aio.h>
#include <devices/io/block/sync-aio.h>
#include <captive.h>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

USE_CONTEXT(BlockDevice);
DECLARE_CHILD_CONTEXT(FileBackedBlockDevice, BlockDevice);

using namespace captive::devices::io::block;

FileBackedBlockDevice::FileBackedBlockDevice() 
	: BlockDevice(512),
		_file_descr(-1),
		_file_size(0),
		_block_count(0),
		_read_only(false),
		_aio_impl(NULL)
{
}

FileBackedBlockDevice::~FileBackedBlockDevice()
{
	if (_file_descr > -1) {
		close_file();
	}
}

bool FileBackedBlockDevice::open_file(std::string filename, bool read_only)
{
	if (_file_descr >= 0) return false;
	
	_read_only = read_only;

	_file_descr = open(filename.c_str(), (read_only ? O_RDONLY : O_RDWR) | O_EXCL | O_DIRECT);
	if (_file_descr < 0) {
		ERROR << CONTEXT(FileBackedBlockDevice) << "Failed to open file";
		return false;
	}

	struct stat st;
	if (fstat(_file_descr, &st)) {
		ERROR << CONTEXT(FileBackedBlockDevice) << "Failed to stat file";
		close(_file_descr);
		_file_descr = -1;
		
		return false;
	}

	DEBUG << CONTEXT(FileBackedBlockDevice) << "File size: " << st.st_size;

	_file_size = st.st_size;

	_block_count = _file_size / block_size();
	if (_file_size % block_size() != 0) {
		_block_count++;
	}
	
	//_aio_impl = new SyncAIO(_file_descr, *this);
	_aio_impl = new LinuxAIO(_file_descr, *this);
	//_aio_impl = new POSIXAIO(_file_descr, *this);
	
	if (!_aio_impl->init()) {
		close(_file_descr);
		_file_descr = -1;
		
		return false;
	}

	return true;
}

void FileBackedBlockDevice::close_file()
{
	if (_file_descr == -1) return;

	delete _aio_impl;
	_aio_impl = NULL;
	
	close(_file_descr);
	_file_descr = -1;
}

bool FileBackedBlockDevice::submit_request(BlockDeviceRequest *rq, block_request_cb_t callback)
{
	return _aio_impl->submit(rq, callback);
}
