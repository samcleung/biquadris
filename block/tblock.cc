#include <vector>
#include "block.h"
#include "tblock.h"
#include "../cell/tcell.h"

TBlock::TBlock(int x, int y) {
	cells.emplace_back(new TCell{this, x + 1, y});
	cells.emplace_back(new TCell{this, x, y + 1});
	cells.emplace_back(new TCell{this, x + 1, y + 1});
	cells.emplace_back(new TCell{this, x + 2, y + 1});
}
