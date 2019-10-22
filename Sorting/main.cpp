/*******************************************************************************
 *	Program Name: Lab 8
 *	Author: Grayson Schillereff
 *	Date: May 26th 2019
 *	Discription: This program uses a simple search and a binary search.
 *				It also sorts a file of integers and then creates a new 
 *				output file of the integers in order.
 * ****************************************************************************/

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using std::cin;
using std::cout;
using std::endl;


//Function declarations
bool search(int[], int, int);
void sort(int[], int);
int binarySearch(const int[], int, int);

int main()
{
	
	int i;
	int x;
	int numArray[9];
	int earlyArray[10];
	int middleArray[10];
	int endArray[10];
	std::ifstream inFile;
	std::ofstream outFile;
	bool test;
	std::string numOutFileName;
	std::string earlyOutFileName;
	std::string middleOutFileName;
	std::string endOutFileName;
	int postion;
	int searchNum;

	//Open and set all numbers in num txt to array;
	inFile.open("num.txt");
	
	i = 0;
	while(inFile >> x)
	{

	numArray[i] = x;
	i++;	
	
	}

	//Close file
	inFile.close();



	//Open and set all values to an array;
	inFile.open("early.txt");
	i = 0;
	while(inFile >> x)
	{

	earlyArray[i] = x;
	i++;	
	
	}

	//Close the file
	inFile.close();


	//Open and set all values to an array;
	inFile.open("middle.txt");
	i = 0;
	while(inFile >> x)
	{

	middleArray[i] = x;
	i++;	
	
	}

	//Close the file
	inFile.close();


	//Open and set all values to an array;
	inFile.open("end.txt");
	i = 0;
	while(inFile >> x)
	{

	endArray[i] = x;
	i++;	
	
	}

	//Close the file
	inFile.close();

	//Find the integer to look for
	cout << "What integer would you like to search for?" << endl;
	cin >> searchNum;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid entry, please enter an integer" << endl;
		cin >> searchNum;
		
	}
	cin.ignore(256, '\n');

	//Search array for number
	cout << "num.txt: ";
	test = search(numArray, searchNum, 9);
	if (test == 1)
	{
		cout << "target value found" << endl;
	}
	else
	{
		cout << "target value not found" << endl;
	}
	
	//Search array for number
	cout << "early.txt: ";
	test = search(earlyArray, searchNum, 10);
	if(test == 1)
	{
	cout << "target value found" << endl;
	}
	else
	{
	cout << "target value not found" << endl;
	} 

	//Search array for number
	cout << "middle.txt: ";
	test = search(middleArray, searchNum, 10);
	if (test == 1)
	{
		cout << "target value found" << endl;
	}
	else
	{
		cout << "target value not found" << endl;
	}

	//Search array for number
	cout << "end.txt: ";
	test = search(endArray, searchNum, 10);
	if (test == 1)
	{
		cout << "target value found" << endl;
	}
	else
	{
		cout << "target value not found" << endl;
	}


	//Sort and write to new files
	//Ask where new files should be named
	cout << "Where would you like the sorted contents of num.txt to go?" << endl;
	std::getline(std::cin, numOutFileName);

	sort(numArray, 9);
	cout << "num.txt sorted and written to " << numOutFileName << endl;
	outFile.open(numOutFileName);
	for (i = 0; i < 9; i++)
	{
		cout << numArray[i] << " ";
		outFile << numArray[i] << " ";
	}

	outFile.close();
	cout << endl;



	//Sort and write to new files
	//Ask where new files should be named
	cout << "Where would you like the sorted contents of early.txt to go?" << endl;
	std::getline(std::cin, earlyOutFileName);

	sort(earlyArray, 10);
	cout << "early.txt sorted and written to " << earlyOutFileName << endl;
	outFile.open(earlyOutFileName);
	for (i = 0; i < 10; i++)
	{
		cout << earlyArray[i] << " ";
		outFile << earlyArray[i] << " ";
	}
	
	outFile.close();
	cout << endl;


	//Sort and write to new files
	//Ask where new files should be named
	cout << "Where would you like the sorted contents of middle.txt to go?" << endl;
	std::getline(std::cin, middleOutFileName);

	sort(middleArray, 10);
	cout << "middle.txt sorted and written to " << middleOutFileName << endl;
	outFile.open(middleOutFileName);
	for (i = 0; i < 10; i++)
	{
		cout << middleArray[i] << " ";
		outFile << middleArray[i] << " ";
	}
	
	outFile.close();
	cout << endl;



	//Sort and write to new files
	//Ask where new files should be named
	cout << "Where would you like the sorted contents of end.txt to go?" << endl;
	std::getline(std::cin, endOutFileName);

	sort(endArray, 10);
	cout << "end.txt sorted and written to " << endOutFileName << endl;
	outFile.open(endOutFileName);
	for (i = 0; i < 10; i++)
	{
		cout << endArray[i] << " ";
		outFile << endArray[i] << " ";
	}
	
	outFile.close();
	cout << endl;


	
	//Use binary search function, and return location of int.

	postion = binarySearch(numArray, 9, searchNum);
	if (postion == -1)
	{
		cout << "The search value is not found" << endl;
	}
	else
	cout << "Searched value is in array postion " << postion << " in file " << numOutFileName << endl;

	//Use binary search function, and return location of int.
	postion = binarySearch(earlyArray, 10, searchNum);
	if (postion == -1)
	{
		cout << "The search value is not found" << endl;
	}
	else
	cout << "Searched value is in array postion " << postion << " in file " << earlyOutFileName << endl;


	//Use binary search function, and return location of int.
	postion = binarySearch(middleArray, 10, searchNum);
	if (postion == -1)
	{
		cout << "The search value is not found" << endl;
	}
	else
	cout << "Searched value is in array postion " << postion << " in file " << middleOutFileName << endl;


	//Use binary search function, and return location of int.
	postion = binarySearch(endArray, 10, searchNum);
	if (postion == -1)
	{
		cout << "The search value is not found" << endl;
	}
	else
	cout << "Searched value is in array postion " << postion << " in file " << endOutFileName << endl;

}


