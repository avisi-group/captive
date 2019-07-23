/* SPDX-License-Identifier: MIT */

#include <loader/initrd-loader.h>
#include <string.h>

using namespace captive::loader;

InitRDLoader::InitRDLoader(std::string filename, uint32_t base_address) : FileBasedLoader(filename), _base_address(base_address)
{
}

bool InitRDLoader::install(uint8_t* gpm)
{
	if (!open())
		return false;
	
	uint8_t *base = gpm + (uint64_t)_base_address;
	memcpy(base, read(0, size()), size());
	
	close();
	return true;
}
