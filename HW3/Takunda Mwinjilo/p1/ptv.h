/**
* @file ptv.h
* @author Takunda MWinjilo
* @Date 07/04/2018
* @version 1.0
* @section Header file for the classes Person, Vehicle and the derived class Truck
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Takunda Mwinjilo ____ _____07/04/2018______________
//
// ___301344066__

#ifndef PTV_H
#define PTV_H
#include<iostream>
#include<string>
using namespace std;
class Person
{
public: 
//Constructors
Person();
Person(string theName);
Person(const Person& theObject);
//Accessors
 string getName() const;
//Overloaded operators
Person& operator = (const Person& rtSide);
friend istream& operator >>(istream& inStream,Person& personObject);
friend ostream& operator <<(ostream& outStream,const Person& personObject);

private:
 string name;
};

//Vehicle base class
class Vehicle
{
public:
//Constructors
	Vehicle();
	Vehicle(string manu, int cyl,string ownedBy);
	Vehicle(string manu, int cyl, Person ownedBy);
	Vehicle(const Vehicle& vObject);


 //Accessors
string getManufacturer();
int getCylinders();
string getOwner();

//Mutators
void setManufacturer(string manu);
void setCylinders(int cyl);
void setOwner(string ownedBy);
void setOwner(Person ownedBy);


//Overloaded operators

Vehicle& operator = (const Vehicle& rtSide);
friend ostream& operator <<(ostream& outStream,const Vehicle& theObject);

protected:
string manufacturer;
int cylinders;
Person owner;
};

//Truck derived class
class Truck: public Vehicle
{
public:
//Constructors
Truck();
Truck(string manu, int cyl, string ownedBy, double load, int tow);
Truck(string manu, int cyl, Person ownedBy, double load, int tow);
Truck(Vehicle& v, double load, int tow);
Truck(const Truck& truckObject);

//Accessors
double getLoadC();
int getTowingC();

//Overloaded operators
Truck& operator = (const Truck& rtSide);
friend ostream& operator <<(ostream& outStream,const Truck& truckObject);

//Mutators
void setLoad(double load);
void setTow(int tow);


private:
double loadCapacity;
int towingCapacity;
};
#endif
