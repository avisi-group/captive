/* SPDX-License-Identifier: MIT */

#if CONFIG_MMU_STRATEGY == MMU_STRATEGY_PGTSW

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
#include <printf.h>
#include <mmu.h>
#include <mmu/host-mmu.h>
#include <cpu.h>
#include <safepoint.h>

//#define INLINE_ZONE_CHANGE

extern safepoint_t cpu_safepoint;

using namespace captive::arch::jit::x86;
using namespace captive::arch::mmu;
using namespace captive::arch::mmu::strategy;

#ifndef INLINE_ZONE_CHANGE

template<bool PRIVILEGED>
static void __change_zone(uint8_t zone)
{
	/*uint8_t old_zone;
	asm volatile("movb %%fs:0x68, %0" : "=r"(old_zone));
	
	printf("OLD ZONE %u, NEW ZONE: %u\n", old_zone, zone);*/

	asm volatile("incq %fs:0x38");

	HostVMA *new_zone = mmu_strategy.get_zone(zone);
	host_mmu.activate_vma<PRIVILEGED>(*new_zone);

	asm volatile("movb %0, %%fs:0x68" ::"r"(zone));
}
#endif

template<bool PRIVILEGED>
static void __pgtswitch_flush()
{
	mmu_strategy.invalidate<PRIVILEGED>();
}

template<bool PRIVILEGED>
static void __pgtswitch_flush_va(gva_t va)
{
	mmu_strategy.invalidate_gva<PRIVILEGED>(va);
}

template<bool PRIVILEGED>
static uint64_t __pgtswitch_form_address(uint64_t address)
{
	uint8_t zone = (address >> 47) & 3;
	uint8_t current_zone;
	asm volatile("movb %%fs:0x68, %0" : "=r"(current_zone));

	//printf("X %u:%u\n", current_zone, zone);
	if (current_zone != zone) {
		HostVMA *new_zone = mmu_strategy.get_zone(zone);
		host_mmu.activate_vma<PRIVILEGED>(*new_zone);
		asm volatile("movb %0, %%fs:0x68" ::"r"(zone));
	}

	return address & 0x7fffffffffff;
}

template<bool PRIVILEGED>
static void __pgtswitch_store(uint64_t address, uint64_t data, uint8_t size)
{
	uint64_t host_address = __pgtswitch_form_address<PRIVILEGED>(address);

	//printf("STORE %p:%p %lx:%u\n", address, host_address, data, size);

	switch (size) {
	case 8: *((uint8_t *) host_address) = data;
		break;
	case 16: *((uint16_t *) host_address) = data;
		break;
	case 32: *((uint32_t *) host_address) = data;
		break;
	case 64: *((uint64_t *) host_address) = data;
		break;
	}
}

template<bool PRIVILEGED>
static void __pgtswitch_load(uint64_t address, uint64_t *data, uint8_t size)
{
	uint64_t host_address = __pgtswitch_form_address<PRIVILEGED>(address);

	//printf("LOAD %p:%p :%u\n", address, host_address, size);

	switch (size) {
	case 8: *data = *((uint8_t *) host_address);
		break;
	case 16: *data = *((uint16_t *) host_address);
		break;
	case 32: *data = *((uint32_t *) host_address);
		break;
	case 64: *data = *((uint64_t *) host_address);
		break;
	}
}

template<>
void X86Emitter::mmu_flush<captive::arch::mmu::strategy::PageTableSwitchStrategy < false >> (X86Value *addr)
{
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);

	if (addr != nullptr) {
		add_mov_auto(addr->as_operand(*this), Operand::make_register(X86PhysicalRegisters::DI, 64));

		if (_kernel_mode) {
			add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __pgtswitch_flush_va<true>, 64), Operand::make_register(tmp, 64));
		} else {
			add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __pgtswitch_flush_va<false>, 64), Operand::make_register(tmp, 64));
		}

		add_instruction(InstructionKind::CALL1, Operand::make_register(tmp, 64));
	} else {
		if (_kernel_mode) {
			add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __pgtswitch_flush<true>, 64), Operand::make_register(tmp, 64));
		} else {
			add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __pgtswitch_flush<false>, 64), Operand::make_register(tmp, 64));
		}

		add_instruction(InstructionKind::CALL0, Operand::make_register(tmp, 64));
	}
}

template<>
void X86Emitter::mmu_pgt_change<captive::arch::mmu::strategy::PageTableSwitchStrategy < false >> ()
{
	// mmu_flush<captive::arch::mmu::strategy::PageTableSwitchStrategy>(nullptr);
}

