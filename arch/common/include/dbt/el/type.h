/* SPDX-License-Identifier: MIT */

#pragma once

namespace captive {
	namespace arch {
		namespace dbt {
			namespace el {
				class Types;

				namespace FundamentalType {

					enum FundamentalType {
						VOID,
						UNSIGNED_INTEGER,
						SIGNED_INTEGER,
						FLOATING_POINT
					};
				}

				class Type {
					friend class Types;

				public:

					bool is_void() const
					{
						return _fundamental_type == FundamentalType::VOID;
					}

					bool is_integer() const
					{
						return _fundamental_type == FundamentalType::SIGNED_INTEGER || _fundamental_type == FundamentalType::UNSIGNED_INTEGER;
					}

					bool is_signed() const
					{
						return _fundamental_type == FundamentalType::SIGNED_INTEGER;
					}

					bool is_floating() const
					{
						return _fundamental_type == FundamentalType::FLOATING_POINT;
					}

					bool is_vector() const
					{
						return _velem_cnt > 1;
					}

					int size_in_bits() const
					{
						return _size_in_bits * _velem_cnt;
					}

					int vector_element_count() const
					{
						return _velem_cnt;
					}

					int vector_element_size_in_bits() const
					{
						return _size_in_bits;
					}

					friend bool operator==(const Type& t1, const Type& t2)
					{
						return t1._size_in_bits == t2._size_in_bits && t1._velem_cnt == t2._velem_cnt && t1._fundamental_type == t2._fundamental_type;
					}

					friend bool operator!=(const Type& t1, const Type& t2)
					{
						return !(t1 == t2);
					}

					Type element_type() const
					{
						return Type(_size_in_bits, _fundamental_type, 1);
					}

				private:

					Type(int element_size_in_bits, FundamentalType::FundamentalType fundamental_type, int vector_element_count = 1) : _size_in_bits(element_size_in_bits), _velem_cnt(vector_element_count), _fundamental_type(fundamental_type)
					{
					}

					int _size_in_bits, _velem_cnt;
					FundamentalType::FundamentalType _fundamental_type;
				};
			}
		}
	}
}
