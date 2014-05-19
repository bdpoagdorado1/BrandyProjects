// Author: Brandy Poag
// Date : 09/09/09
// File : Rational.cpp

#include <iostream>
#include <cmath>
#include "Rational.h"

std::ostream & operator<<(std::ostream & cout, const Rational & r)
{
	char sign = '+';
	if ((r.n >= 0 && r.d < 0) || (r.n < 0 && r.d >= 0)) sign = '-';

	if (r.n == 0)
	{
		cout << 0;
	}
	else if (r.d == 0)
	{
		cout << "UNDEFINED";
	}
	else if (sign == '+' && r.n < 0 && r.d < 0)
	{
		if (r.n / r.d == r.n || r.n / r.d == -(r.n)) cout << -(r.n);
		else cout << -(r.n) << '/' << -(r.d);
	}
	else if (sign == '-' && r.n < 0) 
	{	
		if (r.n / r.d == r.n || r.n / r.d == -(r.n)) cout << sign << -(r.n);
		else cout << sign << -(r.n) << '/' << r.d;
	}
	else if (sign == '-' && r.d < 0)
	{
		if (r.n / r.d == r.n || r.n / r.d == -(r.n)) cout << sign << r.n;
		else cout << sign << r.n << '/' << -(r.d);
	}
	else if (sign == '+') 
	{
		if (r.n / r.d == r.n || r.n / r.d == -(r.n)) cout << r.n;
		else cout << r.n << '/' << r.d;
	}
	return cout;
}


Rational operator+(const Rational &a, const Rational &b)
{
	Rational add;

	add.n = a.n*b.d + a.d*b.n;
	add.d = a.d*b.d;
	return add;
}


Rational operator-(const Rational &a, const Rational &b)
{
	Rational sub;

	sub.n = a.n*b.d - a.d*b.n;
	sub.d = a.d*b.d;
	return sub;
}


Rational operator*(const Rational &a, const Rational &b)
{
	Rational mult;

	mult.n = a.n*b.n;
	mult.d = a.d*b.d;
	return mult;
}


Rational operator/(const Rational &a, const Rational &b)
{
	Rational div;

	div.n = a.n*b.d;
	div.d = a.d*b.n;
	return div;
}


bool operator==(const Rational &a, const Rational &b)
{
	return (a.n * b.d == b.n * a.d);
}


bool operator!=(const Rational &a, const Rational &b)
{
	return !(a==b);
}


Rational reduce(Rational &a)
{
	for (int i = (abs(a.n) < abs(a.d) ? abs(a.n) : abs(a.d)); i >= 1; i--)
	{
		if (a.n % i == 0 && a.d % i == 0)
		{
			a.n /= i;
			a.d /= i;
		}
		if (abs(a.n) == 1 || abs(a.d) == 1) return a;
	}
	return a;
}
