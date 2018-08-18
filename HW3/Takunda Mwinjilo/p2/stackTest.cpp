/**
* @file stackTest.cpp
* @author TAKUNDA MWINJILO
* @Date 07/05/2018
* @version 1.0
* @section Test Driver program for Stack class and its exceptions and implementation
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ TAKUNDA MWINJILO ____ _____07/05/2018______________
//
// ____ 301344066_____
//
#include<iostream>
#include<string>
using namespace std;
#include "stack.h"

int main()
{
	char choice = '\0';
	int size = 0;
	bool done = 0;
	char element;

	while(1)
	{
		cout<<"Please enter the maximum size of your stack"<<endl;
		if(!(cin>>size))
		{
			cout<<"Integer values only"<<endl;
		}
		else if (size <= 0)
		{
			cout<<"Cannot create a stack of this size"<<endl;
		}
		else
			break;

		cin.clear();
		cin.ignore(256,'\n');
	}

	Stack s(size);
	cout<<"Stack has been created"<<endl
		<<"Press 1 to add to stack"<<endl
		<<"Press 2 to remove from stack"<<endl
		<<"Press 3 to empty Stack"<<endl
		<<"Press 4 to end the program"<<endl;

	while (done == 0)
	{
		cout<<"Please enter a choice"<<endl;
		try
		{
			cin>>choice;
			switch (choice)
			{
				case '1':	
					cout<<"Enter an element to add"<<endl;
					cin>>element;
					s.push(element);
					break;

				case '2':	
					s.pop();
					break;

				case '3':	
					s.empty();
					cout<<"StackEmptied"<<endl;
					break;

				case '4':	
					done = 1;
					break;

				default:
					cout<<"Please use one of the 4 options"<<endl;
					cin.clear();
					cin.ignore(256,'\n');
			}

		}
		catch(StackOverflowException e1)
		{
			cout<<e1.getMessage()<<endl;
			cin.clear();
			cin.ignore(256,'\n');
		}
		catch(StackEmptyException e2)
		{
			cout<<e2.getMessage()<<endl;
			cin.clear();
			cin.ignore(256,'\n');
		}
		catch(...)
		{
			cout<<"Something went wrong"<<endl;
			cin.clear();
			cin.ignore(256,'\n');
		}
	}

	cout<<"TEST COMPLETE"<<endl;
	return 1;

}