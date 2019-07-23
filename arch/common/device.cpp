/* SPDX-License-Identifier: MIT */

#include <device.h>
#include <shmem.h>
#include <cpu.h>
#include <x86/decode.h>

using namespace captive::arch;

Device::Device(Environment& env) : _env(env)
{

}

Device::~Device()
{

}

CoreDevice::CoreDevice(Environment& env) : Device(env)
{

}

CoreDevice::~CoreDevice()
{

}

#define FAST_DEVICE_ACCESS

#ifdef FAST_DEVICE_ACCESS

void captive::arch::mmio_device_read(gpa_t pa, uint8_t size, uint64_t& value)
{
	__local_irq_disable();

	captive::PerGuestData *pgd = CPU::get_active_cpu_data()->guest_data;

	pgd->fast_device.address = pa;
	pgd->fast_device.size = size;

	pgd->fast_device.operation = FAST_DEV_OP_READ;

	captive::lock::barrier_wait_nopause(&pgd->fast_device.hypervisor_barrier, FAST_DEV_GUEST_TID);
	captive::lock::barrier_wait_nopause(&pgd->fast_device.guest_barrier, FAST_DEV_GUEST_TID);

	value = pgd->fast_device.value;

	__local_irq_enable();
}

void captive::arch::mmio_device_write(gpa_t pa, uint8_t size, uint64_t value)
{
	__local_irq_disable();

	captive::PerGuestData *pgd = CPU::get_active_cpu_data()->guest_data;

	pgd->fast_device.address = pa;
	pgd->fast_device.size = size;
	pgd->fast_device.value = value;

	pgd->fast_device.operation = FAST_DEV_OP_WRITE;

	captive::lock::barrier_wait_nopause(&pgd->fast_device.hypervisor_barrier, FAST_DEV_GUEST_TID);
	captive::lock::barrier_wait_nopause(&pgd->fast_device.guest_barrier, FAST_DEV_GUEST_TID);

	__local_irq_enable();
}

void captive::arch::mmio_device_dummy(gpa_t pa, uint8_t size, uint64_t value)
{
	fatal("XXX");
}

#else

static inline void __out32(uint32_t address, uint32_t value)
{
	asm volatile("outl %0, $0xf0\n" ::"a"(value), "d"(address));
}

static inline void __out16(uint32_t address, uint16_t value)
{
	asm volatile("outw %0, $0xf0\n" ::"a"(value), "d"(address));
}

static inline void __out8(uint32_t address, uint8_t value)
{
	asm volatile("outb %0, $0xf0\n" ::"a"(value), "d"(address));
}

static inline uint32_t __in32(uint32_t address)
{
	uint32_t value;
	asm volatile("inl $0xf0, %0\n" : "=a"(value) : "d"(address));
	return value;
}

static inline uint16_t __in16(uint32_t address)
{
	uint16_t value;
	asm volatile("inw $0xf0, %0\n" : "=a"(value) : "d"(address));
	return value;
}

static inline uint8_t __in8(uint32_t address)
{
	uint8_t value;
	asm volatile("inb $0xf0, %0\n" : "=a"(value) : "d"(address));
	return value;
}

void captive::arch::mmio_device_read(gpa_t pa, uint8_t size, uint64_t& value)
{
	switch (size) {
	case 1: value = __in8(pa);
		break;
	case 2: value = __in16(pa);
		break;
	case 4: value = __in32(pa);
		break;
	default: abort();
	}
}

void captive::arch::mmio_device_write(gpa_t pa, uint8_t size, uint64_t value)
{
	switch (size) {
	case 1: __out8(pa, value);
		break;
	case 2: __out16(pa, value);
		break;
	case 4: __out32(pa, value);
		break;
	default: abort();
	}
}
#endif
