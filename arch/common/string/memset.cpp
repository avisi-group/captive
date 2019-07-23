/* SPDX-License-Identifier: MIT */

#include <string.h>

int memcmp(const void *s1, const void *s2, size_t size)
{
	uint8_t *p1 = (uint8_t *) s1;
	uint8_t *p2 = (uint8_t *) s2;

	while (size-- > 0) {
		if (*p1++ != *p2++) return 1;
	}

	return 0;
}
