// Name: Brandy Poag
// File: othelloheader.h

#ifndef OTHELLOHEADER_H
#define OTHELLOHEADER_H

struct play
{
	char board[SIZE_ROW][SIZE_COL];
	int playx;
	int playy;
	char piece;
	bool move_um;
};

struct slope
{
	int rise;
	int run;
};

void help();
void load();
void setup(play);
void init(play);
void draw(play);


#endif



