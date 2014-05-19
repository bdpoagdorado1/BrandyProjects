//  Author:  Brandy Poag
//  Due Date:  04/26/2010
//  Project No: 05
//  Description:  

/*******************************************************************
	This program takes an event node graph and calculates the
	earliest, and latest completion times as well as the slack
	time and finds all critical paths.  The program treats all
	nodes as if they were activities even though some nodes were
	created in the process of making the event node graph.
*******************************************************************/

//  Honor Statement: My signature below attests to the fact that 
//  I have neither given nor received aid on this project.


// ___________________________ (Signature)


#include <iostream>
#include <fstream>
#include "graph.h"


using namespace std;



    // Test program
int main( )
{
	int node;
	int edge;
	int x;
	int y;
	int z;

	ifstream inFile("data.txt");

	if(!inFile)
	{
		cout << "oops" << '\n';
		exit(1);
	}
	while(!inFile.eof())
	{
		inFile >> node;
		inFile >> edge;

		Graph m(node, edge);
 
		for (int i = 0; i <= edge; i++)
		{
			inFile >> x;
			inFile >> y;
			inFile >> z;

			m.build_list(x, y, z);
		}
		m.time(0, 0);
	}
	inFile.close();
		
    return 0;
}

