//  Author:  Brandy Poag
//  Due Date:  02/28/2010
//  Project No: 03
//  Description:  This takes an infix expression and converts it to
//  a postfix expression and then evaluates the expression.

//  Honor Statement: My signature below attests to the fact that I have 
//  neither given nor received aid on this project.


// ___________________________ (Signature)

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include "postfix.h"
using namespace std;

int main()
{
	try
	{
		POSTFIX pos0;
		//string s;
		///
	
		string s = "5 + 4 * 5 + (6 / 2)";
		pos0.infix(s);
/*
		ifstream inFile("data.txt");
		if(!inFile)
		{
			cout << "oops" << '\n';
			exit(1);
		}
		while(!inFile.eof())
		{
			getline(inFile, s);
			pos0.infix(s);
		}
		inFile.close();
*/
		
	}
	catch( std::exception & e )
	{
		std::cout << "caught ... " << e.what() << "\n";
	}
	return 0;
}