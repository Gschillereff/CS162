/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/

#include "MainSt.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*******************************************************************************
 *		Default constructor for mainSt
 * ****************************************************************************/
MainSt::MainSt()
{
	areaName = "Main Street";
}

/*******************************************************************************
 *			Sets locations from abstract class
 * ****************************************************************************/
void MainSt::setForward(Space * front)
{
	forward = front;
}

void MainSt::setLeft(Space * lef)
{
	left = lef;
}

void MainSt::setRight(Space * righ)
{
	right = righ;
}

void MainSt::setBackwards(Space * back)
{
	backwards = back;
}

/*******************************************************************************
 *			showDown(Player*)
 *		This function goes through all the different outcomes of the fight.
 *		It depends on what items you currently have.
 *		It takes in a pointer to Player for inventory.
 *		No return
 * ****************************************************************************/
void MainSt::showDown(Player * p1)
{
	cout << "\n\n*You walk out into the street, Bad Bart is on the other end staring at you, a tumbleweed rolls by for dramatic effect*" << endl
	<< "Bad Bart: \"Hope you brought yourself a big iorn!\"" << endl;


	//Gun ending
	if (p1->checkForItem("Pearl Handeled Colt 45") == true)
	{
		cout << "*You move your coat and reveal .45, the sun glimmers off its handle*" << endl
			<< "Bad Bart:\"Good lookin gun, hope it shoots straight!\"" << endl
			<< "*The town is silent, waiting for the next toll of the clock*"
			<< "*Dong*" << endl
			<< "*You both reach for your guns, you fiddle with the latch, you can't get it open!*" << endl
			<<"*Bart raises his, and fires... *click*... *nothing*" << endl
			<<"Bad Bart: \"What in tarnation, it's jammed!\"" << endl
			<<"*You manage to pull your gun out, and **BAM**, that's the end of Bad Bart\"" << endl
			<< "\n\n******************You did it, you saved the town of Butcher Creek!*****************" << endl;
	}

	//Knife endings
	else if (p1->checkForItem("Knife") == true)
	{
		cout << "Bad Bart: \"You brought a knife to a gun fight? Seriously?\"" << endl
			<< "*Bad Bart aims down his revolver and **BAM**" << endl
			<< "*Everything goes dark*" << endl;
		//Snake Oil endings
		if (p1->checkForItem("Snake Oil") == true)
		{
			cout << "*Suddenly you start to come to, Bad Bart is standing over the top of you*" << endl
				<< "*You feel something wet on your chest, it's the Snake Oil!*" << endl
				<< "*Bad Bart must of broke the bottle when he shot you! You can't believe it worked!*" << endl
				<< "*Thinking quick you pull out your knife and stab Bad Bart in the ankle while he's standing over you.*" << endl
				<< "Bad Bart: \"Not my achilles heel! My only weakness! Im'a coming Elizabeth! \"" << endl
				<< "*Bad Bart falls to his grave.*" << endl
				<< "\n\n******************You did it, you saved the town of Butcher Creek!*****************" << endl;
		}
		else
		{
			cout << "*You fade out, and follow the sounds of angels singing.*" << endl
				<< "\n\n******************Our hero dies and Bad Bart lives to torment another day******************" << endl;
		}
		
	}
	//No items
	else
	{
		cout << "Bad Bart: \"You don't even have a weapon! This'll be quick!" << endl
			<< "*Bad Bart aims down his revolver and **BAM**" << endl
			<< "*Everything goes dark*" << endl;
		cout << "*You fade out, and follow the sounds of angels singing.*" << endl
			<< "\n\n******************Our hero dies and Bad Bart lives to torment another day******************" << endl;
	}
}


/*******************************************************************************
 *			twist()
 *	This function just displays text. It is the "Twist" ending.
 *	Hope you liked it.
 *	No parameters or returns.
 * ****************************************************************************/
void MainSt::twist()
{
	cout << "\n\n\n\n\n\n\n\"Leroy: \"And that's my script for the next Hollywood BlockBuster!\"" << endl
		<< "\"Its gonna be bigger than Avengers! We will have spinoffs, action figures, theme parks, you name it!\"" << endl
		<< "Movie Director: \n\"....\"\n\"....\"\n\"....\" \"Please leave my office, and never return.\"" << endl
		<< "Leroy: \"Wait you didn't like it? You must not of understood the plot, the symbolism!\"" << endl
		<< "Movie Director:\"SECURITY!!\"" << endl;

}
