/**
* @file queue.h
* @author Takunda MWinjilo
* @Date 06/22/2018
* @version 1.0
* @section Header file for program that simulates a queue of customers using linked lists to immitate a queue data structure
*@section As stated in the question this code is a modification of the code given in lecture 09 2018 for ENSC 251
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Takunda Mwinjilo ____ _____06/22/2018______________
//
// ___301344066__

#ifndef "QUEUE_H"
#define "QUEUE_H"
namespace queuesavitch
{
	struct QueueNode
	{
		int ticketNo;
		long entryTime;
		QueueNode *link;
	};
	typedef QueueNode* QueueNodePtr;

	class Queue
	{
	public:
		Queue();
		//Initializes the object to an emty queue
		Queue(const Queue& aQueue);
		~Queue();

		void add(int item,long theTime);
		//Postcondition: item has been added to the back of the queue.

		int remove(long service);
		//precondition: queue cannot be empty;
		//postcondition: item has been removed from the queue;

		bool empty() const;
		//checks whether the queue is empty or not


	private:

		QueueNodePtr front;
		QueueNodePtr back;
	

	};
}//queuesavitch
#endif //QUEUE_H
