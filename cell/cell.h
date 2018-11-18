#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <string>
#include "../block/block.h"

class Block;
struct Cell {
	std::string print(int, int);
	enum class Color { Brown = -31, Red = 31, Green, Yellow, Magenta = 35, Cyan = 36, Default, Blue = 94 };
	Cell(char, Block*, int x = 0, int y = 0, Color c = Color::Default);

	int x;
	int y;


	private:	
	const char value;
	Block* const block;
	const Color color;
};

std::ostream& operator<<(std::ostream&, const Cell&);

#endif
