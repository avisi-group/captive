/* SPDX-License-Identifier: MIT */
#pragma once

#include <util/fd/net/endpoint.h>
#include <util/fd/net/ip-address.h>

namespace captive {
	namespace util {
		namespace fd {
			namespace net {

				class IPEndPoint : public EndPoint {
				public:
					IPEndPoint(const IPAddress& addr, int port);
					~IPEndPoint();

					const IPAddress& address() const
					{
						return _addr;
					}

					int port() const
					{
						return _port;
					}

					virtual struct sockaddr *create_sockaddr(socklen_t& len) override;
					virtual void free_sockaddr(struct sockaddr *sa) override;

				private:
					const IPAddress _addr;
					int _port;
				};
			}
		}
	}
}
