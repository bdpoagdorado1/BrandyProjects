#include <iostream>
#include "prac04q01.h"


int & operator+=(int & i, const Rational & r)
{
	i = (Rational(i) += r).get_int();
	/*Rational a(i);
	a += r;
	i = a.get_int();*/
	return i;
}


Rational operator+(const int i, const Rational & r)
{
	return(Rational(i) += r);
}


Rational operator-(int i, const Rational & r)
{
	return(Rational(i) -= r);
}


Rational operator*(int i, const Rational & r)
{
	return(Rational(i) *= r);
}


Rational operator/(int i, const Rational & r)
{
	return(Rational(i) /= r);
}


Rational abs(const Rational & r)
{
	return Rational(abs(r.get_n()), abs(r.get_d()));
}


int & operator-=(int & i, const Rational & r)
{
	Rational a(i);
	a -= r;
	i = a.get_int();
	return i;
}


int & operator*=(int & i, const Rational & r)
{
	Rational a(i);
	a *= r;
	i = a.get_int();
	return i;
}


int & operator/=(int & i, const Rational & r)
{
	Rational a(i);
	a /= r;
	i = a.get_int();
	return i;
}


Rational operator+(const double i, const Rational & r)
{
	return(Rational(i) += r);
}


int Rational::get_int() const
{
	return n / d;
}


double Rational::get_double() const 
{
	return double(n) / double(d);
}


Rational Rational::operator-() const
{
	return *this * -1;
}


void Rational::reduce()
{
	int a = abs(n);
	int b = abs(d);
	int g = GCD(a,b);
	a /= g;
	b /= g;
	n = sign(n) * sign(d) * a;
	d = b;
}


// Helper functions for reduce
int abs(int n)
{
	return (n >= 0 ? n : -n);
}


int sign(int n)
{
	return (n >= 0 ? 1 : -1);
}


int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}


bool operator==(int i, const Rational & r)
{
	return(Rational(i) == r);
}


bool operator!=(int i, const Rational & r)
{
	return(Rational(i) != r);
}


bool operator> (int i, const Rational & r)
{
	return(Rational(i) > r);
}


bool operator>=(int i, const Rational & r)
{
	return(Rational(i) >= r);
}


bool operator< (int i, const Rational & r)
{
	return(Rational(i) < r);
}


bool operator<=(int i, const Rational & r)
{
	return(Rational(i) <= r);
}


bool Rational::operator==(const Rational & r) const
{
	return (n * r.d == r.n * d);
}


bool Rational::operator!=(const Rational & r) const
{
    return !(operator==(r));
}


bool Rational::operator<(const Rational & r) const
{
	int flip = sign(d) * sign(r.d);
	return (flip == 1 ? n * r.d < r.n * d : n * r.d > r.n * d);
}


bool Rational::operator<=(const Rational & r) const
{
    return (operator<(r) || operator==(r));
}


bool Rational::operator>(const Rational & r) const
{
    return !(operator<=(r));
}


bool Rational::operator>=(const Rational & r) const
{
    return !(operator<(r));
}


Rational & Rational::operator+=(const Rational & a)
{
	n = n * a.d + a.n * d;
	d *= a.d;
	return (*this);
}


Rational & Rational::operator-=(const Rational & a)
{
	n = n * a.d - a.n * d;
	d *= a.d;
	return (*this);
}


Rational & Rational::operator*=(const Rational & r)
{
	n *= r.n;
	d *= r.d;
	return (*this);
}


Rational & Rational::operator/=(const Rational & r)
{
	n *= r.d;
	d *= r.n;
	return (*this);
}


Rational Rational::operator+(const Rational & r) const
{
	return (Rational(*this) += r);
}


Rational Rational::operator*(const Rational & r) const
{
	return (Rational(*this) *= r);
}


Rational Rational::operator-(const Rational & r) const
{
	return (Rational(*this) -= r);
}


Rational Rational::operator/(const Rational & r) const
{
	return (Rational(*this) /= r);
}


std::ostream & operator<<(std::ostream & cout, const Rational & r)
{
    if (r.get_d() == 0)
    {
        cout << "UNDEFINED";
    }
    else if (r.get_n() == 0)
    {
        cout << 0;
    }
    else
    {
        int abs_n = abs(r.get_n()); // absolute value of r.n
        int abs_d = abs(r.get_d()); // absolute value of d.n

        if (sign(r.get_n()) * sign(r.get_d()) == -1) cout << '-';

        cout << abs_n;

        if (abs_d != 1) cout << '/' << abs_d;
    }
    return cout;
}
