/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <vector>

#include <hypervisor/config.h>
#include <hypervisor/gpa-resolver.h>

#include <simulation/cache/cache-simulation.h>

namespace captive {
	namespace engine {
		class Engine;
	}

	namespace platform {
		class Platform;
	}

	namespace loader {
		class Loader;
	}

	namespace simulation {
		class Simulation;
	}

	namespace util {
		namespace config {
			class Configuration;
		}
	}

	namespace hypervisor {
		class Hypervisor;
		class CPU;

		class SharedMemory;

		class GuestConfiguration;
		class GuestCPUConfiguration;

		class SemihostingContext;
		class SemihostingCallData;

		class Guest : public GPAResolver {
		public:
			static __thread CPU *current_core;

			typedef void (*memory_callback_fn_t)(gpa_t gpa);

			Guest(Hypervisor& owner, engine::Engine& engine, platform::Platform& pfm);
			virtual ~Guest();
			virtual bool init(const util::config::Configuration& cfg);
			virtual bool init_semihosting();
			virtual bool finalise_platform() = 0;

			virtual bool load(loader::Loader& loader) = 0;

			inline Hypervisor& owner() const
			{
				return _owner;
			}

			inline engine::Engine& engine() const
			{
				return _engine;
			}

			inline platform::Platform& platform() const
			{
				return _pfm;
			}

			virtual void guest_entrypoint(gpa_t ep) = 0;
			virtual void guest_stackpointer(gpa_t sp) = 0;

			virtual bool resolve_gpa(gpa_t gpa, void*& out_addr) const = 0;

			virtual bool run() = 0;
			virtual void stop() = 0;

			virtual void debug_interrupt(int code) = 0;

			void add_simulation(simulation::Simulation& simulation);

			void attach_semihosting_context(SemihostingContext& ctx)
			{
				_semihosting_ctx = &ctx;
			}

		protected:

			const std::vector<simulation::Simulation *>& simulations() const
			{
				return _simulations;
			}

			bool initialise_simulations(void *seb);
			void start_simulations();
			void stop_simulations();
			void dump_simulations();
			void handle_simulation_events(CPU& core, uint32_t count);

			bool handle_semihosting_call(CPU& core, SemihostingCallData& call_data);

		private:
			Hypervisor& _owner;
			engine::Engine& _engine;
			platform::Platform& _pfm;
			std::vector<simulation::Simulation *> _simulations;
			uint64_t *simulation_event_buffer;
			SemihostingContext *_semihosting_ctx;
		};
	}
}
