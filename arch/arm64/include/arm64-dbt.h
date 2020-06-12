/* SPDX-License-Identifier: MIT */

#pragma once

#include <arm64-jit2.h>

namespace captive {
	namespace arch {
		namespace arm64 {
			template<bool T>
			using arm64_dbt = arm64_jit2<T>;
		}
	}
}
