// Name: Brandy Poag
// File: vec2.h

#include <iostream>
#include <cmath>

#ifndef VEC2_H
#define VEC2_H

template< class T >

class vec2
{
public:
	vec2(T x0 = 0, T y0 = 0) : x(x0), y(y0) {}
	vec2(const vec2 & vec) : x(vec.x), y(vec.y) {}
	vec2 & operator=(const vec2 & vec)
	{
		x = vec.x;
		y = vec.y;
		return *this;
	}
	T get_x() const { return x; }
	T get_y() const { return y; }

	void set_y(T y0) { y = y0; }
	void set_x(T x0) { x = x0; }

	bool operator==(const vec2 & vec) const;
	bool operator!=(const vec2 & vec) const;

	T & operator[](int a);
	T operator[](int a) const;

	vec2 operator-() const;

	vec2 & operator+=(const vec2 & vec);
	vec2 & operator-=(const vec2 & vec);
	vec2 & operator*=(const vec2 & vec);
	vec2 & operator/=(const vec2 & vec);

	vec2 operator+(const vec2 & vec) const;
	vec2 operator-(const vec2 & vec) const;
	vec2 operator*(const vec2 & vec) const;
	vec2 operator/(const vec2 & vec) const;

	vec2 & operator+=(T a);
	vec2 & operator-=(T a);
	vec2 & operator*=(T a);
	vec2 & operator/=(T a);

	vec2 operator+(T a) const;
	vec2 operator-(T a) const;
	vec2 operator*(T a) const;
	vec2 operator/(T a) const;

	
private:
	T x;
	T y;
};

template< class T >
std::ostream & operator<<(std::ostream & out, const vec2< T > & vec)
{
	return out << '(' << vec.get_x() << ", " << vec.get_y() << ')' << '\n';
}

template< class T >
bool vec2< T >::operator==(const vec2 & vec) const
{
	return (x == vec.x && y == vec.y);
}


template< class T >
bool vec2< T >::operator!=(const vec2 & vec) const
{
	return !(x == vec.x && y == vec.y);
}


template< class T >
T & vec2< T >::operator[](int a)
{
	return (a == 0 ? x : y);
}


template< class T >
T vec2< T >::operator[](int a) const
{
	return (a == 0 ? x : y);
}


template< class T >
vec2< T > & vec2< T >::operator+=(const vec2 & vec)
{
	x += vec.x;
	y += vec.y;
	return (*this);
}


template< class T >
vec2< T > operator+(int a, const vec2< T > & vec1)
{
	vec2< T > val(vec1);
	return val += a;
}


template< class T >
vec2< T > & vec2< T >::operator-=(const vec2 & vec)
{
	x -= vec.x;
	y -= vec.y;
	return (*this);
}


template< class T >
vec2< T > & vec2< T >::operator*=(const vec2 & vec)
{
	x *= vec.x;
	y *= vec.y;
	return (*this);
}


template< class T >
vec2< T > & vec2< T >::operator/=(const vec2 & vec)
{
	if (vec.get_y() == 0)
	{
		std::cout << "undefined\n";
		return *this;
	}
	x /= vec.x;
	y /= vec.y;
	return (*this);
}


template< class T >
vec2< T > vec2< T >::operator+(const vec2 & vec) const
{
	return (vec2(*this) += vec);
}


template< class T >
vec2< T > vec2< T >::operator-(const vec2 & vec) const
{
	return (vec2(*this) -= vec);
}


template< class T >
vec2< T > vec2< T >::operator*(const vec2 & vec) const
{
	return (vec2(*this) *= vec);
}

/////
template< class T >
vec2< T > operator-(T a, const vec2< T > & vec1)
{
	vec2< T > val(vec1);
	return val -= a;
}


////
template< class T >
vec2< T > operator*(T a, const vec2< T > & vec1)
{
	vec2< T > val(vec1);
	return val *= a;
}


///
template< class T >
vec2< T > operator/(T a, const vec2< T > & vec1)
{
	vec2< T > val(vec1);
	return val /= a;

}




template< class T >
vec2< T > vec2< T >::operator/(const vec2 & vec) const
{
	return (vec2(*this) /= vec);
}


template< class T >
vec2< T > vec2< T >::operator-() const
{
	return vec2(-x, -y);
}


template< class T >
vec2< T > & vec2< T >::operator+=(T a)
{
	x += a;
	y += a;
	return (*this);
}


template< class T >
vec2< T > & vec2< T >::operator-=(T a)
{
	x -= a;
	y -= a;
	return (*this);
}


template< class T >
vec2< T > & vec2< T >::operator*=(T a)
{
	x *= a;
	y *= a;
	return (*this);
}


template< class T >
vec2< T > & vec2< T >::operator/=(T a)
{
	x /= a;
	y /= a;
	return (*this);
}


template< class T >
vec2< T > & geti_vec2(T a)
{
	return vec2i(a, a);
}


template< class T >
vec2< T > vec2< T >::operator+(T a) const
{
	return (vec2(*this) += a);
}


template< class T >
vec2< T > vec2< T >::operator-(T a) const
{
	return (vec2(*this) -= a);
}


template< class T >
vec2< T > vec2< T >::operator*(T a) const
{
	return (vec2(*this) *= a);
}



template< class T >
vec2< T > vec2< T >::operator/(T a) const
{
	return (vec2(*this) /= a);
}


template< class T >
double len(const vec2< T > & vec)
{
	return sqrt(double(vec.get_x()*vec.get_x()+vec.get_y()*vec.get_y()));
}


template< class T >
T dotprod(const vec2< T > & vec1, const vec2< T > & vec2a)
{
	return (vec1.get_x()*vec2a.get_x()+vec1.get_y()*vec2a.get_y());
}

#endif

