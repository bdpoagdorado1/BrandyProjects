// Name: Brandy Poag
// File: testvec2d.cpp


#include <iostream>
#include "vec2d.h"


int main()
{
	VEC2D q(1.2, 8.9);
	std::cout << "q = " << q << std::endl;

	VEC2D x;
	std::cout << x;

	std::cout << 5 / q;
	std::cout << q;

	/*VEC2D z(2, 3);
	std::cout << z;

	VEC2D y = z;
	std::cout << y;

	VEC2D v(1, 2), u(1, 3), w(1, 2);
	std::cout << (v == u) << ' ' << (v == w) << '\n';
	std::cout << (v != u) << ' ' << (v != w) << '\n';

	v.set_y(2.2);
	v.set_x(1.1);
	std::cout << v;

	std::cout << v[0] << '\n';
	v[0] = 8;
	std::cout << v[1] << '\n';
	v[1] = 9;

	std::cout << v;

	std::cout << u + w;
	u += w;
	std::cout << u;

	u.set_y(2);
	u.set_x(1);
	w.set_y(5);
	w.set_x(4);
	std::cout << u - w;
	u -= w;
	std::cout << u;

	u.set_y(2);
	u.set_x(3);
	w.set_y(2);
	w.set_x(1);
	std::cout << u * w;
	u *= w;
	std::cout << u;

	u.set_y(2);
	u.set_x(2);
	w.set_y(2);
	w.set_x(1);
	std::cout << u / w;
	u /= w;
	std::cout << u;

	u = u + w;
	std::cout << u;

	u = -u;
	std::cout << u;

	std::cout << 5 * u;
	std::cout << u;
	std::cout << u * 5;
	std::cout << u;
	u *= 5;
	std::cout << u;
	std::cout << "+\n";
	u.set_x(5);
	u.set_y(10);
	std::cout << 5 + u;
	std::cout << u;
	std::cout << u + 5;
	std::cout << u;
	u += 5;
	std::cout << u;
	std::cout << "-\n";
	u.set_x(5);
	u.set_y(10);
	std::cout << 5 - u;
	std::cout << u;
	std::cout << u - 5;
	std::cout << u;
	u -= 5;
	std::cout << u;
	std::cout << "/\n";
	u.set_x(5);
	u.set_y(10);
	std::cout << 5 / u;
	std::cout << u;
	std::cout << u / 5;
	std::cout << u;
	u /= 5;
	std::cout << u;

	VEC2D j(3, 4);
	std::cout << len(j)<< '\n';

	VEC2D k(1, 2), l(3, 4);
	double d = dotprod(k, l);
	std::cout << d << '\n';*/

	return 0;
}