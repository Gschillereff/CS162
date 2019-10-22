/*******************************************************************************
 *	Program Name: Lab 9
 *	Author: Grayson Schillereff
 *	Date: June 1st 2019
 *	Discription: This program either creates a buffer, where it adds a number
 *	to the end of the queue or removes the front. Or it allows the user
 *	to create a palindrome with any word.
 * ****************************************************************************/

#include "Palindrome.hpp"
#include <iostream>
using std::endl;
using std::cin;
using std::cout;

/*******************************************************************************
 *							getWord()
 *		This function gets the string from the user.
 *		It reutrns the string. It takes no parameters
 * ****************************************************************************/
std::string Palindrome::getWord()
{
	cout << "Please enter the word for the Palindrome" << endl;
	std::getline(cin, word);

	return word;
}

/*******************************************************************************
 *							doPalindrome()
 *				This function takes the string and puts every charcter
 *				in the stack, and then pops them off in reverse.
 *				No parameters or return
 * ****************************************************************************/
void Palindrome::doPalindrome()
{
	cin.ignore();
	word = getWord();

	//Get word length
	wordLength = word.length();
	cout << endl << "Your palindrome is:" << word;

	//Push each character onto the stack
	std::stack< char, std::list<char> > iStack;
	for (int i = 0; i < wordLength; i++)
	{
		iStack.push(word[i]);
	}

	//Pop each character off untill stack is empty
	while (!iStack.empty())
	{
		cout << iStack.top();
		iStack.pop();
	}
	cout << endl << endl;
}
