#include <vector>
#include "block.h"
#include "zblock.h"
#include "../cell/cell.h"

ZBlock::ZBlock(const Coord& coord, int level) : Block{level, 3} {
	cells.emplace_back({'Z', this, coord.x + 1, coord.y, Cell::Color::Blue});
	cells.emplace_back({'Z', this, coord.x, coord.y + 1, Cell::Color::Blue});
	cells.emplace_back({'Z', this, coord.x + 1, coord.y + 1, Cell::Color::Blue});
	cells.emplace_back({'Z', this, coord.x + 2, coord.y, Cell::Color::Blue});
}
