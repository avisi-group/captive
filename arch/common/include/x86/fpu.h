/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace x86 {

			enum class RoundingMode {
				RoundToNearest = 0,
				RoundDown = 1,
				RoundUp = 2,
				RoundToZero = 3
			};

			enum class X87Precision {
				Single = 0,
				Reserved = 1,
				Double = 2,
				DoubleExtended = 3
			};

			enum class FloatingPointExceptions {
				InvalidOperation = 1,
				DenormalOperation = 2,
				DivideByZero = 4,
				Overflow = 8,
				Underflow = 16,
				Precision = 32
			};

			class FPU {
			public:
				static bool init();
				static void dump_state();

				static void rounding_mode(RoundingMode rmode);
				static RoundingMode rounding_mode();

				static void x87_precision(X87Precision precision);
				static X87Precision x87_precision();

				static FloatingPointExceptions current_exceptions();
				static void clear_exceptions(FloatingPointExceptions exceptions);

			private:

				struct MXCSR {
					uint32_t InvalidOperationFlag : 1;
					uint32_t DenormalFlag : 1;
					uint32_t DivideByZeroFlag : 1;
					uint32_t OverflowFlag : 1;
					uint32_t UnderflowFlag : 1;
					uint32_t PrecisionFlag : 1;
					uint32_t DenormalsAreZeros : 1;
					uint32_t InvalidOperationMask : 1;
					uint32_t DenormalOperationMask : 1;
					uint32_t DivideByZeroMask : 1;
					uint32_t OverflowMask : 1;
					uint32_t UnderflowMask : 1;
					uint32_t PrecisionMask : 1;
					uint32_t RoundingControl : 2;
					uint32_t FlushToZero : 1;
					uint32_t reserved : 16;
				} packed;

				struct FPUCW {
					uint32_t InvalidOperation : 1;
					uint32_t DenormalOperand : 1;
					uint32_t ZeroDivide : 1;
					uint32_t Overflow : 1;
					uint32_t Underflow : 1;
					uint32_t Precision : 1;
					uint32_t Reserved0 : 2;
					uint32_t PrecisionControl : 2;
					uint32_t RoundingControl : 2;
					uint32_t InfinityControl : 1;
					uint32_t Reserved1 : 3;
				} packed;

				static MXCSR get_mxcsr();
				static void set_mxcsr(const MXCSR& val);

				static FPUCW get_fpucw();
				static void set_fpucw(const FPUCW& val);

				static uint64_t get_xcr0();
				static void set_xcr0(uint64_t val);
			};
		}
	}
}
