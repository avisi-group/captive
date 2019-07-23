/* SPDX-License-Identifier: MIT */

#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_TVAS

#include <mmu/strategy/strategy.h>
#include <smc/strategy.h>
#include <dbt/x86/x86-emitter.h>
#include <dbt/x86/x86-context.h>
#include <dbt/x86/x86-block.h>
#include <dbt/x86/x86-value.h>
#include <dbt/dbt.h>
#include <dbt/el/context.h>
#include <dbt/mc/x86/instruction.h>
#include <dbt/mc/x86/formatter.h>
#include <x86/rdtsc-timer.h>
#include <printf.h>
#include <mmu.h>
#include <cpu.h>
#include <safepoint.h>

extern safepoint_t cpu_safepoint;

using namespace captive::arch::jit::x86;
using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

//#define USE_FUNCTIONS

template<bool PRIVILEGED>
static void __flush_mmu()
{
	//printf("FLUSH MMU\n");
	mmu_strategy.invalidate<PRIVILEGED>();
}

template<bool PRIVILEGED>
static void __pgt_change()
{
	//__flush_mmu<PRIVILEGED>();
}

template<bool PRIVILEGED>
static void __asid_change()
{
	//printf("ASID CHANGE\n");
	__flush_mmu<PRIVILEGED>();
}

template<>
void X86Emitter::mmu_flush<captive::arch::mmu::strategy::TVAS>(X86Value *addr)
{
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __flush_mmu<true>, 64), Operand::make_register(tmp, 64));
	} else {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __flush_mmu<false>, 64), Operand::make_register(tmp, 64));
	}
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
}

template<>
void X86Emitter::mmu_pgt_change<captive::arch::mmu::strategy::TVAS>()
{
	/*auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)__pgt_change<true>, 64), Operand::make_register(tmp, 64));
	} else {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)__pgt_change<false>, 64), Operand::make_register(tmp, 64));
	}
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));*/
}

template<>
void X86Emitter::mmu_asid_change<captive::arch::mmu::strategy::TVAS>(X86Value *asid)
{
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __asid_change<true>, 64), Operand::make_register(tmp, 64));
	} else {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __asid_change<false>, 64), Operand::make_register(tmp, 64));
	}
	add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
}

#ifdef USE_FUNCTIONS

template<bool PRIVILEGED, bool STORE>
static void *__tvas_resolve(uint64_t address)
{
	uint64_t guest_segment_index = address >> TVAS_SEGMENT_BITS;
	uint64_t host_segment_index = guest_segment_index % TVAS_NR_CACHE_ENTRIES;

	uint64_t cache_tag;
	asm volatile("movq %%gs:(,%1,8), %0" : "=r"(cache_tag) : "r"(host_segment_index));

	if (cache_tag != guest_segment_index) {
		asm volatile("movq %0, %%gs:(,%1,8)" ::"r"(guest_segment_index), "r"(host_segment_index));
		mmu_strategy.invalidate_segment<PRIVILEGED>(host_segment_index);
	}

	//printf("ADDR=%p, GSI=%lx, HSI=%lx, TAG=%lx, PTR=%p\n", address, guest_segment_index, host_segment_index, cache_tag, ((TVAS_SEGMENT_BYTES * host_segment_index) | (address & TVAS_SEGMENT_MASK)));

	return(void *) ((TVAS_SEGMENT_BYTES * host_segment_index) | (address & TVAS_SEGMENT_MASK));
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
static void __tvas_store(uint64_t address, uint64_t value)
{
	//uint64_t start = captive::arch::x86::rdtsc_timer.count();
	void *ptr = __tvas_resolve<PRIVILEGED, true>(address);
	//uint64_t end = captive::arch::x86::rdtsc_timer.count();

	switch (SIZE_IN_BITS) {
	case 8: *((uint8_t *) ptr) = value;
		break;
	case 16: *((uint16_t *) ptr) = value;
		break;
	case 32: *((uint32_t *) ptr) = value;
		break;
	case 64: *((uint64_t *) ptr) = value;
		break;
	}

	//captive::arch::CPU::get_active_cpu()->cpu_data().insns_executed += captive::arch::x86::rdtsc_timer.ticks_to_nsec(end - start);
}

template<bool PRIVILEGED, int SIZE_IN_BITS>
void __tvas_load(uint64_t address, uint64_t *value)
{
	//uint64_t start = captive::arch::x86::rdtsc_timer.count();
	void *ptr = __tvas_resolve<PRIVILEGED, false>(address);
	//uint64_t end = captive::arch::x86::rdtsc_timer.count();

	switch (SIZE_IN_BITS) {
	case 8: *value = (uint64_t)*((uint8_t *) ptr);
		break;
	case 16: *value = (uint64_t)*((uint16_t *) ptr);
		break;
	case 32: *value = (uint64_t)*((uint32_t *) ptr);
		break;
	case 64: *value = (uint64_t)*((uint64_t *) ptr);
		break;
	}
	//captive::arch::CPU::get_active_cpu()->cpu_data().insns_executed += captive::arch::x86::rdtsc_timer.ticks_to_nsec(end - start);
}
#else

template<bool PRIVILEGED>
static void __tvas_invalidate_segment(uint64_t host_segment_index, uint64_t ptr)
{
	//printf("INV %p, ADDR %p\n", host_segment_index, ptr);

	mmu_strategy.invalidate_segment<PRIVILEGED>(host_segment_index);
}

#endif

#ifndef USE_FUNCTIONS

X86PhysicalRegister X86Emitter::tvas_compute_host_ptr(X86Value *addr)
{
	//increment_pca();

	// Calculate Guest Segment Index
	auto gsi = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	auto hptr = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_mov_auto(addr->as_operand(*this), Operand::make_register(gsi, 64));
	add_instruction(InstructionKind::MOV, Operand::make_register(gsi, 64), Operand::make_register(hptr, 64));
	add_instruction(InstructionKind::SHR, Operand::make_constant(TVAS_SEGMENT_BITS, 8), Operand::make_register(gsi, 64));

	// Calculate Host Segment Index
	auto hsi = X86PhysicalRegisters::DI; //vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_register(gsi, 64), Operand::make_register(hsi, 64));
	add_instruction(InstructionKind::AND, Operand::make_constant((TVAS_NR_CACHE_ENTRIES - 1), 32), Operand::make_register(hsi, 32));

	// Read and compare cache tag
	add_instruction(InstructionKind::CMP, Operand::make_mem(64, 64, X86PhysicalRegisters::GS, X86PhysicalRegisters::RIZ, hsi, MemoryScale::S8, 0), Operand::make_register(gsi, 64));
	//add_instruction(InstructionKind::CMPXCHG, Operand::make_register(gsi, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::GS, X86PhysicalRegisters::RIZ, hsi, MemoryScale::S8, 0));
	auto je_over_invalidate = add_instruction(InstructionKind::JE);

	// Update cache tag and call invalidate segment
	add_instruction(InstructionKind::MOV, Operand::make_register(gsi, 64), Operand::make_mem(64, 64, X86PhysicalRegisters::GS, X86PhysicalRegisters::RIZ, hsi, MemoryScale::S8, 0));
	//add_instruction(InstructionKind::MOV, Operand::make_register(hsi, 64), Operand::make_register(X86PhysicalRegisters::DI, 64));

	//add_mov_auto(addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::SI, 64));

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_invalidate_segment<true>, 64), Operand::make_register(tmp, 64));
		//add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)___tvas_invalidate_segment_priv, 64), Operand::make_register(tmp, 64));
	} else {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_invalidate_segment<false>, 64), Operand::make_register(tmp, 64));
		//add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t)___tvas_invalidate_segment_nonpriv, 64), Operand::make_register(tmp, 64));
	}
	add_instruction(InstructionKind::CALL1, Operand::make_register(tmp, 64));
	//increment_pcb();

	auto after_invalidate = add_instruction(InstructionKind::LABEL);
	je_over_invalidate->set_operand(0, Operand::make_label(after_invalidate));

	// Calculate Host PTR  ((TVAS_SEGMENT_BYTES * host_segment_index) | (address & TVAS_SEGMENT_MASK));
	add_instruction(InstructionKind::AND, Operand::make_constant(TVAS_SEGMENT_MASK, 32), Operand::make_register(hptr, 32));

	add_instruction(InstructionKind::SHL, Operand::make_constant(TVAS_SEGMENT_BITS, 8), Operand::make_register(hsi, 64));
	add_instruction(InstructionKind::OR, Operand::make_register(hsi, 64), Operand::make_register(hptr, 64));

	return hptr;
}
#endif

