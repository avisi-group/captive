/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <loader/devtree-loader.h>

using namespace captive::loader;

DeviceTreeLoader::DeviceTreeLoader(std::string filename, uint32_t base_address) : FileBasedLoader(filename), _base_address(base_address)
{

}

bool DeviceTreeLoader::install(uint8_t* gpm)
{
	if (!open()) {
		ERROR << "Unable to open file";
		return false;
	}

	void *device_tree_data = read(0, size());
	if (!device_tree_data) {
		close();

		ERROR << "Unable to read device tree";
		return false;
	}

	memcpy((gpm + _base_address), device_tree_data, size());

	close();
	return true;
}
