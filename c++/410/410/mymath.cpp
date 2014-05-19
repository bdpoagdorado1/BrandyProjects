// File: mymath.cpp

#include <iostream>

#include "mymath.h"

int max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}


int square(int x)
{
	return x * x;
}