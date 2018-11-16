#include "cell.h"
#include "ocell.h"
#include "../block/block.h"

OCell::OCell(Block* block, int x, int y) {'O', block, x, y, Cell::Color::Magenta} {}
