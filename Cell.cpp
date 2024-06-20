#include "Cell.h"

Cell::Cell(bool state) {
	_state = state;
}

bool Cell::getState() {
	return _state;
}

int Cell::getIntState() {
	return _state ? 1 : 0;
}

void Cell::setState(bool state) {
	_state = state;
}
