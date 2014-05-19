#include <iostream>

int main()
{
	int index = 1, i = 2, j = 1, n = 0;
	bool out = false;
	const int SIZE = 1000;
	std::cin >> n;

	if (n == 1)
	{
		index = 0;
		out = true;
	}

	while (!out /*&& n <= SIZE*/)
	{
		index = j;

		if (i >= n) out = true;

		if (j + 2 > i)
		{
			j = 1;
		}
		else
		{
			j += 2;
		}

		i++;
	}

	std::cout << index << '\n';

	return 0;
}