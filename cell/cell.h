#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <string>
#include "../block/block.h"
#include "../coord/coord.h"

class Block;
struct Cell {
	enum class Color { Brown = -31, Red = 31, Green, Yellow, Magenta = 35, Cyan = 36, Default, Blue = 94 };
	Cell(char, Block* const, const Coord& coord = Coord::origin(), const Color& color = Color::Default);
	Cell(const Cell&, Block* const); // used for move/copy constructor in Block

	void setCoord(const Coord&);
	Coord getCoord() const;
	std::string print(int, int) const;
	bool isValid() const;
	void remove();

	private:
	bool valid = true;
	const char value;
	Block* const block;
	Coord coord = Coord::origin();
	const Color color;
};

std::ostream& operator<<(std::ostream&, const Cell&);

#endif
