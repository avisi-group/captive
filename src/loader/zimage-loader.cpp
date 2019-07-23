/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <loader/zimage-loader.h>

using namespace captive::loader;

USE_CONTEXT(Loader)
DECLARE_CHILD_CONTEXT(ZImageLoader, Loader)

ZImageLoader::ZImageLoader(std::string filename) : FileBasedLoader(filename)
{

}

bool ZImageLoader::install(uint8_t* gpm)
{
	// Attempt to open the file.
	if (!open()) {
		ERROR << CONTEXT(ZImageLoader) << "Unable to open file";
		return false;
	}

	// Retrieve the entire ZIMAGE and check that the magic number
	// is okay.
	const zimage_header *header = (const zimage_header *)read(0, size());

	if (header->magic_number != ZIMAGE_MAGIC_NUMBER) {
		close();

		ERROR << CONTEXT(ZImageLoader) << "ZImage Header has invalid magic number";
		return false;
	}

	// Copy the ZIMAGE into guest memory.
	void *gpm_base = &gpm[ZIMAGE_BASE];
	memcpy(gpm_base, (const void *)header, size());

	close();
	return true;
}

gpa_t ZImageLoader::entrypoint() const
{
	return (gpa_t)ZIMAGE_BASE;
}

bool ZImageLoader::requires_device_tree() const
{
	return true;
}

bool ZImageLoader::match(const uint8_t* buffer)
{
	return (((const zimage_header *)buffer)->magic_number) == ZIMAGE_MAGIC_NUMBER;
}
