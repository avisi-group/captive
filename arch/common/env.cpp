/* SPDX-License-Identifier: MIT */

#include <env.h>
#include <cpu.h>
#include <printf.h>
#include <string.h>
#include <device.h>
#include <mm.h>

typedef void (*trap_fn_t)(struct mcontext *);

extern "C" void trap_unk(struct mcontext *);
extern "C" void trap_unk_arg(struct mcontext *);

extern "C" void trap_dbz(struct mcontext *);
extern "C" void trap_debug(struct mcontext *);
extern "C" void trap_breakpoint(struct mcontext *);
extern "C" void trap_pf(struct mcontext *);
extern "C" void trap_gpf(struct mcontext *);
extern "C" void trap_signal(struct mcontext *);
extern "C" void trap_illegal(struct mcontext *);
extern "C" void trap_simd(struct mcontext *);

extern "C" void int80_handler(struct mcontext *);
extern "C" void int81_handler(struct mcontext *);
extern "C" void int82_handler(struct mcontext *);
extern "C" void int83_handler(struct mcontext *);
extern "C" void int90_handler(struct mcontext *);
extern "C" void int91_handler(struct mcontext *);
extern "C" void int60_handler(struct mcontext *);
extern "C" void int61_handler(struct mcontext *);
extern "C" void int62_handler(struct mcontext *);

extern "C" void call_gate_tramp(void);
extern "C" void memory_access_handler(void);
extern "C" void syscall_memory_access_handler(void);

extern "C" void trap_timer(struct mcontext *);
extern "C" void trap_irq0(struct mcontext *);
extern "C" void trap_irq1(struct mcontext *);

struct IDT {
	uint16_t off_low;
	uint16_t sel;
	uint8_t zero0;
	uint8_t type;
	uint16_t off_mid;
	uint32_t off_high;
	uint32_t zero1;
} packed;

using namespace captive;
using namespace captive::arch;

Environment::Environment(PerGuestData *per_guest_data) : per_guest_data(per_guest_data)
{
	bzero(devices, sizeof(devices));
}

Environment::~Environment()
{

}

static void set_idt(IDT* idt, trap_fn_t fn, bool allow_user = false)
{
	idt->zero0 = 0;
	idt->zero1 = 0;

	idt->off_low = ((uint64_t) fn) & 0xffff;
	idt->off_mid = (((uint64_t) fn) >> 16) & 0xffff;
	idt->off_high = (((uint64_t) fn) >> 32);

	idt->sel = 0x8;
	idt->type = 0x8e | (allow_user ? 0x60 : 0);
}

static inline void wrmsr(uint32_t msr_id, uint64_t msr_value)
{
	uint32_t low = msr_value & 0xffffffff;
	uint32_t high = (msr_value >> 32);

	asm volatile ( "rex.b wrmsr" : : "c" (msr_id), "a" (low), "d" (high));
}

void Environment::install_idt()
{

	struct {
		uint16_t limit;
		uint64_t base;
	} packed IDTR;

	asm volatile("sidt %0" : "=m"(IDTR));

	IDTR.limit = sizeof(struct IDT) * 0x100;
	//IDTR.base = (uint64_t)vm_phys_to_virt(0x6000ULL);

	IDT *idt = (IDT *) IDTR.base;

	// Initialise the table with unknowns
	for (int i = 0; i < 0x100; i++) {
		set_idt(&idt[i], trap_unk);
	}

	// Exceptions with arguments
	set_idt(&idt[0x08], trap_unk_arg);
	set_idt(&idt[0x0a], trap_unk_arg);
	set_idt(&idt[0x0b], trap_unk_arg);
	set_idt(&idt[0x0c], trap_unk_arg);
	set_idt(&idt[0x11], trap_unk_arg);
	set_idt(&idt[0x1e], trap_unk_arg);

	// Fault Handlers
	set_idt(&idt[0x00], trap_dbz);
	set_idt(&idt[0x01], trap_debug);
	set_idt(&idt[0x03], trap_breakpoint, true);
	set_idt(&idt[0x06], trap_illegal);
	set_idt(&idt[0x0d], trap_gpf);
	set_idt(&idt[0x0e], trap_pf);
	set_idt(&idt[0x13], trap_simd);

	set_idt(&idt[0x20], trap_timer);

	// IRQ Handler
	set_idt(&idt[0x30], trap_irq0);
	set_idt(&idt[0x31], trap_irq1);

	// 64-bit Memory Handler
	set_idt(&idt[0x60], int60_handler, true);
	set_idt(&idt[0x61], int61_handler, true);
	set_idt(&idt[0x62], int62_handler, true);

	// Software-interrupt handlers
	set_idt(&idt[0x80], int80_handler, true); // Enter Kernel
	set_idt(&idt[0x81], int81_handler, true); // Enter User
	set_idt(&idt[0x82], int82_handler, true); // Flush TLB
	set_idt(&idt[0x83], int83_handler, true); // Invalidate translation

	set_idt(&idt[0x90], int90_handler, true);
	set_idt(&idt[0x91], int91_handler, true);

	asm volatile("lidt %0\n" ::"m"(IDTR));
}

