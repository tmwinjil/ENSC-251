/**
* @file stack.cpp
* @author TAKUNDA MWINJILO
* @Date 07/05/2018
* @version 1.0
* @section Implementation of the Stack, StackOverFlowException and StackEmptyException classes
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


//Stack implementation

//Constructor that produces new stack with maximum size as stated
Stack::Stack(int size) : top(NULL)
{
maxSize = size;
currentSize = 0;
}

//copy constructor
Stack::Stack(const Stack& aStack)
{
}

//Destructor
Stack::~Stack()
{
while(! empty())
pop();
}

//Pushes element into stack. Throws StackOverFlowException if stack is at maximum size
void Stack::push(char element)
{
if (currentSize == maxSize)
{
	throw StackOverflowException(maxSize);
	exit(1);
}
StackNodePtr tempPtr = new Node;
if(currentSize == 0)
{
	tempPtr->data = element;
	tempPtr->link = NULL;
	top = tempPtr;
}
else
{
	tempPtr->data = element;
	tempPtr->link = top;
	top = tempPtr;
}
currentSize ++;
cout<<"'"<<element<<"' has been added to the stack"<<endl;
}

//Pops element from stack. Throws StackEmptyException if stack empty  
void Stack::pop()
{
if (empty())
{
	throw StackEmptyException();
	exit(1);
}

char result = top->data;

StackNodePtr tempPtr;
tempPtr = top;
top = top->link;
currentSize --;

delete tempPtr;
cout<<"'"<<result<<"' has been popped from the stack"<<endl;

}

//Checks if Stack is empty
bool Stack::empty() const
{
return (currentSize == 0);
}



// StackOverflowException Implementation

//Constrcutor to produce relevent error message
StackOverflowException::StackOverflowException(int max)
{
	message = "STACK FULL.ELEMENT WAS NOT ADDED. CANNOT EXCEED MAXIMUM STACK SIZE OF " + to_string(max);
}

//Collects error message
string StackOverflowException::getMessage()
{
	return message;
}


//StackEmptyException Implementation

//Produces relevent error message
StackEmptyException::StackEmptyException()
{
	message = "STACK EMPTY. CANNOT POP ANY MORE ITEMS";
}

//Collects error message
string StackEmptyException::getMessage()
{
	return message;
}



