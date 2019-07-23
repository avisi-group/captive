/* SPDX-License-Identifier: MIT */
#pragma once

#include <simulation/simulation.h>

namespace captive {
	namespace simulation {

		class InstructionCounter : public Simulation {
		public:

			InstructionCounter() : _count(0)
			{
			}

			Events::Events required_events() const override
			{
				return(Events::Events)(Events::InstructionFetch | Events::InstructionCount);
			}

			void process_events(const EventPacket* events, uint32_t count) override;

			bool init() override;
			void start() override;
			void stop() override;
			void dump() override;

		private:
			uint64_t _count;
		};
	}
}
