// Author: Brandy Poag
// Date : 09/16/09
// File : Rational.cpp

#include <iostream>
#include <cmath>
#include "Rational.h"

int sign(int a)
{
	return (a >= 0 ? 1 : -1);
}


int min(int a, int b)
{
	return (a <= b ? a : b);
}


std::ostream & operator<<(std::ostream & cout, const Rational & r)
{
	int d = r.get_d();
	int n = r.get_n();
	if (d == 0)
	{
		cout << "UNDEFINED";
	}
	else if (n == 0)
	{
		cout << 0;
	}
	else
	{
		int abs_n = abs(n); // absolute value of r.n
		int abs_d = abs(d); // absolute value of d.n
		if (sign(n) * sign(d) == -1) cout << '-';
		cout << abs_n;
		if (abs_d != 1) cout << '/' << abs_d;
	}
	return cout;
}


void Rational::set_n(int i0)
{
	n = i0;
}


void Rational::set_d(int i0)
{
	d = i0;
}


Rational Rational::operator+(const Rational & b) const
{
	Rational ret(n * b.d + b.n * d, d * b.d);
	return ret;
}


Rational Rational::operator-(const Rational & b) const
{
	Rational ret(n * b.d - b.n * d, d * b.d);
	return ret;
}


Rational Rational::operator*(const Rational & b) const
{
	Rational ret(n * b.n, d * b.d);
	return ret;
}


Rational Rational::operator/(const Rational & b) const
{
	Rational ret(n * b.d, d * b.n);
	return ret;
}


void Rational::reduce()
{
	if (d == 0)
	{
		n = 1;
	}
	else if (n == 0)
	{
		d = 1;
	}
	else
	{
		int s = sign(n) * sign(d); // the sign of a
		int abs_n = abs(n); // abs value of numerator of a
		int abs_d = abs(d); // abs value of denominator of a
		// Compute g, the greatest common divisor of |a| and |b|.
		int g = min(abs_n, abs_d);
		while (abs_n % g != 0 || abs_d % g != 0)
		{
			g--;
		}
		n = s * abs_n / g;
		d = abs_d / g;
	}
	return;
}


bool Rational::operator!=(const Rational & b) const
{
	Rational a(n, d);
	return !(a.operator ==(b));
}


bool Rational::operator==(const Rational & b) const
{
	return (n * b.d == d * b.n);
}


bool Rational::operator>(const Rational & b) const
{
	Rational a(n, d);
	return (a.operator !=(b) && (!a.operator <(b)));
}


bool Rational::operator>=(const Rational & b) const
{
	Rational a(n, d);
	return (!a.operator <(b));
}


bool Rational::operator<(const Rational & b) const
{
	if (((d > -1) && (b.d > -1)) || ((d < -1) && (b.d < -1)))
		return (n * b.d < b.n * d);
	else
		return (n * b.d > b.n * d);
}


bool Rational::operator<=(const Rational & b) const
{
	Rational a(n, d);
	if (((d > -1) && (b.d > -1)) || ((d < -1) && (b.d < -1)))
		return ((n * b.d < b.n * d) || (a.operator ==(b)));
	else
		return ((n * b.d > b.n * d) || (a.operator ==(b)));
}