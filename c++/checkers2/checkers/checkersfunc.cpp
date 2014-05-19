// Name: Brandy Poag
// File: checkersfunc.cpp

const char RED_PIECE = 'r';
const char RED_KING = 'R';
const char WHITE_PIECE = 'w';
const char WHITE_KING = 'W';

#include "checker.h"


///explain rules of the game
void help()
{
	std::cout 
		<< "\n\nThe rules to this checkers game resemble those\n"
		<< "of American Checkers: \n\n\n"
		<< "#1: Once the players have determined who is red\n" 
		<< "and who is white. The game randomly choses a player to\n"
		<< "begin playing the game.\n\n"
		<< "#2: Players may only move diagonally.\n\n" 
		<< "#3: Players may only move forward (towards opponet),\n"
		<< "unless they are a king, then they may move"
		<< " backwards (toward their side) as well.\n\n"
		<< "#4: To become a king the players piece must reach the\n"
		<< "opposite side of the playing board from  where\n"
		<< "they started, then they are crowned.\n\n"
		<< "#5: Players may jump an opponets piece if opponet is\n"
		<< "directly next to them, and if they have the ability to\n"
		<< "move in that direction, and still remain on the board\n"
		<< "and if the position after the piece they have "
		<< "jumped is vaccant,\n"
		<< "and as long as these conditions are met the player can\n"
		<< "jump until the conditions are no longer met.\n\n"
		<< "If it is whites turn, and the board looks like:\n\n"
		<< "  A B C D E F G H\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "1| |r| |r| |r| |r|1\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "2|r| |r| |r| |r| |2\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "3| |r| |r| | | |r|3\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "4| | | | |r| | | |4\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "5| | | |w| | | | |5\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "6|w| | | |w| |w| |6\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "7| |w| |w| |w| |w|7\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "8|w| |w| |w| |w| |8\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "  A B C D E F G H\n\n"
		<< "White can jump red:\n\n"
		<< "  A B C D E F G H\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "1| |r| |r| |r| |r|1\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "2|r| |r| |r| |r| |2\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "3| |r| |r| |w| |r|3\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "4| | | | | | | | |4\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "5| | | | | | | | |5\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "6|w| | | |w| |w| |6\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "7| |w| |w| |w| |w|7\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "8|w| |w| |w| |w| |8\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "  A B C D E F G H\n\n"
		<< "#6: Once a piece or king has been jumped "
		<< "the piece is removed from the board.\n\n"
		<< "#7: The game continues until one player is out of moves"
		<< " or one player has no pieces left.\n"
		<< "The winner is the player with the most points,"
		<< " regular piece worth 1 point, king worth 2 points.\n\n"
		<< "#8: If a move(s) is possible the player must make it.\n"
		<< "if their is more than one direction the player can \n"
		<< "make a capture in, the may go wherever; \n"
		<< "reguardless of number of possible captures or types \n"
		<< "of pieces being captured.\n\n"
		<< "#9: Each player starts with 12 pieces.\n"
		<< "The board looks like this:\n\n"
		<< "  A B C D E F G H\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "1| |r| |r| |r| |r|1\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "2|r| |r| |r| |r| |2\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "3| |r| |r| |r| |r|3\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "4| | | | | | | | |4\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "5| | | | | | | | |5\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "6|w| |w| |w| |w| |6\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "7| |w| |w| |w| |w|7\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "8|w| |w| |w| |w| |8\n"
		<< " +-+-+-+-+-+-+-+-+\n"
		<< "  A B C D E F G H\n\n";
	return;
}



/// set up the board and call draw and play functions
void init(Game &p)
{
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			//row odd and col even or row even and col odd  
			////if row is 2 or less piece is black 
			////if row is 5 or more piece is white 
			////else piece is space
			if ((i % 2 != 0 && j % 2 == 0)
				||(i % 2 == 0 && j % 2 != 0))
			{
				if(i <= 2)
				{
					p.board[i][j] = RED_PIECE;
				}
				else if(i >= 5)
				{
					p.board[i][j] = WHITE_PIECE;
				}
				else
				{
					p.board[i][j] = ' ';
				}
			}
			else
			{
				p.board[i][j] = ' ';
			}
		} 
	}

	draw(p);

	play(p);

	return;
}


