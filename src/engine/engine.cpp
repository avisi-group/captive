/* SPDX-License-Identifier: MIT */

#include <captive.h>
#include <engine/engine.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>

DECLARE_CONTEXT(Engine)

using namespace captive;
using namespace captive::engine;

Engine::Engine(std::string libfile) : loaded(false), libfile(libfile), _boot_entrypoint(0), _core_entrypoint(0)
{

}

Engine::~Engine()
{
	if (loaded) {
		munmap(lib, lib_size);
		lib = NULL;
	}
}

bool Engine::init()
{
	if (!load()) {
		ERROR << CONTEXT(Engine) << "Unable to load libfile";
		return false;
	}

	return true;
}

bool Engine::install(uint8_t* base)
{
	if (!loaded) {
		ERROR << CONTEXT(Engine) << "Engine has not been initialised";
		return false;
	}

	Elf64_Ehdr *hdr = (Elf64_Ehdr *)lib;

	if (hdr->e_ident[0] != 0x7f || hdr->e_ident[1] != 0x45 || hdr->e_ident[2] != 0x4c || hdr->e_ident[3] != 0x46) {
		ERROR << CONTEXT(Engine) << "Invalid ELF header";
		return false;
	}

	// First, load the program.
	for (int i = 0; i < hdr->e_phnum; i++) {
		Elf64_Phdr *phdr = (Elf64_Phdr *)(lib + hdr->e_phoff + (i * hdr->e_phentsize));

		DEBUG << CONTEXT(Engine) << "Program Header: type=" << phdr->p_type << ", flags=" << phdr->p_flags << ", file offset=" << phdr->p_offset << ", file size=" << phdr->p_filesz << ", paddr=" << std::hex << phdr->p_paddr << ", vaddr=" << phdr->p_vaddr;

		if (phdr->p_type == PT_LOAD) {
			uint64_t offset = phdr->p_paddr;

			DEBUG << CONTEXT(Engine) << "Loading @ " << std::hex << offset << " hva=" << ((uintptr_t)base + offset);
			memcpy(base + offset, lib + phdr->p_offset, phdr->p_filesz);
		}
	}

	// Next, find the string table.
	const char *strtab = NULL;
	for (int i = 0; i < hdr->e_shnum; i++) {
		Elf64_Shdr *shdr = (Elf64_Shdr *)(lib + hdr->e_shoff + (i * hdr->e_shentsize));

		DEBUG << CONTEXT(Engine) << "Section: type=" << shdr->sh_type;

		if (shdr->sh_type == SHT_STRTAB) {
			DEBUG << CONTEXT(Engine) << "Found string table";
			strtab = (const char *)(lib + shdr->sh_offset);
			break;
		}
	}

	if (!strtab) {
		ERROR << CONTEXT(Engine) << "Unable to locate string table";
		return false;
	}

	// Now load the symbol table.
	for (int i = 0; i < hdr->e_shnum; i++) {
		Elf64_Shdr *shdr = (Elf64_Shdr *)(lib + hdr->e_shoff + (i * hdr->e_shentsize));

		DEBUG << CONTEXT(Engine) << "Section: type=" << shdr->sh_type;

		if (shdr->sh_type == SHT_SYMTAB) {
			DEBUG << CONTEXT(Engine) << "Found symbol table";

			Elf64_Sym *symbol = (Elf64_Sym *)(lib + shdr->sh_offset);
			Elf64_Sym *symbol_end = (Elf64_Sym *)(lib + shdr->sh_offset + shdr->sh_size);
			while (symbol < symbol_end) {
				//DEBUG << CONTEXT(Engine) << "Loading symbol " << std::string(&strtab[symbol->st_name]) << " = " << std::hex << symbol->st_value << ENABLE;
				symbols[std::string(&strtab[symbol->st_name])] = (uint64_t)symbol->st_value;
				symbol++;
			}
		}
	}

	_boot_entrypoint = hdr->e_entry;
	_core_entrypoint = 0; //hdr->e_entry;

	return true;
}

bool Engine::load()
{
	struct stat st;

	int fd = ::open(libfile.c_str(), O_RDONLY);
	if (fd < 0) {
		ERROR << CONTEXT(Engine) << "Unable to open libfile";
		return false;
	}

	if (fstat(fd, &st)) {
		::close(fd);

		ERROR << CONTEXT(Engine) << "Unable to stat libfile";
		return false;
	}

	lib_size = st.st_size;
	lib = (uint8_t *)mmap(NULL, lib_size, PROT_READ, MAP_PRIVATE, fd, 0);
	::close(fd);

	if (lib == MAP_FAILED) {
		ERROR << CONTEXT(Engine) << "Unable to map libfile";
		return false;
	}

	loaded = true;
	return true;
}
