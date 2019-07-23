/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <shmem.h>

namespace captive {
	namespace arch {

		class SpinLockWrapper {
		public:

			SpinLockWrapper(captive::lock::SpinLock *lock) : _lock(lock)
			{
				captive::lock::spinlock_acquire(_lock);
			}

			~SpinLockWrapper()
			{
				captive::lock::spinlock_release(_lock);
			}

		private:
			captive::lock::SpinLock *_lock;
		};
	}
}
