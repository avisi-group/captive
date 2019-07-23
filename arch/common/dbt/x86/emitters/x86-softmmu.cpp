/* SPDX-License-Identifier: MIT */

#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_SOFT

#include <mmu/strategy/strategy.h>
#include <smc/strategy.h>
#include <cpu.h>
#include <dbt/x86/x86-emitter.h>
#include <dbt/x86/x86-context.h>
#include <dbt/x86/x86-block.h>
#include <dbt/x86/x86-value.h>
#include <dbt/dbt.h>
#include <dbt/el/context.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/formatter.h>
#include <printf.h>

using namespace captive::arch::jit::x86;
using namespace captive::arch::dbt::el;

//#define VALIDATE
//#define USE_FUNCTIONS

template<int TYPE>
extern void *populate_cache_entry(uint64_t);

static void __invalidate_translations()
{
	captive::arch::CPU::get_active_cpu()->invalidate_virtual_mappings_all();
}

uint64_t counter;

#ifdef VALIDATE

template<bool PRIVILEGED, bool WRITE>
static bool ___softmmu_validate(uint64_t gva, uint64_t hva)
{
	uint64_t features;
	asm volatile("mov %%fs:0x60, %0" : "=r"(features));

	if (!!(features & 1) != PRIVILEGED) {
		fatal("mode mismatch\n");
	}

	captive::arch::mmu::AddressTranslationContext atc;
	atc.privilege = PRIVILEGED ? captive::arch::mmu::AddressTranslationPrivilege::SUPERVISOR : captive::arch::mmu::AddressTranslationPrivilege::USER;
	atc.type = WRITE ? captive::arch::mmu::AddressTranslationType::WRITE : captive::arch::mmu::AddressTranslationType::READ;

	if (!captive::arch::mmu::strategy::mmu_strategy.translate(gva, atc)) {
		fatal("ERROR\n");
	}

	if (atc.result != captive::arch::mmu::AddressTranslationResult::OK) {
		printf("FAULT GVA=%p HVA=%p %u\n", gva, hva, atc.result);
		fatal("FAULT\n");
	}

	uint64_t cached_gpa = hva - VM_VIRT_SPLIT - VM_PHYS_GPM_BASE;

	if (cached_gpa != (atc.pa & (~0xfffull))) {
		printf("INVALID: P=%u, W=%u GVA=%p, COMPUTED GPA=%p, COMPUTED HVA=%p, CACHED HVA=%p, CACHED GPA=%p\n", PRIVILEGED, WRITE, gva, atc.pa, VM_VIRT_SPLIT + VM_PHYS_GPM_BASE + atc.pa, hva, cached_gpa);
		return false;
	}

	return true;
}

template<bool PRIVILEGED, bool WRITE>
static void __softmmu_validate(uint64_t gva, uint64_t hva)
{
	if (!___softmmu_validate<PRIVILEGED, WRITE>(gva, hva)) {
		fatal("MISMATCH");
	}
}
#endif

//#ifdef USE_FUNCTIONS

