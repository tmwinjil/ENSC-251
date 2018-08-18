/**
* @file stack.h
* @author TAKUNDA MWINJILO
* @Date 07/05/2018
* @version 1.0
* @section Header file contining all structure and class definitions related to the Stack class
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ TAKUNDA MWINJILO ____ _____07/05/2018______________
//
// ____ 301344066_____
//

#ifndef STACK_H
#define STACK_H

//Node definition
struct Node
{
char data;
Node* link;
};
typedef Node* StackNodePtr;

//Stack definition
class Stack
{
public:
Stack(int size);
//Precondition: size in a positive integer
//initializes teh object to an empty stack of whatever size is specified

Stack(const Stack& aStack);
//copy constructor

~Stack();
//Destroys stack and retruns all memory to freestore

void push(char element);
//Precondition: Stack is not at max size.
//Postcondition: element has been added to the stack

void pop();
//Precondition: Stack is not empty. If stack is empty throws StackEmptyException
//Returns the top element on the stack and removes that element from the stack

bool empty() const;
//Returns True if stack is empty. Returns False otherwise

private:
StackNodePtr top;
int currentSize;
int maxSize;
};

//StackEmptyException Class
class StackEmptyException
{
public:
StackEmptyException();
//Creates Relevent error message

string getMessage();
//Collects error message for output

private:
string message;
};

// StackOverflowException Class
class StackOverflowException
{
public:
StackOverflowException(int max);
//Creates Relevent error message

string getMessage();
//Collect error message for output

private: 
string message;
};
#endif



