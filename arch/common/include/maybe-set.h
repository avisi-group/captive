/* SPDX-License-Identifier: MIT */
#pragma once

#include "small-set.h"

//#include <cstring>
#include <map>

template <typename key_type, typename value_type, int threshold> class maybe_map {
private:
	typedef std::map<key_type, value_type> map_t;

	//	union {
	map_t inner_map;

	struct {
		value_type *inner_array;
		PopulatedSet<threshold> inner_array_populated;
	};
	//	};

#ifndef NDEBUG
	unsigned int expected_count;
#endif

	bool is_array;


public:

	maybe_map(unsigned int expected_count)
#ifndef NDEBUG
	: expected_count(expected_count)
#endif

	{
		if (expected_count >= threshold) is_array = false;
		else is_array = true;

		if (is_array) {
			inner_array = new value_type[expected_count];
			inner_array_populated.clear();
		}
	}

	~maybe_map()
	{
		if (is_array) delete inner_array;
	}

	void insert(key_type key, value_type value)
	{
		assert(key < expected_count);
		if (is_array) {
			inner_array[key] = value;
			inner_array_populated.set(key);
		} else {
			inner_map[key] = value;
		}
	}

	value_type &operator[](key_type key)
	{
		if (is_array) {
			assert(key < expected_count);
			inner_array_populated.set(key);
			return inner_array[key];
		} else {
			return inner_map[key];
		}
	}

	void clear()
	{
		if (is_array) {
			inner_array_populated.clear();
		} else {
			inner_map.clear();
		}
	}

	int count(key_type key)
	{
		if (is_array) {
			assert(key < expected_count);
			return inner_array_populated.get(key);
		} else {
			return inner_map.count(key);
		}
	}

	void erase(key_type key)
	{
		if (is_array) {
			assert(key < expected_count);
			inner_array_populated.clear(key);
		} else {
			inner_map.erase(key);
		}
	}
};
