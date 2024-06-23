#ifndef _CELL_H_
#define _CELL_H_
#pragma once

class Cell {
public:
	int x_ = 0;
	int y_ = 0;

	Cell(bool state);
	Cell(bool state, const int x, const int y);
	bool getState();
	int getIntState();
	void setState(bool state);
private:
	bool _state;
};

#endif