template<>
void X86Emitter::mmu_asid_change<captive::arch::mmu::strategy::PageTableSwitchStrategy < false >> (X86Value *asid)
{
	mmu_flush<captive::arch::mmu::strategy::PageTableSwitchStrategy < false >> (nullptr);
}

#if 0

template<>
void X86Emitter::mmu_store_memory<captive::arch::mmu::strategy::PageTableSwitchStrategy>(X86Value *addr, X86Value *value)
{
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __pgtswitch_store<true>, 64), Operand::make_register(tmp, 64));
	} else {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __pgtswitch_store<false>, 64), Operand::make_register(tmp, 64));
	}

	auto addr_reg = X86PhysicalRegisters::DI;
	add_mov_auto(addr->as_operand(*this), Operand::make_register(addr_reg, 64));

	auto value_reg = X86PhysicalRegisters::SI;
	add_mov_auto(value->as_operand(*this), Operand::make_register(value_reg, value->type().size_in_bits()));

	add_instruction(InstructionKind::MOV, Operand::make_constant(value->type().size_in_bits(), 8), Operand::make_register(X86PhysicalRegisters::D, 8));
	add_instruction(InstructionKind::CALL3, Operand::make_register(tmp, 64));
}

template<>
dbt::el::Value* X86Emitter::mmu_load_memory<captive::arch::mmu::strategy::PageTableSwitchStrategy>(X86Value *addr, const dbt::el::Type& type)
{
	auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	if (_kernel_mode) {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __pgtswitch_load<true>, 64), Operand::make_register(tmp, 64));
	} else {
		add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __pgtswitch_load<false>, 64), Operand::make_register(tmp, 64));
	}

	auto addr_reg = X86PhysicalRegisters::DI;
	add_mov_auto(addr->as_operand(*this), Operand::make_register(addr_reg, 64));

	auto value_ptr_reg = X86PhysicalRegisters::SI;
	add_instruction(InstructionKind::SUB, Operand::make_constant(8, 64), Operand::make_register(X86PhysicalRegisters::SP, 64));
	add_instruction(InstructionKind::MOV, Operand::make_register(X86PhysicalRegisters::SP, 64), Operand::make_register(value_ptr_reg, 64));

	add_instruction(InstructionKind::MOV, Operand::make_constant(type.size_in_bits(), 8), Operand::make_register(X86PhysicalRegisters::D, 8));
	add_instruction(InstructionKind::CALL3, Operand::make_register(tmp, 64));

	auto value = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
	add_instruction(InstructionKind::POP, Operand::make_register(value, 64));

	return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(value, type.size_in_bits()));
}

#else

template<>
void X86Emitter::mmu_store_memory<captive::arch::mmu::strategy::PageTableSwitchStrategy < false >> (X86Value *addr, X86Value *value)
{
	if (_no_mmu) {
		auto address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_mov_auto(addr->as_operand(*this), Operand::make_register(address, 64));

		add_instruction(InstructionKind::MOV, value->as_operand(*this), Operand::make_mem(value->type().size_in_bits(), 64, X86PhysicalRegisters::GS, address, 0))->make_volatile();
	} else {
		auto address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_mov_auto(addr->as_operand(*this), Operand::make_register(address, 64));

#ifdef INLINE_ZONE_CHANGE
		auto zone = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
#else
		auto zone = X86PhysicalRegisters::DI;
#endif

		add_instruction(InstructionKind::MOV, Operand::make_register(address, 64), Operand::make_register(zone, 64));
		add_instruction(InstructionKind::SHR, Operand::make_constant(47, 8), Operand::make_register(zone, 64));
		add_instruction(InstructionKind::AND, Operand::make_constant(0x3, 32), Operand::make_register(zone, 32));

		// %fs:68 - mode
		add_instruction(InstructionKind::CMP, Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x68), Operand::make_register(zone, 8));
		auto jmp_zone_equal = add_instruction(InstructionKind::JE);

#ifdef INLINE_ZONE_CHANGE
		// Lookup zone cr3
		if (_kernel_mode) {
			auto cr3 = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, zone, MemoryScale::S8, 0x70), Operand::make_register(cr3, 64));
			add_instruction(InstructionKind::MOV, Operand::make_register(cr3, 64), Operand::make_register(X86PhysicalRegisters::CR3, 64));
		} else {
			add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, zone, MemoryScale::S8, 0x70), Operand::make_register(X86PhysicalRegisters::DI, 64));
			add_instruction(InstructionKind::INT, Operand::make_constant(0x61, 8));
		}

		// Write new zone
		add_instruction(InstructionKind::MOV, Operand::make_register(zone, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x68));