template<int CACHE>
static void *__softmmu_ghp(uint64_t vaddr)
{
	uint64_t page_index = vaddr >> 12;
	uint64_t entry_index = page_index % SOFTMMU_CACHE_ENTRIES;

	entry_index += SOFTMMU_CACHE_ENTRIES * CACHE;

	captive::arch::mmu::strategy::softmmu_cache_entry *cache;
	asm volatile("rdgsbase %0" : "=r"(cache));

#ifdef VALIDATE
	bool was_hit;
#endif
	if (cache[entry_index].tag != page_index) {
#ifdef VALIDATE
		was_hit = false;
#endif
		return populate_cache_entry<CACHE>(vaddr);
	} else {
#ifdef VALIDATE
		was_hit = true;
#endif
	}

	uint64_t host_pointer = (uint64_t) cache[entry_index].value;

#ifdef VALIDATE
	bool validation_result;
	switch (CACHE) {
	case SOFTMMU_KR_INDEX: validation_result = ___softmmu_validate<true, false>(vaddr, host_pointer);
		break;
	case SOFTMMU_KW_INDEX: validation_result = ___softmmu_validate<true, true>(vaddr, host_pointer);
		break;
	case SOFTMMU_UR_INDEX: validation_result = ___softmmu_validate<false, false>(vaddr, host_pointer);
		break;
	case SOFTMMU_UW_INDEX: validation_result = ___softmmu_validate<false, true>(vaddr, host_pointer);
		break;
	default: __builtin_unreachable();
	}

#if 0
	if (counter > 233557475) {
		if (was_hit) {
			printf("HIT:  ");
		} else {
			printf("MISS: ");
		}

		uint64_t ttbr0 = captive::arch::CPU::get_active_cpu()->ttbr0();
		uint64_t ttbr1 = captive::arch::CPU::get_active_cpu()->ttbr1();
		printf("CACHE NR=%u, VA=%p, page_index=%lx, entry_index=%lx, cache_base=%p, tag=%lx, value=%lx, ttbr=%p %p\n", CACHE, vaddr, page_index, entry_index, cache, cache[entry_index].tag, cache[entry_index].value, ttbr0, ttbr1);
	}
#endif

	counter++;

	if (!validation_result) {
		//printf("CACHE NR=%u, page_index=%lx, entry_index=%lx, cache_base=%p, tag=%lx, value=%lx\n", CACHE, page_index, entry_index, cache, cache[entry_index].tag, cache[entry_index].value);

		printf("%lu\n", counter);
		if (was_hit) {
			printf("HIT:\n");
		} else {
			printf("MISS:\n");
		}

		unsigned long offset = page_index % SOFTMMU_CACHE_ENTRIES;
		for (int i = 0; i < 4; i++) {
			printf("  CACHE %u TAG=%p, VALUE=%p\n", i, cache[(i * SOFTMMU_CACHE_ENTRIES) + offset].tag, cache[(i * SOFTMMU_CACHE_ENTRIES) + offset].value);
		}

		fatal("VALIDATION FAILED\n");
	}
#endif

	host_pointer += vaddr & 0xfffull;

	return(void *) host_pointer;
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
static void ___softmmu_store(uint64_t vaddr, uint64_t data)
{
	void *hostPointer;
	if (PRIVILEGED) {
		hostPointer = __softmmu_ghp<SOFTMMU_KW_INDEX>(vaddr);
	} else {
		hostPointer = __softmmu_ghp<SOFTMMU_UW_INDEX>(vaddr);
	}

	switch (SIZE_IN_BITS) {
	case 8: *((uint8_t *) hostPointer) = (uint8_t) data;
		break;
	case 16: *((uint16_t *) hostPointer) = (uint16_t) data;
		break;
	case 32: *((uint32_t *) hostPointer) = (uint32_t) data;
		break;
	case 64: *((uint64_t *) hostPointer) = (uint64_t) data;
		break;
	}
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
static void ___softmmu_load(uint64_t vaddr, uint64_t *data)
{
	void *hostPointer;
	if (PRIVILEGED) {
		hostPointer = __softmmu_ghp<SOFTMMU_KR_INDEX>(vaddr);
	} else {
		hostPointer = __softmmu_ghp<SOFTMMU_UR_INDEX>(vaddr);
	}

	//printf("LOAD %p %p %p %p\n", vaddr, hostPointer, data, *data);

	switch (SIZE_IN_BITS) {
	case 8: *data = *((uint8_t *) hostPointer);
		break;
	case 16: *data = *((uint16_t *) hostPointer);
		break;
	case 32: *data = *((uint32_t *) hostPointer);
		break;
	case 64: *data = *((uint64_t *) hostPointer);
		break;
	}
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
static void __softmmu_store(uint64_t vaddr, uint64_t data)
{
	if ((vaddr & 0xfff) + (SIZE_IN_BITS / 8) > 0x1000) {
		for (int i = 0; i < (SIZE_IN_BITS >> 3); i++) {
			___softmmu_store<PRIVILEGED, SIZE_IN_BITS>(vaddr + i, (uint64_t) (((uint8_t *) & data)[i]));
		}
	} else {
		___softmmu_store<PRIVILEGED, SIZE_IN_BITS>(vaddr, data);
	}
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
static void __softmmu_load(uint64_t vaddr, uint64_t *data)
{
	if ((vaddr & 0xfff) + (SIZE_IN_BITS / 8) > 0x1000) {
		*data = 0;
		for (int i = 0; i < (SIZE_IN_BITS >> 3); i++) {
			uint64_t tmp;
			___softmmu_load<PRIVILEGED, SIZE_IN_BITS>(vaddr + i, &tmp);

			*data |= (tmp & 0xffull) << (i * 8);
		}
	} else {
		___softmmu_load<PRIVILEGED, SIZE_IN_BITS>(vaddr, data);
	}
}

static void __softmmu_invalidate()
{
	//printf("INVALIDATE %u\n", invalidated_counter++);

	captive::arch::mmu::strategy::mmu_strategy.invalidate();
	__invalidate_translations();
}

static void __softmmu_pgtchange()
{
	//__softmmu_invalidate();
	captive::arch::CPU::get_active_cpu()->invalidate_translations();
}
//#endif

template<>
void X86Emitter::mmu_flush<captive::arch::mmu::strategy::SoftMMUStrategy>(X86Value *addr)
{
#ifdef USE_FUNCTIONS
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_invalidate, 64), Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
#else
	add_instruction(InstructionKind::MOV, Operand::make_constant(0xf0f0f0f0f0f0f0f0, 64), Operand::make_register(X86PhysicalRegisters::A, 64));
	add_instruction(InstructionKind::RDGSBASE, Operand::make_register(X86PhysicalRegisters::DI, 64));
	add_instruction(InstructionKind::CLD);
	add_instruction(InstructionKind::MOV, Operand::make_constant((SOFTMMU_NR_CACHES * SOFTMMU_CACHE_BYTES) / 8, 32), Operand::make_register(X86PhysicalRegisters::C, 32));
	add_instruction(InstructionKind::REP_STOSQ);

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __invalidate_translations, 64), Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
#endif
}

template<>
void X86Emitter::mmu_pgt_change<captive::arch::mmu::strategy::SoftMMUStrategy>()
{
#ifdef USE_FUNCTIONS
	//auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	//add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)__softmmu_pgtchange, 64), Operand::make_register(tmp, 64));
	//add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
#else
	// mmu_flush<captive::arch::mmu::strategy::SoftMMUStrategy>(nullptr);
#endif
}

template<>
void X86Emitter::mmu_asid_change<captive::arch::mmu::strategy::SoftMMUStrategy>(X86Value *asid)
{
#ifdef USE_FUNCTIONS
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_pgtchange, 64), Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
#else
	mmu_flush<captive::arch::mmu::strategy::SoftMMUStrategy>(nullptr);
#endif
}

template<bool PRIVILEGED, int SIZE_IN_BITS> static void __softmmu_store_slow(uint64_t gva, uint64_t value)
{
	void *hva;
	if (PRIVILEGED) {
		hva = populate_cache_entry<SOFTMMU_KW_INDEX>(gva);
	} else {
		hva = populate_cache_entry<SOFTMMU_UW_INDEX>(gva);
	}

	if (((gva & 0xfff) + (SIZE_IN_BITS / 8)) > 0x1000) {
		if (SIZE_IN_BITS == 8) fatal("RUH-ROH");

		for (int i = 0; i < SIZE_IN_BITS / 8; i++) {
			__softmmu_store_slow<PRIVILEGED, 8>(gva + i, value);
			value >>= 8;
		}

		return;
	}

	switch (SIZE_IN_BITS) {
	case 8: *((uint8_t *) hva) = (uint8_t) value;
		break;
	case 16: *((uint16_t *) hva) = (uint16_t) value;
		break;
	case 32: *((uint32_t *) hva) = (uint32_t) value;
		break;
	case 64: *((uint64_t *) hva) = (uint64_t) value;
		break;
	}
}

template<bool PRIVILEGED, int SIZE_IN_BITS> static void __softmmu_load_slow(uint64_t gva, uint64_t *value)
{
	void *hva;
	if (PRIVILEGED) {
		hva = populate_cache_entry<SOFTMMU_KR_INDEX>(gva);
	} else {
		hva = populate_cache_entry<SOFTMMU_UR_INDEX>(gva);
	}

	if (((gva & 0xfff) + (SIZE_IN_BITS / 8)) > 0x1000) {
		if (SIZE_IN_BITS == 8) fatal("RUH-ROH");

		for (int i = 0; i < SIZE_IN_BITS / 8; i++) {
			uint64_t tmp;
			__softmmu_load_slow<PRIVILEGED, 8>(gva + i, &tmp);

			((uint8_t *) value)[i] = (uint8_t) tmp;
		}

		return;
	}

	switch (SIZE_IN_BITS) {
	case 8: *value = (uint64_t)*((uint8_t *) hva);
		break;
	case 16: *value = (uint64_t)*((uint16_t *) hva);
		break;
	case 32: *value = (uint64_t)*((uint32_t *) hva);
		break;
	case 64: *value = (uint64_t)*((uint64_t *) hva);
		break;
	}
}

template<>
void X86Emitter::mmu_store_memory<captive::arch::mmu::strategy::SoftMMUStrategy>(X86Value *addr, X86Value *value)
{
	auto address_register = X86PhysicalRegisters::DI;
	add_mov_auto(addr->as_operand(*this), Operand::make_register(address_register, 64));

	auto value_register = X86PhysicalRegisters::SI;
	add_mov_auto(value->as_operand(*this), Operand::make_register(value_register, value->type().size_in_bits()));

#ifdef USE_FUNCTIONS
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	// DI + SI already set up
	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));
