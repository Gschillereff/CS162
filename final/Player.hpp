

/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include"Items.hpp"




class Player
{

private:
	int currency;
	int track = 0;
	string itemArray[5];


public:
	Player();
	Player(std::string);
	int checkWallet();
	int walletChange(int);
	void addToArray(std::string);
	void displayInventory();
	bool checkForItem(std::string);

};

#endif
