// Name: Brandy Poag
// File: revision othello.cpp

#include <iostream>
#include <cstring>
#include "othelloheader.h"

const int SIZE_ROW = 8, SIZE_COL = 8;
const int BLACK = 0;
const int WHITE = 1;
const char BLACK_PIECE = '@';
const char WHITE_PIECE = 'o';

typedef char Board[SIZE_ROW][SIZE_COL];

int main()
{
	bool prompt = true;
	while (prompt)
	{
		std::cout << "Welcome to Super Othello Version 0.1\n"
			<< " by Brandy Poag\n"
			<< " [?] Help\n"
			<< " [P/p] Play a new game (FIRST setup the board or load a previous game!)\n"
			<< " [L/l] Load a previous game\n"
			<< " [S/s] Setup the board\n"
			<< " [Q/q] Quit\n"
			<< " Enter option: ";
		char option = ' ';
		std::cin >> option;

		switch (option)
		{
		case '?': help();
					break;
		/*case 'P': 
		case 'p': play();
					break;*/
		case 'L': 
		case 'l': load();
					break;
		case 'S': 
		case 's': setup();
					break;
		case 'Q': 
		case 'q': std::cout << "\nThanks for playing Super Othello Version 0.1\n";
					prompt = false;
					break;

		}
	}
	return 0;
}