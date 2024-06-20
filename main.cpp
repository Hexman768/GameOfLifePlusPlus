#if defined _WIN32
#include <Windows.h>
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined (__linux__)
#include <unistd.h>
#endif
#include "Board.h"

void clear() {
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
	system("clear");
#endif
}

int main(int argc, char **argv) {
	/*
	if (argc < 2) {
		std::cout << "Usage: ./main input.txt" << "\n";
		return 1;
	}*/

	Board board = Board(20, 20);
	board.generateRandomMatrix();
	while (true) {
		clear();
		board.drawBoard();
		board.calcNextGeneration();
#if defined _WIN32
		Sleep(500);
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		usleep(500);
#endif
	}
}
