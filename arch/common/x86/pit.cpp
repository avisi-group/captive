/* SPDX-License-Identifier: MIT */

#include <x86/pit.h>

using namespace captive::arch;
using namespace captive::arch::x86;

void PIT::initialise_oneshot(uint16_t ticks)
{
	uint8_t data;
	asm volatile("inb $0x61, %0" : "=a"(data));
	data &= 0xfd;
	data |= 1;
	asm volatile("outb %0, $0x61" :: "a"(data));

	asm volatile("outb %0, $0x43" :: "a"((uint8_t)0xb2));

	asm volatile("outb %0, $0x42" :: "a"((uint8_t)ticks));
	asm volatile("outb %0, $0x42" :: "a"((uint8_t)((ticks >> 8))));
}

void PIT::start()
{
	uint8_t data;
	asm volatile("inb $0x61, %0" : "=a"(data));
	data &= 0xfe;
	asm volatile("outb %0, $0x61" :: "a"(data));
	data |= 1;
	asm volatile("outb %0, $0x61" :: "a"(data));
}

void PIT::stop() {

}

PIT captive::arch::x86::pit;
