/*******************************************************************************
 *	Program Name: Lab 9
 *	Author: Grayson Schillereff
 *	Date: June 1st 2019
 *	Discription: This program either creates a buffer, where it adds a number
 *	to the end of the queue or removes the front. Or it allows the user
 *	to create a palindrome with any word.
 * ****************************************************************************/

#include "Buffer.hpp"
#include "Menu.h"
#include <iostream>
#include <queue>
using std::endl;
using std::cin;
using std::cout;


/*******************************************************************************
 *					generateN()
 *		This function generates a random number between 1 and 1000
 *		This function returns N and takes no parameters
 * ****************************************************************************/
int Buffer::generateN()
{
	N = (rand() % 1000) + 1;
	return N;

}

/******************************************************************************
 *					generatePercent()
 *		This function generates a random number between 1 and 100
 *		This function takes no parameters and retruns an int
 * ****************************************************************************/
int Buffer::generatePercent()
{
	randomPercent = (rand() % 100) + 1;
	return randomPercent;
}


/*******************************************************************************
 *				printQueue(queue)
 *			This function prints the queue.
 *			It takes in a parameter of the queue.
 *			It has no return
 * ****************************************************************************/
void Buffer::printQueue(std::queue <int> q)
{
	//Pop all the values untill empty
	while (!q.empty())
	{
		//Display the front
		cout << " " << q.front();
		//Pop off stack
		q.pop();
	}

}

/*******************************************************************************
 *					bufferAvg(int, int, int)
 *			This function finds the average length of the buffer
 *			It takes in 2 int the round and length.
*			Last it takes in a double of the last avg.
*			It returns a double of the avg
 * ****************************************************************************/
double Buffer::bufferAvg(int i, double avg, int length)
{
	
	double avg1 = (avg * (i - 1));
	
	double avg2 = (avg1 + length);
	
	double avg3 = avg2 / i;

	return avg3;
}

/*******************************************************************************
 *					doBuffer()
 *		This function gets the rounds, and the percentage to add
 *		or remove a number. It then generates the random N and the
 *		random number to add something or remove. Next it prints 
 *		the queue. Displays the size. finally the avg.
 *			No return or parameters.
 * ****************************************************************************/
void Buffer::doBuffer()
{
	std::queue<int> iQueue;

	//Get rounds, and percentages to add or remove
	rounds = menu.rounds();
	append = menu.percentEnd();
	remove = menu.percentRemove();
	average = 0;

	//Run for number of rounds
	for (int i = 0; i < rounds; i++)
	{
		cout << endl;
		//Get random number to add
		N = generateN();

		//Get first random number between 1 and 100
		int randomHundred = generatePercent();

		if (randomHundred <= append)
		{
			//Push N to stack
			iQueue.push(N);
		}

		//Get secont number between 1 and 100
		randomHundred = generatePercent();
		
		if (randomHundred <= remove)
		{
			//If queue is not empty
			if (!iQueue.empty())
			{
				//Pop front of queue
				iQueue.pop();
			}
		}

		//Display queue valeues
		cout << "The queue values are: ";
		printQueue(iQueue);
		cout << endl;

		//Get length of queue
		int length = iQueue.size();

		cout << "The length is: " << length << endl;

		//Get average
		int test = i + 1;
		average = bufferAvg(test, average, length);
		cout << "The average is: " << average << endl;

		cout << endl;

	}
}
