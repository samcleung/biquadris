#include <vector>
#include "block.h"
#include "oblock.h"
#include "../cell/ocell.h"

OBlock::OBlock(int x, int y) {
	cells.emplace_back(new OCell{this, x, y});
	cells.emplace_back(new OCell{this, x + 1, y});
	cells.emplace_back(new OCell{this, x, y + 1});
	cells.emplace_back(new OCell{this, x + 1, y + 1});
}
