/* SPDX-License-Identifier: MIT */

#include <mmu/strategy/strategy.h>
#include <mmu/strategy/softmmu.h>
#include <mmu/strategy/fetch-cache.h>
#include <mmu/host-mmu.h>
#include <mmu/host-vma.h>
#include <mmu/x86-mmu-structures.h>
#include <mmu/guest-mmu.h>
#include <smc/strategy.h>
#include <malloc/page-allocator.h>
#include <mmu.h>
#include <cpu.h>
#include <printf.h>
#include <safepoint.h>

extern safepoint_t cpu_safepoint;

using namespace captive::arch;
using namespace captive::arch::malloc;
using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

bool SoftMMUStrategy::initialise()
{
	_cache = (softmmu_cache_entry *) page_alloc.alloc_pages(SOFTMMU_CACHE_PAGES * SOFTMMU_NR_CACHES);
	invalidate();

	printf("initialising soft-mmu strategy %gs=%p\n", _cache);
	set_gs_gpm();

	return true;
}

void SoftMMUStrategy::set_gs_cache()
{
	__wrmsr(0xc0000101, (uint64_t) _cache); // GS Base
	__wrmsr(0xc0000102, (uint64_t) _cache); // Kernel GS Base
}

void SoftMMUStrategy::set_gs_gpm()
{
	__wrmsr(0xc0000101, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE));
	__wrmsr(0xc0000102, (uint64_t) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE)); // Kernel GS Base
}

template<bool PRIVILEGED>
void SoftMMUStrategy::invalidate()
{
	for (unsigned long i = 0; i < (SOFTMMU_CACHE_ENTRIES * SOFTMMU_NR_CACHES); i++) {
		_cache[i].tag = 0xf0f0f0f0f0f0f0f0;
	}

	fetch_cache.invalidate();
}

template void SoftMMUStrategy::invalidate<true>();
template void SoftMMUStrategy::invalidate<false>();

template<bool PRIVILEGED>
void SoftMMUStrategy::invalidate_gva(gva_t va)
{
	uint64_t cacheEntryIndex = (va >> 12) % SOFTMMU_CACHE_ENTRIES;

	for (unsigned long i = 0; i < SOFTMMU_NR_CACHES; i++) {
		_cache[cacheEntryIndex + (SOFTMMU_CACHE_ENTRIES * i)].tag = 0xf0f0f0f0f0f0f0f0;
	}
}

template void SoftMMUStrategy::invalidate_gva<true>(gva_t);
template void SoftMMUStrategy::invalidate_gva<false>(gva_t);

bool SoftMMUStrategy::translate(gva_t va, AddressTranslationContext& ctx)
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
		fatal("SoftMMUStrategy: TRANSLATE FAILED\n");
	}

	if (ctx.type == AddressTranslationType::FETCH && ctx.result == AddressTranslationResult::OK) {
		fetch_cache.update(va, ctx.pa);
	}

	return true;
}

void SoftMMUStrategy::handle_page_fault(const PageFaultContext& context)
{
	printf("FAULT: %p (%x)\n", context.va, context.reason);
	fatal("SOFTMMU");
}

#if 1

template<int TYPE>
void *populate_cache_entry(uint64_t virtual_address)
{
	uint64_t page_index = virtual_address >> 12ull;
	uint64_t entry_index = (page_index % SOFTMMU_CACHE_ENTRIES);
	uint64_t entry_offset = entry_index << 4;

	AddressTranslationContext ctx;
	switch (TYPE) {
	case SOFTMMU_KR_INDEX: ctx.privilege = AddressTranslationPrivilege::SUPERVISOR;
		ctx.type = AddressTranslationType::READ;
		break;
	case SOFTMMU_KW_INDEX: ctx.privilege = AddressTranslationPrivilege::SUPERVISOR;
		ctx.type = AddressTranslationType::WRITE;
		break;
	case SOFTMMU_UR_INDEX: ctx.privilege = AddressTranslationPrivilege::USER;
		ctx.type = AddressTranslationType::READ;
		break;
	case SOFTMMU_UW_INDEX: ctx.privilege = AddressTranslationPrivilege::USER;
		ctx.type = AddressTranslationType::WRITE;
		break;
	default: fatal("INVALID TXLN TYPE %u\n", TYPE);
	}

	if (!guest_mmu.translate(virtual_address, ctx)) {
		fatal("MMU TXLN FAILED\n");
	}

	if (ctx.result == AddressTranslationResult::FAULT) {
		if (!captive::arch::CPU::get_active_cpu()->handle_mmu_fault(virtual_address, ctx)) {
			fatal("guest machine failed to handle mmu fault\n");
		}

		//for (unsigned long cache_index = 0; cache_index < SOFTMMU_NR_CACHES; cache_index++) {
		//asm volatile("movq %0, %%gs:(%1)" :: "r"(0xf0f0f0f0f0f0f0f0), "r"(entry_offset));
		//entry_offset += SOFTMMU_CACHE_BYTES;
		//}

		restore_safepoint(&cpu_safepoint, 1);
		__builtin_unreachable();
	}

	uint64_t pa = (VM_PHYS_GPM_BASE + VM_VIRT_SPLIT) + (ctx.pa & ~0xfffull);

	entry_offset += SOFTMMU_CACHE_BYTES * TYPE;

	//printf("POPULATING %u @ %p %p=%p\n", TYPE, entry_offset, virtual_address, pa);

#ifdef VIA_GS
	asm volatile("movq %0, %%gs:8(%1)" ::"r"(pa), "r"(entry_offset)); // VAL
	asm volatile("movq %0, %%gs:0(%1)" ::"r"(page_index), "r"(entry_offset)); // TAG
#else
	uintptr_t cache_base;
	asm volatile("rdgsbase %0" : "=r"(cache_base));
	((softmmu_cache_entry *) (cache_base + entry_offset))->tag = page_index;
	((softmmu_cache_entry *) (cache_base + entry_offset))->value = pa;
#endif

	return(void *) (pa | (virtual_address & 0xfffull));
}
#else
extern bool __force_trace;

