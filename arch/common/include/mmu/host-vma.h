/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace mmu {

			enum class MappingTargetGranularity {
				Granularity4K,
				Granularity2M,
				Granularity1G,
			};

			struct MappingTarget {
				hpa_t pa;

				MappingTargetGranularity granularity;

				bool allow_write;
				bool allow_user;
				bool deny_exec;
				bool user_flags[3];
			};

			struct x86_pte;

			class HostVMA {
			public:
				HostVMA();

				HostVMA *shallow_clone() const;

				void insert_mapping(hva_t va, const MappingTarget& target);
				void remove_mapping(hva_t va);
				bool get_mapping(hva_t va, MappingTarget& target);
				bool update_mapping(hva_t va, const MappingTarget& target);

				void flush(hva_t va)
				{
					asm volatile("invlpg %0" ::"m"(va) : "memory");
				}

				void flush_all()
				{
					uint64_t x[2] = {0};
					asm volatile("invpcid %0, %1" ::"m"(x), "r"((uint64_t) 3) : "memory");
				}

				hpa_t get_pml4() const
				{
					return pml4;
				}

			private:
				hpa_t pml4;

				hpa_t alloc_page_table();

				template<bool CREATE>
				bool get_pte(hva_t va, x86_pte **pte);

				bool get_entry(hva_t va, void **te, MappingTargetGranularity *granularity);
			};
		}
	}
}
