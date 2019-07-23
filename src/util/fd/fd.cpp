/* SPDX-License-Identifier: MIT */

#include <util/fd/fd.h>
#include <unistd.h>

using namespace captive::util::fd;

/**
 * Constructs a FileDescriptor wrapper, for the given fd.
 * @param fd The fd to wrap.
 */
FileDescriptor::FileDescriptor(int fd) : _fd(fd)
{

}

/**
 * Performs a read operation on the file descriptor.
 * @param buffer The buffer to read into.
 * @param size The maximum size of the buffer.
 * @return The number of bytes read into the buffer.
 */
int FileDescriptor::read(void* buffer, size_t size)
{
	return ::read(_fd, buffer, size);
}

/**
 * Performs a write operation on the file descriptor.
 * @param buffer The buffer to read from.
 * @param size The number of bytes in the buffer to write.
 * @return The number of bytes written.
 */
int FileDescriptor::write(const void* buffer, size_t size)
{
	return ::write(_fd, buffer, size);
}

/**
 * Closes the file descriptor.
 */
void FileDescriptor::close()
{
	::close(_fd);
}

/**
 * Performs clean-up on the file descriptor by closing it.
 */
FileDescriptor::~FileDescriptor()
{
	this->close();
}
