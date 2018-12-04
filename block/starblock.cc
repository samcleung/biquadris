#include <vector>
#include "block.h"
#include "starblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

StarBlock::StarBlock(int points, unsigned int dropBy, const Coord& coord) : Block{points, dropBy, false, 1} {
	cells.emplace_back(Cell{'*', this, coord, Cell::Color::Brown});
}
