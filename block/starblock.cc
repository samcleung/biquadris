#include <vector>
#include "block.h"
#include "starblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

StarBlock::StarBlock(const Coord& coord, int level) : Block{level, 1} {
	cells.emplace_back(Cell{'*', this, coord, Cell::Color::Brown});
}
