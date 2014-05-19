
//  Author:  Brandy Poag
//  Due Date:  04/12/2010
//  Project No: 04
//  Description:  
//	The sort_em class uses varrious sorting algorithims to 
//  sort an array of 8,192 elements	then prints the 
//  number of exchanges and compairsons and checks to 
//  make sure all the sorted arrays are identical.


//  Honor Statement: My signature below attests to the fact that 
//  I have neither given nor received aid on this project.


// ___________________________ (Signature)


/*******************************************************************
RESULT REPORT:

	After using all of the sorting algorithms on this particular set
	of 8,192 random integers the results surprised me. I assumed that 
	quicksort would be the fastest of the algorithms however the 
	Mergesort was the best with the fewest key comparisons and fewest 
	key moves and actually the comparisions fell below N log N. 
	Quicksort, however, held its own by taking the next 
	three spots for the fastest with the least amount of comparisons
	the quicksort w/ a cut-off of 10 was better than the cut-off of
	20, and both were better than the quicksort without a cut-off.
	Then heapsort was not too far behind merge and quicksort with 
	few comparisons doing very well. These are the top five sorts
	all were considerably close to N log N.

	The bottom half is not as impressive although even the worst
	case senerio was almost 4 times better than O(N^2).  The 
	origional shellsort was so much better than the Hibbard and 
	Sedgewick version, 36 times better, I think there must be a 
	mistake with my code. The insertion sort was close to the
	the Hibbard and Sedgewick version of shell sort only a little 
	better, but not near as good as the origional shellsort.  
	Finally, the Hibbard and Sedgewick versions of shellsort were 
	very close with Sedgewick doing slightly better.
	

*******************************************************************/
                

#include <iostream>
#include "sorter.h"


using namespace std;



    // Test program
int main( )
{
	Sort_em a;
	
    return 0;
}










