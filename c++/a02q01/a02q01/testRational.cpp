// Author: Brandy Poag
// Date : 09/16/09
// File : testRational.cpp

#include <iostream>
#include "Rational.h"

int main()
{
	Rational r(1, -2);
	std::cout << "Testing Rational ...\n";

	std::cout << "You should see -1/2 ... " << r << std::endl;
	r.set_n(-1);
	r.set_d(-2);
	std::cout << "You should see 1/2 ... " << r << std::endl;
	r.set_n(3);
	r.set_d(1);
	std::cout << "You should see 3 ... " << r << std::endl;
	r.set_n(3);
	r.set_d(-1);
	std::cout << "You should see -3 ... " << r << std::endl;
	r.set_n(35);
	r.set_d(5);
	r.reduce();
	std::cout << "You should see 7 ... " << r << std::endl;

	Rational x(1, 2);

	std::cout << "You should see 15/2 ... " 
		<< r.operator +(x) << std::endl;
	std::cout << "You should see 13/2 ... " 
		<< r.operator -(x) << std::endl;
	std::cout << "You should see 7/2 ... " 
		<< r.operator *(x) << std::endl;
	std::cout << "You should see 14 ... " 
		<< r.operator /(x) << std::endl;
	std::cout << "You should see 1 ... " 
		<< x.operator *(x) << std::endl;
	std::cout << "You should see 1 ... " 
		<< r.operator !=(x) << std::endl;
	std::cout << "You should see 0 ... " 
		<< r.operator ==(x) << std::endl;

	Rational m(5, 2);
	Rational l = m.operator +(x);

	l.reduce();
	std::cout << "You should see 3 ... " << l << std::endl;
	std::cout << "You should see 12/4 ... " 
		<< m.operator +(x) << std::endl;
	std::cout << "You should see 8/4 ... " 
		<< m.operator -(x) << std::endl;
	std::cout << "You should see 0 ... " 
		<< m.operator <(x) << std::endl;
	std::cout << "You should see 0 ... "
		<< m.operator <=(x) << std::endl;
	std::cout << "You should see 1 ... " 
		<< m.operator >(x) << std::endl;
	std::cout << "You should see 1 ... " 
		<< m.operator >=(x) << std::endl;
	std::cout << "You should see 0 ... " 
		<< m.operator ==(x) << std::endl;
	std::cout << "You should see 1 ... " 
		<< l.operator ==(m.operator +(x)) << std::endl;
	return 0;
}
