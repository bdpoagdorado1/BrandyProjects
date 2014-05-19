#include <iostream>
//include IntPtr p(42); default value of 0 and int ptr to 0
//define operator= so *x = *(b.x)
//make rational accept int and give double and accept double and give rational

class IntDynArr
{
public:
	IntDynArr(int size0 = 0) : size(size0), x(new int [size0]) { }
	IntDynArr(const IntDynArr & a) : size(a.size), x(new int[a.size])
	{
		for (int i = 0; i < a.size; i++)
		{
			x[i] = a.x[i];
		}
	}
	IntDynArr & operator =(const IntDynArr & a)
	{
		if (this != &a)
		{
			size = a.size;
			delete [] x;
			x = new int[size];
			for (int i = 0; i < size; i++)
			{
				x[i] = a.x[i];
				return (*this);
			}
		}
	}
	~IntDynArr()
	{
		delete [] x;
	}
	int get(int index) const
	{
		return x[index];
	}
	void set(int index, int value)
	{
		x[index] = value;
	}
	
private:
	int * x;
	int size;
};

int main()
{
	IntDynArr a(5);
	IntDynArr b(a);
	
	return 0;
}



///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
//include IntPtr p(42); default value of 0 and int ptr to 0
//define operator= so *x = *(b.x)
//make rational accept int and give double and accept double and give rational

class IntPtr
{
public:
	IntPtr(int i = 0) : x(new int)
	{
		*x = i;
		std::cout << "constructor IntPtr...\n";
	}
	IntPtr(const IntPtr & obj)
		: x(new int)
	{
		*x = *(obj.x);
		std::cout << "copy constructor IntPtr...\n"; 
	}
	~IntPtr() 
	{ 
		std::cout << "deconstructor IntPtr...\n"; 
		delete x;
	}
	IntPtr & operator=(const IntPtr & p)
	{
		*x = *(p.x);
		return (*this);
	}
	int get() const
	{
		return *x;
	}
	void set(int i) const
	{
		*x = i;
	}
private:
	int * x;
};

int main()
{
	std::cout << "test" << '\n';
	IntPtr p(42);
	IntPtr q;
	std::cout << p.get() << ' ' << q.get() << '\n';
	q = p;
	std::cout << p.get() << ' ' << q.get() << '\n';
	IntPtr r;
	r = q = p;
	std::cout << p.get() << ' ' << q.get() << ' ' << r.get() << '\n';
	IntPtr m(r);
	std::cout << r.get() << ' ' << m.get() << '\n';

	return 0;
}
*/