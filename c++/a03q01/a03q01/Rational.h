// Name: Brandy Poag
// File: Rational.h

#include <iostream>

#ifndef RATIONAL_H
#define RATIONAL_H

int GCD(int, int);
int sign(int);

class Rational
{
public:
	Rational(int a = 0, int b = 1) : n(a), d(b) {}
	Rational(const Rational & r) : n(r.n), d(r.d) { }
	int get_n() const { return n; }
	int get_d() const { return d; }

	void reduce();

	bool operator==(const Rational &) const;
	bool operator!=(const Rational &) const;
	bool operator> (const Rational &) const;
	bool operator>=(const Rational &) const;
	bool operator< (const Rational &) const;
	bool operator<=(const Rational &) const;

	Rational & operator+=(const Rational &);
	Rational & operator-=(const Rational &);
	Rational & operator*=(const Rational &);
	Rational & operator/=(const Rational &);

	Rational operator+(const Rational &) const;
	Rational operator-(const Rational &) const;
	Rational operator*(const Rational &) const;
	Rational operator/(const Rational &) const;

private:
	int n, d;
};

std::ostream & operator<<(std::ostream &, const Rational &);

#endif
