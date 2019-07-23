/* SPDX-License-Identifier: MIT */
#pragma once

#include <define.h>

namespace captive {
	namespace arch {
#define UNSIGNED_BITS(v, u, l) (((uint32_t)(v) << (31 - u)) >> (31 - u + l))
#define SIGNED_BITS(v, u, l) (((int32_t)(v) << (31 - u)) >> (31 - u + l))
#define BITSEL(v, b)   (((v) >> b) & 1UL)
#define BIT_LSB(i)    (1 << (i))

#define __ROR(v, s, a) (((v) >> a) | ((v) << (s - a)))
#define __ROR32(v, a) __ROR((uint32_t)(v), 32, a)
#define __ROR64(v, a) __ROR((uint64_t)(v), 64, a)
#define __SEXT64(v, from) (((int64_t)(((uint64_t)(v)) << (64 - (from)))) >> (64 - (from)))

#define __ONES(a) (~0ULL >> (64 - (a)))
#define __CLZ32(a) __builtin_clz((a))

		static inline uint64_t __REPLICATE(uint64_t __v, unsigned int __e)
		{
			while (__e < 64) {
				__v |= __v << __e;
				__e *= 2;
			}

			return __v;
		}

		class JumpInfo {
		public:

			enum JumpType {
				NONE,
				DIRECT,
				DIRECT_PREDICATED,
				INDIRECT
			};

			JumpType type;
			uint64_t target;
		};

		class Decode {
		public:
			uint64_t pc;
			uint32_t length;

			bool end_of_block;
			bool is_predicated;

			virtual bool decode(uint32_t isa_mode, uint64_t insn_pc, const uint8_t *ptr) = 0;

			virtual JumpInfo get_jump_info() = 0;
		};

	}
}
