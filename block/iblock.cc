#include <vector>
#include "block.h"
#include "iblock.h"
#include "../cell/cell.h"

IBlock::IBlock(const Coord& coord, int level) : Block{level, 4} {
	cells.emplace_back({'I', this, coord.x, coord.y, Cell::Color::Red});
	cells.emplace_back({'I', this, coord.x + 1, coord.y, Cell::Color::Red});
	cells.emplace_back({'I', this, coord.x + 2, coord.y, Cell::Color::Red});
	cells.emplace_back({'I', this, coord.x + 3, coord.y, Cell::Color::Red});
}
