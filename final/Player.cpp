/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/

#include "Player.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*******************************************************************************
 *			Default constructor for PLayer
 * ****************************************************************************/
Player::Player()
{
	currency = 10;
	string itemArray[5];
}

Player::Player(std::string name)
{
	
	currency = 10;
}

/*******************************************************************************
 *			int checkWallet()
 *	This function returns and int of the current currency
 * ****************************************************************************/
int Player::checkWallet()
{
	return currency;
}


/*******************************************************************************
 *			int walletChange(int)
 *	This function changes the currency.
 *	It takes in an int and changes based off that.
 *	It returns and int.
 * ****************************************************************************/
int Player::walletChange(int change)
{
	currency = currency - change;
	return currency;
}


/*******************************************************************************
 *			void addToArray(string)
 *		This function adds the parameter to the array.
 *		It has a string parameter.
 *		Returns void. If track is larger then 5, inventory is full
 * ****************************************************************************/
void Player::addToArray(std::string adding)
{
	if (track < 5)
	{
		itemArray[track] = adding;
		track++;
	}
	else
	{
		cout << "*Your inventory is full*" << endl;
	}
}

/*******************************************************************************
 *			displayInvetory()
 *		This function displays the current inventory,
 *		It cycles through the inventory displaying the number and whats there.
 *		It has no parameters or returns.
 * ****************************************************************************/
void Player::displayInventory()
{

	if (track == 0)
	{
		cout << "Empty Invy" << endl;
	}
	else
	{
		int j = 1;
		for (int i = 0; i < track; i++)
		{
			cout << j << ": " << itemArray[i] << endl;
			j++;
		}
	}
}



/*******************************************************************************
 *			bool checkForItem(string)
 *		This function checks the array for a string.
 *		Returns true if it is there, else false
 *		String parameter.
 *		bool return.
 * ****************************************************************************/
bool Player::checkForItem(std::string thisOne)
{

	for (int i = 0; i < track; i++)
	{
		if (itemArray[i] == thisOne)
		{
			return true;
		}
	}
	return false;
}
