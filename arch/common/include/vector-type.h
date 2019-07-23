/* SPDX-License-Identifier: MIT */
#pragma once

namespace wutils {

	template <typename ElementT, unsigned Width> class Vector {
	public:

		Vector()
		{
			for (unsigned i = 0; i < Width; ++i) {
				new (&elements[i]) ElementT();
			}
		}

		~Vector()
		{
			for (unsigned i = 0; i < Width; ++i) {
				elements[i].~ElementT();
			}
		}

		// 'Splat' constructor

		Vector(const ElementT &element)
		{
			for (auto &i : elements) {
				i = element;
			}
		}

		// Element cast constructor

		template<typename OtherTy> Vector(const Vector<OtherTy, Width> &otherVector)
		{
			for (unsigned i = 0; i < Width; ++i) {
				elements[i] = otherVector.elements[i];
			}
		}

		/*Vector(const std::initializer_list<ElementT> &elems) {
		    if (elems.size() != Width) {
			throw std::range_error("Incorrect vector width");
		    }
		    unsigned i = 0;
		    for (auto elem : elems) {
			elements[i++] = elem;
		    }
		}*/

		template<typename OtherElementT> void operator=(const Vector<OtherElementT, Width> &other)
		{
			for (unsigned int i = 0; i < Width; ++i) {
				InsertElement(i, other.ExtractElement(i));
			}
		}

		template<typename OtherElementT> operator Vector<OtherElementT, Width>()
		{
			Vector<OtherElementT, Width> newvector;
			for (unsigned i = 0; i < Width; ++i) {
				newvector.InsertElement(i, ExtractElement(i));
			}
			return newvector;
		}

#define OPERATEANDSET(op) void operator op(const Vector<ElementT, Width> &other) { for(unsigned i = 0; i < Width; ++i) elements[i] op other.elements[i]; }

		OPERATEANDSET( +=)
		OPERATEANDSET( -=)
		OPERATEANDSET( *=)
		OPERATEANDSET( /=)

		OPERATEANDSET( &=)
		OPERATEANDSET( |=)
		OPERATEANDSET( ^=)
#undef OPERATEANDSET

		void InsertElement(unsigned index, ElementT value)
		{
			elements[index] = value;
		}

		const ElementT &ExtractElement(unsigned index) const
		{
			return elements[index];
		}

		ElementT &ExtractElement(unsigned index)
		{
			return elements[index];
		}

		ElementT &operator[](unsigned i)
		{
			return ExtractElement(i);
		}

		const ElementT &operator[](unsigned i) const
		{
			return ExtractElement(i);
		}

	private:
		ElementT elements[Width];
	};
}

template<typename ElementT1, typename ElementT2, unsigned Width> wutils::Vector<bool, Width> operator==(const wutils::Vector<ElementT1, Width> &v1, const wutils::Vector<ElementT2, Width> &v2)
{
	wutils::Vector<bool, Width> output;
	for (unsigned int i = 0; i < Width; ++i) {
		output.InsertElement(i, v1.ExtractElement(i) == v2.ExtractElement(i));
	}
	return output;
}

template<typename ElementT1, typename ElementT2, unsigned Width> wutils::Vector<bool, Width> operator>=(const wutils::Vector<ElementT1, Width> &v1, const wutils::Vector<ElementT2, Width> &v2)
{
	wutils::Vector<bool, Width> output;
	for (unsigned int i = 0; i < Width; ++i) {
		output.InsertElement(i, v1.ExtractElement(i) >= v2.ExtractElement(i));
	}
	return output;
}

#define OPERATE(op) \
template <typename ElementT, unsigned Width> wutils::Vector<ElementT, Width> operator op(const wutils::Vector<ElementT, Width> &v1, const wutils::Vector<ElementT, Width> &v2) { \
        wutils::Vector<ElementT, Width> result; \
        for(unsigned i = 0; i < Width; ++i) result[i] = v1[i] op v2[i]; \
        return result; \
}

OPERATE(+)
OPERATE(-)
OPERATE(*)
OPERATE( /)

OPERATE(&)
OPERATE( |)
OPERATE(^)

#undef OPERATE

