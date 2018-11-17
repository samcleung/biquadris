#include <vector>
#include "block.h"
#include "oblock.h"
#include "../cell/cell.h"

OBlock::OBlock(int x, int y) : Block{2} {
	cells.emplace_back({'O', this, x, y, Cell::Color::Magenta});
	cells.emplace_back({'O', this, x + 1, y, Cell:Color::Magenta});
	cells.emplace_back({'O', this, x, y + 1, Cell::Color::Magenta});
	cells.emplace_back({'O', this, x + 1, y + 1, Cell::Color::Magenta});
}
