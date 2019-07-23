/* SPDX-License-Identifier: MIT */

#include <define.h>
#include <printf.h>
#include <cpu.h>
#include <env.h>
#include <priv.h>
#include <disasm.h>

extern "C" void cpu_set_mode(void *cpu, uint8_t mode)
{
	printf("set mode\n");
}

extern "C" void cpu_trap(void *cpu)
{
	assert(false);
}

extern "C" void cpu_write_device(captive::arch::CPU *cpu, uint32_t devid, uint32_t reg, uint64_t val)
{
	cpu->env().write_core_device(*cpu, devid, reg, val);
}

extern "C" void cpu_read_device(captive::arch::CPU *cpu, uint32_t devid, uint32_t reg, uint64_t& val)
{
	cpu->env().read_core_device(*cpu, devid, reg, val);
}

extern "C" void jit_trace(captive::arch::CPU *cpu, uint64_t opcode, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4)
{
	assert(cpu);

	switch ((uint8_t) opcode) {
	case 0: // START
	{
		printf("[%016lx] %25s ", read_pc(), cpu->disassemble_address(*cpu->tagged_registers().ISA, read_pc()));
		break;
	}

	case 1: // STOP
		printf("\n");
		break;

	case 2: // READ MEM
		switch ((uint8_t) a3) {
		case 1: printf("M1[%016lx] => 0x%02x ", a1, a2 & 0xff);
			break;
		case 2: printf("M2[%016lx] => 0x%04x ", a1, a2 & 0xffff);
			break;
		case 4: printf("M4[%016lx] => 0x%08x ", a1, a2 & 0xffffffff);
			break;
		case 8: printf("M8[%016lx] => 0x%016lx ", a1, a2);
			break;
		default: printf("M?[%016lx] => 0x%016lx ", a1, a2);
			break;
		}
		break;

	case 3: // WRITE MEM
		switch ((uint8_t) a3) {
		case 1: printf("M1[%016lx] <= 0x%02x ", a1, a2 & 0xff);
			break;
		case 2: printf("M2[%016lx] <= 0x%04x ", a1, a2 & 0xffff);
			break;
		case 4: printf("M4[%016lx] <= 0x%08x ", a1, a2 & 0xffffffff);
			break;
		case 8: printf("M8[%016lx] <= 0x%016lx ", a1, a2);
			break;
		default: printf("M?[%016lx] <= 0x%016lx ", a1, a2);
			break;
		}
		break;

	case 4: // READ REG
		switch ((uint8_t) a3) {
		case 1: printf("R[%s] => 0x%02x ", cpu->get_reg_name(a1), a2 & 0xff);
			break;
		case 2: printf("R[%s] => 0x%04x ", cpu->get_reg_name(a1), a2 & 0xffff);
			break;
		case 4: printf("R[%s] => 0x%08x ", cpu->get_reg_name(a1), a2 & 0xffffffff);
			break;
		case 8: printf("R[%s] => 0x%016lx ", cpu->get_reg_name(a1), a2);
			break;
		default: printf("R[%s] => 0x%016lx ", cpu->get_reg_name(a1), a2);
			break;
		}

		break;
	case 5: // WRITE REG
		switch ((uint8_t) a3) {
		case 1: printf("R[%s] <= 0x%02x ", cpu->get_reg_name(a1), a2 & 0xff);
			break;
		case 2: printf("R[%s] <= 0x%04x ", cpu->get_reg_name(a1), a2 & 0xffff);
			break;
		case 4: printf("R[%s] <= 0x%08x ", cpu->get_reg_name(a1), a2 & 0xffffffff);
			break;
		case 8: printf("R[%s] <= 0x%016lx ", cpu->get_reg_name(a1), a2);
			break;
		default: printf("R[%s] <= 0x%016lx ", cpu->get_reg_name(a1), a2);
			break;
		}

		break;

	case 6: // READ DEV
		printf("D[%02u @ %02u] => 0x%016lx ", a1, a2, a3);
		break;
	case 7: // WRITE DEV
		printf("D[%02u @ %02u] <= 0x%016lx ", a1, a2, a3);
		break;

	case 8:
		printf("(not taken)");
		break;

	default:
		fatal("unhandled trace opcode %lx pc=%p\n", opcode, read_pc());
	}
}

