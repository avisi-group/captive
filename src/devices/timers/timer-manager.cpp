/* SPDX-License-Identifier: MIT */

#include <devices/timers/timer-manager.h>
#include <time.h>
#include <pthread.h>

using namespace captive::devices::timers;

TimerManager::TimerManager() : timer_thread(NULL)
{
	for (int i = 0; i < MAX_TIMERS; i++) {
		timers[i].valid = false;
	}
}

TimerManager::~TimerManager()
{
	stop();
}

void TimerManager::start()
{
	if (timer_thread) return;
	
	start_time = std::chrono::high_resolution_clock::now();
	
	terminate = false;
	timer_thread = new std::thread(timer_thread_proc_tramp, this);
}

void TimerManager::stop()
{
	if (!timer_thread) return;
	
	terminate = true;
	if (timer_thread->joinable()) timer_thread->join();
	timer_thread = NULL;
}

void TimerManager::add_timer(std::chrono::nanoseconds interval, TimerSink& sink)
{
	for (int i = 0; i < MAX_TIMERS; i++) {
		if (!timers[i].valid) {
			timers[i].interval = interval;
			timers[i].first_tick = std::chrono::high_resolution_clock::now();
			timers[i].ticks = 0;
			timers[i].sink = &sink;
			timers[i].valid = true;
			
			break;
		}
	}
}

void TimerManager::remove_timer(TimerSink& sink)
{

}

void TimerManager::timer_thread_proc_tramp(void* o)
{
	pthread_setname_np(pthread_self(), "timer-mgr");
	((TimerManager *)o)->timer_thread_proc();
}


void TimerManager::timer_thread_proc()
{
	struct timespec ts_in;
	ts_in.tv_sec = 0;
	ts_in.tv_nsec = 1000000;
	
	for (int i = 0; i < MAX_TIMERS; i++) {
		if (timers[i].valid) {
			timers[i].first_tick = std::chrono::high_resolution_clock::now();
		}
	}
	
	while (!terminate) {
		// Find any timers that are due to tick
		for (int i = 0; i < MAX_TIMERS; i++) {
			struct runtime_timer *timer = &timers[i];
			if (!timer->valid) continue;
			
			std::chrono::nanoseconds delta_first_tick = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - timer->first_tick);
			uint64_t integral_ticks = delta_first_tick / timer->interval;
			uint64_t delta_ticks = integral_ticks - timer->ticks;

			if (delta_ticks > 0) {
				// Update the number of ticks this timer should have had since it started.
				timer->ticks = integral_ticks;
				timer->sink->timer_expired(delta_ticks);
			}
		}

		nanosleep(&ts_in, NULL);
	}
}
