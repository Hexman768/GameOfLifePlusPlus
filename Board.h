#ifndef _BOARD_H_
#define _BOARD_H_
#pragma once

#include <vector>
#include "Cell.h"

class Board {
private:
	int _rows;
	int _cols;
	std::vector<std::vector<Cell>> matrix;

public:
	Board(const int rows, const int cols);
	void drawBoard();
	void calcNextGeneration();
	void generateRandomMatrix();
	int getNeighbors(const int x, const int y);
};

#endif

