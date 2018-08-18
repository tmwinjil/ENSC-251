/**
* @file car.cpp
* @author Takunda MWinjilo
* @Date 01/06/2018
* @version 1.0
* @section Creates class Car and tests the acceleration and brake functions 5 times each
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Takunda Mwinjilo ____ _____06/01/2018______________
//
// __

#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	Car(int year,string type);

	int getYearModel();
	string getMake();
	int getSpeed();

	void accelerate();
	void brake();

private:
	int yearModel;
	string make;
	int speed;

};

int main()
{
	Car audiA4(2017,"Audi A4");
	
	cout<<"Commencing acceleration and deceleration test"<<endl;
	cout<<"initial speed = "<<audiA4.getSpeed()<<endl;

	for(int i = 1;i <= 5;i ++)
	{
		audiA4.accelerate();
		cout<<"t= "<<i<<":   speed = "<<audiA4.getSpeed()<<"km/h"<<endl;
	}

	
        for(int j = 1;j <= 5;j ++)
        {
                audiA4.brake();
                cout<<"t= "<<j+5<<":   speed = "<<audiA4.getSpeed()<<"km/h"<<endl;
        }
	cout<<"Test Over"<<endl;
return 1;
}
//Constructor
Car::Car(int year, string type)
{
	yearModel=year;
	make=type;
	speed=0;
}
//Accessors for Car
 int Car::getYearModel()
{
	return yearModel;
}
 string Car::getMake()
{
	return make;
}
 int Car::getSpeed()
{
	return speed;
}

//Mutators
 void Car::accelerate()
{
	speed += 5;
}

 void Car::brake()
{
        speed -= 5;
}
