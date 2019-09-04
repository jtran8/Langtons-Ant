/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/15/2019
** Description:  Functions for the user prompt start and play again menus. 
**               Inline input validation ensures correct input and prevents the
**               program from crashing.
*******************************************************************************/

#include <iostream>
#include <limits>
#include "menu.hpp"
#include "inputChecker.hpp"

using std::cout;

/*******************************************************************************
** startMenu function
** Displays menu options, prompts user for input by calling another function
** and returns the valid input or takes an appropriate action.
*******************************************************************************/
int startMenu()
{
	int startSim = 0;

	cout << "\nSelect one of the options below:\n";
	cout << "1. Start Langton's Ant simulation\n";
	cout << "2. Quit\n";
	
	startSim = inputValidate(1, 2);
	
	if (startSim == 2)
	{
		cout << "\nQuitting...goodbye.\n";
	}

	return startSim;
}

/*******************************************************************************
** playAgain function
** Displays menu options, prompts user for input by calling another function
** and returns the valid input.
*******************************************************************************/
int startLocation()
{
	int startSpot = 0;

	cout << "\nWhere do you want the ant to start?\n";
	cout << "1. Manually enter a start location\n";
	cout << "2. Randomize the start location\n";

	startSpot = inputValidate(1, 2);

	return startSpot;
}

/*******************************************************************************
** playAgain function
** Displays menu options, prompts user for input by calling another function
** and returns the valid input or takes an appropriate action.
*******************************************************************************/
int playAgain()
{
	int playAgainChoice = 2;

	cout << "\nDo you want to play again?\n";
	cout << "0. Quit\n";
	cout << "1. Play Again\n";

	playAgainChoice = inputValidate(0, 1);

	if (playAgainChoice == 0)
	{
		cout << "\nQuitting...goodbye.\n";
	}

	return playAgainChoice;
}