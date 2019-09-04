/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/15/2019
** Description:  This is the specification file for the board class. This class
**               keeps track of the board's tile colors. This class also
**               generates the board, places the ant, changes the tile color
**               as neccessary, and displays the board.
*******************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
	private:
		char** board;
		char color;
		int rows;
		int cols;
	public:
		Board(int, int);
		void setUpBoard();
		char getColor();
		void changeColor(int, int);
		void placeAnt(int, int);
		void printBoard();
		void deallocate();
};
#endif