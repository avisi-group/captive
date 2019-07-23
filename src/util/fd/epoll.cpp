/* SPDX-License-Identifier: MIT */

#include <util/fd/epoll.h>
#include <util/exception.h>
#include <sys/epoll.h>

using namespace captive::util::fd;

/**
 * Creates a new epollfd wrapper.
 * @return An Epoll object representing the newly created epollfd.
 */
Epoll *Epoll::create()
{
	// Create the epollfd.
	int fd = epoll_create1(0);
	if (fd < 0)
		return NULL;

	// Create and return the Epoll wrapper object.
	return new Epoll(fd);
}

Epoll::Epoll(int fd) : FileDescriptor(fd)
{

}

/**
 * Adds a file-descriptor to the epoll watch list.
 * @param fd The file-descriptor to add to the watch list.
 * @param events The events to associate with the file-descriptor on the watch list.
 */
void Epoll::add(FileDescriptor* fd, EpollEventType::EpollEventType events)
{
	// Construct a native epoll_event structure, to represent the fd being
	// added to the epollfd.
	struct epoll_event evt;
	evt.data.ptr = fd;
	evt.events = (uint32_t)events;

	// Add the fd to the epollfd.
	if (epoll_ctl(_fd, EPOLL_CTL_ADD, fd->fd(), &evt) < 0)
		throw Exception("unable to add file descriptor");
}

/**
 * Removes a file-descriptor from the epoll watch list
 * @param fd The file-descriptor to remove from the watch list.
 */
void Epoll::remove(FileDescriptor* fd)
{
	// Tell the epollfd to remove the given file-descriptor.
	if (epoll_ctl(_fd, EPOLL_CTL_DEL, fd->fd(), NULL) < 0)
		throw Exception("unable to remove file descriptor");
}

/**
 * Waits for one or more events to occur on the watched file-descriptors.
 * @param events A list to populate with events.  This list is NOT cleared.
 * @param max_events The maximum number of events to return.
 * @param timeout A timeout for the wait, or -1 for infinity.
 * @return Whether or not the wait proceeded without errors.
 */
bool Epoll::wait(std::list<EpollEvent>& events, int max_events, int timeout)
{
	// Create a bunch of event descriptors on the stack.
	// TODO: maybe malloc() these instead.
	struct epoll_event evts[max_events];

	// Wait for events to become ready.
	int count = epoll_wait(_fd, evts, max_events, timeout);

	// If there was an error, check to see if it was because it was interrupted,
	// or if there was an ACTUAL error.
	if (count < 0) {
		if (errno == EINTR)
			return true;
		return false;
	}

	// Enumerate over all the ready events, and populate the event list.
	for (int i = 0; i < count; i++) {
		events.push_back({
			(FileDescriptor *)evts[i].data.ptr,
			(EpollEventType::EpollEventType)evts[i].events
		});
	}

	return true;
}
