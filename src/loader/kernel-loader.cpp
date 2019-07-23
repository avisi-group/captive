/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <loader/kernel-loader.h>
#include <loader/zimage-loader.h>
#include <loader/elf-loader.h>
#include <loader/arm64-loader.h>
#include <loader/um-loader.h>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

using namespace captive::loader;
using namespace captive::util::config;

USE_CONTEXT(Loader)
DECLARE_CHILD_CONTEXT(KernelLoader, Loader)

KernelLoader *KernelLoader::create_from_file(const Configuration& cfg)
{
	if (cfg.universal_machine) {
		return new UMLoader(cfg.guest_kernel);
	}
	
	uint8_t buffer[128];
	
	int fd = open(cfg.guest_kernel.c_str(), O_RDONLY);
	if (fd < 0) {
		ERROR << CONTEXT(KernelLoader) << "Unable to open file";
		return NULL;
	}
	
	if (read(fd, buffer, 128) <= 0) {
		ERROR << CONTEXT(KernelLoader) << "Unable to read file";
		close(fd);
		return NULL;
	}
	
	close(fd);
	
	if (ZImageLoader::match(buffer)) {
		return new ZImageLoader(cfg.guest_kernel);
	} else if (ELFLoader::match(buffer)) {
		return new ELFLoader(cfg.guest_kernel);
	} else if (ARM64Loader::match(buffer)) {
		return new ARM64Loader(cfg.guest_kernel);
	} else {
		ERROR << CONTEXT(KernelLoader) << "Unable to detect file type";
		return NULL;
	}
}
