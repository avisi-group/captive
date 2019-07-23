/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <loader/loader.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

using namespace captive::loader;

DECLARE_CONTEXT(Loader)
DECLARE_CHILD_CONTEXT(FileBasedLoader, Loader)

FileBasedLoader::FileBasedLoader(const std::string& filename) : _filename(resolve(filename)), _opened(false), mmap_base(NULL), mmap_size(0)
{

}

std::string FileBasedLoader::resolve(const std::string& filename)
{
	if (filename[0] == '/') return filename;
	
	std::string cwd = std::string(get_current_dir_name());
	if (cwd[cwd.length()-1] == '/') {
		return cwd + filename;
	} else {
		return cwd + "/" + filename;
	}
}

bool FileBasedLoader::open()
{
	struct stat st;

	int fd = ::open(filename().c_str(), O_RDONLY);
	if (fd < 0) {
		ERROR << "Unable to open file";
		return false;
	}

	if (fstat(fd, &st)) {
		::close(fd);

		ERROR << "Unable to stat file";
		return false;
	}

	mmap_size = st.st_size;
	mmap_base = mmap(NULL, mmap_size, PROT_READ, MAP_PRIVATE, fd, 0);
	::close(fd);

	if (mmap_base == MAP_FAILED) {
		ERROR << "Unable to map file";
		return false;
	}

	_opened = true;
	return true;
}

void FileBasedLoader::close()
{
	_opened = false;
	munmap(mmap_base, mmap_size);
}

uint8_t* FileBasedLoader::read(off_t offset, size_t size)
{
	if (!is_open()) {
		WARNING << "Attempted read in file-based loader, when file was not open";
		return NULL;
	}

	return &((uint8_t *)mmap_base)[offset];
}
