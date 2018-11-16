#include <vector>
#include "block.h"
#include "zblock.h"
#include "../cell/zcell.h"

ZBlock::ZBlock(int x, int y) {
	cells.emplace_back(new ZCell{x + 1, y});
	cells.emplace_back(new ZCell{x, y + 1});
	cells.emplace_back(new ZCell{x + 1, y + 1});
	cells.emplace_back(new ZCell{x + 2, y});
}
