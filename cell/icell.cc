#include "cell.h"
#include "icell.h"
#include "../block/block.h"

ICell::ICell(Block* block, int x, int y) : Cell{'I', block, x, y, Cell::Color::Red} {}
