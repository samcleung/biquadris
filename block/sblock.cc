#include <vector>
#include "block.h"
#include "sblock.h"
#include "../cell/cell.h"

SBlock::SBlock(const Coord& coord, int level) : Block{3} {
	cells.emplace_back({'S', this, coord.x, coord.y, Cell::Color::Cyan});
	cells.emplace_back({'S', this, coord.x + 1, coord.y, Cell::Color::Cyan});
	cells.emplace_back({'S', this, coord.x + 1, coord.y + 1, Cell::Color::Cyan});
	cells.emplace_back({'S', this, coord.x + 2, coord.y + 1, Cell::Color::Cyan});
}
