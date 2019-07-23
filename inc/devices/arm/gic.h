/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/device.h>
#include <devices/irq/irq-controller.h>
#include <unordered_map>
#include <mutex>

namespace captive {
	namespace devices {
		using namespace irq;

		namespace arm {
			class GIC;
			class GICIRQLine;
			class GICDistributorInterface;
			class GICCPUInterface;

			typedef uint32_t interrupt_bitmask_t[32];

			class GICDistributorInterface : public Device {
				friend class GIC;
				friend class GICCPUInterface;

			public:
				GICDistributorInterface(GIC& gic);
				~GICDistributorInterface();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				uint32_t size() const override
				{
					return 0x1000;
				}

				std::string name() const override
				{
					return "gic-distributor";
				}

			private:
				GIC& _gic;

				bool _enabled;
			};

			class GICCPUInterface : public Device {
				friend class GIC;
				friend class GICDistributorInterface;

			public:
				GICCPUInterface(GIC& gic, uint8_t id, irq::IRQLineBase& irq);
				virtual ~GICCPUInterface();

				bool read(uint64_t off, uint8_t len, uint64_t& data) override;
				bool write(uint64_t off, uint8_t len, uint64_t data) override;

				uint32_t size() const override
				{
					return 0x1000;
				}

				std::string name() const override
				{
					return "gic-cpu-" + std::to_string(_id);
				}

			private:
				void update();
				uint64_t acknowledge();
				void eoi(uint64_t irqid);

				uint32_t running_priority() const;

				GIC& _gic;
				uint8_t _id;
				irq::IRQLineBase& _irq;

				bool _enabled;
				uint8_t _pmr;
				GICIRQLine *_current_pending, *_current_running;
			};

			class GICIRQLine : public IRQLineBase {
				friend class GIC;
				friend class GICDistributorInterface;
				friend class GICCPUInterface;

			public:
				GICIRQLine(GIC& gic, unsigned int id);
				~GICIRQLine();

				bool enabled() const
				{
					return _enabled;
				}

				bool active() const
				{
					return _active;
				}

				bool pending() const
				{
					return _pending;
				}

				uint8_t priority() const
				{
					return _priority;
				}

				uint8_t cpu_mask() const
				{
					return _cpu_mask;
				}

				uint8_t config() const
				{
					return _config;
				}

				bool edge_triggered() const
				{
					return !!(_config & 2);
				}

				bool level_triggered() const
				{
					return !(_config & 2);
				}

				void dump() const;

			private:
				GIC& _gic;
				unsigned int _id;
				GICIRQLine *_last_active;

				bool _enabled, _active, _pending;
				uint8_t _priority, _cpu_mask, _config;
			};

			class GIC : public IRQControllerBase {
				friend class GICDistributorInterface;
				friend class GICCPUInterface;

			public:
				static constexpr unsigned int nr_lines = 1020;

				GIC();
				~GIC();

				void dump() const override;

				void irq_raised(IRQLineBase& line) override;
				void irq_rescinded(IRQLineBase& line) override;

				GICDistributorInterface& get_distributor()
				{
					return _distributor;
				}
				GICCPUInterface& create_cpu_interface(IRQLineBase& irq);

				GICIRQLine& get_irq_line(unsigned int idx) const
				{
					assert(idx < nr_lines);
					return *_irq_lines[idx];
				}

			private:
				std::recursive_mutex _lock;
				GICDistributorInterface _distributor;

				uint8_t _next_cpu_id;
				std::unordered_map<uint8_t, GICCPUInterface *> _cpus;

				std::vector<GICIRQLine *> _irq_lines;

				std::vector<GICIRQLine *> lines_for_bitvector(unsigned int base, uint8_t len, uint8_t bits);
			};
		}
	}
}
