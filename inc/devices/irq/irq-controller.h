/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>
#include <devices/irq/irq-line.h>

namespace captive {
	namespace hypervisor {
		class CPU;
	}

	namespace devices {
		namespace irq {

			class IRQControllerBase {
				friend class IRQLineBase;

			public:

				IRQControllerBase()
				{
				}

				virtual ~IRQControllerBase()
				{
				}

				virtual void dump() const = 0;

			protected:
				virtual void irq_raised(IRQLineBase& line) = 0;
				virtual void irq_rescinded(IRQLineBase& line) = 0;

				virtual void irq_acknowledged(IRQLineBase& line)
				{
				}
			};

			class CPUIRQController {
			public:

				inline void attach(hypervisor::CPU& cpu)
				{
					_cpu = &cpu;
				}

			protected:

				inline hypervisor::CPU& cpu() const
				{
					return *_cpu;
				}

			private:
				hypervisor::CPU *_cpu;
			};

			template<typename irq_line_t, uint32_t _nr_lines>
			class IRQController : public IRQControllerBase {
			public:
				static constexpr uint32_t nr_lines = _nr_lines;

				IRQController()
				{
					for (uint32_t i = 0; i < nr_lines; i++) {
						lines[i].attach(*this, i);
					}
				}

				virtual ~IRQController()
				{
				}

				inline irq_line_t *get_irq_line(uint32_t idx)
				{
					if (idx < nr_lines) {
						return &lines[idx];
					} else {
						assert(false);
						return NULL;
					}
				}

				inline const irq_line_t *get_irq_line(uint32_t idx) const
				{
					if (idx < nr_lines) {
						return &lines[idx];
					} else {
						return NULL;
					}
				}

				virtual void dump() const override
				{
					for (unsigned int i = 0; i < nr_lines; i++) {
						// fprintf(stderr, "[%02d] = %s\n", i, lines[i].raised() ? "high" : "low");
					}
				}

				inline constexpr uint32_t count() const
				{
					return nr_lines;
				}

			private:
				irq_line_t lines[nr_lines];
			};
		}
	}
}
