// File: LinearContainer.cpp
// Name: Brandy Poag

#include <iostream>

const int LINEAR_CONTAINER_SIZE = 5;
const int NO_DATA = -9999;

struct LinearContainer
{
	int x[LINEAR_CONTAINER_SIZE];
	int len;
	int size;
};

void init(LinearContainer & x)
{
	x.len = 0;
	x.size = LINEAR_CONTAINER_SIZE;
	return;
}

void println(const LinearContainer & x)
{
	for (int i = 0; i < x.len; i++)
	{
		std::cout << x.x[i] << ' ';
	}
	std::cout << std::endl;
	return;
}

int len( const LinearContainer & x)
{
	return x.len;
}

bool isempty(const LinearContainer & x)
{
	if (x.len == 0) return true;
	else return false;
}

void insert(LinearContainer & x, int index, int newvalue)
{
	for (int i = x.len; i > index; --i)
	{
		x.x[i] = x.x[i - 1];
	}

	x.x[index] = newvalue;
	++x.len;
	return;
}

void remove(LinearContainer & x, int index)
{
	if (index < x.len)
	{
		for (int i = index; i < x.len; i++)
		{
			x.x[i] = x.x[i + 1];
		}

		--x.len;
	}
	return;
}

void push(LinearContainer & x, int newvalue)
{
	x.x[x.len] = newvalue;
	++x.len;
	return;
}

int pop(LinearContainer & x)
{
	if (isempty(x)) return -9999;
	--x.len;
	return x.x[x.len];
}

void enqueue(LinearContainer & x, int newvalue)
{
	push(x, newvalue);
	return;
}

int dequeue(LinearContainer & x)
{
	if (isempty(x)) return -9999;
	int hold = x.x[0];
	remove(x, 0);
	return hold;
}

