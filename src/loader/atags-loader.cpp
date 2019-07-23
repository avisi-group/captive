/* SPDX-License-Identifier: MIT */

#include <loader/atags-loader.h>
#include <loader/initrd-loader.h>
#include <string.h>

using namespace captive::loader;

ATAGsLoader::ATAGsLoader() : _initrd(nullptr)
{
	
}

ATAGsLoader::ATAGsLoader(InitRDLoader& initrd) : _initrd(&initrd)
{
	
}

bool ATAGsLoader::install(uint8_t* gpm)
{
	uint32_t *base = (uint32_t *)(gpm + (uint64_t)base_address());
	
	// CORE
	*base++ = 5;
	*base++ = 0x54410001;
	*base++ = 0;
	*base++ = 4096;
	*base++ = 0;
	
	// MEM
	*base++ = 4;
	*base++ = 0x54410002;
	*base++ = 0x10000000;
	*base++ = 0x00000000;
	
	if (_initrd) {
		// INITRD
		*base++ = 4;
		*base++ = 0x54420005;
		*base++ = _initrd->base_address();	// START
		*base++ = _initrd->size();			// SIZE
	}
	
	// COMMAND-LINE
	const char *cmdline = "earlyprintk=serial console=ttyAMA0 root=/dev/vda1 rw verbose"; // kgdboc=ttyAMA1,115200 kgdbwait";
	int cmdline_size = strlen(cmdline);
	int cmdline_words = (cmdline_size + 5) >> 2;

	*base++ = 2 + cmdline_words;
	*base++ = 0x54410009;
	strcpy((char *)base, cmdline);
	base += cmdline_words;
	
	assert(!((uint64_t)base & 3));
		
	// NONE
	*base++ = 0;
	*base++ = 0;
		
	return true;
}
