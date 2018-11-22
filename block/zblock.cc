#include <vector>
#include "block.h"
#include "zblock.h"
#include "../cell/cell.h"

ZBlock::ZBlock(int x, int y) : Block{3} {
	cells.emplace_back({'Z', this, x + 1, y, Cell::Color::Blue});
	cells.emplace_back({'Z', this, x, y + 1, Cell::Color::Blue});
	cells.emplace_back({'Z', this, x + 1, y + 1, Cell::Color::Blue});
	cells.emplace_back({'Z', this, x + 2, y, Cell::Color::Blue});
}
