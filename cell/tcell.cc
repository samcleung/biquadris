#include "cell.h"
#include "tcell.h"
#include "../block/block.h"

TCell::TCell(Block* block, int x, int y) {'T', block, x, y, Cell::Color::Default} {}
