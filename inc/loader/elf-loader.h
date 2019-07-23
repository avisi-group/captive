/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <loader/loader.h>
#include <loader/kernel-loader.h>

namespace captive {
	namespace loader {

		class ELFLoader : public FileBasedLoader, public KernelLoader {
		public:
			ELFLoader(std::string filename);

			bool install(uint8_t* gpm) override;
			gpa_t entrypoint() const override;
			bool requires_device_tree() const override;

			gpa_t base_address() const override
			{
				return _base_address;
			}

			static bool match(const uint8_t *buffer);

			gpa_t end_of_loaded_data() const
			{
				return _end_of_loaded_data;
			}

			gpa_t program_headers_offset() const
			{
				return _phdr_addr;
			}

			uint32_t program_header_size() const
			{
				return _phdr_ent_size;
			}

			uint32_t nr_program_headers() const
			{
				return _phdr_cnt;
			}

		private:
			gpa_t _entrypoint, _base_address;
			gpa_t _end_of_loaded_data;

			uint32_t _phdr_ent_size, _phdr_cnt, _phdr_addr;

			bool install32(uint8_t* gpm);
			bool install64(uint8_t* gpm);
		};
	}
}
