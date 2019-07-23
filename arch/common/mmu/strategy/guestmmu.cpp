/* SPDX-License-Identifier: MIT */

#include <mmu/strategy/guestmmu.h>
#include <mmu/strategy/strategy.h>
#include <mmu/strategy/fetch-cache.h>
#include <mmu/host-mmu.h>
#include <mmu/host-vma.h>
#include <mmu/guest-mmu.h>
#include <mmu.h>
#include <cpu.h>
#include <printf.h>
#include <safepoint.h>

extern safepoint_t cpu_safepoint;

using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

bool GuestMMUStrategy::initialise()
{
	printf("initialising guest-mmu strategy...\n");

	__wrmsr(0xc0000101, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE));
	__wrmsr(0xc0000102, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE)); // Kernel GS Base

	return true;
}

void GuestMMUStrategy::enable()
{
	_enabled = true;
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate();
}

void GuestMMUStrategy::disable()
{
	_enabled = false;
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
	invalidate();
}

template<bool PRIVILEGED>
void GuestMMUStrategy::invalidate()
{
	fetch_cache.invalidate();
	captive::arch::CPU::get_active_cpu()->invalidate_virtual_mappings_all();
}

template void GuestMMUStrategy::invalidate<true>();

template<bool PRIVILEGED>
void GuestMMUStrategy::invalidate_gva(gva_t)
{
	invalidate();
}

bool GuestMMUStrategy::translate(gva_t va, AddressTranslationContext& ctx)
{
	if (!enabled()) {
		ctx.pa = va;
		ctx.result = AddressTranslationResult::OK;
		return true;
	}

	if (ctx.type == AddressTranslationType::FETCH) {
		if (fetch_cache.translate(va, ctx.pa)) {
			ctx.result = AddressTranslationResult::OK;
			return true;
		}
	}

	if (!guest_mmu.translate(va, ctx)) {
		fatal("GuestMMUStrategy: TRANSLATE FAILED\n");
	}

	if (ctx.type == AddressTranslationType::FETCH && ctx.result == AddressTranslationResult::OK) {
		fetch_cache.update(va, ctx.pa);
	}

	return true;
}

void GuestMMUStrategy::handle_page_fault(const PageFaultContext& context)
{
	printf("FAULT: %p (%x)\n", context.va, context.reason);
	printf("rip=%p\n", context.rip);
	dump_stack();
	fatal("GuestMMUStrategy");
}
