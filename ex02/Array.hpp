#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
public:
	Array() : _data(0), _size(0) {}

	Array(unsigned int n) : _data(new T[n]()), _size(n) {}

	Array(const Array &other) : _data(0), _size(0)
	{
		*this = other;
	}

	Array &operator=(const Array &other)
	{
		if (this == &other)
			return *this;

		delete[] _data;
		_size = other._size;
		_data = (_size == 0) ? 0 : new T[_size]();
		for (std::size_t i = 0; i < _size; ++i)
			_data[i] = other._data[i];
		return *this;
	}

	~Array()
	{
		delete[] _data;
	}

	T &operator[](std::size_t index)
	{
		if (index >= _size)
			throw std::out_of_range("Array index out of range");
		return _data[index];
	}

	const T &operator[](std::size_t index) const
	{
		if (index >= _size)
			throw std::out_of_range("Array index out of range");
		return _data[index];
	}

	std::size_t size() const
	{
		return _size;
	}

private:
	T *_data;
	std::size_t _size;
};
