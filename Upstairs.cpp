/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/
#include "Upstairs.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*******************************************************************************
 *			Upstairs()
 *	Default constructor for upstairs
 * ****************************************************************************/
Upstairs::Upstairs()
{
	areaName = "2nd floor of Saloon";
}



/*******************************************************************************
 *			Sets locations from abstract class
 * ****************************************************************************/
void Upstairs::setForward(Space * front)
{
	forward = front;
}

void Upstairs::setLeft(Space * lef)
{
	left = lef;
}

void Upstairs::setRight(Space * righ)
{
	right = righ;
}

void Upstairs::setBackwards(Space * back)
{
	backwards = back;
}


/*******************************************************************************
 *			bool ladyPresent(int)
 *		This function checks if the Madam is downstairs or not
 *		Returns a bool
 * ****************************************************************************/
bool Upstairs::ladyPresent(int check)
{
	if (check == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*******************************************************************************
 *			bool safe(bool, player*)
 *		This function handels the dialouge upstairs. It also checks for 
 *		Certain items in players inventory, and changes based on that.
 *		It also adds to inventory.
 *		It returns a bool if the safe is opened.
 * ****************************************************************************/
bool Upstairs::safe(bool code, Player* p1)
{

	if (p1->checkForItem("Pearl Handeled Colt 45") == true)
	{
		cout << "Madam: Excuse me hun, you already got what you were looking for here" << endl;
			return true;
	}
	else
	{
		cout << "*You enter a bedroom with the Madam, a huge safe catches your eye*" << endl
			<< "Madam: \"Ahh, the safe, it catches many people's eye, but no one has been able to crack it.\"" << endl
			<< "\"It is said to hold a gun, powerful enough to shoot down any man.\"" << endl
			<< "\"Would you like to try and open it?\"" << endl
			<< "*You nod and approach the safe dial*" << endl << endl;
		if (code == true)
		{
			cout << "*You notice the safe company is the same the as the old manual you have.*" << endl
				<< "*You pull it out and open it up, and the code is written on the first page!*\n" << endl
				<< "It reads \"Buthcer Creek Saloon Safe code:\"" << endl
				<< "First Num: 9" << endl
				<< "Second Num: 23" << endl
				<< "Third Num: Same as the first!\n" << endl;
		}
		cout << "Enter first number: " << endl;
		cin >> safe1;
		if (safe1 == 9)
		{
			cout << "\n*click good start*" << endl
				<< "Enter second number" << endl;
			cin >> safe2;
			if (safe2 == 23)
			{
				cout << "\n*click, almost there!*" << endl
					<< "*Enter third number*" << endl;
				cin >> safe3;
				if (safe3 == 9)
				{
					cout << "\n*clunk* the safe opens, revealing a beautiful pearl grip colt 45" << endl
						<< "*You take it, it feels good in your hand*" << endl
						<< "Madam: \"Maybe now you can defeat Bart, and save this town!\"" << endl;
					p1->addToArray("Pearl Handeled Colt 45");
					return true;

				}
				else
				{
					cout << "*Nothing happend, the code must be wrong*" << endl
						<< "Madam: \"Come back when you know the code\"" << endl;
					return false;

				}
			}
			else
			{
				cout << "*Nothing happend, the code must be wrong*" << endl
					<< "Madam: \"Come back when you know the code\"" << endl;
				return false;

			}


		}
		else
		{
			cout << "*Nothing happend, the code must be wrong*" << endl
				<< "Madam: \"Come back when you know the code\"" << endl;
			return false;
		}
	}
}


