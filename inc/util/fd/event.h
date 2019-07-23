/* SPDX-License-Identifier: MIT */
#pragma once

#include <util/fd/fd.h>

namespace captive {
	namespace util {
		namespace fd {

			class Event : public FileDescriptor {
			public:
				static Event *create();

				void invoke();

			private:
				Event(int fd);
			};
		}
	}
}
