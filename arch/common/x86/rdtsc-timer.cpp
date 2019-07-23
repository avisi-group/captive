/* SPDX-License-Identifier: MIT */

#include <x86/rdtsc-timer.h>
#include <x86/pit.h>
#include <printf.h>
#include <cpu.h>

using namespace captive::arch;
using namespace captive::arch::x86;

RDTSCTimer captive::arch::x86::rdtsc_timer;

RDTSCTimer::RDTSCTimer() : _frequency(0)
{

}

bool RDTSCTimer::init()
{
	return calibrate();
}

bool RDTSCTimer::calibrate()
{
	printf("rdtsc: calibrating\n");

	// Some useful constants for the calibration
#define FACTOR     1000
#define PIT_FREQUENCY   (1193180)
#define CALIBRATION_PERIOD  (10)
#define CALIBRATION_TICKS  (uint16_t)((PIT_FREQUENCY * CALIBRATION_PERIOD) / FACTOR)

	printf("rdtsc: calibration ticks=%d\n", (uint32_t) CALIBRATION_TICKS);

	// Initialise the LAPIC and the PIT for one-shot operation.
	pit.initialise_oneshot(CALIBRATION_TICKS); // 10ms

	// Start the PIT and the LAPIC
	pit.start();

	uint64_t start = __rdtsc();

	// Spin until the PIT expires
	while (!pit.expired());

	uint64_t end = __rdtsc();

	// Stop the PIT
	pit.stop();

	// Calculate the number of ticks per period
	uint32_t ticks_per_period = end - start;

	printf("rdtsc: ticks-per-period=%u\n", ticks_per_period);

	// Determine the LAPIC base frequency
	_frequency = (ticks_per_period * (FACTOR / CALIBRATION_PERIOD));

	printf("rdtsc: frequency=%lu\n", _frequency);

	return true;
}

uint64_t RDTSCTimer::count()
{
	return __rdtscp();
}

uint64_t RDTSCTimer::ticks_to_nsec(uint64_t ticks)
{
	return(ticks * 1000000000ull) / _frequency;
}
