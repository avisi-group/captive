/* SPDX-License-Identifier: MIT */

#include <engine/engine.h>
#include <hypervisor/kvm/cpu.h>
#include <hypervisor/kvm/guest.h>
#include <hypervisor/kvm/kvm.h>
#include <hypervisor/semihosting-context.h>
#include <platform/platform.h>
#include <util/config/config.h>

#include <simulation/simulation.h>

#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include <devices/device.h>
#include <devices/irq/irq-controller.h>
#include <sys/eventfd.h>
#include <sys/signal.h>
#include <fcntl.h>
#include <chrono>
#include <sstream>
#include <iomanip>

USE_CONTEXT(CPU);

using namespace captive::hypervisor::kvm;

KVMCpu::KVMCpu(int id, KVMGuest& owner, const GuestCPUConfiguration& config, int fd, PerCPUData *per_cpu_data)
: CPU(id, owner, config, per_cpu_data),
_initialised(false),
fd(fd),
cpu_run_struct(NULL),
cpu_run_struct_size(0),
irq_signal(owner),
irq_raise(owner) {
	pthread_barrier_init(&single_step_barrier, nullptr, 2);
	single_stepping = false;
}

KVMCpu::~KVMCpu() {
	if (initialised()) {
		munmap(cpu_run_struct, cpu_run_struct_size);
	}

	DEBUG << CONTEXT(CPU) << "Closing KVM VCPU fd";
	close(fd);
}