/// if there is only player or no players it returns false
bool only1_player(Game &p)
{
	bool red = false, white = false;
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			if (p.board[i][j] == RED_PIECE 
				|| p.board[i][j] == RED_KING) red = true;
			if (p.board[i][j] == WHITE_PIECE 
				|| p.board[i][j] == WHITE_KING) white = true;
		}
	}
	return (red && white);
}


/// counts all remaining pieces and assigns point values
/// kings worth 2 point else 1 point and declares a winner or tie
void game_over(Game &p)
{
	int count_r = 0, count_w = 0, count_rk = 0, count_wk = 0; 
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			if (p.board[i][j] == RED_PIECE) ++count_r;
			else if (p.board[i][j] == RED_KING) ++count_rk;
			else if (p.board[i][j] == WHITE_PIECE) ++count_w;
			else if (p.board[i][j] == WHITE_KING) ++count_wk;
		}
	}
	count_r += count_rk * 2;
	count_w += count_wk * 2;
	if (count_r > count_w) 
	{
		std::cout << "Red is the winner!\n";
	}
	else if (count_r < count_w) 
	{
		std::cout << "White is the winner!\n";
	}
	else 
	{
		std::cout << "There is a tie!";
	}
	return;
}


/// draws the current board
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


///randomly selects red or white to go first
void whos_first(Game &p)
{
	int x = int((double) rand() / RAND_MAX * 1000);
	if (x % 2 == 0)
	{
		std::cout << "Red goes first!\n";
		p.piece = RED_PIECE;
		p.notPiece = WHITE_PIECE;
	}
	else
	{
		std::cout << "White goes first!\n";
		p.piece = WHITE_PIECE;
		p.notPiece = RED_PIECE;
	}
	return;
}


int convert_row()
{
	char x;
	while (1)
	{
		std::cout << "Enter a row [1-8]: ";
		std::cin >> x;
		std::cin.ignore();
		if (x >= 49 && x <= 56)return x - 49;
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
		if ((x >= 65 && x <= 73)
			||(x >= 97 && x <= 105)) return (tolower(x) - 97);
		else std::cout << "This is not a valid entry!\n";
	}
}


///scans all board if it is the current players piece 
///calls valid_move to see if a move is poss if so returns true
bool poss_move(Game &p)
{
	bool yes = false;
	//loop through board arrary calling each position that has a p.piece 
	//into move_made if returns true record row col in valid_arrary
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			if (p.board[i][j] == p.piece)
			{
				p.row = i;
				p.col = j;
				if (jump_check(p))
				{
					p.any_jump = true;
					yes = true;
				}
			}
		}
	}
	for (int i = 0; i < SIZE_ROW; i++)
	{
		for (int j = 0; j < SIZE_COL; j++)
		{
			if (p.board[i][j] == p.piece)
			{
				p.row = i;
				p.col = j;
				if (valid_move(p)) yes = true;
			}
		}
	}
	return yes;
}


