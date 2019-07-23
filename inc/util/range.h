/* SPDX-License-Identifier: MIT */
#pragma once

namespace captive {
	namespace util {

		template<typename T>
		struct range {
		public:
			typedef T value_type;

			range(T const & center) : min_(center), max_(center)
			{
			}

			range(T const & min, T const & max) : min_(min), max_(max)
			{
			}

			inline T min() const
			{
				return min_;
			}

			inline T max() const
			{
				return max_;
			}

		private:
			T min_;
			T max_;
		};

		template <typename T>
		struct left_of_range : public std::binary_function< range<T>, range<T>, bool > {

			inline bool operator()(range<T> const & lhs, range<T> const & rhs) const
			{
				return lhs.min() < rhs.min()
					&& lhs.max() <= rhs.min();
			}
		};
	}
}