extern "C" void jit_rum(captive::arch::CPU *cpu)
{
	if (in_kernel_mode()) {
		printf("*** read-user-memory: in kernel mode\n");
	} else {
		printf("*** read-user-memory: in user mode\n");
	}
}

extern "C" uint32_t jit_handle_interrupt(captive::arch::CPU *cpu, uint32_t isr)
{
	return cpu->handle_irq(isr);
}

extern "C" void jit_debug1(uint32_t pc)
{
	printf("CHAIN: %x\n", pc);
}

extern "C" void jit_debug2(uint32_t pc)
{
	printf("DO DISPATCH: %x\n", pc);
}

/*extern "C" void mem_read8(captive::arch::CPU *cpu, uint32_t addr, uint8_t *val)
{
 *val = *((volatile uint8_t *)(uint64_t)addr);
}

extern "C" void mem_read16(captive::arch::CPU *cpu, uint32_t addr, uint16_t *val)
{
 *val = *((volatile uint16_t *)(uint64_t)addr);
}

extern "C" void mem_read32(captive::arch::CPU *cpu, uint32_t addr, uint32_t *val)
{
 *val = *((volatile uint32_t *)(uint64_t)addr);
}

extern "C" void mem_user_read8(captive::arch::CPU *cpu, uint32_t addr, uint8_t *val)
{
	if (cpu->kernel_mode()) { switch_to_user_mode(); }
 *val = *((volatile uint8_t *)(uint64_t)addr);
	if (cpu->kernel_mode() && !in_kernel_mode()) { switch_to_kernel_mode(); }
}

extern "C" void mem_user_read16(captive::arch::CPU *cpu, uint32_t addr, uint16_t *val)
{
	if (cpu->kernel_mode()) { switch_to_user_mode(); }
 *val = *((volatile uint16_t *)(uint64_t)addr);
	if (cpu->kernel_mode() && !in_kernel_mode()) { switch_to_kernel_mode(); }
}

extern "C" void mem_user_read32(captive::arch::CPU *cpu, uint32_t addr, uint32_t *val)
{
	if (cpu->kernel_mode()) { switch_to_user_mode(); }
 *val = *((volatile uint32_t *)(uint64_t)addr);
	if (cpu->kernel_mode() && !in_kernel_mode()) { switch_to_kernel_mode(); }
}

extern "C" void mem_write8(captive::arch::CPU *cpu, uint32_t addr, uint8_t val)
{
 *((volatile uint8_t *)(uint64_t)addr) = val;
}

extern "C" void mem_write16(captive::arch::CPU *cpu, uint32_t addr, uint16_t val)
{
 *((volatile uint16_t *)(uint64_t)addr) = val;
}

extern "C" void mem_write32(captive::arch::CPU *cpu, uint32_t addr, uint32_t val)
{
 *((volatile uint32_t *)(uint64_t)addr) = val;
}

extern "C" void mem_user_write8(captive::arch::CPU *cpu, uint32_t addr, uint8_t val)
{
	if (cpu->kernel_mode()) { switch_to_user_mode(); }
 *((volatile uint8_t *)(uint64_t)addr) = val;
	if (cpu->kernel_mode() && !in_kernel_mode()) { switch_to_kernel_mode(); }
}

extern "C" void mem_user_write16(captive::arch::CPU *cpu, uint32_t addr, uint16_t val)
{
	if (cpu->kernel_mode()) { switch_to_user_mode(); }
 *((volatile uint16_t *)(uint64_t)addr) = val;
	if (cpu->kernel_mode() && !in_kernel_mode()) { switch_to_kernel_mode(); }
}

extern "C" void mem_user_write32(captive::arch::CPU *cpu, uint32_t addr, uint32_t val)
{
	if (cpu->kernel_mode()) { switch_to_user_mode(); }
 *((volatile uint32_t *)(uint64_t)addr) = val;
	if (cpu->kernel_mode() && !in_kernel_mode()) { switch_to_kernel_mode(); }
}
 */