void Environment::install_syscall()
{

	struct {
		uint16_t limit;
		uint64_t base;
	} packed GDTR;

	asm volatile("sgdt %0" : "=m"(GDTR));

	uint32_t *gdt = (uint32_t *) (GDTR.base + GDTR.limit);
	GDTR.limit += (16 * 2);

	uintptr_t gate_addr = (uintptr_t) call_gate_tramp; // 0x38
	*gdt++ = 0x00080000 | (gate_addr & 0xffff);
	*gdt++ = (gate_addr & 0xffff0000) | 0xec00;
	*gdt++ = (gate_addr >> 32);
	*gdt++ = 0;

	gate_addr = (uintptr_t) memory_access_handler; // 0x48
	*gdt++ = 0x00080000 | (gate_addr & 0xffff);
	*gdt++ = (gate_addr & 0xffff0000) | 0xec00;
	*gdt++ = (gate_addr >> 32);
	*gdt++ = 0;

	asm volatile("lgdt %0" ::"m"(GDTR));
}

extern "C" void memory_access_handler(void);

void Environment::prepare_fast_syscall()
{
	wrmsr(0xC0000081, 0x0018000800000000ULL); // ucs/kcs
	wrmsr(0xC0000082, (uint64_t) syscall_memory_access_handler); // rip
	wrmsr(0xC0000084, 1 << 9);
}

void Environment::setup_interrupts()
{
	// Enable interrupts
	asm volatile("sti\n");
}

bool Environment::init()
{
	install_idt();
	install_syscall();
	prepare_fast_syscall();
	setup_interrupts();

	return true;
}

bool Environment::run(PerCPUData *per_cpu_data)
{
	CPU *core = create_cpu(per_cpu_data);
	if (!core) {
		printf("error: unable to create core\n");
		return false;
	}

	CPU::set_active_cpu(core);

	if (!core->init()) {
		printf("error: unable to init core\n");
		return false;
	}

	printf("core: register file @ %p\n", core->reg_state());

	printf("env: preparing bootloader\n");
	prepare_bootloader();

	printf("env: preparing boot core entrypoint=%08x\n", per_guest_data->entrypoint);
	prepare_boot_cpu(core);

	bool result = core->run();

	printf("pca=%lu %016lx\n", core->performance_counter_a(), core->performance_counter_a());
	printf("pcb=%lu %016lx\n", core->performance_counter_b(), core->performance_counter_b());
	delete core;

	return result;
}

bool Environment::read_core_device(CPU& cpu, uint32_t id, uint32_t reg, uint64_t& data)
{
	if (id > 23 || devices[id] == NULL) {
		printf("attempted read of invalid device %d @ %08x\n", id, read_pc());
		return false;
	}

	return devices[id]->read(cpu, reg, data);
}

bool Environment::write_core_device(CPU& cpu, uint32_t id, uint32_t reg, uint64_t data)
{
	if (id > 23 || devices[id] == NULL) {
		printf("attempted write of invalid device %lx @ %08x\n", id, read_pc());
		return false;
	}

	return devices[id]->write(cpu, reg, data);
}