///checks ne nw se sw for a move to the next spot if so move is made 
bool king_next_spot(Game &p)
{
	if (p.board[p.row-1][p.col+1] == ' ') //-+
	{
		if (p.row > -1 && p.col < 8 
			&& p.row-1 == p.new_row && p.col+1 == p.new_col)
		{
			p.board[p.row][p.col] = ' ';
			if (p.piece == 'r') p.board[p.row-1][p.col+1] = RED_KING;
			else p.board[p.row-1][p.col+1] = WHITE_KING;
			return true;
		}
	}
	if (p.board[p.row+1][p.col+1] == ' ')//++
	{
		if (p.row < 8 && p.col < 8 
			&& p.row+1 == p.new_row && p.col+1 == p.new_col)
		{
			p.board[p.row][p.col] = ' ';
			if (p.piece == 'r') p.board[p.row+1][p.col+1] = RED_KING;
			else p.board[p.row+1][p.col+1] = WHITE_KING;
			return true;
		}
	}
	if (p.board[p.row+1][p.col-1] == ' ') //+-
	{
		if (p.row < 8 && p.col > -1 
			&& p.row+1 == p.new_row && p.col-1 == p.new_col)
		{
			p.board[p.row][p.col] = ' ';
			if (p.piece == 'r') p.board[p.row+1][p.col-1] = RED_KING;
			else p.board[p.row+1][p.col-1] = WHITE_KING;
			return true;
		}
	}
	if (p.board[p.row-1][p.col-1] == ' ')//--
	{
		if (p.row > -1 && p.col > -1 
			&& p.row-1 == p.new_row && p.col-1 == p.new_col)
		{
			p.board[p.row][p.col] = ' ';
			if (p.piece == 'r') p.board[p.row-1][p.col-1] = RED_KING;
			else p.board[p.row-1][p.col-1] = WHITE_KING;
			return true;
		}
	}		
	return false;
}


///checks se sw for a move to the next spot if so move is made
bool red_next_spot(Game &p)
{
	if (p.row < 8 && p.col > -1 && p.board[p.row+1][p.col-1] == ' ')
	{
		if (p.row+1 == p.new_row && p.col-1 == p.new_col)
		{
			p.board[p.row][p.col] = ' ';
			if (p.row+1 == 7) p.board[p.row+1][p.col-1] = RED_KING;
			else p.board[p.row+1][p.col-1] = p.piece;
			return true;
		}
	}
	if (p.row-1 < 8 && p.col < 8 && p.board[p.row+1][p.col+1] == ' ')
	{
		if (p.row+1 == p.new_row && p.col+1 == p.new_col)
		{
			p.board[p.row][p.col] = ' ';
			if (p.row+1 == 7) p.board[p.row+1][p.col+1] = RED_KING;
			else p.board[p.row+1][p.col+1] = p.piece;
			return true;
		}
	}
	return false;
}


///checks ne nw for a move to the next spot if so move is made
bool white_next_spot(Game &p)
{
	if (p.row-1 > -1 && p.col > -1 
		&& p.board[p.row-1][p.col-1] == ' ') 
	{
		if (p.row-1 == p.new_row && p.col-1 == p.new_col)
		{
			p.board[p.row][p.col] = ' ';
			if (p.row-1 == 0) p.board[p.row-1][p.col-1] = WHITE_KING;
			else p.board[p.row-1][p.col-1] = p.piece;
			return true;
		}
	}
	if (p.row-1 > -1 && p.col < 8 
		&& p.board[p.row-1][p.col+1] == ' ')
	{
		if (p.row-1 == p.new_row && p.col+1 == p.new_col)
		{
			p.board[p.row][p.col] = ' ';
			if (p.row-1 == 0) p.board[p.row-1][p.col+1] = WHITE_KING;
			else p.board[p.row-1][p.col+1] = p.piece;
			return true;
		}
	}
	return false;
}


