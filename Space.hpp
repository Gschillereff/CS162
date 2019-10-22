/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "Items.hpp"



class Space
{

protected:

	Items item;
	Space * forward;
	Space * left;
	Space * right;
	Space * backwards;
	Space * quit;
	std::string areaName;
	int direction;
	int time;


public:
	Space();
	virtual void setForward(Space*) = 0;
	virtual void setLeft(Space*) = 0;
	virtual void setRight(Space*) = 0;
	virtual void setBackwards(Space*) = 0;
	std::string getAreaName();
	void setAreaName(std::string);
	Space * getForward();
	Space *  chooseDirection();
	int timeRemaing();
	void timeChange();

};
#endif

