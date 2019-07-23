/* SPDX-License-Identifier: MIT */

#if 0
#include <devices/timers/microsecond-tick-source.h>
#include <captive.h>
#include <thread>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

using namespace captive::devices::timers;

MicrosecondTickSource::MicrosecondTickSource() : tick_thread(NULL), terminate(false), ticks(1000), total_overshoot(0), overshoot_samples(0), calibrated_ticks(0), recalibrate(0) {
}

MicrosecondTickSource::~MicrosecondTickSource() {
	stop();
}

void MicrosecondTickSource::start() {
	if (tick_thread) return;

	terminate = false;
	tick_thread = new std::thread(tick_thread_proc_tramp, this);
}

void MicrosecondTickSource::stop() {
	if (!tick_thread) return;

	terminate = true;
	if (tick_thread->joinable())
		tick_thread->join();

	delete tick_thread;
	tick_thread = NULL;
}

void MicrosecondTickSource::tick_thread_proc_tramp(MicrosecondTickSource* o) {
	o->tick_thread_proc();
}

void MicrosecondTickSource::tick_thread_proc() {
	pthread_setname_np(pthread_self(), "microsecond-tick");
	
	while (!terminate) {
		tick(1);

		if (recalibrate-- == 0) {
			recalibrate = 1000;

			// Attempt a calibration delay and measure how long it lasts
			auto before = std::chrono::high_resolution_clock::now();
			usleep(ticks);
			auto after = std::chrono::high_resolution_clock::now();

			int64_t delta_ticks = std::chrono::duration_cast<std::chrono::microseconds>(after - before).count();

			//Figure out the overshoot. If we have overshot by a large amount then schedule another calibration soon
			int64_t overshoot = delta_ticks - ticks;
			if (overshoot > ticks) {
				overshoot = ticks / 2;
				recalibrate = 50;
			}

			total_overshoot += overshoot;
			if (overshoot_samples++ > 1000) {
				overshoot_samples = 1;
				total_overshoot = overshoot;
			}

			calibrated_ticks = ticks - (total_overshoot / overshoot_samples);
		} else {
			if (usleep(calibrated_ticks) < 0) {
				fprintf(stderr, "**** INTERRRRRRRUPTED SLEEP\n");
			}
		}
	}
}
#endif