///checks ne nw se sw for a jump if so move is made 
bool king_jump(Game &p)
{
	////////////know piece is king so decied if red or white
	if (n_w(p) && p.new_row == p.row - 2 && p.new_col == p.col - 2)
	{
		p.board[p.row][p.col] = ' ';
		p.board[p.row-1][p.col-1] = ' ';
		if (p.king == 'R') p.board[p.row-2][p.col-2] = RED_KING;
		else p.board[p.row-2][p.col-2] = WHITE_KING;
		return true;
	}
	if (n_e(p) && p.new_row == p.row - 2 && p.new_col == p.col + 2)
	{
		p.board[p.row][p.col] = ' ';
		p.board[p.row-1][p.col+1] = ' ';
		if (p.king == 'R') p.board[p.row-2][p.col+2] = RED_KING;
		else p.board[p.row-2][p.col+2] = WHITE_KING;
		return true;
	}
	if (s_w(p) && p.new_row == p.row + 2 && p.new_col == p.col - 2)
	{
		p.board[p.row][p.col] = ' ';
		p.board[p.row+1][p.col-1] = ' ';
		if (p.king == 'R') p.board[p.row+2][p.col-2] = RED_KING;
		else p.board[p.row+2][p.col-2] = WHITE_KING;
		return true;
	}
	if (s_e(p) && p.new_row == p.row + 2 && p.new_col == p.col + 2)
	{
		p.board[p.row][p.col] = ' ';
		p.board[p.row+1][p.col+1] = ' ';
		if (p.king == 'R') p.board[p.row+2][p.col+2] = RED_KING;
		else p.board[p.row+2][p.col+2] = WHITE_KING;
		return true;
	}	
	return false;
}


///checks se sw for a jump if so move is made and true is returned
bool red_jump(Game &p)
{
	///////know piece is red so upgrade if row is 7
	if (s_w(p))
	{
		p.board[p.row][p.col] = ' ';
		p.board[p.row + 1][p.col - 1] = ' ';
		if (p.row + 2 == 7) p.board[p.row+2][p.col-2] = RED_KING;
		else p.board[p.row+2][p.col-2] = p.piece;
		return true;
	}
	if (s_e(p))
	{
		p.board[p.row][p.col] = ' ';
		p.board[p.row + 1][p.col + 1] = ' ';
		if (p.row + 2 == 7) p.board[p.row+2][p.col+2] = RED_KING;
		else p.board[p.row+2][p.col+2] = p.piece;
		return true;
	}
	return false;
}


///checks ne nw for a jump if so move is made and true is returned
bool white_jump(Game &p)
{
	////////make change and up grade to king if newrow is 0
	if (n_w(p))
	{
		p.board[p.row][p.col] = ' ';
		p.board[p.row - 1][p.col - 1] = ' ';
		if (p.row - 2 == 0) p.board[p.row-2][p.col-2] = WHITE_KING;
		else p.board[p.row-2][p.col-2] = p.piece;
		return true;
	}
	if (n_e(p))
	{
		p.board[p.row][p.col] = ' ';
		p.board[p.row - 1][p.col + 1] = ' ';
		if (p.row - 2 == 0) p.board[p.row-2][p.col+2] = WHITE_KING;
		else p.board[p.row-2][p.col+2] = p.piece;
		return true;
	}
	return false;
}


///if piece is king see if there is a move ne nw se sw 
//if white check ne nw if red check se sw 
//and if any are true move was made and return true
bool space_check_move(Game &p)
{
	if (p.board[p.row][p.col] == RED_KING 
		|| p.board[p.row][p.col] == WHITE_KING)
	{
		return (king_next_spot(p));
	}
	else if (p.board[p.row][p.col] == RED_PIECE)
	{
		return (red_next_spot(p));
	}
	else if(p.board[p.row][p.col] == WHITE_PIECE)
	{
		return (white_next_spot(p));
	}
	return false;
}


bool jump_check_move(Game &p)
{
	if (p.board[p.row][p.col] == RED_KING 
		|| p.board[p.row][p.col] == WHITE_KING)
	{
		return (king_jump(p));
	}
	else if (p.board[p.row][p.col] == RED_PIECE)
	{
		return (red_jump(p));
	}
	else if(p.board[p.row][p.col] == WHITE_PIECE)
	{
		return (white_jump(p));
	}
	return false;
}


bool jump_check(Game &p)
{
	if (p.board[p.row][p.col] == RED_KING 
		|| p.board[p.row][p.col] == WHITE_KING)
	{
		if(n_w(p) || n_e(p) || s_w(p) || s_e(p))
		{
			return true;
		}
	}
	else if (p.board[p.row][p.col] == RED_PIECE)
	{
		if(s_w(p) || s_e(p))
		{
			return true;
		}
	}
	else if(p.board[p.row][p.col] == WHITE_PIECE)
	{
		if(n_w(p) || n_e(p))
		{
			return true;
		}
	}
	return false;
}


