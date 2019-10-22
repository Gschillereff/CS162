/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/
#ifndef SALOON_HPP
#define SALOON_HPP


#include "Player.hpp"
#include "Items.hpp"
#include <string>
#include "Space.hpp"

class Saloon : public Space
{

private:
	int choice;
	Items item;
	
	int kennyRoll;
	int yourRoll;
	


public:
	Saloon();
	void speakToBartender(Player*);
	int speakToLady(Player *);
	virtual void setForward(Space*);
	virtual void setRight(Space*);
	virtual void setLeft(Space*);
	virtual void setBackwards(Space*);
	bool goUpStairs(bool);
	void gamble(Player * p1);


};
#endif


