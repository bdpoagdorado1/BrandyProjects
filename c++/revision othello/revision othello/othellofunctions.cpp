// Name: Brandy Poag
// File: othellofunctions.cpp

#include <iostream>
#include <cstring>
#include "othelloheader.h"

const int SIZE_ROW = 8, SIZE_COL = 8;
const int BLACK = 0;
const int WHITE = 1;
const char BLACK_PIECE = '@';
const char WHITE_PIECE = 'o';

void help()
{
	std::cout << '\n'
		<< "The official rules can be found at\n"
		<< "http://en.wikipedia.org/wiki/Reversi\n\n"
		<< "The Othello board is set up is the following " 
		<< "manner\n\n"
		<< "  A B C D E F G H\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "1| | | | | | | | |1\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "2| | | | | | | | |2\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "3| | | | | | | | |3\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "4| | | |o|@| | | |4\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "5| | | |@|o| | | |5\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "6| | | | | | | | |6\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "7| | | | | | | | |7\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "8| | | | | | | | |8\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "  A B C D E F G H\n\n"
		<< "BLACK plays X and WHITE plays O. Players take "
		<< "turn in entering\n"
		<< "moves. The first player to enter a move is BLACK. "
		<< "To place an X\n"
		<< "at row 6 and column E, BLACK enters E6. The result "
		<< "of the move\n\n"
		<< "  A B C D E F G H\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "1| | | | | | | | |1\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "2| | | | | | | | |2\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "3| | | | | | | | |3\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "4| | | |o|@| | | |4\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "5| | | |@|@| | | |5\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "6| | | | |@| | | |6\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "7| | | | | | | | |7\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "8| | | | | | | | |8\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "  A B C D E F G H\n\n"
		<< "The WHITE piece at E5 is now a BLACK piece.\n\n";
	return;
}


void load()
{
	return;
}


void setup(play game)
{
	char option;
	while (1)
	{
		std::cout << "If you would like to create your own board\n"
			<< "enter Y/y\n"
			<< "OR enter N/n\n"
			<< "to use a standard board: ";
		std::cin << option;
		if (option == 'n' || option == 'N')
		{
			init(game);
			draw(game);
			return;
		}
		if (option == 'y' || option == 'Y') break;
	}

	bool out = false;
	while (!out)
	{
		char color, column, row;
		std::cout << "Please enter positions of players. Specify color, column, and row.\n"
			<< "Color of player B/b for black and W/w for white\n"
			<< "column A, B, C, D, E, F, G, or H\n"
			<< "row 1, 2, 3, 4, 5, 6, 7, or 8\n"
			<< "To stop entering positions enter Q/q\n";
		std::cout << "color: ";
		std::cin >> color;
		if (color == 'q' || color == 'Q')
		{
			out = true;
			break;
		}
		else if (color == 'b' || color == 'B')
		{
			std::cout << "column: ";
			std::cin >> column;
			if (column == 'q' || column == 'Q')
			{
				out = true;
				break;
			}
			std::cout << "row: ";
			std::cin >> row;
			if (row == 'q' || column == 'Q')
			{
				out = true;
				break;
			}
			b[row][column] = '@';
		}
		else if (color == 'w' || color == 'W')
		{
			std::cout << "column: ";
			std::cin >> column;
			if (column == 'q' || column == 'Q')
			{
				out = true;
				break;
			}
			std::cout << "row: ";
			std::cin >> row;
			if (row == 'q' || column == 'Q')
			{
				out = true;
				break;
			}
			b[row][column] = 'o';
		}
	}
	draw(game);

	return;
} 

void init(play game)
{
	int half_row = SIZE_ROW / 2, half_col = SIZE_COL / 2;

	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			if ((i == half_row - 1 && j == half_col - 1)|| (i == half_row && j == half_col)) play[i][j] = 'o';
			else if ((i == half_row- 1 && j == half_col)|| (i == half_row && j == half_col - 1)) b[i][j] = '@';
			else b[i][j] = ' ';
		}
	}
	std::cout << '\n';
}


void draw(Board b)
{
	std::cout << "  A B C D E F G H\n";
	for (int i = 0; i < SIZE_ROW; i++)
	{
		std::cout << " +";
		for (int j = 0; j < SIZE_COL; j++)
		{
			std::cout << '-' << '+';
		}
		std::cout << '\n';
		std::cout << i + 1 << '|';
		for (int j = 0; j < SIZE_COL; j++)
		{
			std::cout << b[i][j] << '|';
		}
		std::cout << i + 1 << '\n';
	}
	std::cout << " +";
	for (int j = 0; j < SIZE_COL; j++)
	{
		std::cout << '-' << '+';
	}
	std::cout << '\n';
	std::cout << "  A B C D E F G H\n";
	std::cout << '\n';
}