// Name: Brandy Poag
// File: set.cpp

#include "set.h"
#include <iostream>

void set_println(int x[], int & length)
{
	std::cout << '{';

	for (int i = 0; i < length; i++)
	{
		if (i != 0) std::cout << ", ";
		std::cout << x[i];
	}

	std::cout << "}\n";
	return;
}

bool set_hasmember(int x[], int & len, int i)
{
	bool check = false;

	for (int j = 0; j < len; j++)
	{
		if (x[j] == i)
		{
			check = true;
			break;
		}
	}
	
	return check;
}

void set_insert(int x[], int & len, int i)
{
	x[len] = i;
	++len;
	return;
}

void set_remove(int x[], int & len, int i)
{
	int count = 0;
	for (int j = 0; j < len; ++j)
	{
		if (x[j] == i)
		{
			for (int m = j; m < len - 1; ++m)
			{
				x[m] = x[m + 1];
			}
			++count;
		}	
	}
	len -= count;
	return;
}

void set_clear(int x[], int & len)
{
	for (int i = 0; i < len; i++)
	{
		x[i] = 0;
	}
	len = 0;
	return;
}

bool set_issubset(int x[], int & xlen, int y[], int & ylen)
{
	bool found = false;

	for (int i = 0; i < ylen; i++)
	{
		found = set_hasmember(x, xlen, y[i]);
		if (!found && xlen != 1) break;
		
	}
	if (ylen == 0 && xlen > 0) found = false;
	if (xlen == 0) found = true;
	return found;
}

bool set_isequal(int x[], int & xlen, int y[], int & ylen)
{
	bool check = false;

	if (set_issubset(x, xlen, y, ylen)) check = true;

	return check;
}
