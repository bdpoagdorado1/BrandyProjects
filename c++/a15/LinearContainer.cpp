// Name: Brandy Poag
// File: LinearContainer.cpp

#include <iostream>
#include "LinearContainer.h"

void println(const LinearContainer & c) //  , int size
{
	std::cout << "[ ";
	for (int i = 0; i < c.len; i++)
	{
		std::cout << c.x[i] << ' '; // tried newArray++ and *(newArray + i)
	}	
	std::cout << "]\n";

	return;
}


void init(LinearContainer & c, int size)
{
	c.x = new int[size];

	// allocate memory for pointer c.x so that it points to an array of size
	// number of integers
	c.size = size;
	// set c.size to size
	c.len = 0;
	
	return;
}


void resize(LinearContainer & c, int newsize)
{
	// CASE: newsize is at least c.size:
	// declare newx, an int pointer, and allocate an array of newsize integers
	// for newx
	if (newsize > c.size)///newsize >= c.size
	{
		int * newx = new int[newsize];

		// copy all the values from the array c.x is pointing to over to the new array
		// newx is pointing to
		for (int i = 0; i < c.len; i++)
		{
			*(newx + i) = c.x[i];
		}
		// deallocate the memory c.x is pointing to
		delete [] c.x;
		// point c.x to the array newx is pointing to
		c.x = newx;
		// set c.size to newsize
		c.size = newsize;
	}
	else if (newsize < c.size)
	{
		// Once the above is working you need to think about what to do when newsize
		// is *less than* c.size. Everything should be the same except that
		// you only copy newsize integer values from the array c.x is pointing to
		// over to the array newx is pointing to.

		int * newx = new int[newsize];

		// copy all the values from the array c.x is pointing to over to the new array
		// newx is pointing to
		for (int i = 0; i < newsize; i++)
		{
			*(newx + i) = c.x[i];
		}
		// deallocate the memory c.x is pointing to
		delete [] c.x;
		// point c.x to the array newx is pointing to
		c.x = newx;
		// set c.size to newsize
		c.size = newsize;
		c.len = newsize;
	}
	/////////why need if else why not just say if not equal resize and else switch pointer??????????????????????
	return;
}


bool isempty(const LinearContainer & c)
{
	return (c.len == 0);
}


bool isfull(const LinearContainer & c)
{
	return (c.len == c.size);
}


int len(const LinearContainer & c)
{
	return c.len;
}


void insert(LinearContainer & c, int index, int newvalue)
{
	if (!isfull(c) && 0 <= index && index <= c.len)
	{
		for (int i = c.len - 1; i >= index; i--)
		{
			c.x[i + 1] = c.x[i];
		}
		c.len++;
		c.x[index] = newvalue;
	}
}


void remove(LinearContainer & c, int index)
{
	if (!isempty(c) && 0 <= index && index < c.len)
	{
		for (int i = index; i < c.len - 1; i++)
		{
			c.x[i] = c.x[i + 1];
		}
		c.len--;
	}
}


void push(LinearContainer & c, int newvalue)
{
	insert(c, c.len, newvalue);
}


int pop(LinearContainer & c)
{
	if (!isempty(c))
	{
		int popped = c.x[c.len - 1];
		remove(c, c.len - 1);
		return popped;
	}
	else
	{
		return NO_DATA;
	}
}


void enqueue(LinearContainer & c, int newvalue)
{
	insert(c, c.len, newvalue);
}


int dequeue(LinearContainer & c)
{
	if (!isempty(c))
	{
		int dequeued = c.x[0];
		remove(c, 0);
		return dequeued;
	}
	else
	{
		return NO_DATA;
	}
}

