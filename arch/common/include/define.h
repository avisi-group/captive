/* SPDX-License-Identifier: MIT */
#pragma once

#include <assert.h>

#define packed __attribute__((packed))

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

#define ARRAY_SIZE(a) (sizeof((a)) / sizeof((a)[0]))

#define PAGE_BITS				12ULL
#define PAGE_SIZE				((uint64_t)(1 << PAGE_BITS))
#define PAGE_OFFSET_MASK		(PAGE_SIZE - 1)
#define PAGE_ADDRESS_MASK		(~(PAGE_SIZE - 1))
#define PAGE_OFFSET_OF(_addr)	(((uint64_t)(_addr)) & PAGE_OFFSET_MASK)
#define PAGE_INDEX_OF(_addr)	(((uint64_t)(_addr)) >> PAGE_BITS)
#define PAGE_ADDRESS_OF(_addr)	(((uint64_t)(_addr)) & PAGE_ADDRESS_MASK)

// SOMETHING ABOUT THIS IS WRONG, and PROBABLY THE GPA/HPA/HVA STUFF BELOW TOO
/*#define PHYS_TO_VIRT_BASE		((uintptr_t)(0xffff800000000000ULL))
#define CODE_PHYS_BASE			((uintptr_t)0)
#define CODE_VIRT_BASE			(PHYS_TO_VIRT_BASE | CODE_PHYS_BASE)
#define GPM_PHYS_BASE			((uintptr_t)0x100000000ULL)
#define GPM_VIRT_BASE			(PHYS_TO_VIRT_BASE | GPM_PHYS_BASE)
#define GPM_VIRT_START			((uintptr_t)0)
#define HEAP_PHYS_BASE			((uintptr_t)0x200000000ULL)
#define HEAP_VIRT_BASE			(PHYS_TO_VIRT_BASE | HEAP_PHYS_BASE)

#define GPA_TO_HPA(_gpa)		((hpa_t)(GPM_PHYS_BASE | (uint32_t)(_gpa)))
#define GPA_TO_HVA(_gpa)		((hva_t)(GPM_VIRT_BASE | (uint32_t)(_gpa)))
#define HPA_TO_HVA(_hpa)		((hva_t)(PHYS_TO_VIRT_BASE | (uintptr_t)(_hpa)))
#define HVA_TO_HPA(_hva)		((hpa_t)((uintptr_t)(_hva) & ~0xfff000000000ULL))*/

#define VM_PHYS_CODE_BASE			0ULL
#define VM_CODE_SIZE				0x100000000ULL
#define VM_PHYS_HEAP_BASE			0x100000000ULL
#define VM_HEAP_SIZE				0x100000000ULL
#define VM_PHYS_GPM_BASE			0x200000000ULL

#define VM_PHYS_GUEST_DATA			0x1000ULL
#define VM_PHYS_CPU_DATA			0x2000ULL
#define VM_PHYS_PRINTF_BUFFER		0x3000ULL
#define VM_PHYS_GDT					0x4000ULL
#define VM_PHYS_TSS					0x4100ULL
#define VM_PHYS_KSTACK				0x5000ULL

#define VM_PHYS_PAGE_TABLES			0x10000ULL
#define VM_PHYS_PML4_0				VM_PHYS_PAGE_TABLES
#define VM_PHYS_PML4_1				(VM_PHYS_PML4_0 + 0x1000ULL)
#define VM_INIT_CR3					VM_PHYS_PML4_0

#define VM_VIRT_SPLIT				0xffff800000000000ULL
#define VM_VIRT_KERNEL				0xffffffff80000000ULL

#define ALIGN(_addr, _alignment) ((_addr) + ((_alignment) - ((_addr) % (_alignment))))

typedef unsigned long size_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int int64_t;

typedef unsigned long uintptr_t;
typedef signed long intptr_t;
typedef unsigned long ptrdiff_t;

typedef uintptr_t hpa_t;
typedef uintptr_t hva_t;

typedef uint64_t gpa_t;
typedef uint64_t gva_t;

#define NULL nullptr

static inline void *vm_phys_to_virt(uintptr_t ptr) {
	return (void *)((uintptr_t)VM_VIRT_SPLIT + ptr);
}

static inline uintptr_t vm_virt_to_phys(void *ptr) {
	if ((uintptr_t)ptr >= VM_VIRT_KERNEL) {
		assert(false);
		__builtin_unreachable();
	} else {
		uintptr_t ret = (uintptr_t)((uintptr_t)ptr - (uintptr_t)VM_VIRT_SPLIT);
		assert(ret < VM_PHYS_GPM_BASE);
		return ret;
	}
}

static inline uintptr_t vm_phys_to_guest_phys(uintptr_t ptr) {
	assert(ptr >= VM_PHYS_GPM_BASE);
	return (uintptr_t)(ptr - VM_PHYS_GPM_BASE);
}

static inline void *guest_phys_to_vm_virt(uintptr_t ptr) {
	return vm_phys_to_virt(VM_PHYS_GPM_BASE + ptr);
}

static inline uint32_t read_gp_u32(uintptr_t ptr) {
	return *(uint32_t *)guest_phys_to_vm_virt(ptr);
}

static inline uintptr_t guest_phys_to_vm_phys(uintptr_t ptr) {
	return VM_PHYS_GPM_BASE + ptr;
}

static inline uintptr_t convert_guest_va_to_local_va(uintptr_t ptr) {
	return ptr & 0x7fffffffffffULL;
}

struct mcontext
{
	uint64_t r15, r14, r13, r12, r11, r10, r9, r8;
	uint64_t rbp;
	uint64_t rsi, rdi, rdx, rcx, rbx, rax;
	uint64_t flags, extra, rip;
} packed;

static inline __attribute__((noreturn)) void abort()
{
	asm volatile("out %0, $0xff\n" : : "a"(0x02));

	for(;;) {
		asm volatile("hlt\n");
	}
	
	__builtin_unreachable();
}

#define unreachable() __builtin_unreachable()
#define should_not_reach() do {  __assertion_failure(__FILE__, __LINE__, "should_not_reach"); __builtin_unreachable(); } while(0);

static inline void __local_irq_enable()
{
	asm volatile("sti\n");
}

static inline void __local_irq_disable()
{
	asm volatile("cli\n");
}

static inline uint64_t __rdtsc()
{
	uint32_t l, h;
	asm volatile("rdtsc" : "=a"(l), "=d"(h));
	
	return (uint64_t)l | ((uint64_t)h) << 32;
}

static inline uint64_t __rdtscp()
{
	uint32_t l, h;
	asm volatile("rdtscp" : "=a"(l), "=d"(h));
	
	return (uint64_t)l | ((uint64_t)h) << 32;
}

static inline void __wrmsr(uint32_t msr_id, uint64_t msr_value)
{
	uint32_t low = msr_value & 0xffffffff;
	uint32_t high = (msr_value >> 32);

	asm volatile ( "rex.b wrmsr" : : "c" (msr_id), "a" (low), "d" (high) );
}

static inline uint64_t __rdmsr(uint32_t msr_id)
{
	uint32_t low, high;

	asm volatile("rex.b rdmsr" : "=a"(low), "=d"(high) : "c" (msr_id));
	return (uint64_t)low | ((uint64_t)high << 32);
}

#include "vector-type.h"
