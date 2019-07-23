/* SPDX-License-Identifier: MIT */

#include <dbt/mc/x86/encoder.h>

using namespace captive::arch::dbt::mc::x86;

#define REX  0x40
#define REX_B 0x41
#define REX_X 0x42
#define REX_R 0x44
#define REX_W 0x48

#define SEG_OVERRIDE_FS  0x64
#define SEG_OVERRIDE_GS  0x65
#define OPER_SIZE_OVERRIDE 0x66
#define ADDR_SIZE_OVERRIDE 0x67

bool Encoder::requires_rex(const Operand& reg) const
{
	return(reg.is_reg() &&
			reg.reg.width == 8 &&
			(reg.reg.reg == X86PhysicalRegisters::SP ||
			reg.reg.reg == X86PhysicalRegisters::BP ||
			reg.reg.reg == X86PhysicalRegisters::SI ||
			reg.reg.reg == X86PhysicalRegisters::DI));
}

bool Encoder::encode_sse_opcode_modrm(TranslatedCodeBuffer& tcb, dbt_u16 opcode, const Operand& reg, const Operand& rm, bool no_operand_prefix)
{
	// Make sure we have REG/REG or REG/MEM
	assert_true((reg.is_reg() && rm.is_reg()) || (reg.is_reg() && rm.is_mem()), "invalid operands to modrm", _current);

	//assert_true((reg.is_reg() && rm.is_reg()) && (reg.reg.width == rm.reg.width), "reg-reg must have same width", _current);
	//assert_true((reg.is_reg() && rm.is_mem()) && (reg.reg.width == rm.mem.access_width), "reg-mem must have same width", _current);

	assert_true((reg.reg.reg.is_sse() && (reg.reg.width == 128)) || reg.reg.reg.is_gpr(), "invalid size for reg in sse modrm", _current);

	// (1) If RM is a memory operand, then check for various overrides
	if (rm.is_mem()) {
		// (1.1) Check for segment overrides
		if (rm.mem.segment_override == X86PhysicalRegisters::FS) {
			tcb.emit8(SEG_OVERRIDE_FS);
		} else if (rm.mem.segment_override == X86PhysicalRegisters::GS) {
			tcb.emit8(SEG_OVERRIDE_GS);
		}

		// (1.2) Emit an address-size override if the memory base is 32-bits
		if (rm.mem.address_width == 32) {
			tcb.emit8(ADDR_SIZE_OVERRIDE);
		}
	}

	// (2) Emit an operand-size override if the reg (or rm, if register) operand is 128-bits
	if (!no_operand_prefix && (reg.reg.width == 128 || (rm.is_reg() && rm.reg.width == 128))) {
		if (reg.reg.width == 128 && ((rm.is_reg() && rm.reg.width == 128) || (rm.is_mem() && rm.mem.access_width == 64))) {
			switch (opcode) {
			case 0x17e:
				tcb.emit8(0xF3);
				break;
			default:
				tcb.emit8(OPER_SIZE_OVERRIDE);
				break;
			}
		} else {
			tcb.emit8(OPER_SIZE_OVERRIDE);
		}
	}

	// (3) Prepare a REX prefix (if necessary)
	dbt_u8 rex = 0;

	// (3.1) If the reg operand is a high register, emit a REX_R
	if (reg.reg.reg.needs_extension()) {
		rex |= REX_R;
	}

	// 
	if ((rm.is_reg() && rm.reg.reg.is_gpr() && rm.reg.width == 64) || (rm.is_mem() && rm.mem.access_width == 64) || (reg.reg.reg.is_gpr() && reg.reg.width == 64)) {
		rex |= REX_W;
	}

	// (3.2) If the base operand is a high register, emit a REX_B
	if ((rm.is_mem() && rm.mem.base_register.needs_extension()) || (rm.is_reg() && rm.reg.reg.needs_extension())) {
		rex |= REX_B;
	}

	// (3.3) If the index operand is a high register, emit a REX_X
	if (rm.is_mem() && rm.mem.index_register.needs_extension()) {
		rex |= REX_X;
	}

	// If we are to emit a REX prefix, do that now.
	if (rex) {
		tcb.emit8(rex);
	}

	// Emit the opcode
	if (opcode > 0x100) {
		tcb.emit8(0x0f);
		if (opcode > 0x300) {
			tcb.emit8(0x3a);
		} else if (opcode > 0x200) {
			tcb.emit8(0x38);
		}
	}

	tcb.emit8(opcode & 0xff);

	// Emit the modrm
	return encode_mod_reg_rm(tcb, reg, rm);
}

