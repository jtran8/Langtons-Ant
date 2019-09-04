/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/15/2019
** Description:  This function validates user input by ensuring it is the right
**               type and calls another function to verify it is in range.
*******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include "inputChecker.hpp"

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::atoi;

/*******************************************************************************
** inputValidate function
** Prompts user for an input, checks the input for invalid characters and then
** passes the valid integer along with the min and max integer range to another
** function for range validation. Returns the validated input integer.
*******************************************************************************/
int inputValidate(int min, int max)
{
	int userInput = 0;
	string strInput = "";
	bool onlyDigits = true;
	
	// Loop that gets input as string and checks for non-alpha characters
	// Code source: https://bit.ly/2v8xEcN
	do
	{
		getline(cin, strInput);

		for (int i = 0; i < strInput.size(); i++)
		{
			if (!(isdigit(strInput[i])))
			{
				onlyDigits = false;
				cout << "\nYour choice is not valid, please try again:\n";
				break;
			}
		}
	} while (!onlyDigits);

	userInput = atoi(strInput.c_str());
	rangeValidate(userInput, min, max);

	return userInput;
}
/*******************************************************************************
** rangeValidate function
** Checks to see if the passed integer is in the passed integer range. Calls
** The inputValidate function to prompt the user for another input if the 
** input is outside the range.
*******************************************************************************/
void rangeValidate(int userInput, int min, int max)
{
	// Calls back to inputValidate to get another input if out of range
	if (userInput < min || userInput > max)
	{
		cout << "\nYour choice is not valid, please try again:\n";
		inputValidate(min, max);
	}
}