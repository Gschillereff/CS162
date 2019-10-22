/*******************************************************************************
 *	Program Name: Lab 9
 *	Author: Grayson Schillereff
 *	Date: June 1st 2019
 *	Discription: This program either creates a buffer, where it adds a number
 *	to the end of the queue or removes the front. Or it allows the user
 *	to create a palindrome with any word.
 * ****************************************************************************/

#include "Menu.h"
#include<iostream>
using std::endl;
using std::cin;
using std::cout;


/*******************************************************************************
 *							startUp()
 *				Get selction from user.
 *				Returns a char. No parameters
 * ****************************************************************************/
char Menu::startUp()
{
	cout << "Please enter your selection." << endl
		<< "1. Test the buffer" << endl
		<< "2. Create a palindrome" << endl
		<< "3. Quit" << endl;

	cin >> choice;
	
	while (choice != '1' && choice != '2' && choice != '3')
	{
		cin.ignore();
		cout << "Invalid input, please enter 1, 2. or 3" << endl;
		cin >> choice;
	}

	return choice;
}


/*******************************************************************************
 *						rounds()
 *				Get numbers of rounds from user.
 *				No parameters. Returns an int
 * ****************************************************************************/
int Menu::rounds()
{
	cout << "How many rounds would you like to go through?" << endl;
	cin >> numRounds;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid integer" << endl;
		cin >> numRounds;
	}

	return numRounds;
}


/*******************************************************************************
 *							percentEnd()
 *				Get the perecetage to add to the end of the queue
 *				No parameters. Returns an int.
 * ****************************************************************************/
int Menu::percentEnd()
{
	cout << "Please enter the percentage chance a number will be added to the end" << endl;
	cin >> percentageEnd;

	while (cin.fail() || percentageEnd < 0 || percentageEnd > 100)
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid percent 0-100" << endl;
		cin >> percentageEnd;
	}

	return percentageEnd;

}


/*******************************************************************************
 *							percentRemove()
 *				Get the perecetage to remove a number from the front
 *				No parameters. Returns an int.
 * ****************************************************************************/
int Menu::percentRemove()
{
	cout << "please enter the percentage chance a number will be removed from the front" << endl;
	cin >> percentageRemove;

	while (cin.fail() || percentageRemove < 0 || percentageRemove > 100)
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid percent 0-100" << endl;
		cin >> percentageRemove;
	}

	return percentageRemove;
}
