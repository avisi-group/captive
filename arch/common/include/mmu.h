/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <malloc/page-allocator.h>
#include <printf.h>

extern "C" void __fast_zero_page(void *);

namespace captive {
	namespace arch {
		class CPU;

		struct entry_t {

			enum entry_flags_t {
				// PTE
				PRESENT = 1 << 0,
				WRITABLE = 1 << 1,
				ALLOW_USER = 1 << 2,
				WRITE_THROUGH = 1 << 3,
				CACHE_DISABLED = 1 << 4,
				ACCESSED = 1 << 5,
				DIRTY = 1 << 6,
				HUGE = 1 << 7,
				GLOBAL = 1 << 8,

				// CUSTOM
				DEVICE = 1 << 9,
				EXECUTED = 1 << 10,
				SYNC = 1 << 11,
			};

			uint64_t data;

			inline hpa_t base_address() const
			{
				return data & ~0xfffULL;
			}

			inline void base_address(hpa_t v)
			{
				data &= 0xfffULL;
				data |= v & ~0xfffULL;
			}

			inline uint16_t flags() const
			{
				return data & 0xfffULL;
			}

			inline void flags(uint16_t v)
			{
				data &= ~0xfffULL;
				data |= v & 0xfffULL;
			}

			inline uint8_t pk() const
			{
				return(data >> 59) & 0xf;
			}

			inline void pk(uint8_t v)
			{
				data &= ~(0xfull << 59);
				data |= ((uint64_t) v & 0xf) << 59;
			}

			inline bool present() const
			{
				return(flags() & PRESENT) == PRESENT;
			}

			inline void present(bool v)
			{
				if (v) flags(flags() | PRESENT);
				else flags(flags() & ~PRESENT);
			}

			inline bool dirty() const
			{
				return(flags() & DIRTY) == DIRTY;
			}

			inline void dirty(bool v)
			{
				if (v) flags(flags() | DIRTY);
				else flags(flags() & ~DIRTY);
			}

			inline bool writable() const
			{
				return(flags() & WRITABLE) == WRITABLE;
			}

			inline void writable(bool v)
			{
				if (v) flags(flags() | WRITABLE);
				else flags(flags() & ~WRITABLE);
			}

			inline bool allow_user() const
			{
				return get_flag(ALLOW_USER);
			}

			inline void allow_user(bool v)
			{
				set_flag(ALLOW_USER, v);
			}

			inline bool executed() const
			{
				return get_flag(EXECUTED);
			}

			inline void executed(bool v)
			{
				set_flag(EXECUTED, v);
			}

			inline bool device() const
			{
				return get_flag(DEVICE);
			}

			inline void device(bool v)
			{
				set_flag(DEVICE, v);
			}

			inline bool cache_disabled() const
			{
				return get_flag(CACHE_DISABLED);
			}

			inline void cache_disabled(bool v)
			{
				set_flag(CACHE_DISABLED, v);
			}

			inline bool write_through() const
			{
				return get_flag(WRITE_THROUGH);
			}

			inline void write_through(bool v)
			{
				set_flag(WRITE_THROUGH, v);
			}

			inline bool huge() const
			{
				return get_flag(HUGE);
			}

			inline void huge(bool v)
			{
				set_flag(HUGE, v);
			}

			inline bool sync() const
			{
				return get_flag(SYNC);
			}

			inline void sync(bool v)
			{
				set_flag(SYNC, v);
			}

			inline bool get_flag(entry_flags_t flag) const
			{
				return(flags() & (uint16_t) flag) == (uint16_t) flag;
			}

			inline void set_flag(entry_flags_t flag, bool v)
			{
				if (v) {
					flags(flags() | (uint16_t) flag);
				} else {
					flags(flags() & ~(uint16_t) flag);
				}
			}

			/*inline void dump() const {
				printf("mm: entry: data=%016lx, addr=%lx, flags=%x\n", data, base_address(), flags());
			}*/
		} packed;

		static_assert(sizeof(entry_t) == 8, "x86 page table entry must be 64-bits");

		typedef entry_t page_map_entry_t;
		typedef entry_t page_dir_ptr_entry_t;
		typedef entry_t page_dir_entry_t;
		typedef entry_t page_table_entry_t;

