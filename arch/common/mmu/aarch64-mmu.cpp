/* SPDX-License-Identifier: MIT */

#include <cpu.h>
#include <mmu/aarch64-mmu.h>

__thread uint8_t *__gpm;

struct tt_descriptor {

	tt_descriptor() : bits(0)
	{
	}

	tt_descriptor(uint64_t v) : bits(v)
	{
	}

	union {
		uint64_t bits;

		struct {
			uint64_t type : 2;
			uint64_t ignored : 62;
		} type;

		struct {
			uint64_t ignored;
		} invalid;

		struct {
			uint64_t type : 2;
			uint64_t attr_index : 3;
			uint64_t ns : 1;
			uint64_t ap : 2;
			uint64_t sh : 2;
			uint64_t af : 1;
			uint64_t ng : 1;
			uint64_t output_address : 36;
			uint64_t reserved : 4;
			uint64_t contiguous : 1;
			uint64_t pxn : 1;
			uint64_t uxn : 1;
			uint64_t ignored1 : 4;
			uint64_t ignored2 : 5;
		} block;

		struct {
			uint64_t type : 2;
			uint64_t ignored1 : 10;
			uint64_t next : 36;
			uint64_t reserved : 4;
			uint64_t ignored2 : 7;
			uint64_t pxntable : 1;
			uint64_t xntable : 1;
			uint64_t aptable : 2;
			uint64_t nstable : 1;
		} table;

		struct {
			uint64_t type : 2;
			uint64_t attr_index : 3;
			uint64_t ns : 1;
			uint64_t ap : 2;
			uint64_t sh : 2;
			uint64_t af : 1;
			uint64_t ng : 1;
			uint64_t output_address : 36;
			uint64_t reserved : 4;
			uint64_t contiguous : 1;
			uint64_t pxn : 1;
			uint64_t uxn : 1;
			uint64_t ignored1 : 4;
			uint64_t ignored2 : 5;
		} l3;
	};
} packed;

using namespace captive::arch::mmu;

static inline const tt_descriptor& get_pte(gpa_t table_base, uint64_t index)
{
	return((const tt_descriptor *) (VM_VIRT_SPLIT + VM_PHYS_GPM_BASE + table_base))[index];
}

enum class MMUFaultLevel {
	LEVEL0 = 0,
	LEVEL1 = 1,
	LEVEL2 = 2,
	LEVEL3 = 3,
};

enum class MMUFaultType {
	ADDRESS_SIZE = 0,
	TRANSLATION = 4,
	ACCESS_FLAG = 8,
	PERMISSION = 12
};

static void update_fault(AddressTranslationContext& ctx, MMUFaultLevel level, MMUFaultType type)
{
	ctx.private_data = (uint64_t) type | (uint64_t) level;

	if (ctx.type == AddressTranslationType::WRITE) {
		ctx.private_data |= 0x40;
	}
}

static bool check_permissions(AddressTranslationContext& ctx, int ap)
{
	switch (ap) {
	case 0: // EL1 RW, EL0 -
		if (ctx.privilege == AddressTranslationPrivilege::USER) {
			return false;
		} else {
			return true;
		}

	case 1: // EL1 RW, EL0 RW
		return true;

	case 2: // EL1 RO, EL0 -
		if (ctx.privilege == AddressTranslationPrivilege::USER) {
			return false;
		} else {
			return ctx.type == AddressTranslationType::READ || ctx.type == AddressTranslationType::FETCH;
		}

	case 3: // EL1 RO, EL0 RO
		return ctx.type == AddressTranslationType::READ || ctx.type == AddressTranslationType::FETCH;

	default:
		return false;
	}
}

static bool do_translate_l3(gva_t va, gpa_t table_base, AddressTranslationContext& ctx)
{
	const tt_descriptor& l3 = get_pte(table_base, (va >> 12) & 0x1ff);
	//printf("l3=%016x\n", l3.bits);

	switch (l3.type.type) {
	case 0: case 2: case 1:
		update_fault(ctx, MMUFaultLevel::LEVEL3, MMUFaultType::TRANSLATION);
		return true;

	case 3: // Page
		if (l3.l3.af == 0) {
			update_fault(ctx, MMUFaultLevel::LEVEL3, MMUFaultType::ACCESS_FLAG);
		} else if (!check_permissions(ctx, l3.l3.ap)) {
			update_fault(ctx, MMUFaultLevel::LEVEL3, MMUFaultType::PERMISSION);
		} else {
			ctx.result = AddressTranslationResult::OK;
			ctx.pa = (l3.l3.output_address << 12) | (va & 0xfff);
		}

		return true;

	default:
		return false;
	}
}

