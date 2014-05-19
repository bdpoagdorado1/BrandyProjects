#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;


const int SIZE_ROW = 8, SIZE_COL = 8;
const char BLACK_PIECE = '@';
const char WHITE_PIECE = 'o';

std::fstream binaryio;

struct Game
{
	bool move;
	char board[SIZE_ROW][SIZE_COL];
	int row;
	int col;
	char piece;
	bool here;
};

Game playit;
void help();
void play(Game &p);
void setup(Game &p);
int convert_col();
int convert_row();
bool poss_move(Game &p);
bool move_made(Game &p);
void clear_board(Game &p);
void init(Game &p);
void draw(Game &p);
bool poss_move(Game &p);
void game_over(Game &p);
void save(Game &p);
void load(Game &p);
void switch_player(Game &p);
bool north (Game &p);
bool south (Game &p);
bool east (Game &p);
bool west (Game &p);
bool northeast (Game &p);
bool northwest (Game &p);
bool southeast (Game &p);
bool southwest (Game &p);

int main()
{	
	clear_board(playit);
	bool prompt = true;
	while (prompt)
	{
		std::cout << "Welcome to Super Othello Version 0.1\n"
			<< " by Brandy Poag\n"
			<< " [?] Help\n"
			<< " [P/p] Play a new game\n"
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
		case 'P': 
		case 'p': init(playit);
					break;
		case 'L': 
		case 'l': load(playit);
					break;
		case 'S': 
		case 's': setup(playit);
					break;
		case 'Q': 
		case 'q': std::cout << "\nThanks for playing Super Othello Version 0.1\n";
					prompt = false;
					break;
		
		}
	}
	return 0;
	
}

void help()
{
	std::cout << "The official rules can be found at\n"
		<< "http://en.wikipedia.org/wiki/Reversi\n\n"
		<< " The Othello board is set up in the following" 
		<< " manner\n\n"
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
		<< "BLACK plays @ and WHITE plays O. Players take "
		<< "turn in entering\n"
		<< "moves. The first player to enter a move is BLACK. "
		<< "To place an @\n"
		<< "at row 6 and column E, BLACK enters 6 then an E. The result "
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


void init(Game &p)
{
	int half_row = SIZE_ROW / 2, half_col = SIZE_COL / 2;

	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			if ((i == half_row - 1 && j == half_col - 1)|| (i == half_row && j == half_col)) p.board[i][j] = WHITE_PIECE;
			else if ((i == half_row- 1 && j == half_col)|| (i == half_row && j == half_col - 1)) p.board[i][j] = BLACK_PIECE;
			else p.board[i][j] = ' ';
		}
	}
	draw(p);
	
	p.piece = BLACK_PIECE;
	play(p);

	return;
}


void draw(Game &p)
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
			std::cout << p.board[i][j] << '|';
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

	return;
}


void setup(Game &p)
{
	std::cin.ignore();
	char clr, setchar;
	int letter_num, digit;
	bool set = true;
	
	while (set)
	{
		
		std::cout << "Enter [Q/q] to return to the menu.\n"
			<< "To manually setup the board enter the color of the\n"
			<< "player [B/b] for black and [W/w] for white: \n";
		std::cin >> clr;
		std::cin.ignore();
		if (clr == 'q' || clr == 'Q') return;

		if (clr == 'b'|| clr == 'B')
		{
			digit = convert_row();
			letter_num = convert_col();
			p.board[digit][letter_num] = BLACK_PIECE;
			
		}
		else if (clr == 'w' || clr == 'W')
		{
			digit = convert_row();
			letter_num = convert_col();
			p.board[digit][letter_num] = WHITE_PIECE;
		}	
		else
		{
			std::cout << "Invalid entry\n";
		}

		std::cout << "If you would like to begin playing the game"
			<< " press [Y/y]\nor to continue setting up the board"
			<< " press [N/n]\nor to quit press [Q/q]: ";

		std::cin >> setchar;
		std::cin.ignore();
		if (setchar == 'Y' || setchar == 'y')
		{
			set = false;
			draw(p);
	
			p.piece = BLACK_PIECE;
			
			std::cout << "Please enter the player that goes first\n"
				<< "black [@] or white [o]: ";
			std::cin >> p.piece;
			
			play(p);
		}
		else if (setchar == 'N' || setchar == 'n')
		{
			continue;
		}
		else if (setchar == 'Q' || setchar == 'q')
		{
			return;
		}
		else std::cout << "Invalid entry\n";

	}
	return;
}

bool poss_move(Game &p)
{
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			p.col = j;
			p.row = i;
			p.here = false;
			p.move = false;
			if (move_made(p))
			{
				return true;
			}
		}
	}
	return false;
}
void clear_board(Game &p)
{
	for (int i = 0; i < SIZE_ROW; i++)//number
	{
		for (int j = 0; j < SIZE_COL; j++)//letter
		{
			p.board[j][i] = ' ';
		}
	}
}
int convert_row()
{
	char x;
	while (1)
	{
		std::cout << "Enter a row [1-8] or enter 9 to quit: ";
		std::cin >> x;
		std::cin.ignore();
		if (x >= 49 && x <= 56)return x - 49;
		else if (x == '9') return 9;
		else std::cout << "This is not a valid entry!\n";
	}
}

