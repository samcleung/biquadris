#include "cell.h"
#include "scell.h"
#include "../block/block.h"

SCell::SCell(Block* block, int x, int y) {'S', block, x, y, Cell::Color::Cyan} {}
