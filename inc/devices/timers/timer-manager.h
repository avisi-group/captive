/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <thread>
#include <chrono>
#include <vector>

#define MAX_TIMERS 8

namespace captive {
	namespace devices {
		namespace timers {

#define RATE_HZ std::chrono::nanoseconds(1000000000ULL)
#define RATE_kHZ std::chrono::nanoseconds(1000000ULL)
#define RATE_MHZ std::chrono::nanoseconds(1000ULL)

			class TimerSink {
			public:
				virtual void timer_expired(uint64_t ticks) = 0;
			};

			class TimerManager {
			public:
				TimerManager();
				~TimerManager();

				void start();
				void stop();

				void add_timer(std::chrono::nanoseconds interval, TimerSink& sink);
				void remove_timer(TimerSink& sink);

				std::chrono::nanoseconds ticks() const
				{
					return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start_time);
				}

			private:
				std::chrono::high_resolution_clock::time_point start_time;

				struct runtime_timer {
					bool valid;

					std::chrono::nanoseconds interval;
					std::chrono::high_resolution_clock::time_point first_tick;

					uint64_t ticks;
					TimerSink *sink;
				};

				struct runtime_timer timers[MAX_TIMERS];

				void timer_thread_proc();
				static void timer_thread_proc_tramp(void *o);

				volatile bool terminate;
				std::thread *timer_thread;
			};
		}
	}
}
