#include <vector>
#include "block.h"
#include "lblock.h"
#include "../cell/cell.h"

LBlock::LBlock(const Coord& coord, int level) : Block{level, 3} {
	cells.emplace_back({'L', this, coord.x, coord.y, Cell::Color::Yellow});
	cells.emplace_back({'L', this, coord.x + 1, coord.y, Cell::Color::Yellow});
	cells.emplace_back({'L', this, coord.x + 2, coord.y, Cell::Color::Yellow});
	cells.emplace_back({'L', this, coord.x + 2, coord.y + 1, Cell::Color::Yellow});
}
