#ifndef DATE_H
#define DATE_H

class Date
{
public:
	void init (int, int, int);
	void print ();
	void add_y (int);
	void add_m (int);
	void add_d (int);

private:
	int d, m, y;
};


#endif
