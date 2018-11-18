#include <vector>
#include "block.h"
#include "starblock.h"
#include "../cell/cell.h"

StarBlock::StarBlock(int x, int y) : Block{1} {
	cells.emplace_back(new Cell{'*', this, x, y, Cell::Color::Brown});
}
