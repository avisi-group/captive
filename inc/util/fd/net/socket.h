/* SPDX-License-Identifier: MIT */
#pragma once

#include <util/fd/fd.h>
#include <util/fd/net/types.h>
#include <util/fd/net/endpoint.h>

namespace captive {
	namespace util {
		namespace fd {
			namespace net {

				class Socket : public FileDescriptor {
				public:
					static Socket *create(AddressFamily family, SocketType type, ProtocolType protocol);

					void bind(EndPoint& ep);
					void listen(int max_pending);
					Socket *accept();

					bool reuse_addr() const;
					void reuse_addr(bool v);

					const EndPoint *remote_endpoint() const
					{
						return _remote_endpoint;
					}

				private:
					Socket(int fd, AddressFamily family, SocketType type, ProtocolType protocol, const EndPoint *rep);

					AddressFamily _family;
					SocketType _type;
					ProtocolType _protocol;
					const EndPoint *_remote_endpoint;

					void set_option(int level, int optname, const void *optval, size_t optlen);
					void get_option(int level, int optname, void *optval, size_t& optlen) const;
				};
			}
		}
	}
}
