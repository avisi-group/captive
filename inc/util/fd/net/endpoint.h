/* SPDX-License-Identifier: MIT */
#pragma once

#include <util/fd/net/types.h>
#include <sys/socket.h>

namespace captive {
	namespace util {
		namespace fd {
			namespace net {

				class EndPoint {
				public:
					EndPoint(AddressFamily family);
					virtual ~EndPoint();

					AddressFamily family() const
					{
						return _family;
					}

					virtual struct sockaddr *create_sockaddr(socklen_t& len) = 0;
					virtual void free_sockaddr(struct sockaddr *sa) = 0;

					static const EndPoint *from_sockaddr(const struct sockaddr *sa);

				private:
					AddressFamily _family;
				};
			}
		}
	}
}
