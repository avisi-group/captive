/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/support.h>

namespace captive {
	namespace arch {
		namespace dbt {
			namespace util {

				template<typename TElement>
				class Vector {
				public:

					Vector(Support& support, dbt_size_t capacity = 0) : _support(support), _capacity(0), _size(0), _array(nullptr)
					{
						resize(capacity);
					}

					~Vector()
					{
						if (_array) {
							_support.free(_array, AllocClass::DATA);
						}
					}

					void append(const TElement& elem)
					{
						if (_size >= _capacity) {
							if (_capacity == 0) {
								resize(1);
							} else {
								resize(_capacity * 2);
							}
						}

						_array[_size] = elem;
						_size++;
					}

					dbt_size_t size() const
					{
						return _size;
					}

				private:
					Support& _support;
					dbt_size_t _capacity;
					dbt_size_t _size;
					TElement *_array;

					void resize(dbt_size_t new_capacity)
					{
						if (new_capacity == 0) {
							if (_array) {
								_support.free(_array, AllocClass::DATA);
								_array = nullptr;
							}
						} else {
							_array = (TElement *) _support.realloc(_array, new_capacity * sizeof(TElement), AllocClass::DATA);
						}

						_capacity = new_capacity;

						if (_size > _capacity) {
							_size = _capacity;
						}
					}
				};
			}
		}
	}
}
