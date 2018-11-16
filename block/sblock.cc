#include <vector>
#include "block.h"
#include "sblock.h"
#include "../cell/scell.h"

SBlock::SBlock(int x, int y) {
	cells.emplace_back(new SCell{this, x, y});
	cells.emplace_back(new SCell{this, x + 1, y});
	cells.emplace_back(new SCell{this, x + 1, y + 1});
	cells.emplace_back(new SCell{this, x + 2, y + 1});
}
