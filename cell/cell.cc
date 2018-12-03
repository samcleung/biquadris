#include <iostream>
#include <sstream>
#include "cell.h"
#include "../game/game.h"
#include "../block/block.h"
#include "../coord/coord.h"

using namespace std;

Cell::Cell(char value, Block* const block, const Coord& coord, const Cell::Color& color)
: value{value}, block{block}, coord{coord}, color{color} {}

Cell::Cell(const Cell& other, Block* const block)
: value{other.value}, block{block}, coord{other.coord}, color{other.color} {}

bool Cell::isValid() const {
	return valid;
}

void Cell::remove() {
	valid = false;
}

void Cell::setCoord(const Coord& coord) {
	this->coord = coord;
}

Coord Cell::getCoord() const {
	return coord;
}

string Cell::print(int offsetX, int offsetY) const {
	// prints cell to text interface in its corresponding color
	ostringstream oss;
	if (Game::isBonusEnabled) {
		oss << "\033[";
		int x = (int)color;
		if (x < 0) oss << "2;" << x * -1;
		else oss << "22;" << x;
		oss << "m" << value << "\033[0m";
	} else {
		oss << value;
	}
	return oss.str();
}

ostream& operator<<(std::ostream& out, const Cell& cell) {
	out << cell.print(0, 0);
	return out;
}
