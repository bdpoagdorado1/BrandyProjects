#include <iostream>

int main()
{
	/*double i = 3.14; 
	double & j = i;
	double & k = j;
	std::cout << i << ' ' << j << ' ' << k << '\n';
	i = 2.718;
	std::cout << i << ' ' << j << '\n';
	j = 1.414;
	std::cout << i << ' ' << j << '\n';
	k = -0.693;
	std::cout << i << ' ' << j << ' ' << k << '\n';
	int i = 5;
	int k = 6;
	int & j = i;*/


	char s[100] = "123";
	char t[100] = "12.3";

	int i = strtol(s, NULL, 10);
	double d = strtod(t, NULL);

	std::cout << i << ' ' << d << '\n';
	return 0;
}