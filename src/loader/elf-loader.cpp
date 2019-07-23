/* SPDX-License-Identifier: MIT */

#include <loader/elf-loader.h>
#include <captive.h>

#include <elf.h>

USE_CONTEXT(Loader);
DECLARE_CHILD_CONTEXT(ELF, Loader);

using namespace captive::loader;

ELFLoader::ELFLoader(std::string filename) : FileBasedLoader(filename), _entrypoint(0), _base_address(0), _end_of_loaded_data(0), _phdr_ent_size(0), _phdr_cnt(0), _phdr_addr(0)
{

}

gpa_t ELFLoader::entrypoint() const
{
	return _entrypoint;
}

bool ELFLoader::requires_device_tree() const
{
	return false;
}

bool ELFLoader::install(uint8_t* gpm)
{
	// Attempt to open the file.
	if (!open()) {
		ERROR << CONTEXT(ELF) << "Unable to open file";
		return false;
	}

	const Elf32_Ehdr *hdr = (const Elf32_Ehdr *)read(0, sizeof(Elf32_Ehdr));

	if (hdr->e_ident[EI_MAG0] != ELFMAG0 || hdr->e_ident[EI_MAG1] != ELFMAG1 || hdr->e_ident[EI_MAG2] != ELFMAG2 || hdr->e_ident[EI_MAG3] != ELFMAG3) {
		close();

		ERROR << CONTEXT(ELF) << "Invalid ELF magic number";
		return false;
	}

	if (hdr->e_ident[EI_CLASS] == ELFCLASS32) {
		return install32(gpm);
	} else {
		return install64(gpm);
	}
}

bool ELFLoader::match(const uint8_t* buffer)
{
	const Elf32_Ehdr *hdr = (const Elf32_Ehdr *)buffer;
	
	if (hdr->e_ident[EI_MAG0] != ELFMAG0 || hdr->e_ident[EI_MAG1] != ELFMAG1 || hdr->e_ident[EI_MAG2] != ELFMAG2 || hdr->e_ident[EI_MAG3] != ELFMAG3) {
		return false;
	}
	
	return true;
}

bool ELFLoader::install32(uint8_t* gpm)
{
	const Elf32_Ehdr *hdr = (const Elf32_Ehdr *)read(0, sizeof(Elf32_Ehdr));

	if (hdr->e_ident[EI_DATA] != ELFDATA2LSB) {
		close();

		ERROR << CONTEXT(ELF) << "Invalid ELF data encoding";
		return false;
	}

	if (hdr->e_ident[EI_VERSION] != EV_CURRENT) {
		close();

		ERROR << CONTEXT(ELF) << "Invalid ELF version";
		return false;
	}

	const uint8_t *elf_base = (const uint8_t *)read(0, size());
	for (int i = 0; i < hdr->e_phnum; i++) {
		Elf32_Phdr *phdr = (Elf32_Phdr *)(elf_base + hdr->e_phoff + (i * hdr->e_phentsize));

		DEBUG << CONTEXT(ELF) << "Program Header: type=" << phdr->p_type << ", flags=" << phdr->p_flags << ", file offset=" << phdr->p_offset << ", file size=" << phdr->p_filesz << ", paddr=" << std::hex << phdr->p_paddr << ", vaddr=" << phdr->p_vaddr;

		if (phdr->p_type == PT_LOAD || phdr->p_type == PT_PHDR) {
			DEBUG << CONTEXT(ELF) << "Loading @ " << std::hex << phdr->p_vaddr << " to " << (uint64_t)(gpm + phdr->p_vaddr) << ENABLE;
			memcpy(gpm + phdr->p_vaddr, elf_base + phdr->p_offset, phdr->p_filesz);
		}
		
		Elf32_Addr end_vaddr = (phdr->p_vaddr + phdr->p_memsz);
		if (end_vaddr > _end_of_loaded_data) {
			_end_of_loaded_data = end_vaddr;
		}
	}
	
	_phdr_ent_size = hdr->e_phentsize;
	_phdr_cnt = hdr->e_phnum;

	_entrypoint = (gpa_t)hdr->e_entry;
	DEBUG << CONTEXT(ELF) << "Entry Point @ " << std::hex << _entrypoint;
	
	close();

	return true;
}

bool ELFLoader::install64(uint8_t* gpm)
{
	const Elf64_Ehdr *hdr = (const Elf64_Ehdr *)read(0, sizeof(Elf64_Ehdr));

	if (hdr->e_ident[EI_DATA] != ELFDATA2LSB) {
		close();

		ERROR << CONTEXT(ELF) << "Invalid ELF data encoding";
		return false;
	}

	if (hdr->e_ident[EI_VERSION] != EV_CURRENT) {
		close();

		ERROR << CONTEXT(ELF) << "Invalid ELF version";
		return false;
	}
	
	const uint8_t *elf_base = (const uint8_t *)read(0, size());
	for (int i = 0; i < hdr->e_phnum; i++) {
		Elf64_Phdr *phdr = (Elf64_Phdr *)(elf_base + hdr->e_phoff + (i * hdr->e_phentsize));

		DEBUG << CONTEXT(ELF) << "Program Header: type=" << phdr->p_type << ", flags=" << phdr->p_flags << ", file offset=" << phdr->p_offset << ", file size=" << phdr->p_filesz << ", paddr=" << std::hex << phdr->p_paddr << ", vaddr=" << phdr->p_vaddr;

		if (phdr->p_type == PT_LOAD) {
			DEBUG << CONTEXT(ELF) << "Loading @ " << std::hex << phdr->p_vaddr << " to " << (uint64_t)(gpm + phdr->p_vaddr);
			memcpy(gpm + phdr->p_vaddr, elf_base + phdr->p_offset, phdr->p_filesz);
			
			if (_base_address == 0 || phdr->p_vaddr < _base_address) {
				_base_address = phdr->p_vaddr;
			}
		} else if (phdr->p_type == PT_PHDR) {
			_phdr_addr = phdr->p_vaddr;
		}
		
		Elf64_Addr end_vaddr = (phdr->p_vaddr + phdr->p_memsz);
		if (end_vaddr > _end_of_loaded_data) {
			_end_of_loaded_data = end_vaddr;
		}
	}
	
	_phdr_ent_size = hdr->e_phentsize;
	_phdr_cnt = hdr->e_phnum;
	
	fprintf(stderr, "elf: base=0x%lx, ent-size=%x, ent-cnt=%x\n", _base_address, _phdr_ent_size, _phdr_cnt);

	_entrypoint = (gpa_t)hdr->e_entry;
	DEBUG << CONTEXT(ELF) << "Entry Point @ " << std::hex << _entrypoint;
	
	close();
	
	return true;
}
