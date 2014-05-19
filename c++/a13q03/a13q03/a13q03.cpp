// Name: Brandy Poag
// File: a13q03.cpp

#include <iostream>
#include <cmath>

void es(int n, int prime[], int & len);
void printLiving(int n, bool dead[]);
bool living(int & theKiller, int n, bool dead[], bool stop);
int determineKiller(int & theKiller, int n, bool dead[]);

int main()
{
	int n = 0, len = 0;
	int prime[1000];
	std::cin >> n;

	// call es to create an arrary of primes
	es(n, prime, len);

	std::cout << "\nprimes from 2 to " << n << ":\n";
	for (int i = 0; i < len; i++)
	{
		std::cout << prime[i] << ' ';
	}
	std::cout << "\nlen: " << len << '\n';

	return 0;
}

void es(int n, int prime[], int & len)
{
	// create a bool array to store (living number) 0
	// eventually all prime # will be 0 else value is 1 (dead num)
	bool dead[1000] = {0};
	dead[0] = 1;
	dead[1] = 1;

	// stop allows the loops to know the only living values 
	// have prime index's
	bool stop = true;

	// this pime "theKiller" will help determine if other numbers 
	// are prime if theKiller is a divisor then numer is dead
	int theKiller = 2;

	// call printLiving to show the remaining living numbers 
	printLiving(n, dead);

	while(stop)
	{
		// determine if loop should end by calling living
		stop = living(theKiller, n, dead, stop);
		// call printLiving to show the remaining living numbers 
		if (stop == false && theKiller != int(sqrt((double)n)))
		{
			break;
		}
		printLiving(n, dead);
	}
	// Scan arrary for 0 (living) and set the count of
	// primes to len
	int count = 0;
	int j = 0;
	for (int i = 0; i <= n; i++)
	{
		if (dead[i] == 0)
		{
			prime[j] = i;
			count++;
			j++;
		}
	}
	len = count;

	return;
}

// If living **print their index values (from 2 to n)
void printLiving(int n, bool dead[])
{
	for (int i = 2; i <= n; i++)
	{
		if (dead[i] == 0) std::cout << i << ' ';
	}
	std::cout << '\n';

	return;
}

bool living(int & theKiller, int n, bool dead[], bool stop)
{
	// print the current killer
	if (theKiller <= int(sqrt((double)n)))
	{
		std::cout << theKiller << ": ";
	}

	// scan for living and divisors of thekiller set them to 1
	for (int i = theKiller + 1; i <= n; ++i)
	{
		if (dead[i] == 0 && i % theKiller == 0) dead[i] = 1;
	}

	// if there is a living number that is not a prime
	// n (rounded up and minus 1) 
	if (theKiller < int(sqrt((double)n)))
	{
		// then call determineKiller for a new killer
		theKiller = determineKiller(theKiller, n, dead);
	}
	else
	{
		// no more killers possible then set stop to 1 and return
		stop = false;
	}
	
	return stop;
}

// determine killer if prime # and number is < than the sqrt of n 
// the start changes! begin past previous start goes to sqrt of n
int determineKiller(int & theKiller, int n, bool dead[])
{
	for (int i = theKiller + 1; i < int(sqrt((double)n)) + 1; ++i)
	{
		if (dead[i] == 0)
		{
			theKiller = i;
			return theKiller;
		}
	}
	
	
}