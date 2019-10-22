/*******************************************************************************
 *	Program Name: Project 5
 *	Author: Grayson Schillereff
 *	Date: June 11th 2019
 *	Discription: This is a text based game, set in the wild west. You move
 *	from linked location to location, interacting with people and items.
 *	Allowing you to increase your inventory and advance the story.
 * ****************************************************************************/

#include <iostream>
#include <sstream>
#include "Player.hpp"
#include "Saloon.hpp"
#include "Space.hpp"
#include "TrainStation.hpp"
#include "Upstairs.hpp"
#include "MainSt.hpp"
#include "Store.hpp"
#include "Menu.hpp"
//#include "Items.hpp"
#include <ctime>
using std::cin;
using std::cout;
using std::endl;


//Reference for validation: geeksforgeeks.org/converting-strings-numbers-cc
int main()
{
	//Seed random
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int x = 0;

	//Set up all the locations
	Saloon saloon;
	TrainStation trainstation;
	Upstairs upstairs;
	Store store;
	MainSt street;
	Menu menu;
	
	std::string newItem;
	bool approved = false;
	int speak;
	int lady = 0;
	Items item;
	std::string inventoryArray[5];
	int arrayCount = 0;
	Player play;
	bool safeCode = false;
	bool openSafe = false;
	Player *p1 = new Player;
	int start = 1;

	//Call Start menu
	start = menu.startUp();

	//Set player to trainstation
	Space *playerLocation;
	playerLocation = &trainstation;

	//If start = 1 play game
	if (start == 1)
	{
		
		start++;

	}
	//Start returns 3, then quit
	else if (start == 2)
	{
		delete p1;
		return 1;
	}

	//Display wlecome text
	trainstation.welcome();

	//Continue untill time runs out
	while (trainstation.timeRemaing() > 0 )
	{
		//While at the station
		while (playerLocation->getAreaName() == "Butcher Creek Train Station" && trainstation.timeRemaing() > 0)
		{
			
			if (start = 2)
			{
				cout << "You arrived at: " << playerLocation->getAreaName();
				trainstation.timeChange();
				
			}
			
			
		

			cout << endl << endl;
			
		
			//Set up locations
			trainstation.setForward(&saloon);
			trainstation.setLeft(nullptr);
			trainstation.setRight(nullptr);
			trainstation.setBackwards(nullptr);
			cout << "In front of you is " << saloon.getAreaName() << endl;



			//Choose place to go
			playerLocation = trainstation.chooseDirection();
			while (playerLocation == nullptr)
			{
				cout << "Can't go that way" << endl;
				trainstation.setForward(&saloon);
				trainstation.setLeft(nullptr);
				trainstation.setRight(nullptr);
				trainstation.setBackwards(nullptr);
				cout << "In front of you is " << saloon.getAreaName() << endl;

				playerLocation = trainstation.chooseDirection();
			}




		}

		//While at ButcherCreeKSaloon
		while (playerLocation->getAreaName() == "Butcher Creek Boys Saloon" && trainstation.timeRemaing() > 0)
		{
			cout << endl;
			cout << "You arrived at: " << playerLocation->getAreaName();
			cout << endl;
			trainstation.timeChange();
			cout << endl << endl;
			
			//Show options at saloon
			cout << "*Would you like to (1) speak to the bartender, (2) speak to the Madam of the house, (3) go somewhere else" << endl
			<< "(4) display Wallet and Inventory and 15 min goes by, (5) go see the gambeling man" << endl;


			//validation of choice
			std::string way;
		
			std::getline(cin, way);

			std::stringstream check(way);
			int x = 0;
			
			check >> x;
			cout << endl;
			while (way.length() > 1 || x > 5 || x < 1)
			{
				
				cout << "Invalid input" << endl;
				std::getline(cin, way);
				std::stringstream check(way);
				check >> x;
			}
			speak = std::stoi(way);

			
			//1 calls speak to bartender
			if (speak == 1)
			{
				saloon.speakToBartender(p1);
			}
			//2 Speaks with Madam and starts the bool switches
			else if (speak == 2)
			{
				if (approved == false)
				{
					lady = saloon.speakToLady(p1);
					if (lady == 1)
					{
						upstairs.ladyPresent(lady);
						playerLocation = &upstairs;
						approved = true;
					}
				}
				else
				{
					cout << "*The Madam is already upstairs*" << endl;
				}
			}
			//3 display where to go
			else if(speak == 3)
			{
				//Can only go upstairs after the lady is upstairs
				cout << endl << "In front of you is the " << upstairs.getAreaName() << endl;
				{
					if (saloon.goUpStairs(approved) == false)
					{
						cout << "But, but you arent allowed there yet" << endl;
						saloon.setForward(nullptr);
					}
					else
						saloon.setForward(&upstairs);
				}
				//Set rest of locations
				saloon.setLeft(nullptr);
				saloon.setRight(&street);
				cout << "To your right is " << street.getAreaName() << endl;
				saloon.setBackwards(&trainstation);
				cout << "Behind you is " << trainstation.getAreaName() << endl;
				playerLocation = saloon.chooseDirection();
				while (playerLocation == nullptr)
				{
					cout << "Can't go that way" << endl;
					playerLocation = saloon.chooseDirection();
				}
				
			}
			//Display your wallet and invetory
			else if (speak == 4)
			{
				cout << "You curently have: $" << p1->checkWallet() << " dollars" << endl
					<< "Your inventory: ";
				p1->displayInventory();
				cout << endl << endl;
			}
			else
			//Start gamble
			{
				saloon.gamble(p1);
			}
			

		}

		//While upstairs
		while (playerLocation->getAreaName() == "2nd floor of Saloon" && trainstation.timeRemaing() > 0)
		{
		
			//Set bool if you have the manual
			safeCode = p1->checkForItem("Safe Manual");
			cout << endl;
			cout << "You arrived at: " << playerLocation->getAreaName();
			cout << endl;
			trainstation.timeChange();
		

			cout << endl << endl;

			//If lady is upstairs and  check safecode
			if (upstairs.ladyPresent(lady) == true)
			{
				openSafe = upstairs.safe(safeCode, p1);

				cout << "\nYour inventory now includes: " << endl;
				p1->displayInventory();

			}

			cin.ignore();
			cout << "\nWould you like to (1) go somewhere else, or (2)  Check Wallet and Inventory and 15 min goes by?" << endl;


			//validate choice
			std::string way;

			std::getline(cin, way);

			std::stringstream check(way);
			int x = 0;

			check >> x;
			cout << endl;
			while (way.length() > 1 || x > 2 || x < 1)
			{

				cout << "Invalid input" << endl;
				std::getline(cin, way);
				std::stringstream check(way);
				check >> x;
			}
			speak = std::stoi(way);


			//Display location chocies
			if (speak == 1)
			{
				upstairs.setForward(nullptr);
				upstairs.setLeft(&street);
				cout << "To your left is " << street.getAreaName() << endl;
				upstairs.setRight(nullptr);
				upstairs.setBackwards(&saloon);
				cout << "Behind you is " << saloon.getAreaName() << endl;

				cout << endl;
				playerLocation = upstairs.chooseDirection();
				while (playerLocation == nullptr)
				{
					cout << "Can't go that way" << endl;
					cout << "To your left is " << street.getAreaName() << endl;
					cout << "Behind you is " << saloon.getAreaName() << endl;
					playerLocation = upstairs.chooseDirection();
				}
			}
			//Display wallet and inventory
			else
			{
			
				cout << "You curently have: $" << p1->checkWallet() << " dollars" << endl
					<< "Your inventory: ";
				p1->displayInventory();
				cout << endl << endl;
			
			}
			
		}

		//While on main st
		while (playerLocation->getAreaName() == "Main Street" && trainstation.timeRemaing() > 0)
		{
			cout << endl;
			cout << "You arrived at: " << playerLocation->getAreaName();
		
			cout << endl;
			trainstation.timeChange();
			cout << endl;
			
			//Set locations
			street.setForward(nullptr);
			street.setLeft(&store);
			cout << "To your left is " << store.getAreaName() << endl;
			street.setRight(nullptr);
			street.setBackwards(&saloon);
			cout << "Behind you is " << saloon.getAreaName() << endl;

			cout << endl;
			playerLocation = street.chooseDirection();
			while (playerLocation == nullptr)
			{
				cout << "Can't go that way" << endl;
				cout << "To your left is " << store.getAreaName() << endl;
				cout << "Behind you is " << saloon.getAreaName() << endl;
				playerLocation = street.chooseDirection();
			}

			
		}

		//While at the general store
		while (playerLocation->getAreaName() == "Dan's General Store" && trainstation.timeRemaing() > 0)
		{
			cout << endl;
			cout << "You arrived at: " << playerLocation->getAreaName();
			cout << endl;
			trainstation.timeChange();
			cout << endl;
			//set locations
			store.setForward(nullptr);
			store.setLeft(nullptr);
			store.setRight(nullptr);
			store.setBackwards(&street);
			

			
			cout << "*Would you like to (1) speak to Dan or (2) go somewhere else?*" << endl;


			//Validate
			std::string way;
			
			std::getline(cin, way);

			std::stringstream check(way);
			int x = 0;
			check >> x;

			while (way.length() > 1 || x > 2 || x < 1)
			{

				cout << "Invalid input" << endl;
				std::getline(cin, way);
				std::stringstream check(way);
				check >> x;
			}
			speak = std::stoi(way);

			

			cout << endl;

			//Call speak with dan
			if (speak == 1)
			{
				 store.talkToDan(p1);
				playerLocation = &store;
			}

			//Display locations to travel
			if (speak == 2)
			{
				cout << "Behind you is " << street.getAreaName() << endl;
				playerLocation = store.chooseDirection();
				while (playerLocation == nullptr)
				{
					cout << "Can't go that way" << endl;
					cout << "Behind you is " << street.getAreaName() << endl;
					playerLocation = store.chooseDirection();
				}
			}
		}




	}
	//Call show down
	street.showDown(p1);

	char end;
	cout << "Press any key to continue: ";
	cin >> end;

	//Display "Twist"
	street.twist();
	delete p1;
	
	cin >> x;

	return 0;
}
