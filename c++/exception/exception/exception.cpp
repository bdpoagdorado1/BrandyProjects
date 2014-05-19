#include <iostream>
#include <exception>

/*void f()
{
	std::cout << "f ... 1\n";
	throw std::exception("exception message");
	std::cout << "f ... 2\n";
}

int main()
{
	try
	{
		std::cout << "try ... 1\n";
		f();
		std::cout << "try ... 2\n";
	}
	catch (std::exception & e)
	{
		std::cout << "caught ... " << e.what() << "\n";
	}
	std::cout << "end\n";
	return 0;
}*/
/*
void f()
{
	std::cout << "f ... 1\n";
	throw std::exception();
	std::cout << "f ... 2\n";
}

void g()
{
	try
	{
		std::cout << "g ... 1\n";
		f();
		std::cout << "g ... 2\n";
	}
	catch (std::exception & e)
	{
		std::cout << "g ... caught\n";
		throw;
	}
}

int main()
{
	try
	{
		std::cout << "main ... 1\n";
		g();
		std::cout << "main ... 2\n";
	}
	catch (std::exception & e)
	{
		std::cout << "main ... caught\n";
	}
	std::cout << "end\n";
	return 0;
}*/

/*class MyException
{
};

void f()
{
	throw MyException();
}

int main()
{
	try 
	{
		f();
	}
	catch (MyException & e)
	{
		std::cout << "caught a myexception obj\n";
	}
}*/
/*class stackException
{ };// int err_code or two classes 1 stack_overflow { }; and 2 stack_underflow { };

class Stack
{
public:
	void push(int i)
	{
		if (size == 5) throw StackException();
	}
	int pop()
	{
		if (size ++ 0) throw StackException();
	}
};
int main()
{
	srand((unsigned) time(NULL));
	Stack stack;
	
	try 
	{
		while (1)
		{
			int option;
			std::cin >> option;
			switch (option)
			{
			case 0: stack.push(rand()); break;
			case 1: stack.pop(); break;
			}
			std::cout << stack << '\n';
		}
	}
	catch (StackException e)////have two catches one for each class under/over flow
	{
		std::cout << "stack error/n";
	}
}*/



/*class MyException
{
public:
	MyException(int err_code0) : err_code(err_code0) { }
	int err_code;
};
class MyException2
{ };
void f()
{
	//throw MyException(5);
	//throw MyException2();
	throw 42;
}
int main()
{
	try
	{
		f();
	}
	catch (MyException e)
	{
		std::cout << "caught a MyException obj. "
			<< "error code " << e.err_code << "\n";
	}

	catch (MyException2 e)
	{
		std::cout << "caught a MyException2 obj. \n";
	}
	catch (int i)
	{
		std::cout << "caught an int " << i << "\n";
	}
	return 0;
}
*/
/*
//problem
void f()
{
	std::cout << "f ... 1\n";
	throw 42;
	std::cout << "f ... 2\n";
}
int main()
{
	try
	{
		std::cout << "try ... 1\n";
		f();
		std::cout << "try ... 2\n";
	}
	catch (exception & e)
	{
		std::cout << "caught\n";
	}
	return 0;
}*/

int main()
{
	try
	{
		while (1)
		{
			int * p = new int [1000000];
			std::cout << "ok\n";
		}
	}
	catch (std::bad_alloc & e)
	{
		std::cout << "bad!!\n";
	}
	return 0;
}