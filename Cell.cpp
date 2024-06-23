#include "Cell.h"

Cell::Cell(bool state) { _state = state; }

Cell::Cell(bool state, const int x, const int y) {
	_state = state;
	x_ = x;
	y_ = y;
}

bool Cell::getState() { return _state; }

int Cell::getIntState() { return _state ? 1 : 0; }

void Cell::setState(bool state) { _state = state; }
