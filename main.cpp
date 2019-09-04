/*******************************************************************************
** Program Name: Langton's Ant
** Author:       Jacky Tran
** Date:         04/15/2019
** Description:  This program simulates Langton's Ant: https://bit.ly/2aABD8T.
**               The program uses an Ant class to keep track of the ant's
**               location and orientation, a board class to keep track of tile
**               color, and functions for the menus and input validation.
**               Requires: ant.cpp, ant.hpp, board.cpp, board.hpp, menu.cpp,
**               menu.hpp, inputChecker.cpp, inputChecker.hpp to compile
*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "menu.hpp"
#include "ant.hpp"
#include "inputChecker.hpp"

using std::cout;

int main()
{
	if (startMenu() == 2)
	{
		return 0;
	}

	do
	{
		cout << "\nWelcome to the Langton's Ant Simulation!\n\n";

		int numRows, numCols, steps, startX, startY;
		numRows = numCols = steps = startX = startY = 0;

		cout << "Choose the number of rows for the board (5 - 100):\n";
		numRows = inputValidate(5, 100);
		
		cout << "Choose the number of columns for the board (5 - 100):\n";
		numCols = inputValidate(5, 100);

		cout << "Choose the number of steps the ant will take during the simulation:\n";
		steps = inputValidate(1, 20000);
		
		if (startLocation() == 1)
		{
			cout << "Choose the starting x-axis position (1 - " << numCols << "):\n";
			startX = inputValidate(1, numCols);
			cout << "Choose the starting y-axis position (1 - " << numRows << "):\n";
			startY = inputValidate(1, numRows);
		}
		// Randomize the starting location
		// Code Source: https://bit.ly/1payDUb
		else
		{
			cout << "\nRandomizing the starting location.\n\n";
			srand(time(NULL));
			startX = rand() % numCols + 1;
			startY = rand() % numRows + 1;
		}

		Ant ant1(numRows, numCols, startX, startY);
		ant1.print();

		for (int i = 0; i < steps; i++)
		{
			ant1.turn();
			ant1.move();
		}
		
		ant1.deallocate();
	} while (playAgain());
	
	return 0;
}