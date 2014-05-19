#include <iostream>


int main()
{
	int * x = new int;
	int * y = new int;
	*y = 1;
	std::cin >> *x;
	*x = *x + *y;
	std::cout << *x << ' ' << *y << '\n';
	return 0;
}