/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace util {
		namespace fd {

			class FileDescriptor {
			public:
				~FileDescriptor();
				void close();

				int fd() const
				{
					return _fd;
				}

				int read(void *buffer, size_t size);
				int write(const void *buffer, size_t size);

			protected:
				FileDescriptor(int fd);
				int _fd;
			};
		}
	}
}