bool Encoder::encode_opcode_modrm(TranslatedCodeBuffer& tcb, dbt_u16 opcode, const Operand& reg, const Operand& rm, bool omit_operand_size_override, bool inhibit_66)
{
	// Make sure we have REG/REG or REG/MEM
	assert_true((reg.is_reg() && rm.is_reg()) || (reg.is_reg() && rm.is_mem()), "invalid operands to modrm", nullptr);

	assert_true(
			reg.reg.width == 8 ||
			reg.reg.width == 16 ||
			reg.reg.width == 32 ||
			reg.reg.width == 64,
			"invalid size for reg in modrm",
			_current);

	//assert(rm.base.size == 4 || rm.base.size == 8 || rm.base == REG_RIZ || rm.base == REG_RIP);

	// Figure out what prefixes are needed (if any)

	// (1) If RM is a memory operand, then check for various overrides
	if (rm.is_mem()) {
		if (rm.mem.base_register == X86PhysicalRegisters::R13) {
			assert_true(false, "R13 BASE", _current);
		}

		// (1.1) Check for segment overrides
		if (rm.mem.segment_override == X86PhysicalRegisters::FS) {
			tcb.emit8(SEG_OVERRIDE_FS);
		} else if (rm.mem.segment_override == X86PhysicalRegisters::GS) {
			tcb.emit8(SEG_OVERRIDE_GS);
		}

		// (1.2) Emit an address-size override if the memory base is 32-bits
		if (rm.mem.address_width == 32) {
			tcb.emit8(ADDR_SIZE_OVERRIDE);
		}
	}

	// (2) Emit an operand-size override if the reg (or rm, if register) operand is 16-bits
	if ((reg.reg.width == 16 || (rm.is_reg() && rm.reg.width == 16)) && !inhibit_66) {
		tcb.emit8(OPER_SIZE_OVERRIDE);
	}

	// (3) Prepare a REX prefix (if necessary)
	dbt_u8 rex = 0;

	// (3.1) Any REX prefix will do to access the new registers
	if (requires_rex(reg) || requires_rex(rm)) {
		rex |= REX;
	}

	// (3.2) If the reg operand is 64-bits, emit a REX_W (unless we're doing a creg/jmp)
	if (reg.reg.width == 64 && !omit_operand_size_override) {
		rex |= REX_W;
	}

	// (3.3) If the reg operand is a high register, emit a REX_R
	if (reg.reg.reg.needs_extension()) {
		rex |= REX_R;
	}

	// (3.4) If the base operand is a high register, emit a REX_B
	if ((rm.is_mem() && rm.mem.base_register.needs_extension()) || (rm.is_reg() && rm.reg.reg.needs_extension())) {
		rex |= REX_B;
	}

	// (3.5) If the index operand is a high register, emit a REX_X
	if (rm.is_mem() && rm.mem.index_register.needs_extension()) {
		rex |= REX_X;
	}

	// If we are to emit a REX prefix, do that now.
	if (rex) {
		tcb.emit8(rex);
	}

	// Emit the opcode
	if (opcode > 0x100) {
		tcb.emit8(0x0f);
	}

	tcb.emit8(opcode & 0xff);

	// Emit the modrm
	return encode_mod_reg_rm(tcb, reg, rm);
}

