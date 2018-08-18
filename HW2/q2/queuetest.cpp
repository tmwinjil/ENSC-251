/**
* @file queuetest.cpp
* @author Takunda MWinjilo
* @Date 06/22/2018
* @version 1.0
* @section User interface file that acts as a test driver to simulate a queue using the queue class
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Takunda Mwinjilo ____ _____06/22/2018______________
// ___301344066__


#include <iostream>
#include<ctime>
#include "queue.h"
using namespace std;
using namespace queuesavitch;

int main()
{
	Queue q;
	int choice=0;
	int ticket=0;
	long seconds;
	int waitTime[3]={0};
	int avg=0;
	int next=0;


	do
	{
		cout<<"Enter '1' to simulate customer's arrival, '2' to help the choice customer, or '3' to quit"<<endl;
		if(!(cin>>choice))
		{
			cout<<"PLEASE PICK 1,2, OR 3"<<endl;
			cin.clear();
			cin.ignore(10000,'\n');
			continue;
		}
		else
		{
			seconds=static_cast<long>(time(NULL));
		}
		

		if (choice == 1)
		{	
			ticket++;
			q.add(ticket,seconds);
		}
		else if(choice == 2)
		{		
			waitTime[next%3]=q.remove(seconds);
			next++;
			switch(next)
			{
			case 1: avg = waitTime[next-1];
					break;

			case 2: if (next >= 2)
					{avg = (waitTime[next-1]+waitTime[next])/2;}
					break;
			
			default: avg=(waitTime[0]+waitTime[1]+waitTime[2])/3;
			}
				cout<<"the estimated wait time for "<<next+1<<" is "<<avg<<" seconds"<<endl;
		}
		else if (choice < 1 || choice > 3)
		{
			cout<<"Please pick one of the choices"<<endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}

	}while (choice != 3);

	return 0;
}
