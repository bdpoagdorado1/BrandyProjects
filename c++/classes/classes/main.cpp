#include "date.h"

int main()
{
	Date today, yesterday;

	today.init (12, 25, 2003);
	today.print ();

	today.init (12, 24, 2003);
	today.print ();

	return 0;
}