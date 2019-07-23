/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <map>

namespace captive {
	namespace engine {

		class Engine {
		public:
			Engine(std::string libfile);
			virtual ~Engine();

			bool init();
			bool install(uint8_t *base);

			uint64_t boot_entrypoint() const
			{
				return _boot_entrypoint;
			}

			uint64_t core_entrypoint() const
			{
				return _core_entrypoint;
			}

			inline bool lookup_symbol(std::string name, uint64_t& symbol)
			{
				auto sym = symbols.find(name);
				if (sym == symbols.end())
					return false;

				symbol = sym->second;
				return true;
			}

			inline bool resolve_symbol(uint64_t symbol, std::string& name)
			{
				for (auto sym : symbols) {
					if (sym.second == symbol) {
						name = sym.first;
						return true;
					}
				}

				return false;
			}

		private:
			bool load();
			bool loaded;

			std::string libfile;
			uint8_t *lib;
			size_t lib_size;

			uint64_t _boot_entrypoint, _core_entrypoint;

			std::map<std::string, uint64_t> symbols;
		};
	}
}
