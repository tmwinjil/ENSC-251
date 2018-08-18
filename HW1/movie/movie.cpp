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

	Movie(string name, string age_restriction);
	//Creates a movie object with then name and age restriction defined by the programmer

	void addRating(int rating);
	//Adds a users rating to the list of ratings

	void getAverage();
	//gets the average rating of the the movie object	
	
	string getName();
private:

	string movieName;
	string ageRating;
	int movieRating[5];
};

void getUserRating(Movie film,int& rating);

int main()
{
	int userRating=0;

	Movie DeadPool2("DeadPool 2","R-18");
	Movie ThorRagnarok("Thor Ragnarok", "PG-13");

	cout<<"We will start with movie 1"<<endl;
	getUserRating(DeadPool2,userRating);
	DeadPool2.addRating(userRating);
	DeadPool2.getAverage();

	cout<<"We will start with movie 2"<<endl;
        getUserRating(ThorRagnarok,userRating);
        ThorRagnarok.addRating(userRating);
	ThorRagnarok.getAverage();
}	

/**
*@brief This function is constructor function for the class Movie 
*@param name holds the name for the movie that the programmer is making
*@param age_restriction holds the MPAA ratin designated to this movie
*/
Movie::Movie(string name, string age_restriction)
{
	movieName=name;
	ageRating=age_restriction;
	for (int i = 0;i < 5;i ++)
	{
		movieRating[i] = 0;
	}
}

/**
*@brief This function  adds a users rating to the curent ratings already in place
*@param rating is an intger value representing the users rating of the movie
* return bool true(1) if rating is valid and false(0) if the rating is invalid
*/
void Movie::addRating(int rating )
{	
	bool correct=0;

	while(correct==0)
	{
		if (rating == 1 || rating == 2 || rating == 3 || rating == 4 || rating == 5)
		{	
			movieRating[rating-1] += 1;
			cout<<"a vote of "<<rating<<" has been added"<<endl;
			correct=1;
		}
		else
		{
			cerr<<"Please pick one of the digits on the list"<<endl<<endl;
			cin.clear();
			cin.ignore(256,'\n');
		}
	}
}
/**
*@brief This member function obtains an average of the current votes that are stored.
*return int
*/
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

string Movie::getName()
{
	return movieName; 
}

void getUserRating(Movie film, int& rating)
{
	bool correct=0;
	    cout<<"How would you rate "<<film.getName()<<"?"<<endl
                <<"1-Terrible"<<endl
                <<"2-Bad"<<endl
                <<"3-OK"<<endl
                <<"4-Good"<<endl
                <<"5-Great"<<endl;

        while(correct==0)
        {
                if(!(cin>>rating))
                {
                        cerr<<"Please enter a digit from one of the choices"<<endl<<endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                }
		else
		{
			correct=1;
		}
        }
}


