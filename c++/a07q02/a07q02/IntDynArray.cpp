// File: IntDynArray.cpp
// Name: Brandy Poag


#include <iostream>
#include "IntDynArray.h"


std::ostream & operator<<(std::ostream & out, IntDynArray & a)
{
		out << '[';
		for (int i = 0; i < a.get_size(); i++)
		{
			out << a[i];
			if (i != a.get_size() - 1)
			{
				out << ", ";
			}
		}
		out << "]\n";
		return out;
}


bool IntDynArray::operator==(const IntDynArray & arr) const
{
	if(arr.get_size() == size && arr.get_capacity() == capacity)
	{
		for (int i = 0; i < size; i++)
		{
			if (x[i] != arr.x[i]) return false;
		}
		return true;
	}
	return false;
}


bool IntDynArray::operator!=(const IntDynArray & arr) const
{
	return !(*this == arr);
}


IntDynArray & IntDynArray::operator+=(const IntDynArray & a)
{
	int hold = size;
	resize(size + a.get_size());
	for (int i = 0; i < a.get_size(); i++)
	{
		x[i + hold] = a.x[i];
	}
	return *this;
}


IntDynArray IntDynArray::operator+(const IntDynArray & a) const
{
	IntDynArray b = *this;
	return b += a;
}


IntDynArray & IntDynArray::insert(int ind, int val)
{
	IntDynArray temp = *this;
	resize(size + 1);
	for (int i = 0; i < ind; i ++)
	{
		x[i] = temp[i];
	}
	x[ind] = val;
	for (int i = ind + 1; i < size; i ++)
	{
		x[i] = temp[i - 1];
	}
	return *this;
}


IntDynArray & IntDynArray::remove(int index)
{
	IntDynArray temp = *this;
	resize(size - 1);
	for (int i = 0; i < index - 1; i ++)
	{
		x[i] = temp[i];
	}
	for (int i = index; i < size; i ++)
	{
		x[i] = temp[i + 1];
	}
	return *this;
}


IntDynArray IntDynArray::subarray(int index, int length) const
{
	if (length < 0) length = size - index;
	IntDynArray temp(length);
	for (int i = index, j = 0; i < index + length; i++, j++)
	{
		temp[j] = x[i];
	}
	return temp;
}


IntDynArray IntDynArray::print() const
{
	std::cout << '[';
	for (int i = 0; i < size; i++)
	{
		std::cout << x[i];
		if (i != size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "], size:" << size 
		<< ", capacity:" << capacity << '\n';
	return *this;
}


void IntDynArray::resize(const int size0)
{
	if (size0 < 0) return;
	if (size0 > capacity || size0 < capacity / 3)
	{
		int *temp = new int[size0 * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = x[i];
		}
		delete [] x;
		x = temp;
		for (int i = size; i < size0 * 2; i++)
		{
			x[i] = -1;
		}
		size = size0;
		capacity = size0 * 2;
		helper_check_error(*this);
	}
	size = size0;
}
