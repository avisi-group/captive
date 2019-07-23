/* SPDX-License-Identifier: MIT */
#pragma once

template<int size> class PopulatedSet {
private:
	bool _populated[size];

public:

	void set(int i)
	{
		_populated[i] = true;
	}

	bool get(int i)
	{
		return _populated[i];
	}

	int count()
	{
		int c = 0;
		for (auto& i : _populated) if (i) c++;
		return c;
	}

	void clear()
	{
		for (auto &i : _populated) i = 0;
	}

	void clear(int i)
	{
		_populated[i] = 0;
	}

	bool empty()
	{
		return count() == 0;
	}

	bool full()
	{
		return count() == size;
	}

	int next_avail()
	{
		for (int i = 0; i < size; ++i) if (get(i)) return i;
		return -1;
	}

	void fill(int d)
	{
		clear();
		for (int i = 0; i < size; ++i) if ((1 << i) & d) set(i);
	}

	void invert()
	{
		for (int i = 0; i < size; ++i) _populated[i] = !_populated[i];
	}
};

template<> class PopulatedSet<8> {
private:
	uint8_t _bits;

public:

	PopulatedSet()
	{
		clear();
	}

	void set(int i)
	{
		assert(i < 8);
		assert(i >= 0);
		_bits |= 1 << i;
	}

	bool get(int i)
	{
		assert(i < 8);
		assert(i >= 0);
		return _bits & (1 << i);
	}

	int count() const
	{
		return __builtin_popcount(_bits);
	}

	void clear()
	{
		_bits = 0;
	}

	void clear(int i)
	{
		assert(i < 8);
		assert(i >= 0);
		_bits &= ~(1 << i);
	}

	bool empty()
	{
		return _bits == 0;
	}

	bool full()
	{
		return _bits == 0xff;
	}

	int next_avail()
	{
		if (empty()) return -1;
		int8_t avail = __builtin_ffs(_bits) - 1;
		assert(get(avail));
		return avail;
	}

	void fill(int d)
	{
		_bits = d;
	}

	void invert()
	{
		_bits = ~_bits;
	}
};

template<typename innertype, int tsize> class SmallSet {
private:
	innertype _data[tsize];
	PopulatedSet<tsize> _populated;

	static const int _size = tsize;

public:

	typedef SmallSet<innertype, tsize> smallset_t;

	class iterator {
		friend smallset_t;
	private:
		smallset_t &_target;
		int _ptr;

		iterator(smallset_t &target, int ptr) : _target(target), _ptr(ptr)
		{
		}

		void advance()
		{
			while ((_ptr < _target._size) && !_target._populated.get(_ptr)) {
				_ptr += 1;
			}
		}

	public:

		iterator(smallset_t &target) : _target(target), _ptr(0)
		{
			advance();
		}

		bool operator==(const iterator &other)
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const iterator &other)
		{
			return _ptr != other._ptr;
		}

		innertype &operator*()
		{
			return _target._data[_ptr];
		}

		// preincrement

		iterator &operator++()
		{
			_ptr++;
			advance();
			return *this;
		}
	};

	SmallSet()
	{
		clear();
	}

	iterator begin()
	{
		return iterator(*this);
	}

	iterator end()
	{
		return iterator(*this, _size);
	}

	int count(innertype test)
	{
		for (int i = 0; i < _size; ++i) {
			if (_populated.get(i) && _data[i] == test) return 1;
		}
		return 0;
	}

	long unsigned size()
	{
		return _populated.count();
	}

	void insert(innertype data)
	{
		int pointer = -1;
		for (int i = 0; i < _size; ++i) {
			if (_populated.get(i)) {
				if (_data[i] == data) return;
			} else {
				pointer = i;
			}
		}
		assert(pointer != -1);
		_populated.set(pointer);
		_data[pointer] = data;
	}

	void erase(innertype data)
	{
		if (_populated.empty()) return;
		for (int i = 0; i < _size; ++i) {
			if (_data[i] == data) {
				_populated.clear(i);
				return;
			}
		}
	}

	void erase(iterator it)
	{
		_populated.clear(it._ptr);
	}

	void clear()
	{
		_populated.clear();
	}

	bool empty()
	{
		return size() == 0;
	}
};
