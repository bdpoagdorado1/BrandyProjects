// Author: Brandy Poag
// Date : 09/09/09
// File : testRational.cpp

#include <iostream>
#include "Rational.h"

int main()
{

	std::cout << "Testing Rational ...\n";

	Rational r = {1, 2};
	std::cout << "You should see 1/2 ... " << r << std::endl;
	r.n = -1;
	r.d = -2;
	std::cout << "You should see 1/2 ... " << r << std::endl;
	r.n = 3;
	r.d = 1;
	std::cout << "You should see 3 ... " << r << std::endl;
	r.n = 3;
	r.d = -1;
	std::cout << "You should see -3 ... " << r << std::endl;
	r.n = 3;
	r.d = -1;
	std::cout << "You should see -3 ... " << r << std::endl;

	Rational a = {1, 2};
	Rational b = {1, 4};
	Rational c = {1, 2};
	Rational d = {1, -4};
	Rational e = {-1, -2};
	Rational f = {-4, -2};
	Rational g = {-2, 2};
	Rational h = {-5, 2};
	Rational i = {30, 21};
	Rational j = {15, 10};
	Rational k = {10, 5};
	Rational l = {5, 10};

	std::cout << "You should see 6/8 ... " << a + b << std::endl;
	std::cout << "You should see 6/8 ... " << a + b << std::endl;
	std::cout << "You should see 6/8 ... " << b + a << std::endl;
	std::cout << "You should see 6/8 ... " << c + b << std::endl;
	std::cout << "You should see 4/4 ... " << c + e << std::endl;
	std::cout << "You should see 4/4 ... " << c + a << std::endl;
	std::cout << "You should see 2/8 ... " << e + d << std::endl;

	std::cout << "You should see 1/4 ... " << c - b << std::endl;
	std::cout << "You should see 0 ... " << c - a << std::endl;

	std::cout << "You should see -1/2 ... " << g * e << std::endl;
	std::cout << "You should see 1/8 ... " << a * b << std::endl;

	std::cout << "You should see 2/4 ... " << b / a << std::endl;
	std::cout << "You should see -4/2 ... " << e / d << std::endl;

	std::cout << "You should see 1 ... " << (c == e) << std::endl;
	std::cout << "You should see 1 ... " << (c == a) << std::endl;

	std::cout << "You should see 1 ... " << (e != d) << std::endl;

	std::cout << "You should see 10/7 ... " << reduce(i) << std::endl;
	std::cout << "You should see -1 ... " << reduce(g) << std::endl;
	std::cout << "You should see 2 ... " << reduce (f) << std::endl;
	std::cout << "You should see -5/2 ... " << reduce(h) << std::endl;
	std::cout << "You should see 3/2 ... " << reduce(j) << std::endl;
	std::cout << "You should see 2 ... " << reduce (k) << std::endl;
	std::cout << "You should see 1/2 ... " << reduce(l) << std::endl;
	

	Rational x = {15, 0};
	Rational y = {10, -5};
	Rational z = {5, 10};

	std::cout << "You should see -3/2 ... " << z + y << std::endl;
	std::cout << "You should see undefined ... " << y - x << std::endl;
	std::cout << "You should see -1 ... " << y * z << std::endl;
	std::cout << "You should see 0 ... " << y / x << std::endl;
	std::cout << "You should see 0 ... " << y * x << std::endl;
	std::cout << "You should see undefined ... " << reduce(x) << std::endl;
	
	return 0;
}