#include <iostream>
#include "fib3.h"
#include "Math.h"
int main()
{
	int n1 = 0, n2 = 1, n3 = 0;
	std::cout << "Testing Fib: \n";
	int i;
	int errors = 0;
	for (i = 0; i < 10; ++i)
	{
		if ( i == 0 ) n3 = 1;
		std::cout << "Test " << i + 1 << ": " << (Math::fib(i) == n3 ? "pass" : "FAIL" ) << '\n';
		if (Math::fib(i) != n3) ++errors;
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	std::cout << "Number of errors: " << errors << '\n';
	std::cout << "Total number of test: " << i << '\n'; 
	return 0;
}