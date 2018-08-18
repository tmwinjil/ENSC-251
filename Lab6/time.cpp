/**
* @file time.cpp
* @author TAKUNDA MWINJILO
* @Date 06/27/2018
* @version 1.0
* @section Program that takes the current time in 24-hour notation and returns the 12-hour notation
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ TAKUNDA MWINJILO ____ _____06/27/2018______________
//
// ____ 301344066______
//

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class TimeFormatMistake
{
public:
//CONSTRUCTORS:

	TimeFormatMistake();
//Blank constructor signifying error in input types 

TimeFormatMistake(int h, int m);
//Constructor with erraneous values of hours and minutes

//ACCESSORS:
string getError();
// returns the correct error message to the required input
private:
int hours;
int mins;
string error;
};


int main()
{
int hours = -1;
int mins = -1;
char colon= '\0';
char again = '\0';
string suffix = "AM";

while(1)
{
	try
	{
		cout<<"Enter time in 24-hour: "<<endl;
		cin>>hours>>colon>>mins;

		if(!cin)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			throw TimeFormatMistake();
		}
		else if(hours > 24 || hours < 0 || mins > 59 || mins < 0)
		{
                        cin.clear();
                        cin.ignore(1000,'\n');
			throw TimeFormatMistake(hours,mins);		

		}
	}
	catch(TimeFormatMistake e)
	{
		cout<<e.getError()<<endl;
		cout<<"Try again"<<endl<<endl;
		continue;
	}
	catch(...)
	{
		cout<<"ERROR IN PROCESSING. PLEASE TRY AGAIN"<<endl<<endl;
	}

	if(hours > 12 && hours < 24)
	{
		hours -= 12;
		suffix = "PM";
	}
	else if (hours == 24)
		hours = 0;
	else if(hours == 12)
		suffix = "PM";

	cout.fill('0');
	cout<<"That is the same as: "<<endl
		<<setw(2)<<hours<<":"
		<<setw(2)<<mins<<" "<<suffix<<endl;
	cout<<"Again?(y/n)"<<endl;
	cin>>again;
	if(again == 'y' || again == 'Y')
		continue;

	else if(again == 'n' || again == 'N')
		break;

	else
	{
		cout<<"I'll take that as a No"<<endl;
		break;
	}
	

}

cout<<"End of Program"<<endl;
return 1;
}

/*
*@brief Blank constructor that sets error message to show input was of wrong type i.e not <int>:<int>
*/
TimeFormatMistake::TimeFormatMistake()
{
hours = -1;
mins = -1;
error ="Your input was not understood. Please use correct notation";
}

/*
*@brief Constructor which takes in out of range values and produces correct error message
*@param h represents the out of range hours
*@param m represents the out of range minutes
*/
TimeFormatMistake::TimeFormatMistake(int h, int m)
{
hours = h;
mins = m;
error = "There is no such time as " + to_string(hours) + ":" + to_string(mins);
}

/*
*@brief Function that returns the type of error found by the code
*@param returns string
*/
string TimeFormatMistake::getError()
{
return error;
}
