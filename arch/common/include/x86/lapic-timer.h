/* SPDX-License-Identifier: MIT */
#pragma once

#include <x86/lapic.h>

namespace captive {
	namespace arch {
		namespace x86 {

			class LAPICTimer {
			public:
				typedef void (*callback_fn_t)(void *, uint64_t);

				LAPICTimer();

				bool init();

				void init_oneshot(uint64_t period);
				void init_periodic(uint64_t period);

				void start();
				void stop();
				void reset();

				uint64_t count() const;
				bool expired() const;

				uint64_t frequency() const
				{
					return _frequency;
				}

				void callback(callback_fn_t cb, void *priv)
				{
					_cb = cb;
					_cb_priv = priv;
				}

				inline void invoke_callback(uint64_t ticks)
				{
					if (_cb) _cb(_cb_priv, ticks);
				}
			private:
				uint64_t _frequency;
				callback_fn_t _cb;
				void *_cb_priv;

				bool calibrate();
			};

			extern LAPICTimer lapic_timer;
		}
	}
}
