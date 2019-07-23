/* SPDX-License-Identifier: MIT */

#include <dbt/feature-manager.h>
#include <cpu.h>
#include <printf.h>

using namespace captive::arch::jit;

FeatureManager::FeatureManager(CPU& cpu) : _cpu(cpu)
{

}

uint32_t FeatureManager::active_features() const
{
	return (uint32_t)_cpu.jit_state.active_features;
}

uint32_t FeatureManager::get_feature(uint32_t feature) const
{
	uint64_t mask = (1ull << feature);
	return !!(_cpu.jit_state.active_features & mask);
}

void FeatureManager::set_feature(uint32_t feature, uint32_t value)
{
	uint64_t mask = (1ull << feature);

	if (value) {
		_cpu.jit_state.active_features |= mask;
	} else {
		_cpu.jit_state.active_features &= ~mask;
	}
}
