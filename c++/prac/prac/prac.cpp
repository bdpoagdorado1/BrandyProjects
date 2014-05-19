// Name: Brandy Poag
// File: a13q04.cpp

#include <iostream>

void printHello(char s[] = "world")
{
	std::cout << "hello " << s << '\n';
}

int main()
{
	printHello();
	printHello("columbia");

	return 0;
}
