#include <iostream>
#include <sstream>
#include "cell.h"
#include "../block/block.h"

using namespace std;

Cell::Cell(char value, Block* block, int x, int y, Cell::Color c) : x{x}, y{y}, value{value}, block{block}, color{c} {}

string Cell::print(int offsetX, int offsetY) const {
	// prints cell to text interface in its corresponding color
	ostringstream oss;
	oss << "\033[";
	int x = (int)color;
	if (x < 0) oss << "2;" << x * -1;
	else oss << "22;" << x;
	oss << "m" << value << "\033[0m";
	return oss.str();
}

ostream& operator<<(std::ostream& out, const Cell& cell) {
	out << cell.print(0, 0);
	return out;
}
