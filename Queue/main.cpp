/*******************************************************************************
 *	Program Name: Lab 9
 *	Author: Grayson Schillereff
 *	Date: June 1st 2019
 *	Discription: This program either creates a buffer, where it adds a number
 *	to the end of the queue or removes the front. Or it allows the user
 *	to create a palindrome with any word.
 * ****************************************************************************/

#include <iostream>
#include <ctime>
using std::endl;
using std::cin;
using std::cout;
#include "Menu.h"
#include "Buffer.hpp"
#include "Palindrome.hpp"
#include <queue>
#include <string>
#include <stack>
#include <list>

int main()
{
	Menu menu;
	Buffer buffer;
	Palindrome palindrome;


	int N;
	char next;

	//Seed random	
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	//Call start up
	next = menu.startUp();
	
	//Loop while user wants to continue
	while (next == '1' || next == '2')
	{
		if (next == '1')
		{

			buffer.doBuffer();
			next = menu.startUp();
		}


		else if (next == '2')
		{

			palindrome.doPalindrome();
			next = menu.startUp();


		}

		else if (next == '3')
		{
			return 0;
		}
	}
	
}
