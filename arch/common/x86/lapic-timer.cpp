/* SPDX-License-Identifier: MIT */

#include <x86/lapic-timer.h>
#include <x86/pit.h>
#include <printf.h>
#include <cpu.h>
#include <malloc/page-allocator.h>

using namespace captive::arch;
using namespace captive::arch::x86;

LAPICTimer captive::arch::x86::lapic_timer;

LAPICTimer::LAPICTimer() : _frequency(0), _cb(nullptr), _cb_priv(nullptr)
{
}

bool LAPICTimer::calibrate()
{
	printf("lapic: calibrating\n");

	// Some useful constants for the calibration
#define FACTOR     1000
#define PIT_FREQUENCY   (1193180)
#define CALIBRATION_PERIOD  (10)
#define CALIBRATION_TICKS  (uint16_t)((PIT_FREQUENCY * CALIBRATION_PERIOD) / FACTOR)

	printf("lapic: calibration ticks=%d\n", (uint32_t) CALIBRATION_TICKS);

	// Initialise the LAPIC and the PIT for one-shot operation.
	this->init_oneshot(0xffffffff);
	pit.initialise_oneshot(CALIBRATION_TICKS); // 10ms

	// Start the PIT and the LAPIC
	pit.start();
	this->start();

	// Spin until the PIT expires
	while (!pit.expired());

	// Stop the LAPIC
	this->stop();

	// Stop the PIT
	pit.stop();

	// Calculate the number of ticks per period (accounting for the LAPIC division)
	uint32_t ticks_per_period = (0xffffffff - count());
	ticks_per_period <<= 4;

	printf("lapic: ticks-per-period=%u\n", ticks_per_period);

	// Determine the LAPIC base frequency
	_frequency = (ticks_per_period * (FACTOR / CALIBRATION_PERIOD));

	printf("lapic: frequency=%lu\n", _frequency);

	return true;
}

bool LAPICTimer::init()
{
	// Initialise the timer controls
	lapic.set_timer_divide(3);
	lapic.set_timer_initial_count(1);

	// Calibrate the timer.
	return calibrate();
}

/**
 * Starts the timer running.
 */
void LAPICTimer::start()
{
	lapic.unmask_interrupts(LAPIC::Timer);
}

/**
 * Stops the timer running.
 */
void LAPICTimer::stop()
{
	lapic.mask_interrupts(LAPIC::Timer);
}

/**
 * Stops and resets the timer.
 */
void LAPICTimer::reset()
{
	lapic.mask_interrupts(LAPIC::Timer);
	lapic.set_timer_initial_count(0);
}

/**
 * Initialises the timer for one-shot mode.
 * @param period The duration of the one-shot timer.
 */
void LAPICTimer::init_oneshot(uint64_t period)
{
	reset();

	lapic.set_timer_one_shot();
	lapic.set_timer_initial_count(period);
}

/**
 * Initialises the timer for periodic mode.
 * @param period The duration of the period.
 */
void LAPICTimer::init_periodic(uint64_t period)
{
	reset();

	lapic.set_timer_periodic();
	lapic.set_timer_initial_count(period);
}

/**
 * Returns the raw counter value for the timer.
 * @return The raw counter value for the timer.
 */
uint64_t LAPICTimer::count() const
{
	return lapic.get_timer_current_count();
}

/**
 * Determines whether or not the timer has expired.
 * @return 
 */
bool LAPICTimer::expired() const
{
	// TODO: Implement
	return false;
}

uint64_t __system_jiffies;
static uint64_t last_time;
static uint64_t last_pca, last_pcb;

uint64_t *__profile, *__profile_next;

extern "C" void handle_trap_timer(struct mcontext *mctx)
{
	lapic.eoi();

	__system_jiffies++;

	/*if ((__system_jiffies - last_time) > 100) {
		last_time = __system_jiffies;
		
		uint64_t pca = captive::arch::CPU::get_active_cpu()->performance_counter_a();
		uint64_t pcb = captive::arch::CPU::get_active_cpu()->performance_counter_b();
		
		printf("time: %lu ms A: %lu (delta=%lu) B: %lu (delta=%lu)\n", (__system_jiffies * 10), pca, (pca - last_pca), pcb, (pcb - last_pcb));
		last_pca = pca;
		last_pcb = pcb;
	}*/

#ifdef CONFIG_PROFILE
	if (__profile == nullptr) {
		__profile = (uint64_t *) captive::arch::malloc::page_alloc.alloc_pages(256);
		__profile_next = __profile;
	}

	*__profile_next++ = mctx->rip;

	//printf("rip=%p\n", mctx->rip);
#endif

	captive::arch::x86::lapic_timer.invoke_callback(100000);
}
