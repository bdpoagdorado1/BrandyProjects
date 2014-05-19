// File: Fib.h
// Name: Brandy Poag

#ifndef FIB_H
#define FIB_H

#include "IntDynArray.h"

class Fib
{
public:
	int operator() (int n)
	{
		if (n <= 1) return 1;
		if (n >= table.get_size()) table.resize(n + 1);
		return comp_fib(n);
	}
	int comp_fib( int n )
	{
		if (n <= 1) return 1;
		if (table[n] == -1)
		{
			table[n] = comp_fib(n - 1) + comp_fib(n - 2);
		}

		return table[n];
	}

	static Fib fib;

private:

	IntDynArray table;
	Fib() : table(20) { }
	Fib(const Fib & ) { }
};

#endif