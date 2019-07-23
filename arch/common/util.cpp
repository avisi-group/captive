/* SPDX-License-Identifier: MIT */

#include <define.h>
#include <printf.h>
#include <malloc/malloc.h>
#include <new>

void *operator new(size_t size){
	return captive::arch::malloc::data_alloc.alloc(size);
}

void *operator new(size_t size, std::align_val_t av){
	uint64_t mask = ((uint64_t) av - 1ull);
	uintptr_t ptr = (uintptr_t) captive::arch::malloc::data_alloc.alloc(size + (size_t) av);
	if ((ptr & mask) == 0) return(void *) ptr;
	else return(void *) ((ptr + (uint64_t) av) & ~mask);
}

void *operator new[](size_t size)
{
	return captive::arch::malloc::data_alloc.calloc(1, size);
}

void operator delete(void *p)
{
	captive::arch::malloc::data_alloc.free(p);
}

void operator delete(void *p, size_t sz)
{
	captive::arch::malloc::data_alloc.free(p);
}

extern "C" void __cxa_pure_virtual()
{
	printf("PURE VIRTUAL PAL\n");
	abort();
}

extern "C" {
	void *__dso_handle;
}

extern "C" int __cxa_atexit(void (*destructor) (void *), void *arg, void *dso)
{
	return 0;
}

extern "C" void __cxa_finalize(void *f)
{

}

typedef signed int si_int;
typedef unsigned int su_int;
typedef signed long long di_int;
typedef unsigned long long du_int;

extern "C" si_int __popcountdi2(di_int a)
{
	du_int x2 = (du_int) a;
	x2 = x2 - ((x2 >> 1) & 0x5555555555555555uLL);
	/* Every 2 bits holds the sum of every pair of bits (32) */
	x2 = ((x2 >> 2) & 0x3333333333333333uLL) + (x2 & 0x3333333333333333uLL);
	/* Every 4 bits holds the sum of every 4-set of bits (3 significant bits) (16) */
	x2 = (x2 + (x2 >> 4)) & 0x0F0F0F0F0F0F0F0FuLL;
	/* Every 8 bits holds the sum of every 8-set of bits (4 significant bits) (8) */
	su_int x = (su_int) (x2 + (x2 >> 32));
	/* The lower 32 bits hold four 16 bit sums (5 significant bits). */
	/*   Upper 32 bits are garbage */
	x = x + (x >> 16);
	/* The lower 16 bits hold two 32 bit sums (6 significant bits). */
	/*   Upper 16 bits are garbage */
	return(x + (x >> 8)) & 0x0000007F; /* (7 significant bits) */
}

namespace std {

	void __throw_out_of_range(const char *message)
	{
		printf("out of range exception: %s\n", message);
		abort();
	}
}
