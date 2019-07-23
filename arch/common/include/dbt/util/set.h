/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/support.h>
#include <dbt/util/map.h>

namespace captive {
	namespace arch {

		namespace dbt {
			namespace util {

				template<typename TElement>
				class Set {
				public:

					Set(Support& support) : _map(support)
					{
					}

					void insert(const TElement& element)
					{
						_map.put(element, true);
					}

					void remove(const TElement& element)
					{
						_map.remove(element);
					}

					bool contains(const TElement& element)
					{
						return _map.contains(element);
					}

					//private:
					Map<TElement, bool> _map;
				};
			}
		}
	}
}
