#include <vector>
#include "block.h"
#include "lblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

LBlock::LBlock(int points, unsigned int dropBy, const Coord& coord) : Block{points, dropBy, true, 3} {
	cells.emplace_back(Cell{'L', this, coord, Cell::Color::Yellow});
	cells.emplace_back(Cell{'L', this, Coord{coord.x + 1, coord.y}, Cell::Color::Yellow});
	cells.emplace_back(Cell{'L', this, Coord{coord.x + 2, coord.y}, Cell::Color::Yellow});
	cells.emplace_back(Cell{'L', this, Coord{coord.x + 2, coord.y + 1}, Cell::Color::Yellow});
}
