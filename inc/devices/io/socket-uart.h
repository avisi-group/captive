/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/io/uart.h>
#include <thread>
#include <queue>
#include <set>
#include <mutex>
#include <condition_variable>

namespace captive {
	namespace devices {
		namespace io {

			class SocketUART : public UART {
			public:
				SocketUART(int port);
				virtual ~SocketUART();

				bool open() override;
				bool close() override;

				bool read_char(uint8_t& ch) override;
				bool write_char(uint8_t ch) override;

			private:
				int _port, _server_fd;
				std::thread *_server_thread;

				std::set<int> _clients;
				std::mutex _clients_lock;

				std::queue<char> _data_queue;
				std::mutex _data_queue_lock;
				std::condition_variable _data_queue_cond;

				volatile bool _terminate;

				static void server_thread_proc(SocketUART *tp);

				bool make_socket_nonblocking(int fd);
				void enqueue_data(const char *data, int size);
				char dequeue_data();
			};
		}
	}
}
