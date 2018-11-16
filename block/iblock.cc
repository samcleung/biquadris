#include <vector>
#include "block.h"
#include "iblock.h"
#include "../cell/icell.h"

IBlock::IBlock(int x, int y) : Block{4} {
	cells.emplace_back(new ICell{this, x, y});
	cells.emplace_back(new ICell{this, x + 1, y});
	cells.emplace_back(new ICell{this, x + 2, y});
	cells.emplace_back(new ICell{this, x + 3, y});
}
