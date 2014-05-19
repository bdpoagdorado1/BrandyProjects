#include <iostream>
#include <exception>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


#ifndef POSTFIX_H
#define POSTFIX_H

class POSTFIX
{
public:
	int priority( char c)
	{
		switch(c)
		{
		case '(':	return 0;
		case '+':	
		case '-':	return 1;
		case '/':	
		case '*':	
		case '%':	return 2;
		case '^':	return 3;
		default:	{
						std::cout << "Error in priority\n";
						return -1;
					}
		}
	}
	void evaluate( const vector<string> & vec )
	{
		std:: vector <string> stack;
		for (size_t i = 0; i < vec.size(); i++) 
		{
			string theStr = vec[i];

			if (theStr[0] == '+' || theStr[0] == '-' || theStr[0] == '*'
				|| theStr[0] == '/' || theStr[0] == '%' ||  theStr[0] == '^')
			{
				string strx = stack[stack.size()-1];
				int x = std::atoi( strx.c_str() );
				stack.pop_back();
				string stry = stack[stack.size()-1];
				int y = std::atoi( stry.c_str() );
				stack.pop_back();
				int n = 0;
				string newString;
				char c = theStr[0];
				switch(c)
				{
				case '+':	{
								n = y + x;
								std::ostringstream stm;
								stm << n;
								newString = stm.str() ;
								break;
							}
				case '-':	{
								n = y - x;
								std::ostringstream stm;
								stm << n;
								newString = stm.str() ;
								break;
							}
				case '/':	{
								if (x == 0) throw std::exception("Error division by zero!");
								n = y / x;
								std::ostringstream stm;
								stm << n;
								newString = stm.str() ;
								break;
							}
				case '*':	{
								n = y * x;
								std::ostringstream stm;
								stm << n;
								newString = stm.str() ;
								break;
							}
				case '%':	{
								n = y % x;
								std::ostringstream stm;
								stm << n;
								newString = stm.str() ;
								break;
							}
				case '^':	{
								n = y ^ x;
								std::ostringstream stm;
								stm << n;
								newString = stm.str() ;
								break;
							}
				default:	{
								std::cout << "Error in computation\n";
								break;
							}
				}
				stack.push_back(newString);
			}
			else stack.push_back(theStr);
		}
		string stry = stack[stack.size()-1];
		int y = std::atoi( stry.c_str() );
		std::cout << "answer: " << y << '\n';
	}

	void compute_postfix( const vector<string> & vec )
	{
		std:: vector <char> stack;
		std:: vector <std::string> display;
		int i = 0;
		while (i != vec.size())
		{
			string theStr = vec[i];
			if (theStr[0] == '(') stack.push_back(theStr[0]);
			else if (theStr[0] == ')')
			{
				while(stack[stack.size()-1] != '(')
				{
					stringstream ss;
					string s;
					char c = stack[stack.size()-1];
					ss << c;
					ss >> s;
					display.push_back(s);
					stack.pop_back();
				}    
				stack.pop_back();
			}
			else if (theStr[0] == '+' || theStr[0] == '-' || theStr[0] == '*'
				|| theStr[0] == '/' || theStr[0] == '%' ||  theStr[0] == '^')
			{
				if (stack.empty()) stack.push_back(theStr[0]);
				else
				{
					while (!stack.empty()) 
					{
						if (priority(theStr[0]) <= priority(stack[stack.size()-1]))
						{
							stringstream ss;
							string s;
							char c = stack[stack.size()-1];
							ss << c;
							ss >> s;
							display.push_back(s);
							stack.pop_back();
						}
						else break;
					}
					stack.push_back(theStr[0]);
				}
			}
			else display.push_back(theStr);
			++i;
		}
		while (stack.size() != 0)
		{
			stringstream ss;
			string s;
			char c = stack[stack.size()-1];
			ss << c;
			ss >> s;
			display.push_back(s);
			stack.pop_back();
		}
		std::cout << "postfix: ";
		for (size_t j = 0; j < display.size(); j++)
		{
			std::cout << display[j];
		}
		std::cout << '\n';
		evaluate(display);
		return;
	}

	void infix( string str )
	{
		std:: vector <std::string> str2;

		bool num = true;
		bool paren = false;
		//convert str to vector of strings 
		//check for a malformed expression
		for (size_t i = 0; i < str.size(); i++)
		{
			string str1;
			str1.clear();
			if ( (!num) && ( str[i] == '+' ||
				str[i] == '-' || str[i] == '*' || str[i] == '/' ||
				str[i] == '%' ||  str[i] == '^'))
			{
				str1.assign(1, str[i]);
				str2.push_back(str1);
				num = true;
			}
			else if ( str[i] == '(' )
			{
				str1.assign(1, str[i]);
				str2.push_back(str1);
				if (!paren) paren = true;
				else paren = false;
			}
			else if ( str[i] == ')' )
			{
				if ( paren ) paren = false;
				else paren = true;
				str1.assign(1, str[i]);
				str2.push_back(str1);
			}
			else if (num && str[i] >= 48 && str[i] <= 57)
			{
				while (num && str[i] >= 48 && str[i] <= 57)
				{
					str1.append(1, str[i]);
					++i;
				}
				--i;
				str2.push_back(str1);
				num = false;
			}
			else if(str[i] != ' ' )
			{
				for (size_t j = 0; j < str2.size(); j++)
				{
					std::cout << str2[j];
				}
				std::cout << "\nERROR improperly formed expression!: \n";
				std::cout << "expression: " << str << '\n';
				return;
			}
		}
		if( paren )
		{
			for (size_t j = 0; j < str2.size(); j++)
			{
				std::cout << str2[j];
			}
			std::cout << "\nERROR improperly formed expression! paren : \n";
			std::cout << "expression: " << str << '\n';
			return;
		}
		std::cout << "expression: ";
		for (size_t j = 0; j < str2.size(); j++)
		{
			std::cout << str2[j];
		}
		std::cout << '\n';
		compute_postfix(str2);


		return;
	}
};

#endif