int convert_col()
{
	char x;
	while (1)
	{
		std::cout << "Enter a col [A/a - H/h]: ";
		std::cin >> x;
		std::cin.ignore();
		if ((x >= 65 && x <= 73)||(x >= 97 && x <= 105)) return (tolower(x) - 97);
		else std::cout << "This is not a valid entry!\n";
	}
}


void play(Game &p)
{
	std::cin.ignore();
	int count = 0;

	while (1)
	{
		if (poss_move(p))
		{
			if (p.piece == BLACK_PIECE)
			{
				std::cout << "Black's turn ";
			}
			else
			{
				std::cout << "White's turn ";
			}
			p.here = true;
			p.row = convert_row();
			if (p.row == 9)
			{
				count = 10;
				break;
			}
			p.col = convert_col();
			if (move_made(p))
			{
				draw(p);
				count = 0;
				switch_player(p);
				p.here = false;
				p.move = false;
			}
			else
			{
				std::cout << "Invalid Play!\n";
			}
		}
		else
		{
			switch_player(p);
			count++;
		}
		
		if(count >= 2)
		{
			game_over(p);
			clear_board(p);
			return;
		}
	}
		if(count >= 10)
		{
			std::cout << "To save this game enter [Y/y] else enter [N/n]: ";
			char option2;
			std::cin >> option2;
			if ('y' == tolower(option2))
			{
				save(p);
				clear_board(p);
				return;
			}
			else return;
		}
	
	return;
}

void game_over(Game &p)
{
	int countb = 0, countw = 0;
	for (int startr = 0; startr < SIZE_ROW; startr++)
	{
		for (int startc = 0; startc < SIZE_COL; startc++)
		{
			if (p.board[startr][startc] == '@') ++countb;
			if (p.board[startr][startc] == 'o') ++countw;
		}
	}
	if (countb > countw) std::cout << "Winner: BLACK\n\n";
	else if (countb < countw)std::cout << "Winner: WHITE\n\n";
	else std::cout << "Winner: none\n\n";
	
	return;
}

void switch_player(Game &p)
{
	(p.piece == BLACK_PIECE ? p.piece = WHITE_PIECE : p.piece = BLACK_PIECE);

	return;
}


bool move_made(Game &p)
{
	bool good_move = false;

	if (north(p))
	{
		good_move = true;
		p.move = true;
		north(p);
		p.move = false;
	}
	if (south(p))
	{
		good_move = true;
		p.move = true;
		south(p);
		p.move = false;
	}
	if (east(p))
	{
		good_move = true;
		p.move = true;
		east(p);
		p.move = false;
	}
	if (west(p))
	{
		good_move = true;
		p.move = true;
		west(p);
		p.move = false;
	}
	if (northeast(p))
	{
		good_move = true;
		p.move = true;
		northeast(p);
		p.move = false;
	}
	if (northwest(p))
	{
		good_move = true;
		p.move = true;
		northwest(p);
		p.move = false;
	}
	if (southeast(p))
	{
		good_move = true;
		p.move = true;
		southeast(p);
		p.move = false;
	}
	if (southwest(p))
	{
		good_move = true;
		p.move = true;
		southwest(p);
		p.move = false;
	}
	if (good_move) return true;
	else return false;
}