#else
	auto off = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_register(address_register, 64), Operand::make_register(off, 64));
	add_instruction(InstructionKind::AND, Operand::make_constant(0xfff, 32), Operand::make_register(off, 32));

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::LEA, Operand::make_mem(32, 32, off, (value->type().size_in_bits() / 8)), Operand::make_register(tmp, 32));
	add_instruction(InstructionKind::CMP, Operand::make_constant(0x1000, 32), Operand::make_register(tmp, 32));

	auto ja_slow_path = add_instruction(InstructionKind::JA);

	auto pageIndex = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_register(address_register, 64), Operand::make_register(pageIndex, 64));
	add_instruction(InstructionKind::SHR, Operand::make_constant(12, 8), Operand::make_register(pageIndex, 64));

	auto entryOffset = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

	add_instruction(InstructionKind::MOV, Operand::make_register(pageIndex, 32), Operand::make_register(entryOffset, 32));
	add_instruction(InstructionKind::AND, Operand::make_constant((SOFTMMU_CACHE_ENTRIES - 1), 32), Operand::make_register(entryOffset, 32));
	add_instruction(InstructionKind::SHL, Operand::make_constant(4, 8), Operand::make_register(entryOffset, 32));

	// Check tag
	if (_kernel_mode) {
		add_instruction(InstructionKind::CMP, Operand::make_register(pageIndex, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_KW_OFFSET_TAG));
	} else {
		add_instruction(InstructionKind::CMP, Operand::make_register(pageIndex, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_UW_OFFSET_TAG));
	}

	auto jne_slow_path = add_instruction(InstructionKind::JNE);

	// Grab HVA from cache
	auto hva = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_KW_OFFSET_VAL), Operand::make_register(hva, 64));
	} else {
		add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_UW_OFFSET_VAL), Operand::make_register(hva, 64));
	}

	// Store
	add_instruction(InstructionKind::MOV, Operand::make_register(value_register, value->type().size_in_bits()), Operand::make_mem(value->type().size_in_bits(), 64, hva, off, MemoryScale::S1, 0))->make_volatile();

	// Jump over slow path
	auto jmp_eoi = add_instruction(InstructionKind::JMP);

	auto slow_path_label = add_instruction(InstructionKind::LABEL);
	ja_slow_path->set_operand(0, Operand::make_label(slow_path_label));
	jne_slow_path->set_operand(0, Operand::make_label(slow_path_label));

	if (_kernel_mode) {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	// DI + SI already set up
	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));

	auto eoi_label = add_instruction(InstructionKind::LABEL);
	jmp_eoi->set_operand(0, Operand::make_label(eoi_label));

