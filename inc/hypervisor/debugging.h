/* SPDX-License-Identifier: MIT */
#pragma once

#include <util/fd/net/socket.h>
#include <thread>
#include <pthread.h>

namespace captive {
	namespace hypervisor {
		class DebuggerInterface;

		class DebuggerSession {
		public:

			DebuggerSession(captive::util::fd::net::Socket *client, DebuggerInterface& iface) : _client(client), _thread(nullptr), _iface(iface)
			{
			}
			~DebuggerSession();

			bool start();
			void interrupt();

		private:
			captive::util::fd::net::Socket *_client;
			std::thread *_thread;
			DebuggerInterface& _iface;
			pthread_barrier_t _ready_barrier;

			static void thread_proc_trampoline(void *o);
			void thread_proc();

			bool read_char(char &c);

			bool send_command(const std::string& command, char starter = '$');
			bool read_command(std::string& command);
			bool wait_ack();

			void send_ack();
			void send_nack();

			void handle_query_get(const std::string& command);
			void handle_exec_cmd(const std::string& command);
			void handle_report();
			void handle_read_registers();
			void handle_read_register(const std::string& command);
			void handle_read_memory(const std::string& command);

			void send_stop_code();
		};

		class DebuggerInterface {
		public:
			virtual void debug_stop() = 0;
			virtual void debug_resume() = 0;

			virtual void debug_step() = 0;

			virtual bool debug_get_registers(uint64_t *registers, size_t& count)
			{
				return false;
			}

			virtual bool debug_get_memory(uint64_t gva, void *buffer, size_t size)
			{
				return false;
			}
		};

		class Debugger {
		public:
			Debugger();
			~Debugger();

			bool init();

			bool wait_attach(DebuggerInterface& iface);
			void interrupt();

		private:
			captive::util::fd::net::Socket *_gdb_socket;
			DebuggerSession *_debug_session;

			std::thread *_debug_session_thread;

			bool start_debug_session(captive::util::fd::net::Socket *client, DebuggerInterface& iface);
		};
	}
}
