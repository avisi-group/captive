/* SPDX-License-Identifier: MIT */

#include <dbt/el/value.h>

using namespace captive::arch::dbt::el;

void Value::allocate(dbt_u64 regid)
{
	_allocated_regid = regid;
	_allocated = true;
}
