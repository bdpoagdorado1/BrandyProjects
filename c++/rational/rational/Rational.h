// Author: Brandy Poag
// Date : 09/09/09
// File : Rational.h
#ifndef RATIONAL_H
#define RATIONAL_H

struct Rational
{
	int n; // numerator
	int d; // denominator
};

std::ostream & operator<<(std::ostream &, const Rational &r);
Rational operator+(const Rational &a, const Rational &b);
Rational operator-(const Rational &a, const Rational &b);
Rational operator*(const Rational &a, const Rational &b);
Rational operator/(const Rational &a, const Rational &b);
bool operator==(const Rational &a, const Rational &b);
bool operator!=(const Rational &a, const Rational &b);
Rational reduce(Rational &a);

#endif

