/* SPDX-License-Identifier: MIT */
#pragma once

namespace captive {
	namespace util {

		template<typename T>
		class maybe {
		public:

			maybe() : _has_value(false)
			{
			}

			maybe(T v) : _has_value(true), _value(v)
			{
			}

			inline bool has_value() const
			{
				return _has_value;
			}

			inline const T& value() const
			{
				return _value;
			}

			bool operator==(const T& check) const
			{
				if (!_has_value) {
					return false;
				} else {
					return _value == check;
				}
			}

			inline operator bool() const
			{
				return _has_value;
			}

		private:
			bool _has_value;
			T _value;
		};
	}
}
