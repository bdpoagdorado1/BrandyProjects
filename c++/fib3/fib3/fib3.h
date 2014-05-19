#ifndef FIB3_H
#define FIB3_H

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

	/*void resize(int n)
	{
		if (capacity0 < n + 1)
		{
			int *temp = new int[n + 1];

			for (int i = 0; i < capacity0; i++)
			{
				temp[i] = table[i];
			}

			delete [] table;
			table = temp;
			for (int i = capacity0; i <= n; i++)
			{
				table[i] = -1;
			}
			capacity0 = n + 1;
		}
	}*/

	static Fib fib;

private:

	IntDynArray table;
	Fib() : table(20) { }
	Fib(const Fib & ) { }
};

#endif