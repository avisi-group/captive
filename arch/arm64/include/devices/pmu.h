/* SPDX-License-Identifier: MIT */
#pragma once

#include <device.h>

namespace captive::arch::arm64
{
    class arm64_environment;

    namespace devices
    {
        class PMU : public CoreDevice
        {
        public:
            PMU(arm64_environment &env);

            bool read(CPU &cpu, uint32_t reg, uint64_t &data) override;
            bool write(CPU &cpu, uint32_t reg, uint64_t data) override;

        private:
            uint64_t PMCR, PMUSERENR, PMCNTEN, PMINTEN, PMOVS, PMSELR;

            uint64_t PMXEVTYPER[32];
            uint64_t PMXEVCNTR[32];

            void update_counters(CPU& cpu);
            void reset_counters(CPU& cpu);
        };
    } // namespace devices
} // namespace captive::arch::arm64
