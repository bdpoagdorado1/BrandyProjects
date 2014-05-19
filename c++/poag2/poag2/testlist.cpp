#include <iostream>
#include <fstream>
#include <exception>
#include "list.h"

using namespace std;

int main()
{
	try
	{
		List< int > list1;
		List< int > list2;
		int x;
		ifstream inFile("data.txt");
		if(!inFile)
		{
			cout << "oops" << '\n';
			exit(1);
		}
		while(!inFile.eof())
		{
			inFile >> x;
			switch(x)
			{
			case 1:	{
						inFile >> x;
						if (x == 1)
						{
							inFile >> x;
							list1.push_front(x);
						}
						else
						{
							inFile >> x;
							list2.push_front(x);
						}
				break;
					}
			case 2:	{
						inFile >> x;
						if (x == 1)
						{
							inFile >> x;
							list1.push_back(x);
						}
						else
						{
							inFile >> x;
							list2.push_back(x);
						}
				break;
					}
			case 3:	{
						inFile >> x;
						if (x == 1)
						{
							list1.pop_back();
						}
						else
						{
							list2.pop_back();
						}
				break;
					}
			case 4:	{
						inFile >> x;
						if (x == 1)
						{
							list1.pop_front();
						}
						else
						{
							list2.pop_front();
						}
				break;
					}
			case 5:	{
						inFile >> x;
						if (x == 1)
						{
							inFile >> x;
							list1.insert_inorder(x);
						}
						else
						{
							inFile >> x;
							list2.insert_inorder(x);
						}
				break;
					}
			case 6:	{
						inFile >> x;
						if (x == 1)
						{
							list2.merge( list1 );
						}
						else
						{
							list1.merge( list2 );
						}	
				break;
					}
			case 7:	{
						inFile >> x;
						if (x == 1)
						{
							inFile >> x;
							std::cout << "value: " << x << "  occurrences: " << list1.countOcc(x) << '\n';
						}
						else
						{
							inFile >> x;
							std::cout << "value: " << x << "  occurrences: " << list2.countOcc(x) << '\n';
						}
				break;
					}
			case 8:	{
						inFile >> x;
						if (x == 1)
						{
							inFile >> x;
							list1.removeAll(x);
						}
						else
						{
							inFile >> x;
							list2.removeAll(x);
						}
				break;
					}
			case 9:	{
						inFile >> x;
						if (x == 1)
						{
							list1.print();
						}
						else
						{
							list2.print();
						}
				break;
					}
			case 10:{
						inFile >> x;
						if (x == 1)
						{
							list1.sort();
						}
						else
						{
							list2.sort();
						}
				break;
					}
			case 11:{
						inFile >> x;
						if (x == 1)
						{
							list1.reverse();
						}
						else
						{
							list2.reverse();
						}
				break;
					}
			default:  break;
			}
		}
		inFile.close();
		
	}
	catch( std::exception & e )
	{
		std::cout << "caught ... " << e.what() << "\n";
	}
	return 0;
}