		struct page_map_t {
			page_map_entry_t entries[512];
		} packed;

		static_assert(sizeof(page_map_t) == 0x1000, "x86 page map must be 4096 bytes");

		struct page_dir_ptr_t {
			page_dir_ptr_entry_t entries[512];
		} packed;

		static_assert(sizeof(page_dir_ptr_t) == 0x1000, "x86 page directory pointer table must be 4096 bytes");

		struct page_dir_t {
			page_dir_entry_t entries[512];
		} packed;

		static_assert(sizeof(page_dir_t) == 0x1000, "x86 page directory table must be 4096 bytes");

		struct page_table_t {
			page_table_entry_t entries[512];
		} packed;

		static_assert(sizeof(page_table_t) == 0x1000, "x86 page table must be 4096 bytes");

		typedef uint16_t table_idx_t;

		class PCIDFlushPolicy {
		public:

			static inline void flush_page(hva_t addr, uint16_t pcid)
			{
				asm volatile("invlpg (%0)\n" ::"r"((uint64_t) addr) : "memory");
			}

			static inline void flush_tlb()
			{
				uint64_t x[2] = {0};
				asm volatile("invpcid %0, %1" ::"m"(x), "r"((uint64_t) 3) : "memory");
			}

			static inline void flush_tlb_global()
			{
				uint64_t x[2] = {0};
				asm volatile("invpcid %0, %1" ::"m"(x), "r"((uint64_t) 4) : "memory");
			}
		};

		class CR3FlushPolicy {
		public:

			static inline void flush_page(hva_t addr, uint16_t pcid)
			{
				asm volatile("invlpg (%0)\n" ::"r"((uint64_t) addr) : "memory");
			}

			static inline void flush_tlb_global()
			{
				uint64_t val;
				asm volatile("mov %%cr4, %0\n\t" : "=r"(val));
				asm volatile("mov %0, %%cr4\n\t" ::"r"(val) : "memory");
			}

			static void flush_tlb()
			{
				uint64_t val;
				asm volatile("mov %%cr3, %0\n\t" : "=r"(val));
				asm volatile("mov %0, %%cr3\n\t" ::"r"(val) : "memory");
			}
		};

		class MMU {
		public:
			using FlushPolicy = PCIDFlushPolicy;
			//using FlushPolicy = CR3FlushPolicy;

			enum resolution_fault {
				NONE,
				READ_FAULT,
				WRITE_FAULT,
				FETCH_FAULT,
				DEVICE_FAULT,
				SMC_FAULT
			};

			enum permissions {
				NO_PERMISSION = 0,
				USER_READ = 0x01,
				USER_WRITE = 0x02,
				USER_FETCH = 0x04,
				KERNEL_READ = 0x10,
				KERNEL_WRITE = 0x20,
				KERNEL_FETCH = 0x40,

				USER_READ_WRITE = 0x03,
				USER_READ_FETCH = 0x05,
				USER_ALL = 0x07,

				KERNEL_READ_WRITE = 0x30,
				KERNEL_READ_FETCH = 0x50,
				KERNEL_ALL = 0x70,

				ALL_WRITE = 0x22,
				ALL_READ_FETCH = 0x55,
				ALL_READ_WRITE = 0x33,
				ALL_READ_WRITE_FETCH = 0x77,
			};

			struct resolution_context {

				explicit resolution_context(gva_t va) : va(va)
				{
				}

				const gva_t va;
				gpa_t pa;

				enum permissions requested_permissions;
				enum permissions allowed_permissions;

				enum resolution_fault fault;

				bool emulate_user;

				uint64_t private_data;

				inline bool is_write() const
				{
					return !!(requested_permissions & (USER_WRITE | KERNEL_WRITE));
				}
			};

			MMU(CPU& cpu);
			virtual ~MMU();

			//bool enable();
			//bool disable();

			//bool enabled() const {
			//                return _enabled;
			//          }

			inline CPU& cpu() const
			{
				return _cpu;
			}

			//bool handle_fault(struct resolution_context& context);
			virtual bool resolve_gpa(struct resolution_context& context, bool have_side_effects = true) = 0;

