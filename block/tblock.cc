#include <vector>
#include "block.h"
#include "tblock.h"
#include "../cell/cell.h"

TBlock::TBlock(const Coord& coord, int level) : Block{level, 3} {
	cells.emplace_back({'T', this, coord.x + 1, coord.y, Cell::Color::Default});
	cells.emplace_back({'T', this, coord.x, coord.y + 1, Cell::Color::Default});
	cells.emplace_back({'T', this, coord.x + 1, coord.y + 1, Cell::Color::Default});
	cells.emplace_back({'T', this, coord.x + 2, coord.y + 1, Cell::Color::Default});
}
