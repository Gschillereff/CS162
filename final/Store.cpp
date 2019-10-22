/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/
#include "Store.hpp"
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
int selection;

/*******************************************************************************
 *			Default constructor for Store
 * ****************************************************************************/
Store::Store()
{
	areaName = "Dan's General Store";
}

/*******************************************************************************
 *			Sets locations from abstract class
 * ****************************************************************************/
void Store::setForward(Space * front)
{
	forward = front;
}

void Store::setLeft(Space * lef)
{
	left = lef;
}

void Store::setRight(Space * righ)
{
	right = righ;
}

void Store::setBackwards(Space * back)
{
	backwards = back;
}


/*******************************************************************************
 *			talkToDan(Player*)
 *	This function handels the player speaking with Dan.
 *	It takes the player as a paramter to access his wallet and inventory.
 *	It has no reutrn.
 * ****************************************************************************/
void Store::talkToDan(Player* p1)
{

	cout << "Dan: \"Welcome to Dan's General Store, I am Dan.\"" << endl
		<< "\"What can I do ya for, stranger?\"" << endl << endl;

	cout << "Things to Buy:" << endl
		<< "1. $3 Knife, ya never know when you will need a knife, maybe never!" << endl
		<< "2. $10 Snake Oil, guaranteed to fix all your aches and pains!" << endl
		<< "3. $5 Old Safe Manual, probably garbage... possibly not?" << endl
		<< "4. $2 Bubble gum, taste great and blows big bubbles." << endl;

	//cin.ignore();

	//Input validation
	std::string way;
	
	std::getline(cin, way);

	std::stringstream check(way);
	int x = 0;
	check >> x;

	while (way.length() > 1 || x > 4 || x < 1)
	{

		cout << "Invalid input" << endl;
		std::getline(cin, way);
		std::stringstream check(way);
		check >> x;
	}
	selection = std::stoi(way);

	cout << endl;


	//Add to inventory depending on what is bought
	if (selection == 1)
	{
		//Always checks if you have enough money
		if (p1->checkWallet() >= 3)
		{
			p1->walletChange(3);
			cout << "You now have $" << p1->checkWallet() << " and a new knife!" << endl;
			p1->addToArray("Knife");
		}
		else
		{
			cout << "Dan: \"You don't have enough cash! Come back after you get some more.\"" << endl;
			return;
		}
	}
	else if (selection == 2)
	{
		if (p1->checkWallet() >= 10)
		{
			p1->walletChange(10);
			cout << "You now have $" << p1->checkWallet() << " and some snake oil!" << endl;
			p1->addToArray("Snake Oil");
		}
		else
		{
			cout << "Dan: \"You don't have enough cash! Come back after you get some more.\"" << endl;
			return;
		}
	}
	else if (selection == 3)
	{
		if (p1->checkWallet() >= 5)
		{
			p1->walletChange(5);
			cout << "You now have $" << p1->checkWallet() << " and an old Safe Manual!" << endl;
			p1->addToArray("Safe Manual");
		}
		else
		{
			cout << "Dan: \"You don't have enough cash! Come back after you get some more.\"" << endl;
			return;
		}
	}
	else if (selection == 4)
	{
		if (p1->checkWallet() >= 2)
		{
			p1->walletChange(2);
			cout << "You now have $" << p1->checkWallet() << " and some bubble gum!" << endl;
			p1->addToArray("Bubble Gum");
		}
		else
		{
			cout << "Dan: \"You don't have enough cash! Come back after you get some more.\"" << endl;
			return;
		}
	}
	
	cout << "Dan: \"Thanks for coming in!\"" << endl;
}
