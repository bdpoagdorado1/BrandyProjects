#include "mtrand.h"
#include <cmath>
#include <vector>
#include <functional>
using namespace std;

#ifndef SORTER_H
#define SORTER_H


/******************************************************************/
/******************************************************************/
/******************************************************************/

/**
 * Several sorting routines put into a class called sort_em;
 * Arrays are rearranged with smallest item first.
 */

class Sort_em
{
public:

	int comp;
	int exch;
	Sort_em( ) : comp(0), exch(0)
	{
		const int NUM_ITEMS = 8192;
		vector < size_t > a0;
		for( int i = 0; i < a0.size( ); i++ )
			a0[ i ] = i;

		MTRand_int32 irand(unsigned(5));
		for (size_t i = 0; i < NUM_ITEMS; ++i)
		{
			a0.push_back(irand());
		}
	       
		vector < size_t > a = a0;
		insertionSort( a );
		std::cout << "Insertion Sort: comparisons: " << comp << 
			" and exchanges: " << exch << "\n";
		comp = 0, exch = 0;
		
		vector < size_t > a1 = a0;
		heapsort( a1 );
		std::cout << "Heap Sort: comparisons: " << comp << 
			" and exchanges: " << exch << "\n";
		comp = 0, exch = 0;
	    
		vector < size_t > a2 = a0;
		shellsort( a2 );
		std::cout << "Shellsort: comparisons: " << comp << 
			" and exchanges: " << exch << "\n";
		comp = 0, exch = 0;
	   
		
		vector < size_t > a3 = a0;
		mergeSort( a3 );
		std::cout << "Merge Sort: comparisons: " << comp << 
			" and exchanges: " << exch << "\n";
		comp = 0, exch = 0;

	  
		vector < size_t > a4 = a0;
		quicksort( a4 );
		std::cout << "Quick Sort w/o cu-off: comparisons: " 
			<< comp << " and exchanges: " << exch << "\n";
		comp = 0, exch = 0;

		vector < size_t > a5 = a0;
		quicksort10( a5 );
		std::cout << "Quick Sort w cu-off 10: comparisons: "
			<< comp << " and exchanges: " << exch << "\n";
		comp = 0, exch = 0;


		vector < size_t > a6 = a0;
		quicksort20( a6 );
		std::cout << "Quick Sort w cu-off 20: comparisons: " 
			<< comp << " and exchanges: " << exch << "\n";
		comp = 0, exch = 0;

		vector < size_t > a7 = a0;
		shellsort_hibbard( a7 );
		std::cout << "Shellsort Hibbard: comparisons: " << comp 
			<< " and exchanges: " << exch << "\n";
		comp = 0, exch = 0;

		vector < size_t > a8 = a0;
		shellsort_sedgewick( a8 );
		std::cout << "Shellsort Sedgewick: comparisons: " << comp 
			<< " and exchanges: " << exch << "\n";


	   for (size_t i = 0; i < NUM_ITEMS; ++i)
		{
			if (a[i] != a1[i]) std::cout << "error at index i = " 
				<< i << " array 1\n";
			else if (a[i] != a2[i]) std::cout 
				<< "error at index i = " << i << " array 2\n";
			else if (a[i] != a3[i]) std::cout 
				<< "error at index i = " << i << " array 3\n";
			else if (a[i] != a4[i]) std::cout 
				<< "error at index i = " << i << " array 4\n";
			else if (a[i] != a5[i]) std::cout 
				<< "error at index i = " << i << " array 5\n";
			else if (a[i] != a6[i]) std::cout 
				<< "error at index i = " << i << " array 6\n";
			else if (a[i] != a7[i]) std::cout 
				<< "error at index i = " << i << " array 7\n";
			else if (a[i] != a8[i]) std::cout 
				<< "error at index i = " << i << " array 8\n";
	   }
	}

	/**
	 * Simple insertion sort.
	 */
	template <typename Comparable>
	void insertionSort( vector<Comparable> & a )
	{
		for( int p = 1; p < a.size( ); p++ )
		{
			Comparable tmp = a[ p ];
			//+1e
			 exch++;

			int j;
			for( j = p; j > 0 && tmp < a[ j - 1 ]; j-- )
			{
				//+1c
				comp++;
				a[ j ] = a[ j - 1 ];
				//+1e
				exch++;
			}
			//+1c
			comp++;
			a[ j ] = tmp;
			//+1e
			exch++;
		}
	}