bool Encoder::encode_opcode_modrm_oper(TranslatedCodeBuffer& tcb, dbt_u16 opcode, dbt_u8 oper, const Operand& rm, bool omit_operand_override)
{
	// Make sure we have REG/REG or REG/MEM
	assert_true(rm.is_reg() || rm.is_mem(), "modrm-oper: rm must be reg or mem", nullptr);

	// Figure out what prefixes are needed (if any)

	// (1) If RM is a memory operand, then check for various overrides
	if (rm.is_mem()) {
		if (rm.mem.base_register == X86PhysicalRegisters::R13) {
			assert_true(false, "R13 BASE", _current);
		}

		// (1.1) Check for segment overrides
		if (rm.mem.segment_override == X86PhysicalRegisters::FS) {
			tcb.emit8(SEG_OVERRIDE_FS);
		} else if (rm.mem.segment_override == X86PhysicalRegisters::GS) {
			tcb.emit8(SEG_OVERRIDE_GS);
		}

		// (1.2) Emit an address-size override if the memory base is 32-bits
		if (rm.mem.address_width == 32) {
			tcb.emit8(ADDR_SIZE_OVERRIDE);
		}
	}

	// (2) Emit an operand-size override if the reg operand is 16-bits
	if (rm.is_reg() && rm.reg.width == 16) {
		tcb.emit8(OPER_SIZE_OVERRIDE);
	}

	// (3) Prepare a REX prefix (if necessary)
	dbt_u8 rex = 0;

	// (3.1) Any REX prefix will do to access the new registers
	if (requires_rex(rm)) {
		rex |= REX;
	}

	// (3.2) If the rm operand is 64-bits, emit a REX_W
	if (!omit_operand_override && ((rm.is_reg() && rm.reg.width == 64) || (rm.is_mem() && rm.mem.access_width == 64))) {
		rex |= REX_W;
	}

	// (3.4) If the base operand is a high register, emit a REX_B
	if ((rm.is_mem() && rm.mem.base_register.needs_extension()) || (rm.is_reg() && rm.reg.reg.needs_extension())) {
		rex |= REX_B;
	}

	// (3.5) If the index operand is a high register, emit a REX_X
	if (rm.is_mem() && rm.mem.index_register.needs_extension()) {
		rex |= REX_X;
	}

	// If we are to emit a REX prefix, do that now.
	if (rex) {
		tcb.emit8(rex);
	}

	// Emit the opcode
	if (opcode > 0x100) {
		tcb.emit8(0x0f);
	}

	tcb.emit8(opcode & 0xff);

	// Emit the modrm
	return encode_mod_reg_rm_oper(tcb, oper, rm);
}

bool Encoder::encode_mod_reg_rm(TranslatedCodeBuffer& tcb, const Operand& reg, const Operand& rm)
{
	assert_true(reg.is_reg(), "modrm: reg must be a register", nullptr);
	return encode_mod_reg_rm_oper(tcb, reg.reg.reg.raw_index(), rm);
}

