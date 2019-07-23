/* SPDX-License-Identifier: MIT */

#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_MPK

#include <mmu/strategy/strategy.h>
#include <mmu/guest-mmu.h>
#include <smc/strategy.h>
#include <dbt/x86/x86-emitter.h>
#include <dbt/x86/x86-context.h>
#include <dbt/x86/x86-block.h>
#include <dbt/x86/x86-value.h>
#include <dbt/dbt.h>
#include <dbt/el/context.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/formatter.h>
#include <printf.h>
#include <mmu.h>
#include <cpu.h>
#include <safepoint.h>

extern safepoint_t cpu_safepoint;

using namespace captive::arch::jit::x86;
using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

//#define USE_FUNCTIONS
//#define PROPAGATE_IN_R14
#define USE_TABLE

static void __mpk_flush()
{
	//printf("XXX\n");
	mmu_strategy.invalidate();
	//asm volatile("wrpkru" :: "a"(~3u), "c"(0), "d"(0));
}

template<>
void X86Emitter::mmu_flush<captive::arch::mmu::strategy::MPKStrategy>(X86Value *addr)
{
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_flush, 64), Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
}

template<>
void X86Emitter::mmu_pgt_change<captive::arch::mmu::strategy::MPKStrategy>()
{
	//auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	//add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)__invalidate_translations, 64), Operand::make_register(tmp, 64));
	//add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
}

template<>
void X86Emitter::mmu_asid_change<captive::arch::mmu::strategy::MPKStrategy>(X86Value *asid)
{
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_flush, 64), Operand::make_register(tmp, 64));
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
}

#ifdef USE_FUNCTIONS

static inline void __wrpkru(uint32_t pk)
{
	asm volatile("wrpkru" ::"a"(pk), "c"((uint32_t) 0), "d"((uint32_t) 0) : "memory");
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
void __mpk_load(uint64_t address, uint64_t *value)
{
	if (((address & 0xfff) + (SIZE_IN_BITS / 8)) > 0x1000) {
		if (SIZE_IN_BITS == 8) fatal("RUH-ROH");
		for (int i = 0; i < (SIZE_IN_BITS / 8); i++) {
			uint64_t tmp;
			__mpk_load<PRIVILEGED, 8>(address + i, &tmp);

			((uint8_t *) value)[i] = (uint8_t) tmp;
		}
	} else {
		uint64_t masked_address = address & 0x7fffffffffff;
		uint32_t segment = ((address >> 47) & 3u) + (PRIVILEGED ? 1u : 5u);
		uint32_t pkru = ~((3u << ((segment) * 2u)) | 3u);

		//printf("LOAD: ADDR=%p, MASK=%p, SEG=%u, PKRU=%x\n", address, masked_address, segment, pkru);
		__wrpkru(pkru);

		switch (SIZE_IN_BITS) {
		case 8: *value = *(uint8_t *) masked_address;
			break;
		case 16: *value = *(uint16_t *) masked_address;
			break;
		case 32: *value = *(uint32_t *) masked_address;
			break;
		case 64: *value = *(uint64_t *) masked_address;
			break;
		}
	}
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
static void __mpk_store(uint64_t address, uint64_t value)
{
	if (((address & 0xfff) + (SIZE_IN_BITS / 8)) > 0x1000) {
		if (SIZE_IN_BITS == 8) fatal("RUH-ROH");
		for (int i = 0; i < (SIZE_IN_BITS / 8); i++) {
			__mpk_store<PRIVILEGED, 8>(address + i, value);
			value >>= 8;
		}
	} else {
		uint64_t masked_address = address & 0x7fffffffffff;
		uint32_t segment = ((address >> 47) & 3u) + (PRIVILEGED ? 1u : 5u);
		uint32_t pkru = ~((3u << ((segment) * 2u)) | 3u);

		//printf("STORE: ADDR=%p, MASK=%p, SEG=%u, PKRU=%x, PC=%lx\n", address, masked_address, segment, pkru, read_pc());
		__wrpkru(pkru);

		switch (SIZE_IN_BITS) {
		case 8: *((uint8_t *) masked_address) = value;
			break;
		case 16: *((uint16_t *) masked_address) = value;
			break;
		case 32: *((uint32_t *) masked_address) = value;
			break;
		case 64: *((uint64_t *) masked_address) = value;
			break;
		}
	}
}
#endif

static inline uint32_t __rdpkru()
{
	uint32_t pk, edx;
	asm volatile("rdpkru" : "=a"(pk), "=d"(edx) : "c"((uint32_t) 0));

	return pk;
}

static void __mpk_debug()
{
	printf("PKRU=%016x\n", __rdpkru());
}

template<>
void X86Emitter::mmu_store_memory<captive::arch::mmu::strategy::MPKStrategy>(X86Value *addr, X86Value *value)
{
#ifdef USE_FUNCTIONS
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::DI, 64));
	add_instruction(InstructionKind::MOV, value->as_operand(*this), Operand::make_register(X86PhysicalRegisters::SI, value->type().size_in_bits()));

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_store<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_store<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_store<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_store<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_store<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_store<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_store<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_store<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));
#elif defined(USE_TABLE)
	// Compute the MASKED address
	auto masked_address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(masked_address, 64)); // Move address into masked_address

	auto mask = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffffffff, 64), Operand::make_register(mask, 64)); // Prepare mask register

	add_instruction(InstructionKind::AND, Operand::make_register(mask, 64), Operand::make_register(masked_address, 64)); // Apply mask

	// Compute the PKRU
	auto segment = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(segment, 64)); // Move address into segment
	add_instruction(InstructionKind::SHR, Operand::make_constant(47, 8), Operand::make_register(segment, 64)); // Shift right, to get at segment index
	add_instruction(InstructionKind::AND, Operand::make_constant(0x3, 32), Operand::make_register(segment, 32)); // Mask with 3

	// Load PKRU from table
	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::D, 32), Operand::make_register(X86PhysicalRegisters::D, 32)); // Clear D
	add_instruction(InstructionKind::MOV, Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, segment, MemoryScale::S8, 0x70), Operand::make_register(X86PhysicalRegisters::A, 32));
	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::C, 32), Operand::make_register(X86PhysicalRegisters::C, 32)); // Clear C

	add_instruction(InstructionKind::WRPKU);
	add_instruction(InstructionKind::MOV, value->as_operand(*this), Operand::make_mem(value->type().size_in_bits(), 64, masked_address, 0))->make_volatile();

