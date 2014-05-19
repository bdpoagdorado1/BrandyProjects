#include <iostream>
//------------------------------------------------------------------------
// SimpleClass
//------------------------------------------------------------------------
class SimpleClass
{
public:
	SimpleClass(int i0) : i(i0) {}
	void set(int);
	int get();
private:
	int i;
};

void SimpleClass::set(int i0)
{
	i = i0;
}

int SimpleClass::get()
{
	return i;
}
//------------------------------------------------------------------------
// Test SimpleClass
//------------------------------------------------------------------------
int main()
{	
	SimpleClass x(42);
	std::cout << "x has value " << x.get() << std::endl;
	return 0;
}
