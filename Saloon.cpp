/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/

#include <iostream>
#include "Saloon.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
/*******************************************************************************
 *			Default constructor for Saloon
 * ****************************************************************************/
Saloon::Saloon()
{
	areaName = "Butcher Creek Boys Saloon";
}

/*******************************************************************************
 *			Sets locations from abstract class
 * ****************************************************************************/
void Saloon::setForward(Space * front)
{
	forward = front;
}

void Saloon::setLeft(Space * lef)
{
	left = lef;
}

void Saloon::setRight(Space * righ)
{
	right = righ;
}

void Saloon::setBackwards(Space * back)
{
	backwards = back;
}


/*******************************************************************************
 *			bool goUpStairs(bool)
 *	This function returns a bool based on if you are approved to go upstairs.
 *	It has bool paramater and reutrn.
 * ****************************************************************************/
bool Saloon::goUpStairs(bool approved)
{
	if (approved == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*******************************************************************************
 *			speakToBartender(Player*)
 *	This function handels the interatction with the bartender.
 *	It has no return,
 *	Takes in a pointer to Player to access his wallet and inventory.
 * ****************************************************************************/
void Saloon::speakToBartender(Player * p1)
{
	
	cout << "*You approach the bartender.*" << endl
		<< "*He is cleaning the mugs with a towel, in old timey fashion*" << endl
		<< "Bartender: What'll it be partner?" << endl;

	cout << "1. Buy drink ($5)" << endl
		<< "2. Ask advice on Bad Bart" << endl
		<< "3. Leave" << endl;


	//validation
	std::string way;

	std::getline(cin, way);

	std::stringstream check(way);
	int x = 0;

	check >> x;

	while (way.length() > 1 || x > 3 || x < 1)
	{

		cout << "Invalid input" << endl;
		std::getline(cin, way);
		std::stringstream check(way);
		check >> x;
	}
	choice = std::stoi(way);

	

	switch (choice)
	{
		//Buys drink
	case 1:	p1->walletChange(5);
		cout << "*You hand the bartender the money and take a long pull*" << endl
			<< "Bartender: \"So your the guy Bad Bart just challenged. He's killed 4 men, just this week!\"" << endl
			<< "*You take another drink*" << endl
			<< "Bartender: \"Your only chance at winning is if you got a real quick gun.\"" << endl
			<< "\"Do ya gots one?\"" << endl;

		//Check if you have the gun
		if(p1->checkForItem("Pearl Handeled Colt 45") == true)
		{
			cout << "*You shake your head yes*" << endl
				<< "Bartender: \"Well hope you are quick with it! Probably won't make a difference.\"" << endl;
		}
		else
		{
			cout << "*You shake your head no*" << endl
				<< "Bartender: \"Sorry son, hope you enjoyed your life.\"" << endl;
		}
		//Chekc if you already got the coupon from him
		if(p1->checkForItem("Coupon") == true)
		{
			cout << "Bartender: \"Well good luck, we are all pulling for ya.\"" << endl;
		}
		else
		{
			cout << "\"Well as a dead man walking take this coupon to the Madam, might as well enjoy your last night\"" << endl
				<< "*You take the coupon from the bartender and thank him*" << endl;
			//Add coupon to inventory
			p1->addToArray("Coupon");
		}
		
		break;
	case 2: cout << "Bartender: \"I aint give advice for free, buy a drink or getout\"" << endl;
		break;
	case 3: cout << "*You get off the stool and leave*" << endl;
		break;
	default:
		break;
	}

}


/*******************************************************************************
 *			int speakToLady(Player*)
 *		This function handels speaking with the Madam while downstairs.
 *		It returns an int based on whats happening.
 *		It takes in a Player pointer to access inventory and wallet
 * ****************************************************************************/
int Saloon::speakToLady(Player * p1)
{
	cout << "Madam: \"Hey there handsome, I got something you need upstairs...\"" << endl
		<< "Madam: \"Follow me, only $100.\"" << endl;

	//Check for money or coupon
	cout << "*You check your wallet, you currently have $" << p1->checkWallet() << "*" << endl;
	if (p1->checkWallet() >= 100 || p1->checkForItem("Coupon"))
	{
		if (p1->checkForItem("Coupon") == true)
		{
			cout << "Madam: \"Oh a coupon, I guess that works\"" << endl;
		}
		else
		{
			//No coupon but has $100
			(p1->walletChange(100));
		}
		cout << "Madam \"Follow me then.\"" << endl
			<< "*You follow the Madam upstairs*" << endl << endl << endl;
		//Used for approval
		return 1;
	}
	else
	{
		//No money or wallet
		cout << "Madam \"Come see me after you fill your wallet.\"" << endl;
		return 2;
	}

}

/*******************************************************************************
 *		gamble(Player*)
 *	This function handels the gambling.
 *	It has no return.
 *	Takes in a Player pointer to acces the wallet
 * ****************************************************************************/
void Saloon::gamble(Player * p1)
{
	int gamble = 0; //Money to wager

	cout << "Kenny R: \"Welcome to the table, Slick, the game's War, ever heard of it?\"" << endl
		<< "\"All you gotta do is roll a number higher then me on this 20 sided die and you win, sound easy?\"" << endl
		<< "\"Double your money if you win, you in?\"" << endl;

	cout << "*You check your wallet, you have $" << p1->checkWallet() << "*" << endl;


	//Check for money
	//Give player money if they ran out
	if (p1->checkWallet() <= 0)
	{
		cout << "Kenny R: \"Well, that sure is sad, heres $1, come back and gamble if ya want.\"" << endl;
		p1->walletChange(-1);
	}
	//Start wager
	else
	{
		cout << "*How much do you want to wager ($1-$50)*" << endl;

		std::string way;

		std::getline(cin, way);

		std::stringstream check(way);
		int x = 0;

		check >> x;
		//Validation, cant be more then wallet
		while (way.length() > 2 || x > 50 || x < 1 || x > p1->checkWallet())
		{

			cout << "Invalid input" << endl;
			std::getline(cin, way);
			std::stringstream check(way);
			check >> x;
		}
		gamble = std::stoi(way);

		

		cout << "\n\n\nKenny R: $" << gamble << "\" is that all? Oh well. Roll the bones!!" << endl;


		//Both rolls are random, between 1 and 20
		yourRoll = ((rand() % 20) + 1);
		cout << "*You rolled " << yourRoll << "*" << endl;
		kennyRoll = ((rand() % 20) + 1);
		cout << "*The gambler rolled " << kennyRoll << "*" << endl;


		//Change wallet depending on the roll.
		if (yourRoll > kennyRoll)
		{
			cout << "Kenny R: \"You win this time.\"";
			p1->walletChange(gamble * -1);
		}
		else if (yourRoll < kennyRoll)
		{
			cout << "Kenny R: \"Knew I would win, always do!\"" << endl;
			p1->walletChange(gamble);
		}
		else
		{
			cout << "Kenny R: \"Guess lady luck didn't want either of us to win" << endl;
		}

	}
	cout << endl;
}