	/**
	 * Shellsort, using Shell's (poor) increments.
	 */
	template <typename Comparable>
	void shellsort( vector<Comparable> & a )
	{
		for( int gap = a.size( ) / 2; gap > 0; gap /= 2 )
			for( int i = gap; i < a.size( ); i++ )
			{
				//+1e
				exch++;
				Comparable tmp = a[ i ];
				int j = i;

				for( ; j >= gap && tmp < a[ j - gap ]; j -= gap )
				{
					//+1c
					comp++;
					a[ j ] = a[ j - gap ];
					//+1e
					exch++;
				}
				//+1c
				comp++;
				//+1e
				exch++;
				a[ j ] = tmp;
			}
	}

	/**
	 * Shellsort, using Hibbard's increments.
	 */
	template <typename Comparable>
	void shellsort_hibbard( vector<Comparable> & a )
	{
		int gap;
		for( int k = 1; k < a.size() / 2; k++) 
		{
			gap = pow(2.0, k) - 1;
			for( int i = gap; i < a.size( ); i++ )
			{
				//+1e
				exch++;
				Comparable tmp = a[ i ];
				int j = i;

				for( ; j >= gap && tmp < a[ j - gap ]; j -= gap )
				{
					//+1c
					comp++;
					a[ j ] = a[ j - gap ];
					//+1e
					exch++;
				}
				//+1c
				comp++;
				//+1e
				exch++;
				a[ j ] = tmp;
			}
		}
	}

	/*
	 * Shellsort, using Sedgewick's increments.
	 */
	template <typename Comparable>
	void shellsort_sedgewick( vector<Comparable> & a )
	{
		int gap;
		for( int k = 0; 9 * pow(4.0, k) - 9 * pow(2.0, k) + 1
			<= a.size(); k++) 
		{
			gap = 9 * pow(4.0, k) - 9 * pow(2.0, k) + 1;
			for( int i = gap; i < a.size( ); i++ )
			{
				//+1e
				exch++;
				Comparable tmp = a[ i ];
				int j = i;

				for( ; j >= gap && tmp < a[ j - gap ]; j -= gap )
				{
					//+1c
					comp++;
					a[ j ] = a[ j - gap ];
					//+1e
					exch++;
				}
				//+1c
				comp++;
				//+1e
				exch++;
				a[ j ] = tmp;
			}

			k += 2;
			gap = pow(4.0, k) - 3 * pow(2.0, k) + 1;
			for( int i = gap; i < a.size( ); i++ )
			{
				//+1e
				exch++;
				Comparable tmp = a[ i ];
				int j = i;

				for( ; j >= gap && tmp < a[ j - gap ]; j -= gap )
				{
					//+1c
					comp++;
					a[ j ] = a[ j - gap ];
					//+1e
					exch++;
				}
				//+1c
				comp++;
				//+1e
				exch++;
				a[ j ] = tmp;
			}
			k -= 2;
		}
	}

	/**
	 * Standard heapsort.
	 */
	template <typename Comparable>
	void heapsort( vector<Comparable> & a )
	{
		for( int i = a.size( ) / 2; i >= 0; i-- )  /* buildHeap */
			percDown( a, i, a.size( ) );
		for( int j = a.size( ) - 1; j > 0; j-- )
		{
			//+3e
			exch += 3;
			swap( a[ 0 ], a[ j ] );                  /* deleteMax */
			percDown( a, 0, j );
		}
	}

	/**
	 * Internal method for heapsort.
	 * i is the index of an item in the heap.
	 * Returns the index of the left child.
	 */
	inline int leftChild( int i )
	{
		return 2 * i + 1;
	}

	/**
	 * Internal method for heapsort that is used in
	 * deleteMax and buildHeap.
	 * i is the position from which to percolate down.
	 * n is the logical size of the binary heap.
	 */
	template <typename Comparable>
	void percDown( vector<Comparable> & a, int i, int n )
	{
		int child;
		//+1e
		exch++;
		Comparable tmp;

		for( tmp = a[ i ]; leftChild( i ) < n; i = child )
		{
			//+1c
			comp++;
			child = leftChild( i );
			if( child != n - 1 && a[ child ] < a[ child + 1 ] )
				child++;
			//+1c
			comp++;
			if( tmp < a[ child ] )
			{
				//+1e
				exch++;
				a[ i ] = a[ child ];
			}
			else
				break;
		}
		a[ i ] = tmp;
		//+1e
		exch++;
	}

