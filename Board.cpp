#include <iostream>
#include <string>
#include "Board.h"

Board::Board(const int rows, const int cols) {
	_rows = rows;
	_cols = cols;
	for (int i = 0; i < _rows; i++) {
		std::vector<Cell> row;
		for (int j = 0; j < _cols; j++) {
			row.push_back(Cell(false));
		}
		matrix.push_back(row);
	}

	// TODO: Remove the following preset stuff
	//matrix[0][1] = Cell(true);
	//matrix[1][1] = Cell(true);
	//matrix[2][1] = Cell(true);
}

void Board::drawBoard() {
	std::string consoleStr = "";
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			if (matrix[i][j].getState()) {
				consoleStr += "#";
			}
			else {
				consoleStr += ".";
			}
		}
		consoleStr += "\n";
	}
	std::cout << consoleStr << "\n";
}

int Board::getNeighbors(const int x, const int y) {
	int nbrs = 0;
	// check top left
	if (x > 0 && y > 0) {
		nbrs += matrix[y - 1][x - 1].getIntState();
	}
	// check top
	if (y > 0) {
		nbrs += matrix[y - 1][x].getIntState();
	}
	// check top right
	if (x < (_cols - 1) && y > 0) {
		nbrs += matrix[y - 1][x + 1].getIntState();
	}
	// check left
	if (x > 0) {
		nbrs += matrix[y][x - 1].getIntState();
	}
	// check right
	if (x < _cols - 1) {
		nbrs += matrix[y][x + 1].getIntState();
	}
	// check bottom left
	if (x > 0 && y < _rows - 1) {
		nbrs += matrix[y + 1][x - 1].getIntState();
	}
	// check bottom
	if (y < _rows - 1) {
		nbrs += matrix[y + 1][x].getIntState();
	}
	// check bottom right
	if (x < _cols - 1 && y < _rows - 1) {
		nbrs += matrix[y + 1][x + 1].getIntState();
	}
	return nbrs;
}

void Board::calcNextGeneration() {
	std::vector<std::vector<Cell>> nextGen;
	for (int i = 0; i < _rows; i++) {
		std::vector<Cell> row;
		for (int j = 0; j < _cols; j++) {
			bool die = false;
			bool birth = false;
			bool alive = matrix[i][j].getState();
			int nbrs = getNeighbors(j, i);

			/* Rules */
			if (alive && nbrs < 2) { die = true; }
			if (alive && (nbrs == 2 || nbrs == 3)) { birth = true; }
			if (alive && nbrs > 3) { die = false; }
			if (!alive && nbrs == 3) { birth = true; }

			/* Construct Next Generation */
			if (die) { row.push_back(Cell(false)); }
			else if (birth) { row.push_back(Cell(true)); }
			else { row.push_back(Cell(false)); }
		}
		nextGen.push_back(row);
	}
	matrix = nextGen;
}

void Board::generateRandomMatrix() {
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			// create random number between one and zero.
			int rnd = rand() % 2;
			matrix[i][j] = rnd == 0 ? Cell(false) : Cell(true);
		}
	}
}