			//bool translate_fetch(struct resolution_context& context);

			//inline uint32_t context_id() const {
			//  return _context_id;
			//}
			//void context_id(uint32_t ctxid);

			//MMUMode::MMUMode mode() const;
			//void mode(MMUMode::MMUMode mode);

			bool quick_fetch(gva_t va, gpa_t& pa, bool user_mode);

		protected:

			inline bool permit_access(const struct resolution_context& context) const
			{
				return !!(context.requested_permissions & context.allowed_permissions);
			}

		private:
			//void init_modes();
			//bool is_device(gpa_t pa);

			//MMUMode::MMUMode gva_to_mode(gva_t gva) const;

			//void sync_pte(const struct resolution_context& context, page_table_entry_t *pte);

			static uint64_t __force_order;

			static inline uint64_t read_cr4()
			{
				uint64_t val;
				asm volatile("mov %%cr4, %0\n\t" : "=r"(val), "=m"(__force_order));
				return val;
			}

			static inline void write_cr4(uint64_t val)
			{
				asm volatile("mov %0, %%cr4" ::"r"(val), "m"(__force_order));
			}

			static inline void flush_page(hva_t addr, uint16_t pcid)
			{
				FlushPolicy::flush_page(addr, pcid);
			}

			static inline void flush_tlb()
			{
				FlushPolicy::flush_tlb();
			}

			static void flush_tlb_safe();

			static inline void flush_tlb_global()
			{
				FlushPolicy::flush_tlb_global();
			}

			static inline void wbinvd()
			{
				asm volatile("wbinvd" :: : "memory");
			}

			inline uintptr_t alloc_pgt()
			{
				uintptr_t va = (uintptr_t) captive::arch::malloc::page_alloc.alloc_page();
				uintptr_t pa = vm_virt_to_phys((void *) va);

				__fast_zero_page((void *) va);
				return pa;
			}

#define BITS(val, start, end) ((((uint64_t)val) >> start) & (((1 << (end - start + 1)) - 1)))

			static inline void va_table_indicies(hva_t va, table_idx_t& pm, table_idx_t& pdp, table_idx_t& pd, table_idx_t& pt)
			{
				pm = BITS(va, 39, 47);
				pdp = BITS(va, 30, 38);
				pd = BITS(va, 21, 29);
				pt = BITS(va, 12, 20);
			}

			inline void get_va_table_entries(hva_t va, page_map_entry_t*& pm, page_dir_ptr_entry_t*& pdp, page_dir_entry_t*& pd, page_table_entry_t*& pt, bool allocate = true)
			{
				table_idx_t pm_idx = 0, pdp_idx, pd_idx, pt_idx;
				va_table_indicies(va, pm_idx, pdp_idx, pd_idx, pt_idx);

				uint64_t cr3val;
				asm volatile("mov %%cr3, %0\n\t" : "=r"(cr3val));

				// L4 read_cr3()
				pm = &((page_map_t *) vm_phys_to_virt(cr3val & ~0x8000000000000fffull))->entries[pm_idx];
				if (pm->base_address() == 0) {
					pm->base_address(alloc_pgt());
					pm->present(true);
					pm->writable(true);
					pm->allow_user(true);
				}

				// L3
				pdp = &((page_dir_ptr_t *) vm_phys_to_virt(pm->base_address()))->entries[pdp_idx];
				if (pdp->base_address() == 0) {
					pdp->base_address(alloc_pgt());
					pdp->present(true);
					pdp->writable(true);
					pdp->allow_user(true);
				}

				// L2
				pd = &((page_dir_t *) vm_phys_to_virt(pdp->base_address()))->entries[pd_idx];
				if (pd->base_address() == 0) {
					pd->base_address(alloc_pgt());
					pd->present(true);
					pd->writable(true);
					pd->allow_user(true);
				}

				if (pd->huge()) {
					pt = nullptr;
				} else {
					pt = &((page_table_t *) vm_phys_to_virt(pd->base_address()))->entries[pt_idx];
				}
			}

#undef BITS

			CPU& _cpu;
			uint32_t _context_id;
			bool _enabled;

			//page_map_t *_mode_to_pml4[5];
		};
	}
}
