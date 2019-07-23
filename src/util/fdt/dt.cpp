/* SPDX-License-Identifier: MIT */

#include <util/fdt/dt.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

using namespace captive::util::fdt;

DeviceTree::DeviceTree() : _root(nullptr)
{
	
}

DeviceTree::~DeviceTree()
{
	if (_root != nullptr) {
		delete _root;
	}
}

bool DeviceTree::load(const void *buffer, size_t size)
{
	if (size < sizeof(DeviceTreeHeader)) return false;
	
	const DeviceTreeHeader *hdr = (const DeviceTreeHeader *)buffer;

	if (hdr->magic != 0xd00dfeed) {
		fprintf(stderr, "magic error %x\n", (uint32_t)hdr->magic);
		return false;
	}
	
	fprintf(stderr, "magic number %x\n", (uint32_t)hdr->magic);
	
	// --- Sanity Checks --- //
	
	// (1) Check that sizes and offsets are within bounds.
	if (hdr->off_dt_strings < sizeof(hdr) || hdr->off_dt_struct < sizeof(hdr) || hdr->off_mem_rsvmap < sizeof(hdr)) {
		fprintf(stderr, "offsets blank error\n");
		return false;
	}
	
	if (hdr->totalsize != size || hdr->off_dt_struct >= size || hdr->off_dt_strings >= size || hdr->size_dt_strings >= size || hdr->size_dt_struct >= size) {
		fprintf(stderr, "header error %x %u\n", (uint32_t)hdr->totalsize, (uint32_t)size);
		return false;
	}
	
	// (2) Check that reported structures fit correctly.
	if ((hdr->off_dt_strings + hdr->size_dt_strings) > size) {
		fprintf(stderr, "string offset error\n");
		return false;
	}
	
	if (hdr->off_dt_struct + hdr->size_dt_struct > size) {
		fprintf(stderr, "structure offset error\n");
		return false;
	}
	
	// --- Parsing --- //
	return build_tree(
			hdr, 
			(const DeviceTreeStructure *)((uintptr_t)buffer + hdr->off_dt_struct), 
			(const DeviceTreeStrings *)((uintptr_t)buffer + hdr->off_dt_strings),
			(const DeviceTreeReservedEntry *)((uintptr_t)buffer + hdr->off_mem_rsvmap));
}

bool DeviceTree::save(void *buffer, size_t& size) const
{
	DeviceTreeHeader header;
	header.magic = 0xd00dfeed;
	
	// generate_structure()
	
	return false;
}

bool DeviceTree::from_file(const std::string& filename, DeviceTree& dt)
{
	int fd = open(filename.c_str(), O_RDONLY);
	if (fd < 0) {
		return false;
	}
	
	struct stat st;
	if (fstat(fd, &st) < 0) {
		close(fd);
		return false;
	}
	
	void *buffer = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	close(fd);
	
	if (buffer == MAP_FAILED) {
		return false;
	}
	
	bool rc = dt.load(buffer, st.st_size);
	munmap(buffer, st.st_size);
	
	return rc;
}

bool DeviceTree::build_tree(const DeviceTreeHeader* hdr, const DeviceTreeStructure* structure, const DeviceTreeStrings* strings, const DeviceTreeReservedEntry* reserved_entries)
{
	if (_root != nullptr) {
		delete _root;
	}
	
	while (reserved_entries->address != 0 && reserved_entries->size != 0) {
		fprintf(stderr, "reserved entry: %lx %lx\n", (uint64_t)reserved_entries->address, (uint64_t)reserved_entries->size);
	}
	
	_root = new DeviceTreeNode("<root>");

	DeviceTreeNode *current = _root;
	
	be32_t *current_token = (be32_t *)structure;
	while (*current_token != 9) {
		
		switch (*current_token) {
		case 1:		// BEGIN NODE
		{
			current_token++;
			
			const char *name = (const char *)current_token;
			int skip = strlen(name)+1;
			if ((skip % 4) != 0) skip += 4 - (skip % 4);
			
			current_token = (be32_t *)((uintptr_t)current_token + skip);
			
			DeviceTreeNode *new_node = new DeviceTreeNode(name);
			current->add_child(*new_node);
			current = new_node;
			
			break;
		}
			
		case 2:		// END NODE
			current = current->parent();
			if (!current) {
				fprintf(stderr, "nodes out of sync\n");
				return false;
			}
			
			current_token++;
			break;
			
		case 3:		// PROP
		{
			current_token++;

			const DeviceTreeNodeProperty *prop = (const DeviceTreeNodeProperty *)current_token;
			current_token = (be32_t *)((uintptr_t)current_token + sizeof(*prop));
			
			std::vector<char> value(prop->len);
			memcpy(value.data(), current_token, prop->len);
			
			int skip = prop->len;
			if ((skip % 4) != 0) skip += 4 - (skip % 4);
			current_token = (be32_t *)((uintptr_t)current_token + skip);
						
			current->add_property(strings->lookup((uint32_t)prop->nameoff), value);
			break;
		}
		
		case 4:		// NOP
			current_token++;
			break;
		
		default:
			fprintf(stderr, "fdt: warning: unknown token %u\n", (uint32_t)*current_token);
			current_token++;
			break;
		}
	}
	
	return true;
}

void DeviceTree::dump() const
{
	if (_root != nullptr) {
		dump_node(*_root, 0);
	}
}

void DeviceTree::dump_node(const DeviceTreeNode& node, int indent) const
{
	for(int i = 0; i <indent; i++) fprintf(stderr, "  ");
	fprintf(stderr, "NODE: %s\n", node.name().c_str());
	
	for(const auto& prop : node.properties()) {
		for(int i = 0; i <indent; i++) fprintf(stderr, "  ");
		fprintf(stderr, "  %s = %u\n", prop.first.c_str(), (uint32_t)prop.second.size());
	}
	
	for(const auto& child : node.children()) {
		dump_node(*child, indent+1);
	}
}