///decides if piece is king or white or red and sees if a 
///move is possibe returns true if there is but move is not made
bool valid_move(Game &p)
{
	//call the valid directions
	//kings can move all four directions
	//red pieces move down
	//white pieces move up
	if (p.board[p.row][p.col] == RED_KING 
		|| p.board[p.row][p.col] == WHITE_KING)
	{
		return ((p.board[p.row+1][p.col-1] == ' ' 
			&& p.row+1 < 8 && p.col-1 > -1)
			|| (p.board[p.row-1][p.col-1] == ' ' 
			&& p.row-1 > -1 && p.col-1 > -1)
			|| (p.board[p.row+1][p.col+1] == ' ' 
			&& p.row+1 < 8 && p.col+1 < 8)
			|| (p.board[p.row-1][p.col+1] == ' ' 
			&& p.row-1 > -1 && p.col+1 < 8));
	}
	else if (p.board[p.row][p.col] == RED_PIECE)
	{
		return ((p.row+1 < 8 && p.col-1 > -1 
			&& p.board[p.row+1][p.col-1] == ' ')
			|| (p.board[p.row+1][p.col+1] == ' ' 
			&& p.row+1 < 8 && p.col+1 < 8));
	}
	else if(p.board[p.row][p.col] == WHITE_PIECE)
	{
		return ((p.row-1 > -1 && p.col-1 > -1 
			&& p.board[p.row-1][p.col-1] == ' ')
			|| (p.row-1 > -1 && p.col+1 < 8 
			&& p.board[p.row-1][p.col+1] == ' '));
	}
	return false;
}


///if a there is a ne jump returns true
bool n_e(Game &p)
{	
	if (p.row-2 > -1 && p.col+2 < 8)
	{
		if ((p.board[p.row - 1][p.col + 1] == p.notPiece
			|| p.board[p.row - 1][p.col + 1] == p.notKing) 
			&& p.board[p.row - 2][p.col + 2] == ' ')
		{
			if (p.row-2 == p.new_row && 
				p.col+2 == p.new_col)  p.jump_nrnc = true;
			p.jump = true;
			return true;
		}
	}
	return false;
}



///if a there is a nw jump returns true
bool n_w(Game &p)
{
	if (p.row-2 > -1 && p.col-2 > -1)
	{
		if ((p.board[p.row-1][p.col-1] == p.notPiece 
			|| p.board[p.row-1][p.col-1] == p.notKing) 
			&& p.board[p.row - 2][p.col - 2] == ' ')
		{
			if (p.row-2 == p.new_row && 
				p.col-2 == p.new_col)  p.jump_nrnc = true;
			p.jump = true;
			return true;
		}
	}
	return false;
}



///if a there is a sw jump returns true
bool s_w(Game &p)
{
	if (p.row+2 < 8 && p.col-2 > -1)
	{
		if ((p.board[p.row+1][p.col-1] == p.notPiece 
			|| p.board[p.row+1][p.col-1] == p.notKing) 
			&& p.board[p.row + 2][p.col - 2] == ' ')
			{
			if (p.row+2 == p.new_row && 
				p.col-2 == p.new_col)  p.jump_nrnc = true;
			p.jump = true;
			return true;
		}
	}
	return false;
}


///if a there is a se jump returns true
bool s_e(Game &p)
{
	if (p.row+2 < 8 && p.col+2 < 8)
	{
		if ((p.board[p.row+1][p.col+1] == p.notPiece
			|| p.board[p.row+1][p.col+1] == p.notKing) 
			&& p.board[p.row + 2][p.col + 2] == ' ')
			{
			if (p.row+2 == p.new_row && 
				p.col+2 == p.new_col)  p.jump_nrnc = true;
			p.jump = true;
			return true;
		}
	}
	return false;
}


