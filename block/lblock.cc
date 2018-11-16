#include <vector>
#include "block.h"
#include "lblock.h"
#include "../cell/lcell.h"

LBlock::LBlock(int x, int y) : Block{3} {
	cells.emplace_back(new LCell{this, x, y});
	cells.emplace_back(new LCell{this, x + 1, y});
	cells.emplace_back(new LCell{this, x + 2, y});
	cells.emplace_back(new LCell{this, x + 2, y + 1});
}