#if 0
	auto jna_cache_check = add_instruction(InstructionKind::JNA);

	// if (offset + size > 0x1000) slow_path

	if (_kernel_mode) {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	// DI + SI already set up
	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));
	auto jmp_eoi_1 = add_instruction(InstructionKind::JMP);

	auto cache_check_label = add_instruction(InstructionKind::LABEL);
	jna_cache_check->set_operand(0, Operand::make_label(cache_check_label));

	// if (cache[bing bong] != tag) slow_path

	auto pageIndex = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_register(address_register, 64), Operand::make_register(pageIndex, 64));
	add_instruction(InstructionKind::SHR, Operand::make_constant(12, 8), Operand::make_register(pageIndex, 64));

	auto entryOffset = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

	add_instruction(InstructionKind::MOV, Operand::make_register(pageIndex, 32), Operand::make_register(entryOffset, 32));
	add_instruction(InstructionKind::AND, Operand::make_constant((SOFTMMU_CACHE_ENTRIES - 1), 32), Operand::make_register(entryOffset, 32));
	add_instruction(InstructionKind::SHL, Operand::make_constant(4, 8), Operand::make_register(entryOffset, 32));

	// Check tag
	if (_kernel_mode) {
		add_instruction(InstructionKind::CMP, Operand::make_register(pageIndex, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_KW_OFFSET_TAG));
	} else {
		add_instruction(InstructionKind::CMP, Operand::make_register(pageIndex, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_UW_OFFSET_TAG));
	}

	auto je_tag_matches = add_instruction(InstructionKind::JE);

	if (_kernel_mode) {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_store_slow<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	// DI + SI already set up
	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));
	auto jmp_eoi_2 = add_instruction(InstructionKind::JMP);

	auto tag_matches_label = add_instruction(InstructionKind::LABEL);
	je_tag_matches->set_operand(0, Operand::make_label(tag_matches_label));

	// Grab HVA from cache
	auto hva = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_KW_OFFSET_VAL), Operand::make_register(hva, 64));
	} else {
		add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_UW_OFFSET_VAL), Operand::make_register(hva, 64));
	}

	// Store
	add_instruction(InstructionKind::MOV, Operand::make_register(value_register, value->type().size_in_bits()), Operand::make_mem(value->type().size_in_bits(), 64, hva, off, MemoryScale::S1, 0))->make_volatile();

	auto eoi_label = add_instruction(InstructionKind::LABEL);
	jmp_eoi_1->set_operand(0, Operand::make_label(eoi_label));
	jmp_eoi_2->set_operand(0, Operand::make_label(eoi_label));
