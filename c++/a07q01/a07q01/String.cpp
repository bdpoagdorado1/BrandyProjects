// Name: Brandy Poag
// File: String.cpp

#include <iostream>
#include "String.h"


std::ostream & operator<<(std::ostream & out, const String & a)
{
	for (int i = 0; i < a.size(); i++)
	{
		out << a[i];
	}
	return out;
}

std::istream & operator>>(std::istream & cin, String & a)
{
	char arr[1000];
	cin >> arr;
	String copy(arr); 
	a = copy;
	return cin;
}


bool String::operator==(const String & a) const
{ 
	if(a.size() == size())
	{
		for (int i = 0; i < size(); i++)
		{
			if (x[i] != a.x[i]) return false;
		}
		return true;
	}
	return false;
}


bool String::operator!=(const String & a) const
{
	return !(*this == a);
}


bool String::operator>(const String & a) const
{
	for (int i = 0; i < size() && i < a.size(); i++)
	{
		if (x[i] > a.x[i]) return true;
		if (x[i] < a.x[i]) return false;
	}

	return (a.size() < size());
}


bool String::operator>=(const String & a) const
{
	return (*this > a || *this == a);
}


bool String::operator<(const String & a) const
{
	return !(*this >= a);
}


bool String::operator<=(const String & a) const
{
	return !(*this > a);
}


String & String::operator+=(const String & a)
{
	int start = size();
	resize(a.size() + size());
	int j = 0;
	for (int i = start; i < size(); ++i)
	{
		x[i] = a[j];
		++j;
	}
	return (*this);
}


String String::operator+(const String & a) const
{
	String b = *this;
	return b += a;
}


String & String::operator+=(char a)
{
	return (*this += String(a));
}


String & String::operator+=(const char string_s[])
{
	return (*this += String(string_s));
}


String String::operator+(char a) const
{
	String copy(*this);
	return (copy += String(a));
}


String String::operator+(const char string_s[]) const
{
	String copy(*this);
	return (copy += String(string_s));
}


String operator+(char a, const String & s)
{
	return (String(a) += s);
}


String operator+(const char string_a[], const String & s)
{
	return (String(string_a) += s);
}


String & String::insert(int ind, const String & a, int size0)
{
	if (ind > size()) ind = size();
	String temp(a);
	String hold(*this);
	if (size0 == -1) size0 = a.size();
	else temp.resize(size0);
	resize(size0 + hold.size());
	int i;
	int j = 0;
	for (i = ind; i < size0 + ind; ++i)
	{
		x[i] = temp[j];
		++j;
	}
	int k = ind;
	for (; i < size(); ++i)
	{
		x[i] = hold[k];
		++k;
	}
	return *this;
}


String String::substr(int index, int length) const
{
	String temp;
	int size0 = (length == -1 || length > size() ? size() - index : length);
	temp.resize(size0);
	for (int i = index, j = 0; i < size0 + index; ++i, ++j)
	{
		temp[j] = x[i];
	}
	return temp;
}


int String::find(const String & a) const
{
	int index = -1;
	int j = 0;
	bool found = false;
	for (int i = 0; (i < size() && !found); ++i)
	{
		if (x[i] == a[0])
		{
			for (int j = i, k = 0; (j < i + a.size() || j < size()); ++j, ++k)
			{
				if (x[j] == a[k] && k == a.size() - 1)
				{
					index = i;
					found = true;
				}
			}
		}
	}
	return index;
}


int String::find(const char string_s[]) const
{
	return find(String(string_s));

}


int String::find(char a) const
{
	return find(String(a));
}


int String::rfind(const String & a) const
{
	int index = -1;
	int j = 0;
	bool found = false;
	for (int i = size(); (i > 0 && !found); --i)
	{
		if (x[i - 1] == a[a.size() - 1])
		{
			for (int j = i - 1, k = a.size() - 1; (j > i - a.size() || j > 0); --j, --k)
			{
				if (x[j] == a[k] && k == 0)
				{
					index = j;
					found = true;
				}
			}
		}
	}
	return index;
}


int String::rfind(const char string_s[]) const
{
	return rfind(String(string_s));

}


int String::rfind(char a) const
{
	return rfind(String(a));
}


void String::resize(const int size0)
{
	if (size0 < 0) return;
	if (size0 > capacity || size0 < capacity / 3)
	{
		char *temp = new char[size0 * 2];
		for (int i = 0; i < size0; i++)
		{
			temp[i] = x[i];
		}
		delete [] x;
		x = temp;
		string_size = size0;
		capacity = size0 * 2;
		helper_check_error(*this);
	}
	string_size = size0;
}


