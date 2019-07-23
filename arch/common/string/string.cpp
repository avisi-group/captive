/* SPDX-License-Identifier: MIT */

#include <string.h>
#include <malloc/malloc.h>

int strlen(const char *str)
{
	int n = 0;
	while (*str++ != '\0') n++;
	return n;
}

char *strcpy(char *dest, const char *src)
{
	char *orig = dest;

	while (*src) {
		*dest++ = *src++;
	}

	*dest = '\0';
	return orig;
}

char *strncpy(char *dest, const char *src, int n)
{
	char *orig = dest;

	while (*src && --n > 0) {
		*dest++ = *src++;
	}

	*dest = '\0';
	return orig;
}

char *strcat(char *dest, const char *src)
{
	char *orig = dest;

	while (*dest) dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';
	return orig;
}

char *strncat(char *dest, const char *src, int n)
{
	char *orig = dest;

	while (*dest) dest++;

	while (*src && --n > 0)
		*dest++ = *src++;

	*dest = '\0';

	return orig;
}

char *strdup(const char *str)
{
	char *newstr = (char*) captive::arch::malloc::data_alloc.alloc(strlen(str) + 1);
	strcpy(newstr, str);
	return newstr;
}