#endif
#endif
}

template<>
Value* X86Emitter::mmu_load_memory<captive::arch::mmu::strategy::SoftMMUStrategy>(X86Value *addr, const Type& type)
{
	auto address_register = X86PhysicalRegisters::DI;
	add_mov_auto(addr->as_operand(*this), Operand::make_register(address_register, 64));

	auto value = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

#ifdef USE_FUNCTIONS
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	add_instruction(InstructionKind::SUB, Operand::make_constant(8, 64), Operand::make_register(X86PhysicalRegisters::SP, 64));
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::SP, 64), Operand::make_register(X86PhysicalRegisters::SI, 64));

	// DI + SI already set up
	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::POP, Operand::make_register(value, 64));

#else
	auto off = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_register(address_register, 64), Operand::make_register(off, 64));
	add_instruction(InstructionKind::AND, Operand::make_constant(0xfff, 32), Operand::make_register(off, 32));

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::LEA, Operand::make_mem(32, 32, off, (type.size_in_bits() / 8)), Operand::make_register(tmp, 32));
	add_instruction(InstructionKind::CMP, Operand::make_constant(0x1000, 32), Operand::make_register(tmp, 32));

	auto jna_cache_check = add_instruction(InstructionKind::JNA);

	// if (offset + size > 0x1000) slow_path

	if (_kernel_mode) {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	add_instruction(InstructionKind::SUB, Operand::make_constant(8, 64), Operand::make_register(X86PhysicalRegisters::SP, 64));
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::SP, 64), Operand::make_register(X86PhysicalRegisters::SI, 64));

	// DI + SI already set up
	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::POP, Operand::make_register(value, 64));

	auto jmp_eoi_1 = add_instruction(InstructionKind::JMP);

	auto cache_check_label = add_instruction(InstructionKind::LABEL);
	jna_cache_check->set_operand(0, Operand::make_label(cache_check_label));

	// if (cache[bing bong] != tag) slow_path

	auto pageIndex = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_register(address_register, 64), Operand::make_register(pageIndex, 64));
	add_instruction(InstructionKind::SHR, Operand::make_constant(12, 8), Operand::make_register(pageIndex, 64));

	auto entryOffset = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

	add_instruction(InstructionKind::MOV, Operand::make_register(pageIndex, 32), Operand::make_register(entryOffset, 32));
	add_instruction(InstructionKind::AND, Operand::make_constant((SOFTMMU_CACHE_ENTRIES - 1), 32), Operand::make_register(entryOffset, 32));
	add_instruction(InstructionKind::SHL, Operand::make_constant(4, 8), Operand::make_register(entryOffset, 32));

	// Check tag
	if (_kernel_mode) {
		add_instruction(InstructionKind::CMP, Operand::make_register(pageIndex, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_KR_OFFSET_TAG));
	} else {
		add_instruction(InstructionKind::CMP, Operand::make_register(pageIndex, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_UR_OFFSET_TAG));
	}

	auto je_tag_matches = add_instruction(InstructionKind::JE);

	if (_kernel_mode) {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __softmmu_load_slow<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	add_instruction(InstructionKind::SUB, Operand::make_constant(8, 64), Operand::make_register(X86PhysicalRegisters::SP, 64));
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::SP, 64), Operand::make_register(X86PhysicalRegisters::SI, 64));

	// DI + SI already set up
	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::POP, Operand::make_register(value, 64));

	auto jmp_eoi_2 = add_instruction(InstructionKind::JMP);

	auto tag_matches_label = add_instruction(InstructionKind::LABEL);
	je_tag_matches->set_operand(0, Operand::make_label(tag_matches_label));

	// Grab HVA from cache
	auto hva = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_KR_OFFSET_VAL), Operand::make_register(hva, 64));
	} else {
		add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::GS, entryOffset, SOFTMMU_UR_OFFSET_VAL), Operand::make_register(hva, 64));
	}

	// Load

	add_instruction(InstructionKind::MOV, Operand::make_mem(type.size_in_bits(), 64, hva, off, MemoryScale::S1, 0), Operand::make_register(value, type.size_in_bits()))->make_volatile();

	auto eoi_label = add_instruction(InstructionKind::LABEL);
	jmp_eoi_1->set_operand(0, Operand::make_label(eoi_label));
	jmp_eoi_2->set_operand(0, Operand::make_label(eoi_label));
#endif

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(value, type.size_in_bits()));
}

#endif

template<>
void X86Emitter::mmu_monitor_acquire<captive::arch::mmu::strategy::SoftMMUStrategy>(X86Value *addr)
{
	add_instruction(InstructionKind::MOV, Operand::make_constant(1, 32), Operand::make_mem(64, 32, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x50));
}

template<>
Value *X86Emitter::mmu_monitor_release<captive::arch::mmu::strategy::SoftMMUStrategy>(X86Value *addr)
{
	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::C, 32), Operand::make_register(X86PhysicalRegisters::C, 32));
	add_instruction(InstructionKind::MOV, Operand::make_constant(1, 32), Operand::make_register(X86PhysicalRegisters::A, 32));
	add_instruction(InstructionKind::CMPXCHG, Operand::make_register(X86PhysicalRegisters::C, 32), Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x50));

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, _x86_context.types().u32(), Operand::make_register(X86PhysicalRegisters::A, 32));
}

template<>
void X86Emitter::mmu_monitor_release_all<captive::arch::mmu::strategy::SoftMMUStrategy>()
{
	add_instruction(InstructionKind::MOV, Operand::make_constant(0, 32), Operand::make_mem(64, 32, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x50));
}
