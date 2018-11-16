#include <vector>
#include "block.h"
#include "jblock.h"
#include "../cell/jcell.h"

JBlock::JBlock(int x, int y) {
	cells.emplace_back(new JCell{this, x, y});
	cells.emplace_back(new JCell{this, x, y + 1});
	cells.emplace_back(new JCell{this, x + 1, y});
	cells.emplace_back(new JCell{this, x + 2, y});
}
