/*******************************************************************************
 *	Program Name: Lab 9
 *	Author: Grayson Schillereff
 *	Date: June 1st 2019
 *	Discription: This program either creates a buffer, where it adds a number
 *	to the end of the queue or removes the front. Or it allows the user
 *	to create a palindrome with any word.
 * ****************************************************************************/

#ifndef PALINDROME_HPP
#define PALINDROME_HPP
#include <string>
#include <stack>
#include <list>

class Palindrome
{
	std::string word;
	int wordLength;
public:
	std::string getWord();
	void doPalindrome();
};
#endif
