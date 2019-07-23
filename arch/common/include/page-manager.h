/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		struct Page;

		class PageManager {
		public:
			PageManager();
			~PageManager();

			Page *get_page(gpa_t pa) const;

		private:
			uint32_t _pages_buffer_page_count;
			Page *_pages;
		};
	}
}
