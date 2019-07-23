/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/common.h>

namespace captive {
	namespace arch {
		namespace dbt {
			namespace mc {
				namespace x86 {
					namespace X86RegisterClasses {

						enum X86RegisterClasses {
							GENERAL_PURPOSE,
							SSE,
							FLAGS,
							SEGMENT,
							CONTROL,
							ZERO,
							PC
						};
					}

					class X86PhysicalRegisters;

					class X86PhysicalRegister {
						friend class X86PhysicalRegisters;

					public:

						bool operator==(const X86PhysicalRegister& other) const
						{
							return _unique_index == other._unique_index;
						}

						bool operator!=(const X86PhysicalRegister& other) const
						{
							return !(*this == other);
						}

						const char *name() const
						{
							return "?";
						}

						dbt_u64 unique_index() const
						{
							return _unique_index;
						}

						dbt_u64 raw_index() const
						{
							return _raw_index;
						}

						bool is_gpr() const
						{
							return _regclass == X86RegisterClasses::GENERAL_PURPOSE;
						}

						bool is_sse() const
						{
							return _regclass == X86RegisterClasses::SSE;
						}

						bool is_virtual() const
						{
							return _virtual;
						}

						bool is_special() const
						{
							return !(is_gpr() || is_sse());
						}

						void make_virtual()
						{
							_virtual = true;
						}

						bool needs_extension() const
						{
							return _needs_extension;
						}

						X86RegisterClasses::X86RegisterClasses regclass() const
						{
							return _regclass;
						}
					private:

						X86PhysicalRegister(X86RegisterClasses::X86RegisterClasses regclass, dbt_u64 unique_index, dbt_u64 raw_index, const char *name, bool needs_extension = false, bool is_virt = false)
						: _regclass(regclass),
						_unique_index(unique_index),
						_raw_index(raw_index),
						_needs_extension(needs_extension),
						_virtual(is_virt)
						{
						}

						X86RegisterClasses::X86RegisterClasses _regclass;
						dbt_u64 _unique_index, _raw_index;
						bool _needs_extension, _virtual;
					};

					class X86Registers;

					class X86Register {
						friend class X86Registers;

					public:

						const X86PhysicalRegister& physical_register() const
						{
							return _physical_register;
						}

						dbt_u8 width_in_bits() const
						{
							return _width;
						}

						const char *name() const
						{
							return _name;
						}

						bool operator==(const X86Register& other) const
						{
							return _physical_register == other._physical_register && _width == other._width;
						}

						bool operator!=(const X86Register& other) const
						{
							return !(*this == other);
						}

					private:

						X86Register(const X86PhysicalRegister& physical_register, dbt_u8 width, const char *name)
						: _physical_register(physical_register),
						_width(width),
						_name(name)
						{
						}

						const X86PhysicalRegister& _physical_register;
						dbt_u8 _width;
						const char *_name;
					};

					class X86Registers {
					public:
						static const X86Register AL, AH, AX, EAX, RAX;
						static const X86Register BL, BH, BX, EBX, RBX;
						static const X86Register CL, CH, CX, ECX, RCX;
						static const X86Register DL, DH, DX, EDX, RDX;
						static const X86Register SIL, SI, ESI, RSI;
						static const X86Register DIL, DI, EDI, RDI;
						static const X86Register BPL, BP, EBP, RBP;
						static const X86Register SPL, SP, ESP, RSP;
						static const X86Register R8B, R8W, R8D, R8;
						static const X86Register R9B, R9W, R9D, R9;
						static const X86Register R10B, R10W, R10D, R10;
						static const X86Register R11B, R11W, R11D, R11;
						static const X86Register R12B, R12W, R12D, R12;
						static const X86Register R13B, R13W, R13D, R13;
						static const X86Register R14B, R14W, R14D, R14;
						static const X86Register R15B, R15W, R15D, R15;
					};

					class X86PhysicalRegisters {
					public:
						static const X86PhysicalRegister A, B, C, D, SP, BP, SI, DI;
						static const X86PhysicalRegister R8, R9, R10, R11, R12, R13, R14, R15;

						static const X86PhysicalRegister XMM0, XMM1, XMM2, XMM3, XMM4, XMM5, XMM6, XMM7;
						static const X86PhysicalRegister XMM8, XMM9, XMM10, XMM11, XMM12, XMM13, XMM14, XMM15;

						static const X86PhysicalRegister RIZ, RIP, RFLAGS;
						static const X86PhysicalRegister CS, DS, ES, FS, GS, SS;
						static const X86PhysicalRegister CR3;

						static X86PhysicalRegister create_virtual(X86RegisterClasses::X86RegisterClasses regclass, dbt_u32 virtual_id);

						static const X86PhysicalRegister& get_by_unique_index(dbt_u64 unique_index);
					};
				}
			}
		}
	}
}
