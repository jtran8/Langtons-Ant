/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/15/2019
** Description:  This is the specification file for the ant class. This class
**               keeps track of the ant's location and direction. This class
**               also rotates and moves the ant.
*******************************************************************************/

#include <iostream>
#include "ant.hpp"

/*******************************************************************************
** 4 parameter constructor
** Initializes the data members of Ant class when integers are passed by
** by argument.
*******************************************************************************/
Ant::Ant(int numRows, int numCols, int startX, int startY)
{
	rows = numRows;
	cols = numCols;
	xCoord = startX;
	yCoord = startY;
	orientation = 'N';
	antPosition = new Board(rows, cols);
	antPosition->placeAnt(yCoord, xCoord);
}

/*******************************************************************************
** turn function
** Turns the ant by changing its orientation according to the tile color.
** Calls the changeColor function to change the tile color.
*******************************************************************************/
void Ant::turn()
{
	if (antPosition->getColor() == ' ')
	{
		if (orientation == 'N')
		{
			orientation = 'E';
		}
		else if (orientation == 'S')
		{
			orientation = 'W';
		}
		else if (orientation == 'E')
		{
			orientation = 'S';
		}
		else
		{
			orientation = 'N';
		}

		antPosition->changeColor(yCoord, xCoord);
	}
	else
	{
		if (orientation == 'N')
		{
			orientation = 'W';
		}
		else if (orientation == 'S')
		{
			orientation = 'E';
		}
		else if (orientation == 'E')
		{
			orientation = 'N';
		}
		else
		{
			orientation = 'S';
		}

		antPosition->changeColor(yCoord, xCoord);
	}	
}

/*******************************************************************************
** move function
** Moves the ant by changing its coordinates according to its orientation.
** Calls the print function to print the updated board.
*******************************************************************************/
void Ant::move()
{
	if (orientation == 'N')
	{
		if (yCoord == 1)
		{
			yCoord = rows;
		}
		else
		{
			yCoord -= 1;
		}
	}
	else if (orientation == 'S')
	{
		if (yCoord == rows)
		{
			yCoord = 1;
		}
		else
		{
			yCoord += 1;
		}
	}
	else if (orientation == 'E')
	{
		if (xCoord == cols)
		{
			xCoord = 1;
		}
		else
		{
			xCoord += 1;
		}
	}
	else
	{
		if (xCoord == 1)
		{
			xCoord = cols;
		}
		else
		{
			xCoord -= 1;
		}
	}

	antPosition->placeAnt(yCoord, xCoord);
	antPosition->printBoard();
}

/*******************************************************************************
** print function
** Prints the board.
*******************************************************************************/
void Ant::print()
{
	antPosition->printBoard();
}

/*******************************************************************************
** deallocate function
** Deallocates dynamically allocated memory and sets pointer to null.
*******************************************************************************/
void Ant::deallocate()
{
	antPosition->deallocate();
	delete antPosition;
	antPosition = nullptr;
}
