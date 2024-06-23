#if defined _WIN32
#include <Windows.h>
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined (__linux__)
#include <unistd.h>
#endif
#include <fstream>
#include <iostream>
#include <string>
#include "Board.h"

void clear() {
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

void sleep(int millis) {
#if defined _WIN32
	Sleep(millis);
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	usleep(500);
#endif
}

int main(int argc, char **argv) {
	std::string inFileName;
	std::vector<Cell> liveCells;
	Board board;
	if (true) {
		int x = 0;
		int y = 0;
		std::ifstream file("cells.txt");
		std::string line;
		if (file.is_open()) {
			while (std::getline(file, line)) {
				// yes, I am ignoring the return value here
				int result = sscanf_s(line.c_str(), "%d %d", &x, &y);
				liveCells.push_back(Cell(true, x, y));
			}
			board = Board(liveCells);
		}
		else {
			std::cout << "File: " << argv[1] << " could not be opened!\n";
		}
	}

	//board.generateRandomMatrix();
	while (true) {
		clear();
		board.drawBoard();
		board.calcNextGeneration();
		sleep(1000);
	}
}
