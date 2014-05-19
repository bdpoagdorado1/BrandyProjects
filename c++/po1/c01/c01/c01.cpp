// Name: Brandy Poag
// File: p01.cpp

#include <iostream>
#include <cstring>

const int SIZE_ROW = 8, SIZE_COL = 8;
const int BLACK = 0;
const int WHITE = 1;
const char BLACK_PIECE = '@';
const char WHITE_PIECE = 'o';

typedef char Board[SIZE_ROW][SIZE_COL];

void help();
void play();
void load();
void setup();
bool turn(bool color, char piece);
bool is_valid_position(int row, int col);
int get_row(char input[]);
int get_col(char input[]);

void init(Board b);
void draw(Board b);

bool is_poss_move(int playx, int playy, bool move_um, Board board, char piece);
bool is_poss_move(int playx, int playy, bool move_um, Board board, char piece, bool change[]);
bool check_for_move(int playx, int playy, int rise, int run, bool move_um, Board board, char piece);


int main()
{
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
		case 'p': play();
					break;
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

void help()
{
	std::cout << "The official rules can be found at\n"
		<< "http://en.wikipedia.org/wiki/Reversi\n\n"
		<< " The Othello board is set up is the following" 
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


void play()
{
	char input[100];
	char piece = '@';
	Board board;
	init(board);

	bool color = false, move_um = false, play_game = true, on = true;
	int count = 0;

	std::cin.getline(input, 100);

	while(count <= 2)
	{
		for (int startr = 0; startr < SIZE_ROW; startr++)
		{
			for (int startc = 0; startc < SIZE_COL; startc++)
			{
				if (is_poss_move(startr, startc, move_um, board, piece))
				{						
					play_game = true;
					count = 0;
					break;
				}
			}
			if (play_game) break;
		}
		if (!play_game) ++count;
		
		
		if (play_game && on)
		{
			(on ? on = false : on = true);
			draw(board);
		}

		bool change[8] = {0};

		while (play_game)
		{
			if (color == BLACK)
			{
				piece = BLACK_PIECE;
				std::cout << "BLACK's turn: ";
			}
			if (color == WHITE)
			{
				std::cout << "WHITE's turn: ";
				piece = WHITE_PIECE;
			}

			std::cin.getline(input, 100);

			for (int j = 0; j < 3; j++)
			{
				if ((input[j] == 'q' || input[j] == 'Q') && input[j + 1] == '\0')
				{
					int countb = 0, countw = 0;
					//game over return;
					for (int startr = 0; startr < SIZE_ROW; startr++)
					{
						for (int startc = 0; startc < SIZE_COL; startc++)
						{
							if (board[startr][startc] == '@') ++countb;
							if (board[startr][startc] == 'o') ++countw;
						}
					}

					if (countb > countw) std::cout << "Winner: BLACK\n\n";
					else if (countb < countw)std::cout << "Winner: WHITE\n\n";
					else std::cout << "Winner: none\n\n";
					
					return;
				}
			}

			int i = get_row(input), j = get_col(input);


			if (is_valid_position(i, j))
			{
				if(is_poss_move(i, j, move_um, board, piece, change))
				{
					move_um = true;
					if (is_poss_move(i, j, move_um, board, piece, change)) move_um = false;
					draw(board);
					color = turn(color, piece);
					count = 0;
					play_game = false;
					move_um = false;
					break;
				}
				else
				{
					std::cout << "Invalid position\n";
				}
			}	
			else
			{
				std::cout << "Invalid position\n";
			}
		}
		if (count == 2)
		{
			int countb = 0, countw = 0;
			//game over return;
			for (int startr = 0; startr < SIZE_ROW; startr++)
			{
				for (int startc = 0; startc < SIZE_COL; startc++)
				{
					if (board[startr][startc] == '@') ++countb;
					if (board[startr][startc] == 'o') ++countw;
				}
			}

			if (countb > countw) std::cout << "Winner: BLACK\n\n";
			else if (countb < countw)std::cout << "Winner: WHITE\n\n";
			else std::cout << "Winner: none\n\n";
			
			return;
		}
		
	} //outer while
}


int get_row(char input[1])
{
	return input[1] - '1';
}


int get_col(char input[])
{
	return input[0] - 'A';
}


void load()
{
	return;
}


void setup()
{
	return;
} 


bool is_valid_position(int row, int col)
{
	bool is_valid = false;
	if ((col >= 0 && col <= 7)&&(row >= 0 && row <= 7)) is_valid = true;
	return is_valid;
}


bool turn(bool color, char piece)
{
	(color ? color = false : color = true);
	if (color == BLACK)
	{
		piece = BLACK_PIECE;
	}
	else
	{
		piece = WHITE_PIECE;
	}
	return color;
}


void init(Board b)
{
	int half_row = SIZE_ROW / 2, half_col = SIZE_COL / 2;

	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			if ((i == half_row - 1 && j == half_col - 1)|| (i == half_row && j == half_col)) b[i][j] = 'o';
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


bool is_poss_move(int playx, int playy, bool move_um, Board board, char piece)
{
	bool n = false, ne = false, e = false, se = false, s = false, sw = false, w = false, nw = false;
	if (check_for_move(playx, playy, -1, 0, move_um, board, piece)) n = true;
	if (check_for_move(playx, playy, -1, 1, move_um, board, piece)) ne = true;
	if (check_for_move(playx, playy, 0, 1, move_um, board, piece)) e = true;
	if (check_for_move(playx, playy, 1, 1, move_um, board, piece)) se = true;
	if (check_for_move(playx, playy, 1, 0, move_um, board, piece)) s = true;
	if (check_for_move(playx, playy, 1, -1, move_um, board, piece)) sw = true;
	if (check_for_move(playx, playy, 0, -1, move_um, board, piece)) w = true;
	if (check_for_move(playx, playy, -1, -1, move_um, board, piece)) nw = true;

	if (n || ne || e || se || s || sw || w || nw) return true;
	else return false;
}

bool is_poss_move(int playx, int playy, bool move_um, Board board, char piece, bool change[])
{
	bool move = false;
	if (move_um) move = true;
	if (change[0] == 1 && move) move_um = true;
	else move_um = false;
	if (check_for_move(playx, playy, -1, 0, move_um, board, piece)) change[0] = 1;
	if (change[1] == 1&& move) move_um = true;
	else move_um = false;
	if (check_for_move(playx, playy, -1, 1, move_um, board, piece)) change[1] = 1;
	if (change[2] == 1 && move) move_um = true;
	else move_um = false;
	if (check_for_move(playx, playy, 0, 1, move_um, board, piece)) change[2] = 1;
	if (change[3] == 1 && move) move_um = true;
	else move_um = false;
	if (check_for_move(playx, playy, 1, 1, move_um, board, piece)) change[3] = 1;
	if (change[4] == 1 && move) move_um = true;
	else move_um = false;
	if (check_for_move(playx, playy, 1, 0, move_um, board, piece))change[4] = 1;
	if (change[5] == 1 && move) move_um = true;
	else move_um = false;
	if (check_for_move(playx, playy, 1, -1, move_um, board, piece)) change[5] = 1;
	if (change[6] == 1 && move) move_um = true;
	else move_um = false;
	if (check_for_move(playx, playy, 0, -1, move_um, board, piece)) change[6] = 1;
	if (change[7] == 1 && move) move_um = true;
	else move_um = false;
	if (check_for_move(playx, playy, -1, -1, move_um, board, piece)) change[7] = 1;
	
	
	for (int i = 0; i < 8; i++)
	{
		if (change[i] == 1)
		{
			return true;
		}
	}
	return false;
}

bool check_for_move(int playx, int playy, int rise, int run, bool move_um, Board board, char piece)
{
	int startx = playx;
	int starty = playy;
	bool check = false;
	startx += rise;
	starty += run;

	if (board[startx][starty] == piece || board[startx][starty] == ' ' || !(is_valid_position(startx, starty))) return check;

	while (board[startx][starty] != ' ' && is_valid_position(startx, starty))
	{
		if (board[startx][starty] == piece)
		{
			if (move_um) board[playx][playy] = piece;
			check = true;
			break;
		}
		else
		{
			if (move_um)
			{
				board[startx][starty] = piece;
			}
		}

		startx += rise;
		starty += run;
	}

	return check;
}

