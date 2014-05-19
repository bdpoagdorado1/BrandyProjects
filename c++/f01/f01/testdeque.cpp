// Name: Brandy Poag
// File: testdeque.cpp

#include <iostream> 
#include <exception>
#include "Deque.h"

int main()
{
	try
	{
		Deque< char > y;
		std::cout << y.is_empty() << '\n';
		std::cout << y.size() << '\n';
		std::cout << y << '\n';
		y.insert_head('&');
		std::cout << y.is_empty() << '\n';
		std::cout << y.size() << '\n';
		std::cout << y << '\n';
		y.insert_tail('$');
		std::cout << y.size() << '\n';
		std::cout << y << '\n';
		y.insert_head('*');
		std::cout << y.size() << '\n';
		std::cout << y << '\n';
		Iterator < char > iter1(y);
		while (iter1.has_value())
		{
			std::cout << *iter1; 
			++iter1;
			if (iter1.has_value()) std::cout << ", ";
			else std::cout << '\n';
		}

		Deque< int > d;
		std::cout << d.is_empty() << '\n';
		std::cout << d.size() << '\n';
		std::cout << d << '\n';
		d.insert_head(5);
		std::cout << d.is_empty() << '\n';
		std::cout << d.size() << '\n';
		std::cout << d << '\n';
		d.insert_tail(3);
		std::cout << d.size() << '\n';
		std::cout << d << '\n';
		d.insert_head(6);
		std::cout << d.size() << '\n';
		std::cout << d << '\n';
		d.insert_head(9);
		std::cout << d.size() << '\n';
		std::cout << d << '\n';
		d.insert_tail(4);
		std::cout << d.size() << '\n';
		std::cout << d << '\n';
		int x;
		x = d.remove_head();
		std::cout << d.size() << '\n';
		std::cout << d << '\n';
		std::cout << x << "\n\n";
		x = d.remove_tail();
		std::cout << d.size() << '\n';
		std::cout << d << '\n';
		std::cout << x << "\n\n";
		Deque< int > f;
		f = d;
		std::cout << f.size() << '\n';
		std::cout << f << '\n';
		Deque< int > e = d;
		std::cout << e.size() << '\n';
		std::cout << e << '\n';
		d.remove_head();
		std::cout << d << '\n';
		std::cout << f << '\n';
		std::cout << e << '\n';
		d.remove_tail();
		std::cout << d << '\n';
		bool m = d.remove(6);
		std::cout << d << '\n';
		std::cout << m << '\n';
		m = d.remove(5);
		std::cout << d << '\n';
		std::cout << m << '\n';
		d.insert_head(7);
		d.clear();
		std::cout << d << '\n';
		d.insert_head(5);
		d.insert_head(7);
		d.insert_head(3);
		std::cout << d << '\n';
		m = d.remove(5);
		std::cout << d << '\n';
		std::cout << m << '\n';
		m = d.remove(3);
		std::cout << d << '\n';
		std::cout << m << '\n';
		m = d.remove(7);
		std::cout << d << '\n';
		std::cout << m << '\n';
		/*m = d.remove(5);
		std::cout << d << '\n';
		std::cout << m << '\n';*/
		/*m = d.remove_head();
		std::cout << d << '\n';
		std::cout << m << '\n';*/
		/*m = d.remove_tail();
		std::cout << d << '\n';
		std::cout << m << '\n';*/
		/*while (1)
		{
			d.insert_tail(5);
			//std::cout << "insert 5 to tail " << d << '\n';
		}*/
		/*while (1)
		{
			d.insert_head(4);
			std::cout << "insert 4 to head " << d << '\n';
		}*/
		d.insert_tail(3);
		d.insert_tail(5);
		d.insert_tail(2);
		std::cout << d << '\n';
		Iterator < int > iter(d);
		while (iter.has_value())
		{
			std::cout << *iter; 
			++iter;
			if (iter.has_value()) std::cout << ", ";
			else std::cout << '\n';
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Error ... " << e.what() << "\n";
	}
	return 0;
}