bool north (Game &p)
{
	if (p.row < 2) return false;
	int holdr = p.row - 1;
	if (p.board[holdr][p.col] == p.piece || 
		p.board[holdr][p.col] == ' ') return false;
	else if (p.here && p.move)
	{
		p.board[p.row][p.col] = p.piece;
		p.board[holdr][p.col] = p.piece;
	}
	for (int startr = holdr - 1; startr >= 0; startr--)
	{
		if (p.board[startr][p.col] == p.piece)
		{
			return true;
		}
		if (p.board[startr][p.col] == ' ') return false;
		if (p.here && p.move) p.board[startr][p.col] = p.piece;
	}
	return false;
}
bool south (Game &p)
{
	if (p.row > 5) return false;
	int holdr = p.row + 1;
	if (p.board[holdr][p.col] == p.piece || 
		p.board[holdr][p.col] == ' ') return false;
	else if (p.here && p.move)
	{
		p.board[p.row][p.col] = p.piece;
		p.board[holdr][p.col] = p.piece;
	}
	for (int startr = holdr + 1; startr <= 7; startr++)
	{
		if (p.board[startr][p.col] == p.piece)
		{
			return true;
		}
		if (p.board[startr][p.col] == ' ') return false;
		if (p.here && p.move) p.board[startr][p.col] = p.piece;
	}
	return false;
}
bool east (Game &p)
{
	if (p.col > 5) return false;
	int holdc = p.col + 1;
	if (p.board[p.row][holdc] == p.piece || 
		p.board[p.row][holdc] == ' ') return false;
	else if (p.here && p.move)
	{
		p.board[p.row][p.col] = p.piece;
		p.board[p.row][holdc] = p.piece;
	}
	for (int startc = holdc + 1; startc <= 7; startc++)
	{
		if (p.board[p.row][startc] == p.piece)
		{
			return true;
		}
		if (p.board[p.row][startc] == ' ') return false;
		if (p.here && p.move) p.board[p.row][startc] = p.piece;
	}
	return false;
}
bool west (Game &p)
{
	if (p.col < 2) return false;
	int holdc = p.col - 1;
	if (p.board[p.row][holdc] == p.piece || 
		p.board[p.row][holdc] == ' ') return false;
	else if (p.here && p.move)
	{
		p.board[p.row][p.col] = p.piece;
		p.board[p.row][holdc] = p.piece;
	}
	for (int startc = holdc - 1; startc >= 0; startc--)
	{
		if (p.board[p.row][startc] == p.piece)
		{
			return true;
		}
		if (p.board[p.row][startc] == ' ') return false;
		if (p.here && p.move) p.board[p.row][startc] = p.piece;
	}
	return false;
}
bool northeast (Game &p)
{
	if (p.row < 2 || p.col > 5) return false;
	int holdr = p.row - 1, holdc = p.col + 1;
	if (p.board[holdr][holdc] == p.piece || 
		p.board[holdr][holdc] == ' ') return false;
	else if (p.here && p.move)
	{
		p.board[p.row][p.col] = p.piece;
		p.board[holdr][holdc] = p.piece;
	}
	for (int startr = holdr - 1, startc = holdc + 1;
		startr >= 0, startc <= 7; startr--, startc++)
	{
		if (p.board[startr][startc] == p.piece)
		{
			return true;
		}
		if (p.board[startr][startc] == ' ') return false;
		if (p.here && p.move) p.board[startr][startc] = p.piece;
	}
	return false;
}
bool northwest (Game &p)
{
	if (p.row < 2 || p.col < 2) return false;
	int holdr = p.row - 1, holdc = p.col - 1;
	if (p.board[holdr][holdc] == p.piece || 
		p.board[holdr][holdc] == ' ') return false;
	else if (p.here && p.move)
	{
		p.board[p.row][p.col] = p.piece;
		p.board[holdr][holdc] = p.piece;
	}
	for (int startr = holdr - 1, startc = holdc - 1;
		startr >= 0, startc >= 0; startr--, startc--)
	{
		if (p.board[startr][startc] == p.piece)
		{
			return true;
		}
		if (p.board[startr][startc] == ' ') return false;
		if (p.here && p.move) p.board[startr][startc] = p.piece;
	}
	return false;
}
bool southeast (Game &p)
{
	if (p.row > 5 || p.col > 5) return false;
	int holdr = p.row + 1, holdc = p.col + 1;
	if (p.board[holdr][holdc] == p.piece || 
		p.board[holdr][holdc] == ' ') return false;
	else if (p.here && p.move)
	{
		p.board[p.row][p.col] = p.piece;
		p.board[holdr][holdc] = p.piece;
	}
	for (int startr = holdr + 1, startc = holdc + 1;
		startr <= 7, startc <= 7; startr++, startc++)
	{
		if (p.board[startr][startc] == p.piece)
		{
			return true;
		}
		if (p.board[startr][startc] == ' ') return false;
		if (p.here && p.move) p.board[startr][startc] = p.piece;
	}
	return false;
}
bool southwest (Game &p)
{
	if (p.row > 5 || p.col < 2) return false;
	int holdr = p.row + 1, holdc = p.col - 1;
	if (p.board[holdr][holdc] == p.piece || 
		p.board[holdr][holdc] == ' ') return false;
	else if (p.here && p.move)
	{
		p.board[p.row][p.col] = p.piece;
		p.board[holdr][holdc] = p.piece;
	}
	for (int startr = holdr + 1, startc = holdc - 1;
		startr <= 7, startc >= 0; startr++, startc--)
	{
		if (p.board[startr][startc] == p.piece)
		{
			return true;
		}
		if (p.board[startr][startc] == ' ') return false;
		if (p.here && p.move) p.board[startr][startc] = p.piece;
	}
	return false;
}
void save(Game &p)
{
	
	binaryio.open("board_array.dat", ios::out | ios::binary);
	binaryio.write(reinterpret_cast<char *>(&p.board), sizeof(p.board));
	binaryio.close();
	return;
}
void load(Game &p)
{
	binaryio.open("board_array.dat", ios::in | ios::binary);
	binaryio.read(reinterpret_cast<char *>(&p.board), sizeof(p.board));
	binaryio.close();

	draw(p);
	
	p.piece = BLACK_PIECE;
	
	std::cout << "Please enter the player that goes first\n"
		<< "black [@] or white [o]: ";
	std::cin >> p.piece;
	
	play(p);

	return;
}