static bool do_translate_l2(gva_t va, gpa_t table_base, AddressTranslationContext& ctx)
{
	const tt_descriptor& l2 = get_pte(table_base, (va >> 21) & 0x1ff);
	//printf("l2=%016x\n", ctx.l2.bits);

	switch (l2.type.type) {
	case 0: case 2:
		update_fault(ctx, MMUFaultLevel::LEVEL2, MMUFaultType::TRANSLATION);
		return true;

	case 1: // Block
		if (l2.block.af == 0) {
			update_fault(ctx, MMUFaultLevel::LEVEL2, MMUFaultType::ACCESS_FLAG);
		} else if (!check_permissions(ctx, l2.block.ap)) {
			update_fault(ctx, MMUFaultLevel::LEVEL2, MMUFaultType::PERMISSION);
		} else {
			ctx.result = AddressTranslationResult::OK;
			ctx.pa = (l2.block.output_address << 12) | (va & 0x1fffff);
		}

		return true;

	case 3: // Table
		return do_translate_l3(va, l2.table.next << 12, ctx);

	default:
		return false;
	}
}

static bool do_translate_l1(gva_t va, gpa_t table_base, AddressTranslationContext& ctx)
{
	const tt_descriptor& l1 = get_pte(table_base, (va >> 30) & 0x1ff);
	//printf("l1=%016x\n", ctx.l1.bits);

	switch (l1.type.type) {
	case 0: case 2: // Invalid
		update_fault(ctx, MMUFaultLevel::LEVEL1, MMUFaultType::TRANSLATION);
		return true;

	case 1: // Block
		if (l1.block.af == 0) {
			update_fault(ctx, MMUFaultLevel::LEVEL1, MMUFaultType::ACCESS_FLAG);
		} else if (!check_permissions(ctx, l1.block.ap)) {
			update_fault(ctx, MMUFaultLevel::LEVEL1, MMUFaultType::PERMISSION);
		} else {
			ctx.result = AddressTranslationResult::OK;
			ctx.pa = (l1.block.output_address << 12) | (va & 0x3fffffff);
		}

		return true;

	case 3: // Table
		return do_translate_l2(va, l1.table.next << 12, ctx);

	default:
		return false;
	}
}

static bool do_translate_l0(gva_t va, gpa_t table_base, AddressTranslationContext& ctx)
{
	const tt_descriptor& l0 = get_pte(table_base, (va >> 39) & 0x1ff);
	//printf("l0=%016x\n", l0.bits);

	switch (l0.type.type) {
	case 0: case 2: case 1: // Invalid
		update_fault(ctx, MMUFaultLevel::LEVEL0, MMUFaultType::TRANSLATION);
		return true;

	case 3: // Table
		return do_translate_l1(va, l0.table.next << 12, ctx);

	default:
		return false;
	}
}

static bool do_translate(gva_t va, AddressTranslationContext& ctx)
{
	ctx.result = AddressTranslationResult::FAULT;

	if (va >= 0xffff000000000000ull) {
		return do_translate_l0(va, captive::arch::CPU::get_active_cpu()->get_page_table_base(1), ctx);
	} else if (va < 0x1000000000000ull) {
		return do_translate_l0(va, captive::arch::CPU::get_active_cpu()->get_page_table_base(0), ctx);
	} else {
		update_fault(ctx, MMUFaultLevel::LEVEL0, MMUFaultType::TRANSLATION);
		return true;
	}
}

bool AArch64MMU::translate(gva_t va, AddressTranslationContext& ctx)
{
	return do_translate(va, ctx);

	/*captive::arch::MMU::resolution_context rctx(va);
	rctx.emulate_user = false;
	
	switch (ctx.privilege) {
	case AddressTranslationPrivilege::SUPERVISOR:
		switch (ctx.type) {
		case AddressTranslationType::READ: rctx.requested_permissions = captive::arch::MMU::KERNEL_READ; break;
		case AddressTranslationType::WRITE: rctx.requested_permissions = captive::arch::MMU::KERNEL_WRITE; break;
		case AddressTranslationType::FETCH: rctx.requested_permissions = captive::arch::MMU::KERNEL_FETCH; break;
		}
		break;
		
	case AddressTranslationPrivilege::USER:
		switch (ctx.type) {
		case AddressTranslationType::READ: rctx.requested_permissions = captive::arch::MMU::USER_READ; break;
		case AddressTranslationType::WRITE: rctx.requested_permissions = captive::arch::MMU::USER_WRITE; break;
		case AddressTranslationType::FETCH: rctx.requested_permissions = captive::arch::MMU::USER_FETCH; break;
		}
		break;
	}
	
	if (!captive::arch::CPU::get_active_cpu()->mmu().resolve_gpa(rctx, true)) {
		return false;
	}
		
	ctx.pa = rctx.pa;
	ctx.private_data = rctx.private_data;
	ctx.result = rctx.fault == captive::arch::MMU::NONE ? AddressTranslationResult::OK : AddressTranslationResult::FAULT;
	
	if (ctx.result == AddressTranslationResult::FAULT) {
		//printf("GUEST PAGE FAULT PC=%p, VA=%p, TYPE=%u PRIV=%u\n", read_pc(), va, ctx.type, ctx.privilege);
	}*/

	return true;
}
