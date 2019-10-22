
/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/
#include "Space.hpp"
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;

/*******************************************************************************
 *			Default constructors
 * ****************************************************************************/
Space::Space()
{
	areaName = "";
	forward = nullptr;
	left = nullptr;
	right = nullptr;
	backwards = nullptr;
	time = 240;
}

/*******************************************************************************
 *			Sets area names from abstract class
 * ****************************************************************************/
std::string Space::getAreaName()
{
	return areaName;
}

void Space::setAreaName(std::string name)
{
	areaName = name;
}

Space * Space::getForward()
{
	return forward;
}

/*******************************************************************************
 *			Space * chooseDirection()
 *		This function allows the user to choose which way they want to travel.
 *		It returns a pointer to the new location.
 *		No parameters.
 * ****************************************************************************/
Space * Space::chooseDirection()
{
	cout << "Which way would you like to go?" << endl;

		cout << "1. Forward: " << endl;
	
		cout << "2. Left: " << endl;

		cout << "3. Right" << endl;


	cout << "4. Backwards" << endl;



	//Validation
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
	direction = std::stoi(way);

	switch (direction)
	{
	case 1:
		return forward;
		break;

	case 2:
		return left;
		break;
	case 3:
		return right;
		break;
	case 4:
		return backwards;
		break;
	}
}


/*******************************************************************************
 *			int timeRemaing()
 *		This function returns the current time that is remaing. If time
 *		is equal to 0 it outputs the noon text.
 *		No paramaters, returns an int
 * ****************************************************************************/
int Space::timeRemaing()
{
	if (time == 0)
	{
		cout << "\n*The church bells ring out. Its high noon*" << endl
			<< "Bad Bart: \"Where's that no good, dirty rotten farm boy that got my brother throw'd in the clink!!\"" << endl
			<< "*You make your way out to the middle of the street for a showdown!*" << endl;
		
		
		return time;
	}
	else
	{
		
		return time;
	}
}

/*******************************************************************************
 *		void timeChange()
 *	This function subtracts the time by 15 "Minutes" and displays the
 *	remaining hours and minutes.
 *	This function has no return and takes no parameters.
 * ****************************************************************************/
void Space::timeChange()
{
	if (time > 0)
	{
		time = time - 15;
		int hours = time / 60;
		int minutes = time % 60;
		cout << hours << " hour(s) and " << minutes << " minutes remaing untill noon." << endl;
	}
	
}