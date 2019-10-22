#include "Menu.hpp"
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;

/*******************************************************************************
 *			int startUp()
 *	This function displays the start menu. Asks if you want intstructions,
 *	To play, or to quit.
 *	No parameters
 *	Returns an int.
 * ****************************************************************************/
int Menu::startUp()
{
	cout << "Welcome to \"Butcher Creek\" the text based game!" << endl << endl;
	cout << "How would you like to proceed?" << endl
		<< "1. Play!" << endl
		<< "2. About the game" << endl
		<< "3. Quit" << endl;

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
	
	//Return choices
	if (choice == 1)
	{
		return 1;
	}
	else if (choice == 2)
	{
		//call the about
		about();
		//Call self
		startUp();
	}
	else
	{
		return 2;
	}

	return 0;
}

/*******************************************************************************
 *			about()
 *	This function just does a brief overview of the game.
 *	No parameters or return.
 * ****************************************************************************/
void Menu::about()
{

	cout << "\n\nThis is a text based game. You, a farm boy, head out to make a name for yourself." << endl
		<< "Trouble quickly emerges and you must find a way out of it!" << endl
		<< "Follow prompts on the screen." << endl
		<< "You start with $15, spend it wisely. But, you can always try and win some back gambling!" << endl
		<< "You can hold 5 items in your inventory, but you can't get rid of any!" << endl
		<< "*Hint* \n I would recommend buying a drink first!\n" << endl
		<< "Remember, move efficently, it takes 15 min to go between spaces, and you don't have that much time!" << endl
		<< "Good luck!\n" << endl;
}
