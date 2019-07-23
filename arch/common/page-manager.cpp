/* SPDX-License-Identifier: MIT */

#include <page-manager.h>
#include <page.h>
#include <malloc/page-allocator.h>
#include <printf.h>

using namespace captive::arch;

#define NR_PAGES 1048576

static_assert(((sizeof(Page) * NR_PAGES) & 0xfff) == 0, "Size of Page structure invalid");

PageManager::PageManager() : _pages_buffer_page_count((sizeof(Page) * NR_PAGES) >> 12)
{
	printf("page-manager: managing %u guest pages (need %u pages for buffer)\n", NR_PAGES, _pages_buffer_page_count);

	_pages = (Page *) malloc::page_alloc.alloc_pages(_pages_buffer_page_count);
}

PageManager::~PageManager()
{
	malloc::page_alloc.free_pages(_pages, _pages_buffer_page_count);
}

Page *PageManager::get_page(gpa_t pa) const
{
	return &_pages[pa >> 12];
}
