/* SPDX-License-Identifier: MIT */

#pragma once

namespace captive {
	namespace arch {
		namespace jit {
			namespace x86 {
				namespace emitters {

					class X86ALU {
					public:
						dbt::el::Value* adc(dbt::el::Value* lhs, dbt::el::Value* rhs, dbt::el::Value* carry);
					};
				}
			}
		}
	}
}