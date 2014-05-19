// Name: Brandy Poag
// File: testRational.cpp

#include <iostream>
#include "Rational.h"

int main()
{
	Rational a(1, 2);
	Rational b(1, 2);
	std::cout << a + b << '\n';
	std::cout << a << '\n';
	(a += b) += b;
	a.reduce();
	std::cout << a << '\n';

	Rational c(-1, 4);
	Rational d(3);
	std::cout << c - d << '\n';
	std::cout << c << '\n';
	(c -= b) -= b;
	c.reduce();
	std::cout << c << '\n';

	Rational j(3, 1);
	Rational n(2, 1);
	std::cout << j * n << '\n';
	std::cout << j << '\n';
	(j *= n) += n;
	j.reduce();
	std::cout << j << '\n';

	Rational f(-2, 3);
	Rational g(1);
	std::cout << f / g << '\n';
	std::cout << f << '\n';
	(f /= g) /= g;
	f.reduce();
	std::cout << f << '\n';



	Rational s(10);
	Rational t(5);
	std::cout << s + t << '\n';
	std::cout << s << '\n';
	(s += t) += t;
	s.reduce();
	std::cout << s << '\n';

	Rational q(6);
	Rational u(2);
	std::cout << q - u << '\n';
	std::cout << q << '\n';
	(q -= u) -= u;
	q.reduce();
	std::cout << q << '\n';

	Rational x(1);
	Rational w(2, 4);
	std::cout << x * w << '\n';
	std::cout << x << '\n';
	(x *= w) += w;
	x.reduce();
	std::cout << x << '\n';

	Rational z(3, -15);
	Rational y(3);
	std::cout << z / y << '\n';
	std::cout << z << '\n';
	(z /= y) /= y;
	z.reduce();
	std::cout << z << '\n';


	
	return 0;
}