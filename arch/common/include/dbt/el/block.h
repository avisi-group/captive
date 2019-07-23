/* SPDX-License-Identifier: MIT */

#pragma once

namespace captive {
	namespace arch {
		namespace dbt {
			namespace el {
				class Context;

				class Block {
				public:

					Block(Context& ctx) : _ctx(ctx)
					{
					}

				private:
					Context& _ctx;
				};
			}
		}
	}
}