#else
	// Compute the MASKED address
	auto masked_address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(masked_address, 64)); // Move address into masked_address

	auto mask = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffffffff, 64), Operand::make_register(mask, 64)); // Prepare mask register

	add_instruction(InstructionKind::AND, Operand::make_register(mask, 64), Operand::make_register(masked_address, 64)); // Apply mask

	// Compute the PKRU
	auto segment = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(segment, 64)); // Move address into segment
	add_instruction(InstructionKind::SHR, Operand::make_constant(47, 8), Operand::make_register(segment, 64)); // Shift right, to get at segment index

	auto pkru = X86PhysicalRegisters::A;
	add_instruction(InstructionKind::MOV, Operand::make_constant(3, 32), Operand::make_register(pkru, 64)); // Prepare pkey zero
	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::D, 32), Operand::make_register(X86PhysicalRegisters::D, 32)); // Clear D

	add_instruction(InstructionKind::AND, Operand::make_constant(0x3, 32), Operand::make_register(segment, 32));
	add_instruction(InstructionKind::LEA, Operand::make_mem(32, 64, segment, segment, MemoryScale::S1, _kernel_mode ? 2 : 10), Operand::make_register(X86PhysicalRegisters::C, 32));
	add_instruction(InstructionKind::SHL, Operand::make_register(X86PhysicalRegisters::C, 8), Operand::make_register(pkru, 32));
	add_instruction(InstructionKind::OR, Operand::make_constant(3, 32), Operand::make_register(pkru, 32));
	add_instruction(InstructionKind::NOT, Operand::make_register(pkru, 32));

	// Clear C
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::D, 32), Operand::make_register(X86PhysicalRegisters::C, 32));

	add_instruction(InstructionKind::WRPKU);

#ifdef PROPAGATE_IN_R14
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::R14, 64));
#endif

	add_instruction(InstructionKind::MOV, value->as_operand(*this), Operand::make_mem(value->type().size_in_bits(), 64, masked_address, 0))->make_volatile();
#endif
}

