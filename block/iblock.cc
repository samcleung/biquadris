#include <vector>
#include "block.h"
#include "iblock.h"
#include "../cell/cell.h"

IBlock::IBlock(int x, int y) : Block{4} {
	cells.emplace_back({'I', this, x, y, Cell::Color::Red});
	cells.emplace_back({'I', this, x + 1, y, Cell::Color::Red});
	cells.emplace_back({'I', this, x + 2, y, Cell::Color::Red});
	cells.emplace_back({'I', this, x + 3, y, Cell::Color::Red});
}