	/**
	 * Mergesort algorithm (driver).
	 */
	template <typename Comparable>
	void mergeSort( vector<Comparable> & a )
	{
		vector<Comparable> tmpArray( a.size( ) );

		mergeSort( a, tmpArray, 0, a.size( ) - 1 );
	}

	/**
	 * Internal method that makes recursive calls.
	 * a is an array of Comparable items.
	 * tmpArray is an array to place the merged result.
	 * left is the left-most index of the subarray.
	 * right is the right-most index of the subarray.
	 */
	template <typename Comparable>
	void mergeSort( vector<Comparable> & a,
				vector<Comparable> & tmpArray, int left, int right )
	{
		if( left < right )
		{
			int center = ( left + right ) / 2;
			mergeSort( a, tmpArray, left, center );
			mergeSort( a, tmpArray, center + 1, right );
			merge( a, tmpArray, left, center + 1, right );
		}
	}

	/**
	 * Internal method that merges two sorted halves of a subarray.
	 * a is an array of Comparable items.
	 * tmpArray is an array to place the merged result.
	 * leftPos is the left-most index of the subarray.
	 * rightPos is the index of the start of the second half.
	 * rightEnd is the right-most index of the subarray.
	 */
	template <typename Comparable>
	void merge( vector<Comparable> & a, vector<Comparable> & tmpArray,
			int leftPos, int rightPos, int rightEnd )
	{
		int leftEnd = rightPos - 1;
		int tmpPos = leftPos;
		int numElements = rightEnd - leftPos + 1;
		

		// Main loop
		while( leftPos <= leftEnd && rightPos <= rightEnd )
		{
			//+1c
			comp++;
			//+1e
			exch++;
			if( a[ leftPos ] <= a[ rightPos ] )
				tmpArray[ tmpPos++ ] = a[ leftPos++ ];
			else
				tmpArray[ tmpPos++ ] = a[ rightPos++ ];
		}
		while( leftPos <= leftEnd )    // Copy rest of first half
		{
			tmpArray[ tmpPos++ ] = a[ leftPos++ ];
			//+1e
			exch++;
		}
		while( rightPos <= rightEnd )  // Copy rest of right half
		{
			tmpArray[ tmpPos++ ] = a[ rightPos++ ];
			//+1e
			exch++;
		}

		// Copy tmpArray back
		for( int i = 0; i < numElements; i++, rightEnd-- )
		{
			a[ rightEnd ] = tmpArray[ rightEnd ];
			//+1e
			exch++;
		}
	}

	/**
	 * Quicksort algorithm (driver).
	 */
	template <typename Comparable>
	void quicksort( vector<Comparable> & a )
	{
		quicksort( a, 0, a.size( ) - 1 );
	}


	/**
	 * Return median of left, center, and right.
	 * Order these and hide the pivot.
	 */
	template <typename Comparable>
	const Comparable & median3( vector<Comparable> & a, int left, 
		int right )
	{
		//+3c
		comp += 3;
		int center = ( left + right ) / 2;
		if( a[ center ] < a[ left ] )
		{
			swap( a[ left ], a[ center ] );
			//+3e
			exch += 3;
		}
		if( a[ right ] < a[ left ] )
		{
			swap( a[ left ], a[ right ] );
			//+3e
			exch += 3;
		}
		if( a[ right ] < a[ center ] )
		{
			swap( a[ center ], a[ right ] );
			//+3e
			exch += 3;
		}

		//+1e
		exch++;
			// Place pivot at position right - 1
		swap( a[ center ], a[ right - 1 ] );
		return a[ right - 1 ];
	}

