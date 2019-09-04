/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/15/2019
** Description:  This is the specification file for the board class. This class
**               keeps track of the board's tile colors. This class also
**               generates the board, places the ant, changes the tile color
**               as neccessary, and displays the board.
*******************************************************************************/

#include <iostream>
#include "board.hpp"

using std::cout;
using std::endl;

/*******************************************************************************
** 2 parameter constructor
** Initializes the data members of Board class when integers are passed by 
** by argument. Calls the setUpBoard function.
*******************************************************************************/
Board::Board(int numRows, int numCols)
{
	rows = numRows;
	cols = numCols;
	color = ' ';

	// Adding 2 rows and 2 columns for the border
	board = new char* [rows + 2];
	for (int i = 0; i < rows + 2; i++)
	{
		board[i] = new char[cols + 2];
	}

	setUpBoard();
}

/*******************************************************************************
** setUpBoard function
** Draws the border around the board and fills it with white spaces.
*******************************************************************************/
void Board::setUpBoard()
{
	// Adds the top and bottom borders
	for (int j = 0; j < cols + 2; j++)
	{
		board[0][j] = '-';
		board[rows + 1][j] = '-';
	}

	// Adds the left and right borders
	for (int i = 1; i < rows + 1; i++)
	{
		board[i][0] = '|';
		board[i][cols + 1] = '|';
	}

	// Fill white spaces, adding one to compensate for borders
	for (int i = 1; i < rows + 1; i++)
	{
		for (int j = 1; j < cols + 1; j++)
		{
			board[i][j] = ' ';
		}
	}
}

/*******************************************************************************
** getColor function
** Returns the color of the tile occupied by the ant.
*******************************************************************************/
char Board::getColor()
{
	return color;
}

/*******************************************************************************
** changeColor function
** Takes two integers representing the coordinates of the ant and flips the
** color.
*******************************************************************************/
void Board::changeColor(int yCoord, int xCoord)
{
	if (getColor() == ' ')
	{
		board[yCoord][xCoord] = '#';
	}
	else
	{
		board[yCoord][xCoord] = ' ';
	}

}

/*******************************************************************************
** placeAnt function
** Takes two integers representing the coordinates of the new tile and places
** the ant.
*******************************************************************************/
void Board::placeAnt(int yCoord, int xCoord)
{
	// Saving the tile color info before placing ant
	color = board[yCoord][xCoord];
	board[yCoord][xCoord] = '*';
}

/*******************************************************************************
** printBoard function
** Prints the board.
*******************************************************************************/
void Board::printBoard()
{
	for (int i = 0; i < rows + 2; i++)
	{
		for (int j = 0; j < cols + 2; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

/*******************************************************************************
** deallocate function
** Deallocates dynamically allocated memory and sets pointer to null.
*******************************************************************************/
void Board::deallocate()
{
	for (int i = 0; i < rows + 2; i++)
	{
		delete[] board[i];
	}
	delete[] board;

	board = nullptr;
}
