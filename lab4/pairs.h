/**
* @file pairs.h
* @author Takund Mwinjilo
* @date 06/08/2018
* @version 1.0
*
* @brief <ENSC 251, Lab 4>
*
* The header file containing initial definitions for the class type
*
*/

#ifndef PAIRS_H
#define PAIRS_H

#include <iostream>
using namespace std;

class Pairs
{
public:
//Constructors
Pairs( );
Pairs(int first);
Pairs(int first, int second);
//Overloaded operators
friend Pairs operator +(const Pairs first, const Pairs second);
friend Pairs operator -(const Pairs first, const Pairs second);
friend Pairs operator *(const Pairs set, const int c);
friend istream& operator >>(istream& ins, Pairs& second);
friend ostream& operator <<(ostream& outs, const Pairs& second);
private:
int f;
int s;
};
#endif
