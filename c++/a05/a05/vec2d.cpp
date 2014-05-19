// Name: Brandy Poag
// File: vec2d.cpp


#include <iostream>
#include <cmath>
#include "vec2d.h"


std::ostream & operator<<(std::ostream & out, const VEC2D & vec)
{
	return out << '(' << vec.get_x() << ", " << vec.get_y() << ')' << '\n';
}


bool VEC2D::operator==(const VEC2D & vec) const
{
	return (x == vec.x && y == vec.y);
}


bool VEC2D::operator!=(const VEC2D & vec) const
{
	return !(x == vec.x && y == vec.y);
}


double & VEC2D::operator[](const double a)
{
	if (a == 0)
	{
		return (x);
	}
	else if (a == 1)
	{
		return (y);
	}
	else 
	{
		std::cout << "Error!\n";
		return (x);
	}
}


VEC2D & VEC2D::operator+=(const VEC2D & vec)
{
	x += vec.get_x();
	y += vec.get_y();
	return (*this);
}


VEC2D & VEC2D::operator-=(const VEC2D & vec)
{
	x -= vec.get_x();
	y -= vec.get_y();
	return (*this);
}


VEC2D & VEC2D::operator*=(const VEC2D & vec)
{
	x *= vec.get_x();
	y *= vec.get_y();
	return (*this);
}


VEC2D & VEC2D::operator/=(const VEC2D & vec)
{
	x /= vec.get_x();
	y /= vec.get_y();
	return (*this);
}

VEC2D VEC2D::operator+(const VEC2D & vec) const
{
	return (VEC2D(*this) += vec);
}


VEC2D VEC2D::operator-(const VEC2D & vec) const
{
	return (VEC2D(*this) -= vec);
}


VEC2D VEC2D::operator*(const VEC2D & vec) const
{
	return (VEC2D(*this) *= vec);
}


VEC2D & VEC2D::operator/(const VEC2D & vec) const
{
	return (VEC2D(*this) /= vec);
}


VEC2D & VEC2D::operator-()
{
	x *= -1;
	y *= -1;
	return (*this);
}

VEC2D & VEC2D::operator+=(const double a)
{
	x += a;
	y += a;
	return (*this);
}


VEC2D & VEC2D::operator-=(const double a)
{
	x -= a;
	y -= a;
	return (*this);
}


VEC2D & VEC2D::operator*=(const double a)
{
	x *= a;
	y *= a;
	return (*this);
}


VEC2D & VEC2D::operator/=(const double a)
{
	x /= a;
	y /= a;
	return (*this);
}


VEC2D get_vec2d(const double a)
{
	return VEC2D(a, a);
}

VEC2D VEC2D::operator+(const double a) const
{
	return (VEC2D(*this) += a);
}


VEC2D VEC2D::operator-(const double a) const
{
	return (VEC2D(*this) -= a);
}


VEC2D VEC2D::operator*(const double a) const
{
	return (VEC2D(*this) *= a);
}


VEC2D VEC2D::operator/(const double a) const
{
	return (VEC2D(*this) /= a);
}


VEC2D operator+(const double a, const VEC2D & vec1)
{
	return (get_vec2d(a) += vec1);
}


VEC2D operator-(const double a, const VEC2D & vec1)
{
	return (get_vec2d(a) -= vec1);
}


VEC2D operator*(const double a, const VEC2D & vec1)
{
	return (get_vec2d(a) *= vec1);
}


VEC2D operator/(const double a, const VEC2D & vec1)
{
	return (get_vec2d(a) /= vec1);
}


double len(const VEC2D & vec)
{
	return sqrt(vec.get_x()*vec.get_x()+vec.get_y()*vec.get_y());
}


double dotprod(const VEC2D & vec1, const VEC2D & vec2)
{
	return (vec1.get_x()*vec2.get_x()+vec1.get_y()*vec2.get_y());
}
