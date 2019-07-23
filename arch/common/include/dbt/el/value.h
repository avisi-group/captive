/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/common.h>

namespace captive {
	namespace arch {
		namespace dbt {
			namespace el {
				class Type;

				class Value {
				public:

					Value() : _allocated_regid(0), _allocated(false)
					{
					}

					virtual const Type& type() const = 0;
					void allocate(dbt_u64 regid);

				protected:
					dbt_u64 _allocated_regid;
					bool _allocated;
				};
			}
		}
	}
}