/*

////////////call in a while loop until true
///1. call convert row if 9 quit col
///2. make sure piece is on of the currents players pieces
///3. if there is a jump this must be start of the jump 
///4. if there is no jump make sure there is a move from here
/////////////if false must say this piece has no moves for you
/////////////
///#3jump if true them call jump_check 
///#4 if jump not true then check move 
/*/
bool get_start_position(Game &p)
{
	std::cout << "Select a piece to be moved!\n";

	p.row = convert_row();
	p.col = convert_col();
	if (!(p.board[p.row][p.col] == p.king 
		|| p.board[p.row][p.col] == p.piece))
	{
		std::cout << "This is not your piece.\n"; 
		return false;
	}
	if (p.any_jump)
	{
		p.jump = false;
		jump_check(p);
		if (p.jump)
		{
			return true;
		}
		else
		{
			std::cout << "You have to make a jump!\n";
			return false;
		}
	}
	else
	{
		if (valid_move(p))
		{
			return true;
		}
		else
		{
			std::cout << "There are no moves from there!\n";
			return false;
		}
	}
	return false;
}


/*
////////////call in a while loop until true
///1. call convert row if 9 quit col
///2. make sure piece is a ' '
///3. if there is a jump this must be end of the jump 
///4. if no jump this must be the end of a move
////////////if false must say this is not a valid spot
///////////
///#3 if jump true then make sure a jump from start will end here
//*/
bool get_new_position(Game &p)
{
	p.jump_nrnc = false;
	std::cout << "Select a spot to move to.\n";
	p.new_row = convert_row();
	p.new_col = convert_col();
	
	if (p.board[p.new_row][p.new_col] != ' ') 
	{
		std::cout << "This spot is not avalible.\n";
		return false;
	}

	if (p.jump)
	{
		jump_check(p);
		if (p.jump_nrnc)
		{
			jump_check_move(p);
			p.row = p.new_row;
			p.col = p.new_col;
			while(jump_check(p))
			{
				jump_check_move(p);
				p.row = p.new_row;
				p.col = p.new_col;
				draw(p);
				p.jump = false;
				p.jump_nrnc = false;
			}
		}
		else
		{
			std::cout << "You have to make a jump!\n";
			return false;
		}
	}
	else
	{
		if (!valid_move(p))
		{
			std::cout << "There is not move to there!\n";
			return false;
		}
		else 
		{
			if (!space_check_move(p))
			{
				std::cout << "Try again\n";
				return false;
			}
		}
	}
	return true;
}



/// switches current player and current player's piece and notpiece
void switch_player(Game &p)
{
	if (p.piece == RED_PIECE || p.piece == RED_KING)
	{
		std::cout << "White's turn: \n";
		p.piece = WHITE_PIECE;
		p.notPiece = RED_PIECE;
		p.king = WHITE_KING;
		p.notKing = RED_KING;
	}
	else
	{
		std::cout << "Red's turn: \n";
		p.piece = RED_PIECE;
		p.notPiece = WHITE_PIECE;
		p.king = RED_KING;
		p.notKing = WHITE_KING;
	}
	return;
}





void play(Game &p)
{
	char x;
	p.jump = false;
	p.jump_nrnc = false;
	p.any_jump = false;
	whos_first(p);
	while (only1_player(p) && poss_move(p))
	{
		while (1)
		{
			if (get_start_position(p)) break;
		}
		while (1)
		{
			if (get_new_position(p)) break;
			std::cout << "If you want to end game enter "
				<< "[y] for yes and [n] for no: ";
			std::cin >> x;
			if (x == 'y' || x == 'Y')
			{
				game_over(p);
				return;
			}
		}
		draw(p);
		std::cout << "If you want to end game enter "
			"[y] for yes and [n] for no: ";
		std::cin >> x;
		if (x == 'y' || x == 'Y')
		{
			game_over(p);
			return;
		}
		switch_player(p);
		p.any_jump = false;
		poss_move(p); 
		p.jump = false;
	}
	game_over(p);
	return;
}