#else
		if (_kernel_mode) {
			auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __change_zone<true>, 64), Operand::make_register(tmp, 64));
			add_instruction(InstructionKind::CALL1, Operand::make_register(tmp, 64));
		} else {
			auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __change_zone<false>, 64), Operand::make_register(tmp, 64));
			add_instruction(InstructionKind::CALL1, Operand::make_register(tmp, 64));
		}
#endif

		auto zone_equal_label = add_instruction(InstructionKind::LABEL);
		jmp_zone_equal->set_operand(0, Operand::make_label(zone_equal_label));

		auto mask = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffffffff, 64), Operand::make_register(mask, 64));
		add_instruction(InstructionKind::AND, Operand::make_register(mask, 64), Operand::make_register(address, 64));

		add_instruction(InstructionKind::INC, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x40))->make_volatile();

		add_instruction(InstructionKind::MOV, value->as_operand(*this), Operand::make_mem(value->type().size_in_bits(), 64, address, 0))->make_volatile();
	}
}

template<>
dbt::el::Value* X86Emitter::mmu_load_memory<captive::arch::mmu::strategy::PageTableSwitchStrategy < false >> (X86Value *addr, const dbt::el::Type& type)
{
	if (_no_mmu) {
		auto address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_mov_auto(addr->as_operand(*this), Operand::make_register(address, 64));

		auto value = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_mem(type.size_in_bits(), 64, X86PhysicalRegisters::GS, address, 0), Operand::make_register(value, type.size_in_bits()))->make_volatile();

		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(value, type.size_in_bits()));
	} else {
		auto address = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_mov_auto(addr->as_operand(*this), Operand::make_register(address, 64));

#ifdef INLINE_ZONE_CHANGE
		auto zone = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
#else
		auto zone = X86PhysicalRegisters::DI;
#endif

		add_instruction(InstructionKind::MOV, Operand::make_register(address, 64), Operand::make_register(zone, 64));
		add_instruction(InstructionKind::SHR, Operand::make_constant(47, 8), Operand::make_register(zone, 64));
		add_instruction(InstructionKind::AND, Operand::make_constant(0x3, 32), Operand::make_register(zone, 32));

		// %fs:68 - mode
		add_instruction(InstructionKind::CMP, Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x68), Operand::make_register(zone, 8));
		auto jmp_zone_equal = add_instruction(InstructionKind::JE);

#ifdef INLINE_ZONE_CHANGE
		// Lookup zone cr3
		if (_kernel_mode) {
			auto cr3 = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, zone, MemoryScale::S8, 0x70), Operand::make_register(cr3, 64));
			add_instruction(InstructionKind::MOV, Operand::make_register(cr3, 64), Operand::make_register(X86PhysicalRegisters::CR3, 64));
		} else {
			add_instruction(InstructionKind::MOV, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, zone, MemoryScale::S8, 0x70), Operand::make_register(X86PhysicalRegisters::DI, 64));
			add_instruction(InstructionKind::INT, Operand::make_constant(0x61, 8));
		}

		// Write new zone
		add_instruction(InstructionKind::MOV, Operand::make_register(zone, 8), Operand::make_mem(8, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x68));
#else
		if (_kernel_mode) {
			auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __change_zone<true>, 64), Operand::make_register(tmp, 64));
			add_instruction(InstructionKind::CALL1, Operand::make_register(tmp, 64));
		} else {
			auto tmp = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
			add_instruction(InstructionKind::MOV, Operand::make_constant((uint64_t) __change_zone<false>, 64), Operand::make_register(tmp, 64));
			add_instruction(InstructionKind::CALL1, Operand::make_register(tmp, 64));
		}
#endif  
		auto zone_equal_label = add_instruction(InstructionKind::LABEL);
		jmp_zone_equal->set_operand(0, Operand::make_label(zone_equal_label));

		auto mask = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_constant(0x7fffffffffff, 64), Operand::make_register(mask, 64));
		add_instruction(InstructionKind::AND, Operand::make_register(mask, 64), Operand::make_register(address, 64));

		add_instruction(InstructionKind::INC, Operand::make_mem(64, 64, X86PhysicalRegisters::FS, X86PhysicalRegisters::RIZ, 0x40))->make_volatile();

		auto value = vreg_allocator().alloc_vreg(X86RegisterClasses::GENERAL_PURPOSE);
		add_instruction(InstructionKind::MOV, Operand::make_mem(type.size_in_bits(), 64, address, 0), Operand::make_register(value, type.size_in_bits()))->make_volatile();

		return _x86_context.support().alloc_obj<X86Operand>(_x86_context, type, Operand::make_register(value, type.size_in_bits()));
	}
}
#endif

#endif