template<int TYPE>
void populate_cache_entry(uint64_t virtual_address)
{
	uint64_t page_index = virtual_address >> 12ull;
	uint64_t entry_index = (page_index % SOFTMMU_CACHE_ENTRIES);
	entry_index += SOFTMMU_CACHE_ENTRIES * TYPE;

	AddressTranslationContext ctx;
	bzero(&ctx, sizeof(ctx));

	switch (TYPE) {
	case SOFTMMU_KR_INDEX: ctx.privilege = AddressTranslationPrivilege::SUPERVISOR;
		ctx.type = AddressTranslationType::READ;
		break;
	case SOFTMMU_KW_INDEX: ctx.privilege = AddressTranslationPrivilege::SUPERVISOR;
		ctx.type = AddressTranslationType::WRITE;
		break;
	case SOFTMMU_UR_INDEX: ctx.privilege = AddressTranslationPrivilege::USER;
		ctx.type = AddressTranslationType::READ;
		break;
	case SOFTMMU_UW_INDEX: ctx.privilege = AddressTranslationPrivilege::USER;
		ctx.type = AddressTranslationType::WRITE;
		break;
	default: fatal("INVALID TXLN TYPE %u\n", TYPE);
	}

	if (!guest_mmu.translate(virtual_address, ctx)) {
		fatal("MMU TXLN FAILED\n");
	}

	if (ctx.result == AddressTranslationResult::FAULT) {
		/*printf("ZZZ %p\n", read_pc());
		if ((read_pc() & 0xfffull) == 0xc70ull) {
			printf("ENABLING TRACING\n");
			__force_trace = true;
		}*/

		if (!captive::arch::CPU::get_active_cpu()->handle_mmu_fault(virtual_address, ctx)) {
			fatal("guest machine failed to handle mmu fault\n");
		}

		softmmu_cache_entry *cache;
		asm volatile("rdgsbase %0" : "=r"(cache));

		uint64_t base_index = page_index % SOFTMMU_CACHE_ENTRIES;
		for (int i = 0; i < 4; i++) {
			cache[base_index + (SOFTMMU_CACHE_ENTRIES * i)].tag = 0xf0f0f0f0f0f0f0f0;
		}

		//captive::arch::mmu::strategy::mmu_strategy.invalidate();
		//captive::arch::CPU::get_active_cpu()->invalidate_virtual_mappings_all();

		restore_safepoint(&cpu_safepoint, 1);
		__builtin_unreachable();
	}

	uint64_t hva = (VM_PHYS_GPM_BASE + VM_VIRT_SPLIT) + (ctx.pa & ~0xfffull);

	softmmu_cache_entry *cache;
	asm volatile("rdgsbase %0" : "=r"(cache));

	/*uint32_t ir;
	{
		AddressTranslationContext pctx;
		pctx.privilege = AddressTranslationPrivilege::SUPERVISOR;
		pctx.type = AddressTranslationType::READ;
		guest_mmu.translate(read_pc(), pctx);
		
		ir = *(uint32_t *)guest_phys_to_vm_virt(pctx.pa);
	}*/

	cache[entry_index].a = read_pc();

	uint64_t icount;
	asm volatile("mov %%fs:0x38, %0" : "=r"(icount));
	cache[entry_index].b = icount;

	//virtual_address >= 0xffff000000000000ull ? captive::arch::CPU::get_active_cpu()->ttbr1() : captive::arch::CPU::get_active_cpu()->ttbr0();

	cache[entry_index].tag = page_index;
	cache[entry_index].value = hva;

#if 1
	for (unsigned long i = 0; i < 4; i++) {
		if (i == TYPE) continue;

		auto *entry = &cache[(i * SOFTMMU_CACHE_ENTRIES) + (page_index % SOFTMMU_CACHE_ENTRIES)];
		if (entry->tag == cache[entry_index].tag && entry->value != cache[entry_index].value) {
			printf("CACHE INCOHERENCY - ACCESS TYPE: %u, VA=%p, PA=%p\n", TYPE, virtual_address, ctx.pa);

			for (unsigned long j = 0; j < 4; j++) {
				unsigned long idx = (j * SOFTMMU_CACHE_ENTRIES) + (page_index % SOFTMMU_CACHE_ENTRIES);

				auto *centry = &cache[idx];
				printf("  CACHE %u, IDX=%03x, A=%p, B=%p, TAG=%p, VAL=%p\n", j, idx, centry->a, centry->b, centry->tag, centry->value);
			}

			fatal("PLONK\n");
		}
	}
#endif
}
#endif

template void *populate_cache_entry<0>(uint64_t);
template void *populate_cache_entry<1>(uint64_t);
template void *populate_cache_entry<2>(uint64_t);
template void *populate_cache_entry<3>(uint64_t);
