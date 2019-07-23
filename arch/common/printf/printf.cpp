/* SPDX-License-Identifier: MIT */

#include <define.h>
#include <printf.h>
#include <shmem.h>
#include <cpu.h>
#include <mmu/guest-mmu.h>

static inline void putch(char c)
{
	asm volatile("out %0, $0xfe\n" : : "a"(c));
}

static char *fast_buffer;
static int fast_buffer_size;

void printf_init(uintptr_t base_address, size_t size)
{
	fast_buffer = (char *) base_address;
	fast_buffer_size = size;
}

int printf(const char *fmt, ...)
{
	if (!fast_buffer) {
		char buffer[0x1000];

		int rc;
		va_list args;

		va_start(args, fmt);
		rc = vsnprintf(buffer, 0x1000, fmt, args);
		va_end(args);

		for (int i = 0; i < 0x1000; i++) {
			if (buffer[i] == 0) {
				break;
			}

			putch(buffer[i]);
		}

		return rc;
	} else {
		int rc;
		va_list args;

		va_start(args, fmt);
		*fast_buffer = '\0';
		rc = vsnprintf(fast_buffer, fast_buffer_size, fmt, args);
		va_end(args);

		asm volatile("out %0, $0xfe\n" : : "a"(0));
		return rc;
	}
}

int fatal(const char *fmt, ...)
{
	char buffer[0x1000];
	va_list args;

	va_start(args, fmt);
	int rc = vsnprintf(buffer, 0x1000, fmt, args);
	va_end(args);

	buffer[rc] = 0;

	printf("fatal: %s", buffer);
	abort();
}

void dump_instruction_at(gva_t va)
{
	captive::arch::mmu::AddressTranslationContext atc;
	atc.privilege = captive::arch::mmu::AddressTranslationPrivilege::SUPERVISOR;
	atc.type = captive::arch::mmu::AddressTranslationType::READ;

	if (!captive::arch::mmu::guest_mmu.translate(va, atc)) {
		fatal("VPC->PPC RESOLUTUION FAILED\n");
	}

	if (atc.result != captive::arch::mmu::AddressTranslationResult::OK) {
		fatal("VPC->PPC RESOLUTION FAULTED\n");
	}

	uint32_t ir = *(uint32_t *) guest_phys_to_vm_virt(atc.pa);
	printf("INSTRUCTION @ virt=%016x, phys=%016x, ir=%08x\n", va, atc.pa, ir);
	printf("> %s\n", captive::arch::CPU::get_active_cpu()->disassemble_address(0, va));
}

void dump_current_instruction()
{
	dump_instruction_at(read_pc());
}
