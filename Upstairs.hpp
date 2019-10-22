/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/

#ifndef UPSTAIRS_HPP
#define UPSTAIRS_HPP
#include "Space.hpp"
#include <string>
#include "Player.hpp"

class Upstairs : public Space
{
private:
	int safe1;
	int safe2;
	int safe3;
	bool upstairs = false;
	bool safeOpen = false;
	
public:
	Upstairs();
	virtual void setForward(Space*);
	virtual void setRight(Space*);
	virtual void setLeft(Space*);
	virtual void setBackwards(Space*);
	bool ladyPresent(int);
	bool safe(bool, Player*);
	
	

};
#endif
