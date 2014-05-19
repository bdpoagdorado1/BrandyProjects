#include <iostream>
void swap(int * x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
	return;
}
int main()
{
	int a = 0, b = 1;
	swap(&a, &b);
	std::cout << a << ' ' << b << '\n';

	return 0;
}