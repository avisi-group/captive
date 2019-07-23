/* SPDX-License-Identifier: MIT */

#pragma once

namespace captive {
	namespace lock {
		typedef volatile uint64_t spinlock;

		inline void spinlock_init(spinlock *lock)
		{
			*lock = 0;
		}

		inline void spinlock_acquire(spinlock *lock)
		{
			while(__sync_lock_test_and_set(lock, 1)) asm volatile("pause" ::: "memory");
		}

		inline void spinlock_release(spinlock *lock)
		{
			__sync_synchronize();
			*lock = 0;
		}
		
		typedef struct { uint32_t ctr; volatile uint32_t b[2]; } barrier;
		
		inline void barrier_init(barrier *b)
		{
			b->ctr = 0;
			b->b[0] = 0;
			b->b[1] = 0;
		}
		
		inline void barrier_wait(barrier *br, uint32_t tid)
		{
			assert(tid == 0 || tid == 1);
			
			uint32_t ctr = br->ctr;
			uint32_t val = !ctr;
			
			br->b[tid] = val;
			while (br->b[!tid] != val) asm ("pause");
			
			br->ctr = !ctr;
		}
		
		inline void barrier_wait_nopause(barrier *br, uint32_t tid)
		{
			assert(tid == 0 || tid == 1);
			
			uint32_t ctr = br->ctr;
			uint32_t val = !ctr;
			
			br->b[tid] = val;
			while (br->b[!tid] != val);
			
			br->ctr = !ctr;
		}
	}
	
#define FAST_DEV_OP_WRITE	(1)
#define FAST_DEV_OP_READ	(2)
#define FAST_DEV_OP_QUIT	((unsigned long)-1)
	
#define FAST_DEV_HYPERVISOR_TID	0
#define FAST_DEV_GUEST_TID		1
	
#define SIM_EVENT_FETCH		(1 << 0)
#define SIM_EVENT_READ		(1 << 1)
#define SIM_EVENT_WRITE		(1 << 2)
#define SIM_EVENT_COUNT		(1 << 3)

	struct PerGuestData {
		struct {
			captive::lock::barrier hypervisor_barrier;
			captive::lock::barrier guest_barrier;

			volatile uint64_t address;
			volatile uint64_t value;
			volatile uint64_t size;
			volatile uint64_t operation;
		} fast_device;
		
		uint64_t entrypoint;
		uint64_t initial_sp;
		
		uintptr_t printf_buffer;
		uintptr_t trace_buffer;
		
		uintptr_t code_virt_base;
		uintptr_t code_phys_base;
		size_t code_size;
		
		uintptr_t heap_virt_base;
		uintptr_t heap_phys_base;
		size_t heap_size;
		
		uint64_t simulation_events;
		bool tracing, dump_code;
		
		uint64_t jiffies;
		uint64_t some_sort_of_pointer;
	};

	struct PerCPUData {
		uint64_t id;
		
		PerGuestData *guest_data;
		void *event_ring;

		volatile bool halt;

		uint32_t isr;
		uint32_t async_action;		// Pending actions
		uint32_t signal_code;		// Incoming signal code
		uint64_t insns_executed;	// Number of instructions executed
		uint64_t interrupts_taken;
		
		uint32_t execution_mode;	// Mode of execution
		
		uint64_t watchpoint;
		uint8_t *interrupt_pending;
		
		uint64_t compilation_time;
		uint64_t execution_time;
		
		bool verbose_enabled;
	};
}
