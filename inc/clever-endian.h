/* SPDX-License-Identifier: MIT */
#pragma once

template<typename T>
struct DefaultSwapper {

	T operator()(const T& t) const
	{
		return 0;
	}
};

template<>
struct DefaultSwapper<uint32_t> {

	uint32_t operator()(const uint32_t& t) const
	{
		uint32_t v = 0;

		v |= (t & 0xff) << 24;
		v |= (t & 0xff00) << 8;
		v |= (t & 0xff0000) >> 8;
		v |= (t & 0xff000000) >> 24;

		return v;
	}
};

template<>
struct DefaultSwapper<uint64_t> {

	uint64_t operator()(const uint64_t& t) const
	{
		uint64_t v = t;
		v = (v & 0x00000000FFFFFFFF) << 32 | (v & 0xFFFFFFFF00000000) >> 32;
		v = (v & 0x0000FFFF0000FFFF) << 16 | (v & 0xFFFF0000FFFF0000) >> 16;
		v = (v & 0x00FF00FF00FF00FF) << 8 | (v & 0xFF00FF00FF00FF00) >> 8;

		return v;
	}
};

template<typename T, class Swapper = DefaultSwapper<T>>
struct bigendian_t {
public:

	bigendian_t() : _value(0)
	{
	}

	bigendian_t(const T& other) : _value(other)
	{
	}

	bigendian_t(const bigendian_t& other) : _value(other._value)
	{
	}

	bigendian_t(const bigendian_t&& other) : _value(other._value)
	{
	}

	bigendian_t& operator=(const bigendian_t& other)
	{
		_value = other._value;
		return *this;
	}

	bigendian_t& operator=(const bigendian_t&& other)
	{
		_value = other._value;
		return *this;
	}

	bigendian_t& operator=(const T& other)
	{
		_value = other;
		return *this;
	}

	bigendian_t& operator=(const T&& other)
	{
		_value = other;
		return *this;
	}

	operator T() const
	{
		Swapper _swapper;
		return _swapper(_value);
	}

private:
	T _value;
} __packed;

typedef bigendian_t<uint32_t> be32_t;
typedef bigendian_t<uint64_t> be64_t;
