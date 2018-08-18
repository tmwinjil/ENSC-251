/**
* @file queue.cpp
* @author Takunda MWinjilo
* @Date 06/22/2018
* @version 1.0
* @section Implementation file for the queue class. Contains definition of all functions to be used by the class
*@section As stated in the instructions, code is a modification of textbook code with Queue copy constructor and destructor coming from pages 778-779 of  "Problem Solving with C++: 9th edition"
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Takunda Mwinjilo ____ _____06/22/2018______________
//
// ___301344066__

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include "queue.h"
using namespace std;

namespace queuesavicth
{
	//Constructor
	Queue::Queue() : front(NULL), back(NULL)
	{
		//Intentionally empty
	}

	//Copy Constructor
	Queue::Queue(const Queue& aQueue)
	{
		if (aQueue.empty( ))
		{
			front = back = NULL;
		}
		else
		{
			QueueNodePtr temp_ptr_old = aQueue.front;
			//temp_ptr_old moves through the nodes
			//from front to back of aQueue.
			QueueNodePtr temp_ptr_new;
			//temp_ptr_new is used to create new nodes.
			back = new QueueNode;
			back->ticketNo = temp_ptr_old->ticketNo;
			back->entryTime = temp_ptr_old->entryTime;
			back->link = NULL;
			front = back;
			//First node created and filled with ticketNo.
			//New nodes are now added AFTER this first node.
			temp_ptr_old = temp_ptr_old->link;
			//temp_ptr_old now points to second
			//node or NULL if there is no second node.
			while (temp_ptr_old != NULL)
			{
				temp_ptr_new = new QueueNode;
				temp_ptr_new->ticketNo = temp_ptr_old->ticketNo;
				temp_ptr_new->entryTime = temp_ptr_old->entryTime;
				temp_ptr_new->link = NULL;
				back->link = temp_ptr_new;
				back = temp_ptr_new;
				temp_ptr_old = temp_ptr_old->link;
			}	
		}
	}

	//Destructor
	Queue::~Queue()
	{
		int seconds = static_cast<long>(time(NULL));
		int next;
		while (! empty( ))
		{
			next = remove(seconds);	//remove calls delete.
		}
	}

	/*@brief checks to see whether queue is empty
	*@param returns bool
	*/
	bool Queue::empty() const
	{
		return(back==NULL);
	}

	/*@brief checks to see whether queue is empty
	*@param item represents the ticket number of the person being added
	*@param  theTime contains the long int form of the time
	*@param returns void;
	*/
	void Queue::add(int item, long theTime)
	{
		if (empty())
		{
			front = new QueueNode;
			front->ticketNo = item;
			front->entryTime = theTime;
			front->link = NULL;
			back = front;
		}
		else
		{
			QueueNodePtr temp_ptr;
			temp_ptr = new QueueNode;
			temp_ptr->ticketNo = item;
			temp_ptr->entryTime = theTime;
			back->link = temp_ptr;
			back = temp_ptr;
		}
		cout<<"customer "<<item<<" entered the queue at time"<<theTime<<"."<<endl;

	}

	/*@brief checks to see whether queue is empty
	*@param service is the time which the customer was serviced
	*@param returns int representing time taken to serve customer;
	*/
	int Queue::remove(long service)
	{
		int customer=0;
		long time=0;
		long wait=0;
		int result=0;
			

		if(empty())
		{
			cout<<"Error: Removing an item from an empty queue.\n";
			exit(1);
		}
		
		
		customer=front->ticketNo;
		time=front->entryTime;
		wait=service-time;
		result=static_cast<int>(wait);
		cout<<"Customer "<<customer<<" is being helped at time "<<time<<"."
			<<" Wait time = "<<wait<<" seconds"<<endl;

		QueueNodePtr discard;
		discard=front;
		front=front->link;
		if (front == NULL)
		{
			back = NULL;
		}
		
		delete discard;

		return wait;

	}
}//queuesavitch

