#include "cell.h"
#include "lcell.h"
#include "../block/block.h"

LCell::LCell(Block* block, int x, int y) {'L', block, x, y, Cell::Color::Yellow} {}
