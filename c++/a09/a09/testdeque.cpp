//Name: Brandy Poag
//File: testdeque.cpp

#include <iostream>
#include "Deque.h"
#include <exception>

int main()
{
	try
	{
		Deque< int > que;
		std::cout << que << '\n';
		que.insert_tail(5);
		std::cout << "insert 5 to tail " << que << '\n';
		que.insert_head(4);
		std::cout << "insert 4 to head " << que << '\n';
		que.insert_tail(3);
		std::cout << "insert 3 to tail " << que << '\n';
		que.insert_head(2);
		std::cout << "insert 2 to head " << que << '\n';
		que.insert_tail(7);
		std::cout << "insert 7 to tail " << que << '\n';
		que.insert_head(8);
		std::cout << "insert 8 to head " << que << '\n';
		que.insert_tail(9);
		std::cout << "insert 9 to tail " << que << '\n';
		int a = que.remove_head();
		std::cout << "removed " << a << '\n';
		std::cout << que << '\n';
		int b = que.remove_tail();
		std::cout << "removed " << b << '\n';
		std::cout << que << '\n';
		int a1 = que.remove_head();
		std::cout << "removed " << a1 << '\n';
		std::cout << que << '\n';
		int b1 = que.remove_tail();
		std::cout << "removed " << b1 << '\n';
		std::cout << que << '\n';
		int a2 = que.remove_head();
		std::cout << "removed " << a2 << '\n';
		std::cout << que << '\n';
		int b2 = que.remove_tail();
		std::cout << "removed " << b2 << '\n';
		std::cout << que << '\n';
		int a3 = que.remove_head();
		std::cout << "removed " << a3 << '\n';
		std::cout << que << '\n';
		int b3 = que.remove_tail();
		std::cout << "removed " << b3 << '\n';
		std::cout << que << '\n';
		int a4 = que.remove_head();
		std::cout << "removed " << a4 << '\n';
		std::cout << que << '\n';
		/*while (1)
		{
			que.insert_tail(5);
			std::cout << "insert 5 to tail " << que << '\n';
		}
		while (1)
		{
			que.insert_head(4);
			std::cout << "insert 4 to head " << que << '\n';
		}*/
	}
	catch (std::exception & e)
	{
		std::cout << "Error ... " << e.what() << "\n";
	}
	return 0;
}