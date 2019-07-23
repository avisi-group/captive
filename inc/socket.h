/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {

	class Socket {
	public:
		Socket();
		Socket(int fd);
		virtual ~Socket();

		void close();

		inline int get_fd() const
		{
			return fd;
		}

	protected:
		int fd;
	};

	class ServerSocket {
	public:
		ServerSocket();
		virtual ~ServerSocket();

		virtual bool create() = 0;
		virtual bool bind() = 0;
		virtual void listen(int max_pending) = 0;
		virtual Socket *accept() = 0;
	};

	class ClientSocket {
	public:
		ClientSocket();
		virtual ~ClientSocket();
		virtual bool connect() = 0;
	};

	class UnixDomainSocket : public ServerSocket, public ClientSocket, public Socket {
	public:
		UnixDomainSocket(std::string path);
		virtual ~UnixDomainSocket();

		bool connect() override;
		void listen(int max_pending) override;
		Socket *accept() override;
		bool create() override;
		bool bind() override;

	private:
		std::string path;
	};

	class TCPSocket : public ServerSocket, public ClientSocket, public Socket {
	public:
		TCPSocket(std::string host, int port);
		virtual ~TCPSocket();

		bool connect() override;
		void listen(int max_pending = 8) override;
		Socket *accept() override;
		bool create() override;
		bool bind() override;

	private:
		std::string host;
		int port;
	};
}
