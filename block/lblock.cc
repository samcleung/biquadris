#include <vector>
#include "block.h"
#include "lblock.h"
#include "../cell/cell.h"

LBlock::LBlock(int x, int y) : Block{3} {
	cells.emplace_back({'L', this, x, y, Cell::Color::Yellow});
	cells.emplace_back({'L', this, x + 1, y, Cell::Color::Yellow});
	cells.emplace_back({'L', this, x + 2, y, Cell::Color::Yellow});
	cells.emplace_back({'L', this, x + 2, y + 1, Cell::Color::Yellow});
}