/*******************************************************************************
 *						search(array, int, int)
 *				This function searches through an array for a number.
 *				It retruns true if found, else it returns false.
 *				The parameters are an array, an int of the number looked for
 *				and the length of the array.
 * ****************************************************************************/
bool search(int array[], int searched, int length)
{

	int i = 0;
	while(i < length)
	{
		if(array[i] == searched)
		{
			return true;
		}
		else
		{
			i++;
		}

	}

	return false;
}
	

/*******************************************************************************
 *							sort(array, int)
 *				This function uses a bubble sort, found in the textbook.
 *				It sorts the array so that they are numerical.
 *				It returns nothing.
 *				It takes in an array and its length
 * ****************************************************************************/
//Reference "Starting out with C++ early Objects" 9th editon
//Authors: Gladis, Walters, Muganda
//Pg# [613-617]
void sort(int sortArray[], int size)
{
	int temp;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (sortArray[count] > sortArray[count + 1])
			{
				temp = sortArray[count];
				sortArray[count] = sortArray[count + 1];
				sortArray[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

}



/*******************************************************************************
 *							binarySearch(array, size, search)
 *				This function uses a binary search, found in the textbook
 *				It searches through a sorted array and returns the location
 *				of the searched for integer.
 *				It takes in the array, the size, and the int to search for.
 *				Returns the int of the location
 * ****************************************************************************/
//Reference "Starting out with C++ early Objects" 9th editon
//Authors: Gladis, Walters, Muganda
//Pg# [606-609]
int binarySearch(const int biArray[], int size, int search)
{
	int first = 0;
	int last = size - 1;
	int middle;
	int position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (biArray[middle] == search)
		{
			found = true;
			position = middle;

		}
		else if (biArray[middle] > search)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

