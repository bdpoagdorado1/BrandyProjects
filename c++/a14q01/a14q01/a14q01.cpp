// Name: Brandy Poag
// File: a14q01.cpp

#include <iostream>
#include "set.h"

void test_set_println()
{
	int x[] = {5, 3, 1, 3, 5};
	int len = 0;
	set_println(x, len); // prints {} (and newline)

	len = 1;
	set_println(x, len); // prints {5} (and newline)

	len = 2;
	set_println(x, len); // prints {5, 3} (and newline)

	len = 5;
	set_println(x, len); // prints {5, 3, 1, 3, 5} (and newline)
}


void test_set_hasmember()
{
	int x[] = {5, 3, 1, 3, 5, 2};
	int len = 0;
	std::cout << (!set_hasmember(x, len, 1)) << ' ';

	len = 1;
	std::cout << set_hasmember(x, len, 5) << ' ';
	std::cout << (!set_hasmember(x, len, 3)) << ' ';
	std::cout << (!set_hasmember(x, len, 1)) << ' ';
	std::cout << (!set_hasmember(x, len, 2)) << ' ';

	len = 2;
	std::cout << set_hasmember(x, len, 5) << ' ';
	std::cout << set_hasmember(x, len, 3) << ' ';
	std::cout << (!set_hasmember(x, len, 1)) << ' ';
	std::cout << (!set_hasmember(x, len, 2)) << ' ';

	len = 3;
	std::cout << set_hasmember(x, len, 5) << ' ';
	std::cout << set_hasmember(x, len, 3) << ' ';
	std::cout << set_hasmember(x, len, 1) << ' ';
	std::cout << (!set_hasmember(x, len, 2)) << ' ';

	len = 6;
	std::cout << set_hasmember(x, len, 2) << ' ';

	std::cout << std::endl;
}

void test_set_modify()
{
	int x[10] = {5, 3, 1, 3, 5};
	int len = 5;

	set_insert(x, len, 2);
	
	set_remove(x, len, 5);
	
	std::cout << set_hasmember(x, len, 1) << ' ';
	std::cout << set_hasmember(x, len, 3) << ' ';
	std::cout << (!set_hasmember(x, len, 5)) << ' ';

	set_remove(x, len, 6);
	std::cout << (!set_hasmember(x, len, 6)) << ' ';

	set_clear(x, len);

	std::cout << std::endl;
}

void test_set_issubset()
{
	int x[] = {1, 3, 5};
	int xlen;
	int y[] = {5, 1, 3, 3, 5, 5};
	int ylen;

	xlen = 0;
	ylen = 0;
	std::cout << set_issubset(x, xlen, y, ylen) << ' ';

	xlen = 0;
	ylen = 1;
	std::cout << set_issubset(x, xlen, y, ylen) << ' ';

	xlen = 1;
	ylen = 0;
	std::cout << (!set_issubset(x, xlen, y, ylen)) << ' ';

	xlen = 1;
	ylen = 1;
	std::cout << (!set_issubset(x, xlen, y, ylen)) << ' ';

	xlen = 1;
	ylen = 2;
	std::cout << set_issubset(x, xlen, y, ylen) << ' ';

	xlen = 2;
	ylen = 2;
	std::cout << (!set_issubset(x, xlen, y, ylen)) << ' ';
	
	xlen = 3;
	for (ylen = 3; ylen <= 6; ylen++)
	{
		std::cout << set_issubset(x, xlen, y, ylen) << ' ';
	}


	std::cout << std::endl;
}

void test_set_isequal()
{
	int x[] = {1, 3, 5};
	int xlen;
	int y[] = {5, 1, 3, 3, 5, 5};
	int ylen;

	xlen = 0;
	ylen = 0;
	std::cout << set_isequal(x, xlen, y, ylen) << ' ';

	xlen = 1;
	ylen = 1;
	std::cout << (!set_isequal(x, xlen, y, ylen)) << ' ';

	xlen = 2;
	ylen = 2;
	std::cout << (!set_isequal(x, xlen, y, ylen)) << ' ';

	xlen = 3;
	ylen = 3;
	std::cout << set_isequal(x, xlen, y, ylen) << ' ';

	xlen = 3;
	ylen = 4;
	std::cout << set_isequal(x, xlen, y, ylen) << ' ';

	std::cout << std::endl;
}

int main()
{
	test_set_println();
	test_set_hasmember();
	test_set_modify();
	test_set_issubset();
	test_set_isequal();
	return 0;
}
