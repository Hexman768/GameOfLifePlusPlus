#ifndef _CELL_H_
#define _CELL_H_
#pragma once

class Cell {
public:
	Cell(bool state);
	bool getState();
	int getIntState();
	void setState(bool state);
private:
	bool _state;
};

#endif

