// Name: Brandy Poag
// File: String.h

#ifndef STRING_H
#define STRING_H

class String
{
public:
	String(const char string_s[])
	{
		int size0 = 0;
		while (string_s[size0] != '\0')
		{
			++size0;
		}
		x = new char [size0];
		string_size = size0;
		capacity = size0;
		helper_check_error(*this);
		for (int i = 0; i < size0; i++)
		{
			x[i] = string_s[i];
		}

	}

	String() : string_size(0), 
		x(new char [1]), capacity(1)
	{
		helper_check_error(*this);
		x[0] = '\0';
	}

	String(char a) : string_size(1), 
		x(new char [1]), capacity(1)
	{
		helper_check_error(*this);
		x[0] = a;
	}
	

	String(const String & a) : string_size(a.size()), 
		x(new char [a.size()]), capacity(a.size())
	{
		helper_check_error(*this);
		helper_copy(a, *this);
	}

	String & operator=(const String & a)
	{
		if (this != & a)
		{
			string_size = a.size();
			resize(string_size);
			helper_copy(a, *this);
		}
		return (*this);
	}
	~String()
	{
		delete [] x;
	}
	int size() const
	{
		return string_size;
	}
	int get_capacity() const
	{
		return capacity;
	}

	char & operator[](int i)
	{
		return x[i];
	}

	char operator[](int i) const
	{
		return x[i];
	}
	friend std::istream & operator>>(std::istream & cin, String & a); 
	
	bool operator==(const String & a) const; 	
	bool operator!=(const String & a) const; 
	bool operator>(const String & a) const; 
	bool operator>=(const String & a) const;
	bool operator<(const String & a) const;
	bool operator<=(const String & a) const;


	String & operator+=(const String & a); 
	String operator+(const String & a) const;

	String & operator+=(char a);
	String & operator+=(const char string_s[]);
	String operator+(char a) const;
	String operator+(const char string_s[]) const;

	String & insert(int ind, const String & a, int size0 = -1); 
	int find(const String & a) const;
	int find(const char string_s[]) const;
	int find(char a) const;
	int rfind(const String & a) const;
	int rfind(char a) const;
	int rfind(const char string_s[]) const;
	String substr(int index, int length = -1) const;
	void resize(const int size0); 
													
private:
	void helper_copy(const String & a, String & b)
	{
		for (int i = 0; i < a.size(); i++)
		{
			b.x[i] = a.x[i];
		}

	}
	void helper_check_error(String & r) 
	{
		if (x == NULL) std::cout << "ERROR: memory allocation returns NULL\n";
		return;
	}
	int string_size;
	char *x;
	int capacity;
};

std::ostream & operator<<(std::ostream &, const String & a);
String operator+(char a, const String & s);
String operator+(const char string_a[], const String & s);

#endif


