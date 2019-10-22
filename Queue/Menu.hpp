/*******************************************************************************
 *	Program Name: Lab 9
 *	Author: Grayson Schillereff
 *	Date: June 1st 2019
 *	Discription: This program either creates a buffer, where it adds a number
 *	to the end of the queue or removes the front. Or it allows the user
 *	to create a palindrome with any word.
 * ****************************************************************************/



#ifndef MENU_HPP
#define MENU_HPP


class Menu
{

private:
	char choice;
	int numRounds;
	int percentageEnd;
	int percentageRemove;

public:
	char startUp();
	int rounds();
	int percentEnd();
	int percentRemove();


};
#endif
