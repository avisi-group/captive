/* SPDX-License-Identifier: MIT */

#pragma once

#include <dbt/el/type.h>

namespace captive {
	namespace arch {
		namespace dbt {
			class Support;

			namespace el {
				class Block;
				class Type;

				class Context;

				class Types {
					friend class Context;

				public:

					const Type& u8() const
					{
						return _u8;
					}

					const Type& u16() const
					{
						return _u16;
					}

					const Type& u32() const
					{
						return _u32;
					}

					const Type& u64() const
					{
						return _u64;
					}

					const Type& u128() const
					{
						return _u128;
					}

					const Type& s8() const
					{
						return _s8;
					}

					const Type& s16() const
					{
						return _s16;
					}

					const Type& s32() const
					{
						return _s32;
					}

					const Type& s64() const
					{
						return _s64;
					}

					const Type& s128() const
					{
						return _s128;
					}

					const Type& f32() const
					{
						return _f32;
					}

					const Type& f64() const
					{
						return _f64;
					}

					const Type& f80() const
					{
						return _f80;
					}

					const Type& v() const
					{
						return _v;
					}

					const Type& v2u32() const
					{
						return _v2u32;
					}

					const Type& v4u16() const
					{
						return _v4u16;
					}

					const Type& v8u8() const
					{
						return _v8u8;
					}

					const Type& v16u8() const
					{
						return _v16u8;
					}

					const Type& v8u16() const
					{
						return _v8u16;
					}

					const Type& v4u32() const
					{
						return _v4u32;
					}

					const Type& v2u64() const
					{
						return _v2u64;
					}

					const Type& v2s32() const
					{
						return _v2s32;
					}

					const Type& v4s16() const
					{
						return _v4s16;
					}

					const Type& v8s8() const
					{
						return _v8s8;
					}

					const Type& v16s8() const
					{
						return _v16s8;
					}

					const Type& v8s16() const
					{
						return _v8s16;
					}

					const Type& v4s32() const
					{
						return _v4s32;
					}

					const Type& v2s64() const
					{
						return _v2s64;
					}

					const Type& v2f32() const
					{
						return _v2f32;
					}

					const Type& v4f32() const
					{
						return _v4f32;
					}

					const Type& v2f64() const
					{
						return _v2f64;
					}

				private:

					Types() :
					_u8(8, FundamentalType::UNSIGNED_INTEGER), _u16(16, FundamentalType::UNSIGNED_INTEGER), _u32(32, FundamentalType::UNSIGNED_INTEGER), _u64(64, FundamentalType::UNSIGNED_INTEGER), _u128(128, FundamentalType::UNSIGNED_INTEGER),
					_s8(8, FundamentalType::SIGNED_INTEGER), _s16(16, FundamentalType::SIGNED_INTEGER), _s32(32, FundamentalType::SIGNED_INTEGER), _s64(64, FundamentalType::SIGNED_INTEGER), _s128(128, FundamentalType::SIGNED_INTEGER),
					_f32(32, FundamentalType::FLOATING_POINT), _f64(64, FundamentalType::FLOATING_POINT), _f80(128, FundamentalType::FLOATING_POINT),
					_v2u32(32, FundamentalType::UNSIGNED_INTEGER, 2), _v2u64(64, FundamentalType::UNSIGNED_INTEGER, 2),
					_v4u16(16, FundamentalType::UNSIGNED_INTEGER, 4), _v4u32(32, FundamentalType::UNSIGNED_INTEGER, 4),
					_v8u8(8, FundamentalType::UNSIGNED_INTEGER, 8), _v8u16(16, FundamentalType::UNSIGNED_INTEGER, 8),
					_v16u8(8, FundamentalType::UNSIGNED_INTEGER, 16),
					_v2s32(32, FundamentalType::SIGNED_INTEGER, 2), _v2s64(64, FundamentalType::SIGNED_INTEGER, 2),
					_v4s16(16, FundamentalType::SIGNED_INTEGER, 4), _v4s32(32, FundamentalType::SIGNED_INTEGER, 4),
					_v8s8(8, FundamentalType::SIGNED_INTEGER, 8), _v8s16(16, FundamentalType::SIGNED_INTEGER, 8),
					_v16s8(8, FundamentalType::SIGNED_INTEGER, 16),
					_v2f32(32, FundamentalType::FLOATING_POINT, 2), _v4f32(32, FundamentalType::FLOATING_POINT, 4),
					_v2f64(64, FundamentalType::FLOATING_POINT, 2),
					_v(0, FundamentalType::VOID)
					{
					}

					const Type _u8;
					const Type _u16;
					const Type _u32;
					const Type _u64;
					const Type _u128;
					const Type _s8;
					const Type _s16;
					const Type _s32;
					const Type _s64;
					const Type _s128;
					const Type _f32;
					const Type _f64;
					const Type _f80;
					const Type _v2u32;
					const Type _v2u64;
					const Type _v4u16;
					const Type _v4u32;
					const Type _v8u8;
					const Type _v8u16;
					const Type _v16u8;
					const Type _v2s32;
					const Type _v2s64;
					const Type _v4s16;
					const Type _v4s32;
					const Type _v8s8;
					const Type _v8s16;
					const Type _v16s8;
					const Type _v2f32;
					const Type _v4f32;
					const Type _v2f64;
					const Type _v;
				};

				class Context {
				public:

					Context(Support& support) : _support(support)
					{
					}
					virtual ~Context();

					inline Support& support() const
					{
						return _support;
					}

					const Types& types() const
					{
						return _types;
					}

					virtual Block *create_block() = 0;
					virtual Block *entry_block() const = 0;

				private:
					Support& _support;
					const Types _types;
				};
			}
		}
	}
}