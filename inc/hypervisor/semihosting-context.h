/* SPDX-License-Identifier: MIT */
#pragma once

#include <hypervisor/guest.h>

namespace captive {
	namespace hypervisor {

		struct SemihostingCallData {
			uint64_t call_nr;
			uint64_t arguments[16];
			uint64_t result;
		};

		class SemihostingContext {
		public:

			SemihostingContext(Guest& guest) : _guest(guest)
			{
			}

			virtual bool init() = 0;
			virtual bool handle_semihosting_call(SemihostingCallData& data) = 0;

		protected:

			Guest& guest() const
			{
				return _guest;
			}

			void *resolve_guest_ptr(gpa_t pa);

		private:
			Guest& _guest;
		};
	}
}
