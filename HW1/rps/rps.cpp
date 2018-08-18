/**
 * @file rps.cpp
 * @author Takunda Mwinjilo
 * @date   05/25/2018
 * @version 2.0
 *@brief <ENSC 251, Lab 2>
 * @section Program that simulates a rock paper scissors game between the user and the computer
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ TAKUNDA MWINJILO ____      _____05/28/2018______________
//
// ____ 301344066______


#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

int checkWinner(int compChoice, int userChoice);
void getUserChoice(int& choice1);
void getCptrChoice(int& choice1);


int main()
{
    int userChoice=0;
    int compChoice=0;

	srand(time(NULL));

	do
	{
    getCptrChoice(compChoice);
    getUserChoice(userChoice);
	}while(checkWinner(compChoice,userChoice)==0);



return 0;

}

/**
*@brief This function checks for the winner of the game. returns zero if there is no winner and 1 if there is one.
*@param computer represents the computer's choice 1=rock, 2=paper, 3=scissors
*@param user represents the user's choice
*@param returns integer
*/
int checkWinner(int computer, int user)
{
	int diff=0;	//diff checks the difference between numeric values of the choices to determine the winner
	char message[3][24]= {"Rock crushes Scissors","Paper covers rock","Scissors cut Paper"};
	diff=computer-user;


	if (diff==1 || diff==-2)
	{
        cout<<message[computer]<<endl;
		cout<<"COMPUTER WINS"<<endl;
	}
	else if (diff==0)
	{
		cout<<"There is no winner. PLAY AGAIN"<<endl;
		return 0;
	}
	else
	{
        cout<<message[user]<<endl;
		cout<<"Congratulations!!! YOU WIN"<<endl;
	}
	return 1;

}
/**
*@brief This function collects the user's input of rock,paper or scissors
*@param choice1 is an integer variable to hold the user's choice
*@param return string
*/

void getUserChoice(int& choice1)
{
    int correct=0;

    while(correct==0)
    {

    // Make sure only numbers between 1 and 3 can be input;
        cout<<"Choose your weapon"<<endl;
        cout<<"1-Rock"<<endl;
        cout<<"2-Paper"<<endl;
        cout<<"3-Scissors"<<endl;
		//Loop to check that the input is of the correct data type. Re-loops if not
        if(!(cin>>choice1))
        {
            cerr<<"Please use the number of the weapon, e.g '1' for rock"<<endl<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            continue;
        }
		else if(getchar() != '\0' || getchar() !=' ')
		{
			cerr<<"Please enter a digit only"<<endl<<endl;
			cin.clear();
			cin.ignore(256,'\n');
			continue;
		}

		//This loop checks that the integer entered is either 1, 2 or 3
		if(choice1 == 1 || choice1 == 2 || choice1 == 3)
        {
            correct=1;
        }
		else
		{
			cerr<<"Please pick between 1,2 and 3 only"<<endl;
		}

        return;
    }





}
/**
*@brief This function generates the computer's choice
*@param initial takes the first initial of the name
*@param pL is the final PigLatin version of the name
*@param return string
*/

void getCptrChoice(int& choice2)
{
    choice2=(rand()%3)+1;
    return;
}
