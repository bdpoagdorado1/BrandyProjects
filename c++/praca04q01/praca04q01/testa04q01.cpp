#include <iostream>
#include "prac04q01.h"

int main()
{
	Rational a(1, 2);
	Rational b(1);
	std::cout << a + 2 << '\n';
	std::cout << a << '\n';
	std::cout << 2 + a << '\n';
	std::cout << a << '\n';
	a += 2;
	std::cout << a << '\n';
	int bum = 2;
	bum = bum += b;
	std::cout << bum << '\n';
	Rational xd(1, -2);
	std::cout << xd.get_double() << '\n';
	std::cout << abs(xd) << '\n';

	/*Rational a(1, 2);
	std::cout << a - 2 << '\n';
	std::cout << a << '\n';
	std::cout << 3 - a << '\n';
	std::cout << a << '\n';
	a -= 2;
	std::cout << a << '\n';*/


	/*Rational a(1, 2);
	std::cout << a * 2 << '\n';
	std::cout << a << '\n';
	std::cout << 3 * a << '\n';
	std::cout << a << '\n';
	a *= 2;
	std::cout << a << '\n';*/

	/*Rational a(1, 2);
	std::cout << a / 2 << '\n';
	std::cout << a << '\n';
	std::cout << 3 / a << '\n';
	std::cout << a << '\n';
	a /= 2;
	std::cout << a << '\n';*/

	/*Rational a(1, 2);
	std::cout << a.operator !=(3) << '\n';
	std::cout << a.operator ==(5) << '\n';
	std::cout << a.operator >=(3) << '\n';
	std::cout << a.operator <=(3) << '\n';
	std::cout << a.operator >(3) << '\n';
	std::cout << a.operator <(0) << '\n';
	std::cout << a.operator !=(0) << '\n';
	std::cout << a.operator ==(3) << '\n';*/


	/*Rational a(2, 5);
	Rational c = - a;
	std::cout << c << '\n';*/

	/*Rational c(-1, 4);
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
	std::cout << f << '\n';*/


	
	return 0;
}