bool Encoder::encode_mod_reg_rm_oper(TranslatedCodeBuffer& tcb, dbt_u8 mreg, const Operand& rm)
{
	if (rm.is_reg()) {
		dbt_u8 mod = 3;
		dbt_u8 mrm = rm.reg.reg.raw_index();

		tcb.emit8(((mod & 3) << 6) | ((mreg & 7) << 3) | (mrm & 7));
		return true;
	} else if (rm.is_mem()) {
		dbt_u8 mod, mrm;

		if (rm.mem.base_register == X86PhysicalRegisters::R13) {
			assert_true(false, "R13 BASE", _current);
		}

		if (rm.mem.displacement == 0 || (rm.mem.base_register == X86PhysicalRegisters::RIZ && rm.mem.index_register == X86PhysicalRegisters::RIZ) || (rm.mem.base_register == X86PhysicalRegisters::RIP)) {
			mod = 0;
		} else if (rm.mem.displacement < 128 && rm.mem.displacement > -127) {
			mod = 1;
		} else {
			mod = 2;
		}

		if (rm.mem.base_register == X86PhysicalRegisters::SP) {
			mrm = 4; // Need a SIB byte
		} else if (rm.mem.base_register == X86PhysicalRegisters::R12) {
			mrm = 4; // Need a SIB byte
		} else if (rm.mem.base_register == X86PhysicalRegisters::RIP) {
			mrm = 5;
		} else if (rm.mem.base_register == X86PhysicalRegisters::RIZ) {
			mrm = 4; // Need a SIB byte
		} else if (rm.mem.scale != MemoryScale::S1 || rm.mem.index_register != X86PhysicalRegisters::RIZ) { // TODO: LOOK AT THIS
			mrm = 4; // Need a SIB byte
		} else {
			mrm = rm.mem.base_register.raw_index();
		}

		if (mod == 0 && (rm.mem.base_register == X86PhysicalRegisters::BP)) {
			mod = 1;
		} else if (mod == 0 && (rm.mem.base_register == X86PhysicalRegisters::R13)) {
			mod = 1;
		}

		if (mrm == 4 && (rm.mem.base_register == X86PhysicalRegisters::RIZ)) {
			mod = 0;
		} else if (mrm == 4 && (rm.mem.base_register == X86PhysicalRegisters::BP)) {
			if (mod == 0) mod = 1;
		}

		// Emit the MODRM byte
		tcb.emit8((mod & 3) << 6 | (mreg & 7) << 3 | (mrm & 7));

		// Determine if we need to emit a SIB byte (mod cannot be 3 here)
		if (mrm == 4) {
			dbt_u8 s, i, b;

			switch (rm.mem.scale) {
			case MemoryScale::S1:
				s = 0;
				if (rm.mem.base_register == X86PhysicalRegisters::RIZ) {
					i = 4;
					b = 5;
				} else if (rm.mem.base_register.raw_index() == 5) {
					if (rm.mem.base_register == X86PhysicalRegisters::BP || rm.mem.base_register == X86PhysicalRegisters::R13) {
						// OK
					} else {
						i = 0;
						b = 0;
						_support.assertion_fail("modrm: invalid encoding");
					}
				} else {
					i = 4;
					b = rm.mem.base_register.raw_index();
				}

				break;
			case MemoryScale::S2: s = 1;
				break;
			case MemoryScale::S4: s = 2;
				break;
			case MemoryScale::S8:
				s = 3;
				if (rm.mem.base_register == X86PhysicalRegisters::RIZ) {
					b = 5;
				}
				break;
			default:
				return false;
			}

			if (rm.mem.index_register == X86PhysicalRegisters::RIZ) {
				i = 4;
			} else {
				i = rm.mem.index_register.raw_index();
			}

			if (rm.mem.base_register == X86PhysicalRegisters::RIZ) {
				b = 5;
			} else if (rm.mem.base_register == X86PhysicalRegisters::BP || rm.mem.base_register == X86PhysicalRegisters::R13) {
				b = 5;
			} else if (rm.mem.base_register.raw_index() == 5) {
				b = 0;
				_support.assertion_fail("modrm: unsupported encoding");
			} else {
				b = rm.mem.base_register.raw_index();
			}

			tcb.emit8((s & 3) << 6 | (i & 7) << 3 | (b & 7));
		}

		if (mod == 0 && (rm.mem.base_register == X86PhysicalRegisters::BP || rm.mem.base_register == X86PhysicalRegisters::R13)) {
			_support.assertion_fail("something's up");
		}

		if (mod == 1) {
			tcb.emit8(rm.mem.displacement);
		} else if (mod == 2 || (mod == 0 && rm.mem.base_register == X86PhysicalRegisters::RIZ) || (rm.mem.base_register == X86PhysicalRegisters::RIZ && rm.mem.index_register == X86PhysicalRegisters::RIZ) || (rm.mem.base_register == X86PhysicalRegisters::RIP)) {
			tcb.emit32(rm.mem.displacement);
		}
		return true;
	} else {
		_support.assertion_fail("modrm: rm must be a reg or mem");
		return false;
	}
}
