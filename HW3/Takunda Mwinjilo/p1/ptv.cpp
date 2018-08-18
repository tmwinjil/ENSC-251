#include<iostream>
#include<string>
using namespace std;
#include "ptv.h"

//IMPLEMENTATION OF PERSON CLASS
/*
*@brief Blank constructor. Creates Blank Person object
*/
Person::Person()
{
	name = " ";
}

/*
*@brief Single argument constructor. Creates Person object with specified name
*@param theNmae is the name to be assigned to the person
*/
Person::Person(string theName)
{
	name = theName;
}

/*
*@brief Copy constructor for class Person. Copies the Person to another object
*/
Person::Person(const Person& theObject)
{
	name = theObject.name;
}
/*
*@brief Accessor to obtain person name
*/
string Person::getName() const
{
	return name;
}
/*
*@brief Copy assignemnt to copy the value of the person on the right to the one on the left
*/
Person& Person::operator = (const Person& rtSide)
{
	if(this != &rtSide)
	{
		this->name = rtSide.name;
	}
	return *this;
	
}

/*
*@brief Overloaded input assignment operator. Assigns value in inStream to properties in personObject
*/
istream& operator >>(istream& inStream,Person& personObject)
{
string holder= " ";
bool wrongInput;
do
{
	wrongInput = 0;
	inStream>>holder;
	for (int i = 0; i < holder.length();i ++)
	{
		if(isalpha(holder[i]) == 0)
		{
		cout<<"Name not valid. Enter again"<<endl;
		inStream.clear();
		inStream.ignore(256,'\n');
		wrongInput=1;
		break;
		} 
	}
}while(wrongInput == 1);

personObject.name = holder;
return inStream;
}

/*
*@brief Overloaded output operator to output all properties of Person
*/
ostream& operator <<(ostream& outStream,const Person& personObject)
{
outStream<<"Person: "<<personObject.name; 
return outStream;
}

//IMPLEMENTATION OF VEHICLE CLASS

//No parameter constructor to initialize new Vehicle object
Vehicle::Vehicle()
{
	manufacturer = " ";
	cylinders = 0;
	Person p(" ");
	owner = p;
}

/*
*@brief Constructor to produce object with specified properties
*@param manu holds the manufacturer name
*@param cyl holds the number of cylinders
*@param ownedBy holds the name of the owner
*/
Vehicle::Vehicle(string manu, int cyl,string ownedBy)
{
	manufacturer = manu;
	cylinders = cyl;
	Person p(ownedBy);
	owner = p;
}

/*
*@brief Constructor to produce object with specified properties
*@param manu holds the manufacturer name
*@param cyl holds the number of cylinders
*@param ownedBy holds the Person object who owns the vehicle
*/
Vehicle::Vehicle(string manu, int cyl, Person ownedBy)
{
	manufacturer = manu;
	cylinders = cyl;
	owner = ownedBy;
}

//Copy constructor
Vehicle::Vehicle(const Vehicle& vObject)
{
	manufacturer = vObject.manufacturer;
	cylinders = vObject.cylinders;
	owner = vObject.owner;
}

//Accessors
string Vehicle::getManufacturer()
{
	return manufacturer;
}
int Vehicle::getCylinders()
{
	return cylinders;
}
string Vehicle::getOwner()
{
	return owner.getName();
}

//Copy assignment 
Vehicle& Vehicle::operator = (const Vehicle& rtSide)
{
	if(this != &rtSide)
	{
		this->manufacturer = rtSide.manufacturer;
		this->cylinders = rtSide.cylinders;
		this->owner = rtSide.owner;
	}
	return *this;
}
    
//Overloaded operators
ostream& operator <<(ostream& outStream,const Vehicle& theObject)
{
	outStream<<"Manufacturer: "<<theObject.manufacturer<<endl
			<<"Number of cylinders: "<<theObject.cylinders<<endl
			<<"Owner Name: "<<theObject.owner<<endl;
	return outStream;
}

//Mutators
void Vehicle::setManufacturer(string manu)
{
	manufacturer = manu;
}
void Vehicle::setCylinders(int cyl)
{
	cylinders = cyl;
}
void Vehicle::setOwner(string ownedBy)
{
	Person p(ownedBy);
	owner = p;
}
void Vehicle::setOwner(Person ownedBy)
{
	owner = ownedBy;
}


//IMPLEMENTATION OF TRUCK CLASS

//Constructors
Truck::Truck()
{
	manufacturer = " ";
	cylinders = 0;
	Person p(" ");
	owner = p;
	loadCapacity = 0;
	towingCapacity = 0;
}

/*
*@brief Constructor to produce object with specified properties
*@param manu holds the manufacturer name
*@param cyl holds the number of cylinders
*@param ownedBy holds the name of the owner
*@param load holds the load capacity of the truck
*@param tow holds the towing capacity of the truck
*/
Truck::Truck(string manu, int cyl, string ownedBy, double load, int tow)
{
	manufacturer = manu;
	cylinders = cyl;
	Person p(ownedBy);
	owner = p;
	loadCapacity = load;
	towingCapacity = tow;
}

/*
*@brief Constructor to produce object with specified properties
*@param manu holds the manufacturer name
*@param cyl holds the number of cylinders
*@param ownedBy holds the Person object owner
*@param load holds the load capacity of the truck
*@param tow holds the towing capacity of the truck
*/
Truck::Truck(string manu, int cyl, Person ownedBy, double load, int tow)
{
	manufacturer = manu;
	cylinders = cyl;
	owner = ownedBy;
	loadCapacity = load;
	towingCapacity = tow;
}

/*
*@brief Constructor to produce a truck object from a vehicle object with specified properties
*@param load holds the load capacity of the truck
*@param tow holds the towing capacity of the truck
*/
Truck::Truck(Vehicle& v, double load, int tow)
{
	manufacturer = v.getManufacturer();
	cylinders = v.getCylinders();
	Person p(v.getOwner());
	owner = p;
	loadCapacity = load;
	towingCapacity = tow;
}

//Copy constructor
Truck::Truck(const Truck& truckObject)
{
	manufacturer = truckObject.manufacturer;
	cylinders = truckObject.cylinders;
	owner = truckObject.owner;
	loadCapacity = truckObject.loadCapacity;
	towingCapacity = truckObject.towingCapacity;
}

//Accessors
double Truck::getLoadC()
{
	return loadCapacity;
}
int Truck::getTowingC()
{
	return towingCapacity;
}

//Overloaded operators
Truck& Truck::operator = (const Truck& rtSide)
{
	if(this != &rtSide)
	{
		this->manufacturer = rtSide.manufacturer;
		this->cylinders = rtSide.cylinders;
		this->owner = rtSide.owner;
		this->loadCapacity = rtSide.loadCapacity;
		this->towingCapacity = rtSide.towingCapacity;
	}
	return *this;
}
ostream& operator <<(ostream& outStream,const Truck& truckObject)
{
	outStream<<"Manufacturer: "<<truckObject.manufacturer<<endl
			<<"Number of cylinders: "<<truckObject.cylinders<<endl
			<<"Owner Name: "<<truckObject.owner<<endl
			<<"LoadCapacity: "<<truckObject.loadCapacity<<endl
			<<"Towing Capacity: "<<truckObject.towingCapacity<<endl;
	return outStream;
}

//Mutators
void Truck::setLoad(double load)
{
	loadCapacity = load;
}
void Truck::setTow(int tow)
{
	towingCapacity = tow;
}
