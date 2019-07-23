/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <string>
#include <vector>

namespace captive {
	namespace hypervisor {
		class Guest;
	}

	namespace devices {

		struct RegisterDescriptor {
			//RegisterDescriptor(uint64_t offset, uint8_t size) : offset(offset), size(size) { }

			uint64_t offset;
			uint8_t size;
		};

		class Device {
		public:
			Device();
			virtual ~Device();

			inline void attach(hypervisor::Guest& guest)
			{
				_guest = &guest;
			}

			inline hypervisor::Guest& guest() const
			{
				return *_guest;
			}

			virtual uint32_t size() const = 0;

			virtual bool read(uint64_t off, uint8_t len, uint64_t& data) = 0;
			virtual bool write(uint64_t off, uint8_t len, uint64_t data) = 0;

			virtual std::string name() const
			{
				return "(unknown)";
			}

			virtual const std::vector<RegisterDescriptor> registers() const;

		private:
			hypervisor::Guest *_guest;
		};
	}
}
