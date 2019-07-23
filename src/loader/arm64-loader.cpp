/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <loader/arm64-loader.h>

using namespace captive::loader;

USE_CONTEXT(Loader)
DECLARE_CHILD_CONTEXT(ARM64Loader, Loader)

#define LOAD_BIAS 0x80000000ull

ARM64Loader::ARM64Loader(std::string filename) : FileBasedLoader(filename)
{

}

bool ARM64Loader::install(uint8_t* gpm)
{
	// Attempt to open the file.
	if (!open()) {
		ERROR << CONTEXT(ARM64Loader) << "Unable to open file";
		return false;
	}

	// Retrieve the entire ZIMAGE and check that the magic number
	// is okay.
	const arm64_header *header = (const arm64_header *)read(0, size());

	if (header->magic != ARM64_MAGIC) {
		ERROR << CONTEXT(ARM64Loader) << "Magic number invalid";
		return false;
	}
	
	_base_address = header->text_offset;
	_entrypoint = header->text_offset + LOAD_BIAS;
	
	fprintf(stderr, "loading arm64 kernel to %p\n", (void *)_entrypoint);
	
	// Copy the image into guest memory.
	void *gpm_base = &gpm[header->text_offset + LOAD_BIAS];
	memcpy(gpm_base, (const void *)header, size());

	close();
	return true;
}

bool ARM64Loader::requires_device_tree() const
{
	return true;
}

bool ARM64Loader::match(const uint8_t* buffer)
{
	const arm64_header *header = (const arm64_header *)buffer;

	if (header->magic != ARM64_MAGIC) {
		return false;
	}
	
	return true;
}
