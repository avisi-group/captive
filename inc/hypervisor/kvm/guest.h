/* SPDX-License-Identifier: MIT */
#pragma once

#include <list>
#include <map>
#include <unordered_map>

#include <sys/ioctl.h>

#include <define.h>
#include <shmem.h>

#include <hypervisor/guest.h>
#include <hypervisor/shared-memory.h>

#include <linux/kvm.h>

#include <util/range.h>

#define VM_PHYS_CODE_BASE   0ULL
#define VM_CODE_SIZE    0x080000000ULL
#define VM_PHYS_HEAP_BASE   0x100000000ULL
#define VM_HEAP_SIZE    0x100000000ULL
#define VM_PHYS_GPM_BASE   0x200000000ULL

#define VM_PHYS_LAPIC_BASE   0xfee00000ULL
#define VM_LAPIC_SIZE    0x1000ULL

#define VM_PHYS_GUEST_DATA   0x1000ULL
#define VM_PHYS_CPU_DATA   0x2000ULL
#define VM_PHYS_PRINTF_BUFFER  0x3000ULL
#define VM_PHYS_TRACE_BUFFER  0x4000ULL
#define VM_PHYS_GDT     0x5000ULL
#define VM_PHYS_TSS     0x5100ULL
#define VM_PHYS_IDT     0x6000ULL
#define VM_PHYS_KSTACK    0x7000ULL

#define VM_PHYS_PAGE_TABLES   0x10000ULL
#define VM_PHYS_PML4_0    VM_PHYS_PAGE_TABLES
#define VM_PHYS_PML4_1    (VM_PHYS_PML4_0 + 0x1000ULL)

#define VM_VIRT_SPLIT    0xffff800000000000ULL
#define VM_VIRT_KERNEL    0xffffffff80000000ULL

#define HOST_VIRT_GPM    0x680000000000ULL

extern void MMIOThreadTrampoline(void *);

namespace captive {
	namespace devices {
		class Device;
	}

	namespace hypervisor {
		namespace kvm {
			class KVM;
			class KVMCpu;
			class IRQFD;

			class KVMGuest : public Guest {
				friend class KVMCpu;
				friend class IRQFD;
				friend void ::MMIOThreadTrampoline(void *);

			public:
				KVMGuest(KVM& owner, engine::Engine& engine, platform::Platform& pfm, int fd);
				virtual ~KVMGuest();

				bool init(const util::config::Configuration& cfg) override;

				bool load(loader::Loader& loader) override;

				bool finalise_platform() override;

				inline bool initialised() const
				{
					return _initialised;
				}

				bool resolve_gpa(gpa_t gpa, void*& out_addr) const override;

				void do_guest_printf();

				bool run() override;
				void stop() override;

				void guest_entrypoint(gpa_t entrypoint) override;
				void guest_stackpointer(gpa_t stackpointer) override;
				void debug_interrupt(int code) override;

			private:
				volatile bool __stop;
				typedef bool (*event_callback_t)(int fd, bool is_input, void *data);

				struct event_loop_event {
					int fd;
					event_callback_t cb;
					void *data;
				};

				std::vector<KVMCpu *> kvm_cpus;
				static void core_thread_proc(KVMCpu *core);
				static void device_thread_proc(KVMGuest *guest);
				static void rdtsc_pump_thread_proc(KVMGuest *guest);

				bool create_cpu(const GuestCPUConfiguration& config);

				bool _initialised;
				int fd;
				int next_cpu_id;
				int next_slot_idx;
				int epollfd, stopfd, intrfd;

				struct vm_mem_region {
					struct kvm_userspace_memory_region kvm;
					void *host_buffer;
				};

				PerGuestData *per_guest_data;

				std::list<vm_mem_region *> vm_mem_region_free;
				std::list<vm_mem_region *> vm_mem_region_used;

				struct gpm_desc {
					vm_mem_region *vmr;
					const GuestMemoryRegionConfiguration *cfg;
				};

				std::list<gpm_desc> gpm;

				struct dev_desc {
					devices::Device *dev;
					const GuestDeviceConfiguration *cfg;
				};

