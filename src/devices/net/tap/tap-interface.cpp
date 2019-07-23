/* SPDX-License-Identifier: MIT */

#include <devices/net/tap/tap-interface.h>
#include <captive.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/ioctl.h>
#include <netinet/in.h>
#include <linux/if.h>
#include <linux/if_tun.h>

#include <pthread.h>

USE_CONTEXT(Network);
DECLARE_CHILD_CONTEXT(TapInterface, Network);

using namespace captive::devices::net;
using namespace captive::devices::net::tap;

TapInterface::TapInterface(std::string tap_device) : _tap_device(tap_device), _terminate(false)
{

}

TapInterface::~TapInterface()
{

}

bool TapInterface::start()
{
	_tap_fd = open("/dev/net/tun", O_RDWR);
	if (_tap_fd < 0) {
		ERROR << "Unable to open tunnel control: " << LAST_ERROR_TEXT;
		return false;
	}
	
	struct ifreq ifr;
	bzero(&ifr, sizeof(ifr));
	
	ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
	strncpy(ifr.ifr_name, _tap_device.c_str(), IFNAMSIZ-1);
	
	DEBUG << CONTEXT(TapInterface) << "Attaching to: " << _tap_device;
	int rc = ioctl(_tap_fd, TUNSETIFF, (void *)&ifr);
	if (rc < 0) {
		close(_tap_fd);
		
		ERROR << "Unable to create TAP device: " << LAST_ERROR_TEXT;
		return false;
	}
		
	_terminate = false;
	_receive_thread = new std::thread(receive_thread_trampoline, this);
	
	return true;
}

void TapInterface::stop()
{
	DEBUG << "Stopping TAP Interface...";

	_terminate = true;
	close(_tap_fd);
		
	/*if (_receive_thread->joinable()) {
		_receive_thread->join();
	}*/
}

bool TapInterface::transmit_packet(const uint8_t* buffer, uint32_t length)
{
	DEBUG << CONTEXT(TapInterface) << "Transmitting Packet";
	
	write(_tap_fd, buffer, length);	
	return true;
}

void TapInterface::receive_thread_trampoline(TapInterface* obj)
{
	pthread_setname_np(pthread_self(), "net-receive");
	obj->receive_thread_proc();
}

#define MTU	1600

void TapInterface::receive_thread_proc()
{
	DEBUG << "Starting TAP receive thread...";
	
	while (!_terminate) {
		uint8_t buffer[MTU];
		
		DEBUG << CONTEXT(TapInterface) << "Waiting for packet";
		int bytes = read(_tap_fd, buffer, sizeof(buffer));
		
		if (bytes <= 0) break;

		DEBUG << CONTEXT(TapInterface) << "Receiving Packet";
		invoke_receive((const uint8_t *)buffer, bytes);
	}
	
	DEBUG << CONTEXT(TapInterface) << "Exiting TAP receive thread";
}
