/* SPDX-License-Identifier: MIT */

#include <hypervisor/semihosting-context.h>

using namespace captive::hypervisor;

void *SemihostingContext::resolve_guest_ptr(gpa_t pa)
{
	void *out_addr;
	if (!guest().resolve_gpa(pa, out_addr)) return nullptr;
	return out_addr;
}
