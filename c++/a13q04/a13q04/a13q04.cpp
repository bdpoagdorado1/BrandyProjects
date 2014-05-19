// Name: Brandy Poag
// File: a13q04.cpp

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

const int SIZE = 1024;
const int PLUS = 0;
const int MINUS = 1;
const int MULT = 2;
const int DIV = 3;

double plus(double x, double y)
{
	return x + y;
}

double max_value(double x, double y)
{
	double max = x;
	if (max < y) max = y;
	return max;
}

double min_value(double x, double y)
{
	double min = x;
	if (min > y) min = y;
	return min;
}

double minus(double x, double y)
{
	double max = max_value(x, y);
	double min = min_value(x, y);
	return (max - min);
}
double mult(double x, double y)
{
	return x * y;
}
double divn(double x, double y)
{
	return ((double)x) / y;
}

double get_op(char input[], int & j)
{
	++j;
	for (int i = j; i < SIZE; i++)
	{
		if (input[i] == ' ') continue;
		if (input[i] == '+')
		{
			j = i + 1;
			return PLUS;
		}
		else if (input[i] == '-')
		{
			j = i + 1;
			return MINUS;
		}
		else if (input[i] == '*')
		{
			j = i + 1;
			return MULT;
		}
		else if (input[i] == '/')
		{
			j = i + 1;
			return DIV;
		}
	}
	return -1;
}

double evaluates(double x, int op, double y)
{
	if (op == 0) return plus(x, y);
	if (op == 1) return minus(x, y);
	if (op == 2) return mult(x, y);
	if (op == 3) return divn(x, y);
}

double get_value_of_array(char memory[])
{
	double sum = strtol(memory, NULL, 10);
	return sum;
}

double record_num_index(bool go, char input[], int j)
{
	char memory[SIZE] = {0};
	bool out = false;
	int m = 0;
	if (input[j] == '%') ++j;
	while (!out)
	{
	
		// if valid input record
		if (input[j] >= '0' && input[j] <= '9' || input[j] == '-')
		{
			memory[m] = input[j];
			++j;
			++m;
		}
		else if (input[j] == '\0')
		{
			go = false;
			out = true;
		}
		else if (input[j] == ' ' || input[j] == '=')
		{
			go = true;
			out = true;	
		}
		else
		{
			out = true;
		}
	}
	
	return get_value_of_array(memory);
}

double get_value(bool & go, char input[], int & j, int last[])
{
	double x = 0;
	// check to record
	for (int k = j; j < SIZE; k++)
	{
		if (input[k] == ' ')
		{
			continue;
		}
		// if valid data
		if (input[k] >= '0' && input[k] <= '9' || input[k] == '-' 
			|| input[k] == '%')
		{
			// if first value is memory data retreive it
			if (input[k] == '%')
			{
				++k;
				j = k;
				int n = record_num_index(go, input, j);
				x = last[n];
				go = true;
			}
			// else get first value and stor in x
			else
			{
				j = k;
				x = record_num_index(go, input, j);
				go = true;
			}
		}
		return x;
	}
}

int store_memory(int & j, double & x, int last[], char input[], bool go)
{
	j = 0;
	int index = record_num_index(go, input, j);
	return index;
}

bool scan_for_equal(int & start, char input[], bool found)
{
	int count = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		if (input[i] == '=')
		{
			++count;
			start = i + 1;
			found = true;
		}
	}
	return found;
}

// Print prompt and get a string from user
void get_input(int last[], char input[], int & stop)
{
	// get user input
	std::cout << ">>> ";
	std::cin.getline(input, SIZE);
	
	// if input is q stop = 0 then return
	if (input[0] == 'q')
	{
		stop = 0;
		return;
	}

	// if not quit go in loop for input
	double x = 0, y = 0;
	while (1)
	{
		bool found = false, go = false;
		int j = 0, start = 0, index = 0;

		found = scan_for_equal(start, input, found);
		
		if (found)
		{
			j = 1;
			index = store_memory(j, x, last, input, go);
			j = start;
		}
		if(input[j] == ' ' || input[j] == '-' || input[j] == '%' 
			||input[j] >= '0' && input[j] <= '9')
		{
			x = get_value(go, input, j, last);

			last[index] = x;
		}
		if (go)
		{
			// get operator
			double op = get_op(input, j);
			if (op == -1)
			{
				if (found)
				{
					last[index] = x;
					std::cout << "%" << index << '\n';
				}
				std::cout << x << '\n';
				break;
			}
			y = get_value(go, input, j, last);
			x = evaluates(x, op, y);
		}
		if (found)
		{
			last[index] = x;
			std::cout << "%" << index << '\n';
		}
		std::cout << int(x) << '\n';
		return;
	}
	return;
}

int main()
{
	int stop = 1;
	int index = 0;
	int increase = 0;
	int last[SIZE] = {0};
	// go to promt for data
	while (stop)
	{
		char input[SIZE] = "";
		get_input(last, input, stop);
	}

	return 0;
}
