/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace loader {

		class Loader {
		public:
			virtual bool install(uint8_t *gpm) = 0;
			virtual gpa_t base_address() const = 0;
		};

		class FileBasedLoader : public Loader {
		public:
			FileBasedLoader(const std::string& filename);

			inline const std::string& filename() const
			{
				return _filename;
			}

			inline bool is_open() const
			{
				return _opened;
			}

			inline size_t size() const
			{
				return mmap_size;
			}

		protected:
			bool open();
			void close();
			uint8_t *read(off_t offset, size_t size);

		private:
			std::string resolve(const std::string& filename);

			std::string _filename;
			bool _opened;

			void *mmap_base;
			size_t mmap_size;
		};
	}
}
