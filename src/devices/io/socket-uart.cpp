/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <devices/io/socket-uart.h>

#include <socket.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/epoll.h>

using namespace captive::devices::io;

SocketUART::SocketUART(int port) : _port(port)
{
	
}

SocketUART::~SocketUART()
{

}

bool SocketUART::open()
{
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_server_fd < 0)
		return false;
	
	struct sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(_port);
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	
	if (bind(_server_fd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) < 0) {
		::close(_server_fd);
		return false;
	}
	
	if (!make_socket_nonblocking(_server_fd)) {
		::close(_server_fd);
		return false;
	}
	
	listen(_server_fd, 8);
	
	_terminate = false;
	_server_thread = new std::thread(server_thread_proc, this);
	return true;
}

bool SocketUART::close()
{
	_terminate = true;
	::close(_server_fd);

	if (_server_thread->joinable()) {
		_server_thread->join();
	}
	
	_server_thread = NULL;
	return true;
}

bool SocketUART::read_char(uint8_t& ch)
{
	ch = (uint8_t)dequeue_data();
	//fprintf(stderr, "read_char: %c %02x\n", ch, ch);
	return true;
}

bool SocketUART::write_char(uint8_t ch)
{
	std::unique_lock<std::mutex> lock(_clients_lock);
	
	//fprintf(stderr, "write_char: %c %02x\n", ch, ch);
	
	for (auto client : _clients) {
		write(client, &ch, 1);
	}
	
	return true;
}

void SocketUART::server_thread_proc(SocketUART *tp)
{
	int efd = epoll_create1(0);
	if (efd < 0) {
		ERROR << "Unable to create epoll fd";
		return;
	}
	
	struct epoll_event evt;
	evt.data.fd = tp->_server_fd;
	evt.events = EPOLLIN | EPOLLET | EPOLLHUP;
	
	if (epoll_ctl(efd, EPOLL_CTL_ADD, tp->_server_fd, &evt) < 0) {
		::close(efd);
		ERROR << "Unable to add server socket to event loop";
		return;
	}
	
	struct epoll_event evts[12];
	
	while (!tp->_terminate) {
		int nr_events = epoll_wait(efd, evts, sizeof(evts) / sizeof(evts[0]), -1);
		
		for (int i = 0; i < nr_events; i++) {
			if (evts[i].events & EPOLLERR) {
				DEBUG << "EPOLL error";
				::close(evts[i].data.fd);
			} else if (evts[i].data.fd == tp->_server_fd) {
				if (evts[i].events & EPOLLHUP) {
					DEBUG << "Server hangup";
				} else {
					while (1) {
						int clientfd = accept(tp->_server_fd, NULL, NULL);
						if (clientfd < 0) {
							if (errno == EAGAIN || errno == EWOULDBLOCK) {
								break;
							} else {
								ERROR << "Unable to accept socket";
								break;
							}
						}
						
						tp->make_socket_nonblocking(clientfd);
						
						evt.data.fd = clientfd;
						evt.events = EPOLLIN | EPOLLET;
						if (epoll_ctl(efd, EPOLL_CTL_ADD, clientfd, &evt) < 0) {
							ERROR << "Unable to add accepted socket to event loop";
						} else {
							tp->_clients_lock.lock();
							tp->_clients.insert(clientfd);
							tp->_clients_lock.unlock();
						}
					}
				}
			} else {
				while (1) {
					char buffer[512];
					int nr_bytes = read(evts[i].data.fd, buffer, sizeof(buffer));
					if (nr_bytes < 0) {
						if (errno != EAGAIN) {
							tp->_clients_lock.lock();
							tp->_clients.erase(evts[i].data.fd);
							tp->_clients_lock.unlock();
							
							::close(evts[i].data.fd);
						}
						
						break;
					} else if (nr_bytes == 0) {
						tp->_clients_lock.lock();
						tp->_clients.erase(evts[i].data.fd);
						tp->_clients_lock.unlock();
						
						::close(evts[i].data.fd);
						break;
					}
					
					tp->enqueue_data(buffer, nr_bytes);
				}
			}
		}
	}
	
	tp->_clients_lock.lock();
	for (auto client : tp->_clients) {
		::close(client);
	}
	tp->_clients.clear();
	tp->_clients_lock.unlock();
}

bool SocketUART::make_socket_nonblocking(int fd)
{
	int flags = fcntl(fd, F_GETFL, 0);
	if (flags < 0) {
		return false;
	}
	
	flags |= O_NONBLOCK;
	if (fcntl(fd, F_SETFL, flags) < 0) {
		return false;
	}
	
	return true;
}

void SocketUART::enqueue_data(const char *data, int size)
{
	std::unique_lock<std::mutex> lock(_data_queue_lock);
	
	for (int i = 0; i < size; i++) {
		_data_queue.push(data[i]);
	}
	
	_data_queue_cond.notify_all();
}

char SocketUART::dequeue_data()
{
	std::unique_lock<std::mutex> lock(_data_queue_lock);
	
	while (_data_queue.size() == 0) {
		_data_queue_cond.wait(lock);
	}
	
	char rc = _data_queue.front();
	_data_queue.pop();
	
	return rc;
}
