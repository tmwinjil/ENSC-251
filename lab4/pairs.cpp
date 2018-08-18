/**
* @file pairsdriver.cpp
* @author Takunda Mwinjilo
* @date 06/08/2018
* @version 1.0
*
* @brief <ENSC 251, Lab 1>
*
* This program contains the functional definitions of the class functions and overloaded operators
*
*/
#include <iostream>
using namespace std;
#include "pairs.h"

/*
*@brief No argument constructor of Pairs class
*/

Pairs::Pairs()
{
	f = 0;
	s = 0;
}

/*
*@brief Single argument constructor of Pairs class
*@param first represents the first of a pair of numbers
*/
Pairs::Pairs(int first)
{
	f = first;
	s = 0;
}

/*
*@brief Two argument constructor of Pairs class
*@param first represents the first number of the pair
*@param second represents the second number of the pair
*/
Pairs::Pairs(int first, int second)
{
    f = first;
    s = second;
}

/*
*@brief Overloaded + operator. Adds two pairs
*@param first is of type pairs and is the first pair in the + operation
*@param second is of type pairs and is the second pair in the + operation
*@return Pairs
*/
Pairs operator +(const Pairs first, const Pairs second)
{
	Pairs temp;
	temp.f = first.f+second.f;
	temp.s = first.s+second.s;
return temp;
}

/*
*@brief Overloaded - operator. Subtracts two pairs
*@param first is of type pairs and is the first pair in the - operation
*@param second is of type pairs and is the second pair in the - operation
*@return Pairs
*/
Pairs operator -(const Pairs first, const Pairs second)
{
	Pairs temp;
	temp.f = first.f - second.f;
    temp.s = first.s - second.s;
return temp;
}

/*
*@brief Overloaded * operator. Multiplies  set by a constant
*@param set is the pair of numbers to be multiplied by a constant
*@param c is an integer that will be multiplied with the pair
*@return Pairs
*/
Pairs operator *(const Pairs set, const int c)
{
	Pairs temp;
	temp.f = c * set.f;
    temp.s = c * set.s;
	return temp;
}

/*
*@brief Overloaded input operator
*@param ins represents the input stream
*@param second represents the pair being inputted to
*@return type istream
*/
istream& operator >>(istream& ins, Pairs& second)
{
	char extra = '\0';
		
	while(1)	//infinite loop till correct input
	{
		if(!(ins>>second.f>>extra>>second.s) || extra != ',')
		{
			cerr<<"Not in correct format"<<endl
			<<"format is <inetger> , <integer>"<<endl;
			ins.clear();
			ins.ignore(256,'\n');
			cout<<"please re-input"<<endl;
		}
		else
		{
			break;
		}
	}
	return ins;
}

/*
*@brief Overloaded output operator
*@param outs represents the output stream
*@param second represents the pair being outputted to
*@return type ostream
*/
ostream& operator <<(ostream& outs, const Pairs& second)
{
	outs<<"("<<second.f<<","<<second.s<<")";
	return outs;
}
