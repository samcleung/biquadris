#include <vector>
#include "block.h"
#include "zblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

ZBlock::ZBlock(int points, unsigned int dropBy, const Coord& coord) : Block{points, dropBy, true, 3} {
	cells.emplace_back(Cell{'Z', this, Coord{coord.x + 1, coord.y}, Cell::Color::Blue});
	cells.emplace_back(Cell{'Z', this, Coord{coord.x, coord.y + 1}, Cell::Color::Blue});
	cells.emplace_back(Cell{'Z', this, Coord{coord.x + 1, coord.y + 1}, Cell::Color::Blue});
	cells.emplace_back(Cell{'Z', this, Coord{coord.x + 2, coord.y}, Cell::Color::Blue});
}
