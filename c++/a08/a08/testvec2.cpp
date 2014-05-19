// Name: Brandy Poag
// File: testvec2.cpp

#include <iostream>
#include "vec2.h"

typedef vec2< int > vec2i;
typedef vec2< float > vec2f;
typedef vec2< double > vec2d;

int main()
{
	vec2< int > u(1, 2);
	std::cout << u << '\n';
	vec2< float > v(1.2f, 3.4f);
	std::cout << v << '\n';
	vec2< double > w(1.2, 3.4);
	std::cout << w << '\n';
	vec2i u1(1, 2);
	std::cout << u1 << '\n';
	vec2f v1(1.2f, 3.4f);
	std::cout << v1 << '\n';
	vec2d w1(1.2, 3.4);
	std::cout << w1 << '\n';


	
	vec2i q(1.2, 8.9);
	std::cout << "q = " << q << std::endl;
	vec2f q1(1.2, 8.9);
	std::cout << "q1 = " << q1 << std::endl;
	vec2d q2(1.2, 8.9);
	std::cout << "q2 = " << q2 << std::endl;

	vec2i x;
	std::cout << x;
	vec2f x1;
	std::cout << x1;
	vec2d x2;
	std::cout << x2;

	vec2i z(2, 3);
	std::cout << z;
	vec2f z1(2, 3);
	std::cout << z1;
	vec2d z2(2, 3);
	std::cout << z2;

	vec2i y = z;
	std::cout << y;
	vec2f y1 = z1;
	std::cout << y1;
	vec2d y2 = z2;
	std::cout << y2;

	vec2i v3(1, 2), u3(1, 3), w3(1, 2);
	std::cout << (v3 == u3) << ' ' << (v3 == w3) << '\n';
	std::cout << (v3 != u3) << ' ' << (v3 != w3) << '\n';
	vec2f v10(1, 2), u10(1, 3), w10(1, 2);
	std::cout << (v10 == u10) << ' ' << (v10 == w10) << '\n';
	std::cout << (v10 != u10) << ' ' << (v10 != w10) << '\n';
	vec2d v20(1, 2), u20(1, 3), w20(1, 2);
	std::cout << (v20 == u20) << ' ' << (v20 == w20) << '\n';
	std::cout << (v20 != u20) << ' ' << (v20 != w20) << '\n';

	v3.set_y(2.2);
	v3.set_x(1.1);
	std::cout << v3;
	v10.set_y(2.2);
	v10.set_x(1.1);
	std::cout << v10;
	v20.set_y(2.2);
	v20.set_x(1.1);
	std::cout << v20;

	std::cout << v3[0] << '\n';
	v3[0] = 8;
	std::cout << v3[0] << '\n';
	std::cout << v3[1] << '\n';
	v3[1] = 9;
	std::cout << v3[1] << '\n';

	std::cout << v10[0] << '\n';
	v10[0] = 8;
	std::cout << v10[0] << '\n';
	std::cout << v10[1] << '\n';
	v10[1] = 9;
	std::cout << v10[1] << '\n';

	std::cout << v20[0] << '\n';
	v20[0] = 8;
	std::cout << v20[0] << '\n';
	std::cout << v20[1] << '\n';
	v20[1] = 9;
	std::cout << v20[1] << '\n';

	std::cout << u3 + w3;
	u3 += w3;
	std::cout << u3;
	std::cout << u10 + w10;
	u10 += w10;
	std::cout << u10;
	std::cout << u20 + w20;
	u20 += w20;
	std::cout << u20;

	u3.set_y(2);
	u3.set_x(1);
	w3.set_y(5);
	w3.set_x(4);
	std::cout << u3 - w3;
	u3 -= w3;
	std::cout << u3;

	u10.set_y(2);
	u10.set_x(1);
	w10.set_y(5);
	w10.set_x(4);
	std::cout << u10 - w10;
	u10 -= w10;
	std::cout << u10;

	u20.set_y(2);
	u20.set_x(1);
	w20.set_y(5);
	w20.set_x(4);
	std::cout << u20 - w20;
	u20 -= w20;
	std::cout << u20;

	u3.set_y(2);
	u3.set_x(3);
	w3.set_y(2);
	w3.set_x(1);
	std::cout << u3 * w3;
	u3 *= w3;
	std::cout << u3;

	u10.set_y(2);
	u10.set_x(3);
	w10.set_y(2);
	w10.set_x(1);
	std::cout << u10 * w10;
	u10 *= w10;
	std::cout << u10;

	u20.set_y(2);
	u20.set_x(3);
	w20.set_y(2);
	w20.set_x(1);
	std::cout << u20 * w20;
	u20 *= w20;
	std::cout << u20;

	u3.set_y(2);
	u3.set_x(2);
	w3.set_y(2);
	w3.set_x(1);
	std::cout << u3 / w3;
	u3 /= w3;
	std::cout << u3;

	u10.set_y(2);
	u10.set_x(2);
	w10.set_y(2);
	w10.set_x(1);
	std::cout << u10 / w10;
	u10 /= w10;
	std::cout << u10;

	u20.set_y(2);
	u20.set_x(2);
	w20.set_y(2);
	w20.set_x(1);
	std::cout << u20 / w20;
	u20 /= w20;
	std::cout << u20;

	u3 = u3 + w3;
	std::cout << u3;

	u10 = u10 + w10;
	std::cout << u10;

	u20 = u20 + w20;
	std::cout << u20;

	u3 = -u3;
	std::cout << u3;

	u10 = -u10;
	std::cout << u10;

	u20 = -u20;
	std::cout << u20;

	std::cout << u3;
	std::cout << u3 * 5;
	std::cout << u3;
	u3 *= 5;
	std::cout << u3;

	std::cout << u10;
	std::cout << u10 * 5;
	std::cout << u10;
	u10 *= 5;
	std::cout << u10;

	std::cout << u20;
	std::cout << u20 * 5;
	std::cout << u20;
	u20 *= 5;
	std::cout << u20;
	

	std::cout << "+\n";
	u3.set_x(5);
	u3.set_y(10);
	std::cout << 5 + u3;
	std::cout << u3;
	std::cout << u3 + 5;
	std::cout << u3;
	u3 += 5;
	std::cout << u3;

	std::cout << "+\n";
	u10.set_x(5);
	u10.set_y(10);
	std::cout << (float)5 + u10;
	std::cout << u10;
	std::cout << u10 + 5;
	std::cout << u10;
	u10 += 5;
	std::cout << u10;

	std::cout << "+\n";
	u20.set_x(5);
	u20.set_y(10);
	std::cout << (double)5 + u20;
	std::cout << u20;
	std::cout << u20 + 5;
	std::cout << u20;
	u20 += 5;
	std::cout << u20;

	std::cout << "-\n";
	u3.set_x(5);
	u3.set_y(10);
	std::cout << 5 - u3;
	std::cout << u3;
	std::cout << u3 - 5;
	std::cout << u3;
	u3 -= 5;
	std::cout << u3;

	std::cout << "-\n";
	u10.set_x(5);
	u10.set_y(10);
	std::cout << (float)5 - u10;
	std::cout << u10;
	std::cout << u10 - 5;
	std::cout << u10;
	u10 -= 5;
	std::cout << u10;

	std::cout << "-\n";
	u20.set_x(5);
	u20.set_y(10);
	std::cout << (double)5 - u20;
	std::cout << u20;
	std::cout << u20 - 5;
	std::cout << u20;
	u20 -= 5;
	std::cout << u20;

	std::cout << "/\n";
	u3.set_x(5);
	u3.set_y(10);
	std::cout << 5 / u3;
	std::cout << u3;
	std::cout << u3 / 5;
	std::cout << u3;
	u3 /= 5;
	std::cout << u3;

	std::cout << "/\n";
	u10.set_x(5);
	u10.set_y(10);
	std::cout << (float)5 / u10;
	std::cout << u10;
	std::cout << u10 / 5;
	std::cout << u10;
	u10 /= 5;
	std::cout << u10;

	std::cout << "/\n";
	u20.set_x(5);
	u20.set_y(10);
	std::cout << (double)5 / u20;
	std::cout << u20;
	std::cout << u20 / 5;
	std::cout << u20;
	u20 /= 5;
	std::cout << u20;


	vec2i j(3, 4);
	std::cout << len(j)<< '\n';

	vec2f j2(3, 4);
	std::cout << len(j)<< '\n';

	vec2d j3(3, 4);
	std::cout << len(j)<< '\n';


	vec2i k1(1, 2), l1(3, 4);
	int d1 = dotprod(k1, l1);
	std::cout << d1 << '\n';

	vec2d k2(1, 2), l2(3, 4);
	double d2 = dotprod(k2, l2);
	std::cout << d2 << '\n';

	vec2f k3(1, 2), l3(3, 4);
	float d3 = dotprod(k3, l3);
	std::cout << d3 << '\n';

	
	return 0;
}
