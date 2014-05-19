// Name: Brandy Poag
// File: checker.h

#ifndef CHECKER_H
#define CHECKER_H

#include <iostream>
#include <ctime>

const int SIZE_ROW = 8, SIZE_COL = 8;

struct Game
{
	char board[SIZE_ROW][SIZE_COL];
	int row;
	int col;
	int new_row;
	int new_col;
	char piece;
	char king;
	char notKing;
	char notPiece;
	bool jump;
	bool jump_nrnc;
	bool any_jump;
};

void help();
void init(Game &p);
void draw(Game &p);
void whos_first(Game &p);
int convert_row();
int convert_col();
bool get_new_position(Game &p);
bool get_start_position(Game &p);
void switch_player(Game &p);
bool poss_move(Game &p);
bool valid_move(Game &p);
bool n_w(Game &p);
bool n_e(Game &p);
bool s_w(Game &p);
bool s_e(Game &p);
bool jump_check(Game &p);
bool jump_check_move(Game &p);
bool space_check_move(Game &p);
bool only1_player(Game &p);
void game_over(Game &p);
void play(Game &p);

#endif
