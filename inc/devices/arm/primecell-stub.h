/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/arm/primecell.h>

namespace captive {
	namespace devices {
		namespace arm {

			class PrimecellStub : public Primecell {
			public:
				PrimecellStub(uint32_t device_id, std::string name = "stub", uint32_t size = 0x1000);
				virtual ~PrimecellStub();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				virtual uint32_t size() const
				{
					return _size;
				}

				virtual std::string name() const
				{
					return _name;
				}

			private:
				std::string _name;
				uint32_t _size;
			};
		}
	}
}