bool KVMCpu::init() {
	if (initialised()) {
		ERROR << CONTEXT(CPU) << "KVM CPU already initialised";
		return false;
	}

	if (!CPU::init())
		return false;

	if (!setup_interrupts())
		return false;

	// Attach the CPU IRQ controller
	config().irq_controller().attach(*this);

	cpu_run_struct_size = ioctl(((KVM &) ((KVMGuest &) owner()).owner()).kvm_fd, KVM_GET_VCPU_MMAP_SIZE, 0);
	if ((int) cpu_run_struct_size == -1) {
		ERROR << CONTEXT(CPU) << "Unable to ascertain size of CPU run structure";
		return false;
	}

	DEBUG << CONTEXT(CPU) << "Mapping CPU run structure size=" << std::hex << cpu_run_struct_size;
	cpu_run_struct = (struct kvm_run *) mmap(NULL, cpu_run_struct_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (cpu_run_struct == MAP_FAILED) {
		ERROR << CONTEXT(CPU) << "Unable to mmap CPU run struct";
		return false;
	}
#if 1
	struct {
		struct kvm_cpuid2 header;
		struct kvm_cpuid_entry2 entries[5];
	} cpuid_data;
	
	bzero(&cpuid_data, sizeof(cpuid_data));
	
	cpuid_data.header.nent = sizeof(cpuid_data.entries) / sizeof(cpuid_data.entries[0]);
	
	cpuid_data.entries[0].function = 1;
	cpuid_data.entries[0].index = 0;
	cpuid_data.entries[0].eax = 0;
	cpuid_data.entries[0].ebx = 0;
	
	// pcid, xsave, osxsave, fma, avx, sse3
	cpuid_data.entries[0].ecx |= (1u << 17) | (1u << 26) | (1u << 27) | (1u << 12) | (1u << 28) | (1u << 0);
	
	// fxsr, sse, sse2
	cpuid_data.entries[0].edx |= (1u << 24) | (1u << 25) | (1u << 26);
	cpuid_data.entries[0].flags = 0;

	cpuid_data.entries[1].function = 7;
	cpuid_data.entries[1].index = 0;
	cpuid_data.entries[1].eax = 0;
	
	cpuid_data.entries[1].ebx = 0;
	cpuid_data.entries[1].ebx |= (1u << 10);				// invpcid
	cpuid_data.entries[1].ebx |= (1u << 5) | (1u << 21);	// avx2	
	cpuid_data.entries[1].ebx |= (1u << 0);					// fsgsbase
	cpuid_data.entries[1].ebx |= (1u << 14);				// mpx

	cpuid_data.entries[1].ecx = 0;
	cpuid_data.entries[1].ecx |= (1u << 3);		// pku
	
	cpuid_data.entries[1].edx = 0;
	cpuid_data.entries[1].flags = 0;
	
	cpuid_data.entries[2].function = 0xd;
	cpuid_data.entries[2].index = 1;
	cpuid_data.entries[2].eax = 7;
	cpuid_data.entries[2].ebx = 0;
	cpuid_data.entries[2].ecx = 0;
	cpuid_data.entries[2].edx = 0;
	cpuid_data.entries[2].flags = 0;
	
	cpuid_data.entries[3].function = 0x50000000;
	cpuid_data.entries[3].index = 0;
	cpuid_data.entries[3].eax = 0x1234;
	cpuid_data.entries[3].ebx = 0x5678;
	cpuid_data.entries[3].ecx = 0x9abc;
	cpuid_data.entries[3].edx = 0xdef0;
	cpuid_data.entries[3].flags = 0;

	cpuid_data.entries[4].function = 0x80000001;
	cpuid_data.entries[4].index = 0;
	cpuid_data.entries[4].eax = 0;
	cpuid_data.entries[4].ebx = 0;
	cpuid_data.entries[4].ecx = 0;
	cpuid_data.entries[4].edx = (1u << 27);
	cpuid_data.entries[4].flags = 0;
	
	if (vmioctl(KVM_SET_CPUID2, &cpuid_data)) {
		ERROR << "Unable to update CPUID";
		return false;
	}
#endif

	_initialised = true;
	return true;
}

void KVMCpu::interrupt(uint32_t code) {
	per_cpu_data().async_action = code;
	irq_signal.raise();
}

void KVMCpu::raise_guest_interrupt(uint8_t irq) {
	if (__sync_val_compare_and_swap(&per_cpu_data().isr, 0, 2) == 0) {
		//irq_raise.raise();
		
		KVMGuest& kvm_guest = (KVMGuest &) owner();
		
		uintptr_t ipp = (uintptr_t)per_cpu_data().interrupt_pending;
		if (ipp) {
			uint64_t *x = (uint64_t *)kvm_guest.vm_phys_to_host_virt(kvm_guest.vm_virt_to_vm_phys(ipp));
			*x = 1;
		}
		
		//*per_cpu_data().interrupt_pending = 1;
	}
}

void KVMCpu::rescind_guest_interrupt(uint8_t irq) {
	per_cpu_data().isr = 0;
}

void KVMCpu::acknowledge_guest_interrupt(uint8_t irq) {
}

#ifndef NDEBUG
extern std::map<captive::devices::Device *, uint64_t> device_reads, device_writes;
#endif

bool KVMCpu::run() {
	KVMGuest& kvm_guest = (KVMGuest &) owner();

	bool run_cpu = true;
	int rc;

	if (!initialised()) {
		ERROR << CONTEXT(CPU) << "CPU not initialised";
		return false;
	}

	struct kvm_regs regs;
	vmioctl(KVM_GET_REGS, &regs);

	regs.rdi = kvm_guest.vm_phys_to_vm_virt(VM_PHYS_CPU_DATA + (0x100 * id()));
	regs.rip = kvm_guest.engine().boot_entrypoint();
	regs.rsi = id();
	regs.rflags = 2;
	regs.rsp = kvm_guest.vm_phys_to_vm_virt(VM_PHYS_HEAP_BASE + VM_HEAP_SIZE);
	
	vmioctl(KVM_SET_REGS, &regs);

	struct kvm_sregs sregs;
	vmioctl(KVM_GET_SREGS, &sregs);
	sregs.idt.base = kvm_guest.vm_phys_to_vm_virt(VM_PHYS_IDT);
	sregs.idt.limit = 0;

	sregs.gdt.base = kvm_guest.vm_phys_to_vm_virt(VM_PHYS_GDT);
	sregs.gdt.limit = 0x38;

	sregs.cr0 = 0x80010007; // PG, PE, MP, EM, WP
	sregs.cr3 = VM_PHYS_PML4_0;
	sregs.cr4 = 0x206b0;
	
	// Allow SSE
	sregs.cr0 &= ~(1u << 2);	// Clear EM
	sregs.cr0 |= (1u << 1);		// Set MP
	sregs.cr0 |= (1u << 18);	// Set AM
	sregs.cr4 |= (1u << 9);		// Set OXFXSR
	sregs.cr4 |= (1u << 10);	// Set OSXMMEXCPT
	sregs.cr4 |= (1u << 18);	// Set OSXSAVE
	sregs.cr4 |= (1u << 18);	// Set OSXSAVE
	sregs.cr4 |= (1u << 16);	// Set FSGSBASE
	
	if (owner().platform().host_configuration().mpk) {
		sregs.cr4 |= (1u << 22);		// Set PKE
	}
	
	//sregs.cr0 &= ~(1u << 16);	// Disable WP
	//sregs.cr4 &= ~(1u << 20);	// Disable SMEP
	//sregs.cr4 &= ~(1u << 21);	// Disable SMAP
	
	sregs.efer = 0;
	sregs.efer |= (1u << 0);		// SCE
	sregs.efer |= (1u << 8);		// LME
	sregs.efer |= (1u << 10);		// LMA
	sregs.efer |= (1u << 11);	// NXE
	//sregs.efer |= (1 << 13);	// LMSLE
	//sregs.efer |= (1 << 14);	// FFXSR
	//sregs.efer |= (1 << 15);	// TCE
		
	struct kvm_segment cs, ds, tr;
	cs.base = 0;
	cs.limit = 0xffffffff;
	cs.dpl = 0;
	cs.db = 0;
	cs.g = 1;
	cs.s = 1;
	cs.l = 1;
	cs.type = 0xb;
	cs.present = 1;
	cs.selector = 0x08;

	ds.base = 0;
	ds.limit = 0xffffffff;
	ds.dpl = 0;
	ds.db = 1;
	ds.g = 1;
	ds.s = 1;
	ds.l = 0;
	ds.type = 0x3;
	ds.present = 1;
	ds.selector = 0x10;

	tr.base = 0;
	tr.limit = 0xffffffff;
	tr.dpl = 0;
	tr.db = 1;
	tr.g = 1;
	tr.s = 0;
	tr.l = 0;
	tr.type = 0xb;
	tr.present = 1;
	tr.selector = 0x2b;

	sregs.ss = ds;
	sregs.cs = cs;
	sregs.ds = ds;
	sregs.es = ds;
	sregs.fs = ds;
	sregs.gs = ds;
	sregs.tr = tr;

	int x = vmioctl(KVM_SET_SREGS, &sregs);
	if (x) {
		ERROR << CONTEXT(CPU) << "Unable to update SREGS: " << LAST_ERROR_TEXT;
		return false;
	}
	
	struct kvm_lapic_state lapic_state;
	bzero(&lapic_state, sizeof(lapic_state));
	
	vmioctl(KVM_GET_LAPIC, &lapic_state);
	vmioctl(KVM_SET_LAPIC, &lapic_state);

	cpu_start_time = std::chrono::high_resolution_clock::now();

	if (owner().owner().debugger() != nullptr) {
		debug_stop();
	}
	
	DEBUG << CONTEXT(CPU) << "Running CPU " << id();
	do {
		if (single_stepping) {
			pthread_barrier_wait(&single_step_barrier);
		}
		
		rc = vmioctl(KVM_RUN);
		if (rc < 0) {
			if (errno == EINTR) {
				continue;
			}

			ERROR << CONTEXT(CPU) << "Unable to run VCPU: " << LAST_ERROR_TEXT;

			run_cpu = false;
			continue;
		}

		switch (cpu_run_struct->exit_reason) {
		case KVM_EXIT_DEBUG:
			DEBUG << CONTEXT(CPU) << "DEBUG";
			//dump_regs();
			break;

		case KVM_EXIT_IO:
			struct kvm_regs regs;
			vmioctl(KVM_GET_REGS, &regs);
			run_cpu = handle_port_io(regs);
			
			break;
			
		/*case KVM_EXIT_IOAPIC_EOI:
			break;*/

		case KVM_EXIT_MMIO:
			if (cpu_run_struct->mmio.phys_addr >= 0x200000000) {
				uint64_t converted_pa = cpu_run_struct->mmio.phys_addr - 0x200000000;

				uint64_t base_addr;
				devices::Device *dev = kvm_guest.lookup_device(converted_pa, base_addr);

				if (dev != NULL) {
					void *data = (void *) cpu_run_struct->mmio.data;

					uint64_t offset = converted_pa - base_addr;
					if (cpu_run_struct->mmio.is_write) {
						run_cpu = dev->write(offset, cpu_run_struct->mmio.len, *(uint64_t *) data);
					} else {
						run_cpu = dev->read(offset, cpu_run_struct->mmio.len, *(uint64_t *) data);
					}

					if (!run_cpu) {
						fprintf(stderr, "device io failed: %s: base=%lx, pa=%lx\n", dev->name().c_str(), base_addr, converted_pa);
					}

					/*if (!(run_cpu = handle_device_access(dev, converted_pa, *cpu_run_struct))) {
						DEBUG << CONTEXT(CPU) << "Device (" << dev->name() << ") " << (cpu_run_struct->mmio.is_write ? "Write" : "Read") << " Access Failed: " << std::hex << converted_pa;
					}*/

					continue;
				} else {
					ERROR << CONTEXT(CPU) << "Device Not Found: " << std::hex << converted_pa;
				}
			}

			run_cpu = false;
			ERROR << CONTEXT(CPU) << "EXIT MMIO, pa=" << std::hex << cpu_run_struct->mmio.phys_addr << ", size=" << std::hex << cpu_run_struct->mmio.len;

			break;
		case KVM_EXIT_UNKNOWN:
			run_cpu = false;
			ERROR << CONTEXT(CPU) << "EXIT UNKNOWN, reason=" << cpu_run_struct->hw.hardware_exit_reason;
			break;
		case KVM_EXIT_INTERNAL_ERROR:
			run_cpu = false;
			ERROR << CONTEXT(CPU) << "EXIT INTERNAL ERROR, error=" << cpu_run_struct->internal.suberror;
			for (uint32_t i = 0; i < cpu_run_struct->internal.ndata; i++) {
				ERROR << "DATA: " << std::hex << cpu_run_struct->internal.data[i];
			}
			break;
		case KVM_EXIT_FAIL_ENTRY:
			run_cpu = false;
			ERROR << CONTEXT(CPU) << "EXIT FAIL ENTRY, error=" << cpu_run_struct->fail_entry.hardware_entry_failure_reason;
			break;
		case KVM_EXIT_SHUTDOWN:
			run_cpu = false;
			ERROR << CONTEXT(CPU) << "EXIT SHUTDOWN";
			break;
		case KVM_EXIT_HYPERCALL:
			run_cpu = false;
			ERROR << CONTEXT(CPU) << "EXIT HYPERCALL";
			break;
		case KVM_EXIT_HLT:
			run_cpu = false;
			ERROR << CONTEXT(CPU) << "EXIT HALT";
			break;
		default:
			run_cpu = false;
			ERROR << CONTEXT(CPU) << "UNKNOWN: " << cpu_run_struct->exit_reason;
			break;
		}
	} while (run_cpu && !per_cpu_data().halt);

	dump_regs();

	return true;
}

void KVMCpu::stop() {
	per_cpu_data().halt = true;
	interrupt(1);
}

#pragma GCC diagnostic ignored "-Wstrict-aliasing"

bool KVMCpu::handle_device_access(devices::Device* device, uint64_t pa) {
	uint64_t offset = pa & (device->size() - 1);
	DEBUG << CONTEXT(CPU) << "Handling Device Access: pa=" << std::hex << pa << ", name=" << device->name() << ", is-write=" << (uint32_t) cpu_run_struct->mmio.is_write << ", offset=" << std::hex << offset << ", len=" << cpu_run_struct->mmio.len;

	void *data = (void *) cpu_run_struct->mmio.data;

	if (cpu_run_struct->mmio.is_write) {
		return device->write(offset, cpu_run_struct->mmio.len, *(uint64_t *) data);
	} else {
		if (!device->read(offset, cpu_run_struct->mmio.len, *(uint64_t *) data))
			return false;
		return true;
	}
}
#pragma GCC diagnostic pop

bool KVMCpu::handle_port_io(struct kvm_regs& regs)
{
	KVMGuest& kvm_guest = (KVMGuest &) owner();
	
	switch (cpu_run_struct->io.port) {
	case 0xff:
		return handle_hypercall(regs.rax, regs.rdi, regs.rsi);

	case 0xfe:
		if (regs.rax == 0) {
			kvm_guest.do_guest_printf();
		} else {
			fprintf(stderr, "%c", (char) regs.rax & 0xff);
		}
		
		return true;
		
	case 0xfd:
		dump_regs();
		return true;

	case 0xfc:
		if (owner().owner().debugger()) {
			debug_stop();
			owner().owner().debugger()->interrupt();
		}
		return true;
		
	case 0xfb:
		switch(regs.rax & 0xff) {
		case 0:
			fprintf(stderr, "* STOP PROFILE\n");
			break;
		case 1:
			fprintf(stderr, "* START PROFILE\n");
			break;
		}
		return true;
		
	case 0xf1:
		instrument_fn_enter(regs.rdi, regs.rsi);
		return true;
		
	case 0xf2:
		instrument_fn_exit(regs.rdi, regs.rsi);
		return true;
		
	case 0xf0:
	{
		uint64_t base_addr;
		devices::Device *dev = kvm_guest.lookup_device(regs.rdx, base_addr);
		if (dev != NULL) {
			uint64_t offset = regs.rdx - base_addr;
			if (cpu_run_struct->io.direction == KVM_EXIT_IO_OUT) {
#ifndef NDEBUG
				device_writes[dev]++;
#endif   
				// Device Write
				dev->write(offset, cpu_run_struct->io.size, *(uint64_t *) ((uint64_t) cpu_run_struct + cpu_run_struct->io.data_offset));
			} else {
#ifndef NDEBUG
				device_reads[dev]++;
#endif   
				// Device Read
				dev->read(offset, cpu_run_struct->io.size, *(uint64_t *) ((uint64_t) cpu_run_struct + cpu_run_struct->io.data_offset));
			}
		}
		
		return true;
	}
	
	case 0xed:
	{
		SemihostingCallData call_data;
		call_data.call_nr = regs.rax;
		call_data.arguments[0] = regs.rdi;
		call_data.arguments[1] = regs.rsi;
		call_data.arguments[2] = regs.rdx;
		call_data.arguments[3] = regs.rcx;
		call_data.arguments[4] = regs.rax;
		call_data.arguments[5] = regs.rbx;
		call_data.arguments[6] = regs.rsp;
		call_data.arguments[7] = regs.rbp;
		call_data.arguments[8] = regs.r8;
		call_data.arguments[9] = regs.r9;
		call_data.arguments[10] = regs.r10;
		call_data.arguments[11] = regs.r11;
		call_data.arguments[12] = regs.r12;
		call_data.arguments[13] = regs.r13;
		call_data.arguments[14] = regs.r14;
		call_data.arguments[15] = regs.r15;
		
		if (kvm_guest.handle_semihosting_call(*this, call_data)) {
			regs.rax = call_data.result;
			vmioctl(KVM_SET_REGS, &regs);
		} else {
			return false;
		}

		return true;
	}
	
	case 0xee:
		kvm_guest.handle_simulation_events(*this, 8192);
		return true;
	
	case 0xef:
		switch (regs.rax) {
		case 0:
			for (simulation::Simulation *sim : kvm_guest.simulations()) {
				sim->dump();
			}
			break;
			
		case 1:
			for (simulation::Simulation *sim : kvm_guest.simulations()) {
				sim->begin_record();
			}
			break;

		case 2:
			for (simulation::Simulation *sim : kvm_guest.simulations()) {
				sim->end_record();
			}
			break;
		}
		
		return true;
		
	case 0x30 ... 0x3f:
		fprintf(stderr, "x");
		return true;
		
	default:
		DEBUG << CONTEXT(CPU) << "EXIT IO "
				"port=" << std::hex << cpu_run_struct->io.port << ", "
				"data offset=" << std::hex << cpu_run_struct->io.data_offset << ", "
				"count=" << std::hex << cpu_run_struct->io.count;
		
		return false;
	}
}

bool KVMCpu::handle_hypercall(uint64_t data, uint64_t arg1, uint64_t arg2) {
	DEBUG << CONTEXT(CPU) << "Hypercall " << data;

	switch (data) {
	case 2:
		DEBUG << CONTEXT(CPU) << "Abort Requested";
		return false;

	case 3:
		ERROR << CONTEXT(CPU) << "Guest Assert Failure";
		dump_regs();
		return false;

	case 4:
	{
		std::chrono::high_resolution_clock::time_point then = std::chrono::high_resolution_clock::now();
		std::chrono::seconds dur = std::chrono::duration_cast<std::chrono::seconds>(then - cpu_start_time);

		DEBUG << "Instruction Count: " << per_cpu_data().insns_executed << ENABLE;
		DEBUG << "MIPS: " << ((per_cpu_data().insns_executed * 1e-6) / dur.count()) << ENABLE;
		return true;
	}

	case 5:
		dump_regs();
		fgetc(stdin);
		return true;

	case 13:
	{
		std::stringstream cmd;
		cmd << "addr2line -e " << owner().platform().host_configuration().arch_module << " " << std::hex << arg1;
		system(cmd.str().c_str());
		return true;
	}

	case 15:
	{
		struct kvm_regs regs;
		vmioctl(KVM_GET_REGS, &regs);

		std::stringstream fname;
		fname << "code-" << std::hex << std::setw(8) << std::setfill('0') << regs.rdx << ".bin";
		FILE *f = fopen(fname.str().c_str(), "wb");

		void *ptr = ((KVMGuest&)owner()).vm_phys_to_host_virt(regs.rdi);
		if (ptr) {
			fwrite(ptr, regs.rsi, 1, f);
		}

		fflush(f);
		fclose(f);
		return true;
	}
	}

	return false;
}

void KVMCpu::dump_regs() {
	struct kvm_regs regs;
	struct kvm_sregs sregs;
	struct kvm_fpu fregs;

	int rc = ioctl(fd, KVM_GET_REGS, &regs);
	if (rc) {
		ERROR << "Unable to retrieve CPU registers";
		return;
	}

	rc = ioctl(fd, KVM_GET_SREGS, &sregs);
	if (rc) {
		ERROR << "Unable to retrieve special CPU registers";
		return;
	}

	rc = ioctl(fd, KVM_GET_FPU, &fregs);
	if (rc) {
		ERROR << "Unable to retrieve FP CPU registers";
		return;
	}
	
#define PREG(rg) << #rg " = " << std::hex << regs.rg << " (" << std::dec << regs.rg << ")" << std::endl

	INFO << "Registers:" << std::endl

	PREG(rax)
	PREG(rbx)
	PREG(rcx)
	PREG(rdx)
	PREG(rsi)
	PREG(rdi)
	PREG(rsp)
	PREG(rbp)

	PREG(r8)
	PREG(r9)
	PREG(r10)
	PREG(r11)
	PREG(r12)
	PREG(r13)
	PREG(r14)
	PREG(r15)
	
	PREG(rip)
	PREG(rflags)

#undef PREG
	<< "mxcsr = " << std::hex << fregs.mxcsr << std::endl
			
#define PFREG(rg,i) << #rg " = " << std::hex << std::setw(2) << std::setfill('0') \
			<< (uint64_t)fregs.xmm[i][15] \
			<< (uint64_t)fregs.xmm[i][14] \
			<< (uint64_t)fregs.xmm[i][13] \
			<< (uint64_t)fregs.xmm[i][12] \
			<< (uint64_t)fregs.xmm[i][11] \
			<< (uint64_t)fregs.xmm[i][10] \
			<< (uint64_t)fregs.xmm[i][9] \
			<< (uint64_t)fregs.xmm[i][8] \
			<< (uint64_t)fregs.xmm[i][7] \
			<< (uint64_t)fregs.xmm[i][6] \
			<< (uint64_t)fregs.xmm[i][5] \
			<< (uint64_t)fregs.xmm[i][4] \
			<< (uint64_t)fregs.xmm[i][3] \
			<< (uint64_t)fregs.xmm[i][2] \
			<< (uint64_t)fregs.xmm[i][1] \
			<< (uint64_t)fregs.xmm[i][0] \
			<< std::endl
			
	PFREG(xmm0,0)
	PFREG(xmm1,1)
	PFREG(xmm2,2)
	PFREG(xmm3,3)
			
#undef PFREG
#define PSREG(rg) << #rg ": base=" << std::hex << sregs.rg.base << ", limit=" << std::hex << sregs.rg.limit << ", selector=" << std::hex << sregs.rg.selector << ", dpl=" << (uint32_t)sregs.rg.dpl << ", avl=" << (uint32_t)sregs.rg.avl << std::endl

	PSREG(cs)
	PSREG(ds)
	PSREG(es)
	PSREG(fs)
	PSREG(gs)
	PSREG(ss)
	PSREG(tr)

#undef PSREG
#define PCREG(rg) << #rg ": " << std::hex << sregs.rg << std::endl

	PCREG(cr0)
	PCREG(cr2)
	PCREG(cr3)
	PCREG(cr4)
	PCREG(cr8)

#undef PCREG

			<< "gdt base=" << std::hex << sregs.gdt.base << ", limit=" << std::hex << sregs.gdt.limit << std::endl
			<< "idt base=" << std::hex << sregs.idt.base << ", limit=" << std::hex << sregs.idt.limit << std::endl
			<< "apic base=" << std::hex << sregs.apic_base << std::endl
			<< "efer=" << std::hex << sregs.efer << std::endl;
}

bool KVMCpu::setup_interrupts() {
	if (!irq_signal.attach((id() * 2) + 16)) return false;
	if (!irq_raise.attach((id() * 2) + 17)) return false;

	return true;
}

void KVMCpu::debug_stop()
{
	struct kvm_guest_debug guest_debug;
	bzero(&guest_debug, sizeof(guest_debug));
	
	guest_debug.control = KVM_GUESTDBG_ENABLE;
	guest_debug.control = KVM_GUESTDBG_ENABLE | KVM_GUESTDBG_SINGLESTEP;
	
	vmioctl(KVM_SET_GUEST_DEBUG, &guest_debug);
	
	single_stepping = true;
}

void KVMCpu::debug_resume()
{
	struct kvm_guest_debug guest_debug;
	bzero(&guest_debug, sizeof(guest_debug));
	
	vmioctl(KVM_SET_GUEST_DEBUG, &guest_debug);
	
	single_stepping = false;
	pthread_barrier_wait(&single_step_barrier);
}

void KVMCpu::debug_step()
{
	pthread_barrier_wait(&single_step_barrier);
}

bool KVMCpu::debug_get_registers(uint64_t* registers, size_t& count)
{
	struct kvm_regs regs;
	int rc = vmioctl(KVM_GET_REGS, &regs);
	if (rc) return false;
	
	if (count < 18) return false;
	
	registers[0] = regs.rax;
	registers[1] = regs.rbx;
	registers[2] = regs.rcx;
	registers[3] = regs.rdx;
	registers[4] = regs.rsi;
	registers[5] = regs.rdi;
	registers[6] = regs.rbp;
	registers[7] = regs.rsp;
	
	registers[8] = regs.r8;
	registers[9] = regs.r9;
	registers[10] = regs.r10;
	registers[11] = regs.r11;
	registers[12] = regs.r12;
	registers[13] = regs.r13;
	registers[14] = regs.r14;
	registers[15] = regs.r15;
	
	registers[16] = regs.rip;
	registers[17] = regs.rflags;
	
	count = 18;
	return true;
}

bool KVMCpu::debug_get_memory(uint64_t gva, void* buffer, size_t size)
{
	KVMGuest& guest = (KVMGuest&)owner();
	
	if (gva < VM_VIRT_SPLIT) {
		return false;
	}
	
	uintptr_t gpa = guest.vm_virt_to_vm_phys(gva);
	void *mem = guest.vm_phys_to_host_virt(gpa);
	if (mem == nullptr) return false;
	
	memcpy(buffer, mem, size);
	return true;
}


IRQFD::IRQFD(KVMGuest& owner) : owner(owner), fd(-1), gsi(0) {
	fd = eventfd(0, O_NONBLOCK | O_CLOEXEC);
	if (fd < 0) {
		ERROR << "Unable to create IRQ fd";
		throw 0;
	}
}

IRQFD::~IRQFD() {
	close(fd);
}

bool IRQFD::attach(int gsi) {
	assert(fd >= 0);
	DEBUG << CONTEXT(CPU) << "Attaching IRQFD to GSI=" << gsi;

	struct kvm_irqfd irqfd;
	bzero(&irqfd, sizeof (irqfd));

	irqfd.fd = fd;
	irqfd.gsi = gsi;

	if (owner.vmioctl(KVM_IRQFD, &irqfd)) {
		ERROR << "Unable to install IRQ fd";
		return false;
	}

	return true;
}

void IRQFD::raise() {
	uint64_t data = 0;
	write(fd, &data, sizeof (data));
}
