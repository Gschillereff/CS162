/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/

#ifndef MAINST_HPP
#define MAINST_HPP
#include "Space.hpp"
#include "Player.hpp"

class MainSt : public Space
{

public:
	MainSt();
	virtual void setForward(Space*);
	virtual void setRight(Space*);
	virtual void setLeft(Space*);
	virtual void setBackwards(Space*);
	void showDown(Player* p1);
	void twist();

};


#endif // !MAINST_HPP


