#include <iostream>
#include <string>
#include <time.h>
#include "Board.h"

std::vector<std::vector<Cell>> constructBoard(const int rows, const int cols, std::vector<Cell> vLiveCells) {
	std::vector<std::vector<Cell>> vGameBoard;
	for (int i = 0; i < rows; i++) {
		std::vector<Cell> row;
		for (int j = 0; j < cols; j++) {
			row.push_back(Cell(false, j, i));
		}
		vGameBoard.push_back(row);
	}
	for (const auto cell : vLiveCells) {
		vGameBoard[cell.y_][cell.x_] = cell;
	}
	return vGameBoard;
}

Board::Board() {
	_rows = 20;
	_cols = 20;
	std::vector<Cell> vCells;
	matrix = constructBoard(_rows, _cols, vCells);
}

Board::Board(std::vector<Cell> vLiveCells) {
	_rows = 20;
	_cols = 20;
	vLiveCells_ = vLiveCells;
	matrix = constructBoard(_rows, _cols, vLiveCells_);
}

Board::Board(const int rows, const int cols) {
	_rows = rows;
	_cols = cols;
	std::vector<Cell> vCells;
	matrix = constructBoard(_rows, _cols, vCells);
}

Board::Board(const int rows, const int cols, std::vector<Cell> liveCells) {
	_rows = rows;
	_cols = cols;
	vLiveCells_ = liveCells;
	matrix = constructBoard(_rows, _cols, vLiveCells_);
}

void Board::drawBoard() {
	std::string consoleStr = "";
	for (int i = 0; i < _rows; i++) {
		if (i == 0) {
			consoleStr += "+";
			for (int k = 0; k < _cols + 2; k++) { consoleStr += "-"; }
			consoleStr += "+\n";
		}
		for (int j = 0; j < _cols; j++) {
			if (j == 0) { consoleStr += "| "; }
			if (matrix[i][j].getState()) {
				consoleStr += "#";
			}
			else {
				consoleStr += " ";
			}
		}
		consoleStr += " |\n";
	}
	consoleStr += "+";
	for (int i = 0; i < _cols + 2; i++) {
		consoleStr += "-";
	}
	std::cout << consoleStr << "+\n";
}

int Board::getNeighbors(const int x, const int y) {
	int nbrs = 0;
	// check top left
	if (x > 0 && y > 0) { nbrs += matrix[y - 1][x - 1].getIntState(); }
	// check top
	if (y > 0) { nbrs += matrix[y - 1][x].getIntState(); }
	// check top right
	if (x < (_cols - 1) && y > 0) { nbrs += matrix[y - 1][x + 1].getIntState(); }
	// check left
	if (x > 0) { nbrs += matrix[y][x - 1].getIntState(); }
	// check right
	if (x < _cols - 1) { nbrs += matrix[y][x + 1].getIntState(); }
	// check bottom left
	if (x > 0 && y < _rows - 1) { nbrs += matrix[y + 1][x - 1].getIntState(); }
	// check bottom
	if (y < _rows - 1) { nbrs += matrix[y + 1][x].getIntState(); }
	// check bottom right
	if (x < _cols - 1 && y < _rows - 1) { nbrs += matrix[y + 1][x + 1].getIntState(); }
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
	srand(time(NULL));
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			// create random number between one and zero.
			int rnd = rand() % 2;
			matrix[i][j] = rnd == 0 ? Cell(false) : Cell(true);
		}
	}
}