				typedef util::range<uint64_t> devices_range_type;
				typedef util::left_of_range<uint64_t> devices_left_range_type;
				typedef std::map<devices_range_type, dev_desc, devices_left_range_type> devices_type;
				devices_type devices;

				bool prepare_event_loop();
				bool attach_event(int fd, event_callback_t cb, bool input, bool output, void *data);
				void cleanup_event_loop();
				bool prepare_guest_irq();
				bool prepare_guest_memory(const util::config::Configuration& cfg);
				bool attach_guest_devices();
				devices::Device *lookup_device(uint64_t addr, uint64_t& base_addr);

				bool install_gdt();
				bool install_tss();

				void dump_memory();

				vm_mem_region *get_mem_slot();
				void put_mem_slot(vm_mem_region *region);

				vm_mem_region *alloc_guest_memory(uint64_t gpa, uint64_t size, uint32_t flags = 0, void *fixed_addr = NULL);
				void release_guest_memory(vm_mem_region *rgn);
				void release_all_guest_memory();

				void *_vm_code_region, *_vm_heap_region;

				typedef uint64_t pte_t;
				typedef pte_t *pm_t;
				typedef pte_t *pdp_t;
				typedef pte_t *pd_t;
				typedef pte_t *pt_t;

				uint64_t next_init_pgt_page, last_init_pgt_page;

				inline uint64_t alloc_init_pgt_page()
				{
					assert(next_init_pgt_page < last_init_pgt_page);

					uint64_t next = next_init_pgt_page;
					next_init_pgt_page += 0x1000;

					return next;
				}

				//void *sys_guest_phys_to_host_virt(uint64_t addr);

				void map_pages(uint64_t va, uint64_t pa, uint64_t size, uint32_t flags, bool use_huge_pages = true, uintptr_t pml4 = VM_PHYS_PML4_0);
				void map_page(uint64_t va, uint64_t pa, uint32_t flags, uintptr_t pml4);
				void map_huge_page(uint64_t va, uint64_t pa, uint32_t flags, uintptr_t pml4);

				inline int vmioctl(unsigned long int req) const
				{
					return vmioctl(req, (unsigned long int) 0);
				}

				inline int vmioctl(unsigned long int req, unsigned long int arg) const
				{
					return ioctl(fd, req, arg);
				}

				inline int vmioctl(unsigned long int req, void *arg) const
				{
					return ioctl(fd, req, arg);
				}

				static bool intr_callback(int fd, bool is_input, void *p);

				void *vm_phys_to_host_virt(uintptr_t ptr)
				{
					if (ptr >= VM_PHYS_CODE_BASE && ptr < (VM_PHYS_CODE_BASE + VM_CODE_SIZE))
						return(void *) ((uintptr_t) _vm_code_region + (ptr - VM_PHYS_CODE_BASE));
					else if (ptr >= VM_PHYS_HEAP_BASE && ptr < (VM_PHYS_HEAP_BASE + VM_HEAP_SIZE))
						return(void *) ((uintptr_t) _vm_heap_region + (ptr - VM_PHYS_HEAP_BASE));
					else
						return nullptr;
				}

				void *guest_phys_to_host_virt(uintptr_t ptr) const
				{
					return(void *) ((uintptr_t) HOST_VIRT_GPM + ptr);
				}

				uintptr_t vm_phys_to_vm_virt(uintptr_t ptr) const
				{
					return(uintptr_t) ((uintptr_t) VM_VIRT_SPLIT + ptr);
				}

				uintptr_t vm_virt_to_vm_phys(uintptr_t ptr) const
				{
					assert(ptr > VM_VIRT_SPLIT);

					if (ptr >= VM_VIRT_KERNEL) {
						return(uintptr_t) (ptr - (uintptr_t) VM_VIRT_KERNEL);
					} else {
						return(uintptr_t) (ptr - (uintptr_t) VM_VIRT_SPLIT);
					}
				}

				uintptr_t vm_phys_to_vm_kernel_virt(uintptr_t ptr) const
				{
					return(uintptr_t) ((uintptr_t) VM_VIRT_KERNEL + ptr);
				}
			};
		}
	}
}
