/* SPDX-License-Identifier: MIT */

#include <x86/fpu.h>
#include <printf.h>

using namespace captive::arch::x86;

FPU::MXCSR FPU::get_mxcsr()
{
	MXCSR val;
	asm volatile("stmxcsr %0" : "=m"(val));

	return val;
}

void FPU::set_mxcsr(const MXCSR& val)
{
	asm volatile("ldmxcsr %0" ::"m"(val));
}

FPU::FPUCW FPU::get_fpucw()
{
	FPUCW val;
	asm volatile("fstcw %0" : "=m"(val));

	return val;
}

void FPU::set_fpucw(const FPUCW& val)
{
	asm volatile("fldcw %0" ::"m"(val));
}

uint64_t FPU::get_xcr0()
{
	uint32_t a, d, c = 0;
	asm volatile("xgetbv" : "=a"(a), "=d"(d) : "c"(c));

	return(uint64_t) a | ((uint64_t) d << 32);
}

void FPU::set_xcr0(uint64_t val)
{
	uint32_t a = (val & 0xffffffff), d = ((val >> 32) & 0xffffffff), c = 0;

	printf("set xcr0=%08x:%08x\n", d, a);
	asm volatile("xsetbv" ::"a"(a), "d"(d), "c"(c));
}

void FPU::rounding_mode(RoundingMode rmode)
{
	MXCSR mxcsr = get_mxcsr();
	mxcsr.RoundingControl = (int) rmode;
	set_mxcsr(mxcsr);

	FPUCW fpucw = get_fpucw();
	fpucw.RoundingControl = (int) rmode;
	set_fpucw(fpucw);
}

RoundingMode FPU::rounding_mode()
{
	MXCSR mxcsr = get_mxcsr();
	return(RoundingMode) mxcsr.RoundingControl;
}

void FPU::x87_precision(X87Precision precision)
{
	FPUCW fpucw = get_fpucw();
	fpucw.PrecisionControl = (int) precision;
	set_fpucw(fpucw);
}

X87Precision FPU::x87_precision()
{
	FPUCW fpucw = get_fpucw();
	return(X87Precision) fpucw.PrecisionControl;
}

FloatingPointExceptions FPU::current_exceptions()
{
	MXCSR mxcsr = get_mxcsr();

	FloatingPointExceptions r = (FloatingPointExceptions) 0;

	if (mxcsr.DenormalFlag) r = (FloatingPointExceptions) ((int) r | (int) FloatingPointExceptions::DenormalOperation);
	if (mxcsr.DivideByZeroFlag) r = (FloatingPointExceptions) ((int) r | (int) FloatingPointExceptions::DivideByZero);
	if (mxcsr.InvalidOperationFlag) r = (FloatingPointExceptions) ((int) r | (int) FloatingPointExceptions::InvalidOperation);
	if (mxcsr.OverflowFlag) r = (FloatingPointExceptions) ((int) r | (int) FloatingPointExceptions::Overflow);
	if (mxcsr.PrecisionFlag) r = (FloatingPointExceptions) ((int) r | (int) FloatingPointExceptions::Precision);
	if (mxcsr.UnderflowFlag) r = (FloatingPointExceptions) ((int) r | (int) FloatingPointExceptions::Underflow);

	return r;
}

void FPU::clear_exceptions(FloatingPointExceptions exceptions)
{
	MXCSR mxcsr = get_mxcsr();

	if ((int) exceptions & (int) FloatingPointExceptions::DenormalOperation) mxcsr.DenormalFlag = 0;
	if ((int) exceptions & (int) FloatingPointExceptions::DivideByZero) mxcsr.DivideByZeroFlag = 0;
	if ((int) exceptions & (int) FloatingPointExceptions::InvalidOperation) mxcsr.InvalidOperationFlag = 0;
	if ((int) exceptions & (int) FloatingPointExceptions::Overflow) mxcsr.OverflowFlag = 0;
	if ((int) exceptions & (int) FloatingPointExceptions::Precision) mxcsr.PrecisionFlag = 0;
	if ((int) exceptions & (int) FloatingPointExceptions::Underflow) mxcsr.UnderflowFlag = 0;

	set_mxcsr(mxcsr);
}

bool FPU::init()
{
	MXCSR mxcsr;
	mxcsr.reserved = 0;
	mxcsr.DenormalFlag = 0;
	mxcsr.DenormalOperationMask = 1;
	mxcsr.DivideByZeroFlag = 0;
	mxcsr.DivideByZeroMask = 1;
	mxcsr.InvalidOperationFlag = 0;
	mxcsr.InvalidOperationMask = 1;
	mxcsr.OverflowFlag = 0;
	mxcsr.OverflowMask = 1;
	mxcsr.PrecisionFlag = 0;
	mxcsr.PrecisionMask = 1;
	mxcsr.UnderflowFlag = 0;
	mxcsr.UnderflowMask = 1;

	mxcsr.DenormalsAreZeros = 0;
	mxcsr.FlushToZero = 0;
	mxcsr.RoundingControl = 0;

	set_mxcsr(mxcsr);

	uint64_t xcr0 = get_xcr0();
	xcr0 |= 7;
	set_xcr0(xcr0);

	return true;
}

void FPU::dump_state()
{
	MXCSR mxcsr = get_mxcsr();

	printf("  xcr0 = %016lx\n", get_xcr0());
	printf("  mxcsr.invalid-operation = %x\n", mxcsr.InvalidOperationFlag);
	printf("  mxcsr.rounding-control = %x\n", mxcsr.RoundingControl);
}
