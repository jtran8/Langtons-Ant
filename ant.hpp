/*******************************************************************************
** Author:       Jacky Tran
** Date:         04/15/2019
** Description:  This is the specification file for the ant class. This class
**               keeps track of the ant's location and direction. This class
**               also rotates and moves the ant.
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "board.hpp"

class Ant
{
	private:
		Board* antPosition;
		char orientation;
		int rows;
		int cols;
		int xCoord;
		int yCoord;
	public:
		Ant(int, int, int, int);
		void turn();
		void move();
		void print();
		void deallocate();
};

#endif