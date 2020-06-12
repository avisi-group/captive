/* SPDX-License-Identifier: MIT */
#pragma once

#include <device.h>

namespace captive {
	namespace arch {
		namespace arm64 {
			class arm64_environment;

			namespace devices {

				class GenericTimer : public CoreDevice {
				public:
					GenericTimer(arm64_environment& env);

					bool read(CPU& cpu, uint32_t reg, uint64_t& data) override;
					bool write(CPU& cpu, uint32_t reg, uint64_t data) override;

					void tick(uint64_t ticks);

				private:

					class GenericTimerImpl {
					public:

						GenericTimerImpl(bool _virt) : virt(_virt), CVAL(0), OFF(0)
						{
							CTL.bits = 0;
							CTL.imask = 1;
						}

						void tick(uint64_t ticks);
						void update();

						uint32_t tval() const
						{
							return CVAL - (COUNTER - OFF);
						}

						void tval(uint32_t v)
						{
							CVAL = (uint64_t) (((int64_t) COUNTER - (int64_t) OFF) + (int64_t) (int32_t) v);
						}

						bool virt;

						union {

							struct {
								uint32_t enable : 1;
								uint32_t imask : 1;
								uint32_t istatus : 1;
								uint32_t res0 : 29;
							};

							uint32_t bits;
						} CTL;

						uint64_t COUNTER, CVAL, OFF;
					} PT, VT;

					static void tick_callback(void *ptr, uint64_t ticks);

					union {
						uint32_t bits;
					} CNTKCTL;

					uint64_t _base_jiffies;
				};
			}
		}
	}
}
