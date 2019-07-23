/* SPDX-License-Identifier: MIT */
#pragma once

#include <util/fd/net/endpoint.h>
#include <string>

namespace captive {
	namespace util {
		namespace fd {
			namespace net {

				class UnixEndPoint : public EndPoint {
				public:
					UnixEndPoint(std::string path);
					~UnixEndPoint();

					const std::string& path() const
					{
						return _path;
					}

					virtual struct sockaddr *create_sockaddr(socklen_t& len) override;
					virtual void free_sockaddr(struct sockaddr *sa) override;

				private:
					const std::string _path;
				};
			}
		}
	}
}
