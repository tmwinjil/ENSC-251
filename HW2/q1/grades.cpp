/**
 * @file grades.cpp
 * @author Takunda Mwinjilo
 * @date   06/22/2018
 * @version 2.0
 *@brief <ENSC 251, HW 2>
 * @section Program that allows user to enter in grades and create a histogram from this data
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ TAKUNDA MWINJILO ____      _____06/22/2018____________
//
// ____ 301344066______


#include <iostream>
#include <vector>
using namespace std;

class Grades
{
public:
	
	Grades();
	//Constructor
	
	void addGrade(int g);
	//Mutator
	
	void makeHistogram();
	//Histogram function
	
private:
vector<int> grade;
int max;
};


int main()
{
	Grades test;
	int grade=0;

	cout<<"You will now start inputting grades. Input -1 to terminate grade entry"<<endl;
	cout<<"please input grades:"<<endl;

	while(1)
	{
		if(!(cin>>grade))
		{
			cerr<<"INTEGER VALUES ONLY"<<endl;
			cin.clear();
			cin.ignore(256,'\n');
			continue;
		}
		else if(grade==-1)
		{
			break;
		}
		else if (grade < -1 || grade > 100)
		{
			cerr<<"out of range"<<endl;
		}
		else
		{
			test.addGrade(grade);
		}
	}
	
	test.makeHistogram();
	
	return 1;
}


Grades::Grades()
{
	max = 0;
}

/**
*@brief This adds the grade entered by the user into the grades vector
*@param g represents the correct grade to be input into the array
*@param returns void
*/
void Grades::addGrade(int g)
{
	
	if(g > max)
	{
		max = g;
	}
	grade.push_back(g);
}

/**
*@brief function that produces a histogram from the input grades vector
*@param returns void
*/
void Grades::makeHistogram()
{
	int index=0;

	if(grade.size() == 0)
	{
		cout<<"no histogram can be made"<<endl;
		exit(0);
	}

	int* histo = new int [max+1];
	
	for(int j=0; j <= max;j++)
	{
		histo[j]=0;
	}

	for(unsigned int x = 0;x < grade.size(); x++)
	{
		index=grade[x];
		histo[index] ++;
	}

	for(int i = 0;i <= max;i++)
	{
		if(histo[i] != 0)
		{
			cout<<"Number of "<<i<<"'s: "<<histo[i]<<endl;
		}
	} 

	delete [] histo;
	histo = NULL;

}


