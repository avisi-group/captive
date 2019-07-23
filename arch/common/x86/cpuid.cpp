/* SPDX-License-Identifier: MIT */

#include <x86/cpuid.h>
#include <printf.h>

using namespace captive::arch::x86;

cpuid_feature features[] = {
	{ .function = 1, .index = 0, .part = 3, .bit = 0, .name = "fpu"},
	{ .function = 1, .index = 0, .part = 3, .bit = 1, .name = "vme"},
	{ .function = 1, .index = 0, .part = 3, .bit = 2, .name = "de"},
	{ .function = 1, .index = 0, .part = 3, .bit = 3, .name = "pse"},
	{ .function = 1, .index = 0, .part = 3, .bit = 4, .name = "tsc"},
	{ .function = 1, .index = 0, .part = 3, .bit = 5, .name = "msr"},
	{ .function = 1, .index = 0, .part = 3, .bit = 6, .name = "pae"},
	{ .function = 1, .index = 0, .part = 3, .bit = 7, .name = "mce"},
	{ .function = 1, .index = 0, .part = 3, .bit = 8, .name = "cx8"},
	{ .function = 1, .index = 0, .part = 3, .bit = 9, .name = "apic"},
	{ .function = 1, .index = 0, .part = 3, .bit = 11, .name = "sep"},
	{ .function = 1, .index = 0, .part = 3, .bit = 12, .name = "mtrr"},
	{ .function = 1, .index = 0, .part = 3, .bit = 13, .name = "pge"},
	{ .function = 1, .index = 0, .part = 3, .bit = 14, .name = "mca"},
	{ .function = 1, .index = 0, .part = 3, .bit = 15, .name = "cmov"},
	{ .function = 1, .index = 0, .part = 3, .bit = 16, .name = "pat"},
	{ .function = 1, .index = 0, .part = 3, .bit = 17, .name = "pse-36"},
	{ .function = 1, .index = 0, .part = 3, .bit = 18, .name = "psn"},
	{ .function = 1, .index = 0, .part = 3, .bit = 19, .name = "clfsh"},
	{ .function = 1, .index = 0, .part = 3, .bit = 21, .name = "ds"},
	{ .function = 1, .index = 0, .part = 3, .bit = 22, .name = "acpi"},
	{ .function = 1, .index = 0, .part = 3, .bit = 23, .name = "mmx"},
	{ .function = 1, .index = 0, .part = 3, .bit = 24, .name = "fxsr"},
	{ .function = 1, .index = 0, .part = 3, .bit = 25, .name = "sse"},
	{ .function = 1, .index = 0, .part = 3, .bit = 26, .name = "sse2"},
	{ .function = 1, .index = 0, .part = 3, .bit = 27, .name = "ss"},
	{ .function = 1, .index = 0, .part = 3, .bit = 28, .name = "htt"},
	{ .function = 1, .index = 0, .part = 3, .bit = 29, .name = "tm"},
	{ .function = 1, .index = 0, .part = 3, .bit = 30, .name = "ia64"},
	{ .function = 1, .index = 0, .part = 3, .bit = 31, .name = "pbe"},

	{ .function = 1, .index = 0, .part = 2, .bit = 0, .name = "sse3"},
	{ .function = 1, .index = 0, .part = 2, .bit = 1, .name = "pclmulqdq"},
	{ .function = 1, .index = 0, .part = 2, .bit = 2, .name = "dtes64"},
	{ .function = 1, .index = 0, .part = 2, .bit = 3, .name = "monitor"},
	{ .function = 1, .index = 0, .part = 2, .bit = 4, .name = "ds-cpl"},
	{ .function = 1, .index = 0, .part = 2, .bit = 5, .name = "vmx"},
	{ .function = 1, .index = 0, .part = 2, .bit = 6, .name = "smx"},
	{ .function = 1, .index = 0, .part = 2, .bit = 7, .name = "est"},
	{ .function = 1, .index = 0, .part = 2, .bit = 8, .name = "tm2"},
	{ .function = 1, .index = 0, .part = 2, .bit = 9, .name = "ssse3"},
	{ .function = 1, .index = 0, .part = 2, .bit = 10, .name = "cntx-id"},
	{ .function = 1, .index = 0, .part = 2, .bit = 11, .name = "sdbg"},
	{ .function = 1, .index = 0, .part = 2, .bit = 12, .name = "fma"},
	{ .function = 1, .index = 0, .part = 2, .bit = 13, .name = "cx16"},
	{ .function = 1, .index = 0, .part = 2, .bit = 14, .name = "xtpr"},
	{ .function = 1, .index = 0, .part = 2, .bit = 15, .name = "pdcm"},
	{ .function = 1, .index = 0, .part = 2, .bit = 17, .name = "pcid"},
	{ .function = 1, .index = 0, .part = 2, .bit = 18, .name = "dca"},
	{ .function = 1, .index = 0, .part = 2, .bit = 19, .name = "sse4.1"},
	{ .function = 1, .index = 0, .part = 2, .bit = 20, .name = "sse4.2"},
	{ .function = 1, .index = 0, .part = 2, .bit = 21, .name = "x2apic"},
	{ .function = 1, .index = 0, .part = 2, .bit = 22, .name = "movbe"},
	{ .function = 1, .index = 0, .part = 2, .bit = 23, .name = "popcnt"},
	{ .function = 1, .index = 0, .part = 2, .bit = 24, .name = "tsc-deadline"},
	{ .function = 1, .index = 0, .part = 2, .bit = 25, .name = "aes"},
	{ .function = 1, .index = 0, .part = 2, .bit = 26, .name = "xsave"},
	{ .function = 1, .index = 0, .part = 2, .bit = 27, .name = "osxsave"},
	{ .function = 1, .index = 0, .part = 2, .bit = 28, .name = "avx"},
	{ .function = 1, .index = 0, .part = 2, .bit = 29, .name = "f16c"},
	{ .function = 1, .index = 0, .part = 2, .bit = 30, .name = "rdrnd"},
	{ .function = 1, .index = 0, .part = 2, .bit = 31, .name = "hypervisor"},

	{ .function = 7, .index = 0, .part = 1, .bit = 0, .name = "fsgsbase"},
	{ .function = 7, .index = 0, .part = 1, .bit = 14, .name = "mpx"},

	{ .function = 13, .index = 0, .part = 0, .bit = 3, .name = "bndregs"},
	{ .function = 13, .index = 0, .part = 0, .bit = 4, .name = "bndcsr"},
};

