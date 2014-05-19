// File: IntDynArr.h
// Name: Brandy Poag

#ifndef INTDYNARRAY_H
#define INTDYNARRAY_H

class IntDynArray
{
public:
	IntDynArray(int size0 = 0) : size(size0), 
		x(new int [size0]), capacity(size0)
	{
		helper_check_error(*this);
		//point x[0] thru x[size0] to -1
		for (int i = 0; i < size0; i++)
		{
			x[i] = -1;
		}

	}
	IntDynArray(int size0, int a[]) : size(size0), 
		x(new int [size0]), capacity(size0)  
	{
		helper_check_error(*this);
		for (int i = 0; i < size0; i++)
		{
			x[i] = a[i];
		}
		
	}
	IntDynArray(const IntDynArray & arr) : size(arr.size), 
		x(new int [arr.size]), capacity(arr.size)
	{
		helper_check_error(*this);
		helper_copy(arr, *this);
	}
	IntDynArray & operator=(const IntDynArray & arr)
	{
		if (this != & arr)
		{
			size = arr.size;
			resize(size);
			helper_copy(arr, *this);
		}
		return (*this);
	}
	~IntDynArray()
	{
		delete [] x;
	}

	int get_size() const
	{
		return size;
	}
	int get_capacity() const
	{
		return size;
	}

	int & operator[](const int i)
	{
		return x[i];
	}
	
	bool operator==(const IntDynArray & arr) const; 
	bool operator!=(const IntDynArray & arr) const; 

	IntDynArray & operator+=(const IntDynArray & a); 
	IntDynArray operator+(const IntDynArray & a) const; 

	IntDynArray & insert(int ind, int val); 
	IntDynArray & remove(int index);
	IntDynArray subarray(int index, int length = -1) const;
	IntDynArray print() const;
	void resize(int size0); 
													
private:
	void helper_copy(const IntDynArray & a, IntDynArray & b)
	{
		for (int i = 0; i < a.size; i++)
		{
			b.x[i] = a.x[i];
		}

	}
	void helper_check_error(IntDynArray & r) 
	{
		if (x == NULL) std::cout << "ERROR: memory allocation returns NULL\n";
		return;
	}
	int size;
	int *x;
	int capacity;
};

std::ostream & operator<<(std::ostream &, IntDynArray & a); 

#endif


