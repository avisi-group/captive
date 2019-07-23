/* SPDX-License-Identifier: MIT */

#include <loader/um-loader.h>
#include <captive.h>

using namespace captive::loader;

UMLoader::UMLoader(const std::string& filename) : FileBasedLoader(filename)
{

}

bool UMLoader::install(uint8_t* gpm)
{
	// Attempt to open the file.
	if (!open()) {
		return false;
	}
	
	uint8_t *buffer = read(0, size());
	
	memcpy(gpm, buffer, size());
	
	close();
	return true;
}
