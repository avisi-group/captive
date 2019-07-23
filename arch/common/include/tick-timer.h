/* SPDX-License-Identifier: MIT */
#pragma once

#include <vector>

#include <malloc/malloc.h>
#include <string.h>

template<bool enabled>
class tick_timer {
};

template<>
class tick_timer<false> {
public:

	inline void reset()
	{
	}

	inline void tick(const char *tickname = NULL)
	{
	}

	inline void dump(const char *prefix = NULL)
	{
	}
};

template<>
class tick_timer<true> {
public:

	tick_timer()
	{
	}

	~tick_timer()
	{
		for (auto i : names) {
			if (i) captive::arch::malloc::data_alloc.free(i);
		}
	}

	void reset()
	{
		ticks.clear();
		tick("Start");
	}

	void tick(const char *tickname = NULL)
	{
		ticks.push_back(__rdtsc());
		if (tickname)names.push_back(strdup(tickname));
		else names.push_back(NULL);
	}

	void dump(const char *prefix = NULL)
	{
		if (prefix) printf(prefix);
		uint64_t last = ticks[0];
		for (uint32_t i = 1; i < ticks.size(); ++i) {
			uint64_t current = ticks[i];
			if (names[i])printf("%s: %lu\t", names[i], current - last);
			last = current;
		}

		printf("Total: %lu\n", ticks[ticks.size() - 1] - ticks[0]);
	}

private:
	std::vector<uint64_t> ticks;
	std::vector<char *> names;
};
