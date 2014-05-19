// Name: Brandy Poag
// File: vec2d.h

#include <iostream>

#ifndef VEC2D_H
#define VEC2D_H


class VEC2D
{
public:
	VEC2D(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}
	VEC2D(const VEC2D & vec) : x(vec.x), y(vec.y) {}
	VEC2D & operator=(const VEC2D & vec)
	{
		x = vec.x;
		y = vec.y;
		return *this;
	}
	double get_x() const { return x; }
	double get_y() const { return y; }

	void set_y(double y0) { y = y0; }
	void set_x(double x0) { x = x0; }

	bool operator==(const VEC2D & vec) const;
	bool operator!=(const VEC2D & vec) const;

	double & operator[](const double a);

	VEC2D & operator-();

	VEC2D & operator+=(const VEC2D & vec);
	VEC2D & operator-=(const VEC2D & vec);
	VEC2D & operator*=(const VEC2D & vec);
	VEC2D & operator/=(const VEC2D & vec);

	VEC2D operator+(const VEC2D & vec) const;
	VEC2D operator-(const VEC2D & vec) const;
	VEC2D operator*(const VEC2D & vec) const;
	VEC2D & operator/(const VEC2D & vec) const;

	VEC2D & operator+=(const double a);
	VEC2D & operator-=(const double a);
	VEC2D & operator*=(const double a);
	VEC2D & operator/=(const double a);

	VEC2D operator+(const double a) const;
	VEC2D operator-(const double a) const;
	VEC2D operator*(const double a) const;
	VEC2D operator/(const double a) const;
private:
	double x;
	double y;
};

std::ostream & operator<<(std::ostream & out, const VEC2D & vec);

VEC2D operator+(const double a, const VEC2D & vec1);
VEC2D operator-(const double a, const VEC2D & vec1);
VEC2D operator*(const double a, const VEC2D & vec1);
VEC2D operator/(const double a, const VEC2D & vec1);

VEC2D get_vec2d(const double a);

double len(const VEC2D & vec);
double dotprod(const VEC2D & vec1, const VEC2D & vec2);

#endif

