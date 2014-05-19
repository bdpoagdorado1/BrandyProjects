//Name: Brandy Poag
//File: Deque.h

#include <iostream>
#include <exception>

#ifndef DEQUE_H
#define DEQUE_H

template< class T >

class Deque
{
public:
	Deque(int capacity0 = 5) : size(0), capacity(capacity0), 
		x(new T [capacity0]) {}
	Deque(const Deque & que) : size(que.size), 
		x(new T [que.size]), capacity(que.size)
	{
		helper_copy(que, *this);
	}
	~Deque() { delete [] x;}
	Deque operator=(const Deque< T > & que)
	{
		if (this != & que)
		{
			size = que.size;
			resize(size);
			helper_copy(que, *this);
		}
		return *this;
	}
	int get_size() const { return size; }
	T & operator[](int i) { return x[i]; }
	T operator[](int i) const { return x[i]; }
	void insert_tail(T i);
	void insert_head(T i);
	T remove_tail();
	T remove_head();
	void resize(int size0); 
private:
	void helper_copy(const Deque< T > & a, Deque< T > & b)
	{
		for (int i = 0; i < a.size; i++)
		{
			b.x[i] = a.x[i];
		}
	}
	T * x;
	int size;
	int capacity;
};


template< class T >
std::ostream & operator<<(std::ostream & out, const Deque< T > que)
{
	out << '[';
	for (int i = 0; i < que.get_size(); ++i)
	{
		out << que[i];
		if (i != que.get_size() - 1) out << ", ";
	}
	out << ']';
	return out;
}


template< class T >
void Deque< T >::insert_tail(T i)
{
	resize(++size);
	x[size - 1] = i;
}


template< class T >
void Deque< T >::insert_head(T i)
{
	Deque< T > copy = *this;
	resize(++size);
	x[0] = i;
	for (int j = 0; j < copy.get_size(); ++j)
	{
		x[j+1] = copy[j];
	}
}


template< class T >
T Deque< T >::remove_tail()
{
	T hold = x[size];
	resize(--size);
	return hold;
}


template< class T >
T Deque< T >::remove_head()
{
	T a = x[0];
	for (int i = 0; i < size - 1; ++i)
	{
		x[i] = x[i + 1];
	}
	resize(--size);
	return a;
}


template< class T >
void Deque< T >::resize(int size0)
{
	if (size0 < 0) 
		throw std::exception("Stack Error ... can't remove");
	try
	{
		if (size0 > capacity || size0 < capacity / 3)
		{
			int *temp = new T[size0 * 2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = x[i];
			}
			delete [] x;
			x = temp;
			size = size0;
			capacity = size0 * 2;
		}
		size = size0;
	}
	catch (std::bad_alloc & e)
	{
		throw std::exception("Stack Error ... can't insert");
	}
}


#endif

