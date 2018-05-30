/**
 * @file rps.cpp
 * @author Takunda Mwinjilo
 * @date   05/31/2018
 * @version 2.0
 *@brief <ENSC 251, Lab 2>
 * @section Program which allows a user to enter their rating of a certain movie displayed to them 
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ TAKUNDA MWINJILO ____      _____05/31/2018______________
//
// ____ 301344066______

#include <iostream>
#include <string>

using namespace std;

class Movie
{
public:

	void createMovie(string name, string age_restriction);

	void addRating();

	void getAverage();
	
	
private:
	string movieName;
	string ageRating;
	int movieRating[5];



};

int main()
{

}

/**
*@brief
*@param
*/
void Movie::createMovie(string name, string age_restriction)
{
	movieName=name;

	

	ageRating=age_restriction;
}

void Movie::addRating()
{
	int rating = 0;
	bool correct = 0;

	cout<<"How would you rate "<<movieName<<"?"<<endl
		<<"1-Terrible"<<endl
		<<"2-Bad"<<endl
		<<"3-OK"<<endl
		<<"4-Good"<<endl
		<<"5-Great"<<endl;

	while(correct == 0)
	{
		if(!(cin>>rating))
		{
			cerr<<"Please enter a digit from one of the choices"<<endl<<endl;
			cin.clear;
			cin.ignore(256,'\n');
		}
		
		if (rating == 1 | rating == 2 | rating == 3 | rating == 4 | rating == 5)
		{
			correct = 1;
		}
		else
		{
			cerr<<"Please pick one of the digits on the list"<<endl<<endl;
			cin.clear();
			cin.ignore(256,'\n');
		}

	}

	movieRating[rating] += 1;


}

void Movie::getAverage()
{
	int points = 0;
	int votes = 0;
	int average = 0;

	for (int i = 1;i <= 5;i ++)
	{
	points += i * movieRating[i-1];
	votes += movieRating[i-1];
	}

	average = points / votes;

	cout<<"The average rating for this movie is: "<<average
		<<" After "<<votes<<" votes"<<endl;

}



