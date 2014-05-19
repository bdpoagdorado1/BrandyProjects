// Brandy Poag
// File: checkers.cpp

#include "checker.h"

Game playit;

int main()
{
	srand((unsigned int) time(0));
	
	bool prompt = true;
	while (prompt)
	{
		std::cout << "Welcome to Checkers\n"
			<< " by Brandy Poag\n"
			<< " [?] Help\n"
			<< " [P/p] Play a new game\n"
			<< " [Q/q] Quit\n"
			<< " Enter option: ";
		char option = ' ';
		std::cin >> option;

		switch (option)
		{
		case '?': help();
					break;
		case 'P': 
		case 'p': init(playit);
					break;
		case 'Q': 
		case 'q': std::cout << "\nThanks for playing Checkers!\n";
					prompt = false;
					break;
		
		}
	}
	
	return 0;
}
