/* SPDX-License-Identifier: MIT */
#pragma once

#include <util/fd/fd.h>
#include <list>

namespace captive {
	namespace util {
		namespace fd {
			namespace EpollEventType {

				enum EpollEventType {
					IN = 0x001,
					PRI = 0x002,
					OUT = 0x004,
					RDNORM = 0x040,
					RDBAND = 0x080,
					WRNORM = 0x100,
					WRBAND = 0x200,
					MSG = 0x400,
					ERR = 0x008,
					HUP = 0x010,
					RDHUP = 0x2000,
					WAKEUP = 1u << 29,
					ONESHOT = 1u << 30,
					ET = 1u << 31
				};
			}

			struct EpollEvent {
				FileDescriptor *fd;
				EpollEventType::EpollEventType event_type;

				inline bool in() const
				{
					return event_type & EpollEventType::IN;
				}

				inline bool out() const
				{
					return event_type & EpollEventType::OUT;
				}

				inline bool err() const
				{
					return event_type & EpollEventType::ERR;
				}

				inline bool hup() const
				{
					return event_type & EpollEventType::HUP;
				}
			};

			class Epoll : public FileDescriptor {
			public:
				static Epoll *create();

				void add(FileDescriptor *fd, EpollEventType::EpollEventType event_types);
				void remove(FileDescriptor *fd);
				bool wait(std::list<EpollEvent>& events, int max_events = 24, int timeout = -1);

			private:
				Epoll(int fd);
			};
		}
	}
}
