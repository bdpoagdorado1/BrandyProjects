// Name: Brandy Poag
// File: set.h
#ifndef SET_H
#define SET_H

void set_println(int x[], int & len);


bool set_hasmember(int x[], int & len, int i);

void set_insert(int x[], int & len, int i);
void set_remove(int x[], int & len, int i);
void set_clear(int x[], int & len);

bool set_issubset(int x[], int & xlen, int y[], int & ylen);
bool set_isequal(int x[], int & xlen, int y[], int & ylen);

#endif
