#include "date.h"
#include <iostream>

void Date::init (int m0, int d0, int y0)
{
	m = m0;
	d = d0;
	y = y0;
	return;
}

void Date::print ()
{
	std::cout <<  m << '/' << d << '/' << y << '\n';
	return;
}

void Date::add_y (int inc)
{
	y += inc;
	return;
}

void Date::add_m (int inc)
{
	m += inc;
	return;
}

void Date::add_d (int inc)
{
	d += inc;
	return;
}
