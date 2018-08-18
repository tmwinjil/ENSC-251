/**
* @file pairsdriver.cpp
* @author Takunda Mwinjilo
* @date 06/08/2018
* @version 1.0
*
* @brief <ENSC 251, Lab 1>
*
* This is the driver program for the "Pairs" class type displaying the capabilities of the overloaded operators
*
*/
#include <iostream>
using namespace std;
#include "pairs.h"


int main()
{
	Pairs a;
	Pairs b;
	int c;

	cout<<"The Pairs class can be intialized in 3 ways"<<endl
		<<"1)Firstly by way of a no argument constructor"<<endl
		<<"2)By way of a single argument constructor"<<endl
		<<"3)By way of a 2 argument constructor"<<endl;

	cout<<"Since we cannot test the constructors we will test the input, output, '+', '-'and '*' operators"<<endl<<endl;
	cout<<"First enter the first pair in the format <integer>,<integer>"<<endl;
	cin>>a;
	cout<<"Now enter the next pair in the same format"<<endl;
	cin>>b;
	cout<<"Now enter a regular integer value"<<endl;
	cin>>c;

	cout<<"Now the operations"<<endl;
	cout<<"Addition"<<endl
		<<a<<" + "<<b<<" = "<<a + b<<endl;
	
        cout<<"Subtraction"<<endl
            <<a<<" - "<<b<<" = "<<a - b<<endl;
   
        cout<<"Multiplication"<<endl
            <<c<<" * "<<a<<" = "<<a * c<<endl;
	cout<<"THIS DEMO IS NOW OVER";

	return 1;
}