	/**
	 * Internal quicksort method that makes recursive calls.
	 * Uses median-of-three partitioning without a cut-off.
	 * a is an array of Comparable items.
	 * left is the left-most index of the subarray.
	 * right is the right-most index of the subarray.
	 */
	template <typename Comparable>
	void quicksort( vector<Comparable> & a, int left, int right )
	{
		//+1c
		comp++;
		if( left + 1 < right )
		{
			Comparable pivot = median3( a, left, right );

				// Begin partitioning
			int i = left, j = right - 1;
			for( ; ; )
			{
				//+2c
				comp += 2;
				while( a[ ++i ] < pivot ) { comp++; }
				while( pivot < a[ --j ] ) { comp++; }
				if( i < j )
				{
					swap( a[ i ], a[ j ] );
					//+3e
					exch += 3;
				}
				else
					break;
			}

			//+3e
			exch += 3;
			swap( a[ i ], a[ right - 1 ] );  // Restore pivot

			quicksort( a, left, i - 1 );     // Sort small elements
			quicksort( a, i + 1, right );    // Sort large elements
		}
		else  if (a[ right ] < a[ left ]) 
		{
			//+3e
			exch += 3;
			Comparable tmp = a[ right ];
			a[ right ] = a[ left ];
			a[ left ] = tmp;
		}
	}
	 
	/**
	 * Quicksort algorithm (driver).
	 */
	template <typename Comparable>
	void quicksort20( vector<Comparable> & a )
	{
		quicksort20( a, 0, a.size( ) - 1 );
	}

	/**
	 * Internal quicksort method that makes recursive calls.
	 * Uses median-of-three partitioning and a cutoff of 20.
	 * a is an array of Comparable items.
	 * left is the left-most index of the subarray.
	 * right is the right-most index of the subarray.
	 */
	template <typename Comparable>
	void quicksort20( vector<Comparable> & a, int left, int right )
	{
		if( left + 20 <= right )
		{
			Comparable pivot = median3( a, left, right );

				// Begin partitioning
			int i = left, j = right - 1;
			for( ; ; )
			{
				//+2c
				comp += 2;
				while( a[ ++i ] < pivot ) { comp++; }
				while( pivot < a[ --j ] ) { comp++; }
				if( i < j )
				{
					swap( a[ i ], a[ j ] );
					//+3e
					exch += 3;
				}
				else
					break;
			}

			//+3e
			exch += 3;
			swap( a[ i ], a[ right - 1 ] );  // Restore pivot

			quicksort20( a, left, i - 1 );     // Sort small elements
			quicksort20( a, i + 1, right );    // Sort large elements
		}
		else  // Do an insertion sort on the subarray
			insertionSort( a, left, right );
	}



	/**
	 * Quicksort algorithm (driver).
	 */
	template <typename Comparable>
	void quicksort10( vector<Comparable> & a )
	{
		quicksort10( a, 0, a.size( ) - 1 );
	}

	/**
	 * Internal quicksort method that makes recursive calls.
	 * Uses median-of-three partitioning and a cutoff of 10.
	 * a is an array of Comparable items.
	 * left is the left-most index of the subarray.
	 * right is the right-most index of the subarray.
	 */
	template <typename Comparable>
	void quicksort10( vector<Comparable> & a, int left, int right )
	{
		if( left + 10 <= right )
		{
			Comparable pivot = median3( a, left, right );

				// Begin partitioning
			int i = left, j = right - 1;
			for( ; ; )
			{
				//+2c
				comp += 2;
				while( a[ ++i ] < pivot ) { comp++; }
				while( pivot < a[ --j ] ) { comp++; }
				if( i < j )
				{
					swap( a[ i ], a[ j ] );
					//+3e
					exch += 3;
				}
				else
					break;
			}

			//+3e
			exch += 3;
			swap( a[ i ], a[ right - 1 ] );  // Restore pivot

			quicksort10( a, left, i - 1 );     // Sort small elements
			quicksort10( a, i + 1, right );    // Sort large elements
		}
		else  // Do an insertion sort on the subarray
			insertionSort( a, left, right );
	}

	/**
	 * Internal insertion sort routine for subarrays
	 * that is used by quicksort.
	 * a is an array of Comparable items.
	 * left is the left-most index of the subarray.
	 * right is the right-most index of the subarray.
	 */
	template <typename Comparable>
	void insertionSort( vector<Comparable> & a, int left, int right )
	{
		for( int p = left + 1; p <= right; p++ )
		{
			Comparable tmp = a[ p ];
			//+1e
			exch++;

			int j;
			for( j = p; j > 0 && tmp < a[ j - 1 ]; j-- )
			{
				//+1c
				comp++;
				a[ j ] = a[ j - 1 ];
				//+1e
				exch++;
			}
			//+1c
			comp++;
			a[ j ] = tmp;
			//+1e
			exch++;
		}
	}

};


#endif




