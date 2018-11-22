#include <vector>
#include "block.h"
#include "sblock.h"
#include "../cell/cell.h"

SBlock::SBlock(int x, int y) : Block{3} {
	cells.emplace_back({'S', this, x, y, Cell::Color::Cyan});
	cells.emplace_back({'S', this, x + 1, y, Cell::Color::Cyan});
	cells.emplace_back({'S', this, x + 1, y + 1, Cell::Color::Cyan});
	cells.emplace_back({'S', this, x + 2, y + 1, Cell::Color::Cyan});
}
