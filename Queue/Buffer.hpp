/*******************************************************************************
 *	Program Name: Lab 9
 *	Author: Grayson Schillereff
 *	Date: June 1st 2019
 *	Discription: This program either creates a buffer, where it adds a number
 *	to the end of the queue or removes the front. Or it allows the user
 *	to create a palindrome with any word.
 * ****************************************************************************/


#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <queue>
#include "Menu.h"

class Buffer
{

private:
	int N;
	int randomPercent;
	int count;
	int avg;
	int rounds;
	int append;
	int remove;
	Menu menu;
	double average;

public:

	int generateN();
	int generatePercent();
	void printQueue(std::queue<int>);
	double bufferAvg(int, double, int);
	void doBuffer();

};

#endif

