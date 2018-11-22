#include <vector>
#include "block.h"
#include "jblock.h"
#include "../cell/cell.h"

JBlock::JBlock(int x, int y) : Block{3} {
	cells.emplace_back({'J', this, x, y, Cell::Color::Green});
	cells.emplace_back({'J', this, x, y + 1, Cell::Color::Green});
	cells.emplace_back({'J', this, x + 1, y, Cell::Color::Green});
	cells.emplace_back({'J', this, x + 2, y, Cell::Color::Green});
}