template<>
void X86Emitter::mmu_store_memory<captive::arch::mmu::strategy::TVAS>(X86Value *addr, X86Value *value)
{
#ifdef USE_FUNCTIONS
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::DI, 64));
	add_instruction(InstructionKind::MOV, value->as_operand(*this), Operand::make_register(X86PhysicalRegisters::SI, value->type().size_in_bits()));

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_store<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_store<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_store<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_store<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		default: assert(false);
		}
	} else {
		switch (value->type().size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_store<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_store<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_store<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_store<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		default: assert(false);
		}
	}

	add_instruction(InstructionKind::CALL, Operand::make_register(tmp, 64));
#else
	auto hptr = tvas_compute_host_ptr(addr);
	add_instruction(InstructionKind::MOV, value->as_operand(*this), Operand::make_mem(value->type().size_in_bits(), 64, hptr, 0));
#endif
}

template<>
dbt::el::Value* X86Emitter::mmu_load_memory<captive::arch::mmu::strategy::TVAS>(X86Value *addr, const dbt::el::Type& type)
{
#ifdef USE_FUNCTIONS
	add_instruction(InstructionKind::MOV, addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::DI, 64));

	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

	if (_kernel_mode) {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_load<true, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_load<true, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_load<true, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_load<true, 64>, 64), Operand::make_register(tmp, 64));
			break;
		default: assert(false);
		}
	} else {
		switch (type.size_in_bits()) {
		case 8: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_load<false, 8>, 64), Operand::make_register(tmp, 64));
			break;
		case 16: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_load<false, 16>, 64), Operand::make_register(tmp, 64));
			break;
		case 32: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_load<false, 32>, 64), Operand::make_register(tmp, 64));
			break;
		case 64: add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __tvas_load<false, 64>, 64), Operand::make_register(tmp, 64));
			break;
		default: assert(false);
		}
	}

	add_instruction(InstructionKind::SUB, Operand::make_constant(8, 64), Operand::make_register(X86PhysicalRegisters::SP, 64));
	add_instruction(InstructionKind::LEA, Operand::make_mem(64, 64, X86PhysicalRegisters::SP, 0), Operand::make_register(X86PhysicalRegisters::SI, 64));

	add_instruction(InstructionKind::CALL, Operand::make_register(tmp, 64));

	auto val = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::POP, Operand::make_register(val, 64));

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(val, type.size_in_bits()));
#else
	auto hptr = tvas_compute_host_ptr(addr);

	auto val = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::MOV, Operand::make_mem(type.size_in_bits(), 64, hptr, 0), Operand::make_register(val, type.size_in_bits()));

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(val, type.size_in_bits()));
#endif
}

#endif