struct cpuid_value {
	uint32_t eax, ebx, ecx, edx;
};

static struct {

	struct {
		bool valid;
		cpuid_value value;
	} indicies[64];
} cpuid_cache[64];

static const cpuid_value *get_cpuid(int function, int index)
{
	if (function > 63 || index > 63) fatal("uncacheable cpuid");

	if (!cpuid_cache[function].indicies[index].valid) {
		uint32_t eax, ebx, ecx, edx;
		eax = function;
		ecx = index;

		asm volatile("cpuid" : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) : "a"(eax), "c"(ecx));

		cpuid_cache[function].indicies[index].value.eax = eax;
		cpuid_cache[function].indicies[index].value.ebx = ebx;
		cpuid_cache[function].indicies[index].value.ecx = ecx;
		cpuid_cache[function].indicies[index].value.edx = edx;
	}

	return &cpuid_cache[function].indicies[index].value;
}

static void dump_feature(const cpuid_feature *feature)
{
	const cpuid_value *cv = get_cpuid(feature->function, feature->index);

	uint32_t part_value = 0;
	switch (feature->part) {
	case 0: part_value = cv->eax;
		break;
	case 1: part_value = cv->ebx;
		break;
	case 2: part_value = cv->ecx;
		break;
	case 3: part_value = cv->edx;
		break;
	}

	if (part_value & (1u << feature->bit)) {
		printf("%s ", feature->name);

		if (feature->rq == feature_requirement::forbidden) {
			fatal("forbidden feature active\n");
		}
	} else {
		if (feature->rq == feature_requirement::required) {
			fatal("required feature missing\n");
		}
	}
}

void captive::arch::x86::dump_cpu_features()
{
	printf("cpu features:\n  ");
	for (int feature_index = 0; feature_index < ARRAY_SIZE(features); feature_index++) {
		dump_feature(&features[feature_index]);
	}
	printf("\n");
}
