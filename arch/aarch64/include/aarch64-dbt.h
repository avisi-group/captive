/* SPDX-License-Identifier: MIT */

#pragma once

#include <aarch64-jit2.h>

namespace captive {
	namespace arch {
		namespace aarch64 {
			template<bool T>
			using aarch64_dbt = aarch64_jit2<T>;
		}
	}
}