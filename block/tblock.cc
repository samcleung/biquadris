#include <vector>
#include "block.h"
#include "tblock.h"
#include "../cell/cell.h"

TBlock::TBlock(int x, int y) : Block{3} {
	cells.emplace_back({'T', this, x + 1, y, Cell::Color::Default});
	cells.emplace_back({'T', this, x, y + 1, Cell::Color::Default});
	cells.emplace_back({'T', this, x + 1, y + 1, Cell::Color::Default});
	cells.emplace_back({'T', this, x + 2, y + 1, Cell::Color::Default});
}
