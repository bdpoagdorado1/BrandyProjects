// Name: Brandy Poag
// File: final.cpp

#include <iostream>
#include <ctime>
#include <cmath>

const int MAX_SIZE = 100;

void init(char world[100][100], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            world[row][col] = ' ';
        }
    }
}

void put_gold(char world[MAX_SIZE][MAX_SIZE], int size, int n)
{
	int count = 0;
	while (1)
	{
		int x = rand() % size;
		int y = rand() % size;
		if (x != 0 && y != 0)
		{
			++count;
			world[x][y] = 'G';
		}
		if (count > 5) break;
	}
	return;
}

void draw(char world[MAX_SIZE][MAX_SIZE], int size)
{
    std::cout << '+';
    for (int i = 0; i < size; i++)
        std::cout << '-';
    std::cout << "+\n";
    for (int row = 0; row < size; row++)
    {
        std::cout << '|';
        for (int col = 0; col < size; col++)
        {
            std::cout << world[row][col];
        }
        std::cout << "|\n";
    }
        std::cout << '+';
    for (int i = 0; i < size; i++)
        std::cout << '-';
    std::cout << "+\n";
}


void move(int size, int & row, int & col)
{
    switch (rand() % 4)
    {
        case 0:// move S
            row++;
            if (row == size) row = size - 1;
            break;
            
        case 1:
            // move N
            row--;
            if (row < 0) row = 0;
            break;
            
        case 2:
            // move E
            col++;
            if (col == size) col = size - 1;
            break;
            
        case 3:
            // move W
            col--;
            if (col < 0) col = 0;
            break;
    }
}

int main()
{
    srand(time(NULL));
    
    char world[MAX_SIZE][MAX_SIZE];

    while (1)
    {
        int size;
        std::cout << "size of the world: ";
        std::cin >> size;
        init(world, size);
        
        int num_steps;
        std::cout << "number of steps: ";
        std::cin >> num_steps;

        int n;
        std::cout << "number of gold pieces: ";
        std::cin >> n;
        
        put_gold(world, size, n);
        
        int robot_row = 0, robot_col = 0; // row and column of robot
        world[robot_row][robot_col] = 'R';
        
        int score = 0, count = 0;
        for (int step = 1; step <= num_steps; step++)
        {
            draw(world, size);
            std::cout << "step #" << step << '\n';
			score = count;
            std::cout << "score:" << score << '\n';
            std::cout << std::endl;
			if (score == n) break;

            world[robot_row][robot_col] = ' ';
            move(size, robot_row, robot_col);
			if (world[robot_row][robot_col] == 'G')
			{
				count++;
			}
            world[robot_row][robot_col] = 'R';
        }
    }
    return 0;
}