template<>
dbt::el::Value* X86Emitter::mmu_load_memory<captive::arch::mmu::strategy::MPKStrategy>(X86Value *addr, const dbt::el::Type& type)
{
#ifdef USE_FUNCTIONS
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::DI, 64));

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_load<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_load<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_load<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_load<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	} else {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_load<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_load<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_load<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __mpk_load<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		}
	}

	add_instruction(InstructionKind::SUB, Operand::make_constant(8, 64), Operand::make_register(X86PhysicalRegisters::SP, 64));
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::SP, 64), Operand::make_register(X86PhysicalRegisters::SI, 64));

	add_instruction(InstructionKind::CALL2, Operand::make_register(tmp, 64));

	auto val = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::POP, Operand::make_register(val, 64));

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(val, type.size_in_bits()));
#elif defined(USE_TABLE)
	// Compute the MASKED address
	auto masked_address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(masked_address, 64)); // Move address into masked_address

	auto mask = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffffffff, 64), Operand::make_register(mask, 64)); // Prepare mask register

	add_instruction(InstructionKind::AND, Operand::make_register(mask, 64), Operand::make_register(masked_address, 64)); // Apply mask

	// Compute the PKRU
	auto segment = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(segment, 64)); // Move address into segment
	add_instruction(InstructionKind::SHR, Operand::make_constant(47, 8), Operand::make_register(segment, 64)); // Shift right, to get at segment index
	add_instruction(InstructionKind::AND, Operand::make_constant(0x3, 32), Operand::make_register(segment, 32)); // Mask with 3

	// Load PKRU from table
	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::D, 32), Operand::make_register(X86PhysicalRegisters::D, 32)); // Clear D
	add_instruction(InstructionKind::MOV, Operand::make_mem(32, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, segment, MemoryScale::S8, 0x70), Operand::make_register(X86PhysicalRegisters::A, 32));
	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::C, 32), Operand::make_register(X86PhysicalRegisters::C, 32)); // Clear C

	add_instruction(InstructionKind::WRPKU);

	auto value = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_mem(type.size_in_bits(), 64, masked_address, 0), Operand::make_register(value, type.size_in_bits()))->make_volatile();

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(value, type.size_in_bits()));
#else

	// Compute the MASKED address
	auto masked_address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(masked_address, 64)); // Move address into masked_address

	auto mask = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffffffff, 64), Operand::make_register(mask, 64)); // Prepare mask register

	add_instruction(InstructionKind::AND, Operand::make_register(mask, 64), Operand::make_register(masked_address, 64)); // Apply mask

	// Compute the PKRU
	auto segment = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(segment, 64)); // Move address into segment
	add_instruction(InstructionKind::SHR, Operand::make_constant(47, 8), Operand::make_register(segment, 64)); // Shift right, to get at segment index

	auto pkru = X86PhysicalRegisters::A;
	add_instruction(InstructionKind::MOV, Operand::make_constant(3, 32), Operand::make_register(pkru, 64)); // Prepare pkey zero
	add_instruction(InstructionKind::XOR, Operand::make_register(X86PhysicalRegisters::D, 32), Operand::make_register(X86PhysicalRegisters::D, 32)); // Clear D

	add_instruction(InstructionKind::AND, Operand::make_constant(0x3, 32), Operand::make_register(segment, 32));
	add_instruction(InstructionKind::LEA, Operand::make_mem(32, 64, segment, segment, MemoryScale::S1, _kernel_mode ? 2 : 10), Operand::make_register(X86PhysicalRegisters::C, 32));
	add_instruction(InstructionKind::SHL, Operand::make_register(X86PhysicalRegisters::C, 8), Operand::make_register(pkru, 32));
	add_instruction(InstructionKind::OR, Operand::make_constant(3, 32), Operand::make_register(pkru, 32));
	add_instruction(InstructionKind::NOT, Operand::make_register(pkru, 32)); // Invert

	// Clear C
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::D, 32), Operand::make_register(X86PhysicalRegisters::C, 32));

	add_instruction(InstructionKind::WRPKU);

#ifdef PROPAGATE_IN_R14
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::R14, 64));
#endif

	auto value = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_mem(type.size_in_bits(), 64, masked_address, 0), Operand::make_register(value, type.size_in_bits()))->make_volatile();

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(value, type.size_in_bits()));
#endif
}

#endif
