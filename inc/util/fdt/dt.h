/* SPDX-License-Identifier: MIT */
#pragma once

#include <string>
#include <vector>
#include <map>
#include <define.h>

namespace captive {
	namespace util {
		namespace fdt {

			struct DeviceTreeHeader {
				be32_t magic;
				be32_t totalsize;
				be32_t off_dt_struct;
				be32_t off_dt_strings;
				be32_t off_mem_rsvmap;
				be32_t version;
				be32_t last_comp_version;
				be32_t boot_cpuid_phys;
				be32_t size_dt_strings;
				be32_t size_dt_struct;
			} __packed;

			struct DeviceTreeStructure {
			} __packed;

			struct DeviceTreeStrings {

				std::string lookup(uint32_t off) const
				{
					const char *base = (const char *) this;
					return std::string(base + off);
				}
			} __packed;

			struct DeviceTreeReservedEntry {
				be64_t address;
				be64_t size;
			} __packed;

			struct DeviceTreeNodeProperty {
				be32_t len;
				be32_t nameoff;
			} __packed;

			class DeviceTree;

			class DeviceTreeNode {
				friend class DeviceTree;
			public:

				DeviceTreeNode(const std::string& name) : _parent(nullptr), _name(name)
				{
				}

				~DeviceTreeNode()
				{
					for (auto child : _children) {
						delete child;
					}

					_children.clear();
				}

				DeviceTreeNode *parent() const
				{
					return _parent;
				}

				const std::string& name() const
				{
					return _name;
				}

				const std::vector<DeviceTreeNode *>& children() const
				{
					return _children;
				}
				//				const std::map<std::string, std::string>& properties() const { return _properties; }

				const auto& properties() const
				{
					return _properties;
				}

				void add_property(const std::string& name, const std::vector<char>& value)
				{
					_properties[name] = value;
				}

				void add_child(DeviceTreeNode& child)
				{
					if (child._parent == nullptr) {
						child._parent = this;
						_children.push_back(&child);
					}
				}

			private:
				DeviceTreeNode *_parent;
				std::string _name;
				std::vector<DeviceTreeNode *> _children;
				std::map<std::string, std::vector<char>> _properties;
			};

			class DeviceTree {
			public:
				DeviceTree();
				~DeviceTree();

				bool load(const void *buffer, size_t size);
				bool save(void *buffer, size_t& size) const;

				static bool from_file(const std::string& filename, DeviceTree& dt);

				void dump() const;

			private:
				DeviceTree(const DeviceTree& dt);
				DeviceTree(const DeviceTree&& dt);

				bool build_tree(const DeviceTreeHeader* hdr, const DeviceTreeStructure* structure, const DeviceTreeStrings* strings, const DeviceTreeReservedEntry* reserved_entries);
				void dump_node(const DeviceTreeNode& node, int indent) const;

				DeviceTreeNode *_root;
			};
		}
	}
}
