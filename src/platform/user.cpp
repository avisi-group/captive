/* SPDX-License-Identifier: MIT */

#include <platform/user.h>
#include <util/config/config.h>
#include <loader/loader.h>
#include <loader/elf-loader.h>

#include <devices/arm/cpu-irq.h>
#include <cstring>

using namespace captive;
using namespace captive::hypervisor;
using namespace captive::platform;
using namespace captive::devices;
using namespace captive::devices::arm;
using namespace captive::loader;

#define KB(_v) ((_v) * 1024ULL)
#define MB(_v) (KB(_v) * 1024ULL)
#define GB(_v) (MB(_v) * 1024ULL)

UserPlatform::UserPlatform(const util::config::Configuration& hcfg, devices::timers::TimerManager& timer_manager, const Loader *kernel) : Platform(hcfg, timer_manager), _kernel(kernel), cfg(), _initial_stackpointer(0xc0000000)
{
	cfg.memory_regions.clear();
	
	cfg.memory_regions.push_back(GuestMemoryRegionConfiguration(0, GB(12)));
	
	ArmCpuIRQController *core0irq = new ArmCpuIRQController();
	GuestCPUConfiguration core0(*core0irq);
	cfg.cores.push_back(core0);
}

UserPlatform::~UserPlatform() {

}

bool UserPlatform::start()
{
	return true;
}

bool UserPlatform::stop()
{
	return true;
}

void UserPlatform::dump() const
{

}

#define __STACK_ALLOC(__size) do { _initial_stackpointer -= (__size); } while (0)
#define __GV_STACK_PTR ((uint64_t)_initial_stackpointer)
#define __HV_STACK_PTR ((void *)((uintptr_t)ptr + (__GV_STACK_PTR)))
#define __PUSH32(__value) do { __STACK_ALLOC(4); uint32_t *__ptr = (uint32_t *)__HV_STACK_PTR; *__ptr = __value; } while (0)
#define __PUSH64(__value) do { __STACK_ALLOC(8); uint64_t *__ptr = (uint64_t *)__HV_STACK_PTR; *__ptr = __value; } while (0)
#define __PUSHSTR(__str) do { __STACK_ALLOC(__str.size() + 1); uint8_t *__ptr = (uint8_t *)__HV_STACK_PTR; ::strcpy((char *)__ptr, (const char *)__str.c_str()); } while (0)
#define __PUSH_AUX_ENT(__id, __value) do { __PUSH64(__value); __PUSH64(__id); } while (0)
#define __ALIGN_STACK(__amount) do { __STACK_ALLOC(__GV_STACK_PTR & (__amount - 1)); } while (0)

bool UserPlatform::prepare_guest_memory(void* ptr)
{
	std::vector<uint64_t> guest_argv_ptrs;
	uint64_t guest_argc;

		
	// XXX: AARCH64 HACK
	*(uint32_t *)((uintptr_t)ptr + 0x200) = 0xd4000021;

	__PUSH64(0);
	
	if (auto fbl = dynamic_cast<const FileBasedLoader *>(_kernel)) {
		__PUSHSTR(std::string("_=" + fbl->filename()));
	} else {
		__PUSHSTR(std::string("_=/home/a.out"));
	}
	
	guest_argv_ptrs.push_back(__GV_STACK_PTR);
	guest_argc++;
	
	if (auto fbl = dynamic_cast<const FileBasedLoader *>(_kernel)) {
		__PUSHSTR(std::string("_=" + fbl->filename()));
	} else {
		__PUSHSTR(std::string("_=/home/a.out"));
	}

	uint64_t envp0 = __GV_STACK_PTR;
		
	for (auto& arg : host_configuration().cmdline) {
		__PUSHSTR(arg);
		guest_argv_ptrs.push_back(__GV_STACK_PTR);
		guest_argc++;
	}
		
	__ALIGN_STACK(8);
	__PUSH64(0);
	
	// AUXV
	__PUSH_AUX_ENT(0, 0);
	__PUSH_AUX_ENT(31, 0);			// AT_EXECFN
	__PUSH_AUX_ENT(25, 0);			// AT_RANDOM
	__PUSH_AUX_ENT(23, 0);			// AT_SECURE

	__PUSH_AUX_ENT(14, 0);		// AT_EGID
	__PUSH_AUX_ENT(13, 0);		// AT_GID
	__PUSH_AUX_ENT(12, 0);		// AT_EUID
	__PUSH_AUX_ENT(11, 0);		// AT_UID
	
	if (auto ebl = dynamic_cast<const ELFLoader *>(_kernel)) {
		__PUSH_AUX_ENT(9, ebl->entrypoint());				// AT_ENTRY_POINT
		__PUSH_AUX_ENT(5, ebl->nr_program_headers());		// AT_PHNUM
		__PUSH_AUX_ENT(4, ebl->program_header_size());		// AT_PHENT
		__PUSH_AUX_ENT(3, ebl->program_headers_offset());	// AT_PHDR
	}

	__PUSH_AUX_ENT(8, 0);			// AT_FLAGS
	__PUSH_AUX_ENT(7, 0);			// AT_BASE
	
	__PUSH_AUX_ENT(6, 4096);		// AT_PAGESZ		
	__PUSH_AUX_ENT(16, 0x8197);		// AT_HWCAP
	
	// ENVP
	__PUSH64(0);
	__PUSH64(envp0);
	
	// ARGV
	__PUSH64(0);
	
	for (auto II = guest_argv_ptrs.rbegin(), IE = guest_argv_ptrs.rend(); II != IE; ++II) {
		__PUSH64(*II);
	}
		
	// ARGC
	__PUSH64(guest_argc);
	
#if 0
	
	printf("XXXX %p\n", _initial_stackpointer);
	
	 for(unsigned long i = _initial_stackpointer; i < 0xc0000000; i += 8) {
        uint64_t data = *(uint64_t *)((uintptr_t)ptr + i);
        printf("%p %016lx ", i, data);
        for(int c = 0; c < 8; ++c) {
            char character = data >> (c * 8);
            if(character == 0) { 
                printf(".");
            } else {
				printf("-");
                //printf("%c", data >> (c*8));
            }
        }
        printf("\n");
    }
#endif
	
	return true;
}

gpa_t UserPlatform::stackpointer() const
{
	return _initial_stackpointer;
}
