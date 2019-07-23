/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
		namespace mmu {

			enum class PageFaultResult {
				ABORT,
				CONTINUE,
				RESET
			};

			enum class PageFaultReason {
				UNKNOWN,
				NOT_PRESENT,
				READ_ONLY,
				SUPERVISOR_ONLY,
				NO_EXECUTE,
				PKEY
			};

			enum class PageFaultAccessType {
				KERNEL_READ,
				KERNEL_WRITE,
				USER_READ,
				USER_WRITE
			};

			class HostVMA;

			struct PageFaultContext {
				hva_t va, rip;
				hpa_t cr3;
				gva_t r14;

				PageFaultAccessType type;
				PageFaultReason reason;
				PageFaultResult result;
			};

			class HostMMU {
			public:

				HostMMU() : _initial_vma(nullptr), _current_vma(nullptr)
				{
				}

				bool initialise();

				template<bool PRIVILEGED = true >
				void activate_vma(const HostVMA& vma);

				const HostVMA& template_vma() const
				{
					return *_initial_vma;
				}

				const HostVMA& current_vma() const
				{
					return *_current_vma;
				}

				HostVMA& current_vma()
				{
					return *_current_vma;
				}

				void handle_page_fault(const PageFaultContext& context);

				template<bool PRIVILEGED = true >
				inline void flush(hva_t va)
				{
					asm volatile("invlpg %0" ::"m"(va) : "memory");
				}

				template<bool PRIVILEGED = true >
				void flush_all()
				{
					if (PRIVILEGED) {
						uint64_t x[2] = {0};
						asm volatile("invpcid %0, %1" ::"m"(x), "r"((uint64_t) 3) : "memory");
					} else {
						asm volatile("int $0x62" :: : "rdi");
					}
				}

				template<bool PRIVILEGED = true >
				inline void flush_range(hva_t va_from, hva_t va_to)
				{
					/*for (hva_t page = va_from; page < va_to; page += 0x1000) {
					    flush(page);
					}*/
					flush_all();
				}

			private:
				HostVMA *_initial_vma;
				HostVMA *_current_vma;
			};

			extern HostMMU host_mmu;
		}
	}
}
