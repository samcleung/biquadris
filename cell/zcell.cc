#include "cell.h"
#include "zcell.h"
#include "../block/block.h"

ZCell::ZCell(Block* block, int x, int y) {'Z', block, x, y, Cell::Color::Blue} {}
