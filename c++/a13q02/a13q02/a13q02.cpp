// Name: Brandy Poag
// File: a12q02.cpp

#include <iostream>

void println(int x[], int len)
{
	std::cout << "[ ";
	for (int i = 0; i < len; i++)
	{
		std::cout << x[i] << ' ';
	}
	std::cout << "]" << std::endl;
}

// Check to make sure the position of insertion is a valid 
// position if between 0 and len
bool okInsert(int len, int index, int size)
{
	bool check = false;
	if (index >= 0 && index <= len && len < size) check = true;
	return check;
}

// Moves values to the right of position indicated 
void moveRight(int x[], int len, int index)
{
	for (int i = len; i > index; i--)
	{
		x[i] = x[i - 1];
	}
}

// Inserts newvalue into container x at position index
void insert(int x[], int & len, int size, int index, int newvalue)
{
	// Call okInsert if true, call moveRight, then inset value at 
	// position 
	if (okInsert(len, index, size))
	{
		moveRight(x, len, index);
		x[index] = newvalue;
		++len;
	}

}

// Check to make sure the position of removal is a valid position
// if between 0 and len - 1
bool okRemove(int len, int index, int size)
{
	bool check = false;
	if (index >= 0 && index < len) check = true;
	return check;
}

// Moves values to the left of position indicated
void moveLeft(int x[], int len, int index)
{
	for (int i = index; i < len - 1; i++)
	{
		x[i] = x[i + 1];
	}
}

// Removes the value at position index of the container x
void remove(int x[], int & len, int size, int index)
{
	// Call okRemove if true, call moveLeft move all values at
	// position and to the right move left
	if (okRemove(len, index, size))
	{
		moveLeft(x, len, index);
		--len;
	}
}

int main()
{
	const int SIZE = 5;
	int x[SIZE] = {0};
	int len = 0;
	bool out = false;
	println(x, len);

	while (!out)
	{
		int option = 0;
		std::cout << "option (0-quit, 1-insert, 2-remove): ";
		std::cin >> option;
		// Break the while loop if option is 0.
		if (option == 0)
		{
			out = true;
		}
		else
		{
			int newValue = 0;

			// Prompt for index
			int index = 0;
			std::cout << "index: ";
			std::cin >> index;

			switch (option)
			{
			case 1: // Prompt for new value and call the insert
					std::cout << "value: ";
					std::cin >> newValue;

					insert(x, len, SIZE, index, newValue);
					break;

			case 2: // Call the remove() function.
					remove(x, len, SIZE, index);
					break;
			}

			std::cout << std::endl;
			println(x, len);
		}
	}

	return 0;
}