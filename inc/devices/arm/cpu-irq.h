/* SPDX-License-Identifier: MIT */
#pragma once

#include <devices/irq/irq-controller.h>

namespace captive {
	namespace devices {
		namespace arm {

			class ArmCpuIRQController : public irq::IRQController<irq::IRQLineBase, 2u>, public irq::CPUIRQController {
			public:
				void irq_raised(irq::IRQLineBase& line) override;
				void irq_rescinded(irq::IRQLineBase& line) override;
				void irq_acknowledged(irq::IRQLineBase& line) override;
			};
		}
	}
}
